#ifndef GUARD_MEVENT_H
#define GUARD_MEVENT_H

struct MEvent_Str_1
{
    u16 unk_000;
    size_t unk_004;
    const void * unk_008;
};

struct MEvent_Str_2
{
    u8 fill_00[0x40];
};

struct MysteryGiftLinkGameData
{
    u32 unk_00;
    u16 unk_04;
    u32 unk_08;
    u16 unk_0C;
    u32 unk_10;
    u16 unk_14;
    u16 unk_16[NUM_QUESTIONNAIRE_WORDS];
    struct WonderCardMetadata unk_20;
    u8 unk_44;
    u8 unk_45[7];
    u8 unk_4C[4];
    u16 unk_50[6];
    u8 unk_5C[4];
    u8 unk_60;
};

void ClearMysteryGift(void);
struct WonderNews *GetSavedWonderNews(void);
struct WonderCard *GetSavedWonderCard(void);
struct WonderCardMetadata *GetSavedWonderCardMetadata(void);
struct MysteryEventStruct *GetSavedWonderNewsMetadata(void);
u16 *GetQuestionnaireWordsPtr(void);
void ClearSavedWonderNewsAndRelated(void);
bool32 SaveWonderNews(const struct WonderNews *src);
bool32 ValidateReceivedWonderNews(void);
bool32 IsSendingSavedWonderNewsAllowed(void);
bool32 IsWonderNewsSameAsSaved(const u8 *src);
void DestroyWonderCard(void);
bool32 SaveWonderCard(const struct WonderCard *data);
bool32 ValidateReceivedWonderCard(void);
bool32 IsSendingSavedWonderCardAllowed(void);
u16 GetWonderCardFlagID(void);
void WonderCard_ResetInternalReceivedFlag(struct WonderCard *buffer);
bool32 CheckReceivedGiftFromWonderCard(void);
bool32 MysteryGift_TrySaveStamp(const u16 *data);
void MysteryGift_LoadLinkGameData(struct MysteryGiftLinkGameData *data, bool32 a1);
bool32 MysteryGift_ValidateLinkGameData(const struct MysteryGiftLinkGameData *data, bool32 a1);
u32 MysteryGift_CompareCardFlags(const u16 *a0, const struct MysteryGiftLinkGameData *a1, const void *unused);
u32 MysteryGift_CheckStamps(const u16 *a0, const struct MysteryGiftLinkGameData *a1, const void *unused);
bool32 MysteryGift_DoesQuestionnaireMatch(const struct MysteryGiftLinkGameData *a0, const u16 *a1);
u16 MysteryGift_GetCardStatFromLinkData(const struct MysteryGiftLinkGameData *a0, u32 command);
u16 MysteryGift_GetCardStat(u32 command);
void MysteryGift_DisableStats(void);
bool32 MysteryGift_TryEnableStatsByFlagId(u16 a0);

#endif //GUARD_MEVENT_H
