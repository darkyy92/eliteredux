#include "global.h"
#include "util.h"
#include "main.h"
#include "event_data.h"
#include "easy_chat.h"
#include "script.h"
#include "battle_tower.h"
#include "mevent_news.h"
#include "string_util.h"
#include "new_game.h"
#include "mevent.h"
#include "constants/mevent.h"

static EWRAM_DATA bool32 sStatsEnabled = FALSE;

static void ClearSavedWonderNewsMetadata(void);
static void ClearSavedWonderNews(void);
static bool32 ValidateWonderNews(const struct WonderNews *data);
static bool32 ValidateWonderCard(const struct WonderCard *data);
static void ClearSavedWonderCard(void);
static void ClearSavedWonderCardMetadata(void);
static void ClearSavedTrainerIds(void);
static void IncrementCardStatForNewTrainer(u32 a0, u32 a1, u32 *a2, int a3);

void ClearMysteryGift(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    CpuFill32(0, &gSaveBlock1Ptr->mysteryGift, sizeof(gSaveBlock1Ptr->mysteryGift));
    ClearSavedWonderNewsMetadata();
    #endif
    InitQuestionnaireWords();
}

struct WonderNews *GetSavedWonderNews(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    return &gSaveBlock1Ptr->mysteryGift.wonderNews.data;
    #endif
}

struct WonderCard *GetSavedWonderCard(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    return &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
    #endif
}

struct WonderCardMetadata *GetSavedWonderCardMetadata(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    return &gSaveBlock1Ptr->mysteryGift.cardMetadata.data;
    #endif
}

struct MysteryEventStruct *GetSavedWonderNewsMetadata(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    return &gSaveBlock1Ptr->mysteryGift.newsMetadata;
    #endif
}

u16 *GetQuestionnaireWordsPtr(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    return gSaveBlock1Ptr->mysteryGift.questionnaireWords;
    #endif
}

void ClearSavedWonderNewsAndRelated(void)
{
    ClearSavedWonderNews();
}

bool32 SaveWonderNews(const struct WonderNews *news)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    if (!ValidateWonderNews(news))
        return FALSE;

    ClearSavedWonderNews();
    gSaveBlock1Ptr->mysteryGift.wonderNews.data = *news;
    gSaveBlock1Ptr->mysteryGift.wonderNews.crc = CalcCRC16WithTable((void *)&gSaveBlock1Ptr->mysteryGift.wonderNews.data, sizeof(struct WonderNews));
    return TRUE;
    #else
    return FALSE;
    #endif
}

bool32 ValidateReceivedWonderNews(void)
{
        #ifndef FREE_MYSTERY_EVENT_BUFFERS
    if (CalcCRC16WithTable((void *)&gSaveBlock1Ptr->mysteryGift.wonderNews.data, sizeof(struct WonderNews)) != gSaveBlock1Ptr->mysteryGift.wonderNews.crc)
        return FALSE;
    if (!ValidateWonderNews(&gSaveBlock1Ptr->mysteryGift.wonderNews.data))
        return FALSE;

    return TRUE;
    #else
    return FALSE;
    #endif
}

static bool32 ValidateWonderNews(const struct WonderNews *data)
{
    if (data->unk_00 == 0)
        return FALSE;

    return TRUE;
}

bool32 IsSendingSavedWonderNewsAllowed(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    const struct WonderNews *news = &gSaveBlock1Ptr->mysteryGift.wonderNews.data;
    if (news->unk_02 == 0)
        return FALSE;

    return TRUE;
    #else
    return FALSE;
    #endif
}

static void ClearSavedWonderNews(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    CpuFill32(0, GetSavedWonderNews(), sizeof(gSaveBlock1Ptr->mysteryGift.wonderNews.data));
    gSaveBlock1Ptr->mysteryGift.wonderNews.crc = 0;
    #endif
}

static void ClearSavedWonderNewsMetadata(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    CpuFill32(0, GetSavedWonderNewsMetadata(), sizeof(struct MysteryEventStruct));
    WonderNews_Reset();
    #endif
}

