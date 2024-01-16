Route114_MapScripts:: @ 81F252F
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
	.byte 0

Route114_OnTransition: @ 81F253F
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route114_OnLoad: @ 81F2561
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute114North
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute114South
	end

Route114_OnFrame: @ 81F2578
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route114_EventScript_Man:: @ 81F2582
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_ReceivedBerry
	msgbox Route114_Text_LoveUsingBerryCrushShareBerry, MSGBOX_DEFAULT
	random NUM_ROUTE_114_MAN_BERRIES
	addvar VAR_RESULT, NUM_ROUTE_114_MAN_BERRIES_SKIPPED
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
	msgbox Route114_Text_TryBerryCrushWithFriends, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_ReceivedBerry:: @ 81F25C7
	msgbox Route114_Text_FunToThinkAboutBerries, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RoarGentleman:: @ 81F25D1
	lock
	faceplayer
	msgbox Route114_Text_AllMyMonDoesIsRoarTakeThis, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_ReceivedRoar:: @ 81F2608
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_Poochyena:: @ 81F2612
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, 2
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route114_EventScript_MeteorFallsSign:: @ 81F2625
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route114_EventScript_FossilManiacsHouseSign:: @ 81F262E
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
	end

Route114_EventScript_LanettesHouseSign:: @ 81F2637
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
	end

Route114_EventScript_Lenny:: @ 81F2640
	trainerbattle_single TRAINER_LENNY, Route114_Text_LennyIntro, Route114_Text_LennyDefeat
	msgbox Route114_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Lucas:: @ 81F2657
	trainerbattle_single TRAINER_LUCAS_1, Route114_Text_LucasIntro, Route114_Text_LucasDefeat
	msgbox Route114_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Shane:: @ 81F266E
	trainerbattle_single TRAINER_SHANE, Route114_Text_ShaneIntro, Route114_Text_ShaneDefeat
	msgbox Route114_Text_ShanePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Nancy:: @ 81F2685
	trainerbattle_single TRAINER_NANCY, Route114_Text_NancyIntro, Route114_Text_NancyDefeat
	msgbox Route114_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Steve:: @ 81F269C
	trainerbattle_single TRAINER_STEVE_1, Route114_Text_SteveIntro, Route114_Text_SteveDefeat, Route114_EventScript_RegisterSteve
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route114_EventScript_RematchSteve
	msgbox Route114_Text_StevePostBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RegisterSteve:: @ 81F26C8
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route114_Text_SteveRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_STEVE_1
	release
	end

Route114_EventScript_RematchSteve:: @ 81F26E7
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_SteveRematchIntro, Route114_Text_SteveRematchDefeat
	msgbox Route114_Text_StevePostRematch, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Bernie:: @ 81F26FE
	trainerbattle_single TRAINER_BERNIE_1, Route114_Text_BernieIntro, Route114_Text_BernieDefeat, Route114_EventScript_RegisterBernie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route114_EventScript_RematchBernie
	msgbox Route114_Text_BerniePostBattle, MSGBOX_DEFAULT
	release
	end

Route114_EventScript_RegisterBernie:: @ 81F272A
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route114_Text_BernieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BERNIE_1
	release
	end

Route114_EventScript_RematchBernie:: @ 81F2749
	trainerbattle_rematch TRAINER_BERNIE_1, Route114_Text_BernieRematchIntro, Route114_Text_BernieRematchDefeat
	msgbox Route114_Text_BerniePostRematch, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Claude:: @ 81F2760
	trainerbattle_single TRAINER_CLAUDE, Route114_Text_ClaudeIntro, Route114_Text_ClaudeDefeat
	msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Nolan:: @ 81F2777
	trainerbattle_single TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat
	msgbox Route114_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Tyra:: @ 81F278E
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_TyraIntro, Route114_Text_TyraDefeat, Route114_Text_TyraNotEnoughMons
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Ivy:: @ 81F27A9
	trainerbattle_double TRAINER_TYRA_AND_IVY, Route114_Text_IvyIntro, Route114_Text_IvyDefeat, Route114_Text_IvyNotEnoughMons
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Angelina:: @ 81F27C4
	trainerbattle_single TRAINER_ANGELINA, Route114_Text_AngelinaIntro, Route114_Text_AngelinaDefeat
	msgbox Route114_Text_AngelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Charlotte:: @ 81F27DB
	trainerbattle_single TRAINER_CHARLOTTE, Route114_Text_CharlotteIntro, Route114_Text_CharlotteDefeat
	msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_Kai:: @ 81F27F2
	trainerbattle_single TRAINER_KAI, Route114_Text_KaiIntro, Route114_Text_KaiDefeat
	msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
	end

