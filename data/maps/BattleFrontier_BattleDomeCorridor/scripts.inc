# 1 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 4 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_MapScripts:: @ 824B0FE
# 5 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeCorridor_OnFrame
# 6 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	.byte 0
# 7 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 8 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_OnFrame: @ 824B104
# 9 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor
# 10 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	.2byte 0
# 11 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 12 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_EnterCorridor:: @ 824B10E
# 13 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	delay 16
# 14 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 16 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	compare VAR_RESULT, FRONTIER_LVL_OPEN
# 17 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen
# 18 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50
# 19 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50
# 20 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 21 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	opendoor 13, 3
# 22 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 23 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50
# 24 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50
# 25 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 26 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	closedoor 13, 3
# 27 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 28 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	goto BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom
# 29 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 30 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_WalkToBattleRoomLvOpen:: @ 824B161
# 31 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen
# 32 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen
# 33 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 34 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	opendoor 37, 3
# 35 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 36 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen
# 37 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen
# 38 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 39 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	closedoor 37, 3
# 40 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitdooranim
# 41 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_EventScript_WarpToPreBattleRoom:: @ 824B18F
# 42 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitmovement 0
# 43 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	setvar VAR_0x8006, 0
# 44 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 255, 5, 7
# 45 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	waitstate
# 46 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	end
# 47 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 48 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLv50: @ 824B1A1
# 49 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 50 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 51 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 52 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 53 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 54 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 55 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 56 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 57 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 58 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 59 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 60 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_in_place_fastest_up
# 61 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 62 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 63 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLv50: @ 824B1AE
# 64 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 65 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 66 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 67 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 68 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 69 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLv50: @ 824B1B2
# 70 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 71 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 72 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 73 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 74 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 75 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 76 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 77 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 78 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 79 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_left
# 80 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 81 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 82 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 83 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLv50: @ 824B1BE
# 84 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 85 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 86 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 87 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 88 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerWalkToDoorLvOpen: @ 824B1C1
# 89 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 90 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 91 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 92 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 93 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 94 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 95 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 96 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 97 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 98 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 99 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 100 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 101 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 102 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 103 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 104 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_in_place_fastest_up
# 105 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 106 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 107 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_PlayerEnterDoorLvOpen: @ 824B1D2
# 108 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 109 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 110 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 111 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 112 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 113 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantWalkToDoorLvOpen: @ 824B1D6
# 114 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 115 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 116 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 117 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 118 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 119 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 120 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 121 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 122 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 123 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 124 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 125 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 126 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 127 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 128 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 129 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 130 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 131 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_AttendantEnterDoorLvOpen: @ 824B1E6
# 132 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 133 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 134 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
# 135 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"

# 136 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
@ Unused
# 137 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
BattleFrontier_BattleDomeCorridor_Movement_WalkToBattleRoomMidRight: @ 824B1E9
# 138 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 139 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 140 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 141 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 142 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 143 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 144 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 145 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 146 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 147 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 148 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 149 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_right
# 150 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 151 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	walk_up
# 152 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	set_invisible
# 153 "data/maps/BattleFrontier_BattleDomeCorridor/scripts.pory"
	step_end
