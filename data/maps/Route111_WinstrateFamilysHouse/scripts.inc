# 1 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 2 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
.set LOCALID_VIVI, 1
# 3 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
.set LOCALID_VICTOR, 2
# 4 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
.set LOCALID_VICTORIA, 3
# 5 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
.set LOCALID_VICKY, 4
# 6 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 7 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_MapScripts:: @ 822A48C
# 8 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.byte 0
# 9 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 10 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_Victor:: @ 822A48D
# 11 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	lock
# 12 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setvar VAR_0x8008, LOCALID_VICTOR
# 14 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
# 15 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 16 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 17 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 18 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_Victoria:: @ 822A4A2
# 19 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	lock
# 20 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	faceplayer
# 21 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setvar VAR_0x8008, LOCALID_VICTORIA
# 22 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_LIFE_ORB, Route111_WinstrateFamilysHouse_EventScript_ReceivedLifeOrb
# 23 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveLifeOrb, MSGBOX_DEFAULT
# 24 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	givecustommon SPECIES_PINSIR, 30, ITEM_FOCUS_SASH, ITEM_SAFARI_BALL, NATURE_JOLLY, 0, 0, 252, 4, 252, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_GUILLOTINE, MOVE_STONE_EDGE, MOVE_SUPERPOWER, MOVE_SWORDS_DANCE, FALSE
# 25 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 26 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	message Route111_WinstrateFamilysHouse_Text_Got_Pinsir
# 27 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	waitfanfare
# 28 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setflag FLAG_RECEIVED_LIFE_ORB
# 29 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 30 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 31 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 32 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_ReceivedLifeOrb:: @ 822A4DA
# 33 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
# 34 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 35 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 36 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 37 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_Vivi:: @ 822A4E8
# 38 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	lock
# 39 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	faceplayer
# 40 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setvar VAR_0x8008, LOCALID_VIVI
# 41 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
# 42 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 43 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 44 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 45 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_Vicky:: @ 822A4FD
# 46 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	lock
# 47 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	faceplayer
# 48 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setvar VAR_0x8008, LOCALID_VICKY
# 49 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
# 50 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
# 51 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	setflag FLAG_TEMP_4
# 52 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 53 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 54 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 55 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo:: @ 822A51E
# 56 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
# 57 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
# 58 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 59 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 60 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection:: @ 822A52C
# 61 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	closemessage
# 62 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
# 63 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	waitmovement 0
# 64 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	release
# 65 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	end
# 66 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 67 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou: @ 822A539
# 68 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "You're the first Trainer I've seen who\n"
# 69 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "deploys Pokémon so masterfully.\p"
# 70 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "But, I should tell you--my son is\n"
# 71 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "stronger than you.\p"
# 72 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "He even took the Pokémon League\n"
# 73 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "challenge, I'll have you know.$"
# 74 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 75 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_LikeYouToHaveLifeOrb: @ 822A5F4
# 76 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "You witnessed the raw power of\n"
# 77 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "my Pinsir in battle.\p"
# 78 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Since you've beaten all of us here,\n"
# 79 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "I don't know if you need it, but I\l"
# 80 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "would like you to have this!$"
# 81 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 82 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles: @ 822A6B4
# 83 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "When it comes to Pokémon battles,\n"
# 84 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "we tend to be pretty passionate.$"
# 85 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 86 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers: @ 822A6F7
# 87 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Mommy is stronger than Daddy.\p"
# 88 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "I'm stronger than Mommy.\p"
# 89 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "And Grandma's stronger than me!\p"
# 90 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "But my big brother is even stronger\n"
# 91 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "than Grandma.$"
# 92 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 93 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_GrandsonStrong: @ 822A780
# 94 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "There's no question that you're strong.\p"
# 95 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "But if you were to battle my grandson,\n"
# 96 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "you'd end up crying in frustration.\p"
# 97 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "He's much stronger than any Trainer\n"
# 98 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "our family knows.\p"
# 99 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "He must be challenging the Pokémon\n"
# 100 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "League Champion by now.\p"
# 101 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Knowing my grandson, he could be the\n"
# 102 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Champion already!$"
# 103 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"

# 104 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort: @ 822A89B
# 105 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "My grandson must be challenging the\n"
# 106 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Pokémon League Champion by now.\p"
# 107 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Knowing my grandson, he could be the\n"
# 108 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "Champion already!$"

Route111_WinstrateFamilysHouse_Text_Got_Pinsir::
# 111 "data/maps/Route111_WinstrateFamilysHouse/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Pinsir{COLOR DARK_GRAY} as a gift!$"
