# 1 "data/maps/Route127/scripts.pory"

# 2 "data/maps/Route127/scripts.pory"
Route127_MapScripts:: @ 81F69D9
# 3 "data/maps/Route127/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route127_OnTransition
# 4 "data/maps/Route127/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route127_OnLoad
# 5 "data/maps/Route127/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route127_OnFrame
# 6 "data/maps/Route127/scripts.pory"
	.byte 0
# 7 "data/maps/Route127/scripts.pory"

# 8 "data/maps/Route127/scripts.pory"
Route127_OnTransition: @ 81F69E9
# 9 "data/maps/Route127/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 10 "data/maps/Route127/scripts.pory"
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 11 "data/maps/Route127/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
# 12 "data/maps/Route127/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_NORTH
# 13 "data/maps/Route127/scripts.pory"
	call_if_eq AbnormalWeather_StartKyogreWeather
# 14 "data/maps/Route127/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_SOUTH
# 15 "data/maps/Route127/scripts.pory"
	call_if_eq AbnormalWeather_StartKyogreWeather
# 16 "data/maps/Route127/scripts.pory"
	end
# 17 "data/maps/Route127/scripts.pory"

# 18 "data/maps/Route127/scripts.pory"
Route127_OnLoad: @ 81F6A14
# 19 "data/maps/Route127/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_NORTH
# 20 "data/maps/Route127/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute127North
# 21 "data/maps/Route127/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_127_SOUTH
# 22 "data/maps/Route127/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute127South
# 23 "data/maps/Route127/scripts.pory"
	end
# 24 "data/maps/Route127/scripts.pory"

# 25 "data/maps/Route127/scripts.pory"
Route127_OnFrame: @ 81F6A2B
# 26 "data/maps/Route127/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 27 "data/maps/Route127/scripts.pory"
	.2byte 0
# 28 "data/maps/Route127/scripts.pory"

# 29 "data/maps/Route127/scripts.pory"
Route127_EventScript_Camden:: @ 81F6A35
# 30 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_CAMDEN, Route127_Text_CamdenIntro, Route127_Text_CamdenDefeat
# 31 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_CamdenPostBattle, MSGBOX_AUTOCLOSE
# 32 "data/maps/Route127/scripts.pory"
	end
# 33 "data/maps/Route127/scripts.pory"

# 34 "data/maps/Route127/scripts.pory"
Route127_EventScript_Donny:: @ 81F6A4C
# 35 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_DONNY, Route127_Text_DonnyIntro, Route127_Text_DonnyDefeat
# 36 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_DonnyPostBattle, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route127/scripts.pory"
	end
# 38 "data/maps/Route127/scripts.pory"

# 39 "data/maps/Route127/scripts.pory"
Route127_EventScript_Jonah:: @ 81F6A63
# 40 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_JONAH, Route127_Text_JonahIntro, Route127_Text_JonahDefeat
# 41 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route127/scripts.pory"
	end
# 43 "data/maps/Route127/scripts.pory"

# 44 "data/maps/Route127/scripts.pory"
Route127_EventScript_Henry:: @ 81F6A7A
# 45 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_HENRY, Route127_Text_HenryIntro, Route127_Text_HenryDefeat
# 46 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_HenryPostBattle, MSGBOX_AUTOCLOSE
# 47 "data/maps/Route127/scripts.pory"
	end
# 48 "data/maps/Route127/scripts.pory"

# 49 "data/maps/Route127/scripts.pory"
Route127_EventScript_Roger:: @ 81F6A91
# 50 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_ROGER, Route127_Text_RogerIntro, Route127_Text_RogerDefeat
# 51 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_RogerPostBattle, MSGBOX_AUTOCLOSE
# 52 "data/maps/Route127/scripts.pory"
	end
# 53 "data/maps/Route127/scripts.pory"

# 54 "data/maps/Route127/scripts.pory"
Route127_EventScript_Aidan:: @ 81F6AA8
# 55 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_AIDAN, Route127_Text_AidanIntro, Route127_Text_AidanDefeat
# 56 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_AidanPostBattle, MSGBOX_AUTOCLOSE
# 57 "data/maps/Route127/scripts.pory"
	end
# 58 "data/maps/Route127/scripts.pory"

# 59 "data/maps/Route127/scripts.pory"
Route127_EventScript_Athena:: @ 81F6ABF
# 60 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_ATHENA, Route127_Text_AthenaIntro, Route127_Text_AthenaDefeat
# 61 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_AthenaPostBattle, MSGBOX_AUTOCLOSE
# 62 "data/maps/Route127/scripts.pory"
	end
# 63 "data/maps/Route127/scripts.pory"

# 64 "data/maps/Route127/scripts.pory"
Route127_EventScript_Koji:: @ 81F6AD6
# 65 "data/maps/Route127/scripts.pory"
	trainerbattle_single TRAINER_KOJI_1, Route127_Text_KojiIntro, Route127_Text_KojiDefeat, Route127_EventScript_RegisterKoji
# 66 "data/maps/Route127/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 67 "data/maps/Route127/scripts.pory"
	compare VAR_RESULT, TRUE
# 68 "data/maps/Route127/scripts.pory"
	goto_if_eq Route127_EventScript_RematchKoji
# 69 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_KojiPostBattle, MSGBOX_DEFAULT
# 70 "data/maps/Route127/scripts.pory"
	release
# 71 "data/maps/Route127/scripts.pory"
	end
# 72 "data/maps/Route127/scripts.pory"

