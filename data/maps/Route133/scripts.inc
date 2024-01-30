# 1 "data/maps/Route133/scripts.pory"

# 2 "data/maps/Route133/scripts.pory"
.set LOCALID_NURSE, 8
# 3 "data/maps/Route133/scripts.pory"
.set LOCALID_CHANSEY, 9
# 4 "data/maps/Route133/scripts.pory"

# 5 "data/maps/Route133/scripts.pory"
Route133_MapScripts::
# 6 "data/maps/Route133/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route133_OnTransition
# 7 "data/maps/Route133/scripts.pory"
	.byte 0
# 8 "data/maps/Route133/scripts.pory"

# 9 "data/maps/Route133/scripts.pory"
Route133_OnTransition:
# 10 "data/maps/Route133/scripts.pory"
	compare VAR_POKE_VIAL_MAX_CHARGES, 1
# 11 "data/maps/Route133/scripts.pory"
	goto_if_eq Route133_HideNurse
# 12 "data/maps/Route133/scripts.pory"
	compare VAR_POKE_VIAL_MAX_CHARGES, 2
# 13 "data/maps/Route133/scripts.pory"
	goto_if_eq Route133_ShowNurse
# 14 "data/maps/Route133/scripts.pory"
	end
# 15 "data/maps/Route133/scripts.pory"

# 16 "data/maps/Route133/scripts.pory"
Route133_HideNurse:
# 17 "data/maps/Route133/scripts.pory"
	setflag FLAG_LENT_NURSE_SURF
# 18 "data/maps/Route133/scripts.pory"
	end
# 19 "data/maps/Route133/scripts.pory"

# 20 "data/maps/Route133/scripts.pory"
Route133_ShowNurse:
# 21 "data/maps/Route133/scripts.pory"
	clearflag FLAG_LENT_NURSE_SURF
# 22 "data/maps/Route133/scripts.pory"
	end
# 23 "data/maps/Route133/scripts.pory"

# 24 "data/maps/Route133/scripts.pory"
Route133_EventScript_Franklin:: @ 81F75A3
# 25 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_FRANKLIN, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat
# 26 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
# 27 "data/maps/Route133/scripts.pory"
	end
# 28 "data/maps/Route133/scripts.pory"

# 29 "data/maps/Route133/scripts.pory"
Route133_EventScript_Debra:: @ 81F75BA
# 30 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_DEBRA, Route133_Text_DebraIntro, Route133_Text_DebraDefeat
# 31 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_DebraPostBattle, MSGBOX_AUTOCLOSE
# 32 "data/maps/Route133/scripts.pory"
	end
# 33 "data/maps/Route133/scripts.pory"

# 34 "data/maps/Route133/scripts.pory"
Route133_EventScript_Linda:: @ 81F75D1
# 35 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_LINDA, Route133_Text_LindaIntro, Route133_Text_LindaDefeat
# 36 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_LindaPostBattle, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route133/scripts.pory"
	end
# 38 "data/maps/Route133/scripts.pory"

# 39 "data/maps/Route133/scripts.pory"
Route133_EventScript_Warren:: @ 81F75E8
# 40 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_WARREN, Route133_Text_WarrenIntro, Route133_Text_WarrenDefeat
# 41 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route133/scripts.pory"
	end
# 43 "data/maps/Route133/scripts.pory"

# 44 "data/maps/Route133/scripts.pory"
Route133_EventScript_Beck:: @ 81F75FF
# 45 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_BECK, Route133_Text_BeckIntro, Route133_Text_BeckDefeat
# 46 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
# 47 "data/maps/Route133/scripts.pory"
	end
# 48 "data/maps/Route133/scripts.pory"

# 49 "data/maps/Route133/scripts.pory"
Route133_EventScript_Mollie:: @ 81F7616
# 50 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_MOLLIE, Route133_Text_MollieIntro, Route133_Text_MollieDefeat
# 51 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_MolliePostBattle, MSGBOX_AUTOCLOSE
# 52 "data/maps/Route133/scripts.pory"
	end
# 53 "data/maps/Route133/scripts.pory"

# 54 "data/maps/Route133/scripts.pory"
Route133_EventScript_Conor:: @ 81F762D
# 55 "data/maps/Route133/scripts.pory"
	trainerbattle_single TRAINER_CONOR, Route133_Text_ConorIntro, Route133_Text_ConorDefeat
# 56 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_ConorPostBattle, MSGBOX_AUTOCLOSE
# 57 "data/maps/Route133/scripts.pory"
	end
