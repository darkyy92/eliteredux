# 1 "data/maps/Route134/scripts.pory"

# 2 "data/maps/Route134/scripts.pory"
Route134_MapScripts:: @ 81F7644
# 3 "data/maps/Route134/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route134_OnResume
# 4 "data/maps/Route134/scripts.pory"
	.byte 0
# 5 "data/maps/Route134/scripts.pory"

# 6 "data/maps/Route134/scripts.pory"
Route134_OnResume: @ 81F764A
# 7 "data/maps/Route134/scripts.pory"
	setdivewarp MAP_UNDERWATER_ROUTE134, 255, 8, 6
# 8 "data/maps/Route134/scripts.pory"
	end
# 9 "data/maps/Route134/scripts.pory"

# 10 "data/maps/Route134/scripts.pory"
Route134_EventScript_Jack:: @ 81F7653
# 11 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_JACK, Route134_Text_JackIntro, Route134_Text_JackDefeat
# 12 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_JackPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/Route134/scripts.pory"
	end
# 14 "data/maps/Route134/scripts.pory"

# 15 "data/maps/Route134/scripts.pory"
Route134_EventScript_Laurel:: @ 81F766A
# 16 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_LAUREL, Route134_Text_LaurelIntro, Route134_Text_LaurelDefeat
# 17 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
# 18 "data/maps/Route134/scripts.pory"
	end
# 19 "data/maps/Route134/scripts.pory"

# 20 "data/maps/Route134/scripts.pory"
Route134_EventScript_Alex:: @ 81F7681
# 21 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_ALEX, Route134_Text_AlexIntro, Route134_Text_AlexDefeat
# 22 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
# 23 "data/maps/Route134/scripts.pory"
	end
# 24 "data/maps/Route134/scripts.pory"

# 25 "data/maps/Route134/scripts.pory"
Route134_EventScript_Aaron:: @ 81F7698
# 26 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_AARON, Route134_Text_AaronIntro, Route134_Text_AaronDefeat
# 27 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/Route134/scripts.pory"
	end
# 29 "data/maps/Route134/scripts.pory"

# 30 "data/maps/Route134/scripts.pory"
Route134_EventScript_Hitoshi:: @ 81F76AF
# 31 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_HITOSHI, Route134_Text_HitoshiIntro, Route134_Text_HitoshiDefeat
# 32 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
# 33 "data/maps/Route134/scripts.pory"
	end
# 34 "data/maps/Route134/scripts.pory"

# 35 "data/maps/Route134/scripts.pory"
Route134_EventScript_Hudson:: @ 81F76C6
# 36 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_HUDSON, Route134_Text_HudsonIntro, Route134_Text_HudsonDefeat
# 37 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_HudsonPostBattle, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route134/scripts.pory"
	end
# 39 "data/maps/Route134/scripts.pory"

# 40 "data/maps/Route134/scripts.pory"
Route134_EventScript_Reyna:: @ 81F76DD
# 41 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_REYNA, Route134_Text_ReynaIntro, Route134_Text_ReynaDefeat
# 42 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_ReynaPostBattle, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route134/scripts.pory"
	end
# 44 "data/maps/Route134/scripts.pory"

# 45 "data/maps/Route134/scripts.pory"
Route134_EventScript_Marley:: @ 81F76F4
# 46 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_MARLEY, Route134_Text_MarleyIntro, Route134_Text_MarleyDefeat
# 47 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_MarleyPostBattle, MSGBOX_AUTOCLOSE
# 48 "data/maps/Route134/scripts.pory"
	end
# 49 "data/maps/Route134/scripts.pory"

# 50 "data/maps/Route134/scripts.pory"
Route134_EventScript_Kelvin:: @ 81F770B
# 51 "data/maps/Route134/scripts.pory"
	trainerbattle_single TRAINER_KELVIN, Route134_Text_KelvinIntro, Route134_Text_KelvinDefeat
# 52 "data/maps/Route134/scripts.pory"
	msgbox Route134_Text_KelvinPostBattle, MSGBOX_AUTOCLOSE
# 53 "data/maps/Route134/scripts.pory"
	end

