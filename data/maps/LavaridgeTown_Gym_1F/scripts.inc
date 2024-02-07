# 1 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 2 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
.set LOCALID_COLE, 2
# 3 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
.set LOCALID_GERALD, 3
# 4 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
.set LOCALID_AXLE, 4
# 5 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
.set LOCALID_DANIELLE, 5
# 6 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 7 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_MapScripts:: @ 81FE6F4
# 8 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
# 9 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.byte 0
# 10 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 11 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_OnTransition: @ 81FE6FA
# 12 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
# 13 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
# 14 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 15 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 16 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
@ Unclear where/if these temp vars are getting checked
# 17 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars:: @ 81FE705
# 18 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_B, 0
# 19 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_C, 0
# 20 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_D, 0
# 21 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_E, 0
# 22 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_F, 0
# 23 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_COLE LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
# 24 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_B, 1
# 25 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar:: @ 81FE72C
# 26 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
# 27 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_C, 1
# 28 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar:: @ 81FE73A
# 29 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
# 30 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_D, 1
# 31 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar:: @ 81FE748
# 32 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
# 33 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_TEMP_E, 1
# 34 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars:: @ 81FE756
# 35 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	return
# 36 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 37 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers:: @ 81FE757
# 38 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
# 39 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
# 40 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald:: @ 81FE764
# 41 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
# 42 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
# 43 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle:: @ 81FE771
# 44 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
# 45 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
# 46 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle:: @ 81FE77E
# 47 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
# 48 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
# 49 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers:: @ 81FE78B
# 50 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	return
# 51 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 52 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Flannery:: @ 81FE78C
# 53 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_EventScript_CheckTrainers
# 54 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_FLANNERY, LavaridgeTown_Gym_1F_EventScript_AlreadyRematched
# 55 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
# 56 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
# 57 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM50, LavaridgeTown_Gym_1F_EventScript_GiveOverheat
# 58 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
# 59 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 60 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 61 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 62 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated:: @ 81FE7C1
# 63 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
# 64 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	waitmessage
# 65 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 66 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
# 67 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	closemessage
# 68 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	delay 30
# 69 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 70 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredArcanine, MSGBOX_DEFAULT
# 71 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	waitfanfare
# 72 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	closemessage
# 73 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	delay 30
# 74 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_TakeThis, MSGBOX_DEFAULT
# 75 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
# 76 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 77 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_BADGE04_GET
# 78 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 79 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 6
# 80 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
# 81 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_0x8008, 4
# 82 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 83 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
# 84 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
# 85 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
# 86 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	closemessage
# 87 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	delay 30
# 88 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 89 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
# 90 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	waitfanfare
# 91 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	closemessage
# 92 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	delay 30
# 93 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
# 94 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 95 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 96 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 97 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
# 98 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	message LavaridgeTown_Gym_1F_Text_FlanneryChooseFormat
# 99 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	waitmessage
# 100 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
# 101 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	switch VAR_RESULT
# 102 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	case 0, LavaridgeTown_Gym_1F_EventScript_SetSingles
# 103 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	case 1, LavaridgeTown_Gym_1F_EventScript_SetDoubles
# 104 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	case 2, LavaridgeTown_Gym_1F_EventScript_Exit
# 105 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	case 127, LavaridgeTown_Gym_1F_EventScript_Exit
# 106 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 107 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 108 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 109 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
@ 2: singles, legendaries
# 110 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
@ 3: singles, no legendaries
# 111 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
@ 4: doubles, legendaries
# 112 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
@ 5: doubles, no legendaries
# 113 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 114 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetSingles::
# 115 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryAllowLegends, MSGBOX_YESNO
# 116 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	compare VAR_RESULT, NO
# 117 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_FlannerySinglesRematch
# 118 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_3, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
# 119 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_FLANNERY
# 120 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 121 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 122 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 123 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_SetDoubles::
# 124 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryAllowLegends, MSGBOX_YESNO
# 125 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	compare VAR_RESULT, NO
# 126 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_FlanneryDoublesRematch
# 127 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_4, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
# 128 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_FLANNERY
# 129 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 130 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 131 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 132 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_FlannerySinglesRematch::
# 133 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_2, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
# 134 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_FLANNERY
# 135 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 136 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 137 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 138 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_FlanneryDoublesRematch::
# 139 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_5, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
# 140 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_FLANNERY
# 141 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 142 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 143 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 144 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_AlreadyRematched::
# 145 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
# 146 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 147 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 148 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 149 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Exit::
# 150 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 151 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 152 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 153 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Cole:: @ 81FE87F
# 154 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
# 155 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle MSGBOX_AUTOCLOSE
# 156 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 157 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 158 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_EventScript_CheckTrainerScript:: @ 81FE89A
# 159 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
# 160 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 161 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	special ShouldTryGetTrainerScript
# 162 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	compare VAR_RESULT, 1
# 163 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_eq EventScript_GotoTrainerScript
# 164 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 165 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 166 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Axle:: @ 81FE8AF
# 167 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
# 168 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
# 169 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 170 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 171 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_Keegan:: @ 81FE8CA
# 172 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
# 173 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
# 174 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 175 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 176 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Danielle:: @ 81FE8E5
# 177 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
# 178 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
# 179 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 180 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 181 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_Gerald:: @ 81FE900
# 182 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
# 183 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
# 184 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 185 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 186 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_Jace:: @ 81FE91B
# 187 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
# 188 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
# 189 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 190 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 191 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_Jeff:: @ 81FE936
# 192 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
# 193 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
# 194 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 195 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 196 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_EventScript_Eli:: @ 81FE951
# 197 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
# 198 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
# 199 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 200 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 201 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymGuide:: @ 81FE96C
# 202 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	lock
# 203 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	faceplayer
# 204 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
# 205 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice1, MSGBOX_DEFAULT
# 206 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice2, MSGBOX_DEFAULT
# 207 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 208 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 209 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 210 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymGuide2::
# 211 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice2, MSGBOX_DEFAULT
# 212 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 213 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 214 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 215 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory:: @ 81FE981
# 216 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 217 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
# 218 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 219 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 220 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_LeftGymStatue:: @ 81FE98B
# 221 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	lockall
# 222 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
# 223 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
# 224 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 225 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 226 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_RightGymStatue:: @ 81FE99B
# 227 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	lockall
# 228 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
# 229 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
# 230 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 231 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 232 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymStatueCertified:: @ 81FE9AB
# 233 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
# 234 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 235 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 236 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 237 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_EventScript_GymStatue:: @ 81FE9B5
# 238 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
# 239 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	releaseall
# 240 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	end
# 241 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 242 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymGuideAdvice1:
# 243 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Hey, how's it going, Champion-\n"
# 244 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "bound {PLAYER}?$"
# 245 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 246 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymGuideAdvice2: @ 81FE9BF
# 247 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Lavaridge's Gym Leader Flannery\n"
# 248 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "uses Fire-type Pokémon.\p"
# 249 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Her passion for Pokémon burns stronger\n"
# 250 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "and hotter than a volcano.\p"
# 251 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "She likes to battle in the sun, and\n"
# 252 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "her Pokémon are all trained to hit as\l"
# 253 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "hard as they can.\p"
# 254 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "You might need some extra power to\n"
# 255 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "keep up!\p"	
# 256 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Try changing or using the weather\n"
# 257 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "to your own advantage.$"
# 258 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 259 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymGuidePostVictory: @ 81FEAB8
# 260 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Yow! That was a scorching-hot battle!$"
# 261 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 262 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ColeIntro: @ 81FEADE
# 263 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Owowowowow!\n"
# 264 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Yikes, it's hot!$"
# 265 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 266 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ColeDefeat: @ 81FEAFB
# 267 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'm blinded by sweat in my eyes…$"
# 268 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 269 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ColePostBattle: @ 81FEB1C
# 270 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Being buried in hot sand promotes\n"
# 271 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "circulation.\p"
# 272 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "It's effective for healing pain in\n"
# 273 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "your joints.$"
# 274 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 275 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_AxleIntro: @ 81FEB7B
# 276 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'm trying to relieve my stress.\n"
# 277 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Don't come along and stress me out!$"
# 278 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 279 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_AxleDefeat: @ 81FEBC0
# 280 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I hope Flannery flames you good!$"
# 281 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 282 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_AxlePostBattle: @ 81FEBE1
# 283 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Haaah… Whew…\p"
# 284 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "If you spend too much time buried in\n"
# 285 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "hot sand, it tuckers you out…$"
# 286 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 287 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_KeeganIntro: @ 81FEC31
# 288 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "You must be getting tired by now.\n"
# 289 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "You'd like to rest in the hot sand,\l"
# 290 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "wouldn't you?\p"
# 291 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "But you should know that maintaining\n"
# 292 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "your willpower is an important ability\l"
# 293 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "for all Trainers.$"
# 294 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 295 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_KeeganDefeat: @ 81FECE3
# 296 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Play with fire, and be burned…$"
# 297 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 298 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_KeeganPostBattle: @ 81FED02
# 299 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Your skill is real…\n"
# 300 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "But our Leader Flannery is strong.\p"
# 301 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "If you don't watch yourself, you'll be\n"
# 302 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "burned seriously.$"
# 303 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 304 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GeraldIntro: @ 81FED72
# 305 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Can your Pokémon withstand\n"
# 306 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "392-degree heat?$"
# 307 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 308 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GeraldDefeat: @ 81FED9E
# 309 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "It didn't burn hotly enough…$"
# 310 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 311 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GeraldPostBattle: @ 81FEDBB
# 312 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "The temperature of magma is\n"
# 313 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "392 degrees.\p"
# 314 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Your Pokémon beat me, so they should\n"
# 315 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "easily survive in magma.$"
# 316 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 317 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_DanielleIntro: @ 81FEE22
# 318 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Um…\n"
# 319 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Okay, I'll battle with you.$"
# 320 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 321 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_DanielleDefeat: @ 81FEE42
# 322 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Oh, but you're too strong.$"
# 323 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 324 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_DaniellePostBattle: @ 81FEE5D
# 325 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'm going to be a pretty and strong\n"
# 326 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Trainer just like Flannery.$"
# 327 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 328 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JaceIntro: @ 81FEE9D
# 329 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Come on, get with it!\n"
# 330 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Let's go before my feelings cool!$"
# 331 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 332 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JaceDefeat: @ 81FEED5
# 333 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "It's so hot, and yet my heart is\n"
# 334 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "clutched by ice…$"
# 335 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 336 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JacePostBattle: @ 81FEF07
# 337 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "The way the battling spirit burns\n"
# 338 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "within you, you may stand a chance\l"
# 339 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "against our Leader.$"
# 340 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 341 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JeffIntro: @ 81FEF60
# 342 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "See how the flames blaze wildly?\n"
# 343 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "They flare in anticipation of my win!$"
# 344 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 345 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JeffDefeat: @ 81FEFA7
# 346 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Something didn't go right.$"
# 347 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 348 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_JeffPostBattle: @ 81FEFC2
# 349 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Well, so what? I say so what?\n"
# 350 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I can walk on hot coals barefoot!\p"
# 351 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "…Don't even think about trying it!$"
# 352 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 353 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_EliIntro: @ 81FF025
# 354 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "As much as I love mountains,\n"
# 355 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I especially love volcanoes.$"
# 356 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 357 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_EliDefeat: @ 81FF05F
# 358 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Well, it seems to me I lost without\n"
# 359 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "ever being in control.$"
# 360 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 361 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_B1F_Text_EliPostBattle: @ 81FF09A
# 362 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I stay here because I became a fan\n"
# 363 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "of Flannery's power.\p"
# 364 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Hehehehe.$"
# 365 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 366 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryIntro: @ 81FF0DC
# 367 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Welcome… No, wait.\p"
# 368 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Puny Trainer, how good to see you've\n"
# 369 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "made it here!\p"
# 370 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I have been entrusted with the…\n"
# 371 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "No, wait.\p"
# 372 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I am Flannery, and I'm the Gym\n"
# 373 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Leader here!\p"
# 374 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Uh…\n"
# 375 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Dare not underestimate me, though\l"
# 376 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I have been Leader only a short time!\p"
# 377 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "With skills inherited from my grand-\n"
# 378 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "father, I shall, uh…demonstrate the\l"
# 379 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "hot moves we have honed on this land!$"
# 380 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 381 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryDefeat: @ 81FF233
# 382 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Oh…\n"
# 383 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I guess I was trying too hard…\p"
# 384 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I… I've only recently become\n"
# 385 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "a Gym Leader.\p"
# 386 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I tried too hard to be someone\n"
# 387 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'm not.\p"
# 388 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I have to do things my natural way. If\n"
# 389 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I don't, my Pokémon will be confused.\p"
# 390 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Thanks for teaching me that.\n"
# 391 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "For that, you deserve this.$"
# 392 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 393 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge: @ 81FF32F
# 394 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "{PLAYER} received the Heat Badge\n"
# 395 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "from Flannery.$"
# 396 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 397 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis: @ 81FF359
# 398 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "If you have a Heat Badge, all Pokémon\n"
# 399 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "up to Level 60, even those you get in\l"
# 400 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "trades from other people, will obey\l"
# 401 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "you completely.\p"
# 402 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "And, it lets Pokémon use the HM move\n"
# 403 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Strength outside of battle.\p"
# 404 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I'll even let you call on my Arcanine\n"
# 405 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "to use Strength for you.$"
# 406 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 407 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_TakeThis:
# 408 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "This is a token of my appreciation.\n"
# 409 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Don't be shy about taking it!$"
# 410 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 411 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_ExplainOverheat: @ 81FF45C
# 412 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "That TM50 contains Overheat.\p"
# 413 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "That move inflicts serious damage on\n"
# 414 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "the opponent.\p"
# 415 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "But it also sharply cuts the Sp. Atk\n"
# 416 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "of the Pokémon using it. It might not\l"
# 417 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "be suitable for longer battles.$"
# 418 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 419 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_RegisteredFlannery: @ 81FF517
# 420 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Registered Gym Leader Flannery\n"
# 421 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "in the PokéNav.$"
# 422 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 423 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_RegisteredArcanine: @ 81FF517
# 424 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Registered Flannery's Arcanine\n"
# 425 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "in the PokéNav.$"
# 426 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 427 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryPostBattle: @ 81FF546
# 428 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Your power reminds me of someone…\p"
# 429 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Oh! I know! You battle like Norman,\n"
# 430 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "the Gym Leader of Petalburg.$"
# 431 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 432 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymStatue: @ 81FF5A9
# 433 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Lavaridge Town Pokémon Gym$"
# 434 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 435 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_GymStatueCertified: @ 81FF5C4
# 436 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Lavaridge Town Pokémon Gym\p"
# 437 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "FLANNERY's Certified Trainers:\n"
# 438 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "{PLAYER}$"
# 439 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 440 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryPreRematch: @ 81FF601
# 441 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Flannery: Let's exchange superhot\n"
# 442 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "moves in another battle!$"
# 443 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 444 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat: @ 81FF69F
# 445 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Whew!\n"
# 446 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "On the verge of eruption!$"
# 447 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 448 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryPostRematch: @ 81FF6BF
# 449 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Flannery: I lost the match,\n"
# 450 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "but I'm completely satisfied.\p"
# 451 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "It's not often I get to enjoy a battle\n"
# 452 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "this heated.\p"
# 453 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Let's have another one like this\n"
# 454 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "again sometime!$"
# 455 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 456 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons: @ 81FF75E
# 457 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Oh, wait. Do you only have one Pokémon\n"
# 458 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "that can battle?\p"
# 459 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I hate to say this, but when you come\n"
# 460 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "see me, bring at least two Pokémon.$"
# 461 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 462 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryChooseFormat:
# 463 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Flannery: Losing a battle isn't going\n"
# 464 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "to deflate me.\p"
# 465 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I love Pokémon.\n"
# 466 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "I love to battle.\l"
# 467 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "And… I love this Gym!\p"
# 468 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "So… Let's choose some rules for our\n"
# 469 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "rematch: singles or doubles?$"
# 470 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"

