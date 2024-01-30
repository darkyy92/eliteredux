# 1 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 2 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_MapScripts:: @ 8224E4C
# 3 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
# 4 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
# 5 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
# 6 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
# 7 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.byte 0
# 8 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 9 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_OnTransition: @ 8224E61
# 10 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 11 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 12 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 13 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_OnResume: @ 8224E67
# 14 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
# 15 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 16 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 17 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_OnLoad: @ 8224E6A
# 18 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
# 19 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	special SetSootopolisGymCrackedIceMetatiles
# 20 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 21 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 22 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles:: @ 8224E73
# 23 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	compare VAR_ICE_STEP_COUNT, 8
# 24 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_lt SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
# 25 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	compare VAR_ICE_STEP_COUNT, 28
# 26 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_lt SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
# 27 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	compare VAR_ICE_STEP_COUNT, 67
# 28 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_lt SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
# 29 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, 0
# 30 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, 0
# 31 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs:: @ 8224EA6
# 32 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, 0
# 33 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, 0
# 34 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs:: @ 8224EB8
# 35 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, 0
# 36 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, 0
# 37 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs:: @ 8224ECA
# 38 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	return
# 39 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 40 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_OnFrame: @ 8224ECB
# 41 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
# 42 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
# 43 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
# 44 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
# 45 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.2byte 0
# 46 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 47 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs:: @ 8224EED
# 48 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	addvar VAR_ICE_STEP_COUNT, 1
# 49 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 40
# 50 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	playse SE_ICE_STAIRS
# 51 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
# 52 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	special DrawWholeMapView
# 53 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 54 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 55 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs:: @ 8224F01
# 56 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	addvar VAR_ICE_STEP_COUNT, 1
# 57 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 40
# 58 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	playse SE_ICE_STAIRS
# 59 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
# 60 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	special DrawWholeMapView
# 61 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 62 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 63 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs:: @ 8224F15
# 64 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	addvar VAR_ICE_STEP_COUNT, 1
# 65 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 40
# 66 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	playse SE_ICE_STAIRS
# 67 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
# 68 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	special DrawWholeMapView
# 69 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 70 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 71 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_FallThroughIce:: @ 8224F29
# 72 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	lockall
# 73 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 20
# 74 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
# 75 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	waitmovement 0
# 76 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	playse SE_FALL
# 77 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 60
# 78 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
# 79 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	waitstate
# 80 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 81 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 82 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Movement_FallThroughIce: @ 8224F42
# 83 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	set_invisible
# 84 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	step_end
# 85 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 86 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_Juan:: @ 8224F44
# 87 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_EventScript_CheckTrainers
# 88 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_JUAN, SootopolisCity_Gym_1F_EventScript_AlreadyRematched
# 89 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_Gym_1F_EventScript_JuanRematch
# 90 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
# 91 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM03, SootopolisCity_Gym_1F_EventScript_GiveScald
# 92 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
# 93 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
# 94 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 95 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 96 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 97 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_JuanDefeated:: @ 8224F82
# 98 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
# 99 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	waitmessage
# 100 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 101 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
# 102 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	closemessage
# 103 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 30
# 104 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 105 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_RegisteredKabutops, MSGBOX_DEFAULT
# 106 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	waitfanfare
# 107 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	closemessage
# 108 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 30
# 109 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_TakeThis, MSGBOX_DEFAULT
# 110 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 111 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_BADGE08_GET
# 112 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
# 113 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
# 114 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
# 115 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
# 116 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
# 117 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setvar VAR_0x8008, 8
# 118 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 119 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_GiveScald
# 120 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	closemessage
# 121 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 30
# 122 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 123 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
# 124 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	waitfanfare
# 125 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	closemessage
# 126 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	delay 30
# 127 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
# 128 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 129 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 130 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 131 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge:: @ 822501B
# 132 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
# 133 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 134 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 135 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 136 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_JuanRematch::
# 137 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	message SootopolisCity_Gym_1F_Text_JuanChooseFormat
# 138 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	waitmessage
# 139 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
# 140 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	switch VAR_RESULT
# 141 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	case 0, SootopolisCity_Gym_1F_EventScript_SetSingles
# 142 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	case 1, SootopolisCity_Gym_1F_EventScript_SetDoubles
# 143 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	case 2, SootopolisCity_Gym_1F_EventScript_Exit
# 144 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	case 127, SootopolisCity_Gym_1F_EventScript_Exit
# 145 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 146 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 147 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 148 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_SetSingles::
# 149 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanAllowLegends, MSGBOX_YESNO
# 150 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	compare VAR_RESULT, 0
# 151 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_eq SootopolisCity_Gym_1F_EventScript_JuanSinglesRematch
# 152 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_4, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
# 153 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_JUAN
# 154 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 155 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 156 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 157 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_SetDoubles::
# 158 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanAllowLegends, MSGBOX_YESNO
# 159 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	compare VAR_RESULT, 0
# 160 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_eq SootopolisCity_Gym_1F_EventScript_JuanDoublesRematch
# 161 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_5, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
# 162 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_JUAN
# 163 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 164 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 165 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 166 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_JuanSinglesRematch::
# 167 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_2, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
# 168 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_JUAN
# 169 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 170 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 171 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 172 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_JuanDoublesRematch::
# 173 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_3, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
# 174 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_JUAN
# 175 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 176 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 177 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 178 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_AlreadyRematched::
# 179 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
# 180 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 181 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 182 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 183 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_Exit::
# 184 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 185 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 186 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 187 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GymGuide:: @ 8225040
# 188 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	lock
# 189 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	faceplayer
# 190 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
# 191 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 192 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 193 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 194 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 195 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory:: @ 8225055
# 196 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 197 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	release
# 198 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 199 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 200 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_LeftGymStatue:: @ 822505F
# 201 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	lockall
# 202 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
# 203 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
# 204 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 205 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 206 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_RightGymStatue:: @ 822506F
# 207 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	lockall
# 208 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
# 209 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
# 210 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 211 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 212 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GymStatueCertified:: @ 822507F
# 213 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
# 214 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 215 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 216 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 217 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_EventScript_GymStatue:: @ 8225089
# 218 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
# 219 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	releaseall
# 220 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	end
# 221 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 222 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GymGuideAdvice: @ 8225093
# 223 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Yo! How's it going, Champion-\n"
# 224 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "bound {PLAYER}?\p"
# 225 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Sootopolis's Gym Leader Juan is\n"
# 226 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "a master of Water-type Pokémon.\p"
# 227 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "And, to get to Juan, an icy floor\n"
# 228 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "will hamper your progress…\p"
# 229 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Listen, I'm sorry, but that's all I\n"
# 230 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "have for you.\p"
# 231 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The rest of the way, you have to\n"
# 232 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "go for it yourself!$"
# 233 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 234 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GymGuidePostVictory: @ 82251AF
# 235 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Yow! You've beaten even Juan, who\n"
# 236 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "was supposedly the best in all Hoenn!\p"
# 237 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Okay! Check out your Trainer Card.\p"
# 238 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "If you've gotten all the Badges, you're\n"
# 239 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "set for the Pokémon League challenge!$"
# 240 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 241 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanIntro: @ 8225268
# 242 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Let me ask you.\n"
# 243 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Did you know?\l"
# 244 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ah, I should not be so coy.\p"
# 245 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "It was I who taught Wallace everything\n"
# 246 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "there is to know about Pokémon.\p"
# 247 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Once, I had given up my position as\n"
# 248 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "the Gym Leader.\p"
# 249 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "In my place, I had entrusted Wallace\n"
# 250 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "with the Gym.\p"
# 251 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "However, a compelling reason arose for\n"
# 252 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "me to make a comeback.\p"
# 253 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ah, but enough chatter.\n"
# 254 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Let us begin our match, shall we?\p"
# 255 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Please, you shall bear witness to\n"
# 256 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "our artistry.\p"
# 257 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "A grand illusion of water sculpted\n"
# 258 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "by Pokémon and myself!$"
# 259 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 260 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
# 261 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
# 262 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
# 263 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
@ the existence of that unused array of ints.
# 264 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanDefeat: @ 8225432
# 265 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ahahaha, excellent!\n"
# 266 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Very well, you are the winner.\p"
# 267 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "From you, I sense the brilliant shine\n"
# 268 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of skill that will overcome all.\p"
# 269 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "However, compared with me or even\n"
# 270 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Wallace, you are lacking in elegance.\p"
# 271 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Perhaps I should make you a loan\n"
# 272 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of my outfit?\p"
# 273 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "… … … … … …\n"
# 274 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "… … … … … …\p"
# 275 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Hahaha, I merely jest!\p"
# 276 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Rather than my clothes, I shall reward\n"
# 277 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "you with this, the Rain Badge!$"
# 278 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 279 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_ReceivedRainBadge: @ 8225598
# 280 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "{PLAYER} received the Rain Badge\n"
# 281 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "from Juan.$"
# 282 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 283 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis: @ 82255BE
# 284 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Having the Rain Badge shall assure you\n"
# 285 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "the full obedience of all your Pokémon\l"
# 286 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "to your every command.\p"
# 287 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The Rain Badge also allows the use\n"
# 288 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of the HM move Waterfall to scale\l"
# 289 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "walls of cascading water.\p"
# 290 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "If you require assistance finding a\n"
# 291 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Pokémon to use Waterfall for you,\l"
# 292 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "you may borrow my Kabutops.\p"
# 293 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "… … … … … …$"
# 294 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 295 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_RegisteredKabutops:
# 296 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Registered Juan's Kabutops\n"
# 297 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "in the PokéNav.$"
# 298 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 299 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_TakeThis:
# 300 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "And, so that you never forget the\n"
# 301 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "battle we shared, take this…$"
# 302 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 303 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_ExplainScald: @ 82256C1
# 304 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The Technical Machine I handed you\n"
# 305 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "contains Scald.\p"
# 306 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "In use, it will occasionally burn\n"
# 307 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "the target with boiling hot water.\p"
# 308 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "… … … … … …$"
# 309 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 310 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_RegisteredJuan: @ 822574D
# 311 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Registered Gym Leader Juan\n"
# 312 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "in the PokéNav.$"
# 313 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 314 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanPostBattle: @ 8225778
# 315 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The Trainers who have gathered all\n"
# 316 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "the Gym Badges of Hoenn should make\l"
# 317 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "way to the ultimate destination.\p"
# 318 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "The Pokémon League.\p"
# 319 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Travel to the easternmost reaches\n"
# 320 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of Hoenn, to the island Ever Grande.\p"
# 321 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "There, you shall find the Pokémon\n"
# 322 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "League.$"
# 323 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 324 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GoGetFortreeBadge: @ 8225865
# 325 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "There remains but one Badge to\n"
# 326 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "obtain in Hoenn.\p"
# 327 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "If you wish to challenge the Pokémon\n"
# 328 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "League, you must obtain the last\l"
# 329 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Badge from the Gym in Fortree.$"
# 330 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 331 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GymStatue: @ 82258FA
# 332 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Sootopolis City Pokémon Gym$"
# 333 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 334 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_GymStatueCertified: @ 8225916
# 335 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Sootopolis City Pokémon Gym\p"
# 336 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Juan's Certified Trainers:\n"
# 337 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "{PLAYER}$"
# 338 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 339 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanPreRematch: @ 8225950
# 340 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Juan: Very Good!\n"
# 341 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Let the dance begin!$"
# 342 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 343 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanRematchDefeat: @ 8225A2E
# 344 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Ahahaha, you are the winner!\n"
# 345 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "You have defeated me again!$"
# 346 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 347 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanPostRematch: @ 8225A67
# 348 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Juan: If I told you to become my\n"
# 349 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "apprentice, you will refuse, I am sure.\p"
# 350 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I would like to make a gift of my coat\n"
# 351 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "to you.\p"
# 352 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "But again, you will refuse.\n"
# 353 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I imagine that to be so.\p"
# 354 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "And that, my friend, is a certain sign\n"
# 355 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "of nobility!$"
# 356 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 357 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons: @ 8225B48
# 358 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Juan: Ah, no, no, no.\n"
# 359 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "You have with you but one Pokémon.\p"
# 360 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I wish that you would return with\n"
# 361 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "two, perhaps more, Pokémon, please.$"
# 362 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 363 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanChooseFormat:
# 364 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Juan: Ah, this Gym had returned to its\n"
# 365 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "usual state of serenity…\p"
# 366 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "But our young typhoon has returned\n"
# 367 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "to put us to the test again!\p"
# 368 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Well, my friend, most certainly!\p"
# 369 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "I shall be delighted to dance with you\n"
# 370 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "as often as you wish!\p"
# 371 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "So, how shall we do this?$"
# 372 "data/maps/SootopolisCity_Gym_1F/scripts.pory"

