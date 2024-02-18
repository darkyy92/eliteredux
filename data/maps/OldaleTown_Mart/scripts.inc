# 1 "data/maps/OldaleTown_Mart/scripts.pory"

# 2 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_MapScripts:: @ 81FC23F
# 3 "data/maps/OldaleTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/OldaleTown_Mart/scripts.pory"

# 5 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_Woman:: @ 81FC28A
# 6 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 7 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/OldaleTown_Mart/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
# 9 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
# 10 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 11 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 12 "data/maps/OldaleTown_Mart/scripts.pory"

# 13 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_PokeBallsInStock:: @ 81FC29F
# 14 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
# 15 "data/maps/OldaleTown_Mart/scripts.pory"
	release
# 16 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 17 "data/maps/OldaleTown_Mart/scripts.pory"

# 18 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_EventScript_Boy:: @ 81FC2A9
# 19 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
# 20 "data/maps/OldaleTown_Mart/scripts.pory"
	end
# 21 "data/maps/OldaleTown_Mart/scripts.pory"

# 22 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_PokeBallsAreSoldOut: @ 81FC2B2
# 23 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "The clerk says they're all sold out.\n"
# 24 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "I can't buy any Poké Balls.$"
# 25 "data/maps/OldaleTown_Mart/scripts.pory"

# 26 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_ImGoingToBuyPokeBalls: @ 81FC2F3
# 27 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "I'm going to buy a bunch of Poké Balls\n"
# 28 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "and catch a bunch of Pokémon!$"
# 29 "data/maps/OldaleTown_Mart/scripts.pory"

# 30 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleTown_Mart_Text_RestoreHPWithPotion: @ 81FC338
# 31 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "If a Pokémon gets hurt and loses its HP\n"
# 32 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "and faints, it won't be able to battle.\p"
# 33 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "To prevent your Pokémon from fainting,\n"
# 34 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "restore its HP with a Potion.$"

OldaleTown_Mart_EventScript_Clerk::
# 39 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 40 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 41 "data/maps/OldaleTown_Mart/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_Clerk_2
# 50 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox OldaleTown_Mart_EventScript_Clerk_Text_0, MSGBOX_DEFAULT
OldaleTown_Mart_EventScript_Clerk_1:
# 52 "data/maps/OldaleTown_Mart/scripts.pory"
	release
	end

OldaleTown_Mart_EventScript_Clerk_2:
# 42 "data/maps/OldaleTown_Mart/scripts.pory"
	setvar VAR_SHOP_TYPE, 3
# 43 "data/maps/OldaleTown_Mart/scripts.pory"
	setvar VAR_SHOP_MONEY_TYPE, 1
# 44 "data/maps/OldaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 45 "data/maps/OldaleTown_Mart/scripts.pory"
	waitmessage
# 46 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart OldaleMartMons
# 47 "data/maps/OldaleTown_Mart/scripts.pory"
	setvar VAR_SHOP_MONEY_TYPE, 0
	goto OldaleTown_Mart_EventScript_Clerk_1


	.align 2
# 56 "data/maps/OldaleTown_Mart/scripts.pory"
OldaleMartMons:
# 57 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte SPECIES_BULBASAUR
# 58 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte SPECIES_CHARMANDER
# 59 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte SPECIES_SQUIRTLE
# 60 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte SPECIES_CATERPIE
# 61 "data/maps/OldaleTown_Mart/scripts.pory"
	.2byte SPECIES_PIDGEY
	.2byte ITEM_NONE

General_Adoption_Center_Script::
# 65 "data/maps/OldaleTown_Mart/scripts.pory"
	lock
# 66 "data/maps/OldaleTown_Mart/scripts.pory"
	faceplayer
# 67 "data/maps/OldaleTown_Mart/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, General_Adoption_Center_Script_2
# 76 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox General_Adoption_Center_Script_Text_0, MSGBOX_DEFAULT
General_Adoption_Center_Script_1:
# 78 "data/maps/OldaleTown_Mart/scripts.pory"
	release
	end

General_Adoption_Center_Script_2:
# 68 "data/maps/OldaleTown_Mart/scripts.pory"
	setvar VAR_SHOP_TYPE, 3
# 69 "data/maps/OldaleTown_Mart/scripts.pory"
	setvar VAR_SHOP_MONEY_TYPE, 1
# 70 "data/maps/OldaleTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 71 "data/maps/OldaleTown_Mart/scripts.pory"
	waitmessage
# 72 "data/maps/OldaleTown_Mart/scripts.pory"
	pokemart 0
# 73 "data/maps/OldaleTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	goto General_Adoption_Center_Script_1


OldaleTown_Mart_EventScript_Clerk_Text_0:
# 50 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "Sorry but I can't sell you any Pokémon yet, you need your Pokedex.$"

General_Adoption_Center_Script_Text_0:
# 76 "data/maps/OldaleTown_Mart/scripts.pory"
	.string "Sorry but I can't sell you any Pokémon yet, you need a Pokedex.$"
