.set LOCALID_STEVEN, 3
.set LOCALID_ARCHIE, 4
.set LOCALID_MAXIE, 5

Route128_MapScripts:: @ 81F6B38
	map_script MAP_SCRIPT_ON_TRANSITION, Route128_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route128_OnFrame
	.byte 0

Route128_OnTransition: @ 81F6B43
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route128_OnFrame: @ 81F6B4D
	map_script_2 VAR_ROUTE128_STATE, 1, Route128_EventScript_KyogreAwakenedScene
	.2byte 0

Route128_EventScript_KyogreAwakenedScene:: @ 81F6B57
	lockall
	delay 20
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieLookAround
	waitmovement 0
	msgbox Route128_Text_ArchieWhatHappened, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieBackUp
	waitmovement 0
	msgbox Route128_Text_ArchieIOnlyWanted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieApproachArchie
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_MaxieDoYouUnderstandNow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_MaxieResposibilityFallsToArchieAndMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieRunLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieWalkLeft
	waitmovement 0
	msgbox Route128_Text_MaxieThisDefiesBelief, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieExit
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieExit
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_ARCHIE
	delay 100
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	waitfieldeffect FLDEFF_NPCFLY_OUT
	addobject LOCALID_STEVEN
	applymovement LOCALID_STEVEN, Route128_Movement_StevenApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox Route128_Text_StevenWhatIsHappening, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Route128_Movement_StevenWalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox Route128_Text_StevenWholeWorldWillDrown, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route128_Text_StevenImGoingToSootopolis, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_STEVEN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE128_STATE, 2
	releaseall
	end

Route128_Movement_Unused1: @ 81F6C76
	walk_fast_left
	step_end

Route128_Movement_Unused2: @ 81F6C78
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route128_Movement_StevenWalkUp: @ 81F6C85
	walk_up
	step_end

Route128_Movement_StevenApproachPlayer: @ 81F6C87
	walk_fast_left
	step_end

Route128_Movement_ArchieLookAround: @ 81F6C89
	walk_fast_down
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

Route128_Movement_ArchieBackUp: @ 81F6C91
	lock_facing_direction
	walk_slow_up
	delay_16
	unlock_facing_direction
	step_end

Route128_Movement_ArchieRunLeft: @ 81F6C96
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_fastest_right
	step_end

Route128_Movement_ArchieExit: @ 81F6C9B
	delay_16
	delay_16
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_MaxieWalkLeft: @ 81F6CA8
	walk_left
	walk_left
	delay_8
	delay_4
	step_end

Route128_Movement_MaxieApproachArchie: @ 81F6CAD
	walk_left
	walk_in_place_fastest_down
	step_end

Route128_Movement_MaxieExit: @ 81F6CB0
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route128_Movement_MaxieApproachPlayer: @ 81F6CBB
	walk_right
	walk_in_place_fastest_down
	step_end

Route128_EventScript_Isaiah:: @ 81F6CBE
	trainerbattle_single TRAINER_ISAIAH_1, Route128_Text_IsaiahIntro, Route128_Text_IsaiahDefeat, Route128_EventScript_RegisterIsaiah
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route128_EventScript_RematchIsaiah
	msgbox Route128_Text_IsaiahPostBattle, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_RegisterIsaiah:: @ 81F6CEA
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route128_Text_IsaiahRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAIAH_1
	release
	end

Route128_EventScript_RematchIsaiah:: @ 81F6D09
	trainerbattle_rematch TRAINER_ISAIAH_1, Route128_Text_IsaiahRematchIntro, Route128_Text_IsaiahRematchDefeat
	msgbox Route128_Text_IsaiahPostRematch, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Katelyn:: @ 81F6D20
	trainerbattle_single TRAINER_KATELYN_1, Route128_Text_KatelynIntro, Route128_Text_KatelynDefeat, Route128_EventScript_RegisterKatelyn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route128_EventScript_RematchKatelyn
	msgbox Route128_Text_KatelynPostBattle, MSGBOX_DEFAULT
	release
	end

Route128_EventScript_RegisterKatelyn:: @ 81F6D4C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route128_Text_KatelynRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KATELYN_1
	release
	end

