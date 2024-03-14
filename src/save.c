#include "global.h"
#include "agb_flash.h"
#include "gba/flash_internal.h"
#include "fieldmap.h"
#include "save.h"
#include "task.h"
#include "decompress.h"
#include "load_save.h"
#include "overworld.h"
#include "pokemon_storage_system.h"
#include "main.h"
#include "trainer_hill.h"
#include "link.h"
#include "constants/game_stat.h"

static u16 CalculateChecksum(void *data, u16 size);
static bool8 DoReadFlashWholeSection(u8 sector, struct SaveSector *section);
static u8 GetSaveValidStatus(const struct SaveSectionLocation *location);
static u8 CopySaveSlotData(u16, const struct SaveSectionLocation *location);
static u8 HandleReplaceSector(u16 a1, const struct SaveSectionLocation *location);
static u8 TryWriteSector(u8 sector, u8 *data);
static u8 HandleWriteSector(u16 a1, const struct SaveSectionLocation *location);

// Divide save blocks into individual chunks to be written to flash sectors

/*
 * Sector Layout:
 *
 * Sectors 0 - 13:      Save Slot 1
 * Sectors 14 - 27:     Save Slot 2
 * Sectors 28 - 29:     Hall of Fame
 * Sector 30:           Trainer Hill
 * Sector 31:           Recorded Battle
 *
 * There are two save slots for saving the player's game data. We alternate between
 * them each time the game is saved, so that if the current save slot is corrupt,
 * we can load the previous one. We also rotate the sectors in each save slot
 * so that the same data is not always being written to the same sector. This
 * might be done to reduce wear on the flash memory, but I'm not sure, since all
 * 14 sectors get written anyway.
 */

// (u8 *)structure was removed from the first statement of the macro in Emerald.
// This is because malloc is used to allocate addresses so storing the raw
// addresses should not be done in the offsets information.
#define SAVEBLOCK_CHUNK(structure, chunkNum)                                \
{                                                                           \
    chunkNum * SECTOR_DATA_SIZE,                                            \
    min(sizeof(structure) - chunkNum * SECTOR_DATA_SIZE, SECTOR_DATA_SIZE)  \
}                                                                           \

static const struct SaveSectionOffsets sSaveSectionOffsets[] =
{
    SAVEBLOCK_CHUNK(gSaveblock2, 0),

    SAVEBLOCK_CHUNK(gSaveblock1, 0),
    SAVEBLOCK_CHUNK(gSaveblock1, 1),
    SAVEBLOCK_CHUNK(gSaveblock1, 2),
    SAVEBLOCK_CHUNK(gSaveblock1, 3),

    SAVEBLOCK_CHUNK(gPokemonStorage, 0),
    SAVEBLOCK_CHUNK(gPokemonStorage, 1),
    SAVEBLOCK_CHUNK(gPokemonStorage, 2),
    SAVEBLOCK_CHUNK(gPokemonStorage, 3),
    SAVEBLOCK_CHUNK(gPokemonStorage, 4),
    SAVEBLOCK_CHUNK(gPokemonStorage, 5),
    SAVEBLOCK_CHUNK(gPokemonStorage, 6),
    SAVEBLOCK_CHUNK(gPokemonStorage, 7),
    SAVEBLOCK_CHUNK(gPokemonStorage, 8),
};

// iwram common
u16 gLastWrittenSector;
u32 gLastSaveCounter;
u16 gLastKnownGoodSector;
u32 gDamagedSaveSectors;
u32 gSaveCounter;
struct SaveSector *gReadWriteSector;
u16 gIncrementalSectorId;
u16 gSaveUnusedVar;
u16 gSaveFileStatus;
void (*gGameContinueCallback)(void);
struct SaveSectionLocation gRamSaveSectionLocations[SECTOR_SAVE_SLOT_LENGTH];
u16 gSaveUnusedVar2;
u16 gSaveAttemptStatus;

EWRAM_DATA struct SaveSector gSaveDataBuffer = {0};
EWRAM_DATA static u8 sUnusedVar = 0;

