# 1 "data/maps/ArtisanCave_B1F/scripts.pory"

# 2 "data/maps/ArtisanCave_B1F/scripts.pory"
ArtisanCave_B1F_MapScripts:: @ 823AFAD
# 3 "data/maps/ArtisanCave_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
# 4 "data/maps/ArtisanCave_B1F/scripts.pory"
	.byte 0
# 5 "data/maps/ArtisanCave_B1F/scripts.pory"

# 6 "data/maps/ArtisanCave_B1F/scripts.pory"
ArtisanCave_B1F_OnTransition: @ 823AFB3
# 7 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_LANDMARK_ARTISAN_CAVE
# 8 "data/maps/ArtisanCave_B1F/scripts.pory"
	end
