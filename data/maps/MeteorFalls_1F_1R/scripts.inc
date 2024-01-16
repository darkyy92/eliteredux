.set LOCALID_MAGMA_GRUNT_1, 1
.set LOCALID_MAGMA_GRUNT_2, 2
.set LOCALID_ARCHIE, 3
.set LOCALID_AQUA_GRUNT_1, 4
.set LOCALID_AQUA_GRUNT_2, 5
.set LOCALID_PROF_COSMO, 6
.set LOCALID_RIVAL, 7
.set LOCALID_ACE_TRAINER, 8

MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	call_if_set FLAG_BADGE07_GET, MeteorFalls_1F_1R_EventScript_MoveAceTrainer
	call Common_EventScript_SetupRivalGfxId
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave:: @ 822BD3A
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, 1
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, 1
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, 0
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, 1
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene:: @ 822BD5F
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_WalkDown2
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MeteorFalls_1F_1R_EventScript_May
	compare VAR_RESULT, FEMALE
	goto_if_eq MeteorFalls_1F_1R_EventScript_Brendan
MeteorFalls_1F_1R_EventScript_MagmaAfterBattle::
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	addobject LOCALID_ARCHIE
	addobject LOCALID_AQUA_GRUNT_1
	addobject LOCALID_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_RIVAL, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WatchAquaLeave
	applymovement LOCALID_RIVAL, MeteorFalls_1F_1R_Movement_WatchAquaLeave
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_AQUA_GRUNT_1
	removeobject LOCALID_AQUA_GRUNT_2
	special RemoveCameraObject
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_EventScript_May::
	msgbox MeteorFalls_1F_1R_Text_MayBozos, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_Brat, MSGBOX_DEFAULT
	closemessage
MeteorFalls_1F_1R_EventScript_MayAfterCancel::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WalkDown2
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_MayPlayerHere, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MeteorFalls_1F_1R_EventScript_CancelMultiBattle
	case YES, MeteorFalls_1F_1R_EventScript_MultiMay
	end

MeteorFalls_1F_1R_EventScript_Brendan::
	msgbox MeteorFalls_1F_1R_Text_BrendanJerks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_Brat, MSGBOX_DEFAULT
	closemessage
MeteorFalls_1F_1R_EventScript_BrendanAfterCancel::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WalkDown2
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BrendanPlayerHere, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MeteorFalls_1F_1R_EventScript_CancelMultiBattle
	case YES, MeteorFalls_1F_1R_EventScript_MultiBrendan
	end

MeteorFalls_1F_1R_EventScript_MultiMay::
	msgbox MeteorFalls_1F_1R_Text_MayLetsBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_WalkRight1
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	special HealPlayerParty
	msgbox MeteorFalls_1F_1R_Text_CourtneyLetsBattle, MSGBOX_DEFAULT
	choose_mons
    compare VAR_RESULT, 0
    call_if_eq MeteorFalls_1F_1R_EventScript_ChooseMons
	switch VAR_STARTER_MON
	case 0, MeteorFalls_1F_1R_EventScript_MayBattleTreecko
	case 1, MeteorFalls_1F_1R_EventScript_MayBattleTorchic
	case 2, MeteorFalls_1F_1R_EventScript_MayBattleMudkip
	end

MeteorFalls_1F_1R_EventScript_MultiBrendan::
	msgbox MeteorFalls_1F_1R_Text_BrendayLetsBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_WalkRight1
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	special HealPlayerParty
	msgbox MeteorFalls_1F_1R_Text_CourtneyLetsBattle, MSGBOX_DEFAULT
	choose_mons
    compare VAR_RESULT, 0
    call_if_eq MeteorFalls_1F_1R_EventScript_ChooseMons
	switch VAR_STARTER_MON
	case 0, MeteorFalls_1F_1R_EventScript_BrendanBattleTreecko
	case 1, MeteorFalls_1F_1R_EventScript_BrendanBattleTorchic
	case 2, MeteorFalls_1F_1R_EventScript_BrendanBattleMudkip
	end