Route128_EventScript_RematchKatelyn:: @ 81F6D6B
	trainerbattle_rematch TRAINER_KATELYN_1, Route128_Text_KatelynRematchIntro, Route128_Text_KatelynRematchDefeat
	msgbox Route128_Text_KatelynPostRematch, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Alexa:: @ 81F6D82
	trainerbattle_single TRAINER_ALEXA, Route128_Text_AlexaIntro, Route128_Text_AlexaDefeat
	msgbox Route128_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Ruben:: @ 81F6D99
	trainerbattle_single TRAINER_RUBEN, Route128_Text_RubenIntro, Route128_Text_RubenDefeat
	msgbox Route128_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Wayne:: @ 81F6DB0
	trainerbattle_single TRAINER_WAYNE, Route128_Text_WayneIntro, Route128_Text_WayneDefeat
	msgbox Route128_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Harrison:: @ 81F6DC7
	trainerbattle_single TRAINER_HARRISON, Route128_Text_HarrisonIntro, Route128_Text_HarrisonDefeat
	msgbox Route128_Text_HarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

Route128_EventScript_Carlee:: @ 81F6DDE
	trainerbattle_single TRAINER_CARLEE, Route128_Text_CarleeIntro, Route128_Text_CarleeDefeat
	msgbox Route128_Text_CarleePostBattle, MSGBOX_AUTOCLOSE
	end

Route128_Text_ArchieWhatHappened: @ 81F6DF5
	.string "Archie: What happened…\n"
	.string "What is this wretched scene…\p"
	.string "Did I…make a horrible mistake?$"

Route128_Text_ArchieIOnlyWanted: @ 81F6E48
	.string "I…\n"
	.string "I only wanted…$"

Route128_Text_MaxieDoYouUnderstandNow: @ 81F6E5A
	.string "Maxie: Do you understand now,\n"
	.string "Archie?\p"
	.string "Do you finally see how disastrous\n"
	.string "your dream turned out to be?\p"
	.string "We have to hurry! We have to do\n"
	.string "something before the situation goes\l"
	.string "completely out of control!$"

Route128_Text_MaxieResposibilityFallsToArchieAndMe: @ 81F6F1E
	.string "Maxie: {PLAYER}, don't say anything.\p"
	.string "I know that I have no right to be\n"
	.string "critical of Archie…\p"
	.string "But the way things are now, I doubt\n"
	.string "that we humans will be capable of\l"
	.string "doing anything about it.\p"
	.string "But neither can we stand by and\n"
	.string "just watch helplessly.\p"
	.string "The responsibility for putting an end\n"
	.string "to this falls to Archie and I…$"

Route128_Text_MaxieThisDefiesBelief: @ 81F704F
	.string "Maxie: This defies belief…\p"
	.string "Those super-ancient Pokémon…\p"
	.string "Their power is unbelievable.\n"
	.string "They've upset the balance of nature…$"

Route128_Text_StevenWhatIsHappening: @ 81F70C9
	.string "Steven: {PLAYER}{KUN}!\n"
	.string "What is happening?$"

Route128_Text_StevenWholeWorldWillDrown: @ 81F70EA
	.string "This is terrible…\p"
	.string "After the scorching heat wave ended,\n"
	.string "this deluge began.\p"
	.string "If this doesn't stop, all of Hoenn…\n"
	.string "No, the whole world will drown.\p"
	.string "This huge rain cloud is spreading\n"
	.string "from above Sootopolis…\p"
	.string "What in the world is taking place there?\p"
	.string "There's no point arguing here…\n"
	.string "Sootopolis might provide answers…$"

Route128_Text_StevenImGoingToSootopolis: @ 81F721B
	.string "{PLAYER}{KUN}…\n"
	.string "I don't know what you intend to do,\l"
	.string "but don't do anything reckless.\p"
	.string "Okay.\n"
	.string "I'm going to Sootopolis.$"

Route128_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route128_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route128_EventScript_LegendaryNPC_2
	msgbox Route128_EventScript_LegendaryNPC_Text_4
