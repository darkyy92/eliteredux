# 1 "data/maps/SkyPillar_2F/scripts.pory"

# 2 "data/maps/SkyPillar_2F/scripts.pory"
SkyPillar_2F_MapScripts:: @ 823962B
# 3 "data/maps/SkyPillar_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
# 4 "data/maps/SkyPillar_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_2F_OnTransition
# 5 "data/maps/SkyPillar_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_2F_SetHoleWarp
# 6 "data/maps/SkyPillar_2F/scripts.pory"
	.byte 0
# 7 "data/maps/SkyPillar_2F/scripts.pory"

# 8 "data/maps/SkyPillar_2F/scripts.pory"
SkyPillar_2F_OnTransition: @ 823963B
# 9 "data/maps/SkyPillar_2F/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 2
# 10 "data/maps/SkyPillar_2F/scripts.pory"
	call_if_lt SkyPillar_2F_EventScript_CleanFloor
# 11 "data/maps/SkyPillar_2F/scripts.pory"
	copyvar VAR_ICE_STEP_COUNT, 1
# 12 "data/maps/SkyPillar_2F/scripts.pory"
	end
# 13 "data/maps/SkyPillar_2F/scripts.pory"

# 14 "data/maps/SkyPillar_2F/scripts.pory"
SkyPillar_2F_EventScript_CleanFloor:: @ 823964C
# 15 "data/maps/SkyPillar_2F/scripts.pory"
	setmaplayoutindex LAYOUT_SKY_PILLAR_2F_CLEAN
# 16 "data/maps/SkyPillar_2F/scripts.pory"
	return
# 17 "data/maps/SkyPillar_2F/scripts.pory"

# 18 "data/maps/SkyPillar_2F/scripts.pory"
SkyPillar_2F_SetHoleWarp: @ 8239650
# 19 "data/maps/SkyPillar_2F/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 20 "data/maps/SkyPillar_2F/scripts.pory"
	setholewarp MAP_SKY_PILLAR_1F, 255, 0, 0
# 21 "data/maps/SkyPillar_2F/scripts.pory"
	end
