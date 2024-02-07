# 1 "data/maps/DewfordTown_Gym/scripts.pory"

# 2 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_MapScripts:: @ 81FC63C
# 3 "data/maps/DewfordTown_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
# 4 "data/maps/DewfordTown_Gym/scripts.pory"
	.byte 0
# 5 "data/maps/DewfordTown_Gym/scripts.pory"

# 6 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_OnTransition: @ 81FC642
# 7 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashRadius
# 8 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 9 "data/maps/DewfordTown_Gym/scripts.pory"

# 10 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashRadius:: @ 81FC648
# 11 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
# 12 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 13 "data/maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 14 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 0
# 15 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius7
# 16 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 1
# 17 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius6
# 18 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 2
# 19 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius5
# 20 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 3
# 21 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius4
# 22 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 4
# 23 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius3
# 24 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 5
# 25 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius2
# 26 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_SetFlashRadius1
# 27 "data/maps/DewfordTown_Gym/scripts.pory"

# 28 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetLightsOn:: @ 81FC6A2
# 29 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashradius 0
# 30 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 31 "data/maps/DewfordTown_Gym/scripts.pory"

# 32 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashRadius1:: @ 81FC6A6
# 33 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashradius 1
# 34 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 35 "data/maps/DewfordTown_Gym/scripts.pory"

# 36 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashRadius2:: @ 81FC6AA
# 37 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashradius 2
# 38 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 39 "data/maps/DewfordTown_Gym/scripts.pory"

# 40 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashRadius3:: @ 81FC6AE
# 41 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashradius 3
# 42 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 43 "data/maps/DewfordTown_Gym/scripts.pory"

# 44 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashRadius4:: @ 81FC6B2
# 45 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashradius 4
# 46 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 47 "data/maps/DewfordTown_Gym/scripts.pory"

# 48 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashRadius5:: @ 81FC6B6
# 49 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashradius 5
# 50 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 51 "data/maps/DewfordTown_Gym/scripts.pory"

# 52 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashRadius6:: @ 81FC6BA
# 53 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashradius 6
# 54 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 55 "data/maps/DewfordTown_Gym/scripts.pory"

# 56 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashRadius7:: @ 81FC6BE
# 57 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashradius 7
# 58 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 59 "data/maps/DewfordTown_Gym/scripts.pory"

# 60 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrightenRoom:: @ 81FC6C2
# 61 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 62 "data/maps/DewfordTown_Gym/scripts.pory"
	nop1
# 63 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, VAR_0x8001
# 64 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_NoLightChange
# 65 "data/maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 66 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 1
# 67 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash1Trainer
# 68 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 2
# 69 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash2Trainers
# 70 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 3
# 71 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash3Trainers
# 72 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 4
# 73 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash4Trainers
# 74 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 5
# 75 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash5Trainers
# 76 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_0x8000, 6
# 77 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash6Trainers
# 78 "data/maps/DewfordTown_Gym/scripts.pory"

# 79 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_NoLightChange:: @ 81FC71A
# 80 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 81 "data/maps/DewfordTown_Gym/scripts.pory"

# 82 "data/maps/DewfordTown_Gym/scripts.pory"
@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
# 83 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash1Trainer:: @ 81FC71B
# 84 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 85 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 6
# 86 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashRadius
# 87 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 88 "data/maps/DewfordTown_Gym/scripts.pory"

# 89 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash2Trainers:: @ 81FC726
# 90 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 91 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 5
# 92 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashRadius
# 93 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 94 "data/maps/DewfordTown_Gym/scripts.pory"

# 95 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash3Trainers:: @ 81FC731
# 96 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 97 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 4
# 98 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashRadius
# 99 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 100 "data/maps/DewfordTown_Gym/scripts.pory"

# 101 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash4Trainers:: @ 81FC73C
# 102 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 103 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 3
# 104 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashRadius
# 105 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 106 "data/maps/DewfordTown_Gym/scripts.pory"

# 107 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash5Trainers:: @ 81FC747
# 108 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 109 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 2
# 110 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashRadius
# 111 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 112 "data/maps/DewfordTown_Gym/scripts.pory"

