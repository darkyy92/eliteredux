# 1 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
.set LOCALID_PLAYER, 1
# 3 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
.set LOCALID_ATTENDANT_1, 2
# 4 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
.set LOCALID_ATTENDANT_2, 3
# 5 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
.set LOCALID_PARTNER, 4
# 6 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_MapScripts:: @ 8248D4A
# 8 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiCorridor_OnTransition
# 9 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiCorridor_OnWarp
# 10 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiCorridor_OnFrame
# 11 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.byte 0
# 12 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 13 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 14 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, and has the gfx id VAR_OBJ_GFX_ID_F
# 15 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	@ The multi partner is represented by LOCALID_PARTNER, and has the gfx id VAR_OBJ_GFX_ID_E
# 16 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 17 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnTransition: @ 8248D5A
# 18 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 19 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx
# 20 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 21 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx
# 22 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 23 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetObjGfx:: @ 8248D71
# 25 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	tower_setpartnergfx
# 26 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	checkplayergender
# 27 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	compare VAR_RESULT, FEMALE
# 28 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_SetPlayerGfxFemale
# 29 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 30 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 31 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 32 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetPlayerGfxFemale:: @ 8248D8B
# 33 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
# 34 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 35 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 36 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetLinkPlayerGfx:: @ 8248D91
# 37 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	special SetBattleTowerLinkPlayerGfx
# 38 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 39 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 40 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnWarp: @ 8248D95
# 41 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects
# 42 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.2byte 0
# 43 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 44 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_SetUpObjects:: @ 8248D9F
# 45 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 46 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 47 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	hideobjectat LOCALID_PARTNER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 48 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	special OffsetCameraForBattle
# 49 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 50 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 51 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_OnFrame: @ 8248DB2
# 52 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor
# 53 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	.2byte 0
# 54 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 55 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_EnterCorridor:: @ 8248DBC
# 56 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	lockall
# 57 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 58 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8004, 14  @ x coord of far door, used by DrawDoor
# 59 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8005, 1   @ y coord of far door, used by DrawDoor
# 60 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	opendoor 1, 1
# 61 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 62 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 63 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 64 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	showobjectat LOCALID_PARTNER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR
# 65 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
# 66 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator
# 67 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 68 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 69 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8004, 14  @ x coord of far door, used by DrawDoor
# 70 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_0x8005, 1   @ y coord of far door, used by DrawDoor
# 71 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	closedoor 1, 1
# 72 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 73 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	clearflag FLAG_ENABLE_MULTI_CORRIDOR_DOOR
# 74 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor
# 75 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor
# 76 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor
# 77 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor
# 78 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 79 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay 40
# 80 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, Common_Movement_WalkInPlaceFastestUp
# 81 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, Common_Movement_WalkInPlaceFastestUp
# 82 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 83 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	opendoor 7, 1
# 84 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 85 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
# 86 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor
# 87 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
# 88 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor
# 89 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitmovement 0
# 90 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	closedoor 7, 1
# 91 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitdooranim
# 92 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay 30
# 93 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 94 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom
# 95 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	releaseall
# 96 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	end
# 97 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 98 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToBattleRoom:: @ 8248E71
# 99 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 100 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom
# 101 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 102 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom
# 103 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 104 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToMultiBattleRoom
# 105 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 106 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToLinkMultiBattleRoom
# 107 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 108 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 109 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToNormalBattleRoom:: @ 8248E9E
# 110 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM, 255, 4, 8
# 111 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 112 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 113 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 114 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToMultiBattleRoom:: @ 8248EA8
# 115 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 4, 5
# 116 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 117 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 118 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 119 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
@ Unnecessary duplicate of the above
# 120 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_EventScript_WarpToLinkMultiBattleRoom:: @ 8248EB2
# 121 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM, 255, 4, 5
# 122 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	waitstate
# 123 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	return
# 124 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 125 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerWalkToDoor: @ 8248EBC
# 126 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 127 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 128 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 129 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 130 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 131 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 132 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 133 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 134 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 135 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerWalkToDoor: @ 8248EC4
# 136 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 137 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 138 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 139 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 140 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 141 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 142 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 143 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 144 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 145 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PlayerAttendantWalkToDoor: @ 8248ECC
# 146 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 147 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 148 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 149 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 150 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 151 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_right
# 152 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 153 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_in_place_fastest_right
# 154 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 155 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 156 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_PartnerAttendantWalkToDoor: @ 8248ED5
# 157 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 158 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 159 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 160 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 161 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 162 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_left
# 163 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 164 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_in_place_fastest_left
# 165 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 166 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 167 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_TrainerEnterDoor: @ 8248EDE
# 168 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	delay_16
# 169 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 170 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 171 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	set_invisible
# 172 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 173 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 174 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_AttendantEnterDoor: @ 8248EE3
# 175 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_up
# 176 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	set_invisible
# 177 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
# 178 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"

# 179 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
BattleFrontier_BattleTowerMultiCorridor_Movement_ExitElevator: @ 8248EE6
# 180 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	walk_down
# 181 "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.pory"
	step_end
