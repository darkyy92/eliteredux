# 1 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"

# 2 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
ShoalCave_LowTideStairsRoom_MapScripts:: @ 82370FA
# 3 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideStairsRoom_OnLoad
# 4 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	.byte 0
# 5 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"

# 6 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
ShoalCave_LowTideStairsRoom_OnLoad: @ 8237100
# 7 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	call ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatiles
# 8 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	end
# 9 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"

# 10 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatiles:: @ 8237106
# 11 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_3, ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatilesEnd
# 12 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	setmetatile 11, 11, METATILE_Cave_ShoalCave_DirtPile_Large, 1
# 13 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	return
# 14 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"

# 15 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatilesEnd:: @ 8237119
# 16 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	return
# 17 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"

# 18 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
ShoalCave_LowTideStairsRoom_EventScript_ShoalSalt3:: @ 823711A
# 19 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	lockall
# 20 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_3, ShoalCave_LowTideStairsRoom_EventScript_ReceivedShoalSalt
# 21 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	giveitem ITEM_SHOAL_SALT
# 22 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 23 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 24 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	setmetatile 11, 11, METATILE_Cave_ShoalCave_DirtPile_Small, 0
# 25 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	special DrawWholeMapView
# 26 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SALT_3
# 27 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	releaseall
# 28 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	end
# 29 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"

# 30 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
ShoalCave_LowTideStairsRoom_EventScript_ReceivedShoalSalt:: @ 823714C
# 31 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
# 32 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	releaseall
# 33 "data/maps/ShoalCave_LowTideStairsRoom/scripts.pory"
	end
