# 1 "data/maps/Route129/scripts.pory"

# 2 "data/maps/Route129/scripts.pory"
Route129_MapScripts:: @ 81F7284
# 3 "data/maps/Route129/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route129_OnTransition
# 4 "data/maps/Route129/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route129_OnLoad
# 5 "data/maps/Route129/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route129_OnFrame
# 6 "data/maps/Route129/scripts.pory"
	.byte 0
# 7 "data/maps/Route129/scripts.pory"

# 8 "data/maps/Route129/scripts.pory"
Route129_OnLoad: @ 81F7294
# 9 "data/maps/Route129/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_129_WEST
# 10 "data/maps/Route129/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute129West
# 11 "data/maps/Route129/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_129_EAST
# 12 "data/maps/Route129/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute129East
# 13 "data/maps/Route129/scripts.pory"
	end
# 14 "data/maps/Route129/scripts.pory"

# 15 "data/maps/Route129/scripts.pory"
Route129_OnTransition: @ 81F72AB
# 16 "data/maps/Route129/scripts.pory"
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 17 "data/maps/Route129/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
# 18 "data/maps/Route129/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 19 "data/maps/Route129/scripts.pory"
	call_if_ge Route129_EventScript_CheckSetAbnormalWeather
# 20 "data/maps/Route129/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_129_WEST
# 21 "data/maps/Route129/scripts.pory"
	call_if_eq AbnormalWeather_StartKyogreWeather
# 22 "data/maps/Route129/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_129_EAST
# 23 "data/maps/Route129/scripts.pory"
	call_if_eq AbnormalWeather_StartKyogreWeather
# 24 "data/maps/Route129/scripts.pory"
	end
# 25 "data/maps/Route129/scripts.pory"

# 26 "data/maps/Route129/scripts.pory"
Route129_EventScript_CheckSetAbnormalWeather:: @ 81F72D8
# 27 "data/maps/Route129/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 28 "data/maps/Route129/scripts.pory"
	return
# 29 "data/maps/Route129/scripts.pory"

# 30 "data/maps/Route129/scripts.pory"
Route129_OnFrame: @ 81F72E2
# 31 "data/maps/Route129/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 32 "data/maps/Route129/scripts.pory"
	.2byte 0
# 33 "data/maps/Route129/scripts.pory"

# 34 "data/maps/Route129/scripts.pory"
Route129_EventScript_Chase:: @ 81F72EC
# 35 "data/maps/Route129/scripts.pory"
	trainerbattle_single TRAINER_CHASE, Route129_Text_ChaseIntro, Route129_Text_ChaseDefeat
# 36 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_ChasePostBattle, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route129/scripts.pory"
	end
# 38 "data/maps/Route129/scripts.pory"

# 39 "data/maps/Route129/scripts.pory"
Route129_EventScript_Allison:: @ 81F7303
# 40 "data/maps/Route129/scripts.pory"
	trainerbattle_single TRAINER_ALLISON, Route129_Text_AllisonIntro, Route129_Text_AllisonDefeat
# 41 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route129/scripts.pory"
	end
# 43 "data/maps/Route129/scripts.pory"

# 44 "data/maps/Route129/scripts.pory"
Route129_EventScript_Reed:: @ 81F731A
# 45 "data/maps/Route129/scripts.pory"
	trainerbattle_single TRAINER_REED, Route129_Text_ReedIntro, Route129_Text_ReedDefeat
# 46 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_ReedPostBattle, MSGBOX_AUTOCLOSE
# 47 "data/maps/Route129/scripts.pory"
	end
# 48 "data/maps/Route129/scripts.pory"

# 49 "data/maps/Route129/scripts.pory"
Route129_EventScript_Tisha:: @ 81F7331
# 50 "data/maps/Route129/scripts.pory"
	trainerbattle_single TRAINER_TISHA, Route129_Text_TishaIntro, Route129_Text_TishaDefeat
# 51 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_TishaPostBattle, MSGBOX_AUTOCLOSE
# 52 "data/maps/Route129/scripts.pory"
	end
# 53 "data/maps/Route129/scripts.pory"

# 54 "data/maps/Route129/scripts.pory"
Route129_EventScript_Clarence:: @ 81F7348
# 55 "data/maps/Route129/scripts.pory"
	trainerbattle_single TRAINER_CLARENCE, Route129_Text_ClarenceIntro, Route129_Text_ClarenceDefeat
# 56 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_ClarencePostBattle, MSGBOX_AUTOCLOSE
# 57 "data/maps/Route129/scripts.pory"
	end
