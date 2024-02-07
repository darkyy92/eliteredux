# 1 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
.set LOCALID_ATTENDANT_SINGLES, 1
# 3 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
.set LOCALID_ATTENDANT_DOUBLES, 6
# 4 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 5 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_MapScripts:: @ 82497E2
# 6 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume
# 7 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame
# 8 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
# 9 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.byte 0
# 10 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnResume: @ 82497F2
# 12 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_initresultstree
# 13 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 14 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 15 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnWarp: @ 82497FB
# 16 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth
# 17 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.2byte 0
# 18 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 19 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TurnPlayerNorth:: @ 8249805
# 20 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 21 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 22 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 23 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 24 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_OnFrame: @ 824980F
# 25 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus
# 26 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving
# 27 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge
# 28 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleDomeLobby_EventScript_WonChallenge
# 29 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleDomeLobby_EventScript_LostChallenge
# 30 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.2byte 0
# 31 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 32 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_GetChallengeStatus:: @ 8249839
# 33 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_getstatus
# 34 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 35 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 36 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_QuitWithoutSaving:: @ 8249842
# 37 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 38 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 39 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 40 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK, 0
# 41 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
# 42 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 43 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 44 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 45 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 46 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 47 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 48 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WonChallenge:: @ 824989B
# 49 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 50 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 51 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_isbrain
# 52 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 53 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce
# 54 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney, MSGBOX_DEFAULT
# 55 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints
# 56 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 57 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DefeatedAce:: @ 82498C1
# 58 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker, MSGBOX_DEFAULT
# 59 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_GiveBattlePoints:: @ 82498C9
# 60 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints, MSGBOX_DEFAULT
# 61 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_givepoints
# 62 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 63 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
# 64 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 65 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 66 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 67 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkairshow
# 68 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 69 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_HAS_WON_CHALLENGE, TRUE
# 70 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, TRUE
# 71 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 72 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 73 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle
# 74 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 75 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_LostChallenge:: @ 8249940
# 76 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 77 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying, MSGBOX_DEFAULT
# 78 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved
# 79 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 80 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 81 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 82 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkairshow
# 83 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_WIN_STREAK_ACTIVE, FALSE
# 84 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_set DOME_DATA_ATTEMPTED_CHALLENGE, TRUE
# 85 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 86 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 87 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AskRecordBattle:: @ 8249991
# 88 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_save 0
# 89 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	playse SE_SAVE
# 90 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitse
# 91 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 92 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 93 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 94 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_RecordLastMatch
# 95 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 96 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 97 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 98 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 99 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RecordBattle
# 100 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_EndChallenge
# 101 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 102 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RecordBattle:: @ 82499E4
# 103 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 104 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EndChallenge:: @ 82499E9
# 105 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
# 106 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 107 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 108 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 109 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 110 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 111 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ResumeChallenge:: @ 82499F9
# 112 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 113 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou, MSGBOX_DEFAULT
# 114 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2
# 115 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 116 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_save CHALLENGE_STATUS_SAVING
# 117 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	playse SE_SAVE
# 118 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitse
# 119 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 120 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 121 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge
# 122 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 123 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendant:: @ 8249A35
# 124 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lock
# 125 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	faceplayer
# 126 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
# 127 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 128 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
# 129 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 130 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 131 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendant:: @ 8249A47
# 132 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lock
# 133 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	faceplayer
# 134 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_DOME
# 135 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 136 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome
# 137 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 138 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 139 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AttendantWelcome:: @ 8249A59
# 140 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special SavePlayerParty
# 141 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 142 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles
# 143 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 144 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles
# 145 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge:: @ 8249A72
# 146 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 147 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge
# 148 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 149 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge
# 150 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 151 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 152 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 153 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge
# 154 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge
# 155 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 2, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 156 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 157 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 158 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TryEnterChallenge:: @ 8249ABF
# 159 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_WhichLevelMode
# 160 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 161 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 162 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 163 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 164 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 165 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_checkineligible
# 166 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_0x8004, TRUE
# 167 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons
# 168 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 169 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 170 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 171 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 172 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 173 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 174 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 175 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 176 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_RESULT, 0
# 177 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 178 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 179 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 180 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case NO, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 181 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case YES, BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge
# 182 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge
# 183 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 184 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SaveBeforeChallenge:: @ 8249B60
# 185 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 186 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 187 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_init
# 188 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 189 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 190 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 191 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 192 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	delay 2
# 193 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 194 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 195 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_RESULT, 0
# 196 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed
# 197 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_inittrainers
# 198 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EnterChallenge:: @ 8249BC2
# 199 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special SavePlayerParty
# 200 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 201 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_settrainers
# 202 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome, MSGBOX_DEFAULT
# 203 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closemessage
# 204 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor
# 205 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special HealPlayerParty
# 206 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_DOME_CORRIDOR, 255, 23, 6
# 207 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 208 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 209 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 210 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 211 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainChallenge:: @ 8249BFA
# 212 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 213 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge
# 214 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 215 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge
# 216 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_AskTakeChallenge
# 217 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 218 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMons:: @ 8249C15
# 219 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 220 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50
# 221 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen
# 222 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 223 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLv50:: @ 8249C30
# 224 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 225 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge
# 226 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 227 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_NotEnoughValidMonsLvOpen:: @ 8249C3D
# 228 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 229 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge
# 230 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 231 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CancelChallengeSaveFailed:: @ 8249C4A
# 232 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 233 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge
# 234 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 235 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_LoadPartyCancelChallenge:: @ 8249C61
# 236 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special LoadPlayerParty
# 237 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CancelChallenge:: @ 8249C64
# 238 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain, MSGBOX_DEFAULT
# 239 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_EndCancelChallenge:: @ 8249C6C
# 240 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	release
# 241 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 242 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 243 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WalkToDoor:: @ 8249C6E
# 244 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 245 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor
# 246 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 247 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor
# 248 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 249 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmovement 0
# 250 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 251 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor
# 252 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 253 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor
# 254 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitdooranim
# 255 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 256 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor
# 257 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 258 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor
# 259 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor
# 260 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmovement 0
# 261 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 262 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor
# 263 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 264 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor
# 265 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitdooranim
# 266 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 267 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 268 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantWalkToDoor:: @ 8249CDD
# 269 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 270 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 271 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 272 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantWalkToDoor:: @ 8249CE5
# 273 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_WalkToDoor
# 274 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 275 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 276 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_SinglesAttendantEnterDoor:: @ 8249CED
# 277 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT_SINGLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
# 278 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 279 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 280 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_DoublesAttendantEnterDoor:: @ 8249CF5
# 281 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT_DOUBLES, BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor
# 282 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 283 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 284 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WelcomeSingles:: @ 8249CFD
# 285 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle, MSGBOX_DEFAULT
# 286 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 287 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 288 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_WelcomeDoubles:: @ 8249D06
# 289 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
# 290 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 291 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 292 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TakeSinglesChallenge:: @ 8249D0F
# 293 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge
# 294 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 295 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 296 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_TakeDoublesChallenge:: @ 8249D15
# 297 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge
# 298 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 299 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 300 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainSinglesChallenge:: @ 8249D1B
# 301 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 302 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 303 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 304 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExplainDoublesChallenge:: @ 8249D24
# 305 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 306 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 307 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 308 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_OpenSinglesDoor:: @ 8249D2D
# 309 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	opendoor 5, 4
# 310 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 311 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 312 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_OpenDoublesDoor:: @ 8249D33
# 313 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	opendoor 17, 4
# 314 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 315 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 316 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CloseSinglesDoor:: @ 8249D39
# 317 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closedoor 5, 4
# 318 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 319 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 320 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_CloseDoublesDoor:: @ 8249D3F
# 321 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	closedoor 17, 4
# 322 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 323 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 324 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_WalkToDoor: @ 8249D45
# 325 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 326 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 327 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 328 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 329 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 330 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 331 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 332 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_AttendantEnterDoor: @ 8249D4B
# 333 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 334 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	set_invisible
# 335 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 336 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 337 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Movement_PlayerEnterDoor: @ 8249D4E
# 338 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 339 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	walk_up
# 340 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	set_invisible
# 341 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	step_end
# 342 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 343 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowSinglesResults:: @ 8249D52
# 344 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 345 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES
# 346 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitbuttonpress
# 347 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special RemoveRecordsWindow
# 348 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 349 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 350 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 351 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowDoublesResults:: @ 8249D6B
# 352 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 353 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_DOUBLES
# 354 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitbuttonpress
# 355 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	special RemoveRecordsWindow
# 356 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 357 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 358 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 359 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree:: @ 8249D84
# 360 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_get DOME_DATA_PREV_TOURNEY_TYPE
# 361 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_RESULT, 0
# 362 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50
# 363 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_RESULT, 1
# 364 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50
# 365 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_RESULT, 2
# 366 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen
# 367 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	compare VAR_RESULT, 3
# 368 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen
# 369 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 370 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_showprevtourneytree
# 371 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitstate
# 372 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 373 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 374 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLv50:: @ 8249DC9
# 375 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50, MSGBOX_SIGN
# 376 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 377 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 378 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLv50:: @ 8249DD2
# 379 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50, MSGBOX_SIGN
# 380 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 381 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 382 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsSinglesLvOpen:: @ 8249DDB
# 383 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen, MSGBOX_SIGN
# 384 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 385 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 386 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_PrevTourneyResultsDoublesLvOpen:: @ 8249DE4
# 387 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen, MSGBOX_SIGN
# 388 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	return
# 389 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Maniac:: @ 8249DED
# 391 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	dome_getwinnersname
# 392 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough, MSGBOX_NPC
# 393 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 394 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 395 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Lass:: @ 8249DFE
# 396 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation, MSGBOX_NPC
# 397 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 398 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 399 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_FatMan:: @ 8249E07
# 400 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound, MSGBOX_NPC
# 401 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 402 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 403 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_Man:: @ 8249E10
# 404 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully, MSGBOX_NPC
# 405 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 406 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ A few OutsideWest event scripts are inserted here instead, two of which are unused
# 408 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man3:: @ 8249E19
# 409 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier, MSGBOX_NPC
# 410 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 411 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 412 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 413 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleDomeSign2:: @ 8249E22
# 414 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign2, MSGBOX_NPC
# 415 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 416 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 417 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 418 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnderConstructionSign:: @ 8249E2B
# 419 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction, MSGBOX_NPC
# 420 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 421 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 422 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesBoard:: @ 8249E34
# 423 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	lockall
# 424 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 425 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 426 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 427 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 428 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard:: @ 8249E43
# 429 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	message BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading
# 430 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	waitmessage
# 431 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	multichoice 17, 4, MULTI_BATTLE_DOME_RULES, FALSE
# 432 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	switch VAR_RESULT
# 433 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 0, BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup
# 434 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 1, BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree
# 435 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 2, BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO
# 436 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case 3, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
# 437 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleDomeLobby_EventScript_ExitRules
# 438 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 439 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 440 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesMatchup:: @ 8249E8B
# 441 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules, MSGBOX_DEFAULT
# 442 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 443 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 444 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 445 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesTourneyTree:: @ 8249E99
# 446 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree, MSGBOX_DEFAULT
# 447 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 448 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 449 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 450 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_RulesDoubleKO:: @ 8249EA7
# 451 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	msgbox BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules, MSGBOX_DEFAULT
# 452 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	goto BattleFrontier_BattleDomeLobby_EventScript_ReadRulesBoard
# 453 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 454 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 455 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_EventScript_ExitRules:: @ 8249EB5
# 456 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	releaseall
# 457 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	end
# 458 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 459 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle: @ 8249EB7
# 460 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Where the strategies of Trainers\n"
# 461 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are put to the test!\p"
# 462 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Welcome to the BATTLE DOME!\p"
# 463 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I am your guide to the SINGLE BATTLE\n"
# 464 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament.$"
# 465 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 466 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge: @ 8249F3A
# 467 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to challenge\n"
# 468 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the SINGLE BATTLE Tournament?$"
# 469 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 470 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain: @ 8249F74
# 471 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "We hope to see you again.$"
# 472 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 473 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge: @ 8249F8E
# 474 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The SINGLE BATTLE Tournament\n"
# 475 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "is exactly as the name suggests--\l"
# 476 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a tournament of SINGLE BATTLES.\p"
# 477 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "All participating Trainers must\n"
# 478 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "enter three Pokémon each.\p"
# 479 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In each battle, one of the three\n"
# 480 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Pokémon must be held in reserve.\p"
# 481 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The other two Pokémon can battle\n"
# 482 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "one at a time.\p"
# 483 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Choose the two battling Pokémon after\n"
# 484 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "examining the opponent's trio.\p"
# 485 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You win the tournament by defeating\n"
# 486 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "four Trainers.\p"
# 487 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Battle Points are awarded to\n"
# 488 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the tournament winner.\p"
# 489 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 490 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament, please save the game.\p"
# 491 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 492 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you will be disqualified.$"
# 493 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 494 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge: @ 824A1C6
# 495 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Before I show you to the BATTLE DOME,\n"
# 496 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I must save the data. Is that okay?$"
# 497 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 498 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WhichLevelMode: @ 824A210
# 499 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament offers two levels\n"
# 500 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "of challenge, Level 50 and Open Level.\l"
# 501 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Which is your choice?$"
# 502 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 503 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_SelectThreeMons: @ 824A26E
# 504 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Now select the three Pokémon that\n"
# 505 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you wish to enter, please.$"
# 506 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 507 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen: @ 824A2AB
# 508 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 509 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You don't have three eligible Pokémon.\p"
# 510 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Also, the Pokémon must be holding\n"
# 511 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "different kinds of items.\p"
# 512 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 513 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 514 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 515 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50: @ 824A353
# 516 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 517 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You don't have three eligible Pokémon.\p"
# 518 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You must have three different Pokémon\n"
# 519 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 520 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They also must be holding different\n"
# 521 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "kinds of items.\p"
# 522 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 523 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 524 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 525 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome: @ 824A437
# 526 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I will now show you to\n"
# 527 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the BATTLE DOME.$"
# 528 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 529 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting: @ 824A45F
# 530 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
# 531 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You didn't save before you quit your\n"
# 532 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "challenge last time.\p"
# 533 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Because of that, your challenge so far\n"
# 534 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "has been disqualified. Sorry!$"
# 535 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 536 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney: @ 824A4E9
# 537 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Congratulations for winning\n"
# 538 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "your Battle Tournament!$"
# 539 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 540 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 541 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize: @ 824A51D
# 542 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Here is your prize for your Battle\n"
# 543 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament victory.$"
# 544 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 545 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Used by Verdanturf Tent
# 546 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ReceivedPrize: @ 824A554
# 547 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 548 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 549 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 550 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Unused
# 551 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom: @ 824A56E
# 552 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Oh, your Bag appears to be full.\p"
# 553 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please make room in your Bag, then come\n"
# 554 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "see me.$"
# 555 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 556 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying: @ 824A5BF
# 557 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Thank you for playing!$"
# 558 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 559 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved: @ 824A5D6
# 560 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Your record will be saved.\n"
# 561 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Please wait.$"
# 562 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 563 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou: @ 824A5FE
# 564 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "We've been waiting for you!$"
# 565 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 566 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2: @ 824A61A
# 567 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Before I show you to the BATTLE DOME,\n"
# 568 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I must save the data. Is that okay?$"
# 569 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 570 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle: @ 824A664
# 571 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Where the strategies of Trainers\n"
# 572 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are put to the test!\p"
# 573 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Welcome to the BATTLE DOME!\p"
# 574 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I am your guide to the Double Battle\n"
# 575 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tournament.$"
# 576 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 577 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge: @ 824A6E7
# 578 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to challenge\n"
# 579 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the Double Battle Tournament?$"
# 580 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 581 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge: @ 824A721
# 582 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Double Battle Tournament\n"
# 583 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "is exactly as the name suggests--\l"
# 584 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a tournament of Double Battles.\p"
# 585 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "All participating Trainers must\n"
# 586 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "enter three Pokémon each.\p"
# 587 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In each battle, one of the three\n"
# 588 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Pokémon must be held in reserve.\p"
# 589 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The remaining two Pokémon must take\n"
# 590 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "part in a Double Battle.\p"
# 591 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Choose the two battling Pokémon after\n"
# 592 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "examining the opponent's trio.\p"
# 593 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You win the tournament by defeating\n"
# 594 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "four Trainers.\p"
# 595 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Battle Points are awarded to\n"
# 596 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the tournament winner.\p"
# 597 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 598 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament, please save the game.\p"
# 599 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 600 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "you will be disqualified.$"
# 601 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 602 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50: @ 824A966
# 603 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 604 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Level 50 SINGLE BATTLE Tournament.$"
# 605 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 606 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50: @ 824A9A9
# 607 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 608 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Level 50 Double Battle Tournament.$"
# 609 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 610 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen: @ 824A9EC
# 611 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 612 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Open Level SINGLE BATTLE Tournament.$"
# 613 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 614 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen: @ 824AA31
# 615 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last\n"
# 616 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Open Level Double Battle Tournament.$"
# 617 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 618 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough: @ 824AA76
# 619 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Did you see it?\n"
# 620 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The last Battle Tournament?\p"
# 621 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The winner, {STR_VAR_1}, was seriously\n"
# 622 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tough.\p"
# 623 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You should check out the results\n"
# 624 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "on the monitor beside the PC.$"
# 625 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 626 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier: @ 824AB06
# 627 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Battle Frontier…\n"
# 628 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I've long dreamed about a place like it.$"
# 629 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 630 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Functionally unused
# 631 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleDomeSign2: @ 824AB44
# 632 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The BATTLE DOME\n"
# 633 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Become the Unbeatable Superstar!$"
# 634 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 635 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
@ Functionally unused
# 636 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction: @ 824AB75
# 637 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The ??????\n"
# 638 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Under Construction!$"
# 639 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 640 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation: @ 824AB94
# 641 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "When a Trainer chains tournament\n"
# 642 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "wins at the BATTLE DOME, he or she\l"
# 643 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "gains a reputation as a star.\p"
# 644 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Tough Trainers are drawn by that\n"
# 645 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "reputation to the BATTLE DOME.\p"
# 646 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "A true superstar is a Trainer who\n"
# 647 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "can keep winning tournaments.$"
# 648 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 649 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound: @ 824AC76
# 650 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I ran into one of the tournament\n"
# 651 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "favorites in the very first round.\p"
# 652 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Of course I got trashed…$"
# 653 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 654 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully: @ 824ACD3
# 655 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I would've won if I'd kept this Pokémon\n"
# 656 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "held in reserve.\p"
# 657 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 658 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Pokémon carefully before choosing\l"
# 659 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "your battling Pokémon.$"
# 660 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 661 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker: @ 824AD67
# 662 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Congratulations!\p"
# 663 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "You defeated the DOME ACE and won\n"
# 664 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the Battle Tournament!$"
# 665 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 666 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints: @ 824ADB1
# 667 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In recognition of your strategy--\n"
# 668 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "a thing of beauty it was, too--\l"
# 669 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "we award you these Battle Point(s)!$"
# 670 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 671 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RecordLastMatch: @ 824AE17
# 672 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to record your\n"
# 673 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "last BATTLE DOME match on your\l"
# 674 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 675 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 676 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_RulesAreListed: @ 824AE63
# 677 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Battle Tournament rules\n"
# 678 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "are listed.$"
# 679 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 680 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading: @ 824AE8B
# 681 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 682 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 683 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules: @ 824AEAE
# 684 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament matchups are drawn up\n"
# 685 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "based on the toughness of Pokémon\l"
# 686 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "held by Trainers.\p"
# 687 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The matchups avoid having tough\n"
# 688 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Trainers face each other right away.$"
# 689 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 690 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree: @ 824AF4C
# 691 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament chart, or as we call it,\n"
# 692 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the “Tree,” is available for viewing\l"
# 693 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "in the Waiting Room from any guide.\p"
# 694 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Tournament Tree will provide\n"
# 695 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "several kinds of data.\p"
# 696 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The data on view includes the previous\n"
# 697 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "tournament's results, the Pokémon held\l"
# 698 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "by TRAINERS, and the battle styles of\l"
# 699 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Trainers.$"
# 700 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"

# 701 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules: @ 824B073
# 702 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If battling Pokémon faint at the same\n"
# 703 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "time--a double KO--in a tournament\l"
# 704 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "match, the REFEREES will review\l"
# 705 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "the match and declare the winner.$"