MeteorFalls_1F_1R_EventScript_MayBattleTreecko::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_TREECKO_METEOR_FALLS, TRAINER_BACK_PIC_MAY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_MayBattleTorchic::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_TORCHIC_METEOR_FALLS, TRAINER_BACK_PIC_MAY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_MayBattleMudkip::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_MUDKIP_METEOR_FALLS, TRAINER_BACK_PIC_MAY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_BrendanBattleTreecko::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_TREECKO_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_BrendanBattleTorchic::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_TORCHIC_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_BrendanBattleMudkip::
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_MUDKIP_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
    releaseall
    end

MeteorFalls_1F_1R_EventScript_ChooseMons::
    msgbox MeteorFalls_1F_1R_Text_ChooseMons, MSGBOX_DEFAULT
    choose_mons
    compare VAR_RESULT, 0
    goto_if_eq MeteorFalls_1F_1R_EventScript_CancelMultiBattle
    return

MeteorFalls_1F_1R_EventScript_CancelMultiBattle::
    msgbox MeteorFalls_1F_1R_Text_CancelMultiBattle, MSGBOX_DEFAULT
	setvar VAR_METEOR_FALLS_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_Camera2
	waitmovement 0
	special RemoveCameraObject
	fadedefaultbgm
    releaseall
    end

MeteorFalls_1F_1R_EventScript_Lost::
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

MeteorFalls_1F_1R_EventScript_MultiCancelled::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_WalkDown2
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MeteorFalls_1F_1R_EventScript_MayAfterCancel
	compare VAR_RESULT, FEMALE
	goto_if_eq MeteorFalls_1F_1R_EventScript_BrendanAfterCancel

MeteorFalls_1F_1R_EventScript_RivalTalkAfterBattle::
	lock
	faceplayer
	msgbox MeteorFalls_1F_1R_Text_RivalAfterBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Movement_WalkDown2:
	walk_down
	walk_down
	step_end

MeteorFalls_1F_1R_Movement_Camera2:
	walk_up
	walk_up
	step_end

MeteorFalls_1F_1R_Movement_WalkRight1:
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit: @ 822BEC4
	delay_16
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit: @ 822BECE
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive: @ 822BED9
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive: @ 822BEE0
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive: @ 822BEE8
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit: @ 822BEF0
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer: @ 822BEF8
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit: @ 822BEFE
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie: @ 822BF08
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit: @ 822BF0D
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie: @ 822BF18
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_fastest_left
	delay_4
	walk_in_place_fastest_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_Movement_WatchAquaLeave:
	delay_16
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo:: @ 822BF25
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo:: @ 822BF3D
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_MayBozos:
	.string "May: Give it up, you bozos!\n"
	.string "Let the professor go!$"

MeteorFalls_1F_1R_Text_BrendanJerks:
	.string "Brendan: Hey! You jerks!\n"
	.string "Let Professor Cozmo go!$"

MeteorFalls_1F_1R_Text_Brat:
	.string "Hmm?\p"
	.string "What's this?\n"
	.string "Who is this spoiled brat?$"

MeteorFalls_1F_1R_Text_MayPlayerHere:
	.string "May: {PLAYER}{KUN}! You came!\p"
	.string "We've got to save Professor Cozmo\n"
	.string "from these people!\p"
	.string "There are two of them…\n"
	.string "And two of us…\p"
	.string "{PLAYER}{KUN}, please!\n"
	.string "Battle together with me!$"

MeteorFalls_1F_1R_Text_BrendanPlayerHere:
	.string "Brendan: {PLAYER}! You finally made\n" 
	.string "it, huh!\p"
	.string "We've gotta protect the professor\n"
	.string "from these lunatics!\p"
	.string "There's two of them…\n"
	.string "And two of us, huh?\p"
	.string "Sorry to ask, {PLAYER}, but…\n"
	.string "Battle alongside me!$"

MeteorFalls_1F_1R_Text_MayLetsBattle:
	.string "Thanks a mill!$"

MeteorFalls_1F_1R_Text_BrendayLetsBattle:
	.string "Thanks, pal!$"

MeteorFalls_1F_1R_Text_CourtneyLetsBattle:
	.string "Ahahaha!\p"
	.string "You brats are no match for a Team\n"
	.string "Magma Admin!\p"
	.string "I'll put you in your place, kiddos!$"

