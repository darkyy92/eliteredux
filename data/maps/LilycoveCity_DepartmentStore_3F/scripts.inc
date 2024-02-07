# 1 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_MapScripts:: @ 821FC64
# 3 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 5 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft:: @ 821FC65
# 6 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 7 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 8 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 10 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
# 11 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 13 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 14 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 15 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins: @ 821FC7C
# 16 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PROTEIN
# 17 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CALCIUM
# 18 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IRON
# 19 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ZINC
# 20 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CARBOS
# 21 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HP_UP
# 22 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NONE
# 23 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 24 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 25 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 26 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight:: @ 821FC8C
# 27 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 28 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 29 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 30 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 31 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
# 32 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 33 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 34 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 35 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 36 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 37 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters: @ 821FCA4
# 38 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ATTACK
# 39 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 40 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 41 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 42 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SPEED
# 43 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 44 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 45 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 46 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NONE
# 47 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 48 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 49 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 50 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM:: @ 821FCB6
# 51 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
# 52 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 53 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 54 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_PokefanM:: @ 821FCBF
# 55 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
# 56 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 57 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 58 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_Woman:: @ 821FCC8
# 59 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
# 60 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 61 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 62 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon: @ 821FCD1
# 63 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "For quickly toughening up Pokémon,\n"
# 64 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "items are the best.\p"
# 65 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "Protein boosts Attack,\n"
# 66 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and Calcium raises Sp. Atk.$"
# 67 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 68 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance: @ 821FD3B
# 69 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I want my Pokémon to have more\n"
# 70 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "endurance.\p"
# 71 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I'm trying to decide whether to raise\n"
# 72 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "Defense with Iron, or Sp. Def with Zinc.$"
# 73 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 74 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon: @ 821FDB4
# 75 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I gave a Carbos to my Pokémon,\n"
# 76 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and its Speed went up.$"
