# 1 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
.set LOCALID_ATTENDANT_SINGLES, 1
# 3 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
.set LOCALID_ATTENDANT_DOUBLES, 7
# 4 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
.set LOCALID_ATTENDANT_MULTIS, 8
# 5 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
.set LOCALID_ATTENDANT_LINK_MULTIS, 9
# 6 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 7 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_MapScripts:: @ 823E67B
# 8 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerLobby_OnResume
# 9 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerLobby_OnTransition
# 10 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_OnFrame
# 11 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_OnWarp
# 12 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.byte 0
# 13 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 14 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_OnResume: @ 823E690
# 15 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TryHideBattleTowerReporter
# 16 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 17 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 18 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_OnTransition: @ 823E694
# 19 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_ShowOrHideReporter
# 20 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	apprentice_shouldcheckgone
# 21 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8004, FALSE  @ Always TRUE here
# 22 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_ShowApprentice
# 23 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, BattleFrontier_BattleTowerLobby_EventScript_HideApprentice
# 24 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowApprentice:: @ 823E6B5
# 25 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_HIDE_APPRENTICE
# 26 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	apprentice_setgfx
# 27 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_EndShowOrHideApprentice:: @ 823E6C0
# 28 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 29 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 30 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_HideApprentice:: @ 823E6C1
# 31 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setflag FLAG_HIDE_APPRENTICE
# 32 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndShowOrHideApprentice
# 33 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 34 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_OnWarp: @ 823E6C9
# 35 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth
# 36 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.2byte 0
# 37 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 38 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_PlayerFaceNorth:: @ 823E6D3
# 39 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 40 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 41 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 42 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 43 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_OnFrame: @ 823E6DD
# 44 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus
# 45 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving
# 46 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge
# 47 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleTowerLobby_EventScript_WonChallenge
# 48 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleTowerLobby_EventScript_LostChallenge
# 49 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.2byte 0
# 50 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 51 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus:: @ 823E707
# 52 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_getstatus
# 53 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 54 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 55 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving:: @ 823E710
# 56 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 57 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 58 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 59 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 60 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK, 0
# 61 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
# 62 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 63 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 64 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 65 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 66 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 67 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_WonChallenge:: @ 823E758
# 68 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 69 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 70 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_isbrain
# 71 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 72 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden
# 73 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven
# 74 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 75 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons
# 76 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 77 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden:: @ 823E778
# 78 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
# 79 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons:: @ 823E780
# 80 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_giveribbons
# 81 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, FALSE
# 82 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints
# 83 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons
# 84 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 85 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 86 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitfanfare
# 87 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons, MSGBOX_DEFAULT
# 88 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints:: @ 823E7A5
# 89 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
# 90 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_givepoints
# 91 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
# 92 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
# 93 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 94 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 49
# 95 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge
# 96 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
# 97 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge:: @ 823E7E2
# 98 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 99 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 100 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 101 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 102 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 103 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 104 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LostChallenge:: @ 823E7F2
# 105 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 106 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
# 107 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
# 108 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_get TOWER_DATA_WIN_STREAK
# 109 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 110 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying
# 111 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak:: @ 823E81E
# 112 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
# 113 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying:: @ 823E830
# 114 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 115 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 116 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying
# 117 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 118 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
# 119 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 120 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 121 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 122 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 123 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 124 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 125 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle:: @ 823E84D
# 126 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved
# 127 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 128 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkairshow
# 129 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 130 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special HealPlayerParty
# 131 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save 0
# 132 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 133 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 134 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 135 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 136 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
# 137 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_RecordLastMatch
# 138 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 139 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 140 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 141 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
# 142 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_EventScript_SaveBattle
# 143 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
# 144 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 145 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_EventScript_SaveBattle:: @ 823E8B4
# 146 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_savebattle
# 147 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, FALSE
# 148 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_EventScript_BattleSaveFailed
# 149 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 150 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
# 151 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
# 152 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 153 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_EventScript_BattleSaveFailed:: @ 823E8D7
# 154 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved, MSGBOX_DEFAULT
# 155 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle:: @ 823E8DF
# 156 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 157 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 158 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_EventScript_GetCantRecordBattle:: @ 823E8E0
# 159 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_get FRONTIER_DATA_RECORD_DISABLED
# 160 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 161 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 162 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge:: @ 823E8EE
# 163 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 164 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 165 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 166 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_SetBravoTrainerOn
# 167 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou
# 168 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 169 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved
# 170 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 171 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 172 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 173 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 174 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 175 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 176 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 177 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 178 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SetBravoTrainerOn:: @ 823E930
# 179 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
# 180 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 181 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 182 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SinglesAttendant:: @ 823E936
# 183 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 184 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 185 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 186 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 187 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle, MSGBOX_DEFAULT
# 188 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskEnterSinglesChallenge:: @ 823E948
# 189 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge
# 190 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 191 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 192 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 193 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge
# 194 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainSinglesChallenge
# 195 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 196 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 197 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 198 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge:: @ 823E984
# 199 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 200 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 201 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 202 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 203 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 204 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 205 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 206 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 207 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8004, TRUE
# 208 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 209 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 210 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 211 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 212 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 213 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 214 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 215 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 216 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 217 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 218 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 219 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 220 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 221 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 222 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge
# 223 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 224 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 225 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge:: @ 823EA2A
# 226 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 227 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 228 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 229 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 230 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 231 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 232 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 233 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 234 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 235 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 236 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 237 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
# 238 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 239 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
# 240 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 241 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 242 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 243 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExplainSinglesChallenge:: @ 823EA91
# 244 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
# 245 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterSinglesChallenge
# 246 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 247 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 248 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_DoublesAttendant:: @ 823EA9F
# 249 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 250 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 251 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 252 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 253 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
# 254 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskEnterDoublesChallenge:: @ 823EAB1
# 255 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge
# 256 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 257 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 258 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 259 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge
# 260 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainDoublesChallenge
# 261 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 262 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 263 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 264 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge:: @ 823EAED
# 265 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 266 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 267 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 268 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 269 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 270 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 271 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 272 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 273 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8004, TRUE
# 274 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 275 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 276 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
# 277 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 278 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 279 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 280 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
# 281 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 282 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 283 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 284 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 285 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 286 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 287 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 288 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge
# 289 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 290 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 291 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge:: @ 823EB93
# 292 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 293 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 294 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 295 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 296 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 297 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 298 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 299 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 300 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 301 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 302 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 303 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
# 304 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 305 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 306 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 307 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 308 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 309 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExplainDoublesChallenge:: @ 823EBFA
# 310 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
# 311 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterDoublesChallenge
# 312 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 313 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 314 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_MultisAttendant:: @ 823EC08
# 315 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 316 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 317 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 318 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
# 319 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 320 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle, MSGBOX_DEFAULT
# 321 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskEnterMultisChallenge:: @ 823EC1D
# 322 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge
# 323 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 324 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 325 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 326 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge
# 327 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainMultisChallenge
# 328 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 329 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 330 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 331 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge:: @ 823EC59
# 332 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 333 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 334 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 335 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 336 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 337 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 338 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 339 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 340 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8004, TRUE
# 341 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 342 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 343 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons, MSGBOX_DEFAULT
# 344 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 345 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 346 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 347 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
# 348 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 349 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 350 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 351 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 352 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 353 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 354 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 355 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge
# 356 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 357 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 358 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge:: @ 823ECFF
# 359 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 360 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 361 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 362 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 363 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 364 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 365 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 366 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 367 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 368 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 369 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 370 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
# 371 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 372 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 373 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 374 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 375 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 376 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExplainMultisChallenge:: @ 823ED66
# 377 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge, MSGBOX_DEFAULT
# 378 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterMultisChallenge
# 379 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 380 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 381 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LinkMultisAttendant:: @ 823ED74
# 382 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 383 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 384 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 385 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 386 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle, MSGBOX_DEFAULT
# 387 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AskEnterLinkMultisChallenge:: @ 823ED86
# 388 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge
# 389 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 390 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 391 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 392 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterLinkMultisChallenge
# 393 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_ExplainLinkMultisChallenge
# 394 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 395 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 396 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 397 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryEnterLinkMultisChallenge:: @ 823EDC2
# 398 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 399 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
# 400 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 401 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
# 402 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 403 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 404 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 405 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_checkineligible
# 406 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8004, TRUE
# 407 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
# 408 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
# 409 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2, MSGBOX_DEFAULT
# 410 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 411 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_EventScript_GetLvlMode
# 412 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 413 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
# 414 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 415 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 416 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 417 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 418 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
# 419 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 420 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 421 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge
# 422 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
# 423 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 424 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge:: @ 823EE68
# 425 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 426 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 427 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_init
# 428 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
# 429 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 430 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 431 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 432 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 2
# 433 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save 0
# 434 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 435 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 436 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 437 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
# 438 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 439 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 440 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 441 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink
# 442 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_TryCableLink
# 443 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 444 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 445 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsMan:: @ 823EEE7
# 446 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 447 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 448 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower
# 449 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 450 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 16, 4, MULTI_BATTLE_TOWER_FEELINGS, FALSE
# 451 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 452 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_FeelingsBattleNow
# 453 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_FeelingsIWon
# 454 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_FeelingsILost
# 455 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 3, BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell
# 456 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell
# 457 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 458 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 459 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 460 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsBattleNow:: @ 823EF32
# 461 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin, MSGBOX_DEFAULT
# 462 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_START
# 463 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_ShowEasyChatScreen
# 464 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 465 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 466 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
# 467 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 468 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 469 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsIWon:: @ 823EF4C
# 470 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon, MSGBOX_DEFAULT
# 471 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_WON
# 472 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_ShowEasyChatScreen
# 473 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 474 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 475 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
# 476 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 477 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 478 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsILost:: @ 823EF66
# 479 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost, MSGBOX_DEFAULT
# 480 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_LOST
# 481 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call Common_ShowEasyChatScreen
# 482 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lock
# 483 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	faceplayer
# 484 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings
# 485 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 486 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 487 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FeelingsWontTell:: @ 823EF80
# 488 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt, MSGBOX_DEFAULT
# 489 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 490 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 491 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 492 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CheckFeelings:: @ 823EF8A
# 493 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 0
# 494 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CanceledEasyChat
# 495 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 1
# 496 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_SubmittedFeelings
# 497 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 498 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 499 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CanceledEasyChat:: @ 823EFA1
# 500 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChangedYourMind, MSGBOX_DEFAULT
# 501 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 502 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 503 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 504 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SubmittedFeelings:: @ 823EFAB
# 505 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel, MSGBOX_DEFAULT
# 506 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 507 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 508 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 509 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_Woman:: @ 823EFB5
# 510 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded, MSGBOX_NPC
# 511 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 512 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 513 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_Boy:: @ 823EFBE
# 514 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins, MSGBOX_NPC
# 515 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 516 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 517 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowSinglesResults:: @ 823EFC7
# 518 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 519 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_SINGLES
# 520 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 521 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 522 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 523 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 524 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 525 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowDoublesResults:: @ 823EFE0
# 526 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 527 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_DOUBLES
# 528 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 529 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 530 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 531 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 532 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 533 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowMultisResults:: @ 823EFF9
# 534 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 535 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_MULTIS
# 536 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 537 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 538 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 539 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 540 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 541 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowLinkMultisResults:: @ 823F012
# 542 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 543 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_LINK_MULTIS
# 544 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitbuttonpress
# 545 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special RemoveRecordsWindow
# 546 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 547 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 548 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 549 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons:: @ 823F02B
# 550 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 551 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_50, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50
# 552 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen
# 553 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 554 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50:: @ 823F046
# 555 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 556 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles
# 557 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles
# 558 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis, MSGBOX_DEFAULT
# 559 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 560 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 561 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 562 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles:: @ 823F06F
# 563 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
# 564 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 565 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 566 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 567 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles:: @ 823F07D
# 568 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
# 569 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 570 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 571 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 572 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen:: @ 823F08B
# 573 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_FRONTIER_BATTLE_MODE
# 574 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles
# 575 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles
# 576 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis, MSGBOX_DEFAULT
# 577 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 578 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 579 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 580 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles:: @ 823F0B4
# 581 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
# 582 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 583 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 584 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 585 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles:: @ 823F0C2
# 586 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
# 587 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
# 588 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 589 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 590 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed:: @ 823F0D0
# 591 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS  @ No status provided, so it relies on VAR_0x8006 being 0 already
# 592 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 593 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 594 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 595 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge:: @ 823F0E3
# 596 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special LoadPlayerParty
# 597 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge:: @ 823F0E6
# 598 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 599 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
# 600 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge:: @ 823F0F1
# 601 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 602 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 603 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 604 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_EnterElevator:: @ 823F0F3
# 605 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SavePlayerParty
# 606 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
# 607 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GetPartySize
# 608 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CallFrontierUtilFunc
# 609 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_RESULT, 0
# 610 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad:: @ 823F108
# 611 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_loadlinkopponents
# 612 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 1
# 613 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, 6
# 614 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerLobby_EventScript_WaitForLinkOpponentLoad
# 615 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom
# 616 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
# 617 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
# 618 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 619 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 620 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 621 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 622 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom:: @ 823F135
# 623 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_BufferModeText
# 624 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 625 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom
# 626 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
# 627 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator
# 628 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 629 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom:: @ 823F152
# 630 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	messageautoscroll BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom
# 631 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 632 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	delay 48
# 633 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator:: @ 823F15B
# 634 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closemessage
# 635 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo
# 636 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord
# 637 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
# 638 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
# 639 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmovement 0
# 640 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	opendoor VAR_0x8004, 1
# 641 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitdooranim
# 642 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator
# 643 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator
# 644 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmovement 0
# 645 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	closedoor VAR_0x8004, 1
# 646 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitdooranim
# 647 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 648 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 649 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_WalkToElevator: @ 823F195
# 650 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 651 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 652 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 653 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end
# 654 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 655 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator: @ 823F199
# 656 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 657 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	set_invisible
# 658 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end
# 659 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 660 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator: @ 823F19C
# 661 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 662 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_up
# 663 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	set_invisible
# 664 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end
# 665 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 666 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 667 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Movement_UnusedEnterElevator: @ 823F1A0
# 668 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 669 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 670 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 671 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 672 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	walk_fast_up
# 673 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	set_invisible
# 674 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	step_end
# 675 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 676 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferModeText:: @ 823F1A7
# 677 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 678 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle
# 679 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 680 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble
# 681 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 682 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti
# 683 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 684 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_BufferTextLinkMulti
# 685 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 686 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 687 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle:: @ 823F1D4
# 688 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring 0, STDSTRING_SINGLE
# 689 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 690 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 691 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble:: @ 823F1D9
# 692 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring 0, STDSTRING_DOUBLE
# 693 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 694 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 695 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti:: @ 823F1DE
# 696 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring 0, STDSTRING_MULTI
# 697 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 698 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 699 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_BufferTextLinkMulti:: @ 823F1E3
# 700 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	bufferstdstring 0, STDSTRING_MULTI_LINK
# 701 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 702 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 703 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_SetAttendantTalkedTo:: @ 823F1E8
# 704 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 705 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_TalkedToSinglesAttendant
# 706 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 707 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_TalkedToDoublesAttendant
# 708 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 709 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_TalkedToMultisAttendant
# 710 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 711 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_TalkedToLinkMultisAttendant
# 712 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 713 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 714 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TalkedToSinglesAttendant:: @ 823F215
# 715 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
# 716 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 717 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 718 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TalkedToDoublesAttendant:: @ 823F21B
# 719 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
# 720 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 721 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 722 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TalkedToMultisAttendant:: @ 823F221
# 723 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_MULTIS
# 724 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 725 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 726 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TalkedToLinkMultisAttendant:: @ 823F227
# 727 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_LINK_MULTIS
# 728 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 729 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 730 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoord:: @ 823F22D
# 731 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 732 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordSingles
# 733 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 734 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordDoubles
# 735 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 736 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordMultis
# 737 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 738 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordLinkMultis
# 739 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 740 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 741 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordSingles:: @ 823F25A
# 742 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 6
# 743 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 744 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 745 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordDoubles:: @ 823F260
# 746 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 10
# 747 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 748 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 749 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordMultis:: @ 823F266
# 750 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 14
# 751 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 752 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 753 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoorXCoordLinkMultis:: @ 823F26C
# 754 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, 18
# 755 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 756 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 757 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetPartySize:: @ 823F272
# 758 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 759 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize
# 760 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
# 761 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize
# 762 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 763 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize
# 764 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 765 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_GetLinkMultisPartySize
# 766 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 767 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 768 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize:: @ 823F29F
# 769 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 770 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 771 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 772 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize:: @ 823F2A5
# 773 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
# 774 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 775 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 776 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize:: @ 823F2AB
# 777 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
# 778 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 779 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 780 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_GetLinkMultisPartySize:: @ 823F2B1
# 781 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
# 782 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 783 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 784 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_EventScript_GetLvlMode:: @ 823F2B7
# 785 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 786 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 787 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 788 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryCableLink:: @ 823F2C5
# 789 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, USING_BATTLE_TOWER
# 790 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message gText_PleaseWaitForLink
# 791 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 792 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8005, 0
# 793 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TryBattleLinkup
# 794 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 795 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 796 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful
# 797 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_SOMEONE_NOT_READY
# 798 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
# 799 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
# 800 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections
# 801 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
# 802 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers
# 803 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 804 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 805 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
# 806 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
# 807 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER
# 808 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AbortLink
# 809 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 810 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 811 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections:: @ 823F327
# 812 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 813 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8005, 3
# 814 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection
# 815 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
# 816 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 817 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 818 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 819 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FriendDifferentSelection:: @ 823F33F
# 820 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
# 821 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
# 822 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 823 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 824 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 825 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AbortLinkIncorrectNumberOfPlayers:: @ 823F351
# 826 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers, MSGBOX_DEFAULT
# 827 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 828 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
# 829 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 830 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 831 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 832 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_AbortLink:: @ 823F366
# 833 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special CloseLink
# 834 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8005, 0
# 835 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_FriendChoseDifferentLvlMode
# 836 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8005, 1
# 837 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMon
# 838 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_0x8005, 2
# 839 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMons
# 840 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
# 841 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 842 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 843 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 844 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FriendChoseDifferentLvlMode:: @ 823F394
# 845 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
# 846 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 847 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 848 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMon:: @ 823F39D
# 849 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon, MSGBOX_DEFAULT
# 850 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 851 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 852 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_FriendAlsoSelectedMons:: @ 823F3A6
# 853 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons, MSGBOX_DEFAULT
# 854 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 855 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 856 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_CableLinkSuccessful:: @ 823F3AF
# 857 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 858 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 859 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
# 860 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 861 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 862 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SaveForBattleTowerLink
# 863 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 864 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 865 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 866 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special TrySetBattleTowerLinkType
# 867 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 868 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 869 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 870 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExplainLinkMultisChallenge:: @ 823F3DA
# 871 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge, MSGBOX_DEFAULT
# 872 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_AskEnterLinkMultisChallenge
# 873 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 874 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 875 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryWirelessLink:: @ 823F3E8
# 876 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_BATTLE_TOWER
# 877 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
# 878 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 879 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 880 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader:: @ 823F3F3
# 881 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message CableClub_Text_ChooseGroupLeaderOfTwo
# 882 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 883 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
# 884 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 885 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
# 886 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
# 887 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 888 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
# 889 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 890 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 891 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader:: @ 823F430
# 892 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call CableClub_EventScript_TryBecomeLinkLeader
# 893 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 894 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
# 895 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 896 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
# 897 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 898 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_TryBecomeLeader
# 899 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER
# 900 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AbortLink
# 901 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 902 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 903 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 904 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup:: @ 823F463
# 905 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	call CableClub_EventScript_TryJoinLinkGroup
# 906 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 907 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful
# 908 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 909 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_ChooseLeader
# 910 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 911 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_TryJoinGroup
# 912 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED_BATTLE_TOWER
# 913 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AbortLink
# 914 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	release
# 915 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	return
# 916 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 917 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_WirelessLinkSuccessful:: @ 823F496
# 918 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
# 919 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
# 920 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn
# 921 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 922 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	tower_save CHALLENGE_STATUS_SAVING
# 923 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	special SaveForBattleTowerLink
# 924 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitstate
# 925 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	playse SE_SAVE
# 926 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitse
# 927 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
# 928 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 929 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 930 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesBoard:: @ 823F4BE
# 931 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	lockall
# 932 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 933 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 934 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 935 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 936 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard:: @ 823F4CD
# 937 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
# 938 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	waitmessage
# 939 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	multichoice 17, 2, MULTI_BATTLE_TOWER_RULES, FALSE
# 940 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	switch VAR_RESULT
# 941 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 0, BattleFrontier_BattleTowerLobby_EventScript_RulesTower
# 942 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 1, BattleFrontier_BattleTowerLobby_EventScript_RulesMons
# 943 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 2, BattleFrontier_BattleTowerLobby_EventScript_RulesSalon
# 944 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 3, BattleFrontier_BattleTowerLobby_EventScript_RulesMultiLink
# 945 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case 4, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
# 946 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
# 947 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 948 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 949 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesTower:: @ 823F520
# 950 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules, MSGBOX_DEFAULT
# 951 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 952 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 953 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 954 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesMons:: @ 823F52E
# 955 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
# 956 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 957 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 958 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 959 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesSalon:: @ 823F53C
# 960 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules, MSGBOX_DEFAULT
# 961 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 962 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 963 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 964 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_RulesMultiLink:: @ 823F54A
# 965 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules, MSGBOX_DEFAULT
# 966 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
# 967 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 968 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 969 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_ExitRules:: @ 823F558
# 970 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	releaseall
# 971 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	end
# 972 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 973 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 974 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_EventScript_DirectYouToBattleRoom: @ 823F55A
# 975 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I'll direct you to your BATTLE ROOM now.$"
# 976 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 977 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting: @ 823F583
# 978 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 979 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You didn't save before you quit your\n"
# 980 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "challenge last time.\p"
# 981 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Because of that, your challenge so far\n"
# 982 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "has been disqualified. Sorry!$"
# 983 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 984 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven: @ 823F60D
# 985 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Congratulations!\n"
# 986 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You've beaten all seven Trainers!\p"
# 987 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "$"
# 988 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 989 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 990 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_EarnedFabulousPrize: @ 823F641
# 991 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "For beating seven Trainers in a row,\n"
# 992 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you have earned this fabulous prize!\p"
# 993 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "$"
# 994 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 995 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ReceivedPrize: @ 823F68C
# 996 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
# 997 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 998 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 999 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1000 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_BagFullMakeRoom: @ 823F6A6
# 1001 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Oh, your Bag appears to be full.\p"
# 1002 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please make room in your Bag, then come\n"
# 1003 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "see me.$"
# 1004 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1005 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying: @ 823F6F7
# 1006 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Thank you for playing!\p"
# 1007 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "$"
# 1008 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1009 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved: @ 823F70F
# 1010 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your record will be saved.\n"
# 1011 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please wait.$"
# 1012 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1013 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou: @ 823F737
# 1014 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "We've been waiting for you!\p"
# 1015 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "$"
# 1016 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1017 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved: @ 823F754
# 1018 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Before entering a BATTLE ROOM, your\n"
# 1019 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "progress will be saved. Please wait.$"
# 1020 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1021 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer: @ 823F79D
# 1022 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You're finally about to face the\n"
# 1023 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "50th Trainer.\p"
# 1024 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "From here on, every time you beat seven\n"
# 1025 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Trainers in a row, your Pokémon will\l"
# 1026 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "receive a commemorative RIBBON.\p"
# 1027 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Good luck!$"
# 1028 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1029 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons: @ 823F844
# 1030 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Here are some RIBBONS for beating\n"
# 1031 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "seven tough Trainers in a row.\p"
# 1032 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} received some RIBBONS!$"
# 1033 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1034 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons: @ 823F89F
# 1035 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} put the RIBBONS on\n"
# 1036 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the challenger Pokémon.$"
# 1037 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1038 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DescribeFeelingsAboutBattleTower: @ 823F8CD
# 1039 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me, do you have a moment?\p"
# 1040 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Can you describe your feelings when\n"
# 1041 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you're about to begin a Battle Tower\l"
# 1042 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "match, or when you've either won or\l"
# 1043 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "lost a match?$"
# 1044 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1045 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouBegin: @ 823F969
# 1046 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Okay, what are your feelings when\n"
# 1047 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you're about to begin a match?$"
# 1048 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1049 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveWon: @ 823F9AA
# 1050 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "What do you feel when you've won\n"
# 1051 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "a match?$"
# 1052 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1053 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FeelWhatWhenYouveLost: @ 823F9D4
# 1054 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Can I hear about your feelings when\n"
# 1055 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you have lost a match?$"
# 1056 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1057 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DontThinkMuchAboutIt: @ 823FA0F
# 1058 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Oh, so you don't think much about it?\n"
# 1059 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You're one cool customer.$"
# 1060 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1061 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ChangedYourMind: @ 823FA4F
# 1062 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Hunh? You changed your mind?\n"
# 1063 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I guess you're fickle.$"
# 1064 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1065 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ThatsHowYouFeel: @ 823FA83
# 1066 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Okay, so that's how you feel?\n"
# 1067 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "That's quite original.\p"
# 1068 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Thanks!$"
# 1069 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1070 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded: @ 823FAC0
# 1071 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The number of matches you win in a row\n"
# 1072 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "is recorded.\p"
# 1073 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I'd better not get beaten in\n"
# 1074 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "an embarrassing way!$"
# 1075 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1076 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins: @ 823FB26
# 1077 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Once you've entered the Battle Tower,\n"
# 1078 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you can't leave until you either lose\l"
# 1079 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "or you beat seven Trainers in a row.\p"
# 1080 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You'd best be certain that you're up\n"
# 1081 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to the challenge.$"
# 1082 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1083 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1084 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_DoubleBattleRoomConstruction: @ 823FBCE
# 1085 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the Battle Tower\n"
# 1086 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Double Battle CORNER!\p"
# 1087 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Unfortunately, the BATTLE ROOMS\n"
# 1088 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are still under construction.\p"
# 1089 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come back when the work\n"
# 1090 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "is completed.$"
# 1091 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1092 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1093 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_MultiBattleRoomConstruction: @ 823FC6B
# 1094 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the Battle Tower\n"
# 1095 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "MULTI BATTLE CORNER!\p"
# 1096 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Unfortunately, the BATTLE ROOMS\n"
# 1097 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are still under construction.\p"
# 1098 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come back when the work\n"
# 1099 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "is completed.$"
# 1100 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1101 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge: @ 823FD07
# 1102 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "We look forward to seeing you on\n"
# 1103 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "another challenge!$"
# 1104 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1105 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WhichLevelMode: @ 823FD3B
# 1106 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE ROOM offers two levels\n"
# 1107 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of challenge, Level 50 and Open Level.\l"
# 1108 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Which is your choice?$"
# 1109 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1110 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1111 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PleaseSelectMons: @ 823FD9A
# 1112 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please select the Pokémon you wish\n"
# 1113 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.$"
# 1114 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1115 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering: @ 823FDC7
# 1116 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Before entering a BATTLE ROOM, your\n"
# 1117 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "progress must be saved. Is that okay?$"
# 1118 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1119 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom: @ 823FE11
# 1120 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I will now show you to the\n"
# 1121 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{STR_VAR_1} BATTLE ROOM.$"
# 1122 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1123 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_RecordLastMatch: @ 823FE3C
# 1124 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Shall I record your last Battle Tower\n"
# 1125 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "match on your FRONTIER PASS?$"
# 1126 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1127 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1128 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50: @ 823FE7F
# 1129 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1130 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have {STR_VAR_2} eligible Pokémon.\p"
# 1131 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have {STR_VAR_2} different Pokémon\n"
# 1132 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 1133 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1134 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1135 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1136 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1137 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1138 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1139 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpen: @ 823FF5D
# 1140 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1141 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have {STR_VAR_2} eligible Pokémon.\p"
# 1142 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have {STR_VAR_2} different Pokémon\n"
# 1143 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.\p"
# 1144 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1145 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1146 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1147 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1148 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1149 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles: @ 8240027
# 1150 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1151 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have three eligible Pokémon.\p"
# 1152 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have three different Pokémon\n"
# 1153 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 1154 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1155 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1156 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1157 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1158 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1159 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles: @ 824010B
# 1160 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1161 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have three eligible Pokémon.\p"
# 1162 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have three different Pokémon\n"
# 1163 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.\p"
# 1164 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1165 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1166 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1167 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1168 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1169 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles: @ 82401DB
# 1170 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1171 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have four eligible Pokémon.\p"
# 1172 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have four different Pokémon\n"
# 1173 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 1174 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1175 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1176 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1177 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1178 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1179 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles: @ 82402BD
# 1180 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1181 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have four eligible Pokémon.\p"
# 1182 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have four different Pokémon\n"
# 1183 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.\p"
# 1184 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1185 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1186 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1187 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1188 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1189 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis: @ 824038B
# 1190 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1191 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have two eligible Pokémon.\p"
# 1192 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have two different Pokémon\n"
# 1193 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "of Level 50 or less to enter.\p"
# 1194 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1195 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1196 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1197 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1198 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1199 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis: @ 824046B
# 1200 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Excuse me!\p"
# 1201 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You don't have two eligible Pokémon.\p"
# 1202 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must have two different Pokémon\n"
# 1203 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to enter.\p"
# 1204 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "They also must be holding different\n"
# 1205 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "kinds of items.\p"
# 1206 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "EGGS{STR_VAR_1} ineligible.\p"
# 1207 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please come see me when you are ready.$"
# 1208 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1209 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WelcomSingleBattle: @ 8240537
# 1210 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of Trainers\n"
# 1211 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are put to the test!\p"
# 1212 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the Battle Tower!\p"
# 1213 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I am your guide to the SINGLE\n"
# 1214 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOMS.$"
# 1215 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1216 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_TakeSinglesChallenge: @ 82405B3
# 1217 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the SINGLE\n"
# 1218 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOM challenge?$"
# 1219 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1220 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainSinglesChallenge: @ 82405EC
# 1221 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The Battle Tower's SINGLE BATTLE\n"
# 1222 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "ROOMS are facilities for conducting\l"
# 1223 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "SINGLE BATTLES with three Pokémon.\p"
# 1224 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "There are many SINGLE BATTLE ROOMS\n"
# 1225 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "in the Battle Tower for team battles.\p"
# 1226 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In each of the SINGLE BATTLE ROOMS,\n"
# 1227 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "seven Trainers await your challenge.\p"
# 1228 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you manage to defeat all seven,\n"
# 1229 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will earn Battle Points.\p"
# 1230 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 1231 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 1232 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 1233 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will be disqualified.$"
# 1234 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1235 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_SelectThreeMons: @ 82407A6
# 1236 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the three Pokémon\n"
# 1237 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "that are to be entered.$"
# 1238 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1239 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WelcomeDoubleBattle: @ 82407E2
# 1240 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of Trainers\n"
# 1241 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are put to the test!\p"
# 1242 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the Battle Tower!\p"
# 1243 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I am your guide to the DOUBLE\n"
# 1244 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOMS.$"
# 1245 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1246 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_TakeDoublesChallenge: @ 824085E
# 1247 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the DOUBLE\n"
# 1248 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOM challenge?$"
# 1249 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1250 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainDoublesChallenge: @ 8240897
# 1251 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The Battle Tower's Double Battle\n"
# 1252 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "ROOMS are facilities for conducting\l"
# 1253 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Double Battles with four Pokémon.\p"
# 1254 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "There are many Double Battle ROOMS\n"
# 1255 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "in the Battle Tower for team battles.\p"
# 1256 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In each of the Double Battle ROOMS,\n"
# 1257 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "seven Trainers await your challenge.\p"
# 1258 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you manage to defeat all seven,\n"
# 1259 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will earn Battle Points.\p"
# 1260 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 1261 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 1262 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 1263 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will be disqualified.$"
# 1264 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1265 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons: @ 8240A50
# 1266 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the four Pokémon\n"
# 1267 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "that are to be entered.$"
# 1268 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1269 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WelcomeMultiBattle: @ 8240A8B
# 1270 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of Trainers\n"
# 1271 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are put to the test!\p"
# 1272 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the Battle Tower!\p"
# 1273 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I am your guide to the MULTI\n"
# 1274 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOMS.$"
# 1275 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1276 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_TakeMultisChallenge: @ 8240B06
# 1277 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the MULTI\n"
# 1278 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOM challenge?$"
# 1279 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1280 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainMultisChallenge: @ 8240B3E
# 1281 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The Battle Tower's MULTI BATTLE\n"
# 1282 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "ROOMS are facilities for conducting\l"
# 1283 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Multi Battles.\p"
# 1284 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "For Multi Battles, you must partner\n"
# 1285 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "with a Trainer in the TOWER and enter\l"
# 1286 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "with two Pokémon each.\p"
# 1287 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Inside the TOWER is a room named\n"
# 1288 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the BATTLE SALON where you may meet\l"
# 1289 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "other Trainers.\p"
# 1290 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "There, you must find a Trainer to act\n"
# 1291 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "as your partner in Multi Battles.\p"
# 1292 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Once you have partnered up, you will\n"
# 1293 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "be shown to a MULTI BATTLE ROOM.\p"
# 1294 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In the MULTI BATTLE ROOM, seven\n"
# 1295 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "tag teams await your challenge.\p"
# 1296 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you manage to defeat all seven\n"
# 1297 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "teams, you will earn Battle Points.\p"
# 1298 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you want to interrupt your\n"
# 1299 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "challenge, please save the game.\p"
# 1300 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you don't save before interrupting,\n"
# 1301 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you will be disqualified.$"
# 1302 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1303 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons: @ 8240DDB
# 1304 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the two Pokémon\n"
# 1305 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "that are to be entered.$"
# 1306 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1307 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_WelcomeLinkMultiBattle: @ 8240E15
# 1308 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Where the talents of Trainers\n"
# 1309 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "are put to the test!\p"
# 1310 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Welcome to the Battle Tower!\p"
# 1311 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I am your guide to the LINK MULTI\n"
# 1312 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOMS.$"
# 1313 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1314 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_TakeLinkMultisChallenge: @ 8240E95
# 1315 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Would you like to take the LINK MULTI\n"
# 1316 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE ROOM challenge?$"
# 1317 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1318 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainLinkMultisChallenge: @ 8240ED2
# 1319 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The Battle Tower's MULTI BATTLE\n"
# 1320 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "ROOMS are facilities for conducting\l"
# 1321 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Multi Battles with a friend.\p"
# 1322 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must link with your friend using\n"
# 1323 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Wireless Adapters or a Game Boy\l"
# 1324 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Advance Game Link cable.\p"
# 1325 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must partner with your friend and\n"
# 1326 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "enter two different kinds of Pokémon.\p"
# 1327 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "There are many MULTI BATTLE ROOMS\n"
# 1328 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "in the Battle Tower for team battles.\p"
# 1329 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In a MULTI BATTLE ROOM, seven\n"
# 1330 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "tag teams await you and your friend\l"
# 1331 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "to make a tag-team challenge.\p"
# 1332 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "If you manage to defeat all seven\n"
# 1333 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "teams, you will earn Battle Points.\p"
# 1334 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please beware that unlike other ROOMS,\n"
# 1335 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you may not interrupt your challenge.\p"
# 1336 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Once you start, you must battle seven\n"
# 1337 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Multi Battles in a row nonstop.$"
# 1338 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1339 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons2: @ 824115E
# 1340 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Now please select the two Pokémon\n"
# 1341 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "that are to be entered.$"
# 1342 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1343 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1344 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ChoseSameMonAsFriend: @ 8241198
# 1345 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You have chosen the same kind of\n"
# 1346 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Pokémon as your friend.\p"
# 1347 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please choose two Pokémon different\n"
# 1348 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "from your friend's, match the level\l"
# 1349 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you wish to enter, and register again.$"
# 1350 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1351 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_LinkMultiOnlyForTwoPlayers: @ 8241240
# 1352 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The LINK MULTI BATTLE ROOM challenge\n"
# 1353 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "is only for two linked players.$"
# 1354 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1355 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMon: @ 8241285
# 1356 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected\n"
# 1357 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the Pokémon {STR_VAR_1}.$"
# 1358 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1359 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendAlsoSelectedMons: @ 82412B3
# 1360 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected the\n"
# 1361 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Pokémon {STR_VAR_1} and {STR_VAR_2}.$"
# 1362 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1363 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlMode: @ 82412E8
# 1364 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has chosen a different\n"
# 1365 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "battle level.$"
# 1366 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1367 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1368 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMon: @ 8241319
# 1369 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has chosen a different\n"
# 1370 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "battle level.\p"
# 1371 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected\n"
# 1372 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the Pokémon {STR_VAR_1}.$"
# 1373 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1374 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
@ Unused
# 1375 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_FriendChoseDifferentLvlModeSameMons: @ 8241378
# 1376 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has chosen a different\n"
# 1377 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "battle level.\p"
# 1378 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Your friend has also selected the\n"
# 1379 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Pokémon {STR_VAR_1} and {STR_VAR_2}.$"
# 1380 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1381 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ChooseDifferentMonsMatchLvlMode: @ 82413DE
# 1382 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please choose two Pokémon different\n"
# 1383 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "from your friend's, match the level\l"
# 1384 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "you wish to enter, and register again.$"
# 1385 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1386 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn: @ 824144D
# 1387 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "I will save the game before\n"
# 1388 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "showing you in. Please wait.$"
# 1389 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1390 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden: @ 8241486
# 1391 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Congratulations!\n"
# 1392 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You have defeated the SALON MAIDEN\l"
# 1393 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "and swept seven Trainers!$"
# 1394 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1395 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints: @ 82414D4
# 1396 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "In recognition of your infinite talent,\n"
# 1397 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "we award you these Battle Point(s).$"
# 1398 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1399 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_Text_ObtainedXBattlePoints: @ 8241520
# 1400 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "{PLAYER} obtained {STR_VAR_1} Battle Point(s).$"
# 1401 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1402 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_RulesAreListed: @ 8241540
# 1403 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The Battle Tower rules are listed.$"
# 1404 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1405 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading: @ 8241563
# 1406 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Which heading do you want to read?$"
# 1407 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1408 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules: @ 8241586
# 1409 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The Battle Tower is a facility where\n"
# 1410 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "four types of battles are waged--\l"
# 1411 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "SINGLE BATTLE, Double Battle, MULTI\l"
# 1412 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "BATTLE, and LINK MULTI BATTLE.\p"
# 1413 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "For each of these types, there are\n"
# 1414 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "separate BATTLE ROOMS.\p"
# 1415 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Please speak with a guide offering\n"
# 1416 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the type of battle you wish to enter.$"
# 1417 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1418 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainMonRules: @ 8241693
# 1419 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Depending on the BATTLE ROOM you are\n"
# 1420 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "entering, you will be required to take\l"
# 1421 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "a certain number of Pokémon.\p"
# 1422 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The SINGLE BATTLE mode requires\n"
# 1423 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "three Pokémon.\p"
# 1424 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The Double Battle mode requires four,\n"
# 1425 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "and the MULTI modes both require two.$"
# 1426 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1427 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules: @ 8241777
# 1428 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The BATTLE SALON is where you must\n"
# 1429 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "find a partner to form a tag team for\l"
# 1430 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the MULTI BATTLE ROOM challenge.\p"
# 1431 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Choose the best partner for you by\n"
# 1432 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "examining other TRAINERS'\l"
# 1433 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Pokémon and their moves.\p"
# 1434 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You may choose a new tag partner\n"
# 1435 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "after winning seven straight matches.$"
# 1436 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"

# 1437 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
BattleFrontier_BattleTowerLobby_Text_ExplainMultiLinkRules: @ 824187E
# 1438 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "The LINK MULTI BATTLE Mode is for two\n"
# 1439 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "friends to mount a challenge together.\p"
# 1440 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You and your friend must be linked with\n"
# 1441 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "Wireless Adapters or a GBA Game Link\l"
# 1442 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "cable.\p"
# 1443 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You must choose two Pokémon at\n"
# 1444 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "the registration counter.\p"
# 1445 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "These Pokémon must be different\n"
# 1446 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "from those of your friend.\p"
# 1447 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "You may not interrupt this challenge\n"
# 1448 "data/maps/BattleFrontier_BattleTowerLobby/scripts.pory"
	.string "in the middle, unlike other modes.$"