void ClearSaveData(void)
{
    u16 i;

    for (i = 0; i < NUM_SECTORS_PER_SLOT; i++)
    {
        EraseFlashSector(i);
        EraseFlashSector(i + NUM_SECTORS_PER_SLOT); // clear slot 2.
    }
}

void Save_ResetSaveCounters(void)
{
    gSaveCounter = 0;
    gLastWrittenSector = 0;
    gDamagedSaveSectors = 0;
}

static bool32 SetDamagedSectorBits(u8 op, u8 bit)
{
    bool32 retVal = FALSE;

    switch (op)
    {
    case ENABLE:
        gDamagedSaveSectors |= (1 << bit);
        break;
    case DISABLE:
        gDamagedSaveSectors &= ~(1 << bit);
        break;
    case CHECK: // unused
        if (gDamagedSaveSectors & (1 << bit))
            retVal = TRUE;
        break;
    }

    return retVal;
}

static u8 SaveWriteToFlash(u16 a1, const struct SaveSectionLocation *location)
{
    u32 status;
    u16 i;

    gReadWriteSector = &gSaveDataBuffer;

    if (a1 != FULL_SAVE_SLOT) // for link
    {
        status = HandleWriteSector(a1, location);
    }
    else
    {
        gLastKnownGoodSector = gLastWrittenSector; // backup the current written sector before attempting to write.
        gLastSaveCounter = gSaveCounter;
        gLastWrittenSector++;
        gLastWrittenSector = gLastWrittenSector % SECTOR_SAVE_SLOT_LENGTH; // array count save sector locations
        gSaveCounter++;
        status = SAVE_STATUS_OK;

        for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
            HandleWriteSector(i, location);

        if (gDamagedSaveSectors != 0) // skip the damaged sector.
        {
            status = SAVE_STATUS_ERROR;
            gLastWrittenSector = gLastKnownGoodSector;
            gSaveCounter = gLastSaveCounter;
        }
    }

    return status;
}

static u8 HandleWriteSector(u16 sectorId, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 sector;
    u8 *data;
    u16 size;

    sector = sectorId + gLastWrittenSector;
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % NUM_SAVE_SLOTS);

    data = location[sectorId].data;
    size = location[sectorId].size;

    // clear save section.
    for (i = 0; i < sizeof(struct SaveSector); i++)
        ((char *)gReadWriteSector)[i] = 0;

    gReadWriteSector->id = sectorId;
    gReadWriteSector->security = SECTOR_SIGNATURE;
    gReadWriteSector->counter = gSaveCounter;

    for (i = 0; i < size; i++)
        gReadWriteSector->data[i] = data[i];

    gReadWriteSector->checksum = CalculateChecksum(data, size);
    return TryWriteSector(sector, gReadWriteSector->data);
}

static u8 HandleWriteSectorNBytes(u8 sector, u8 *data, u16 size)
{
    u16 i;
    struct SaveSector *section = &gSaveDataBuffer;

    for (i = 0; i < sizeof(struct SaveSector); i++)
        ((char *)section)[i] = 0;

    section->security = SECTOR_SIGNATURE;

    for (i = 0; i < size; i++)
        section->data[i] = data[i];

    section->id = CalculateChecksum(data, size); // though this appears to be incorrect, it might be some sector checksum instead of a whole save checksum and only appears to be relevent to HOF data, if used.
    return TryWriteSector(sector, section->data);
}

static u8 TryWriteSector(u8 sector, u8 *data)
{
    if (ProgramFlashSectorAndVerify(sector, data) != 0) // is damaged?
    {
        // Failed
        SetDamagedSectorBits(ENABLE, sector);
        return SAVE_STATUS_ERROR;
    }
    else
    {
        // Succeeded
        SetDamagedSectorBits(DISABLE, sector);
        return SAVE_STATUS_OK;
    }
}

// location is unused
static u32 RestoreSaveBackupVarsAndIncrement(const struct SaveSectionLocation *location)
{
    gReadWriteSector = &gSaveDataBuffer;
    gLastKnownGoodSector = gLastWrittenSector;
    gLastSaveCounter = gSaveCounter;
    gLastWrittenSector++;
    gLastWrittenSector %= SECTOR_SAVE_SLOT_LENGTH;
    gSaveCounter++;
    gIncrementalSectorId = 0;
    gDamagedSaveSectors = 0;
    return 0;
}

