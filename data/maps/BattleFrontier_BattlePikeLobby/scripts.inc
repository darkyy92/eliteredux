# 1 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 4 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_MapScripts:: @ 825B6C6
# 5 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
# 6 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
# 7 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.byte 0
# 8 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 9 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_OnFrame: @ 825B6D1
# 10 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
# 11 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
# 12 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
# 13 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
# 14 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.2byte 0
# 15 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 16 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_OnWarp: @ 825B6F3
# 17 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
# 18 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.2byte 0
# 19 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 20 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth:: @ 825B6FD
# 21 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 22 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 23 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 24 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 25 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus:: @ 825B707
# 26 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_getstatus
# 27 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 28 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 29 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving:: @ 825B710
# 30 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special HealPlayerParty
# 31 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_resethelditems
# 32 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 33 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
# 34 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 35 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK 0
# 36 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
# 37 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 38 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 39 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 40 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 41 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 42 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_WonChallenge:: @ 825B762
# 43 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 44 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_isbrain
# 45 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 46 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
# 47 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
# 48 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 49 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints
# 50 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 51 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen:: @ 825B784
# 52 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
# 53 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 54 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints:: @ 825B78D
# 55 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
# 56 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_givepoints
# 57 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 58 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_checkairshow
# 59 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_get PIKE_DATA_TOTAL_STREAKS
# 60 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	addvar VAR_RESULT, 1
# 61 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
# 62 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special LoadPlayerParty
# 63 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special HealPlayerParty
# 64 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_resethelditems
# 65 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
# 66 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 67 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_save 0
# 68 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	playse SE_SAVE
# 69 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitse
# 70 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
# 71 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 72 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 73 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 74 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 75 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 76 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_LostChallenge:: @ 825B806
# 77 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 78 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
# 79 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 80 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_checkairshow
# 81 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
# 82 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
# 83 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special LoadPlayerParty
# 84 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special HealPlayerParty
# 85 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_resethelditems
# 86 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_save 0
# 87 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	playse SE_SAVE
# 88 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitse
# 89 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
# 90 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 91 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 92 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 93 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 94 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 95 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_Attendant:: @ 825B868
# 96 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lock
# 97 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	faceplayer
# 98 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
# 99 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 100 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special SavePlayerParty
# 101 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
# 102 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge:: @ 825B87F
# 103 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
# 104 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 105 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 106 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 107 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
# 108 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
# 109 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 110 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 111 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 112 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge:: @ 825B8BB
# 113 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
# 114 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 115 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 116 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 117 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 118 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 119 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_checkineligible
# 120 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	compare VAR_0x8004, TRUE
# 121 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
# 122 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 123 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
# 124 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 125 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 126 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 127 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 128 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 129 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitstate
# 130 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	compare VAR_RESULT, 0
# 131 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
# 132 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
# 133 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 134 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
# 135 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
# 136 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
# 137 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 138 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge:: @ 825B95C
# 139 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 140 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_1, 0
# 141 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 142 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_init
# 143 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 144 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
# 145 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_savehelditems
# 146 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 147 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special LoadPlayerParty
# 148 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 149 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	delay 2
# 150 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 151 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 152 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	pike_savehelditems
# 153 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	compare VAR_RESULT, 0
# 154 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
# 155 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special SavePlayerParty
# 156 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 157 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 158 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	closemessage
# 159 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_settrainers
# 160 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
# 161 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special HealPlayerParty
# 162 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
# 163 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 255, 6, 7
# 164 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 165 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitstate
# 166 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 167 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 168 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge:: @ 825BA1A
# 169 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
# 170 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge
# 171 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 172 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons:: @ 825BA27
# 173 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 174 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
# 175 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen
# 176 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 177 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50:: @ 825BA42
# 178 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 179 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge
# 180 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 181 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen:: @ 825BA4F
# 182 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 183 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge
# 184 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 185 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed:: @ 825BA5C
# 186 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 187 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
# 188 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 189 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge:: @ 825BA73
# 190 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special LoadPlayerParty
# 191 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge:: @ 825BA76
# 192 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
# 193 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge:: @ 825BA7E
# 194 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	release
# 195 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 196 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 197 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_ShowResults:: @ 825BA80
# 198 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 199 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PIKE
# 200 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitbuttonpress
# 201 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special RemoveRecordsWindow
# 202 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 203 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 204 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 205 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor:: @ 825BA94
# 206 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
# 207 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
# 208 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmovement 0
# 209 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	return
# 210 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 211 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor: @ 825BAA6
# 212 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	walk_up
# 213 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor: @ 825BAA7
# 214 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	walk_up
# 215 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	walk_up
# 216 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	set_invisible
# 217 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	step_end
# 218 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 219 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_Hiker:: @ 825BAAB
# 220 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
# 221 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 222 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 223 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_Twin:: @ 825BAB4
# 224 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
# 225 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 226 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 227 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_Beauty:: @ 825BABD
# 228 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
# 229 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 230 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 231 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_RulesBoard:: @ 825BAC6
# 232 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	lockall
# 233 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 234 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
# 235 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 236 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 237 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard:: @ 825BAD5
# 238 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
# 239 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitmessage
# 240 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
# 241 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	switch VAR_RESULT
# 242 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
# 243 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
# 244 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
# 245 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
# 246 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
# 247 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 248 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 249 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag:: @ 825BB1D
# 250 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
# 251 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
# 252 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 253 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 254 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems:: @ 825BB2B
# 255 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
# 256 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
# 257 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 258 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 259 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder:: @ 825BB39
# 260 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
# 261 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
# 262 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 263 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 264 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_EventScript_ExitRules:: @ 825BB47
# 265 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	releaseall
# 266 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	end
# 267 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 268 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePike_EventScript_CloseCurtain:: @ 825BB49
# 269 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	playse SE_PIKE_CURTAIN_CLOSE
# 270 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	special CloseBattlePikeCurtain
# 271 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitstate
# 272 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	waitse
# 273 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	return
# 274 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 275 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike: @ 825BB52
# 276 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Where the luck of Trainers\n"
# 277 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "is put to the test…\p"
# 278 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Welcome to the BATTLE PIKE…\p"
# 279 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I am your guide to the BATTLE PIKE…$"
# 280 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 281 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_TakeChallenge: @ 825BBC1
# 282 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Would you like to take the Battle\n"
# 283 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Choice challenge?$"
# 284 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 285 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike: @ 825BBF5
# 286 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Here we conduct an event we call\n"
# 287 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "the Battle Choice.\p"
# 288 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "The Battle Choice rules are very\n"
# 289 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "simple…\p"
# 290 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Choose one of three paths and make\n"
# 291 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "your way to the goal room at the end\l"
# 292 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "of the BATTLE PIKE. It's that simple.\p"
# 293 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "However, what happens on the chosen\n"
# 294 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "path depends entirely on the luck\l"
# 295 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "of the challenger…\p"
# 296 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "If you reach the goal, you will be\n"
# 297 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "rewarded with Battle Points.\p"
# 298 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 299 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "challenge, please have a word with\l"
# 300 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "our staff in the big rooms on the way.\p"
# 301 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 302 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you will be disqualified.$"
# 303 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 304 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou: @ 825BE02
# 305 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "We look forward to seeing you\n"
# 306 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "on another occasion…$"
# 307 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 308 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode: @ 825BE35
# 309 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You have the choice of two courses,\n"
# 310 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Level 50 and Open Level.\l"
# 311 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Which will you challenge?$"
# 312 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 313 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50: @ 825BE8C
# 314 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I beg your pardon, but…\p"
# 315 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You do not have three eligible\n"
# 316 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Pokémon for the Battle Choice event.\p"
# 317 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You must have three different Pokémon\n"
# 318 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 319 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "They also must be holding different\n"
# 320 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "kinds of items.\p"
# 321 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 322 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please come see me when\n"
# 323 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you are ready…$"
# 324 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 325 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen: @ 825BF9A
# 326 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I beg your pardon, but…\p"
# 327 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You do not have three eligible\n"
# 328 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Pokémon for the Battle Choice event.\p"
# 329 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You must have three different\n"
# 330 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Pokémon to enter.\p"
# 331 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "They also must be holding different\n"
# 332 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "kinds of items.\p"
# 333 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 334 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please come see me when\n"
# 335 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you are ready…$"
# 336 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 337 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons: @ 825C094
# 338 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please choose the three Pokémon\n"
# 339 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you wish to enter in the challenge…$"
# 340 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 341 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge: @ 825C0D8
# 342 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Before starting your Battle Choice\n"
# 343 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "challenge, I must save the game.\l"
# 344 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Is that acceptable?$"
# 345 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 346 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_StepThisWay: @ 825C130
# 347 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please step this way…$"
# 348 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 349 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults: @ 825C146
# 350 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Your challenge has ended…\p"
# 351 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I shall record your results.\n"
# 352 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please wait…$"
# 353 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 354 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance: @ 825C18A
# 355 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You have completed the challenge…\p"
# 356 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I must say… You seem to possess luck\n"
# 357 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "in abundance…$"
# 358 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 359 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ShallRecordResults: @ 825C1DF
# 360 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I shall record your results.\n"
# 361 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Please wait…$"
# 362 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 363 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
@ Unused
# 364 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2: @ 825C209
# 365 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "To commemorate your completion of\n"
# 366 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "the Battle Choice challenge, we award\l"
# 367 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "you these Battle Point(s)…$"
# 368 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 369 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
@ Unused
# 370 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit: @ 825C26C
# 371 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You appear to have reached the limit\n"
# 372 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "for Battle Points…\pPlease exchange some Battle Points\n"
# 373 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "for prizes, then return…$"
# 374 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 375 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting: @ 825C2E0
# 376 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I beg your pardon, but…\p"
# 377 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You failed to save before you quit\n"
# 378 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "your challenge the last time.\p"
# 379 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Because of that, your challenge so far\n"
# 380 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "has been disqualified. I am sorry…$"
# 381 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 382 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen: @ 825C383
# 383 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Congratulations…\p"
# 384 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "You have snatched victory from the\n"
# 385 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "PIKE QUEEN and cleared the event…$"
# 386 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 387 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints: @ 825C3D9
# 388 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "In recognition of your amazing luck,\n"
# 389 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "we award you these Battle Point(s)…$"
# 390 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 391 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal: @ 825C422
# 392 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Arrgh! I blew my chance!\n"
# 393 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I was one room away from the goal!\p"
# 394 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "In this place, you'd better watch out\n"
# 395 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "for poison, freezing, and so on.$"
# 396 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 397 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer: @ 825C4A5
# 398 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I've completed the challenge 10 times\n"
# 399 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "now, but I've never had to battle\l"
# 400 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "a Trainer once.$"
# 401 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 402 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere: @ 825C4FD
# 403 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Listen! Listen!\p"
# 404 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Don't you think that the special\n"
# 405 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "abilities of Pokémon will be useful\l"
# 406 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "here?$"
# 407 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 408 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
@ Unused
# 409 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose: @ 825C558
# 410 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "What is this weird place?\n"
# 411 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I can't figure it out at all!\p"
# 412 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "I've taken the challenge a bunch\n"
# 413 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "of times, but all I ever do is run into\l"
# 414 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Trainers whichever path I choose.$"
# 415 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 416 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_RulesAreListed: @ 825C5FB
# 417 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "The Battle Choice's rules are listed.$"
# 418 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 419 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading: @ 825C621
# 420 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 421 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 422 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules: @ 825C644
# 423 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "The Bag and PokéNav may not be used\n"
# 424 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "during a Battle Choice challenge.$"
# 425 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 426 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules: @ 825C68A
# 427 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "During a Battle Choice challenge,\n"
# 428 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "any Berry or HERB held by Pokémon\l"
# 429 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "will be effective only once.$"
# 430 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"

# 431 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules: @ 825C6EB
# 432 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "During a Battle Choice challenge,\n"
# 433 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "the sequence of Pokémon cannot be\l"
# 434 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "changed.\p"
# 435 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "The sequence must be set before\n"
# 436 "data/maps/BattleFrontier_BattlePikeLobby/scripts.pory"
	.string "starting your challenge.$"
