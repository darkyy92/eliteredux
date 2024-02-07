# 1 "data/maps/MossdeepCity_Gym/scripts.pory"

# 2 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_MapScripts:: @ 8220800
# 3 "data/maps/MossdeepCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
# 4 "data/maps/MossdeepCity_Gym/scripts.pory"
	.byte 0
# 5 "data/maps/MossdeepCity_Gym/scripts.pory"

# 6 "data/maps/MossdeepCity_Gym/scripts.pory"
@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below
# 7 "data/maps/MossdeepCity_Gym/scripts.pory"

# 8 "data/maps/MossdeepCity_Gym/scripts.pory"
@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
# 9 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_OnLoad: @ 8220806
# 10 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
# 11 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
# 12 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 13 "data/maps/MossdeepCity_Gym/scripts.pory"

# 14 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch2:: @ 8220815
# 15 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
# 16 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
# 17 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 18 "data/maps/MossdeepCity_Gym/scripts.pory"

# 19 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch3:: @ 8220824
# 20 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
# 21 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
# 22 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 23 "data/maps/MossdeepCity_Gym/scripts.pory"

# 24 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_CheckSwitch4:: @ 8220833
# 25 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
# 26 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 27 "data/maps/MossdeepCity_Gym/scripts.pory"

# 28 "data/maps/MossdeepCity_Gym/scripts.pory"
@ All the below set metatile scripts are leftover from RS and are functionally unused
# 29 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles:: @ 822083D
# 30 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, 0
# 31 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, 1
# 32 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
# 33 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 34 "data/maps/MossdeepCity_Gym/scripts.pory"

# 35 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch2Metatiles:: @ 8220855
# 36 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, 0
# 37 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, 1
# 38 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
# 39 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 40 "data/maps/MossdeepCity_Gym/scripts.pory"

# 41 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch3Metatiles:: @ 822086D
# 42 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, 0
# 43 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, 1
# 44 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
# 45 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 46 "data/maps/MossdeepCity_Gym/scripts.pory"

# 47 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_SetSwitch4Metatiles:: @ 8220885
# 48 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, 0
# 49 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, 1
# 50 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 51 "data/maps/MossdeepCity_Gym/scripts.pory"

# 52 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLiza:: @ 8220898
# 53 "data/maps/MossdeepCity_Gym/scripts.pory"
	//call MossdeepCity_Gym_EventScript_CheckTrainers
# 54 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_SYS_INVERSE_BATTLE
# 55 "data/maps/MossdeepCity_Gym/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_TATE_AND_LIZA, MossdeepCity_Gym_EventScript_AlreadyRematched
# 56 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_Gym_EventScript_TateAndLizaRematch
# 57 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
# 58 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_SYS_INVERSE_BATTLE
# 59 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLizaRematch
# 60 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM04, MossdeepCity_Gym_EventScript_GiveCalmMind
# 61 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
# 62 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 63 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 64 "data/maps/MossdeepCity_Gym/scripts.pory"

# 65 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLizaDefeated:: @ 82208D1
# 66 "data/maps/MossdeepCity_Gym/scripts.pory"
	message MossdeepCity_Gym_Text_ReceivedMindBadge
# 67 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmessage
# 68 "data/maps/MossdeepCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 69 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
# 70 "data/maps/MossdeepCity_Gym/scripts.pory"
	closemessage
# 71 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay 30
# 72 "data/maps/MossdeepCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 73 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_RegisteredSlowbro, MSGBOX_DEFAULT
# 74 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitfanfare
# 75 "data/maps/MossdeepCity_Gym/scripts.pory"
	closemessage
# 76 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay 30
# 77 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TakeThis, MSGBOX_DEFAULT
# 78 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 79 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_BADGE07_GET
# 80 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
# 81 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
# 82 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_UNKNOWN_0x393
# 83 "data/maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 84 "data/maps/MossdeepCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 85 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
# 86 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 87 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
# 88 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
# 89 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
# 90 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_SYS_INVERSE_BATTLE
# 91 "data/maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 1
# 92 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
# 93 "data/maps/MossdeepCity_Gym/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
# 94 "data/maps/MossdeepCity_Gym/scripts.pory"
	call MossdeepCity_Gym_EventScript_GiveCalmMind