// only ever called once, and gSaveBlock2 is passed to this function. location is unused
static u32 RestoreSaveBackupVars(const struct SaveSectionLocation *location) 
{
    gReadWriteSector = &gSaveDataBuffer;
    gLastKnownGoodSector = gLastWrittenSector;
    gLastSaveCounter = gSaveCounter;
    gIncrementalSectorId = 0;
    gDamagedSaveSectors = 0;
    return 0;
}

static u8 HandleWriteIncrementalSector(u16 sectorId, const struct SaveSectionLocation *location)
{
    u8 status;

    if (gIncrementalSectorId < sectorId - 1)
    {
        status = SAVE_STATUS_OK;
        HandleWriteSector(gIncrementalSectorId, location);
        gIncrementalSectorId++;
        if (gDamagedSaveSectors)
        {
            status = SAVE_STATUS_ERROR;
            gLastWrittenSector = gLastKnownGoodSector;
            gSaveCounter = gLastSaveCounter;
        }
    }
    else
    {
        status = SAVE_STATUS_ERROR;
    }

    return status;
}

static u8 HandleReplaceSectorAndVerify(u16 sectorId, const struct SaveSectionLocation *location)
{
    u8 status = SAVE_STATUS_OK;

    HandleReplaceSector(sectorId - 1, location);

    if (gDamagedSaveSectors)
    {
        status = SAVE_STATUS_ERROR;
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
    }
    return status;
}

// Similar to HandleWriteSector, but fully erases the sector first, and skips writing the first signature byte
static u8 HandleReplaceSector(u16 sectorId, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 sector;
    u8 *data;
    u16 size;
    u8 status;

    // Adjust sector id for current save slot
    sector = sectorId + gLastWrittenSector;
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % NUM_SAVE_SLOTS);

    // Get current save data
    data = location[sectorId].data;
    size = location[sectorId].size;

    // Clear temp save sector.
    for (i = 0; i < sizeof(struct SaveSector); i++)
        ((char *)gReadWriteSector)[i] = 0;

    // Set footer data
    gReadWriteSector->id = sectorId;
    gReadWriteSector->security = SECTOR_SIGNATURE;
    gReadWriteSector->counter = gSaveCounter;

    // Copy current data to temp buffer for writing
    for (i = 0; i < size; i++)
        gReadWriteSector->data[i] = data[i];

    // Calculate checksum.
    gReadWriteSector->checksum = CalculateChecksum(data, size);

    // Erase old save data
    EraseFlashSector(sector);

    status = SAVE_STATUS_OK;

    // Write new save data up to signature field
    for (i = 0; i < SECTOR_SIGNATURE_OFFSET; i++)
    {
        if (ProgramFlashByte(sector, i, ((u8 *)gReadWriteSector)[i]))
        {
            status = SAVE_STATUS_ERROR;
            break;
        }
    }

    if (status == SAVE_STATUS_ERROR)
    {
        // Writing save data failed
        SetDamagedSectorBits(ENABLE, sector);
        return SAVE_STATUS_ERROR;
    }
    else
    {
        // Writing save data succeeded, write signature and counter
        status = SAVE_STATUS_OK;

        // Write signature (skipping the first byte) and counter fields.
        // The byte of signature that is skipped is instead written by WriteSectorSignatureByte or WriteSectorSignatureByte_NoOffset
        for (i = 0; i < 7; i++)
        {
            if (ProgramFlashByte(sector, 0xFF9 + i, ((u8 *)gReadWriteSector)[0xFF9 + i]))
            {
                status = SAVE_STATUS_ERROR;
                break;
            }
        }

        if (status == SAVE_STATUS_ERROR)
        {
            // Writing signature/counter failed
            SetDamagedSectorBits(ENABLE, sector);
            return SAVE_STATUS_ERROR;
        }
        else
        {
            // Succeeded
            SetDamagedSectorBits(DISABLE, sector);
            return SAVE_STATUS_OK;
        }
    }
}