bool32 IsWonderNewsSameAsSaved(const u8 *src)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    const u8 *savedNews = (const u8 *)&gSaveBlock1Ptr->mysteryGift.wonderNews.data;
    u32 i;
    if (!ValidateReceivedWonderNews())
        return FALSE;

    for (i = 0; i < sizeof(struct WonderNews); i++)
    {
        if (savedNews[i] != src[i])
            return FALSE;
    }

    return TRUE;
    #else
    return FALSE;
    #endif
}

void DestroyWonderCard(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    ClearSavedWonderCard();
    ClearSavedWonderCardMetadata();
    ClearSavedTrainerIds();
    ClearRamScript();
    ClearMysteryEventFlags();
    ClearMysteryEventVars();
    ClearEReaderTrainer(&gSaveBlock2Ptr->frontier.ereaderTrainer);
    #endif
}

bool32 SaveWonderCard(const struct WonderCard *card)
{
    return FALSE;
    /*#ifndef FREE_MYSTERY_EVENT_BUFFERS
    struct WonderCardMetadata *metadata;
    if (!ValidateWonderCard(card))
        return FALSE;

    ClearSavedWonderCardAndRelated();
    memcpy(&gSaveBlock1Ptr->mysteryGift.wonderCard.card, card, sizeof(struct WonderCard));
    gSaveBlock1Ptr->mysteryGift.cardCrc = CALC_CRC(gSaveBlock1Ptr->mysteryGift.card);
    metadata = &gSaveBlock1Ptr->mysteryGift.cardMetadata.data;
    metadata->unk_06 = metadata->unk_02;
    return TRUE;
    #else
    return FALSE;
    #endif*/
}

bool32 ValidateReceivedWonderCard(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    if (gSaveBlock1Ptr->mysteryGift.wonderCard.crc != CalcCRC16WithTable((void *)&gSaveBlock1Ptr->mysteryGift.wonderCard.data, sizeof(struct WonderCard)))
        return FALSE;
    if (!ValidateWonderCard(&gSaveBlock1Ptr->mysteryGift.wonderCard.data))
        return FALSE;
    if (!ValidateSavedRamScript())
        return FALSE;

    return TRUE;
    #else
    return FALSE;
    #endif
}

static bool32 ValidateWonderCard(const struct WonderCard *data)
{
    if (data->unk_00 == 0)
        return FALSE;
    if (data->unk_08_0 > 2)
        return FALSE;
    if (!(data->unk_08_6 == 0 || data->unk_08_6 == 1 || data->unk_08_6 == 2))
        return FALSE;
    if (data->unk_08_2 > 7)
        return FALSE;
    if (data->unk_09 > 7)
        return FALSE;

    return TRUE;
}

bool32 IsSendingSavedWonderCardAllowed(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    const struct WonderCard *data = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
    if (data->unk_08_6 == 0)
        return FALSE;

    return TRUE;
    #else
    return FALSE;
    #endif
}

static void ClearSavedWonderCard(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    CpuFill32(0, &gSaveBlock1Ptr->mysteryGift.wonderCard.data, sizeof(struct WonderCard));
    gSaveBlock1Ptr->mysteryGift.wonderCard.crc = 0;
    #endif
}

static void ClearSavedWonderCardMetadata(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    CpuFill32(0, GetSavedWonderCardMetadata(), 18 *sizeof(u16));
    gSaveBlock1Ptr->mysteryGift.cardMetadata.crc = 0;
    #endif
}

u16 GetWonderCardFlagID(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    if (ValidateReceivedWonderCard())
        return gSaveBlock1Ptr->mysteryGift.wonderCard.data.unk_00;
    #endif
    return 0;
}

void WonderCard_ResetInternalReceivedFlag(struct WonderCard *buffer)
{
    if (buffer->unk_08_6 == 1)
        buffer->unk_08_6 = 0;
}

static bool32 IsWonderCardFlagIDInValidRange(u16 a0)
{
    if (a0 >= 1000 && a0 < 1020)
        return TRUE;

    return FALSE;
}

