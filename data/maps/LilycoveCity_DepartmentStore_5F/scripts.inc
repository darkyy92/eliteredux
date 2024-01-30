# 1 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
.set LOCALID_WOMAN, 7
# 3 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 4 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_MapScripts:: @ 821FF7A
# 5 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_OnWarp
# 6 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.byte 0
# 7 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 8 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
@ During the abnormal weather from Kyogre/Groudon awakening the dept store rooftop is inaccessible
# 9 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
@ Likely done to avoid dealing with showing the weather. Technically the rooftop is indoors
# 10 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_OnWarp: @ 821FF80
# 11 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
# 12 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 2, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
# 13 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
# 14 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte 0
# 15 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 16 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs:: @ 821FF9A
# 17 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	setobjectxy LOCALID_WOMAN, 16, 2
# 18 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	turnobject LOCALID_WOMAN, DIR_NORTH
# 19 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 20 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 21 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarLeft:: @ 821FFA6
# 22 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lock
# 23 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 24 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	message gText_HowMayIServeYou
# 25 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 26 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Dolls
# 27 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 28 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 29 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 30 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 31 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 32 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Pokemart_Dolls: @ 821FFC0
# 33 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_PICHU_DOLL
# 34 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_PIKACHU_DOLL
# 35 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_MARILL_DOLL
# 36 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_JIGGLYPUFF_DOLL
# 37 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_DUSKULL_DOLL 
# 38 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_WYNAUT_DOLL
# 39 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_BALTOY_DOLL
# 40 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_KECLEON_DOLL
# 41 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_AZURILL_DOLL
# 42 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SKITTY_DOLL
# 43 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SWABLU_DOLL
# 44 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_GULPIN_DOLL
# 45 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_NONE
# 46 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 47 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 48 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 49 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft:: @ 821FFDC
# 50 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lock
# 51 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 52 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	message gText_HowMayIServeYou
# 53 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 54 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Cushions
# 55 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 56 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 57 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 58 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 59 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 60 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Pokemart_Cushions: @ 821FFF4
# 61 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_PIKA_CUSHION
# 62 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_ROUND_CUSHION
# 63 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_ZIGZAG_CUSHION
# 64 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SPIN_CUSHION
# 65 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_DIAMOND_CUSHION
# 66 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_BALL_CUSHION
# 67 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_GRASS_CUSHION
# 68 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_FIRE_CUSHION
# 69 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_WATER_CUSHION
# 70 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_NONE
# 71 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 72 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 73 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 74 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight:: @ 822000A
# 75 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lock
# 76 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 77 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	message gText_HowMayIServeYou
# 78 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 79 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Posters
# 80 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 81 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 82 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 83 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 84 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 85 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Pokemart_Posters: @ 8220024
# 86 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_BALL_POSTER
# 87 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_GREEN_POSTER
# 88 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_RED_POSTER
# 89 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_BLUE_POSTER
# 90 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_CUTE_POSTER
# 91 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_PIKA_POSTER
# 92 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_LONG_POSTER
# 93 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SEA_POSTER
# 94 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SKY_POSTER
# 95 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_NONE
# 96 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 97 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 98 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 99 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight:: @ 822003A
# 100 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lock
# 101 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 102 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	message gText_HowMayIServeYou
# 103 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 104 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Mats
# 105 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 106 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 107 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 108 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 109 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 110 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Pokemart_Mats: @ 8220054
# 111 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SURF_MAT
# 112 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_THUNDER_MAT
# 113 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_FIRE_BLAST_MAT
# 114 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_POWDER_SNOW_MAT
# 115 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_ATTRACT_MAT
# 116 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_FISSURE_MAT
# 117 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SPIKES_MAT
# 118 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_GLITTER_MAT
# 119 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_JUMP_MAT
# 120 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_SPIN_MAT
# 121 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.2byte DECOR_NONE
# 122 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	release
# 123 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 124 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 125 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_PokefanF:: @ 822006C
# 126 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls, MSGBOX_NPC
# 127 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 128 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 129 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_Woman:: @ 8220075
# 130 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	lockall
# 131 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	applymovement LOCALID_WOMAN, Common_Movement_FacePlayer
# 132 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmovement 0
# 133 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
# 134 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
# 135 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 136 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	goto_if_ge LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
# 137 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	goto LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather
# 138 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 139 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 140 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal:: @ 822009C
# 141 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere, MSGBOX_DEFAULT
# 142 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 143 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	releaseall
# 144 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 145 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 146 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather:: @ 82200A7
# 147 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather, MSGBOX_DEFAULT
# 148 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	closemessage
# 149 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	applymovement LOCALID_WOMAN, Common_Movement_WalkInPlaceFastestUp
# 150 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	waitmovement 0
# 151 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	releaseall
# 152 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 153 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 154 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_EventScript_LittleGirl:: @ 82200BC
# 155 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon, MSGBOX_NPC
# 156 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	end
# 157 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 158 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls: @ 82200C5
# 159 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "This place is full of cute Dolls.\p"
# 160 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "I should buy some for me, instead of\n"
# 161 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "just for my children.$"
# 162 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 163 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon: @ 8220122
# 164 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "I'm not big enough to raise Pokémon,\n"
# 165 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "so I'm getting a cute Doll instead.$"
# 166 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 167 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere: @ 822016B
# 168 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "They sell many cute Mats here.\p"
# 169 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "I wonder which one I should get?\n"
# 170 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "Maybe I'll buy them all…$"
# 171 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"

# 172 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather: @ 82201C4
# 173 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "I think they closed the rooftop\n"
# 174 "data/maps/LilycoveCity_DepartmentStore_5F/scripts.pory"
	.string "because the weather is wild today.$"
