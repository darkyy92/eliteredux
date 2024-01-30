# 1 "data/maps/NewMauville_Inside/scripts.pory"

# 2 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_MapScripts:: @ 82373D7
# 3 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
# 4 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
# 5 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Inside_OnLoad
# 6 "data/maps/NewMauville_Inside/scripts.pory"
	.byte 0
# 7 "data/maps/NewMauville_Inside/scripts.pory"

# 8 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnResume: @ 82373E7
# 9 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_TEMP_1, 1
# 10 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_eq NewMauville_Inside_EventScript_SetBarrierStateBlueButton
# 11 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_TEMP_2, 1
# 12 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_eq NewMauville_Inside_EventScript_SetBarrierStateGreenButton
# 13 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveVoltorb
# 14 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 15 "data/maps/NewMauville_Inside/scripts.pory"

# 16 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_TryRemoveVoltorb:: @ Also handles Zapdos
# 17 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 18 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 19 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 20 "data/maps/NewMauville_Inside/scripts.pory"
	removeobject VAR_LAST_TALKED
# 21 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 22 "data/maps/NewMauville_Inside/scripts.pory"

# 23 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnTransition: @ 823741B
# 24 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 0
# 25 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 0
# 26 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb1
# 27 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb2
# 28 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_ELECTRODE_3_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb3
# 29 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 30 "data/maps/NewMauville_Inside/scripts.pory"

# 31 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb1:: @ 8237441
# 32 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_ELECTRODE_1
# 33 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 34 "data/maps/NewMauville_Inside/scripts.pory"

# 35 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb2:: @ 8237445
# 36 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_ELECTRODE_2
# 37 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 38 "data/maps/NewMauville_Inside/scripts.pory"

# 39 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb3:: @ 8237449
# 40 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_ELECTRODE_3
# 41 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 42 "data/maps/NewMauville_Inside/scripts.pory"

# 43 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnLoad: @ 823744D
# 44 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 2
# 45 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_eq NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 46 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 4
# 47 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_eq NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 48 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 6
# 49 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_eq NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 50 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 51 "data/maps/NewMauville_Inside/scripts.pory"

# 52 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_BlueButton:: @ 8237459
# 53 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 54 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 1
# 55 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 0
# 56 "data/maps/NewMauville_Inside/scripts.pory"
	playse SE_PIN
# 57 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
# 58 "data/maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 59 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 60 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 61 "data/maps/NewMauville_Inside/scripts.pory"

# 62 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_GreenButton:: @ 8237471
# 63 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 64 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 0
# 65 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 1
# 66 "data/maps/NewMauville_Inside/scripts.pory"
	playse SE_PIN
# 67 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
# 68 "data/maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 69 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 70 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 71 "data/maps/NewMauville_Inside/scripts.pory"

# 72 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierStateBlueButton:: @ 8237489
# 73 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, 1
# 74 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
# 75 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, 0
# 76 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, 0
# 77 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, 1
# 78 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
# 79 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, 0
# 80 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, 0
# 81 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, 1
# 82 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
# 83 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, 0
# 84 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, 0
# 85 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, 1
# 86 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, 1
# 87 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, 1
# 88 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, 1
# 89 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, 1
# 90 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, 1
# 91 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, 1
# 92 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, 1
# 93 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, 1
# 94 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, 1
# 95 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, 1
# 96 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, 1
# 97 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, 1
# 98 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, 1
# 99 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, 1
# 100 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, 1
# 101 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, 0
# 102 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, 0
# 103 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, 0
# 104 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, 0
# 105 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, 0
# 106 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, 0
# 107 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, 0
# 108 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, 0
# 109 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, 0
# 110 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 111 "data/maps/NewMauville_Inside/scripts.pory"

# 112 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierStateGreenButton:: @ 82375D7
# 113 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, 1
# 114 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, 1
# 115 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
# 116 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, 1
# 117 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, 1
# 118 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, 1
# 119 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
# 120 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, 1
# 121 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, 1
# 122 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, 1
# 123 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
# 124 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, 1
# 125 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, 1
# 126 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
# 127 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, 0
# 128 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, 0
# 129 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, 1
# 130 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
# 131 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, 0
# 132 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, 0
# 133 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, 1
# 134 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
# 135 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, 0
# 136 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, 0
# 137 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, 1
# 138 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
# 139 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, 0
# 140 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, 0
# 141 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, 0
# 142 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, 0
# 143 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, 0
# 144 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, 0
# 145 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, 0
# 146 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, 0
# 147 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, 0
# 148 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, 0
# 149 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, 0
# 150 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 151 "data/maps/NewMauville_Inside/scripts.pory"

# 152 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_RedButton::
# 153 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 154 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
# 155 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 156 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 2
# 157 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 158 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 159 "data/maps/NewMauville_Inside/scripts.pory"

# 160 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Rotom::
# 161 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 162 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_ROTOM, 2
# 163 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 164 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRestarted, MSGBOX_DEFAULT
# 165 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetGeneratorOnMetatiles
# 166 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 3
# 167 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 168 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 169 "data/maps/NewMauville_Inside/scripts.pory"

