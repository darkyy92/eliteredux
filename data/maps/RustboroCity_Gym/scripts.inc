# 1 "data/maps/RustboroCity_Gym/scripts.pory"

# 2 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_MapScripts:: @ 8212F30
# 3 "data/maps/RustboroCity_Gym/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Gym/scripts.pory"

# 5 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Roxanne::
# 6 "data/maps/RustboroCity_Gym/scripts.pory"
	call RustboroCity_Gym_EventScript_CheckTrainers //Make sure to call this before the Gym Leader Script
# 7 "data/maps/RustboroCity_Gym/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_ROXANNE, RustboroCity_Gym_EventScript_AlreadyRematched
# 8 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, RustboroCity_Gym_EventScript_RoxanneRematch
# 9 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
# 10 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq RustboroCity_Gym_EventScript_RoxanneRematch
# 11 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_Gym_EventScript_GiveRockTomb
# 12 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
# 13 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 14 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 15 "data/maps/RustboroCity_Gym/scripts.pory"

# 16 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneDefeated:: @ 8212F66
# 17 "data/maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_Text_ReceivedStoneBadge
# 18 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 19 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 20 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
# 21 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 22 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_BADGE01_GET
# 23 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 24 "data/maps/RustboroCity_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 25 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 26 "data/maps/RustboroCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 27 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 6
# 28 "data/maps/RustboroCity_Gym/scripts.pory"
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
# 29 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GiveRockTomb
# 30 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 31 "data/maps/RustboroCity_Gym/scripts.pory"

# 32 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneRematch::
# 33 "data/maps/RustboroCity_Gym/scripts.pory"
	message RustboroCity_Gym_Text_RoxanneChooseFormat
# 34 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 35 "data/maps/RustboroCity_Gym/scripts.pory"
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
# 36 "data/maps/RustboroCity_Gym/scripts.pory"
	switch VAR_RESULT
# 37 "data/maps/RustboroCity_Gym/scripts.pory"
	case 0, RustboroCity_Gym_EventScript_SetSingles
# 38 "data/maps/RustboroCity_Gym/scripts.pory"
	case 1, RustboroCity_Gym_EventScript_SetDoubles
# 39 "data/maps/RustboroCity_Gym/scripts.pory"
	case 2, RustboroCity_Gym_EventScript_Exit
# 40 "data/maps/RustboroCity_Gym/scripts.pory"
	case 127, RustboroCity_Gym_EventScript_Exit
# 41 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 42 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 43 "data/maps/RustboroCity_Gym/scripts.pory"

# 44 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_SetSingles::
# 45 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxanneAllowLegends, MSGBOX_YESNO
# 46 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 47 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq RustboroCity_Gym_EventScript_RoxanneSinglesRematch
# 48 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_3, RustboroCity_Gym_Text_RoxanneRematchDefeat
# 49 "data/maps/RustboroCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_ROXANNE
# 50 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 51 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 52 "data/maps/RustboroCity_Gym/scripts.pory"

# 53 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_SetDoubles::
# 54 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxanneAllowLegends, MSGBOX_YESNO
# 55 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 56 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq RustboroCity_Gym_EventScript_RoxanneDoublesRematch
# 57 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_5, RustboroCity_Gym_Text_RoxanneRematchDefeat
# 58 "data/maps/RustboroCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_ROXANNE
# 59 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 60 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 61 "data/maps/RustboroCity_Gym/scripts.pory"

# 62 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneSinglesRematch::
# 63 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_2, RustboroCity_Gym_Text_RoxanneRematchDefeat
# 64 "data/maps/RustboroCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_ROXANNE
# 65 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 66 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 67 "data/maps/RustboroCity_Gym/scripts.pory"

# 68 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RoxanneDoublesRematch::
# 69 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_4, RustboroCity_Gym_Text_RoxanneRematchDefeat
# 70 "data/maps/RustboroCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_ROXANNE
# 71 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 72 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 73 "data/maps/RustboroCity_Gym/scripts.pory"

# 74 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_AlreadyRematched::
# 75 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
# 76 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 77 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 78 "data/maps/RustboroCity_Gym/scripts.pory"

# 79 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Exit::
# 80 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 81 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 82 "data/maps/RustboroCity_Gym/scripts.pory"

# 83 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Josh:: @ 8212FE3
# 84 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
# 85 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
# 86 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 87 "data/maps/RustboroCity_Gym/scripts.pory"