static u8 WriteSectorSignatureByte_NoOffset(u16 sectorId, const struct SaveSectionLocation *location)
{
    // Adjust sector id for current save slot
    // This first line lacking -1 is the only difference from WriteSectorSignatureByte
    u16 sector;

    sector = sectorId + gLastWrittenSector;
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % NUM_SAVE_SLOTS);

    // Write just the first byte of the signature field, which was skipped by HandleReplaceSector
    if (ProgramFlashByte(sector, SECTOR_SIGNATURE_OFFSET, SECTOR_SIGNATURE & 0xFF))
    {
        // Sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return SAVE_STATUS_ERROR;
    }
    else
    {
        // Succeeded
        SetDamagedSectorBits(DISABLE, sector);
        return SAVE_STATUS_OK;
    }
}

static u8 CopySectorSignatureByte(u16 sectorId, const struct SaveSectionLocation *location)
{
    // Adjust sector id for current save slot
    u16 sector;

    sector = sectorId + gLastWrittenSector - 1;
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % NUM_SAVE_SLOTS);

    // Copy just the first byte of the signature field from the read/write buffer
    if (ProgramFlashByte(sector, SECTOR_SIGNATURE_OFFSET, ((u8 *)gReadWriteSector)[SECTOR_SIGNATURE_OFFSET]))
    {
        // Sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return SAVE_STATUS_ERROR;
    }
    else
    {
        // Succeeded
        SetDamagedSectorBits(DISABLE, sector);
        return SAVE_STATUS_OK;
    }
}

static u8 WriteSectorSignatureByte(u16 sectorId, const struct SaveSectionLocation *location)
{
    // Adjust sector id for current save slot
    u16 sector;

    sector = sectorId + gLastWrittenSector - 1;
    sector %= SECTOR_SAVE_SLOT_LENGTH;
    sector += SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % NUM_SAVE_SLOTS);

    // Write just the first byte of the signature field, which was skipped by HandleReplaceSector
    if (ProgramFlashByte(sector, SECTOR_SIGNATURE_OFFSET, SECTOR_SIGNATURE & 0xFF))
    {
        // Sector is damaged, so enable the bit in gDamagedSaveSectors and restore the last written sector and save counter.
        SetDamagedSectorBits(ENABLE, sector);
        gLastWrittenSector = gLastKnownGoodSector;
        gSaveCounter = gLastSaveCounter;
        return SAVE_STATUS_ERROR;
    }
    else
    {
        // Succeeded
        SetDamagedSectorBits(DISABLE, sector);
        return SAVE_STATUS_OK;
    }
}

static u8 TryLoadSaveSlot(u16 sectorId, const struct SaveSectionLocation *location)
{
    u8 status;
    gReadWriteSector = &gSaveDataBuffer;
    if (sectorId != FULL_SAVE_SLOT)
    {
        // This function may not be used with a specific sector id
        status = SAVE_STATUS_ERROR;
    }
    else
    {
        status = GetSaveValidStatus(location);
        CopySaveSlotData(FULL_SAVE_SLOT, location);
    }

    return status;
}

// sectorId arg is ignored, this always reads the full save slot
static u8 CopySaveSlotData(u16 sectorId, const struct SaveSectionLocation *location)
{
    u16 i;
    u16 checksum;
    u16 v3 = SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % NUM_SAVE_SLOTS);
    u16 id;

    for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
    {
        DoReadFlashWholeSection(i + v3, gReadWriteSector);
        id = gReadWriteSector->id;
        if (id == 0)
            gLastWrittenSector = i;
        checksum = CalculateChecksum(gReadWriteSector->data, location[id].size);
        if (gReadWriteSector->security == SECTOR_SIGNATURE
         && gReadWriteSector->checksum == checksum)
        {
            u16 j;
            for (j = 0; j < location[id].size; j++)
                ((u8 *)location[id].data)[j] = gReadWriteSector->data[j];
        }
    }

    return SAVE_STATUS_OK;
}