# 95 "data/maps/MossdeepCity_Gym/scripts.pory"
	closemessage
# 96 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay 30
# 97 "data/maps/MossdeepCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 98 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
# 99 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitfanfare
# 100 "data/maps/MossdeepCity_Gym/scripts.pory"
	closemessage
# 101 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay 30
# 102 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
# 103 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 104 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 105 "data/maps/MossdeepCity_Gym/scripts.pory"

# 106 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLizaRematch::
# 107 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaAllowLegends, MSGBOX_YESNO
# 108 "data/maps/MossdeepCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 109 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLizaDoublesRematch
# 110 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_3, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
# 111 "data/maps/MossdeepCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_TATE_AND_LIZA
# 112 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_SYS_INVERSE_BATTLE
# 113 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 114 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 115 "data/maps/MossdeepCity_Gym/scripts.pory"

# 116 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_TateAndLizaDoublesRematch::
# 117 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_2, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
# 118 "data/maps/MossdeepCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_TATE_AND_LIZA
# 119 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_SYS_INVERSE_BATTLE
# 120 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 121 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 122 "data/maps/MossdeepCity_Gym/scripts.pory"

# 123 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_AlreadyRematched::
# 124 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
# 125 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_SYS_INVERSE_BATTLE
# 126 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 127 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 128 "data/maps/MossdeepCity_Gym/scripts.pory"

# 129 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Exit::
# 130 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_SYS_INVERSE_BATTLE
# 131 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 132 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 133 "data/maps/MossdeepCity_Gym/scripts.pory"

# 134 "data/maps/MossdeepCity_Gym/scripts.pory"
@ All the below switch scripts are leftover from RS and are functionally unused
# 135 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch1:: @ 8220999
# 136 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 137 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
# 138 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 139 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 140 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 141 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, 0
# 142 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, 1
# 143 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 144 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 145 "data/maps/MossdeepCity_Gym/scripts.pory"

# 146 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed:: @ 82209C8
# 147 "data/maps/MossdeepCity_Gym/scripts.pory"
	special DrawWholeMapView
# 148 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_CLICK
# 149 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 150 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 151 "data/maps/MossdeepCity_Gym/scripts.pory"

# 152 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch1:: @ 82209D0
# 153 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 154 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 155 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 156 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Left, 0
# 157 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Up, 1
# 158 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 159 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 160 "data/maps/MossdeepCity_Gym/scripts.pory"

# 161 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch2:: @ 82209F5
# 162 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 163 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
# 164 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 165 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 166 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 167 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, 0
# 168 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, 1
# 169 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 170 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 171 "data/maps/MossdeepCity_Gym/scripts.pory"

# 172 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch2:: @ 8220A24
# 173 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 174 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 175 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 176 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Down, 0
# 177 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Up, 1
# 178 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 179 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 180 "data/maps/MossdeepCity_Gym/scripts.pory"

# 181 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch3:: @ 8220A49
# 182 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 183 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
# 184 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 185 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 186 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 187 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, 0
# 188 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, 1
# 189 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 190 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 191 "data/maps/MossdeepCity_Gym/scripts.pory"

# 192 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch3:: @ 8220A78
# 193 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 194 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 195 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 196 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Right, 0
# 197 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Up, 1
# 198 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 199 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 200 "data/maps/MossdeepCity_Gym/scripts.pory"

# 201 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Switch4:: @ 8220A9D
# 202 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 203 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
# 204 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 205 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 206 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 207 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, 0
# 208 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, 1
# 209 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 210 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 211 "data/maps/MossdeepCity_Gym/scripts.pory"

# 212 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_ClearSwitch4:: @ 8220ACC
# 213 "data/maps/MossdeepCity_Gym/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 214 "data/maps/MossdeepCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
# 215 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 216 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Right, 0
# 217 "data/maps/MossdeepCity_Gym/scripts.pory"
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Up, 1
# 218 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
# 219 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 220 "data/maps/MossdeepCity_Gym/scripts.pory"

