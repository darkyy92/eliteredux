# 1 "data/maps/DewfordTown_House1/scripts.pory"

# 2 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_MapScripts:: @ 81FC3CD
# 3 "data/maps/DewfordTown_House1/scripts.pory"
	.byte 0
# 4 "data/maps/DewfordTown_House1/scripts.pory"

# 5 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_EventScript_Man:: @ 81FC3CE
# 6 "data/maps/DewfordTown_House1/scripts.pory"
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
# 7 "data/maps/DewfordTown_House1/scripts.pory"
	end
# 8 "data/maps/DewfordTown_House1/scripts.pory"

# 9 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_EventScript_Woman:: @ 81FC3D7
# 10 "data/maps/DewfordTown_House1/scripts.pory"
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
# 11 "data/maps/DewfordTown_House1/scripts.pory"
	end
# 12 "data/maps/DewfordTown_House1/scripts.pory"

# 13 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_EventScript_Zigzagoon:: @ 81FC3E0
# 14 "data/maps/DewfordTown_House1/scripts.pory"
	lock
# 15 "data/maps/DewfordTown_House1/scripts.pory"
	faceplayer
# 16 "data/maps/DewfordTown_House1/scripts.pory"
	waitse
# 17 "data/maps/DewfordTown_House1/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 18 "data/maps/DewfordTown_House1/scripts.pory"
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
# 19 "data/maps/DewfordTown_House1/scripts.pory"
	waitmoncry
# 20 "data/maps/DewfordTown_House1/scripts.pory"
	release
# 21 "data/maps/DewfordTown_House1/scripts.pory"
	end
# 22 "data/maps/DewfordTown_House1/scripts.pory"

# 23 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland: @ 81FC3F3
# 24 "data/maps/DewfordTown_House1/scripts.pory"
	.string "There's a lot to be said for living on\n"
# 25 "data/maps/DewfordTown_House1/scripts.pory"
	.string "a small island like this in harmony with\l"
# 26 "data/maps/DewfordTown_House1/scripts.pory"
	.string "Pokémon and the family.$"
# 27 "data/maps/DewfordTown_House1/scripts.pory"

# 28 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_Text_LifeGoesSlowlyOnIsland: @ 81FC45B
# 29 "data/maps/DewfordTown_House1/scripts.pory"
	.string "I left the major port of Slateport\n"
# 30 "data/maps/DewfordTown_House1/scripts.pory"
	.string "City when I married my husband here.\p"
# 31 "data/maps/DewfordTown_House1/scripts.pory"
	.string "Life goes by slowly on this little\n"
# 32 "data/maps/DewfordTown_House1/scripts.pory"
	.string "island. But being surrounded by the\l"
# 33 "data/maps/DewfordTown_House1/scripts.pory"
	.string "beautiful sea--that's happiness, too.$"
# 34 "data/maps/DewfordTown_House1/scripts.pory"

# 35 "data/maps/DewfordTown_House1/scripts.pory"
DewfordTown_House1_Text_Zigzagoon: @ 81FC510
# 36 "data/maps/DewfordTown_House1/scripts.pory"
	.string "Zigzagoon: Guguuh!$"
