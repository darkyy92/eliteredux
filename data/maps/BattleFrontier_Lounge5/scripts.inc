# 1 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_MapScripts:: @ 82645C5
# 3 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirl:: @ 82645C6
# 6 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	lock
# 7 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	faceplayer
# 8 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
# 9 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	compare VAR_RESULT, NO
# 10 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
# 11 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	special ChoosePartyMon
# 12 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	waitstate
# 13 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	lock
# 14 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	faceplayer
# 15 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	compare VAR_0x8004, 255
# 16 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
# 17 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 18 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	compare VAR_RESULT, SPECIES_EGG
# 19 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlEgg
# 20 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	special ShowNatureGirlMessage
# 21 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	waitmessage
# 22 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	waitbuttonpress
# 23 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 24 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 25 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 26 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirlEgg:: @ 8264603
# 27 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
# 28 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 29 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 30 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 31 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown:: @ 826460D
# 32 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
# 33 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	release
# 34 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 35 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 36 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_Gentleman:: @ 8264617
# 37 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
# 38 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 39 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 40 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_BlackBelt:: @ 8264620
# 41 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
# 42 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 43 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 44 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_EventScript_LittleBoy:: @ 8264629
# 45 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
# 46 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	end
# 47 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 48 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlGreeting:: @ 8264632
# 49 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Ehehe!\n"
# 50 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I can tell what Pokémon are thinking!\p"
# 51 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Please!\n"
# 52 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Can I see your Pokémon?$"
# 53 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 54 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlNoneShown:: @ 826467F
# 55 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Boo!\n"
# 56 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Cheapie!$"
# 57 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 58 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlHardy:: @ 826468D
# 59 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 60 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 61 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It will battle even if it has a lot\l"
# 62 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "of ouchies!$"
# 63 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 64 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlLonely:: @ 82646E5
# 65 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 66 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 67 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 68 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will hit back!$"
# 69 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 70 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlBrave:: @ 8264741
# 71 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 72 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 73 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 74 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will worry about itself!$"
# 75 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 76 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlAdamant:: @ 82647A4
# 77 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 78 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 79 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It will battle even if it has a lot\l"
# 80 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "of ouchies!$"
# 81 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 82 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlNaughty:: @ 82647FC
# 83 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 84 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 85 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 86 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will hit back!$"
# 87 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 88 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlBold:: @ 8264858
# 89 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 90 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 91 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 92 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will worry about itself!$"
# 93 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 94 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky:: @ 82648BE
# 95 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 96 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 97 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It will battle even if it has a lot\l"
# 98 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "of ouchies!$"
# 99 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 100 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlRelaxed:: @ 8264916
# 101 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 102 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 103 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 104 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will hit back!$"
# 105 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 106 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlImpish:: @ 8264972
# 107 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 108 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 109 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 110 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will worry about itself!$"
# 111 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 112 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlLax:: @ 82649D5
# 113 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 114 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 115 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it likes to be sneaky even\l"
# 116 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "if it has a lot of ouchies!$"
# 117 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 118 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlTimid:: @ 8264A3F
# 119 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 120 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 121 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 122 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will turn sneaky!$"
# 123 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 124 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlHasty:: @ 8264A9B
# 125 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 126 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 127 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It will battle even if it has a lot\l"
# 128 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "of ouchies!$"
# 129 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 130 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlSerious:: @ 8264AF3
# 131 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 132 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 133 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it likes to be sneaky even\l"
# 134 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "if it has a lot of ouchies!$"
# 135 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 136 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlJolly:: @ 8264B5D
# 137 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 138 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 139 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 140 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will worry about itself!$"
# 141 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 142 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlModest:: @ 8264BC3
# 143 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 144 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 145 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it worries about itself whether\l"
# 146 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "or not it has a lot of ouchies!$"
# 147 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 148 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlMild:: @ 8264C36
# 149 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 150 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 151 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 152 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will turn sneaky!$"
# 153 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 154 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlBashful:: @ 8264C95
# 155 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 156 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 157 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it worries about itself even\l"
# 158 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "if it has a lot of ouchies!$"
# 159 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 160 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlRash:: @ 8264D01
# 161 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 162 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to be sneaky!\n"
# 163 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it likes to be sneaky even\l"
# 164 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "if it has a lot of ouchies!$"
# 165 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 166 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlCalm:: @ 8264D6B
# 167 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 168 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 169 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "It says it worries about itself even\l"
# 170 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "if it has a lot of ouchies!$"
# 171 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 172 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlGentle:: @ 8264DD7
# 173 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 174 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 175 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 176 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will hit back!$"
# 177 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 178 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlSassy:: @ 8264E33
# 179 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 180 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it likes to battle!\n"
# 181 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 182 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will turn sneaky!$"
# 183 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 184 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlCareful:: @ 8264E8F
# 185 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "Hmhm…\p"
# 186 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "This one says it looks after itself!\n"
# 187 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "But if it gets enough ouchies,\l"
# 188 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "it will turn sneaky!$"
# 189 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 190 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_NatureGirlEgg:: @ 8264EEE
# 191 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That's silly! An Egg is asleep!\n"
# 192 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I can't talk to it!$"
# 193 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 194 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon:: @ 8264F22
# 195 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "How charming!\n"
# 196 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That little lady claims she can\l"
# 197 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "understand Pokémon!$"
# 198 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 199 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound:: @ 8264F64
# 200 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I have this feeling that the little girl\n"
# 201 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "is saying something profound.$"
# 202 "data/maps/BattleFrontier_Lounge5/scripts.pory"

# 203 "data/maps/BattleFrontier_Lounge5/scripts.pory"
BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot:: @ 8264FAB
# 204 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "I know something!\p"
# 205 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "That little girl plays at the red house\n"
# 206 "data/maps/BattleFrontier_Lounge5/scripts.pory"
	.string "a lot!$"
