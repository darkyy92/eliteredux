.set LOCALID_BRINEY, 9
.set LOCALID_WANDAS_BF_OUTSIDE, 17

Route116_MapScripts:: @ 81F2C0C
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition: @ 81F2C1C
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route116_EventScript_SetWandasBoyfriendPos:: @ 81F2C47
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
	return

Route116_OnLoad: @ 81F2C4F
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute116North
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute116South
	end

Route116_OnFrame: @ 81F2C66
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route116_EventScript_WandasBoyfriend:: @ 81F2C70
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntLeftTunnel:: @ 81F2C8E
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntInTunnel:: @ 81F2C98
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_DevonEmployee:: @ 81F2CA2
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveAggroniteAgain
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveAggronite
	end

Route116_EventScript_GiveAggronite:: @ 81F2CBB
	setflag FLAG_MET_DEVON_EMPLOYEE
	givecustommon SPECIES_AGGRON, 30, ITEM_AGGRONITE, ITEM_HEAVY_BALL, NATURE_ADAMANT, 0, 252, 252, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_HEAVY_SLAM, MOVE_ICE_PUNCH, MOVE_SLACK_OFF, MOVE_HIGH_HORSEPOWER, TRUE
	playfanfare MUS_OBTAIN_ITEM
	message Route116_EventScript_Text_Got_Aggron
	waitfanfare
	msgbox Route116_Text_AlsoNeedKeystone, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route116_EventScript_DevonEmployeeExit
	compare VAR_FACING, DIR_SOUTH
	call_if_eq Route116_EventScript_DevonEmployeeExit
	compare VAR_FACING, DIR_WEST
	call_if_eq Route116_EventScript_DevonEmployeeExit
	compare VAR_FACING, DIR_EAST
	call_if_eq Route116_EventScript_DevonEmployeeExitEast
	removeobject VAR_LAST_TALKED
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setflag FLAG_RECEIVED_AGGRONITE
	release
	end

Route116_EventScript_DevonEmployeeExit:: @ 81F2D15
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
	waitmovement 0
	return

Route116_EventScript_DevonEmployeeExitEast:: @ 81F2D20
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
	waitmovement 0
	return

Route116_EventScript_TryGiveAggroniteAgain:: @ 81F2D2B
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveAggronite
	end

Route116_EventScript_NoRoomForAggronite:: @ 81F2D39
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
	release
	end

Route116_Movement_DevonEmployeeExit: @ 81F2D43
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_DevonEmployeeExitEast: @ 81F2D4C
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_RouteSignRustboro:: @ 81F2D57
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route116_EventScript_RusturfTunnelSign:: @ 81F2D60
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

Route116_EventScript_TunnelersRestHouseSign:: @ 81F2D69
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBToStopEvolution:: @ 81F2D72
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBagHasPockets:: @ 81F2D7B
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
	end

Route116_EventScript_Briney:: @ 81F2D84
	lock
	faceplayer
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	release
	end

Route116_EventScript_BrineyTrigger:: @ 81F2D95
	lockall
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	releaseall
	end

Route116_EventScript_GlassesMan:: @ 81F2DB6
	lock
	faceplayer
	checkitem ITEM_BLACK_GLASSES, 1
	compare VAR_RESULT, TRUE
	goto_if_eq Route116_EventScript_PlayerHasGlasses
	specialvar VAR_RESULT, FoundBlackGlasses
	compare VAR_RESULT, TRUE
	goto_if_eq Route116_EventScript_FoundGlassesNotOnPlayer
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesNotOnPlayer:: @ 81F2DE2
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_PlayerHasGlasses:: @ 81F2DF1
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	compare VAR_RESULT, TRUE
	goto_if_eq Route116_EventScript_FoundGlassesOnPlayer
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesOnPlayer:: @ 81F2E1B
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_GlassesManExit:: @ 81F2E2A
	delay 20
	compare VAR_FACING, DIR_NORTH
	call_if_eq Route116_EventScript_GlassesManExitNormal
	compare VAR_FACING, DIR_SOUTH
	call_if_eq Route116_EventScript_GlassesManExitNormal
	compare VAR_FACING, DIR_WEST
	call_if_eq Route116_EventScript_GlassesManExitNormal
	compare VAR_FACING, DIR_EAST
	call_if_eq Route116_EventScript_GlassesManExitEast
	removeobject VAR_LAST_TALKED
	release
	end

