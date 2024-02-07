# 1 "data/maps/MauvilleCity_Gym/scripts.pory"

# 2 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_MapScripts:: @ 820DD6E
# 3 "data/maps/MauvilleCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
# 4 "data/maps/MauvilleCity_Gym/scripts.pory"
	.byte 0
# 5 "data/maps/MauvilleCity_Gym/scripts.pory"

# 6 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_OnLoad: @ 820DD74
# 7 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
# 8 "data/maps/MauvilleCity_Gym/scripts.pory"
	switch VAR_MAUVILLE_GYM_STATE
# 9 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
# 10 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
# 11 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
# 12 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
# 13 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
# 14 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 15 "data/maps/MauvilleCity_Gym/scripts.pory"

# 16 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_UpdateBarriers:: @ 820DDBA
# 17 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
# 18 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 19 "data/maps/MauvilleCity_Gym/scripts.pory"

# 20 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetAltBarriers:: @ 820DDC4
# 21 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, 1
# 22 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, 1
# 23 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, 1
# 24 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, 0
# 25 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, 0
# 26 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, 1
# 27 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, 1
# 28 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, 0
# 29 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, 0
# 30 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, 1
# 31 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, 1
# 32 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, 0
# 33 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, 0
# 34 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, 0
# 35 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, 0
# 36 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, 0
# 37 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, 0
# 38 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, 0
# 39 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, 0
# 40 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, 1
# 41 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, 0
# 42 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, 0
# 43 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, 0
# 44 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, 0
# 45 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, 0
# 46 "data/maps/MauvilleCity_Gym/scripts.pory"
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, 0
# 47 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 48 "data/maps/MauvilleCity_Gym/scripts.pory"

# 49 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch1Pressed:: @ 820DEAF
# 50 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 0
# 51 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 52 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 53 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 54 "data/maps/MauvilleCity_Gym/scripts.pory"

# 55 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch2Pressed:: @ 820DEBD
# 56 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 57 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 58 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 59 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 60 "data/maps/MauvilleCity_Gym/scripts.pory"

# 61 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch3Pressed:: @ 820DECB
# 62 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 63 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 64 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 65 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 66 "data/maps/MauvilleCity_Gym/scripts.pory"

# 67 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch4Pressed:: @ 820DED9
# 68 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 69 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 70 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
# 71 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 72 "data/maps/MauvilleCity_Gym/scripts.pory"

# 73 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_DeactivatePuzzle:: @ 820DEE7
# 74 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymDeactivatePuzzle
# 75 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 76 "data/maps/MauvilleCity_Gym/scripts.pory"

# 77 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Wattson:: @ 820DEEB
# 78 "data/maps/MauvilleCity_Gym/scripts.pory"
	call MauvilleCity_Gym_EventScript_CheckTrainers
# 79 "data/maps/MauvilleCity_Gym/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_WATTSON, MauvilleCity_Gym_EventScript_AlreadyRematched
# 80 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MauvilleCity_Gym_EventScript_WattsonRematch
# 81 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
# 82 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM72, MauvilleCity_Gym_EventScript_GiveVoltSwitch
# 83 "data/maps/MauvilleCity_Gym/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 6
# 84 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq MauvilleCity_Gym_EventScript_CompletedNewMauville
# 85 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
# 86 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 87 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 88 "data/maps/MauvilleCity_Gym/scripts.pory"

# 89 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonDefeated:: @ 820DF2B
# 90 "data/maps/MauvilleCity_Gym/scripts.pory"
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
# 91 "data/maps/MauvilleCity_Gym/scripts.pory"
	waitmessage
# 92 "data/maps/MauvilleCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 93 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
# 94 "data/maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 95 "data/maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 96 "data/maps/MauvilleCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 97 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_RegisteredRaichu, MSGBOX_DEFAULT
# 98 "data/maps/MauvilleCity_Gym/scripts.pory"
	waitfanfare
# 99 "data/maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 100 "data/maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 101 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
# 102 "data/maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
# 103 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 104 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_BADGE03_GET
# 105 "data/maps/MauvilleCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 106 "data/maps/MauvilleCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 6
# 107 "data/maps/MauvilleCity_Gym/scripts.pory"
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
# 108 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 109 "data/maps/MauvilleCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 110 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymDeactivatePuzzle
# 111 "data/maps/MauvilleCity_Gym/scripts.pory"
	special DrawWholeMapView
