# 1 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 1
# 3 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 2
# 4 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 3
# 5 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_DUSCLOPS, 4
# 6 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
.set LOCALID_AZURILL, 5
# 7 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 8 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_MapScripts:: @ 824F815
# 9 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePalaceBattleRoom_OnTransition
# 10 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnFrame
# 11 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceBattleRoom_OnWarp
# 12 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.byte 0
# 13 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 14 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 15 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_0
# 16 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	@ The opponent is represented by LOCALID_OPPONENT, which has the gfx id VAR_OBJ_GFX_ID_1
# 17 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 18 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnTransition: @ 824F825
# 19 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_settrainers
# 20 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 21 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 22 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 23 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx:: @ 824F833
# 24 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	checkplayergender
# 25 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, MALE
# 26 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale
# 27 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, FEMALE
# 28 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale
# 29 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 30 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 31 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
@ The opponent's gfx are set to the players by default
# 32 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxMale:: @ 824F84B
# 33 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 34 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 35 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 36 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 37 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfxFemale:: @ 824F856
# 38 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 39 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 40 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 41 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 42 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnFrame: @ 824F861
# 43 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom
# 44 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 45 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 46 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_EnterRoom:: @ 824F86B
# 47 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 48 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 49 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 50 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge
# 51 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge
# 52 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 53 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 54 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 55 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 56 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 57 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 58 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BeginChallenge:: @ 824F8B5
# 59 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom
# 60 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 61 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter:: @ 824F8BF
# 62 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	tower_setopponent
# 63 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 64 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter
# 65 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 66 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_getopponentintro
# 67 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 68 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 69 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 70 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 71 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent
# 72 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost:: @ 824F8FA
# 73 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 74 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby
# 75 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 76 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedOpponent:: @ 824F911
# 77 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 78 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 79 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 80 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 81 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 82 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 83 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit
# 84 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 85 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 86 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 87 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 88 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 89 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
# 90 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special LoadPlayerParty
# 91 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special SavePlayerParty
# 92 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 93 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 94 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 95 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 96 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent:: @ 824F98A
# 97 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 98 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 99 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
# 100 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext
# 101 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 102 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 103 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent
# 104 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 105 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent
# 106 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 3
# 107 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent
# 108 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 4
# 109 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent
# 110 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 5
# 111 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent
# 112 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 6
# 113 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent
# 114 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 115 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 116 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 117 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 118 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 119 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
# 120 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
# 121 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 122 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 123 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 124 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 125 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponentNoRecord:: @ 824FA42
# 126 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 127 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 128 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge
# 129 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 130 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 131 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 132 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 133 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle:: @ 824FA78
# 134 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch
# 135 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 136 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 137 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 138 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 139 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle
# 140 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 141 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 142 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_RecordBattle:: @ 824FAAA
# 143 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 144 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 145 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 146 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge:: @ 824FAB4
# 147 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 148 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 149 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 150 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge
# 151 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 152 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 153 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge:: @ 824FAE2
# 154 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
# 155 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 156 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 157 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 158 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 159 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 160 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForOpponent
# 161 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 162 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ContinueChallenge:: @ 824FB14
# 163 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 164 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 165 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 166 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter
# 167 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 168 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon:: @ 824FB28
# 169 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 170 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby
# 171 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 172 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_PauseChallenge:: @ 824FB3F
# 173 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
# 174 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 175 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_save CHALLENGE_STATUS_PAUSED
# 176 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playse SE_SAVE
# 177 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitse
# 178 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 179 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_reset
# 180 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 181 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 182 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_MavenUpNext:: @ 824FB61
# 183 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_TEMP_2, 1
# 184 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 185 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven, MSGBOX_DEFAULT
# 186 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 187 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven:: @ 824FB79
# 188 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven
# 189 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 190 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 191 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 192 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord
# 193 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 194 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 195 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
# 196 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRecordBattle
# 197 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 198 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 199 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 200 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 201 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMavenNoRecord:: @ 824FBD0
# 202 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 203 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_RESULT
# 204 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser
# 205 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskPauseChallenge
# 206 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskRetireChallenge
# 207 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceBattleRoom_EventScript_AskReadyForMaven
# 208 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 209 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenser:: @ 824FC06
# 210 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 211 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser, MSGBOX_DEFAULT
# 212 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 213 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 214 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight
# 215 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 15, 1
# 216 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 217 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_OPPONENT, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 218 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxy LOCALID_OPPONENT, 13, 1
# 219 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 13, 1
# 220 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter
# 221 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter
# 222 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter
# 223 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 224 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 225 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold
# 226 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
# 227 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
# 228 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 229 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 230 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver
# 231 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro, MSGBOX_DEFAULT
# 232 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 233 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserSilver:: @ 824FCAA
# 234 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons, MSGBOX_DEFAULT
# 235 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 236 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 237 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver
# 238 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 239 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 240 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserSilver:: @ 824FCC7
# 241 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_incrementstreak
# 242 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getsymbols
# 243 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 244 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 245 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle, MSGBOX_DEFAULT
# 246 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 247 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 248 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass, MSGBOX_DEFAULT
# 249 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 250 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol
# 251 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 252 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 253 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_givesymbol
# 254 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, Common_Movement_WalkInPlaceLeft
# 255 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 256 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 257 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestRight
# 258 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 259 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime, MSGBOX_DEFAULT
# 260 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 261 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 262 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_IntroSpenserGold:: @ 824FD3A
# 263 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 264 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 265 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold
# 266 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack, MSGBOX_DEFAULT
# 267 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 268 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_BattleSpenserGold:: @ 824FD67
# 269 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah, MSGBOX_DEFAULT
# 270 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 271 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 272 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold
# 273 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyLost
# 274 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 275 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DefeatedSpenserGold:: @ 824FD84
# 276 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	palace_incrementstreak
# 277 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_getsymbols
# 278 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 279 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 280 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable, MSGBOX_DEFAULT
# 281 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp
# 282 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown
# 283 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass, MSGBOX_DEFAULT
# 284 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 285 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine
# 286 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 287 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitfanfare
# 288 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_givesymbol
# 289 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, Common_Movement_WalkInPlaceLeft
# 290 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 291 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 292 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestRight
# 293 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmovement 0
# 294 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain, MSGBOX_DEFAULT
# 295 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyWon
# 296 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 297 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle:: @ 824FDF7
# 298 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	closemessage
# 299 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 300 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 301 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 302 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PALACE
# 303 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 304 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 305 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 306 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_restorehelditems
# 307 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	special HealPlayerParty
# 308 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	frontier_resetsketch
# 309 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 310 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 311 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_OnWarp: @ 824FE34
# 312 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects
# 313 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.2byte 0
# 314 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 315 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_SetUpRoomObjects:: @ 824FE3E
# 316 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM
# 317 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_SetPlayerGfx
# 318 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 319 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 320 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 321 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_DUSCLOPS, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 322 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	applymovement LOCALID_AZURILL, BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible
# 323 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 324 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 325 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor2ndOpponent:: @ 824FE66
# 326 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 327 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 328 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 329 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 330 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor3rdOpponent:: @ 824FE6D
# 331 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 332 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 333 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 334 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 335 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor4thOpponent:: @ 824FE74
# 336 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent
# 337 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 338 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 339 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 340 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor5thOpponent:: @ 824FE7B
# 341 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent
# 342 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 343 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 344 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 345 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor6thOpponent:: @ 824FE82
# 346 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent
# 347 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 348 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 349 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 350 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_ReadyFor7thOpponent:: @ 824FE89
# 351 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent
# 352 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitmessage
# 353 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	return
# 354 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 355 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SetInvisible: @ 824FE90
# 356 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_invisible
# 357 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 358 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 359 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom: @ 824FE92
# 360 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 361 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 362 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 363 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 364 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 365 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight: @ 824FE97
# 366 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_right
# 367 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 368 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 369 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceUp: @ 824FE99
# 370 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_up
# 371 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 372 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 373 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerReturnToChallenge: @ 824FE9B
# 374 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 375 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 376 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 377 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 378 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 379 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 380 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 381 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentEnter: @ 824FEA1
# 382 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 383 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 384 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 385 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 386 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 387 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 388 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 389 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_OpponentExit: @ 824FEA7
# 390 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 391 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 392 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 393 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_up
# 394 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 395 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 396 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_FaceDown: @ 824FEAC
# 397 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_down
# 398 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 399 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 400 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter1: @ 824FEAE
# 401 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 402 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 403 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 404 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 405 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 406 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 407 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter2: @ 824FEB3
# 408 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 409 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 410 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 411 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 412 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_UnusedOpponentEnter3: @ 824FEB6
# 413 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 414 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 415 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 416 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 417 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 418 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 419 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobby:: @ 824FEBB
# 420 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 421 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_MODE_DOUBLES
# 422 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles
# 423 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 5, 7
# 424 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 425 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 426 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 427 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_EventScript_WarpToLobbyDoubles:: @ 824FED5
# 428 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_LOBBY, 255, 19, 7
# 429 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	waitstate
# 430 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	end
# 431 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 432 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_DusclopsEnter: @ 824FEDF
# 433 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 434 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 435 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 436 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 437 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_right
# 438 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_down
# 439 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 440 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 441 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 442 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_AzurillEnter: @ 824FEE7
# 443 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 444 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 445 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_right
# 446 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 447 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 448 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 449 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 450 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_fast_down
# 451 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 452 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 453 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 454 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 455 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Movement_SpenserEnter: @ 824FEF2
# 456 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 457 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 458 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 459 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 460 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 461 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 462 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	delay_16
# 463 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	set_visible
# 464 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 465 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 466 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 467 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	walk_slow_down
# 468 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	face_left
# 469 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	step_end
# 470 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 471 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons: @ 824FF00
# 472 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Excellent…\n"
# 473 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let me restore your Pokémon.$"
# 474 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 475 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent: @ 824FF28
# 476 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 2nd opponent is next.\n"
# 477 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 478 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 479 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent: @ 824FF54
# 480 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 3rd opponent is next.\n"
# 481 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 482 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 483 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor4thOpponent: @ 824FF80
# 484 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 4th opponent is next.\n"
# 485 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 486 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 487 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor5thOpponent: @ 824FFAC
# 488 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 5th opponent is next.\n"
# 489 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 490 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 491 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor6thOpponent: @ 824FFD8
# 492 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 6th opponent is next.\n"
# 493 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 494 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 495 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor7thOpponent: @ 8250004
# 496 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The 7th opponent is next.\n"
# 497 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 498 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 499 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame: @ 8250030
# 500 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Would you like to save and quit\n"
# 501 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the game?$"
# 502 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 503 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge: @ 825005A
# 504 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to quit your challenge?$"
# 505 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 506 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SavingData: @ 825007E
# 507 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Saving the data.\n"
# 508 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Have patience…$"
# 509 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 510 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_RecordLastMatch: @ 825009E
# 511 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you wish to record your latest\n"
# 512 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 513 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 514 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ChallengingPalaceMaven: @ 82500DD
# 515 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "And now…\p"
# 516 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "By winning consistently, you have\n"
# 517 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "earned the privilege of challenging\l"
# 518 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "our master, the PALACE MAVEN…$"
# 519 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 520 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReadyForPalaceMaven: @ 825014A
# 521 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I shall send for the PALACE MAVEN.\n"
# 522 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 523 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 524 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_AnnounceArrivalOfSpenser: @ 825017C
# 525 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let great fanfare announce the arrival\n"
# 526 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "of the PALACE MAVEN, SPENSER!$"
# 527 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 528 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserFirstIntro: @ 82501C1
# 529 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: My physical being is with\n"
# 530 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Pokémon always!\p"
# 531 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My heart beats as one with\n"
# 532 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Pokémon always!\p"
# 533 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Young one of a Trainer!\n"
# 534 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Do you believe in your Pokémon?\p"
# 535 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Can you believe them through\n"
# 536 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "and through?\p"
# 537 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "If your bonds of trust are frail,\n"
# 538 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "you will never beat my brethren!$"
# 539 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 540 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ProveYourBondWithMons: @ 82502C4
# 541 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The bond you share with your Pokémon!\n"
# 542 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prove it to me here!$"
# 543 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 544 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserPostSilverBattle: @ 82502FF
# 545 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 546 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hah, you never fell for my bluster!\n"
# 547 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Sorry for trying that stunt!\p"
# 548 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 549 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me the thing!$"
# 550 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 551 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_LetsSeeFrontierPass: @ 825036D
# 552 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain that\n"
# 553 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "facade of distinguished authority…\p"
# 554 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 555 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS!$"
# 556 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 557 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_ReceivedSpiritsSymbol: @ 82503DC
# 558 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol was embossed on\n"
# 559 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 560 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 561 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserAwaitNextTime: @ 8250412
# 562 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Your Pokémon's eyes are \n"
# 563 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "truly clear and unclouded.\p"
# 564 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "I will eagerly await the next\n"
# 565 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "opportunity to see you.$"
# 566 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 567 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserThisTimeWontHoldBack: @ 8250485
# 568 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\n"
# 569 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You've battled your way up again?\p"
# 570 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "You must have developed a truly\n"
# 571 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "formidable bond with your Pokémon.\p"
# 572 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "So be it!\p"
# 573 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, I won't bluster or hold back.\n"
# 574 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "This time, there's no fooling around.\p"
# 575 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Ready now?\n"
# 576 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Prepare to lose!$"
# 577 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 578 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_Kaaah: @ 8250572
# 579 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "… … …Kaaah!$"
# 580 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 581 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserYourTeamIsAdmirable: @ 825057E
# 582 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Well, that was some display!\n"
# 583 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Even fully unleashed, my brethren\l"
# 584 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "could not overpower you.\p"
# 585 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Your team spirit is truly admirable!\p"
# 586 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Here!\n"
# 587 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Bring me that thing, will you?$"
# 588 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 589 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_HurryWithFrontierPass: @ 8250629
# 590 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My, my, if only you could maintain\n"
# 591 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a certain level of decorum…\p"
# 592 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Gaaah, here!\n"
# 593 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Hurry with that FRONTIER PASS, you!$"
# 594 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 595 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpiritsSymbolTookGoldenShine: @ 8250699
# 596 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "The Spirits Symbol took on\n"
# 597 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 598 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"

# 599 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
BattleFrontier_BattlePalaceBattleRoom_Text_SpenserComeSeeMeAgain: @ 82506C4
# 600 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "SPENSER: Gwahahah!\p"
# 601 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "Come see me time and again!\n"
# 602 "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.pory"
	.string "My brethren and I will be waiting!$"