Route114_Text_AllMyMonDoesIsRoarTakeThis: @ 81F2809
	.string "All my Pokémon does is Roar…\n"
	.string "No one dares to come near me…$"

Route114_Text_ExplainRoar: @ 81F2872
	.string "TM05 contains Roar.\n"
	.string "A Roar sends Pokémon scurrying.$"

Route114_Text_Poochyena: @ 81F28A6
	.string "Bow! Bowwow!$"

Route114_Text_MeteorFallsSign: @ 81F28B3
	.string "Meteor Falls\n"
	.string "RUSTBORO CITY THROUGH HERE$"

Route114_Text_FossilManiacsHouseSign: @ 81F28DB
	.string "Fossil Maniac's House\n"
	.string "“Fossils gratefully accepted!”$"

Route114_Text_LanettesHouse: @ 81F2910
	.string "Lanette's House$"

Route114_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route114_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route114_EventScript_LegendaryNPC_2
	msgbox Route114_EventScript_LegendaryNPC_Text_4, MSGBOX_NPC
Route114_EventScript_LegendaryNPC_1:
	release
	end

Route114_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route114_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_LENNY
	goto_if 1, Route114_EventScript_LegendaryNPC_11
Route114_EventScript_LegendaryNPC_9:
	msgbox Route114_EventScript_LegendaryNPC_Text_3
	goto Route114_EventScript_LegendaryNPC_1

Route114_EventScript_LegendaryNPC_5:
	msgbox Route114_EventScript_LegendaryNPC_Text_1
	goto Route114_EventScript_LegendaryNPC_1

Route114_EventScript_LegendaryNPC_8:
	msgbox Route114_EventScript_LegendaryNPC_Text_2
	goto Route114_EventScript_LegendaryNPC_1

Route114_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_SHANE
	goto_if 1, Route114_EventScript_LegendaryNPC_15
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_LUCAS_1
	goto_if 1, Route114_EventScript_LegendaryNPC_10
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_STEVE_1
	goto_if 1, Route114_EventScript_LegendaryNPC_19
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_NANCY
	goto_if 1, Route114_EventScript_LegendaryNPC_14
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_CLAUDE
	goto_if 1, Route114_EventScript_LegendaryNPC_23
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_BERNIE_1
	goto_if 1, Route114_EventScript_LegendaryNPC_18
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_22:
	checktrainerflag TRAINER_TYRA_AND_IVY
	goto_if 1, Route114_EventScript_LegendaryNPC_27
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_23:
	checktrainerflag TRAINER_NOLAN
	goto_if 1, Route114_EventScript_LegendaryNPC_22
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_26:
	checktrainerflag TRAINER_CHARLOTTE
	goto_if 1, Route114_EventScript_LegendaryNPC_30
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_27:
	checktrainerflag TRAINER_ANGELINA
	goto_if 1, Route114_EventScript_LegendaryNPC_26
	goto Route114_EventScript_LegendaryNPC_9

Route114_EventScript_LegendaryNPC_30:
	checktrainerflag TRAINER_KAI
	goto_if 1, Route114_EventScript_LegendaryNPC_8
	goto Route114_EventScript_LegendaryNPC_9


Route114_EventScript_Feraligatr::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ROUTE114_FERALIGATR, Route114_EventScript_Feraligatr_Join
	goto_if_unset FLAG_BADGE05_GET, Route114_EventScript_Feraligatr_PreNorman
	playmoncry SPECIES_FERALIGATR, 2
	msgbox Route114_EventScript_Feraligatr_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route114_EventScript_Feraligatr_2
	playmoncry SPECIES_FERALIGATR, 2
	msgbox Route114_EventScript_Feraligatr_Text_3, MSGBOX_DEFAULT
Route114_EventScript_Feraligatr_1:
	release
	end

Route114_EventScript_Feraligatr_2:
	playmoncry SPECIES_FERALIGATR, 2
	msgbox Route114_EventScript_Feraligatr_Text_1, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setflag FLAG_TOTEM_BATTLE
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 2
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 1
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_FERALIGATR
	setwildbattlewithcustommoves SPECIES_FERALIGATR, 0, ITEM_FERALIGATRITE_Y, MOVE_HYDRO_CANNON, MOVE_HYPER_BEAM, MOVE_BLIZZARD, MOVE_HYPER_VOICE, 0, NATURE_MODEST, 252, 252, 252, 252, 252, 252
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Route114_EventScript_Feraligatr_6
	case B_OUTCOME_WON, Route114_EventScript_Feraligatr_6
	case B_OUTCOME_RAN, Route114_EventScript_Feraligatr_7
	case B_OUTCOME_PLAYER_TELEPORTED, Route114_EventScript_Feraligatr_7
	goto Route114_EventScript_Feraligatr_1

Route114_EventScript_Feraligatr_6:
	goto Route114_EventScript_Feraligatr_Join
	goto Route114_EventScript_Feraligatr_1