# 112 "data/maps/MauvilleCity_Gym/scripts.pory"
	playse SE_UNLOCK
# 113 "data/maps/MauvilleCity_Gym/scripts.pory"
	call MauvilleCity_Gym_EventScript_GiveVoltSwitch
# 114 "data/maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 115 "data/maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 116 "data/maps/MauvilleCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 117 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
# 118 "data/maps/MauvilleCity_Gym/scripts.pory"
	waitfanfare
# 119 "data/maps/MauvilleCity_Gym/scripts.pory"
	closemessage
# 120 "data/maps/MauvilleCity_Gym/scripts.pory"
	delay 30
# 121 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
# 122 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 123 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 124 "data/maps/MauvilleCity_Gym/scripts.pory"

# 125 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_CompletedNewMauville:: @ 820DFD4
# 126 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
# 127 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 128 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 129 "data/maps/MauvilleCity_Gym/scripts.pory"

# 130 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonRematch::
# 131 "data/maps/MauvilleCity_Gym/scripts.pory"
	message MauvilleCity_Gym_Text_WattsonChooseFormat
# 132 "data/maps/MauvilleCity_Gym/scripts.pory"
	waitmessage
# 133 "data/maps/MauvilleCity_Gym/scripts.pory"
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
# 134 "data/maps/MauvilleCity_Gym/scripts.pory"
	switch VAR_RESULT
# 135 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 0, MauvilleCity_Gym_EventScript_SetSingles
# 136 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 1, MauvilleCity_Gym_EventScript_SetDoubles
# 137 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 2, MauvilleCity_Gym_EventScript_Exit
# 138 "data/maps/MauvilleCity_Gym/scripts.pory"
	case 127, MauvilleCity_Gym_EventScript_Exit
# 139 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 140 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 141 "data/maps/MauvilleCity_Gym/scripts.pory"

# 142 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetSingles::
# 143 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonAllowLegends, MSGBOX_YESNO
# 144 "data/maps/MauvilleCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 145 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq MauvilleCity_Gym_EventScript_WattsonSinglesRematch
# 146 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_3, MauvilleCity_Gym_Text_WattsonRematchDefeat
# 147 "data/maps/MauvilleCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_WATTSON
# 148 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 149 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 150 "data/maps/MauvilleCity_Gym/scripts.pory"

# 151 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetDoubles::
# 152 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonAllowLegends, MSGBOX_YESNO
# 153 "data/maps/MauvilleCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 154 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq MauvilleCity_Gym_EventScript_WattsonDoublesRematch
# 155 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_5, MauvilleCity_Gym_Text_WattsonRematchDefeat
# 156 "data/maps/MauvilleCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_WATTSON
# 157 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 158 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 159 "data/maps/MauvilleCity_Gym/scripts.pory"

# 160 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonSinglesRematch::
# 161 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_2, MauvilleCity_Gym_Text_WattsonRematchDefeat
# 162 "data/maps/MauvilleCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_WATTSON
# 163 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 164 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 165 "data/maps/MauvilleCity_Gym/scripts.pory"

# 166 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_WattsonDoublesRematch::
# 167 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_4, MauvilleCity_Gym_Text_WattsonRematchDefeat
# 168 "data/maps/MauvilleCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_WATTSON
# 169 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 170 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 171 "data/maps/MauvilleCity_Gym/scripts.pory"

# 172 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_AlreadyRematched::
# 173 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
# 174 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 175 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 176 "data/maps/MauvilleCity_Gym/scripts.pory"

# 177 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Exit::
# 178 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 179 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 180 "data/maps/MauvilleCity_Gym/scripts.pory"

# 181 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch1:: @ 820DFF9
# 182 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 183 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 184 "data/maps/MauvilleCity_Gym/scripts.pory"
	compare VAR_MAUVILLE_GYM_STATE, 1
# 185 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq MauvilleCity_Gym_EventScript_SwitchDoNothing
# 186 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 1
# 187 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 0
# 188 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 189 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 190 "data/maps/MauvilleCity_Gym/scripts.pory"

# 191 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch2:: @ 820E01E
# 192 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 193 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 194 "data/maps/MauvilleCity_Gym/scripts.pory"
	compare VAR_MAUVILLE_GYM_STATE, 2
# 195 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq MauvilleCity_Gym_EventScript_SwitchDoNothing
# 196 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 2
# 197 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 198 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 199 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 200 "data/maps/MauvilleCity_Gym/scripts.pory"

