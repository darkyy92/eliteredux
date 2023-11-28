.set LOCALID_WALLACE, 1
.set LOCALID_GAUNTLET_TRAINER_1, 2 // Expert M middle
.set LOCALID_GAUNTLET_TRAINER_2, 3 // Expert F right
.set LOCALID_GAUNTLET_TRAINER_3, 4 // Expert F left

SkyPillar_Outside_MapScripts:: @ 82392A8
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_OnFrame
	.byte 0

SkyPillar_Outside_OnTransition: @ 82392B8
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
	call_if_eq SkyPillar_Outside_EventScript_HideMapNamePopup
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
	call_if_ge SkyPillar_Outside_EventScript_CheckSetAbnormalWeather
	end

SkyPillar_Outside_EventScript_HideMapNamePopup:: @ 82392CF
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SkyPillar_Outside_EventScript_CheckSetAbnormalWeather:: @ 82392D3
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

SkyPillar_Outside_OnLoad: @ 82392DD
	call SkyPillar_Outside_EventScript_HideGauntletTrainers
	call_if_set FLAG_WALLACE_GOES_TO_SKY_PILLAR, SkyPillar_Outside_EventScript_OpenDoor
	end

SkyPillar_Outside_EventScript_OpenDoor:: @ 82392E7
	setmetatile 14, 4, METATILE_Pacifidlog_SkyPillar_DoorOpen_Top, 0
	setmetatile 14, 5, METATILE_Pacifidlog_SkyPillar_DoorOpen_Bottom, 0
	return

SkyPillar_Outside_OnFrame: @ 82392FA
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, SkyPillar_Outside_EventScript_WallaceScene
	.2byte 0

SkyPillar_Outside_EventScript_WallaceScene:: @ 8239304
	lockall
	applymovement LOCALID_WALLACE, SkyPillar_Outside_Movement_WallaceApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox SkyPillar_Outside_Text_OpenedDoorToSkyPillar, MSGBOX_DEFAULT
	closemessage
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	delay 40
	msgbox SkyPillar_Outside_Text_EarthquakeNotMomentToWaste, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SkyPillar_Outside_Movement_PlayerClimbSkyPillar
	applymovement LOCALID_WALLACE, SkyPillar_Outside_Movement_WallaceClimbSkyPillar
	waitmovement 0
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 3   @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 5   @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	msgbox SkyPillar_Outside_Text_SituationGettingWorse, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_ABNORMAL
	doweather
	special WaitWeather
	waitstate
	delay 30
	msgbox SkyPillar_Outside_Text_GotToGoBackForSootopolis, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenswapbuffers FADE_TO_BLACK
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SOOTOPOLIS_CITY_STATE, 4
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

SkyPillar_Outside_Movement_WallaceApproachPlayer: @ 82393D3
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SkyPillar_Outside_Movement_WallaceClimbSkyPillar: @ 82393DE
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Outside_Movement_PlayerClimbSkyPillar: @ 82393EB
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

SkyPillar_Outside_EventScript_Wallace:: @ 82393F8
	end

SkyPillar_Outside_EventScript_ClosedDoor:: @ 82393F9
	msgbox SkyPillar_Outside_Text_DoorIsClosed, MSGBOX_SIGN
	end

SkyPillar_Outside_Text_DoorIsClosed: @ 8239402
	.string "The door is closed.$"

SkyPillar_Outside_Text_OpenedDoorToSkyPillar: @ 8239416
	.string "Wallace: Oh, my, I'm terribly sorry!\p"
	.string "In my haste, I didn't notice that\n"
	.string "I'd left you behind!\p"
	.string "I've opened the locked door of\n"
	.string "the Sky Pillar.\p"
	.string "{PLAYER}{KUN}, let's be on our way!$"

SkyPillar_Outside_Text_EarthquakeNotMomentToWaste: @ 82394BC
	.string "Wallace: It's an earthquake!\p"
	.string "There's not a moment to waste!\n"
	.string "We've got to hurry!$"

SkyPillar_Outside_Text_SituationGettingWorse: @ 823950C
	.string "Wallace: Hmm…\n"
	.string "The situation is getting worse…$"

SkyPillar_Outside_Text_GotToGoBackForSootopolis: @ 823953A
	.string "Wallace: This isn't good…\p"
	.string "The weather distortion is spreading\n"
	.string "even here…\p"
	.string "{PLAYER}{KUN}.\p"
	.string "Rayquaza should be farther up\n"
	.string "from here.\p"
	.string "I'm worried about Sootopolis.\n"
	.string "I've got to go back.\p"
	.string "Everything is in your hands now.\n"
	.string "Don't fail us!$"

SkyPillar_Outside_Text_Gauntlet::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SkyPillar_Outside_Text_Gauntlet_2
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_12, MSGBOX_NPC
SkyPillar_Outside_Text_Gauntlet_1:
	release
	end

SkyPillar_Outside_Text_Gauntlet_2:
	goto_if_unset FLAG_OBTAINED_DRAGONITENITE, SkyPillar_Outside_Text_Gauntlet_5
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_11, MSGBOX_NPC
	goto SkyPillar_Outside_Text_Gauntlet_1