# 113 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash6Trainers:: @ 81FC752
# 114 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 115 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 1
# 116 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashRadius
# 117 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 118 "data/maps/DewfordTown_Gym/scripts.pory"

# 119 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlashFullBrightness:: @ 81FC75D
# 120 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 121 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 0
# 122 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashRadius
# 123 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 124 "data/maps/DewfordTown_Gym/scripts.pory"

# 125 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CountTrainersDefeated:: @ 81FC768
# 126 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8000, 0
# 127 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
# 128 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 129 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckJocelyn:: @ 81FC77B
# 130 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
# 131 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 132 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLaura:: @ 81FC789
# 133 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
# 134 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 135 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckBrenden:: @ 81FC797
# 136 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
# 137 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 138 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckCristian:: @ 81FC7A5
# 139 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
# 140 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 141 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLilith:: @ 81FC7B3
# 142 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
# 143 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 144 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_StopCountingTrainers:: @ 81FC7C1
# 145 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 146 "data/maps/DewfordTown_Gym/scripts.pory"

# 147 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brawly:: @ 81FC7C2
# 148 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CheckTrainers
# 149 "data/maps/DewfordTown_Gym/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_BRAWLY, DewfordTown_Gym_EventScript_AlreadyRematched
# 150 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, DewfordTown_Gym_EventScript_BrawlyRematch
# 151 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
# 152 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM08, DewfordTown_Gym_EventScript_GiveBulkUp
# 153 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
# 154 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 155 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 156 "data/maps/DewfordTown_Gym/scripts.pory"

# 157 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyDefeated:: @ 81FC7F7
# 158 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
# 159 "data/maps/DewfordTown_Gym/scripts.pory"
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
# 160 "data/maps/DewfordTown_Gym/scripts.pory"
	waitmessage
# 161 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 162 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
# 163 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 164 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_BADGE02_GET
# 165 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
# 166 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 167 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 6
# 168 "data/maps/DewfordTown_Gym/scripts.pory"
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
# 169 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 170 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 171 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_GiveBulkUp
# 172 "data/maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 173 "data/maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 174 "data/maps/DewfordTown_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 175 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
# 176 "data/maps/DewfordTown_Gym/scripts.pory"
	waitfanfare
# 177 "data/maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 178 "data/maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 179 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
# 180 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 181 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 182 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 183 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 184 "data/maps/DewfordTown_Gym/scripts.pory"

# 185 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyRematch::
# 186 "data/maps/DewfordTown_Gym/scripts.pory"
	message DewfordTown_Gym_Text_BrawlyChooseFormat
# 187 "data/maps/DewfordTown_Gym/scripts.pory"
	waitmessage
# 188 "data/maps/DewfordTown_Gym/scripts.pory"
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
# 189 "data/maps/DewfordTown_Gym/scripts.pory"
	switch VAR_RESULT
# 190 "data/maps/DewfordTown_Gym/scripts.pory"
	case 0, DewfordTown_Gym_EventScript_SetSingles
# 191 "data/maps/DewfordTown_Gym/scripts.pory"
	case 1, DewfordTown_Gym_EventScript_SetDoubles
# 192 "data/maps/DewfordTown_Gym/scripts.pory"
	case 2, DewfordTown_Gym_EventScript_Exit
# 193 "data/maps/DewfordTown_Gym/scripts.pory"
	case 127, DewfordTown_Gym_EventScript_Exit
# 194 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 195 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 196 "data/maps/DewfordTown_Gym/scripts.pory"

# 197 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetSingles::
# 198 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyAllowLegends, MSGBOX_YESNO
# 199 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 200 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_BrawlySinglesRematch
# 201 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_3, DewfordTown_Gym_Text_BrawlyRematchDefeat
# 202 "data/maps/DewfordTown_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_BRAWLY
# 203 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 204 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 205 "data/maps/DewfordTown_Gym/scripts.pory"

# 206 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetDoubles::
# 207 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyAllowLegends, MSGBOX_YESNO
# 208 "data/maps/DewfordTown_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 209 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq DewfordTown_Gym_EventScript_BrawlyDoublesRematch
# 210 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_5, DewfordTown_Gym_Text_BrawlyRematchDefeat
# 211 "data/maps/DewfordTown_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_BRAWLY
# 212 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 213 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 214 "data/maps/DewfordTown_Gym/scripts.pory"

