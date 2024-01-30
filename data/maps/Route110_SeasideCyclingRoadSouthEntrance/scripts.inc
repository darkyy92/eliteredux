# 1 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 2 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_MapScripts:: @ 826EBA1
# 3 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_SeasideCyclingRoadSouthEntrance_OnTransition
# 4 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	.byte 0
# 5 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 6 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_OnTransition: @ 826EBA7
# 7 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	compare VAR_CYCLING_CHALLENGE_STATE, 3
# 8 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	call_if_eq Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
# 9 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	compare VAR_CYCLING_CHALLENGE_STATE, 2
# 10 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	call_if_eq Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
# 11 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	end
# 12 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 13 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge:: @ 826EBBE
# 14 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
# 15 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	return
# 16 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 17 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_EventScript_Clerk:: @ 826EBC4
# 18 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	lock
# 19 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	faceplayer
# 20 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
# 21 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	release
# 22 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	end
# 23 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 24 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_EventScript_BikeCheck:: @ 826EBD0
# 25 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	lockall
# 26 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	specialvar VAR_RESULT, GetPlayerAvatarBike
# 27 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	compare VAR_RESULT, 2
# 28 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	call_if_eq Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike
# 29 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	compare VAR_RESULT, 0
# 30 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	goto_if_eq Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike
# 31 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	setflag FLAG_SYS_CYCLING_ROAD
# 32 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	setvar VAR_TEMP_1, 1
# 33 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	releaseall
# 34 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	end
# 35 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 36 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike:: @ 826EBF6
# 37 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
# 38 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	return
# 39 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 40 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike:: @ 826EBFC
# 41 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
# 42 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	closemessage
# 43 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter
# 44 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	waitmovement 0
# 45 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	releaseall
# 46 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	end
# 47 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 48 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter: @ 826EC11
# 49 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	walk_left
# 50 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	step_end
# 51 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 52 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_EventScript_ClearCyclingRoad:: @ 826EC13
# 53 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	lockall
# 54 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 0
# 55 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	clearflag FLAG_SYS_CYCLING_ROAD
# 56 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	setvar VAR_TEMP_1, 0
# 57 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	releaseall
# 58 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	end
# 59 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 60 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad: @ 826EC23
# 61 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	.string "On Cycling Road, you can go all out\n"
# 62 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	.string "and cycle as fast as you'd like.\p"
# 63 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	.string "It feels great to go that fast, but try\n"
# 64 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	.string "not to crash into anyone!$"
# 65 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"

# 66 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk: @ 826ECAA
# 67 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	.string "Sorry, you can't walk on Cycling\n"
# 68 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	.string "Road. It's too dangerous.\p"
# 69 "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.pory"
	.string "Please come back with a Bike.$"
