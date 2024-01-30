# 1 "data/maps/Route124/scripts.pory"

# 2 "data/maps/Route124/scripts.pory"
Route124_MapScripts:: @ 81F656C
# 3 "data/maps/Route124/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
# 4 "data/maps/Route124/scripts.pory"
	.byte 0
# 5 "data/maps/Route124/scripts.pory"

# 6 "data/maps/Route124/scripts.pory"
Route124_OnTransition: @ 81F6572
# 7 "data/maps/Route124/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 8 "data/maps/Route124/scripts.pory"
	end
# 9 "data/maps/Route124/scripts.pory"

# 10 "data/maps/Route124/scripts.pory"
Route124_EventScript_HuntersHouseSign:: @ 81F657C
# 11 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
# 12 "data/maps/Route124/scripts.pory"
	end
# 13 "data/maps/Route124/scripts.pory"

# 14 "data/maps/Route124/scripts.pory"
Route124_EventScript_Spencer:: @ 81F6585
# 15 "data/maps/Route124/scripts.pory"
	trainerbattle_single TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat
# 16 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
# 17 "data/maps/Route124/scripts.pory"
	end
# 18 "data/maps/Route124/scripts.pory"

# 19 "data/maps/Route124/scripts.pory"
Route124_EventScript_Roland:: @ 81F659C
# 20 "data/maps/Route124/scripts.pory"
	trainerbattle_single TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat
# 21 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
# 22 "data/maps/Route124/scripts.pory"
	end
# 23 "data/maps/Route124/scripts.pory"

# 24 "data/maps/Route124/scripts.pory"
Route124_EventScript_Jenny:: @ 81F65B3
# 25 "data/maps/Route124/scripts.pory"
	trainerbattle_single TRAINER_JENNY_1, Route124_Text_JennyIntro, Route124_Text_JennyDefeat, Route124_EventScript_RegisterJenny
# 26 "data/maps/Route124/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 27 "data/maps/Route124/scripts.pory"
	compare VAR_RESULT, TRUE
# 28 "data/maps/Route124/scripts.pory"
	goto_if_eq Route124_EventScript_RematchJenny
# 29 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_JennyPostBattle, MSGBOX_DEFAULT
# 30 "data/maps/Route124/scripts.pory"
	release
# 31 "data/maps/Route124/scripts.pory"
	end
# 32 "data/maps/Route124/scripts.pory"

# 33 "data/maps/Route124/scripts.pory"
Route124_EventScript_RegisterJenny:: @ 81F65DF
# 34 "data/maps/Route124/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 35 "data/maps/Route124/scripts.pory"
	waitmovement 0
# 36 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_JennyRegister, MSGBOX_DEFAULT
# 37 "data/maps/Route124/scripts.pory"
	register_matchcall TRAINER_JENNY_1
# 38 "data/maps/Route124/scripts.pory"
	release
# 39 "data/maps/Route124/scripts.pory"
	end
# 40 "data/maps/Route124/scripts.pory"

# 41 "data/maps/Route124/scripts.pory"
Route124_EventScript_RematchJenny:: @ 81F65FE
# 42 "data/maps/Route124/scripts.pory"
	trainerbattle_rematch TRAINER_JENNY_1, Route124_Text_JennyRematchIntro, Route124_Text_JennyRematchDefeat
# 43 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_JennyPostRematch, MSGBOX_AUTOCLOSE
# 44 "data/maps/Route124/scripts.pory"
	end
# 45 "data/maps/Route124/scripts.pory"

# 46 "data/maps/Route124/scripts.pory"
Route124_EventScript_Grace:: @ 81F6615
# 47 "data/maps/Route124/scripts.pory"
	trainerbattle_single TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat
# 48 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_GracePostBattle, MSGBOX_AUTOCLOSE
# 49 "data/maps/Route124/scripts.pory"
	end
# 50 "data/maps/Route124/scripts.pory"

# 51 "data/maps/Route124/scripts.pory"
Route124_EventScript_Chad:: @ 81F662C
# 52 "data/maps/Route124/scripts.pory"
	trainerbattle_single TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat
# 53 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
# 54 "data/maps/Route124/scripts.pory"
	end
# 55 "data/maps/Route124/scripts.pory"