# 215 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlySinglesRematch::
# 216 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_2, DewfordTown_Gym_Text_BrawlyRematchDefeat
# 217 "data/maps/DewfordTown_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_BRAWLY
# 218 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 219 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 220 "data/maps/DewfordTown_Gym/scripts.pory"

# 221 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyDoublesRematch::
# 222 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_4, DewfordTown_Gym_Text_BrawlyRematchDefeat
# 223 "data/maps/DewfordTown_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_BRAWLY
# 224 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 225 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 226 "data/maps/DewfordTown_Gym/scripts.pory"

# 227 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AlreadyRematched::
# 228 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
# 229 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 230 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 231 "data/maps/DewfordTown_Gym/scripts.pory"

# 232 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Exit::
# 233 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 234 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 235 "data/maps/DewfordTown_Gym/scripts.pory"

# 236 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Takao:: @ 81FC8B7
# 237 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
# 238 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
# 239 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 240 "data/maps/DewfordTown_Gym/scripts.pory"

# 241 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_TakaoBrightenRoom:: @ 81FC8D2
# 242 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 243 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 244 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 245 "data/maps/DewfordTown_Gym/scripts.pory"

# 246 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Jocelyn:: @ 81FC8D9
# 247 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
# 248 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
# 249 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 250 "data/maps/DewfordTown_Gym/scripts.pory"

# 251 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_JocelynBrightenRoom:: @ 81FC8F4
# 252 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 253 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 254 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 255 "data/maps/DewfordTown_Gym/scripts.pory"

# 256 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Laura:: @ 81FC8FB
# 257 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
# 258 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
# 259 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 260 "data/maps/DewfordTown_Gym/scripts.pory"

# 261 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LauraBrightenRoom:: @ 81FC916
# 262 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 263 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 264 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 265 "data/maps/DewfordTown_Gym/scripts.pory"

# 266 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brenden:: @ 81FC91D
# 267 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
# 268 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
# 269 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 270 "data/maps/DewfordTown_Gym/scripts.pory"

# 271 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrendenBrightenRoom:: @ 81FC938
# 272 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 273 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 274 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 275 "data/maps/DewfordTown_Gym/scripts.pory"

# 276 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Cristian:: @ 81FC93F
# 277 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
# 278 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
# 279 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 280 "data/maps/DewfordTown_Gym/scripts.pory"

# 281 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CristianBrightenRoom:: @ 81FC95A
# 282 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 283 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 284 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 285 "data/maps/DewfordTown_Gym/scripts.pory"

# 286 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Lilith:: @ 81FC961
# 287 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
# 288 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
# 289 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 290 "data/maps/DewfordTown_Gym/scripts.pory"

# 291 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LilithBrightenRoom:: @ 81FC97C
# 292 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 293 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 294 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 295 "data/maps/DewfordTown_Gym/scripts.pory"

# 296 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuide:: 
# 297 "data/maps/DewfordTown_Gym/scripts.pory"
	lock
# 298 "data/maps/DewfordTown_Gym/scripts.pory"
	faceplayer
# 299 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
# 300 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_Guide2, MSGBOX_DEFAULT
# 301 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 302 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 303 "data/maps/DewfordTown_Gym/scripts.pory"

# 304 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Guide2::
# 305 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_Guide2, MSGBOX_DEFAULT
# 306 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 307 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 308 "data/maps/DewfordTown_Gym/scripts.pory"

# 309 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuidePostVictory:: @ 81FC998
# 310 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 311 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 312 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 313 "data/maps/DewfordTown_Gym/scripts.pory"

# 314 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LeftGymStatue:: @ 81FC9A2
# 315 "data/maps/DewfordTown_Gym/scripts.pory"
	lockall
# 316 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 317 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 318 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 319 "data/maps/DewfordTown_Gym/scripts.pory"

# 320 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_RightGymStatue:: @ 81FC9B2
# 321 "data/maps/DewfordTown_Gym/scripts.pory"
	lockall
# 322 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 323 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 324 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 325 "data/maps/DewfordTown_Gym/scripts.pory"

# 326 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatueCertified:: @ 81FC9C2
# 327 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 328 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 329 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 330 "data/maps/DewfordTown_Gym/scripts.pory"

