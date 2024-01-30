# 1 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_MapScripts:: @ 826C860
# 3 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.byte 0
# 4 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 5 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Scroll:: @ 826C861
# 6 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	lockall
# 7 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0
# 8 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle4_EventScript_FoundScroll
# 9 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 10 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 11 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 12 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_FoundScroll:: @ 826C873
# 13 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
# 14 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 15 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 16 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 17 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Cora:: @ 826C87E
# 18 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
# 19 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
# 20 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 21 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 22 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Yuji:: @ 826C895
# 23 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
# 24 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
# 25 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 26 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 27 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Paula:: @ 826C8AC
# 28 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
# 29 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
# 30 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	end
# 31 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 32 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened: @ 826C8C3
# 33 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 34 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "on the door.\p"
# 35 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "“Trick Master is cool.”\n"
# 36 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "… … … … … … … …\p"
# 37 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "The lock clicked open!$"
# 38 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 39 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraIntro: @ 826C92D
# 40 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "It's too much bother to think this out.\n"
# 41 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "I only wanted to battle!$"
# 42 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 43 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraDefeat: @ 826C96E
# 44 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Even though I lost, I still like battling\n"
# 45 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "the best!$"
# 46 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 47 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_CoraPostBattle: @ 826C9A2
# 48 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Wouldn't you agree? You would go\n"
# 49 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "anywhere if Trainers were there.$"
# 50 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 51 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiIntro: @ 826C9E4
# 52 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Heh! Boulders like this, I can brush\n"
# 53 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "aside with one finger!$"
# 54 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 55 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiDefeat: @ 826CA20
# 56 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "I can push boulders, but I can't solve\n"
# 57 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "the puzzle…$"
# 58 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 59 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_YujiPostBattle: @ 826CA53
# 60 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "It's not good enough to be brawny…\n"
# 61 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "You have to use your head. Be brainy!$"
# 62 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 63 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaIntro: @ 826CA9C
# 64 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "The Trick House is getting trickier,\n"
# 65 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "isn't it?$"
# 66 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 67 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaDefeat: @ 826CACB
# 68 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Aaak!$"
# 69 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"

# 70 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
Route110_TrickHousePuzzle4_Text_PaulaPostBattle: @ 826CAD1
# 71 "data/maps/Route110_TrickHousePuzzle4/scripts.pory"
	.string "Has anyone made it to the end?$"