static u8 GetSaveValidStatus(const struct SaveSectionLocation *location)
{
    u16 i;
    u16 checksum;
    u32 saveSlot1Counter = 0;
    u32 saveSlot2Counter = 0;
    u32 slotCheckField = 0;
    bool8 securityPassed = FALSE;
    u8 saveSlot1Status;
    u8 saveSlot2Status;

    // check save slot 1.
    for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
    {
        DoReadFlashWholeSection(i, gReadWriteSector);
        if (gReadWriteSector->security == SECTOR_SIGNATURE)
        {
            securityPassed = TRUE;
            checksum = CalculateChecksum(gReadWriteSector->data, location[gReadWriteSector->id].size);
            if (gReadWriteSector->checksum == checksum)
            {
                saveSlot1Counter = gReadWriteSector->counter;
                slotCheckField |= 1 << gReadWriteSector->id;
            }
        }
    }

    if (securityPassed)
    {
        if (slotCheckField == 0x3FFF)
            saveSlot1Status = SAVE_STATUS_OK;
        else
            saveSlot1Status = SAVE_STATUS_ERROR;
    }
    else
    {
        saveSlot1Status = SAVE_STATUS_EMPTY;
    }

    slotCheckField = 0;
    securityPassed = FALSE;

    // check save slot 2.
    for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
    {
        DoReadFlashWholeSection(i + SECTOR_SAVE_SLOT_LENGTH, gReadWriteSector);
        if (gReadWriteSector->security == SECTOR_SIGNATURE)
        {
            securityPassed = TRUE;
            checksum = CalculateChecksum(gReadWriteSector->data, location[gReadWriteSector->id].size);
            if (gReadWriteSector->checksum == checksum)
            {
                saveSlot2Counter = gReadWriteSector->counter;
                slotCheckField |= 1 << gReadWriteSector->id;
            }
        }
    }

    if (securityPassed)
    {
        if (slotCheckField == 0x3FFF)
            saveSlot2Status = SAVE_STATUS_OK;
        else
            saveSlot2Status = SAVE_STATUS_ERROR;
    }
    else
    {
        saveSlot2Status = SAVE_STATUS_EMPTY;
    }

    if (saveSlot1Status == SAVE_STATUS_OK && saveSlot2Status == SAVE_STATUS_OK)
    {
        if ((saveSlot1Counter == -1 && saveSlot2Counter == 0) || (saveSlot1Counter == 0 && saveSlot2Counter == -1))
        {
            if ((unsigned)(saveSlot1Counter + 1) < (unsigned)(saveSlot2Counter + 1))
                gSaveCounter = saveSlot2Counter;
            else
                gSaveCounter = saveSlot1Counter;
        }
        else
        {
            if (saveSlot1Counter < saveSlot2Counter)
                gSaveCounter = saveSlot2Counter;
            else
                gSaveCounter = saveSlot1Counter;
        }
        return SAVE_STATUS_OK;
    }

    if (saveSlot1Status == SAVE_STATUS_OK)
    {
        gSaveCounter = saveSlot1Counter;
        if (saveSlot2Status == SAVE_STATUS_ERROR)
            return SAVE_STATUS_ERROR;
        return SAVE_STATUS_OK;
    }

    if (saveSlot2Status == SAVE_STATUS_OK)
    {
        gSaveCounter = saveSlot2Counter;
        if (saveSlot1Status == SAVE_STATUS_ERROR)
            return SAVE_STATUS_ERROR;
        return SAVE_STATUS_OK;
    }

    if (saveSlot1Status == SAVE_STATUS_EMPTY && saveSlot2Status == SAVE_STATUS_EMPTY)
    {
        gSaveCounter = 0;
        gLastWrittenSector = 0;
        return SAVE_STATUS_EMPTY;
    }

    gSaveCounter = 0;
    gLastWrittenSector = 0;
    return SAVE_STATUS_CORRUPT;
}

static u8 sub_81530DC(u8 sectorId, u8 *data, u16 size)
{
    u16 i;
    struct SaveSector *section = &gSaveDataBuffer;
    DoReadFlashWholeSection(sectorId, section);
    if (section->security == SECTOR_SIGNATURE)
    {
        u16 checksum = CalculateChecksum(section->data, size);
        if (section->id == checksum)
        {
            for (i = 0; i < size; i++)
                data[i] = section->data[i];
            return SAVE_STATUS_OK;
        }
        else
        {
            return SAVE_STATUS_CORRUPT;
        }
    }
    else
    {
        return SAVE_STATUS_EMPTY;
    }
}