# 471 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
LavaridgeTown_Gym_1F_Text_FlanneryAllowLegends:
# 472 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Flannery: And can I turn up the heat\n"
# 473 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "with my Legendary Pokémon?$"

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
# 476 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_GiveOverheat_Text_0
# 477 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	givecustommon SPECIES_VOLCARONA, 40, ITEM_CHARTI_BERRY, ITEM_CHERISH_BALL, NATURE_TIMID, 2, 248, 0, 0, 112, 40, 108, 0, 0, 0, 0, 0, 0, MOVE_FIERY_DANCE, MOVE_GIGA_DRAIN, MOVE_QUIVER_DANCE, MOVE_ROOST, TRUE
# 478 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 479 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	message LavaridgeTown_Gym_1F_EventScript_GiveOverheat_Text_1
# 480 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	waitfanfare
# 481 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	setflag FLAG_RECEIVED_TM50
# 482 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
# 483 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
	end


LavaridgeTown_Gym_EventScript_CheckTrainers::
# 489 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_COLE
	goto_if 0, LavaridgeTown_Gym_EventScript_CheckTrainers_3
# 490 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_AXLE
	goto_if 0, LavaridgeTown_Gym_EventScript_CheckTrainers_3
# 491 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_KEEGAN
	goto_if 0, LavaridgeTown_Gym_EventScript_CheckTrainers_3
