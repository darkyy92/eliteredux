#ifndef GUARD_QUESTS_H
#define GUARD_QUESTS_H

//#include constants/quests.h       //included in global.h

//#define FLAG_QUEST_MENU_ACTIVE    0x264 //added to constants/flags.h

#define QUEST_TITLE_NAME_LENGTH  150
#define QUEST_DESC_NAME_LENGTH   150
#define QUEST_NUM_POSSIBLE_STEPS 5

struct SideQuest 
{
    const u8 name[QUEST_TITLE_NAME_LENGTH];
    const u8 desc[QUEST_DESC_NAME_LENGTH];
    const u8 poc[QUEST_DESC_NAME_LENGTH];
    const u8 map[QUEST_DESC_NAME_LENGTH];
    const u8 hint[QUEST_DESC_NAME_LENGTH];
    const u8 reward[QUEST_DESC_NAME_LENGTH];
	u8 difficulty;
	u8 type;
};

extern const struct SideQuest gSideQuests[SIDE_QUEST_COUNT];

enum 
{
	QUEST_DIFFICULTY_EASY,
	QUEST_DIFFICULTY_MEDIUM,
	QUEST_DIFFICULTY_HARD,
	QUEST_DIFFICULTY_EXTREME,
};

enum{
	QUEST_TYPE_MAIN_STORY,
	QUEST_TYPE_OPTIONAL,
};

#define QUEST_STATUS_LOCKED          0
#define QUEST_STATUS_UNLOCKED        1
#define QUEST_STATUS_COMPLETED       253
#define QUEST_STATUS_REWARD_OBTAINED 254

enum QuestCases
{
    FLAG_GET_UNLOCKED,      // check if quest is unlocked
    FLAG_SET_UNLOCKED,      // mark unlocked quest
    FLAG_GET_COMPLETED,     // check if quest is completed
    FLAG_SET_COMPLETED,     // mark completed quest
};

// functions
void CreateItemMenuIcon(u16, u8);
void ResetItemMenuIconState(void);
void DestroyItemMenuIcon(u8 idx);
void Task_OpenQuestMenuFromStartMenu(u8);
s8 GetSetQuestFlag(u8 quest, u8 caseId);
s8 GetActiveQuestIndex(void);
void SetActiveQuest(u8 questId);
void TextWindow_SetStdFrame0_WithPal(u8 windowId, u16 destOffset, u8 palIdx);
void QuestMenu_Init(u8 a0, MainCallback callback);
void SetQuestMenuActive(void);
void ResetActiveQuest(void);
void CopyQuestName(u8 *dst, u8 questId);

#endif // GUARD_QUESTS_H