Route116_EventScript_GlassesManExitNormal:: @ 81F2E5E
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
	waitmovement 0
	return

Route116_EventScript_GlassesManExitEast:: @ 81F2E69
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
	waitmovement 0
	return

Route116_Movement_GlassesManExit: @ 81F2E74
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_GlassesManExitEast: @ 81F2E7E
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_Joey:: @ 81F2E89
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jose:: @ 81F2EA0
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jerry:: @ 81F2EB7
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route116_EventScript_RematchJerry
	setvar VAR_0x8004, TRAINER_JERRY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route116_EventScript_TryRegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterJerryAfterBattle:: @ 81F2EF8
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
	release
	end

Route116_EventScript_RegisterJerryAfterBattle:: @ 81F2F03
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_TryRegisterJerry:: @ 81F2F22
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterJerry:: @ 81F2F35
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_RematchJerry:: @ 81F2F4E
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Clark:: @ 81F2F65
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Janice:: @ 81F2F7C
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Karen:: @ 81F2F93
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route116_EventScript_RematchKaren
	setvar VAR_0x8004, TRAINER_KAREN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq Route116_EventScript_TryRegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterKarenAfterBattle:: @ 81F2FD4
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
	release
	end

Route116_EventScript_RegisterKarenAfterBattle:: @ 81F2FDF
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_TryRegisterKaren:: @ 81F2FFE
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterKaren:: @ 81F3011
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_RematchKaren:: @ 81F302A
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Sarah:: @ 81F3041
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Dawson:: @ 81F3058
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Devan:: @ 81F306F
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Johnson:: @ 81F3086
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_Text_ScoundrelMadeOffWithPeeko: @ 81F309D
	.string "Ohhh, what am I to do?\p"
	.string "We were on our walk, Peeko and I, when\n"
	.string "we were jumped by an odd thug…\p"
	.string "The scoundrel made off with my\n"
	.string "darling Peeko!\p"
	.string "Wrrrooooooaaaar! Peeko!$"

Route116_Text_WantToDigTunnel: @ 81F3140
	.string "Nnn… Roar!\p"
	.string "I want to dig that tunnel!$"

Route116_Text_DiggingTunnelWhenGoonOrderedMeOut: @ 81F3166
	.string "Nnn… Roar!\n"
	.string "What's going on?\p"
	.string "I was digging the tunnel without any\n"
	.string "tools when some goon ordered me out!\p"
	.string "That tunnel's filled with Pokémon\n"
	.string "that react badly to loud noises.\l"
	.string "They could cause an uproar.\p"
	.string "That's why we stopped using heavy\n"
	.string "equipment for tunneling…\p"
	.string "I'm worried that the goon will do\n"
	.string "something stupid and startle the\l"
	.string "Pokémon into an uproar.$"

Route116_Text_GoonHightailedItOutOfTunnel: @ 81F32C1
	.string "Nnn… Roar!\p"
	.string "That goofy goon hightailed it out of\n"
	.string "the tunnel! I can go back to digging!$"

