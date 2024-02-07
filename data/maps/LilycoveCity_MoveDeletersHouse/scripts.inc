# 1 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 2 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
.set LOCALID_MOVE_DELETER, 1
# 3 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 4 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_MapScripts:: @ 821EA0A
# 5 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.byte 0
# 6 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 7 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
.set BALL_SWAP_PRICE,  	2000
# 8 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 9 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
@ VAR_0x8004: Chosen Party Slot
# 10 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
@ VAR_0x8005: Chosen Poke Ball
# 11 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_EventScript_BallSwapper::
# 12 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	lock
# 13 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	faceplayer
# 14 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	@showmoneybox 0, 0, 0
# 15 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call_if_unset FLAG_LILYCOVE_MET_BALL_SWAPPER, LilycoveCity_EventScript_BallSwapperIntro
# 16 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	checkmoney BALL_SWAP_PRICE, 0
# 17 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 18 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_BallSwapper_CantAfford
# 19 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperChoosePokemon, MSGBOX_DEFAULT
# 20 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	@hidemoneybox
# 21 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 22 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitstate
# 23 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_0x8004, PARTY_SIZE
# 24 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_ge LilycoveCity_EventScript_BallSwapperExitNoMoneyBox
# 25 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 26 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
# 27 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_BallSwapperEgg
# 28 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperChoosePokeBall, MSGBOX_AUTOCLOSE
# 29 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 30 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special Bag_ChoosePokeBall
# 31 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitstate
# 32 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_0x8005, VAR_ITEM_ID
# 33 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_ITEM_ID, 0
# 34 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_BallSwapperExitNoMoneyBox
# 35 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	showmoneybox 0, 0, 0
# 36 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 37 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	bufferitemname 1, VAR_0x8005
# 38 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperConfirmChoice, MSGBOX_YESNO
# 39 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, NO
# 40 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq LilycoveCity_EventScript_BallSwapperExit
# 41 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playse SE_SHOP
# 42 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	removemoney BALL_SWAP_PRICE, 0
# 43 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	removeitem VAR_ITEM_ID, 1
# 44 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	updatemoneybox 0, 0
# 45 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 46 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperChooseGivePokemon, MSGBOX_DEFAULT
# 47 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hidemoneybox
# 48 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperChoosePleaseWait, MSGBOX_DEFAULT
# 49 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 50 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChangePokeBall
# 51 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playse SE_BALL_OPEN
# 52 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitse
# 53 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 54 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playmoncry VAR_RESULT, 0
# 55 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperDelay, MSGBOX_AUTOCLOSE
# 56 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playse SE_BALL_BOUNCE_1
# 57 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitse
# 58 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playse SE_BALL_BOUNCE_2
# 59 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitse
# 60 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playse SE_BALL_BOUNCE_4
# 61 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitse
# 62 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playse SE_RG_BALL_CLICK
# 63 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitse
# 64 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 65 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playfanfare MUS_CAUGHT
# 66 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 67 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperAllDone, MSGBOX_DEFAULT
# 68 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
# 69 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 70 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 71 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_EventScript_BallSwapperIntro::
# 72 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperIntro, MSGBOX_DEFAULT
# 73 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	setflag FLAG_LILYCOVE_MET_BALL_SWAPPER
# 74 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	return
# 75 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 76 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_EventScript_BallSwapper_CantAfford::
# 77 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperCantAfford, MSGBOX_DEFAULT
# 78 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
# 79 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 80 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 81 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_EventScript_BallSwapperExit::
# 82 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hidemoneybox
# 83 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperExit, MSGBOX_DEFAULT
# 84 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
# 85 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 86 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 87 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_EventScript_BallSwapperExitNoMoneyBox::
# 88 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperExit, MSGBOX_DEFAULT
# 89 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
# 90 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 91 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 92 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_EventScript_BallSwapperEgg::
# 93 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_Text_BallSwapperEgg, MSGBOX_DEFAULT
# 94 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
# 95 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 96 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 97 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperIntro:
# 98 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I'm the Poké Ball Swapper!\p"
# 99 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can move your Pokémon from their\n"
# 100 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "current Poké Ball into a new one.\p"
# 101 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I charge ¥2000 for this, and I'll need\n"
# 102 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "you to provide the new Poké Ball.$"
# 103 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 104 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperCantAfford:
# 105 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I'm the Poké Ball Swapper!\p"
# 106 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "…But it seems you can't afford my\n"
# 107 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "services.\p"
# 108 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Please come back when you have ¥2000.$"
# 109 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 110 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperChoosePokemon:
# 111 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which Pokémon's Ball would you like\n"
# 112 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "to swap?$"
# 113 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 114 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperChoosePokeBall:
# 115 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "And which Poké Ball will be their\n"
# 116 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "new home?$"
# 117 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 118 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperConfirmChoice:
# 119 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "So you want to move {STR_VAR_1}\n"
# 120 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "into a {STR_VAR_2} for ¥2000?$"
# 121 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 122 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperChooseGivePokemon:
# 123 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Very well. Please hand over your\n"
# 124 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1}.$"
# 125 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 126 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperChoosePleaseWait:
# 127 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Don't worry, this will only take\n"
# 128 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "a moment.$"
# 129 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 130 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperDelay:
# 131 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "… … … … … …\n"
# 132 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "… … … … … …\p"
# 133 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "… … … … … …\n"
# 134 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "… … … … … …\p"
# 135 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "… … … … … …\n"
# 136 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "… … … … … …$"
# 137 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 138 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperAllDone:
# 139 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "All done! I hope {STR_VAR_1} enjoys\n"
# 140 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "its new Poké Ball!$"
# 141 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 142 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperExit:
# 143 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "See you later then!$"
# 144 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 145 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_Text_BallSwapperEgg:
# 146 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can't change an Egg's Poké Ball!\n"
# 147 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Come back once it's hatched.$"
