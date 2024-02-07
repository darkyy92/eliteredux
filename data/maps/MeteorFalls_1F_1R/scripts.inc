# 1 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 2 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_MAGMA_GRUNT_1, 1
# 3 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_MAGMA_GRUNT_2, 2
# 4 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_ARCHIE, 3
# 5 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_AQUA_GRUNT_1, 4
# 6 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_AQUA_GRUNT_2, 5
# 7 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_PROF_COSMO, 6
# 8 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_RIVAL, 7
# 9 "data/maps/MeteorFalls_1F_1R/scripts.pory"
.set LOCALID_ACE_TRAINER, 8
# 10 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 11 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
# 12 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
# 13 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.byte 0
# 14 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 15 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_OnLoad:
# 16 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
# 17 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	call_if_set FLAG_BADGE07_GET, MeteorFalls_1F_1R_EventScript_MoveAceTrainer
# 18 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 19 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 20 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 21 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_OpenStevensCave:: @ 822BD3A
# 22 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, 1
# 23 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, 1
# 24 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, 0
# 25 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, 1
# 26 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	return
# 27 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 28 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene:: @ 822BD5F
# 29 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lockall
# 30 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 31 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 32 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 33 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay 30
# 34 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	special SpawnCameraObject
# 35 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_WalkDown2
# 36 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 37 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
# 38 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 39 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	checkplayergender
# 40 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, MALE
# 41 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_May
# 42 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, FEMALE
# 43 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_Brendan
# 44 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MagmaAfterBattle::
# 45 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFastestRight
# 46 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 47 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
# 48 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 49 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
# 50 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 51 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 52 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
# 53 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFastestLeft
# 54 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
# 55 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 56 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_ARCHIE
# 57 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_AQUA_GRUNT_1
# 58 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	addobject LOCALID_AQUA_GRUNT_2
# 59 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 60 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
# 61 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
# 62 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
# 63 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 64 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFastestLeft
# 65 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 66 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
# 67 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 68 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
# 69 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
# 70 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
# 71 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
# 72 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 73 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 74 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 75 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
# 76 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 77 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 78 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
# 79 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 80 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
# 81 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 82 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
# 83 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
# 84 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 85 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
# 86 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestLeft
# 87 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 88 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
# 89 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestRight
# 90 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 91 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
# 92 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 93 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
# 94 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
# 95 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
# 96 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WatchAquaLeave
# 97 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, MeteorFalls_1F_1R_Movement_WatchAquaLeave
# 98 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 99 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	fadedefaultbgm
# 100 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_ARCHIE
# 101 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_AQUA_GRUNT_1
# 102 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	removeobject LOCALID_AQUA_GRUNT_2
# 103 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	special RemoveCameraObject
# 104 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
# 105 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
# 106 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
# 107 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setvar VAR_METEOR_FALLS_STATE, 1
# 108 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	releaseall
# 109 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 110 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 111 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_May::
# 112 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_MayBozos, MSGBOX_DEFAULT
# 113 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 114 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceRight
# 115 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 116 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_Brat, MSGBOX_DEFAULT
# 117 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 118 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MayAfterCancel::
# 119 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
# 120 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 121 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playse SE_PIN
# 122 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 123 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WalkDown2
# 124 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 125 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_MayPlayerHere, MSGBOX_YESNO
# 126 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	switch VAR_RESULT
# 127 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case NO, MeteorFalls_1F_1R_EventScript_CancelMultiBattle
# 128 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case YES, MeteorFalls_1F_1R_EventScript_MultiMay
# 129 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 130 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 131 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_Brendan::
# 132 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BrendanJerks, MSGBOX_DEFAULT
# 133 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 134 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceRight
# 135 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 136 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_Brat, MSGBOX_DEFAULT
# 137 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	closemessage
# 138 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_BrendanAfterCancel::
# 139 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
# 140 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 141 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playse SE_PIN
# 142 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 143 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_WalkDown2
# 144 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 145 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BrendanPlayerHere, MSGBOX_YESNO
# 146 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	switch VAR_RESULT
# 147 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case NO, MeteorFalls_1F_1R_EventScript_CancelMultiBattle
# 148 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case YES, MeteorFalls_1F_1R_EventScript_MultiBrendan
# 149 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 150 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 151 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MultiMay::
# 152 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_MayLetsBattle, MSGBOX_DEFAULT
# 153 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_WalkRight1
# 154 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
# 155 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
# 156 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 157 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceRight
# 158 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 159 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	special HealPlayerParty
# 160 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_CourtneyLetsBattle, MSGBOX_DEFAULT
# 161 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	choose_mons
# 162 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    compare VAR_RESULT, 0
# 163 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    call_if_eq MeteorFalls_1F_1R_EventScript_ChooseMons
# 164 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	switch VAR_STARTER_MON
# 165 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case 0, MeteorFalls_1F_1R_EventScript_MayBattleTreecko
# 166 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case 1, MeteorFalls_1F_1R_EventScript_MayBattleTorchic
# 167 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case 2, MeteorFalls_1F_1R_EventScript_MayBattleMudkip
# 168 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 169 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 170 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MultiBrendan::
# 171 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_BrendayLetsBattle, MSGBOX_DEFAULT
# 172 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_WalkRight1
# 173 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
# 174 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
# 175 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 176 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceRight
# 177 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 178 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	special HealPlayerParty
# 179 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_CourtneyLetsBattle, MSGBOX_DEFAULT
# 180 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	choose_mons
# 181 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    compare VAR_RESULT, 0
# 182 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    call_if_eq MeteorFalls_1F_1R_EventScript_ChooseMons
# 183 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	switch VAR_STARTER_MON
# 184 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case 0, MeteorFalls_1F_1R_EventScript_BrendanBattleTreecko
# 185 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case 1, MeteorFalls_1F_1R_EventScript_BrendanBattleTorchic
# 186 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	case 2, MeteorFalls_1F_1R_EventScript_BrendanBattleMudkip
# 187 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 188 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 189 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MayBattleTreecko::
# 190 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_TREECKO_METEOR_FALLS, TRAINER_BACK_PIC_MAY
# 191 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 192 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 193 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
# 194 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
# 195 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    releaseall
# 196 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    end
# 197 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 198 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MayBattleTorchic::
# 199 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_TORCHIC_METEOR_FALLS, TRAINER_BACK_PIC_MAY
# 200 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 201 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 202 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
# 203 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
# 204 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    releaseall
# 205 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    end
# 206 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 207 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MayBattleMudkip::
# 208 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, MAY_MUDKIP_METEOR_FALLS, TRAINER_BACK_PIC_MAY
# 209 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 210 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 211 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
# 212 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
# 213 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    releaseall
# 214 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    end
# 215 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 216 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_BrendanBattleTreecko::
# 217 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_TREECKO_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
# 218 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 219 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 220 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
# 221 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
# 222 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    releaseall
# 223 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    end
# 224 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 225 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_BrendanBattleTorchic::
# 226 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_TORCHIC_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
# 227 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 228 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 229 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
# 230 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
# 231 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    releaseall
# 232 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    end
# 233 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 234 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_BrendanBattleMudkip::
# 235 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    multi_2_vs_2 TRAINER_COURTNEY_METEOR_FALLS, MeteorFalls_1F_1R_Text_CourtneyLose, TRAINER_GRUNT_METEOR_FALLS, MeteorFalls_1F_1R_Text_GruntLose, BRENDAN_MUDKIP_METEOR_FALLS, TRAINER_BACK_PIC_BRENDAN
# 236 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 237 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 238 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_Lost
# 239 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto MeteorFalls_1F_1R_EventScript_MagmaAfterBattle
# 240 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    releaseall
# 241 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    end
# 242 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 243 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_ChooseMons::
# 244 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    msgbox MeteorFalls_1F_1R_Text_ChooseMons, MSGBOX_DEFAULT
# 245 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    choose_mons
# 246 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    compare VAR_RESULT, 0
# 247 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    goto_if_eq MeteorFalls_1F_1R_EventScript_CancelMultiBattle
# 248 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    return
# 249 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 250 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_CancelMultiBattle::
# 251 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    msgbox MeteorFalls_1F_1R_Text_CancelMultiBattle, MSGBOX_DEFAULT
# 252 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setvar VAR_METEOR_FALLS_STATE, 2
# 253 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
# 254 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_Camera2
# 255 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 256 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	special RemoveCameraObject
# 257 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	fadedefaultbgm
# 258 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    releaseall
# 259 "data/maps/MeteorFalls_1F_1R/scripts.pory"
    end
