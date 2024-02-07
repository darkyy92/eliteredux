# 1 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 4 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_MapScripts:: @ 82419DB
# 5 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerElevator_OnFrame
# 6 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerElevator_OnWarp
# 7 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.byte 0
# 8 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 9 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_OnFrame: @ 82419E6
# 10 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerElevator_EventScript_EnterElevator
# 11 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.2byte 0
# 12 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_EnterElevator:: @ 82419F0
# 14 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerElevator_Movement_AttendantEnter
# 16 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_PlayerEnter
# 17 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitmovement 0
# 18 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	special BufferBattleTowerElevatorFloors
# 19 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitse
# 20 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	special MoveElevator
# 21 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 22 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	delay 48
# 23 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerElevator_Movement_AttendantExit
# 24 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerElevator_Movement_PlayerExit
# 25 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitmovement 0
# 26 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom
# 27 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	end
# 28 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 29 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoom:: @ 8241A28
# 30 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 31 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor
# 32 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 33 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor
# 34 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 35 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti
# 36 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 37 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti
# 38 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 39 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 40 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridor:: @ 8241A55
# 41 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_CORRIDOR, 255, 8, 1
# 42 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 43 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 44 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToNextRoomMulti:: @ 8241A5F
# 46 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	goto_if_unset FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerElevator_EventScript_WarpToPartnerRoom
# 47 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR, 255, 7, 2
# 48 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 49 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 50 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 51 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToCorridorMulti:: @ 8241A72
# 52 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR, 255, 7, 2
# 53 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 54 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 55 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 56 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_WarpToPartnerRoom:: @ 8241A7C
# 57 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 255, 10, 1
# 58 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	waitstate
# 59 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	return
# 60 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 61 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_AttendantEnter: @ 8241A86
# 62 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 63 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_right
# 64 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	face_down
# 65 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 66 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 67 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_PlayerEnter: @ 8241A8A
# 68 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 69 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_up
# 70 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	face_down
# 71 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 72 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 73 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_AttendantExit: @ 8241A8E
# 74 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 75 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 76 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	set_invisible
# 77 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 78 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 79 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_Movement_PlayerExit: @ 8241A92
# 80 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_right
# 81 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 82 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	walk_down
# 83 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	step_end
# 84 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 85 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_OnWarp: @ 8241A96
# 86 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerElevator_EventScript_TurnPlayerNorth
# 87 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	.2byte 0
# 88 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"

# 89 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
BattleFrontier_BattleTowerElevator_EventScript_TurnPlayerNorth:: @ 8241AA0
# 90 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	setvar VAR_TEMP_1, 1
# 91 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 92 "data/maps/BattleFrontier_BattleTowerElevator/scripts.pory"
	end
