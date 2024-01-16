.set LOCALID_CHANSEY, 6
.set LOCALID_POKE_BALL, 7

AshenWoods_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AshenWoods_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AshenWoods_OnTransition
	.byte 0

AshenWoods_OnResume::
	setstepcallback STEP_CB_ASH
	end

AshenWoods_OnTransition::
	setflag FLAG_LANDMARK_ASHEN_WOODS
	compare VAR_JAGGED_PASS_ASH_WEATHER, 1
	call_if_eq AshenWoods_EventScript_SetWeatherAsh
	switch VAR_CHANSEY_NURSE_STATE
	case 4, AshenWoods_EventScript_ChanseySetPos1
	case 5, AshenWoods_EventScript_ChanseySetPos2
	end

AshenWoods_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

AshenWoods_EventScript_Chef::
	msgbox AshenWoods_Text_Mushrooms, MSGBOX_NPC
	end

AshenWoods_EventScript_ChanseyTrigger::
	lockall
	waitse
	playse SE_PIN
	applymovement LOCALID_CHANSEY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHANSEY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyJumpRight
	waitmovement 0
	waitse
	playmoncry SPECIES_CHANSEY, 0
	delay 40
	waitmoncry
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyEscape1
	waitmovement 0
	call AshenWoods_EventScript_ChanseySetPos1
	setvar VAR_CHANSEY_NURSE_STATE, 4
	releaseall
	end

AshenWoods_EventScript_ChanseyTrigger2::
	lockall
	waitse
	playse SE_PIN
	applymovement LOCALID_CHANSEY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CHANSEY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyJumpUp
	waitmovement 0
	waitse
	playmoncry SPECIES_CHANSEY, 0
	delay 40
	waitmoncry
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyEscape2
	waitmovement 0
	call AshenWoods_EventScript_ChanseySetPos2
	setvar VAR_CHANSEY_NURSE_STATE, 5
	releaseall
	end

AshenWoods_EventScript_ChanseySetPos1::
	setobjectxy LOCALID_CHANSEY, 6, 40
	copyobjectxytoperm LOCALID_CHANSEY
	return

AshenWoods_EventScript_ChanseySetPos2::
	setobjectxy LOCALID_CHANSEY, 27, 43
	copyobjectxytoperm LOCALID_CHANSEY
	return

AshenWoods_EventScript_Chansey::
	lockall
	faceplayer
	applymovement LOCALID_CHANSEY, AshenWoods_Movement_ChanseyJumpRight
	waitmovement 0
	waitse
	playmoncry SPECIES_CHANSEY, 0
	delay 40
	waitmoncry
	msgbox AshenWoods_Text_BlobNowhereToRun, MSGBOX_DEFAULT
	checkitem ITEM_HEAL_BALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq AshenWoods_EventScript_BlobNoHealBall
	msgbox AshenWoods_Text_CatchBlob, MSGBOX_DEFAULT
	removeitem ITEM_HEAL_BALL, 1
	playse SE_BALL_THROW
	waitse
	removeobject LOCALID_CHANSEY
	addobject LOCALID_POKE_BALL
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_4
	waitse
	playse SE_RG_BALL_CLICK
	waitse
	msgbox AshenWoods_Text_BlobCaught, MSGBOX_DEFAULT
	removeobject LOCALID_POKE_BALL
	setvar VAR_CHANSEY_NURSE_STATE, 6
	releaseall
	end

AshenWoods_EventScript_BlobNoHealBall::
	msgbox AshenWoods_Text_BlobNoHealBall, MSGBOX_DEFAULT
	releaseall
	end

AshenWoods_Movement_ChanseyJumpRight:
	jump_in_place_right
	delay_4
	jump_in_place_right
	step_end

AshenWoods_Movement_ChanseyJumpUp:
	jump_in_place_up
	delay_4
	jump_in_place_up
	step_end

AshenWoods_Movement_ChanseyEscape1:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

AshenWoods_Movement_ChanseyEscape2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

