# 1 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 2 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_MapScripts:: @ 822C4DD
# 3 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.byte 0
# 4 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 5 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_Nicolas:: @ 822C4DE
# 6 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
# 7 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 8 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	compare VAR_RESULT, TRUE
# 9 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq MeteorFalls_1F_2R_EventScript_RematchNicolas
# 10 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
# 11 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 12 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 13 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 14 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RegisterNicolas:: @ 822C50A
# 15 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 16 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	waitmovement 0
# 17 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
# 18 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	register_matchcall TRAINER_NICOLAS_1
# 19 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 20 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 21 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 22 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RematchNicolas:: @ 822C529
# 23 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
# 24 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
# 25 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 26 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 27 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_John:: @ 822C540
# 28 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
# 29 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 30 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	compare VAR_RESULT, TRUE
# 31 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq MeteorFalls_1F_2R_EventScript_RematchJohn
# 32 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
# 33 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 34 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 35 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 36 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RegisterJohn:: @ 822C570
# 37 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
# 38 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	register_matchcall TRAINER_JOHN_AND_JAY_1
# 39 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 40 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 41 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 42 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RematchJohn:: @ 822C589
# 43 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
# 44 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
# 45 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 46 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 47 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_Jay:: @ 822C5A4
# 48 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
# 49 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 50 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	compare VAR_RESULT, TRUE
# 51 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq MeteorFalls_1F_2R_EventScript_RematchJay
# 52 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
# 53 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 54 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 55 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 56 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RegisterJay:: @ 822C5D4
# 57 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
# 58 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	register_matchcall TRAINER_JOHN_AND_JAY_1
# 59 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 60 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 61 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 62 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_EventScript_RematchJay:: @ 822C5ED
# 63 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
# 64 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
# 65 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 66 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 67 "data/maps/MeteorFalls_1F_2R/scripts.pory"
Meteor_Falls1F_2R_EventScript_DragonAscentTutor::
# 68 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	lock
# 69 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	faceplayer
# 70 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MoveTutor_Text_DragonAscentTeach, MSGBOX_YESNO
# 71 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	compare VAR_RESULT, NO
# 72 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq MoveTutor_EventScript_DragonAscentDeclined
# 73 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	call Meteor_Falls1F_2R_EventScript_RayquazaCheck
# 74 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MoveTutor_Text_DragonAscentWhichMon, MSGBOX_DEFAULT
# 75 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	setvar VAR_0x8005, TUTOR_MOVE_DRAGON_ASCENT
# 76 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 77 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	compare VAR_RESULT, 0
# 78 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq MoveTutor_EventScript_DragonAscentDeclined
# 79 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto MoveTutor_EventScript_DragonAscentTaught
# 80 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 81 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 82 "data/maps/MeteorFalls_1F_2R/scripts.pory"
Meteor_Falls1F_2R_EventScript_RayquazaCheck::
# 83 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	checkPartyHasSpecies SPECIES_RAYQUAZA
# 84 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	compare VAR_RESULT, FALSE
# 85 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	goto_if_eq Meteor_Falls1F_2R_EventScript_DragonAscentNoFug
# 86 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	return
# 87 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 88 "data/maps/MeteorFalls_1F_2R/scripts.pory"
Meteor_Falls1F_2R_EventScript_DragonAscentNoFug::
# 89 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MoveTutor_Text_DragonAscentNoFug, MSGBOX_DEFAULT
# 90 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 91 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 92 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 93 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MoveTutor_EventScript_DragonAscentDeclined::
# 94 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MoveTutor_Text_DragonAscentDeclined, MSGBOX_DEFAULT
# 95 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 96 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 97 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 98 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MoveTutor_EventScript_DragonAscentTaught::
# 99 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MoveTutor_Text_DragonAscentTaught, MSGBOX_DEFAULT
# 100 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	release
# 101 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	end
# 102 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 103 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MoveTutor_EventScript_OpenPartyMenu::
# 104 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	special ChooseMonForMoveTutor
# 105 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	waitstate
# 106 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	lock
# 107 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	faceplayer
# 108 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	return
# 109 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 110 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasIntro: @ 822C608
# 111 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "This is where we Dragon users do our\n"
# 112 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "training.\p"
# 113 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "The Champion even visits.\n"
# 114 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Now do you see how special it is here?$"
# 115 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 116 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasDefeat: @ 822C678
# 117 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Urgh!\n"
# 118 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I didn't expect you to be so strong!$"
# 119 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 120 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasPostBattle: @ 822C6A3
# 121 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "The road ahead remains long and harsh.\p"
# 122 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "When will my Pokémon and I become\n"
# 123 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "the best?$"
# 124 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 125 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasRegister: @ 822C6F6
# 126 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I want to know more about your power.\n"
# 127 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Let me register you in my PokéNav.$"
# 128 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 129 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasRematchIntro: @ 822C73F
# 130 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Since we met, we have trained hard\n"
# 131 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "with our sights on number one.\p"
# 132 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Help us see how much stronger we've\n"
# 133 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "become!$"
# 134 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 135 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasRematchDefeat: @ 822C7AD
# 136 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Urgh!\n"
# 137 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I didn't expect you to be so strong!$"
# 138 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 139 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_NicolasPostRematch: @ 822C7D8
# 140 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "You've obviously kept up your\n"
# 141 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Pokémon training.\p"
# 142 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "So long as you remain strong, I, too,\n"
# 143 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "can become stronger!$"
# 144 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 145 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnIntro: @ 822C843
# 146 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: We've always battled Pokémon\n"
# 147 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "together as a twosome.\l"
# 148 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've confidence in ourselves.$"
# 149 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 150 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnDefeat: @ 822C89C
# 151 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: Oh, my.\n"
# 152 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've lost, dear wife.$"
# 153 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 154 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnPostBattle: @ 822C8C1
# 155 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: We've been married for\n"
# 156 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "fifty years.\p"
# 157 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Come to think of it, I've yet to beat\n"
# 158 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "my dear wife in a battle.$"
# 159 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 160 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnNotEnoughMons: @ 822C92B
# 161 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: Well, well, what a young Trainer!\p"
# 162 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Will you battle with us? If so, you'll\n"
# 163 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "have to return with more Pokémon.$"
# 164 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 165 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnRegister: @ 822C99C
# 166 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: Young Trainer, if the chance\n"
# 167 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "arises, will you battle with us again?$"
# 168 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 169 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayIntro: @ 822C9E6
# 170 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Jay: We've been married for\n"
# 171 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "fifty years.\p"
# 172 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "The bond we share as a couple could\n"
# 173 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "never be broken.$"
# 174 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 175 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayDefeat: @ 822CA44
# 176 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Jay: Oh, dear.\n"
# 177 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've lost, my dear husband.$"
# 178 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 179 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayPostBattle: @ 822CA70
# 180 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Jay: Fifty years of marriage…\p"
# 181 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "If we ever argued, we always settled\n"
# 182 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "it with a Pokémon battle…$"
# 183 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 184 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayNotEnoughMons: @ 822CACD
# 185 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Jay: Well, well, aren't you a young\n"
# 186 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Trainer?\p"
# 187 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "If you'd care to battle with us, you'll\n"
# 188 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "have to come back with more Pokémon.$"
# 189 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 190 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnRematchIntro: @ 822CB47
# 191 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: We've always battled Pokémon\n"
# 192 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "together as a twosome.\l"
# 193 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've confidence in ourselves.$"
# 194 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 195 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnRematchDefeat: @ 822CBA0
# 196 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: Oh, my.\n"
# 197 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've lost, dear wife.$"
# 198 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 199 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnPostRematch: @ 822CBC5
# 200 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: Married for fifty years…\p"
# 201 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "On reflection, the dear wife and I,\n"
# 202 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "we battled day in and day out…$"
# 203 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 204 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons: @ 822CC27
# 205 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "John: Well, well, what a young Trainer!\p"
# 206 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Will you battle with us? If so, you'll\n"
# 207 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "have to return with more Pokémon.$"
# 208 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 209 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayRematchIntro: @ 822CC98
# 210 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Jay: We've been married for\n"
# 211 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "fifty years.\p"
# 212 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've supported each other all that\n"
# 213 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "time. We've made ourselves strong.$"
# 214 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 215 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayRematchDefeat: @ 822CD08
# 216 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Jay: Oh, dear.\n"
# 217 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "We've lost, my dear husband.$"
# 218 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 219 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayPostRematch: @ 822CD34
# 220 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Jay: Fifty years of marriage…\n"
# 221 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Many things have happened.\p"
# 222 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I hope that we will continue to make\n"
# 223 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "happy memories together.$"
# 224 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 225 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons: @ 822CDAB
# 226 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Jay: Well, well, aren't you a young\n"
# 227 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Trainer?\p"
# 228 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "If you'd care to battle with us, you'll\n"
# 229 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "have to come back with more Pokémon.$"
# 230 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 231 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MoveTutor_Text_DragonAscentTeach:
# 232 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Hmm… Do you want me to teach\n"
# 233 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Dragon Ascent to your Pokémon?$"
# 234 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 235 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MoveTutor_Text_DragonAscentWhichMon:
# 236 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Which Pokémon do you want me to teach\n"
# 237 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "the move?$"
# 238 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 239 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MoveTutor_Text_DragonAscentNoFug:
# 240 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Hmm… Only Rayquaza can learn\n"
# 241 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Dragon Ascent.\l"
# 242 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "You don't seem to have one.$"
# 243 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 244 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MoveTutor_Text_DragonAscentDeclined:
# 245 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Hmm… I see.\n"
# 246 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Come back anytime you need my help.$"
# 247 "data/maps/MeteorFalls_1F_2R/scripts.pory"

# 248 "data/maps/MeteorFalls_1F_2R/scripts.pory"
MoveTutor_Text_DragonAscentTaught:
# 249 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Dragon Ascent is a powerful move that\n"
# 250 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "only Rayquaza can use.\p"
# 251 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "They say its power is so strong that\n"
# 252 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "even a huge meteoroid can be broken\l"
# 253 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "into pieces with one attack.$"
