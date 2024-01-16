.set LOCALID_STEVEN, 19

Route118_MapScripts:: @ 81F3DBC
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
	.byte 0

Route118_OnTransition: @ 81F3DCC
	call GabbyAndTy_EventScript_UpdateLocation
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route118_OnLoad: @ 81F3DF3
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute118East
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute118West
	end

Route118_OnFrame: @ 81F3E0A
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route114_EventScript_GoodRodFisherman:: @ 81F3E14
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route118_EventScript_ReceiveGoodRod
	compare VAR_RESULT, NO
	goto_if_eq Route118_EventScript_DeclineGoodRod
	end

Route118_EventScript_ReceiveGoodRod:: @ 81F3E3E
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_DeclineGoodRod:: @ 81F3E5F
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ReceivedGoodRod:: @ 81F3E69
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl:: @ 81F3E73
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Route118_EventScript_RouteSignMauville:: @ 81F3E7C
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route118_EventScript_RouteSign119:: @ 81F3E85
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end

Route118_EventScript_StevenExit0:: @ 81F3F28
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
	waitmovement 0
	return

Route118_EventScript_StevenExit1:: @ 81F3F3A
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	waitmovement 0
	return

Route118_EventScript_StevenExit2:: @ 81F3F4C
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
	waitmovement 0
	return

Route118_Movement_PlayerWatchStevenExit: @ 81F3F5E
	delay_16
	walk_in_place_fastest_right
	step_end

Route118_Movement_StevenApproachLedge0: @ 81F3F61
	walk_left
	step_end

Route118_Movement_StevenApproachLedge2: @ 81F3F63
	walk_right
	step_end

Route118_Movement_StevenJumpLedge: @ 81F3F65
	jump_2_down
	delay_16
	walk_down
	step_end

Route118_Movement_StevenExit0: @ 81F3F69
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit1: @ 81F3F74
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_Movement_StevenExit2: @ 81F3F7E
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route118_EventScript_Rose:: @ 81F3F87
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route118_EventScript_RematchRose
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterRose:: @ 81F3FB3
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROSE_1
	release
	end

Route118_EventScript_RematchRose:: @ 81F3FD2
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Barny:: @ 81F3FE9
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Wade:: @ 81F4000
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Dalton:: @ 81F4017
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route118_EventScript_RematchDalton
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_RegisterDalton:: @ 81F4043
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DALTON_1
	release
	end

Route118_EventScript_RematchDalton:: @ 81F4062
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Perry:: @ 81F4079
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Chester:: @ 81F4090
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route118_EventScript_Deandre:: @ 81F40A7
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Route114_EventScript_MagikarpGuy::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE118_GYARADOSITE, Route118_EventScript_ReceivedGyaradosite
	msgbox Route118_Text_DoYouLiekKarp, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route118_EventScript_ILuurveKarp
	compare VAR_RESULT, NO
	goto_if_eq Route118_EventScript_DontLikeKarp
	release
	end

Route118_EventScript_ReceivedGyaradosite::
	msgbox Route118_Text_KarpBetterThanGyara, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_ILuurveKarp::
	msgbox Route118_Text_ILuurveKarp, MSGBOX_DEFAULT
	closemessage
	msgbox Route118_Text_ReadyForKarpFite, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route118_EventScript_CheckParty
	release
	end

Route118_EventScript_DontLikeKarp::
	msgbox Route118_Text_DontLikeKarp, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_CheckParty::
	specialvar VAR_RESULT, CheckMagikarpBattle
	compare VAR_RESULT, FALSE
	goto_if_eq Route118_EventScript_NeedMoreKarp
	msgbox Route118_Text_KarpFiteStart, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAGIKARP_GUY, Route118_Text_MagikarpDefeat
	msgbox Route118_Text_TakeGyaradosite, MSGBOX_DEFAULT
	givecustommon SPECIES_MAGIKARP, 55, ITEM_GYARADOSITE, ITEM_CHERISH_BALL, NATURE_NAIVE, 0, 0, 252, 4, 252, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_V_CREATE, MOVE_DRAGON_ASCENT, MOVE_WICKED_BLOW, MOVE_CORE_ENFORCER, TRUE
	playfanfare MUS_OBTAIN_ITEM
	message Route118_EventScript_Text_Got_Magikarp
	waitfanfare
	setflag FLAG_ROUTE118_GYARADOSITE
	msgbox Route118_Text_KarpBetterThanGyara, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_NeedMoreKarp::
	msgbox Route118_Text_NeedMoreKarp, MSGBOX_DEFAULT
	release
	end

