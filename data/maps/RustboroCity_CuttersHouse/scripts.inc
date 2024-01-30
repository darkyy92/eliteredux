# 1 "data/maps/RustboroCity_CuttersHouse/scripts.pory"

# 2 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_MapScripts:: @ 8215BD3
# 3 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_CuttersHouse/scripts.pory"

# 5 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_EventScript_Cutter:: @ 8215BD4
# 6 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	lock
# 7 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	faceplayer
# 8 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM01, RustboroCity_CuttersHouse_EventScript_ExplainCut
# 9 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
# 10 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	giveitem ITEM_HM01_CUT
# 11 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	setflag FLAG_RECEIVED_HM01
# 12 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
# 13 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	release
# 14 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	end
# 15 "data/maps/RustboroCity_CuttersHouse/scripts.pory"

# 16 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_EventScript_ExplainCut:: @ 8215C00
# 17 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
# 18 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	release
# 19 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	end
# 20 "data/maps/RustboroCity_CuttersHouse/scripts.pory"

# 21 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_EventScript_Lass:: @ 8215C0A
# 22 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
# 23 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	end
# 24 "data/maps/RustboroCity_CuttersHouse/scripts.pory"

# 25 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse: @ 8215C13
# 26 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "That determined expression…\n"
# 27 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "That limber way you move…\l"
# 28 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "And your well-trained Pokémon…\p"
# 29 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "You're obviously a skilled Trainer!\p"
# 30 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "No, wait, don't say a word.\n"
# 31 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "I can tell just by looking at you.\p"
# 32 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "I'm sure that you can put this\n"
# 33 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "Hidden Machine to good use.\p"
# 34 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "No need to be modest or shy.\n"
# 35 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "Go on, take it!$"
# 36 "data/maps/RustboroCity_CuttersHouse/scripts.pory"

# 37 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_Text_ExplainCut: @ 8215D33
# 38 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "That Hidden Machine, or HM for\n"
# 39 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "short, is Cut.\p"
# 40 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "An HM move is one that can be used\n"
# 41 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "by Pokémon outside of battle.\p"
# 42 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "Any Pokémon that's learned Cut can\n"
# 43 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "chop down thin trees if the Trainer\l"
# 44 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "has earned the Stone Badge.\p"
# 45 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "And, like a TM, an HM can be used\n"
# 46 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "more than once.$"
# 47 "data/maps/RustboroCity_CuttersHouse/scripts.pory"

# 48 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees: @ 8215E39
# 49 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "When they were expanding the city of\n"
# 50 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "Rustboro, my dad helped out.\p"
# 51 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "He made his Pokémon use Cut to clear\n"
# 52 "data/maps/RustboroCity_CuttersHouse/scripts.pory"
	.string "the land of trees.$"