# 221 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_WarpToEntrance:: @ 8220AF1
# 222 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 223 "data/maps/MossdeepCity_Gym/scripts.pory"
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 255, 7, 30
# 224 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitstate
# 225 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 226 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 227 "data/maps/MossdeepCity_Gym/scripts.pory"

# 228 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Preston:: @ 8220AFD
# 229 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
# 230 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
# 231 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 232 "data/maps/MossdeepCity_Gym/scripts.pory"

# 233 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Virgil:: @ 8220B14
# 234 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
# 235 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
# 236 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 237 "data/maps/MossdeepCity_Gym/scripts.pory"

# 238 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Blake:: @ 8220B2B
# 239 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
# 240 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
# 241 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 242 "data/maps/MossdeepCity_Gym/scripts.pory"

# 243 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Hannah:: @ 8220B42
# 244 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
# 245 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
# 246 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 247 "data/maps/MossdeepCity_Gym/scripts.pory"

# 248 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Samantha:: @ 8220B59
# 249 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
# 250 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
# 251 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 252 "data/maps/MossdeepCity_Gym/scripts.pory"

# 253 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Maura:: @ 8220B70
# 254 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
# 255 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
# 256 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 257 "data/maps/MossdeepCity_Gym/scripts.pory"

# 258 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Sylvia:: @ 8220B87
# 259 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
# 260 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
# 261 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 262 "data/maps/MossdeepCity_Gym/scripts.pory"

# 263 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Nate:: @ 8220B9E
# 264 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
# 265 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
# 266 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 267 "data/maps/MossdeepCity_Gym/scripts.pory"

# 268 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Macey:: @ 8220BB5
# 269 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
# 270 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
# 271 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 272 "data/maps/MossdeepCity_Gym/scripts.pory"

# 273 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Clifford:: @ 8220BCC
# 274 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
# 275 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
# 276 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 277 "data/maps/MossdeepCity_Gym/scripts.pory"

# 278 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Nicholas:: @ 8220BE3
# 279 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
# 280 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
# 281 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 282 "data/maps/MossdeepCity_Gym/scripts.pory"

# 283 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_Kathleen:: @ 8220BFA
# 284 "data/maps/MossdeepCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
# 285 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
# 286 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 287 "data/maps/MossdeepCity_Gym/scripts.pory"

# 288 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymGuide:: 
# 289 "data/maps/MossdeepCity_Gym/scripts.pory"
	lock
# 290 "data/maps/MossdeepCity_Gym/scripts.pory"
	faceplayer
# 291 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
# 292 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_Guide1, MSGBOX_DEFAULT
# 293 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_Guide2, MSGBOX_DEFAULT
# 294 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 295 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 296 "data/maps/MossdeepCity_Gym/scripts.pory"

# 297 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Guide2::
# 298 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_Guide2, MSGBOX_DEFAULT
# 299 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 300 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 301 "data/maps/MossdeepCity_Gym/scripts.pory"

# 302 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymGuidePostVictory:: @ 81FC998
# 303 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 304 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
# 305 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 306 "data/maps/MossdeepCity_Gym/scripts.pory"

# 307 "data/maps/MossdeepCity_Gym/scripts.pory"
@ Leftover from RS, functionally unused
# 308 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Movement_WaitAfterSwitchUse: @ 8220C30
# 309 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay_16
# 310 "data/maps/MossdeepCity_Gym/scripts.pory"
	delay_16
# 311 "data/maps/MossdeepCity_Gym/scripts.pory"
	step_end
# 312 "data/maps/MossdeepCity_Gym/scripts.pory"

# 313 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_LeftGymStatue:: @ 8220C33
# 314 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 315 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
# 316 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_GymStatue
# 317 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 318 "data/maps/MossdeepCity_Gym/scripts.pory"

# 319 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_RightGymStatue:: @ 8220C43
# 320 "data/maps/MossdeepCity_Gym/scripts.pory"
	lockall
# 321 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
# 322 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto MossdeepCity_Gym_EventScript_GymStatue
# 323 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 324 "data/maps/MossdeepCity_Gym/scripts.pory"

# 325 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymStatueCertified:: @ 8220C53
# 326 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 327 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 328 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 329 "data/maps/MossdeepCity_Gym/scripts.pory"

