# 1 "data/maps/LittlerootTown/scripts.pory"

# 2 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_TWIN, 1
# 3 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_MOM, 4
# 4 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_BIRCH, 8
# 6 "data/maps/LittlerootTown/scripts.pory"

# 7 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts:: @ 81E7DCB
# 8 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 9 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 10 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 11 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 12 "data/maps/LittlerootTown/scripts.pory"

# 13 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 14 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 15 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 16 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 17 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 18 "data/maps/LittlerootTown/scripts.pory"

# 19 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 20 "data/maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 21 "data/maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 22 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 23 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 24 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 25 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 26 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 27 "data/maps/LittlerootTown/scripts.pory"

# 28 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 29 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 30 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 31 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 32 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 33 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 35 "data/maps/LittlerootTown/scripts.pory"

# 36 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 37 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 38 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 39 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 40 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 41 "data/maps/LittlerootTown/scripts.pory"

# 42 "data/maps/LittlerootTown/scripts.pory"

# 43 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition: @ 81E7DDB
# 44 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_EnableLegendaryNPC
# 45 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 46 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 47 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 2
# 48 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MoveMomToMaysDoor
# 49 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 50 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 3
# 51 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 52 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
# 53 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 54 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
# 55 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 56 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_OLDALE_RIVAL_STATE, 1
# 57 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MoveRivalFromOldale
# 58 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
# 59 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetRivalLeftForRoute103
# 60 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
# 61 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_HideMapNamePopup
# 62 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 63 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 64 "data/maps/LittlerootTown/scripts.pory"
	end
# 65 "data/maps/LittlerootTown/scripts.pory"

# 66 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade:: @ 81E7E45
# 67 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 68 "data/maps/LittlerootTown/scripts.pory"
	return
# 69 "data/maps/LittlerootTown/scripts.pory"

# 70 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup:: @ 81E7E4B
# 71 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 72 "data/maps/LittlerootTown/scripts.pory"
	return
# 73 "data/maps/LittlerootTown/scripts.pory"

# 74 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103:: @ 81E7E4F
# 75 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 76 "data/maps/LittlerootTown/scripts.pory"
	return
# 77 "data/maps/LittlerootTown/scripts.pory"

# 78 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale:: @ 81E7E53
# 79 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 80 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 81 "data/maps/LittlerootTown/scripts.pory"
	return
# 82 "data/maps/LittlerootTown/scripts.pory"

# 83 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent:: @ 81E7E5C
# 84 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 85 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 86 "data/maps/LittlerootTown/scripts.pory"
	return
# 87 "data/maps/LittlerootTown/scripts.pory"

# 88 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor:: @ 81E7E67
# 89 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 8
# 90 "data/maps/LittlerootTown/scripts.pory"
	return
# 91 "data/maps/LittlerootTown/scripts.pory"

# 92 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos:: @ 81E7E6F
# 93 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 0
# 94 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 95 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 10, 1
# 96 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
# 97 "data/maps/LittlerootTown/scripts.pory"
	return
# 98 "data/maps/LittlerootTown/scripts.pory"

# 99 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos:: @ 81E7E86
# 100 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 7, 2
# 101 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 102 "data/maps/LittlerootTown/scripts.pory"
	return
# 103 "data/maps/LittlerootTown/scripts.pory"

# 104 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos:: @ 81E7E92
# 105 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 106 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
# 107 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 108 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 109 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 110 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 111 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 112 "data/maps/LittlerootTown/scripts.pory"
	return
# 113 "data/maps/LittlerootTown/scripts.pory"

# 114 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale:: @ 81E7EB1
# 115 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 5, 9
# 116 "data/maps/LittlerootTown/scripts.pory"
	return
# 117 "data/maps/LittlerootTown/scripts.pory"

# 118 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale:: @ 81E7EB9
# 119 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 9
# 120 "data/maps/LittlerootTown/scripts.pory"
	return
# 121 "data/maps/LittlerootTown/scripts.pory"

# 122 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame: @ 81E7EC1
# 123 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 124 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 125 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 126 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 127 "data/maps/LittlerootTown/scripts.pory"

# 128 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale:: @ 81E7EDB
# 129 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 130 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 131 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 132 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 133 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 134 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 8
# 135 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 136 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 137 "data/maps/LittlerootTown/scripts.pory"
	end
# 138 "data/maps/LittlerootTown/scripts.pory"

# 139 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale:: @ 81E7EF9
# 140 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 141 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 142 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 143 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 144 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 145 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 255, 2, 8
# 146 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 147 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 148 "data/maps/LittlerootTown/scripts.pory"
	end
# 149 "data/maps/LittlerootTown/scripts.pory"

# 150 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom:: @ 81E7F17
# 151 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 152 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 153 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 154 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 155 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 156 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 157 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 158 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
# 159 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 160 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 161 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 162 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 163 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 164 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 165 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 166 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 167 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
# 168 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 169 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 170 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 171 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 172 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
# 173 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 174 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 175 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 176 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 177 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 178 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 179 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 180 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 181 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 182 "data/maps/LittlerootTown/scripts.pory"
	return
# 183 "data/maps/LittlerootTown/scripts.pory"

# 184 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse: @ 81E7F98
# 185 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 186 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 187 "data/maps/LittlerootTown/scripts.pory"

# 188 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck: @ 81E7F9A
# 189 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 190 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_left
# 191 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 192 "data/maps/LittlerootTown/scripts.pory"

# 193 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor: @ 81E7F9D
# 194 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 195 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 196 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 197 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 198 "data/maps/LittlerootTown/scripts.pory"

# 199 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse: @ 81E7FA1
# 200 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 201 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 202 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 203 "data/maps/LittlerootTown/scripts.pory"

# 204 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor: @ 81E7FA4
# 205 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 206 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 207 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 208 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 209 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 210 "data/maps/LittlerootTown/scripts.pory"

# 211 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse: @ 81E7FA9
# 212 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 213 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 214 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 215 "data/maps/LittlerootTown/scripts.pory"

# 216 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck: @ 81E7FAC
# 217 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 218 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 219 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 220 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 221 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 222 "data/maps/LittlerootTown/scripts.pory"

# 223 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene:: @ 81E7FB1
# 224 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 225 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 226 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 227 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 228 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 229 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 230 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 231 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 232 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 233 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 234 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 235 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
# 236 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 237 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 238 "data/maps/LittlerootTown/scripts.pory"
	end
# 239 "data/maps/LittlerootTown/scripts.pory"

# 240 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp: @ 81E7FE2
# 241 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 242 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 243 "data/maps/LittlerootTown/scripts.pory"

# 244 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade:: @ 81E7FEC
# 245 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_BIRCH
# 246 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_RIVAL
# 247 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 248 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 249 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 250 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 251 "data/maps/LittlerootTown/scripts.pory"
	end
# 252 "data/maps/LittlerootTown/scripts.pory"

# 253 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale:: @ 81E8004
# 254 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 6, 10
# 255 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 5, 10
# 256 "data/maps/LittlerootTown/scripts.pory"
	end
# 257 "data/maps/LittlerootTown/scripts.pory"

# 258 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale:: @ 81E8013
# 259 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 13, 10
# 260 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 14, 10
# 261 "data/maps/LittlerootTown/scripts.pory"
	end
# 262 "data/maps/LittlerootTown/scripts.pory"

# 263 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan:: @ 81E8022
# 264 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 265 "data/maps/LittlerootTown/scripts.pory"
	end
# 266 "data/maps/LittlerootTown/scripts.pory"

# 267 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy:: @ 81E802B
# 268 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 269 "data/maps/LittlerootTown/scripts.pory"
	end
# 270 "data/maps/LittlerootTown/scripts.pory"

# 271 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin:: @ 81E8034
# 272 "data/maps/LittlerootTown/scripts.pory"
	lock
# 273 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 274 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 275 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 276 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 0
# 277 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_GoSaveBirch
# 278 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 279 "data/maps/LittlerootTown/scripts.pory"
	release
# 280 "data/maps/LittlerootTown/scripts.pory"
	end
# 281 "data/maps/LittlerootTown/scripts.pory"

# 282 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch:: @ 81E805D
# 283 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 284 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 285 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 286 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 287 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 288 "data/maps/LittlerootTown/scripts.pory"
	release
# 289 "data/maps/LittlerootTown/scripts.pory"
	end
# 290 "data/maps/LittlerootTown/scripts.pory"

# 291 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch:: @ 81E807A
# 292 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 293 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 294 "data/maps/LittlerootTown/scripts.pory"
	release
# 295 "data/maps/LittlerootTown/scripts.pory"
	end
# 296 "data/maps/LittlerootTown/scripts.pory"

# 297 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck:: @ 81E8087
# 298 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 299 "data/maps/LittlerootTown/scripts.pory"
	release
# 300 "data/maps/LittlerootTown/scripts.pory"
	end
# 301 "data/maps/LittlerootTown/scripts.pory"

# 302 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft:: @ 81E8091
# 303 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 304 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 305 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 306 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 307 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 308 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 309 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 310 "data/maps/LittlerootTown/scripts.pory"
	end
# 311 "data/maps/LittlerootTown/scripts.pory"

# 312 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon:: @ 81E80AD
# 313 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 314 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 315 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 316 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 317 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 318 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 319 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 320 "data/maps/LittlerootTown/scripts.pory"
	return
# 321 "data/maps/LittlerootTown/scripts.pory"

# 322 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft: @ 81E80D1
# 323 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 324 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 325 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 326 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 327 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 328 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 329 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 330 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 331 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 332 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 334 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 335 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 336 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 337 "data/maps/LittlerootTown/scripts.pory"

# 338 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute: @ 81E80DF
# 339 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 340 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 341 "data/maps/LittlerootTown/scripts.pory"

# 342 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft: @ 81E80E1
# 343 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 344 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 345 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 346 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 347 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 348 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 349 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 350 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 351 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_down
# 352 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 353 "data/maps/LittlerootTown/scripts.pory"

# 354 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute: @ 81E80EB
# 355 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 356 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 357 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 358 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 359 "data/maps/LittlerootTown/scripts.pory"

# 360 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight:: @ 81E80EF
# 361 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 362 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 363 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 364 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 365 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
# 366 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 367 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 368 "data/maps/LittlerootTown/scripts.pory"
	end
# 369 "data/maps/LittlerootTown/scripts.pory"

# 370 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight: @ 81E810B
# 371 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 372 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 373 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 374 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 375 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 376 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 377 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 378 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 379 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 380 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 381 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 382 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 383 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 384 "data/maps/LittlerootTown/scripts.pory"

# 385 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight: @ 81E8118
# 386 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 387 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 388 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 389 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 390 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 391 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_down
# 392 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 393 "data/maps/LittlerootTown/scripts.pory"

# 394 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger:: @ 81E811F
# 395 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 396 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFastestRight
# 397 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 398 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 399 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 400 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 401 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 402 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 403 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 404 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 405 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 406 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 407 "data/maps/LittlerootTown/scripts.pory"
	end
# 408 "data/maps/LittlerootTown/scripts.pory"

# 409 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign:: @ 81E8151
# 410 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 411 "data/maps/LittlerootTown/scripts.pory"
	end
# 412 "data/maps/LittlerootTown/scripts.pory"

# 413 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign:: @ 81E815A
# 414 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 415 "data/maps/LittlerootTown/scripts.pory"
	end
# 416 "data/maps/LittlerootTown/scripts.pory"

# 417 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign:: @ 81E8163
# 418 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 419 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 420 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 421 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_PlayersHouseSignMale
# 422 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 423 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_BirchsHouseSignFemale
# 424 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 425 "data/maps/LittlerootTown/scripts.pory"
	end
# 426 "data/maps/LittlerootTown/scripts.pory"

# 427 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale:: @ 81E817D
# 428 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 429 "data/maps/LittlerootTown/scripts.pory"
	return
# 430 "data/maps/LittlerootTown/scripts.pory"

# 431 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale:: @ 81E8186
# 432 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 433 "data/maps/LittlerootTown/scripts.pory"
	return
# 434 "data/maps/LittlerootTown/scripts.pory"

# 435 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign:: @ 81E818F
# 436 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 437 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 438 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 439 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_BirchsHouseSignMale
# 440 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 441 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_PlayersHouseSignFemale
# 442 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 443 "data/maps/LittlerootTown/scripts.pory"
	end
# 444 "data/maps/LittlerootTown/scripts.pory"

# 445 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale:: @ 81E81A9
# 446 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 447 "data/maps/LittlerootTown/scripts.pory"
	return
# 448 "data/maps/LittlerootTown/scripts.pory"

# 449 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale:: @ 81E81B2
# 450 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 451 "data/maps/LittlerootTown/scripts.pory"
	return