// Return value always ignored
static bool8 DoReadFlashWholeSection(u8 sector, struct SaveSector *section)
{
    ReadFlash(sector, 0, section->data, sizeof(struct SaveSector));
    return TRUE;
}

static u16 CalculateChecksum(void *data, u16 size)
{
    u16 i;
    u32 checksum = 0;

    for (i = 0; i < (size / 4); i++)
    {
        checksum += *((u32 *)data);
        data += sizeof(u32);
    }

    return ((checksum >> 16) + checksum);
}

static void UpdateSaveAddresses(void)
{
    int i = 0;

    gRamSaveSectionLocations[i].data = (void*)(gSaveBlock2Ptr) + sSaveSectionOffsets[i].toAdd;
    gRamSaveSectionLocations[i].size = sSaveSectionOffsets[i].size;

    for (i = SECTOR_ID_SAVEBLOCK1_START; i <= SECTOR_ID_SAVEBLOCK1_END; i++)
    {
        gRamSaveSectionLocations[i].data = (void*)(gSaveBlock1Ptr) + sSaveSectionOffsets[i].toAdd;
        gRamSaveSectionLocations[i].size = sSaveSectionOffsets[i].size;
    }

    for (; i <= SECTOR_ID_PKMN_STORAGE_END; i++) //setting i to SECTOR_ID_PKMN_STORAGE_START does not match
    {
        gRamSaveSectionLocations[i].data = (void*)(gPokemonStoragePtr) + sSaveSectionOffsets[i].toAdd;
        gRamSaveSectionLocations[i].size = sSaveSectionOffsets[i].size;
    }
}

u8 HandleSavingData(u8 saveType)
{
    u8 i;
    u32 *backupVar = gTrainerHillVBlankCounter;
    u8 *tempAddr;

    gTrainerHillVBlankCounter = NULL;
    UpdateSaveAddresses();
    switch (saveType)
    {
    case SAVE_HALL_OF_FAME_ERASE_BEFORE: // deletes HOF before overwriting HOF completely. unused
        for (i = SECTOR_ID_HOF_1; i < SECTORS_COUNT; i++)
            EraseFlashSector(i);
    case SAVE_HALL_OF_FAME: // hall of fame.
        if (GetGameStat(GAME_STAT_ENTERED_HOF) < 999)
            IncrementGameStat(GAME_STAT_ENTERED_HOF);
        SaveSerializedGame();
        SaveWriteToFlash(FULL_SAVE_SLOT, gRamSaveSectionLocations);
        tempAddr = gDecompressionBuffer;
        HandleWriteSectorNBytes(SECTOR_ID_HOF_1, tempAddr, SECTOR_DATA_SIZE);
        HandleWriteSectorNBytes(SECTOR_ID_HOF_2, tempAddr + SECTOR_DATA_SIZE, SECTOR_DATA_SIZE);
        break;
    case SAVE_NORMAL: // normal save. also called by overwriting your own save.
    default:
        SaveSerializedGame();
        SaveWriteToFlash(FULL_SAVE_SLOT, gRamSaveSectionLocations);
        break;
    case SAVE_LINK:  // Link and Battle Frontier
    case SAVE_LINK2: // Unused
        SaveSerializedGame();
        for(i = SECTOR_ID_SAVEBLOCK2; i <= SECTOR_ID_SAVEBLOCK1_END; i++)
            HandleReplaceSector(i, gRamSaveSectionLocations);
        for(i = SECTOR_ID_SAVEBLOCK2; i <= SECTOR_ID_SAVEBLOCK1_END; i++)
            WriteSectorSignatureByte_NoOffset(i, gRamSaveSectionLocations);
        break;
    // Support for Ereader was removed in Emerald.
    /*
    case EREADER_SAVE: // used in mossdeep "game corner" before/after battling old man e-reader trainer
        SaveSerializedGame();
        SaveWriteToFlash(0, gRamSaveSectionLocations);
        break;
    */
    case SAVE_OVERWRITE_DIFFERENT_FILE:
        for (i = SECTOR_ID_HOF_1; i < SECTORS_COUNT; i++)
            EraseFlashSector(i); // erase HOF.
        SaveSerializedGame();
        SaveWriteToFlash(FULL_SAVE_SLOT, gRamSaveSectionLocations);
        break;
    }
    gTrainerHillVBlankCounter = backupVar;
    return 0;
}

