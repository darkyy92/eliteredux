# 1 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 2 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_MapScripts:: @ 822AD30
# 3 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
# 4 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 6 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_OnTransition: @ 822AD36
# 7 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
# 8 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 9 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 10 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother:: @ 822AD3A
# 11 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	lock
# 12 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM28, Route114_FossilManiacsHouse_EventScript_ReceivedDig
# 14 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
# 15 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	giveitem ITEM_TM28_DIG
# 16 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 17 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 18 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	setflag FLAG_RECEIVED_TM28
# 19 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	release
# 20 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 21 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 22 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_EventScript_ReceivedDig:: @ 822AD69
# 23 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
# 24 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	release
# 25 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 26 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 27 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_EventScript_RockDisplay:: @ 822AD73
# 28 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
# 29 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 30 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 31 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_EventScript_Bookshelf:: @ 822AD7C
# 32 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
# 33 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	end
# 34 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 35 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother: @ 822AD85
# 36 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "My big brother's the Fossil Maniac…\n"
# 37 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "He's a nice guy who loves Fossils…\p"
# 38 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "He loves digging holes, too…\n"
# 39 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "He dug this hole by himself…\p"
# 40 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "You can have this, so you can Dig\n"
# 41 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "holes just like my big brother…$"
# 42 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 43 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance: @ 822AE48
# 44 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "If you make a Pokémon Dig inside a\n"
# 45 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "cave, you're returned to the entrance…$"
# 46 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 47 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_Text_RocksFillDisplayCase: @ 822AE92
# 48 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "Rocks in peculiar shapes fill\n"
# 49 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "the display case…$"
# 50 "data/maps/Route114_FossilManiacsHouse/scripts.pory"

# 51 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
Route114_FossilManiacsHouse_Text_CrammedWithBooks: @ 822AEC2
# 52 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "THE COMPOSITION OF STRATA…\n"
# 53 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "HOW RAIN SHAPES THE LAND…\l"
# 54 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "STONES, SOIL, AND ROCK…\p"
# 55 "data/maps/Route114_FossilManiacsHouse/scripts.pory"
	.string "It's crammed with books.$"
