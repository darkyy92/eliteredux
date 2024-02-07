# 1 "data/maps/Route105/scripts.pory"

# 2 "data/maps/Route105/scripts.pory"
Route105_MapScripts:: @ 81EE1DB
# 3 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route105_OnLoad
# 4 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
# 5 "data/maps/Route105/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_OnFrame
# 6 "data/maps/Route105/scripts.pory"
	.byte 0
# 7 "data/maps/Route105/scripts.pory"

# 8 "data/maps/Route105/scripts.pory"
Route105_OnLoad: @ 81EE1EB
# 9 "data/maps/Route105/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route105_CloseRegiEntrance
# 10 "data/maps/Route105/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH
# 11 "data/maps/Route105/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute105North
# 12 "data/maps/Route105/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH
# 13 "data/maps/Route105/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute105South
# 14 "data/maps/Route105/scripts.pory"
	end
# 15 "data/maps/Route105/scripts.pory"

# 16 "data/maps/Route105/scripts.pory"
Route105_CloseRegiEntrance:: @ 81EE20B
# 17 "data/maps/Route105/scripts.pory"
	setmetatile 9, 19, METATILE_General_RockWall_RockBase, 1
# 18 "data/maps/Route105/scripts.pory"
	setmetatile 9, 20, METATILE_General_RockWall_SandBase, 1
# 19 "data/maps/Route105/scripts.pory"
	return
# 20 "data/maps/Route105/scripts.pory"

# 21 "data/maps/Route105/scripts.pory"
Route105_OnTransition: @ 81EE21E
# 22 "data/maps/Route105/scripts.pory"
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 23 "data/maps/Route105/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
# 24 "data/maps/Route105/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH
# 25 "data/maps/Route105/scripts.pory"
	call_if_eq AbnormalWeather_StartKyogreWeather
# 26 "data/maps/Route105/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH
# 27 "data/maps/Route105/scripts.pory"
	call_if_eq AbnormalWeather_StartKyogreWeather
# 28 "data/maps/Route105/scripts.pory"
	end
# 29 "data/maps/Route105/scripts.pory"

# 30 "data/maps/Route105/scripts.pory"
Route105_OnFrame: @ 81EE240
# 31 "data/maps/Route105/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 32 "data/maps/Route105/scripts.pory"
	.2byte 0
# 33 "data/maps/Route105/scripts.pory"

# 34 "data/maps/Route105/scripts.pory"
Route105_EventScript_Foster:: @ 81EE24A
# 35 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated
# 36 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route105/scripts.pory"
	end
# 38 "data/maps/Route105/scripts.pory"

# 39 "data/maps/Route105/scripts.pory"
Route105_EventScript_Luis:: @ 81EE261
# 40 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated
# 41 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route105/scripts.pory"
	end
# 43 "data/maps/Route105/scripts.pory"

# 44 "data/maps/Route105/scripts.pory"
Route105_EventScript_Dominik:: @ 81EE278
# 45 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated
# 46 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_DominikPostBattle, MSGBOX_AUTOCLOSE
# 47 "data/maps/Route105/scripts.pory"
	end
# 48 "data/maps/Route105/scripts.pory"

# 49 "data/maps/Route105/scripts.pory"
Route105_EventScript_Beverly:: @ 81EE28F
# 50 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated
# 51 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_PostBattle, MSGBOX_AUTOCLOSE
# 52 "data/maps/Route105/scripts.pory"
	end
# 53 "data/maps/Route105/scripts.pory"

# 54 "data/maps/Route105/scripts.pory"
Route105_EventScript_Imani:: @ 81EE2A6
# 55 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated
# 56 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_AUTOCLOSE
# 57 "data/maps/Route105/scripts.pory"
	end
# 58 "data/maps/Route105/scripts.pory"

# 59 "data/maps/Route105/scripts.pory"
Route105_EventScript_Josue:: @ 81EE2BD
# 60 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_JOSUE, Route105_Text_JosueIntro, Route105_Text_JosueDefeated
# 61 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_JosuePostBattle, MSGBOX_AUTOCLOSE
# 62 "data/maps/Route105/scripts.pory"
	end
# 63 "data/maps/Route105/scripts.pory"

# 64 "data/maps/Route105/scripts.pory"
Route105_EventScript_Andres:: @ 81EE2D4
# 65 "data/maps/Route105/scripts.pory"
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_AndresIntro, Route105_Text_AndresDefeated, Route105_EventScript_AndresRegisterMatchCallAfterBattle
# 66 "data/maps/Route105/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 67 "data/maps/Route105/scripts.pory"
	compare VAR_RESULT, TRUE
# 68 "data/maps/Route105/scripts.pory"
	goto_if_eq Route105_EventScript_AndresRematch
# 69 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresPostBattle, MSGBOX_DEFAULT
# 70 "data/maps/Route105/scripts.pory"
	release
# 71 "data/maps/Route105/scripts.pory"
	end
# 72 "data/maps/Route105/scripts.pory"

# 73 "data/maps/Route105/scripts.pory"
Route105_EventScript_AndresRegisterMatchCallAfterBattle:: @ 81EE300
# 74 "data/maps/Route105/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 75 "data/maps/Route105/scripts.pory"
	waitmovement 0
# 76 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresRegister, MSGBOX_DEFAULT
# 77 "data/maps/Route105/scripts.pory"
	register_matchcall TRAINER_ANDRES_1
# 78 "data/maps/Route105/scripts.pory"
	release
# 79 "data/maps/Route105/scripts.pory"
	end
# 80 "data/maps/Route105/scripts.pory"