# 88 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Tommy:: @ 8212FFA
# 89 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
# 90 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
# 91 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 92 "data/maps/RustboroCity_Gym/scripts.pory"

# 93 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_Marc:: @ 8213011
# 94 "data/maps/RustboroCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
# 95 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
# 96 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 97 "data/maps/RustboroCity_Gym/scripts.pory"

# 98 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuide:: @ 8213028
# 99 "data/maps/RustboroCity_Gym/scripts.pory"
	lock
# 100 "data/maps/RustboroCity_Gym/scripts.pory"
	faceplayer
# 101 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
# 102 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 103 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 104 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 105 "data/maps/RustboroCity_Gym/scripts.pory"

# 106 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymGuidePostVictory:: @ 821303D
# 107 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 108 "data/maps/RustboroCity_Gym/scripts.pory"
	release
# 109 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 110 "data/maps/RustboroCity_Gym/scripts.pory"

# 111 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_LeftGymStatue:: @ 8213047
# 112 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 113 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 114 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 115 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 116 "data/maps/RustboroCity_Gym/scripts.pory"

# 117 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RightGymStatue:: @ 8213057
# 118 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 119 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
# 120 "data/maps/RustboroCity_Gym/scripts.pory"
	goto RustboroCity_Gym_EventScript_GymStatue
# 121 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 122 "data/maps/RustboroCity_Gym/scripts.pory"

# 123 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatueCertified:: @ 8213067
# 124 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 125 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 126 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 127 "data/maps/RustboroCity_Gym/scripts.pory"

# 128 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_GymStatue:: @ 8213071
# 129 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 130 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 131 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 132 "data/maps/RustboroCity_Gym/scripts.pory"

# 133 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_EventScript_RegisterRoxanne:: @ 821307B
# 134 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 135 "data/maps/RustboroCity_Gym/scripts.pory"
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
# 136 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmessage
# 137 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 138 "data/maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 139 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 140 "data/maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 141 "data/maps/RustboroCity_Gym/scripts.pory"
	closemessage
# 142 "data/maps/RustboroCity_Gym/scripts.pory"
	delay 30
# 143 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 144 "data/maps/RustboroCity_Gym/scripts.pory"
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 145 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 146 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 147 "data/maps/RustboroCity_Gym/scripts.pory"

# 148 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Trigger1::
# 149 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 150 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_TEMP_1, 1
# 151 "data/maps/RustboroCity_Gym/scripts.pory"
	playse SE_PIN
# 152 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 153 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 154 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 155 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 156 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Rustboro_Gym_Guide_Move1
# 157 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 158 "data/maps/RustboroCity_Gym/scripts.pory"
	goto Rustboro_Gym_Guide_Speech
# 159 "data/maps/RustboroCity_Gym/scripts.pory"

# 160 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Trigger2::
# 161 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 162 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_TEMP_1, 2
# 163 "data/maps/RustboroCity_Gym/scripts.pory"
	playse SE_PIN
# 164 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 165 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 166 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 167 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 168 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Rustboro_Gym_Guide_Move2
# 169 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 170 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Rustboro_Gym_Player_Move2
# 171 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 172 "data/maps/RustboroCity_Gym/scripts.pory"
	goto Rustboro_Gym_Guide_Speech
# 173 "data/maps/RustboroCity_Gym/scripts.pory"

# 174 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Trigger3::
# 175 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 176 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_TEMP_1, 3
# 177 "data/maps/RustboroCity_Gym/scripts.pory"
	playse SE_PIN
# 178 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 179 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 180 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 181 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 182 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Rustboro_Gym_Guide_Move3
# 183 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 184 "data/maps/RustboroCity_Gym/scripts.pory"
	goto Rustboro_Gym_Guide_Speech
# 185 "data/maps/RustboroCity_Gym/scripts.pory"

# 186 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Trigger4::
# 187 "data/maps/RustboroCity_Gym/scripts.pory"
	lockall
# 188 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_TEMP_1, 4
# 189 "data/maps/RustboroCity_Gym/scripts.pory"
	playse SE_PIN
# 190 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 191 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 192 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 193 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 194 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Rustboro_Gym_Player_Move_Face
# 195 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Rustboro_Gym_Guide_Move4
# 196 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 197 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Rustboro_Gym_Player_Move4
# 198 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 199 "data/maps/RustboroCity_Gym/scripts.pory"
	goto Rustboro_Gym_Guide_Speech
