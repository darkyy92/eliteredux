# 1 "data/maps/GraniteCave_B2F/scripts.pory"

# 2 "data/maps/GraniteCave_B2F/scripts.pory"
GraniteCave_B2F_MapScripts::
# 3 "data/maps/GraniteCave_B2F/scripts.pory"
	.byte 0
# 4 "data/maps/GraniteCave_B2F/scripts.pory"

# 5 "data/maps/GraniteCave_B2F/scripts.pory"
GraniteCave_B2F_SetFlashRadius:
# 6 "data/maps/GraniteCave_B2F/scripts.pory"
	end

GraniteCave_B2F_EventScript_HitmonStone::
# 11 "data/maps/GraniteCave_B2F/scripts.pory"
	lock
# 12 "data/maps/GraniteCave_B2F/scripts.pory"
	faceplayer
# 13 "data/maps/GraniteCave_B2F/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, GraniteCave_B2F_EventScript_HitmonStone_2
# 56 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_8, MSGBOX_NPC
GraniteCave_B2F_EventScript_HitmonStone_1:
# 58 "data/maps/GraniteCave_B2F/scripts.pory"
	release
	end

GraniteCave_B2F_EventScript_HitmonStone_2:
# 15 "data/maps/GraniteCave_B2F/scripts.pory"
	goto_if_unset FLAG_OBTAINED_HITMON_MEGA_STONE, GraniteCave_B2F_EventScript_HitmonStone_5
# 52 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_7, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_5:
# 16 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_0, MSGBOX_YESNO
# 17 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GraniteCave_B2F_EventScript_HitmonStone_8
# 48 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_6, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_8:
# 18 "data/maps/GraniteCave_B2F/scripts.pory"
	checkpartyfortypeornumber TYPE_FIGHTING, 1
# 19 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq GraniteCave_B2F_EventScript_HitmonStone_11
# 44 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_5, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_11:
# 20 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_1, MSGBOX_NPC
# 21 "data/maps/GraniteCave_B2F/scripts.pory"
	random 3
# 22 "data/maps/GraniteCave_B2F/scripts.pory"
	switch VAR_RESULT
# 23 "data/maps/GraniteCave_B2F/scripts.pory"
	case 0, GraniteCave_B2F_EventScript_HitmonStone_16
# 26 "data/maps/GraniteCave_B2F/scripts.pory"
	case 1, GraniteCave_B2F_EventScript_HitmonStone_17
# 29 "data/maps/GraniteCave_B2F/scripts.pory"
	case 2, GraniteCave_B2F_EventScript_HitmonStone_18
GraniteCave_B2F_EventScript_HitmonStone_14:
# 33 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_3, MSGBOX_NPC
# 34 "data/maps/GraniteCave_B2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 35 "data/maps/GraniteCave_B2F/scripts.pory"
	giveitem ITEM_HITMONCHANITE, 1
# 36 "data/maps/GraniteCave_B2F/scripts.pory"
	giveitem ITEM_HITMONLEENITE, 1
# 37 "data/maps/GraniteCave_B2F/scripts.pory"
	giveitem ITEM_HITMONTOPITE, 1
# 38 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_OBTAINED_HITMON_MEGA_STONE
# 39 "data/maps/GraniteCave_B2F/scripts.pory"
	waitfanfare
# 40 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_4, MSGBOX_NPC
# 41 "data/maps/GraniteCave_B2F/scripts.pory"
	waitmessage
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_16:
# 24 "data/maps/GraniteCave_B2F/scripts.pory"
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_1, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14

GraniteCave_B2F_EventScript_HitmonStone_17:
# 27 "data/maps/GraniteCave_B2F/scripts.pory"
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_2, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14

GraniteCave_B2F_EventScript_HitmonStone_18:
# 30 "data/maps/GraniteCave_B2F/scripts.pory"
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_3, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14


GraniteCave_B2F_EventScript_HitmonStone_Text_0:
# 16 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "Greetings, young one. I can tell you\n"
	.string "wield immense strength. How about a\l"
	.string "proposal? If you can defeat one of my\l"
	.string "Pokemon with only one of your own, I will\l"
	.string "grant you these Mega Stones. My\l"
	.string "Pokemon are all Fighting-Type, so I ask\l"
	.string "that you only use Fighting-Types\l"
	.string "yourself.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_1:
# 20 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "Then let the duel start!$"

GraniteCave_B2F_EventScript_HitmonStone_Text_2:
# 24 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "You truly are incredibly strong.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_3:
# 33 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "I am very impressed with your strength.\n"
	.string "As promised, take these Mega Stones.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_4:
# 40 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "Each one corresponds to one of\n"
	.string "Tyrogue's 3 evolutions. Use them well.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_5:
# 44 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "You don't have the correct Pokémon. You\n"
	.string "can only bring 1 Fighting-type into\l"
	.string "this battle.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_6:
# 48 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "I understand. Please, do return\n"
	.string "whenever you are ready.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_7:
# 52 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "My apologies, but I have nothing left\n"
	.string "for you.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_8:
# 56 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "My apologies, but you aren't worthy yet.\n"
	.string "Come back after defeating the\l"
	.string "Mossdeep Twins, and I will speak with\l"
	.string "you.$"
