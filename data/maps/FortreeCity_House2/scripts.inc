# 1 "data/maps/FortreeCity_House2/scripts.pory"

# 2 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_MapScripts:: @ 82177CA
# 3 "data/maps/FortreeCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/FortreeCity_House2/scripts.pory"

# 5 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_HiddenPowerGiver:: @ 82177CB
# 6 "data/maps/FortreeCity_House2/scripts.pory"
	lock
# 7 "data/maps/FortreeCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/FortreeCity_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM10, FortreeCity_House2_EventScript_ExplainHiddenPower
# 9 "data/maps/FortreeCity_House2/scripts.pory"
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
# 10 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
# 11 "data/maps/FortreeCity_House2/scripts.pory"
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
# 12 "data/maps/FortreeCity_House2/scripts.pory"
	switch VAR_RESULT
# 13 "data/maps/FortreeCity_House2/scripts.pory"
	case 1, FortreeCity_House2_EventScript_WrongGuess
# 14 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
# 15 "data/maps/FortreeCity_House2/scripts.pory"
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
# 16 "data/maps/FortreeCity_House2/scripts.pory"
	switch VAR_RESULT
# 17 "data/maps/FortreeCity_House2/scripts.pory"
	case 1, FortreeCity_House2_EventScript_WrongGuess
# 18 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
# 19 "data/maps/FortreeCity_House2/scripts.pory"
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
# 20 "data/maps/FortreeCity_House2/scripts.pory"
	switch VAR_RESULT
# 21 "data/maps/FortreeCity_House2/scripts.pory"
	case 0, FortreeCity_House2_EventScript_WrongGuess
# 22 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
# 23 "data/maps/FortreeCity_House2/scripts.pory"
	setflag FLAG_RECEIVED_TM10
# 24 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
# 25 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 26 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 27 "data/maps/FortreeCity_House2/scripts.pory"

# 28 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_Greeting:: @ 8217862
# 29 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
# 30 "data/maps/FortreeCity_House2/scripts.pory"
	setflag FLAG_MET_HIDDEN_POWER_GIVER
# 31 "data/maps/FortreeCity_House2/scripts.pory"
	return
# 32 "data/maps/FortreeCity_House2/scripts.pory"

# 33 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_ExplainHiddenPower:: @ 821786E
# 34 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
# 35 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 36 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 37 "data/maps/FortreeCity_House2/scripts.pory"

# 38 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_WrongGuess:: @ 8217878
# 39 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
# 40 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 41 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 42 "data/maps/FortreeCity_House2/scripts.pory"

# 43 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_SleepTalkTM::
# 44 "data/maps/FortreeCity_House2/scripts.pory"
	lock
# 45 "data/maps/FortreeCity_House2/scripts.pory"
	faceplayer
# 46 "data/maps/FortreeCity_House2/scripts.pory"
	checkitem ITEM_TM49_SLEEP_TALK, 1
# 47 "data/maps/FortreeCity_House2/scripts.pory"
	compare VAR_RESULT, 1
# 48 "data/maps/FortreeCity_House2/scripts.pory"
	goto_if_eq FortreeCity_House2_EventScript_ReceivedTM49
# 49 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_WantSleepTalk, MSGBOX_YESNO
# 50 "data/maps/FortreeCity_House2/scripts.pory"
	compare VAR_RESULT, NO
# 51 "data/maps/FortreeCity_House2/scripts.pory"
	goto_if_eq FortreeCity_House2_EventScript_SleepTalkDeclined
# 52 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_Text_GiveTM49, MSGBOX_DEFAULT
# 53 "data/maps/FortreeCity_House2/scripts.pory"
	giveitem ITEM_TM49_SLEEP_TALK
# 54 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_Text_HaveTM49, MSGBOX_DEFAULT
# 55 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 56 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 57 "data/maps/FortreeCity_House2/scripts.pory"

# 58 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_ReceivedTM49::
# 59 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_Text_HaveTM49, MSGBOX_DEFAULT
# 60 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 61 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 62 "data/maps/FortreeCity_House2/scripts.pory"

# 63 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_SleepTalkDeclined::
# 64 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_House2_Text_SleepTalkDeclined, MSGBOX_DEFAULT
# 65 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 66 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 67 "data/maps/FortreeCity_House2/scripts.pory"

# 68 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_EventScript_SleepTalkTaught::
# 69 "data/maps/FortreeCity_House2/scripts.pory"
	msgbox FortreeCity_Text_HaveTM49, MSGBOX_DEFAULT
# 70 "data/maps/FortreeCity_House2/scripts.pory"
	release
# 71 "data/maps/FortreeCity_House2/scripts.pory"
	end
# 72 "data/maps/FortreeCity_House2/scripts.pory"