# 330 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GymStatue:: @ 8220C5D
# 331 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 332 "data/maps/MossdeepCity_Gym/scripts.pory"
	releaseall
# 333 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 334 "data/maps/MossdeepCity_Gym/scripts.pory"

# 335 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_YellowFloorSwitch:: @ 8220C67
# 336 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 337 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 338 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 339 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 340 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 0
# 341 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 342 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 343 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 344 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 345 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 346 "data/maps/MossdeepCity_Gym/scripts.pory"

# 347 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_BlueFloorSwitch:: @ 8220C7D
# 348 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 349 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 350 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 351 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 352 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 1
# 353 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 354 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 355 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 356 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 357 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 358 "data/maps/MossdeepCity_Gym/scripts.pory"

# 359 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_GreenFloorSwitch:: @ 8220C93
# 360 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 361 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 362 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 363 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 364 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 2
# 365 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 366 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 367 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 368 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 369 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 370 "data/maps/MossdeepCity_Gym/scripts.pory"

# 371 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_PurpleFloorSwitch:: @ 8220CA9
# 372 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 373 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 374 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 375 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 376 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 3
# 377 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 378 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 379 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 380 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 381 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 382 "data/maps/MossdeepCity_Gym/scripts.pory"

# 383 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_EventScript_RedFloorSwitch:: @ 8220CBF
# 384 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_SWITCH
# 385 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitse
# 386 "data/maps/MossdeepCity_Gym/scripts.pory"
	playse SE_REPEL
# 387 "data/maps/MossdeepCity_Gym/scripts.pory"
	initrotatingtilepuzzle FALSE
# 388 "data/maps/MossdeepCity_Gym/scripts.pory"
	moverotatingtileobjects 4
# 389 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 390 "data/maps/MossdeepCity_Gym/scripts.pory"
	turnrotatingtileobjects
# 391 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitmovement 0
# 392 "data/maps/MossdeepCity_Gym/scripts.pory"
	freerotatingtilepuzzle
# 393 "data/maps/MossdeepCity_Gym/scripts.pory"
	end
# 394 "data/maps/MossdeepCity_Gym/scripts.pory"

# 395 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_Guide1: @ 8220CD5
# 396 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Yo, how's it going, Champion-\n"
# 397 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "bound {PLAYER}?$"
# 398 "data/maps/MossdeepCity_Gym/scripts.pory"

# 399 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_Guide2: @ 8220CD5
# 400 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The Gym Leaders here use\n"
# 401 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Psychic-type Pokémon.\p"
# 402 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "They've also got psychic powers\n"
# 403 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "themselves, which they'll use to\l"
# 404 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "alter the battle field!\p"
# 405 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "If you want to win, you'll need to show\n"
# 406 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "them how tight you are with your\l"
# 407 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Pokémon. Go for it!$"
# 408 "data/maps/MossdeepCity_Gym/scripts.pory"

# 409 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymGuidePostVictory: @ 8220E2A
# 410 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Wow, you're astounding!\n"
# 411 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You're one great Trainer!$"
# 412 "data/maps/MossdeepCity_Gym/scripts.pory"

# 413 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonIntro: @ 8220E5C
# 414 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Battles hinge on the strength of your\n"
# 415 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "spirit! The weak-spirited will never win!$"
# 416 "data/maps/MossdeepCity_Gym/scripts.pory"

# 417 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonDefeat: @ 8220EAC
# 418 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I lost!\n"
# 419 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I must temper my spirit again!$"
# 420 "data/maps/MossdeepCity_Gym/scripts.pory"

# 421 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_PrestonPostBattle: @ 8220ED3
# 422 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The indecisive lose.\n"
# 423 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "That's my warning to you.$"
# 424 "data/maps/MossdeepCity_Gym/scripts.pory"

# 425 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilIntro: @ 8220F02
# 426 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Let me see your talent!$"
# 427 "data/maps/MossdeepCity_Gym/scripts.pory"

# 428 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilDefeat: @ 8220F1A
# 429 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You possess spectacular talent!$"
# 430 "data/maps/MossdeepCity_Gym/scripts.pory"