# 331 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatue:: @ 81FC9CC
# 332 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 333 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 334 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 335 "data/maps/DewfordTown_Gym/scripts.pory"

# 336 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_Guide1::
# 337 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, how's it going, Champion-\n"
# 338 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "bound {PLAYER}?$"
# 339 "data/maps/DewfordTown_Gym/scripts.pory"

# 340 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_Guide2::
# 341 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Dewford's Gym Leader Brawly commands\n"
# 342 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Fighting-type Pokémon.\p"
# 343 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "His strongest Pokémon is his Hitmonchan,\n"
# 344 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "and the rest of his team are no joke!\p"
# 345 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Bringing a Ghost-type Pokémon\n"
# 346 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "could give you an advantage.\p"
# 347 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You can find some in Granite Cave,\n"
# 348 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Petalburg Woods or Dewford Manor.\p"
# 349 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Also, the Gym is as dark as the\n"
# 350 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "ocean floor.\p"
# 351 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But it will get brighter after defeating\n"
# 352 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "the Trainers in your way.\p"
# 353 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, okay, go for it!$"
# 354 "data/maps/DewfordTown_Gym/scripts.pory"

# 355 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuidePostVictory: @ 81FCB5C
# 356 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah! It's turned too bright in here!\p"
# 357 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your future is bright, too!$"
# 358 "data/maps/DewfordTown_Gym/scripts.pory"

# 359 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoIntro: @ 81FCB9F
# 360 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Might is right!\n"
# 361 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Come on!$"
# 362 "data/maps/DewfordTown_Gym/scripts.pory"

# 363 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoDefeat: @ 81FCBB8
# 364 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Not enough power…$"
# 365 "data/maps/DewfordTown_Gym/scripts.pory"

# 366 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoPostBattle: @ 81FCBCA
# 367 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your skill overcame my strength!\n"
# 368 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your technique is commendable!$"
# 369 "data/maps/DewfordTown_Gym/scripts.pory"

# 370 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynIntro: @ 81FCC0A
# 371 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "There's no need for Brawly to be\n"
# 372 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "involved!\p"
# 373 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll crush you!$"
# 374 "data/maps/DewfordTown_Gym/scripts.pory"

# 375 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynDefeat: @ 81FCC45
# 376 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But… How?\n"
# 377 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "How could I lose so easily?$"
# 378 "data/maps/DewfordTown_Gym/scripts.pory"

# 379 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynPostBattle: @ 81FCC6B
# 380 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm not going to waste this loss.\n"
# 381 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll use it to motivate me to train!\p"
# 382 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "One day I'll become a Gym Leader…\p"
# 383 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "No, I'll become the Pokémon League\n"
# 384 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Champion!$"
# 385 "data/maps/DewfordTown_Gym/scripts.pory"

# 386 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraIntro: @ 81FCD01
# 387 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Don't you dare brush me off!\n"
# 388 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's not my fault if you cry!$"
# 389 "data/maps/DewfordTown_Gym/scripts.pory"

# 390 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraDefeat: @ 81FCD3C
# 391 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Waaaaaaah!\n"
# 392 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I lost!$"
# 393 "data/maps/DewfordTown_Gym/scripts.pory"

# 394 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraPostBattle: @ 81FCD4F
# 395 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I battle in the dark to make my heart\n"
# 396 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "stronger.\p"
# 397 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But because it's so dark, I can never\n"
# 398 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "see Brawly's face…$"
# 399 "data/maps/DewfordTown_Gym/scripts.pory"

# 400 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithIntro: @ 81FCDB8
# 401 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Ufufu…\n"
# 402 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Are you stumbling around in the dark?$"
# 403 "data/maps/DewfordTown_Gym/scripts.pory"

# 404 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithDefeat: @ 81FCDE5
# 405 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, you…\n"
# 406 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I don't want to know you!$"
# 407 "data/maps/DewfordTown_Gym/scripts.pory"

# 408 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithPostBattle: @ 81FCE08
# 409 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You deserve to stay lost and end up\n"
# 410 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "back at the entrance again!$"
# 411 "data/maps/DewfordTown_Gym/scripts.pory"

# 412 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenIntro: @ 81FCE48
# 413 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll show you the gumption of\n"
# 414 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "a sailing man!$"
# 415 "data/maps/DewfordTown_Gym/scripts.pory"