# 201 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch3:: @ 820E043
# 202 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 203 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 204 "data/maps/MauvilleCity_Gym/scripts.pory"
	compare VAR_MAUVILLE_GYM_STATE, 3
# 205 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq MauvilleCity_Gym_EventScript_SwitchDoNothing
# 206 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 3
# 207 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 208 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 209 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 210 "data/maps/MauvilleCity_Gym/scripts.pory"

# 211 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Switch4:: @ 820E068
# 212 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 213 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
# 214 "data/maps/MauvilleCity_Gym/scripts.pory"
	compare VAR_MAUVILLE_GYM_STATE, 4
# 215 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_eq MauvilleCity_Gym_EventScript_SwitchDoNothing
# 216 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 4
# 217 "data/maps/MauvilleCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 218 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
# 219 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 220 "data/maps/MauvilleCity_Gym/scripts.pory"

# 221 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_PressFloorSwitch:: @ 820E08D
# 222 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymSetDefaultBarriers
# 223 "data/maps/MauvilleCity_Gym/scripts.pory"
	special MauvilleGymPressSwitch
# 224 "data/maps/MauvilleCity_Gym/scripts.pory"
	special DrawWholeMapView
# 225 "data/maps/MauvilleCity_Gym/scripts.pory"
	playse SE_UNLOCK
# 226 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
# 227 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
# 228 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 229 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 230 "data/maps/MauvilleCity_Gym/scripts.pory"

# 231 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SwitchDoNothing:: @ 820E0AD
# 232 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 233 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 234 "data/maps/MauvilleCity_Gym/scripts.pory"

# 235 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_SetBarriersAltState:: @ 820E0AF
# 236 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 237 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 238 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 239 "data/maps/MauvilleCity_Gym/scripts.pory"

# 240 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_ClearBarriersAltState:: @ 820E0B4
# 241 "data/maps/MauvilleCity_Gym/scripts.pory"
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 242 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 243 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 244 "data/maps/MauvilleCity_Gym/scripts.pory"

# 245 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Kirk:: @ 820E0B9
# 246 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
# 247 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
# 248 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 249 "data/maps/MauvilleCity_Gym/scripts.pory"

# 250 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Shawn:: @ 820E0D0
# 251 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
# 252 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
# 253 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 254 "data/maps/MauvilleCity_Gym/scripts.pory"

# 255 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Ben:: @ 820E0E7
# 256 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
# 257 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
# 258 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 259 "data/maps/MauvilleCity_Gym/scripts.pory"

# 260 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Vivian:: @ 820E0FE
# 261 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
# 262 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
# 263 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 264 "data/maps/MauvilleCity_Gym/scripts.pory"

# 265 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_Angelo:: @ 820E115
# 266 "data/maps/MauvilleCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
# 267 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
# 268 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 269 "data/maps/MauvilleCity_Gym/scripts.pory"

# 270 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymGuide::
# 271 "data/maps/MauvilleCity_Gym/scripts.pory"
	lock
# 272 "data/maps/MauvilleCity_Gym/scripts.pory"
	faceplayer
# 273 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
# 274 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 275 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice2, MSGBOX_DEFAULT
# 276 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 277 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 278 "data/maps/MauvilleCity_Gym/scripts.pory"

# 279 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymGuidePostVictory::
# 280 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 281 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 282 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 283 "data/maps/MauvilleCity_Gym/scripts.pory"

# 284 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_GymGuide_2::
# 285 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice2, MSGBOX_DEFAULT
# 286 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
# 287 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 288 "data/maps/MauvilleCity_Gym/scripts.pory"

# 289 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_LeftGymStatue:: @ 820E14B
# 290 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 291 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
# 292 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_GymStatue
# 293 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 294 "data/maps/MauvilleCity_Gym/scripts.pory"

# 295 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_RightGymStatue:: @ 820E15B
# 296 "data/maps/MauvilleCity_Gym/scripts.pory"
	lockall
# 297 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
# 298 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto MauvilleCity_Gym_EventScript_GymStatue
# 299 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 300 "data/maps/MauvilleCity_Gym/scripts.pory"

# 301 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymStatueCertified:: @ 820E16B
# 302 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 303 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 304 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 305 "data/maps/MauvilleCity_Gym/scripts.pory"

