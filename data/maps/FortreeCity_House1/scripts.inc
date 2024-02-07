# 1 "data/maps/FortreeCity_House1/scripts.pory"

# 2 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_MapScripts:: @ 82162BA
# 3 "data/maps/FortreeCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/FortreeCity_House1/scripts.pory"

# 5 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_ExpertF:: @ 821635F
# 6 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
# 7 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 8 "data/maps/FortreeCity_House1/scripts.pory"

# 9 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_Zigzagoon:: @ 8216368
# 10 "data/maps/FortreeCity_House1/scripts.pory"
	lock
# 11 "data/maps/FortreeCity_House1/scripts.pory"
	faceplayer
# 12 "data/maps/FortreeCity_House1/scripts.pory"
	waitse
# 13 "data/maps/FortreeCity_House1/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 14 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
# 15 "data/maps/FortreeCity_House1/scripts.pory"
	waitmoncry
# 16 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 17 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 18 "data/maps/FortreeCity_House1/scripts.pory"

# 19 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_Trader:: @ 8264FED
# 20 "data/maps/FortreeCity_House1/scripts.pory"
	lock
# 21 "data/maps/FortreeCity_House1/scripts.pory"
	faceplayer
# 22 "data/maps/FortreeCity_House1/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, FortreeCity_House1_EventScript_TradeCompleted
# 23 "data/maps/FortreeCity_House1/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_KARRABLAST
# 24 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 25 "data/maps/FortreeCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 26 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 27 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_WouldYouLikeToTrade, MSGBOX_YESNO
# 28 "data/maps/FortreeCity_House1/scripts.pory"
	compare VAR_RESULT, NO
# 29 "data/maps/FortreeCity_House1/scripts.pory"
	goto_if_eq FortreeCity_House1_EventScript_DeclineTrade
# 30 "data/maps/FortreeCity_House1/scripts.pory"
	special ChoosePartyMon
# 31 "data/maps/FortreeCity_House1/scripts.pory"
	waitstate
# 32 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 33 "data/maps/FortreeCity_House1/scripts.pory"
	compare VAR_0x8004, 255
# 34 "data/maps/FortreeCity_House1/scripts.pory"
	goto_if_eq FortreeCity_House1_EventScript_DeclineTrade
# 35 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 36 "data/maps/FortreeCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 37 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 38 "data/maps/FortreeCity_House1/scripts.pory"
	compare VAR_RESULT, VAR_0x8009
# 39 "data/maps/FortreeCity_House1/scripts.pory"
	goto_if_ne FortreeCity_House1_EventScript_NotRequestedMon
# 40 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 41 "data/maps/FortreeCity_House1/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 42 "data/maps/FortreeCity_House1/scripts.pory"
	special CreateInGameTradePokemon
# 43 "data/maps/FortreeCity_House1/scripts.pory"
	special DoInGameTradeScene
# 44 "data/maps/FortreeCity_House1/scripts.pory"
	waitstate
# 45 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
# 46 "data/maps/FortreeCity_House1/scripts.pory"
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
# 47 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 48 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 49 "data/maps/FortreeCity_House1/scripts.pory"

# 50 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_DeclineTrade:: @ 826506B
# 51 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_WellThatsFineToo, MSGBOX_DEFAULT
# 52 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 53 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 54 "data/maps/FortreeCity_House1/scripts.pory"

# 55 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_NotRequestedMon:: @ 8265075
# 56 "data/maps/FortreeCity_House1/scripts.pory"
	bufferspeciesname 0, VAR_0x8009
# 57 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
# 58 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 59 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 60 "data/maps/FortreeCity_House1/scripts.pory"

# 61 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_EventScript_TradeCompleted:: @ 8265083
# 62 "data/maps/FortreeCity_House1/scripts.pory"
	msgbox FortreeCity_House1_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
# 63 "data/maps/FortreeCity_House1/scripts.pory"
	release
# 64 "data/maps/FortreeCity_House1/scripts.pory"
	end
# 65 "data/maps/FortreeCity_House1/scripts.pory"

# 66 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_WouldYouLikeToTrade: @ 826508D
# 67 "data/maps/FortreeCity_House1/scripts.pory"
	.string "My Pokémon is a {STR_VAR_2}.\n"
# 68 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Do you know it?\l"
# 69 "data/maps/FortreeCity_House1/scripts.pory"
	.string "It's quite cute and rather nice.\p"
# 70 "data/maps/FortreeCity_House1/scripts.pory"
	.string "This little one, I could trade with\n"
# 71 "data/maps/FortreeCity_House1/scripts.pory"
	.string "pride!\p"
# 72 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Would you like to trade me a {STR_VAR_1}\n"
# 73 "data/maps/FortreeCity_House1/scripts.pory"
	.string "for my {STR_VAR_2}?$"
# 74 "data/maps/FortreeCity_House1/scripts.pory"

# 75 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_PromiseIllBeGoodToIt: @ 8265128
# 76 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Oh, it's adorable!\n"
# 77 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Thank you!\l"
# 78 "data/maps/FortreeCity_House1/scripts.pory"
	.string "I promise I'll be good to it!\p"
# 79 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Oh! I hope you'll be good to\n"
# 80 "data/maps/FortreeCity_House1/scripts.pory"
	.string "my {STR_VAR_2}, too!$"
# 81 "data/maps/FortreeCity_House1/scripts.pory"

# 82 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_DontTradeForAnythingButMon: @ 826518D
# 83 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Oh, I'm sorry!\n"
# 84 "data/maps/FortreeCity_House1/scripts.pory"
	.string "I don't intend to trade for anything\l"
# 85 "data/maps/FortreeCity_House1/scripts.pory"
	.string "but a {STR_VAR_1}.$"
# 86 "data/maps/FortreeCity_House1/scripts.pory"

# 87 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_WellThatsFineToo: @ 82651CB
# 88 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Oh, you won't?\n"
# 89 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Well, that's fine, too.\l"
# 90 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Please come visit us again.$"
# 91 "data/maps/FortreeCity_House1/scripts.pory"

# 92 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_SkittySoMuchCuterThanImagined: @ 826520E
# 93 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Giggle!\n"
# 94 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Did you know Karrablast would evolve?\l"
# 95 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Your Shelmet evolved too!$"
# 96 "data/maps/FortreeCity_House1/scripts.pory"

# 97 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_Zigzagoon: @ 8216597
# 98 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Zigzagoon: Gumomoh?$"
# 99 "data/maps/FortreeCity_House1/scripts.pory"

# 100 "data/maps/FortreeCity_House1/scripts.pory"
FortreeCity_House1_Text_TradingMemoriesWithOthers: @ 821653B
# 101 "data/maps/FortreeCity_House1/scripts.pory"
	.string "Trading Pokémon with others…\p"
# 102 "data/maps/FortreeCity_House1/scripts.pory"
	.string "It's as if you're trading your own\n"
# 103 "data/maps/FortreeCity_House1/scripts.pory"
	.string "memories with other people.$"