# 416 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenDefeat: @ 81FCE75
# 417 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "How'd this happen?\n"
# 418 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's not like me to lose this way!$"
# 419 "data/maps/DewfordTown_Gym/scripts.pory"

# 420 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenPostBattle: @ 81FCEAB
# 421 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, aye! You're worthy of seeing\n"
# 422 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "our Gym Leader.$"
# 423 "data/maps/DewfordTown_Gym/scripts.pory"

# 424 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianIntro: @ 81FCEDC
# 425 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If you mean to pass, it has to be\n"
# 426 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "through me!$"
# 427 "data/maps/DewfordTown_Gym/scripts.pory"

# 428 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianDefeat: @ 81FCF0A
# 429 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Grrrrr!\n"
# 430 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Vastly overpowered!$"
# 431 "data/maps/DewfordTown_Gym/scripts.pory"

# 432 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianPostBattle: @ 81FCF26
# 433 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You win!\n"
# 434 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Go after that Badge!$"
# 435 "data/maps/DewfordTown_Gym/scripts.pory"

# 436 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyIntro: @ 81FCF44
# 437 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm Brawly!\n"
# 438 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Dewford's Gym Leader!\p"
# 439 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I've been churned in the rough waves\n"
# 440 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "of these parts, and I've grown tough\l"
# 441 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "in the pitch-black cave!\p"
# 442 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "So you wanted to challenge me?\n"
# 443 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Let me see what you're made of!$"
# 444 "data/maps/DewfordTown_Gym/scripts.pory"

# 445 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyDefeat: @ 81FD008
# 446 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah, wow! You made a much bigger\n"
# 447 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "splash than I expected!\p"
# 448 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You swamped me!\p"
# 449 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Okay, you've got me.\n"
# 450 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Take this Gym Badge!$"
# 451 "data/maps/DewfordTown_Gym/scripts.pory"

# 452 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ReceivedKnuckleBadge: @ 81FD07D
# 453 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER} received the Knuckle Badge\n"
# 454 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "from Brawly.$"
# 455 "data/maps/DewfordTown_Gym/scripts.pory"

# 456 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis: @ 81FD0A8
# 457 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "The Knuckle Badge makes all Pokémon\n"
# 458 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "up to Level 40, even those you get in\l"
# 459 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "trades, obey without question.\p"
# 460 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "And, you'll be able to use the HM move\n"
# 461 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Flash outside of battle.\p"
# 462 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, yeah. You don't need to teach a\n"
# 463 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Pokémon Flash to use it.\p"
# 464 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If your Pokémon can learn Flash, it\n"
# 465 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "can always use it outside of battle.\p"
# 466 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If you'd like, you can have\n"
# 467 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "my amazing Hitmonchan, too.$"
# 468 "data/maps/DewfordTown_Gym/scripts.pory"

# 469 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_RegisteredBrawly: @ 81FD1E0
# 470 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Registered Gym Leader Brawly\n"
# 471 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "in the PokéNav.$"
# 472 "data/maps/DewfordTown_Gym/scripts.pory"

# 473 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostBattle: @ 81FD20D
# 474 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I can see your talent becoming a giant\n"
# 475 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "wave to cause a storm of astonishment\l"
# 476 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "among Trainers one day!$"
# 477 "data/maps/DewfordTown_Gym/scripts.pory"

# 478 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatue: @ 81FD272
# 479 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Dewford Town Pokémon Gym$"
# 480 "data/maps/DewfordTown_Gym/scripts.pory"

# 481 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatueCertified: @ 81FD28B
# 482 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Dewford Town Pokémon Gym\p"
# 483 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Brawly's certified Trainers:\n"
# 484 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER}$"
# 485 "data/maps/DewfordTown_Gym/scripts.pory"

# 486 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPreRematch: @ 81FD2C4
# 487 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Brawly: Show me how much higher\n"
# 488 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "you've gone!$"
# 489 "data/maps/DewfordTown_Gym/scripts.pory"

# 490 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchDefeat: @ 81FD367
# 491 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Wow!\n"
# 492 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Swamped again!$"
# 493 "data/maps/DewfordTown_Gym/scripts.pory"

