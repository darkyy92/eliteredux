# 1 "data/maps/LilycoveCity_House3/scripts.pory"

# 2 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_MapScripts:: @ 821EE3C
# 3 "data/maps/LilycoveCity_House3/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
# 4 "data/maps/LilycoveCity_House3/scripts.pory"
	.byte 0
# 5 "data/maps/LilycoveCity_House3/scripts.pory"

# 6 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_OnTransition: @ 821EE42
# 7 "data/maps/LilycoveCity_House3/scripts.pory"
	random 4
# 8 "data/maps/LilycoveCity_House3/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 9 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 10 "data/maps/LilycoveCity_House3/scripts.pory"

# 11 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_PokefanF:: @ 821EE4B
# 12 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 13 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 14 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
# 15 "data/maps/LilycoveCity_House3/scripts.pory"
	compare VAR_RESULT, NO
# 16 "data/maps/LilycoveCity_House3/scripts.pory"
	goto_if_eq LilycoveCity_House3_EventScript_DeclinePokeblockLearn
# 17 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
# 18 "data/maps/LilycoveCity_House3/scripts.pory"
	closemessage
# 19 "data/maps/LilycoveCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 20 "data/maps/LilycoveCity_House3/scripts.pory"
	waitmovement 0
# 21 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 22 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 23 "data/maps/LilycoveCity_House3/scripts.pory"

# 24 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_DeclinePokeblockLearn:: @ 821EE75
# 25 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
# 26 "data/maps/LilycoveCity_House3/scripts.pory"
	closemessage
# 27 "data/maps/LilycoveCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 28 "data/maps/LilycoveCity_House3/scripts.pory"
	waitmovement 0
# 29 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 30 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 31 "data/maps/LilycoveCity_House3/scripts.pory"

# 32 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_Man:: @ 821EE8A
# 33 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 34 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 35 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
# 36 "data/maps/LilycoveCity_House3/scripts.pory"
	closemessage
# 37 "data/maps/LilycoveCity_House3/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 38 "data/maps/LilycoveCity_House3/scripts.pory"
	waitmovement 0
# 39 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 40 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 41 "data/maps/LilycoveCity_House3/scripts.pory"

# 42 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_GameBoyKid1:: @ 821EEA1
# 43 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 44 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 45 "data/maps/LilycoveCity_House3/scripts.pory"
	switch VAR_TEMP_1
# 46 "data/maps/LilycoveCity_House3/scripts.pory"
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
# 47 "data/maps/LilycoveCity_House3/scripts.pory"
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
# 48 "data/maps/LilycoveCity_House3/scripts.pory"
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
# 49 "data/maps/LilycoveCity_House3/scripts.pory"
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
# 50 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 51 "data/maps/LilycoveCity_House3/scripts.pory"

# 52 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_GameBoyKid2:: @ 821EED5
# 53 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 54 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 55 "data/maps/LilycoveCity_House3/scripts.pory"
	switch VAR_TEMP_1
# 56 "data/maps/LilycoveCity_House3/scripts.pory"
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
# 57 "data/maps/LilycoveCity_House3/scripts.pory"
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
# 58 "data/maps/LilycoveCity_House3/scripts.pory"
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
# 59 "data/maps/LilycoveCity_House3/scripts.pory"
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
# 60 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 61 "data/maps/LilycoveCity_House3/scripts.pory"

# 62 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_GameBoyKid3:: @ 821EF09
# 63 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 64 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 65 "data/maps/LilycoveCity_House3/scripts.pory"
	switch VAR_TEMP_1
# 66 "data/maps/LilycoveCity_House3/scripts.pory"
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
# 67 "data/maps/LilycoveCity_House3/scripts.pory"
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
# 68 "data/maps/LilycoveCity_House3/scripts.pory"
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
# 69 "data/maps/LilycoveCity_House3/scripts.pory"
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
# 70 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 71 "data/maps/LilycoveCity_House3/scripts.pory"

# 72 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_GameBoyKid4:: @ 821EF3D
# 73 "data/maps/LilycoveCity_House3/scripts.pory"
	lock
# 74 "data/maps/LilycoveCity_House3/scripts.pory"
	faceplayer
# 75 "data/maps/LilycoveCity_House3/scripts.pory"
	switch VAR_TEMP_1
# 76 "data/maps/LilycoveCity_House3/scripts.pory"
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
# 77 "data/maps/LilycoveCity_House3/scripts.pory"
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
# 78 "data/maps/LilycoveCity_House3/scripts.pory"
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
# 79 "data/maps/LilycoveCity_House3/scripts.pory"
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
# 80 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 81 "data/maps/LilycoveCity_House3/scripts.pory"

# 82 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_WereDoingMultiBattle:: @ 821EF71
# 83 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
# 84 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 85 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 86 "data/maps/LilycoveCity_House3/scripts.pory"

