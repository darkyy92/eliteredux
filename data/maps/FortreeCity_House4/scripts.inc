# 1 "data/maps/FortreeCity_House4/scripts.pory"

# 2 "data/maps/FortreeCity_House4/scripts.pory"
.set LOCALID_WINGULL, 3
# 3 "data/maps/FortreeCity_House4/scripts.pory"

# 4 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_MapScripts:: @ 8217C80
# 5 "data/maps/FortreeCity_House4/scripts.pory"
	.byte 0
# 6 "data/maps/FortreeCity_House4/scripts.pory"

# 7 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_Woman:: @ 8217C81
# 8 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
# 9 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 10 "data/maps/FortreeCity_House4/scripts.pory"

# 11 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_Boy:: @ 8217C8A
# 12 "data/maps/FortreeCity_House4/scripts.pory"
	lockall
# 13 "data/maps/FortreeCity_House4/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHOICE_SCARF, FortreeCity_House4_EventScript_ReceivedMentalHerb
# 14 "data/maps/FortreeCity_House4/scripts.pory"
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
# 15 "data/maps/FortreeCity_House4/scripts.pory"
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
# 16 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
# 17 "data/maps/FortreeCity_House4/scripts.pory"
	closemessage
# 18 "data/maps/FortreeCity_House4/scripts.pory"
	setflag FLAG_WINGULL_SENT_ON_ERRAND
# 19 "data/maps/FortreeCity_House4/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
# 20 "data/maps/FortreeCity_House4/scripts.pory"
	applymovement LOCALID_WINGULL, FortreeCity_House4_Movement_WingullExit
# 21 "data/maps/FortreeCity_House4/scripts.pory"
	waitmovement 0
# 22 "data/maps/FortreeCity_House4/scripts.pory"
	removeobject LOCALID_WINGULL
# 23 "data/maps/FortreeCity_House4/scripts.pory"
	releaseall
# 24 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 25 "data/maps/FortreeCity_House4/scripts.pory"

# 26 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_WingullOnErrand:: @ 8217CC4
# 27 "data/maps/FortreeCity_House4/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 28 "data/maps/FortreeCity_House4/scripts.pory"
	waitmovement 0
# 29 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
# 30 "data/maps/FortreeCity_House4/scripts.pory"
	releaseall
# 31 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 32 "data/maps/FortreeCity_House4/scripts.pory"

# 33 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_WingullReturned:: @ 8217CD8
# 34 "data/maps/FortreeCity_House4/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 35 "data/maps/FortreeCity_House4/scripts.pory"
	waitmovement 0
# 36 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
# 37 "data/maps/FortreeCity_House4/scripts.pory"
	giveitem ITEM_CHOICE_SCARF
# 38 "data/maps/FortreeCity_House4/scripts.pory"
	compare VAR_RESULT, FALSE
# 39 "data/maps/FortreeCity_House4/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 40 "data/maps/FortreeCity_House4/scripts.pory"
	setflag FLAG_RECEIVED_CHOICE_SCARF
# 41 "data/maps/FortreeCity_House4/scripts.pory"
	releaseall
# 42 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 43 "data/maps/FortreeCity_House4/scripts.pory"

# 44 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_ReceivedMentalHerb:: @ 8217D06
# 45 "data/maps/FortreeCity_House4/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 46 "data/maps/FortreeCity_House4/scripts.pory"
	waitmovement 0
# 47 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
# 48 "data/maps/FortreeCity_House4/scripts.pory"
	releaseall
# 49 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 50 "data/maps/FortreeCity_House4/scripts.pory"

# 51 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Movement_WingullExit: @ 8217D1A
# 52 "data/maps/FortreeCity_House4/scripts.pory"
	walk_fast_down
# 53 "data/maps/FortreeCity_House4/scripts.pory"
	walk_fast_down
# 54 "data/maps/FortreeCity_House4/scripts.pory"
	walk_fast_right
# 55 "data/maps/FortreeCity_House4/scripts.pory"
	walk_in_place_fastest_down
# 56 "data/maps/FortreeCity_House4/scripts.pory"
	delay_8
# 57 "data/maps/FortreeCity_House4/scripts.pory"
	step_end
# 58 "data/maps/FortreeCity_House4/scripts.pory"

# 59 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_EventScript_Wingull:: @ 8217D20
# 60 "data/maps/FortreeCity_House4/scripts.pory"
	lock
# 61 "data/maps/FortreeCity_House4/scripts.pory"
	faceplayer
# 62 "data/maps/FortreeCity_House4/scripts.pory"
	waitse
# 63 "data/maps/FortreeCity_House4/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 64 "data/maps/FortreeCity_House4/scripts.pory"
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
# 65 "data/maps/FortreeCity_House4/scripts.pory"
	waitmoncry
# 66 "data/maps/FortreeCity_House4/scripts.pory"
	release
# 67 "data/maps/FortreeCity_House4/scripts.pory"
	end
# 68 "data/maps/FortreeCity_House4/scripts.pory"

# 69 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_BringsWorldCloserTogether: @ 8217D33
# 70 "data/maps/FortreeCity_House4/scripts.pory"
	.string "By being together with Pokémon,\n"
# 71 "data/maps/FortreeCity_House4/scripts.pory"
	.string "people make more and more friends.\p"
# 72 "data/maps/FortreeCity_House4/scripts.pory"
	.string "And that brings the world closer\n"
# 73 "data/maps/FortreeCity_House4/scripts.pory"
	.string "together. I think it's wonderful!$"
# 74 "data/maps/FortreeCity_House4/scripts.pory"

# 75 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_GoBirdPokemon: @ 8217DB9
# 76 "data/maps/FortreeCity_House4/scripts.pory"
	.string "There!\n"
# 77 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Go, Bird Pokémon!$"
# 78 "data/maps/FortreeCity_House4/scripts.pory"

# 79 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_AskedWingullToRunErrand: @ 8217DD2
# 80 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Heheh, I asked my Wingull to run\n"
# 81 "data/maps/FortreeCity_House4/scripts.pory"
	.string "an errand for me.$"
# 82 "data/maps/FortreeCity_House4/scripts.pory"

# 83 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb: @ 8217E05
# 84 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Good!\n"
# 85 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Welcome back, Wingull!\p"
# 86 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Huh? What is this?\n"
# 87 "data/maps/FortreeCity_House4/scripts.pory"
	.string "What is it holding?\p"
# 88 "data/maps/FortreeCity_House4/scripts.pory"
	.string "A Choice Scarf?\n"
# 89 "data/maps/FortreeCity_House4/scripts.pory"
	.string "It must have picked it up somewhere.\p"
# 90 "data/maps/FortreeCity_House4/scripts.pory"
	.string "But I'm not a Trainer, so you can\n"
# 91 "data/maps/FortreeCity_House4/scripts.pory"
	.string "have it.$"
# 92 "data/maps/FortreeCity_House4/scripts.pory"

# 93 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_FriendsFarAwayThanksToWingull: @ 8217EA8
# 94 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Thanks to my Wingull, I have friends\n"
# 95 "data/maps/FortreeCity_House4/scripts.pory"
	.string "who live far away.$"
# 96 "data/maps/FortreeCity_House4/scripts.pory"

# 97 "data/maps/FortreeCity_House4/scripts.pory"
FortreeCity_House4_Text_Wingull: @ 8217EE0
# 98 "data/maps/FortreeCity_House4/scripts.pory"
	.string "Wingull: Pihyoh!$"