Route128_EventScript_LegendaryNPC_1:
	release
	end

Route128_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route128_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_CARLEE
	goto_if 1, Route128_EventScript_LegendaryNPC_11
Route128_EventScript_LegendaryNPC_9:
	msgbox Route128_EventScript_LegendaryNPC_Text_3
	goto Route128_EventScript_LegendaryNPC_1

Route128_EventScript_LegendaryNPC_5:
	msgbox Route128_EventScript_LegendaryNPC_Text_1
	goto Route128_EventScript_LegendaryNPC_1

Route128_EventScript_LegendaryNPC_8:
	msgbox Route128_EventScript_LegendaryNPC_Text_2
	goto Route128_EventScript_LegendaryNPC_1

Route128_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_WAYNE
	goto_if 1, Route128_EventScript_LegendaryNPC_15
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_HARRISON
	goto_if 1, Route128_EventScript_LegendaryNPC_10
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_ALEXA
	goto_if 1, Route128_EventScript_LegendaryNPC_19
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_RUBEN
	goto_if 1, Route128_EventScript_LegendaryNPC_14
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_ISAIAH_1
	goto_if 1, Route128_EventScript_LegendaryNPC_8
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_KATELYN_1
	goto_if 1, Route128_EventScript_LegendaryNPC_18
	goto Route128_EventScript_LegendaryNPC_9


Route128_EventScript_LegendaryNPC_Text_0:
	.string "Sage: Not only am I a sage, but once\n"
	.string "upon a time I was a bard, too. A good\l"
	.string "one at that... but a long time has\l"
	.string "passed. I used to sing the legend of\l"
	.string "King Calyrex, the righteous king turned\l"
	.string "mad by power. Do you want to hear me\l"
	.string "sing one last time?$"

Route128_EventScript_LegendaryNPC_Text_1:
	.string "Once upon a time, in the frozen lands of\n"
	.string "Galar, lived a benevolent king named\l"
	.string "Calyrex\p"
	.string "Calyrex was beloved by the people and\n"
	.string "feared by his enemies: every day he\l"
	.string "would ride his magnificent steed,\l"
	.string "Glastrier, across the realm,\p"
	.string "helping those in need, lifting\n"
	.string "everyone's spirits and being there\l"
	.string "when his presence was needed the most.\p"
	.string "One day, two messengers from Alola came\n"
	.string "to Calyrex's castle: they were the\l"
	.string "island guardians Tapu Koko and Tapu\l"
	.string "Bulu.\p"
	.string "They told Calyrex that Alola was under\n"
	.string "attack from outer space: Necrozma,\l"
	.string "the cosmic devourer, had finally\l"
	.string "reached the region,\p"
	.string "and was about to wreck havoc alongside\n"
	.string "his army of Ultra Beasts. The king,\l"
	.string "fearing for his people, rushed\l"
	.string "immediately to Alola to aid in the\l"
	.string "fight.\p"
	.string "The battle was long and bloody.\n"
	.string "Miracolously, they managed to push\l"
	.string "back Necrozma, but it was already too\l"
	.string "late: the Ultra Beasts had reached the\l"
	.string "surface, and it seemed like nothing\l"
	.string "could stop them...\p"
	.string "This is the part of the legend that was\n"
	.string "taught to me, I'm sure someone knows\l"
	.string "the rest. If you wanna catch this\l"
	.string "battling trio, come back once you\l"
	.string "become champion!$"

Route128_EventScript_LegendaryNPC_Text_2:
	.string "Tapu Koko, Tapu Bulu and Glastrier have\n"
	.string "deemed you worthy of meeting them. I\l"
	.string "marked their location on your DexNav:\l"
	.string "use it on this route to meet them!$"

Route128_EventScript_LegendaryNPC_Text_3:
	.string "The Tapus and the King's steed admire\n"
	.string "your dedication to becoming champion,\l"
	.string "but would like to see some more action\l"
	.string "from you! Defeat every trainer in this\l"
	.string "route and come back to me!$"

Route128_EventScript_LegendaryNPC_Text_4:
	.string "You know there's nothing left of me...\n"
	.string "Let me sing... please...$"
