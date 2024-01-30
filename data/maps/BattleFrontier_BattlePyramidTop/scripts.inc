# 1 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
.set LOCALID_BRANDON, 2
# 4 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 5 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_MapScripts:: @ 82550A1
# 6 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_OnResume
# 7 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_OnFrame
# 8 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_OnTransition
# 9 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_OnWarp
# 10 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.byte 0
# 11 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 12 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_OnTransition: @ 82550B6
# 13 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	pyramid_updatelight 200, PYRAMID_LIGHT_SET_RADIUS
# 14 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_F, 1
# 15 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 16 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 17 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_OnWarp: @ 82550CE
# 18 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects
# 19 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.2byte 0
# 20 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 21 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects:: @ 82550D8
# 22 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_1, 1
# 23 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 24 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_TEMP_C, 0
# 25 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects
# 26 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setobjectxyperm LOCALID_BRANDON, 0, 0
# 27 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects:: @ 82550F3
# 28 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 29 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 30 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_OnResume: @ 82550F4
# 31 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_getbrainstatus
# 32 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, FRONTIER_BRAIN_NOT_READY
# 33 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus
# 34 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	call BattleFrontier_EventScript_SetBrainObjectGfx
# 35 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus:: @ 825510C
# 36 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	copyvar VAR_TEMP_C, VAR_RESULT
# 37 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_getstatus
# 38 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	switch VAR_TEMP_0
# 39 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case 0, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
# 40 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
# 41 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
# 42 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 43 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 44 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 45 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_DREW
# 46 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 47 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_FORFEITED
# 48 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 49 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 50 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 51 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_OnFrame: @ 825516E
# 52 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic
# 53 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidTop_EventScript_ShowMapName
# 54 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.2byte 0
# 55 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 56 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic:: @ 8255180
# 57 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playbgm MUS_B_PYRAMID_TOP, FALSE
# 58 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_E, 1
# 59 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 60 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 61 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_ShowMapName:: @ 825518A
# 62 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special ShowMapNamePopup
# 63 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_F, 0
# 64 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 65 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 66 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge:: @ 8255193
# 67 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	pyramid_save CHALLENGE_STATUS_SAVING
# 68 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special SavePlayerParty
# 69 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 70 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	pyramid_settrainers
# 71 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 72 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_F, 1
# 73 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 74 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 75 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_Attendant:: @ 82551D0
# 76 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	lock
# 77 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	faceplayer
# 78 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_TEMP_D, 0
# 79 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady
# 80 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_TEMP_C, FRONTIER_BRAIN_NOT_READY
# 81 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside
# 82 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo, MSGBOX_DEFAULT
# 83 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 84 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
# 85 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 86 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop
# 87 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 88 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath
# 89 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 90 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	message BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid
# 91 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmessage
# 92 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 93 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitfanfare
# 94 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 95 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon:: @ 825521A
# 96 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 97 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 13
# 98 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitstate
# 99 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 100 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 101 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady:: @ 8255236
# 102 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady, MSGBOX_DEFAULT
# 103 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 104 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 105 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 106 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside:: @ 8255240
# 107 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere, MSGBOX_DEFAULT
# 108 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
# 109 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_TEMP_D, 1
# 110 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 111 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 112 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 113 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon:: @ 8255256
# 114 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	lockall
# 115 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	switch VAR_TEMP_C
# 116 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold
# 117 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
# 118 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
# 119 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 120 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, FALSE
# 121 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
# 122 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special SpawnCameraObject
# 123 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
# 124 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 125 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure, MSGBOX_DEFAULT
# 126 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 127 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 128 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
# 129 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 130 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon, MSGBOX_DEFAULT
# 131 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver
# 132 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 133 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 134 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech:: @ 82552D0
# 135 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
# 136 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 137 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver:: @ 82552DA
# 138 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle, MSGBOX_DEFAULT
# 139 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
# 140 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playbgm MUS_B_PYRAMID_TOP, FALSE
# 141 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, 1
# 142 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver
# 143 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 144 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 145 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver:: @ 82552FB
# 146 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_getsymbols
# 147 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, 0
# 148 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
# 149 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease, MSGBOX_DEFAULT
# 150 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 151 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	message BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol
# 152 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmessage
# 153 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitfanfare
# 154 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_givesymbol
# 155 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting, MSGBOX_DEFAULT
# 156 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
# 157 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 158 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold:: @ 8255335
# 159 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 160 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, FALSE
# 161 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
# 162 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special SpawnCameraObject
# 163 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
# 164 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 165 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned, MSGBOX_DEFAULT
# 166 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 167 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 168 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
# 169 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 170 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter, MSGBOX_DEFAULT
# 171 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold
# 172 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	end
# 173 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 174 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech:: @ 8255388
# 175 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
# 176 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmovement 0
# 177 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold:: @ 8255392
# 178 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_EverythingYouHave, MSGBOX_DEFAULT
# 179 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
# 180 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playbgm MUS_B_PYRAMID_TOP, FALSE
# 181 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, 1
# 182 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold
# 183 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 184 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 185 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold:: @ 82553B3
# 186 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_getsymbols
# 187 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	compare VAR_RESULT, 2
# 188 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
# 189 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis, MSGBOX_DEFAULT
# 190 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 191 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	message BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine
# 192 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitmessage
# 193 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitfanfare
# 194 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	frontier_givesymbol
# 195 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	msgbox BattleFrontier_BattlePyramidTop_Text_FarewellForNow, MSGBOX_DEFAULT
# 196 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
# 197 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 198 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle:: @ 82553ED
# 199 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	closemessage
# 200 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PYRAMID
# 201 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	setvar VAR_0x8005, 0
# 202 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	special DoSpecialTrainerBattle
# 203 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	waitstate
# 204 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	return
# 205 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 206 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside: @ 82553FD
# 207 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_right
# 208 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_in_place_fastest_left
# 209 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 210 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 211 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath: @ 8255400
# 212 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_left
# 213 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_in_place_fastest_up
# 214 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 215 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 216 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop: @ 8255403
# 217 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 218 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 219 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 220 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 221 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_up
# 222 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_in_place_fastest_down
# 223 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 224 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 225 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer: @ 825540A
# 226 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_fast_down
# 227 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 228 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 229 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Movement_CameraPanUp: @ 825540C
# 230 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_slow_up
# 231 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	walk_slow_up
# 232 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	delay_16
# 233 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	step_end
# 234 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 235 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo: @ 8255410
# 236 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "It is a delight to see you here!\n"
# 237 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "You have reached the summit of\l"
# 238 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "the BATTLE PYRAMID!\p"
# 239 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Above here is the PYRAMID's\n"
# 240 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "lookout point.\p"
# 241 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "It is a place open only to those\n"
# 242 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "who have conquered the PYRAMID.\p"
# 243 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, please!\n"
# 244 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Up you go!$"
# 245 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 246 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid: @ 82554E8
# 247 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The PYRAMID's new conqueror!\n"
# 248 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Let the name {PLAYER} be known!$"
# 249 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 250 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere: @ 825551F
# 251 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "It is a delight to see you here!\p"
# 252 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Unfortunately, you were second by\n"
# 253 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "a mere fraction of time!\p"
# 254 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Our chief has already conquered\n"
# 255 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "the PYRAMID ahead of you.\p"
# 256 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "However, my young explorer…\n"
# 257 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "You are a Trainer!\p"
# 258 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Assert your power and take the glory\n"
# 259 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "of the pinnacle from our chief!\p"
# 260 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, please! When you are ready,\n"
# 261 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "take one more step of courage!$"
# 262 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 263 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure: @ 8255669
# 264 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Young adventurer…\p"
# 265 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Wouldn't you agree that explorations\n"
# 266 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "are the grandest of adventures?\p"
# 267 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your own wits!\p"
# 268 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your own strength!\p"
# 269 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your own Pokémon!\p"
# 270 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "And, above all, only your own courage\n"
# 271 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "to lead you through unknown worlds…$"
# 272 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 273 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon: @ 825573E
# 274 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Aah, yes, indeed this life is grand!\n"
# 275 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Grand, it is! Eh?\p"
# 276 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I'm BRANDON!\p"
# 277 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I'm the PYRAMID KING, which means\n"
# 278 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I'm in charge here.\p"
# 279 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Most people call me the chief!\p"
# 280 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "You coming here means you have\n"
# 281 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "that much confidence in yourself,\l"
# 282 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "am I right?\p"
# 283 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Hahahah!\n"
# 284 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "This should be exciting!$"
# 285 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 286 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle: @ 8255846
# 287 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, then!\n"
# 288 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Bring your courage to our battle!$"
# 289 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 290 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease: @ 8255873
# 291 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "BRANDON: Hahahah! Grand it was!\n"
# 292 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Grand, yes, indeed!\p"
# 293 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Well done! You've earned recognition!\n"
# 294 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your FRONTIER PASS, please!$"
# 295 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 296 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol: @ 82558E9
# 297 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The Brave Symbol was embossed on\n"
# 298 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "the FRONTIER PASS!$"
# 299 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 300 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting: @ 825591D
# 301 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Young explorer!\n"
# 302 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I look forward to our next meeting!$"
# 303 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 304 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned: @ 8255951
# 305 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "BRANDON: …You've finally returned,\n"
# 306 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "young explorer…\p"
# 307 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Your love of adventure seems to come\n"
# 308 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "deep from within your heart…\p"
# 309 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Yes… You are exactly as I was in\n"
# 310 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "my own youth…\p"
# 311 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "… … …Ah…\p"
# 312 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The passionate!\p"
# 313 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The dangerous!\p"
# 314 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The desperate!\p"
# 315 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Those days of death-defying,\n"
# 316 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "life-affirming adventures are back…$"
# 317 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 318 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter: @ 8255A6D
# 319 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, then!\p"
# 320 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I sense my own courage is off\n"
# 321 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "the meter!$"
# 322 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 323 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_EverythingYouHave: @ 8255AA1
# 324 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Everything you have!\n"
# 325 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I'm braced for it all!$"
# 326 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 327 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis: @ 8255ACD
# 328 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "BRANDON: Hahahah!\n"
# 329 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Remarkable!\l"
# 330 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Yes, it's grand, indeed!\p"
# 331 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Young explorer!\p"
# 332 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "You've bested me through and through!\n"
# 333 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Here! I want you to have this!$"
# 334 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 335 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine: @ 8255B59
# 336 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "The Brave Symbol took on\n"
# 337 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "a golden shine!$"
# 338 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 339 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_FarewellForNow: @ 8255B82
# 340 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Ah, yes! It just goes to show that\n"
# 341 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "I have much to learn still!\p"
# 342 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "May our paths cross again!\n"
# 343 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Farewell for now, young explorer!$"
# 344 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"

# 345 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady: @ 8255BFE
# 346 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "Now, when you are ready, take courage\n"
# 347 "data/maps/BattleFrontier_BattlePyramidTop/scripts.pory"
	.string "and step forward.$"
