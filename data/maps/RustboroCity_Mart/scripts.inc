# 1 "data/maps/RustboroCity_Mart/scripts.pory"

# 2 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_MapScripts:: @ 8214F05
# 3 "data/maps/RustboroCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Mart/scripts.pory"

# 5 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_PokefanF:: @ 8214F74
# 6 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
# 7 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 8 "data/maps/RustboroCity_Mart/scripts.pory"

# 9 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_Boy:: @ 8214F7D
# 10 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
# 11 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 12 "data/maps/RustboroCity_Mart/scripts.pory"

# 13 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_BugCatcher:: @ 8214F86
# 14 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
# 15 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 16 "data/maps/RustboroCity_Mart/scripts.pory"

# 17 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_FalseSwipeTM::
# 18 "data/maps/RustboroCity_Mart/scripts.pory"
	lock
# 19 "data/maps/RustboroCity_Mart/scripts.pory"
	faceplayer
# 20 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_HaveTM98, MSGBOX_DEFAULT
# 21 "data/maps/RustboroCity_Mart/scripts.pory"
	release
# 22 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 23 "data/maps/RustboroCity_Mart/scripts.pory"

# 24 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_EventScript_ReceivedTM98::
# 25 "data/maps/RustboroCity_Mart/scripts.pory"
	msgbox RustboroCity_Mart_Text_HaveTM98, MSGBOX_DEFAULT
# 26 "data/maps/RustboroCity_Mart/scripts.pory"
	release
# 27 "data/maps/RustboroCity_Mart/scripts.pory"
	end
# 28 "data/maps/RustboroCity_Mart/scripts.pory"

# 29 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_ExcuseMeTrainer:
# 30 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "Excuse me, Trainer over there.\n"
# 31 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "Do you have a minute?\p"
# 32 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "You know, sometimes moves are too\n"
# 33 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "strong to catch a Pokémon.\p"
# 34 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "You end up making a Pokémon faint even\n"
# 35 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "when you don't want to.\p"
# 36 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "For such a common problem, use this!$"
# 37 "data/maps/RustboroCity_Mart/scripts.pory"

# 38 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_HaveTM98:
# 39 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "False Swipe is a very handy move.\p"
# 40 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "No matter how many times it's used on\n"
# 41 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "the opposing Pokémon, it won't cause\l"
# 42 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "the Pokémon to faint!$"
# 43 "data/maps/RustboroCity_Mart/scripts.pory"

# 44 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish: @ 8214F8F
# 45 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I'm buying some Parlyz Heals and\n"
# 46 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "Antidotes.\p"
# 47 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "Just in case I run into Paras\n"
# 48 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "in Petalburg Woods.$"
# 49 "data/maps/RustboroCity_Mart/scripts.pory"

# 50 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead: @ 8214FF1
# 51 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "My Pokémon evolved.\n"
# 52 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "It has a lot of HP now.\p"
# 53 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I should buy Super Potions for it\n"
# 54 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "instead of ordinary Potions.$"
# 55 "data/maps/RustboroCity_Mart/scripts.pory"

# 56 "data/maps/RustboroCity_Mart/scripts.pory"
RustboroCity_Mart_Text_GettingEscapeRopeJustInCase: @ 821505C
# 57 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I'm getting an Escape Rope just in\n"
# 58 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "case I get lost in a cave.\p"
# 59 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "I just need to use it to get back to\n"
# 60 "data/maps/RustboroCity_Mart/scripts.pory"
	.string "the entrance.$"