# 431 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_VirgilPostBattle: @ 8220F3A
# 432 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "If there are prodigies in the world,\n"
# 433 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "then our Gym Leaders are them!\p"
# 434 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "However, you may be even more talented\n"
# 435 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "than them…$"
# 436 "data/maps/MossdeepCity_Gym/scripts.pory"

# 437 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakeIntro: @ 8220FB0
# 438 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Fufufufu… Watch me levitate a Poké\n"
# 439 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Ball telekinetically!\p"
# 440 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Wrooooooooaaaar!\n"
# 441 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … … …\p"
# 442 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Sometimes, I'm out of sync…$"
# 443 "data/maps/MossdeepCity_Gym/scripts.pory"

# 444 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakeDefeat: @ 8221024
# 445 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "My Pokémon battling skills are out\n"
# 446 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "of sync, too!$"
# 447 "data/maps/MossdeepCity_Gym/scripts.pory"

# 448 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_BlakePostBattle: @ 8221055
# 449 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "A Poké Ball was too heavy to lift\n"
# 450 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "psychically. But this dust bunny…\p"
# 451 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Whoooooooooooooooh!\n"
# 452 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … …\p"
# 453 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "No, I'm not cheating!\n"
# 454 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I didn't blow on it! Honestly!$"
# 455 "data/maps/MossdeepCity_Gym/scripts.pory"

# 456 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahIntro: @ 82210EE
# 457 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "When you lose to me, don't be too hard\n"
# 458 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "on yourself.\p"
# 459 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "It's not that you're weak--I'm just\n"
# 460 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "too strong!$"
# 461 "data/maps/MossdeepCity_Gym/scripts.pory"

# 462 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahDefeat: @ 8221152
# 463 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You're just too strong!$"
# 464 "data/maps/MossdeepCity_Gym/scripts.pory"

# 465 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_HannahPostBattle: @ 822116A
# 466 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I'm not going to get down on myself for\n"
# 467 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "losing. I just need to train harder.\p"
# 468 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Positive thinking--that's my strong\n"
# 469 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "point!$"
# 470 "data/maps/MossdeepCity_Gym/scripts.pory"

# 471 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaIntro: @ 82211E2
# 472 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I see it…\n"
# 473 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I see your future…\p"
# 474 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "If you can beat me, I will tell you\n"
# 475 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "your future!$"
# 476 "data/maps/MossdeepCity_Gym/scripts.pory"

# 477 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaDefeat: @ 8221230
# 478 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I surrender!$"
# 479 "data/maps/MossdeepCity_Gym/scripts.pory"

# 480 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SamanthaPostBattle: @ 822123D
# 481 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You will wage a terrifically intense\n"
# 482 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "battle with our Gym Leaders…\p"
# 483 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The result…\n"
# 484 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You won't hear it from me!$"
# 485 "data/maps/MossdeepCity_Gym/scripts.pory"

# 486 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraIntro: @ 82212A6
# 487 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The roads you have traveled…\n"
# 488 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "What you have experienced…\p"
# 489 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Come at me with everything you've\n"
# 490 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "learned!$"
# 491 "data/maps/MossdeepCity_Gym/scripts.pory"

# 492 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraDefeat: @ 8221309
# 493 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You've traveled a path of greatness!$"
# 494 "data/maps/MossdeepCity_Gym/scripts.pory"

# 495 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MauraPostBattle: @ 822132E
# 496 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "A bright future awaits those who have\n"
# 497 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "worked diligently.\p"
# 498 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "For those who lazed idly, there is\n"
# 499 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "only despair at the end.\p"
# 500 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "What goes around comes around…$"
# 501 "data/maps/MossdeepCity_Gym/scripts.pory"

# 502 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaIntro: @ 82213C2
# 503 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Even at the risk of life, I will win\n"
# 504 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "this battle!$"
# 505 "data/maps/MossdeepCity_Gym/scripts.pory"

# 506 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaDefeat: @ 82213F4
# 507 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "What you do…\n"
# 508 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "It horrifies me…$"
# 509 "data/maps/MossdeepCity_Gym/scripts.pory"

# 510 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_SylviaPostBattle: @ 8221412
# 511 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "How dare you beat me…\p"
# 512 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "It won't be my fault if something\n"
# 513 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "horrible befalls you…$"
# 514 "data/maps/MossdeepCity_Gym/scripts.pory"

