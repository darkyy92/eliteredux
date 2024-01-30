# 1 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_MapScripts:: @ 826E801
# 3 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.byte 0
# 4 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 5 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Scroll:: @ 826E802
# 6 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	lockall
# 7 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0
# 8 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle8_EventScript_FoundScroll
# 9 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 10 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 11 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 12 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_FoundScroll:: @ 826E814
# 13 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
# 14 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 15 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 16 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 17 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Vincent:: @ 826E81F
# 18 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
# 19 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
# 20 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 21 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 22 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Keira:: @ 826E836
# 23 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
# 24 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
# 25 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 26 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 27 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Leroy:: @ 826E84D
# 28 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
# 29 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
# 30 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	end
# 31 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 32 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_WroteSecretCodeLockOpened:: @ 826E864
# 33 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 34 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "on the door.\p"
# 35 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "“Trick Master I love.”\n"
# 36 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "… … … … … … … …\p"
# 37 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "The lock clicked open!$"
# 38 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 39 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentIntro: @ 826E8CD
# 40 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Not many Trainers have made it\n"
# 41 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "this far.$"
# 42 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 43 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentDefeat: @ 826E8F6
# 44 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "That must mean you're tough, too…$"
# 45 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 46 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_VincentPostBattle: @ 826E918
# 47 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You've beaten the Pokémon League\n"
# 48 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Champion? That's too much!$"
# 49 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 50 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraIntro: @ 826E954
# 51 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Consider yourself lucky to be\n"
# 52 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "battling me!$"
# 53 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 54 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraDefeat: @ 826E97F
# 55 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "This isn't right!\n"
# 56 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "I can't lose!$"
# 57 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 58 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_KeiraPostBattle: @ 826E99F
# 59 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "It's a miracle that you beat me.\n"
# 60 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You can brag about it.$"
# 61 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 62 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyIntro: @ 826E9D7
# 63 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You've been slugging through the Trick\n"
# 64 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "House challenge, too.$"
# 65 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 66 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyDefeat: @ 826EA14
# 67 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "I see…\n"
# 68 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "You possess an extraordinary style.$"
# 69 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"

# 70 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
Route110_TrickHousePuzzle8_Text_LeroyPostBattle: @ 826EA3F
# 71 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "Seeing someone like you should please\n"
# 72 "data/maps/Route110_TrickHousePuzzle8/scripts.pory"
	.string "the Trick Master.$"
