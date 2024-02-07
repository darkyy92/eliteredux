# 1 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 2 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
.set NATURE_CHANGER_COST, 5
# 3 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 4 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_MapScripts::
# 5 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.byte 0
# 6 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 7 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_NatureChanger::
# 8 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	lockall
# 9 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	faceplayer
# 10 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_ChoosePokemon, MSGBOX_DEFAULT
# 11 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special ChoosePartyMon
# 12 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	waitstate
# 13 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	compare VAR_0x8004, PARTY_SIZE
# 14 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_ge Nature_Changer_No
# 15 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 16 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
# 17 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq Nature_Changer_Egg
# 18 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special BufferChosenMonNature
# 19 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 20 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_MonHasNature, MSGBOX_DEFAULT
# 21 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
# 22 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	compare VAR_RESULT, 0
# 23 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq Nature_Changer_Neutral_Nature
# 24 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_BadTaste, MSGBOX_DEFAULT
# 25 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto NatureChanger_2
# 26 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 27 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
SlateportCity_NameRatersHouse_NatureChangerIntro::
# 28 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setflag FLAG_MET_NATURE_CHANGER
# 29 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	return
# 30 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 31 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Changer_Neutral_Nature::
# 32 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_BoringTaste, MSGBOX_DEFAULT
# 33 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto NatureChanger_2
# 34 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 35 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_2::
# 36 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_HowAboutIt, MSGBOX_YESNO
# 37 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	compare VAR_RESULT, 1
# 38 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq Nature_Changer_Yes
# 39 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	compare VAR_RESULT, 0
# 40 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq Nature_Changer_No
# 41 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 42 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Changer_Yes::
# 43 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	checkitem ITEM_ORAN_BERRY, NATURE_CHANGER_COST
# 44 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	compare VAR_RESULT, 1
# 45 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq Nature_Changer_Stat_Up
# 46 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	compare VAR_RESULT, 0
# 47 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto_if_eq Nature_Changer_Berry_Poor
# 48 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 49 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Changer_No::
# 50 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_SomeOtherTime, MSGBOX_DEFAULT
# 51 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	releaseall
# 52 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 53 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 54 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Changer_Egg::
# 55 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_ThisIsEgg, MSGBOX_DEFAULT
# 56 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	releaseall
# 57 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 58 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 59 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Changer_Berry_Poor::
# 60 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_NeedMoreBerries, MSGBOX_DEFAULT
# 61 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	releaseall
# 62 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 63 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 64 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Changer_Stat_Up::
# 65 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	message NatureChanger_Text_WhichColorPrefer
# 66 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	waitmessage
# 67 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	multichoice 0, 0, MULTI_FLAVORS, 0
# 68 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	switch VAR_RESULT
# 69 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 0, Nature_Up_ATK
# 70 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 1, Nature_Up_DEF
# 71 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 2, Nature_Up_SPATK
# 72 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 3, Nature_Up_SPDEF
# 73 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 4, Nature_Up_SPEED
# 74 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 127, Nature_Changer_No
# 75 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 76 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Up_ATK::
# 77 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8005, 0
# 78 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Stat_Down
# 79 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 80 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Up_DEF::
# 81 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8005, 1
# 82 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Stat_Down
# 83 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	
# 84 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Up_SPEED::
# 85 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8005, 2
# 86 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Stat_Down
# 87 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	
# 88 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Up_SPATK::
# 89 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8005, 3
# 90 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Stat_Down
# 91 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	
# 92 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Up_SPDEF::
# 93 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8005, 4
# 94 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Stat_Down
# 95 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	
# 96 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Changer_Stat_Down::
# 97 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	message NatureChanger_Text_WhichColorDislike
# 98 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	waitmessage
# 99 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	multichoice 0, 0, MULTI_FLAVORS, 0
# 100 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	switch VAR_RESULT
# 101 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 0, Nature_Down_ATK
# 102 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 1, Nature_Down_DEF
# 103 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 2, Nature_Down_SPATK
# 104 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 3, Nature_Down_SPDEF
# 105 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 4, Nature_Down_SPEED
# 106 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	case 127, Nature_Changer_No
# 107 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 108 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Down_ATK::
# 109 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8006, 0
# 110 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Nature_Change
# 111 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 112 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Down_DEF::
# 113 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8006, 1
# 114 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Nature_Change
# 115 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	
# 116 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Down_SPEED::
# 117 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8006, 2
# 118 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Nature_Change
# 119 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	
# 120 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Down_SPATK::
# 121 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8006, 3
# 122 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Nature_Change
# 123 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	
# 124 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Down_SPDEF::
# 125 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	setvar VAR_0x8006, 4
# 126 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	goto Nature_Changer_Nature_Change
# 127 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 128 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
Nature_Changer_Nature_Change::
# 129 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	removeitem ITEM_ORAN_BERRY, NATURE_CHANGER_COST
# 130 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	bufferpartymonnick 0, VAR_0x8004
# 131 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_SpecialPokeblock, MSGBOX_DEFAULT
# 132 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	fadescreen 1
# 133 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special ChangePokemonNature
# 134 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	special BufferChosenMonNature
# 135 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	specialvar VAR_0x8007, GetSelectedMonNicknameAndSpecies
# 136 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	waitse
# 137 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_Pause, MSGBOX_AUTOCLOSE
# 138 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	playmoncry VAR_0x8007, 0
# 139 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	waitmoncry
# 140 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	fadescreen 0
# 141 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	playfanfare 0x173
# 142 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	waitfanfare
# 143 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_MonHasNature1, MSGBOX_AUTOCLOSE
# 144 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	waitfanfare
# 145 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	msgbox NatureChanger_Text_ItIsDone MSGBOX_AUTOCLOSE
# 146 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	releaseall
# 147 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	end
# 148 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 149 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_Intro:
# 150 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Ohohoho! You are a Trainer, yes?\p"
# 151 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "How fortunate you are to have\n"
# 152 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "stumbled into my home!\p"
# 153 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I was once the greatest {POKEBLOCK}\n"
# 154 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "chef in all of Kalos!\p"
# 155 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "With but one taste of my {POKEBLOCK}s,\n"
# 156 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "your Pokémon will never want anything\l"
# 157 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "else again!\p"
# 158 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Now, listen!\p"
# 159 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "A Pokémon's taste in {POKEBLOCK}s\n"
# 160 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "determines their very Nature!\p"
# 161 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "How they battle, how they grow!\n"
# 162 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "All decided by their likes and dislikes!\p"
# 163 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "So, do you see?\p"
# 164 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "If a Pokémon wants only the {POKEBLOCK}\n"
# 165 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "flavor I have given them, their Nature\l"
# 166 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "will change!$"
# 167 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 168 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_ChoosePokemon:
# 169 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Which Pokémon needs my help?$"
# 170 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 171 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_MonHasNature:
# 172 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Ohohoho! I see your {STR_VAR_1} has\n"
# 173 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "a {STR_VAR_2} Nature, yes?$"
# 174 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 175 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_BadTaste:
# 176 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "That means it likes {STR_VAR_1}s.\n"
# 177 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "This simply will not do!\p"
# 178 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "You will bring me five Oran Berries,\n"
# 179 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "and I shall create a {POKEBLOCK} that\l"
# 180 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "will fix this travesty!$"
# 181 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 182 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_HowAboutIt:
# 183 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "So, we will do this, yes?\n"
# 184 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "We will change your Pokémon's Nature?$"
# 185 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 186 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_SomeOtherTime:
# 187 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "No?!\n"
# 188 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Surely you cannot mean this!$"
# 189 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 190 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_ThisIsEgg:
# 191 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "This is but an Egg!\p$"
# 192 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "An Egg cannot eat a {POKEBLOCK}!$"
# 193 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 194 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_NeedMoreBerries:
# 195 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "I need more Oran Berries than that.\n"
# 196 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Bring me five!$"
# 197 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 198 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_BoringTaste:
# 199 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "That means it will eat any {POKEBLOCK}!\n"
# 200 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "This simply will not do!\p"
# 201 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "You will bring me five Oran Berries,\n"
# 202 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "and I shall create a {POKEBLOCK} that\l"
# 203 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "will fix this travesty!$"
# 204 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 205 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_WhichColorPrefer:
# 206 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Ah! Very good!\p" 
# 207 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Now, which {POKEBLOCK} color should\n"
# 208 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "your Pokémon prefer?$"
# 209 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 210 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_WhichColorDislike:
# 211 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "And which {POKEBLOCK} color should\n"
# 212 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "it dislike?$"
# 213 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 214 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_SpecialPokeblock:
# 215 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Wait just a moment…$"
# 216 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 217 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_Pause:
# 218 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "… … … … … …$"
# 219 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 220 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_ItIsDone:
# 221 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "Oho! It is done!\p"
# 222 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"

# 223 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
NatureChanger_Text_MonHasNature1:
# 224 "data/maps/SlateportCity_NameRatersHouse/scripts.pory"
	.string "{STR_VAR_1}'s Nature became {STR_VAR_2}!$"