# 452 "data/maps/LittlerootTown/scripts.pory"

# 453 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0:: @ 81E81BB
# 454 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 455 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 456 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 10, 9
# 457 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 458 "data/maps/LittlerootTown/scripts.pory"
	end
# 459 "data/maps/LittlerootTown/scripts.pory"

# 460 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1:: @ 81E81CE
# 461 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 462 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 463 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 11, 9
# 464 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 465 "data/maps/LittlerootTown/scripts.pory"
	end
# 466 "data/maps/LittlerootTown/scripts.pory"

# 467 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2:: @ 81E81E1
# 468 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 469 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 470 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 471 "data/maps/LittlerootTown/scripts.pory"
	end
# 472 "data/maps/LittlerootTown/scripts.pory"

# 473 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3:: @ 81E81ED
# 474 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 475 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 476 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 477 "data/maps/LittlerootTown/scripts.pory"
	end
# 478 "data/maps/LittlerootTown/scripts.pory"

# 479 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4:: @ 81E81F9
# 480 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 481 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 482 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 483 "data/maps/LittlerootTown/scripts.pory"
	end
# 484 "data/maps/LittlerootTown/scripts.pory"

# 485 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5:: @ 81E8205
# 486 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 487 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 488 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 489 "data/maps/LittlerootTown/scripts.pory"
	end
# 490 "data/maps/LittlerootTown/scripts.pory"

# 491 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger:: @ 81E8211
# 492 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 493 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 494 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomNoticePlayerMale
# 495 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 496 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomNoticePlayerFemale
# 497 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 498 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 499 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 500 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 501 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 502 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 503 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 504 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 505 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 506 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale
# 507 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 508 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale
# 509 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 510 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 511 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 512 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale
# 513 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 514 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale
# 515 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 516 "data/maps/LittlerootTown/scripts.pory"
	end
# 517 "data/maps/LittlerootTown/scripts.pory"

# 518 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale:: @ 81E8281
# 519 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 520 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 521 "data/maps/LittlerootTown/scripts.pory"
	return
# 522 "data/maps/LittlerootTown/scripts.pory"

# 523 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale:: @ 81E828C
# 524 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 525 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 526 "data/maps/LittlerootTown/scripts.pory"
	return
# 527 "data/maps/LittlerootTown/scripts.pory"

# 528 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale:: @ 81E8297
# 529 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestRight
# 530 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 531 "data/maps/LittlerootTown/scripts.pory"
	return
# 532 "data/maps/LittlerootTown/scripts.pory"

# 533 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale:: @ 81E82A2
# 534 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestLeft
# 535 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 536 "data/maps/LittlerootTown/scripts.pory"
	return
# 537 "data/maps/LittlerootTown/scripts.pory"

# 538 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale:: @ 81E82AD
# 539 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 0
# 540 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayer0
# 541 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
# 542 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayer1
# 543 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 2
# 544 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale2
# 545 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 3
# 546 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale3
# 547 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 4
# 548 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale4
# 549 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 5
# 550 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerMale5
# 551 "data/maps/LittlerootTown/scripts.pory"
	return
# 552 "data/maps/LittlerootTown/scripts.pory"

# 553 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale:: @ 81E82F0
# 554 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 0
# 555 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayer0
# 556 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
# 557 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayer1
# 558 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 2
# 559 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale2
# 560 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 3
# 561 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale3
# 562 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 4
# 563 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale4
# 564 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 5
# 565 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomApproachPlayerFemale5
# 566 "data/maps/LittlerootTown/scripts.pory"
	return
# 567 "data/maps/LittlerootTown/scripts.pory"

# 568 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0:: @ 81E8333
# 569 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 570 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 571 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 572 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 573 "data/maps/LittlerootTown/scripts.pory"
	return
# 574 "data/maps/LittlerootTown/scripts.pory"

# 575 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1:: @ 81E8348
# 576 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 577 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 578 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 579 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 580 "data/maps/LittlerootTown/scripts.pory"
	return
# 581 "data/maps/LittlerootTown/scripts.pory"

# 582 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2:: @ 81E835D
# 583 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 584 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 585 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 586 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 587 "data/maps/LittlerootTown/scripts.pory"
	return
# 588 "data/maps/LittlerootTown/scripts.pory"

# 589 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3:: @ 81E8372
# 590 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 591 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 592 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 593 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 594 "data/maps/LittlerootTown/scripts.pory"
	return
# 595 "data/maps/LittlerootTown/scripts.pory"

# 596 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4:: @ 81E8387
# 597 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 598 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 599 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 600 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 601 "data/maps/LittlerootTown/scripts.pory"
	return
# 602 "data/maps/LittlerootTown/scripts.pory"

# 603 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5:: @ 81E839C
# 604 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 605 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 606 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 607 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 608 "data/maps/LittlerootTown/scripts.pory"
	return
# 609 "data/maps/LittlerootTown/scripts.pory"

# 610 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2:: @ 81E83B1
# 611 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 612 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 613 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 614 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 615 "data/maps/LittlerootTown/scripts.pory"
	return
# 616 "data/maps/LittlerootTown/scripts.pory"

# 617 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3:: @ 81E83C6
# 618 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 619 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 620 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 621 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 622 "data/maps/LittlerootTown/scripts.pory"
	return
# 623 "data/maps/LittlerootTown/scripts.pory"

# 624 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4:: @ 81E83DB
# 625 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 626 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 627 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 628 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 629 "data/maps/LittlerootTown/scripts.pory"
	return
# 630 "data/maps/LittlerootTown/scripts.pory"

# 631 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5:: @ 81E83F0
# 632 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 633 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 634 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 635 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 636 "data/maps/LittlerootTown/scripts.pory"
	return
# 637 "data/maps/LittlerootTown/scripts.pory"

# 638 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale:: @ 81E8405
# 639 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 0
# 640 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHome0
# 641 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
# 642 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHome1
# 643 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 2
# 644 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale2
# 645 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 3
# 646 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale3
# 647 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 4
# 648 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale4
# 649 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 5
# 650 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeMale5
# 651 "data/maps/LittlerootTown/scripts.pory"
	return
# 652 "data/maps/LittlerootTown/scripts.pory"

# 653 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale:: @ 81E8448
# 654 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 0
# 655 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHome0
# 656 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
# 657 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHome1
# 658 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 2
# 659 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale2
# 660 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 3
# 661 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale3
# 662 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 4
# 663 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale4
# 664 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 5
# 665 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_MomReturnHomeFemale5
# 666 "data/maps/LittlerootTown/scripts.pory"
	return
# 667 "data/maps/LittlerootTown/scripts.pory"

# 668 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0:: @ 81E848B
# 669 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
# 670 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 671 "data/maps/LittlerootTown/scripts.pory"
	return
# 672 "data/maps/LittlerootTown/scripts.pory"

# 673 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1:: @ 81E8496
# 674 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
# 675 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 676 "data/maps/LittlerootTown/scripts.pory"
	return
# 677 "data/maps/LittlerootTown/scripts.pory"

# 678 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2:: @ 81E84A1
# 679 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 680 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 681 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 682 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 683 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 684 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 685 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 686 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 687 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 688 "data/maps/LittlerootTown/scripts.pory"
	return
# 689 "data/maps/LittlerootTown/scripts.pory"

# 690 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3:: @ 81E84C7
# 691 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 692 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 693 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 694 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 695 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 696 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 697 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 698 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 699 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 700 "data/maps/LittlerootTown/scripts.pory"
	return
# 701 "data/maps/LittlerootTown/scripts.pory"

# 702 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4:: @ 81E84ED
# 703 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 704 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 705 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 706 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 707 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 708 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 709 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 710 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 711 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 712 "data/maps/LittlerootTown/scripts.pory"
	return
# 713 "data/maps/LittlerootTown/scripts.pory"

# 714 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5:: @ 81E8513
# 715 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 716 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 717 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 718 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 719 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 720 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 721 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 722 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 723 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 724 "data/maps/LittlerootTown/scripts.pory"
	return
# 725 "data/maps/LittlerootTown/scripts.pory"

# 726 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2:: @ 81E8539
# 727 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 728 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 729 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 730 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 731 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 732 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 733 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 734 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 735 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 736 "data/maps/LittlerootTown/scripts.pory"
	return
# 737 "data/maps/LittlerootTown/scripts.pory"

# 738 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3:: @ 81E855F
# 739 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 740 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 741 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 742 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 743 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 744 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 745 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 746 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 747 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 748 "data/maps/LittlerootTown/scripts.pory"
	return
# 749 "data/maps/LittlerootTown/scripts.pory"

# 750 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4:: @ 81E8585
# 751 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 752 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 753 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 754 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 755 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 756 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 757 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 758 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 759 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 760 "data/maps/LittlerootTown/scripts.pory"
	return
# 761 "data/maps/LittlerootTown/scripts.pory"

# 762 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5:: @ 81E85AB
# 763 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 764 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 765 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 766 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 767 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 768 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 769 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 770 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 771 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 772 "data/maps/LittlerootTown/scripts.pory"
	return
# 773 "data/maps/LittlerootTown/scripts.pory"

# 774 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0: @ 81E85D1
# 775 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 777 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 778 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 779 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 781 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 782 "data/maps/LittlerootTown/scripts.pory"

# 783 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1: @ 81E85D8
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 785 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 786 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 787 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 788 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 789 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 790 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 791 "data/maps/LittlerootTown/scripts.pory"

# 792 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2: @ 81E85DF
# 793 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 794 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 795 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 797 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 798 "data/maps/LittlerootTown/scripts.pory"

# 799 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3: @ 81E85E4
# 800 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 801 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 802 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 803 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 805 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 806 "data/maps/LittlerootTown/scripts.pory"

# 807 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4: @ 81E85EA
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 809 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 810 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 811 "data/maps/LittlerootTown/scripts.pory"

# 812 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5: @ 81E85ED
# 813 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 814 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 815 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 816 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 817 "data/maps/LittlerootTown/scripts.pory"

# 818 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2: @ 81E85F1
# 819 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 821 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 822 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 823 "data/maps/LittlerootTown/scripts.pory"

# 824 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3: @ 81E85F5
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 826 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 827 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 828 "data/maps/LittlerootTown/scripts.pory"

# 829 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4: @ 81E85F8
# 830 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 831 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 832 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 834 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 835 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 836 "data/maps/LittlerootTown/scripts.pory"

# 837 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5: @ 81E85FE
# 838 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 839 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 842 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 843 "data/maps/LittlerootTown/scripts.pory"

# 844 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0: @ 81E8603
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 846 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 847 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 848 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 850 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 851 "data/maps/LittlerootTown/scripts.pory"

# 852 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1: @ 81E8609
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 854 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 858 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 859 "data/maps/LittlerootTown/scripts.pory"

# 860 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2: @ 81E860F
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 862 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 863 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 864 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 866 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 867 "data/maps/LittlerootTown/scripts.pory"

# 868 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3: @ 81E8615
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 870 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 871 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 873 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 874 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 875 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 876 "data/maps/LittlerootTown/scripts.pory"

# 877 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4: @ 81E861C
# 878 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 879 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 880 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 881 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 882 "data/maps/LittlerootTown/scripts.pory"

# 883 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5: @ 81E8620
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 885 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 886 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 887 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 888 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 889 "data/maps/LittlerootTown/scripts.pory"

# 890 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2: @ 81E8625
# 891 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 892 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 894 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 895 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 896 "data/maps/LittlerootTown/scripts.pory"

# 897 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3: @ 81E862A
# 898 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 899 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 900 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 901 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 902 "data/maps/LittlerootTown/scripts.pory"

# 903 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4: @ 81E862E
# 904 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 905 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 906 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 907 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 908 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 909 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 910 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 911 "data/maps/LittlerootTown/scripts.pory"

# 912 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5: @ 81E8635
# 913 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 914 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 915 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 916 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 917 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_fastest_up
# 918 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 919 "data/maps/LittlerootTown/scripts.pory"

# 920 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor: @ 81E863B
# 921 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 922 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 923 "data/maps/LittlerootTown/scripts.pory"

# 924 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom:: @ 81E863D
# 925 "data/maps/LittlerootTown/scripts.pory"
	lock
# 926 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 927 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 928 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, MALE
# 929 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 930 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 931 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 932 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 933 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFastestUp
# 934 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 935 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 936 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 937 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 938 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 939 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 940 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 941 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 942 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 943 "data/maps/LittlerootTown/scripts.pory"
	end
# 944 "data/maps/LittlerootTown/scripts.pory"

# 945 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes:: @ 81E8686
# 946 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MOM
# 947 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 948 "data/maps/LittlerootTown/scripts.pory"
	release
# 949 "data/maps/LittlerootTown/scripts.pory"
	end
