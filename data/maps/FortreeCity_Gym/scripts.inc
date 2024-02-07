# 1 "data/maps/FortreeCity_Gym/scripts.pory"

# 2 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_MapScripts:: @ 82165AB
# 3 "data/maps/FortreeCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
# 4 "data/maps/FortreeCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
# 5 "data/maps/FortreeCity_Gym/scripts.pory"
	.byte 0
# 6 "data/maps/FortreeCity_Gym/scripts.pory"

# 7 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_OnTransition: @ 82165B6
# 8 "data/maps/FortreeCity_Gym/scripts.pory"
	special RotatingGate_InitPuzzle
# 9 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 10 "data/maps/FortreeCity_Gym/scripts.pory"

# 11 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_OnWarp: @ 82165BA
# 12 "data/maps/FortreeCity_Gym/scripts.pory"
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
# 13 "data/maps/FortreeCity_Gym/scripts.pory"
	.2byte 0
# 14 "data/maps/FortreeCity_Gym/scripts.pory"

# 15 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_InitRotatingGates:: @ 82165C4
# 16 "data/maps/FortreeCity_Gym/scripts.pory"
	special RotatingGate_InitPuzzleAndGraphics
# 17 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 18 "data/maps/FortreeCity_Gym/scripts.pory"

# 19 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Winona:: @ 82165C8
# 20 "data/maps/FortreeCity_Gym/scripts.pory"
	call FortreeCity_Gym_EventScript_CheckTrainers
# 21 "data/maps/FortreeCity_Gym/scripts.pory"
	//goto_if_set FLAG_DAILY_REMATCH_WINONA, FortreeCity_Gym_EventScript_AlreadyRematched
# 22 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, FortreeCity_Gym_EventScript_WinonaRematch
# 23 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
# 24 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM51, FortreeCity_Gym_EventScript_GiveRoost
# 25 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
# 26 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 27 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 28 "data/maps/FortreeCity_Gym/scripts.pory"

# 29 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaDefeated:: @ 82165FD
# 30 "data/maps/FortreeCity_Gym/scripts.pory"
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
# 31 "data/maps/FortreeCity_Gym/scripts.pory"
	waitmessage
# 32 "data/maps/FortreeCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 33 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
# 34 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 35 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_BADGE06_GET
# 36 "data/maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_0x8008, 6
# 37 "data/maps/FortreeCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 38 "data/maps/FortreeCity_Gym/scripts.pory"
	call FortreeCity_Gym_EventScript_GiveRoost
# 39 "data/maps/FortreeCity_Gym/scripts.pory"
	closemessage
# 40 "data/maps/FortreeCity_Gym/scripts.pory"
	delay 30
# 41 "data/maps/FortreeCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 42 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
# 43 "data/maps/FortreeCity_Gym/scripts.pory"
	waitfanfare
# 44 "data/maps/FortreeCity_Gym/scripts.pory"
	closemessage
# 45 "data/maps/FortreeCity_Gym/scripts.pory"
	delay 30
# 46 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
# 47 "data/maps/FortreeCity_Gym/scripts.pory"
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
# 48 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
# 49 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 50 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 51 "data/maps/FortreeCity_Gym/scripts.pory"

# 52 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaRematch::
# 53 "data/maps/FortreeCity_Gym/scripts.pory"
	message FortreeCity_Gym_Text_WinonaChooseFormat
# 54 "data/maps/FortreeCity_Gym/scripts.pory"
	waitmessage
# 55 "data/maps/FortreeCity_Gym/scripts.pory"
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
# 56 "data/maps/FortreeCity_Gym/scripts.pory"
	switch VAR_RESULT
# 57 "data/maps/FortreeCity_Gym/scripts.pory"
	case 0, FortreeCity_Gym_EventScript_SetSingles
# 58 "data/maps/FortreeCity_Gym/scripts.pory"
	case 1, FortreeCity_Gym_EventScript_SetDoubles