# 260 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 261 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_Lost::
# 262 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	fadescreen FADE_TO_BLACK
# 263 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	special SetCB2WhiteOut
# 264 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitstate
# 265 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 266 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MultiCancelled::
# 267 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lockall
# 268 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, 0
# 269 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	special SpawnCameraObject
# 270 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, MeteorFalls_1F_1R_Movement_WalkDown2
# 271 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	waitmovement 0
# 272 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	checkplayergender
# 273 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, MALE
# 274 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_MayAfterCancel
# 275 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	compare VAR_RESULT, FEMALE
# 276 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_eq MeteorFalls_1F_1R_EventScript_BrendanAfterCancel
# 277 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 278 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_RivalTalkAfterBattle::
# 279 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lock
# 280 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	faceplayer
# 281 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_RivalAfterBattle, MSGBOX_DEFAULT
# 282 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 283 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 284 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 285 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_WalkDown2:
# 286 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_down
# 287 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_down
# 288 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 289 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 290 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_Camera2:
# 291 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 292 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 293 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 294 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 295 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_WalkRight1:
# 296 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 297 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 298 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 299 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit: @ 822BEC4
# 300 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 301 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 302 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 303 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 304 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 305 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 306 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 307 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 308 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 309 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 310 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 311 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 312 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 313 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 314 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 315 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit: @ 822BECE
# 316 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 317 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 318 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 319 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 320 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_up
# 321 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 322 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 323 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 324 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 325 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 326 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 327 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 328 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_fast_right
# 329 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 330 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 331 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieArrive: @ 822BED9
# 332 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 333 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 334 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 335 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 336 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 337 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 338 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 339 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 340 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive: @ 822BEE0
# 341 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 342 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 343 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 344 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 345 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 346 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 347 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 348 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 349 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 350 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive: @ 822BEE8
# 351 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 352 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 353 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 354 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 355 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 356 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 357 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 358 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 359 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 360 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieExit: @ 822BEF0
# 361 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 362 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 363 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 364 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 365 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 366 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 367 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 368 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 369 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 370 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 371 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 372 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 373 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 374 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 375 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 376 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_ArchieApproachPlayer: @ 822BEF8
# 377 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 378 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 379 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 380 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 381 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1Exit: @ 822BEFE
# 382 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 383 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 384 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 385 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 386 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 387 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 388 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 389 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 390 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 391 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 392 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 393 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 394 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 395 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 396 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 397 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 398 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie: @ 822BF08
# 399 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 400 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 401 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 402 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2Exit: @ 822BF0D
# 403 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 404 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 405 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 406 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 407 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 408 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 409 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_up
# 410 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 411 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 412 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 413 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 414 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 415 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 416 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 417 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 418 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 419 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 420 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie: @ 822BF18
# 421 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_right
# 422 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 423 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 424 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
# 425 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_fastest_left
# 426 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_4
# 427 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_fastest_up
# 428 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lock_facing_direction
# 429 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_down
# 430 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	unlock_facing_direction
# 431 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	face_right
# 432 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 433 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 434 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Movement_WatchAquaLeave:
# 435 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 436 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 437 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_fastest_up
# 438 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 439 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 440 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	walk_in_place_fastest_right
# 441 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 442 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 443 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 444 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 445 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 446 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 447 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 448 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 449 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 450 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 451 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	delay_16
# 452 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	step_end
# 453 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 454 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_ProfCozmo:: @ 822BF25
# 455 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lock
# 456 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	faceplayer
# 457 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
# 458 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setflag FLAG_MET_PROF_COZMO
# 459 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
# 460 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 461 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 462 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 463 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_EventScript_MetCozmo:: @ 822BF3D
# 464 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
# 465 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	release
# 466 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	end
# 467 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 468 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_MayBozos:
# 469 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "May: Give it up, you bozos!\n"
# 470 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Let the professor go!$"
# 471 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 472 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BrendanJerks:
# 473 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Brendan: Hey! You jerks!\n"
# 474 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Let Professor Cozmo go!$"
# 475 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 476 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_Brat:
# 477 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hmm?\p"
# 478 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What's this?\n"
# 479 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Who is this spoiled brat?$"
# 480 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 481 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_MayPlayerHere:
# 482 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "May: {PLAYER}{KUN}! You came!\p"
# 483 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got to save Professor Cozmo\n"
# 484 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "from these people!\p"
# 485 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "There are two of them…\n"
# 486 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "And two of us…\p"
# 487 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "{PLAYER}{KUN}, please!\n"
# 488 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Battle together with me!$"
# 489 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 490 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BrendanPlayerHere:
# 491 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Brendan: {PLAYER}! You finally made\n" 
# 492 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "it, huh!\p"
# 493 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've gotta protect the professor\n"
# 494 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "from these lunatics!\p"
# 495 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "There's two of them…\n"
# 496 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "And two of us, huh?\p"
# 497 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Sorry to ask, {PLAYER}, but…\n"
# 498 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Battle alongside me!$"
# 499 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 500 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_MayLetsBattle:
# 501 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Thanks a mill!$"
# 502 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 503 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BrendayLetsBattle:
# 504 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Thanks, pal!$"
# 505 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 506 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_CourtneyLetsBattle:
# 507 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Ahahaha!\p"
# 508 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You brats are no match for a Team\n"
# 509 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Magma Admin!\p"
# 510 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I'll put you in your place, kiddos!$"
# 511 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 512 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_CourtneyLose:
# 513 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Ahhh?! Did I go too easy on you?!$"
# 514 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 515 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_GruntLose:
# 516 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Are you telling me you're that strong\n"
# 517 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "and still just kids?!$"
# 518 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 519 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ChooseMons:
# 520 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Choose which Pokémon will battle.$"
# 521 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 522 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_CancelMultiBattle:
# 523 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Oh, you've got to get ready first?\n"
# 524 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "OK, but please hurry!$"
# 525 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 526 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_WithThisMeteorite: @ 822BF47
# 527 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Ahahaha!\p"
# 528 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Well, that's embarrasing.\n"
# 529 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But it doesn't matter.\p"
# 530 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "With this Meteorite, that thing in\n"
# 531 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Mt. Chimney will…$"
# 532 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 533 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_HoldItRightThereMagma: @ 822BFE4
# 534 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hold it right there, Team Magma!\p"
# 535 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You're badly mistaken if you think you\n"
# 536 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "can have your way with the world!$"
# 537 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 538 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua: @ 822C04E
# 539 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Ahahaha!\n"
# 540 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Even Team Aqua joins us!\p"
# 541 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But there's nothing to be done about\n"
# 542 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "it…\p"
# 543 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got the Meteorite, so off to\n"
# 544 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Mt. Chimney we go!\p"
# 545 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Be seeing you, brats and Team Aqua!$"
# 546 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 547 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieSeenYouBefore: @ 822C11C
# 548 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Archie: Didn't I see you before?\n"
# 549 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "At Slateport's Museum?\p"
# 550 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Ah, so your name is {PLAYER}.\p"
# 551 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "At the time, I thought you were one\n"
# 552 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "of Team Magma's goons.\p"
# 553 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Humph…\n"
# 554 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "You're one odd kid.\p"
# 555 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Team Magma is a dangerous group of\n"
# 556 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "total fanatics.\p"
# 557 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They engage in destruction, claiming\n"
# 558 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "to expand the land mass.\p"
# 559 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They are the rivals to us,\n"
# 560 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "the sea-loving Team Aqua!$"
# 561 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 562 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma: @ 822C268
# 563 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Boss, we should give chase to\n"
# 564 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Team Magma…$"
# 565 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 566 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo: @ 822C292
# 567 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Archie: Yes, yes, we must!\n"
# 568 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "We've got to hurry.\p"
# 569 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "There's no telling what Team Magma\n"
# 570 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "will do at Mt. Chimney!$"
# 571 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 572 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_ArchieFarewell: @ 822C2FC
# 573 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Archie: {PLAYER}, you should keep\n"
# 574 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "an eye out for Team Magma, too.\p"
# 575 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Farewell!$"
# 576 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 577 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_MeetProfCozmo: @ 822C342
# 578 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I… I'm Cozmo…\n"
# 579 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I'm a Professor\p"
# 580 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Team Magma asked me to guide them\n"
# 581 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "to Meteor Falls…\p"
# 582 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But they tricked me.\n"
# 583 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "They even took my Meteorite away…\p"
# 584 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "And then another similar bunch,\n"
# 585 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Team Aqua showed up.\p"
# 586 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "After that…\n"
# 587 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I don't understand any of it.\p"
# 588 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "But that Team Magma…\p"
# 589 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What are they going to do with that\n"
# 590 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Meteorite at Mt. Chimney?$"
# 591 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 592 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney: @ 822C47D
# 593 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Prof. Cozmo: But that Team Magma…\p"
# 594 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "What are they going to do with that\n"
# 595 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Meteorite at Mt. Chimney?$"
# 596 "data/maps/MeteorFalls_1F_1R/scripts.pory"

