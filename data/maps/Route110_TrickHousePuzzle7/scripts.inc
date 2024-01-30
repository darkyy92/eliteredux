# 1 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_MapScripts:: @ 826E091
# 3 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle7_OnResume
# 4 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle7_OnTransition
# 5 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle7_OnLoad
# 6 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHousePuzzle7_OnFrame
# 7 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.byte 0
# 8 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 9 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
@ Puzzle Room 7 in RSE uses whatever puzzle Mossdeep Gym uses
# 10 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
@ Because Mossdeep Gym was redesigned for Emerald, theres a good deal of leftover script from the old R/S puzzle
# 11 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 12 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_OnResume: @ 826E0A6
# 13 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles
# 14 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 15 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 16 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles:: @ 826E0AC
# 17 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn
# 18 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn
# 19 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn
# 20 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn
# 21 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn
# 22 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 23 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 24 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
@ Leftover from R/S, none of the below metatile scripts are ever called
# 25 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn:: @ 826E0DA
# 26 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 13, 17, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, 0
# 27 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 12, 16, METATILE_TrickHousePuzzle_Lever_On, 1
# 28 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 29 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 30 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn:: @ 826E0ED
# 31 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 12, 13, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, 0
# 32 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 12, 11, METATILE_TrickHousePuzzle_Lever_On, 1
# 33 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 34 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 35 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn:: @ 826E100
# 36 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 7, 12, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Up, 0
# 37 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Lever_On, 1
# 38 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 39 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 40 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn:: @ 826E113
# 41 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 6, 6, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Right_Alt, 0
# 42 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 4, 4, METATILE_TrickHousePuzzle_Lever_On, 1
# 43 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 44 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 45 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn:: @ 826E126
# 46 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 8, 4, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left, 0
# 47 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 7, 5, METATILE_TrickHousePuzzle_Lever_On, 1
# 48 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 49 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 50 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOff:: @ 826E139
# 51 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 13, 17, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Down, 0
# 52 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 12, 16, METATILE_TrickHousePuzzle_Lever_Off, 1
# 53 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 54 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 55 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOff:: @ 826E14C
# 56 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 12, 13, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left, 0
# 57 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 12, 11, METATILE_TrickHousePuzzle_Lever_Off, 1
# 58 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 59 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 60 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOff:: @ 826E15F
# 61 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 7, 12, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Down, 0
# 62 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 5, 10, METATILE_TrickHousePuzzle_Lever_Off, 1
# 63 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 64 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 65 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOff:: @ 826E172
# 66 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 6, 6, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Left_Alt, 0
# 67 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 4, 4, METATILE_TrickHousePuzzle_Lever_Off, 1
# 68 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 69 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 70 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOff:: @ 826E185
# 71 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 8, 4, METATILE_TrickHousePuzzle_Arrow_RedOnBlack_Right, 0
# 72 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setmetatile 7, 5, METATILE_TrickHousePuzzle_Lever_Off, 1
# 73 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	return
# 74 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 75 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_OnTransition: @ 826E198
# 76 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
# 77 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle7_EventScript_TeleportedTransition
# 78 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
# 79 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
# 80 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
# 81 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
# 82 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
# 83 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 84 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 85 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_TeleportedTransition:: @ 826E1B3
# 86 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 87 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 88 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_OnLoad: @ 826E1B4
# 89 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
# 90 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle7_EventScript_UpdateSwitchMetatiles
# 91 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 92 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 93 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_OnFrame: @ 826E1C0
# 94 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1, Route110_TrickHousePuzzle7_EventScript_ClearState2
# 95 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.2byte 0
# 96 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 97 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_ClearState2:: @ 826E1CA
# 98 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 0
# 99 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 100 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 101 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Scroll:: @ 826E1D0
# 102 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	lockall
# 103 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0
# 104 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle7_EventScript_FoundScroll
# 105 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 106 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 107 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 108 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_FoundScroll:: @ 826E1E2
# 109 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 1
# 110 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 111 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 112 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 113 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
@ Unused, leftover from R/S
# 114 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_TeleportPad:: @ 826E1ED
# 115 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	lockall
# 116 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE_2, 1
# 117 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	warpteleport MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 255, 3, 19
# 118 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitstate
# 119 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 120 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 121 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 122 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
@ All the below switch scripts are unused leftover from R/S
# 123 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Switch1:: @ 826E1FE
# 124 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	lockall
# 125 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	delay 32
# 126 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOn
# 127 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1MetatilesOff
# 128 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	special DrawWholeMapView
# 129 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_CLICK
# 130 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1On
# 131 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1, Route110_TrickHousePuzzle7_EventScript_SetSwitch1Off
# 132 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 133 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 134 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Switch2:: @ 826E22D
# 135 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	lockall
# 136 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	delay 32
# 137 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOn
# 138 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2MetatilesOff
# 139 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	special DrawWholeMapView
# 140 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_CLICK
# 141 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2On
# 142 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2, Route110_TrickHousePuzzle7_EventScript_SetSwitch2Off
# 143 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 144 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 145 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Switch3:: @ 826E25C
# 146 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	lockall
# 147 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	delay 32
# 148 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOn
# 149 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3MetatilesOff
# 150 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	special DrawWholeMapView
# 151 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_CLICK
# 152 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3On
# 153 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3, Route110_TrickHousePuzzle7_EventScript_SetSwitch3Off
# 154 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 155 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 156 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Switch4:: @ 826E28B
# 157 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	lockall
# 158 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	delay 32
# 159 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOn
# 160 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4MetatilesOff
# 161 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	special DrawWholeMapView
# 162 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_CLICK
# 163 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4On
# 164 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4, Route110_TrickHousePuzzle7_EventScript_SetSwitch4Off
# 165 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 166 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 167 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Switch5:: @ 826E2BA
# 168 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	lockall
# 169 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	delay 32
# 170 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOn
# 171 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	call_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5MetatilesOff
# 172 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	special DrawWholeMapView
# 173 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_CLICK
# 174 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_unset FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5On
# 175 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	goto_if_set FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5, Route110_TrickHousePuzzle7_EventScript_SetSwitch5Off
# 176 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 177 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 178 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
@ All the below switch scripts are unused leftover from R/S
# 179 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch1On:: @ 826E2E9
# 180 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
# 181 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 182 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 183 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 184 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch1Off:: @ 826E2EE
# 185 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1
# 186 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 187 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 188 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 189 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch2On:: @ 826E2F3
# 190 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
# 191 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 192 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 193 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 194 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch2Off:: @ 826E2F8
# 195 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2
# 196 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 197 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 198 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 199 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch3On:: @ 826E2FD
# 200 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
# 201 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 202 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 203 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 204 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch3Off:: @ 826E302
# 205 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3
# 206 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 207 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 208 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 209 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch4On:: @ 826E307
# 210 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
# 211 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 212 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 213 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 214 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch4Off:: @ 826E30C
# 215 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4
# 216 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 217 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 218 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 219 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch5On:: @ 826E311
# 220 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	setflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
# 221 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 222 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 223 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 224 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_SetSwitch5Off:: @ 826E316
# 225 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	clearflag FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5
# 226 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	releaseall
# 227 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 228 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 229 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
@ From here is where the new, actually used puzzle scripts begin
# 230 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_YellowButton:: @ 826E31B
# 231 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_SWITCH
# 232 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitse
# 233 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_REPEL
# 234 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	initrotatingtilepuzzle TRUE
# 235 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	moverotatingtileobjects 0
# 236 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 237 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	turnrotatingtileobjects
# 238 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 239 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	freerotatingtilepuzzle
# 240 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 241 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 242 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_BlueButton:: @ 826E331
# 243 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_SWITCH
# 244 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitse
# 245 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_REPEL
# 246 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	initrotatingtilepuzzle TRUE
# 247 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	moverotatingtileobjects 1
# 248 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 249 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	turnrotatingtileobjects
# 250 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 251 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	freerotatingtilepuzzle
# 252 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 253 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 254 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_GreenButton:: @ 826E347
# 255 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_SWITCH
# 256 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitse
# 257 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_REPEL
# 258 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	initrotatingtilepuzzle TRUE
# 259 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	moverotatingtileobjects 2
# 260 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 261 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	turnrotatingtileobjects
# 262 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 263 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	freerotatingtilepuzzle
# 264 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 265 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 266 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_PurpleButton:: @ 826E35D
# 267 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_SWITCH
# 268 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitse
# 269 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_REPEL
# 270 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	initrotatingtilepuzzle TRUE
# 271 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	moverotatingtileobjects 3
# 272 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 273 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	turnrotatingtileobjects
# 274 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 275 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	freerotatingtilepuzzle
# 276 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 277 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 278 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
@ Unused
# 279 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_RedButton:: @ 826E373
# 280 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_SWITCH
# 281 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitse
# 282 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	playse SE_REPEL
# 283 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	initrotatingtilepuzzle TRUE
# 284 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	moverotatingtileobjects 4
# 285 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 286 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	turnrotatingtileobjects
# 287 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	waitmovement 0
# 288 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	freerotatingtilepuzzle
# 289 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 290 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 291 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Joshua:: @ 826E389
# 292 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	trainerbattle_single TRAINER_JOSHUA, Route110_TrickHousePuzzle7_Text_JoshuaIntro, Route110_TrickHousePuzzle7_Text_JoshuaDefeat
# 293 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	msgbox Route110_TrickHousePuzzle7_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
# 294 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 295 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 296 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Patricia:: @ 826E3A0
# 297 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	trainerbattle_single TRAINER_PATRICIA, Route110_TrickHousePuzzle7_Text_PatriciaIntro, Route110_TrickHousePuzzle7_Text_PatriciaDefeat
# 298 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	msgbox Route110_TrickHousePuzzle7_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
# 299 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 300 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 301 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Alexis:: @ 826E3B7
# 302 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	trainerbattle_single TRAINER_ALEXIS, Route110_TrickHousePuzzle7_Text_AlexisIntro, Route110_TrickHousePuzzle7_Text_AlexisDefeat
# 303 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	msgbox Route110_TrickHousePuzzle7_Text_AlexisPostBattle, MSGBOX_AUTOCLOSE
# 304 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 305 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 306 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Mariela:: @ 826E3CE
# 307 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	trainerbattle_single TRAINER_MARIELA, Route110_TrickHousePuzzle7_Text_MarielaIntro, Route110_TrickHousePuzzle7_Text_MarielaDefeat
# 308 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	msgbox Route110_TrickHousePuzzle7_Text_MarielaPostBattle, MSGBOX_AUTOCLOSE
# 309 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 310 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 311 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Alvaro:: @ 826E3E5
# 312 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	trainerbattle_single TRAINER_ALVARO, Route110_TrickHousePuzzle7_Text_AlvaroIntro, Route110_TrickHousePuzzle7_Text_AlvaroDefeat
# 313 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	msgbox Route110_TrickHousePuzzle7_Text_AlvaroPostBattle, MSGBOX_AUTOCLOSE
# 314 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 315 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 316 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Everett:: @ 826E3FC
# 317 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	trainerbattle_single TRAINER_EVERETT, Route110_TrickHousePuzzle7_Text_EverettIntro, Route110_TrickHousePuzzle7_Text_EverettDefeat
# 318 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	msgbox Route110_TrickHousePuzzle7_Text_EverettPostBattle, MSGBOX_AUTOCLOSE
# 319 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	end
# 320 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 321 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_WroteSecretCodeLockOpened:: @ 826E413
# 322 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 323 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "on the door.\p"
# 324 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "“Trick Master is huggable.”\n"
# 325 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "… … … … … … … …\p"
# 326 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "The lock clicked open!$"
# 327 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 328 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_JoshuaIntro: @ 826E481
# 329 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "The Trick Master always vanishes\n"
# 330 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "like smoke. How does he do it?$"
# 331 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 332 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_JoshuaDefeat: @ 826E4C1
# 333 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Aiyeeeh! You're much too strong!\n"
# 334 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "How do you do it?$"
# 335 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 336 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_JoshuaPostBattle: @ 826E4F4
# 337 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "I wish I could appear and disappear as\n"
# 338 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "if I were smoke, too.$"
# 339 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 340 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_PatriciaIntro: @ 826E531
# 341 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Going around the same spot…\n"
# 342 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "It begets ill fortune…$"
# 343 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 344 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_PatriciaDefeat: @ 826E564
# 345 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Defeated!\n"
# 346 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "It's a bad sign…$"
# 347 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 348 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_PatriciaPostBattle: @ 826E57F
# 349 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "I've circled the same spot over ten\n"
# 350 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "times now… It's ill fortune…$"
# 351 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 352 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_AlexisIntro: @ 826E5C0
# 353 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Whoever wins will get through here\n"
# 354 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "first. That's the feeling I get.$"
# 355 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 356 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_AlexisDefeat: @ 826E604
# 357 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Oh!\n"
# 358 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Well, go ahead, then!$"
# 359 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 360 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_AlexisPostBattle: @ 826E61E
# 361 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "You're solving all the puzzles in the\n"
# 362 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Trick House. That's the feeling I get.$"
# 363 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 364 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_MarielaIntro: @ 826E66B
# 365 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Nufufufu, here at last!\n"
# 366 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Let's get right with it!$"
# 367 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 368 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_MarielaDefeat: @ 826E69C
# 369 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "You're so casual about winning!$"
# 370 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 371 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_MarielaPostBattle: @ 826E6BC
# 372 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Humph! I'm not upset!\n"
# 373 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Not me!$"
# 374 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 375 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_AlvaroIntro: @ 826E6DA
# 376 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "I ever so closely watched you coming!$"
# 377 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 378 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_AlvaroDefeat: @ 826E700
# 379 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "This outcome I didn't see coming…$"
# 380 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 381 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_AlvaroPostBattle: @ 826E722
# 382 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Well, anyway, we both picked a weird\n"
# 383 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "place to get acquainted.\p"
# 384 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "As one weirdo to another,\n"
# 385 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "let's do our best!$"
# 386 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 387 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_EverettIntro: @ 826E78D
# 388 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "It's awfully cramped in here…$"
# 389 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 390 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_EverettDefeat: @ 826E7AB
# 391 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "Oh, yes, strong you are.$"
# 392 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"

# 393 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
Route110_TrickHousePuzzle7_Text_EverettPostBattle: @ 826E7C4
# 394 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "I was hoping to switch places with you\n"
# 395 "data/maps/Route110_TrickHousePuzzle7/scripts.pory"
	.string "when I beat you, but…$"