# 494 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostRematch: @ 81FD37B
# 495 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Brawly: Battling is vast and it's deep.\n"
# 496 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You can't see the bottom.\l"
# 497 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's just like the sea of Hoenn!$"
# 498 "data/maps/DewfordTown_Gym/scripts.pory"

# 499 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons: @ 81FD3DE
# 500 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh? You only have one Pokémon\n"
# 501 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "that can battle.\p"
# 502 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm sorry, but I'd like you to come back\n"
# 503 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "with at least two Pokémon.$"
# 504 "data/maps/DewfordTown_Gym/scripts.pory"

# 505 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyChooseFormat:
# 506 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Brawly: A wave may draw back, but it\n"
# 507 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 508 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 509 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 510 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "So, you want our rematch to be a\n"
# 511 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "single battle or a double battle?$"
# 512 "data/maps/DewfordTown_Gym/scripts.pory"

# 513 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyAllowLegends:
# 514 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Brawly: And how about battling my\n"
# 515 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Legendary Pokémon? Think you're up\l"
# 516 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "to the challenge?$"

DewfordTown_Gym_EventScript_GiveBulkUp::
# 519 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_EventScript_GiveBulkUp_Text_0
# 520 "data/maps/DewfordTown_Gym/scripts.pory"
	givecustommon SPECIES_HITMONCHAN, 20, ITEM_COBA_BERRY, ITEM_CHERISH_BALL, NATURE_JOLLY, 2, 4, 252, 0, 252, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_DRAIN_PUNCH, MOVE_RAPID_SPIN, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, FALSE
# 521 "data/maps/DewfordTown_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 522 "data/maps/DewfordTown_Gym/scripts.pory"
	message DewfordTown_Gym_EventScript_GiveBulkUp_Text_1
# 523 "data/maps/DewfordTown_Gym/scripts.pory"
	waitfanfare
# 524 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM08
# 525 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
# 526 "data/maps/DewfordTown_Gym/scripts.pory"
	release
	end


DewfordTown_Gym_EventScript_CheckTrainers::
# 532 "data/maps/DewfordTown_Gym/scripts.pory"
	checktrainerflag TRAINER_TAKAO
	goto_if 0, DewfordTown_Gym_EventScript_CheckTrainers_3
# 533 "data/maps/DewfordTown_Gym/scripts.pory"
	checktrainerflag TRAINER_JOCELYN
	goto_if 0, DewfordTown_Gym_EventScript_CheckTrainers_3
# 534 "data/maps/DewfordTown_Gym/scripts.pory"
	checktrainerflag TRAINER_LAURA
	goto_if 0, DewfordTown_Gym_EventScript_CheckTrainers_3
# 535 "data/maps/DewfordTown_Gym/scripts.pory"
	checktrainerflag TRAINER_BRENDEN
	goto_if 0, DewfordTown_Gym_EventScript_CheckTrainers_3
# 536 "data/maps/DewfordTown_Gym/scripts.pory"
	checktrainerflag TRAINER_CRISTIAN
	goto_if 0, DewfordTown_Gym_EventScript_CheckTrainers_3
# 537 "data/maps/DewfordTown_Gym/scripts.pory"
	checktrainerflag TRAINER_LILITH
	goto_if 0, DewfordTown_Gym_EventScript_CheckTrainers_3
DewfordTown_Gym_EventScript_CheckTrainers_2:
	return

DewfordTown_Gym_EventScript_CheckTrainers_1:
# 539 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_EventScript_CheckTrainers_Text_0, MSGBOX_NPC
# 540 "data/maps/DewfordTown_Gym/scripts.pory"
	release
	end

DewfordTown_Gym_EventScript_CheckTrainers_3:
# 538 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_unset FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_CheckTrainers_1
	goto DewfordTown_Gym_EventScript_CheckTrainers_2


DewfordTown_Gym_EventScript_GiveBulkUp_Text_0:
# 519 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Take this special Pokémon as a gift\n"
	.string "from me!$"

DewfordTown_Gym_EventScript_GiveBulkUp_Text_1:
# 522 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER} got Brawly's {COLOR BLUE}Hitmonchan{COLOR DARK_GRAY} as a\n"
	.string "gift!$"

DewfordTown_Gym_EventScript_CheckTrainers_Text_0:
# 539 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Brawly: Sorry, but you need to defeat\n"
	.string "every trainer on this Gym before\l"
	.string "battling me.$"