Route116_Text_ThankYouTokenOfAppreciation: @ 81F3317
	.string "Oh! It's you!\p"
	.string "You're that person who not only helped\n"
	.string "me in Petalburg Woods, but also got\l"
	.string "back my stolen package and then even\l"
	.string "graciously delivered it to Slateport!\p"
	.string "Capt. Stern informed us that the\n"
	.string "package arrived, too!\p"
	.string "I thank you very, very much!\p"
	.string "Why, if I were a rain cloud, I would\n"
	.string "shower you with gratitude and hail\l"
	.string "you as a hero!\p"
	.string "For you, the most wonderful Trainer,\n"
	.string "I bear a gift!\p"
	.string "This is an Aggron, holding an\n"
	.string "Aggronite to Mega Evolve in battle.\p"
	.string "As a token of our appreciation, this\n"
	.string "is our gift to our wonderful Trainer!$"

Route116_Text_AlsoNeedKeystone: @ 81F3521
	.string "You'll also need a Keystone to use\n"
	.string "it, but I bet you already knew that!\p"
	.string "Please do try it out!\n"
	.string "Thank you and bye-bye!$"

Route116_Text_BagIsJamPacked: @ 81F3593
	.string "Your Bag is jam-packed.\n"
	.string "I can't give you this Aggronite.$"

Route116_Text_TokenOfAppreciation: @ 81F35CE
	.string "As a token of our appreciation for\n"
	.string "your delivering our package, I have\l"
	.string "a gift of a Mega Stone for our most\l"
	.string "wonderful Trainer!$"

Route116_Text_CanYouHelpMeFindGlasses: @ 81F3657
	.string "I dropped my glasses…\n"
	.string "Can you help me find them?$"

Route116_Text_MayISeeThoseGlasses: @ 81F3688
	.string "Those glasses!\n"
	.string "May I see them for a second?$"

Route116_Text_NotWhatImLookingForMaybeTheyArentHere: @ 81F36B4
	.string "Hmm…\n"
	.string "These are BlackGlasses.\l"
	.string "They're not what I'm looking for…\p"
	.string "Maybe my glasses aren't around\n"
	.string "here…$"

Route116_Text_CantFindGlassesNotHere: @ 81F3718
	.string "Hmm…\n"
	.string "I can't find my glasses anywhere…\l"
	.string "Maybe they're not around here…$"

Route116_Text_NotWhatImLookingFor: @ 81F375E
	.string "Hmm…\n"
	.string "These are BlackGlasses.\l"
	.string "They're not what I'm looking for…$"

Route116_Text_RouteSignRustboro: @ 81F379D
	.string "Route 116\n"
	.string "{LEFT_ARROW} Rustboro City$"

Route116_Text_RusturfTunnelSign: @ 81F37B7
	.string "Rusturf Tunnel\n"
	.string "“Linking Rustboro and Verdanturf\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

Route116_Text_TunnelersRestHouse: @ 81F380F
	.string "Tunneler's Rest House$"

Route116_Text_TrainerTipsBToStopEvolution: @ 81F3825
	.string "Trainer Tips\p"
	.string "If you want to stop a Pokémon from\n"
	.string "evolving, press the B Button while it\l"
	.string "is trying to evolve.\l"
	.string "The startled Pokémon will stop.\p"
	.string "This is called an evolution cancel.$"

Route116_Text_TrainerTipsBagHasPockets: @ 81F38D4
	.string "Trainer Tips\p"
	.string "Your Bag has several Pockets.\p"
	.string "Items you obtain are automatically\n"
	.string "placed in the appropriate Pockets.\p"
	.string "No Trainer can afford to be without\n"
	.string "a Bag of their own.$"

Route116_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route116_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_LegendaryNPC_2
	msgbox Route116_EventScript_LegendaryNPC_Text_4
Route116_EventScript_LegendaryNPC_1:
	release
	end

Route116_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route116_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_JOEY
	goto_if 1, Route116_EventScript_LegendaryNPC_11
Route116_EventScript_LegendaryNPC_9:
	msgbox Route116_EventScript_LegendaryNPC_Text_3
	goto Route116_EventScript_LegendaryNPC_1

Route116_EventScript_LegendaryNPC_5:
	msgbox Route116_EventScript_LegendaryNPC_Text_1
	goto Route116_EventScript_LegendaryNPC_1

