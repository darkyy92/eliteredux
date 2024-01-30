# 1 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 2 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_MapScripts:: @ 8203030
# 3 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 5 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater:: @ 8203031
# 6 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	lock
# 7 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	faceplayer
# 8 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
# 9 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
# 10 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case 0, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
# 12 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case 1, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
# 13 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case 2, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
# 14 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case 3, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
# 15 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case 4, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
# 16 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case 5, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
# 17 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	case 6, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
# 18 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 19 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 20 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 21 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou:: @ 8203094
# 22 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
# 23 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 24 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 25 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 26 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary:: @ 820309E
# 27 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
# 28 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 29 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 30 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 31 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou:: @ 82030A8
# 32 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
# 33 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 34 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 35 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 36 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou:: @ 82030B2
# 37 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
# 38 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 39 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 40 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 41 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot:: @ 82030BC
# 42 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
# 43 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 44 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 45 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 46 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy:: @ 82030C6
# 47 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
# 48 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 49 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 50 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 51 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou:: @ 82030D0
# 52 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
# 53 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 54 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 55 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 56 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu:: @ 82030DA
# 57 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	lock
# 58 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	faceplayer
# 59 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	waitse
# 60 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	playmoncry SPECIES_PIKACHU, 0
# 61 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
# 62 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	waitmoncry
# 63 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 64 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 65 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 66 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 67 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_Trader:: @ 8203C11
# 68 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	lock
# 69 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	faceplayer
# 70 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, VerdanturfTown_FriendshipRatersHouse_EventScript_TradeCompleted
# 71 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_HAPPINY
# 72 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 73 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 74 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 75 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_WillingToTradeIt, MSGBOX_YESNO
# 76 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	compare VAR_RESULT, NO
# 77 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	goto_if_eq VerdanturfTown_FriendshipRatersHouse_EventScript_DeclineTrade
# 78 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	special ChoosePartyMon
# 79 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	waitstate
# 80 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 81 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	compare VAR_0x8004, 255
# 82 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	goto_if_eq VerdanturfTown_FriendshipRatersHouse_EventScript_DeclineTrade
# 83 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 84 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 85 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 86 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	compare VAR_RESULT, VAR_0x8009
# 87 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	goto_if_ne VerdanturfTown_FriendshipRatersHouse_EventScript_NotRequestedMon
# 88 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 89 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 90 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	special CreateInGameTradePokemon
# 91 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	special DoInGameTradeScene
# 92 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	waitstate
# 93 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	bufferspeciesname 0, VAR_0x8009
# 94 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
# 95 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
# 96 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 97 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 98 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 99 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_DeclineTrade:: @ 8203C93
# 100 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
# 101 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 102 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 103 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 104 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_NotRequestedMon:: @ 8203C9D
# 105 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	bufferspeciesname 0, VAR_0x8009
# 106 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
# 107 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 108 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 109 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 110 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_EventScript_TradeCompleted:: @ 8203CAB
# 111 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
# 112 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	release
# 113 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	end
# 114 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	
# 115 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_WillingToTradeIt: @ 8203CBE
# 116 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Check out this {STR_VAR_2}!\p"
# 117 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It's the {STR_VAR_2} that I caught\n"
# 118 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "yesterday to celebrate my birthday!\p"
# 119 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Oh, I can see that you want it!\n"
# 120 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "After all, it's priceless!\p"
# 121 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "I'll tell you what. I might be willing\n"
# 122 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "to trade it for a {STR_VAR_1}.$"
# 123 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 124 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_ItsSubtlyDifferentThankYou: @ 8203D87
# 125 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Oh, so this is a {STR_VAR_1}?\p"
# 126 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It's sort of like a {STR_VAR_2},\n"
# 127 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "and yet it's subtly different.\p"
# 128 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Thank you!$"
# 129 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 130 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_WontAcceptAnyLessThanRealMon: @ 8203DDE
# 131 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "No, no, no! I won't accept any\n"
# 132 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "less than a real {STR_VAR_1}!$"
# 133 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 134 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_NotDesperateOrAnything: @ 8203E12
# 135 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Oh, so you're not going to go through\n"
# 136 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "with this?\p"
# 137 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "That's cool. I'm not desperate to make\n"
# 138 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "a trade or anything.$"
# 139 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 140 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_ReallyWantedToGetBagon: @ 8203E7F
# 141 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "I know I could go looking for one\n"
# 142 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "on my own, but…\p"
# 143 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "But I really wanted to get a Pyukumuku\n"
# 144 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "that another Trainer caught…$"
# 145 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 146 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou: @ 82030ED
# 147 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Let me see your Pokémon.\n"
# 148 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "I'll check to see how much it likes you.\p"
# 149 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Oh.\n"
# 150 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Your Pokémon…$"
# 151 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 152 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou: @ 8203141
# 153 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It adores you.\n"
# 154 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It can't possibly love you any more.\l"
# 155 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "I even feel happy seeing it.$"
# 156 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 157 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy: @ 8203192
# 158 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It seems to be very happy.\n"
# 159 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It obviously likes you a whole lot.$"
# 160 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 161 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot: @ 82031D1
# 162 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It likes you quite a lot.\n"
# 163 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It seems to want to be babied a little.$"
# 164 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 165 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou: @ 8203213
# 166 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It's getting used to you.\n"
# 167 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It seems to believe in you.$"
# 168 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 169 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou: @ 8203249
# 170 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It's not very used to you yet.\n"
# 171 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It neither loves nor hates you.$"
# 172 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 173 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_VeryWary: @ 8203288
# 174 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It's very wary.\n"
# 175 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It has scary viciousness in its eyes.\l"
# 176 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "It doesn't like you much at all.$"
# 177 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 178 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou: @ 82032DF
# 179 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "This is a little hard for me to say…\p"
# 180 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Your Pokémon simply detests you.\n"
# 181 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Doesn't that make you uncomfortable?$"
# 182 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"

# 183 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
VerdanturfTown_FriendshipRatersHouse_Text_Pikachu: @ 820334A
# 184 "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.pory"
	.string "Pikachu: Pika pika!$"