Route118_Text_DoYouLiekKarp:
	.string "Do you like the Pokémon Magikarp?$"

Route118_Text_DontLikeKarp:
	.string "Oh… That's disappointing.\n"
	.string "I was hoping you were a fellow\l"
	.string "Magikarp aficionado…$"

Route118_Text_ILuurveKarp:
	.string "You do?!\n"
	.string "That's great!\p"
	.string "Not many people appreciate the true\n"
	.string "majesty of Magikarp…\p"
	.string "Oh, I know! If you can show me you\n"
	.string "truly love Magikarp, I'll give you this\l"
	.string "special Pokémon I found!\p"
	.string "Here's what I want you to do…\p"
	.string "You must defeat my team of Magikarp\n"
	.string "all stars…\p"
	.string "With your own team of Magikarp!$"

Route118_Text_ReadyForKarpFite:
	.string "So, are you ready for our magical\n"
	.string "showdown?$"

Route118_Text_NeedMoreKarp:
	.string "Hmm… You don't have enough Magikarp\n"
	.string "to challenge me.\p"
	.string "Please come back once you've fished up\n"
	.string "a full team of them!$"

Route118_Text_KarpFiteStart:
	.string "Oho! Then let us begin!$"

Route118_Text_MagikarpDefeat:
	.string "Ah! Your love for Magikarp is clear!$"

Route118_Text_TakeGyaradosite:
	.string "Here, take this special Magikarp.\n"
	.string "You earned it!$"

Route118_Text_KarpBetterThanGyara:
	.string "Gyarados might not be Magikarp, but\n"
	.string "it's almost as good!$"

Route118_Text_StevenQuestions: @ 81F40BE
	.string "Steven: Hi, {PLAYER}{KUN}!\p"
	.string "It's me, Steven!\n"
	.string "We met in the cave near Dewford.\p"
	.string "Have you met many kinds of Pokémon\n"
	.string "since I last saw you?\p"
	.string "There are many, many kinds of Pokémon\n"
	.string "in this wide world of ours.\p"
	.string "If you wanted to raise only your\n"
	.string "favorites, that's fine.\p"
	.string "Perhaps you find it more fun to raise\n"
	.string "all sorts of Pokémon.\p"
	.string "As a Trainer of Pokémon,\n"
	.string "what do you think?\p"
	.string "Of course, it's not any of my business.\p"
	.string "It would be nice if we were to meet\n"
	.string "again somewhere.$"

Route118_Text_YouAgreeGoodRodIsGood: @ 81F427B
	.string "Hmm!\n"
	.string "A Good Rod is really good!\p"
	.string "Wouldn't you agree?$"

Route118_Text_IdenticalMindsTakeThis: @ 81F42AF
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this Good Rod!$"

Route118_Text_TryYourLuckFishing: @ 81F42E7
	.string "Wherever there's water, try your luck\n"
	.string "at fishing.$"

Route118_Text_DontYouLikeToFish: @ 81F4319
	.string "Don't you like to fish?$"

Route118_Text_TryCatchingMonWithGoodRod: @ 81F4331
	.string "Try catching all sorts of Pokémon\n"
	.string "with your Good Rod.$"

Route118_Text_CanCrossRiversWithSurf: @ 81F4367
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a Pokémon that knows Surf.\p"
	.string "Pokémon can be counted on to do so\n"
	.string "much!$"

Route118_Text_RouteSignMauville: @ 81F43F4
	.string "Route 118\n"
	.string "{LEFT_ARROW} Mauville City$"

Route118_Text_RouteSign119: @ 81F440E
	.string "Route 118\n"
	.string "{UP_ARROW} Route 119$"

Route118_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route118_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route118_EventScript_LegendaryNPC_2
	msgbox Route118_EventScript_LegendaryNPC_Text_4
Route118_EventScript_LegendaryNPC_1:
	release
	end