# 515 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NateIntro: @ 8221460
# 516 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Hohoho.\p"
# 517 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You need me to show you how tenacious\n"
# 518 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "the Psychic type can be.$"
# 519 "data/maps/MossdeepCity_Gym/scripts.pory"

# 520 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NateDefeat: @ 82214A7
# 521 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Oh! My, my!\n"
# 522 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Your battle style is fantastic!$"
# 523 "data/maps/MossdeepCity_Gym/scripts.pory"

# 524 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NatePostBattle: @ 82214D3
# 525 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I… I don't let defeat rattle m-me,\n"
# 526 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "however b-badly.$"
# 527 "data/maps/MossdeepCity_Gym/scripts.pory"

# 528 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenIntro: @ 8221507
# 529 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Let me show you a perfectly awful,\n"
# 530 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "horrifying time!$"
# 531 "data/maps/MossdeepCity_Gym/scripts.pory"

# 532 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenDefeat: @ 822153B
# 533 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "N-nooooo!$"
# 534 "data/maps/MossdeepCity_Gym/scripts.pory"

# 535 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_KathleenPostBattle: @ 8221545
# 536 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Your vitality is contagious!\n"
# 537 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Get away from me quickly!$"
# 538 "data/maps/MossdeepCity_Gym/scripts.pory"

# 539 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordIntro: @ 822157C
# 540 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "I may be past my prime, but I suggest\n"
# 541 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "you not patronize me.$"
# 542 "data/maps/MossdeepCity_Gym/scripts.pory"

# 543 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordDefeat: @ 82215B8
# 544 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Ah, you overflow with the power\n"
# 545 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "of youth!$"
# 546 "data/maps/MossdeepCity_Gym/scripts.pory"

# 547 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_CliffordPostBattle: @ 82215E2
# 548 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "It seems that I could not overcome\n"
# 549 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "your youthful energy.$"
# 550 "data/maps/MossdeepCity_Gym/scripts.pory"

# 551 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyIntro: @ 822161B
# 552 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "You're not getting through to the end!\n"
# 553 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Not if I can help it!$"
# 554 "data/maps/MossdeepCity_Gym/scripts.pory"

# 555 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyDefeat: @ 8221658
# 556 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "How could you be so ludicrously\n"
# 557 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "strong?$"
# 558 "data/maps/MossdeepCity_Gym/scripts.pory"

# 559 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_MaceyPostBattle: @ 8221680
# 560 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Humph! You may be strong, but you're\n"
# 561 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "not suitable for the Psychic type!\p"
# 562 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "The way you battle is somehow brutal!$"
# 563 "data/maps/MossdeepCity_Gym/scripts.pory"

# 564 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasIntro: @ 82216EE
# 565 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Wroooar! Have a taste of my super\n"
# 566 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Pokémon hard-battling power!$"
# 567 "data/maps/MossdeepCity_Gym/scripts.pory"

# 568 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasDefeat: @ 822172D
# 569 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Oh!\n"
# 570 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Done in!$"
# 571 "data/maps/MossdeepCity_Gym/scripts.pory"

# 572 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_NicholasPostBattle: @ 822173A
# 573 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "All right! I think I'll develop a special\n"
# 574 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "invincible Pokémon power next.$"
# 575 "data/maps/MossdeepCity_Gym/scripts.pory"

# 576 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaIntro: @ 8221783
# 577 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Hehehe… Were you surprised?\p"
# 578 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Fufufu… Were you surprised?\p"
# 579 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: That there are two Gym Leaders?\n"
# 580 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: That there are two Gym Leaders?\p"
# 581 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: We're twins!\n"
# 582 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: We're twins!\p"
# 583 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: We don't need to talk because…\n"
# 584 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: We can each determine what…\p"
# 585 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: The other is thinking…\n"
# 586 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: All in our minds!\p"
# 587 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Also…\n"
# 588 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: This will be an Inverse Battle!\p"
# 589 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Supereffective moves will be…\n"
# 590 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Not very effective!\p"
# 591 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: And not very effective moves…\n"
# 592 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: will be Supereffective!\p"
# 593 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: This combination of ours…\n"
# 594 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Can you beat it?$"
# 595 "data/maps/MossdeepCity_Gym/scripts.pory"

