# 1 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_MapScripts:: @ 826B90F
# 3 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
# 4 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.byte 0
# 5 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 6 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_OnLoad: @ 826B915
# 7 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
# 8 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle1_EventScript_OpenDoor
# 9 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 10 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 11 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_OpenDoor:: @ 826B921
# 12 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 13 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 14 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 15 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Scroll:: @ 826B92B
# 16 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	lockall
# 17 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0
# 18 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle1_EventScript_FoundScroll
# 19 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 20 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 21 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 22 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_FoundScroll:: @ 826B93D
# 23 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
# 24 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 25 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 26 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 27 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Sally:: @ 826B948
# 28 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
# 29 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
# 30 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 31 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 32 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Eddie:: @ 826B95F
# 33 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
# 34 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
# 35 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 36 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 37 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Robin:: @ 826B976
# 38 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
# 39 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
# 40 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	end
# 41 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 42 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened:: @ 826B98D
# 43 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 44 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "on the door.\p"
# 45 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "“Trick Master is fabulous.”\n"
# 46 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "… … … … … … … …\p"
# 47 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "The lock clicked open!$"
# 48 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 49 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyIntro: @ 826B9FB
# 50 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I'll hack and slash my way to victory\n"
# 51 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "with the Cut we just learned!$"
# 52 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 53 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyDefeat: @ 826BA3F
# 54 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Why are you so serious?$"
# 55 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 56 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_SallyPostBattle: @ 826BA57
# 57 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I never get tired of hacking\n"
# 58 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "and slashing!$"
# 59 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 60 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddieIntro: @ 826BA82
# 61 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I wandered into this weird house\n"
# 62 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "by accident…$"
# 63 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 64 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddieDefeat: @ 826BAB0
# 65 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "And now I've lost…$"
# 66 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 67 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_EddiePostBattle: @ 826BAC3
# 68 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I lost my way, I lost a battle, and I'm\n"
# 69 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "now even more lost… I can't get out…$"
# 70 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 71 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinIntro: @ 826BB10
# 72 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Just who is the Trick Master?$"
# 73 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 74 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinDefeat: @ 826BB2E
# 75 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "I lost while I was lost in thought!$"
# 76 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"

# 77 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
Route110_TrickHousePuzzle1_Text_RobinPostBattle: @ 826BB52
# 78 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "You're strong!\n"
# 79 "data/maps/Route110_TrickHousePuzzle1/scripts.pory"
	.string "Just who are you?$"
