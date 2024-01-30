# 1 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
.set LOCALID_ATTENDANT_SINGLES, 1
# 3 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
.set LOCALID_ATTENDANT_DOUBLES, 6
# 4 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 5 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_MapScripts:: @ 82583E8
# 6 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
# 7 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
# 8 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.byte 0
# 9 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 10 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnWarp: @ 82583F3
# 11 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
# 12 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 13 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 14 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth:: @ 82583FD
# 15 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 16 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 17 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 18 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 19 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_OnFrame: @ 8258407
# 20 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
# 21 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
# 22 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
# 23 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
# 24 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
# 25 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.2byte 0
# 26 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 27 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus:: @ 8258431
# 28 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_getstatus
# 29 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 30 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 31 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving:: @ 825843A
# 32 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 33 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 34 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 35 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_setswapped
# 36 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
# 37 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK, 0
# 38 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 39 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 40 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 41 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 42 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 43 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 44 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge:: @ 825849B
# 45 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 46 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_isbrain
# 47 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 48 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
# 49 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
# 50 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 51 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints
# 52 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 53 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead:: @ 82584BD
# 54 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
# 55 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 56 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints:: @ 82584C6
# 57 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
# 58 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_givepoints
# 59 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 60 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
# 61 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 62 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 63 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 64 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 65 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 66 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 67 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
# 68 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 69 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 70 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge:: @ 8258506
# 71 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 72 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
# 73 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 74 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_checkairshow
# 75 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 76 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
# 77 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save 0
# 78 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 79 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 80 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 81 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle:: @ 825853B
# 82 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 83 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 84 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 85 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
# 86 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 87 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 88 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 90 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
# 91 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
# 92 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 93 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle:: @ 825857D
# 94 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 95 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle:: @ 8258582
# 96 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 97 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 98 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 99 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 100 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 101 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 102 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge:: @ 8258592
# 103 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 104 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
# 105 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 106 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_save CHALLENGE_STATUS_SAVING
# 107 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	playse SE_SAVE
# 108 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitse
# 109 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 110 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 111 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 112 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge
# 113 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 114 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant:: @ 82585CB
# 115 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 116 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	faceplayer
# 117 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 118 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 119 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 120 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 121 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 122 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant:: @ 82585DD
# 123 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 124 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 125 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
# 126 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 127 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 128 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Attendant:: @ 82585ED
# 129 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 130 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 131 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
# 132 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 133 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
# 134 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge:: @ 8258606
# 135 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 136 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
# 137 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 138 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
# 139 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 140 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 141 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 142 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
# 143 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
# 144 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 145 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 146 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 147 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge:: @ 8258653
# 148 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
# 149 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 150 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 151 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 152 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 153 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 154 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 155 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 156 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 157 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 158 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
# 159 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
# 160 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 161 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge:: @ 82586B9
# 162 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 163 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_init
# 164 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 165 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
# 166 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 167 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 168 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	delay 2
# 169 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 170 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 171 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_RESULT, 0
# 172 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
# 173 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 174 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge:: @ 825871A
# 175 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special SavePlayerParty
# 176 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 177 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	closemessage
# 178 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 179 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
# 180 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 181 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
# 182 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
# 183 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
# 184 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmovement 0
# 185 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 255, 8, 13
# 186 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 187 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitstate
# 188 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 189 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 190 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant:: @ 825875C
# 191 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
# 192 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 193 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 194 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant:: @ 8258762
# 195 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
# 196 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 197 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 198 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge:: @ 8258768
# 199 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 200 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
# 201 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 202 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
# 203 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge
# 204 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 205 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed:: @ 8258783
# 206 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 207 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
# 208 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 209 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge:: @ 825879A
# 210 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special LoadPlayerParty
# 211 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge:: @ 825879D
# 212 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 213 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 214 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 215 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 216 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor: @ 82587A7
# 217 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 218 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 219 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 220 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	set_invisible
# 221 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 222 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 223 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor: @ 82587AC
# 224 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 225 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 226 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 227 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	walk_up
# 228 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	step_end
# 229 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 230 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle:: @ 82587B1
# 231 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
# 232 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 233 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 234 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle:: @ 82587BA
# 235 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
# 236 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 237 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 238 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge:: @ 82587C3
# 239 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
# 240 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 241 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 242 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge:: @ 82587C9
# 243 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
# 244 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 245 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 246 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge:: @ 82587CF
# 247 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 248 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 249 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 250 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge:: @ 82587D8
# 251 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 252 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	return
# 253 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 254 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults:: @ 82587E1
# 255 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 256 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
# 257 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 258 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 259 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 260 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 261 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 262 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults:: @ 82587FA
# 263 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 264 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
# 265 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitbuttonpress
# 266 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	special RemoveRecordsWindow
# 267 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 268 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 269 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 270 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Woman:: @ 8258813
# 271 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
# 272 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 273 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 274 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Camper:: @ 825881C
# 275 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
# 276 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 277 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 278 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_Picnicker:: @ 8258825
# 279 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lock
# 280 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
# 281 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	release
# 282 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 283 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 284 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_FatMan:: @ 8258830
# 285 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
# 286 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 287 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 288 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard:: @ 8258839
# 289 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	lockall
# 290 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 291 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 292 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 293 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 294 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard:: @ 8258848
# 295 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 296 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	waitmessage
# 297 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
# 298 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	switch VAR_RESULT
# 299 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
# 300 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
# 301 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
# 302 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
# 303 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
# 304 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 305 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
# 306 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 307 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 308 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics:: @ 82588A6
# 309 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 310 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 311 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 312 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 313 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner:: @ 82588B4
# 314 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 315 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 316 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 317 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 318 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber:: @ 82588C2
# 319 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 320 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 321 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 322 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 323 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes:: @ 82588D0
# 324 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
# 325 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 326 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 327 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 328 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv:: @ 82588DE
# 329 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
# 330 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
# 331 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 332 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 333 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_EventScript_ExitRules:: @ 82588EC
# 334 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	releaseall
# 335 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	end
# 336 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 337 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle: @ 82588EE
# 338 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of Trainers\n"
# 339 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 340 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 341 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 342 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Single Tournament.$"
# 343 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 344 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge: @ 825897A
# 345 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 346 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Single challenge?$"
# 347 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 348 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge: @ 82589B3
# 349 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Single Tournament\n"
# 350 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a SINGLE BATTLE competition using\l"
# 351 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental Pokémon.\p"
# 352 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 353 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Pokémon specifically for this event.\p"
# 354 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental Pokémon,\n"
# 355 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a SINGLE BATTLE.\p"
# 356 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 357 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental Pokémon.\p"
# 358 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 359 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 360 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 361 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 362 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 363 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save, you will be\n"
# 364 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "disqualified from your challenge.$"
# 365 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 366 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit: @ 8258BC5
# 367 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We look forward to your next visit.$"
# 368 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 369 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode: @ 8258BE9
# 370 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which level do you wish to challenge?\n"
# 371 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Level 50 or Open Level?$"
# 372 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 373 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge: @ 8258C27
# 374 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before you begin your challenge,\n"
# 375 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the game. Is that okay?$"
# 376 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 377 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 378 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping: @ 8258C6F
# 379 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Okay, I will hold your Pokémon for\n"
# 380 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "safekeeping while you compete.$"
# 381 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 382 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_StepThisWay: @ 8258CB1
# 383 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please step this way.$"
# 384 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 385 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults: @ 8258CC7
# 386 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Thank you for participating!\p"
# 387 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your Pokémon in exchange\n"
# 388 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental Pokémon.\p"
# 389 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must also save the event results.\n"
# 390 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please wait.$"
# 391 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 392 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 393 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReturnMons: @ 8258D54
# 394 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I will return your Pokémon in exchange\n"
# 395 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental Pokémon.$"
# 396 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 397 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins: @ 8258D93
# 398 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations! You've won seven\n"
# 399 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "straight Battle Swap matches!$"
# 400 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 401 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 402 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak: @ 8258DD3
# 403 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your 7-win streak,\n"
# 404 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 405 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 406 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 407 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints: @ 8258E1C
# 408 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Oh, oh, oh!\p"
# 409 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Your Battle Points are maxed.\p"
# 410 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Please come back after using\n"
# 411 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "some Battle Points.$"
# 412 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 413 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume: @ 8258E77
# 414 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 415 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Before we resume your challenge,\n"
# 416 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I must save the game.$"
# 417 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 418 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting: @ 8258ECA
# 419 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I'm sorry to say this, but you didn't\n"
# 420 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "save before you quit playing last time.\p"
# 421 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "As a result, you have been disqualified\n"
# 422 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "from your challenge.$"
# 423 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 424 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 425 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons: @ 8258F55
# 426 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "We'll return your personal Pokémon.$"
# 427 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 428 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 429 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem: @ 8258F79
# 430 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 431 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 432 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 433 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle: @ 8258F93
# 434 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Where the intelligence of Trainers\n"
# 435 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is put to the test!\p"
# 436 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Welcome to the BATTLE FACTORY!\p"
# 437 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I am your guide to the Battle Swap\n"
# 438 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Double Tournament.$"
# 439 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 440 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge: @ 825901F
# 441 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 442 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Swap Double challenge?$"
# 443 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 444 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge: @ 8259058
# 445 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap Double Tournament\n"
# 446 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "is a Double Battle competition using\l"
# 447 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only rental Pokémon.\p"
# 448 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, you will be loaned three\n"
# 449 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Pokémon specifically for this event.\p"
# 450 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Using the supplied rental Pokémon,\n"
# 451 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you must conduct a Double Battle.\p"
# 452 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you win, you are permitted to trade\n"
# 453 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "one of your rental Pokémon.\p"
# 454 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Repeat this cycle of battling and\n"
# 455 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trading--if you win seven times in\l"
# 456 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a row, you will earn Battle Points.\p"
# 457 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 458 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 459 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 460 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "you will be disqualified.$"
# 461 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 462 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead: @ 825926A
# 463 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Congratulations for defeating\n"
# 464 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the FACTORY HEAD and winning\l"
# 465 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "seven matches in a row!$"
# 466 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 467 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints: @ 82592BD
# 468 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In recognition of your wealth of\n"
# 469 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "knowledge and keen intelligence,\l"
# 470 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 471 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 472 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave: @ 8259323
# 473 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Let me exchange your Pokémon\n"
# 474 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "for our rental Pokémon.\p"
# 475 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I need to save the battle data,\n"
# 476 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "so please wait.$"
# 477 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 478 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch: @ 8259388
# 479 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Would you like to record your last\n"
# 480 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "BATTLE FACTORY match on your\l"
# 481 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "FRONTIER PASS?$"
# 482 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 483 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves: @ 82593D7
# 484 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Hi!\n"
# 485 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You, there!\p"
# 486 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Are you thinking that the events here\n"
# 487 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are easy since you don't need to have\l"
# 488 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a raised team of Pokémon?\p"
# 489 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I wouldn't be too sure about winning\n"
# 490 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "that easily.\p"
# 491 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "If you don't have thorough knowledge\n"
# 492 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about Pokémon and their moves,\l"
# 493 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "it will be tough to keep winning.$"
# 494 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 495 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon: @ 82594E5
# 496 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I swapped for a weak Pokémon…\n"
# 497 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "I thought it was a good kind to have…\p"
# 498 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "They wiped the floor with us…$"
# 499 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 500 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons: @ 8259547
# 501 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Things haven't been going my way\n"
# 502 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "at all.\p"
# 503 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You need to check your opponent's\n"
# 504 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Pokémon during battle to see if\l"
# 505 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "they're any good.$"
# 506 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 507 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints: @ 82595C4
# 508 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You know how the staff here give you\n"
# 509 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "a few hints about your next opponent?\p"
# 510 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Well, I'm a full-grown man, but I have\n"
# 511 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "trouble figuring out their hints.$"
# 512 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 513 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
@ Unused
# 514 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried: @ 8259658
# 515 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Like, I'm really tough, but I get bored\n"
# 516 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "really easily, so I just kept swapping\l"
# 517 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and battling over and over.\p"
# 518 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "So anyway, when I kept entering\n"
# 519 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Battle Swap events, I noticed they\l"
# 520 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "varied the rental Pokémon.$"
# 521 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 522 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_RulesAreListed: @ 8259721
# 523 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "The Battle Swap rules are listed.$"
# 524 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 525 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading: @ 8259743
# 526 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 527 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 528 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules: @ 8259766
# 529 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In a Battle Swap event, you may use\n"
# 530 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "only three Pokémon.\p"
# 531 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Whether you are renting or swapping,\n"
# 532 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "your team may not have two or more\l"
# 533 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of the same Pokémon.$"
# 534 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 535 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules: @ 82597FB
# 536 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap Pokémon only with\n"
# 537 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the Trainer you have just defeated.\p"
# 538 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You may swap for only those Pokémon\n"
# 539 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "used by the beaten Trainer.$"
# 540 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 541 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules: @ 825987E
# 542 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "After every battle you win, you may\n"
# 543 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "swap for one of your defeated\l"
# 544 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "opponent's Pokémon.\p"
# 545 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "You will not be able to swap Pokémon\n"
# 546 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "with the seventh Trainer in the event.$"
# 547 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 548 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules: @ 8259920
# 549 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "There are two key points to be aware\n"
# 550 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "of when swapping Pokémon.\p"
# 551 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "First, when swapping, you can't check\n"
# 552 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the stats of the Pokémon you are\l"
# 553 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "about to receive.\p"
# 554 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "Second, the Pokémon on your team\n"
# 555 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are lined up in sequence, depending on\l"
# 556 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "the order in which you rented them.\p"
# 557 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "This sequence remains unchanged\n"
# 558 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "even when swaps are made.$"
# 559 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"

# 560 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules: @ 8259A5E
# 561 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "In the Open Level, the rental Pokémon\n"
# 562 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "and the opposing TRAINERS' Pokémon\l"
# 563 "data/maps/BattleFrontier_BattleFactoryLobby/scripts.pory"
	.string "are all Level 100.$"