# 596 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaDefeat: @ 82218EC
# 597 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: What?! Our combination…\n"
# 598 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Was shattered!\p"
# 599 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: It can't be helped. You've won…\n"
# 600 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: So, in recognition, take this.$"
# 601 "data/maps/MossdeepCity_Gym/scripts.pory"

# 602 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ReceivedMindBadge: @ 822196A
# 603 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER} received the Mind Badge\n"
# 604 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "from Liza and Tate.$"
# 605 "data/maps/MossdeepCity_Gym/scripts.pory"

# 606 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis: @ 8221999
# 607 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: The Mind Badge will make any\n"
# 608 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Pokémon up to Level 90 obey you.\p"
# 609 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: It also lets you use the HM move\n"
# 610 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Dive outside of battle, so we'll lend\l"
# 611 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "you our Slowbro whenever you need it!\p"
# 612 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 613 "data/maps/MossdeepCity_Gym/scripts.pory"

# 614 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_RegisteredSlowbro: @ 8221AEA
# 615 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Registered Tate & Liza's Slowbro\n"
# 616 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "in the PokéNav.$"
# 617 "data/maps/MossdeepCity_Gym/scripts.pory"

# 618 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TakeThis:
# 619 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: You should also take this, too.$"
# 620 "data/maps/MossdeepCity_Gym/scripts.pory"

# 621 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_ExplainCalmMind: @ 8221A40
# 622 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: That TM04 contains…\n"
# 623 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Calm Mind!\p"
# 624 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: It raises Sp. Atk and…\n"
# 625 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: It raises Sp. Def!\p"
# 626 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: It's a move that's perfect…\n"
# 627 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: For Psychic Pokémon!\p"
# 628 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 629 "data/maps/MossdeepCity_Gym/scripts.pory"

# 630 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_RegisteredTateAndLiza: @ 8221AEA
# 631 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Registered Gym Leaders Tate & Liza\n"
# 632 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "in the PokéNav.$"
# 633 "data/maps/MossdeepCity_Gym/scripts.pory"

# 634 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPostBattle: @ 8221B1D
# 635 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Looks like the bond between you\n"
# 636 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "and your Pokémon is far stronger than\l"
# 637 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "the bond that we share as twins.\p"
# 638 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: You will become even stronger!\n"
# 639 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "We've battled you, so we know.$"
# 640 "data/maps/MossdeepCity_Gym/scripts.pory"

# 641 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons: @ 8221BCE
# 642 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Hehehe… Were you surprised?\p"
# 643 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: That there are two Gym Leaders?\p"
# 644 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Oops, you have only one…\n"
# 645 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Pokémon that can battle.\p"
# 646 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: We can't battle that way!\p"
# 647 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: If you want to challenge us,\n"
# 648 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "bring some more Pokémon.$"
# 649 "data/maps/MossdeepCity_Gym/scripts.pory"

# 650 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymStatue: @ 8221CB0
# 651 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Mossdeep City Pokémon Gym$"
# 652 "data/maps/MossdeepCity_Gym/scripts.pory"

# 653 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_GymStatueCertified: @ 8221CCA
# 654 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Mossdeep City Pokémon Gym\p"
# 655 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza and Tate's Certified Trainers:\n"
# 656 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 657 "data/maps/MossdeepCity_Gym/scripts.pory"

# 658 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPreRematch: @ 8221D0B
# 659 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Our combination…\n"
# 660 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: We'll show you again and again!$"
# 661 "data/maps/MossdeepCity_Gym/scripts.pory"

# 662 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaRematchDefeat: @ 8221E05
# 663 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: You and your Pokémon…\n"
# 664 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: It's as if you were siblings!$"
# 665 "data/maps/MossdeepCity_Gym/scripts.pory"

# 666 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaPostRematch: @ 8221E45
# 667 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: You can knock us down,\n"
# 668 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "but we'll never stay down!\p"
# 669 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Because the two of us,\n"
# 670 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "we always support each other!$"
# 671 "data/maps/MossdeepCity_Gym/scripts.pory"