# 58 "data/maps/Route133/scripts.pory"

# 59 "data/maps/Route133/scripts.pory"
Route133_EventScript_Nurse::
# 60 "data/maps/Route133/scripts.pory"
	lockall
# 61 "data/maps/Route133/scripts.pory"
	faceplayer
# 62 "data/maps/Route133/scripts.pory"
	playse SE_PIN
# 63 "data/maps/Route133/scripts.pory"
	compare VAR_TEMP_1, 1
# 64 "data/maps/Route133/scripts.pory"
	goto_if_eq Route133_EventScript_NurseShortMsg
# 65 "data/maps/Route133/scripts.pory"
	applymovement LOCALID_NURSE, Common_Movement_ExclamationMark
# 66 "data/maps/Route133/scripts.pory"
	waitmovement 0
# 67 "data/maps/Route133/scripts.pory"
	delay 40
# 68 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_NurseHello, MSGBOX_YESNO
# 69 "data/maps/Route133/scripts.pory"
	compare VAR_RESULT, NO
# 70 "data/maps/Route133/scripts.pory"
	goto_if_eq Route133_EventScript_NurseRefuse
# 71 "data/maps/Route133/scripts.pory"
Route133_EventScript_NurseTeachAudino::
# 72 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_NurseTeachAudino, MSGBOX_DEFAULT
# 73 "data/maps/Route133/scripts.pory"
	playse SE_PC_LOGIN
# 74 "data/maps/Route133/scripts.pory"
	waitse
# 75 "data/maps/Route133/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 76 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_NurseDoneHaveVialUpgrade, MSGBOX_DEFAULT
# 77 "data/maps/Route133/scripts.pory"
	setvar VAR_POKE_VIAL_MAX_CHARGES, 3
# 78 "data/maps/Route133/scripts.pory"
	setvar VAR_POKE_VIAL_CHARGES, 3
# 79 "data/maps/Route133/scripts.pory"
	fadescreen FADE_TO_BLACK
# 80 "data/maps/Route133/scripts.pory"
	waitse
# 81 "data/maps/Route133/scripts.pory"
	playmoncry SPECIES_CHANSEY, 0
# 82 "data/maps/Route133/scripts.pory"
	delay 40
# 83 "data/maps/Route133/scripts.pory"
	waitmoncry
# 84 "data/maps/Route133/scripts.pory"
	removeobject LOCALID_NURSE
# 85 "data/maps/Route133/scripts.pory"
	removeobject LOCALID_CHANSEY
# 86 "data/maps/Route133/scripts.pory"
	closemessage
# 87 "data/maps/Route133/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 88 "data/maps/Route133/scripts.pory"
	setflag FLAG_LENT_NURSE_SURF
# 89 "data/maps/Route133/scripts.pory"
	releaseall
# 90 "data/maps/Route133/scripts.pory"
	end
# 91 "data/maps/Route133/scripts.pory"

# 92 "data/maps/Route133/scripts.pory"
Route133_EventScript_NurseShortMsg::
# 93 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_NurseSoYoullHelp, MSGBOX_YESNO
# 94 "data/maps/Route133/scripts.pory"
	compare VAR_RESULT, NO
# 95 "data/maps/Route133/scripts.pory"
	goto_if_eq Route133_EventScript_NurseRefuse
# 96 "data/maps/Route133/scripts.pory"
	goto Route133_EventScript_NurseTeachAudino
# 97 "data/maps/Route133/scripts.pory"

# 98 "data/maps/Route133/scripts.pory"
Route133_EventScript_NurseRefuse::
# 99 "data/maps/Route133/scripts.pory"
	setvar VAR_TEMP_1, 1
# 100 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_NurseReally, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route133/scripts.pory"
	releaseall
# 102 "data/maps/Route133/scripts.pory"
	end
# 103 "data/maps/Route133/scripts.pory"

# 104 "data/maps/Route133/scripts.pory"
Route133_EventScript_Blob::
# 105 "data/maps/Route133/scripts.pory"
	lockall
# 106 "data/maps/Route133/scripts.pory"
	faceplayer
# 107 "data/maps/Route133/scripts.pory"
	applymovement LOCALID_CHANSEY, Route133_Movement_ChanseyJump
# 108 "data/maps/Route133/scripts.pory"
	waitmovement 0
# 109 "data/maps/Route133/scripts.pory"
	message Route133_Text_Chansey
# 110 "data/maps/Route133/scripts.pory"
	waitse
# 111 "data/maps/Route133/scripts.pory"
	playmoncry SPECIES_CHANSEY, 0