# 73 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_WantSleepTalk:
# 74 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Humph! My wife relies on Hidden\n"
# 75 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Power to stay awake.\p"
# 76 "data/maps/FortreeCity_House2/scripts.pory"
	.string "She should just take a nap like I do,\n"
# 77 "data/maps/FortreeCity_House2/scripts.pory"
	.string "and Sleep Talk.\p"
# 78 "data/maps/FortreeCity_House2/scripts.pory"
	.string "I can teach your Pokémon how to\n"
# 79 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Sleep Talk instead. Interested?$"
# 80 "data/maps/FortreeCity_House2/scripts.pory"

# 81 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_SleepTalkDeclined:
# 82 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Oh, fine, fine. You want to stay awake\n"
# 83 "data/maps/FortreeCity_House2/scripts.pory"
	.string "with Hidden Power, too…$"
# 84 "data/maps/FortreeCity_House2/scripts.pory"

# 85 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_Text_GiveTM49:
# 86 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Ah, an appreciative child!\n"
# 87 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Please take this TM.$"
# 88 "data/maps/FortreeCity_House2/scripts.pory"

# 89 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_Text_HaveTM49:
# 90 "data/maps/FortreeCity_House2/scripts.pory"
	.string "I've never once gotten my wife's\n"
# 91 "data/maps/FortreeCity_House2/scripts.pory"
	.string "coin trick right.\p"
# 92 "data/maps/FortreeCity_House2/scripts.pory"
	.string "I would be happy if I got it right\n"
# 93 "data/maps/FortreeCity_House2/scripts.pory"
	.string "even as I Sleep Talk…$"
# 94 "data/maps/FortreeCity_House2/scripts.pory"

# 95 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_HiddenPowersArousedByNature: @ 8217882
# 96 "data/maps/FortreeCity_House2/scripts.pory"
	.string "People… Pokémon…\p"
# 97 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Their hidden powers are aroused by\n"
# 98 "data/maps/FortreeCity_House2/scripts.pory"
	.string "living in natural environments…$"
# 99 "data/maps/FortreeCity_House2/scripts.pory"

# 100 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_CoinInWhichHand: @ 82178D6
# 101 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Let this old woman see if your hidden\n"
# 102 "data/maps/FortreeCity_House2/scripts.pory"
	.string "power has awoken…\p"
# 103 "data/maps/FortreeCity_House2/scripts.pory"
	.string "I hold a coin in my hand.\p"
# 104 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Now, tell me, have I palmed it in\n"
# 105 "data/maps/FortreeCity_House2/scripts.pory"
	.string "the right hand? Or in the left?$"
# 106 "data/maps/FortreeCity_House2/scripts.pory"

# 107 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_CorrectTryAgainWhichHand: @ 821796A
# 108 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Oh! Yes, correct!\p"
# 109 "data/maps/FortreeCity_House2/scripts.pory"
	.string "We shall try again.\p"
# 110 "data/maps/FortreeCity_House2/scripts.pory"
	.string "In which hand have I palmed the coin?\n"
# 111 "data/maps/FortreeCity_House2/scripts.pory"
	.string "The right or left?$"
# 112 "data/maps/FortreeCity_House2/scripts.pory"

# 113 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_CorrectTryAgainWhichHand2: @ 82179C9
# 114 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Oh! Yes, correct!\p"
# 115 "data/maps/FortreeCity_House2/scripts.pory"
	.string "We shall try again.\p"
# 116 "data/maps/FortreeCity_House2/scripts.pory"
	.string "In which hand have I palmed the coin?\n"
# 117 "data/maps/FortreeCity_House2/scripts.pory"
	.string "The right or left?$"
# 118 "data/maps/FortreeCity_House2/scripts.pory"

# 119 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_YourHiddenPowerHasAwoken: @ 8217A28
# 120 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Oh! Splendid!\p"
# 121 "data/maps/FortreeCity_House2/scripts.pory"
	.string "I would give you Hidden Power now,\n"
# 122 "data/maps/FortreeCity_House2/scripts.pory"
	.string "but you have all TMs already...$"
# 123 "data/maps/FortreeCity_House2/scripts.pory"

# 124 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_ExplainHiddenPower: @ 8217A91
# 125 "data/maps/FortreeCity_House2/scripts.pory"
	.string "Hidden Power is a move that changes\n"
# 126 "data/maps/FortreeCity_House2/scripts.pory"
	.string "with the Pokémon's IVs.$"
# 127 "data/maps/FortreeCity_House2/scripts.pory"

# 128 "data/maps/FortreeCity_House2/scripts.pory"
FortreeCity_House2_Text_YouGuessedWrong: @ 8217AC7
# 129 "data/maps/FortreeCity_House2/scripts.pory"
	.string "No, too bad.\n"
# 130 "data/maps/FortreeCity_House2/scripts.pory"
	.string "You guessed wrong.$"
