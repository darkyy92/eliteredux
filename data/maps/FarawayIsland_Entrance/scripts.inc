# 1 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 2 "data/maps/FarawayIsland_Entrance/scripts.pory"
.set LOCALID_SAILOR, 1
# 3 "data/maps/FarawayIsland_Entrance/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 4 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 5 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_MapScripts:: @ 8267C8E
# 6 "data/maps/FarawayIsland_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
# 7 "data/maps/FarawayIsland_Entrance/scripts.pory"
	.byte 0
# 8 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 9 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_OnTransition: @ 8267C94
# 10 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
# 11 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 12 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 13 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_SetCloudsWeather:: @ 8267C98
# 14 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 15 "data/maps/FarawayIsland_Entrance/scripts.pory"
	doweather
# 16 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 17 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 18 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_ClearWeather:: @ 8267C9D
# 19 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setweather WEATHER_NONE
# 20 "data/maps/FarawayIsland_Entrance/scripts.pory"
	doweather
# 21 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 22 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 23 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_Sailor:: @ 8267CA2
# 24 "data/maps/FarawayIsland_Entrance/scripts.pory"
	lock
# 25 "data/maps/FarawayIsland_Entrance/scripts.pory"
	faceplayer
# 26 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
# 27 "data/maps/FarawayIsland_Entrance/scripts.pory"
	compare VAR_RESULT, NO
# 28 "data/maps/FarawayIsland_Entrance/scripts.pory"
	goto_if_eq FarawayIsland_Entrance_EventScript_AsYouLike
# 29 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
# 30 "data/maps/FarawayIsland_Entrance/scripts.pory"
	closemessage
# 31 "data/maps/FarawayIsland_Entrance/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 32 "data/maps/FarawayIsland_Entrance/scripts.pory"
	waitmovement 0
# 33 "data/maps/FarawayIsland_Entrance/scripts.pory"
	delay 30
# 34 "data/maps/FarawayIsland_Entrance/scripts.pory"
	hideobjectat LOCALID_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
# 35 "data/maps/FarawayIsland_Entrance/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 36 "data/maps/FarawayIsland_Entrance/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 37 "data/maps/FarawayIsland_Entrance/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
# 38 "data/maps/FarawayIsland_Entrance/scripts.pory"
	waitstate
# 39 "data/maps/FarawayIsland_Entrance/scripts.pory"
	release
# 40 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 41 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 42 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_AsYouLike:: @ 8267CE7
# 43 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 44 "data/maps/FarawayIsland_Entrance/scripts.pory"
	release
# 45 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
# 46 "data/maps/FarawayIsland_Entrance/scripts.pory"

# 47 "data/maps/FarawayIsland_Entrance/scripts.pory"
FarawayIsland_Entrance_EventScript_Sign:: @ 8267CF1
# 48 "data/maps/FarawayIsland_Entrance/scripts.pory"
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
# 49 "data/maps/FarawayIsland_Entrance/scripts.pory"
	end