# 306 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_EventScript_GymStatue:: @ 820E175
# 307 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 308 "data/maps/MauvilleCity_Gym/scripts.pory"
	releaseall
# 309 "data/maps/MauvilleCity_Gym/scripts.pory"
	end
# 310 "data/maps/MauvilleCity_Gym/scripts.pory"

# 311 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuideAdvice2:
# 312 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson, the Leader of Mauville\n"
# 313 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Gym, uses Electric-type Pokémon.\p"
# 314 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "He's prepared for Ground and Grass-Type\n"
# 315 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Pokémon, so you should have a backup\l"
# 316 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "plan if you want to beat him!\p"
# 317 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "And, he's put in switch-controlled\n"
# 318 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "doors all over his Gym! Eccentric!\p"
# 319 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Hey, go for it!$"
# 320 "data/maps/MauvilleCity_Gym/scripts.pory"

# 321 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuideAdvice:
# 322 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Hey, how's it going, Champion-\n"
# 323 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "bound {PLAYER}?$"
# 324 "data/maps/MauvilleCity_Gym/scripts.pory"

# 325 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymGuidePostVictory: @ 820E283
# 326 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Whoa, you're electrifying!\n"
# 327 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You've powered the door open!$"
# 328 "data/maps/MauvilleCity_Gym/scripts.pory"

# 329 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkIntro: @ 820E2BC
# 330 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "My electric soul, it'll shatter your\n"
# 331 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "dreams whole, whoa-yeahah!$"
# 332 "data/maps/MauvilleCity_Gym/scripts.pory"

# 333 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkDefeat: @ 820E2FC
# 334 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "That was plugged in, amped up,\n"
# 335 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "over-driven electric, man!$"
# 336 "data/maps/MauvilleCity_Gym/scripts.pory"

# 337 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_KirkPostBattle: @ 820E336
# 338 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Pokémon and rock, it's all about heart,\n"
# 339 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "whoa-yeah!$"
# 340 "data/maps/MauvilleCity_Gym/scripts.pory"

# 341 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnIntro: @ 820E369
# 342 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I trained under Wattson!\n"
# 343 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "There ain't no way I'll lose easily!$"
# 344 "data/maps/MauvilleCity_Gym/scripts.pory"

# 345 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnDefeat: @ 820E3A7
# 346 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Unplugged and turned off…$"
# 347 "data/maps/MauvilleCity_Gym/scripts.pory"

# 348 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ShawnPostBattle: @ 820E3C1
# 349 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson, our Gym Leader, has been\n"
# 350 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "around for a long, long time.\p"
# 351 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "He was battling even before your\n"
# 352 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "daddy was born, that tough coot.$"
# 353 "data/maps/MauvilleCity_Gym/scripts.pory"

# 354 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenIntro: @ 820E443
# 355 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "This Gym's got puzzles!\n"
# 356 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Isn't it fun?$"
# 357 "data/maps/MauvilleCity_Gym/scripts.pory"

# 358 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenDefeat: @ 820E469
# 359 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "It's no fun to lose…$"
# 360 "data/maps/MauvilleCity_Gym/scripts.pory"

# 361 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_BenPostBattle: @ 820E47E
# 362 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson says he likes setting up\n"
# 363 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "little traps with switches.$"
# 364 "data/maps/MauvilleCity_Gym/scripts.pory"

# 365 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianIntro: @ 820E4BB
# 366 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "With my charm and my Pokémon's moves,\n"
# 367 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "you'll be shocked!$"
# 368 "data/maps/MauvilleCity_Gym/scripts.pory"

# 369 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianDefeat: @ 820E4F4
# 370 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I'm shocked by your power!$"
# 371 "data/maps/MauvilleCity_Gym/scripts.pory"

# 372 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_VivianPostBattle: @ 820E50F
# 373 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I've heard that Mauville was founded\n"
# 374 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "by Wattson.\p"
# 375 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "He was a Trainer long before we\n"
# 376 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "became Trainers.\l"
# 377 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "He must know all sorts of things!$"
# 378 "data/maps/MauvilleCity_Gym/scripts.pory"

# 379 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloIntro: @ 820E593
# 380 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I love shiny things!$"
# 381 "data/maps/MauvilleCity_Gym/scripts.pory"

# 382 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloDefeat: @ 820E5A8
# 383 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh…\n"
# 384 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "My eyes are frazzled…$"
# 385 "data/maps/MauvilleCity_Gym/scripts.pory"

