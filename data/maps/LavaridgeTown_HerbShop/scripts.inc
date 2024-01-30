# 1 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 2 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_MapScripts:: @ 81FE4D6
# 3 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.byte 0
# 4 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 5 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_EventScript_Clerk:: @ 81FE4D7
# 6 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	lock
# 7 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	faceplayer
# 8 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
# 9 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	waitmessage
# 10 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	pokemart LavaridgeTown_HerbShop_Pokemart
# 11 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	release
# 13 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 14 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 15 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.align 2
# 16 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Pokemart: @ 81FE4F0
# 17 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_ENERGY_POWDER
# 18 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_ENERGY_ROOT
# 19 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_HEAL_POWDER
# 20 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 21 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.2byte ITEM_NONE
# 22 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	release
# 23 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 24 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 25 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_EventScript_ExpertM:: @ 81FE4FC
# 26 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
# 27 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 28 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 29 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_EventScript_OldMan:: @ 81FE505
# 30 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	lock
# 31 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	faceplayer
# 32 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
# 33 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
# 34 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	giveitem ITEM_CHARCOAL
# 35 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	compare VAR_RESULT, FALSE
# 36 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 37 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	setflag FLAG_RECEIVED_CHARCOAL
# 38 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	release
# 39 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 40 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 41 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_EventScript_ExplainCharcoal:: @ 81FE534
# 42 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
# 43 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	release
# 44 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	end
# 45 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 46 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Text_WelcomeToHerbShop: @ 81FE53E
# 47 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "Welcome to the Herb Shop, home of\n"
# 48 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "effective and inexpensive medicine!$"
# 49 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 50 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine: @ 81FE584
# 51 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "You've come to look at herbal medicine\n"
# 52 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "in Lavaridge?\p"
# 53 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "That's rather commendable.\p"
# 54 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "I like you! Take this!$"
# 55 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 56 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Text_ExplainCharcoal: @ 81FE5EB
# 57 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "That Charcoal I gave you, it's used\n"
# 58 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "for making herbal medicine.\p"
# 59 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "It also does wonders when held by\n"
# 60 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "a Pokémon.\p"
# 61 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "It intensifies the power of Fire-type\n"
# 62 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "moves.$"
# 63 "data/maps/LavaridgeTown_HerbShop/scripts.pory"

# 64 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike: @ 81FE685
# 65 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "Herbal medicine works impressively well.\n"
# 66 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "But your Pokémon will dislike you for it.\l"
# 67 "data/maps/LavaridgeTown_HerbShop/scripts.pory"
	.string "It must be horribly bitter!$"
