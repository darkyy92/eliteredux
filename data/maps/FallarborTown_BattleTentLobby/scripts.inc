# 1 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 2 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 4 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_MapScripts:: @ 81FFE66
# 5 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentLobby_OnFrame
# 6 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_BattleTentLobby_OnWarp
# 7 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.byte 0
# 8 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 9 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_OnWarp: @ 81FFE71
# 10 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, FallarborTown_BattleTentLobby_EventScript_TurnPlayerNorth
# 11 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.2byte 0
# 12 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 13 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_TurnPlayerNorth:: @ 81FFE7B
# 14 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 16 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 17 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 18 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_OnFrame: @ 81FFE85
# 19 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentLobby_EventScript_GetChallengeStatus
# 20 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, FallarborTown_BattleTentLobby_EventScript_QuitWithoutSaving
# 21 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, FallarborTown_BattleTentLobby_EventScript_ResumeChallenge
# 22 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, FallarborTown_BattleTentLobby_EventScript_WonChallenge
# 23 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, FallarborTown_BattleTentLobby_EventScript_LostChallenge
# 24 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.2byte 0
# 25 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 26 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_GetChallengeStatus:: @ 81FFEAF
# 27 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_getstatus
# 28 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 29 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 30 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_QuitWithoutSaving:: @ 81FFEB8
# 31 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	lockall
# 32 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 33 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	closemessage
# 34 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 35 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 36 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 37 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	releaseall
# 38 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 39 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 40 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_WonChallenge:: @ 81FFEED
# 41 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	lockall
# 42 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_BeatThreeTrainers, MSGBOX_DEFAULT
# 43 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	message FallarborTown_BattleTentLobby_Text_WaitWhileSaveGame
# 44 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmessage
# 45 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	fallarbortent_setrandomprize
# 46 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 47 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	fallarbortent_save 0
# 48 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 49 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitse
# 50 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 51 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_GivePrize:: @ 81FFF27
# 52 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_PresentYouWithPrize, MSGBOX_DEFAULT
# 53 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	fallarbortent_giveprize
# 54 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 55 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case FALSE, FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize
# 56 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 57 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	message FallarborTown_BattleTentLobby_Text_ReceivedPrize
# 58 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmessage
# 59 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 60 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitfanfare
# 61 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
# 62 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	closemessage
# 63 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 64 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	releaseall
# 65 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 66 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 67 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize:: @ 81FFF73
# 68 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_BagFullReturnForPrize, MSGBOX_DEFAULT
# 69 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmessage
# 70 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	closemessage
# 71 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 72 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	releaseall
# 73 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 74 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 75 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_PrizeWaiting:: @ 81FFF84
# 76 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	lockall
# 77 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_BeatThreeTrainers, MSGBOX_DEFAULT
# 78 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_GivePrize
# 79 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 80 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 81 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_LostChallenge:: @ 81FFF93
# 82 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	lockall
# 83 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	message FallarborTown_BattleTentLobby_Text_ThankYouWaitWhileSaving
# 84 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmessage
# 85 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 86 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	fallarbortent_save 0
# 87 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 88 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitse
# 89 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
# 90 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	closemessage
# 91 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 92 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	releaseall
# 93 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 94 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 95 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_ResumeChallenge:: @ 81FFFCD
# 96 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	lockall
# 97 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	message FallarborTown_BattleTentLobby_Text_LookingForwardToArrival
# 98 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmessage
# 99 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	fallarbortent_save CHALLENGE_STATUS_SAVING
# 100 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 101 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitse
# 102 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 103 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 104 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_EnterChallenge
# 105 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 106 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_Attendant:: @ 8200001
# 107 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	lock
# 108 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	faceplayer
# 109 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	fallarbortent_getprize
# 110 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	compare VAR_RESULT, ITEM_NONE
# 111 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto_if_ne FallarborTown_BattleTentLobby_EventScript_PrizeWaiting
# 112 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	special SavePlayerParty
# 113 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
# 114 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge:: @ 8200021
# 115 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	message FallarborTown_BattleTentLobby_Text_TakeChallenge
# 116 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmessage
# 117 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 118 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 119 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 0, FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge
# 120 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 1, FallarborTown_BattleTentLobby_EventScript_ExplainChallenge
# 121 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 2, FallarborTown_BattleTentLobby_EventScript_CancelChallenge
# 122 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_CancelChallenge
# 123 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 124 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge:: @ 820005D
# 125 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
# 126 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 127 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_RESULT, 2
# 128 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_checkineligible
# 129 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	compare VAR_0x8004, TRUE
# 130 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMons
# 131 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
# 132 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
# 133 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 134 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_0x8004, 2
# 135 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
# 136 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 137 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitstate
# 138 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	compare VAR_RESULT, 0
# 139 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 140 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
# 141 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 142 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case NO, FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 143 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case YES, FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge
# 144 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 145 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 146 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge:: @ 82000E2
# 147 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 148 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 149 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	fallarbortent_init
# 150 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 151 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 152 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	special LoadPlayerParty
# 153 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	closemessage
# 154 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	delay 2
# 155 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 156 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 157 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	compare VAR_RESULT, 0
# 158 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto_if_eq FallarborTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed
# 159 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_EnterChallenge:: @ 820013C
# 160 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	special SavePlayerParty
# 161 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 162 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_GuideYouToBattleTent, MSGBOX_DEFAULT
# 163 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	closemessage
# 164 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	call FallarborTown_BattleTentLobby_EventScript_WalkToDoor
# 165 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR, 255, 2, 7
# 166 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 167 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitstate
# 168 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 169 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 170 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_ExplainChallenge:: @ 8200169
# 171 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_ExplainFallarborTent, MSGBOX_DEFAULT
# 172 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge
# 173 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 174 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMons:: @ 8200176
# 175 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 176 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case FRONTIER_LVL_50, FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50
# 177 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case FRONTIER_LVL_OPEN, FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen
# 178 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50:: @ 8200191
# 179 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
# 180 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge
# 181 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 182 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen:: @ 820019E
# 183 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
# 184 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge
# 185 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 186 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed:: @ 82001AB
# 187 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 188 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_CancelChallenge
# 189 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 190 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge:: @ 82001C2
# 191 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	special LoadPlayerParty
# 192 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_CancelChallenge:: @ 82001C5
# 193 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
# 194 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge:: @ 82001CD
# 195 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	release
# 196 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 197 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 198 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_WalkToDoor:: @ 82001CF
# 199 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor
# 200 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor
# 201 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmovement 0
# 202 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	opendoor 6, 1
# 203 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitdooranim
# 204 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor
# 205 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor
# 206 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmovement 0
# 207 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	closedoor 6, 1
# 208 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitdooranim
# 209 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	return
# 210 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 211 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor: @ 82001FE
# 212 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 213 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 214 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 215 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	step_end
# 216 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 217 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor: @ 8200202
# 218 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 219 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	set_invisible
# 220 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	step_end
# 221 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 222 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor: @ 8200205
# 223 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 224 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 225 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 226 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	step_end
# 227 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 228 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor: @ 8200209
# 229 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 230 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	walk_up
# 231 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	set_invisible
# 232 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	step_end
# 233 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 234 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_Hiker:: @ 820020D
# 235 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_CameToCampOut, MSGBOX_NPC
# 236 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 237 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 238 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_LittleBoy:: @ 8200216
# 239 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid, MSGBOX_NPC
# 240 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 241 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 242 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_Lass:: @ 820021F
# 243 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite, MSGBOX_NPC
# 244 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 245 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 246 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_Scott:: @ 8200228
# 247 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	lock
# 248 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	faceplayer
# 249 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_IN_FALLARBOR, FallarborTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo
# 250 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone, MSGBOX_DEFAULT
# 251 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 252 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_FALLARBOR
# 253 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	release
# 254 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 255 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 256 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo:: @ 8200245
# 257 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox FallarborTown_BattleTentLobby_Text_ScottMakeChallenge, MSGBOX_DEFAULT
# 258 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	release
# 259 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 260 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 261 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_RulesBoard:: @ 820024F
# 262 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	lockall
# 263 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 264 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
# 265 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 266 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 267 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard:: @ 820025E
# 268 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
# 269 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	waitmessage
# 270 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	multichoice 17, 0, MULTI_FALLARBOR_TENT_RULES, FALSE
# 271 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 272 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 0, FallarborTown_BattleTentLobby_EventScript_RulesLevel
# 273 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 1, FallarborTown_BattleTentLobby_EventScript_RulesBattle
# 274 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 2, FallarborTown_BattleTentLobby_EventScript_RulesMind
# 275 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 3, FallarborTown_BattleTentLobby_EventScript_RulesSkill
# 276 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 4, FallarborTown_BattleTentLobby_EventScript_RulesBody
# 277 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case 5, FallarborTown_BattleTentLobby_EventScript_ExitRules
# 278 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, FallarborTown_BattleTentLobby_EventScript_ExitRules
# 279 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 280 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 281 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_RulesLevel:: @ 82002BC
# 282 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox BattleTentLobby_Text_ExplainLevelRules, MSGBOX_DEFAULT
# 283 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
# 284 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 285 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 286 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_RulesBattle:: @ 82002CA
# 287 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
# 288 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
# 289 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 290 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 291 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_RulesMind:: @ 82002D8
# 292 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
# 293 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
# 294 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 295 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 296 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_RulesSkill:: @ 82002E6
# 297 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
# 298 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
# 299 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 300 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 301 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_RulesBody:: @ 82002F4
# 302 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
# 303 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	goto FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard
# 304 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 305 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 306 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_EventScript_ExitRules:: @ 8200302
# 307 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	releaseall
# 308 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	end
# 309 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 310 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid: @ 8200304
# 311 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Fufufufufu.\p"
# 312 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "I'm going to make everyone think\n"
# 313 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "I'm just a kid and let them play down.\p"
# 314 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Then, I'll shock them and grab\n"
# 315 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "the title!$"
# 316 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 317 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite: @ 8200382
# 318 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "You know how Battle Tents offer\n"
# 319 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "different events in different towns?\p"
# 320 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "My favorite is definitely the Battle\n"
# 321 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Tent in Fallarbor Town.\p"
# 322 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "I think it's fantastic how Trainers\n"
# 323 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "try to win with all their faith in\l"
# 324 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "their Pokémon.$"
# 325 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 326 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Text_CameToCampOut: @ 820045A
# 327 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "I heard something about some tent,\n"
# 328 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "so I came to camp out.\p"
# 329 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "I didn't know that tents these days\n"
# 330 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "are so luxurious!\p"
# 331 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Since I'm here, I may as well try\n"
# 332 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "my hand at battling!$"
# 333 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 334 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone: @ 8200501
# 335 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Scott: Hi, {PLAYER}{KUN}!\n"
# 336 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "So you came out to this Battle Tent!\p"
# 337 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "The people in these parts tend to be\n"
# 338 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "easygoing and laid-back.\p"
# 339 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "But, you see, what I'm looking for are\n"
# 340 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "people with…\p"
# 341 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "How should I say this?\p"
# 342 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Someone bursting with the desire\n"
# 343 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "and the drive to win.\p"
# 344 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "If there were a Trainer like that,\n"
# 345 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "I'd immediately…\p"
# 346 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Whoops! Never mind!\n"
# 347 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Keep working at it!$"
# 348 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"

# 349 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
FallarborTown_BattleTentLobby_Text_ScottMakeChallenge: @ 8200653
# 350 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "Scott: Instead of wasting your\n"
# 351 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "time with the likes of me, why not\l"
# 352 "data/maps/FallarborTown_BattleTentLobby/scripts.pory"
	.string "make a challenge?$"
