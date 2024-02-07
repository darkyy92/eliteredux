# 1 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_MapScripts:: @ 8260642
# 3 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ This NPC gives hints about a random facility or battle mode.
# 6 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ For battle modes he gives generic advice 
# 7 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ For facilities, depending on how far the player has progressed he will say either
# 8 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@    The name of the Frontier Brain there
# 9 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@    The type and description of the 3 pokemon they use in their silver battle
# 10 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@    The type and description of the 3 pokemon they use in their gold battle
# 11 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_FrontierManiac:: @ 8260643
# 12 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	lock
# 13 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	faceplayer
# 14 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
# 15 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
# 16 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
# 17 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
# 18 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 20 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_AlreadyMetManiac:: @ 826065F
# 21 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
# 22 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
# 23 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 24 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 25 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_GiveAdvice:: @ 826066D
# 26 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 0
# 27 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferSingle
# 28 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 1
# 29 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferDouble
# 30 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 2
# 31 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferMulti
# 32 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 3
# 33 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferMultiLink
# 34 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 4
# 35 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattleDome
# 36 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 5
# 37 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattleFactory
# 38 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 6
# 39 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattlePalace
# 40 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 7
# 41 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattleArena
# 42 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 8
# 43 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattlePike
# 44 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 9
# 45 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
# 46 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 3
# 47 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_le BattleFrontier_Lounge2_EventScript_BattleTowerNews
# 48 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	compare VAR_FRONTIER_MANIAC_FACILITY, 4
# 49 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	call_if_ge BattleFrontier_Lounge2_EventScript_FacilityNews
# 50 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	special ShowFrontierManiacMessage
# 51 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	waitmessage
# 52 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	waitbuttonpress
# 53 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	release
# 54 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 55 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 56 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BattleTowerNews:: @ 82606F8
# 57 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
# 58 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 59 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 60 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_FacilityNews:: @ 8260701
# 61 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
# 62 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 63 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 64 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferSingle:: @ 826070A
# 65 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_SINGLE
# 66 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 67 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 68 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferDouble:: @ 826070F
# 69 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_DOUBLE
# 70 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 71 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 72 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferMulti:: @ 8260714
# 73 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_MULTI
# 74 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 75 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 76 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferMultiLink:: @ 8260719
# 77 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_MULTI_LINK
# 78 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 79 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 80 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattleDome:: @ 826071E
# 81 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_BATTLE_DOME
# 82 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 83 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 84 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattleFactory:: @ 8260723
# 85 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_BATTLE_FACTORY
# 86 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 87 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 88 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattlePalace:: @ 8260728
# 89 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_BATTLE_PALACE
# 90 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 91 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 92 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattleArena:: @ 826072D
# 93 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_BATTLE_ARENA
# 94 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 95 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 96 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattlePike:: @ 8260732
# 97 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_BATTLE_PIKE
# 98 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 99 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 100 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_BufferBattlePyramid:: @ 8260737
# 101 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	bufferstdstring 0, STDSTRING_BATTLE_PYRAMID
# 102 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	return
# 103 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 104 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_Maniac1:: @ 826073C
# 105 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	lock
# 106 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
# 107 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	release
# 108 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 109 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 110 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_Maniac2:: @ 8260747
# 111 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	lock
# 112 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
# 113 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	release
# 114 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 115 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 116 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_Maniac3:: @ 8260752
# 117 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	lock
# 118 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
# 119 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	release
# 120 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 121 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 122 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_EventScript_TriathleteF:: @ 826075D
# 123 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
# 124 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	end
# 125 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 126 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FrontierManiacIntro:: @ 8260766
# 127 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Howdy! When it comes to news about\n"
# 128 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the Battle Frontier, I'm no. 1.\p"
# 129 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "You can think of me as\n"
# 130 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the FRONTIER MANIAC.\p"
# 131 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Just checking, but you are a Trainer,\n"
# 132 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "isn't that right?\p"
# 133 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "I'll happily share the hottest news\n"
# 134 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "I gathered about the Battle Frontier.$"
# 135 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 136 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_SwingByForTheLatestWord:: @ 8260857
# 137 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Howdy! Did you swing by to grill me\n"
# 138 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "about the latest word? Oh, all right!$"
# 139 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 140 "data/maps/BattleFrontier_Lounge2/scripts.pory"
@ Unused
# 141 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight:: @ 82608A1
# 142 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Well? Well? Well?\p"
# 143 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "I'm sure my information's been\n"
# 144 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "seriously useful to you, right?$"
# 145 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 146 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FacilityIsHottest:: @ 82608F2
# 147 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Let's see now…\p"
# 148 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It sounds like the {STR_VAR_1}\n"
# 149 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "is the hottest place going.$"
# 150 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 151 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_BattleTowerIsHottest:: @ 8260933
# 152 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Let's see now…\p"
# 153 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It sounds like Battle Tower\n"
# 154 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "{STR_VAR_1} is the hottest.$"
# 155 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 156 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_SalonMaidenIsThere:: @ 8260971
# 157 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 158 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top Trainers that SCOTT\n"
# 159 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 160 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this mysterious Trainer called\n"
# 161 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the SALON MAIDEN that runs the place.$"
# 162 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 163 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_SalonMaidenSilverMons:: @ 8260A1E
# 164 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the SALON MAIDEN?\p"
# 165 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's measuring up her opponent,\n"
# 166 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she apparently uses these Pokémon:\p"
# 167 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A Psychic-type PSI Pokémon,\n"
# 168 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a Fire-type VOLCANO Pokémon,\l"
# 169 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a NORMAL-type SLEEPING Pokémon.$"
# 170 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 171 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_SalonMaidenGoldMons:: @ 8260AE7
# 172 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the SALON MAIDEN\n"
# 173 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when she's serious?\p"
# 174 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's battling flat out,\n"
# 175 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she apparently uses these Pokémon:\p"
# 176 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A DRAGON & PSYCHIC EON Pokémon,\n"
# 177 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "an ELECTRIC-type THUNDER Pokémon,\l"
# 178 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a NORMAL-type SLEEPING Pokémon.$"
# 179 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 180 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DomeAceIsThere:: @ 8260BC4
# 181 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 182 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top Trainers that SCOTT\n"
# 183 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 184 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this flamboyant Trainer called\n"
# 185 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the DOME ACE that runs the place.$"
# 186 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 187 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DomeAceSilverMons:: @ 8260C6D
# 188 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the DOME ACE?\p"
# 189 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's treating the opponent\n"
# 190 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "lightly, he uses these three Pokémon:\p"
# 191 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A DRAGON & FLYING DRAGON Pokémon,\n"
# 192 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a WATER & GROUND MUD FISH Pokémon,\l"
# 193 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a FIRE & FLYING FLAME Pokémon.$"
# 194 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 195 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DomeAceGoldMons:: @ 8260D3A
# 196 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the DOME ACE\n"
# 197 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when he's serious?\p"
# 198 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's demonstrating his strategy,\n"
# 199 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he uses these three Pokémon:\p"
# 200 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A DRAGON & FLYING EON Pokémon,\n"
# 201 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a WATER & GROUND MUD FISH Pokémon,\l"
# 202 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a STEEL- & Psychic-type IRON LEG\l"
# 203 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Pokémon.$"
# 204 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 205 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FactoryHeadIsThere:: @ 8260E1E
# 206 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 207 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top Trainers that SCOTT\n"
# 208 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 209 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this freaky Trainer called\n"
# 210 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the FACTORY HEAD that runs the place.$"
# 211 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 212 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FactoryHeadSilverMons:: @ 8260EC7
# 213 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the FACTORY HEAD\n"
# 214 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "already?\p"
# 215 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Let me think… When he goes to battle,\n"
# 216 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he just gets three rental Pokémon.\p"
# 217 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "He battles under pretty much the same\n"
# 218 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "conditions as you.$"
# 219 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 220 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_FactoryHeadGoldMons:: @ 8260F74
# 221 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the FACTORY HEAD\n"
# 222 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when he's serious?\p"
# 223 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he goes seriously to battle,\n"
# 224 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he still gets three rental Pokémon.\p"
# 225 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "He battles under virtually the same\n"
# 226 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "conditions as you.$"
# 227 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 228 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PikeQueenIsThere:: @ 8261026
# 229 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 230 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top Trainers that SCOTT\n"
# 231 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 232 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this scary Trainer called\n"
# 233 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the PIKE QUEEN that runs the place.$"
# 234 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 235 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PikeQueenSilverMons:: @ 82610CC
# 236 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PIKE QUEEN\n"
# 237 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "before?\p"
# 238 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's in a good mood, they say\n"
# 239 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she uses these three Pokémon:\p"
# 240 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A POISON-type FANG SNAKE Pokémon,\n"
# 241 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a BUG & ROCK MOLD Pokémon,\l"
# 242 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a WATER-type TENDER Pokémon.$"
# 243 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 244 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PikeQueenGoldMons:: @ 8261194
# 245 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PIKE QUEEN\n"
# 246 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when she's serious?\p"
# 247 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's seriously annoyed, they say\n"
# 248 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she uses these three Pokémon:\p"
# 249 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A POISON-type FANG SNAKE Pokémon,\n"
# 250 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a STEEL & GROUND IRON SNAKE Pokémon,\l"
# 251 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a WATER- & Flying-type ATROCIOUS\l"
# 252 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Pokémon.$"
# 253 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 254 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_ArenaTycoonIsThere:: @ 8261282
# 255 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 256 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top Trainers that SCOTT\n"
# 257 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 258 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this cute Trainer called\n"
# 259 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the ARENA TYCOON that runs the place.$"
# 260 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 261 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons:: @ 8261329
# 262 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the ARENA TYCOON\n"
# 263 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "before?\p"
# 264 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she's assessing the foe's ability,\n"
# 265 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she supposedly uses these Pokémon:\p"
# 266 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A BUG & FIGHTING SINGLE HORN Pokémon,\n"
# 267 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a DARK-type MOONLIGHT Pokémon,\l"
# 268 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a BUG & GHOST SHED Pokémon.$"
# 269 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 270 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons:: @ 8261403
# 271 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the ARENA TYCOON\n"
# 272 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when she's serious?\p"
# 273 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When she battles for keeps,\n"
# 274 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "she supposedly uses these Pokémon:\p"
# 275 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A DARK-type MOONLIGHT Pokémon,\n"
# 276 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a GHOST & POISON SHADOW Pokémon\l"
# 277 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a GRASS- & FIGHTING-type\l"
# 278 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "MUSHROOM Pokémon.$"
# 279 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 280 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PalaceMavenIsThere:: @ 82614E6
# 281 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 282 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top Trainers that SCOTT\n"
# 283 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 284 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this sinister Trainer called\n"
# 285 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the PALACE MAVEN that runs the place.$"
# 286 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 287 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PalaceMavenSilverMons:: @ 8261591
# 288 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PALACE MAVEN\n"
# 289 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "before?\p"
# 290 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's testing the opponent's\n"
# 291 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "spirit, he's said to use these Pokémon:\p"
# 292 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A POISON & Flying-type BAT Pokémon,\n"
# 293 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a NORMAL-type LAZY Pokémon, and a\l"
# 294 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "WATER- & ICE-type TRANSPORT Pokémon.$"
# 295 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 296 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PalaceMavenGoldMons:: @ 826166F
# 297 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PALACE MAVEN\n"
# 298 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when he's serious?\p"
# 299 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he throws his entire might into\n"
# 300 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "battle, he's said to use these Pokémon:\p"
# 301 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A Fire-type LEGENDARY Pokémon,\n"
# 302 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "a NORMAL-type LAZY Pokémon,\l"
# 303 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a WATER-type AURORA Pokémon.$"
# 304 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 305 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PyramidKingIsThere:: @ 826174D
# 306 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Bet you didn't know this!\p"
# 307 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "One of those top Trainers that SCOTT\n"
# 308 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "calls the FRONTIER BRAINS is there.\p"
# 309 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's this fiery-hot Trainer called\n"
# 310 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the PYRAMID KING that runs the place.$"
# 311 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 312 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PyramidKingSilverMons:: @ 82617F9
# 313 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PYRAMID KING\n"
# 314 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "before?\p"
# 315 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's checking the foe's power,\n"
# 316 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he apparently uses these Pokémon:\p"
# 317 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "A ROCK-type ROCK PEAK Pokémon,\n"
# 318 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "an ICE-type ICEBERG Pokémon,\l"
# 319 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a STEEL-type IRON Pokémon.$"
# 320 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 321 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_PyramidKingGoldMons:: @ 82618C4
# 322 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Have you battled the PYRAMID KING\n"
# 323 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "when he's serious?\p"
# 324 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "When he's pumped with hot power,\n"
# 325 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "he apparently uses these Pokémon:\p"
# 326 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "An ICE & FLYING FREEZE Pokémon, an\n"
# 327 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "ELECTRIC & FLYING ELECTRIC Pokémon,\l"
# 328 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "and a FIRE- & Flying-type FLAME\l"
# 329 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Pokémon.$"
# 330 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 331 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DoubleBattleAdvice1:: @ 82619AC
# 332 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Sure, there are several places where\n"
# 333 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "you can enter Double Battles.\p"
# 334 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "But the Double Battle ROOMS of\n"
# 335 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the Battle Tower are, like, basic!\p"
# 336 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "They're where you should learn about\n"
# 337 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "how Double Battles are played here\l"
# 338 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "in the Battle Frontier.$"
# 339 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 340 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DoubleBattleAdvice2:: @ 8261A91
# 341 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Watch yourself in the battles here.\p"
# 342 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "I hear there are Trainers that have\n"
# 343 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "strategies they developed just for\l"
# 344 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Double Battles.$"
# 345 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 346 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_DoubleBattleAdvice3:: @ 8261B0C
# 347 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Once you're confident and comfortable\n"
# 348 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "with Double Battles here, you should\l"
# 349 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "think about challenging other places\l"
# 350 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "offering Double Battles.$"
# 351 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 352 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_MultiBattleAdvice:: @ 8261B95
# 353 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "All sorts of Trainers gather in\n"
# 354 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "the BATTLE SALON.\p"
# 355 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "Just think--you may run into your\n"
# 356 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "friends or followers!\l"
# 357 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "You should look carefully!$"
# 358 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 359 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice:: @ 8261C1A
# 360 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "If you're with a friend, head for the\n"
# 361 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "LINK MULTI BATTLE ROOM.\p"
# 362 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "If you play with a strong friend,\n"
# 363 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "you can expect to see tough foes!$"
# 364 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 365 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_NewsGatheringPower:: @ 8261C9C
# 366 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "What amazing news-gathering power!\n"
# 367 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "My mentor's like none other!$"
# 368 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 369 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_AmazingPowersOfObservation:: @ 8261CDC
# 370 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "What amazing powers of observation!\n"
# 371 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "My mentor's like none other!$"
# 372 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 373 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion:: @ 8261D1D
# 374 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "What amazing power of persuasion!\n"
# 375 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "My mentor's like none other!$"
# 376 "data/maps/BattleFrontier_Lounge2/scripts.pory"

# 377 "data/maps/BattleFrontier_Lounge2/scripts.pory"
BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe:: @ 8261D5C
# 378 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "…What is this place?\n"
# 379 "data/maps/BattleFrontier_Lounge2/scripts.pory"
	.string "It's scaring me…$"
