# 1 "data/maps/SkyPillar_5F/scripts.pory"

# 2 "data/maps/SkyPillar_5F/scripts.pory"
SkyPillar_5F_MapScripts:: @ 82396A2
# 3 "data/maps/SkyPillar_5F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_5F_OnTransition
# 4 "data/maps/SkyPillar_5F/scripts.pory"
	.byte 0
# 5 "data/maps/SkyPillar_5F/scripts.pory"

# 6 "data/maps/SkyPillar_5F/scripts.pory"
SkyPillar_5F_OnTransition: @ 82396A8
# 7 "data/maps/SkyPillar_5F/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 2
# 8 "data/maps/SkyPillar_5F/scripts.pory"
	call_if_lt SkyPillar_5F_EventScript_CleanFloor
# 9 "data/maps/SkyPillar_5F/scripts.pory"
	return
# 10 "data/maps/SkyPillar_5F/scripts.pory"

# 11 "data/maps/SkyPillar_5F/scripts.pory"
SkyPillar_5F_EventScript_CleanFloor:: @ 82396B4
# 12 "data/maps/SkyPillar_5F/scripts.pory"
	setmaplayoutindex LAYOUT_SKY_PILLAR_5F_CLEAN
# 13 "data/maps/SkyPillar_5F/scripts.pory"
	return
