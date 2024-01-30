# 1 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 2 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_MapScripts:: @ 826EA77
# 3 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.byte 0
# 4 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 5 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_Clerk:: @ 826EA78
# 6 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	lock
# 7 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	faceplayer
# 8 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
# 9 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	release
# 10 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 11 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 12 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_BikeCheck:: @ 826EA84
# 13 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	lockall
# 14 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	specialvar VAR_RESULT, GetPlayerAvatarBike
# 15 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	compare VAR_RESULT, 0
# 16 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	goto_if_eq Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike
# 17 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setflag FLAG_SYS_CYCLING_ROAD
# 18 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setvar VAR_TEMP_1, 1
# 19 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	releaseall
# 20 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 21 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 22 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike:: @ 826EA9F
# 23 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
# 24 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	closemessage
# 25 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter
# 26 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	waitmovement 0
# 27 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	releaseall
# 28 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 29 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 30 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter: @ 826EAB4
# 31 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	walk_left
# 32 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	step_end
# 33 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 34 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_EventScript_ClearCyclingRoad:: @ 826EAB6
# 35 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	lockall
# 36 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	clearflag FLAG_SYS_CYCLING_ROAD
# 37 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	setvar VAR_TEMP_1, 0
# 38 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	releaseall
# 39 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	end
# 40 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 41 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad: @ 826EAC1
# 42 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "On Cycling Road, you can go all out\n"
# 43 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "and cycle as fast as you'd like.\p"
# 44 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "It feels great to go that fast, but try\n"
# 45 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "not to crash into anyone!$"
# 46 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"

# 47 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk: @ 826EB48
# 48 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "Sorry, you can't walk on Cycling\n"
# 49 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "Road. It's too dangerous.\p"
# 50 "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.pory"
	.string "Please come back with a Bike.$"
