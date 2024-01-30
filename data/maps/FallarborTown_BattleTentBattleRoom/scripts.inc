# 1 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 2 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 1
# 3 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 2
# 4 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 3
# 5 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 6 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_MapScripts:: @ 8200899
# 7 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_BattleTentBattleRoom_OnTransition
# 8 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentBattleRoom_OnFrame
# 9 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_BattleTentBattleRoom_OnWarp
# 10 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	.byte 0
# 11 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 12 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 13 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	@ The player is represented instead by object event 1, which has the gfx id VAR_OBJ_GFX_ID_1
# 14 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	@ The opponent is represented by object event 3, which has the gfx id VAR_OBJ_GFX_ID_0
# 15 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 16 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnTransition: @ 82008A9
# 17 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 18 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 19 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 20 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfx:: @ 82008AF
# 21 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 22 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, MALE
# 23 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 24 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, FEMALE
# 25 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 26 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 27 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 28 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale:: @ 82008C7
# 29 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 30 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 31 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 32 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 33 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale:: @ 82008D2
# 34 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 35 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 36 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 37 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 38 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnFrame: @ 82008DD
# 39 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentBattleRoom_EventScript_EnterRoom
# 40 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 41 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 42 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_EnterRoom:: @ 82008E7
# 43 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	lockall
# 44 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 45 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerEnter
# 46 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 47 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 48 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 49 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_ne FallarborTown_BattleTentBattleRoom_EventScript_ResumeChallenge
# 50 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_NextOpponentEnter:: @ 820090F
# 51 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	tower_setopponent
# 52 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 53 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, FallarborTown_BattleTentBattleRoom_Movement_OpponentEnter
# 54 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 55 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 56 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_M_BELLY_DRUM
# 57 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 58 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 59 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SetKOTourneyBegin, MSGBOX_DEFAULT
# 60 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 61 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 62 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 63 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call BattleFrontier_BattleArenaBattleRoom_EventScript_DoArenaBattle
# 64 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 65 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 66 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 67 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_M_SNORE
# 68 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 69 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 70 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fallarbortent_getopponentname
# 71 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsOpponent, MSGBOX_DEFAULT
# 72 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost:: @ 820097E
# 73 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 74 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 75 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY, 255, 6, 6
# 76 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 77 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 78 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_DefeatedOpponent:: @ 820099C
# 79 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantJump
# 80 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_BANG
# 81 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 82 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 83 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_WinnerIsPlayer, MSGBOX_DEFAULT
# 84 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 85 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_IncrementBattleNum:: @ 82009B3
# 86 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 87 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 88 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 89 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 90 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 3, FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 91 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, FallarborTown_BattleTentBattleRoom_Movement_OpponentExit
# 92 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 93 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 94 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer
# 95 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 96 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant
# 97 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 98 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_MonsWillBeRestored, MSGBOX_DEFAULT
# 99 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 100 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special SavePlayerParty
# 101 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 102 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 103 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitfanfare
# 104 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 105 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge:: @ 8200A2A
# 106 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 107 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 108 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent
# 109 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 110 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent
# 111 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 112 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 113 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 0, FallarborTown_BattleTentBattleRoom_EventScript_ContinueChallenge
# 114 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_AskPauseChallenge
# 115 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 2, FallarborTown_BattleTentBattleRoom_EventScript_AskRetireChallenge
# 116 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 117 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskPauseChallenge:: @ 8200A78
# 118 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleArenaBattleRoom_Text_SaveAndShutDown, MSGBOX_YESNO
# 119 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 120 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case NO, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 121 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case YES, FallarborTown_BattleTentBattleRoom_EventScript_PauseChallenge
# 122 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 123 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 124 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_AskRetireChallenge:: @ 8200AA6
# 125 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_RetireFromChallenge
# 126 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 127 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 128 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 129 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 1, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 130 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case 0, FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost
# 131 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 132 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 133 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ContinueChallenge:: @ 8200AD8
# 134 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 135 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantReturnToPos
# 136 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 137 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceBattle
# 138 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 139 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto FallarborTown_BattleTentBattleRoom_EventScript_NextOpponentEnter
# 140 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 141 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 142 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon:: @ 8200AF3
# 143 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	delay 60
# 144 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 145 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 146 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY, 255, 6, 6
# 147 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 148 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 149 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ Unreachable code block? The flow into the next block also doesnt make sense
# 150 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	arena_get ARENA_DATA_WIN_STREAK
# 151 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, MAX_STREAK
# 152 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq FallarborTown_BattleTentBattleRoom_EventScript_IncrementBattleNum
# 153 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 154 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	arena_set ARENA_DATA_WIN_STREAK, VAR_RESULT
# 155 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ See above
# 156 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 157 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent:: @ 8200B43
# 158 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor2ndOpponent
# 159 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 160 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 161 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 162 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent:: @ 8200B4A
# 163 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_ReadyFor3rdOpponent
# 164 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 165 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	return
# 166 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 167 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_PauseChallenge:: @ 8200B51
# 168 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattleArenaBattleRoom_Text_SavingPleaseWait
# 169 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 170 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fallarbortent_save CHALLENGE_STATUS_PAUSED
# 171 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	playse SE_SAVE
# 172 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 173 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 174 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	frontier_reset
# 175 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 176 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 177 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_ResumeChallenge:: @ 8200B73
# 178 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer
# 179 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 180 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant
# 181 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 182 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	goto FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 183 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
# 184 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 185 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerEnter: @ 8200B8D
# 186 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 187 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 188 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 189 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 190 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 191 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 192 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceBattle: @ 8200B92
# 193 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 194 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 195 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 196 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_PlayerFaceAttendant: @ 8200B94
# 197 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 198 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 199 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 200 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentEnter: @ 8200B96
# 201 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 202 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 203 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 204 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 205 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 206 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 207 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 208 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
@ Unused
# 209 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentStepForward: @ 8200B9C
# 210 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_left
# 211 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 212 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 213 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_OpponentExit: @ 8200B9E
# 214 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 215 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 216 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 217 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 218 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 219 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 220 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantJump: @ 8200BA3
# 221 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 222 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	jump_in_place_down
# 223 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 224 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 225 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantApproachPlayer: @ 8200BA6
# 226 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 227 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 228 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 229 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 230 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 231 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 232 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_Movement_AttendantReturnToPos: @ 8200BAB
# 233 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 234 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 235 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 236 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	walk_in_place_fastest_down
# 237 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 238 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 239 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_OnWarp: @ 8200BB0
# 240 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, FallarborTown_BattleTentBattleRoom_EventScript_SetUpObjects
# 241 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 242 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"

# 243 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
FallarborTown_BattleTentBattleRoom_EventScript_SetUpObjects:: @ 8200BBA
# 244 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 245 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 246 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 247 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 248 "data/maps/FallarborTown_BattleTentBattleRoom/scripts.pory"
	end