Route116_EventScript_LegendaryNPC_8:
	msgbox Route116_EventScript_LegendaryNPC_Text_2
	goto Route116_EventScript_LegendaryNPC_1

Route116_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_JERRY_1
	goto_if 1, Route116_EventScript_LegendaryNPC_15
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_JOSE
	goto_if 1, Route116_EventScript_LegendaryNPC_10
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_JANICE
	goto_if 1, Route116_EventScript_LegendaryNPC_19
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_CLARK
	goto_if 1, Route116_EventScript_LegendaryNPC_14
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_SARAH
	goto_if 1, Route116_EventScript_LegendaryNPC_23
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_KAREN_1
	goto_if 1, Route116_EventScript_LegendaryNPC_18
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_22:
	checktrainerflag TRAINER_DEVAN
	goto_if 1, Route116_EventScript_LegendaryNPC_26
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_23:
	checktrainerflag TRAINER_DAWSON
	goto_if 1, Route116_EventScript_LegendaryNPC_22
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_26:
	checktrainerflag TRAINER_JOHNSON
	goto_if 1, Route116_EventScript_LegendaryNPC_8
	goto Route116_EventScript_LegendaryNPC_9


Route116_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_JOEY
	goto_if 1, Route116_EventScript_Gen8_NPC_5
Route116_EventScript_Gen8_NPC_3:
	msgbox Route116_EventScript_Gen8_NPC_Text_2
Route116_EventScript_Gen8_NPC_1:
	release
	end

Route116_EventScript_Gen8_NPC_2:
	msgbox Route116_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_FARFETCHD_GALARIAN, 10, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message Route116_EventScript_Gen8_NPC_Text_1
	waitfanfare
	goto Route116_EventScript_Gen8_NPC_1

Route116_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_JERRY_1
	goto_if 1, Route116_EventScript_Gen8_NPC_9
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_5:
	checktrainerflag TRAINER_JOSE
	goto_if 1, Route116_EventScript_Gen8_NPC_4
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_8:
	checktrainerflag TRAINER_JANICE
	goto_if 1, Route116_EventScript_Gen8_NPC_13
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_9:
	checktrainerflag TRAINER_CLARK
	goto_if 1, Route116_EventScript_Gen8_NPC_8
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_12:
	checktrainerflag TRAINER_SARAH
	goto_if 1, Route116_EventScript_Gen8_NPC_17
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_13:
	checktrainerflag TRAINER_KAREN_1
	goto_if 1, Route116_EventScript_Gen8_NPC_12
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_16:
	checktrainerflag TRAINER_DEVAN
	goto_if 1, Route116_EventScript_Gen8_NPC_20
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_17:
	checktrainerflag TRAINER_DAWSON
	goto_if 1, Route116_EventScript_Gen8_NPC_16
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_20:
	checktrainerflag TRAINER_JOHNSON
	goto_if 1, Route116_EventScript_Gen8_NPC_2
	goto Route116_EventScript_Gen8_NPC_3


Route116_EventScript_MegaNidos_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, Route116_EventScript_MegaNidos_Battle_2
	msgbox Route116_EventScript_MegaNidos_Battle_Text_6, MSGBOX_NPC
Route116_EventScript_MegaNidos_Battle_1:
	release
	end

Route116_EventScript_MegaNidos_Battle_2:
	checktrainerflag TRAINER_NIDO_MEGAS_ROUTE116_RUSTURF
	goto_if 0, Route116_EventScript_MegaNidos_Battle_5
	msgbox Route116_EventScript_MegaNidos_Battle_Text_5, MSGBOX_NPC
	goto Route116_EventScript_MegaNidos_Battle_1

Route116_EventScript_MegaNidos_Battle_5:
	msgbox Route116_EventScript_MegaNidos_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_MegaNidos_Battle_8
	msgbox Route116_EventScript_MegaNidos_Battle_Text_4, MSGBOX_NPC
	goto Route116_EventScript_MegaNidos_Battle_1