# 386 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_AngeloPostBattle: @ 820E5C2
# 387 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Mauville Gym's Wattson has a shiny\n"
# 388 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "forehead. It makes me happy!$"
# 389 "data/maps/MauvilleCity_Gym/scripts.pory"

# 390 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonIntro: @ 820E602
# 391 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I've given up on my plans to convert\n"
# 392 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "the city, I have.\p"
# 393 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "And so, I put my time into making\n"
# 394 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "door traps in my Gym.\p"
# 395 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oh? Now, what are you doing here?\p"
# 396 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "What's that? You say you've gotten\n"
# 397 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "past all my rigged doors?\p"
# 398 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 399 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Now, that is amusing!\p"
# 400 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Then, I, Wattson, the Leader of\n"
# 401 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Mauville Gym, shall electrify you!$"
# 402 "data/maps/MauvilleCity_Gym/scripts.pory"

# 403 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonDefeat: @ 820E734
# 404 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 405 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Fine, I lost!\p"
# 406 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You ended up giving me a thrill!\n"
# 407 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Take this Badge!$"
# 408 "data/maps/MauvilleCity_Gym/scripts.pory"

# 409 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ReceivedDynamoBadge: @ 820E77F
# 410 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER} received the Dynamo Badge\n"
# 411 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "from Wattson.$"
# 412 "data/maps/MauvilleCity_Gym/scripts.pory"

# 413 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis: @ 820E7AA
# 414 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "With the Dynamo Badge, Pokémon can\n"
# 415 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "use Rock Smash out of battle.\p"
# 416 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "And, I'll register my Raichu in your\n"
# 417 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "PokéNav. It'll help you by smashing\l"
# 418 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "any rocks in your way.\p"
# 419 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 420 "data/maps/MauvilleCity_Gym/scripts.pory"

# 421 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainTakeThis:
# 422 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Hmm…\n"
# 423 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You should take this, too!$"
# 424 "data/maps/MauvilleCity_Gym/scripts.pory"

# 425 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_ExplainVoltSwitch: @ 820E844
# 426 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "That TM72 there contains Volt Switch.\p"
# 427 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "It's a move where your Pokémon attacks\n"
# 428 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "the opponent and then rushes back to\l"
# 429 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "switch places with a party Pokémon.\p"
# 430 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 431 "data/maps/MauvilleCity_Gym/scripts.pory"

# 432 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_RegisteredWattson: @ 820E8B5
# 433 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Registered Gym Leader Wattson\n"
# 434 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "in the PokéNav.$"
# 435 "data/maps/MauvilleCity_Gym/scripts.pory"

# 436 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_RegisteredRaichu: @ 820E8B5
# 437 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Registered Wattson's Raichu\n"
# 438 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "in the PokéNav.$"
# 439 "data/maps/MauvilleCity_Gym/scripts.pory"

# 440 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPostBattle: @ 820E8E3
# 441 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I swell with optimism, seeing a promising\n"
# 442 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "young Trainer like you!$"
# 443 "data/maps/MauvilleCity_Gym/scripts.pory"

# 444 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor: @ 820E925
# 445 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahah!\n"
# 446 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Go forth and endeavor, youngster!$"
# 447 "data/maps/MauvilleCity_Gym/scripts.pory"

# 448 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymStatue: @ 820E952
# 449 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Mauville City Pokémon Gym$"
# 450 "data/maps/MauvilleCity_Gym/scripts.pory"

# 451 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_GymStatueCertified: @ 820E96C
# 452 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Mauville City Pokémon Gym\p"
# 453 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson's Certified Trainers:\n"
# 454 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 455 "data/maps/MauvilleCity_Gym/scripts.pory"

# 456 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPreRematch: @ 820E9A7
# 457 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I'll make sparks fly from you!\n"
# 458 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Don't say I didn't warn you!$"
# 459 "data/maps/MauvilleCity_Gym/scripts.pory"

# 460 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonRematchDefeat: @ 820EA42
# 461 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Oof…\n"
# 462 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Our batteries ran dry…$"
# 463 "data/maps/MauvilleCity_Gym/scripts.pory"

# 464 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonPostRematch: @ 820EA5E
# 465 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson: We'll have to recharge our\n"
# 466 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "batteries again.\p"
# 467 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "When we're fully charged up, we'll\n"
# 468 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "gladly accept your challenge.\p"
# 469 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "So, come back again sometime,\n"
# 470 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "won't you?$"
# 471 "data/maps/MauvilleCity_Gym/scripts.pory"

