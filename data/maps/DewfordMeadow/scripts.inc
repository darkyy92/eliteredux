# 1 "data/maps/DewfordMeadow/scripts.pory"

# 2 "data/maps/DewfordMeadow/scripts.pory"
DewfordMeadow_MapScripts::
# 3 "data/maps/DewfordMeadow/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordMeadow_OnTransition
# 4 "data/maps/DewfordMeadow/scripts.pory"
	.byte 0
# 5 "data/maps/DewfordMeadow/scripts.pory"

# 6 "data/maps/DewfordMeadow/scripts.pory"
DewfordMeadow_OnTransition:
# 7 "data/maps/DewfordMeadow/scripts.pory"
	setflag FLAG_LANDMARK_DEWFORD_MEADOW
# 8 "data/maps/DewfordMeadow/scripts.pory"
	end
# 9 "data/maps/DewfordMeadow/scripts.pory"

# 10 "data/maps/DewfordMeadow/scripts.pory"
DewfordMeadow_EventScript_ManorSign::
# 11 "data/maps/DewfordMeadow/scripts.pory"
	msgbox DewfordMeadow_Text_ManorSign, MSGBOX_SIGN
# 12 "data/maps/DewfordMeadow/scripts.pory"
	end
# 13 "data/maps/DewfordMeadow/scripts.pory"

# 14 "data/maps/DewfordMeadow/scripts.pory"
DewfordMeadow_Text_ManorSign:
# 15 "data/maps/DewfordMeadow/scripts.pory"
	.string "Dewford Manor: Once a Sea Captain's\n"
# 16 "data/maps/DewfordMeadow/scripts.pory"
	.string "escape, now home only to Pokémon.$"