# 81 "data/maps/Route105/scripts.pory"
Route105_EventScript_AndresRematch:: @ 81EE31F
# 82 "data/maps/Route105/scripts.pory"
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_AndresRematchIntro, Route105_Text_AndresRematchDefeated
# 83 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresRematchPostBattle, MSGBOX_AUTOCLOSE
# 84 "data/maps/Route105/scripts.pory"
	end
# 85 "data/maps/Route105/scripts.pory"

# 86 "data/maps/Route105/scripts.pory"
Route104_Text_DadPokenavCall: @ 81EE336
# 87 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 88 "data/maps/Route105/scripts.pory"
	.string "… … … … … Beep!\p"
# 89 "data/maps/Route105/scripts.pory"
	.string "Dad: Oh, {PLAYER}?\p"
# 90 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 91 "data/maps/Route105/scripts.pory"
	.string "Where are you now?\l"
# 92 "data/maps/Route105/scripts.pory"
	.string "It sounds windy wherever you are.\p"
# 93 "data/maps/Route105/scripts.pory"
	.string "I just heard from Devon's Mr. Stone\n"
# 94 "data/maps/Route105/scripts.pory"
	.string "about your PokéNav, so I decided\l"
# 95 "data/maps/Route105/scripts.pory"
	.string "to give you a call.\p"
# 96 "data/maps/Route105/scripts.pory"
	.string "It sounds like you're doing fine,\n"
# 97 "data/maps/Route105/scripts.pory"
	.string "so that's fine with me.\p"
# 98 "data/maps/Route105/scripts.pory"
	.string "You take care now.\p"
# 99 "data/maps/Route105/scripts.pory"
	.string "… … … … … …\n"
# 100 "data/maps/Route105/scripts.pory"
	.string "… … … … … Click!$"
# 101 "data/maps/Route105/scripts.pory"

# 102 "data/maps/Route105/scripts.pory"
Route104_Text_RegisteredDadInPokenav: @ 81EE463
# 103 "data/maps/Route105/scripts.pory"
	.string "Registered Dad Norman\n"
# 104 "data/maps/Route105/scripts.pory"
	.string "in the PokéNav.$"

Route105_EventScript_FeraligatriteX_Battle::
# 108 "data/maps/Route105/scripts.pory"
	lock
# 109 "data/maps/Route105/scripts.pory"
	faceplayer
# 110 "data/maps/Route105/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, Route105_EventScript_FeraligatriteX_Battle_2
# 131 "data/maps/Route105/scripts.pory"
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_6, MSGBOX_NPC
Route105_EventScript_FeraligatriteX_Battle_1:
# 133 "data/maps/Route105/scripts.pory"
	release
	end

Route105_EventScript_FeraligatriteX_Battle_2:
# 112 "data/maps/Route105/scripts.pory"
	checktrainerflag TRAINER_FERALIGATRITEX_ROUTE105
	goto_if 0, Route105_EventScript_FeraligatriteX_Battle_5
# 127 "data/maps/Route105/scripts.pory"
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_5, MSGBOX_NPC
	goto Route105_EventScript_FeraligatriteX_Battle_1

Route105_EventScript_FeraligatriteX_Battle_5:
# 113 "data/maps/Route105/scripts.pory"
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_0, MSGBOX_YESNO
# 114 "data/maps/Route105/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route105_EventScript_FeraligatriteX_Battle_8
# 123 "data/maps/Route105/scripts.pory"
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_4, MSGBOX_NPC
	goto Route105_EventScript_FeraligatriteX_Battle_1

Route105_EventScript_FeraligatriteX_Battle_8:
# 115 "data/maps/Route105/scripts.pory"
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_1, MSGBOX_NPC
# 116 "data/maps/Route105/scripts.pory"
	trainerbattle_no_intro TRAINER_FERALIGATRITEX_ROUTE105, Route105_EventScript_FeraligatriteX_Battle_Text_2
# 117 "data/maps/Route105/scripts.pory"
	msgbox Route105_EventScript_FeraligatriteX_Battle_Text_3, MSGBOX_NPC
# 118 "data/maps/Route105/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 119 "data/maps/Route105/scripts.pory"
	giveitem ITEM_FERALIGATRITE_X, 1
# 120 "data/maps/Route105/scripts.pory"
	waitmessage
	goto Route105_EventScript_FeraligatriteX_Battle_1


Route105_EventScript_FeraligatriteX_Battle_Text_0:
# 113 "data/maps/Route105/scripts.pory"
	.string "Ahoy there, ye seem like a sturdy one,\n"
	.string "aye? Fancy a little tussle with me? If\l"
	.string "ye be willin', I'll part with this here\l"
	.string "fine stone as a reward for our bout.$"

Route105_EventScript_FeraligatriteX_Battle_Text_1:
# 115 "data/maps/Route105/scripts.pory"
	.string "Aye, that be a fine choice, indeed!$"

Route105_EventScript_FeraligatriteX_Battle_Text_2:
# 116 "data/maps/Route105/scripts.pory"
	.string "Aye, ye had me figured out, ye did!$"

Route105_EventScript_FeraligatriteX_Battle_Text_3:
# 117 "data/maps/Route105/scripts.pory"
	.string "Ye've proven yer mettle, and true to me\n"
	.string "word, here's that stone I promised ye!$"

Route105_EventScript_FeraligatriteX_Battle_Text_4:
# 123 "data/maps/Route105/scripts.pory"
	.string "What are ye, scared?$"

Route105_EventScript_FeraligatriteX_Battle_Text_5:
# 127 "data/maps/Route105/scripts.pory"
	.string "Aye, I reckon ye'll find some joy in the\n"
	.string "gift I've handed over to ye, me hearty!$"

Route105_EventScript_FeraligatriteX_Battle_Text_6:
# 131 "data/maps/Route105/scripts.pory"
	.string "Ye be lackin' the strength, me hearty!$"