# 112 "data/maps/Route133/scripts.pory"
	delay 40
# 113 "data/maps/Route133/scripts.pory"
	waitmoncry
# 114 "data/maps/Route133/scripts.pory"
	closemessage
# 115 "data/maps/Route133/scripts.pory"
	releaseall
# 116 "data/maps/Route133/scripts.pory"
	end
# 117 "data/maps/Route133/scripts.pory"

# 118 "data/maps/Route133/scripts.pory"
Route133_Movement_ChanseyJump:
# 119 "data/maps/Route133/scripts.pory"
	jump_in_place_left
# 120 "data/maps/Route133/scripts.pory"
	delay_4
# 121 "data/maps/Route133/scripts.pory"
	jump_in_place_left
# 122 "data/maps/Route133/scripts.pory"
	step_end
# 123 "data/maps/Route133/scripts.pory"

# 124 "data/maps/Route133/scripts.pory"
Route133_Text_Chansey:
# 125 "data/maps/Route133/scripts.pory"
	.string "Siii!$"
# 126 "data/maps/Route133/scripts.pory"

# 127 "data/maps/Route133/scripts.pory"
Route133_Text_NurseHello:
# 128 "data/maps/Route133/scripts.pory"
	.string "Oh, hey, it's {PLAYER}!\n"
# 129 "data/maps/Route133/scripts.pory"
	.string "Mind giving us a hand?\p"
# 130 "data/maps/Route133/scripts.pory"
	.string "We've been stuck on this island\n"
# 131 "data/maps/Route133/scripts.pory"
	.string "for hours!\p"
# 132 "data/maps/Route133/scripts.pory"
	.string "I Surfed out here on my Audino, but\n"
# 133 "data/maps/Route133/scripts.pory"
	.string "it forgot the move, and then a\l"
# 134 "data/maps/Route133/scripts.pory"
	.string "certain pink blob smashed my Surf HM!\p"
# 135 "data/maps/Route133/scripts.pory"
	.string "Can I borrow yours for a moment?\n"
# 136 "data/maps/Route133/scripts.pory"
	.string "I'll make it worth your while!$"
# 137 "data/maps/Route133/scripts.pory"

# 138 "data/maps/Route133/scripts.pory"
Route133_Text_NurseReally:
# 139 "data/maps/Route133/scripts.pory"
	.string "Really? Please, I'm desperate here!$"
# 140 "data/maps/Route133/scripts.pory"

# 141 "data/maps/Route133/scripts.pory"
Route133_Text_NurseSoYoullHelp:
# 142 "data/maps/Route133/scripts.pory"
	.string "So, can I borrow your Surf HM?\n"
# 143 "data/maps/Route133/scripts.pory"
	.string "It'll only take a moment!$"
# 144 "data/maps/Route133/scripts.pory"

# 145 "data/maps/Route133/scripts.pory"
Route133_Text_NurseTeachAudino:
# 146 "data/maps/Route133/scripts.pory"
	.string "Thanks! I'll just teach it to\n"
# 147 "data/maps/Route133/scripts.pory"
	.string "my Audino…$"
# 148 "data/maps/Route133/scripts.pory"

# 149 "data/maps/Route133/scripts.pory"
Route133_Text_NurseDoneHaveVialUpgrade:
# 150 "data/maps/Route133/scripts.pory"
	.string "And… done!\p"
# 151 "data/maps/Route133/scripts.pory"
	.string "Thanks again, {PLAYER}. As a reward,\n"
# 152 "data/maps/Route133/scripts.pory"
	.string "I'll make sure you get an extra dose\l"
# 153 "data/maps/Route133/scripts.pory"
	.string "whenever you refill your Poké Vial\l"
# 154 "data/maps/Route133/scripts.pory"
	.string "from now on.\p"
# 155 "data/maps/Route133/scripts.pory"
	.string "See you around!$"

Route133_EventScript_LegendaryNPC::
# 158 "data/maps/Route133/scripts.pory"
	lock
# 159 "data/maps/Route133/scripts.pory"
	faceplayer
# 160 "data/maps/Route133/scripts.pory"
	msgbox Route133_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 161 "data/maps/Route133/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route133_EventScript_LegendaryNPC_2
# 183 "data/maps/Route133/scripts.pory"
	msgbox Route133_EventScript_LegendaryNPC_Text_4
Route133_EventScript_LegendaryNPC_1:
# 185 "data/maps/Route133/scripts.pory"
	release
	end

