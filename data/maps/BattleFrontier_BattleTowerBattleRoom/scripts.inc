# 1 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 1
# 3 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT_1, 2
# 4 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT_2, 3
# 5 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 6 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_MapScripts:: @ 8241B40
# 7 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerBattleRoom_OnFrame
# 8 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerBattleRoom_OnWarp
# 9 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.byte 0
# 10 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_OnWarp: @ 8241B4B
# 12 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects
# 13 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.2byte 0
# 14 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 15 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_SetUpObjects:: @ 8241B55
# 16 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 17 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible
# 18 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 20 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_OnFrame: @ 8241B62
# 21 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom
# 22 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.2byte 0
# 23 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_EnterRoom:: @ 8241B6C
# 25 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 26 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter
# 27 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 28 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 29 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 30 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
# 31 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
# 32 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 33 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
# 34 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 35 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 36 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 37 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 38 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 39 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter:: @ 8241BC3
# 40 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setopponent
# 41 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 42 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter
# 43 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 44 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 45 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 46 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 47 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 48 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 49 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent
# 50 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTower_EventScript_WarpToLobbyLost:: @ 8241C03
# 51 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 52 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 53 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 54 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 55 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 56 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 57 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedOpponent:: @ 8241C2F
# 58 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 59 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setbattlewon
# 60 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 61 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 62 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit
# 63 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 64 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 65 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 66 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
# 67 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter
# 68 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer
# 69 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 70 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant
# 71 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 72 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 73 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 74 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 75 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 76 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent:: @ 8241C8F
# 77 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 78 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 79 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
# 80 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext
# 81 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 82 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent
# 83 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 84 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 85 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 86 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 87 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 88 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
# 89 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
# 90 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 91 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 92 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 93 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 94 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponentNoRecord:: @ 8241D0A
# 95 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 96 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 97 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge
# 98 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 99 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 100 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 101 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 102 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle:: @ 8241D40
# 103 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 104 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 105 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 106 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 107 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 108 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle
# 109 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 110 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 111 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_RecordBattle:: @ 8241D72
# 112 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 113 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 114 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 115 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge:: @ 8241D7C
# 116 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 117 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 118 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 119 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge
# 120 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 121 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 122 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge:: @ 8241DAA
# 123 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 124 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 125 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 126 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 127 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 128 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge
# 129 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForOpponent
# 130 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 131 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ContinueChallenge:: @ 8241DDC
# 132 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 133 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
# 134 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 135 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
# 136 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 137 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter
# 138 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 139 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon:: @ 8241DF6
# 140 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 141 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 142 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 143 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 144 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 145 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 146 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_PauseChallenge:: @ 8241E22
# 147 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
# 148 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 149 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 150 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playse SE_SAVE
# 151 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitse
# 152 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 153 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_reset
# 154 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 155 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 156 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyForOpponent:: @ 8241E44
# 157 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 158 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 159 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent
# 160 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent
# 161 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent
# 162 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent
# 163 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent
# 164 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent
# 165 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 166 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor2ndOpponent:: @ 8241E90
# 167 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent
# 168 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 169 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 170 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 171 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor3rdOpponent:: @ 8241E97
# 172 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent
# 173 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 174 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 175 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 176 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor4thOpponent:: @ 8241E9E
# 177 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent
# 178 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 179 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 180 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 181 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor5thOpponent:: @ 8241EA5
# 182 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent
# 183 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 184 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 185 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 186 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor6thOpponent:: @ 8241EAC
# 187 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent
# 188 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 189 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 190 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 191 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_ReadyFor7thOpponent:: @ 8241EB3
# 192 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent
# 193 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 194 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 195 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 196 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_EventScript_IncrementWinStreak:: @ 8241EBA
# 197 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_incrementstreak
# 198 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 199 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 200 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_SecondAttendantEnter:: @ 8241EC3
# 201 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter
# 202 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 203 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, Common_Movement_WalkInPlaceLeft
# 204 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 205 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playse SE_PIN
# 206 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, Common_Movement_ExclamationMark
# 207 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 208 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, Common_Movement_Delay48
# 209 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 210 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay
# 211 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant
# 212 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 213 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit
# 214 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 215 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 216 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 217 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_MaidenUpNext:: @ 8241F0A
# 218 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_TEMP_2, 1
# 219 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 220 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay, MSGBOX_DEFAULT
# 221 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 222 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden:: @ 8241F22
# 223 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden
# 224 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 225 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 226 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 227 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord
# 228 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 229 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 230 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
# 231 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRecordBattle
# 232 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 233 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 234 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 235 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 236 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaidenNoRecord:: @ 8241F79
# 237 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 238 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_RESULT
# 239 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel
# 240 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerBattleRoom_EventScript_AskPauseChallenge
# 241 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerBattleRoom_EventScript_AskRetireChallenge
# 242 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerBattleRoom_EventScript_AskReadyForMaiden
# 243 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 244 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabel:: @ 8241FAF
# 245 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 246 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 247 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle
# 248 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 249 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos
# 250 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 251 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 252 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter
# 253 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmovement 0
# 254 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 255 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro
# 256 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
# 257 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
# 258 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 259 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 260 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver
# 261 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel, MSGBOX_DEFAULT
# 262 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 263 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelSilver:: @ 8242029
# 264 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent, MSGBOX_DEFAULT
# 265 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 266 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 267 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver
# 268 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 269 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 270 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelSilver:: @ 8242046
# 271 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 272 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getsymbols
# 273 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 274 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 275 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized, MSGBOX_DEFAULT
# 276 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 277 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol
# 278 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 279 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 280 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_givesymbol
# 281 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime, MSGBOX_DEFAULT
# 282 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 283 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 284 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_AnabelGoldIntro:: @ 8242085
# 285 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 286 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 287 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold
# 288 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack, MSGBOX_DEFAULT
# 289 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 290 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_BattleAnabelGold:: @ 82420B2
# 291 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe, MSGBOX_DEFAULT
# 292 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 293 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 294 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold
# 295 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 296 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 297 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DefeatedAnabelGold:: @ 82420CF
# 298 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 299 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_getsymbols
# 300 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 301 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 302 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease, MSGBOX_DEFAULT
# 303 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 304 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine
# 305 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitmessage
# 306 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitfanfare
# 307 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_givesymbol
# 308 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain, MSGBOX_DEFAULT
# 309 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyWon
# 310 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 311 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle:: @ 824210E
# 312 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	closemessage
# 313 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 314 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 315 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 316 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_TOWER
# 317 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 318 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 319 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 320 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_FRONTIER_BATTLE_MODE
# 321 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_0x8004, FRONTIER_MODE_LINK_MULTIS
# 322 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle
# 323 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_restorehelditems
# 324 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	special HealPlayerParty
# 325 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_resetsketch
# 326 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle:: @ 824215A
# 327 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_setinterviewdata
# 328 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 329 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 330 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 331 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_EventScript_SetBrainObjectGfx:: @ 8242170
# 332 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	frontier_setbrainobj
# 333 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	return
# 334 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 335 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerEnter: @ 8242179
# 336 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 337 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 338 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 339 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 340 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 341 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 342 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceAttendant: @ 824217E
# 343 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_down
# 344 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 345 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 346 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_PlayerFaceBattle: @ 8242180
# 347 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 348 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 349 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 350 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_OpponentEnter: @ 8242182
# 351 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 352 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 353 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 354 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 355 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_left
# 356 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 357 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_OpponentExit: @ 8242188
# 359 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 360 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 361 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 362 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 363 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 364 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 365 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantApproachPlayer: @ 824218D
# 366 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 367 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 368 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 369 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 370 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 371 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 372 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantReturnToPos: @ 8242192
# 373 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 374 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 375 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 376 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 377 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 378 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 379 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 380 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SetInvisible: @ 8242198
# 381 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_invisible
# 382 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 383 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 384 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantEnter: @ 824219A
# 385 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_visible
# 386 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 387 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_up
# 388 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 389 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_left
# 390 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_8
# 391 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 392 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 393 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantExit: @ 82421A1
# 394 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 395 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_right
# 396 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_down
# 397 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	set_invisible
# 398 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 399 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 400 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_SecondAttendantDelay: @ 82421A6
# 401 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 402 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 403 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 404 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 405 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 406 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AttendantFaceSecondAttendant: @ 82421AB
# 408 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_right
# 409 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 410 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 411 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 412 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	delay_16
# 413 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_in_place_right
# 414 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 415 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 416 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Movement_AnabelEnter: @ 82421B2
# 417 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 418 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 419 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 420 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	walk_slow_down
# 421 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	face_left
# 422 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	step_end
# 423 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 424 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby:: @ 82421B8
# 425 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 426 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_MODE_DOUBLES
# 427 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles
# 428 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_MODE_MULTIS
# 429 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis
# 430 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_MODE_LINK_MULTIS
# 431 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis
# 432 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 6, 6
# 433 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 434 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 435 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 436 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyDoubles:: @ 82421E8
# 437 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 10, 6
# 438 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 439 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 440 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 441 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyMultis:: @ 82421F2
# 442 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 14, 6
# 443 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 444 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 445 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 446 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobbyLinkMultis:: @ 82421FC
# 447 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	tower_closelink
# 448 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_LOBBY, 255, 18, 6
# 449 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	waitstate
# 450 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 451 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 452 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_EventScript_RetireChallenge:: @ 824220E
# 453 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	setflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 454 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 455 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	end
# 456 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 457 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth: @ 8242217
# 458 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "We will restore your Pokémon to\n"
# 459 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "full health.$"
# 460 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 461 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
@ Unused
# 462 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForOpponent: @ 8242244
# 463 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. {STR_VAR_1}.\n"
# 464 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 465 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 466 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor2ndOpponent: @ 8242277
# 467 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 2.\n"
# 468 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 469 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 470 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor3rdOpponent: @ 82422A9
# 471 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 3.\n"
# 472 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 473 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 474 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor4thOpponent: @ 82422DB
# 475 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 4.\n"
# 476 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 477 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 478 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor5thOpponent: @ 824230D
# 479 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 5.\n"
# 480 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 481 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 482 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor6thOpponent: @ 824233F
# 483 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 6.\n"
# 484 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 485 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 486 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyFor7thOpponent: @ 8242371
# 487 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing opponent no. 7.\n"
# 488 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 489 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 490 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle: @ 82423A3
# 491 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Record your battle on your\n"
# 492 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "FRONTIER PASS?$"
# 493 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 494 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass: @ 82423CD
# 495 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "{PLAYER}'s battle was recorded\n"
# 496 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "on the FRONTIER PASS.$"
# 497 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 498 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame: @ 82423FC
# 499 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Would you like to save and\n"
# 500 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "quit the game?$"
# 501 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 502 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait: @ 8242426
# 503 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Saving your battle data.\n"
# 504 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Please wait.$"
# 505 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 506 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge: @ 824244C
# 507 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Would you like to cancel your BATTLE\n"
# 508 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ROOM challenge?$"
# 509 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 510 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved:: @ 8242481
# 511 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "There was an error of some sort.\n"
# 512 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your record could not be saved.$"
# 513 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 514 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_SalonMaidenOnHerWay: @ 82424C2
# 515 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Excuse me, but…\p"
# 516 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Our leader, the SALON MAIDEN, is on\n"
# 517 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "her way here in hopes of battling you.\p"
# 518 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "She should be arriving very shortly.$"
# 519 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 520 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReadyForSalonMaiden: @ 8242542
# 521 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You will be facing the SALON MAIDEN.\n"
# 522 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 523 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 524 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_GreetingsImAnabel: @ 8242579
# 525 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Greetings…\n"
# 526 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "My name is ANABEL.\p"
# 527 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I am the SALON MAIDEN, and I am in\n"
# 528 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "charge of running the Battle Tower…\p"
# 529 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I have heard several rumors\n"
# 530 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "about you…\p"
# 531 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "In all honesty, what I have heard does\n"
# 532 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "not seem attractive in any way…\p"
# 533 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The reason I've come to see you…\n"
# 534 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Well, there is but one reason…$"
# 535 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 536 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_LetMeSeeYourTalent: @ 824268C
# 537 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Let me see your talent in\n"
# 538 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "its entirety…$"
# 539 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 540 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelTalentShallBeRecognized: @ 82426B4
# 541 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: Fufufu, nicely done…\p"
# 542 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please…\n"
# 543 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your talent shall be recognized.$"
# 544 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 545 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_ReceivedAbilitySymbol: @ 824270E
# 546 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The Ability Symbol was embossed on\n"
# 547 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 548 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 549 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_UntilNextTime: @ 8242744
# 550 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 551 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You have confidence in your Pokémon\n"
# 552 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "battling talent, don't you?\p"
# 553 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I urge you to keep battling and\n"
# 554 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "keep on winning.\p"
# 555 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I will be waiting for you.\n"
# 556 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Until the next time we meet…$"
# 557 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 558 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelYouCameBack: @ 82427F9
# 559 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: You really did come back to\n"
# 560 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "see me…\p"
# 561 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 562 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "You've won straight matches to see me…\n"
# 563 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I won't have to hold back against you…\p"
# 564 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "It's been too long now…\p"
# 565 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Too long since I've been able to battle\n"
# 566 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "without thinking about anything…$"
# 567 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 568 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_LetsBeginShallWe: @ 82428E0
# 569 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Let's begin, shall we?$"
# 570 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 571 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AnabelCongratsYourPassPlease: @ 82428F7
# 572 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "ANABEL: Fufu, congratulations…\n"
# 573 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please…$"
# 574 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 575 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_AbilitySymbolTookGoldenShine: @ 8242932
# 576 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "The Ability Symbol took on\n"
# 577 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 578 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"

# 579 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
BattleFrontier_BattleTowerBattleRoom_Text_WishICouldBattleYouAgain: @ 824295D
# 580 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "That was fun…\p"
# 581 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I have never had a Pokémon battle\n"
# 582 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "so enjoyable before…\p"
# 583 "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.pory"
	.string "I wish I could battle with you again…$"
