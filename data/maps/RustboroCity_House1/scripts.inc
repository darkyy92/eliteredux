# 1 "data/maps/RustboroCity_House1/scripts.pory"

# 2 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_MapScripts:: @ 821593E
# 3 "data/maps/RustboroCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_House1/scripts.pory"

# 5 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_Trader:: @ 821593F
# 6 "data/maps/RustboroCity_House1/scripts.pory"
	lock
# 7 "data/maps/RustboroCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/RustboroCity_House1/scripts.pory"
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
# 9 "data/maps/RustboroCity_House1/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_PAWNIARD
# 10 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 11 "data/maps/RustboroCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 12 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 13 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
# 14 "data/maps/RustboroCity_House1/scripts.pory"
	compare VAR_RESULT, NO
# 15 "data/maps/RustboroCity_House1/scripts.pory"
	goto_if_eq RustboroCity_House1_EventScript_DeclineTrade
# 16 "data/maps/RustboroCity_House1/scripts.pory"
	special ChoosePartyMon
# 17 "data/maps/RustboroCity_House1/scripts.pory"
	waitstate
# 18 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 19 "data/maps/RustboroCity_House1/scripts.pory"
	compare VAR_0x8004, 255
# 20 "data/maps/RustboroCity_House1/scripts.pory"
	goto_if_eq RustboroCity_House1_EventScript_DeclineTrade
# 21 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 22 "data/maps/RustboroCity_House1/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 23 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 24 "data/maps/RustboroCity_House1/scripts.pory"
	compare VAR_RESULT, VAR_0x8009
# 25 "data/maps/RustboroCity_House1/scripts.pory"
	goto_if_ne RustboroCity_House1_EventScript_NotRequestedMon
# 26 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 27 "data/maps/RustboroCity_House1/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 28 "data/maps/RustboroCity_House1/scripts.pory"
	special CreateInGameTradePokemon
# 29 "data/maps/RustboroCity_House1/scripts.pory"
	special DoInGameTradeScene
# 30 "data/maps/RustboroCity_House1/scripts.pory"
	waitstate
# 31 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
# 32 "data/maps/RustboroCity_House1/scripts.pory"
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
# 33 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 34 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 35 "data/maps/RustboroCity_House1/scripts.pory"

# 36 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_DeclineTrade:: @ 82159BD
# 37 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
# 38 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 39 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 40 "data/maps/RustboroCity_House1/scripts.pory"

# 41 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_NotRequestedMon:: @ 82159C7
# 42 "data/maps/RustboroCity_House1/scripts.pory"
	bufferspeciesname 0, VAR_0x8009
# 43 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
# 44 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 45 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 46 "data/maps/RustboroCity_House1/scripts.pory"

# 47 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_TradeCompleted:: @ 82159D5
# 48 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
# 49 "data/maps/RustboroCity_House1/scripts.pory"
	release
# 50 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 51 "data/maps/RustboroCity_House1/scripts.pory"

# 52 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_EventScript_Hiker:: @ 82159DF
# 53 "data/maps/RustboroCity_House1/scripts.pory"
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
# 54 "data/maps/RustboroCity_House1/scripts.pory"
	end
# 55 "data/maps/RustboroCity_House1/scripts.pory"

# 56 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_IllTradeIfYouWant: @ 82159E8
# 57 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Huh? My Pokémon is cute?\n"
# 58 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Sure, I knew that.\p"
# 59 "data/maps/RustboroCity_House1/scripts.pory"
	.string "But if you really want, I'm willing\n"
# 60 "data/maps/RustboroCity_House1/scripts.pory"
	.string "to trade it to you.\p"
# 61 "data/maps/RustboroCity_House1/scripts.pory"
	.string "I'll trade you my {STR_VAR_2} for\n"
# 62 "data/maps/RustboroCity_House1/scripts.pory"
	.string "a {STR_VAR_1} if you want.$"
# 63 "data/maps/RustboroCity_House1/scripts.pory"

# 64 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_PleaseBeGoodToMyPokemon: @ 8215A77
# 65 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Eheheh…\n"
# 66 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Please be good to my Pokémon.$"
# 67 "data/maps/RustboroCity_House1/scripts.pory"

# 68 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_DoesntLookLikeMonToMe: @ 8215A9D
# 69 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Huh? That doesn't look anything like\n"
# 70 "data/maps/RustboroCity_House1/scripts.pory"
	.string "a {STR_VAR_1} to me.$"
# 71 "data/maps/RustboroCity_House1/scripts.pory"

# 72 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_YouDontWantToThatsOkay: @ 8215ACE
# 73 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Oh, if you don't want to, that's okay.\n"
# 74 "data/maps/RustboroCity_House1/scripts.pory"
	.string "But my Pokémon is cute, you know…$"
# 75 "data/maps/RustboroCity_House1/scripts.pory"

# 76 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_AnyPokemonCanBeCute: @ 8215B17
# 77 "data/maps/RustboroCity_House1/scripts.pory"
	.string "Any Pokémon can be cute if you raise\n"
# 78 "data/maps/RustboroCity_House1/scripts.pory"
	.string "it with care and kindness.$"
# 79 "data/maps/RustboroCity_House1/scripts.pory"

# 80 "data/maps/RustboroCity_House1/scripts.pory"
RustboroCity_House1_Text_AllSortsOfPlaces: @ 8215B57
# 81 "data/maps/RustboroCity_House1/scripts.pory"
	.string "In all sorts of places, there are all\n"
# 82 "data/maps/RustboroCity_House1/scripts.pory"
	.string "sorts of Pokémon and people.\p"
# 83 "data/maps/RustboroCity_House1/scripts.pory"
	.string "I find that fascinating, so I go to all\n"
# 84 "data/maps/RustboroCity_House1/scripts.pory"
	.string "sorts of places.$"