Route133_EventScript_LegendaryNPC_2:
# 162 "data/maps/Route133/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route133_EventScript_LegendaryNPC_5
# 168 "data/maps/Route133/scripts.pory"
	checktrainerflag TRAINER_CONOR
	goto_if 1, Route133_EventScript_LegendaryNPC_11
Route133_EventScript_LegendaryNPC_9:
# 178 "data/maps/Route133/scripts.pory"
	msgbox Route133_EventScript_LegendaryNPC_Text_3
	goto Route133_EventScript_LegendaryNPC_1

Route133_EventScript_LegendaryNPC_5:
# 163 "data/maps/Route133/scripts.pory"
	msgbox Route133_EventScript_LegendaryNPC_Text_1
	goto Route133_EventScript_LegendaryNPC_1

Route133_EventScript_LegendaryNPC_8:
# 175 "data/maps/Route133/scripts.pory"
	msgbox Route133_EventScript_LegendaryNPC_Text_2
	goto Route133_EventScript_LegendaryNPC_1

Route133_EventScript_LegendaryNPC_10:
# 170 "data/maps/Route133/scripts.pory"
	checktrainerflag TRAINER_BECK
	goto_if 1, Route133_EventScript_LegendaryNPC_15
	goto Route133_EventScript_LegendaryNPC_9

Route133_EventScript_LegendaryNPC_11:
# 169 "data/maps/Route133/scripts.pory"
	checktrainerflag TRAINER_MOLLIE
	goto_if 1, Route133_EventScript_LegendaryNPC_10
	goto Route133_EventScript_LegendaryNPC_9

Route133_EventScript_LegendaryNPC_14:
# 172 "data/maps/Route133/scripts.pory"
	checktrainerflag TRAINER_LINDA
	goto_if 1, Route133_EventScript_LegendaryNPC_19
	goto Route133_EventScript_LegendaryNPC_9

Route133_EventScript_LegendaryNPC_15:
# 171 "data/maps/Route133/scripts.pory"
	checktrainerflag TRAINER_WARREN
	goto_if 1, Route133_EventScript_LegendaryNPC_14
	goto Route133_EventScript_LegendaryNPC_9

Route133_EventScript_LegendaryNPC_18:
# 174 "data/maps/Route133/scripts.pory"
	checktrainerflag TRAINER_FRANKLIN
	goto_if 1, Route133_EventScript_LegendaryNPC_8
	goto Route133_EventScript_LegendaryNPC_9

Route133_EventScript_LegendaryNPC_19:
# 173 "data/maps/Route133/scripts.pory"
	checktrainerflag TRAINER_DEBRA
	goto_if 1, Route133_EventScript_LegendaryNPC_18
	goto Route133_EventScript_LegendaryNPC_9


Route133_EventScript_LegendaryNPC_Text_0:
# 160 "data/maps/Route133/scripts.pory"
	.string "Sage: Some more Ultra Beasts reside\n"
	.string "here. Want to know more about them?$"

Route133_EventScript_LegendaryNPC_Text_1:
# 163 "data/maps/Route133/scripts.pory"
	.string "This archipelago is home to the Ultra\n"
	.string "Beasts, creatures from outer space\l"
	.string "that fled their home planets to escape\l"
	.string "Necrozma's hunger.\p"
	.string "Many perished during the trip, many\n"
	.string "more from Calyrex's actions, but some,\l"
	.string "despite all the hardships, survived.\l"
	.string "These lone survivors now reside here.\p"
	.string "These poor creatures are looking for a\n"
	.string "valiant guide: I can tell you're the\l"
	.string "right person for this. Come back once\l"
	.string "you become champion, and I'll tell you\l"
	.string "more about it.$"

Route133_EventScript_LegendaryNPC_Text_2:
# 175 "data/maps/Route133/scripts.pory"
	.string "Yes, I had no doubts: you are worthy of\n"
	.string "meeting the Ultra Beasts. I marked\l"
	.string "their location on your DexNav: use it to\l"
	.string "meet them.$"

Route133_EventScript_LegendaryNPC_Text_3:
# 178 "data/maps/Route133/scripts.pory"
	.string "You remembered our little promise. Good.\n"
	.string "Just one more thing before I show you\l"
	.string "the Beasts' location: there's a couple\l"
	.string "of trainers loose in this route. How\l"
	.string "about you take them down and come back\l"
	.string "to me, yeah?$"

Route133_EventScript_LegendaryNPC_Text_4:
# 183 "data/maps/Route133/scripts.pory"
	.string "Don't lean into calamity.$"