# 56 "data/maps/Route124/scripts.pory"
Route124_EventScript_Lila:: @ 81F6643
# 57 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaIntro, Route124_Text_LilaDefeat, Route124_Text_LilaNotEnoughMons, Route124_EventScript_RegisterLila
# 58 "data/maps/Route124/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 59 "data/maps/Route124/scripts.pory"
	compare VAR_RESULT, TRUE
# 60 "data/maps/Route124/scripts.pory"
	goto_if_eq Route124_EventScript_RematchLila
# 61 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_LilaPostBattle, MSGBOX_DEFAULT
# 62 "data/maps/Route124/scripts.pory"
	release
# 63 "data/maps/Route124/scripts.pory"
	end
# 64 "data/maps/Route124/scripts.pory"

# 65 "data/maps/Route124/scripts.pory"
Route124_EventScript_RegisterLila:: @ 81F6673
# 66 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
# 67 "data/maps/Route124/scripts.pory"
	register_matchcall TRAINER_LILA_AND_ROY_1
# 68 "data/maps/Route124/scripts.pory"
	release
# 69 "data/maps/Route124/scripts.pory"
	end
# 70 "data/maps/Route124/scripts.pory"

# 71 "data/maps/Route124/scripts.pory"
Route124_EventScript_RematchLila:: @ 81F668C
# 72 "data/maps/Route124/scripts.pory"
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_LilaRematchIntro, Route124_Text_LilaRematchDefeat, Route124_Text_LilaRematchNotEnoughMons
# 73 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_LilaPostRematch, MSGBOX_AUTOCLOSE
# 74 "data/maps/Route124/scripts.pory"
	end
# 75 "data/maps/Route124/scripts.pory"

# 76 "data/maps/Route124/scripts.pory"
Route124_EventScript_Roy:: @ 81F66A7
# 77 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyIntro, Route124_Text_RoyDefeat, Route124_Text_RoyNotEnoughMons, Route124_EventScript_RegisterRoy
# 78 "data/maps/Route124/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 79 "data/maps/Route124/scripts.pory"
	compare VAR_RESULT, TRUE
# 80 "data/maps/Route124/scripts.pory"
	goto_if_eq Route124_EventScript_RematchRoy
# 81 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_RoyPostBattle, MSGBOX_DEFAULT
# 82 "data/maps/Route124/scripts.pory"
	release
# 83 "data/maps/Route124/scripts.pory"
	end
# 84 "data/maps/Route124/scripts.pory"

# 85 "data/maps/Route124/scripts.pory"
Route124_EventScript_RegisterRoy:: @ 81F66D7
# 86 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_LilaRoyRegister, MSGBOX_DEFAULT
# 87 "data/maps/Route124/scripts.pory"
	register_matchcall TRAINER_LILA_AND_ROY_1
# 88 "data/maps/Route124/scripts.pory"
	release
# 89 "data/maps/Route124/scripts.pory"
	end
# 90 "data/maps/Route124/scripts.pory"

# 91 "data/maps/Route124/scripts.pory"
Route124_EventScript_RematchRoy:: @ 81F66F0
# 92 "data/maps/Route124/scripts.pory"
	trainerbattle_rematch_double TRAINER_LILA_AND_ROY_1, Route124_Text_RoyRematchIntro, Route124_Text_RoyRematchDefeat, Route124_Text_RoyRematchNotEnoughMons
# 93 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_RoyPostRematch, MSGBOX_AUTOCLOSE
# 94 "data/maps/Route124/scripts.pory"
	end
# 95 "data/maps/Route124/scripts.pory"

# 96 "data/maps/Route124/scripts.pory"
Route124_EventScript_Declan:: @ 81F670B
# 97 "data/maps/Route124/scripts.pory"
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat
# 98 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_AUTOCLOSE
# 99 "data/maps/Route124/scripts.pory"
	end
# 100 "data/maps/Route124/scripts.pory"

# 101 "data/maps/Route124/scripts.pory"
Route124_EventScript_Isabella:: @ 81F6722
# 102 "data/maps/Route124/scripts.pory"
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat
# 103 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_IsabellaPostBattle, MSGBOX_AUTOCLOSE
# 104 "data/maps/Route124/scripts.pory"
	end
# 105 "data/maps/Route124/scripts.pory"

# 106 "data/maps/Route124/scripts.pory"
Route124_Text_HuntersHouse: @ 81F6739
# 107 "data/maps/Route124/scripts.pory"
	.string "Hunter's House$"