# 472 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons: @ 820EAFD
# 473 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson: Oops! Wait!\n"
# 474 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You've only one Pokémon with you!\p"
# 475 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Come see me with two or more\n"
# 476 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Pokémon, all right?$"
# 477 "data/maps/MauvilleCity_Gym/scripts.pory"

# 478 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonChooseFormat:
# 479 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson: Ah-ha! Here at last!\n"
# 480 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I know what you want.\l"
# 481 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "You want to battle my Pokémon!\p"
# 482 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wahahahaha!\p"
# 483 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "I'll let you decide the rules -\n"
# 484 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Singles or Doubles?$"
# 485 "data/maps/MauvilleCity_Gym/scripts.pory"

# 486 "data/maps/MauvilleCity_Gym/scripts.pory"
MauvilleCity_Gym_Text_WattsonAllowLegends:
# 487 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Think you can handle my Legendary\n"
# 488 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Pokémon?\p"
# 489 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "They're shockingly strong!$"

MauvilleCity_Gym_EventScript_GiveVoltSwitch::
# 492 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_GiveVoltSwitch_Text_0
# 493 "data/maps/MauvilleCity_Gym/scripts.pory"
	givecustommon SPECIES_AMPHAROS, 30, ITEM_AMPHAROSITE, ITEM_CHERISH_BALL, NATURE_QUIET, 2, 252, 0, 4, 0, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_RISING_VOLTAGE, MOVE_DRAGON_PULSE, MOVE_FOCUS_BLAST, MOVE_SLACK_OFF, FALSE
# 494 "data/maps/MauvilleCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 495 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_GiveVoltSwitch_Text_1
# 496 "data/maps/MauvilleCity_Gym/scripts.pory"
	waitfanfare
# 497 "data/maps/MauvilleCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM72
# 498 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
# 499 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
	end


MauvilleCity_Gym_EventScript_CheckTrainers::
# 505 "data/maps/MauvilleCity_Gym/scripts.pory"
	checktrainerflag TRAINER_KIRK
	goto_if 0, MauvilleCity_Gym_EventScript_CheckTrainers_3
# 506 "data/maps/MauvilleCity_Gym/scripts.pory"
	checktrainerflag TRAINER_SHAWN
	goto_if 0, MauvilleCity_Gym_EventScript_CheckTrainers_3
# 507 "data/maps/MauvilleCity_Gym/scripts.pory"
	checktrainerflag TRAINER_BEN
	goto_if 0, MauvilleCity_Gym_EventScript_CheckTrainers_3
# 508 "data/maps/MauvilleCity_Gym/scripts.pory"
	checktrainerflag TRAINER_VIVIAN
	goto_if 0, MauvilleCity_Gym_EventScript_CheckTrainers_3
# 509 "data/maps/MauvilleCity_Gym/scripts.pory"
	checktrainerflag TRAINER_ANGELO
	goto_if 0, MauvilleCity_Gym_EventScript_CheckTrainers_3
MauvilleCity_Gym_EventScript_CheckTrainers_2:
	return

MauvilleCity_Gym_EventScript_CheckTrainers_1:
# 511 "data/maps/MauvilleCity_Gym/scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_CheckTrainers_Text_0, MSGBOX_NPC
# 512 "data/maps/MauvilleCity_Gym/scripts.pory"
	release
	end

MauvilleCity_Gym_EventScript_CheckTrainers_3:
# 510 "data/maps/MauvilleCity_Gym/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_CheckTrainers_1
	goto MauvilleCity_Gym_EventScript_CheckTrainers_2


MauvilleCity_Gym_EventScript_GiveVoltSwitch_Text_0:
# 492 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Take this special Pokémon as a gift\n"
	.string "from me!$"

MauvilleCity_Gym_EventScript_GiveVoltSwitch_Text_1:
# 495 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "{PLAYER} got Wattson's {COLOR BLUE}Ampharos{COLOR DARK_GRAY} as a\n"
	.string "gift!$"

MauvilleCity_Gym_EventScript_CheckTrainers_Text_0:
# 511 "data/maps/MauvilleCity_Gym/scripts.pory"
	.string "Wattson: Sorry, but you need to defeat\n"
	.string "every trainer on this Gym before\l"
	.string "battling me.$"