Route114_EventScript_Feraligatr_7:
	setvar VAR_0x8004, SPECIES_FERALIGATR
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox Route114_EventScript_Feraligatr_Text_2, MSGBOX_DEFAULT
	goto Route114_EventScript_Feraligatr_1


Route114_EventScript_Feraligatr_PreNorman::
	message Route114_EventScript_Feraligatr_PreNorman_Text_0
	waitmessage
	release
	end


Route114_EventScript_Feraligatr_Join::
	msgbox Route114_EventScript_Feraligatr_Join_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route114_EventScript_Feraligatr_Join_2
Route114_EventScript_Feraligatr_Join_1:
	goto_if_unset FLAG_DEFEATED_ROUTE114_FERALIGATR, Route114_EventScript_Feraligatr_Join_5
Route114_EventScript_Feraligatr_Join_4:
	release
	end

Route114_EventScript_Feraligatr_Join_2:
	setflag FLAG_OBTAINED_ROUTE114_FERALIGATR
	givecustommon SPECIES_FERALIGATR, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_MODEST, 0, 252, 0, 0, 0, 252, 4, 0, 0, 0, 0, 0, 0, MOVE_HYDRO_CANNON, MOVE_HYPER_BEAM, MOVE_BLIZZARD, MOVE_HYPER_VOICE, FALSE
	playfanfare MUS_OBTAIN_ITEM
	message Route114_EventScript_Feraligatr_Join_Text_1
	waitfanfare
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Route114_EventScript_Feraligatr_Join_1

Route114_EventScript_Feraligatr_Join_5:
	setflag FLAG_DEFEATED_ROUTE114_FERALIGATR
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_FERALIGATRITE_Y, 1
	message Route114_EventScript_Feraligatr_Join_Text_2
	waitfanfare
	goto Route114_EventScript_Feraligatr_Join_4


Route114_EventScript_LegendaryNPC_Text_0:
	.string "Sage: Are you one of those trainers\n"
	.string "trying to become champion?$"

Route114_EventScript_LegendaryNPC_Text_1:
	.string "I assume you want confirmation on the\n"
	.string "fact that legendary Pokémon roam this\l"
	.string "route.\p"
	.string "Rest assured: they do. The Legendary\n"
	.string "beastly trio of Raikou, Suicune and\l"
	.string "Entei\p"
	.string "have chosen these wind-swept lands as\n"
	.string "their lair.\p"
	.string "Should you continue to display such\n"
	.string "promise, the privilege of capturing\l"
	.string "these majestic creatures may fall upon\l"
	.string "you.\p"
	.string "Embrace your burgeoning strength, for\n"
	.string "it may lead you to an extraordinary\l"
	.string "fate.$"

Route114_EventScript_LegendaryNPC_Text_2:
	.string "At last, we meet again. Your prowess in\n"
	.string "battle has been recognized by many,\l"
	.string "including the Beasts. Walk this path\l"
	.string "with your DexNav, and their greatness\l"
	.string "shall be revealed to you.$"

Route114_EventScript_LegendaryNPC_Text_3:
	.string "Ah, an interesting development indeed.\n"
	.string "Your capabilities have surpassed my\l"
	.string "initial expectations. While your\l"
	.string "journey has not yet reached its climax,\l"
	.string "you have shown remarkable potential.\l"
	.string "Your destiny is calling: finish these\l"
	.string "last few battles to finally greet the\l"
	.string "Beasts.$"

Route114_EventScript_LegendaryNPC_Text_4:
	.string "Then why are we even talking?$"

Route114_EventScript_Feraligatr_Text_0:
	.string "With a thunderous roar, Feraligatr\n"
	.string "lunges forward, launching a fierce\l"
	.string "attack against you!$"

Route114_EventScript_Feraligatr_Text_1:
	.string "Feraligatr: Fera!$"

Route114_EventScript_Feraligatr_Text_2:
	.string "The {STR_VAR_1} ran away!$"

Route114_EventScript_Feraligatr_Text_3:
	.string "Feraligatr: Fera...$"

Route114_EventScript_Feraligatr_PreNorman_Text_0:
	.string "Feraligatr regards you with disdain.\n"
	.string "Maybe come back once you've become\l"
	.string "more formidable?{PAUSE_UNTIL_PRESS}$"

Route114_EventScript_Feraligatr_Join_Text_0:
	.string "Feraligatr seems to want to join your\n"
	.string "team, will you let this Feraligatr join\l"
	.string "you?$"

Route114_EventScript_Feraligatr_Join_Text_1:
	.string "{PLAYER} received a Feraligatr!$"

Route114_EventScript_Feraligatr_Join_Text_2:
	.string "{PLAYER} received a Feraligatrite Y!$"