u8 TrySavingData(u8 saveType)
{
    if (gFlashMemoryPresent != TRUE)
    {
        gSaveAttemptStatus = SAVE_STATUS_ERROR;
        return SAVE_STATUS_ERROR;
    }

    HandleSavingData(saveType);
    if (!gDamagedSaveSectors)
    {
        gSaveAttemptStatus = SAVE_STATUS_OK;
        return SAVE_STATUS_OK;
    }
    else
    {
        DoSaveFailedScreen(saveType);
        gSaveAttemptStatus = SAVE_STATUS_ERROR;
        return SAVE_STATUS_ERROR;
    }
}

bool8 LinkFullSave_Init(void) // trade.c
{
    if (gFlashMemoryPresent != TRUE)
        return TRUE;
    UpdateSaveAddresses();
    SaveSerializedGame();
    RestoreSaveBackupVarsAndIncrement(gRamSaveSectionLocations);
    return FALSE;
}

bool8 LinkFullSave_WriteSector(void) // trade.c
{
    u8 status = HandleWriteIncrementalSector(SECTOR_SAVE_SLOT_LENGTH, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(SAVE_NORMAL);
    if (status == SAVE_STATUS_ERROR)
        return TRUE;
    else
        return FALSE;
}

bool8 LinkFullSave_ReplaceLastSector(void) // trade.c
{
    HandleReplaceSectorAndVerify(SECTOR_SAVE_SLOT_LENGTH, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(SAVE_NORMAL);
    return FALSE;
}

bool8 LinkFullSave_SetLastSectorSignature(void) // trade.c
{
    CopySectorSignatureByte(SECTOR_SAVE_SLOT_LENGTH, gRamSaveSectionLocations);
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(SAVE_NORMAL);
    return FALSE;
}

u8 WriteSaveBlock2(void)
{
    if (gFlashMemoryPresent != TRUE)
        return TRUE;

    UpdateSaveAddresses();
    SaveSerializedGame();
    RestoreSaveBackupVars(gRamSaveSectionLocations);
    HandleReplaceSectorAndVerify(gIncrementalSectorId + 1, gRamSaveSectionLocations);
    return FALSE;
}

bool8 WriteSaveBlock1Sector(void)
{
    u8 retVal = FALSE;
    u16 sectorId = ++gIncrementalSectorId;
    if (sectorId <= SECTOR_ID_SAVEBLOCK1_END)
    {
        HandleReplaceSectorAndVerify(gIncrementalSectorId + 1, gRamSaveSectionLocations);
        WriteSectorSignatureByte(sectorId, gRamSaveSectionLocations);
    }
    else
    {
        WriteSectorSignatureByte(sectorId, gRamSaveSectionLocations);
        retVal = TRUE;
    }
    if (gDamagedSaveSectors)
        DoSaveFailedScreen(SAVE_LINK);
    return retVal;
}

u8 LoadGameSave(u8 saveType)
{
    u8 status;

    if (gFlashMemoryPresent != TRUE)
    {
        gSaveFileStatus = SAVE_STATUS_NO_FLASH;
        return SAVE_STATUS_ERROR;
    }

    UpdateSaveAddresses();
    switch (saveType)
    {
    case SAVE_NORMAL:
    default:
        status = TryLoadSaveSlot(FULL_SAVE_SLOT, gRamSaveSectionLocations);
        LoadSerializedGame();
        gSaveFileStatus = status;
        gGameContinueCallback = 0;
        break;
    case SAVE_HALL_OF_FAME:
        status = sub_81530DC(SECTOR_ID_HOF_1, gDecompressionBuffer, SECTOR_DATA_SIZE);
        if (status == SAVE_STATUS_OK)
            status = sub_81530DC(SECTOR_ID_HOF_2, gDecompressionBuffer + SECTOR_DATA_SIZE, SECTOR_DATA_SIZE);
        break;
    }

    return status;
}

u16 GetSaveBlocksPointersBaseOffset(void)
{
    u16 i, v3;
    struct SaveSector* savSection;

    savSection = gReadWriteSector = &gSaveDataBuffer;
    if (gFlashMemoryPresent != TRUE)
        return SAVE_STATUS_EMPTY;
    UpdateSaveAddresses();
    GetSaveValidStatus(gRamSaveSectionLocations);
    v3 = SECTOR_SAVE_SLOT_LENGTH * (gSaveCounter % NUM_SAVE_SLOTS);
    for (i = 0; i < SECTOR_SAVE_SLOT_LENGTH; i++)
    {
        DoReadFlashWholeSection(i + v3, gReadWriteSector);
        if (gReadWriteSector->id == 0)
            return savSection->data[10] +
                   savSection->data[11] +
                   savSection->data[12] +
                   savSection->data[13];
    }
    return SAVE_STATUS_EMPTY;
}

u32 TryReadSpecialSaveSection(u8 sector, u8* dst)
{
    s32 i;
    s32 size;
    u8* savData;

    if (sector != SECTOR_ID_TRAINER_HILL && sector != SECTOR_ID_RECORDED_BATTLE)
        return SAVE_STATUS_ERROR;
    ReadFlash(sector, 0, (u8 *)&gSaveDataBuffer, sizeof(struct SaveSector));
    if (*(u32*)(&gSaveDataBuffer.data[0]) != SPECIAL_SECTION_SENTINEL)
        return SAVE_STATUS_ERROR;
    // copies whole save section except u32 counter
    i = 0;
    size = 0xFFB;
    savData = &gSaveDataBuffer.data[4];
    for (; i <= size; i++)
        dst[i] = savData[i];
    return SAVE_STATUS_OK;
}

u32 TryWriteSpecialSaveSection(u8 sector, u8* src)
{
    s32 i;
    s32 size;
    u8* savData;
    void* savDataBuffer;

    if (sector != SECTOR_ID_TRAINER_HILL && sector != SECTOR_ID_RECORDED_BATTLE)
        return SAVE_STATUS_ERROR;

    savDataBuffer = &gSaveDataBuffer;
    *(u32*)(savDataBuffer) = SPECIAL_SECTION_SENTINEL;

    // copies whole save section except u32 counter
    i = 0;
    size = 0xFFB;
    savData = &gSaveDataBuffer.data[4];
    for (; i <= size; i++)
        savData[i] = src[i];
    if (ProgramFlashSectorAndVerify(sector, savDataBuffer) != 0)
        return SAVE_STATUS_ERROR;
    return SAVE_STATUS_OK;
}

#define tState       data[0]
#define tTimer       data[1]
#define tPartialSave data[2]

void Task_LinkSave(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        gSoftResetDisabled = TRUE;
        tState = 1;
        break;
    case 1:
        SetLinkStandbyCallback();
        tState = 2;
        break;
    case 2:
        if (IsLinkTaskFinished())
        {
            if (!tPartialSave)
                SaveMapView();
            tState = 3;
        }
        break;
    case 3:
        if (!tPartialSave)
            SetContinueGameWarpStatusToDynamicWarp();
        LinkFullSave_Init();
        tState = 4;
        break;
    case 4:
        if (++tTimer == 5)
        {
            tTimer = 0;
            tState = 5;
        }
        break;
    case 5:
        if (LinkFullSave_WriteSector())
            tState = 6;
        else
            tState = 4;
        break;
    case 6:
        LinkFullSave_ReplaceLastSector();
        tState = 7;
        break;
    case 7:
        if (!tPartialSave)
            ClearContinueGameWarpStatus2();
        SetLinkStandbyCallback();
        tState = 8;
        break;
    case 8:
        if (IsLinkTaskFinished())
        {
            LinkFullSave_SetLastSectorSignature();
            tState = 9;
        }
        break;
    case 9:
        SetLinkStandbyCallback();
        tState = 10;
        break;
    case 10:
        if (IsLinkTaskFinished())
            tState++;
        break;
    case 11:
        if (++tTimer > 5)
        {
            gSoftResetDisabled = FALSE;
            DestroyTask(taskId);
        }
        break;
    }
}

#undef tState
#undef tTimer
#undef tPartialSave