# 59 "data/maps/FortreeCity_Gym/scripts.pory"
	case 2, FortreeCity_Gym_EventScript_Exit
# 60 "data/maps/FortreeCity_Gym/scripts.pory"
	case 127, FortreeCity_Gym_EventScript_Exit
# 61 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 62 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 63 "data/maps/FortreeCity_Gym/scripts.pory"

# 64 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_SetSingles::
# 65 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaAllowLegends, MSGBOX_YESNO
# 66 "data/maps/FortreeCity_Gym/scripts.pory"
	compare VAR_RESULT, 0
# 67 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq FortreeCity_Gym_EventScript_WinonaSinglesRematch
# 68 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_4, FortreeCity_Gym_Text_WinonaRematchDefeat
# 69 "data/maps/FortreeCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_WINONA
# 70 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 71 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 72 "data/maps/FortreeCity_Gym/scripts.pory"

# 73 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_SetDoubles::
# 74 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaAllowLegends, MSGBOX_YESNO
# 75 "data/maps/FortreeCity_Gym/scripts.pory"
	compare VAR_RESULT, 0
# 76 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_eq FortreeCity_Gym_EventScript_WinonaDoublesRematch
# 77 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_5, FortreeCity_Gym_Text_WinonaRematchDefeat
# 78 "data/maps/FortreeCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_WINONA
# 79 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 80 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 81 "data/maps/FortreeCity_Gym/scripts.pory"

# 82 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaSinglesRematch::
# 83 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_2, FortreeCity_Gym_Text_WinonaRematchDefeat
# 84 "data/maps/FortreeCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_WINONA
# 85 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 86 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 87 "data/maps/FortreeCity_Gym/scripts.pory"

# 88 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_WinonaDoublesRematch::
# 89 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_3, FortreeCity_Gym_Text_WinonaRematchDefeat
# 90 "data/maps/FortreeCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_WINONA
# 91 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 92 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 93 "data/maps/FortreeCity_Gym/scripts.pory"

# 94 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_AlreadyRematched::
# 95 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
# 96 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 97 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 98 "data/maps/FortreeCity_Gym/scripts.pory"

# 99 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Exit::
# 100 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 101 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 102 "data/maps/FortreeCity_Gym/scripts.pory"

# 103 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Jared:: @ 82166A8
# 104 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
# 105 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
# 106 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 107 "data/maps/FortreeCity_Gym/scripts.pory"

# 108 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Edwardo:: @ 82166BF
# 109 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
# 110 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
# 111 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 112 "data/maps/FortreeCity_Gym/scripts.pory"

# 113 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Flint:: @ 82166D6
# 114 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
# 115 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
# 116 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 117 "data/maps/FortreeCity_Gym/scripts.pory"

# 118 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Ashley:: @ 82166ED
# 119 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
# 120 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
# 121 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 122 "data/maps/FortreeCity_Gym/scripts.pory"

# 123 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Humberto:: @ 8216704
# 124 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
# 125 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
# 126 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 127 "data/maps/FortreeCity_Gym/scripts.pory"

# 128 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_Darius:: @ 821671B
# 129 "data/maps/FortreeCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
# 130 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
# 131 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 132 "data/maps/FortreeCity_Gym/scripts.pory"

# 133 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymGuide:: @ 8216732
# 134 "data/maps/FortreeCity_Gym/scripts.pory"
	lock
# 135 "data/maps/FortreeCity_Gym/scripts.pory"
	faceplayer
# 136 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
# 137 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_MOVE_FORTREE_GYM_ENERGY_ROOT, FortreeCity_GymGuide_2
# 138 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 139 "data/maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_ENERGY_ROOT, 10
# 140 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_MOVE_FORTREE_GYM_ENERGY_ROOT
# 141 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuideAdvice2, MSGBOX_DEFAULT
# 142 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 143 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 144 "data/maps/FortreeCity_Gym/scripts.pory"