# 73 "data/maps/Route127/scripts.pory"
Route127_EventScript_RegisterKoji:: @ 81F6B02
# 74 "data/maps/Route127/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 75 "data/maps/Route127/scripts.pory"
	waitmovement 0
# 76 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_KojiRegister, MSGBOX_DEFAULT
# 77 "data/maps/Route127/scripts.pory"
	register_matchcall TRAINER_KOJI_1
# 78 "data/maps/Route127/scripts.pory"
	release
# 79 "data/maps/Route127/scripts.pory"
	end
# 80 "data/maps/Route127/scripts.pory"

# 81 "data/maps/Route127/scripts.pory"
Route127_EventScript_RematchKoji:: @ 81F6B21
# 82 "data/maps/Route127/scripts.pory"
	trainerbattle_rematch TRAINER_KOJI_1, Route127_Text_KojiRematchIntro, Route127_Text_KojiRematchDefeat
# 83 "data/maps/Route127/scripts.pory"
	msgbox Route127_Text_KojiPostRematch, MSGBOX_AUTOCLOSE
# 84 "data/maps/Route127/scripts.pory"
	end

Route127_EventScript_LegendaryNPC::
# 89 "data/maps/Route127/scripts.pory"
	lock
# 90 "data/maps/Route127/scripts.pory"
	faceplayer
# 91 "data/maps/Route127/scripts.pory"
	msgbox Route127_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 92 "data/maps/Route127/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route127_EventScript_LegendaryNPC_2
# 122 "data/maps/Route127/scripts.pory"
	msgbox Route127_EventScript_LegendaryNPC_Text_4
Route127_EventScript_LegendaryNPC_1:
# 124 "data/maps/Route127/scripts.pory"
	release
	end

Route127_EventScript_LegendaryNPC_2:
# 93 "data/maps/Route127/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route127_EventScript_LegendaryNPC_5
# 105 "data/maps/Route127/scripts.pory"
	checktrainerflag TRAINER_KOJI_1
	goto_if 1, Route127_EventScript_LegendaryNPC_11
Route127_EventScript_LegendaryNPC_9:
# 117 "data/maps/Route127/scripts.pory"
	msgbox Route127_EventScript_LegendaryNPC_Text_3
	goto Route127_EventScript_LegendaryNPC_1

Route127_EventScript_LegendaryNPC_5:
# 94 "data/maps/Route127/scripts.pory"
	msgbox Route127_EventScript_LegendaryNPC_Text_1
	goto Route127_EventScript_LegendaryNPC_1

Route127_EventScript_LegendaryNPC_8:
# 113 "data/maps/Route127/scripts.pory"
	msgbox Route127_EventScript_LegendaryNPC_Text_2
	goto Route127_EventScript_LegendaryNPC_1

Route127_EventScript_LegendaryNPC_10:
# 107 "data/maps/Route127/scripts.pory"
	checktrainerflag TRAINER_AIDAN
	goto_if 1, Route127_EventScript_LegendaryNPC_15
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_11:
# 106 "data/maps/Route127/scripts.pory"
	checktrainerflag TRAINER_ATHENA
	goto_if 1, Route127_EventScript_LegendaryNPC_10
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_14:
# 109 "data/maps/Route127/scripts.pory"
	checktrainerflag TRAINER_HENRY
	goto_if 1, Route127_EventScript_LegendaryNPC_19
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_15:
# 108 "data/maps/Route127/scripts.pory"
	checktrainerflag TRAINER_ROGER
	goto_if 1, Route127_EventScript_LegendaryNPC_14
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_18:
# 111 "data/maps/Route127/scripts.pory"
	checktrainerflag TRAINER_DONNY
	goto_if 1, Route127_EventScript_LegendaryNPC_22
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_19:
# 110 "data/maps/Route127/scripts.pory"
	checktrainerflag TRAINER_JONAH
	goto_if 1, Route127_EventScript_LegendaryNPC_18
	goto Route127_EventScript_LegendaryNPC_9

Route127_EventScript_LegendaryNPC_22:
# 112 "data/maps/Route127/scripts.pory"
	checktrainerflag TRAINER_CAMDEN
	goto_if 1, Route127_EventScript_LegendaryNPC_8
	goto Route127_EventScript_LegendaryNPC_9


Route127_EventScript_LegendaryNPC_Text_0:
# 91 "data/maps/Route127/scripts.pory"
	.string "Sage: This is a resting place for some\n"
	.string "very unfortunate souls, those being\l"
	.string "the Mechanical Wonders. Please don't\l"
	.string "desecrate it. I can tell you how they\l"
	.string "got here, if you're interested.$"

Route127_EventScript_LegendaryNPC_Text_1:
# 94 "data/maps/Route127/scripts.pory"
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
# 113 "data/maps/Route127/scripts.pory"
	.string "You have demonstrated the strength\n"
	.string "and compassion necessary to form an\l"
	.string "unbreakable bond with these creatures.\p"
	.string "I updated your DexNav with their\n"
	.string "location. Go forth: they're waiting for\l"
	.string "you.$"

Route127_EventScript_LegendaryNPC_Text_3:
# 117 "data/maps/Route127/scripts.pory"
	.string "You have the curiosity of the\n"
	.string "Mechanical Marvels on your side. Show\l"
	.string "them your strength on this route:\l"
	.string "defeat these last few trainers first,\l"
	.string "and I'll show you their location.$"

Route127_EventScript_LegendaryNPC_Text_4:
# 122 "data/maps/Route127/scripts.pory"
	.string "Tread carefully.$"