# 373 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
SootopolisCity_Gym_1F_Text_JuanAllowLegends:
# 374 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "And would you allow me to dance with\n"
# 375 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "even stronger Legendary Pokémon?$"

SootopolisCity_Gym_1F_EventScript_GiveScald::
# 379 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_GiveScald_Text_0
# 380 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	givecustommon SPECIES_KINGDRA, 70, ITEM_KINGDRANITE, ITEM_CHERISH_BALL, NATURE_MODEST, 0, 0, 0, 0, 252, 252, 4, 0, 0, 0, 0, 0, 0, MOVE_HYDRO_PUMP, MOVE_HURRICANE, MOVE_DRACO_METEOR, MOVE_FLASH_CANNON, FALSE
# 381 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 382 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	message SootopolisCity_Gym_1F_EventScript_GiveScald_Text_1
# 383 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	waitfanfare
# 384 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	setflag FLAG_RECEIVED_TM03
# 385 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
# 386 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	release
	end


SootopolisCity_Gym_EventScript_CheckTrainers::
# 392 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_ANDREA
	goto_if 0, SootopolisCity_Gym_EventScript_CheckTrainers_3
# 393 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_CONNIE
	goto_if 0, SootopolisCity_Gym_EventScript_CheckTrainers_3
# 394 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_ANNIKA
	goto_if 0, SootopolisCity_Gym_EventScript_CheckTrainers_3
