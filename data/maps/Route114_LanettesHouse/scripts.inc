# 1 "data/maps/Route114_LanettesHouse/scripts.pory"

# 2 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_MapScripts:: @ 822B2C8
# 3 "data/maps/Route114_LanettesHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
# 4 "data/maps/Route114_LanettesHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route114_LanettesHouse/scripts.pory"

# 6 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_OnTransition: @ 822B2CE
# 7 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_LANDMARK_LANETTES_HOUSE
# 8 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 9 "data/maps/Route114_LanettesHouse/scripts.pory"

# 10 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_Lanette:: @ 822B2D2
# 11 "data/maps/Route114_LanettesHouse/scripts.pory"
	lock
# 12 "data/maps/Route114_LanettesHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
# 14 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_SYS_PC_LANETTE
# 15 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
# 16 "data/maps/Route114_LanettesHouse/scripts.pory"
	givedecoration DECOR_LOTAD_DOLL
# 17 "data/maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 18 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowNoRoomForDecor
# 19 "data/maps/Route114_LanettesHouse/scripts.pory"
	givedecoration DECOR_SEEDOT_DOLL
# 20 "data/maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 21 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowNoRoomForDecor
# 22 "data/maps/Route114_LanettesHouse/scripts.pory"
	setflag FLAG_RECEIVED_DOLL_LANETTE
# 23 "data/maps/Route114_LanettesHouse/scripts.pory"
	release
# 24 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 25 "data/maps/Route114_LanettesHouse/scripts.pory"

# 26 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_OfferAdvice:: @ 822B2FF
# 27 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
# 28 "data/maps/Route114_LanettesHouse/scripts.pory"
	release
# 29 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 30 "data/maps/Route114_LanettesHouse/scripts.pory"

# 31 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_Notebook:: @ 822B309
# 32 "data/maps/Route114_LanettesHouse/scripts.pory"
	lockall
# 33 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
# 34 "data/maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, YES
# 35 "data/maps/Route114_LanettesHouse/scripts.pory"
	goto_if_eq Route114_LanettesHouse_EventScript_NotebookPage2
# 36 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
# 37 "data/maps/Route114_LanettesHouse/scripts.pory"
	releaseall
# 38 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 39 "data/maps/Route114_LanettesHouse/scripts.pory"

# 40 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_NotebookPage2:: @ 822B327
# 41 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
# 42 "data/maps/Route114_LanettesHouse/scripts.pory"
	compare VAR_RESULT, YES
# 43 "data/maps/Route114_LanettesHouse/scripts.pory"
	call_if_eq Route114_LanettesHouse_EventScript_NotebookPage3
# 44 "data/maps/Route114_LanettesHouse/scripts.pory"
	releaseall
# 45 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 46 "data/maps/Route114_LanettesHouse/scripts.pory"

# 47 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_NotebookPage3:: @ 822B33C
# 48 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
# 49 "data/maps/Route114_LanettesHouse/scripts.pory"
	return
# 50 "data/maps/Route114_LanettesHouse/scripts.pory"

# 51 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_EventScript_PC:: @ 822B345
# 52 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
# 53 "data/maps/Route114_LanettesHouse/scripts.pory"
	end
# 54 "data/maps/Route114_LanettesHouse/scripts.pory"

# 55 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_EverythingClutteredKeepThis: @ 822B34E
# 56 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Lanette: Oh! {PLAYER}{KUN}!\p"
# 57 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "I'm sorry everything is so cluttered…\n"
# 58 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "When I get engrossed in research,\l"
# 59 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "things end up this way…\p"
# 60 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "This is embarrassing… Please keep\n"
# 61 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "this a secret in exchange for these.$"
# 62 "data/maps/Route114_LanettesHouse/scripts.pory"

# 63 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_OrganizeYourBoxes: @ 822B407
# 64 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "May I offer advice about my Pokémon\n"
# 65 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Storage System?\p"
# 66 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "You should organize your Boxes so you\n"
# 67 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "can tell which Pokémon are in them.$"
# 68 "data/maps/Route114_LanettesHouse/scripts.pory"

# 69 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage1: @ 822B485
# 70 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "It's Lanette's research notes.\n"
# 71 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "There's information about Boxes.\p"
# 72 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Design Boxes to hold 30 Pokémon each.\p"
# 73 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Each Trainer should be able to store\n"
# 74 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "420 Pokémon on the PC system.\p"
# 75 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Keep reading?$"
# 76 "data/maps/Route114_LanettesHouse/scripts.pory"

# 77 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage2: @ 822B53C
# 78 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "A marking system should be added to\n"
# 79 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "make Pokémon easier to organize.\p"
# 80 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "The name and wallpaper design of each\n"
# 81 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Box will be made changeable to please\l"
# 82 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "the stored Pokémon.\p"
# 83 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Keep reading?$"
# 84 "data/maps/Route114_LanettesHouse/scripts.pory"

# 85 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ResearchNotesPage3: @ 822B5EF
# 86 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "When storing a Pokémon, it should be\n"
# 87 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "sent to the Box inspected last.\p"
# 88 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "If that Box is full, the received\n"
# 89 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "Pokémon is stored in the next Box.\p"
# 90 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "In other words, when a Box is examined,\n"
# 91 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "it is automatically selected as the Box\l"
# 92 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "to which Pokémon are sent.$"
# 93 "data/maps/Route114_LanettesHouse/scripts.pory"

# 94 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_ClosedTheNotebook: @ 822B6E4
# 95 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "{PLAYER} closed the notebook.$"
# 96 "data/maps/Route114_LanettesHouse/scripts.pory"

# 97 "data/maps/Route114_LanettesHouse/scripts.pory"
Route114_LanettesHouse_Text_EmailFromBill: @ 822B6FC
# 98 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "There's an e-mail from someone on\n"
# 99 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "the PC.\p"
# 100 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“… … … … … … …\p"
# 101 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“Your Storage System offers more\n"
# 102 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "convenience than mine.\p"
# 103 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“It has a lot of user-friendly features\n"
# 104 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "that make it fun and useful, too.\p"
# 105 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“It makes me proud that I played\n"
# 106 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "a part in its development.\p"
# 107 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“Here's hoping that you'll continue\n"
# 108 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "research in Storage Systems.\p"
# 109 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "“From Bill\n"
# 110 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "… … … … … … … …”$"
