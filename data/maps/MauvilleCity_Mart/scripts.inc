# 1 "data/maps/MauvilleCity_Mart/scripts.pory"

# 2 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_MapScripts:: @ 82110E5
# 3 "data/maps/MauvilleCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_Mart/scripts.pory"

# 5 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_EventScript_Clerk:: @ 82110E6
# 6 "data/maps/MauvilleCity_Mart/scripts.pory"
	lock
# 7 "data/maps/MauvilleCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/MauvilleCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/MauvilleCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/MauvilleCity_Mart/scripts.pory"
	pokemart MauvilleCity_Mart_Pokemart
# 11 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/MauvilleCity_Mart/scripts.pory"
	release
# 13 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 14 "data/maps/MauvilleCity_Mart/scripts.pory"

# 15 "data/maps/MauvilleCity_Mart/scripts.pory"
	.align 2
# 16 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Pokemart::
# 17 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_UPGRADE
# 18 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_METAL_POWDER
# 19 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_LEEK
# 20 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_LIGHT_BALL
# 21 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_THICK_CLUB
# 22 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DEEP_SEA_TOOTH
# 23 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_DEEP_SEA_SCALE
# 24 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_METAL_COAT
# 25 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_KINGS_ROCK
# 26 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_PRISM_SCALE
# 27 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_SACHET
# 28 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_WHIPPED_DREAM
# 29 "data/maps/MauvilleCity_Mart/scripts.pory"
	.2byte ITEM_NONE
# 30 "data/maps/MauvilleCity_Mart/scripts.pory"
	release
# 31 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 32 "data/maps/MauvilleCity_Mart/scripts.pory"

# 33 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_EventScript_ExpertM:: @ 821111C
# 34 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
# 35 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 36 "data/maps/MauvilleCity_Mart/scripts.pory"

# 37 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_EventScript_Man:: @ 8211125
# 38 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
# 39 "data/maps/MauvilleCity_Mart/scripts.pory"
	end
# 40 "data/maps/MauvilleCity_Mart/scripts.pory"

# 41 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats: @ 821112E
# 42 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "There are items that temporarily\n"
# 43 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "elevate the stats of Pokémon.\p"
# 44 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "The ones I know you use in battle\n"
# 45 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "are X Attack and X Defend…\p"
# 46 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "I do believe that there are others\n"
# 47 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "like them.$"
# 48 "data/maps/MauvilleCity_Mart/scripts.pory"

# 49 "data/maps/MauvilleCity_Mart/scripts.pory"
MauvilleCity_Mart_Text_DecisionsDetermineBattle: @ 82111D8
# 50 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "Use a certain move, or use an item\n"
# 51 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "instead…\p"
# 52 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "The Trainer's decisions determine how\n"
# 53 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "battles turn out, I think.$"
