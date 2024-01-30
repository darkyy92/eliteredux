# 1 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_BLACK_BELT_1, 1
# 3 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_BLACK_BELT_2, 2
# 4 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_BLACK_BELT_3, 3
# 5 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_BLACK_BELT_4, 4
# 6 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 5
# 7 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 7
# 8 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 8
# 9 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
.set LOCALID_ANNOUNCER, 9
# 10 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_MapScripts:: @ 8257487
# 12 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleArenaBattleRoom_OnTransition
# 13 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaBattleRoom_OnFrame
# 14 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaBattleRoom_OnWarp
# 15 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleArenaBattleRoom_OnResume
# 16 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.byte 0
# 17 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 18 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 19 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_1
# 20 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 21 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnResume: @ 825749C
# 22 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special OffsetCameraForBattle
# 23 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 24 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 25 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnTransition: @ 82574A0
# 26 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_settrainers
# 27 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfx
# 28 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 29 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 30 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfx:: @ 82574AE
# 31 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	checkplayergender
# 32 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, MALE
# 33 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxMale
# 34 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, FEMALE
# 35 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxFemale
# 36 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 37 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 38 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxMale:: @ 82574C6
# 39 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 40 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 41 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 42 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetPlayerGfxFemale:: @ 82574CC
# 43 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 44 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 45 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 46 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnFrame: @ 82574D2
# 47 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_EnterRoom
# 48 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.2byte 0
# 49 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 50 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_EnterRoom:: @ 82574DC
# 51 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	lockall
# 52 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
# 53 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerEnter
# 54 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 55 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 56 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 57 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers
# 58 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown
# 59 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft
# 60 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 61 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 62 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 63 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 64 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers:: @ 825752E
# 65 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	tower_setopponent
# 66 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 67 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentEnter
# 68 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 69 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 70 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 71 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 72 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 73 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward, MSGBOX_DEFAULT
# 74 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 75 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward
# 76 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 77 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 78 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 79 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 80 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 81 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_gettrainername
# 82 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_OpponentStepForward, MSGBOX_DEFAULT
# 83 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 84 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 85 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 86 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 87 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 88 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 89 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 90 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 91 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 92 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward
# 93 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 94 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 95 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	palace_getopponentintro
# 96 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 97 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 98 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 99 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 100 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedOpponent
# 101 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner:: @ 82575DB
# 102 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 103 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_1, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 104 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_2, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 105 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_3, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 106 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_4, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 107 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_SNORE
# 108 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 109 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 110 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_gettrainername
# 111 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent, MSGBOX_DEFAULT
# 112 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_WarpToLobbyLost:: @ 8257615
# 113 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 114 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 8
# 115 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 116 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 117 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedOpponent:: @ 8257630
# 118 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 119 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 120 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 121 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 122 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 123 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 124 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerWalkBackToLine
# 125 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentExit
# 126 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 127 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 128 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown
# 129 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft
# 130 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 131 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored, MSGBOX_DEFAULT
# 132 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special LoadPlayerParty
# 133 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special SavePlayerParty
# 134 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 135 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 136 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 137 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 138 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent:: @ 82576B0
# 139 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 140 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 141 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
# 142 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_TycoonUpNext
# 143 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 144 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 145 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor2ndOpponent
# 146 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 147 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor3rdOpponent
# 148 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 3
# 149 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor4thOpponent
# 150 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 4
# 151 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor5thOpponent
# 152 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 5
# 153 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor6thOpponent
# 154 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 6
# 155 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor7thOpponent
# 156 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 157 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 158 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponentNoRecord
# 159 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 160 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge
# 162 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle
# 163 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 164 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 165 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 166 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 167 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponentNoRecord:: @ 8257768
# 168 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 169 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 170 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge
# 171 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 172 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 173 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 174 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 175 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle:: @ 825779E
# 176 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RecordLastBattle
# 177 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 178 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 179 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 180 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 181 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_RecordBattle
# 182 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 183 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 184 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_RecordBattle:: @ 82577D0
# 185 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 186 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 187 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge:: @ 82577DA
# 189 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown, MSGBOX_YESNO
# 190 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 191 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 192 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleArenaBattleRoom_EventScript_PauseChallenge
# 193 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 194 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 195 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge:: @ 8257808
# 196 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge
# 197 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 198 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 199 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 200 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 201 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_WarpToLobbyLost
# 202 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForOpponent
# 203 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 204 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge:: @ 825783A
# 205 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 206 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 207 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 208 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 209 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers
# 210 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 211 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon:: @ 8257852
# 212 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay 60
# 213 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 214 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 255, 7, 8
# 215 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 216 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 217 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor2ndOpponent:: @ 8257870
# 218 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent
# 219 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 220 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 221 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 222 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor3rdOpponent:: @ 8257877
# 223 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent
# 224 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 225 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 226 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 227 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor4thOpponent:: @ 825787E
# 228 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor4thOpponent
# 229 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 230 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 231 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 232 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor5thOpponent:: @ 8257885
# 233 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor5thOpponent
# 234 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 235 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 236 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 237 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor6thOpponent:: @ 825788C
# 238 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor6thOpponent
# 239 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 240 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 241 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 242 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_ReadyFor7thOpponent:: @ 8257893
# 243 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor7thOpponent
# 244 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 245 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 246 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 247 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_PauseChallenge:: @ 825789A
# 248 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait
# 249 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 250 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	arena_save CHALLENGE_STATUS_PAUSED
# 251 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_SAVE
# 252 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 253 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 254 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_reset
# 255 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 256 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 257 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_TycoonUpNext:: @ 82578BC
# 258 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_TEMP_2, 1
# 259 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 260 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_NowFaceTycoon, MSGBOX_DEFAULT
# 261 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 262 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon:: @ 82578D4
# 263 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_PreparedForTycoon
# 264 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 265 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 266 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 267 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoonNoRecord
# 268 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 269 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 270 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta
# 271 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRecordBattle
# 272 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 273 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 274 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 275 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 276 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoonNoRecord:: @ 825792B
# 277 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 278 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_RESULT
# 279 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta
# 280 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleArenaBattleRoom_EventScript_AskPauseChallenge
# 281 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleArenaBattleRoom_EventScript_AskRetireChallenge
# 282 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaBattleRoom_EventScript_AskReadyForTycoon
# 283 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 284 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGreta:: @ 8257961
# 285 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 286 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 287 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight
# 288 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 289 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 290 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 291 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 292 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 293 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward, MSGBOX_DEFAULT
# 294 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 295 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForwardLong
# 296 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 297 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 298 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 299 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 300 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 301 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MakeWayForGreta, MSGBOX_DEFAULT
# 302 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 303 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 304 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaEnter
# 305 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 306 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward
# 307 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 308 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 309 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleArenaBattleRoom_EventScript_IntroGretaGold
# 310 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver
# 311 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold
# 312 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 313 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 314 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver
# 315 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureChallenger, MSGBOX_DEFAULT
# 316 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 317 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 318 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer
# 319 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 320 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IsThatRight, MSGBOX_DEFAULT
# 321 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 322 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter
# 323 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 324 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_YouLookWeakTakeThingsEasy, MSGBOX_DEFAULT
# 325 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaSilver:: @ 8257A3F
# 326 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IgniteMyPassionForBattle, MSGBOX_DEFAULT
# 327 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle
# 328 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 329 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaSilver
# 330 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner
# 331 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 332 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaSilver:: @ 8257A5C
# 333 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 334 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getsymbols
# 335 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 336 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 337 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong
# 338 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 339 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureToughAfterAll, MSGBOX_DEFAULT
# 340 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 341 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol
# 342 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 343 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 344 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_givesymbol
# 345 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GoingToBeFunNextTime, MSGBOX_DEFAULT
# 346 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 347 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 348 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_IntroGretaGold:: @ 8257AA5
# 349 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 350 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 351 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold
# 352 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaLookingForwardToSeeingAgain, MSGBOX_DEFAULT
# 353 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 354 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 355 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer
# 356 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 357 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SoAreYouReady, MSGBOX_DEFAULT
# 358 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 359 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter
# 360 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 361 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WontAllowHalfheartedEffort, MSGBOX_DEFAULT
# 362 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_BattleGretaGold:: @ 8257AF8
# 363 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_LetsGetThisStarted, MSGBOX_DEFAULT
# 364 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle
# 365 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 366 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaGold
# 367 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_DeclareOpponentWinner
# 368 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 369 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DefeatedGretaGold:: @ 8257B15
# 370 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner
# 371 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_getsymbols
# 372 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 373 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 374 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong
# 375 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 376 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_GretaBlownAway, MSGBOX_DEFAULT
# 377 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 378 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine
# 379 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmessage
# 380 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitfanfare
# 381 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_givesymbol
# 382 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_IfWeBattleAgainWontLose, MSGBOX_DEFAULT
# 383 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	goto BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon
# 384 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 385 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_StartArenaBattle:: @ 8257B5E
# 386 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 387 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 388 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 389 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle:: @ 8257B6C
# 391 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 392 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 393 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 394 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 395 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_ARENA
# 396 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 397 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 398 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitstate
# 399 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_restorehelditems
# 400 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	special HealPlayerParty
# 401 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	frontier_resetsketch
# 402 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 403 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 404 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_DeclarePlayerWinner:: @ 8257BA9
# 405 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 406 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_1, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 407 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_2, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown
# 408 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_3, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 409 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement LOCALID_BLACK_BELT_4, BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp
# 410 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	playse SE_BANG
# 411 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitse
# 412 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	waitmovement 0
# 413 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer, MSGBOX_DEFAULT
# 414 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	closemessage
# 415 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 416 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	return
# 417 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 418 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerEnter: @ 8257BE2
# 419 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 420 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 421 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForwardLong: @ 8257BE4
# 422 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 423 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward: @ 8257BE5
# 424 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 425 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 426 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 427 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_PlayerWalkBackToLine: @ 8257BE7
# 428 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 429 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 430 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 431 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 432 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 433 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceLeft: @ 8257BEB
# 434 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_fastest_up
# 435 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 436 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 437 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight: @ 8257BED
# 438 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 439 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 440 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 441 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentEnter: @ 8257BEF
# 442 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 443 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 444 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong: @ 8257BF1
# 445 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 446 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward: @ 8257BF2
# 447 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_left
# 448 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 449 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 450 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaEnter: @ 8257BF4
# 451 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 452 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 453 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 454 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 455 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_fast_left
# 456 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 457 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 458 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_OpponentExit: @ 8257BFA
# 459 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 460 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 461 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 462 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 463 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 464 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 465 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_right
# 466 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 467 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 468 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceDown: @ 8257C02
# 469 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 470 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	jump_in_place_down
# 471 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 472 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 473 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_JumpInPlaceUp: @ 8257C05
# 474 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 475 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	jump_in_place_up
# 476 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 477 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 478 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceDown: @ 8257C08
# 479 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_fastest_down
# 480 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 481 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 482 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
@ Unused, redundant
# 483 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_WalkInPlaceRight2: @ 8257C0A
# 484 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 485 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 486 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 487 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_OnWarp: @ 8257C0C
# 488 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaBattleRoom_EventScript_SetUpRoomObjects
# 489 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.2byte 0
# 490 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 491 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_EventScript_SetUpRoomObjects:: @ 8257C16
# 492 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_ARENA_BATTLE_ROOM
# 493 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 494 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 495 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
# 496 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 497 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	end
# 498 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 499 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaLookAroundPlayer: @ 8257C30
# 500 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_down
# 501 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 502 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 503 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 504 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 505 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	delay_16
# 506 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_up
# 507 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_up
# 508 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 509 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 510 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 511 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Movement_GretaWalkBackToCenter: @ 8257C3A
# 512 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_down
# 513 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 514 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	step_end
# 515 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 516 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_PlayerStepForward: @ 8257C3D
# 517 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: Trainer {PLAYER}!\n"
# 518 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Step forward, please!$"
# 519 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 520 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_OpponentStepForward: @ 8257C68
# 521 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: Trainer {STR_VAR_1}!\n"
# 522 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Step forward, please!$"
# 523 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 524 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin: @ 8257C93
# 525 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: Set KO Tourney!\n"
# 526 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Begin!$"
# 527 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 528 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer: @ 8257CB3
# 529 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The winner is {PLAYER}!$"
# 530 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 531 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent: @ 8257CCE
# 532 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The winner is {STR_VAR_1}!$"
# 533 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 534 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored: @ 8257CE9
# 535 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Your Pokémon will be restored to\n"
# 536 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "full health.$"
# 537 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 538 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent: @ 8257D17
# 539 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your second opponent!\n"
# 540 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 541 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 542 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent: @ 8257D50
# 543 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your third opponent!\n"
# 544 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 545 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 546 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor4thOpponent: @ 8257D88
# 547 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your fourth opponent!\n"
# 548 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 549 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 550 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor5thOpponent: @ 8257DC1
# 551 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your fifth opponent!\n"
# 552 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 553 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 554 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor6thOpponent: @ 8257DF9
# 555 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your sixth opponent!\n"
# 556 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 557 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 558 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor7thOpponent: @ 8257E31
# 559 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Next up, your seventh opponent!\n"
# 560 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you ready to move on?$"
# 561 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 562 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown: @ 8257E6B
# 563 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to save the game and\n"
# 564 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "shut down now?$"
# 565 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 566 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge: @ 8257E9E
# 567 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to retire from your\n"
# 568 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Set KO Tourney challenge?$"
# 569 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 570 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait: @ 8257EDB
# 571 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I am saving your game data.\n"
# 572 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Please wait.$"
# 573 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 574 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_RecordLastBattle: @ 8257F04
# 575 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Would you like to record your last\n"
# 576 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "battle on your FRONTIER PASS?$"
# 577 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 578 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_NowFaceTycoon: @ 8257F45
# 579 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "My dear challenger!\p"
# 580 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Your skill level is truly astounding!\p"
# 581 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "We now would like you to face our\n"
# 582 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "leader, the ARENA TYCOON!$"
# 583 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 584 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_PreparedForTycoon: @ 8257FBB
# 585 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "A battle with the ARENA TYCOON!\n"
# 586 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you prepared?$"
# 587 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 588 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_MakeWayForGreta: @ 8257FED
# 589 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "REFEREE: The ARENA TYCOON!\n"
# 590 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Make way for GRETA!$"
# 591 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 592 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureChallenger: @ 825801C
# 593 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Hey!\n"
# 594 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Howdy!\p"
# 595 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "…Wait, are you the challenger?$"
# 596 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 597 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IsThatRight: @ 825804E
# 598 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Is that right? Hmm…\n"
# 599 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmhm…$"
# 600 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 601 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_YouLookWeakTakeThingsEasy: @ 8258068
# 602 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I don't know how to say it, but…\n"
# 603 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "To put it bluntly, you look pretty weak.\l"
# 604 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Are you sure you're up for me?\p"
# 605 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmm…\p"
# 606 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Well, all right!\n"
# 607 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "We'll take things easy to start with!$"
# 608 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 609 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IgniteMyPassionForBattle: @ 825810D
# 610 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Okay! Let's see you ignite my passion\n"
# 611 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "for battle!$"
# 612 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 613 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaYoureToughAfterAll: @ 825813F
# 614 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Ow, wait a second!\n"
# 615 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "You are tough after all!\p"
# 616 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I like you!\n"
# 617 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS.$"
# 618 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 619 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_ReceivedGutsSymbol: @ 825819C
# 620 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "The Guts Symbol was embossed on\n"
# 621 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 622 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 623 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GoingToBeFunNextTime: @ 82581CF
# 624 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Hmm…\p"
# 625 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "It's going to be fun the next time!\n"
# 626 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I'm looking forward to it!$"
# 627 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 628 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaLookingForwardToSeeingAgain: @ 8258213
# 629 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Hey! Howdy!\n"
# 630 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "You finally won your way up to me!\p"
# 631 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I was getting worried waiting for you!\n"
# 632 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I was really looking forward to seeing\l"
# 633 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "you again!$"
# 634 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 635 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_SoAreYouReady: @ 82582A2
# 636 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "… … …\n"
# 637 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "So, are you ready?$"
# 638 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 639 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_WontAllowHalfheartedEffort: @ 82582BB
# 640 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "I won't allow a halfhearted effort!\n"
# 641 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Be ready for a thrashing!$"
# 642 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 643 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_LetsGetThisStarted: @ 82582F9
# 644 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Come on, REFEREE!\n"
# 645 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's get this started!$"
# 646 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 647 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GretaBlownAway: @ 8258323
# 648 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "GRETA: Gaaah! Blown away!\n"
# 649 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Let's see your FRONTIER PASS!$"
# 650 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 651 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_GutsSymbolTookGoldenShine: @ 825835B
# 652 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "The Guts Symbol took on\n"
# 653 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 654 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"

# 655 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
BattleFrontier_BattleArenaBattleRoom_Text_IfWeBattleAgainWontLose: @ 8258383
# 656 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Arrrgh!\n"
# 657 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "This is so infuriating!\p"
# 658 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "If we ever battle again, I won't lose!\n"
# 659 "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.pory"
	.string "Don't you forget it! Bye-bye!$"
