# 1 "data/maps/LavaridgeTown_House/scripts.pory"

# 2 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_MapScripts::
# 3 "data/maps/LavaridgeTown_House/scripts.pory"
	.byte 0
# 4 "data/maps/LavaridgeTown_House/scripts.pory"

# 5 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_EventScript_OldMan:: @ 81FF912
# 6 "data/maps/LavaridgeTown_House/scripts.pory"
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
# 7 "data/maps/LavaridgeTown_House/scripts.pory"
	end
# 8 "data/maps/LavaridgeTown_House/scripts.pory"

# 9 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_EventScript_Zigzagoon:: @ 81FF91B
# 10 "data/maps/LavaridgeTown_House/scripts.pory"
	lock
# 11 "data/maps/LavaridgeTown_House/scripts.pory"
	faceplayer
# 12 "data/maps/LavaridgeTown_House/scripts.pory"
	waitse
# 13 "data/maps/LavaridgeTown_House/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 14 "data/maps/LavaridgeTown_House/scripts.pory"
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
# 15 "data/maps/LavaridgeTown_House/scripts.pory"
	waitmoncry
# 16 "data/maps/LavaridgeTown_House/scripts.pory"
	release
# 17 "data/maps/LavaridgeTown_House/scripts.pory"
	end
# 18 "data/maps/LavaridgeTown_House/scripts.pory"

# 19 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_EventScript_SuckerPunchTM::
# 20 "data/maps/LavaridgeTown_House/scripts.pory"
	lock
# 21 "data/maps/LavaridgeTown_House/scripts.pory"
	faceplayer
# 22 "data/maps/LavaridgeTown_House/scripts.pory"
	msgbox LavaridgeTown_House_Text_HaveTM94, MSGBOX_DEFAULT
# 23 "data/maps/LavaridgeTown_House/scripts.pory"
	release
# 24 "data/maps/LavaridgeTown_House/scripts.pory"
	end
# 25 "data/maps/LavaridgeTown_House/scripts.pory"

# 26 "data/maps/LavaridgeTown_House/scripts.pory"
MoveTutor_EventScript_MimicDeclined::
# 27 "data/maps/LavaridgeTown_House/scripts.pory"
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
# 28 "data/maps/LavaridgeTown_House/scripts.pory"
	release
# 29 "data/maps/LavaridgeTown_House/scripts.pory"
	end
# 30 "data/maps/LavaridgeTown_House/scripts.pory"

# 31 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_EventScript_ReceivedTM94::
# 32 "data/maps/LavaridgeTown_House/scripts.pory"
	msgbox LavaridgeTown_House_Text_HaveTM94, MSGBOX_DEFAULT
# 33 "data/maps/LavaridgeTown_House/scripts.pory"
	release
# 34 "data/maps/LavaridgeTown_House/scripts.pory"
	end
# 35 "data/maps/LavaridgeTown_House/scripts.pory"

# 36 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_Text_HaveTM94::
# 37 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "My favorite Dark move is Sucker Punch.\p"
# 38 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "It's a move that may go first if the\n"
# 39 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "target Pokémon is about to attack.$"
# 40 "data/maps/LavaridgeTown_House/scripts.pory"

# 41 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_Text_GiveTM94::
# 42 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "Too bad!\p"
# 43 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "You can have this TM instead.$"
# 44 "data/maps/LavaridgeTown_House/scripts.pory"

# 45 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
# 46 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "My wife's warming an Egg in the hot\n"
# 47 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "springs. This is what she told me.\p"
# 48 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "She left two Pokémon with the Day Care.\n"
# 49 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "And they discovered that Egg!$"
# 50 "data/maps/LavaridgeTown_House/scripts.pory"

# 51 "data/maps/LavaridgeTown_House/scripts.pory"
LavaridgeTown_House_Text_Zigzagoon: @ 81FF9BB
# 52 "data/maps/LavaridgeTown_House/scripts.pory"
	.string "Zigzagoon: Pshoo!$"