# 145 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_GymGuide_2::
# 146 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuideAdvice2, MSGBOX_DEFAULT
# 147 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 148 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 149 "data/maps/FortreeCity_Gym/scripts.pory"

# 150 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymGuidePostVictory:: @ 8216747
# 151 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 152 "data/maps/FortreeCity_Gym/scripts.pory"
	release
# 153 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 154 "data/maps/FortreeCity_Gym/scripts.pory"

# 155 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_LeftGymStatue:: @ 8216751
# 156 "data/maps/FortreeCity_Gym/scripts.pory"
	lockall
# 157 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
# 158 "data/maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_GymStatue
# 159 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 160 "data/maps/FortreeCity_Gym/scripts.pory"

# 161 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_RightGymStatue:: @ 8216761
# 162 "data/maps/FortreeCity_Gym/scripts.pory"
	lockall
# 163 "data/maps/FortreeCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
# 164 "data/maps/FortreeCity_Gym/scripts.pory"
	goto FortreeCity_Gym_EventScript_GymStatue
# 165 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 166 "data/maps/FortreeCity_Gym/scripts.pory"

# 167 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymStatueCertified:: @ 8216771
# 168 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 169 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 170 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 171 "data/maps/FortreeCity_Gym/scripts.pory"

# 172 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_EventScript_GymStatue:: @ 821677B
# 173 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 174 "data/maps/FortreeCity_Gym/scripts.pory"
	releaseall
# 175 "data/maps/FortreeCity_Gym/scripts.pory"
	end
# 176 "data/maps/FortreeCity_Gym/scripts.pory"

# 177 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuideAdvice: @ 8216785
# 178 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Yo, how's it going, Champion-\n"
# 179 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 180 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Please, take these Energy Roots to\n"
# 181 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "help with your challenge!$"
# 182 "data/maps/FortreeCity_Gym/scripts.pory"

# 183 "data/maps/FortreeCity_Gym/scripts.pory"

# 184 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuideAdvice2:
# 185 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Fortree Gym Leader Winona is\n"
# 186 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "a master of Flying-type Pokémon.\p"
# 187 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "She's waiting at the back of this Gym,\n"
# 188 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "behind the rotating doors.\p"
# 189 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "She's waiting for new challengers\n"
# 190 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "who are trying to take wing!\p"
# 191 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Okay, go for it!$"
# 192 "data/maps/FortreeCity_Gym/scripts.pory"

# 193 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymGuidePostVictory: @ 821687D
# 194 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You did it!\n"
# 195 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You've achieved liftoff!$"
# 196 "data/maps/FortreeCity_Gym/scripts.pory"

# 197 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredIntro: @ 82168A2
# 198 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Behold the elegant battle style of\n"
# 199 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Bird Pokémon!$"
# 200 "data/maps/FortreeCity_Gym/scripts.pory"

# 201 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredDefeat: @ 82168D3
# 202 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You…\n"
# 203 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You're strong…$"
# 204 "data/maps/FortreeCity_Gym/scripts.pory"

# 205 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_JaredPostBattle: @ 82168E7
# 206 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "A Trainer has to be smart to keep\n"
# 207 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "up with unexpected turns of events.\p"
# 208 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Do you have the smarts to get to\n"
# 209 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "our Leader?$"
# 210 "data/maps/FortreeCity_Gym/scripts.pory"

# 211 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoIntro: @ 821695A
# 212 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "The lovers of Bird Pokémon aspire\n"
# 213 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "to join this Gym.\p"
# 214 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "As a member of the Fortree Gym,\n"
# 215 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I'm not allowed to lose!$"
# 216 "data/maps/FortreeCity_Gym/scripts.pory"

# 217 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoDefeat: @ 82169C7
# 218 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "It was too much of a load for me\n"
# 219 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "to bear…$"
# 220 "data/maps/FortreeCity_Gym/scripts.pory"

