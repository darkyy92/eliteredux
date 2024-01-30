# 1 "data/maps/TrainerHill_Elevator/scripts.pory"

# 2 "data/maps/TrainerHill_Elevator/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/TrainerHill_Elevator/scripts.pory"

# 4 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_MapScripts:: @ 826934F
# 5 "data/maps/TrainerHill_Elevator/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Elevator_OnFrame
# 6 "data/maps/TrainerHill_Elevator/scripts.pory"
	.byte 0
# 7 "data/maps/TrainerHill_Elevator/scripts.pory"

# 8 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_OnFrame: @ 8269355
# 9 "data/maps/TrainerHill_Elevator/scripts.pory"
	map_script_2 VAR_TEMP_4, 0, TrainerHill_Elevator_EventScript_EnterElevator
# 10 "data/maps/TrainerHill_Elevator/scripts.pory"
	.2byte 0
# 11 "data/maps/TrainerHill_Elevator/scripts.pory"

# 12 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_Attendant:: @ 826935F
# 13 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 14 "data/maps/TrainerHill_Elevator/scripts.pory"

# 15 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_ExitToRoof:: @ 8269360
# 16 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof
# 17 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 18 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 19 "data/maps/TrainerHill_Elevator/scripts.pory"
	warp MAP_TRAINER_HILL_ROOF, 255, 15, 5
# 20 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 21 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 22 "data/maps/TrainerHill_Elevator/scripts.pory"

# 23 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_EnterElevator:: @ 8269375
# 24 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerApproachAttendant
# 25 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 26 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFacePlayer
# 27 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 28 "data/maps/TrainerHill_Elevator/scripts.pory"
	lockall
# 29 "data/maps/TrainerHill_Elevator/scripts.pory"
	msgbox TrainerHill_Elevator_Text_ReturnToReception, MSGBOX_YESNO
# 30 "data/maps/TrainerHill_Elevator/scripts.pory"
	compare VAR_RESULT, NO
# 31 "data/maps/TrainerHill_Elevator/scripts.pory"
	goto_if_eq TrainerHill_Elevator_EventScript_ExitToRoof
# 32 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 33 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement LOCALID_ATTENDANT, TrainerHill_Elevator_Movement_AttendantFaceDown
# 34 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 35 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator
# 36 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 37 "data/maps/TrainerHill_Elevator/scripts.pory"
	call TrainerHill_Elevator_EventScript_MoveElevator
# 38 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay 25
# 39 "data/maps/TrainerHill_Elevator/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Elevator_Movement_PlayerExitElevator
# 40 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitmovement 0
# 41 "data/maps/TrainerHill_Elevator/scripts.pory"
	warp MAP_TRAINER_HILL_ENTRANCE, 255, 17, 8
# 42 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 43 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 44 "data/maps/TrainerHill_Elevator/scripts.pory"

# 45 "data/maps/TrainerHill_Elevator/scripts.pory"
@ Unused
# 46 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_ExitFloorSelect:: @ 82693CE
# 47 "data/maps/TrainerHill_Elevator/scripts.pory"
	goto TrainerHill_Elevator_EventScript_CloseFloorSelect
# 48 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 49 "data/maps/TrainerHill_Elevator/scripts.pory"

# 50 "data/maps/TrainerHill_Elevator/scripts.pory"
@ Functionally unused
# 51 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_CloseFloorSelect:: @ 82693D4
# 52 "data/maps/TrainerHill_Elevator/scripts.pory"
	special CloseDeptStoreElevatorWindow
# 53 "data/maps/TrainerHill_Elevator/scripts.pory"
	releaseall
# 54 "data/maps/TrainerHill_Elevator/scripts.pory"
	end
# 55 "data/maps/TrainerHill_Elevator/scripts.pory"

# 56 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_EventScript_MoveElevator:: @ 82693D9
# 57 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitse
# 58 "data/maps/TrainerHill_Elevator/scripts.pory"
	special MoveElevator
# 59 "data/maps/TrainerHill_Elevator/scripts.pory"
	waitstate
# 60 "data/maps/TrainerHill_Elevator/scripts.pory"
	return
# 61 "data/maps/TrainerHill_Elevator/scripts.pory"

# 62 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerMoveToCenterOfElevator: @ 82693DF
# 63 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_up
# 64 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_up
# 65 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_right
# 66 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 67 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 68 "data/maps/TrainerHill_Elevator/scripts.pory"

# 69 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerApproachAttendant: @ 82693E4
# 70 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 71 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_left
# 72 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 73 "data/maps/TrainerHill_Elevator/scripts.pory"

# 74 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerExitElevator: @ 82693E7
# 75 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 76 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_down
# 77 "data/maps/TrainerHill_Elevator/scripts.pory"
	walk_down
# 78 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 79 "data/maps/TrainerHill_Elevator/scripts.pory"

# 80 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_PlayerExitElevatorToRoof: @ 82693EB
# 81 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 82 "data/maps/TrainerHill_Elevator/scripts.pory"
	delay_16
# 83 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 84 "data/maps/TrainerHill_Elevator/scripts.pory"

# 85 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_AttendantFacePlayer: @ 82693EE
# 86 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_right
# 87 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
# 88 "data/maps/TrainerHill_Elevator/scripts.pory"

# 89 "data/maps/TrainerHill_Elevator/scripts.pory"
TrainerHill_Elevator_Movement_AttendantFaceDown: @ 82693F0
# 90 "data/maps/TrainerHill_Elevator/scripts.pory"
	face_down
# 91 "data/maps/TrainerHill_Elevator/scripts.pory"
	step_end