Route118_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route118_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_ROSE_1
	goto_if 1, Route118_EventScript_LegendaryNPC_11
Route118_EventScript_LegendaryNPC_9:
	msgbox Route118_EventScript_LegendaryNPC_Text_3
	goto Route118_EventScript_LegendaryNPC_1

Route118_EventScript_LegendaryNPC_5:
	msgbox Route118_EventScript_LegendaryNPC_Text_1
	goto Route118_EventScript_LegendaryNPC_1

Route118_EventScript_LegendaryNPC_8:
	msgbox Route118_EventScript_LegendaryNPC_Text_2
	goto Route118_EventScript_LegendaryNPC_1

Route118_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_WADE
	goto_if 1, Route118_EventScript_LegendaryNPC_15
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_BARNY
	goto_if 1, Route118_EventScript_LegendaryNPC_10
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_PERRY
	goto_if 1, Route118_EventScript_LegendaryNPC_19
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_DALTON_1
	goto_if 1, Route118_EventScript_LegendaryNPC_14
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_DEANDRE
	goto_if 1, Route118_EventScript_LegendaryNPC_8
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_CHESTER
	goto_if 1, Route118_EventScript_LegendaryNPC_18
	goto Route118_EventScript_LegendaryNPC_9


Route118West_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_ROSE_1
	goto_if 1, Route118West_EventScript_Gen8_NPC_5
Route118West_EventScript_Gen8_NPC_3:
	msgbox Route118West_EventScript_Gen8_NPC_Text_2
Route118West_EventScript_Gen8_NPC_1:
	release
	end

Route118West_EventScript_Gen8_NPC_2:
	msgbox Route118West_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_HATENNA, 10, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message Route118West_EventScript_Gen8_NPC_Text_1
	waitfanfare
	goto Route118West_EventScript_Gen8_NPC_1

Route118West_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_DALTON_1
	goto_if 1, Route118West_EventScript_Gen8_NPC_8
	goto Route118West_EventScript_Gen8_NPC_3

Route118West_EventScript_Gen8_NPC_5:
	checktrainerflag TRAINER_WADE
	goto_if 1, Route118West_EventScript_Gen8_NPC_4
	goto Route118West_EventScript_Gen8_NPC_3

Route118West_EventScript_Gen8_NPC_8:
	checktrainerflag TRAINER_DEANDRE
	goto_if 1, Route118West_EventScript_Gen8_NPC_2
	goto Route118West_EventScript_Gen8_NPC_3


Route118East_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_BARNY
	goto_if 1, Route118East_EventScript_Gen8_NPC_5
Route118East_EventScript_Gen8_NPC_3:
	msgbox Route118East_EventScript_Gen8_NPC_Text_2
Route118East_EventScript_Gen8_NPC_1:
	release
	end

Route118East_EventScript_Gen8_NPC_2:
	msgbox Route118East_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_DRACOZOLT, 50, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message Route118East_EventScript_Gen8_NPC_Text_1
	waitfanfare
	goto Route118East_EventScript_Gen8_NPC_1

Route118East_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_CHESTER
	goto_if 1, Route118East_EventScript_Gen8_NPC_2
	goto Route118East_EventScript_Gen8_NPC_3

Route118East_EventScript_Gen8_NPC_5:
	checktrainerflag TRAINER_PERRY
	goto_if 1, Route118East_EventScript_Gen8_NPC_4
	goto Route118East_EventScript_Gen8_NPC_3


Route118_EventScript_StevenTrigger0::
	lockall
	setvar VAR_0x8008, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge0
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end


Route118_EventScript_StevenTrigger1::
	lockall
	setvar VAR_0x8008, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end


Route118_EventScript_StevenTrigger2::
	lockall
	setvar VAR_0x8008, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge2
	waitmovement 0
	goto Route118_EventScript_StevenTrigger
	end


Route118_EventScript_StevenTrigger::
	playse SE_LEDGE
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
	waitmovement 0
	delay 30
	msgbox Route118_EventScript_StevenTrigger_Text_0, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN_ROUTE118, Route118_EventScript_StevenTrigger_Text_1
	msgbox Route118_EventScript_StevenTrigger_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
	switch VAR_0x8008
	case 0, Route118_EventScript_StevenTrigger_3
	case 1, Route118_EventScript_StevenTrigger_4
	case 2, Route118_EventScript_StevenTrigger_5