# 221 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_EdwardoPostBattle: @ 82169F1
# 222 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "The world is huge, and there are\n"
# 223 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "countless tough Trainers.\p"
# 224 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I'm going to keep training and make\n"
# 225 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "myself even stronger.$"
# 226 "data/maps/FortreeCity_Gym/scripts.pory"

# 227 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintIntro: @ 8216A66
# 228 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "There's no need for Winona, our Gym\n"
# 229 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Leader, to deal with you!\p"
# 230 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I'm plenty good enough for you!$"
# 231 "data/maps/FortreeCity_Gym/scripts.pory"

# 232 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintDefeat: @ 8216AC4
# 233 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona, I…\n"
# 234 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I lost!$"
# 235 "data/maps/FortreeCity_Gym/scripts.pory"

# 236 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_FlintPostBattle: @ 8216AD7
# 237 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona is cute and she's strong.\n"
# 238 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "She's the ultimate Leader!\p"
# 239 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Blush…$"
# 240 "data/maps/FortreeCity_Gym/scripts.pory"

# 241 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyIntro: @ 8216B1A
# 242 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona taught me personally!\n"
# 243 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You can't beat me easily!$"
# 244 "data/maps/FortreeCity_Gym/scripts.pory"

# 245 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyDefeat: @ 8216B51
# 246 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I was beaten…$"
# 247 "data/maps/FortreeCity_Gym/scripts.pory"

# 248 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_AshleyPostBattle: @ 8216B5F
# 249 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Thanks to Winona, the people of\n"
# 250 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Fortree can live without fear.$"
# 251 "data/maps/FortreeCity_Gym/scripts.pory"

# 252 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoIntro: @ 8216B9E
# 253 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "When Winona takes to battle, her face\n"
# 254 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "shines with beautiful determination…\p"
# 255 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I'm not letting you witness that\n"
# 256 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "lovely sight!$"
# 257 "data/maps/FortreeCity_Gym/scripts.pory"

# 258 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoDefeat: @ 8216C18
# 259 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Urk!\n"
# 260 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I couldn't stop you.$"
# 261 "data/maps/FortreeCity_Gym/scripts.pory"

# 262 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_HumbertoPostBattle: @ 8216C32
# 263 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You'd better watch it!\n"
# 264 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Don't get distracted staring at Winona\l"
# 265 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "or you'll go crashing down in a heap!$"
# 266 "data/maps/FortreeCity_Gym/scripts.pory"

# 267 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusIntro: @ 8216C96
# 268 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You'd better know that there are all\n"
# 269 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "sorts of Flying-type Pokémon.\p"
# 270 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You do know that, right?$"
# 271 "data/maps/FortreeCity_Gym/scripts.pory"

# 272 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusDefeat: @ 8216CF2
# 273 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You seem to know your stuff!$"
# 274 "data/maps/FortreeCity_Gym/scripts.pory"

# 275 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_DariusPostBattle: @ 8216D0F
# 276 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Sure, you beat me all right.\n"
# 277 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "But you'd better watch it! Our Leader\l"
# 278 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona's Pokémon are all business.$"
# 279 "data/maps/FortreeCity_Gym/scripts.pory"

# 280 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaIntro: @ 8216D75
# 281 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I am Winona. I am the Leader of\n"
# 282 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "the Fortree Pokémon Gym.\p"
# 283 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I have become one with Bird Pokémon\n"
# 284 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "and have soared the skies…\p"
# 285 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "However grueling the battle, we have\n"
# 286 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "triumphed with grace…\p"
# 287 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Witness the elegant choreography\n"
# 288 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "of Bird Pokémon and I!$"
# 289 "data/maps/FortreeCity_Gym/scripts.pory"