# 950 "data/maps/LittlerootTown/scripts.pory"

# 951 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes:: @ 81E8693
# 952 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 953 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_OLD_ROD
# 954 "data/maps/LittlerootTown/scripts.pory"
	giveitem ITEM_COIN_CASE
# 955 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_COIN_CASE
# 956 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
# 957 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 958 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 959 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 960 "data/maps/LittlerootTown/scripts.pory"
	return
# 961 "data/maps/LittlerootTown/scripts.pory"

# 962 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DisableShinyRate:
# 963 "data/maps/LittlerootTown/scripts.pory"
	.string "Yes: 1/1024\n"
# 964 "data/maps/LittlerootTown/scripts.pory"
	.string "No:  Cancel$"		
# 965 "data/maps/LittlerootTown/scripts.pory"

# 966 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ShinyRates:
# 967 "data/maps/LittlerootTown/scripts.pory"
	.string "Yes: 1/250\n"
# 968 "data/maps/LittlerootTown/scripts.pory"
	.string "No:  1/100$"
# 969 "data/maps/LittlerootTown/scripts.pory"
		
# 970 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_EnbableShinyRate:
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "Yes: Boosted shiny rate options\n"
# 972 "data/maps/LittlerootTown/scripts.pory"
	.string "No:  Disable boosted shiny rate$"	
# 973 "data/maps/LittlerootTown/scripts.pory"

# 974 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ShinyRate_0:
# 975 "data/maps/LittlerootTown/scripts.pory"
	.string "Current shiny rate: 1/1024\n"
# 976 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 977 "data/maps/LittlerootTown/scripts.pory"

# 978 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ShinyRate_1:
# 979 "data/maps/LittlerootTown/scripts.pory"
	.string "Current shiny rate: 1/250\n"
# 980 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 981 "data/maps/LittlerootTown/scripts.pory"

# 982 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ShinyRate_2:
# 983 "data/maps/LittlerootTown/scripts.pory"
	.string "Current shiny rate: 1/100\n"
# 984 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 985 "data/maps/LittlerootTown/scripts.pory"
		
# 986 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangePokevial:
# 987 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable infinite Poké Vial?$"
# 988 "data/maps/LittlerootTown/scripts.pory"
		
# 989 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangePokevialEnabled:
# 990 "data/maps/LittlerootTown/scripts.pory"
	.string "Infinite Poké Vial is enabled.\n"
# 991 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 992 "data/maps/LittlerootTown/scripts.pory"

# 993 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangePokevialDisabled:
# 994 "data/maps/LittlerootTown/scripts.pory"
	.string "Infinite Poké Vial is disabled.\n"
# 995 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 996 "data/maps/LittlerootTown/scripts.pory"
		
# 997 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeItems:
# 998 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable nurse Joy items?\n"
# 999 "data/maps/LittlerootTown/scripts.pory"
	.string "Infinite Big Pearls, Sitrus Berries etc...$"
# 1000 "data/maps/LittlerootTown/scripts.pory"
		
# 1001 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeItemsEnabled:
# 1002 "data/maps/LittlerootTown/scripts.pory"
	.string "Nurse Joy items are enabled.\n"
# 1003 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1004 "data/maps/LittlerootTown/scripts.pory"

# 1005 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeItemsDisabled:
# 1006 "data/maps/LittlerootTown/scripts.pory"
	.string "Nurse Joy items are disabled.\n"
# 1007 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1008 "data/maps/LittlerootTown/scripts.pory"

# 1009 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeBerries:
# 1010 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable instant berries?$"
# 1011 "data/maps/LittlerootTown/scripts.pory"
		
# 1012 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeBerriesEnabled:
# 1013 "data/maps/LittlerootTown/scripts.pory"
	.string "Instant berries are enabled.\n"
# 1014 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1015 "data/maps/LittlerootTown/scripts.pory"

# 1016 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeBerriesDisabled:
# 1017 "data/maps/LittlerootTown/scripts.pory"
	.string "Instant berries are disabled.\n"
# 1018 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1019 "data/maps/LittlerootTown/scripts.pory"
		
# 1020 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeUniqueColor:
# 1021 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable Individually-Unique Pokémon?\n"
# 1022 "data/maps/LittlerootTown/scripts.pory"
	.string "All credit goes to codes for the patch.$"
# 1023 "data/maps/LittlerootTown/scripts.pory"
		
# 1024 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeUniqueColorEnabled:
# 1025 "data/maps/LittlerootTown/scripts.pory"
	.string "Individually-Unique Pokémon is enabled.\n"
# 1026 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1027 "data/maps/LittlerootTown/scripts.pory"

# 1028 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeUniqueColorDisabled:
# 1029 "data/maps/LittlerootTown/scripts.pory"
	.string "Individually-Unique Pokémon is Disabled.\n"
# 1030 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1031 "data/maps/LittlerootTown/scripts.pory"
		
# 1032 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeAIcontrolled:
# 1033 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable AI controlled battles?$"
# 1034 "data/maps/LittlerootTown/scripts.pory"
		
# 1035 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeAIcontrolledEnabled:
# 1036 "data/maps/LittlerootTown/scripts.pory"
	.string "AI controlled battles are enabled.\n"
# 1037 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1038 "data/maps/LittlerootTown/scripts.pory"

# 1039 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeAIcontrolledDisabled:
# 1040 "data/maps/LittlerootTown/scripts.pory"
	.string "AI controlled battles are Disabled.\n"
# 1041 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1042 "data/maps/LittlerootTown/scripts.pory"
		
# 1043 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_MakePlaceForSettingsMon:
# 1044 "data/maps/LittlerootTown/scripts.pory"
	.string "Make sure there's no Pokémon in your PC\n"
# 1045 "data/maps/LittlerootTown/scripts.pory"
	.string "box 14 row 5 column 6.$"
# 1046 "data/maps/LittlerootTown/scripts.pory"

# 1047 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeIVSettingsDisabled:
# 1048 "data/maps/LittlerootTown/scripts.pory"
	.string "Perfect IVs are disabled.\n"
# 1049 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1050 "data/maps/LittlerootTown/scripts.pory"

# 1051 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeIVSettingsEnabled:
# 1052 "data/maps/LittlerootTown/scripts.pory"
	.string "Perfect IVs are enabled.\n"
# 1053 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1054 "data/maps/LittlerootTown/scripts.pory"
		
# 1055 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_HandleIVSettings:
# 1056 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable perfect IVs?\n"
# 1057 "data/maps/LittlerootTown/scripts.pory"
	.string "Trainers won't be affected.$"
# 1058 "data/maps/LittlerootTown/scripts.pory"
		
# 1059 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_EnableIVSettings:
# 1060 "data/maps/LittlerootTown/scripts.pory"
	.string "ARE YOU SURE???????? All your Pokémon's\n"
# 1061 "data/maps/LittlerootTown/scripts.pory"
	.string "IVs will be set to 31.$"
# 1062 "data/maps/LittlerootTown/scripts.pory"
		
# 1063 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DisableIVSettings:
# 1064 "data/maps/LittlerootTown/scripts.pory"
	.string "Disable perfect IVs?$"
# 1065 "data/maps/LittlerootTown/scripts.pory"

# 1066 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeEVSettingsEnabled:
# 1067 "data/maps/LittlerootTown/scripts.pory"
	.string "EVs are disabled.\n"
# 1068 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1069 "data/maps/LittlerootTown/scripts.pory"

# 1070 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeEVSettingsDisabled:
# 1071 "data/maps/LittlerootTown/scripts.pory"
	.string "EVs are enabled.\n"
# 1072 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1073 "data/maps/LittlerootTown/scripts.pory"
		
# 1074 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_HandleEVSettings:
# 1075 "data/maps/LittlerootTown/scripts.pory"
	.string "Disable EVs?\n"
# 1076 "data/maps/LittlerootTown/scripts.pory"
	.string "Trainers WILL be affected.$"
# 1077 "data/maps/LittlerootTown/scripts.pory"
		
# 1078 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_EnableEVSettings:
# 1079 "data/maps/LittlerootTown/scripts.pory"
	.string "ARE YOU SURE???????? All your Pokémon's\n"
# 1080 "data/maps/LittlerootTown/scripts.pory"
	.string "EVs will be set to 0.$"
# 1081 "data/maps/LittlerootTown/scripts.pory"

# 1082 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DisableEVSettings:
# 1083 "data/maps/LittlerootTown/scripts.pory"
	.string "Yes: Allow EVs gain\n"
# 1084 "data/maps/LittlerootTown/scripts.pory"
	.string "No:  Cancel$"
# 1085 "data/maps/LittlerootTown/scripts.pory"

# 1086 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside: @ 81E86BC
# 1087 "data/maps/LittlerootTown/scripts.pory"
	.string "Mom: {PLAYER}, we're here, honey!\p"
# 1088 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 1089 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 1090 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is Littleroot Town.\p"
# 1091 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 1092 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 1093 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 1094 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 1095 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 1096 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 1097 "data/maps/LittlerootTown/scripts.pory"

# 1098 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer: @ 81E87E1
# 1099 "data/maps/LittlerootTown/scripts.pory"
	.string "Mom: Wait, {PLAYER}!$"
# 1100 "data/maps/LittlerootTown/scripts.pory"

# 1101 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes: @ 81E87F0
# 1102 "data/maps/LittlerootTown/scripts.pory"
	.string "Mom: {PLAYER}! {PLAYER}! Did you\n"
# 1103 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to Prof. Birch?\p"
# 1104 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable Pokémon!\n"
# 1105 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from Prof. Birch. How nice!\p"
# 1106 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 1107 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with Pokémon!\p"
# 1108 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 1109 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, take Dad's old stuff.\p"
# 1110 "data/maps/LittlerootTown/scripts.pory"
	.string "He never uses it anyway!$"
# 1111 "data/maps/LittlerootTown/scripts.pory"

# 1112 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ComeHomeIfAnythingHappens: @ 81E8A03
# 1113 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 1114 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 1115 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 1116 "data/maps/LittlerootTown/scripts.pory"
	.string "Pokémon now…\l"
# 1117 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\p"
# 1118 "data/maps/LittlerootTown/scripts.pory"
	.string "…But please be careful.\n"
# 1119 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 1120 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, honey!$"
# 1121 "data/maps/LittlerootTown/scripts.pory"

# 1122 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems: @ 81E8ACF
# 1123 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 1124 "data/maps/LittlerootTown/scripts.pory"
	.string "and Pokémon.\p"
# 1125 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 1126 "data/maps/LittlerootTown/scripts.pory"

# 1127 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab: @ 81E8B25
# 1128 "data/maps/LittlerootTown/scripts.pory"
	.string "Prof. Birch spends days in his Lab\n"
# 1129 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 1130 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 1131 "data/maps/LittlerootTown/scripts.pory"
	.string "When does Prof. Birch spend time\n"
# 1132 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 1133 "data/maps/LittlerootTown/scripts.pory"

# 1134 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut: @ 81E8BB8
# 1135 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 1136 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 1137 "data/maps/LittlerootTown/scripts.pory"
	.string "wild Pokémon will jump out!$"
# 1138 "data/maps/LittlerootTown/scripts.pory"

# 1139 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon: @ 81E8C07
# 1140 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 1141 "data/maps/LittlerootTown/scripts.pory"
	.string "your own Pokémon.$"
# 1142 "data/maps/LittlerootTown/scripts.pory"

# 1143 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening: @ 81E8C3A
# 1144 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 1145 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary Pokémon outside!\n"
# 1146 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 1147 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 1148 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any Pokémon…\p"
# 1149 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 1150 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 1151 "data/maps/LittlerootTown/scripts.pory"

# 1152 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch: @ 81E8CE3
# 1153 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved Prof. Birch!\n"
# 1154 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 1155 "data/maps/LittlerootTown/scripts.pory"

# 1156 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon: @ 81E8D07
# 1157 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch Pokémon?\n"
# 1158 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 1159 "data/maps/LittlerootTown/scripts.pory"

# 1160 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign: @ 81E8D32
# 1161 "data/maps/LittlerootTown/scripts.pory"
	.string "Littleroot Town\n"
# 1162 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 1163 "data/maps/LittlerootTown/scripts.pory"

# 1164 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab: @ 81E8D69
# 1165 "data/maps/LittlerootTown/scripts.pory"
	.string "Prof. Birch's Pokémon Lab$"
# 1166 "data/maps/LittlerootTown/scripts.pory"

# 1167 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse: @ 81E8D83
# 1168 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s House$"
# 1169 "data/maps/LittlerootTown/scripts.pory"

# 1170 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse: @ 81E8D8E
# 1171 "data/maps/LittlerootTown/scripts.pory"
	.string "Prof. Birch's House$"
# 1172 "data/maps/LittlerootTown/scripts.pory"

