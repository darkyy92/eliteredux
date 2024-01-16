GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B2F_SetFlashRadius:
	end

GraniteCave_B2F_EventScript_HitmonStone::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, GraniteCave_B2F_EventScript_HitmonStone_2
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_8, MSGBOX_NPC
GraniteCave_B2F_EventScript_HitmonStone_1:
	release
	end

GraniteCave_B2F_EventScript_HitmonStone_2:
	goto_if_unset FLAG_OBTAINED_HITMON_MEGA_STONE, GraniteCave_B2F_EventScript_HitmonStone_5
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_7, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_5:
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq GraniteCave_B2F_EventScript_HitmonStone_8
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_6, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_8:
	checkpartyfortypeornumber TYPE_FIGHTING, 1
	compare VAR_RESULT, 1
	goto_if_eq GraniteCave_B2F_EventScript_HitmonStone_11
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_5, MSGBOX_NPC
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_11:
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_1, MSGBOX_NPC
	random 3
	switch VAR_RESULT
	case 0, GraniteCave_B2F_EventScript_HitmonStone_16
	case 1, GraniteCave_B2F_EventScript_HitmonStone_17
	case 2, GraniteCave_B2F_EventScript_HitmonStone_18
GraniteCave_B2F_EventScript_HitmonStone_14:
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_HITMONCHANITE, 1
	giveitem ITEM_HITMONLEENITE, 1
	giveitem ITEM_HITMONTOPITE, 1
	setflag FLAG_OBTAINED_HITMON_MEGA_STONE
	waitfanfare
	msgbox GraniteCave_B2F_EventScript_HitmonStone_Text_4, MSGBOX_NPC
	waitmessage
	goto GraniteCave_B2F_EventScript_HitmonStone_1

GraniteCave_B2F_EventScript_HitmonStone_16:
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_1, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14

GraniteCave_B2F_EventScript_HitmonStone_17:
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_2, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14

GraniteCave_B2F_EventScript_HitmonStone_18:
	trainerbattle_no_intro TRAINER_HITMONSTONE_BLACKBELT_3, GraniteCave_B2F_EventScript_HitmonStone_Text_2
	goto GraniteCave_B2F_EventScript_HitmonStone_14


GraniteCave_B2F_EventScript_HitmonStone_Text_0:
	.string "Greetings, young one. I can tell you\n"
	.string "wield immense strength. How about a\l"
	.string "proposal? If you can defeat one of my\l"
	.string "Pokemon with only one of your own, I\l"
	.string "will grant you these Mega Stones. My\l"
	.string "Pokemon are all Fighting-Type, so I ask\l"
	.string "that you only use Fighting-Types\l"
	.string "yourself.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_1:
	.string "Then let the duel start!$"

GraniteCave_B2F_EventScript_HitmonStone_Text_2:
	.string "You truly are incredibly strong.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_3:
	.string "I am very impressed with your strength.\n"
	.string "As promised, take these Mega Stones.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_4:
	.string "Each one corresponds to one of\n"
	.string "Tyrogue's 3 evolutions. Use them well.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_5:
	.string "You don't have the correct Pokémon. You\n"
	.string "can only bring 1 Fighting-type into\l"
	.string "this battle.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_6:
	.string "I understand. Please, do return\n"
	.string "whenever you are ready.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_7:
	.string "My apologies, but I have nothing left\n"
	.string "for you.$"

GraniteCave_B2F_EventScript_HitmonStone_Text_8:
	.string "My apologies, but you aren't worthy yet.\n"
	.string "Come back after defeating the\l"
	.string "Mossdeep Twins, and I will speak with\l"
	.string "you.$"
