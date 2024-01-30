# 1 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 2 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_MapScripts:: @ 823433B
# 3 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Underwater_SeafloorCavern_OnResume
# 4 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_SeafloorCavern_OnTransition
# 5 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Underwater_SeafloorCavern_OnLoad
# 6 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.byte 0
# 7 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 8 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_OnTransition: @ 823434B
# 9 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setflag FLAG_LANDMARK_SEAFLOOR_CAVERN
# 10 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_EventScript_HideSubmarine
# 11 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 12 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 13 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_EventScript_HideSubmarine:: @ 8234358
# 14 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setflag FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE
# 15 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 16 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 17 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_OnLoad: @ 823435C
# 18 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	call_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_EventScript_SetSubmarineGoneMetatiles
# 19 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 20 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 21 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_EventScript_SetSubmarineGoneMetatiles:: @ 8234366
# 22 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 5, 3, METATILE_Underwater_RockWall, 1
# 23 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 6, 3, METATILE_Underwater_RockWall, 1
# 24 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 7, 3, METATILE_Underwater_RockWall, 1
# 25 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 8, 3, METATILE_Underwater_RockWall, 1
# 26 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 5, 4, METATILE_Underwater_FloorShadow, 0
# 27 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 6, 4, METATILE_Underwater_FloorShadow, 0
# 28 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 7, 4, METATILE_Underwater_FloorShadow, 0
# 29 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 8, 4, METATILE_Underwater_FloorShadow, 0
# 30 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 5, 5, METATILE_Underwater_FloorShadow, 0
# 31 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 6, 5, METATILE_Underwater_FloorShadow, 0
# 32 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 7, 5, METATILE_Underwater_FloorShadow, 0
# 33 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setmetatile 8, 5, METATILE_Underwater_FloorShadow, 0
# 34 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	return
# 35 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 36 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_OnResume: @ 82343D3
# 37 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	setdivewarp MAP_SEAFLOOR_CAVERN_ENTRANCE, 255, 10, 17
# 38 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 39 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 40 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_EventScript_CheckStolenSub:: @ 82343DC
# 41 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	msgbox Underwater_SeafloorCavern_Text_SubExplorer1, MSGBOX_SIGN
# 42 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	end
# 43 "data/maps/Underwater_SeafloorCavern/scripts.pory"

# 44 "data/maps/Underwater_SeafloorCavern/scripts.pory"
Underwater_SeafloorCavern_Text_SubExplorer1: @ 82343E5
# 45 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "“Submarine Explorer 1” is painted\n"
# 46 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "on the hull.\p"
# 47 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "This is the submarine Team Aqua\n"
# 48 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "stole in Slateport!\p"
# 49 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "Team Aqua must have gone\n"
# 50 "data/maps/Underwater_SeafloorCavern/scripts.pory"
	.string "ashore here.$"