# 1173 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab: @ 81E8DA2
# 1174 "data/maps/LittlerootTown/scripts.pory"
	.string "Prof. Birch: Well, well, {PLAYER}{KUN}!\n"
# 1175 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 1176 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 1177 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 1178 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 1179 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 1180 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my Lab.$"
# 1181 "data/maps/LittlerootTown/scripts.pory"
	
# 1182 "data/maps/LittlerootTown/scripts.pory"
	
# 1183 "data/maps/LittlerootTown/scripts.pory"
	
# 1184 "data/maps/LittlerootTown/scripts.pory"

# 1185 "data/maps/LittlerootTown/scripts.pory"
	
# 1186 "data/maps/LittlerootTown/scripts.pory"
		
# 1187 "data/maps/LittlerootTown/scripts.pory"

# 1188 "data/maps/LittlerootTown/scripts.pory"
	
# 1189 "data/maps/LittlerootTown/scripts.pory"
	
# 1190 "data/maps/LittlerootTown/scripts.pory"
	
# 1191 "data/maps/LittlerootTown/scripts.pory"
	
# 1192 "data/maps/LittlerootTown/scripts.pory"
	
# 1193 "data/maps/LittlerootTown/scripts.pory"
	
# 1194 "data/maps/LittlerootTown/scripts.pory"
	
# 1195 "data/maps/LittlerootTown/scripts.pory"
	
# 1196 "data/maps/LittlerootTown/scripts.pory"
	
# 1197 "data/maps/LittlerootTown/scripts.pory"
	
# 1198 "data/maps/LittlerootTown/scripts.pory"
	
# 1199 "data/maps/LittlerootTown/scripts.pory"
	
# 1200 "data/maps/LittlerootTown/scripts.pory"
	
# 1201 "data/maps/LittlerootTown/scripts.pory"
	
# 1202 "data/maps/LittlerootTown/scripts.pory"
	
# 1203 "data/maps/LittlerootTown/scripts.pory"
	
# 1204 "data/maps/LittlerootTown/scripts.pory"
	
# 1205 "data/maps/LittlerootTown/scripts.pory"
	
# 1206 "data/maps/LittlerootTown/scripts.pory"
	
# 1207 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_PerfectIV::
# 1208 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1209 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1210 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
# 1211 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_NoPlaceForSettingsMon
# 1212 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 0
# 1213 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1214 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1215 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_ChangeIVSettingsEnabled
# 1216 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1217 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_ChangeIVSettingsDisabled
# 1218 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1219 "data/maps/LittlerootTown/scripts.pory"
	end
# 1220 "data/maps/LittlerootTown/scripts.pory"
	
# 1221 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_DisableEV::
# 1222 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1223 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1224 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
# 1225 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_NoPlaceForSettingsMon
# 1226 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 1
# 1227 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1228 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1229 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_ChangeEVSettingsEnabled
# 1230 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1231 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_ChangeEVSettingsDisabled
# 1232 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1233 "data/maps/LittlerootTown/scripts.pory"
	end	
# 1234 "data/maps/LittlerootTown/scripts.pory"
	
# 1235 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_UniqueColor::
# 1236 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1237 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1238 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
# 1239 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_NoPlaceForSettingsMon
# 1240 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_UniqueColor
# 1241 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1242 "data/maps/LittlerootTown/scripts.pory"
	end
# 1243 "data/maps/LittlerootTown/scripts.pory"

# 1244 "data/maps/LittlerootTown/scripts.pory"
	
# 1245 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_AIcontrolled::
# 1246 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1247 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1248 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
# 1249 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_NoPlaceForSettingsMon
# 1250 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_AIcontrolled
# 1251 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1252 "data/maps/LittlerootTown/scripts.pory"
	end
# 1253 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NoPlaceForSettingsMon::
# 1254 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_MakePlaceForSettingsMon, MSGBOX_DEFAULT
# 1255 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1256 "data/maps/LittlerootTown/scripts.pory"
	end
# 1257 "data/maps/LittlerootTown/scripts.pory"
	
# 1258 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_Others::
# 1259 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1260 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1261 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
# 1262 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_NoPlaceForSettingsMon
# 1263 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_PatchSettings_Berries
# 1264 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_PatchSettings_ShinyRate
# 1265 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_PatchSettings_Pokevial
# 1266 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1267 "data/maps/LittlerootTown/scripts.pory"
	end
# 1268 "data/maps/LittlerootTown/scripts.pory"
	
# 1269 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HandleIVSettings::
# 1270 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_HandleIVSettings, MSGBOX_YESNO
# 1271 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
# 1272 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_DisableIVSettings
# 1273 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1274 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_EnableIVSettings
# 1275 "data/maps/LittlerootTown/scripts.pory"
	
# 1276 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableIVSettings::
# 1277 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DisableIVSettings, MSGBOX_YESNO
# 1278 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
# 1279 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_PatchSettings_PerfectIV
# 1280 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 0 
# 1281 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1282 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1283 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1284 "data/maps/LittlerootTown/scripts.pory"
	end
# 1285 "data/maps/LittlerootTown/scripts.pory"
		
# 1286 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableIVSettings::
# 1287 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_EnableIVSettings, MSGBOX_YESNO
# 1288 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
# 1289 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_PatchSettings_PerfectIV
# 1290 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 0 
# 1291 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1292 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1293 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1294 "data/maps/LittlerootTown/scripts.pory"
	end
# 1295 "data/maps/LittlerootTown/scripts.pory"
		
# 1296 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HandleEVSettings::
# 1297 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_HandleEVSettings, MSGBOX_YESNO
# 1298 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
# 1299 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_DisableEVSettings
# 1300 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1301 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_EnableEVSettings
# 1302 "data/maps/LittlerootTown/scripts.pory"
		
# 1303 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableEVSettings::
# 1304 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DisableEVSettings, MSGBOX_YESNO
# 1305 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
# 1306 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_PatchSettings_DisableEV
# 1307 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 1 
# 1308 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1309 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1310 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1311 "data/maps/LittlerootTown/scripts.pory"
	end
# 1312 "data/maps/LittlerootTown/scripts.pory"
		
# 1313 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableEVSettings::
# 1314 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_EnableEVSettings, MSGBOX_YESNO
# 1315 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
# 1316 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_PatchSettings_DisableEV
# 1317 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 1 
# 1318 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1319 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats		
# 1320 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1321 "data/maps/LittlerootTown/scripts.pory"
	end
# 1322 "data/maps/LittlerootTown/scripts.pory"

# 1323 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeEVSettingsEnabled::
# 1324 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeEVSettingsEnabled, MSGBOX_YESNO
# 1325 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES	
# 1326 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_HandleEVSettings
# 1327 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1328 "data/maps/LittlerootTown/scripts.pory"
	end
# 1329 "data/maps/LittlerootTown/scripts.pory"
	
# 1330 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeEVSettingsDisabled::
# 1331 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeEVSettingsDisabled, MSGBOX_YESNO
# 1332 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES	
# 1333 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_HandleEVSettings
# 1334 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1335 "data/maps/LittlerootTown/scripts.pory"
	end
# 1336 "data/maps/LittlerootTown/scripts.pory"
	
# 1337 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeIVSettingsEnabled::
# 1338 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeIVSettingsEnabled, MSGBOX_YESNO
# 1339 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES	
# 1340 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_HandleIVSettings
# 1341 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1342 "data/maps/LittlerootTown/scripts.pory"
	end
# 1343 "data/maps/LittlerootTown/scripts.pory"
	
# 1344 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeIVSettingsDisabled::
# 1345 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeIVSettingsDisabled, MSGBOX_YESNO
# 1346 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES	
# 1347 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq LittlerootTown_EventScript_HandleIVSettings
# 1348 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1349 "data/maps/LittlerootTown/scripts.pory"
	end
# 1350 "data/maps/LittlerootTown/scripts.pory"
	
# 1351 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_AIcontrolled::
# 1352 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 7
# 1353 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1354 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1355 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeAIcontrolledEnabled
# 1356 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1357 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangeAIcontrolledDisabled
# 1358 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1359 "data/maps/LittlerootTown/scripts.pory"
	
# 1360 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeAIcontrolledEnabled::
# 1361 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeAIcontrolledEnabled, MSGBOX_YESNO
# 1362 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1363 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeAIcontrolled
# 1364 "data/maps/LittlerootTown/scripts.pory"
	return
# 1365 "data/maps/LittlerootTown/scripts.pory"

# 1366 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeAIcontrolledDisabled::
# 1367 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeAIcontrolledDisabled, MSGBOX_YESNO
# 1368 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1369 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeAIcontrolled
# 1370 "data/maps/LittlerootTown/scripts.pory"
	return
# 1371 "data/maps/LittlerootTown/scripts.pory"

# 1372 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeAIcontrolled::
# 1373 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeAIcontrolled, MSGBOX_YESNO
# 1374 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1375 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableAIcontrolled
# 1376 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1377 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisableAIcontrolled
# 1378 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1379 "data/maps/LittlerootTown/scripts.pory"

# 1380 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableAIcontrolled::
# 1381 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 7
# 1382 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1383 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1384 "data/maps/LittlerootTown/scripts.pory"
	return
# 1385 "data/maps/LittlerootTown/scripts.pory"
		
# 1386 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableAIcontrolled::
# 1387 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 7
# 1388 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1389 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1390 "data/maps/LittlerootTown/scripts.pory"
	return
# 1391 "data/maps/LittlerootTown/scripts.pory"

# 1392 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_UniqueColor::
# 1393 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 6
# 1394 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1395 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1396 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeUniqueColorEnabled
# 1397 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1398 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangeUniqueColorDisabled
# 1399 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1400 "data/maps/LittlerootTown/scripts.pory"
	
# 1401 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeUniqueColorEnabled::
# 1402 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeUniqueColorEnabled, MSGBOX_YESNO
# 1403 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1404 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeUniqueColor
# 1405 "data/maps/LittlerootTown/scripts.pory"
	return
# 1406 "data/maps/LittlerootTown/scripts.pory"

# 1407 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeUniqueColorDisabled::
# 1408 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeUniqueColorDisabled, MSGBOX_YESNO
# 1409 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1410 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeUniqueColor
# 1411 "data/maps/LittlerootTown/scripts.pory"
	return
# 1412 "data/maps/LittlerootTown/scripts.pory"

# 1413 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeUniqueColor::
# 1414 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeUniqueColor, MSGBOX_YESNO
# 1415 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1416 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableUniqueColor
# 1417 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1418 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisableUniqueColor
# 1419 "data/maps/LittlerootTown/scripts.pory"
	return
# 1420 "data/maps/LittlerootTown/scripts.pory"
		
# 1421 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableUniqueColor::
# 1422 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 6
# 1423 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1424 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1425 "data/maps/LittlerootTown/scripts.pory"
	return
# 1426 "data/maps/LittlerootTown/scripts.pory"
		
# 1427 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableUniqueColor::
# 1428 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 6
# 1429 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1430 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1431 "data/maps/LittlerootTown/scripts.pory"
	return
# 1432 "data/maps/LittlerootTown/scripts.pory"

# 1433 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_Berries::
# 1434 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 5
# 1435 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1436 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1437 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeBerriesEnabled
# 1438 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1439 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangeBerriesDisabled
# 1440 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1441 "data/maps/LittlerootTown/scripts.pory"
	
# 1442 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeBerriesEnabled::
# 1443 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeBerriesEnabled, MSGBOX_YESNO
# 1444 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1445 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeBerries
# 1446 "data/maps/LittlerootTown/scripts.pory"
	return
# 1447 "data/maps/LittlerootTown/scripts.pory"

# 1448 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeBerriesDisabled::
# 1449 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeBerriesDisabled, MSGBOX_YESNO
# 1450 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1451 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeBerries
# 1452 "data/maps/LittlerootTown/scripts.pory"
	return
# 1453 "data/maps/LittlerootTown/scripts.pory"

# 1454 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeBerries::
# 1455 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeBerries, MSGBOX_YESNO
# 1456 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1457 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableBerries
# 1458 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1459 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisableBerries
# 1460 "data/maps/LittlerootTown/scripts.pory"
	return
# 1461 "data/maps/LittlerootTown/scripts.pory"

# 1462 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableBerries::
# 1463 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 5 
# 1464 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1465 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1466 "data/maps/LittlerootTown/scripts.pory"
	return
# 1467 "data/maps/LittlerootTown/scripts.pory"
		
# 1468 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableBerries::
# 1469 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 5
# 1470 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1471 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1472 "data/maps/LittlerootTown/scripts.pory"
	return
# 1473 "data/maps/LittlerootTown/scripts.pory"

# 1474 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_Items::
# 1475 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 4
# 1476 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1477 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1478 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeItemsEnabled
# 1479 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1480 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangeItemsDisabled
# 1481 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1482 "data/maps/LittlerootTown/scripts.pory"
	