Route134_EventScript_LegendaryNPC::
# 57 "data/maps/Route134/scripts.pory"
	lock
# 58 "data/maps/Route134/scripts.pory"
	faceplayer
# 59 "data/maps/Route134/scripts.pory"
	msgbox Route134_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 60 "data/maps/Route134/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route134_EventScript_LegendaryNPC_2
# 83 "data/maps/Route134/scripts.pory"
	msgbox Route134_EventScript_LegendaryNPC_Text_4
Route134_EventScript_LegendaryNPC_1:
# 85 "data/maps/Route134/scripts.pory"
	release
	end

Route134_EventScript_LegendaryNPC_2:
# 61 "data/maps/Route134/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route134_EventScript_LegendaryNPC_5
# 66 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_KELVIN
	goto_if 1, Route134_EventScript_LegendaryNPC_11
Route134_EventScript_LegendaryNPC_9:
# 78 "data/maps/Route134/scripts.pory"
	msgbox Route134_EventScript_LegendaryNPC_Text_3
	goto Route134_EventScript_LegendaryNPC_1

Route134_EventScript_LegendaryNPC_5:
# 62 "data/maps/Route134/scripts.pory"
	msgbox Route134_EventScript_LegendaryNPC_Text_1
	goto Route134_EventScript_LegendaryNPC_1

Route134_EventScript_LegendaryNPC_8:
# 75 "data/maps/Route134/scripts.pory"
	msgbox Route134_EventScript_LegendaryNPC_Text_2
	goto Route134_EventScript_LegendaryNPC_1

Route134_EventScript_LegendaryNPC_10:
# 68 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_REYNA
	goto_if 1, Route134_EventScript_LegendaryNPC_15
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_11:
# 67 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_MARLEY
	goto_if 1, Route134_EventScript_LegendaryNPC_10
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_14:
# 70 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_HITOSHI
	goto_if 1, Route134_EventScript_LegendaryNPC_19
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_15:
# 69 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_HUDSON
	goto_if 1, Route134_EventScript_LegendaryNPC_14
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_18:
# 72 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_ALEX
	goto_if 1, Route134_EventScript_LegendaryNPC_23
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_19:
# 71 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_AARON
	goto_if 1, Route134_EventScript_LegendaryNPC_18
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_22:
# 74 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_JACK
	goto_if 1, Route134_EventScript_LegendaryNPC_8
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_23:
# 73 "data/maps/Route134/scripts.pory"
	checktrainerflag TRAINER_LAUREL
	goto_if 1, Route134_EventScript_LegendaryNPC_22
	goto Route134_EventScript_LegendaryNPC_9


Route134_EventScript_LegendaryNPC_Text_0:
# 59 "data/maps/Route134/scripts.pory"
	.string "Sage: The last of the Ultra Beasts\n"
	.string "reside here. You know the drill: want to\l"
	.string "know more about them?$"

Route134_EventScript_LegendaryNPC_Text_1:
# 62 "data/maps/Route134/scripts.pory"
	.string "Like many others, this route houses\n"
	.string "some of the Ultra Beasts from outer\l"
	.string "space. I will reveal their location\p"
	.string "to you, but only when you become\n"
	.string "champion!$"

Route134_EventScript_LegendaryNPC_Text_2:
# 75 "data/maps/Route134/scripts.pory"
	.string "You demonstrated great strenght and\n"
	.string "resoluteness in your journey, I think\l"
	.string "you're ready to meet the Ultra beasts.\l"
	.string "Xurkitree, Stakataka and Blacephalon\l"
	.string "are hiding here: use your DexNav to see\l"
	.string "their location.$"

Route134_EventScript_LegendaryNPC_Text_3:
# 78 "data/maps/Route134/scripts.pory"
	.string "Are you here looking for some of the\n"
	.string "Ultra Beasts? I thought so. I'll tell you\l"
	.string "where they hide, but first, defeat all\l"
	.string "trainers in this route!$"

Route134_EventScript_LegendaryNPC_Text_4:
# 83 "data/maps/Route134/scripts.pory"
	.string "While I can forget everything I wanna\n"
	.string "be, I can't forget what I don't wanna\l"
	.string "become: you!$"
