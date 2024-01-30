# 1 "data/maps/Route112_CableCarStation/scripts.pory"

# 2 "data/maps/Route112_CableCarStation/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/Route112_CableCarStation/scripts.pory"

# 4 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_MapScripts:: @ 822AABE
# 5 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_OnTransition
# 6 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_OnFrame
# 7 "data/maps/Route112_CableCarStation/scripts.pory"
	.byte 0
# 8 "data/maps/Route112_CableCarStation/scripts.pory"

# 9 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_OnTransition: @ 822AAC9
# 10 "data/maps/Route112_CableCarStation/scripts.pory"
	setescapewarp MAP_ROUTE112, 255, 28, 28
# 11 "data/maps/Route112_CableCarStation/scripts.pory"
	compare VAR_CABLE_CAR_STATION_STATE, 2
# 12 "data/maps/Route112_CableCarStation/scripts.pory"
	call_if_eq Route112_CableCarStation_EventScript_MoveAttendantAside
# 13 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 14 "data/maps/Route112_CableCarStation/scripts.pory"

# 15 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_MoveAttendantAside:: @ 822AADD
# 16 "data/maps/Route112_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 7, 4
# 17 "data/maps/Route112_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_LEFT
# 18 "data/maps/Route112_CableCarStation/scripts.pory"
	return
# 19 "data/maps/Route112_CableCarStation/scripts.pory"

# 20 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_OnFrame: @ 822AAE9
# 21 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_ExitCableCar
# 22 "data/maps/Route112_CableCarStation/scripts.pory"
	.2byte 0
# 23 "data/maps/Route112_CableCarStation/scripts.pory"

# 24 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_ExitCableCar:: @ 822AAF3
# 25 "data/maps/Route112_CableCarStation/scripts.pory"
	lockall
# 26 "data/maps/Route112_CableCarStation/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route112_CableCarStation_Movement_ExitCableCar
# 27 "data/maps/Route112_CableCarStation/scripts.pory"
	applymovement LOCALID_ATTENDANT, Route112_CableCarStation_Movement_FollowPlayerOutFromCableCar
# 28 "data/maps/Route112_CableCarStation/scripts.pory"
	waitmovement 0
# 29 "data/maps/Route112_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 0
# 30 "data/maps/Route112_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
# 31 "data/maps/Route112_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
# 32 "data/maps/Route112_CableCarStation/scripts.pory"
	releaseall
# 33 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 34 "data/maps/Route112_CableCarStation/scripts.pory"

# 35 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_Attendant:: @ 822AB17
# 36 "data/maps/Route112_CableCarStation/scripts.pory"
	lock
# 37 "data/maps/Route112_CableCarStation/scripts.pory"
	faceplayer
# 38 "data/maps/Route112_CableCarStation/scripts.pory"
	msgbox Route112_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
# 39 "data/maps/Route112_CableCarStation/scripts.pory"
	compare VAR_RESULT, YES
# 40 "data/maps/Route112_CableCarStation/scripts.pory"
	goto_if_eq Route112_CableCarStation_EventScript_RideCableCar
# 41 "data/maps/Route112_CableCarStation/scripts.pory"
	compare VAR_RESULT, NO
# 42 "data/maps/Route112_CableCarStation/scripts.pory"
	goto_if_eq Route112_CableCarStation_EventScript_DeclineRide
# 43 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 44 "data/maps/Route112_CableCarStation/scripts.pory"

# 45 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_RideCableCar:: @ 822AB38
# 46 "data/maps/Route112_CableCarStation/scripts.pory"
	msgbox Route112_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
# 47 "data/maps/Route112_CableCarStation/scripts.pory"
	closemessage
# 48 "data/maps/Route112_CableCarStation/scripts.pory"
	applymovement LOCALID_ATTENDANT, Route112_CableCarStation_Movement_LeadPlayerToCableCar
# 49 "data/maps/Route112_CableCarStation/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route112_CableCarStation_Movement_BoardCableCar
# 50 "data/maps/Route112_CableCarStation/scripts.pory"
	waitmovement 0
# 51 "data/maps/Route112_CableCarStation/scripts.pory"
	setvar VAR_0x8004, FALSE  @ Going up
# 52 "data/maps/Route112_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 1
# 53 "data/maps/Route112_CableCarStation/scripts.pory"
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
# 54 "data/maps/Route112_CableCarStation/scripts.pory"
	special CableCarWarp
# 55 "data/maps/Route112_CableCarStation/scripts.pory"
	special CableCar
# 56 "data/maps/Route112_CableCarStation/scripts.pory"
	waitstate
# 57 "data/maps/Route112_CableCarStation/scripts.pory"
	release
# 58 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 59 "data/maps/Route112_CableCarStation/scripts.pory"

# 60 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_EventScript_DeclineRide:: @ 822AB67
# 61 "data/maps/Route112_CableCarStation/scripts.pory"
	msgbox Route112_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
# 62 "data/maps/Route112_CableCarStation/scripts.pory"
	release
# 63 "data/maps/Route112_CableCarStation/scripts.pory"
	end
# 64 "data/maps/Route112_CableCarStation/scripts.pory"

# 65 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Movement_LeadPlayerToCableCar: @ 822AB71
# 66 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 67 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 68 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_right
# 69 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_in_place_fastest_left
# 70 "data/maps/Route112_CableCarStation/scripts.pory"
	step_end
# 71 "data/maps/Route112_CableCarStation/scripts.pory"

# 72 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Movement_FollowPlayerOutFromCableCar: @ 822AB76
# 73 "data/maps/Route112_CableCarStation/scripts.pory"
	delay_16
# 74 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_left
# 75 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 76 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 77 "data/maps/Route112_CableCarStation/scripts.pory"
	step_end
# 78 "data/maps/Route112_CableCarStation/scripts.pory"

# 79 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Movement_BoardCableCar: @ 822AB7B
# 80 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 81 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 82 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_up
# 83 "data/maps/Route112_CableCarStation/scripts.pory"
	delay_16
# 84 "data/maps/Route112_CableCarStation/scripts.pory"
	step_end
# 85 "data/maps/Route112_CableCarStation/scripts.pory"

# 86 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Movement_ExitCableCar: @ 822AB80
# 87 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 88 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 89 "data/maps/Route112_CableCarStation/scripts.pory"
	walk_down
# 90 "data/maps/Route112_CableCarStation/scripts.pory"
	delay_16
# 91 "data/maps/Route112_CableCarStation/scripts.pory"
	step_end
# 92 "data/maps/Route112_CableCarStation/scripts.pory"

# 93 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Text_CableCarReadyGetOn: @ 822AB85
# 94 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "The Cable Car is ready to go up.\n"
# 95 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "Would you like to be on it?$"
# 96 "data/maps/Route112_CableCarStation/scripts.pory"

# 97 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Text_StepThisWay: @ 822ABC2
# 98 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "Please step this way.$"
# 99 "data/maps/Route112_CableCarStation/scripts.pory"

# 100 "data/maps/Route112_CableCarStation/scripts.pory"
Route112_CableCarStation_Text_RideAnotherTime: @ 822ABD8
# 101 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "Please ride with us another time.$"