AshenWoods_EventScript_Alannah::
	trainerbattle_single TRAINER_ALANNAH, AshenWoods_Text_AlannahIntro, AshenWoods_Text_AlannahDefeat
	msgbox AshenWoods_Text_AlannahPostBattle, MSGBOX_AUTOCLOSE
	end

AshenWoods_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN, AshenWoods_Text_MartinIntro, AshenWoods_Text_MartinDefeat
	msgbox AshenWoods_Text_MartinPostBattle, MSGBOX_AUTOCLOSE
	end

AshenWoods_EventScript_Roman::
	trainerbattle_single TRAINER_ROMAN, AshenWoods_Text_RomanIntro, AshenWoods_Text_RomanDefeat
	msgbox AshenWoods_Text_RomanPostBattle, MSGBOX_AUTOCLOSE
	end

AshenWoods_EventScript_Elmer::
	trainerbattle_single TRAINER_ELMER, AshenWoods_Text_ElmerIntro, AshenWoods_Text_ElmerDefeat
	msgbox AshenWoods_Text_ElmerPostBattle, MSGBOX_AUTOCLOSE
	end

AshenWoods_Text_Mushrooms:
	.string "The mushrooms that grow here are\n"
	.string "a highly sought after ingredient.\p"
	.string "They're quite valuable, and they\n"
	.string "seem to grow back overnight!\n"

AshenWoods_Text_BlobNowhereToRun:
	.string "Blob has nowhere to run!$"

AshenWoods_Text_BlobNoHealBall:
	.string "But {PLAYER} doesn't have a\n"
	.string "Heal Ball to catch it…$"

AshenWoods_Text_CatchBlob:
	.string "{PLAYER} threw a Heal Ball at Blob!$"

AshenWoods_Text_BlobCaught:
	.string "Blob was caught!\p"
	.string "Blob was sent to the nurse's PC.$"

AshenWoods_EventScript_Typhlosionite_Battle::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, AshenWoods_EventScript_Typhlosionite_Battle_2
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_6, MSGBOX_NPC
AshenWoods_EventScript_Typhlosionite_Battle_1:
	release
	end

AshenWoods_EventScript_Typhlosionite_Battle_2:
	checktrainerflag TRAINER_TYPHLOSIONITE_ASHEN_WOODS
	goto_if 0, AshenWoods_EventScript_Typhlosionite_Battle_5
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_5, MSGBOX_NPC
	goto AshenWoods_EventScript_Typhlosionite_Battle_1

AshenWoods_EventScript_Typhlosionite_Battle_5:
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq AshenWoods_EventScript_Typhlosionite_Battle_8
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_4, MSGBOX_NPC
	goto AshenWoods_EventScript_Typhlosionite_Battle_1

AshenWoods_EventScript_Typhlosionite_Battle_8:
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_1, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_TYPHLOSIONITE_ASHEN_WOODS, AshenWoods_EventScript_Typhlosionite_Battle_Text_2
	msgbox AshenWoods_EventScript_Typhlosionite_Battle_Text_3, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_TYPHLOSIONITE, 1
	waitmessage
	goto AshenWoods_EventScript_Typhlosionite_Battle_1


AshenWoods_EventScript_Typhlosionite_Battle_Text_0:
	.string "You seem strong, kid! How about this, we\n"
	.string "have a little match, and if you beat me,\l"
	.string "I'll give you a little something!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_1:
	.string "Let's play with fire!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_2:
	.string "That was a great fight, kid!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_3:
	.string "Sheesh! This young, and you're already\n"
	.string "giving someone like me a beating like\l"
	.string "this! You got potential, kid. Take this\l"
	.string "Typhlosionite, and make sure to burn\l"
	.string "all who challenge you to ash!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_4:
	.string "Then you better come back here when\n"
	.string "you're ready! Don't disappoint me!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_5:
	.string "I got nothin' left for you, kid. Now\n"
	.string "scram!$"

AshenWoods_EventScript_Typhlosionite_Battle_Text_6:
	.string "Hmmm... You ain't strong enough, kid!\n"
	.string "Don't come back here until you can beat\l"
	.string "that guy in Petalburg!$"
