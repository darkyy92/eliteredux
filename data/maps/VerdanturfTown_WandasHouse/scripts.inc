# 1 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 2 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_MapScripts:: @ 82028BE
# 3 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 5 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_Wally:: @ 82028BF
# 6 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	lock
# 7 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	faceplayer
# 8 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
# 9 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
# 10 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	setflag FLAG_WALLY_SPEECH
# 11 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 12 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 13 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 14 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech:: @ 82028D7
# 15 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
# 16 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 17 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 18 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 19 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysUncle:: @ 82028E1
# 20 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	lock
# 21 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	faceplayer
# 22 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
# 23 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
# 24 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
# 25 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 26 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 27 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 28 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff:: @ 82028FF
# 29 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
# 30 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 31 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 32 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 33 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande:: @ 8202909
# 34 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
# 35 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 36 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 37 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 38 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend:: @ 8202913
# 39 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
# 40 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 41 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 42 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_Wanda::
# 43 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	lock
# 44 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	faceplayer
# 45 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
# 46 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
# 47 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
# 48 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 49 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 50 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 51 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_MeetWanda::
# 52 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
# 53 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM04, VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite
# 54 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 55 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 56 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 57 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
# 58 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
# 59 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM04, VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite
# 60 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 61 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 62 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 63 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WandaGardevoirite::
# 64 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_WANDA_GARDEVOIRITE, VerdanturfTown_WandasHouse_EventScript_WandaGaveStone
# 65 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	playse SE_PIN
# 66 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	applymovement 5, Common_Movement_ExclamationMark
# 67 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	waitmovement 0
# 68 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	applymovement 5, Common_Movement_Delay48
# 69 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	waitmovement 0
# 70 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_ReceiveGardevoirite, MSGBOX_DEFAULT
# 71 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	givecustommon SPECIES_GARDEVOIR, 40, ITEM_CHOICE_SCARF, ITEM_POKE_BALL, NATURE_TIMID, 1, 4, 0, 0, 252, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_DAZZLING_GLEAM, MOVE_MYSTICAL_FIRE, MOVE_THUNDERBOLT, MOVE_PSYCHIC, TRUE
# 72 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 73 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	message VerdanturfTown_WandasHouse_Text_Got_Gardevoir
# 74 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	waitfanfare
# 75 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	setflag FLAG_WANDA_GARDEVOIRITE
# 76 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_PrettyStone, MSGBOX_DEFAULT
# 77 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 78 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 79 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 80 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WandaGaveStone::
# 81 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 82 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 83 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 84 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysAunt::
# 85 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	lock
# 86 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	faceplayer
# 87 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
# 88 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
# 89 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
# 90 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
# 91 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 92 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 93 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 94 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen:: @ 8202975
# 95 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
# 96 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 97 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 98 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 99 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened:: @ 820297F
# 100 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
# 101 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 102 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 103 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 104 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande:: @ 8202989
# 105 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
# 106 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	release
# 107 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	end
# 108 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 109 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_StrongerSpeech: @ 8202993
# 110 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Wally: I lost to you, {PLAYER}, but I'm\n"
# 111 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "not feeling down anymore.\p"
# 112 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Because I have a new purpose in life.\n"
# 113 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Together with my Gardevoir, I'm going\l"
# 114 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "to challenge Pokémon Gyms and become\l"
# 115 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "a great Trainer.\p"
# 116 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Please watch me, {PLAYER}.\n"
# 117 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I'm going to be stronger than you.\p"
# 118 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "When I do, I'm going to challenge you\n"
# 119 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "to another battle.$"
# 120 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 121 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_StrongerSpeechShort: @ 8202ABE
# 122 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Wally: Please watch me, {PLAYER}.\n"
# 123 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I'm going to get stronger than you.\p"
# 124 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "When I do, I'm going to challenge you\n"
# 125 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "to another battle.$"
# 126 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 127 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_WallysNextDoor: @ 8202B37
# 128 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Uncle: Oh! {PLAYER}{KUN}!\n"
# 129 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Wally's next door.\p"
# 130 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "But, boy, there's something I have to\n"
# 131 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "tell you.\p"
# 132 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "This natural environment is doing\n"
# 133 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "wonders for Wally's health.\p"
# 134 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Maybe it's not just the environment.\n"
# 135 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "It could be Pokémon that are giving\l"
# 136 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "the boy hope.$"
# 137 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 138 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_WallySlippedOff: @ 8202C20
# 139 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Wally's gone away…\n"
# 140 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "He slipped off on his own…$"
# 141 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 142 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_WallyGoneThatFar: @ 8202C4E
# 143 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Uncle: Is that right?\n"
# 144 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Wally's gone away that far all by\l"
# 145 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "himself…\p"
# 146 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Well, I have to give him credit--he is\n"
# 147 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "my little brother's son.$"
# 148 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 149 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_MeetWanda:
# 150 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Wanda: You are?\n"
# 151 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Oh, right, I get it!\p"
# 152 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "You're the {PLAYER} who Wally was\n"
# 153 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "telling me about.\p"
# 154 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I'm Wally's cousin.\n"
# 155 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Glad to meet you!\p"
# 156 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I think Wally's become a lot more lively\n"
# 157 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "and healthy since he came here.$"
# 158 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 159 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_ReceiveGardevoirite:
# 160 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I didn't really thank you properly when\n"
# 161 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "you helped smash those rocks in the\l"
# 162 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "tunnel.\p"
# 163 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I was thinking that I wanted to give\n"
# 164 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "this {COLOR BLUE}Gardevoir{COLOR DARK_GRAY} to you…$"
# 165 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 166 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_PrettyStone:
# 167 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "It's a pretty Pokémon, I hope\n"
# 168 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "you like it as much as I do.$"
# 169 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 170 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_DontWorryAboutWally: @ 8202D91
# 171 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Wanda: Don't worry about Wally.\n"
# 172 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "He'll be just fine.\p"
# 173 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I know my little cousin, and he has\n"
# 174 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Pokémon with him, too.$"
# 175 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 176 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay: @ 8202E00
# 177 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Thanks to you, I can see my girlfriend\n"
# 178 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "every day.\l"
# 179 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Happy? You bet I am!$"
# 180 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 181 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven: @ 8202E47
# 182 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "My daughter's boyfriend is a very\n"
# 183 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "driven and passionate sort of person.\p"
# 184 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "He's been digging a tunnel nonstop\n"
# 185 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "just so he can see my daughter.\p"
# 186 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "My daughter's a little concerned,\n"
# 187 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "so she goes out to the tunnel a lot.$"
# 188 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 189 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging: @ 8202F19
# 190 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "It's amazing. My daughter's boyfriend\n"
# 191 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "was digging the tunnel by hand!\p"
# 192 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "It's so incredible!$"
# 193 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 194 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally: @ 8202F73
# 195 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "If anything were to happen to Wally,\n"
# 196 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "I would never be able to look his\l"
# 197 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "parents in Petalburg in the eye…$"
# 198 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"

# 199 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande: @ 8202FDB
# 200 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "Wally was in Ever Grande?\p"
# 201 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "His parents in Petalburg would be\n"
# 202 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "astonished to hear that!$"

VerdanturfTown_WandasHouse_Text_Got_Gardevoir::
# 205 "data/maps/VerdanturfTown_WandasHouse/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Gardevoir{COLOR DARK_GRAY} as a gift!$"
