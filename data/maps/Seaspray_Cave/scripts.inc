# 1 "data/maps/Seaspray_Cave/scripts.pory"

# 2 "data/maps/Seaspray_Cave/scripts.pory"
Seaspray_Cave_MapScripts:: 
# 3 "data/maps/Seaspray_Cave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Seaspray_Cave_OnTransition
# 4 "data/maps/Seaspray_Cave/scripts.pory"
	.byte 0
# 5 "data/maps/Seaspray_Cave/scripts.pory"

# 6 "data/maps/Seaspray_Cave/scripts.pory"
Seaspray_Cave_OnTransition::
# 7 "data/maps/Seaspray_Cave/scripts.pory"
	setflag FLAG_LANDMARK_SEASPRAY_CAVE
# 8 "data/maps/Seaspray_Cave/scripts.pory"
	end