# 170 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_RedButton2::
# 171 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 172 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
# 173 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 174 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 4
# 175 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 176 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 177 "data/maps/NewMauville_Inside/scripts.pory"

# 178 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Rotom2::
# 179 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 180 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_ROTOM, 2
# 181 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 182 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRestartedAgain, MSGBOX_DEFAULT
# 183 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetGeneratorOnMetatiles
# 184 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 5
# 185 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 186 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 187 "data/maps/NewMauville_Inside/scripts.pory"

# 188 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_RotomEncounter::
# 189 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 190 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 191 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, 0
# 192 "data/maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 193 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_ROTOM, 2
# 194 "data/maps/NewMauville_Inside/scripts.pory"
	delay 40
# 195 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 196 "data/maps/NewMauville_Inside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 197 "data/maps/NewMauville_Inside/scripts.pory"
	waitmovement 0
# 198 "data/maps/NewMauville_Inside/scripts.pory"
	playse SE_PIN
# 199 "data/maps/NewMauville_Inside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 200 "data/maps/NewMauville_Inside/scripts.pory"
	waitmovement 0
# 201 "data/maps/NewMauville_Inside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 202 "data/maps/NewMauville_Inside/scripts.pory"
	waitmovement 0
# 203 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_PokemonCameOut, MSGBOX_DEFAULT
# 204 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 205 "data/maps/NewMauville_Inside/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 206 "data/maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_ROTOM, VAR_0x800A ITEM_NONE
# 207 "data/maps/NewMauville_Inside/scripts.pory"
	waitse
# 208 "data/maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 209 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 210 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 211 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedRotom
# 212 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 213 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_PlayerCaughtRotom
# 214 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 5
# 215 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 216 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 217 "data/maps/NewMauville_Inside/scripts.pory"

# 218 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedRotom::
# 219 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_RotomLeftGenerator, MSGBOX_DEFAULT
# 220 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 221 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 6
# 222 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 223 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 224 "data/maps/NewMauville_Inside/scripts.pory"

# 225 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_PlayerCaughtRotom::
# 226 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorStopped, MSGBOX_DEFAULT
# 227 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 228 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 6
# 229 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 230 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 231 "data/maps/NewMauville_Inside/scripts.pory"

# 232 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetGeneratorOffMetatiles::
# 233 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, 0
# 234 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, 1
# 235 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, 1
# 236 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, 1
# 237 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, 1
# 238 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, 1
# 239 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, 1
# 240 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, 1
# 241 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, 1
# 242 "data/maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 243 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 244 "data/maps/NewMauville_Inside/scripts.pory"

# 245 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetGeneratorOnMetatiles::
# 246 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 6, METATILE_BikeShop_Button_Red, 0
# 247 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 2, METATILE_BikeShop_Generator_On_Tile0, 1
# 248 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 2, METATILE_BikeShop_Generator_On_Tile1, 1
# 249 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 2, METATILE_BikeShop_Generator_On_Tile2, 1
# 250 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 2, METATILE_BikeShop_Generator_On_Tile3, 1
# 251 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 3, METATILE_BikeShop_Generator_On_Tile4, 1
# 252 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 3, METATILE_BikeShop_Generator_On_Tile5, 1
# 253 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 3, METATILE_BikeShop_Generator_On_Tile6, 1
# 254 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 3, METATILE_BikeShop_Generator_On_Tile7, 1
# 255 "data/maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 256 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 257 "data/maps/NewMauville_Inside/scripts.pory"

# 258 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Generator:: @ 823778F
# 259 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 260 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 2
# 261 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_GeneratorOff
# 262 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 4
# 263 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_GeneratorOff
# 264 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 6
# 265 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_GeneratorOff
# 266 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
# 267 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 268 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 269 "data/maps/NewMauville_Inside/scripts.pory"

# 270 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_GeneratorOff:: @ 82377A5
# 271 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
# 272 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 273 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 274 "data/maps/NewMauville_Inside/scripts.pory"

# 275 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Electrode1:: @ 82377AF
# 276 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 277 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 278 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 279 "data/maps/NewMauville_Inside/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 280 "data/maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_ELECTRODE, VAR_0x800A ITEM_NONE
# 281 "data/maps/NewMauville_Inside/scripts.pory"
	waitse
# 282 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_ELECTRODE, 2
# 283 "data/maps/NewMauville_Inside/scripts.pory"
	delay 40
# 284 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 285 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 286 "data/maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 287 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 288 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 289 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 290 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
# 291 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 292 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
# 293 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 294 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
# 295 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_1_NEW_MAUVILLE
# 296 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 297 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 298 "data/maps/NewMauville_Inside/scripts.pory"

# 299 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb1:: @ 82377F3
# 300 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_1_NEW_MAUVILLE
# 301 "data/maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 302 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 303 "data/maps/NewMauville_Inside/scripts.pory"

# 304 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Electrode2:: @ 82377FC
# 305 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 306 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 307 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 308 "data/maps/NewMauville_Inside/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 309 "data/maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_ELECTRODE, VAR_0x800A ITEM_NONE
# 310 "data/maps/NewMauville_Inside/scripts.pory"
	waitse
