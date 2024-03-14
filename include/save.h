#ifndef GUARD_SAVE_H
#define GUARD_SAVE_H

// Each 4 KiB flash sector contains 3968 bytes of actual data followed by a 128 byte footer
#define SECTOR_DATA_SIZE 4084
#define SECTOR_FOOTER_SIZE 12
#define SECTOR_SIZE (SECTOR_DATA_SIZE + SECTOR_FOOTER_SIZE)

// Emerald changes this definition to be the sectors per slot.
#define NUM_SECTORS_PER_SLOT 16

// If the sector's signature field is not this value then the sector is either invalid or empty.
#define SECTOR_SIGNATURE 0x8012025
#define SPECIAL_SECTION_SENTINEL 0xB39D

#define FULL_SAVE_SLOT 0xFFFF
#define NUM_SAVE_SLOTS 2

struct SaveSectionLocation
{
    void *data;
    u16 size;
};

struct SaveSector
{
    u8 data[SECTOR_DATA_SIZE];
    u16 id;
    u16 checksum;
    u32 security; // signature
    u32 counter;
}; // size is 0x1000

struct SaveSectionOffsets
{
    u16 toAdd;
    u16 size;
};

// SetDamagedSectorBits states
enum
{
    ENABLE,
    DISABLE,
    CHECK // unused
};

// Do save types
enum
{
    SAVE_NORMAL,
    SAVE_LINK,
    //EREADER_SAVE, // deprecated in Emerald
    SAVE_LINK2, // unknown 2nd link save
    SAVE_HALL_OF_FAME,
    SAVE_OVERWRITE_DIFFERENT_FILE,
    SAVE_HALL_OF_FAME_ERASE_BEFORE // unused
};

#define SECTOR_SIGNATURE_OFFSET offsetof(struct SaveSector, security) // signature
#define SECTOR_COUNTER_OFFSET   offsetof(struct SaveSector, counter)

#define SECTOR_ID_SAVEBLOCK2  0
#define SECTOR_ID_SAVEBLOCK1_START 1
#define SECTOR_ID_SAVEBLOCK1_END   4
#define SECTOR_ID_PKMN_STORAGE_START 5
#define SECTOR_ID_PKMN_STORAGE_END   13
#define SECTOR_SAVE_SLOT_LENGTH 14
// Save Slot 1: 0-13;  Save Slot 2: 14-27
#define SECTOR_ID_HOF_1 28
#define SECTOR_ID_HOF_2 29
#define SECTOR_ID_TRAINER_HILL 30
#define SECTOR_ID_RECORDED_BATTLE  31
#define SECTORS_COUNT 32

#define SAVE_STATUS_EMPTY    0
#define SAVE_STATUS_OK       1
#define SAVE_STATUS_CORRUPT  2
#define SAVE_STATUS_NO_FLASH 4
#define SAVE_STATUS_ERROR    0xFF

extern u16 gLastWrittenSector;
extern u32 gLastSaveCounter;
extern u16 gLastKnownGoodSector;
extern u32 gDamagedSaveSectors;
extern u32 gSaveCounter;
extern struct SaveSector *gReadWriteSector;
extern u16 gIncrementalSectorId;
extern u16 gSaveFileStatus;
extern void (*gGameContinueCallback)(void);
extern struct SaveSectionLocation gRamSaveSectionLocations[];

extern struct SaveSector gSaveDataBuffer;

void ClearSaveData(void);
void Save_ResetSaveCounters(void);
u8 HandleSavingData(u8 saveType);
u8 TrySavingData(u8 saveType);
bool8 LinkFullSave_Init(void);
bool8 LinkFullSave_WriteSector(void);
bool8 LinkFullSave_ReplaceLastSector(void);
bool8 LinkFullSave_SetLastSectorSignature(void);
bool8 WriteSaveBlock2(void);
bool8 WriteSaveBlock1Sector(void);
u8 LoadGameSave(u8 saveType);
u16 GetSaveBlocksPointersBaseOffset(void);
u32 TryReadSpecialSaveSection(u8 sector, u8* dst);
u32 TryWriteSpecialSaveSection(u8 sector, u8* src);
void Task_LinkSave(u8 taskId);

// save_failed_screen.c
void DoSaveFailedScreen(u8 saveType);

#endif // GUARD_SAVE_H