# 290 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaDefeat: @ 8216E60
# 291 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Never before have I seen a Trainer\n"
# 292 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "command Pokémon with more grace\l"
# 293 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "than I…\p"
# 294 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "In recognition of your prowess,\n"
# 295 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I present to you this Gym Badge.$"
# 296 "data/maps/FortreeCity_Gym/scripts.pory"

# 297 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ReceivedFeatherBadge: @ 8216EEC
# 298 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "{PLAYER} received the Feather Badge\n"
# 299 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "from Winona.$"
# 300 "data/maps/FortreeCity_Gym/scripts.pory"

# 301 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis: @ 8216F17
# 302 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "With the Feather Badge, all Pokémon up\n"
# 303 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "to LV 80, even those received through\l"
# 304 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "trades, will obey your every command.\p"
# 305 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "And this…\n"
# 306 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "This is a gift from me.$"
# 307 "data/maps/FortreeCity_Gym/scripts.pory"

# 308 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_ExplainRoost: @ 8216FEC
# 309 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Roost…\p"
# 310 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "With this move, the user can restore its\n"
# 311 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "HP by up to half of its max HP by\l"
# 312 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "landing on the ground and resting.\p"
# 313 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "However, the user loses its Flying-type\n"
# 314 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "designation during the turn, so be\l"
# 315 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "cautious.$"
# 316 "data/maps/FortreeCity_Gym/scripts.pory"

# 317 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_RegisteredWinona: @ 8217044
# 318 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Registered Gym Leader Winona\n"
# 319 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "in the PokéNav.$"
# 320 "data/maps/FortreeCity_Gym/scripts.pory"

# 321 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPostBattle: @ 8217071
# 322 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Though I fell to you, I will remain\n"
# 323 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "devoted to Bird Pokémon.$"
# 324 "data/maps/FortreeCity_Gym/scripts.pory"

# 325 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymStatue: @ 82170AE
# 326 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Fortree City Pokémon Gym$"
# 327 "data/maps/FortreeCity_Gym/scripts.pory"

# 328 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_GymStatueCertified: @ 82170C7
# 329 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Fortree City Pokémon Gym\p"
# 330 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona's Certified Trainers:\n"
# 331 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 332 "data/maps/FortreeCity_Gym/scripts.pory"

# 333 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPreRematch: @ 8217100
# 334 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona: Please, allow me to see your\n"
# 335 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "power at full flight!$"
# 336 "data/maps/FortreeCity_Gym/scripts.pory"

# 337 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaRematchDefeat: @ 82171E6
# 338 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I failed to reach your height again…$"
# 339 "data/maps/FortreeCity_Gym/scripts.pory"

# 340 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaPostRematch: @ 821720B
# 341 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona: Even though I have lost,\n"
# 342 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "the wings of my heart remain unbroken.\p"
# 343 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I can rise and soar again and\n"
# 344 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "yet again.\p"
# 345 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "I am convinced of it!$"
# 346 "data/maps/FortreeCity_Gym/scripts.pory"

# 347 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaRematchNeedTwoMons: @ 8217292
# 348 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Oh, no… Do you have but one\n"
# 349 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Pokémon with you?\p"
# 350 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Please return with two Pokémon\n"
# 351 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "at the very least.$"
# 352 "data/maps/FortreeCity_Gym/scripts.pory"

# 353 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaChooseFormat:
# 354 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona: We humans can never escape\n"
# 355 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "gravity's pull on the ground.\p"
# 356 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "But by striving for excellence,\n"
# 357 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "we have the power to soar!\p"
# 358 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "You have scaled the pinnacle as\n"
# 359 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "the reigning Champion.\p"
# 360 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Please, allow me to see your power\n"
# 361 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "at full flight!\p"
# 362 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Now, please tell me - how would you\n"
# 363 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "like to battle?$"
# 364 "data/maps/FortreeCity_Gym/scripts.pory"

# 365 "data/maps/FortreeCity_Gym/scripts.pory"
FortreeCity_Gym_Text_WinonaAllowLegends:
# 366 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona: and would you like to challenge\n"
# 367 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "my stronger Legendary Pokémon?$"

