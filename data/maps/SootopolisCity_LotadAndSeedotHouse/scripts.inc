# 1 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 2 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_MapScripts:: @ 822722A
# 3 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 5 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother:: @ 822722B
# 6 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetSeedotSizeRecordInfo
# 7 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lock
# 8 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	faceplayer
# 9 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
# 10 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special ChoosePartyMon
# 11 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	waitstate
# 12 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8004
# 13 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, 255
# 14 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
# 15 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special CompareSeedotSize
# 16 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, 1
# 17 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
# 18 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, 2
# 19 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
# 20 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, 3
# 21 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
# 22 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 23 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 24 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 25 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot:: @ 8227272
# 26 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
# 27 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 28 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 29 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 30 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot:: @ 822727C
# 31 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
# 32 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 33 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 34 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 35 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot:: @ 8227286
# 36 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
# 37 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 38 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 39 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 40 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot:: @ 8227290
# 41 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
# 42 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	giveitem ITEM_ELIXIR
# 43 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 44 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
# 45 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	closemessage
# 46 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 47 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 48 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 49 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1:: @ 82272B2
# 50 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
# 51 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 52 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 53 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 54 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother:: @ 82272BC
# 55 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetLotadSizeRecordInfo
# 56 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lock
# 57 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	faceplayer
# 58 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
# 59 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special ChoosePartyMon
# 60 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	waitstate
# 61 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8004
# 62 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, 255
# 63 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
# 64 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special CompareLotadSize
# 65 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, 1
# 66 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
# 67 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, 2
# 68 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
# 69 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, 3
# 70 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
# 71 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 72 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 73 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 74 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad:: @ 8227303
# 75 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
# 76 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 77 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 78 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 79 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad:: @ 822730D
# 80 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
# 81 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 82 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 83 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 84 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad:: @ 8227317
# 85 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
# 86 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 87 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 88 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 89 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad:: @ 8227321
# 90 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
# 91 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	giveitem ITEM_ELIXIR
# 92 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	compare VAR_RESULT, FALSE
# 93 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	goto_if_eq SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
# 94 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	closemessage
# 95 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 96 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 97 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 98 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2:: @ 8227343
# 99 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
# 100 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	release
# 101 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 102 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 103 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord:: @ 822734D
# 104 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetSeedotSizeRecordInfo
# 105 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lockall
# 106 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
# 107 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	releaseall
# 108 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 109 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 110 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord:: @ 822735B
# 111 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	special GetLotadSizeRecordInfo
# 112 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	lockall
# 113 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
# 114 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	releaseall
# 115 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	end
# 116 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 117 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot: @ 8227369
# 118 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Do you know the Pokémon Seedot?\n"
# 119 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It's hardly ever seen in Sootopolis.\p"
# 120 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Anyway, I love big Seedot.\n"
# 121 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The bigger the better.\p"
# 122 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But my younger brother, he says that\n"
# 123 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "LOTAD is bigger.\p"
# 124 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "That's silly.\n"
# 125 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "SEEDOT has to be bigger than that!\p"
# 126 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Huh? Do you have a Seedot with you?\n"
# 127 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "P-p-please, show me!$"
# 128 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 129 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad: @ 8227480
# 130 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2} inches!\n"
# 131 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Oh, my gosh, this is a big one!\p"
# 132 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It might even beat the big Lotad\n"
# 133 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "my younger brother saw!\p"
# 134 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Thanks for showing me.\n"
# 135 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "This is my thanks!$"
# 136 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 137 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
@ Unused
# 138 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1: @ 822750E
# 139 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{PLAYER} received a Potion.$"
# 140 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 141 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1: @ 8227524
# 142 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh?\n"
# 143 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Your Bag is crammed full.$"
# 144 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 145 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot: @ 8227544
# 146 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2} inches, is it?\p"
# 147 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hmm… I've seen a bigger Seedot\n"
# 148 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "than this one.$"
# 149 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 150 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot: @ 8227584
# 151 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Oh, now this is quite something…\n"
# 152 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But it's not a Seedot!$"
# 153 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 154 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot: @ 82275BC
# 155 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "You don't have a big Seedot?\n"
# 156 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "That's too bad…\p"
# 157 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "If you get a big Seedot, please\n"
# 158 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "come show me.$"
# 159 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 160 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory: @ 8227617
# 161 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The biggest Seedot in history!\n"
# 162 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}'s {STR_VAR_3}-inch giant!\p"
# 163 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "A Seedot bigger than a Lotad\n"
# 164 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "always wanted!$"
# 165 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 166 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad: @ 8227676
# 167 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Do you know the Pokémon Lotad?\n"
# 168 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It's rarely seen in Sootopolis.\p"
# 169 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "I love, I mean love, big Lotad!\p"
# 170 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "My big brother says that Seedot is\n"
# 171 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "bigger.\p"
# 172 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But that's wrong! Everyone knows that\n"
# 173 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Lotad is a lot bigger.\p"
# 174 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh? Do you have a Lotad?\n"
# 175 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "P-p-please show me!$"
# 176 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 177 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot: @ 822776C
# 178 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2} inches!\n"
# 179 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Wow, that is big!\p"
# 180 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "It might be even bigger than the huge\n"
# 181 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Seedot my big brother saw.\p"
# 182 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Thanks for showing me!\n"
# 183 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "This is my thanks!$"
# 184 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 185 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
@ Unused
# 186 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2: @ 82277F4
# 187 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{PLAYER} received a Potion.$"
# 188 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 189 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2: @ 822780A
# 190 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hunh?\n"
# 191 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Your Bag is crammed full.$"
# 192 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 193 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad: @ 822782A
# 194 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2} inches?\p"
# 195 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Hmm… I've seen a bigger Lotad\n"
# 196 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "than this one here.$"
# 197 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 198 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad: @ 8227867
# 199 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Well, isn't this something!\n"
# 200 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "But it's no Lotad!$"
# 201 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 202 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad: @ 8227896
# 203 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "Don't you have a big Lotad?\n"
# 204 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "How disappointing…\p"
# 205 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "If you get a big Lotad, please\n"
# 206 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "come show me!$"
# 207 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"

# 208 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory: @ 82278F2
# 209 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "The biggest Lotad in history!\n"
# 210 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "{STR_VAR_2}'s {STR_VAR_3}-inch colossus!\p"
# 211 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "A Lotad bigger than a Seedot\n"
# 212 "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.pory"
	.string "always wanted!$"