MeteorFalls_1F_1R_Text_CourtneyLose:
	.string "Ahhh?! Did I go too easy on you?!$"

MeteorFalls_1F_1R_Text_GruntLose:
	.string "Are you telling me you're that strong\n"
	.string "and still just kids?!$"

MeteorFalls_1F_1R_Text_ChooseMons:
	.string "Choose which Pokémon will battle.$"

MeteorFalls_1F_1R_Text_CancelMultiBattle:
	.string "Oh, you've got to get ready first?\n"
	.string "OK, but please hurry!$"

MeteorFalls_1F_1R_Text_WithThisMeteorite: @ 822BF47
	.string "Ahahaha!\p"
	.string "Well, that's embarrasing.\n"
	.string "But it doesn't matter.\p"
	.string "With this Meteorite, that thing in\n"
	.string "Mt. Chimney will…$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma: @ 822BFE4
	.string "Hold it right there, Team Magma!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua: @ 822C04E
	.string "Ahahaha!\n"
	.string "Even Team Aqua joins us!\p"
	.string "But there's nothing to be done about\n"
	.string "it…\p"
	.string "We've got the Meteorite, so off to\n"
	.string "Mt. Chimney we go!\p"
	.string "Be seeing you, brats and Team Aqua!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore: @ 822C11C
	.string "Archie: Didn't I see you before?\n"
	.string "At Slateport's Museum?\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of Team Magma's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "Team Magma is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "They are the rivals to us,\n"
	.string "the sea-loving Team Aqua!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma: @ 822C268
	.string "Boss, we should give chase to\n"
	.string "Team Magma…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo: @ 822C292
	.string "Archie: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what Team Magma\n"
	.string "will do at Mt. Chimney!$"

MeteorFalls_1F_1R_Text_ArchieFarewell: @ 822C2FC
	.string "Archie: {PLAYER}, you should keep\n"
	.string "an eye out for Team Magma, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo: @ 822C342
	.string "I… I'm Cozmo…\n"
	.string "I'm a Professor\p"
	.string "Team Magma asked me to guide them\n"
	.string "to Meteor Falls…\p"
	.string "But they tricked me.\n"
	.string "They even took my Meteorite away…\p"
	.string "And then another similar bunch,\n"
	.string "Team Aqua showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that Team Magma…\p"
	.string "What are they going to do with that\n"
	.string "Meteorite at Mt. Chimney?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney: @ 822C47D
	.string "Prof. Cozmo: But that Team Magma…\p"
	.string "What are they going to do with that\n"
	.string "Meteorite at Mt. Chimney?$"

MeteorFalls_1F_1R_Text_RivalAfterBattle:
	.string "Never mind what's happened!\p"
	.string "I've got to get the professor back to\n"
	.string "his lab in Fallarbor!$"

MeteorFalls_1F_1R_EventScript_AceTrainer_Block::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, MeteorFalls_1F_1R_EventScript_AceTrainer_Block_2
	msgbox MeteorFalls_1F_1R_EventScript_AceTrainer_Block_Text_1, MSGBOX_NPC
MeteorFalls_1F_1R_EventScript_AceTrainer_Block_1:
	release
	end

MeteorFalls_1F_1R_EventScript_AceTrainer_Block_2:
	msgbox MeteorFalls_1F_1R_EventScript_AceTrainer_Block_Text_0, MSGBOX_NPC
	goto MeteorFalls_1F_1R_EventScript_AceTrainer_Block_1


MeteorFalls_1F_1R_EventScript_MoveAceTrainer::
	setobjectxyperm LOCALID_ACE_TRAINER, 11, 27
	return


MeteorFalls_1F_1R_EventScript_AceTrainer_Block_Text_0:
	.string "Hmmm... You look strong. I think it's\n"
	.string "okay for you to go in there. But be\l"
	.string "warned! That Pokémon is no joke.$"

MeteorFalls_1F_1R_EventScript_AceTrainer_Block_Text_1:
	.string "Hey, you can't come in here, kid! There's\n"
	.string "a rampaging Pokémon on the loose! Only\l"
	.string "trainers who are at least strong\l"
	.string "enough to get 7 badges can help us\l"
	.string "here.$"
