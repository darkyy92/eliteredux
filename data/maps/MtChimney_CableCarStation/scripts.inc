# 1 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 2 "data/maps/MtChimney_CableCarStation/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 4 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_MapScripts:: @ 822ABFA
# 5 "data/maps/MtChimney_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_CableCarStation_OnTransition
# 6 "data/maps/MtChimney_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtChimney_CableCarStation_OnFrame
# 7 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.byte 0
# 8 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 9 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_OnTransition: @ 822AC05
# 10 "data/maps/MtChimney_CableCarStation/scripts.pory"
	compare VAR_CABLE_CAR_STATION_STATE, 1
# 11 "data/maps/MtChimney_CableCarStation/scripts.pory"
	call_if_eq MtChimney_CableCarStation_EventScript_MoveAttendantAside
# 12 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 13 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 14 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_MoveAttendantAside:: @ 822AC11
# 15 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 5, 4
# 16 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_RIGHT
# 17 "data/maps/MtChimney_CableCarStation/scripts.pory"
	return
# 18 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 19 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_OnFrame: @ 822AC1D
# 20 "data/maps/MtChimney_CableCarStation/scripts.pory"
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 1, MtChimney_CableCarStation_EventScript_ExitCableCar
# 21 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.2byte 0
# 22 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 23 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_ExitCableCar:: @ 822AC27
# 24 "data/maps/MtChimney_CableCarStation/scripts.pory"
	lockall
# 25 "data/maps/MtChimney_CableCarStation/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtChimney_CableCarStation_Movement_ExitCableCar
# 26 "data/maps/MtChimney_CableCarStation/scripts.pory"
	applymovement LOCALID_ATTENDANT, MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar
# 27 "data/maps/MtChimney_CableCarStation/scripts.pory"
	waitmovement 0
# 28 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 0
# 29 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 6, 7
# 30 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setobjectmovementtype LOCALID_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
# 31 "data/maps/MtChimney_CableCarStation/scripts.pory"
	releaseall
# 32 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 33 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 34 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_Attendant:: @ 822AC4B
# 35 "data/maps/MtChimney_CableCarStation/scripts.pory"
	lock
# 36 "data/maps/MtChimney_CableCarStation/scripts.pory"
	faceplayer
# 37 "data/maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
# 38 "data/maps/MtChimney_CableCarStation/scripts.pory"
	compare VAR_RESULT, YES
# 39 "data/maps/MtChimney_CableCarStation/scripts.pory"
	goto_if_eq MtChimney_CableCarStation_EventScript_RideCableCar
# 40 "data/maps/MtChimney_CableCarStation/scripts.pory"
	compare VAR_RESULT, NO
# 41 "data/maps/MtChimney_CableCarStation/scripts.pory"
	goto_if_eq MtChimney_CableCarStation_EventScript_DeclineRide
# 42 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 43 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 44 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_RideCableCar:: @ 822AC6C
# 45 "data/maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
# 46 "data/maps/MtChimney_CableCarStation/scripts.pory"
	closemessage
# 47 "data/maps/MtChimney_CableCarStation/scripts.pory"
	applymovement LOCALID_ATTENDANT, MtChimney_CableCarStation_Movement_LeadPlayerToCableCar
# 48 "data/maps/MtChimney_CableCarStation/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MtChimney_CableCarStation_Movement_BoardCableCar
# 49 "data/maps/MtChimney_CableCarStation/scripts.pory"
	waitmovement 0
# 50 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_0x8004, TRUE  @ Going down
# 51 "data/maps/MtChimney_CableCarStation/scripts.pory"
	setvar VAR_CABLE_CAR_STATION_STATE, 2
# 52 "data/maps/MtChimney_CableCarStation/scripts.pory"
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
# 53 "data/maps/MtChimney_CableCarStation/scripts.pory"
	special CableCarWarp
# 54 "data/maps/MtChimney_CableCarStation/scripts.pory"
	special CableCar
# 55 "data/maps/MtChimney_CableCarStation/scripts.pory"
	waitstate
# 56 "data/maps/MtChimney_CableCarStation/scripts.pory"
	release
# 57 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 58 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 59 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_EventScript_DeclineRide:: @ 822AC9B
# 60 "data/maps/MtChimney_CableCarStation/scripts.pory"
	msgbox MtChimney_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
# 61 "data/maps/MtChimney_CableCarStation/scripts.pory"
	release
# 62 "data/maps/MtChimney_CableCarStation/scripts.pory"
	end
# 63 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 64 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_LeadPlayerToCableCar: @ 822ACA5
# 65 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 66 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 67 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_left
# 68 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_in_place_fastest_right
# 69 "data/maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 70 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 71 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_FollowPlayerOutFromCableCar: @ 822ACAA
# 72 "data/maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 73 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_right
# 74 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 75 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 76 "data/maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 77 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 78 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_BoardCableCar: @ 822ACAF
# 79 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 80 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 81 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_up
# 82 "data/maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 83 "data/maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 84 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 85 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Movement_ExitCableCar: @ 822ACB4
# 86 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 87 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 88 "data/maps/MtChimney_CableCarStation/scripts.pory"
	walk_down
# 89 "data/maps/MtChimney_CableCarStation/scripts.pory"
	delay_16
# 90 "data/maps/MtChimney_CableCarStation/scripts.pory"
	step_end
# 91 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 92 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_CableCarReadyGetOn: @ 822ACB9
# 93 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.string "The Cable Car is ready to go down.\n"
# 94 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.string "Would you like to be on it?$"
# 95 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 96 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_StepThisWay: @ 822ACF8
# 97 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.string "Please step this way.$"
# 98 "data/maps/MtChimney_CableCarStation/scripts.pory"

# 99 "data/maps/MtChimney_CableCarStation/scripts.pory"
MtChimney_CableCarStation_Text_RideAnotherTime: @ 822AD0E
# 100 "data/maps/MtChimney_CableCarStation/scripts.pory"
	.string "Please ride with us another time.$"