# 200 "data/maps/RustboroCity_Gym/scripts.pory"

# 201 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Speech::
# 202 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_Tips, MSGBOX_DEFAULT
# 203 "data/maps/RustboroCity_Gym/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 1
# 204 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_TEMP_1, 1
# 205 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq Rustboro_Gym_Guide_Walk_Away1
# 206 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_TEMP_1, 2
# 207 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq Rustboro_Gym_Guide_Walk_Away2
# 208 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_TEMP_1, 3
# 209 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq Rustboro_Gym_Guide_Walk_Away3
# 210 "data/maps/RustboroCity_Gym/scripts.pory"
	compare VAR_TEMP_1, 4
# 211 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_eq Rustboro_Gym_Guide_Walk_Away4
# 212 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 213 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 214 "data/maps/RustboroCity_Gym/scripts.pory"

# 215 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Walk_Away1::
# 216 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Rustboro_Gym_Guide_Move5
# 217 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 218 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 219 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 220 "data/maps/RustboroCity_Gym/scripts.pory"

# 221 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Walk_Away2::
# 222 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Rustboro_Gym_Guide_Move6
# 223 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 224 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 225 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 226 "data/maps/RustboroCity_Gym/scripts.pory"

# 227 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Walk_Away3::
# 228 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Rustboro_Gym_Guide_Move7
# 229 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 230 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 231 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 232 "data/maps/RustboroCity_Gym/scripts.pory"

# 233 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Walk_Away4::
# 234 "data/maps/RustboroCity_Gym/scripts.pory"
	applymovement 4, Rustboro_Gym_Guide_Move8
# 235 "data/maps/RustboroCity_Gym/scripts.pory"
	waitmovement 0
# 236 "data/maps/RustboroCity_Gym/scripts.pory"
	releaseall
# 237 "data/maps/RustboroCity_Gym/scripts.pory"
	end
# 238 "data/maps/RustboroCity_Gym/scripts.pory"

# 239 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Move1::
# 240 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_down
# 241 "data/maps/RustboroCity_Gym/scripts.pory"
	face_right
# 242 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 243 "data/maps/RustboroCity_Gym/scripts.pory"

# 244 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Move2::
# 245 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_right
# 246 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 247 "data/maps/RustboroCity_Gym/scripts.pory"

# 248 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Move3::
# 249 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_right
# 250 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_right
# 251 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 252 "data/maps/RustboroCity_Gym/scripts.pory"

# 253 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Move4::
# 254 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_right
# 255 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_right
# 256 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_right
# 257 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_right
# 258 "data/maps/RustboroCity_Gym/scripts.pory"
	face_down
# 259 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 260 "data/maps/RustboroCity_Gym/scripts.pory"

# 261 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Player_Move2::
# 262 "data/maps/RustboroCity_Gym/scripts.pory"
	face_left
# 263 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 264 "data/maps/RustboroCity_Gym/scripts.pory"

# 265 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Player_Move4::
# 266 "data/maps/RustboroCity_Gym/scripts.pory"
	face_up
# 267 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 268 "data/maps/RustboroCity_Gym/scripts.pory"

# 269 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Player_Move_Face::
# 270 "data/maps/RustboroCity_Gym/scripts.pory"
	face_left
# 271 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 272 "data/maps/RustboroCity_Gym/scripts.pory"

# 273 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Move5::
# 274 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_up
# 275 "data/maps/RustboroCity_Gym/scripts.pory"
	face_down
# 276 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 277 "data/maps/RustboroCity_Gym/scripts.pory"

# 278 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Move6::
# 279 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_left
# 280 "data/maps/RustboroCity_Gym/scripts.pory"
	face_down
# 281 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 282 "data/maps/RustboroCity_Gym/scripts.pory"

# 283 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Move7::
# 284 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_left
# 285 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_left
# 286 "data/maps/RustboroCity_Gym/scripts.pory"
	face_down
# 287 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 288 "data/maps/RustboroCity_Gym/scripts.pory"

# 289 "data/maps/RustboroCity_Gym/scripts.pory"
Rustboro_Gym_Guide_Move8::
# 290 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_left
# 291 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_left
# 292 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_left
# 293 "data/maps/RustboroCity_Gym/scripts.pory"
	walk_left
