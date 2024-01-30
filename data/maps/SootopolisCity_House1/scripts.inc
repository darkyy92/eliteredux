# 1 "data/maps/SootopolisCity_House1/scripts.pory"

# 2 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_MapScripts:: @ 822694C
# 3 "data/maps/SootopolisCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_House1/scripts.pory"

# 5 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_EventScript_BrickBreakBlackBelt:: @ 822694D
# 6 "data/maps/SootopolisCity_House1/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_House1/scripts.pory"
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
# 9 "data/maps/SootopolisCity_House1/scripts.pory"
	release
# 10 "data/maps/SootopolisCity_House1/scripts.pory"
	end
# 11 "data/maps/SootopolisCity_House1/scripts.pory"

# 12 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_EventScript_ReceivedBrickBreak:: @ 8226984
# 13 "data/maps/SootopolisCity_House1/scripts.pory"
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
# 14 "data/maps/SootopolisCity_House1/scripts.pory"
	release
# 15 "data/maps/SootopolisCity_House1/scripts.pory"
	end
# 16 "data/maps/SootopolisCity_House1/scripts.pory"

# 17 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_EventScript_Kecleon:: @ 822698E
# 18 "data/maps/SootopolisCity_House1/scripts.pory"
	lock
# 19 "data/maps/SootopolisCity_House1/scripts.pory"
	faceplayer
# 20 "data/maps/SootopolisCity_House1/scripts.pory"
	waitse
# 21 "data/maps/SootopolisCity_House1/scripts.pory"
	playmoncry SPECIES_KECLEON, 0
# 22 "data/maps/SootopolisCity_House1/scripts.pory"
	msgbox SootopolisCity_House1_Text_Kecleon, MSGBOX_DEFAULT
# 23 "data/maps/SootopolisCity_House1/scripts.pory"
	waitmoncry
# 24 "data/maps/SootopolisCity_House1/scripts.pory"
	release
# 25 "data/maps/SootopolisCity_House1/scripts.pory"
	end
# 26 "data/maps/SootopolisCity_House1/scripts.pory"

# 27 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_Text_DevelopedThisTM: @ 82269A1
# 28 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "For thirty years I've remained in\n"
# 29 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "Sootopolis honing my skills.\p"
# 30 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "I developed a sword-dancing TM.\n"
# 31 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "I bequeath it to you!$"
# 32 "data/maps/SootopolisCity_House1/scripts.pory"

# 33 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_Text_ExplainBrickBreak: @ 8226A13
# 34 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "My Pokémon love Swords Dance! It's a move\n"
# 35 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "so horrible that I can't describe it.$"
# 36 "data/maps/SootopolisCity_House1/scripts.pory"

# 37 "data/maps/SootopolisCity_House1/scripts.pory"
SootopolisCity_House1_Text_Kecleon: @ 8226A60
# 38 "data/maps/SootopolisCity_House1/scripts.pory"
	.string "Kecleon: Puu puhyaah.$"