static const u16 sMysteryGiftFlags[] =
{
    FLAG_RECEIVED_AURORA_TICKET,
    FLAG_RECEIVED_MYSTIC_TICKET,
    FLAG_RECEIVED_OLD_SEA_MAP,
    FLAG_RECEIVED_ASH_GRENINJA,
    FLAG_RECEIVED_ZYGARDE_10,
    FLAG_UNUSED_MYSTERY_GIFT_0x13F,
    FLAG_UNUSED_MYSTERY_GIFT_0x140,
    FLAG_UNUSED_MYSTERY_GIFT_0x141,
    FLAG_UNUSED_MYSTERY_GIFT_0x142,
    FLAG_UNUSED_MYSTERY_GIFT_0x143,
    FLAG_UNUSED_MYSTERY_GIFT_0x144,
    FLAG_UNUSED_MYSTERY_GIFT_0x145,
    FLAG_UNUSED_MYSTERY_GIFT_0x146,
    FLAG_UNUSED_MYSTERY_GIFT_0x147,
    FLAG_UNUSED_MYSTERY_GIFT_0x148,
    FLAG_UNUSED_MYSTERY_GIFT_0x149,
    FLAG_UNUSED_MYSTERY_GIFT_0x14A,
    FLAG_UNUSED_MYSTERY_GIFT_0x14B,
    FLAG_UNUSED_MYSTERY_GIFT_0x14C,
    FLAG_UNUSED_MYSTERY_GIFT_0x14D,
};

bool32 CheckReceivedGiftFromWonderCard(void)
{
    u16 value = GetWonderCardFlagID();
    if (!IsWonderCardFlagIDInValidRange(value))
        return FALSE;

    if (FlagGet(sMysteryGiftFlags[value - 1000]) == TRUE)
        return FALSE;

    return TRUE;
}

static int GetNumStampsInMetadata(const struct WonderCardMetadata *data, int size)
{
    int r3 = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (data->unk_08[1][i] && data->unk_08[0][i])
            r3++;
    }

    return r3;
}

static bool32 IsStampInMetadata(const struct WonderCardMetadata *data1, const u16 *data2, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (data1->unk_08[1][i] == data2[1])
            return TRUE;
        if (data1->unk_08[0][i] == data2[0])
            return TRUE;
    }

    return FALSE;
}

static bool32 ValidateStamp(const u16 *data)
{
    if (data[1] == 0)
        return FALSE;
    if (data[0] == SPECIES_NONE)
        return FALSE;
    if (data[0] >= NUM_SPECIES)
        return FALSE;
    return TRUE;
}

static int GetNumStampsInSavedCard(void)
{
    struct WonderCard *data;
    if (!ValidateReceivedWonderCard())
        return 0;
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    data = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
    if (data->unk_08_0 != 1)
        return 0;

    return GetNumStampsInMetadata(&gSaveBlock1Ptr->mysteryGift.cardMetadata.data, data->unk_09);
    #else
    return 0;
    #endif
}

bool32 MysteryGift_TrySaveStamp(const u16 *data)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    struct WonderCard *buffer = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
    int size = buffer->unk_09;
    int i;
    if (!ValidateStamp(data))
        return FALSE;

    if (IsStampInMetadata(&gSaveBlock1Ptr->mysteryGift.cardMetadata.data, data, size))
        return FALSE;

    for (i = 0; i < size; i++)
    {
        if (gSaveBlock1Ptr->mysteryGift.cardMetadata.data.unk_08[1][i] == 0 && gSaveBlock1Ptr->mysteryGift.cardMetadata.data.unk_08[0][i] == 0)
        {
            gSaveBlock1Ptr->mysteryGift.cardMetadata.data.unk_08[1][i] = data[1];
            gSaveBlock1Ptr->mysteryGift.cardMetadata.data.unk_08[0][i] = data[0];
            return TRUE;
        }
    }
    #endif
    return FALSE;
}

#define GAME_DATA_VALID_VAR 0x101
#define GAME_DATA_VALID_GIFT_TYPE_1 (1 << 2)
#define GAME_DATA_VALID_GIFT_TYPE_2 (1 << 9)