# 294 "data/maps/RustboroCity_Gym/scripts.pory"
	face_down
# 295 "data/maps/RustboroCity_Gym/scripts.pory"
	step_end
# 296 "data/maps/RustboroCity_Gym/scripts.pory"

# 297 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_Tips::
# 298 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Yo, how's it going?\p"
# 299 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Listen, my friend!\n"
# 300 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you like to become the Champion?\p"
# 301 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm no Trainer, not me, but I can\n"
# 302 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "sure give you winning advice.\p"
# 303 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's settled, then! We'll aim for the\n"
# 304 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Pokémon Championship together!\p"
# 305 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It's your job as a Trainer to collect\n"
# 306 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Gym Badges, am I right?\p"
# 307 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "But Gym Leaders aren't pushovers!\p"
# 308 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "And that's where I come in!\n"
# 309 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm here to provide expert advice!\p"
# 310 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne, the Gym Leader, is a user\n"
# 311 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "of Rock-type Pokémon.\p"
# 312 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "She has a full team of six, with good\n"
# 313 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "type variety.\p"
# 314 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Remember to use an Eviolite on\n"
# 315 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "bulky Pokémon, which gives you a\l"
# 316 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "better chance to withstand Roxanne.\p"
# 317 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Come see me afterwards, if you beat\n"
# 318 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the Gym Leader.$"
# 319 "data/maps/RustboroCity_Gym/scripts.pory"

# 320 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuideAdvice::
# 321 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's all I've got for now,\n"
# 322 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Champ-to-be!\p"
# 323 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you want more advice, I\n"
# 324 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "suggest bringing as many Pokémon\l"
# 325 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "as you can!\p"
# 326 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You could also ask around the town.\p"
# 327 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "People might have something that\n"
# 328 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "could help you, like a Steel-type\l"
# 329 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Pokémon they're willing to trade!$"
# 330 "data/maps/RustboroCity_Gym/scripts.pory"

# 331 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymGuidePostVictory: @ 82132E2
# 332 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Whoa! What a breathtaking victory!\n"
# 333 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My cheering must've worked!\p"
# 334 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Great!\n"
# 335 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Check your Trainer Card.\p"
# 336 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The Stone Badge you got should be\n"
# 337 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "properly recorded on it.\p"
# 338 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "In other words…\p"
# 339 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You've climbed the first step on\n"
# 340 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the stairs to the Championship!\p"
# 341 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That's got to feel awesome!$"
# 342 "data/maps/RustboroCity_Gym/scripts.pory"

# 343 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshIntro: @ 82133E9
# 344 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Don't take us Gym Trainers lightly!\n"
# 345 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'll show you why we're better!$"
# 346 "data/maps/RustboroCity_Gym/scripts.pory"

# 347 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshDefeat: @ 821342D
# 348 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You were too good for me…$"
# 349 "data/maps/RustboroCity_Gym/scripts.pory"

# 350 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_JoshPostBattle: @ 8213447
# 351 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You haven't seen anything of the Rock\n"
# 352 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "type's terrifying power!$"
# 353 "data/maps/RustboroCity_Gym/scripts.pory"

# 354 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyIntro: @ 8213486
# 355 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you can't beat me, you won't stand\n"
# 356 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "a chance against Roxanne!$"
# 357 "data/maps/RustboroCity_Gym/scripts.pory"

# 358 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyDefeat: @ 82134C6
# 359 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Wow! You've got some potential!$"
# 360 "data/maps/RustboroCity_Gym/scripts.pory"

# 361 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_TommyPostBattle: @ 82134E6
# 362 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne is stronger than me by\n"
# 363 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "several times.\p"
# 364 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You'd better be on your guard!$"
# 365 "data/maps/RustboroCity_Gym/scripts.pory"

# 366 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcIntro: @ 8213533
# 367 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "We might be in the middle of town,\n"
# 368 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "but so what?\p"
# 369 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "My Rock Pokémon need room to\n"
# 370 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rampage!$"
# 371 "data/maps/RustboroCity_Gym/scripts.pory"

# 372 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcDefeat: @ 8213589
# 373 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Oh, man oh man!\n"
# 374 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Our challenger is one feisty customer!$"
# 375 "data/maps/RustboroCity_Gym/scripts.pory"