SkyPillar_Outside_Text_Gauntlet_5:
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SkyPillar_Outside_Text_Gauntlet_8
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_10, MSGBOX_NPC
	goto SkyPillar_Outside_Text_Gauntlet_1

SkyPillar_Outside_Text_Gauntlet_8:
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_1, MSGBOX_NPC
	special HealPlayerParty
	setflag FLAG_SYS_DISABLE_AUTOHEAL
	fadescreenswapbuffers FADE_TO_BLACK
	setobjectxy LOCALID_GAUNTLET_TRAINER_1, 14, 17
	clearflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_2
	addobject LOCALID_GAUNTLET_TRAINER_2
	setobjectxy LOCALID_GAUNTLET_TRAINER_2, 15, 17
	clearflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_3
	addobject LOCALID_GAUNTLET_TRAINER_3
	setobjectxy LOCALID_GAUNTLET_TRAINER_3, 16, 17
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_2, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_DRAGONITENITE_SAGE_2, SkyPillar_Outside_Text_Gauntlet_Text_3
	fadescreenswapbuffers FADE_TO_BLACK
	setobjectxy LOCALID_GAUNTLET_TRAINER_2, 16, 17
	setobjectxy LOCALID_GAUNTLET_TRAINER_3, 15, 17
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_4, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_DRAGONITENITE_SAGE_3, SkyPillar_Outside_Text_Gauntlet_Text_5
	fadescreenswapbuffers FADE_TO_BLACK
	setobjectxy LOCALID_GAUNTLET_TRAINER_1, 15, 17
	setobjectxy LOCALID_GAUNTLET_TRAINER_3, 14, 17
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_6, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_DRAGONITENITE_SAGE_1, SkyPillar_Outside_Text_Gauntlet_Text_7
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_8, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_DRAGONITENITE, 1
	setflag FLAG_OBTAINED_DRAGONITENITE
	clearflag FLAG_SYS_DISABLE_AUTOHEAL
	waitfanfare
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_9, MSGBOX_NPC
	waitmessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_1
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_2
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_3
	removeobject LOCALID_GAUNTLET_TRAINER_1
	removeobject LOCALID_GAUNTLET_TRAINER_2
	removeobject LOCALID_GAUNTLET_TRAINER_3
	fadescreenswapbuffers FADE_FROM_BLACK
	goto SkyPillar_Outside_Text_Gauntlet_1


SkyPillar_Outside_EventScript_HideGauntletTrainers::
	goto_if_unset FLAG_OBTAINED_DRAGONITENITE, SkyPillar_Outside_EventScript_HideGauntletTrainers_2
SkyPillar_Outside_EventScript_HideGauntletTrainers_1:
	return

SkyPillar_Outside_EventScript_HideGauntletTrainers_2:
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_2
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_3
	goto SkyPillar_Outside_EventScript_HideGauntletTrainers_1


SkyPillar_Outside_Text_Gauntlet_Text_0:
	.string "Does thou seek might, young seeker?\n"
	.string "Display thine prowess unto us, and\l"
	.string "thee shall be endowed with strength\l"
	.string "unparalleled.$"

SkyPillar_Outside_Text_Gauntlet_Text_1:
	.string "Overcome our united strength, and the\n"
	.string "ancient dragon's power shall awaken\l"
	.string "for you. Prove your worth and harness\l"
	.string "the legacy.$"

SkyPillar_Outside_Text_Gauntlet_Text_2:
	.string "Thus, we commence.$"

SkyPillar_Outside_Text_Gauntlet_Text_3:
	.string "Superb. Onward we shall proceed.$"

SkyPillar_Outside_Text_Gauntlet_Text_4:
	.string "Exquisite! Now, contend with me and\n"
	.string "demonstrate your deserving spirit!$"

SkyPillar_Outside_Text_Gauntlet_Text_5:
	.string "Thou art steadfast; luck grace thy\n"
	.string "final duel.$"

SkyPillar_Outside_Text_Gauntlet_Text_6:
	.string "Thou standest before the eldest sage.\n"
	.string "Thy final trial commences now, seeker.\l"
	.string "Reveal thy true mettle!$"

SkyPillar_Outside_Text_Gauntlet_Text_7:
	.string "Verily, thou hast demonstrated thy\n"
	.string "worth.$"

SkyPillar_Outside_Text_Gauntlet_Text_8:
	.string "Receive this, and brandish the\n"
	.string "veritable power of Dragonite in its\l"
	.string "purest essence.$"

SkyPillar_Outside_Text_Gauntlet_Text_9:
	.string "Fare thee well, noble seeker.$"

SkyPillar_Outside_Text_Gauntlet_Text_10:
	.string "Regrettable. Return unto this place\n"
	.string "when thee art prepared to confront our\l"
	.string "triad.$"

SkyPillar_Outside_Text_Gauntlet_Text_11:
	.string "I have naught more to utter.$"

SkyPillar_Outside_Text_Gauntlet_Text_12:
	.string "Thy worth is not proven. Vanquish the\n"
	.string "Twins of Mossdeep, and then, seeker,\l"
	.string "return to this sacred place.$"
