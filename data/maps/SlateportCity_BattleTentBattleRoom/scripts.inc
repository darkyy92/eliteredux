# 1 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 2 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 2
# 3 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 3
# 4 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 5 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_MapScripts:: @ 8209960
# 6 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_BattleTentBattleRoom_OnTransition
# 7 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentBattleRoom_OnWarp
# 8 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentBattleRoom_OnFrame
# 9 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.byte 0
# 10 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 11 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 12 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_1
# 13 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 14 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnTransition: @ 8209970
# 15 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	call SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfx
# 16 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	end
# 17 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 18 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfx:: @ 8209976
# 19 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	checkplayergender
# 20 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, MALE
# 21 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	goto_if_eq SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxMale
# 22 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	compare VAR_RESULT, FEMALE
# 23 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	goto_if_eq SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale
# 24 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 25 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 26 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxMale:: @ 820998E
# 27 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 28 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 29 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 30 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetPlayerGfxFemale:: @ 8209994
# 31 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 32 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	return
# 33 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 34 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnWarp: @ 820999A
# 35 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentBattleRoom_EventScript_SetUpObjects
# 36 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 37 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 38 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_SetUpObjects:: @ 82099A4
# 39 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 40 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
# 41 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	hideobjectat LOCALID_OPPONENT, MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM
# 42 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	end
# 43 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 44 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_OnFrame: @ 82099B4
# 45 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom
# 46 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	.2byte 0
# 47 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 48 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom:: @ 82099BE
# 49 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_BattleTentBattleRoom_Movement_PlayerEnter
# 50 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	factory_setopponentgfx
# 52 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 5, 1
# 53 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 54 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 55 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, SlateportCity_BattleTentBattleRoom_Movement_OpponentEnter
# 56 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmovement 0
# 57 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	battletent_getopponentintro
# 58 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	lockall
# 59 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 60 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitmessage
# 61 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	closemessage
# 62 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special HealPlayerParty
# 63 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_FACTORY
# 64 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 65 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 66 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 67 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 68 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	case 1, SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent
# 69 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTent_EventScript_WarpToLobbyLost:: @ 8209A1B
# 70 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 71 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 72 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 255, 6, 6
# 73 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 74 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 75 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 76 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent:: @ 8209A39
# 77 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 78 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 79 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 80 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	switch VAR_RESULT
# 81 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	case 3, SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon
# 82 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 83 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 255, 2, 3
# 84 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 85 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 86 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 87 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon:: @ 8209A7B
# 88 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 89 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	special LoadPlayerParty
# 90 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY, 255, 6, 6
# 91 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	waitstate
# 92 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
@ forced stop
# 93 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 94 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_Movement_PlayerEnter: @ 8209A99
# 95 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 96 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 97 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_up
# 98 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 99 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	step_end
# 100 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"

# 101 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
SlateportCity_BattleTentBattleRoom_Movement_OpponentEnter: @ 8209A9E
# 102 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 103 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 104 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 105 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_down
# 106 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 107 "data/maps/SlateportCity_BattleTentBattleRoom/scripts.pory"
	step_end
