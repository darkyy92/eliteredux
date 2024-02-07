# 1 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 2 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_MapScripts:: @ 81FF9CD
# 3 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 5 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_Clerk:: @ 81FF9CE
# 6 "data/maps/LavaridgeTown_Mart/scripts.pory"
	lock
# 7 "data/maps/LavaridgeTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/LavaridgeTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/LavaridgeTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/LavaridgeTown_Mart/scripts.pory"
	pokemart LavaridgeTown_Mart_Pokemart
# 11 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/LavaridgeTown_Mart/scripts.pory"
	release
# 13 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 14 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 15 "data/maps/LavaridgeTown_Mart/scripts.pory"
.align 2
# 16 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Pokemart: @ 81FF9E8
# 17 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_GRASS_GEM
# 18 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_FIRE_GEM
# 19 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_WATER_GEM
# 20 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_ELECTRIC_GEM
# 21 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_ICE_GEM
# 22 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_DRAGON_GEM
# 23 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_FAIRY_GEM
# 24 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_PSYCHIC_GEM
# 25 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_DARK_GEM
# 26 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_GHOST_GEM
# 27 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_BUG_GEM
# 28 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_POISON_GEM
# 29 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_FLYING_GEM
# 30 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_GROUND_GEM
# 31 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_ROCK_GEM
# 32 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_STEEL_GEM
# 33 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_FIGHTING_GEM
# 34 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_NORMAL_GEM
# 35 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.2byte ITEM_NONE
# 36 "data/maps/LavaridgeTown_Mart/scripts.pory"
	release
# 37 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 38 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 39 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_ExpertM:: @ 81FF9FE
# 40 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
# 41 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 42 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 43 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_EventScript_OldWoman:: @ 81FFA07
# 44 "data/maps/LavaridgeTown_Mart/scripts.pory"
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
# 45 "data/maps/LavaridgeTown_Mart/scripts.pory"
	end
# 46 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 47 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Text_XSpeedFirstStrike: @ 81FFA10
# 48 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "Use X Speed to add to a Pokémon's\n"
# 49 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "Speed in battle.\p"
# 50 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "That will help it get in the first\n"
# 51 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "strike--a decided advantage!$"
# 52 "data/maps/LavaridgeTown_Mart/scripts.pory"

# 53 "data/maps/LavaridgeTown_Mart/scripts.pory"
LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney: @ 81FFA83
# 54 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "On Mt. Chimney's peak, there's a local\n"
# 55 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "specialty that you can buy only there.\p"
# 56 "data/maps/LavaridgeTown_Mart/scripts.pory"
	.string "Give it to a Pokémon--it will be elated.$"