# 1483 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeItemsEnabled::
# 1484 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeItemsEnabled, MSGBOX_YESNO
# 1485 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1486 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeItems
# 1487 "data/maps/LittlerootTown/scripts.pory"
	return
# 1488 "data/maps/LittlerootTown/scripts.pory"

# 1489 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeItemsDisabled::
# 1490 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeItemsDisabled, MSGBOX_YESNO
# 1491 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1492 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeItems
# 1493 "data/maps/LittlerootTown/scripts.pory"
	return
# 1494 "data/maps/LittlerootTown/scripts.pory"

# 1495 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeItems::
# 1496 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeItems, MSGBOX_YESNO
# 1497 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1498 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableItems
# 1499 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1500 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisableItems
# 1501 "data/maps/LittlerootTown/scripts.pory"
	return
# 1502 "data/maps/LittlerootTown/scripts.pory"

# 1503 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableItems::
# 1504 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 4 
# 1505 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1506 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1507 "data/maps/LittlerootTown/scripts.pory"
	return
# 1508 "data/maps/LittlerootTown/scripts.pory"
		
# 1509 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableItems::
# 1510 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 4
# 1511 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1512 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1513 "data/maps/LittlerootTown/scripts.pory"
	return			
# 1514 "data/maps/LittlerootTown/scripts.pory"
		
# 1515 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_Pokevial::
# 1516 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 3
# 1517 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1518 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1519 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangePokevialEnabled
# 1520 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1521 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangePokevialDisabled
# 1522 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1523 "data/maps/LittlerootTown/scripts.pory"
	
# 1524 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangePokevialEnabled::
# 1525 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangePokevialEnabled, MSGBOX_YESNO
# 1526 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1527 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangePokevial
# 1528 "data/maps/LittlerootTown/scripts.pory"
	return
# 1529 "data/maps/LittlerootTown/scripts.pory"

# 1530 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangePokevialDisabled::
# 1531 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangePokevialDisabled, MSGBOX_YESNO
# 1532 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1533 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangePokevial
# 1534 "data/maps/LittlerootTown/scripts.pory"
	return
# 1535 "data/maps/LittlerootTown/scripts.pory"

# 1536 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangePokevial::
# 1537 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangePokevial, MSGBOX_YESNO
# 1538 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1539 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnablePokevial
# 1540 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1541 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisablePokevial
# 1542 "data/maps/LittlerootTown/scripts.pory"
	return
# 1543 "data/maps/LittlerootTown/scripts.pory"

# 1544 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnablePokevial::
# 1545 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 3 
# 1546 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1547 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1548 "data/maps/LittlerootTown/scripts.pory"
	return
# 1549 "data/maps/LittlerootTown/scripts.pory"
		
# 1550 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisablePokevial::
# 1551 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 3
# 1552 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1553 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1554 "data/maps/LittlerootTown/scripts.pory"
	return
# 1555 "data/maps/LittlerootTown/scripts.pory"
		
# 1556 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ShinyRate_0::
# 1557 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ShinyRate_0, MSGBOX_YESNO
# 1558 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1559 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_HandleShinyRate
# 1560 "data/maps/LittlerootTown/scripts.pory"
	return
# 1561 "data/maps/LittlerootTown/scripts.pory"

# 1562 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ShinyRate_1::
# 1563 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ShinyRate_1, MSGBOX_YESNO
# 1564 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1565 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_HandleShinyRate
# 1566 "data/maps/LittlerootTown/scripts.pory"
	return
# 1567 "data/maps/LittlerootTown/scripts.pory"

# 1568 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ShinyRate_2::
# 1569 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ShinyRate_2, MSGBOX_YESNO
# 1570 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1571 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_HandleShinyRate
# 1572 "data/maps/LittlerootTown/scripts.pory"
	return
# 1573 "data/maps/LittlerootTown/scripts.pory"
	
# 1574 "data/maps/LittlerootTown/scripts.pory"
		
# 1575 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HandleShinyRate::
# 1576 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 0
# 1577 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_EnbableShinyRate, MSGBOX_YESNO
# 1578 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1579 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableShinyRate
# 1580 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 0
# 1581 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_DisableShinyRate
# 1582 "data/maps/LittlerootTown/scripts.pory"
	return
# 1583 "data/maps/LittlerootTown/scripts.pory"

# 1584 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableShinyRate::
# 1585 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 1
# 1586 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ShinyRates, MSGBOX_YESNO
# 1587 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1588 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableShinyRate_1
# 1589 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, NO
# 1590 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableShinyRate_2
# 1591 "data/maps/LittlerootTown/scripts.pory"
	return
# 1592 "data/maps/LittlerootTown/scripts.pory"

# 1593 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableShinyRate::
# 1594 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DisableShinyRate, MSGBOX_YESNO
# 1595 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1596 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableShinyRate_0
# 1597 "data/maps/LittlerootTown/scripts.pory"
	return
# 1598 "data/maps/LittlerootTown/scripts.pory"
			
# 1599 "data/maps/LittlerootTown/scripts.pory"
		
# 1600 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_ShinyRate::
# 1601 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 2
# 1602 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1603 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005,1
# 1604 "data/maps/LittlerootTown/scripts.pory"
	call_if_lt LittlerootTown_EventScript_ShinyRate_0
# 1605 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005,1
# 1606 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ShinyRate_1
# 1607 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005,1
# 1608 "data/maps/LittlerootTown/scripts.pory"
	call_if_gt LittlerootTown_EventScript_ShinyRate_2
# 1609 "data/maps/LittlerootTown/scripts.pory"
	return
# 1610 "data/maps/LittlerootTown/scripts.pory"
	
# 1611 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableShinyRate_0::
# 1612 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 2 
# 1613 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1614 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1615 "data/maps/LittlerootTown/scripts.pory"
	return
# 1616 "data/maps/LittlerootTown/scripts.pory"
		
# 1617 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableShinyRate_1::
# 1618 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 2
# 1619 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1620 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1621 "data/maps/LittlerootTown/scripts.pory"
	return
# 1622 "data/maps/LittlerootTown/scripts.pory"

# 1623 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableShinyRate_2::
# 1624 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 2
# 1625 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 2
# 1626 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1627 "data/maps/LittlerootTown/scripts.pory"
	return
# 1628 "data/maps/LittlerootTown/scripts.pory"

# 1629 "data/maps/LittlerootTown/scripts.pory"

# 1630 "data/maps/LittlerootTown/scripts.pory"

# 1631 "data/maps/LittlerootTown/scripts.pory"

# 1632 "data/maps/LittlerootTown/scripts.pory"

# 1633 "data/maps/LittlerootTown/scripts.pory"

# 1634 "data/maps/LittlerootTown/scripts.pory"

# 1635 "data/maps/LittlerootTown/scripts.pory"

# 1636 "data/maps/LittlerootTown/scripts.pory"

# 1637 "data/maps/LittlerootTown/scripts.pory"

# 1638 "data/maps/LittlerootTown/scripts.pory"

# 1639 "data/maps/LittlerootTown/scripts.pory"

# 1640 "data/maps/LittlerootTown/scripts.pory"

# 1641 "data/maps/LittlerootTown/scripts.pory"

# 1642 "data/maps/LittlerootTown/scripts.pory"

# 1643 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_Random::
# 1644 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1645 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 1646 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, 1
# 1647 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne LittlerootTown_EventScript_NoPlaceForSettingsMon
# 1648 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_PatchSettings_Starters
# 1649 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_PatchSettings_Legends
# 1650 "data/maps/LittlerootTown/scripts.pory"
	@call LittlerootTown_EventScript_PatchSettings_Unobtainable
# 1651 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_PatchSettings_AltForms
# 1652 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 1653 "data/maps/LittlerootTown/scripts.pory"
	end
# 1654 "data/maps/LittlerootTown/scripts.pory"

# 1655 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeLegends:
# 1656 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable Legendary/Mythical?\n"
# 1657 "data/maps/LittlerootTown/scripts.pory"
	.string "This affects random starters/eggs$"
# 1658 "data/maps/LittlerootTown/scripts.pory"
		
# 1659 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeLegendsEnabled:
# 1660 "data/maps/LittlerootTown/scripts.pory"
	.string "Legendary/Mythical are enabled.\n"
# 1661 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1662 "data/maps/LittlerootTown/scripts.pory"

# 1663 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeLegendsDisabled:
# 1664 "data/maps/LittlerootTown/scripts.pory"
	.string "Legendary/Mythical are disabled.\n"
# 1665 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1666 "data/maps/LittlerootTown/scripts.pory"
		
# 1667 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_Legends::
# 1668 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 8
# 1669 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1670 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1671 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeLegendsEnabled
# 1672 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1673 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangeLegendsDisabled
# 1674 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1675 "data/maps/LittlerootTown/scripts.pory"
	
# 1676 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeLegendsEnabled::
# 1677 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeLegendsEnabled, MSGBOX_YESNO
# 1678 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1679 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeLegends
# 1680 "data/maps/LittlerootTown/scripts.pory"
	return
# 1681 "data/maps/LittlerootTown/scripts.pory"

# 1682 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeLegendsDisabled::
# 1683 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeLegendsDisabled, MSGBOX_YESNO
# 1684 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1685 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeLegends
# 1686 "data/maps/LittlerootTown/scripts.pory"
	return
# 1687 "data/maps/LittlerootTown/scripts.pory"

# 1688 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeLegends::
# 1689 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeLegends, MSGBOX_YESNO
# 1690 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1691 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableLegends
# 1692 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1693 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisableLegends
# 1694 "data/maps/LittlerootTown/scripts.pory"
	return
# 1695 "data/maps/LittlerootTown/scripts.pory"

# 1696 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableLegends::
# 1697 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 8 
# 1698 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1699 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1700 "data/maps/LittlerootTown/scripts.pory"
	return
# 1701 "data/maps/LittlerootTown/scripts.pory"
	
# 1702 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableLegends::
# 1703 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 8
# 1704 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1705 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1706 "data/maps/LittlerootTown/scripts.pory"
	return
# 1707 "data/maps/LittlerootTown/scripts.pory"
	
# 1708 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeStarters:
# 1709 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable random starters?$"
# 1710 "data/maps/LittlerootTown/scripts.pory"
		
# 1711 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeStartersEnabled:
# 1712 "data/maps/LittlerootTown/scripts.pory"
	.string "Random starters are enabled.\n"
# 1713 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1714 "data/maps/LittlerootTown/scripts.pory"

# 1715 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeStartersDisabled:
# 1716 "data/maps/LittlerootTown/scripts.pory"
	.string "Random starters are disabled.\n"
# 1717 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1718 "data/maps/LittlerootTown/scripts.pory"
		
# 1719 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_Starters::
# 1720 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 9
# 1721 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1722 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1723 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeStartersEnabled
# 1724 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1725 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangeStartersDisabled
# 1726 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1727 "data/maps/LittlerootTown/scripts.pory"
	
# 1728 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeStartersEnabled::
# 1729 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeStartersEnabled, MSGBOX_YESNO
# 1730 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1731 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeStarters
# 1732 "data/maps/LittlerootTown/scripts.pory"
	return
# 1733 "data/maps/LittlerootTown/scripts.pory"

# 1734 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeStartersDisabled::
# 1735 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeStartersDisabled, MSGBOX_YESNO
# 1736 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1737 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeStarters
# 1738 "data/maps/LittlerootTown/scripts.pory"
	return
# 1739 "data/maps/LittlerootTown/scripts.pory"

# 1740 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeStarters::
# 1741 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeStarters, MSGBOX_YESNO
# 1742 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1743 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableStarters
# 1744 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1745 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisableStarters
# 1746 "data/maps/LittlerootTown/scripts.pory"
	return
# 1747 "data/maps/LittlerootTown/scripts.pory"

# 1748 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableStarters::
# 1749 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 9 
# 1750 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1751 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1752 "data/maps/LittlerootTown/scripts.pory"
	return
# 1753 "data/maps/LittlerootTown/scripts.pory"
		
# 1754 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableStarters::
# 1755 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 9
# 1756 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1757 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1758 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1759 "data/maps/LittlerootTown/scripts.pory"
		
# 1760 "data/maps/LittlerootTown/scripts.pory"
		
# 1761 "data/maps/LittlerootTown/scripts.pory"
		
# 1762 "data/maps/LittlerootTown/scripts.pory"
		
# 1763 "data/maps/LittlerootTown/scripts.pory"
		
# 1764 "data/maps/LittlerootTown/scripts.pory"
		
# 1765 "data/maps/LittlerootTown/scripts.pory"
		
# 1766 "data/maps/LittlerootTown/scripts.pory"
		
# 1767 "data/maps/LittlerootTown/scripts.pory"
		