# 87 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_WereMixingRecords:: @ 821EF7B
# 88 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
# 89 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 90 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 91 "data/maps/LilycoveCity_House3/scripts.pory"

# 92 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_WereBlendingBerries:: @ 821EF85
# 93 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
# 94 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 95 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 96 "data/maps/LilycoveCity_House3/scripts.pory"

# 97 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_EventScript_WereDoingContest:: @ 821EF8F
# 98 "data/maps/LilycoveCity_House3/scripts.pory"
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
# 99 "data/maps/LilycoveCity_House3/scripts.pory"
	release
# 100 "data/maps/LilycoveCity_House3/scripts.pory"
	end
# 101 "data/maps/LilycoveCity_House3/scripts.pory"

# 102 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks: @ 821EF99
# 103 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Oh, my, my! Are you traveling alone?\n"
# 104 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "But you're so young! Good for you!\p"
# 105 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "I'm sure my kids could learn a thing\n"
# 106 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "or two from you!\p"
# 107 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Me? I'm a master of {POKEBLOCK}S.\p"
# 108 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "If I get serious just a little, why,\n"
# 109 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "I can concoct great {POKEBLOCK}S.\p"
# 110 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Would you like to learn from me,\n"
# 111 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "a master of {POKEBLOCK}S?$"
# 112 "data/maps/LilycoveCity_House3/scripts.pory"

# 113 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_OhAreYouSure: @ 821F0A9
# 114 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Oh? Are you sure?\p"
# 115 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "You shouldn't always try to do\n"
# 116 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "everything by yourself, dear!$"
# 117 "data/maps/LilycoveCity_House3/scripts.pory"

# 118 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_ExplainPokeblocks: @ 821F0F8
# 119 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Oh, good! You're a smart soul!\n"
# 120 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "This is a bit long, so listen up!\p"
# 121 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Are you ready?\p"
# 122 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "If you look at {POKEBLOCK}S, you should see\n"
# 123 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "that they are rated on how they feel.\p"
# 124 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "The lower the feel rating,\n"
# 125 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "the better it is. Don't forget this!\p"
# 126 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "A good {POKEBLOCK} has a low feel\n"
# 127 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "rating and a high level.\p"
# 128 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "A Pokémon can eat more good\n"
# 129 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "{POKEBLOCK}S than ordinary ones, too.\p"
# 130 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "And this is important.\p"
# 131 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "If you want to make smooth {POKEBLOCK}S,\n"
# 132 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "use different kinds of Berries.\p"
# 133 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Don't be stingy--the kinds of Berries\n"
# 134 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "affect the smoothness of {POKEBLOCK}S.\p"
# 135 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "And another thing.\p"
# 136 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "The more people blending Berries,\n"
# 137 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "the smoother the {POKEBLOCK}S.\p"
# 138 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "That's why you should talk to other\n"
# 139 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "people and make {POKEBLOCK}S together.\p"
# 140 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "That's about all you need to know to\n"
# 141 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "make good {POKEBLOCK}S.\p"
# 142 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "If everyone had Pokémon they love,\n"
# 143 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "smooth {POKEBLOCK}S, and a loving family,\l"
# 144 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "the world would be a happier place.\p"
# 145 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Don't give up, dear!$"
# 146 "data/maps/LilycoveCity_House3/scripts.pory"

# 147 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_HappyToHaveQuadruplets: @ 821F430
# 148 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "When my wife gave birth to quadruplets,\n"
# 149 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "you bet I was shocked.\p"
# 150 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "But, now, seeing them play together,\n"
# 151 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "it makes me happy.$"
# 152 "data/maps/LilycoveCity_House3/scripts.pory"

# 153 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_GoingToWinMultiBattles: @ 821F4A7
# 154 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "We're having Multi Battles, but I know\n"
# 155 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "I'm going to win.$"
# 156 "data/maps/LilycoveCity_House3/scripts.pory"

# 157 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_LikeMixingAtRecordCorner: @ 821F4E0
# 158 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "We like mixing stuff at\n"
# 159 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "the Record Corner.\p"
# 160 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "But what gets mixed up?$"
# 161 "data/maps/LilycoveCity_House3/scripts.pory"

# 162 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender: @ 821F523
# 163 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "We're going to make super {POKEBLOCK}S\n"
# 164 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "with a Berry Blender!$"
# 165 "data/maps/LilycoveCity_House3/scripts.pory"

# 166 "data/maps/LilycoveCity_House3/scripts.pory"
LilycoveCity_House3_Text_GoingToEnterContest: @ 821F55A
# 167 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "I want to brag about how tough my\n"
# 168 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "Pokémon is, so we're going to enter\l"
# 169 "data/maps/LilycoveCity_House3/scripts.pory"
	.string "a Contest together.$"
