Route127_MapScripts:: @ 81F69D9
	map_script MAP_SCRIPT_ON_TRANSITION, Route127_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route127_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route127_OnFrame
	.byte 0

Route127_OnTransition: @ 81F69E9
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_NORTH
	call_if_eq AbnormalWeather_StartKyogreWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_SOUTH
	call_if_eq AbnormalWeather_StartKyogreWeather
	end

Route127_OnLoad: @ 81F6A14
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_NORTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute127North
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_SOUTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute127South
	end

Route127_OnFrame: @ 81F6A2B
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route127_EventScript_Camden:: @ 81F6A35
	trainerbattle_single TRAINER_CAMDEN, Route127_Text_CamdenIntro, Route127_Text_CamdenDefeat
	msgbox Route127_Text_CamdenPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Donny:: @ 81F6A4C
	trainerbattle_single TRAINER_DONNY, Route127_Text_DonnyIntro, Route127_Text_DonnyDefeat
	msgbox Route127_Text_DonnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Jonah:: @ 81F6A63
	trainerbattle_single TRAINER_JONAH, Route127_Text_JonahIntro, Route127_Text_JonahDefeat
	msgbox Route127_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Henry:: @ 81F6A7A
	trainerbattle_single TRAINER_HENRY, Route127_Text_HenryIntro, Route127_Text_HenryDefeat
	msgbox Route127_Text_HenryPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Roger:: @ 81F6A91
	trainerbattle_single TRAINER_ROGER, Route127_Text_RogerIntro, Route127_Text_RogerDefeat
	msgbox Route127_Text_RogerPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Aidan:: @ 81F6AA8
	trainerbattle_single TRAINER_AIDAN, Route127_Text_AidanIntro, Route127_Text_AidanDefeat
	msgbox Route127_Text_AidanPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Athena:: @ 81F6ABF
	trainerbattle_single TRAINER_ATHENA, Route127_Text_AthenaIntro, Route127_Text_AthenaDefeat
	msgbox Route127_Text_AthenaPostBattle, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_Koji:: @ 81F6AD6
	trainerbattle_single TRAINER_KOJI_1, Route127_Text_KojiIntro, Route127_Text_KojiDefeat, Route127_EventScript_RegisterKoji
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route127_EventScript_RematchKoji
	msgbox Route127_Text_KojiPostBattle, MSGBOX_DEFAULT
	release
	end

Route127_EventScript_RegisterKoji:: @ 81F6B02
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route127_Text_KojiRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KOJI_1
	release
	end

Route127_EventScript_RematchKoji:: @ 81F6B21
	trainerbattle_rematch TRAINER_KOJI_1, Route127_Text_KojiRematchIntro, Route127_Text_KojiRematchDefeat
	msgbox Route127_Text_KojiPostRematch, MSGBOX_AUTOCLOSE
	end

Route127_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route127_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route127_EventScript_LegendaryNPC_2
	msgbox Route127_EventScript_LegendaryNPC_Text_4
Route127_EventScript_LegendaryNPC_1:
	release
	end

Route127_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route127_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_KOJI_1
	goto_if 1, Route127_EventScript_LegendaryNPC_11
Route127_EventScript_LegendaryNPC_9:
	msgbox Route127_EventScript_LegendaryNPC_Text_3
	goto Route127_EventScript_LegendaryNPC_1

Route127_EventScript_LegendaryNPC_5:
	msgbox Route127_EventScript_LegendaryNPC_Text_1
	goto Route127_EventScript_LegendaryNPC_1

Route127_EventScript_LegendaryNPC_8:
	msgbox Route127_EventScript_LegendaryNPC_Text_2
	goto Route127_EventScript_LegendaryNPC_1

Route127_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_AIDAN
	goto_if 1, Route127_EventScript_LegendaryNPC_15
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_ATHENA
	goto_if 1, Route127_EventScript_LegendaryNPC_10
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_HENRY
	goto_if 1, Route127_EventScript_LegendaryNPC_19
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_ROGER
	goto_if 1, Route127_EventScript_LegendaryNPC_14
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_DONNY
	goto_if 1, Route127_EventScript_LegendaryNPC_22
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_JONAH
	goto_if 1, Route127_EventScript_LegendaryNPC_18
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_22:
	checktrainerflag TRAINER_CAMDEN
	goto_if 1, Route127_EventScript_LegendaryNPC_8
	goto Route127_EventScript_LegendaryNPC_9


Route127_EventScript_LegendaryNPC_Text_0:
	.string "Sage: This is a resting place for some\n"
	.string "very unfortunate souls, those being\l"
	.string "the Mechanical Wonders. Please don't\l"
	.string "desecrate it. I can tell you how they\l"
	.string "got here, if you're interested.$"

Route127_EventScript_LegendaryNPC_Text_1:
	.string "In the pursuit of power, mankind has\n"
	.string "often strayed into morally wrong\l"
	.string "choices.\p"
	.string "The only law? The one of the strongest.\n"
	.string "For some people, anything goes, as long\l"
	.string "as it's for their gain.\p"
	.string "That has been the case for the\n"
	.string "Mechanical Marvels that rest in these\l"
	.string "shores.\p"
	.string "Genesect, Volcanion, Magearna.\n"
	.string "Creatures so powerful, their makers\l"
	.string "feared their possible retaliation.\p"
	.string "They were used as weapons of mass\n"
	.string "destruction against their will,\l"
	.string "tarnishing them in body and spirit.\p"
	.string "Nothing could stand their power, so\n"
	.string "they ended up outliving their\l"
	.string "usefulness. They broke free from\l"
	.string "captivity, and escaped to\p"
	.string "this peaceful place, in search for\n"
	.string "peace and tranquility, repenting over\l"
	.string "their terrible actions.\p"
	.string "And now, in the pursuit of redemption,\n"
	.string "they strive to protect this haven,\l"
	.string "ensuring that no other creature\l"
	.string "suffers the same fate.\p"
	.string "Only a true champion can earn their\n"
	.string "trust. Come back when you're ready.$"

Route127_EventScript_LegendaryNPC_Text_2:
	.string "You have demonstrated the strength\n"
	.string "and compassion necessary to form an\l"
	.string "unbreakable bond with these\l"
	.string "creatures.\p"
	.string "I updated your DexNav with their\n"
	.string "location. Go forth: they're waiting for\l"
	.string "you.$"

Route127_EventScript_LegendaryNPC_Text_3:
	.string "You have the curiosity of the\n"
	.string "Mechanical Marvels on your side. Show\l"
	.string "them your strength on this route:\l"
	.string "defeat these last few trainers first,\l"
	.string "and I'll show you their location.$"

Route127_EventScript_LegendaryNPC_Text_4:
	.string "Tread carefully.$"
