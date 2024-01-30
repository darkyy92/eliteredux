# 1 "data/maps/BirthIsland_Harbor/scripts.pory"

# 2 "data/maps/BirthIsland_Harbor/scripts.pory"
.set LOCALID_SAILOR, 1
# 3 "data/maps/BirthIsland_Harbor/scripts.pory"
.set LOCALID_SS_TIDAL, 2
# 4 "data/maps/BirthIsland_Harbor/scripts.pory"

# 5 "data/maps/BirthIsland_Harbor/scripts.pory"
BirthIsland_Harbor_MapScripts:: @ 826805C
# 6 "data/maps/BirthIsland_Harbor/scripts.pory"
	.byte 0
# 7 "data/maps/BirthIsland_Harbor/scripts.pory"

# 8 "data/maps/BirthIsland_Harbor/scripts.pory"
BirthIsland_Harbor_EventScript_Sailor:: @ 826805D
# 9 "data/maps/BirthIsland_Harbor/scripts.pory"
	lock
# 10 "data/maps/BirthIsland_Harbor/scripts.pory"
	faceplayer
# 11 "data/maps/BirthIsland_Harbor/scripts.pory"
	msgbox BirthIsland_Harbor_Text_SailorReturn, MSGBOX_YESNO
# 12 "data/maps/BirthIsland_Harbor/scripts.pory"
	compare VAR_RESULT, NO
# 13 "data/maps/BirthIsland_Harbor/scripts.pory"
	goto_if_eq BirthIsland_Harbor_EventScript_AsYouLike
# 14 "data/maps/BirthIsland_Harbor/scripts.pory"
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
# 15 "data/maps/BirthIsland_Harbor/scripts.pory"
	closemessage
# 16 "data/maps/BirthIsland_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 17 "data/maps/BirthIsland_Harbor/scripts.pory"
	waitmovement 0
# 18 "data/maps/BirthIsland_Harbor/scripts.pory"
	delay 30
# 19 "data/maps/BirthIsland_Harbor/scripts.pory"
	hideobjectat LOCALID_SAILOR, MAP_BIRTH_ISLAND_HARBOR
# 20 "data/maps/BirthIsland_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 21 "data/maps/BirthIsland_Harbor/scripts.pory"
	call Common_EventScript_FerryDepartIsland
# 22 "data/maps/BirthIsland_Harbor/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
# 23 "data/maps/BirthIsland_Harbor/scripts.pory"
	waitstate
# 24 "data/maps/BirthIsland_Harbor/scripts.pory"
	release
# 25 "data/maps/BirthIsland_Harbor/scripts.pory"
	end
# 26 "data/maps/BirthIsland_Harbor/scripts.pory"

# 27 "data/maps/BirthIsland_Harbor/scripts.pory"
BirthIsland_Harbor_EventScript_AsYouLike:: @ 82680A2
# 28 "data/maps/BirthIsland_Harbor/scripts.pory"
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
# 29 "data/maps/BirthIsland_Harbor/scripts.pory"
	release
# 30 "data/maps/BirthIsland_Harbor/scripts.pory"
	end