# 672 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons: @ 8221EB8
# 673 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Oh…\n"
# 674 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: For our match…\p"
# 675 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: You brought just one Pokémon!\n"
# 676 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: You brought just one Pokémon!\p"
# 677 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: We need you to bring at least…\n"
# 678 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Two Pokémon when you come back.$"
# 679 "data/maps/MossdeepCity_Gym/scripts.pory"

# 680 "data/maps/MossdeepCity_Gym/scripts.pory"
MossdeepCity_Gym_Text_TateAndLizaAllowLegends:
# 681 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Pokémon…\n"
# 682 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Pokémon…\p"
# 683 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: By changing the party's mix…\n"
# 684 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: The battle style changes.\p"
# 685 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: But me…\n"
# 686 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: But me…\p"
# 687 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: I'll always be with Liza!\n"
# 688 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: I'll always be with Tate!\p"
# 689 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Tell us - will you battle…\n"
# 690 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: Our Legendary Pokémon?$"

MossdeepCity_Gym_EventScript_GiveCalmMind::
# 693 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_GiveCalmMind_Text_0
# 694 "data/maps/MossdeepCity_Gym/scripts.pory"
	givecustommon SPECIES_REUNICLUS, 60, ITEM_LIFE_ORB, ITEM_CHERISH_BALL, NATURE_QUIET, 2, 252, 0, 4, 0, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_PSYSHOCK, MOVE_AURA_SPHERE, MOVE_FIRE_BLAST, MOVE_PROTECT, TRUE
# 695 "data/maps/MossdeepCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 696 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitfanfare
# 697 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_GiveCalmMind_Text_1
# 698 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_GiveCalmMind_Text_2
# 699 "data/maps/MossdeepCity_Gym/scripts.pory"
	giveitem ITEM_SLOWKINGITE, 1
# 700 "data/maps/MossdeepCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 701 "data/maps/MossdeepCity_Gym/scripts.pory"
	waitfanfare
# 702 "data/maps/MossdeepCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM04
# 703 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
# 704 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
	end


MossdeepCity_Gym_EventScript_CheckTrainers::
# 710 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_PRESTON
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 711 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_VIRGIL
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 712 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_BLAKE
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 713 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_HANNAH
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 714 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_SAMANTHA
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 715 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_MAURA
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 716 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_NICHOLAS
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 717 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_MACEY
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 718 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_CLIFFORD
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 719 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_KATHLEEN
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 720 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_NATE
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
# 721 "data/maps/MossdeepCity_Gym/scripts.pory"
	checktrainerflag TRAINER_MAURA
	goto_if 0, MossdeepCity_Gym_EventScript_CheckTrainers_3
MossdeepCity_Gym_EventScript_CheckTrainers_2:
	return

MossdeepCity_Gym_EventScript_CheckTrainers_1:
# 723 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_CheckTrainers_Text_0, MSGBOX_NPC
# 724 "data/maps/MossdeepCity_Gym/scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_CheckTrainers_Text_1, MSGBOX_NPC
# 725 "data/maps/MossdeepCity_Gym/scripts.pory"
	release
	end

MossdeepCity_Gym_EventScript_CheckTrainers_3:
# 722 "data/maps/MossdeepCity_Gym/scripts.pory"
	goto_if_unset FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_CheckTrainers_1
	goto MossdeepCity_Gym_EventScript_CheckTrainers_2


MossdeepCity_Gym_EventScript_GiveCalmMind_Text_0:
# 693 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Take this special Pokémon as a\n"
	.string "gift from me!$"

MossdeepCity_Gym_EventScript_GiveCalmMind_Text_1:
# 697 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "{PLAYER} got Tate's {COLOR BLUE}Reuniclus{COLOR DARK_GRAY} as a\n"
	.string "gift!$"

MossdeepCity_Gym_EventScript_GiveCalmMind_Text_2:
# 698 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: And take this gift from me!$"

MossdeepCity_Gym_EventScript_CheckTrainers_Text_0:
# 723 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Tate: Sorry, but you need to defeat\n"
	.string "every$"

MossdeepCity_Gym_EventScript_CheckTrainers_Text_1:
# 724 "data/maps/MossdeepCity_Gym/scripts.pory"
	.string "Liza: trainer on this Gym before\n"
	.string "battling us$"
