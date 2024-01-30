# 1 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 2 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_MapScripts:: @ 826BB73
# 3 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHousePuzzle2_OnResume
# 4 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle2_OnTransition
# 5 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.byte 0
# 6 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 7 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_OnResume: @ 826BB7E
# 8 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	compare VAR_TEMP_1, 1
# 9 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton1
# 10 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	compare VAR_TEMP_2, 1
# 11 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton2
# 12 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	compare VAR_TEMP_3, 1
# 13 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton3
# 14 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	compare VAR_TEMP_4, 1
# 15 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	call_if_eq Route110_TrickHousePuzzle2_EventScript_PressButton4
# 16 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 17 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 18 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_OnTransition: @ 826BBAB
# 19 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_1, 0
# 20 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_2, 0
# 21 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_3, 0
# 22 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_4, 0
# 23 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 24 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 25 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Scroll:: @ 826BBC0
# 26 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 27 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0
# 28 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle2_EventScript_FoundScroll
# 29 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
# 30 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 31 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 32 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_FoundScroll:: @ 826BBD2
# 33 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 1
# 34 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
# 35 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 36 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 37 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Button1:: @ 826BBDD
# 38 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 39 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_1, 1
# 40 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	playse SE_PIN
# 41 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	call Route110_TrickHousePuzzle2_EventScript_PressButton1
# 42 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	special DrawWholeMapView
# 43 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	releaseall
# 44 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 45 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 46 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Button2:: @ 826BBF0
# 47 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 48 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_2, 1
# 49 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	playse SE_PIN
# 50 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	call Route110_TrickHousePuzzle2_EventScript_PressButton2
# 51 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	special DrawWholeMapView
# 52 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	releaseall
# 53 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 54 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 55 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Button3:: @ 826BC03
# 56 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 57 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_3, 1
# 58 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	playse SE_PIN
# 59 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	call Route110_TrickHousePuzzle2_EventScript_PressButton3
# 60 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	special DrawWholeMapView
# 61 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	releaseall
# 62 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 63 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 64 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Button4:: @ 826BC16
# 65 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	lockall
# 66 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setvar VAR_TEMP_4, 1
# 67 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	playse SE_PIN
# 68 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	call Route110_TrickHousePuzzle2_EventScript_PressButton4
# 69 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	special DrawWholeMapView
# 70 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	releaseall
# 71 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 72 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 73 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_PressButton1:: @ 826BC29
# 74 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 11, 12, METATILE_TrickHousePuzzle_Button_Pressed, 0
# 75 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 1, 13, METATILE_TrickHousePuzzle_Door_Shuttered, 0
# 76 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	return
# 77 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 78 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_PressButton2:: @ 826BC3C
# 79 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 0, 4, METATILE_TrickHousePuzzle_Button_Pressed, 0
# 80 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 5, 6, METATILE_TrickHousePuzzle_Door_Shuttered, 0
# 81 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	return
# 82 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 83 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_PressButton3:: @ 826BC4F
# 84 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 14, 5, METATILE_TrickHousePuzzle_Button_Pressed, 0
# 85 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 7, 15, METATILE_TrickHousePuzzle_Door_Shuttered, 0
# 86 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	return
# 87 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 88 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_PressButton4:: @ 826BC62
# 89 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 7, 11, METATILE_TrickHousePuzzle_Button_Pressed, 0
# 90 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	setmetatile 14, 12, METATILE_TrickHousePuzzle_Door_Shuttered, 0
# 91 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	return
# 92 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 93 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Ted:: @ 826BC75
# 94 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	trainerbattle_single TRAINER_TED, Route110_TrickHousePuzzle2_Text_TedIntro, Route110_TrickHousePuzzle2_Text_TedDefeat
# 95 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	msgbox Route110_TrickHousePuzzle2_Text_TedPostBattle, MSGBOX_AUTOCLOSE
# 96 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 97 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 98 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Paul:: @ 826BC8C
# 99 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	trainerbattle_single TRAINER_PAUL, Route110_TrickHousePuzzle2_Text_PaulIntro, Route110_TrickHousePuzzle2_Text_PaulDefeat
# 100 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	msgbox Route110_TrickHousePuzzle2_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 102 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 103 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Georgia:: @ 826BCA3
# 104 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	trainerbattle_single TRAINER_GEORGIA, Route110_TrickHousePuzzle2_Text_GeorgiaIntro, Route110_TrickHousePuzzle2_Text_GeorgiaDefeat
# 105 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	msgbox Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle, MSGBOX_AUTOCLOSE
# 106 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	end
# 107 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 108 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened: @ 826BCBA
# 109 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "{PLAYER} wrote down the secret code\n"
# 110 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "on the door.\p"
# 111 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "“Trick Master is smart.”\n"
# 112 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "… … … … … … … …\p"
# 113 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "The lock clicked open!$"
# 114 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 115 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_TedIntro: @ 826BD25
# 116 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "Which switch closes which hole?$"
# 117 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 118 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_TedDefeat: @ 826BD45
# 119 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "After that battle, I'm even more\n"
# 120 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "confused!$"
# 121 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 122 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_TedPostBattle: @ 826BD70
# 123 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "Can I get you to push all the buttons\n"
# 124 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "for me?$"
# 125 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 126 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_PaulIntro: @ 826BD9E
# 127 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "Oh! You're on your second Trick House\n"
# 128 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "challenge!$"
# 129 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 130 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_PaulDefeat: @ 826BDCF
# 131 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "You're good at battling too?$"
# 132 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 133 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_PaulPostBattle: @ 826BDEC
# 134 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "The Trick Master rigged all the tricks\n"
# 135 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "in this house all by himself.$"
# 136 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 137 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_GeorgiaIntro: @ 826BE31
# 138 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "I want to make my own Gym one day.\n"
# 139 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "So, I'm studying how to set traps.$"
# 140 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 141 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_GeorgiaDefeat: @ 826BE77
# 142 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "I didn't study battling enough!$"
# 143 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"

# 144 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
Route110_TrickHousePuzzle2_Text_GeorgiaPostBattle: @ 826BE97
# 145 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "You're strong, aren't you?\n"
# 146 "data/maps/Route110_TrickHousePuzzle2/scripts.pory"
	.string "Maybe even enough to be a Gym Leader!$"
