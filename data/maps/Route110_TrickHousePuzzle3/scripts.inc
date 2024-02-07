# 1 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_MapScripts:: @ 826BED8
# 3 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle3_OnResume
# 4 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle3_OnTransition
# 5 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.byte 0
# 6 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 7 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_OnResume: @ 826BEE3
# 8 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles
# 9 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_9, 0
# 10 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
# 11 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_9, 1
# 12 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
# 13 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 14 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 15 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_OnTransition: @ 826BEFF
# 16 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_1, 0
# 17 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_2, 0
# 18 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_3, 0
# 19 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_4, 0
# 20 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 0
# 21 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_9, 0
# 22 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 23 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 24 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles:: @ 826BF1E
# 25 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 14, METATILE_TrickHousePuzzle_Button_Up, 0
# 26 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 11, METATILE_TrickHousePuzzle_Button_Up, 0
# 27 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 5, METATILE_TrickHousePuzzle_Button_Up, 0
# 28 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 2, METATILE_TrickHousePuzzle_Button_Up, 0
# 29 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_8, 1
# 30 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_PressedButton1Metatile
# 31 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_8, 2
# 32 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_PressedButton2Metatile
# 33 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_8, 3
# 34 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_PressedButton3Metatile
# 35 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_8, 4
# 36 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_PressedButton4Metatile
# 37 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 38 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 39 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressedButton1Metatile:: @ 826BF6F
# 40 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 14, METATILE_TrickHousePuzzle_Button_Pressed, 0
# 41 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 42 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 43 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressedButton2Metatile:: @ 826BF79
# 44 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 11, METATILE_TrickHousePuzzle_Button_Pressed, 0
# 45 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 46 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 47 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressedButton3Metatile:: @ 826BF83
# 48 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 5, METATILE_TrickHousePuzzle_Button_Pressed, 0
# 49 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 50 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 51 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressedButton4Metatile:: @ 826BF8D
# 52 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 2, METATILE_TrickHousePuzzle_Button_Pressed, 0
# 53 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 54 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 55 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetDoorsState0:: @ 826BF97
# 56 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 6, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
# 57 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 6, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
# 58 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 7, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
# 59 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 7, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
# 60 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
# 61 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
# 62 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
# 63 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
# 64 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
# 65 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
# 66 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
# 67 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
# 68 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
# 69 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 9, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
# 70 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
# 71 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 10, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
# 72 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile0, 0
# 73 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 15, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile1, 0
# 74 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile2, 0
# 75 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 16, METATILE_TrickHousePuzzle_BlueDoorH_Open_Tile3, 0
# 76 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 7, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
# 77 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 8, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
# 78 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 13, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
# 79 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 14, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
# 80 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 6, 4, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
# 81 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 6, 5, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
# 82 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 16, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
# 83 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 17, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
# 84 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 7, METATILE_TrickHousePuzzle_BlueDoorV_Retracted, 1
# 85 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 8, METATILE_TrickHousePuzzle_Floor_ShadowTop, 0
# 86 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 87 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 88 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 89 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 90 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 91 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 92 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 93 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 94 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 95 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 96 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 97 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 98 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 99 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 100 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 101 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 102 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 103 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 104 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 105 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 106 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 7, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 107 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 9, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 108 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 7, 10, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 109 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 10, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 110 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 111 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 6, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 112 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 113 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 7, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 114 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 115 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 12, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 116 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 117 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 13, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 118 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 119 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 18, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 120 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 121 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 19, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 122 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile0, 0
# 123 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 3, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile1, 0
# 124 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile2, 1
# 125 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 4, METATILE_TrickHousePuzzle_RedDoorH_Closed_Tile3, 1
# 126 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 16, METATILE_TrickHousePuzzle_RedDoorV_Open0, 1
# 127 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 17, METATILE_TrickHousePuzzle_RedDoorV_Open1, 1
# 128 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 4, METATILE_TrickHousePuzzle_RedDoorV_Open0, 1
# 129 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 5, METATILE_TrickHousePuzzle_RedDoorV_Open1, 1
# 130 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 131 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 132 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetDoorsState1:: @ 826C232
# 133 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 6, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
# 134 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 6, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
# 135 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 7, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
# 136 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 7, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
# 137 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
# 138 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
# 139 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
# 140 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
# 141 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
# 142 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
# 143 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
# 144 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
# 145 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
# 146 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 9, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
# 147 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
# 148 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 10, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
# 149 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile0, 0
# 150 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 15, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile1, 0
# 151 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile2, 1
# 152 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 16, METATILE_TrickHousePuzzle_BlueDoorH_Closed_Tile3, 1
# 153 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 7, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
# 154 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 8, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
# 155 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 13, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
# 156 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 14, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
# 157 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 6, 4, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
# 158 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 6, 5, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
# 159 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 16, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
# 160 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 17, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
# 161 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 7, METATILE_TrickHousePuzzle_BlueDoorV_Open0, 1
# 162 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 12, 8, METATILE_TrickHousePuzzle_BlueDoorV_Open1, 1
# 163 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 164 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 165 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 166 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 167 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 168 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 169 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 1, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 170 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 2, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 171 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 172 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 173 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 174 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 175 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 176 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 177 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 178 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 179 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 180 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 181 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 4, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 182 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 5, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 183 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 7, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 184 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 9, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 185 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 7, 10, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 186 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 8, 10, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 187 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 188 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 6, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 189 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 190 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 7, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 191 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 192 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 12, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 193 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 194 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 13, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 195 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 196 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 18, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 197 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 10, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 198 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 11, 19, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 199 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile0, 0
# 200 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 3, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile1, 0
# 201 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 13, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile2, 0
# 202 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 14, 4, METATILE_TrickHousePuzzle_RedDoorH_Open_Tile3, 0
# 203 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 16, METATILE_TrickHousePuzzle_RedDoorV_Retracted, 1
# 204 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 3, 17, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, 0
# 205 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 4, METATILE_TrickHousePuzzle_RedDoorV_Retracted, 1
# 206 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setmetatile 9, 5, METATILE_TrickHousePuzzle_Floor_ShadowTop_Alt, 0
# 207 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 208 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 209 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Button1:: @ 826C4CD
# 210 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 211 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 1
# 212 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
# 213 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 214 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 215 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Button2:: @ 826C4D9
# 216 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 217 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 2
# 218 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
# 219 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 220 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 221 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Button3:: @ 826C4E5
# 222 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 223 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 3
# 224 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
# 225 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 226 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 227 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Button4:: @ 826C4F1
# 228 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 229 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_8, 4
# 230 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_PressButton
# 231 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 232 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 233 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_PressButton:: @ 826C4FD
# 234 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call Route110_TrickHousePuzzle3_EventScript_SetButton
# 235 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	playse SE_PIN
# 236 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call Route110_TrickHousePuzzle3_EventScript_UpdateButtonMetatiles
# 237 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle3_EventScript_AlternateDoors
# 238 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 239 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 240 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton:: @ 826C510
# 241 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_1, 0
# 242 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_2, 0
# 243 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_3, 0
# 244 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_4, 0
# 245 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_8, 1
# 246 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetButton1
# 247 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_8, 2
# 248 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetButton2
# 249 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_8, 3
# 250 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetButton3
# 251 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_8, 4
# 252 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetButton4
# 253 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 254 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 255 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton1:: @ 826C551
# 256 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_1, 1
# 257 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 258 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 259 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton2:: @ 826C557
# 260 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_2, 1
# 261 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 262 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 263 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton3:: @ 826C55D
# 264 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_3, 1
# 265 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 266 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 267 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetButton4:: @ 826C563
# 268 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_4, 1
# 269 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	return
# 270 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 271 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_AlternateDoors:: @ 826C569
# 272 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_9, 1
# 273 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetDoorsState0
# 274 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_9, 0
# 275 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle3_EventScript_SetDoorsState1
# 276 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	special DrawWholeMapView
# 277 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_9, 1
# 278 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_ClearAltDoorState
# 279 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TEMP_9, 0
# 280 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_SetAltDoorState
# 281 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 282 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 283 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_ClearAltDoorState:: @ 826C599
# 284 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_9, 0
# 285 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	releaseall
# 286 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 287 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 288 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_SetAltDoorState:: @ 826C5A0
# 289 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TEMP_9, 1
# 290 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	releaseall
# 291 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 292 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 293 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Scroll:: @ 826C5A7
# 294 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	lockall
# 295 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0
# 296 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle3_EventScript_FoundScroll
# 297 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 298 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 299 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 300 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_FoundScroll:: @ 826C5B9
# 301 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 1
# 302 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 303 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 304 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 305 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Justin:: @ 826C5C4
# 306 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	trainerbattle_single TRAINER_JUSTIN, Route110_TrickHousePuzzle3_Text_JustinIntro, Route110_TrickHousePuzzle3_Text_JustinDefeat
# 307 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	msgbox Route110_TrickHousePuzzle3_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
# 308 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 309 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 310 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Martha:: @ 826C5DB
# 311 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	trainerbattle_single TRAINER_MARTHA, Route110_TrickHousePuzzle3_Text_MarthaIntro, Route110_TrickHousePuzzle3_Text_MarthaDefeat
# 312 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	msgbox Route110_TrickHousePuzzle3_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
# 313 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 314 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 315 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Alan:: @ 826C5F2
# 316 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	trainerbattle_single TRAINER_ALAN, Route110_TrickHousePuzzle3_Text_AlanIntro, Route110_TrickHousePuzzle3_Text_AlanDefeat
# 317 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	msgbox Route110_TrickHousePuzzle3_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
# 318 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	end
# 319 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 320 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened: @ 826C609
# 321 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 322 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "on the door.\p"
# 323 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "“Trick Master is coveted.”\n"
# 324 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "… … … … … … … …\p"
# 325 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "The lock clicked open!$"
# 326 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 327 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_JustinIntro: @ 826C676
# 328 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I keep coming back to this same place!$"
# 329 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 330 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_JustinDefeat: @ 826C69D
# 331 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I'm already having trouble, and then\n"
# 332 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "you have to beat me? It's not fair!$"
# 333 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 334 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_JustinPostBattle: @ 826C6E6
# 335 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "It's full of doors here!\n"
# 336 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "It's too small and dark in here! Help!$"
# 337 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 338 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_MarthaIntro: @ 826C726
# 339 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I don't know what's going on here.\n"
# 340 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I'm starting to feel sad…$"
# 341 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 342 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_MarthaDefeat: @ 826C763
# 343 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "You… You're awful!$"
# 344 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 345 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_MarthaPostBattle: @ 826C776
# 346 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I know I'm weak!\n"
# 347 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "And, I have no sense of direction!$"
# 348 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 349 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_AlanIntro: @ 826C7AA
# 350 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I don't get it. What would anyone want\n"
# 351 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "with a house this bizarre?$"
# 352 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 353 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_AlanDefeat: @ 826C7EC
# 354 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I don't get it.\n"
# 355 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "How did I lose?$"
# 356 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"

# 357 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
Route110_TrickHousePuzzle3_Text_AlanPostBattle: @ 826C80C
# 358 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "I don't get it.\n"
# 359 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "How many traps are in this house?\p"
# 360 "data/maps/Route110_TrickHousePuzzle3/scripts.pory"
	.string "You may be the one to solve that.$"
