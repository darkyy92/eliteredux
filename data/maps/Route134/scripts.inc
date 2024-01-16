Route134_MapScripts:: @ 81F7644
	map_script MAP_SCRIPT_ON_RESUME, Route134_OnResume
	.byte 0

Route134_OnResume: @ 81F764A
	setdivewarp MAP_UNDERWATER_ROUTE134, 255, 8, 6
	end

Route134_EventScript_Jack:: @ 81F7653
	trainerbattle_single TRAINER_JACK, Route134_Text_JackIntro, Route134_Text_JackDefeat
	msgbox Route134_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Laurel:: @ 81F766A
	trainerbattle_single TRAINER_LAUREL, Route134_Text_LaurelIntro, Route134_Text_LaurelDefeat
	msgbox Route134_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Alex:: @ 81F7681
	trainerbattle_single TRAINER_ALEX, Route134_Text_AlexIntro, Route134_Text_AlexDefeat
	msgbox Route134_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Aaron:: @ 81F7698
	trainerbattle_single TRAINER_AARON, Route134_Text_AaronIntro, Route134_Text_AaronDefeat
	msgbox Route134_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Hitoshi:: @ 81F76AF
	trainerbattle_single TRAINER_HITOSHI, Route134_Text_HitoshiIntro, Route134_Text_HitoshiDefeat
	msgbox Route134_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Hudson:: @ 81F76C6
	trainerbattle_single TRAINER_HUDSON, Route134_Text_HudsonIntro, Route134_Text_HudsonDefeat
	msgbox Route134_Text_HudsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Reyna:: @ 81F76DD
	trainerbattle_single TRAINER_REYNA, Route134_Text_ReynaIntro, Route134_Text_ReynaDefeat
	msgbox Route134_Text_ReynaPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Marley:: @ 81F76F4
	trainerbattle_single TRAINER_MARLEY, Route134_Text_MarleyIntro, Route134_Text_MarleyDefeat
	msgbox Route134_Text_MarleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Kelvin:: @ 81F770B
	trainerbattle_single TRAINER_KELVIN, Route134_Text_KelvinIntro, Route134_Text_KelvinDefeat
	msgbox Route134_Text_KelvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route134_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route134_EventScript_LegendaryNPC_2
	msgbox Route134_EventScript_LegendaryNPC_Text_4
Route134_EventScript_LegendaryNPC_1:
	release
	end

Route134_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route134_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_KELVIN
	goto_if 1, Route134_EventScript_LegendaryNPC_11
Route134_EventScript_LegendaryNPC_9:
	msgbox Route134_EventScript_LegendaryNPC_Text_3
	goto Route134_EventScript_LegendaryNPC_1

Route134_EventScript_LegendaryNPC_5:
	msgbox Route134_EventScript_LegendaryNPC_Text_1
	goto Route134_EventScript_LegendaryNPC_1

Route134_EventScript_LegendaryNPC_8:
	msgbox Route134_EventScript_LegendaryNPC_Text_2
	goto Route134_EventScript_LegendaryNPC_1

Route134_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_REYNA
	goto_if 1, Route134_EventScript_LegendaryNPC_15
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_MARLEY
	goto_if 1, Route134_EventScript_LegendaryNPC_10
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_HITOSHI
	goto_if 1, Route134_EventScript_LegendaryNPC_19
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_HUDSON
	goto_if 1, Route134_EventScript_LegendaryNPC_14
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_ALEX
	goto_if 1, Route134_EventScript_LegendaryNPC_23
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_AARON
	goto_if 1, Route134_EventScript_LegendaryNPC_18
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_22:
	checktrainerflag TRAINER_JACK
	goto_if 1, Route134_EventScript_LegendaryNPC_8
	goto Route134_EventScript_LegendaryNPC_9

Route134_EventScript_LegendaryNPC_23:
	checktrainerflag TRAINER_LAUREL
	goto_if 1, Route134_EventScript_LegendaryNPC_22
	goto Route134_EventScript_LegendaryNPC_9


Route134_EventScript_LegendaryNPC_Text_0:
	.string "Sage: The last of the Ultra Beasts\n"
	.string "reside here. You know the drill: want to\l"
	.string "know more about them?$"

Route134_EventScript_LegendaryNPC_Text_1:
	.string "Like many others, this route houses\n"
	.string "some of the Ultra Beasts from outer\l"
	.string "space. I will reveal their location\p"
	.string "to you, but only when you become\n"
	.string "champion!$"

Route134_EventScript_LegendaryNPC_Text_2:
	.string "You demonstrated great strenght and\n"
	.string "resoluteness in your journey, I think\l"
	.string "you're ready to meet the Ultra beasts.\l"
	.string "Xurkitree, Stakataka and Blacephalon\l"
	.string "are hiding here: use your DexNav to see\l"
	.string "their location.$"

Route134_EventScript_LegendaryNPC_Text_3:
	.string "Are you here looking for some of the\n"
	.string "Ultra Beasts? I thought so. I'll tell\l"
	.string "you where they hide, but first, defeat\l"
	.string "all trainers in this route!$"

Route134_EventScript_LegendaryNPC_Text_4:
	.string "While I can forget everything I wanna\n"
	.string "be, I can't forget what I don't wanna\l"
	.string "become: you!$"