Route116_EventScript_MegaNidos_Battle_8:
	msgbox Route116_EventScript_MegaNidos_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_NIDO_MEGAS_ROUTE116_RUSTURF, Route116_EventScript_MegaNidos_Battle_Text_2
	msgbox Route116_EventScript_MegaNidos_Battle_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_NIDOKINGITE, 1
	giveitem ITEM_NIDOQUEENITE, 1
	waitmessage
	goto Route116_EventScript_MegaNidos_Battle_1


Route116_EventScript_LegendaryNPC_Text_0:
	.string "Sage: Despite your young age, you\n"
	.string "appear to be someone who seeks a\l"
	.string "profound significance in everyday\l"
	.string "matters... Am I right?$"

Route116_EventScript_LegendaryNPC_Text_1:
	.string "Of course... young trainer, I sense your\n"
	.string "curiosity for the extraordinary. But\l"
	.string "beware, for you tread on sacred\l"
	.string "grounds. The presence of the legendary\l"
	.string "Creation Trio looms over this place.\l"
	.string "They seek a guardian who can commune\l"
	.string "with their power, but you don't seem\l"
	.string "ready yet. Come back once you've\l"
	.string "accomplished an exceptional feat in\l"
	.string "the Pokémon League.$"

Route116_EventScript_LegendaryNPC_Text_2:
	.string "Ah, young trainer, your potential shines\n"
	.string "through the shadows like a glimmering\l"
	.string "light. I can sense it: the Creation Trio\l"
	.string "has deemed you worthy of their time.\l"
	.string "Use your DexNav to meet them.$"

Route116_EventScript_LegendaryNPC_Text_3:
	.string "You are almost worthy. Defeat all\n"
	.string "remaining trainers to prove your might\l"
	.string "once and for all!$"

Route116_EventScript_LegendaryNPC_Text_4:
	.string "You had so much potential... how\n"
	.string "disappointing.$"

Route116_EventScript_Gen8_NPC_Text_0:
	.string "Take this Pokémon from Galar. You can\n"
	.string "have as many of them as you like!$"

Route116_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got a {COLOR BLUE}Galarian Farfetch'd{COLOR DARK_GRAY} as\n"
	.string "a gift for defeating every trainer\l"
	.string "here!$"

Route116_EventScript_Gen8_NPC_Text_2:
	.string "If you can beat all trainers here, I will\n"
	.string "give you an exotic Pokémon from the\l"
	.string "Galar region: a valiant wielder of\l"
	.string "longswords!$"

Route116_EventScript_MegaNidos_Battle_Text_0:
	.string "Hah! Look at you. Hey, pleb. I'm bored, so\n"
	.string "have a battle with me. I'll even give\l"
	.string "you a reward if you do!$"

Route116_EventScript_MegaNidos_Battle_Text_1:
	.string "Then let us begin.$"

Route116_EventScript_MegaNidos_Battle_Text_2:
	.string "What? How?$"

Route116_EventScript_MegaNidos_Battle_Text_3:
	.string "Unbelievable. Me, losing to the likes of\n"
	.string "you? Well, a promise is a promise. Take\l"
	.string "these stones and get out of my sight.$"

Route116_EventScript_MegaNidos_Battle_Text_4:
	.string "No? Tsk. I should've expected as much\n"
	.string "from someone like you.$"

Route116_EventScript_MegaNidos_Battle_Text_5:
	.string "Didn't I tell you to get out of my sight?$"

Route116_EventScript_MegaNidos_Battle_Text_6:
	.string "You aren't worthy enough to talk to me.\n"
	.string "A peasant like you who hasn't even\l"
	.string "beat Winona has no business here.$"

Route116_EventScript_Text_Got_Aggron::
	.string "{PLAYER} got an {COLOR BLUE}Aggron{COLOR DARK_GRAY} as a gift!$"
