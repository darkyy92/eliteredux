# 1 "data/maps/NavelRock_Exterior/scripts.pory"

# 2 "data/maps/NavelRock_Exterior/scripts.pory"
NavelRock_Exterior_MapScripts:: @ 82690B2
# 3 "data/maps/NavelRock_Exterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Exterior_OnTransition
# 4 "data/maps/NavelRock_Exterior/scripts.pory"
	.byte 0
# 5 "data/maps/NavelRock_Exterior/scripts.pory"

# 6 "data/maps/NavelRock_Exterior/scripts.pory"
NavelRock_Exterior_OnTransition: @ 82690B8
# 7 "data/maps/NavelRock_Exterior/scripts.pory"
	setflag FLAG_ARRIVED_AT_NAVEL_ROCK
# 8 "data/maps/NavelRock_Exterior/scripts.pory"
	end