void MysteryGift_LoadLinkGameData(struct MysteryGiftLinkGameData *data, bool32 a1)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    int i;
    CpuFill32(0, data, sizeof(struct MysteryGiftLinkGameData));
    data->unk_00 = 0x101;
    data->unk_04 = 1;
    data->unk_08 = 1;

    if (a1)
    {
        data->unk_0C = 5;
        data->unk_10 = 0x0201;
    }
    else
    {
        data->unk_0C = 4;
        data->unk_10 = 0x0200;
    }

    if (ValidateReceivedWonderCard())
    {
        data->unk_14 = GetSavedWonderCard()->unk_00;
        data->unk_20 = *GetSavedWonderCardMetadata();
        data->unk_44 = GetSavedWonderCard()->unk_09;
    }
    else
    {
        data->unk_14 = 0;
    }

    for (i = 0; i < NUM_QUESTIONNAIRE_WORDS; i++)
        data->unk_16[i] = gSaveBlock1Ptr->mysteryGift.questionnaireWords[i];

    CopyTrainerId(data->unk_4C, gSaveBlock2Ptr->playerTrainerId);
    StringCopy(data->unk_45, gSaveBlock2Ptr->playerName);
    for (i = 0; i < 6; i++)
        data->unk_50[i] = gSaveBlock1Ptr->easyChatProfile[i];

    memcpy(data->unk_5C, RomHeaderGameCode, 4);
    data->unk_60 = RomHeaderSoftwareVersion;
    #endif
}

bool32 MysteryGift_ValidateLinkGameData(const struct MysteryGiftLinkGameData *data, bool32 a1)
{
    if (data->unk_00 != GAME_DATA_VALID_VAR)
        return FALSE;

    if (!(data->unk_04 & 1))
        return FALSE;

    if (!(data->unk_08 & 1))
        return FALSE;

    if (!a1)
    {
        if (!(data->unk_0C & GAME_DATA_VALID_GIFT_TYPE_1))
            return FALSE;

        if (!(data->unk_10 & (GAME_DATA_VALID_GIFT_TYPE_2 | 0x180)))
            return FALSE;
    }

    return TRUE;
}

u32 MysteryGift_CompareCardFlags(const u16 *a0, const struct MysteryGiftLinkGameData *a1, const void *unused)
{
    // Has a Wonder Card already?
    if (a1->unk_14 == 0)
        return 0;

    // Has this Wonder Card already?
    if (*a0 == a1->unk_14)
        return 1;

    // Player has a different Wonder Card
    return 2;
}

// This is referenced by the Mystery Gift server, but the instruction it's referenced in is never used,
// so the return values here are never checked by anything.
u32 MysteryGift_CheckStamps(const u16 *a0, const struct MysteryGiftLinkGameData *a1, const void *unused)
{
    int r4 = a1->unk_44 - GetNumStampsInMetadata(&a1->unk_20, a1->unk_44);
    if (r4 == 0)
        return 1;
    if (IsStampInMetadata(&a1->unk_20, a0, a1->unk_44))
        return 3;
    if (r4 == 1)
        return 4;
    return 2;
}

bool32 MysteryGift_DoesQuestionnaireMatch(const struct MysteryGiftLinkGameData *a0, const u16 *a1)
{
    int i;
    for (i = 0; i < NUM_QUESTIONNAIRE_WORDS; i++)
    {
        if (a0->unk_16[i] != a1[i])
            return FALSE;
    }

    return TRUE;
}

static int GetNumStampsInLinkData(const struct MysteryGiftLinkGameData *a0)
{
    return GetNumStampsInMetadata(&a0->unk_20, a0->unk_44);
}

u16 MysteryGift_GetCardStatFromLinkData(const struct MysteryGiftLinkGameData *a0, u32 command)
{
    switch (command)
    {
    case 0:
        return a0->unk_20.unk_00;
    case 1:
        return a0->unk_20.unk_02;
    case 2:
        return a0->unk_20.unk_04;
    case 3:
        return GetNumStampsInLinkData(a0);
    case 4:
        return a0->unk_44;
    default:
        AGB_ASSERT(0);
        return 0;
    }
}

static void IncrementCardStat(u32 command)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    struct WonderCard *data = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
    if (data->unk_08_0 == 2)
    {
        u16 *dest = NULL;
        switch (command)
        {
        case 0:
            dest = &gSaveBlock1Ptr->mysteryGift.cardMetadata.data.unk_00;
            break;
        case 1:
            dest = &gSaveBlock1Ptr->mysteryGift.cardMetadata.data.unk_02;
            break;
        case 2:
            dest = &gSaveBlock1Ptr->mysteryGift.cardMetadata.data.unk_04;
            break;
        case 3:
            break;
        case 4:
            break;
        }

        if (dest == NULL)
        {
            AGB_ASSERT(0);
        }
        else if (++(*dest) > 999)
        {
            *dest = 999;
        }
    }
    #endif
}