# 492 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_GERALD
	goto_if 0, LavaridgeTown_Gym_EventScript_CheckTrainers_3
# 493 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_JEFF
	goto_if 0, LavaridgeTown_Gym_EventScript_CheckTrainers_3
# 494 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_JACE
	goto_if 0, LavaridgeTown_Gym_EventScript_CheckTrainers_3
# 495 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_DANIELLE
	goto_if 0, LavaridgeTown_Gym_EventScript_CheckTrainers_3
# 496 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	checktrainerflag TRAINER_ELI
	goto_if 0, LavaridgeTown_Gym_EventScript_CheckTrainers_3
LavaridgeTown_Gym_EventScript_CheckTrainers_2:
	return

LavaridgeTown_Gym_EventScript_CheckTrainers_1:
# 498 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	msgbox LavaridgeTown_Gym_EventScript_CheckTrainers_Text_0, MSGBOX_NPC
# 499 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	release
	end

LavaridgeTown_Gym_EventScript_CheckTrainers_3:
# 497 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, LavaridgeTown_Gym_EventScript_CheckTrainers_1
	goto LavaridgeTown_Gym_EventScript_CheckTrainers_2


LavaridgeTown_Gym_1F_EventScript_GiveOverheat_Text_0:
# 476 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Take this special Pokémon as a gift\n"
	.string "from me!$"

LavaridgeTown_Gym_1F_EventScript_GiveOverheat_Text_1:
# 479 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "{PLAYER} got Flannery's {COLOR BLUE}Volcarona{COLOR DARK_GRAY} as\n"
	.string "a gift!$"

LavaridgeTown_Gym_EventScript_CheckTrainers_Text_0:
# 498 "data/maps/LavaridgeTown_Gym_1F/scripts.pory"
	.string "Flannery: Sorry, but you need to defeat\n"
	.string "every trainer on this Gym before\l"
	.string "battling me.$"