Route118_EventScript_StevenTrigger_1:
	waitmovement 0
	setvar VAR_ROUTE118_STATE, 1
	removeobject LOCALID_STEVEN
	releaseall
	end

Route118_EventScript_StevenTrigger_3:
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
	goto Route118_EventScript_StevenTrigger_1

Route118_EventScript_StevenTrigger_4:
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	goto Route118_EventScript_StevenTrigger_1

Route118_EventScript_StevenTrigger_5:
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
	goto Route118_EventScript_StevenTrigger_1


Route118_EventScript_LegendaryNPC_Text_0:
	.string "Sage: The world we live truly is a thing\n"
	.string "of beauty. Do you agree?$"

Route118_EventScript_LegendaryNPC_Text_1:
	.string "How could you not? But I'll tell you\n"
	.string "more. This land we stand on is blessed\l"
	.string "by the presence of the Stewards of\l"
	.string "nature: Manaphy, the sea guardian,\l"
	.string "Phione, their offspring, and Celebi, the\l"
	.string "time travelling wild spirit.\p"
	.string "Remember, as you explore, to remain in\n"
	.string "harmony with nature, treating every\l"
	.string "blade of grass, every little crevace,\l"
	.string "every grain of sand as if it was your\l"
	.string "dearest treasure.\p"
	.string "If you want to meet these angelic\n"
	.string "guardians, become Champion and come\l"
	.string "back to this sacred place.$"

Route118_EventScript_LegendaryNPC_Text_2:
	.string "Your skills in battle have been tested,\n"
	.string "and you have succeded against all\l"
	.string "odds. Congratulations. Use your DexNav\l"
	.string "to finally meet these extraordinary\l"
	.string "protectors.$"

Route118_EventScript_LegendaryNPC_Text_3:
	.string "You have defeated the Pokémon\n"
	.string "League... and the champion too? I'm\l"
	.string "impressed, and the guardians of this\l"
	.string "place are, too. Once you'll have\l"
	.string "defeated these last few trainers,\l"
	.string "nothing will stand between you and\l"
	.string "them!$"

Route118_EventScript_LegendaryNPC_Text_4:
	.string "Your opinion disgusts me. Go away,\n"
	.string "you've made a fool out of yourself.$"

Route118West_EventScript_Gen8_NPC_Text_0:
	.string "Cute might not be the word that best\n"
	.string "describes your battling... but I liked\l"
	.string "it! Here, take this!$"

Route118West_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got a {COLOR BLUE}Hatenna{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer at the beach!$"

Route118West_EventScript_Gen8_NPC_Text_2:
	.string "Have you ever heard the expression\n"
	.string "'cute and deadly'? I have a Pokémon\l"
	.string "here that fits that description to a\l"
	.string "tee! Show your cuteness in battle to\l"
	.string "receive it!$"

Route118East_EventScript_Gen8_NPC_Text_0:
	.string "Here, take it and don't tell anyone!$"

Route118East_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got a {COLOR BLUE}Dracozolt{COLOR DARK_GRAY} as a gift\n"
	.string "for defeating the three regular\l"
	.string "trainers here!$"

Route118East_EventScript_Gen8_NPC_Text_2:
	.string "If you can beat all three regular\n"
	.string "trainers at the east side of this\l"
	.string "route, I will give you this fossil I\l"
	.string "stole from school!$"

Route118_EventScript_StevenTrigger_Text_0:
	.string "Steven: Hi, {PLAYER}{KUN} I hope you're\n"
	.string "ready. I upgraded my team after you\l"
	.string "defeated me last time...$"

Route118_EventScript_StevenTrigger_Text_1:
	.string "You still have great potential.$"

Route118_EventScript_StevenTrigger_Text_2:
	.string "Steven: I knew I wasn't the only one\n"
	.string "who upgraded his team. I hope we meet\l"
	.string "again.$"

Route118_EventScript_Text_Got_Magikarp::
	.string "{PLAYER} got a {COLOR BLUE}Magikarp{COLOR DARK_GRAY} as a gift!$"