# 395 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_DAPHNE
	goto_if 0, SootopolisCity_Gym_EventScript_CheckTrainers_3
# 396 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_BRIDGET
	goto_if 0, SootopolisCity_Gym_EventScript_CheckTrainers_3
# 397 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_TIFFANY
	goto_if 0, SootopolisCity_Gym_EventScript_CheckTrainers_3
SootopolisCity_Gym_EventScript_CheckTrainers_2:
	return

SootopolisCity_Gym_EventScript_CheckTrainers_1:
# 404 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	msgbox SootopolisCity_Gym_EventScript_CheckTrainers_Text_0, MSGBOX_NPC
# 405 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	release
	end

SootopolisCity_Gym_EventScript_CheckTrainers_3:
# 403 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	goto_if_unset FLAG_BADGE08_GET, SootopolisCity_Gym_EventScript_CheckTrainers_1
	goto SootopolisCity_Gym_EventScript_CheckTrainers_2


SootopolisCity_Gym_1F_EventScript_GiveScald_Text_0:
# 379 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Take this special Pokémon as a gift\n"
	.string "from me!$"

SootopolisCity_Gym_1F_EventScript_GiveScald_Text_1:
# 382 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "{PLAYER} got Juan's {COLOR BLUE}Kingdra{COLOR DARK_GRAY} as a gift!$"

SootopolisCity_Gym_EventScript_CheckTrainers_Text_0:
# 404 "data/maps/SootopolisCity_Gym_1F/scripts.pory"
	.string "Juan: Sorry, but you need to defeat\n"
	.string "every trainer on this Gym before\l"
	.string "battling me.$"
