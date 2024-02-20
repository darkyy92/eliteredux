OldaleTown_Mart_MapScripts:: @ 81FC23F
	.byte 0

OldaleTown_Mart_EventScript_Woman:: @ 81FC28A
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock:: @ 81FC29F
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy:: @ 81FC2A9
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut: @ 81FC2B2
	.string "The clerk says they're all sold out.\n"
	.string "I can't buy any Poké Balls.$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls: @ 81FC2F3
	.string "I'm going to buy a bunch of Poké Balls\n"
	.string "and catch a bunch of Pokémon!$"

OldaleTown_Mart_Text_RestoreHPWithPotion: @ 81FC338
	.string "If a Pokémon gets hurt and loses its HP\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your Pokémon from fainting,\n"
	.string "restore its HP with a Potion.$"

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_Clerk_2
	msgbox OldaleTown_Mart_EventScript_Clerk_Text_0, MSGBOX_DEFAULT
OldaleTown_Mart_EventScript_Clerk_1:
	release
	end

OldaleTown_Mart_EventScript_Clerk_2:
	setvar VAR_SHOP_TYPE, 3
	setvar VAR_SHOP_MONEY_TYPE, 1
	message gText_HowMayIServeYou
	waitmessage
	pokemart OldaleMartMons
	setvar VAR_SHOP_MONEY_TYPE, 0
	goto OldaleTown_Mart_EventScript_Clerk_1


	.align 2
OldaleMartMons:
	.2byte SPECIES_BULBASAUR
	.2byte SPECIES_CHARMANDER
	.2byte SPECIES_SQUIRTLE
	.2byte SPECIES_CATERPIE
	.2byte SPECIES_PIDGEY
	.2byte ITEM_NONE

General_Adoption_Center_Script::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, General_Adoption_Center_Script_2
	msgbox General_Adoption_Center_Script_Text_0, MSGBOX_DEFAULT
General_Adoption_Center_Script_1:
	release
	end

General_Adoption_Center_Script_2:
	setvar VAR_SHOP_TYPE, 3
	setvar VAR_SHOP_MONEY_TYPE, 1
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	goto General_Adoption_Center_Script_1


OldaleTown_Mart_EventScript_Clerk_Text_0:
	.string "Sorry but I can't sell you any Pokémon yet, you need your Pokedex.$"

General_Adoption_Center_Script_Text_0:
	.string "Sorry but I can't sell you any Pokémon yet, you need a Pokedex.$"
