# 1 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_MapScripts:: @ 8264FEC
# 3 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_Trader:: @ 8264FED
# 6 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	lock
# 7 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	faceplayer
# 8 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
# 9 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_KARRABLAST
# 10 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 11 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 12 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 13 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
# 14 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	compare VAR_RESULT, NO
# 15 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq BattleFrontier_Lounge6_EventScript_DeclineTrade
# 16 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special ChoosePartyMon
# 17 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	waitstate
# 18 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 19 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	compare VAR_0x8004, 255
# 20 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_eq BattleFrontier_Lounge6_EventScript_DeclineTrade
# 21 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 22 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 23 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 24 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	compare VAR_RESULT, VAR_0x8009
# 25 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	goto_if_ne BattleFrontier_Lounge6_EventScript_NotRequestedMon
# 26 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 27 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 28 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special CreateInGameTradePokemon
# 29 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	special DoInGameTradeScene
# 30 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	waitstate
# 31 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
# 32 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
# 33 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 34 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 35 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 36 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_DeclineTrade:: @ 826506B
# 37 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
# 38 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 39 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 41 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_NotRequestedMon:: @ 8265075
# 42 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	bufferspeciesname 0, VAR_0x8009
# 43 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
# 44 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 45 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 46 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 47 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_EventScript_TradeCompleted:: @ 8265083
# 48 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
# 49 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	release
# 50 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	end
# 51 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 52 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_WouldYouLikeToTrade: @ 826508D
# 53 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "My Pokémon is a {STR_VAR_2}.\n"
# 54 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Do you know it?\l"
# 55 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "It's quite cute and rather nice.\p"
# 56 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "This little one, I could trade with\n"
# 57 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "pride!\p"
# 58 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Would you like to trade me a {STR_VAR_1}\n"
# 59 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "for my {STR_VAR_2}?$"
# 60 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 61 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt: @ 8265128
# 62 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, it's adorable!\n"
# 63 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Thank you!\l"
# 64 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "I promise I'll be good to it!\p"
# 65 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh! I hope you'll be good to\n"
# 66 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "my {STR_VAR_2}, too!$"
# 67 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 68 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon: @ 826518D
# 69 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, I'm sorry!\n"
# 70 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "I don't intend to trade for anything\l"
# 71 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "but a {STR_VAR_1}.$"
# 72 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 73 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_WellThatsFineToo: @ 82651CB
# 74 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Oh, you won't?\n"
# 75 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Well, that's fine, too.\l"
# 76 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Please come visit us again.$"
# 77 "data/maps/BattleFrontier_Lounge6/scripts.pory"

# 78 "data/maps/BattleFrontier_Lounge6/scripts.pory"
BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined: @ 826520E
# 79 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "Giggle!\n"
# 80 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "A SKITTY is so much cuter than I had\l"
# 81 "data/maps/BattleFrontier_Lounge6/scripts.pory"
	.string "imagined. I'm delighted!$"
