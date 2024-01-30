# 1 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 4 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_MapScripts:: @ 8259ABA
# 5 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnFrame
# 6 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryPreBattleRoom_OnWarp
# 7 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.byte 0
# 8 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 9 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_OnWarp: @ 8259AC5
# 10 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects
# 11 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.2byte 0
# 12 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SetUpObjects:: @ 8259ACF
# 14 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, 1
# 16 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth
# 17 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setobjectxy LOCALID_ATTENDANT, 8, 7
# 18 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
# 19 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_TurnPlayerNorth:: @ 8259AEA
# 20 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 21 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 22 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 23 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_OnFrame: @ 8259AEF
# 24 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom
# 25 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.2byte 0
# 26 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 27 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterRoom:: @ 8259AF9
# 28 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, 1
# 29 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle
# 30 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 31 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom
# 32 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom
# 33 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 34 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, 2
# 35 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge
# 36 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generaterentalmons
# 37 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generateopponentmons
# 38 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentmontype
# 39 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8005, VAR_RESULT
# 40 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentstyle
# 41 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 42 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
# 43 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
# 44 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
# 45 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 46 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setswapped
# 47 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_rentmons
# 48 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 49 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom:: @ 8259B74
# 50 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
# 51 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 52 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 53 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_LVL_50
# 54 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50
# 55 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_LVL_OPEN
# 56 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen
# 57 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM, 255, 6, 11
# 59 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 60 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 61 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 62 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReturnToRoomFromBattle:: @ 8259BA5
# 63 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setopponentmons
# 64 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_resethelditems
# 65 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
# 66 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 67 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitfanfare
# 68 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special HealPlayerParty
# 69 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 70 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
# 71 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent
# 72 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 73 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitse
# 74 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments, MSGBOX_DEFAULT
# 75 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 76 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall
# 77 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 78 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo, MSGBOX_DEFAULT
# 79 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 80 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer
# 81 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow, MSGBOX_DEFAULT
# 83 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	closemessage
# 84 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	delay 16
# 85 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 86 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 87 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 88 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent:: @ 8259C13
# 89 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 90 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
# 91 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 92 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForRegularOpponent:: @ 8259C26
# 93 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 94 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 95 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent
# 96 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 97 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent
# 98 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, 3
# 99 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent
# 100 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, 4
# 101 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent
# 102 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, 5
# 103 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent
# 104 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, 6
# 105 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent
# 106 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 107 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 108 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 109 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 110 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 111 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
# 112 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
# 113 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 114 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 115 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 116 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 117 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponentNoRecord:: @ 8259CC6
# 118 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 119 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 120 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon
# 121 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 122 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 123 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 124 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 125 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle:: @ 8259CFC
# 126 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle
# 127 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 128 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 129 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 130 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 131 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle
# 132 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 133 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 134 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_RecordBattle:: @ 8259D2E
# 135 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 136 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 137 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 138 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge:: @ 8259D38
# 139 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 140 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 141 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 142 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge
# 143 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 144 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 145 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge:: @ 8259D66
# 146 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
# 147 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 148 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 149 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 150 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 151 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryBattleRoom_EventScript_WarpToLobbyLost
# 152 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 153 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 154 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapMon:: @ 8259D98
# 155 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_generateopponentmons
# 156 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentmontype
# 157 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8005, VAR_RESULT
# 158 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_getopponentstyle
# 159 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT
# 160 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType
# 161 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle
# 162 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 163 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 164 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 165 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
# 166 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 167 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 168 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons:: @ 8259DF2
# 169 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 170 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_swapmons
# 171 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitstate
# 172 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE  @ Did player keep current pokemon
# 173 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 174 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setswapped
# 175 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
# 176 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 177 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 178 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor2ndOpponent:: @ 8259E1D
# 179 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
# 180 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 181 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 182 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 183 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor3rdOpponent:: @ 8259E24
# 184 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
# 185 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 186 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 187 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor4thOpponent:: @ 8259E2B
# 189 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent
# 190 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 191 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 192 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 193 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor5thOpponent:: @ 8259E32
# 194 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent
# 195 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 196 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 197 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 198 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor6thOpponent:: @ 8259E39
# 199 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent
# 200 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 201 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 202 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 203 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ReadyFor7thOpponent:: @ 8259E40
# 204 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent
# 205 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 206 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 207 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 208 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_PauseChallenge:: @ 8259E47
# 209 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
# 210 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 211 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_save CHALLENGE_STATUS_PAUSED
# 212 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	playse SE_SAVE
# 213 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitse
# 214 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 215 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_reset
# 216 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	end
# 217 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 218 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_ResumeChallenge:: @ 8259E69
# 219 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special SavePlayerParty
# 220 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	factory_setparties 0
# 221 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 222 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	special CalculatePlayerPartyCount
# 223 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForOpponent
# 224 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 225 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentType:: @ 8259E93
# 226 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent, MSGBOX_DEFAULT
# 227 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_NORMAL
# 228 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal
# 229 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_FIGHTING
# 230 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting
# 231 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_FLYING
# 232 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying
# 233 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_POISON
# 234 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison
# 235 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_GROUND
# 236 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround
# 237 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_ROCK
# 238 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock
# 239 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_BUG
# 240 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug
# 241 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_GHOST
# 242 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost
# 243 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_STEEL
# 244 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel
# 245 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_FIRE
# 246 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire
# 247 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_WATER
# 248 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater
# 249 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_GRASS
# 250 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass
# 251 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_ELECTRIC
# 252 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric
# 253 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_PSYCHIC
# 254 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic
# 255 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_ICE
# 256 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce
# 257 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_DRAGON
# 258 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon
# 259 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, TYPE_DARK
# 260 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark
# 261 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8005, NUMBER_OF_MON_TYPES
# 262 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType
# 263 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 264 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 265 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesNormal:: @ 8259F62
# 266 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType, MSGBOX_DEFAULT
# 267 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 268 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 269 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFighting:: @ 8259F6B
# 270 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType, MSGBOX_DEFAULT
# 271 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 272 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 273 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFlying:: @ 8259F74
# 274 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType, MSGBOX_DEFAULT
# 275 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 276 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 277 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPoison:: @ 8259F7D
# 278 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType, MSGBOX_DEFAULT
# 279 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 280 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 281 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGround:: @ 8259F86
# 282 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType, MSGBOX_DEFAULT
# 283 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 284 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 285 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesRock:: @ 8259F8F
# 286 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType, MSGBOX_DEFAULT
# 287 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 288 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 289 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesBug:: @ 8259F98
# 290 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType, MSGBOX_DEFAULT
# 291 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 292 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 293 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGhost:: @ 8259FA1
# 294 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType, MSGBOX_DEFAULT
# 295 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 296 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 297 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesSteel:: @ 8259FAA
# 298 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType, MSGBOX_DEFAULT
# 299 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 300 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 301 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesFire:: @ 8259FB3
# 302 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType, MSGBOX_DEFAULT
# 303 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 304 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 305 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesWater:: @ 8259FBC
# 306 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType, MSGBOX_DEFAULT
# 307 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 308 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 309 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesGrass:: @ 8259FC5
# 310 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType, MSGBOX_DEFAULT
# 311 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 312 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 313 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesElectric:: @ 8259FCE
# 314 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType, MSGBOX_DEFAULT
# 315 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 316 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 317 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesPsychic:: @ 8259FD7
# 318 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType, MSGBOX_DEFAULT
# 319 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 320 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 321 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesIce:: @ 8259FE0
# 322 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType, MSGBOX_DEFAULT
# 323 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 324 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 325 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDragon:: @ 8259FE9
# 326 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType, MSGBOX_DEFAULT
# 327 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 328 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 329 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentUsesDark:: @ 8259FF2
# 330 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType, MSGBOX_DEFAULT
# 331 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 332 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 333 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_OpponentHasNoMostCommonType:: @ 8259FFB
# 334 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite, MSGBOX_DEFAULT
# 335 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 336 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 337 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_CommentOnOpponentStyle:: @ 825A004
# 338 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_STYLE_NONE
# 339 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained
# 340 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_STYLE_PREPARATION
# 341 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation
# 342 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_STYLE_SLOW_STEADY
# 343 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady
# 344 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_STYLE_ENDURANCE
# 345 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance
# 346 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_STYLE_HIGH_RISK
# 347 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk
# 348 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_STYLE_WEAKENING
# 349 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe
# 350 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_STYLE_UNPREDICTABLE
# 351 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict
# 352 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_STYLE_WEATHER
# 353 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow
# 354 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_0x8006, FACTORY_NUM_STYLES
# 355 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible
# 356 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 357 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleUnrestrained:: @ 825A068
# 359 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained, MSGBOX_DEFAULT
# 360 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 361 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 362 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleTotalPreparation:: @ 825A071
# 363 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation, MSGBOX_DEFAULT
# 364 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 365 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 366 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleSlowAndSteady:: @ 825A07A
# 367 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady, MSGBOX_DEFAULT
# 368 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 369 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 370 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleEndurance:: @ 825A083
# 371 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance, MSGBOX_DEFAULT
# 372 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 373 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 374 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleHighRisk:: @ 825A08C
# 375 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk, MSGBOX_DEFAULT
# 376 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 377 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 378 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleWeakenFoe:: @ 825A095
# 379 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe, MSGBOX_DEFAULT
# 380 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 381 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 382 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleImpossibleToPredict:: @ 825A09E
# 383 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict, MSGBOX_DEFAULT
# 384 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 385 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 386 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleDependsOnFlow:: @ 825A0A7
# 387 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow, MSGBOX_DEFAULT
# 388 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 389 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_StyleFlexible:: @ 825A0B0
# 391 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible, MSGBOX_DEFAULT
# 392 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 393 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 394 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead:: @ 825A0B9
# 395 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead
# 396 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	waitmessage
# 397 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 398 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 399 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord
# 400 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 401 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 402 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
# 403 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRecordBattle
# 404 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 405 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 406 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 407 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 408 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHeadNoRecord:: @ 825A110
# 409 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 410 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 411 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead
# 412 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskPauseChallenge
# 413 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskRetireChallenge
# 414 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskReadyForHead
# 415 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 416 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_AskSwapBeforeHead:: @ 825A146
# 417 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead, MSGBOX_DEFAULT
# 418 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 419 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	switch VAR_RESULT
# 420 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 421 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_SwapMons
# 422 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryPreBattleRoom_EventScript_EnterBattleRoom
# 423 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 424 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLv50:: @ 825A17C
# 425 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50
# 426 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50
# 427 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 428 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 429 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_EventScript_WalkToBattleRoomLvOpen:: @ 825A18B
# 430 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen
# 431 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen
# 432 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	return
# 433 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 434 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerEnterRoom: @ 825A19A
# 435 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 436 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 437 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 438 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 439 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 440 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 441 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 442 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLv50: @ 825A1A0
# 443 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 444 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 445 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 446 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 447 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 448 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 449 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 450 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_PlayerWalkToBattleRoomLvOpen: @ 825A1A6
# 451 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 452 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 453 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 454 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 455 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 456 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 457 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 458 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantEnterRoom: @ 825A1AC
# 459 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 460 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 461 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 462 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 463 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 464 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	face_down
# 465 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 466 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 467 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLv50: @ 825A1B3
# 468 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 469 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 470 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 471 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 472 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	set_invisible
# 473 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 474 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 475 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_GuideWalkToBattleRoomLvOpen: @ 825A1B9
# 476 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 477 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 478 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 479 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_up
# 480 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	set_invisible
# 481 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 482 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 483 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantMoveToReceiveCall: @ 825A1BF
# 484 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 485 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 486 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_left
# 487 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 488 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 489 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Movement_AttendantReturnToPlayer: @ 825A1C3
# 490 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 491 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 492 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	walk_right
# 493 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	face_down
# 494 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	step_end
# 495 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 496 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection: @ 825A1C8
# 497 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "First, we will hold your Pokémon for\n"
# 498 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "safekeeping.\p"
# 499 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "You may then choose from our\n"
# 500 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "selection of Pokémon.$"
# 501 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 502 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons: @ 825A22D
# 503 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Thank you for competing!\n"
# 504 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Let us restore your Pokémon!$"
# 505 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 506 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent: @ 825A263
# 507 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 2nd match is next!\n"
# 508 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 509 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 510 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent: @ 825A289
# 511 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 3rd match is next!\n"
# 512 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 513 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 514 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor4thOpponent: @ 825A2AF
# 515 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 4th match is next!\n"
# 516 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 517 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 518 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor5thOpponent: @ 825A2D5
# 519 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 5th match is next!\n"
# 520 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 521 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 522 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor6thOpponent: @ 825A2FB
# 523 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The 6th match is next!\n"
# 524 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 525 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 526 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor7thOpponent: @ 825A321
# 527 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Finally, the 7th match is next!\n"
# 528 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 529 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 530 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame: @ 825A350
# 531 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 532 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "the game?$"
# 533 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 534 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge: @ 825A37A
# 535 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 536 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Battle Swap challenge?$"
# 537 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 538 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_InvestigatedUpcomingOpponent: @ 825A3B4
# 539 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I've conducted a little investigation\n"
# 540 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "about your upcoming opponent.$"
# 541 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 542 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInNormalType: @ 825A3F8
# 543 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 544 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the NORMAL type.$"
# 545 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 546 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFireType: @ 825A43E
# 547 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 548 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FIRE type.$"
# 549 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 550 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInWaterType: @ 825A482
# 551 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 552 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the WATER type.$"
# 553 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 554 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInElectricType: @ 825A4C7
# 555 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 556 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ELECTRIC type.$"
# 557 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 558 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGrassType: @ 825A50F
# 559 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 560 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GRASS type.$"
# 561 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 562 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInIceType: @ 825A554
# 563 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 564 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ICE type.$"
# 565 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 566 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFightingType: @ 825A597
# 567 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 568 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FIGHTING type.$"
# 569 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 570 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPoisonType: @ 825A5DF
# 571 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 572 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the POISON type.$"
# 573 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 574 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGroundType: @ 825A625
# 575 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 576 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GROUND type.$"
# 577 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 578 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInFlyingType: @ 825A66B
# 579 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 580 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the FLYING type.$"
# 581 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 582 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInPsychicType: @ 825A6B1
# 583 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 584 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the Psychic type.$"
# 585 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 586 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInBugType: @ 825A6F8
# 587 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 588 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the BUG type.$"
# 589 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 590 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInRockType: @ 825A73B
# 591 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 592 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the ROCK type.$"
# 593 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 594 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInGhostType: @ 825A77F
# 595 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 596 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the GHOST type.$"
# 597 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 598 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDragonType: @ 825A7C4
# 599 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 600 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the DRAGON type.$"
# 601 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 602 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInDarkType: @ 825A80A
# 603 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 604 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the DARK type.$"
# 605 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 606 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerSkilledInSteelType: @ 825A84E
# 607 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer is apparently skilled\n"
# 608 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "in the handling of the STEEL type.$"
# 609 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 610 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_TrainerHasNoClearFavorite: @ 825A893
# 611 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The Trainer appears to have no clear\n"
# 612 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "favorites when it comes to type.$"
# 613 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 614 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleSlowAndSteady: @ 825A8D9
# 615 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 616 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be slow and steady.$"
# 617 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 618 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleEndurance: @ 825A912
# 619 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 620 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be one of endurance.$"
# 621 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 622 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleHighRisk: @ 825A94C
# 623 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 624 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be high risk, high return.$"
# 625 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 626 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleDependsOnFlow: @ 825A98C
# 627 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 628 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "depend on the battle's flow.$"
# 629 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 630 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleTotalPreparation: @ 825A9CE
# 631 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 632 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be one based on total preparation.$"
# 633 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 634 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleWeakenFoe: @ 825AA16
# 635 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears\n"
# 636 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "to be weakening the foe to start.$"
# 637 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 638 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleFlexible: @ 825AA5A
# 639 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 640 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be flexibly adaptable to the situation.$"
# 641 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 642 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleImpossibleToPredict: @ 825AAA7
# 643 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 644 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be impossible to predict.$"
# 645 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 646 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_StyleUnrestrained: @ 825AAE6
# 647 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The favorite battle style appears to\n"
# 648 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "be free-spirited and unrestrained.$"
# 649 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 650 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon: @ 825AB2E
# 651 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Before starting the battle, would you\n"
# 652 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "like to swap a Pokémon?$"
# 653 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 654 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete: @ 825AB6C
# 655 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Thank you!\n"
# 656 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Your Pokémon swap is complete.$"
# 657 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 658 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay: @ 825AB96
# 659 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Right this way, please!$"
# 660 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 661 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait: @ 825ABAE
# 662 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I am saving your data.\n"
# 663 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Please wait.$"
# 664 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 665 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_RecordLatestBattle: @ 825ABD2
# 666 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Would you like to record your latest\n"
# 667 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "battle on your FRONTIER PASS?$"
# 668 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 669 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_WaitFewMoments: @ 825AC15
# 670 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Excuse me! Excuse me, please!\n"
# 671 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "May I get you to wait a few moments?$"
# 672 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 673 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_UnderstoodSirWillDo: @ 825AC58
# 674 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "…Uh-huh? What?! …Whoa!\n"
# 675 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Understood, sir! Will do!$"
# 676 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 677 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_MessageFromHeadComeRightNow: @ 825AC89
# 678 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Oh, my…\n"
# 679 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Sorry to keep you waiting!\p"
# 680 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I have a message from this facility's\n"
# 681 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "boss, the FACTORY HEAD.\p"
# 682 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "He says, “We're going to do it!\n"
# 683 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Come here right now!”$"
# 684 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 685 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_PreparedToFaceHead: @ 825AD20
# 686 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "The FACTORY HEAD is demanding you.\n"
# 687 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "Are you prepared to face him?$"
# 688 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"

# 689 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
BattleFrontier_BattleFactoryPreBattleRoom_Text_CantTellAnythingAboutHead: @ 825AD61
# 690 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "I'm terribly sorry, but I can't tell you\n"
# 691 "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.pory"
	.string "anything about the FACTORY HEAD.$"
