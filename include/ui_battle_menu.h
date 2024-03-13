#ifndef GUARD_UI_BATTLE_MENU_H
#define GUARD_UI_BATTLE_MENU_H

#include "main.h"

void Task_OpenBattleMenuFromStartMenu(u8 taskId);
void UI_Battle_Menu_Init(MainCallback callback);
void ReshowBattleMenuAfterSummaryScreen(void);
void CB2_SetUpReshowBattleMenuAfterSummaryScreen(void);


#endif // GUARD_UI_BATTLE_MENU_H