# 376 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_MarcPostBattle: @ 82135C0
# 377 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I have to hand it to our Leader.\p"
# 378 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It took smarts and sense for her to\n"
# 379 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "pick the Rock type at her young age.$"
# 380 "data/maps/RustboroCity_Gym/scripts.pory"

# 381 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneIntro: @ 821362A
# 382 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Hello, I am Roxanne, the Rustboro\n"
# 383 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Pokémon Gym Leader.\p"
# 384 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I became a Gym Leader so that I might\n"
# 385 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "apply what I learned at the Pokémon\l"
# 386 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Trainer's School in battle.\p"
# 387 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you kindly demonstrate how you\n"
# 388 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battle, and with which Pokémon?$"
# 389 "data/maps/RustboroCity_Gym/scripts.pory"

# 390 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneDefeat: @ 821370B
# 391 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "So…\n"
# 392 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I lost…\p"
# 393 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It seems that I still have much more\n"
# 394 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "to learn…\p"
# 395 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I understand.\p"
# 396 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The Pokémon League's rules state\n"
# 397 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that Trainers are to be given this\l"
# 398 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "if they defeat a Gym Leader.\p"
# 399 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please accept the official Pokémon\n"
# 400 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "League Stone Badge.$"
# 401 "data/maps/RustboroCity_Gym/scripts.pory"

# 402 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ReceivedStoneBadge: @ 82137EC
# 403 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} received the Stone Badge\n"
# 404 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "from Roxanne.$"
# 405 "data/maps/RustboroCity_Gym/scripts.pory"

# 406 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_StoneBadgeInfoTakeThis: @ 8213816
# 407 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "The Stone Badge enables your Pokémon\n"
# 408 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "to use the HM move Cut outside\l"
# 409 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "of battle.$"
# 410 "data/maps/RustboroCity_Gym/scripts.pory"

# 411 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_ExplainRockTomb: @ 82138B1
# 412 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That Technical Machine, TM39,\n"
# 413 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "contains Rock Tomb.\p"
# 414 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "It not only inflicts damage by dropping\n"
# 415 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "rocks, it also lowers Speed.\p"
# 416 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "If you use a TM, it instantly teaches\n"
# 417 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "the move to a Pokémon.\p"
# 418 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You can use a TM as many times as you\n"
# 419 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "want, so please try it out!$"
# 420 "data/maps/RustboroCity_Gym/scripts.pory"

# 421 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostBattle: @ 82139A7
# 422 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Since you are so strong, you should\n"
# 423 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "challenge the other Gym Leaders.\p"
# 424 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "By battling many Trainers, you'll\n"
# 425 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "learn many things.$"
# 426 "data/maps/RustboroCity_Gym/scripts.pory"

# 427 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatue: @ 8213A21
# 428 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Rustboro City Pokémon Gym$"
# 429 "data/maps/RustboroCity_Gym/scripts.pory"

# 430 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_GymStatueCertified: @ 8213A3B
# 431 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Rustboro City Pokémon Gym\p"
# 432 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne's certified Trainers:\n"
# 433 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 434 "data/maps/RustboroCity_Gym/scripts.pory"

# 435 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRegisterCall: @ 8213A76
# 436 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 437 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Beep!\p"
# 438 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: Oh, hello, {PLAYER}?\n"
# 439 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "This is Roxanne of Rustboro City.\p"
# 440 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I heard from Brawly that you're\n"
# 441 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "moving up through the ranks of\l"
# 442 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Trainers at an incredible pace.\p"
# 443 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Well, I'd rather not think that\n"
# 444 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I can't beat you.\p"
# 445 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I promise, I will shape up my Gym\n"
# 446 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "so that you may challenge us again.\p"
# 447 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I hope you'll be looking forward to\n"
# 448 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "that occasion as much as me!\p"
# 449 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … …\n"
# 450 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "… … … … … Click!$"
# 451 "data/maps/RustboroCity_Gym/scripts.pory"

# 452 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RegisteredRoxanne: @ 8213C01
# 453 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Registered Gym Leader Roxanne\n"
# 454 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "in the PokéNav.$"
# 455 "data/maps/RustboroCity_Gym/scripts.pory"

# 456 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePreRematch: @ 8213C2F
# 457 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: Let us battle!$"
# 458 "data/maps/RustboroCity_Gym/scripts.pory"

