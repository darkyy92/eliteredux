# 1 "data/maps/SkyPillar_3F/scripts.pory"

# 2 "data/maps/SkyPillar_3F/scripts.pory"
SkyPillar_3F_MapScripts:: @ 823965B
# 3 "data/maps/SkyPillar_3F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_3F_OnTransition
# 4 "data/maps/SkyPillar_3F/scripts.pory"
	.byte 0
# 5 "data/maps/SkyPillar_3F/scripts.pory"

# 6 "data/maps/SkyPillar_3F/scripts.pory"
SkyPillar_3F_OnTransition: @ 8239661
# 7 "data/maps/SkyPillar_3F/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 2
# 8 "data/maps/SkyPillar_3F/scripts.pory"
	call_if_lt SkyPillar_3F_EventScript_CleanFloor
# 9 "data/maps/SkyPillar_3F/scripts.pory"
	end
# 10 "data/maps/SkyPillar_3F/scripts.pory"

# 11 "data/maps/SkyPillar_3F/scripts.pory"
SkyPillar_3F_EventScript_CleanFloor:: @ 823966D
# 12 "data/maps/SkyPillar_3F/scripts.pory"
	setmaplayoutindex LAYOUT_SKY_PILLAR_3F_CLEAN
# 13 "data/maps/SkyPillar_3F/scripts.pory"
	return
