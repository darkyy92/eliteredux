# 1 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_ANNOUNCER, 1
# 3 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_AUDIENCE_TWIN, 2
# 4 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_AUDIENCE_WALKING, 6
# 5 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_REFEREE, 9
# 6 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 13
# 7 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
.set LOCALID_OPPONENT, 15
# 8 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 9 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_MapScripts:: @ 824BC9C
# 10 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleDomeBattleRoom_OnTransition
# 11 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeBattleRoom_OnFrame
# 12 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeBattleRoom_OnWarp
# 13 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeBattleRoom_OnResume
# 14 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.byte 0
# 15 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 16 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.set NO_DRAW,       0
# 17 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.set DRAW_TRAINER,  1
# 18 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.set DRAW_TUCKER,   2
# 19 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 20 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnTransition: @ 824BCB1
# 21 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_setopponentgfx
# 22 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 23 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 24 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, DOME_ROUND1
# 25 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos
# 26 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 27 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 28 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 29 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx:: @ 824BCDC
# 30 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	checkplayergender
# 31 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, MALE
# 32 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale
# 33 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, FEMALE
# 34 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale
# 35 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 36 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 37 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxMale:: @ 824BCF4
# 38 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 39 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 40 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 41 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfxFemale:: @ 824BCFA
# 42 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 43 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 44 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 45 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnFrame: @ 824BD00
# 46 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom
# 47 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 48 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 49 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EnterRoom:: @ 824BD0A
# 50 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lockall
# 51 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 52 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, DOME_ROUND1
# 53 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat
# 54 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 55 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 56 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer
# 57 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome, MSGBOX_DEFAULT
# 58 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 59 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 60 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_F, DOME_FINAL
# 61 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter
# 62 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY
# 63 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker
# 64 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnter:: @ 824BD4E
# 65 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter
# 66 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer
# 67 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 68 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerEnterForTucker:: @ 824BD5A
# 69 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker
# 70 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceReactToPlayer:: @ 824BD61
# 71 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 72 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 73 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 74 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_F, DOME_FINAL
# 75 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent
# 76 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_E, FRONTIER_BRAIN_NOT_READY
# 77 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker
# 78 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleOpponent:: @ 824BD82
# 79 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 80 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer, MSGBOX_DEFAULT
# 81 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 82 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward
# 83 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward
# 84 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 85 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 86 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 87 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 88 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_initopponentparty
# 89 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 90 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, NO_DRAW
# 91 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 92 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 93 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 94 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 95 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TRAINER
# 96 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_Draw:: @ 824BDF7
# 97 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait, MSGBOX_DEFAULT
# 98 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 99 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 100 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 101 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 102 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter
# 103 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 104 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft
# 105 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 106 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 180
# 107 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_REFEREE, BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit
# 108 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 109 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_2, DRAW_TUCKER  @ Tucker always wins on a draw
# 110 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent
# 111 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_compareseeds
# 112 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 113 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent
# 114 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToOpponent:: @ 824BE4F
# 115 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 116 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 117 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getopponentname
# 118 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_2, NO_DRAW
# 119 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon
# 120 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_2, DRAW_TRAINER
# 121 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw
# 122 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_2, DRAW_TUCKER
# 123 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw
# 124 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 125 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 126 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 127 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney:: @ 824BE8D
# 128 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_LOST_MATCH
# 129 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobbyLost:: @ 824BE9A
# 130 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 131 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 132 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 133 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWon:: @ 824BEB1
# 134 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername 1
# 135 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner
# 136 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 137 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 138 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 139 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_OpponentWonDraw:: @ 824BEC5
# 140 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_gettrainername 0
# 141 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer
# 142 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 143 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 144 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 145 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerWonDraw:: @ 824BED9
# 146 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker
# 147 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 148 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 149 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 150 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent:: @ 824BEE0
# 151 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, Common_Movement_WalkInPlaceDown
# 152 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 153 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_2, NO_DRAW
# 154 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon
# 155 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_2, DRAW_TRAINER
# 156 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw
# 157 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 158 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 159 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 160 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_getroundtext
# 161 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 162 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 163 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addvar VAR_RESULT, 1
# 164 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 165 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 166 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUNDS_COUNT, BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 167 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8006, 1
# 168 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 255, 5, 3
# 169 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 170 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 171 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney:: @ 824BF62
# 172 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience
# 173 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 174 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 175 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 176 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney
# 177 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ, MSGBOX_DEFAULT
# 178 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin
# 179 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 180 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WonLvOpenTourney:: @ 824BF96
# 181 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp, MSGBOX_DEFAULT
# 182 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CelebrateWin:: @ 824BF9E
# 183 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoDomeConfetti
# 184 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 185 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 186 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 60
# 187 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 188 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby
# 189 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 190 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWon:: @ 824BFC3
# 191 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner, MSGBOX_DEFAULT
# 192 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 193 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 194 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_PlayerWonDraw:: @ 824BFCC
# 195 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer, MSGBOX_DEFAULT
# 196 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 197 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 198 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayer:: @ 824BFD5
# 199 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_ATTEMPTED_CHALLENGE
# 200 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 201 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt
# 202 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_HAS_WON_CHALLENGE
# 203 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 204 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon
# 205 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_get DOME_DATA_WIN_STREAK_ACTIVE
# 206 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 207 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak
# 208 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion
# 209 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 210 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 211 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttempt:: @ 824C023
# 212 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 213 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 214 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1
# 215 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2
# 216 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal
# 217 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal
# 218 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 219 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 220 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound1:: @ 824C05A
# 221 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope
# 222 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 223 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 224 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 225 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptRound2:: @ 824C061
# 226 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_RisingStar
# 227 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 228 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 229 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 230 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptSemifinal:: @ 824C068
# 231 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship
# 232 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 233 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 234 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerFirstAttemptFinal:: @ 824C06F
# 236 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry
# 237 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 238 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 239 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 240 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWon:: @ 824C076
# 241 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 242 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 243 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1
# 244 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2
# 245 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal
# 246 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal
# 247 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 248 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 249 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound1:: @ 824C0AD
# 250 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged
# 251 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 252 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 253 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 254 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonRound2:: @ 824C0B4
# 255 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship
# 256 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 257 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 258 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 259 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonSemifinal:: @ 824C0BB
# 260 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal
# 261 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 262 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 263 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 264 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerNeverWonFinal:: @ 824C0C2
# 265 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue
# 266 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 267 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 268 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 269 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampion:: @ 824C0C9
# 270 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_F, DOME_FINAL
# 271 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker
# 272 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 273 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 274 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 275 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver
# 276 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold
# 277 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionNoTucker:: @ 824C105
# 278 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 279 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 280 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1
# 281 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2
# 282 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal
# 283 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal
# 284 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 285 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 286 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound1:: @ 824C13C
# 287 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion
# 288 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 289 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 290 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 291 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionRound2:: @ 824C143
# 292 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer
# 293 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 294 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 295 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 296 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionSemifinal:: @ 824C14A
# 297 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer
# 298 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 299 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 300 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 301 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerChampionFinal:: @ 824C151
# 302 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle
# 303 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 304 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 305 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 306 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerSilver:: @ 824C158
# 307 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster, MSGBOX_DEFAULT
# 308 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 309 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 310 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerPreTuckerGold:: @ 824C161
# 311 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched, MSGBOX_DEFAULT
# 312 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 313 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 314 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreak:: @ 824C16A
# 315 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum
# 316 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 317 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND1, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1
# 318 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_ROUND2, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2
# 319 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_SEMIFINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal
# 320 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case DOME_FINAL, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal
# 321 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 322 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 323 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound1:: @ 824C1A1
# 324 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned
# 325 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 326 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 327 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 328 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakRound2:: @ 824C1A8
# 329 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned
# 330 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 331 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 332 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 333 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakSemifinal:: @ 824C1AF
# 334 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals
# 335 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 336 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 337 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 338 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnouncePlayerBrokenStreakFinal:: @ 824C1B6
# 339 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory
# 340 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 341 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 342 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 343 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_GetRoundNum:: @ 824C1BD
# 344 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 345 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 346 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 347 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTucker:: @ 824C1CB
# 348 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 349 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_SILVER, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 350 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 351 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver
# 352 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold
# 353 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 354 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerSilver:: @ 824C1FC
# 355 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker, MSGBOX_DEFAULT
# 356 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter
# 357 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AnnounceTuckerGold:: @ 824C209
# 359 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker, MSGBOX_DEFAULT
# 360 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerEnter:: @ 824C211
# 361 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 362 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_AUDIENCE_TWIN, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump
# 363 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_ANNOUNCER, BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance
# 364 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance
# 365 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 366 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 367 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 368 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 369 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 370 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 371 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 372 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 373 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 374 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 375 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 376 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 377 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 378 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 379 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 380 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 381 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant
# 382 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 383 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 384 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 385 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 386 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_TEMP_E
# 387 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro
# 388 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 389 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 390 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 391 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 392 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver
# 393 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro, MSGBOX_DEFAULT
# 394 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 395 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerSilver:: @ 824C2B9
# 396 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy, MSGBOX_DEFAULT
# 397 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 398 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 399 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 400 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 401 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 402 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 403 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 404 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 405 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 406 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 407 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 408 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 409 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 410 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass, MSGBOX_DEFAULT
# 411 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 412 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol
# 413 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 414 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 415 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 416 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime, MSGBOX_DEFAULT
# 417 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 418 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 419 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerGoldIntro:: @ 824C346
# 420 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 421 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 422 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold
# 423 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro, MSGBOX_DEFAULT
# 424 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 425 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_BattleTuckerGold:: @ 824C373
# 426 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess, MSGBOX_DEFAULT
# 427 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle
# 428 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	switch VAR_RESULT
# 429 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_LOST, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 430 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_FORFEITED, BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker
# 431 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	case B_OUTCOME_DREW, BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw
# 432 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer, MSGBOX_DEFAULT
# 433 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resolvewinners DOME_PLAYER_WON_MATCH
# 434 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getsymbols
# 435 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, 2
# 436 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 437 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 438 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer
# 439 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 440 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed, MSGBOX_DEFAULT
# 441 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 442 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	message BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine
# 443 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmessage
# 444 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitfanfare
# 445 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_givesymbol
# 446 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter, MSGBOX_DEFAULT
# 447 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_WonTourney
# 448 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 449 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoTuckerBattle:: @ 824C400
# 450 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker, MSGBOX_DEFAULT
# 451 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	closemessage
# 452 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2
# 453 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward
# 454 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitmovement 0
# 455 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle
# 456 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 457 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 458 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_LostToTucker:: @ 824C420
# 459 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker, MSGBOX_DEFAULT
# 460 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	playse SE_M_ENCORE2
# 461 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
# 462 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitse
# 463 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_LostTourney
# 464 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 465 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TuckerDraw:: @ 824C436
# 466 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_2, DRAW_TUCKER
# 467 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto BattleFrontier_BattleDomeBattleRoom_EventScript_Draw
# 468 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 469 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_DoDomeBattle:: @ 824C440
# 470 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, FALSE
# 471 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 472 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_DOME
# 473 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 474 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 1
# 475 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special DoSpecialTrainerBattle
# 476 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 477 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_9, 0
# 478 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_restorehelditems
# 479 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	special HealPlayerParty
# 480 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	dome_resetsketch
# 481 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 482 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 483 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnWarp: @ 824C481
# 484 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects
# 485 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.2byte 0
# 486 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 487 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetUpObjects:: @ 824C48B
# 488 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_DOME_BATTLE_ROOM
# 489 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 490 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_SetPlayerGfx
# 491 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 492 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible
# 493 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 494 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, DOME_FINAL
# 495 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 496 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	frontier_getbrainstatus
# 497 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_E, VAR_RESULT
# 498 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
# 499 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects
# 500 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 501 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_OPPONENT, 13, 9
# 502 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT
# 503 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT
# 504 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT, BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp
# 505 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_EndSetUpObjects:: @ 824C4EF
# 506 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 507 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 508 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_OnResume: @ 824C4F0
# 509 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_9, 1
# 510 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience
# 511 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 512 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 513 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_CallAddAudience:: @ 824C4FC
# 514 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience
# 515 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 516 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 517 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Add audience members to supplement the permanent object event audience
# 518 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddAudience:: @ 824C502
# 519 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_F, DOME_ROUND1
# 520 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience
# 521 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_F, DOME_ROUND2
# 522 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience
# 523 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_F, DOME_SEMIFINAL
# 524 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience
# 525 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_F, DOME_FINAL
# 526 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience
# 527 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 528 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 529 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound1Audience:: @ 824C52F
# 530 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 531 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 532 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddRound2Audience:: @ 824C530
# 533 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
# 534 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
# 535 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
# 536 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
# 537 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
# 538 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0, 3, DIR_SOUTH
# 539 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
# 540 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
# 541 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
# 542 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
# 543 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
# 544 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 545 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 546 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddSemifinalAudience:: @ 824C594
# 547 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
# 548 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
# 549 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
# 550 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0, 3, DIR_SOUTH
# 551 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
# 552 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0, 3, DIR_SOUTH
# 553 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
# 554 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 0, 3, DIR_SOUTH
# 555 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1, 3, DIR_SOUTH
# 556 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1, 3, DIR_SOUTH
# 557 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1, 3, DIR_SOUTH
# 558 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
# 559 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1, 3, DIR_SOUTH
# 560 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
# 561 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1, 3, DIR_SOUTH
# 562 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
# 563 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
# 564 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2, 3, DIR_SOUTH
# 565 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
# 566 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2, 3, DIR_SOUTH
# 567 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2, 3, 1
# 568 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 569 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 570 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AddFinalAudience:: @ 824C652
# 571 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 0, 2, 0, 3, DIR_SOUTH
# 572 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 1, 3, 0, 3, DIR_SOUTH
# 573 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 2, 15, 0, 3, DIR_SOUTH
# 574 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 3, 5, 0, 3, DIR_SOUTH
# 575 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 4, 6, 0, 3, DIR_SOUTH
# 576 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 5, 7, 0, 3, DIR_SOUTH
# 577 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 6, 8, 0, 3, DIR_SOUTH
# 578 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 7, 9, 0, 3, DIR_SOUTH
# 579 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 8, 10, 0, 3, DIR_SOUTH
# 580 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 9, 11, 0, 3, DIR_SOUTH
# 581 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 10, 12, 0, 3, DIR_SOUTH
# 582 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 11, 13, 0, 3, DIR_SOUTH
# 583 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 12, 14, 0, 3, DIR_SOUTH
# 584 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 13, 15, 2, 3, DIR_SOUTH
# 585 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 14, 12, 2, 3, DIR_SOUTH
# 586 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 15, 2, 1, 3, DIR_SOUTH
# 587 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 16, 3, 1, 3, DIR_SOUTH
# 588 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 17, 4, 1, 3, DIR_SOUTH
# 589 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 18, 6, 1, 3, DIR_SOUTH
# 590 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 19, 7, 1, 3, DIR_SOUTH
# 591 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 9, 1, 3, DIR_SOUTH
# 592 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_2, 21, 10, 1, 3, DIR_SOUTH
# 593 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 22, 11, 1, 3, DIR_SOUTH
# 594 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 23, 13, 1, 3, DIR_SOUTH
# 595 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 14, 1, 3, DIR_SOUTH
# 596 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 15, 1, 3, DIR_SOUTH
# 597 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 2, 2, 3, DIR_SOUTH
# 598 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 3, 2, 3, DIR_SOUTH
# 599 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 5, 2, 3, DIR_SOUTH
# 600 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 5, 1, 3, DIR_SOUTH
# 601 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 6, 2, 3, DIR_SOUTH
# 602 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 31, 8, 2, 3, DIR_SOUTH
# 603 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 604 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 605 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisible: @ 824C773
# 606 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 607 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 608 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 609 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter: @ 824C775
# 610 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 611 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 612 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 613 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 614 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 615 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 616 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward: @ 824C77B
# 617 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 618 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 619 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 620 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerApproachAudience: @ 824C77D
# 621 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 622 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 623 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 624 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Identical to Movement_PlayerEnter
# 625 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnterForTucker: @ 824C77F
# 626 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 627 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 628 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 629 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 630 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 631 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 632 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 633 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 634 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 635 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward2: @ 824C787
# 636 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 637 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 638 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 639 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_OpponentStepForward: @ 824C789
# 640 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 641 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 642 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 643 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_SetInvisibleFacingUp: @ 824C78B
# 644 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 645 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_invisible
# 646 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 647 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 648 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerEnterAndDance: @ 824C78E
# 649 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	set_visible
# 650 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 651 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 652 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_up
# 653 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 654 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 655 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 656 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 657 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 658 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 659 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 660 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 661 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 662 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 663 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 664 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 665 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 666 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 667 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 668 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_fast_up
# 669 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 670 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 671 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 672 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 673 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 674 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 675 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 676 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 677 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 678 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 679 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 680 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 681 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 682 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 683 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 684 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 685 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 686 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 687 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 688 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 689 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 690 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 691 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_2_left
# 692 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 693 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 694 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 695 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 696 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 697 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 698 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 699 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 700 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 701 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 702 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 703 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 704 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 705 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 706 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 707 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 708 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 709 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 710 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 711 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 712 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 713 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 714 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 715 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 716 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 717 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 718 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 719 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 720 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 721 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 722 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 723 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 724 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	lock_facing_direction
# 725 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 726 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 727 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 728 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_slow_right
# 729 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	unlock_facing_direction
# 730 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 731 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 732 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 733 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 734 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 735 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 736 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 737 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 738 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_up
# 739 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 740 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 741 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 742 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 743 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 744 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 745 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_up
# 746 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 747 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_right
# 748 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 749 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_down
# 750 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_2
# 751 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	face_left
# 752 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 753 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 754 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 755 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 756 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 757 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerMoveForTuckerEntrance: @ 824C7F9
# 758 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 759 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 760 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 761 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 762 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 763 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 764 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 765 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 766 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 767 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 768 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 769 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 770 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 771 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 772 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 773 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 774 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 775 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 776 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 777 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 778 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 779 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 780 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 781 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 782 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 783 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 784 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 785 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 786 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 787 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 788 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 789 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 790 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 791 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 792 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 793 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 794 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 795 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 796 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 797 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 798 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 799 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 800 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 801 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 802 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 803 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 804 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_fastest_down
# 805 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 806 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 807 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerStepForward: @ 824C829
# 808 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 809 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 810 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 811 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_TuckerApproachPlayer: @ 824C82B
# 812 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 813 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 814 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 815 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 816 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround:: @ 824C82E
# 817 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_EAST
# 818 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_EAST
# 819 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_EAST
# 820 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_EAST
# 821 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_EAST
# 822 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_WEST
# 823 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_WEST
# 824 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_WEST
# 825 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_WEST
# 826 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_WEST
# 827 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_EAST
# 828 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_EAST
# 829 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_EAST
# 830 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_EAST
# 831 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_EAST
# 832 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_EAST
# 833 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 834 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 0, DIR_SOUTH
# 835 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 2, DIR_SOUTH
# 836 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 4, DIR_SOUTH
# 837 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 6, DIR_SOUTH
# 838 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 8, DIR_SOUTH
# 839 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 10, DIR_SOUTH
# 840 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 12, DIR_SOUTH
# 841 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 14, DIR_SOUTH
# 842 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 16, DIR_SOUTH
# 843 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 18, DIR_SOUTH
# 844 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 20, DIR_SOUTH
# 845 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 22, DIR_SOUTH
# 846 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 24, DIR_SOUTH
# 847 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 26, DIR_SOUTH
# 848 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 28, DIR_SOUTH
# 849 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 30, DIR_SOUTH
# 850 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 851 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_EAST
# 852 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_EAST
# 853 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_EAST
# 854 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_EAST
# 855 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_EAST
# 856 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_WEST
# 857 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_WEST
# 858 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_WEST
# 859 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_WEST
# 860 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_WEST
# 861 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_EAST
# 862 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_EAST
# 863 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_EAST
# 864 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_WEST
# 865 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_WEST
# 866 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 867 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 1, DIR_SOUTH
# 868 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 3, DIR_SOUTH
# 869 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 5, DIR_SOUTH
# 870 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 7, DIR_SOUTH
# 871 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 9, DIR_SOUTH
# 872 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 11, DIR_SOUTH
# 873 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 13, DIR_SOUTH
# 874 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 15, DIR_SOUTH
# 875 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 17, DIR_SOUTH
# 876 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 19, DIR_SOUTH
# 877 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 21, DIR_SOUTH
# 878 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 23, DIR_SOUTH
# 879 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 25, DIR_SOUTH
# 880 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 27, DIR_SOUTH
# 881 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	turnvobject 31, DIR_SOUTH
# 882 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay 20
# 883 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 884 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 885 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_WarpToLobby:: @ 824C8F5
# 886 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_FRONTIER_BATTLE_MODE
# 887 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_RESULT, FRONTIER_MODE_DOUBLES
# 888 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles
# 889 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 5, 11
# 890 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 891 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 892 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 893 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomePreBattleRoom_EventScript_WarpToLobbyDoubles:: @ 824C90F
# 894 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_LOBBY, 255, 17, 11
# 895 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	waitstate
# 896 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	end
# 897 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 898 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ On round 1 there's a 50% chance that a specific audience member will walk to his seat
# 899 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_SetWalkingAudienceMemberPos:: @ 824C919
# 900 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	random 2
# 901 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 902 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_D, 0
# 903 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq Common_EventScript_NopReturn
# 904 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectxyperm LOCALID_AUDIENCE_WALKING, 2, 0
# 905 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	setobjectmovementtype LOCALID_AUDIENCE_WALKING, MOVEMENT_TYPE_FACE_RIGHT
# 906 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 907 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 908 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_EventScript_TryDoAudienceMemberWalkToSeat:: @ 824C938
# 909 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	compare VAR_TEMP_D, 0
# 910 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	goto_if_eq Common_EventScript_NopReturn
# 911 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	applymovement LOCALID_AUDIENCE_WALKING, BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat
# 912 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	return
# 913 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 914 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceTwinJump: @ 824C94B
# 915 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 916 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 917 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 918 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 919 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 920 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 921 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 922 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 923 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 924 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 925 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 926 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_16
# 927 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_8
# 928 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	disable_jump_landing_ground_effect
# 929 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 930 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	delay_4
# 931 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	jump_in_place_down
# 932 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	enable_jump_landing_ground_effect
# 933 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 934 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 935 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AudienceMemberWalkToSeat: @ 824C95E
# 936 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 937 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_down
# 938 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 939 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 940 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_fastest_down
# 941 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 942 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 943 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeEnter: @ 824C964
# 944 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 945 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 946 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 947 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_right
# 948 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 949 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 950 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_AnnouncerFaceLeft: @ 824C969
# 951 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_in_place_fastest_left
# 952 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 953 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 954 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Movement_RefereeExit: @ 824C96B
# 955 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 956 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 957 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 958 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	walk_left
# 959 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	step_end
# 960 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 961 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerHasEnteredDome: @ 824C970
# 962 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} has entered the BATTLE DOME!$"
# 963 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 964 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTrainer: @ 824C990
# 965 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_1}\n"
# 966 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "match!\p"
# 967 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus {STR_VAR_2}!\p"
# 968 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 969 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 970 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsWinner: @ 824C9BE
# 971 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the winner!\n"
# 972 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 973 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 974 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TrainerIsWinner: @ 824C9E1
# 975 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{STR_VAR_2} is the winner!\n"
# 976 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 977 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 978 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ: @ 824CA04
# 979 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 980 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 981 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 982 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 983 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp: @ 824CA44
# 984 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 985 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 986 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 987 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 988 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereeDecisionPleaseWait: @ 824CA86
# 989 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "What an unbelievable finish!\n"
# 990 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "We have a double knockout!\p"
# 991 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In this event, the Battle Tournament\n"
# 992 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "rules call for a REFEREE'S decision.\p"
# 993 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Please wait while the judging\n"
# 994 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "is under way.$"
# 995 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 996 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTrainer: @ 824CB34
# 997 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 998 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 999 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 1000 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 1001 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {STR_VAR_1}!\l"
# 1002 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1003 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1004 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerPlayer: @ 824CB9D
# 1005 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 1006 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 1007 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 1008 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 1009 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is {PLAYER}!\l"
# 1010 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1011 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1012 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_BrightNewHope: @ 824CC06
# 1013 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The bright new hope!\p"
# 1014 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1015 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1016 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RisingStar: @ 824CC1C
# 1017 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The rising star!\p"
# 1018 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1019 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1020 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillTheyRaceToChampionship: @ 824CC2E
# 1021 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this Trainer race to\n"
# 1022 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the championship?\p"
# 1023 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1024 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1025 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAchieveChampionFirstTry: @ 824CC5B
# 1026 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the feat of a championship\n"
# 1027 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "on the first try be achieved?\p"
# 1028 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1029 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1030 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanLossBeAvenged: @ 824CC99
# 1031 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the loss of the last match\n"
# 1032 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "be avenged?\p"
# 1033 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1034 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1035 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_OnFireForChampionship: @ 824CCC5
# 1036 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Trainer is on fire for\n"
# 1037 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the first championship try!\p"
# 1038 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1039 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1040 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinHereAdvancesToFinal: @ 824CCFD
# 1041 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "A win here means this Trainer\n"
# 1042 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "advances to the final!\p"
# 1043 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1044 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1045 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillLongHeldDreamComeTrue: @ 824CD33
# 1046 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the long-held dream of\n"
# 1047 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a championship finally come true?\p"
# 1048 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1049 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1050 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TheInvincibleChampion: @ 824CD72
# 1051 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The invincible champion!\p"
# 1052 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1053 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1054 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanAnyoneHopeToBeatTrainer: @ 824CD8C
# 1055 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can anyone hope to beat this\n"
# 1056 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Trainer?\p"
# 1057 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1058 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1059 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_DoBattlesExistSolelyForTrainer: @ 824CDB3
# 1060 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do battles exist solely for\n"
# 1061 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "this Trainer?\p"
# 1062 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1063 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1064 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CurrentChampAimingToRetainTitle: @ 824CDDE
# 1065 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The current champion aiming to\n"
# 1066 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "retain the title!\p"
# 1067 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1068 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1069 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerChampHasReturned: @ 824CE10
# 1070 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former champion has returned!\p"
# 1071 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1072 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1073 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FormerToughnessReturned: @ 824CE33
# 1074 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The former toughness has returned!\p"
# 1075 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1076 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1077 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillDoExpectedAdvanceToFinals: @ 824CE57
# 1078 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will this Trainer do as expected\n"
# 1079 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "and advance to the finals?\p"
# 1080 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1081 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1082 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WillFormerChampRegainGlory: @ 824CE94
# 1083 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Will the former champ regain\n"
# 1084 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "lost glory?\p"
# 1085 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "$"
# 1086 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1087 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_FeelGlowOfTrueMaster: @ 824CEBE
# 1088 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Feel the glow of a true master!$"
# 1089 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1090 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_MakeWayForDomeAceTucker: @ 824CEDE
# 1091 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "And now… The Trainer standing in\n"
# 1092 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER}'s record-setting path…\p"
# 1093 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes! The one and only!\n"
# 1094 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The BATTLE DOME COMMISSIONER!\l"
# 1095 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1096 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Make way for TUCKER!$"
# 1097 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1098 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SpectatorTuckerChant: @ 824CF7A
# 1099 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Spectators: TUCKER! TUCKER!\n"
# 1100 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER! TUCKER! TUCKER!$"
# 1101 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1102 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerSilverIntro: @ 824CFAE
# 1103 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ahahah!\p"
# 1104 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Do you hear it? This crowd!\n"
# 1105 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "They're all itching to see our match!\p"
# 1106 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ahahah!\p"
# 1107 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I bet you're twitching all over from\n"
# 1108 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the tension of getting to battle me!\p"
# 1109 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "But don't you worry about a thing!\p"
# 1110 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I'm the no. 1 star of the BATTLE DOME!\n"
# 1111 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I, TUCKER the DOME ACE, will bathe you\l"
# 1112 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "in my brilliant glow!$"
# 1113 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1114 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LetsSeeYourStrategy: @ 824D0D9
# 1115 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your strategy!\n"
# 1116 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's see it!$"
# 1117 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1118 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_IncredibleVictorIsPlayer: @ 824D0F6
# 1119 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Unbelievable! It's incredible!\n"
# 1120 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The victor is {PLAYER}!$"
# 1121 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1122 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WinnerIsTucker: @ 824D127
# 1123 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is TUCKER!\n"
# 1124 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The DOME ACE has prevailed!\p"
# 1125 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations, TUCKER!$"
# 1126 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1127 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_SeeYourFrontierPass: @ 824D172
# 1128 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Rules are rules!\n"
# 1129 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let me see your FRONTIER PASS.$"
# 1130 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1131 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_ReceivedTacticsSymbol: @ 824D1AA
# 1132 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol was embossed on\n"
# 1133 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "the FRONTIER PASS!$"
# 1134 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1135 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_WontUnderestimateYouNextTime: @ 824D1E0
# 1136 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "… … … … … …\p"
# 1137 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I sorely underestimated you. I won't\n"
# 1138 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "make the same mistake next time…$"
# 1139 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1140 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_CanWinStreakBeStretched: @ 824D232
# 1141 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Can the win streak be stretched?\n"
# 1142 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The confidence is there!$"
# 1143 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1144 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LegendHasReturnedDomeAceTucker: @ 824D26C
# 1145 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Ladies and gentlemen!\n"
# 1146 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Boys, girls, and Pokémon!\p"
# 1147 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally!\n"
# 1148 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Finally, the legend has returned!\p"
# 1149 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, the name of that legend!\n"
# 1150 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Our very own DOME ACE!\l"
# 1151 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's none other than TUCKER!$"
# 1152 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1153 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TuckerGoldIntro: @ 824D319
# 1154 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: Ah…\n"
# 1155 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The pummeling roar of the crowd…\l"
# 1156 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Their furnace-like heat of excitement…\l"
# 1157 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "This is a wonderful place…\p"
# 1158 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "To the crowd, I am the DOME ACE…\n"
# 1159 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I represent their hopes and dreams…\l"
# 1160 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must never fade from their sight…\p"
# 1161 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must burn!\n"
# 1162 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Brighter and more brilliant!\l"
# 1163 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I must light all that gather here!$"
# 1164 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1165 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_UnleashAllPowerIPossess: @ 824D43E
# 1166 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will unleash all the power that\n"
# 1167 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I possess! Right here and now!$"
# 1168 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1169 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_NeverLostWhenPowerUnleashed: @ 824D47F
# 1170 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "TUCKER: You're genuinely fantastic!\p"
# 1171 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Never before! I haven't ever lost in the\n"
# 1172 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "times I've had to unleash my power.\p"
# 1173 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Yes, quite fantastic!\n"
# 1174 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Your FRONTIER PASS, please?$"
# 1175 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1176 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_TacticsSymbolTookGoldenShine: @ 824D522
# 1177 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The Tactics Symbol took on\n"
# 1178 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a golden shine!$"
# 1179 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1180 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_LookForwardToNextEncounter: @ 824D54D
# 1181 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "You're strong, but above all,\n"
# 1182 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "you have a unique charm!\p"
# 1183 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "In you, I see a definite potential for\n"
# 1184 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a superstar like me.\p"
# 1185 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "I will very much look forward to\n"
# 1186 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "our next encounter!$"
# 1187 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1188 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1189 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLv50Champ2: @ 824D5F5
# 1190 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Level 50\n"
# 1191 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1192 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1193 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1194 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
@ Unused
# 1195 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerIsLvOpenChamp2: @ 824D635
# 1196 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} is the Open Level\n"
# 1197 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Battle Tournament Champion!\p"
# 1198 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations!$"
# 1199 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1200 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_PlayerVersusTucker: @ 824D677
# 1201 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The final match!\p"
# 1202 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "{PLAYER} versus the DOME ACE, TUCKER!\p"
# 1203 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let the battle begin!$"
# 1204 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"

# 1205 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
BattleFrontier_BattleDomeBattleRoom_Text_RefereesDecidedWinnerTucker: @ 824D6BE
# 1206 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The REFEREES have reached\n"
# 1207 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "a decision!\p"
# 1208 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is…\n"
# 1209 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Oh, my goodness!\l"
# 1210 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "The winner is our very own DOME ACE!\l"
# 1211 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "It's TUCKER!\p"
# 1212 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Congratulations! And thank you!\n"
# 1213 "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.pory"
	.string "Let's hear it for the DOME ACE, TUCKER!$"