FortreeCity_Gym_EventScript_GiveRoost::
# 370 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_EventScript_GiveRoost_Text_0
# 371 "data/maps/FortreeCity_Gym/scripts.pory"
	givecustommon SPECIES_DRAGONITE, 55, ITEM_ASSAULT_VEST, ITEM_CHERISH_BALL, NATURE_JOLLY, 2, 4, 252, 0, 252, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_DUAL_WINGBEAT, MOVE_DRAGON_RUSH, MOVE_FIRE_PUNCH, MOVE_EXTREME_SPEED, FALSE
# 372 "data/maps/FortreeCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 373 "data/maps/FortreeCity_Gym/scripts.pory"
	message FortreeCity_Gym_EventScript_GiveRoost_Text_1
# 374 "data/maps/FortreeCity_Gym/scripts.pory"
	waitfanfare
# 375 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_EventScript_GiveRoost_Text_2
# 376 "data/maps/FortreeCity_Gym/scripts.pory"
	giveitem ITEM_TOUCANNONITE, 1
# 377 "data/maps/FortreeCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 378 "data/maps/FortreeCity_Gym/scripts.pory"
	waitfanfare
# 379 "data/maps/FortreeCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM51
# 380 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
# 381 "data/maps/FortreeCity_Gym/scripts.pory"
	release
	end


FortreeCity_Gym_EventScript_CheckTrainers::
# 387 "data/maps/FortreeCity_Gym/scripts.pory"
	checktrainerflag TRAINER_JARED
	goto_if 0, FortreeCity_Gym_EventScript_CheckTrainers_1
# 388 "data/maps/FortreeCity_Gym/scripts.pory"
	checktrainerflag TRAINER_FLINT
	goto_if 0, FortreeCity_Gym_EventScript_CheckTrainers_1
# 389 "data/maps/FortreeCity_Gym/scripts.pory"
	checktrainerflag TRAINER_ASHLEY
	goto_if 0, FortreeCity_Gym_EventScript_CheckTrainers_1
# 390 "data/maps/FortreeCity_Gym/scripts.pory"
	checktrainerflag TRAINER_EDWARDO
	goto_if 0, FortreeCity_Gym_EventScript_CheckTrainers_1
# 391 "data/maps/FortreeCity_Gym/scripts.pory"
	checktrainerflag TRAINER_HUMBERTO
	goto_if 0, FortreeCity_Gym_EventScript_CheckTrainers_1
# 392 "data/maps/FortreeCity_Gym/scripts.pory"
	checktrainerflag TRAINER_DARIUS
	goto_if 0, FortreeCity_Gym_EventScript_CheckTrainers_1
	return

FortreeCity_Gym_EventScript_CheckTrainers_1:
# 393 "data/maps/FortreeCity_Gym/scripts.pory"
	msgbox FortreeCity_Gym_EventScript_CheckTrainers_Text_0, MSGBOX_NPC
# 394 "data/maps/FortreeCity_Gym/scripts.pory"
	release
	end


FortreeCity_Gym_EventScript_GiveRoost_Text_0:
# 370 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Take this special Pokémon as a gift\n"
	.string "from me!$"

FortreeCity_Gym_EventScript_GiveRoost_Text_1:
# 373 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "{PLAYER} got Winona's {COLOR BLUE}Dragonite{COLOR DARK_GRAY} as a\n"
	.string "gift!$"

FortreeCity_Gym_EventScript_GiveRoost_Text_2:
# 375 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Also take this rare Mega stone!$"

FortreeCity_Gym_EventScript_CheckTrainers_Text_0:
# 393 "data/maps/FortreeCity_Gym/scripts.pory"
	.string "Winona: Sorry, but you need to defeat\n"
	.string "every trainer on this Gym before\l"
	.string "battling me.$"
