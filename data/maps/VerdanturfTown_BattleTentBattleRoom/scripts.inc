# 1 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 2 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 1
# 3 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 2
# 4 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT, 3
# 5 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 6 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_MapScripts:: @ 82022FA
# 7 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_BattleTentBattleRoom_OnTransition
# 8 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentBattleRoom_OnFrame
# 9 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentBattleRoom_OnWarp
# 10 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.byte 0
# 11 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 12 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 13 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	@ The player is represented instead by object event 1, which has the gfx id VAR_OBJ_GFX_ID_1
# 14 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	@ The opponent is represented by object event 2, which has the gfx id VAR_OBJ_GFX_ID_0
# 15 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 16 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnTransition: @ 820230A
# 17 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 18 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 19 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 20 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx:: @ 8202310
# 21 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 22 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, MALE
# 23 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 24 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, FEMALE
# 25 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_eq VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 26 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 27 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 28 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxMale:: @ 8202328
# 29 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 30 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 31 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 32 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 33 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale:: @ 8202333
# 34 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 35 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 36 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 37 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 38 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnFrame: @ 820233E
# 39 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom
# 40 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 41 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 42 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom:: @ 8202348
# 43 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
# 44 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_PlayerEnter
# 45 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 46 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 47 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 48 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto_if_ne VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 49 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter:: @ 820236F
# 50 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	tower_setopponent
# 51 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 52 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, VerdanturfTown_BattleTentBattleRoom_Movement_OpponentEnter
# 53 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 54 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 55 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 56 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 57 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle
# 58 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 59 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 60 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost:: @ 82023AA
# 61 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 62 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 63 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 255, 6, 6
# 64 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 65 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 66 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent:: @ 82023C8
# 67 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 68 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 69 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 70 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 71 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 3, VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 72 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, VerdanturfTown_BattleTentBattleRoom_Movement_OpponentExit
# 73 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 74 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 75 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestDown
# 76 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 77 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 78 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_LetMeRestoreYourMons, MSGBOX_DEFAULT
# 79 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 80 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special SavePlayerParty
# 81 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 82 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 83 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitfanfare
# 84 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 85 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 86 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge:: @ 820243C
# 87 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 88 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, 1
# 89 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent
# 90 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 91 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call_if_eq VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent
# 92 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 93 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 94 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge
# 95 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge
# 96 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 2, VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge
# 97 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 98 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge:: @ 820248A
# 99 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattlePalaceBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 100 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 101 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case NO, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 102 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case YES, VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge
# 103 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 104 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 105 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge:: @ 82024B8
# 106 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_WishToQuitChallenge
# 107 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 108 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 109 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 110 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 1, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 111 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case 0, VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost
# 112 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge
# 113 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 114 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge:: @ 82024EA
# 115 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestRight
# 116 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 117 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 118 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	closemessage
# 119 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	goto VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter
# 120 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 121 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon:: @ 8202501
# 122 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 123 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 124 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, 255, 6, 6
# 125 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitstate
# 126 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 127 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge:: @ 820251F
# 128 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_SavingData
# 129 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 130 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	verdanturftent_save CHALLENGE_STATUS_PAUSED
# 131 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	playse SE_SAVE
# 132 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitse
# 133 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 134 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	frontier_reset
# 135 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 136 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 137 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_OnWarp: @ 8202541
# 138 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, VerdanturfTown_BattleTentBattleRoom_EventScript_SetUpObjects
# 139 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 140 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 141 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_SetUpObjects:: @ 820254B
# 142 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
# 143 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	call VerdanturfTown_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 144 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 145 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentBattleRoom_Movement_SetInvisible
# 146 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 147 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	end
# 148 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 149 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent:: @ 8202565
# 150 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor2ndOpponent
# 151 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 152 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 153 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 154 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_EventScript_ReadyFor3rdOpponent:: @ 820256C
# 155 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	message BattleFrontier_BattlePalaceBattleRoom_Text_PreparedFor3rdOpponent
# 156 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 157 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	return
# 158 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 159 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_SetInvisible: @ 8202573
# 160 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	set_invisible
# 161 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 162 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 163 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_PlayerEnter: @ 8202575
# 164 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	set_visible
# 165 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 166 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 167 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 168 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	face_right
# 169 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 170 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 171 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_OpponentEnter: @ 820257B
# 172 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 173 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 174 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 175 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_down
# 176 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	face_left
# 177 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
# 178 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"

# 179 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
VerdanturfTown_BattleTentBattleRoom_Movement_OpponentExit: @ 8202581
# 180 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 181 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 182 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 183 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	walk_up
# 184 "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.pory"
	step_end
