# 1 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_MapScripts:: @ 826DDA7
# 3 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
# 4 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
# 5 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.byte 0
# 6 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 7 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_OnTransition: @ 826DDB2
# 8 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	special RotatingGate_InitPuzzle
# 9 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 10 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 11 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_OnWarp: @ 826DDB6
# 12 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
# 13 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.2byte 0
# 14 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 15 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_InitPuzzle:: @ 826DDC0
# 16 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	special RotatingGate_InitPuzzleAndGraphics
# 17 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 18 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 19 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Scroll:: @ 826DDC4
# 20 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	lockall
# 21 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0
# 22 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle6_EventScript_FoundScroll
# 23 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 24 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 25 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 26 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_FoundScroll:: @ 826DDD6
# 27 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
# 28 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 29 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 30 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 31 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Sophia:: @ 826DDE1
# 32 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
# 33 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
# 34 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 35 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 36 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Benny:: @ 826DDF8
# 37 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
# 38 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
# 39 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 40 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 41 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Sebastian:: @ 826DE0F
# 42 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
# 43 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
# 44 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	end
# 45 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 46 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened: @ 826DE26
# 47 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 48 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "on the door.\p"
# 49 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "“Trick Master is my life.”\n"
# 50 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "… … … … … … … …\p"
# 51 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "The lock clicked open!$"
# 52 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 53 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SophiaIntro: @ 826DE93
# 54 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "When I heard there was a strange\n"
# 55 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "house, I had to check it out.$"
# 56 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 57 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SophiaDefeat: @ 826DED2
# 58 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "I've discovered a tough Trainer!$"
# 59 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 60 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SophiaPostBattle: @ 826DEF3
# 61 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "I'm sure having a good time checking\n"
# 62 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "this place out.\p"
# 63 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "It's a challenge I've found worth\n"
# 64 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "repeating!$"
# 65 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 66 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_BennyIntro: @ 826DF55
# 67 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Maybe I could get my Bird Pokémon\n"
# 68 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "to fly over the wall…$"
# 69 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 70 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_BennyDefeat: @ 826DF8D
# 71 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Gwaaah! I blew it!$"
# 72 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 73 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_BennyPostBattle: @ 826DFA0
# 74 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Ehehehe… I guess I lost because\n"
# 75 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "I was trying to cheat.$"
# 76 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 77 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SebastianIntro: @ 826DFD7
# 78 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "I'm getting dizzy from these rotating\n"
# 79 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "doors…$"
# 80 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 81 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SebastianDefeat: @ 826E004
# 82 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Everything's spinning around and\n"
# 83 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "around. I can't take this anymore…$"
# 84 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"

# 85 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
Route110_TrickHousePuzzle6_Text_SebastianPostBattle: @ 826E048
# 86 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "You don't seem to be affected at all.\n"
# 87 "data/maps/Route110_TrickHousePuzzle6/scripts.pory"
	.string "Or do you have your poker face on?$"