# 1768 "data/maps/LittlerootTown/scripts.pory"
		
# 1769 "data/maps/LittlerootTown/scripts.pory"
		
# 1770 "data/maps/LittlerootTown/scripts.pory"
		
# 1771 "data/maps/LittlerootTown/scripts.pory"
		
# 1772 "data/maps/LittlerootTown/scripts.pory"
		
# 1773 "data/maps/LittlerootTown/scripts.pory"
		
# 1774 "data/maps/LittlerootTown/scripts.pory"
		
# 1775 "data/maps/LittlerootTown/scripts.pory"
		
# 1776 "data/maps/LittlerootTown/scripts.pory"
		
# 1777 "data/maps/LittlerootTown/scripts.pory"
		
# 1778 "data/maps/LittlerootTown/scripts.pory"
		
# 1779 "data/maps/LittlerootTown/scripts.pory"
		
# 1780 "data/maps/LittlerootTown/scripts.pory"
		
# 1781 "data/maps/LittlerootTown/scripts.pory"
		
# 1782 "data/maps/LittlerootTown/scripts.pory"
		
# 1783 "data/maps/LittlerootTown/scripts.pory"
		
# 1784 "data/maps/LittlerootTown/scripts.pory"
		
# 1785 "data/maps/LittlerootTown/scripts.pory"
		
# 1786 "data/maps/LittlerootTown/scripts.pory"
		
# 1787 "data/maps/LittlerootTown/scripts.pory"
		
# 1788 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeUnobtainable:
# 1789 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable unobtainable Pokémon?$"
# 1790 "data/maps/LittlerootTown/scripts.pory"
		
# 1791 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeUnobtainableEnabled:
# 1792 "data/maps/LittlerootTown/scripts.pory"
	.string "Unobtainable Pokémon are enabled.\n"
# 1793 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1794 "data/maps/LittlerootTown/scripts.pory"

# 1795 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeUnobtainableDisabled:
# 1796 "data/maps/LittlerootTown/scripts.pory"
	.string "Unobtainable Pokémon are disabled.\n"
# 1797 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1798 "data/maps/LittlerootTown/scripts.pory"
		
# 1799 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_Unobtainable::
# 1800 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 10
# 1801 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1802 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1803 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeUnobtainableEnabled
# 1804 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1805 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangeUnobtainableDisabled
# 1806 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1807 "data/maps/LittlerootTown/scripts.pory"
	
# 1808 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeUnobtainableEnabled::
# 1809 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeUnobtainableEnabled, MSGBOX_YESNO
# 1810 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1811 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeUnobtainable
# 1812 "data/maps/LittlerootTown/scripts.pory"
	return
# 1813 "data/maps/LittlerootTown/scripts.pory"

# 1814 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeUnobtainableDisabled::
# 1815 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeUnobtainableDisabled, MSGBOX_YESNO
# 1816 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1817 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeUnobtainable
# 1818 "data/maps/LittlerootTown/scripts.pory"
	return
# 1819 "data/maps/LittlerootTown/scripts.pory"

# 1820 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeUnobtainable::
# 1821 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeUnobtainable, MSGBOX_YESNO
# 1822 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1823 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableUnobtainable
# 1824 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1825 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisableUnobtainable
# 1826 "data/maps/LittlerootTown/scripts.pory"
	return
# 1827 "data/maps/LittlerootTown/scripts.pory"

# 1828 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableUnobtainable::
# 1829 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 10
# 1830 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1831 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1832 "data/maps/LittlerootTown/scripts.pory"
	return
# 1833 "data/maps/LittlerootTown/scripts.pory"
		
# 1834 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableUnobtainable::
# 1835 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 10
# 1836 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1837 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1838 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1839 "data/maps/LittlerootTown/scripts.pory"
		
# 1840 "data/maps/LittlerootTown/scripts.pory"
		
# 1841 "data/maps/LittlerootTown/scripts.pory"
		
# 1842 "data/maps/LittlerootTown/scripts.pory"
		
# 1843 "data/maps/LittlerootTown/scripts.pory"
		
# 1844 "data/maps/LittlerootTown/scripts.pory"
		
# 1845 "data/maps/LittlerootTown/scripts.pory"
		
# 1846 "data/maps/LittlerootTown/scripts.pory"
		
# 1847 "data/maps/LittlerootTown/scripts.pory"
		
# 1848 "data/maps/LittlerootTown/scripts.pory"
		
# 1849 "data/maps/LittlerootTown/scripts.pory"
		
# 1850 "data/maps/LittlerootTown/scripts.pory"
		
# 1851 "data/maps/LittlerootTown/scripts.pory"
		
# 1852 "data/maps/LittlerootTown/scripts.pory"
		
# 1853 "data/maps/LittlerootTown/scripts.pory"
		
# 1854 "data/maps/LittlerootTown/scripts.pory"
		
# 1855 "data/maps/LittlerootTown/scripts.pory"
		
# 1856 "data/maps/LittlerootTown/scripts.pory"
		
# 1857 "data/maps/LittlerootTown/scripts.pory"
		
# 1858 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeAltForms:
# 1859 "data/maps/LittlerootTown/scripts.pory"
	.string "Enable alternate forms?\n"
# 1860 "data/maps/LittlerootTown/scripts.pory"
	.string "(Alolan, Galarian, cosmetic etc.)$"
# 1861 "data/maps/LittlerootTown/scripts.pory"
		
# 1862 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeAltFormsEnabled:
# 1863 "data/maps/LittlerootTown/scripts.pory"
	.string "Alternate forms are enabled.\n"
# 1864 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1865 "data/maps/LittlerootTown/scripts.pory"

# 1866 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ChangeAltFormsDisabled:
# 1867 "data/maps/LittlerootTown/scripts.pory"
	.string "Alternate forms are disabled.\n"
# 1868 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to change this settings?$"
# 1869 "data/maps/LittlerootTown/scripts.pory"
		
# 1870 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PatchSettings_AltForms::
# 1871 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 11
# 1872 "data/maps/LittlerootTown/scripts.pory"
	special GetSettingsMonStats
# 1873 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1874 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeAltFormsEnabled
# 1875 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8005, 1
# 1876 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_ChangeAltFormsDisabled
# 1877 "data/maps/LittlerootTown/scripts.pory"
	return	
# 1878 "data/maps/LittlerootTown/scripts.pory"
	
# 1879 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeAltFormsEnabled::
# 1880 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeAltFormsEnabled, MSGBOX_YESNO
# 1881 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1882 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeAltForms
# 1883 "data/maps/LittlerootTown/scripts.pory"
	return
# 1884 "data/maps/LittlerootTown/scripts.pory"

# 1885 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeAltFormsDisabled::
# 1886 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeAltFormsDisabled, MSGBOX_YESNO
# 1887 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1888 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_ChangeAltForms
# 1889 "data/maps/LittlerootTown/scripts.pory"
	return
# 1890 "data/maps/LittlerootTown/scripts.pory"

# 1891 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_ChangeAltForms::
# 1892 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ChangeAltForms, MSGBOX_YESNO
# 1893 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1894 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq LittlerootTown_EventScript_EnableAltForms
# 1895 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, YES
# 1896 "data/maps/LittlerootTown/scripts.pory"
	call_if_ne LittlerootTown_EventScript_DisableAltForms
# 1897 "data/maps/LittlerootTown/scripts.pory"
	return
# 1898 "data/maps/LittlerootTown/scripts.pory"

# 1899 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EnableAltForms::
# 1900 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 11
# 1901 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 1
# 1902 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1903 "data/maps/LittlerootTown/scripts.pory"
	return
# 1904 "data/maps/LittlerootTown/scripts.pory"
		
# 1905 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DisableAltForms::
# 1906 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8006, 11
# 1907 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8007, 0
# 1908 "data/maps/LittlerootTown/scripts.pory"
	special SetSettingsMonStats
# 1909 "data/maps/LittlerootTown/scripts.pory"
	return

LittlerootTown_EventScript_LegendaryNPC::
# 1913 "data/maps/LittlerootTown/scripts.pory"
	lock
# 1914 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 1915 "data/maps/LittlerootTown/scripts.pory"
	goto_if_unset FLAG_GOT_LEGENDARY_NPC_ITEMS, LittlerootTown_EventScript_LegendaryNPC_2
# 1978 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_LegendaryNPC_Text_4, MSGBOX_DEFAULT
# 1979 "data/maps/LittlerootTown/scripts.pory"
	multichoice2 1, 1, LittlerootTown_EventScript_LegendaryNPC_Options
# 1980 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 1981 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_LegendaryNPC_12
# 1986 "data/maps/LittlerootTown/scripts.pory"
	case MULTI_B_PRESSED, LittlerootTown_EventScript_LegendaryNPC_13
LittlerootTown_EventScript_LegendaryNPC_13:
# 1988 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_LegendaryNPC_Text_5
LittlerootTown_EventScript_LegendaryNPC_1:
# 1991 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_LegendaryNPC_2:
# 1916 "data/maps/LittlerootTown/scripts.pory"
	checkSaveblockValue SAVEBLOCK_ENABLE_LEGENDARY
# 1917 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LittlerootTown_EventScript_LegendaryNPC_8
LittlerootTown_EventScript_LegendaryNPC_7:
# 1921 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_LegendaryNPC_Text_1
LittlerootTown_EventScript_LegendaryNPC_5:
# 1923 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_GRACIDEA
# 1924 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_REVEAL_GLASS
# 1925 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_DNA_SPLICERS
# 1926 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_PRISON_BOTTLE
# 1927 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_N_LUNARIZER
# 1928 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_N_SOLARIZER
# 1929 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_FLAME_PLATE
# 1930 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_SPLASH_PLATE
# 1931 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_ZAP_PLATE
# 1932 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_MEADOW_PLATE
# 1933 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_ICICLE_PLATE
# 1934 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_FIST_PLATE
# 1935 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_TOXIC_PLATE
# 1936 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_EARTH_PLATE
# 1937 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_SKY_PLATE
# 1938 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_MIND_PLATE
# 1939 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_INSECT_PLATE
# 1940 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_STONE_PLATE
# 1941 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_SPOOKY_PLATE
# 1942 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_DRACO_PLATE
# 1943 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_DREAD_PLATE
# 1944 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_IRON_PLATE
# 1945 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_PIXIE_PLATE
# 1946 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_FIRE_MEMORY
# 1947 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_WATER_MEMORY
# 1948 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_ELECTRIC_MEMORY
# 1949 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_GRASS_MEMORY
# 1950 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_ICE_MEMORY
# 1951 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_FIGHTING_MEMORY
# 1952 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_POISON_MEMORY
# 1953 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_GROUND_MEMORY
# 1954 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_FLYING_MEMORY
# 1955 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_PSYCHIC_MEMORY
# 1956 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_BUG_MEMORY
# 1957 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_ROCK_MEMORY
# 1958 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_GHOST_MEMORY
# 1959 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_DRAGON_MEMORY
# 1960 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_DARK_MEMORY
# 1961 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_STEEL_MEMORY
# 1962 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_FAIRY_MEMORY
# 1963 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_SHOCK_DRIVE
# 1964 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_BURN_DRIVE
# 1965 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_CHILL_DRIVE
# 1966 "data/maps/LittlerootTown/scripts.pory"
	additem ITEM_DOUSE_DRIVE
# 1967 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1968 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_LegendaryNPC_Text_2
# 1969 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 1970 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 1971 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_GOT_LEGENDARY_NPC_ITEMS
# 1972 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_LegendaryNPC_Text_3
	goto LittlerootTown_EventScript_LegendaryNPC_1

LittlerootTown_EventScript_LegendaryNPC_6:
# 1918 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_LegendaryNPC_Text_0
	goto LittlerootTown_EventScript_LegendaryNPC_5

LittlerootTown_EventScript_LegendaryNPC_8:
# 1917 "data/maps/LittlerootTown/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, LittlerootTown_EventScript_LegendaryNPC_6
	goto LittlerootTown_EventScript_LegendaryNPC_7

LittlerootTown_EventScript_LegendaryNPC_12:
# 1982 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_LegendaryNPC_Text_3
	goto LittlerootTown_EventScript_LegendaryNPC_1


LittlerootTown_EventScript_TutorialNPC::
# 2002 "data/maps/LittlerootTown/scripts.pory"
	lock
# 2003 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 2004 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC_Text_0
# 2005 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
# 2006 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_TutorialNPC2::
# 2011 "data/maps/LittlerootTown/scripts.pory"
	messageinstant LittlerootTown_EventScript_TutorialNPC2_Text_0
# 2012 "data/maps/LittlerootTown/scripts.pory"
	scrollingmultichoice2 0, 0, 0, 6, TRUE