# 459 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchDefeat: @ 8213CF9
# 460 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Grr…\n"
# 461 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Again, I have lost…$"
# 462 "data/maps/RustboroCity_Gym/scripts.pory"

# 463 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxannePostRematch: @ 8213D12
# 464 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: I still have much to learn\n"
# 465 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "when it comes to battling Pokémon.\p"
# 466 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "That awareness makes me love battling\n"
# 467 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "all that much more!$"
# 468 "data/maps/RustboroCity_Gym/scripts.pory"

# 469 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons: @ 8213D93
# 470 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: Oh, no…\n"
# 471 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "You only have one Pokémon with you?\p"
# 472 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Please return with at least one more\n"
# 473 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Pokémon.$"
# 474 "data/maps/RustboroCity_Gym/scripts.pory"

# 475 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneChooseFormat:
# 476 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: I'm so glad to see you again.\n"
# 477 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm Roxanne, the Gym Leader here.\p"
# 478 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I'm sure we've both experienced many\n"
# 479 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "battles since we last met.\p"
# 480 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "I would like to see how much better\n"
# 481 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "we've become.\p"
# 482 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Would you prefer a single battle\n"
# 483 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "or a double battle?$"
# 484 "data/maps/RustboroCity_Gym/scripts.pory"

# 485 "data/maps/RustboroCity_Gym/scripts.pory"
RustboroCity_Gym_Text_RoxanneAllowLegends:
# 486 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "And would you like me to battle with\n"
# 487 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Legendary Pokémon?$"

RustboroCity_Gym_EventScript_GiveRockTomb::
# 490 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GiveRockTomb_Text_0
# 491 "data/maps/RustboroCity_Gym/scripts.pory"
	givecustommon SPECIES_AMAURA, 14, ITEM_CHOPLE_BERRY, ITEM_CHERISH_BALL, NATURE_BOLD, 0, 252, 0, 4, 0, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_FREEZE_DRY, MOVE_THUNDER_WAVE, MOVE_ANCIENT_POWER, MOVE_HYPER_VOICE, TRUE
# 492 "data/maps/RustboroCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 493 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GiveRockTomb_Text_1
# 494 "data/maps/RustboroCity_Gym/scripts.pory"
	waitfanfare
# 495 "data/maps/RustboroCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM39
# 496 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
# 497 "data/maps/RustboroCity_Gym/scripts.pory"
	release
	end


RustboroCity_Gym_EventScript_CheckTrainers::
# 503 "data/maps/RustboroCity_Gym/scripts.pory"
	checktrainerflag TRAINER_JOSH
	goto_if 0, RustboroCity_Gym_EventScript_CheckTrainers_3
# 504 "data/maps/RustboroCity_Gym/scripts.pory"
	checktrainerflag TRAINER_TOMMY
	goto_if 0, RustboroCity_Gym_EventScript_CheckTrainers_3
# 505 "data/maps/RustboroCity_Gym/scripts.pory"
	checktrainerflag TRAINER_MARC
	goto_if 0, RustboroCity_Gym_EventScript_CheckTrainers_3
RustboroCity_Gym_EventScript_CheckTrainers_2:
	return

RustboroCity_Gym_EventScript_CheckTrainers_1:
# 507 "data/maps/RustboroCity_Gym/scripts.pory"
	msgbox RustboroCity_Gym_EventScript_CheckTrainers_Text_0, MSGBOX_NPC
# 508 "data/maps/RustboroCity_Gym/scripts.pory"
	release
	end

RustboroCity_Gym_EventScript_CheckTrainers_3:
# 506 "data/maps/RustboroCity_Gym/scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_CheckTrainers_1
	goto RustboroCity_Gym_EventScript_CheckTrainers_2


RustboroCity_Gym_EventScript_GiveRockTomb_Text_0:
# 490 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Take this special Pokémon as a gift\n"
	.string "from me!$"

RustboroCity_Gym_EventScript_GiveRockTomb_Text_1:
# 493 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "{PLAYER} got Roxanne's {COLOR BLUE}Amaura{COLOR DARK_GRAY} as a\n"
	.string "gift!$"

RustboroCity_Gym_EventScript_CheckTrainers_Text_0:
# 507 "data/maps/RustboroCity_Gym/scripts.pory"
	.string "Roxanne: Sorry, but you need to defeat\n"
	.string "every trainer on this Gym before\l"
	.string "battling me.$"