# 311 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_ELECTRODE, 2
# 312 "data/maps/NewMauville_Inside/scripts.pory"
	delay 40
# 313 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 314 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 315 "data/maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 316 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 317 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 318 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 319 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
# 320 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 321 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
# 322 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 323 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
# 324 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_2_NEW_MAUVILLE
# 325 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 326 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 327 "data/maps/NewMauville_Inside/scripts.pory"

# 328 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb2:: @ 8237840
# 329 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_2_NEW_MAUVILLE
# 330 "data/maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 331 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 332 "data/maps/NewMauville_Inside/scripts.pory"

# 333 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Electrode3:: @ 8237849
# 334 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 335 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 336 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 337 "data/maps/NewMauville_Inside/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 338 "data/maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_ELECTRODE, VAR_0x800A ITEM_NONE
# 339 "data/maps/NewMauville_Inside/scripts.pory"
	waitse
# 340 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_ELECTRODE, 2
# 341 "data/maps/NewMauville_Inside/scripts.pory"
	delay 40
# 342 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 343 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 344 "data/maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 345 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 346 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 347 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 348 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
# 349 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 350 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
# 351 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 352 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
# 353 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_3_NEW_MAUVILLE
# 354 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 355 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 356 "data/maps/NewMauville_Inside/scripts.pory"

# 357 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb3:: @ 823788D
# 358 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ELECTRODE_3_NEW_MAUVILLE
# 359 "data/maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 360 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 361 "data/maps/NewMauville_Inside/scripts.pory"

# 362 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Zapdos::
# 363 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 364 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 365 "data/maps/NewMauville_Inside/scripts.pory"
	waitse
# 366 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_ZAPDOS, 2
# 367 "data/maps/NewMauville_Inside/scripts.pory"
	delay 40
# 368 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 369 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 370 "data/maps/NewMauville_Inside/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 371 "data/maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_ZAPDOS, VAR_0x800A, ITEM_WACAN_BERRY
# 372 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 373 "data/maps/NewMauville_Inside/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 374 "data/maps/NewMauville_Inside/scripts.pory"
	waitstate
# 375 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 376 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 377 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 378 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_DefeatedZapdos
# 379 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 380 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_RanFromZapdos
# 381 "data/maps/NewMauville_Inside/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 382 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq NewMauville_Inside_EventScript_RanFromZapdos
# 383 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 384 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 385 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 386 "data/maps/NewMauville_Inside/scripts.pory"

# 387 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedZapdos:: @ 8238F9F
# 388 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 389 "data/maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 390 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 391 "data/maps/NewMauville_Inside/scripts.pory"

# 392 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_RanFromZapdos:: @ 8238FA8
# 393 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 394 "data/maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 395 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 396 "data/maps/NewMauville_Inside/scripts.pory"

# 397 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorRadiatingHeat: @ 8237896
# 398 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator is radiating heat that\n"
# 399 "data/maps/NewMauville_Inside/scripts.pory"
	.string "can be felt even at a distance.\p"
# 400 "data/maps/NewMauville_Inside/scripts.pory"
	.string "It looks like it should be turned off\n"
# 401 "data/maps/NewMauville_Inside/scripts.pory"
	.string "as soon as possible.$"
# 402 "data/maps/NewMauville_Inside/scripts.pory"

# 403 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorQuietedDown: @ 8237916
# 404 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator quieted down.$"
# 405 "data/maps/NewMauville_Inside/scripts.pory"

# 406 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped: @ 8237932
# 407 "data/maps/NewMauville_Inside/scripts.pory"
	.string "{PLAYER} stepped on the switch.\p"
# 408 "data/maps/NewMauville_Inside/scripts.pory"
	.string "Click…\p"
# 409 "data/maps/NewMauville_Inside/scripts.pory"
	.string "… … … … … … … …\n"
# 410 "data/maps/NewMauville_Inside/scripts.pory"
	.string "… … … … … … … …\p"
# 411 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator appears to have\n"
# 412 "data/maps/NewMauville_Inside/scripts.pory"
	.string "stopped…$"
# 413 "data/maps/NewMauville_Inside/scripts.pory"

# 414 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorRestarted:
# 415 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator restarted!$"
# 416 "data/maps/NewMauville_Inside/scripts.pory"

# 417 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorRestartedAgain:
# 418 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator restarted again!$"
# 419 "data/maps/NewMauville_Inside/scripts.pory"

# 420 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_RotomLeftGenerator:
# 421 "data/maps/NewMauville_Inside/scripts.pory"
	.string "Rotom left the generator and vanished…$"
# 422 "data/maps/NewMauville_Inside/scripts.pory"

# 423 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorStopped:
# 424 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator appears to have\n"
# 425 "data/maps/NewMauville_Inside/scripts.pory"
	.string "stopped…$"
# 426 "data/maps/NewMauville_Inside/scripts.pory"

# 427 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_PokemonCameOut:
# 428 "data/maps/NewMauville_Inside/scripts.pory"
	.string "A Pokémon came out of the generator!$"
