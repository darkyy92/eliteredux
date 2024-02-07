# 1 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 4 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_MapScripts:: @ 8241AAA
# 5 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BattleFrontier_BattleTowerCorridor_OnLoad
# 6 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerCorridor_OnFrame
# 7 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	.byte 0
# 8 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 9 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_OnLoad: @ 8241AB5
# 10 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	compare VAR_0x8006, 1
# 11 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerCorridor_EventScript_OpenFarDoor
# 12 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 12, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, 0
# 13 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 12, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, 0
# 14 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 16 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_OpenFarDoor:: @ 8241AD3
# 17 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 15, 0, METATILE_BattleFrontier_CorridorOpenDoor_Top, 0
# 18 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setmetatile 15, 1, METATILE_BattleFrontier_CorridorOpenDoor_Bottom, 0
# 19 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 20 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 21 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_OnFrame: @ 8241AE6
# 22 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor
# 23 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	.2byte 0
# 24 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 25 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_EnterCorridor:: @ 8241AF0
# 26 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 27 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	compare VAR_0x8006, 1
# 28 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerCorridor_EventScript_WalkToFarDoor
# 29 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor
# 30 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor
# 31 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitmovement 0
# 32 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	goto BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom
# 33 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 34 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_WalkToFarDoor:: @ 8241B16
# 35 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor
# 36 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor
# 37 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitmovement 0
# 38 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 39 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom:: @ 8241B27
# 40 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	setvar VAR_TEMP_0, 0
# 41 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 255, 4, 8
# 42 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	waitstate
# 43 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor: @ 8241B36
# 46 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 47 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor: @ 8241B37
# 48 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 49 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 50 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor: @ 8241B39
# 51 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 52 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor: @ 8241B3A
# 53 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 54 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 55 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_right
# 56 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	walk_up
# 57 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	set_invisible
# 58 "data/maps/BattleFrontier_BattleTowerCorridor/scripts.pory"
	step_end
