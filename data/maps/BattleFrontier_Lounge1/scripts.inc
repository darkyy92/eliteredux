# 1 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_MapScripts:: @ 825E774
# 3 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge1/scripts.pory"
@ NPC that rates pokemon based on their IVs
# 6 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_Breeder:: @ 825E775
# 7 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	lock
# 8 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	faceplayer
# 9 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
# 10 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
# 11 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
# 12 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
# 13 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 14 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 15 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder:: @ 825E792
# 16 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	special ChoosePartyMon
# 17 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	waitstate
# 18 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8004, 255
# 19 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_ne BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
# 20 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8004, 255
# 21 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq BattleFrontier_Lounge1_EventScript_CancelMonSelect
# 22 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 23 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 24 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_BreederIntro:: @ 825E7AD
# 25 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
# 26 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	return
# 27 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 28 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder:: @ 825E7B6
# 29 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
# 30 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	return
# 31 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 32 "data/maps/BattleFrontier_Lounge1/scripts.pory"
@ BufferVarsForIVRater buffers the following values
# 33 "data/maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8005: Sum of the mons IVs
# 34 "data/maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8006: Stat id of highest IV stat
# 35 "data/maps/BattleFrontier_Lounge1/scripts.pory"
@ VAR_0x8007: IV of the highest IV stat
# 36 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder:: @ 825E7BF
# 37 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 38 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
# 39 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
# 40 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	special BufferVarsForIVRater
# 41 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8005, 90   @ Average of 15
# 42 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le BattleFrontier_Lounge1_EventScript_AverageTotalIVs
# 43 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8005, 120  @ Average of 20
# 44 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs
# 45 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8005, 150  @ Average of 25
# 46 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le BattleFrontier_Lounge1_EventScript_HighTotalIVs
# 47 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8005, 151  @ Average of > 25
# 48 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_ge BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs
# 49 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 50 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 51 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_ShowEggToBreeder:: @ 825E7FF
# 52 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
# 53 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
# 54 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 55 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 56 "data/maps/BattleFrontier_Lounge1/scripts.pory"
@ Comment on the highest IV stat
# 57 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVStat:: @ 825E80D
# 58 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8006, STAT_HP
# 59 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVHP
# 60 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8006, STAT_ATK
# 61 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVAtk
# 62 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8006, STAT_DEF
# 63 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVDef
# 64 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8006, STAT_SPEED
# 65 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVSpeed
# 66 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8006, STAT_SPATK
# 67 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
# 68 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8006, STAT_SPDEF
# 69 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVSpDef
# 70 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 71 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 72 "data/maps/BattleFrontier_Lounge1/scripts.pory"
@ Comment on the highest IV value
# 73 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVValue:: @ 825E850
# 74 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8007, 15
# 75 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le BattleFrontier_Lounge1_EventScript_HighestIVLow
# 76 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8007, 25
# 77 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le BattleFrontier_Lounge1_EventScript_HighestIVMid
# 78 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8007, 30
# 79 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_le BattleFrontier_Lounge1_EventScript_HighestIVHigh
# 80 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	compare VAR_0x8007, 31
# 81 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto_if_ge BattleFrontier_Lounge1_EventScript_HighestIVMax
# 82 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 83 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 84 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_EndBreederComments:: @ 825E87D
# 85 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	release
# 86 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 87 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 88 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AverageTotalIVs:: @ 825E87F
# 89 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
# 90 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 91 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 92 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 93 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs:: @ 825E88D
# 94 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
# 95 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 96 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 97 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 98 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighTotalIVs:: @ 825E89B
# 99 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
# 100 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 101 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 102 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 103 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs:: @ 825E8A9
# 104 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
# 105 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
# 106 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 107 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 108 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVHP:: @ 825E8B7
# 109 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
# 110 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 111 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 112 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 113 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVAtk:: @ 825E8C5
# 114 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
# 115 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 116 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 117 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 118 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVDef:: @ 825E8D3
# 119 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
# 120 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 121 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 122 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 123 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpeed:: @ 825E8E1
# 124 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
# 125 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 126 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 127 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 128 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpAtk:: @ 825E8EF
# 129 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
# 130 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 131 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 132 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 133 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVSpDef:: @ 825E8FD
# 134 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
# 135 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
# 136 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 137 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 138 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVLow:: @ 825E90B
# 139 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
# 140 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 141 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 142 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 143 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVMid:: @ 825E919
# 144 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
# 145 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 146 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 147 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 148 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVHigh:: @ 825E927
# 149 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
# 150 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 151 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 152 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 153 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_HighestIVMax:: @ 825E935
# 154 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
# 155 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
# 156 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 157 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 158 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_CancelMonSelect:: @ 825E943
# 159 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
# 160 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	release
# 161 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 162 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 163 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_Boy1:: @ 825E94D
# 164 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
# 165 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 166 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 167 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_EventScript_Boy2:: @ 825E956
# 168 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
# 169 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	end
# 170 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 171 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_PokemonBreederIntro: @ 825E95F
# 172 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "For 70 years I have raised Pokémon!\n"
# 173 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I am the man they revere as\l"
# 174 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "the legendary top Pokémon BREEDER!\p"
# 175 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "If you ever become as seasoned as me,\n"
# 176 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "you'll see the abilities of Pokémon\l"
# 177 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "at a glance.\p"
# 178 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You're a Trainer. Doesn't it interest\n"
# 179 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "you to know your own Pokémon's\l"
# 180 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "abilities?\p"
# 181 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Here!\n"
# 182 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Let's have a look at your Pokémon!$"
# 183 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 184 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_AverageAbility: @ 825EA92
# 185 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 186 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would describe\n"
# 187 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "as being of average ability.$"
# 188 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 189 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BetterThanAverageAbility: @ 825EAD9
# 190 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 191 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would describe as\n"
# 192 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "having better-than-average ability.$"
# 193 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 194 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_ImpressiveAbility: @ 825EB2A
# 195 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 196 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would say is\n"
# 197 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "quite impressive in ability!$"
# 198 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 199 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_OutstandingAbility: @ 825EB6F
# 200 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hmm…\p"
# 201 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "This one, overall, I would say is\n"
# 202 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "wonderfully outstanding in ability!$"
# 203 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 204 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectHP: @ 825EBBB
# 205 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 206 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its HP…$"
# 207 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 208 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectAtk: @ 825EBF8
# 209 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 210 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its ATTACK…$"
# 211 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 212 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectDef: @ 825EC39
# 213 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 214 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its DEFENSE…$"
# 215 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 216 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpAtk: @ 825EC7B
# 217 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 218 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPECIAL ATTACK…$"
# 219 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 220 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpDef: @ 825ECC4
# 221 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 222 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPECIAL DEFENSE…$"
# 223 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 224 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_BestAspectSpeed: @ 825ED0E
# 225 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Incidentally, the best aspect of it,\n"
# 226 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I would say, is its SPEED…$"
# 227 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 228 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatRelativelyGood: @ 825ED4E
# 229 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is relatively good.\n"
# 230 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 231 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 232 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatImpressive: @ 825ED87
# 233 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is quite impressive.\n"
# 234 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 235 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 236 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatOutstanding: @ 825EDC1
# 237 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "That stat is outstanding!\n"
# 238 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 239 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 240 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_StatFlawless: @ 825EDF6
# 241 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "It's flawless! A thing of perfection!\n"
# 242 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "…Hm… That's how I call it.$"
# 243 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 244 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_NoTimeForMyAdvice: @ 825EE37
# 245 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "What?\n"
# 246 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You have no time for my advice?\p"
# 247 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "You should always be eager to learn\n"
# 248 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "from the experiences of your elders!$"
# 249 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 250 "data/maps/BattleFrontier_Lounge1/scripts.pory"
@ Unused
# 251 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending: @ 825EEA6
# 252 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Yes, what is it now?\p"
# 253 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I have business that needs tending!\n"
# 254 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Save it for next time!$"
# 255 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 256 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon: @ 825EEF6
# 257 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Ah, youngster! Do your Pokémon's\n"
# 258 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "abilities intrigue you?\p"
# 259 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Here, here!\n"
# 260 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Let's have a look at your Pokémon!$"
# 261 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 262 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_EvenICantTell: @ 825EF5E
# 263 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "An expert I am, but even I can't tell\n"
# 264 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "anything about an unhatched Pokémon!\p"
# 265 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "Show me a Pokémon!\n"
# 266 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "A Pokémon is what I need to see!$"
# 267 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 268 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding: @ 825EFDD
# 269 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "He said my Pokémon is outstanding!\n"
# 270 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "I'm glad I raised it carefully!$"
# 271 "data/maps/BattleFrontier_Lounge1/scripts.pory"

# 272 "data/maps/BattleFrontier_Lounge1/scripts.pory"
BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt: @ 825F020
# 273 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "He said my Pokémon is outstanding!\n"
# 274 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "But I didn't do anything special\l"
# 275 "data/maps/BattleFrontier_Lounge1/scripts.pory"
	.string "raising it…$"