# 2013 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 2014 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_TutorialNPC2_3
# 2019 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_TutorialNPC2_4
# 2024 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_TutorialNPC2_5
# 2030 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_TutorialNPC2_6
# 2036 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_TutorialNPC2_7
# 2042 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_TutorialNPC2_8
# 2050 "data/maps/LittlerootTown/scripts.pory"
	case 6, LittlerootTown_EventScript_TutorialNPC2_9
# 2056 "data/maps/LittlerootTown/scripts.pory"
	case 7, LittlerootTown_EventScript_TutorialNPC2_10
# 2062 "data/maps/LittlerootTown/scripts.pory"
	case 8, LittlerootTown_EventScript_TutorialNPC2_11
# 2067 "data/maps/LittlerootTown/scripts.pory"
	case 9, LittlerootTown_EventScript_TutorialNPC2_12
# 2071 "data/maps/LittlerootTown/scripts.pory"
	case 10, LittlerootTown_EventScript_TutorialNPC2_13
# 2074 "data/maps/LittlerootTown/scripts.pory"
	case 11, LittlerootTown_EventScript_TutorialNPC2_14
# 2079 "data/maps/LittlerootTown/scripts.pory"
	case 12, LittlerootTown_EventScript_TutorialNPC2_15
# 2082 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_TutorialNPC2_16
# 2086 "data/maps/LittlerootTown/scripts.pory"
	case 14, LittlerootTown_EventScript_TutorialNPC2_17
# 2090 "data/maps/LittlerootTown/scripts.pory"
	case 15, LittlerootTown_EventScript_TutorialNPC2_18
# 2094 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_TutorialNPC2_19
# 2095 "data/maps/LittlerootTown/scripts.pory"
	case MULTI_B_PRESSED, LittlerootTown_EventScript_TutorialNPC2_19
LittlerootTown_EventScript_TutorialNPC2_19:
# 2097 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_LegendaryNPC_Text_5
LittlerootTown_EventScript_TutorialNPC2_1:
# 2099 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_TutorialNPC2_3:
# 2015 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_1
# 2018 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_4:
# 2020 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_2
# 2023 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_5:
# 2025 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_3
# 2029 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_6:
# 2031 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_4
# 2035 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_7:
# 2037 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_5
# 2041 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_8:
# 2043 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_6
# 2049 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_9:
# 2051 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_7
# 2055 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_10:
# 2057 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_8
# 2061 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_11:
# 2063 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_9
# 2066 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_12:
# 2068 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_10
# 2070 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_13:
# 2072 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_11
# 2073 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_14:
# 2075 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_12
# 2078 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_15:
# 2080 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_13
# 2081 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_16:
# 2083 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_14
# 2085 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_17:
# 2087 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_15
# 2089 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1

LittlerootTown_EventScript_TutorialNPC2_18:
# 2091 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TutorialNPC2_Text_16
# 2093 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_TutorialNPC2
	goto LittlerootTown_EventScript_TutorialNPC2_1


PKMN_Center_Move_Tutor::
# 2104 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 2105 "data/maps/LittlerootTown/scripts.pory"
	messageinstant PKMN_Center_Move_Tutor_Text_0
# 2106 "data/maps/LittlerootTown/scripts.pory"
	multichoice2 0, 0, MultiChoice_Move_Tutor_NPC
# 2107 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 2108 "data/maps/LittlerootTown/scripts.pory"
	case 0, PKMN_Center_Move_Tutor_2
# 2112 "data/maps/LittlerootTown/scripts.pory"
	case 1, PKMN_Center_Move_Tutor_3
# 2116 "data/maps/LittlerootTown/scripts.pory"
	case 2, PKMN_Center_Move_Tutor_4
# 2120 "data/maps/LittlerootTown/scripts.pory"
	case 3, PKMN_Center_Move_Tutor_5
# 2124 "data/maps/LittlerootTown/scripts.pory"
	case 4, PKMN_Center_Move_Tutor_6
# 2128 "data/maps/LittlerootTown/scripts.pory"
	case MULTI_B_PRESSED, PKMN_Center_Move_Tutor_7
# 2130 "data/maps/LittlerootTown/scripts.pory"
	case 5, PKMN_Center_Move_Tutor_7
PKMN_Center_Move_Tutor_7:
# 2131 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 2132 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_Move_Tutor_General_Exit
	return

PKMN_Center_Move_Tutor_2:
# 2109 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 2110 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_EventScript_DayNightToggle
	return

PKMN_Center_Move_Tutor_3:
# 2113 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 2114 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_EventScript_RandomizerToggle
	return

PKMN_Center_Move_Tutor_4:
# 2117 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 2118 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_NameRater_EventScript
	return

PKMN_Center_Move_Tutor_5:
# 2121 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 2122 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_EventScript_Mystery_Gift
	return

PKMN_Center_Move_Tutor_6:
# 2125 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 2126 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_EventScript_Lower_Difficulty
	return


PKMN_Center_EventScript_DayNightToggle::
# 2138 "data/maps/LittlerootTown/scripts.pory"
	msgbox PKMN_Center_EventScript_DayNightToggle_Text_0, MSGBOX_YESNO
# 2140 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 2141 "data/maps/LittlerootTown/scripts.pory"
	case YES, PKMN_Center_EventScript_DayNightToggle_3
# 2153 "data/maps/LittlerootTown/scripts.pory"
	case NO, PKMN_Center_EventScript_DayNightToggle_4
# 2154 "data/maps/LittlerootTown/scripts.pory"
	case MULTI_B_PRESSED, PKMN_Center_EventScript_DayNightToggle_4
PKMN_Center_EventScript_DayNightToggle_4:
# 2156 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_Move_Tutor
PKMN_Center_EventScript_DayNightToggle_1:
# 2159 "data/maps/LittlerootTown/scripts.pory"
	release
	end

PKMN_Center_EventScript_DayNightToggle_3:
# 2142 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_IS_DAYNIGHT_INVERTED, PKMN_Center_EventScript_DayNightToggle_6
# 2146 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_IS_DAYNIGHT_INVERTED
PKMN_Center_EventScript_DayNightToggle_5:
# 2148 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2149 "data/maps/LittlerootTown/scripts.pory"
	message PKMN_Center_EventScript_DayNightToggle_Text_1
# 2150 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 2151 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
	goto PKMN_Center_EventScript_DayNightToggle_1

PKMN_Center_EventScript_DayNightToggle_6:
# 2143 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_IS_DAYNIGHT_INVERTED
	goto PKMN_Center_EventScript_DayNightToggle_5


PKMN_Center_EventScript_RandomizerToggle::
# 2164 "data/maps/LittlerootTown/scripts.pory"
	checkSaveblockValue SAVEBLOCK_RANDOMIZER
# 2165 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PKMN_Center_EventScript_RandomizerToggle_2
# 2186 "data/maps/LittlerootTown/scripts.pory"
	msgbox PKMN_Center_EventScript_RandomizerToggle_Text_2, MSGBOX_NPC
# 2187 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 2188 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_Move_Tutor
PKMN_Center_EventScript_RandomizerToggle_1:
# 2190 "data/maps/LittlerootTown/scripts.pory"
	release
	end

PKMN_Center_EventScript_RandomizerToggle_2:
# 2166 "data/maps/LittlerootTown/scripts.pory"
	msgbox PKMN_Center_EventScript_RandomizerToggle_Text_0, MSGBOX_YESNO
# 2167 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 2168 "data/maps/LittlerootTown/scripts.pory"
	case YES, PKMN_Center_EventScript_RandomizerToggle_6
# 2178 "data/maps/LittlerootTown/scripts.pory"
	case NO, PKMN_Center_EventScript_RandomizerToggle_7
# 2179 "data/maps/LittlerootTown/scripts.pory"
	case MULTI_B_PRESSED, PKMN_Center_EventScript_RandomizerToggle_7
PKMN_Center_EventScript_RandomizerToggle_7:
# 2181 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_Move_Tutor
	goto PKMN_Center_EventScript_RandomizerToggle_1

PKMN_Center_EventScript_RandomizerToggle_6:
# 2169 "data/maps/LittlerootTown/scripts.pory"
	checkSaveblockValue SAVEBLOCK_RANDOMIZER
# 2170 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq PKMN_Center_EventScript_RandomizerToggle_9
PKMN_Center_EventScript_RandomizerToggle_8:
# 2175 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 2176 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
	goto PKMN_Center_EventScript_RandomizerToggle_1

PKMN_Center_EventScript_RandomizerToggle_9:
# 2171 "data/maps/LittlerootTown/scripts.pory"
	toggleSaveblock SAVEBLOCK_RANDOMIZER, FALSE
# 2172 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2173 "data/maps/LittlerootTown/scripts.pory"
	message PKMN_Center_EventScript_RandomizerToggle_Text_1
	goto PKMN_Center_EventScript_RandomizerToggle_8


PKMN_Center_EventScript_Lower_Difficulty::
# 2195 "data/maps/LittlerootTown/scripts.pory"
	checkSaveblockValue SAVEBLOCK_DIFFICULTY
# 2196 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, DIFFICULTY_EASY
	goto_if_ne PKMN_Center_EventScript_Lower_Difficulty_2
# 2222 "data/maps/LittlerootTown/scripts.pory"
	msgbox PKMN_Center_EventScript_Lower_Difficulty_Text_3
# 2223 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_Move_Tutor
PKMN_Center_EventScript_Lower_Difficulty_1:
# 2225 "data/maps/LittlerootTown/scripts.pory"
	release
	end

PKMN_Center_EventScript_Lower_Difficulty_2:
# 2197 "data/maps/LittlerootTown/scripts.pory"
	msgbox PKMN_Center_EventScript_Lower_Difficulty_Text_0, MSGBOX_YESNO
# 2198 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 2199 "data/maps/LittlerootTown/scripts.pory"
	case YES, PKMN_Center_EventScript_Lower_Difficulty_6
# 2214 "data/maps/LittlerootTown/scripts.pory"
	case NO, PKMN_Center_EventScript_Lower_Difficulty_7
# 2215 "data/maps/LittlerootTown/scripts.pory"
	case MULTI_B_PRESSED, PKMN_Center_EventScript_Lower_Difficulty_7
PKMN_Center_EventScript_Lower_Difficulty_7:
# 2217 "data/maps/LittlerootTown/scripts.pory"
	goto PKMN_Center_Move_Tutor
	goto PKMN_Center_EventScript_Lower_Difficulty_1

PKMN_Center_EventScript_Lower_Difficulty_6:
# 2200 "data/maps/LittlerootTown/scripts.pory"
	checkSaveblockValue SAVEBLOCK_DIFFICULTY
# 2201 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, DIFFICULTY_ELITE
	goto_if_eq PKMN_Center_EventScript_Lower_Difficulty_9
# 2207 "data/maps/LittlerootTown/scripts.pory"
	toggleSaveblock SAVEBLOCK_DIFFICULTY, DIFFICULTY_EASY
# 2208 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2209 "data/maps/LittlerootTown/scripts.pory"
	message PKMN_Center_EventScript_Lower_Difficulty_Text_2
PKMN_Center_EventScript_Lower_Difficulty_8:
# 2211 "data/maps/LittlerootTown/scripts.pory"
	waitmessage
# 2212 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
	goto PKMN_Center_EventScript_Lower_Difficulty_1

PKMN_Center_EventScript_Lower_Difficulty_9:
# 2202 "data/maps/LittlerootTown/scripts.pory"
	toggleSaveblock SAVEBLOCK_DIFFICULTY, DIFFICULTY_ACE
# 2203 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 2204 "data/maps/LittlerootTown/scripts.pory"
	message PKMN_Center_EventScript_Lower_Difficulty_Text_1
	goto PKMN_Center_EventScript_Lower_Difficulty_8


LittlerootTown_EventScript_EnableLegendaryNPC::
# 2244 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_REMOVE_LEGENDARY_NPC
# 2245 "data/maps/LittlerootTown/scripts.pory"
	checkSaveblockValue SAVEBLOCK_ENABLE_LEGENDARY
# 2246 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LittlerootTown_EventScript_EnableLegendaryNPC_2
# 2246 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LittlerootTown_EventScript_EnableLegendaryNPC_2
LittlerootTown_EventScript_EnableLegendaryNPC_1:
	return

LittlerootTown_EventScript_EnableLegendaryNPC_2:
# 2247 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_REMOVE_LEGENDARY_NPC
	goto LittlerootTown_EventScript_EnableLegendaryNPC_1


LittlerootTown_EventScript_LegendaryNPC_Text_0:
# 1918 "data/maps/LittlerootTown/scripts.pory"
	.string "Since you're playing a Randomizer mode,\n"
	.string "have all the Legendary Pokémon Items!$"