# 597 "data/maps/MeteorFalls_1F_1R/scripts.pory"
MeteorFalls_1F_1R_Text_RivalAfterBattle:
# 598 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Never mind what's happened!\p"
# 599 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "I've got to get the professor back to\n"
# 600 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "his lab in Fallarbor!$"

MeteorFalls_1F_1R_EventScript_AceTrainer_Block::
# 603 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	lock
# 604 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	faceplayer
# 605 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MeteorFalls_1F_1R_EventScript_AceTrainer_Block_2
# 609 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_EventScript_AceTrainer_Block_Text_1, MSGBOX_NPC
MeteorFalls_1F_1R_EventScript_AceTrainer_Block_1:
# 611 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	release
	end

MeteorFalls_1F_1R_EventScript_AceTrainer_Block_2:
# 606 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	msgbox MeteorFalls_1F_1R_EventScript_AceTrainer_Block_Text_0, MSGBOX_NPC
	goto MeteorFalls_1F_1R_EventScript_AceTrainer_Block_1


MeteorFalls_1F_1R_EventScript_MoveAceTrainer::
# 616 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	setobjectxyperm LOCALID_ACE_TRAINER, 11, 27
	return


MeteorFalls_1F_1R_EventScript_AceTrainer_Block_Text_0:
# 606 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hmmm... You look strong. I think it's\n"
	.string "okay for you to go in there. But be\l"
	.string "warned! That Pokémon is no joke.$"

MeteorFalls_1F_1R_EventScript_AceTrainer_Block_Text_1:
# 609 "data/maps/MeteorFalls_1F_1R/scripts.pory"
	.string "Hey, you can't come in here, kid! There's\n"
	.string "a rampaging Pokémon on the loose! Only\l"
	.string "trainers who are at least strong enough\l"
	.string "to get 7 badges can help us here.$"
