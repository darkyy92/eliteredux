# 1 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
.set LOCALID_HINT_GIVER, 2
# 4 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 5 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_MapScripts:: @ 8250716
# 6 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
# 7 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
# 8 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.byte 0
# 9 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 10 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
# 11 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_OnWarp: @ 8250721
# 12 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
# 13 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.2byte 0
# 14 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 15 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth: @ 825072B
# 16 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 17 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 18 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 20 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_OnFrame: @ 8250735
# 21 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
# 22 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
# 23 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
# 24 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
# 25 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
# 26 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.2byte 0
# 27 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 28 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus:: @ 825075F
# 29 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_getstatus
# 30 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 31 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 32 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving:: @ 8250768
# 33 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 34 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
# 35 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 36 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 37 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 38 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 39 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
# 40 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
# 41 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 42 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 43 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 44 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 45 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 46 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge:: @ 82507B1
# 47 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 48 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_isbrain
# 49 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 50 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
# 51 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
# 52 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints
# 53 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 54 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing:: @ 82507D2
# 55 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
# 56 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints:: @ 82507DA
# 57 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special DoBattlePyramidMonsHaveHeldItem
# 58 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 59 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call_if_eq BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
# 60 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
# 61 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkairshow
# 62 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 63 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_clearhelditems
# 64 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 65 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
# 66 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 67 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 68 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 69 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
# 70 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_givepoints
# 71 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 72 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
# 73 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 74 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_setprize
# 75 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_save 0
# 76 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_SAVE
# 77 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 78 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
# 79 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 80 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 81 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 82 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 83 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 84 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge:: @ 8250852
# 85 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkairshow
# 86 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 87 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_clearhelditems
# 88 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 89 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 90 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
# 91 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 92 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 93 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 94 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
# 95 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 96 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
# 97 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_save 0
# 98 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_SAVE
# 99 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 100 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
# 101 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 102 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 103 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 104 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 105 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 106 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge:: @ 82508AC
# 107 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge
# 108 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 109 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_Attendant:: @ 82508B1
# 110 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lock
# 111 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	faceplayer
# 112 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
# 113 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 114 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special SavePlayerParty
# 115 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
# 116 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge:: @ 82508C8
# 117 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
# 118 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 119 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 120 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 121 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
# 122 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
# 123 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 124 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 125 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 126 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge:: @ 8250904
# 127 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
# 128 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 129 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 130 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 131 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 132 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 133 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_checkineligible
# 134 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_0x8004, TRUE
# 135 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
# 136 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 137 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 138 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 139 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 140 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 141 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 142 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 143 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 144 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, 0
# 145 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 146 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
# 147 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 148 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 149 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
# 150 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
# 151 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 152 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge:: @ 82509A5
# 153 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 154 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 155 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_init
# 156 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
# 157 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 158 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 159 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_seedfloor
# 160 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_settrainers
# 161 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 162 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 163 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	delay 2
# 164 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 165 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 166 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, 0
# 167 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
# 168 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge:: @ 8250A21
# 169 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special SavePlayerParty
# 170 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 171 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
# 172 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 173 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
# 174 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 175 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 176 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special HealPlayerParty
# 177 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 255, 1, 1
# 178 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 179 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 180 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 181 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 182 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge:: @ 8250A68
# 183 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
# 184 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge
# 185 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 186 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons:: @ 8250A75
# 187 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 188 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
# 189 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen
# 190 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 191 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50:: @ 8250A90
# 192 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 193 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge
# 194 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 195 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen:: @ 8250A9D
# 196 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 197 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge
# 198 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 199 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed:: @ 8250AAA
# 200 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 201 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
# 202 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 203 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge:: @ 8250AC1
# 204 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special LoadPlayerParty
# 205 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge:: @ 8250AC4
# 206 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
# 207 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge:: @ 8250ACC
# 208 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	release
# 209 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 210 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 211 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintGiver:: @ 8250ACE
# 212 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 213 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_HINT_GIVER, Common_Movement_FacePlayer
# 214 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 215 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
# 216 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
# 217 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
# 218 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 219 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 220 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 221 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHint:: @ 8250AF0
# 222 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 223 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 224 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
# 225 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
# 226 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
# 227 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
# 228 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 229 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 230 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Shouldnt occur
# 231 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_NoHint:: @ 8250B27
# 232 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 233 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 234 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50:: @ 8250B28
# 235 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
# 236 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
# 237 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, FALSE
# 238 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
# 239 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 240 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 241 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 242 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 243 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak:: @ 8250B53
# 244 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
# 245 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 246 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 247 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 248 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen:: @ 8250B66
# 249 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
# 250 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
# 251 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, FALSE
# 252 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
# 253 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 254 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 255 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 256 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 257 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak:: @ 8250B91
# 258 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
# 259 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
# 260 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 261 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 262 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment:: @ 8250BA4
# 263 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 264 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special GetBattlePyramidHint
# 265 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 266 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
# 267 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
# 268 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
# 269 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
# 270 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
# 271 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
# 272 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
# 273 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
# 274 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
# 275 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
# 276 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
# 277 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
# 278 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
# 279 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
# 280 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
# 281 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
# 282 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
# 283 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
# 284 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
# 285 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
# 286 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 287 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 288 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis:: @ 8250C8E
# 289 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
# 290 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 291 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 292 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPoison:: @ 8250C97
# 293 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
# 294 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 295 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 296 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintBurn:: @ 8250CA0
# 297 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
# 298 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 299 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 300 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste:: @ 8250CA9
# 301 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
# 302 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 303 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 304 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate:: @ 8250CB2
# 305 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
# 306 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 307 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 308 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility:: @ 8250CBB
# 309 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
# 310 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 311 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 312 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintIce:: @ 8250CC4
# 313 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
# 314 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 315 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 316 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion:: @ 8250CCD
# 317 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
# 318 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 319 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 320 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic:: @ 8250CD6
# 321 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
# 322 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 323 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 324 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintRock:: @ 8250CDF
# 325 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
# 326 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 327 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 328 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintFighting:: @ 8250CE8
# 329 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
# 330 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 331 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 332 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintWeather:: @ 8250CF1
# 333 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
# 334 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 335 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 336 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintBug:: @ 8250CFA
# 337 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
# 338 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 339 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 340 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintDark:: @ 8250D03
# 341 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
# 342 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 343 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 344 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintWater:: @ 8250D0C
# 345 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
# 346 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 347 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 348 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintGhost:: @ 8250D15
# 349 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
# 350 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 351 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 352 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintSteel:: @ 8250D1E
# 353 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
# 354 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 355 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 356 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon:: @ 8250D27
# 357 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
# 358 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 359 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 360 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve:: @ 8250D30
# 361 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
# 362 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 363 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 364 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HintNormal:: @ 8250D39
# 365 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
# 366 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 367 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 368 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ShowResults:: @ 8250D42
# 369 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 370 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_PYRAMID
# 371 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitbuttonpress
# 372 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special RemoveRecordsWindow
# 373 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 374 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 375 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 376 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag:: @ 8250D56
# 377 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
# 378 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
# 379 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 380 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
# 381 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	pyramid_get PYRAMID_DATA_WIN_STREAK
# 382 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, 0
# 383 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
# 384 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
# 385 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag
# 386 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 387 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag:: @ 8250D94
# 388 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
# 389 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag:: @ 8250D9C
# 390 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
# 391 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 392 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	playse SE_EXP_MAX
# 393 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitse
# 394 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
# 395 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	closemessage
# 396 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
# 397 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 398 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
# 399 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmovement 0
# 400 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 401 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 402 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel: @ 8250DC4
# 403 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 404 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 405 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 406 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 407 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 408 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 409 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 410 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	face_down
# 411 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 412 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 413 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel: @ 8250DCD
# 414 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 415 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 416 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 417 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 418 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 419 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 420 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 421 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 422 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 423 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside: @ 8250DD5
# 424 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_right
# 425 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	face_left
# 426 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 427 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 428 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel: @ 8250DD8
# 429 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 430 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	walk_up
# 431 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	step_end
# 432 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 433 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag:: @ 8250DDB
# 434 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
# 435 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
# 436 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special TryStoreHeldItemsInPyramidBag
# 437 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, 0
# 438 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
# 439 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
# 440 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 441 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 442 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 443 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 444 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag:: @ 8250E00
# 445 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
# 446 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 447 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 448 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
# 449 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep:: @ 8250E09
# 450 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
# 451 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 452 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
# 453 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
# 454 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
# 455 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
# 456 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 457 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 458 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag:: @ 8250E40
# 459 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special ChooseItemsToTossFromPyramidBag
# 460 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 461 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 462 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 463 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 464 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 465 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 466 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty:: @ 8250E50
# 467 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special BattlePyramidChooseMonHeldItems
# 468 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitstate
# 469 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 470 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 471 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 472 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 473 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 474 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems:: @ 8250E60
# 475 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	special DoBattlePyramidMonsHaveHeldItem
# 476 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 477 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
# 478 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	return
# 479 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 480 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems:: @ 8250E6F
# 481 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
# 482 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
# 483 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 484 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
# 485 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 486 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 487 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_Woman:: @ 8250E83
# 488 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
# 489 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 490 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 491 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_FatMan:: @ 8250E8C
# 492 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
# 493 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 494 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 495 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard:: @ 8250E95
# 496 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	lockall
# 497 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 498 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 499 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 500 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 501 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard:: @ 8250EA4
# 502 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
# 503 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	waitmessage
# 504 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
# 505 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	switch VAR_RESULT
# 506 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
# 507 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
# 508 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
# 509 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
# 510 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
# 511 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
# 512 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 513 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 514 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon:: @ 8250EF7
# 515 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
# 516 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 517 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 518 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 519 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers:: @ 8250F05
# 520 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
# 521 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 522 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 523 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 524 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze:: @ 8250F13
# 525 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
# 526 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 527 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 528 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 529 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_RulesBag:: @ 8250F21
# 530 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
# 531 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
# 532 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 533 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 534 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_EventScript_ExitRules:: @ 8250F2F
# 535 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	releaseall
# 536 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	end
# 537 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 538 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid: @ 8250F31
# 539 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Where the courage of Trainers\n"
# 540 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "is put to the test!\p"
# 541 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome to the BATTLE PYRAMID!\p"
# 542 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I am your guide to\n"
# 543 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the Battle Quest.$"
# 544 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 545 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge: @ 8250FA7
# 546 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Have you the courage to embark on\n"
# 547 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the Battle Quest challenge?$"
# 548 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 549 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge: @ 8250FE5
# 550 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We await your challenge in the future!$"
# 551 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 552 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid: @ 825100C
# 553 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The Battle Quest is a battling\n"
# 554 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "event in which you must explore\l"
# 555 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID and try to reach the top.\p"
# 556 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In the PYRAMID are seven floors of\n"
# 557 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "mazes, all of them filled with not only\l"
# 558 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "skilled Trainers but also wild Pokémon.\p"
# 559 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You must enter with three Pokémon,\n"
# 560 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "none of them holding an item.\p"
# 561 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "On your ascent, you will be provided\n"
# 562 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "with a BATTLE Bag for items.\p"
# 563 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you fail in your challenge, any item\n"
# 564 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "placed in the BATTLE Bag disappears.\p"
# 565 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 566 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "challenge, you must select “REST”\l"
# 567 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and save the game.\p"
# 568 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 569 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "you will be disqualified.$"
# 570 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 571 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode: @ 8251248
# 572 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The PYRAMID offers two courses,\n"
# 573 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Level 50 and Open Level.\l"
# 574 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Which will you enter?$"
# 575 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 576 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons: @ 8251297
# 577 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Very good. Now, please select the three\n"
# 578 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Pokémon you wish to accompany you.$"
# 579 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 580 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen: @ 82512E2
# 581 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A slight problem, adventurer!\p"
# 582 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You seem to not have the three\n"
# 583 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Pokémon qualified for the challenge.\p"
# 584 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please also remember to take all\n"
# 585 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items from your Pokémon.\p"
# 586 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 587 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you are ready, please have\n"
# 588 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "a word with me.$"
# 589 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 590 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50: @ 82513C1
# 591 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A slight problem, adventurer!\p"
# 592 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You seem to not have the three\n"
# 593 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Pokémon qualified for the challenge.\p"
# 594 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The three Pokémon must be different\n"
# 595 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and each no higher than Level 50.\p"
# 596 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please also remember to take all\n"
# 597 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items from your Pokémon.\p"
# 598 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 599 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you are ready, please have\n"
# 600 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "a word with me.$"
# 601 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 602 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge: @ 82514E6
# 603 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Before you enter the BATTLE PYRAMID,\n"
# 604 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the game must be saved. Is that okay?$"
# 605 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 606 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid: @ 8251531
# 607 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Very good. I will now show you into\n"
# 608 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE PYRAMID.$"
# 609 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 610 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping: @ 8251569
# 611 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We will hold your Bag for safekeeping,\n"
# 612 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER}, while you are exploring.$"
# 613 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 614 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag: @ 82515AD
# 615 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In exchange, please take this BATTLE\n"
# 616 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BAG, the one you used previously.$"
# 617 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 618 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag: @ 82515F4
# 619 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In exchange, please take this\n"
# 620 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE Bag.$"
# 621 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 622 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag: @ 825161E
# 623 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} exchanged the Bag for\n"
# 624 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE Bag.$"
# 625 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 626 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel: @ 8251647
# 627 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you step on this floor panel,\n"
# 628 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "you will be transported to a higher\l"
# 629 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "floor in the PYRAMID.\p"
# 630 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I hope for your sake that your\n"
# 631 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "quest goes safely!$"
# 632 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 633 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag: @ 82516D6
# 634 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A major problem, explorer!\p"
# 635 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You did not save before ending\n"
# 636 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your challenge the last time.\p"
# 637 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Consequently, your challenge has\n"
# 638 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "been disqualified, I'm sorry to say.\p"
# 639 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is the Bag we've been holding\n"
# 640 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for you.\p"
# 641 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} got the Bag back.$"
# 642 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 643 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid: @ 82517B5
# 644 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Excellent to see you back!\p"
# 645 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've conquered the PYRAMID!\n"
# 646 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "How splendid!$"
# 647 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 648 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake: @ 82517FC
# 649 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Ah, a slight problem.\p"
# 650 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "At least one Pokémon is holding\n"
# 651 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "an item.\p"
# 652 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I'm sorry to say, items obtained in\n"
# 653 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID cannot be taken away.$"
# 654 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 655 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag: @ 8251881
# 656 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "All items held by your Pokémon will be\n"
# 657 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "moved to your BATTLE Bag, {PLAYER}.$"
# 658 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 659 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep: @ 82518C6
# 660 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE Bag cannot hold all your\n"
# 661 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "items, I'm sorry to say.\p"
# 662 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please pick the items you'll keep in the\n"
# 663 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE Bag, and with your Pokémon.$"
# 664 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 665 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem: @ 825194F
# 666 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "At least one Pokémon is still\n"
# 667 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "holding an item.$"
# 668 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 669 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep: @ 825197E
# 670 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please pick the items you'll keep in the\n"
# 671 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "BATTLE Bag, and with your Pokémon.$"
# 672 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 673 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 674 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld: @ 82519CA
# 675 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} returned everything that\n"
# 676 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the Pokémon held.$"
# 677 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 678 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept: @ 82519F8
# 679 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE Bag you used will be kept\n"
# 680 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "in readiness for your next challenge.\p"
# 681 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} turned the BATTLE Bag over\n"
# 682 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for the Bag's return.$"
# 683 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 684 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait: @ 8251A77
# 685 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I must record your results.\n"
# 686 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please wait.$"
# 687 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 688 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 689 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis: @ 8251AA0
# 690 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "As a memento for conquering\n"
# 691 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the BATTLE PYRAMID, please take this.$"
# 692 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 693 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 694 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem: @ 8251AE2
# 695 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 696 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 697 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 698 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 699 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BagIsFull: @ 8251AFC
# 700 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…Ah…\n"
# 701 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Your Bag appears to be filled.\p"
# 702 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please return after you've organized\n"
# 703 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your Bag's contents.$"
# 704 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 705 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag: @ 8251B5A
# 706 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "How disappointing for you…\p"
# 707 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is the Bag we've been holding\n"
# 708 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "for you.\p"
# 709 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} got the Bag back.$"
# 710 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 711 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge: @ 8251BB6
# 712 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We look forward to your\n"
# 713 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "next challenge!$"
# 714 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 715 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
@ Unused
# 716 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize: @ 8251BDE
# 717 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We have been looking forward to\n"
# 718 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "your arrival!\p"
# 719 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Here is your prize for conquering\n"
# 720 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the PYRAMID.$"
# 721 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 722 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait: @ 8251C3B
# 723 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome…\p"
# 724 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I shall be pleased to tell you what\n"
# 725 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "misfortunes await in the PYRAMID…$"
# 726 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 727 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_Aah: @ 8251C8A
# 728 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\n"
# 729 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\p"
# 730 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … …\n"
# 731 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Aah!$"
# 732 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 733 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintParalysis: @ 8251CB3
# 734 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see a shower of sparks…\p"
# 735 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And in it, I see your Pokémon\n"
# 736 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "struggling with paralysis…$"
# 737 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 738 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPoison: @ 8251D07
# 739 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see poison…\p"
# 740 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 741 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from the effects of poison…$"
# 742 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 743 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintBurn: @ 8251D54
# 744 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see bright red flames…\p"
# 745 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 746 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from burns…$"
# 747 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 748 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPPWaste: @ 8251D9C
# 749 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I sense the tremendous pressure of\n"
# 750 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "unrequited anger…\p"
# 751 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "It is a curse…\p"
# 752 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon drained of\n"
# 753 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Power Points and having no recourse\l"
# 754 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "but to use STRUGGLE…$"
# 755 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 756 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintLevitate: @ 8251E3D
# 757 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see Pokémon loftily airborne…\p"
# 758 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon frustrated\n"
# 759 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by powerless GROUND-type moves…$"
# 760 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 761 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility: @ 8251EA1
# 762 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I sense terrific energy rising from\n"
# 763 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the ground below…\p"
# 764 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon unable to\n"
# 765 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "escape the power's clutches…$"
# 766 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 767 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintIce: @ 8251F17
# 768 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see ICE-type Pokémon…\p"
# 769 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon fighting\n"
# 770 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the freezing effects of ice…$"
# 771 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 772 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintExplosion: @ 8251F6E
# 773 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see a flurry of moves that imperil\n"
# 774 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the user…\p"
# 775 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon falling\n"
# 776 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "to them…$"
# 777 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 778 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintPsychic: @ 8251FC7
# 779 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see Psychic-type Pokémon…\p"
# 780 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon in torment\n"
# 781 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from PSYCHIC moves…$"
# 782 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 783 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintRock: @ 825201B
# 784 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see ROCK-type Pokémon…\p"
# 785 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 786 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from ROCK moves…$"
# 787 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 788 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintFighting: @ 8252068
# 789 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see FIGHTING-type Pokémon…\p"
# 790 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon pummeled\n"
# 791 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by FIGHTING moves…$"
# 792 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 793 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintWeather: @ 82520BA
# 794 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "RAIN DANCE… SUNNY DAY…\n"
# 795 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "SANDSTORM… HAIL…\p"
# 796 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see Pokémon that become stronger\n"
# 797 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "with the weather…\p"
# 798 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon confounded\n"
# 799 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "by different types of moves…$"
# 800 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 801 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintBug: @ 8252158
# 802 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see BUG-type Pokémon…\p"
# 803 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 804 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from different kinds of attacks…$"
# 805 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 806 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintDark: @ 82521B4
# 807 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see DARK-type Pokémon…\p"
# 808 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 809 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from DARK-type moves…$"
# 810 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 811 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintWater: @ 8252206
# 812 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see WATER-type Pokémon…\p"
# 813 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 814 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from WATER-type moves…$"
# 815 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 816 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintGhost: @ 825225A
# 817 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see Ghost-type Pokémon…\p"
# 818 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 819 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from Ghost-type moves…$"
# 820 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 821 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintSteel: @ 82522AE
# 822 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see STEEL-type Pokémon…\p"
# 823 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 824 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 825 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 826 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon: @ 825230B
# 827 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see flying Pokémon…\p"
# 828 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 829 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 830 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 831 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve: @ 8252364
# 832 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see those that have evolved from\n"
# 833 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the power of stones…\p"
# 834 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I also sense fire, water,\n"
# 835 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and electricity…\p"
# 836 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 837 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from those three powers…$"
# 838 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 839 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_HintNormal: @ 8252403
# 840 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see NORMAL-type Pokémon…\p"
# 841 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "…And, I see your Pokémon suffering\n"
# 842 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "from enormously powerful moves…$"
# 843 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 844 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot: @ 8252461
# 845 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Whether you believe my fortunes\n"
# 846 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "or not, the choice is yours…\p"
# 847 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The future can be changed anytime…\n"
# 848 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I wish you safe passage…$"
# 849 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 850 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning: @ 82524DA
# 851 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Did you know?\p"
# 852 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "If you run fast, Trainers may notice\n"
# 853 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and come after you for a battle.\p"
# 854 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "So, if you want to avoid TRAINERS,\n"
# 855 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "don't catch their eyes, but sneak\l"
# 856 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "cautiously and quietly past them.$"
# 857 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 858 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems: @ 8252595
# 859 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Awaaaaaaarrrrgh!\p"
# 860 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I had a whole lot of items, but I lost\n"
# 861 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "them all when I lost!\p"
# 862 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Awaaaaaaarrrrgh!$"
# 863 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 864 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing: @ 82525F4
# 865 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome back!\n"
# 866 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've done the unthinkable!\p"
# 867 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You've defeated the PYRAMID KING\n"
# 868 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "and conquered the BATTLE PYRAMID!$"
# 869 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 870 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints: @ 8252662
# 871 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Young explorer!\n"
# 872 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In commendation of your courage,\l"
# 873 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "we give you these Battle Point(s)!$"
# 874 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 875 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_RulesAreListed: @ 82526B6
# 876 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The Battle Quest rules are listed.$"
# 877 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 878 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading: @ 82526D9
# 879 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 880 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 881 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules: @ 82526FC
# 882 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When the PYRAMID is conquered,\n"
# 883 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "the wild Pokémon that appear in it\l"
# 884 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "are replaced by different kinds.\p"
# 885 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Explore, observe, and learn what kinds\n"
# 886 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "of wild Pokémon you may encounter.$"
# 887 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 888 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules: @ 82527A9
# 889 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Trainers are lying in wait for you\n"
# 890 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "inside the PYRAMID.\p"
# 891 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "On each floor, there are up to\n"
# 892 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "eight Trainers.\p"
# 893 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you defeat a Trainer, you will\n"
# 894 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "get a helpful hint for your adventure.$"
# 895 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 896 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules: @ 825285A
# 897 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The mazes in the PYRAMID rearrange\n"
# 898 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "themselves every time you enter it.\p"
# 899 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The mazes are poorly lit.\n"
# 900 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "You must advance with caution.\p"
# 901 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The light grows brighter whenever you\n"
# 902 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "defeat a wild Pokémon or a Trainer.$"
# 903 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"

# 904 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules: @ 8252924
# 905 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE Bag serves as your Bag\n"
# 906 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "while in the PYRAMID.\p"
# 907 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "There are two separate BATTLE BAGS--\n"
# 908 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "one each for the Level 50 and\l"
# 909 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Open Level adventures.\p"
# 910 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "They each can hold up to 99 pieces\n"
# 911 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "of ten kinds of items.\p"
# 912 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The contents of the BATTLE Bag are\n"
# 913 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "lost if you fail in your quest.$"