LittlerootTown_EventScript_LegendaryNPC_Text_1:
# 1921 "data/maps/LittlerootTown/scripts.pory"
	.string "Congratulations on becoming champion!\n"
	.string "Your efforts haven't gone unnoticed.\l"
	.string "I've been waiting this day for ages, but\l"
	.string "I can finally put these items in hands I\l"
	.string "can trust.$"

LittlerootTown_EventScript_LegendaryNPC_Text_2:
# 1968 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} received legendary\n"
	.string "artifacts from the Sage!$"

LittlerootTown_EventScript_LegendaryNPC_Text_3:
# 1972 "data/maps/LittlerootTown/scripts.pory"
	.string "The legendary Pokémon that once\n"
	.string "roamed these lands have returned,\l"
	.string "thanks to you.\p"
	.string "Clear all opponents in a route to make\n"
	.string "it suitable for these legendary beasts\l"
	.string "to appear.\p"
	.string "If you're unsure about something, just\n"
	.string "ask my associates on the field, they'll\l"
	.string "tell you everything you need to know.\p"
	.string "Good luck, champion, we look forward to\n"
	.string "your success!$"

LittlerootTown_EventScript_LegendaryNPC_Text_4:
# 1978 "data/maps/LittlerootTown/scripts.pory"
	.string "Do you need anything?$"

LittlerootTown_EventScript_LegendaryNPC_Text_5:
# 1988 "data/maps/LittlerootTown/scripts.pory"
	.string "See you later.$"

LittlerootTown_EventScript_TutorialNPC_Text_0:
# 2004 "data/maps/LittlerootTown/scripts.pory"
	.string "Hi {PLAYER}, I can tell you about the\n"
	.string "changes Elite Redux has.$"

LittlerootTown_EventScript_TutorialNPC2_Text_0:
# 2011 "data/maps/LittlerootTown/scripts.pory"
	.string "What do you want to know?$"

LittlerootTown_EventScript_TutorialNPC2_Text_1:
# 2015 "data/maps/LittlerootTown/scripts.pory"
	.string "Talk to Nurse Joy in any Pokémon\n"
	.string "Center, she will give you the following:\p"
	.string "Candy Box, DexNav, TM Case, all TMs &\n"
	.string "HMs, Battle items, all Pokéballs, all\l"
	.string "Berries, all Type Gems etc.\p"
	.string "Every time you speak to her, all items\n"
	.string "get refilled.$"

LittlerootTown_EventScript_TutorialNPC2_Text_2:
# 2020 "data/maps/LittlerootTown/scripts.pory"
	.string "Almost every Pokémon has been buffed\n"
	.string "to be more fun and useful.\p"
	.string "Some Pokémon have been reworked - e.g.\n"
	.string "Arbok is Poison/Dark and Gyarados is\l"
	.string "Water/Dragon with Levitate now. Gengar\l"
	.string "is levitating all the time and can be\l"
	.string "played special or physical now with\l"
	.string "fitting moves.\p"
	.string "Check out the Online Pokédex for more\n"
	.string "information.$"

LittlerootTown_EventScript_TutorialNPC2_Text_3:
# 2025 "data/maps/LittlerootTown/scripts.pory"
	.string "Every Pokémon now has up to four\n"
	.string "abilities at the same time.\p"
	.string "There are up to three fixed ones, called\n"
	.string "innates.\p"
	.string "There are over 110 new abilities, but\n"
	.string "many exisiting abilities also have a new\l"
	.string "effect. E.g. Ice Body etc. now recovers\l"
	.string "1/8 HP per turn or Big Pecks acts like\l"
	.string "Tough Claws now.\p"
	.string "Check out the Online Pokédex for more\n"
	.string "information.$"

LittlerootTown_EventScript_TutorialNPC2_Text_4:
# 2031 "data/maps/LittlerootTown/scripts.pory"
	.string "Many moves have been buffed (mostly\n"
	.string "accuracy, but some have more drastic\l"
	.string "changes).\p"
	.string "OHKO moves like Fissure aren't OHKO\n"
	.string "anymore and deal roughly 120 damage\l"
	.string "with 80% accuracy.\p"
	.string "More moves are affected by certain\n"
	.string "abilities (i.e. Mega Launcher).\p"
	.string "Check out the Online Pokédex for more\n"
	.string "information.$"

LittlerootTown_EventScript_TutorialNPC2_Text_5:
# 2037 "data/maps/LittlerootTown/scripts.pory"
	.string "You now have a portable PC (Start Menu).\n"
	.string "It's disabled for the Elite Four.\p"
	.string "You can switch Auto Run, Permanent\n"
	.string "Repel and much more in the Options.\p"
	.string "No need to teach HMs, also you can fly\n"
	.string "to already visited places with every\l"
	.string "Pokémon.\p"
	.string "You can register items in a new list\n"
	.string "menu (press L to access list).$"

LittlerootTown_EventScript_TutorialNPC2_Text_6:
# 2043 "data/maps/LittlerootTown/scripts.pory"
	.string "Weather induced by abilities is 8 turns\n"
	.string "now (12 turns with Weather Rocks), but\l"
	.string "the damage boost for Fire and Water\l"
	.string "moves in Sun and Rain has been reduced\l"
	.string "from 50% to 20%. Sandstream and Snow\l"
	.string "Warning have no penalties.\p"
	.string "Ice-types now get a 50% defense boost\n"
	.string "in Hail. Sandstorm still gives the same\l"
	.string "50% SpDef boost.\p"
	.string "When the weather is induced by moves\n"
	.string "such as Sunny Day or Rain Dance, it still\l"
	.string "lasts 5 rounds, but has 50% power boost\l"
	.string "for the respective types.\p"
	.string "Every Pokémon has 31 IVs by default,\n"
	.string "but you can use the Iron Pill to set\l"
	.string "Speed to 0.\p"
	.string "For Ace and Elite Mode, there is a Sleep\n"
	.string "Clause, which prevents putting more\l"
	.string "than one enemy Pokémon to sleep.\p"
	.string "Every move is already PP maxed. All held\n"
	.string "items stay on your Pokémon after\l"
	.string "battling.$"

LittlerootTown_EventScript_TutorialNPC2_Text_7:
# 2051 "data/maps/LittlerootTown/scripts.pory"
	.string "Press L in battle to check move power,\n"
	.string "accuracy and if the move makes\l"
	.string "contact.\p"
	.string "Now you also see a move's\n"
	.string "effectiveness before attacking. This\l"
	.string "even considers some abilities like\l"
	.string "Levitate or Sap Sipper!\p"
	.string "STAB (50% Same Type Attack Bonus) is\n"
	.string "noted with a Plus Icon.\p"
	.string "You can forfeit trainer battles now.\n"
	.string "You will get sent to the last Pokémon\l"
	.string "Center.$"

LittlerootTown_EventScript_TutorialNPC2_Text_8:
# 2057 "data/maps/LittlerootTown/scripts.pory"
	.string "You'll get one of each Pokéball from\n"
	.string "Nurse Joy. Every ball has 100% catch\l"
	.string "rate.\p"
	.string "Nurse Joy gives you an upgraded\n"
	.string "DexNav: you can directly search the\l"
	.string "Pokémon you want. No need to walk slow\l"
	.string "when approaching.\p"
	.string "The Shiny rate can be massively\n"
	.string "boosted, up to 1/5.\p"
	.string "You can catch almost every Pokémon\n"
	.string "from Gen 1 to 8.$"

LittlerootTown_EventScript_TutorialNPC2_Text_9:
# 2063 "data/maps/LittlerootTown/scripts.pory"
	.string "You can directly switch the ability in\n"
	.string "the Pokémon Summary Screen.\p"
	.string "Some Pokémon only have one ability,\n"
	.string "others have up to three.\p"
	.string "Every Pokémon has up to 3 fixed\n"
	.string "innates. You can't change innates.$"

LittlerootTown_EventScript_TutorialNPC2_Text_10:
# 2068 "data/maps/LittlerootTown/scripts.pory"
	.string "You can directly switch the nature in\n"
	.string "the Pokémon Summary Screen.\p"
	.string "The nature will increase one Base Stat\n"
	.string "by 10% while decreasing another one by\l"
	.string "10%.$"

LittlerootTown_EventScript_TutorialNPC2_Text_11:
# 2072 "data/maps/LittlerootTown/scripts.pory"
	.string "Just use the Type Gems which Nurse Joy\n"
	.string "gives you, on any Pokémon.$"

LittlerootTown_EventScript_TutorialNPC2_Text_12:
# 2075 "data/maps/LittlerootTown/scripts.pory"
	.string "You can directly set the EVs on your\n"
	.string "Pokémon in the Summary Screen. No more\l"
	.string "grinding!\p"
	.string "You can have up to 252 EVs in one stat,\n"
	.string "but you can only have 510 EVs in total.\p"
	.string "In most cases, you'd want to put 252\n"
	.string "EVs in your best two stats.$"

LittlerootTown_EventScript_TutorialNPC2_Text_13:
# 2080 "data/maps/LittlerootTown/scripts.pory"
	.string "You can easily learn new moves directly\n"
	.string "in the Party Menu, but you still need to\l"
	.string "level up to learn certain moves.$"

LittlerootTown_EventScript_TutorialNPC2_Text_14:
# 2083 "data/maps/LittlerootTown/scripts.pory"
	.string "Your whole party will get healed before\n"
	.string "every battle.\p"
	.string "This is also to prevent you from\n"
	.string "pre-burning/poisoning ;-)$"

LittlerootTown_EventScript_TutorialNPC2_Text_15:
# 2087 "data/maps/LittlerootTown/scripts.pory"
	.string "There is a new key item - the Candy Box.\n"
	.string "You can easily level up this way.\p"
	.string "As there are level caps and\n"
	.string "auto-scaling levels (wild + trainer\l"
	.string "battles), you don't have to worry about\l"
	.string "overleveling.$"

LittlerootTown_EventScript_TutorialNPC2_Text_16:
# 2091 "data/maps/LittlerootTown/scripts.pory"
	.string "You can buy all evolution items in the\n"
	.string "Poké Mart.\p"
	.string "You can check the In-Game or Online\n"
	.string "Pokédex for how to evolve a certain\l"
	.string "Pokémon.$"

PKMN_Center_Move_Tutor_Text_0:
# 2105 "data/maps/LittlerootTown/scripts.pory"
	.string "How can I help you today?$"

PKMN_Center_EventScript_DayNightToggle_Text_0:
# 2138 "data/maps/LittlerootTown/scripts.pory"
	.string "Do you want to invert day/night?\n"
	.string "Only used for the Shoal Cave.$"

PKMN_Center_EventScript_DayNightToggle_Text_1:
# 2149 "data/maps/LittlerootTown/scripts.pory"
	.string "The Day and Night time was inverted.$"

PKMN_Center_EventScript_RandomizerToggle_Text_0:
# 2166 "data/maps/LittlerootTown/scripts.pory"
	.string "Do you want to disable the Randomizer\n"
	.string "for wild encounters?$"

PKMN_Center_EventScript_RandomizerToggle_Text_1:
# 2173 "data/maps/LittlerootTown/scripts.pory"
	.string "The randomizer was disabled.$"

PKMN_Center_EventScript_RandomizerToggle_Text_2:
# 2186 "data/maps/LittlerootTown/scripts.pory"
	.string "You already have the Randomizer\n"
	.string "Disabled.$"

PKMN_Center_EventScript_Lower_Difficulty_Text_0:
# 2197 "data/maps/LittlerootTown/scripts.pory"
	.string "Do you want to lower the difficulty?\n"
	.string "THIS CAN NOT BE UNDONE LATER!$"

PKMN_Center_EventScript_Lower_Difficulty_Text_1:
# 2204 "data/maps/LittlerootTown/scripts.pory"
	.string "The difficulty became Ace.$"

PKMN_Center_EventScript_Lower_Difficulty_Text_2:
# 2209 "data/maps/LittlerootTown/scripts.pory"
	.string "The difficulty became Easy.$"

PKMN_Center_EventScript_Lower_Difficulty_Text_3:
# 2222 "data/maps/LittlerootTown/scripts.pory"
	.string "You are already in the lowest\n"
	.string "difficulty, git gud!$"

LittlerootTown_EventScript_LegendaryNPC_Options::
# 1995 "data/maps/LittlerootTown/scripts.pory"
	.string "Please explain things to me again$"
	.string "Nevermind$"
	.string "$"

MultiChoice_Move_Tutor_NPC::
# 2229 "data/maps/LittlerootTown/scripts.pory"
	.string "Invert Day and Night$"
	.string "Disable Randomizer$"
	.string "Rate a nickname$"
	.string "Mystery Gift$"
	.string "Lower Difficulty$"
	.string "Exit$"
	.string "$"

Text_Pokemart_Script_No_Badges::
# 2239 "data/maps/LittlerootTown/scripts.pory"
	.string "Sorry but I can't sell you any item yet,\n"
	.string "you need atleast one badge.$"
