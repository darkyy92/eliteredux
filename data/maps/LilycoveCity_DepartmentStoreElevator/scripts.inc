# 1 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_MapScripts:: @ 8220623
# 3 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_Attendant:: @ 8220624
# 6 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8004, 0
# 9 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call_if_unset FLAG_TEMP_2, LilycoveCity_DepartmentStoreElevator_EventScript_SetFloor
# 10 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
# 11 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special ShowDeptStoreElevatorFloorSelect
# 12 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	message gText_WhichFloorWouldYouLike
# 13 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	waitmessage
# 14 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8004, 0
# 15 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	specialvar VAR_RESULT, GetDeptStoreDefaultFloorChoice
# 16 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	switch VAR_RESULT
# 17 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 0, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom5th
# 18 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 1, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom4th
# 19 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 2, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom3rd
# 20 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 3, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom2nd
# 21 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 4, LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom1st
# 22 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 23 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 24 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
@ Below scripts ensure the cursor for floor select always starts on the current floor
# 25 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom5th:: @ 8220689
# 26 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 0, FALSE
# 27 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 28 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 29 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 30 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom4th:: @ 8220695
# 31 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 1, FALSE
# 32 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 33 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 34 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 35 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom3rd:: @ 82206A1
# 36 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 2, FALSE
# 37 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 38 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 39 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 40 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom2nd:: @ 82206AD
# 41 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 3, FALSE
# 42 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 43 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 44 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 45 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom1st:: @ 82206B9
# 46 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	multichoicedefault 0, 0, MULTI_FLOORS, 4, FALSE
# 47 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor
# 48 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 49 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 50 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor:: @ 82206C5
# 51 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	switch VAR_RESULT
# 52 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 0, LilycoveCity_DepartmentStoreElevator_EventScript_5thFloor
# 53 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 1, LilycoveCity_DepartmentStoreElevator_EventScript_4thFloor
# 54 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 2, LilycoveCity_DepartmentStoreElevator_EventScript_3rdFloor
# 55 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 3, LilycoveCity_DepartmentStoreElevator_EventScript_2ndFloor
# 56 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 4, LilycoveCity_DepartmentStoreElevator_EventScript_1stFloor
# 57 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case 5, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 58 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 59 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 60 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 61 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_1stFloor:: @ 8220718
# 62 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_1F
# 63 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F, 255, 2, 1
# 64 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
# 65 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 66 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 67 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_1F
# 68 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 69 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 70 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 71 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_2ndFloor:: @ 8220740
# 72 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_2F
# 73 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F, 255, 2, 1
# 74 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
# 75 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 76 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 77 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_2F
# 78 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 79 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 80 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 81 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_3rdFloor:: @ 8220768
# 82 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_3F
# 83 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F, 255, 2, 1
# 84 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
# 85 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 86 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 87 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_3F
# 88 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 89 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 90 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 91 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_4thFloor:: @ 8220790
# 92 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_4F
# 93 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F, 255, 2, 1
# 94 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
# 95 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 96 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 97 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_4F
# 98 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 99 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 100 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 101 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_5thFloor:: @ 82207B8
# 102 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_0x8006, DEPT_STORE_FLOORNUM_5F
# 103 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F, 255, 2, 1
# 104 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	compare VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
# 105 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 106 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator
# 107 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setvar VAR_DEPT_STORE_FLOOR, DEPT_STORE_FLOORNUM_5F
# 108 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	goto LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect
# 109 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 110 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 111 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect:: @ 82207E0
# 112 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special CloseDeptStoreElevatorWindow
# 113 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	release
# 114 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	end
# 115 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 116 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator:: @ 82207E5
# 117 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special CloseDeptStoreElevatorWindow
# 118 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	closemessage
# 119 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 120 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	waitmovement 0
# 121 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	waitse
# 122 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special MoveElevator
# 123 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	waitstate
# 124 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	setflag FLAG_TEMP_2
# 125 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	return
# 126 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"

# 127 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
LilycoveCity_DepartmentStoreElevator_EventScript_SetFloor:: @ 82207FC
# 128 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	special SetDeptStoreFloor
# 129 "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.pory"
	return
