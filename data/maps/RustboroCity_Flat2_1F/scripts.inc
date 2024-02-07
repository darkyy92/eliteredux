# 1 "data/maps/RustboroCity_Flat2_1F/scripts.pory"

# 2 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
RustboroCity_Flat2_1F_MapScripts:: @ 8215F76
# 3 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Flat2_1F/scripts.pory"

# 5 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
RustboroCity_Flat2_1F_EventScript_OldWoman:: @ 8215F77
# 6 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
# 7 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	end
# 8 "data/maps/RustboroCity_Flat2_1F/scripts.pory"

# 9 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
RustboroCity_Flat2_1F_EventScript_Skitty:: @ 8215F80
# 10 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	lock
# 11 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	faceplayer
# 12 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	waitse
# 13 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	playmoncry SPECIES_SKITTY, 0
# 14 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
# 15 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	waitmoncry
# 16 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	release
# 17 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	end
# 18 "data/maps/RustboroCity_Flat2_1F/scripts.pory"

# 19 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere: @ 8215F93
# 20 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	.string "Devon Corporation's workers live in\n"
# 21 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	.string "this building.$"
# 22 "data/maps/RustboroCity_Flat2_1F/scripts.pory"

# 23 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
RustboroCity_Flat2_1F_Text_Skitty: @ 8215FC6
# 24 "data/maps/RustboroCity_Flat2_1F/scripts.pory"
	.string "Skitty: Gyaaaah!$"