u16 MysteryGift_GetCardStat(u32 command)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    switch (command)
    {
        case GET_CARD_BATTLES_WON_INTERNAL:
        {
            struct WonderCard *data = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
            if (data->unk_08_0 == 2)
            {
                struct WonderCardMetadata *buffer = &gSaveBlock1Ptr->mysteryGift.cardMetadata.data;
                return buffer->unk_00;
            }
            break;
        }
        case 1: // Never occurs
        {
            struct WonderCard *data = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
            if (data->unk_08_0 == 2)
            {
                struct WonderCardMetadata *buffer = &gSaveBlock1Ptr->mysteryGift.cardMetadata.data;
                return buffer->unk_02;
            }
            break;
        }
        case 2: // Never occurs
        {
            struct WonderCard *data = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
            if (data->unk_08_0 == 2)
            {
                struct WonderCardMetadata *buffer = &gSaveBlock1Ptr->mysteryGift.cardMetadata.data;
                return buffer->unk_04;
            }
            break;
        }
        case GET_NUM_STAMPS_INTERNAL:
        {
            struct WonderCard *data = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
            if (data->unk_08_0 == 1)
                return GetNumStampsInSavedCard();
            break;
        }
        case GET_MAX_STAMPS_INTERNAL:
        {
            struct WonderCard *data = &gSaveBlock1Ptr->mysteryGift.wonderCard.data;
            if (data->unk_08_0 == 1)
                return data->unk_09;
            break;
        }
    }
    #endif
    AGB_ASSERT(0);
    return 0;
}

void MysteryGift_DisableStats(void)
{
    sStatsEnabled = FALSE;
}

bool32 MysteryGift_TryEnableStatsByFlagId(u16 a0)
{
    sStatsEnabled = FALSE;
    if (a0 == 0)
        return FALSE;

    if (!ValidateReceivedWonderCard())
        return FALSE;

    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    if (gSaveBlock1Ptr->mysteryGift.wonderCard.data.unk_00 != a0)
        return FALSE;
    #endif

    sStatsEnabled = TRUE;
    return TRUE;
}

void MysteryGift_TryIncrementStat(u32 a0, u32 a1)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    if (sStatsEnabled)
    {
        switch (a0)
        {
        case 2:
            IncrementCardStatForNewTrainer(2, a1, gSaveBlock1Ptr->mysteryGift.unk_344[1], 5);
            break;
        case 0:
            IncrementCardStatForNewTrainer(0, a1, gSaveBlock1Ptr->mysteryGift.unk_344[0], 5);
            break;
        case 1:
            IncrementCardStatForNewTrainer(1, a1, gSaveBlock1Ptr->mysteryGift.unk_344[0], 5);
            break;
        default:
            AGB_ASSERT(0);
        }
    }
    #endif
}

static void ClearSavedTrainerIds(void)
{
    #ifndef FREE_MYSTERY_EVENT_BUFFERS
    CpuFill32(0, gSaveBlock1Ptr->mysteryGift.unk_344, sizeof(gSaveBlock1Ptr->mysteryGift.unk_344));
    #endif
}

static bool32 RecordTrainerId(u32 a0, u32 *a1, int size)
{
    int i;
    int j;

    for (i = 0; i < size; i++)
    {
        if (a1[i] == a0)
            break;
    }

    if (i == size)
    {
        for (j = size - 1; j > 0; j--)
            a1[j] = a1[j - 1];

        a1[0] = a0;
        return TRUE;
    }
    else
    {
        for (j = i; j > 0; j--)
            a1[j] = a1[j - 1];

        a1[0] = a0;
        return FALSE;
    }
}

static void IncrementCardStatForNewTrainer(u32 a0, u32 a1, u32 *a2, int a3)
{
    if (RecordTrainerId(a1, a2, a3))
        IncrementCardStat(a0);
}
