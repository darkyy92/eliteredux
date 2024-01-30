# 1 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 2 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 4 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_MapScripts:: @ 8208730
# 5 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentLobby_OnFrame
# 6 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentLobby_OnWarp
# 7 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.byte 0
# 8 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 9 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_OnWarp: @ 820873B
# 10 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth
# 11 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.2byte 0
# 12 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 13 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TurnPlayerNorth:: @ 8208745
# 14 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 16 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 17 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 18 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_OnFrame: @ 820874F
# 19 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus
# 20 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving
# 21 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, SlateportCity_BattleTentLobby_EventScript_ResumeChallenge
# 22 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, SlateportCity_BattleTentLobby_EventScript_WonChallenge
# 23 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, SlateportCity_BattleTentLobby_EventScript_LostChallenge
# 24 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.2byte 0
# 25 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 26 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_GetChallengeStatus:: @ 8208779
# 27 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_getstatus
# 28 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 29 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 30 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_QuitWithoutSaving:: @ 8208782
# 31 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 32 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
# 33 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 34 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 35 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 36 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 37 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 38 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 39 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 40 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_WonChallenge:: @ 82087B7
# 41 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 42 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_WonThreeMatchesReturnMons
# 43 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 44 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_setrandomprize
# 45 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 46 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save 0
# 47 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 48 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 49 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_GivePrize:: @ 82087E9
# 50 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_AwardYouThisPrize, MSGBOX_DEFAULT
# 51 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_giveprize
# 52 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 53 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case FALSE, SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize
# 54 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 55 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message BattleFrontier_BattleTowerLobby_Text_ReceivedPrize  @ Odd that it uses Tower's instead of Factory's or its own
# 56 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 57 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 58 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitfanfare
# 59 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize
# 60 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 61 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_NoRoomForPrize:: @ 820882A
# 62 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_NoRoomInBagMakeRoom, MSGBOX_DEFAULT
# 63 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EndGivePrize
# 64 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 65 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_LostChallenge:: @ 8208837
# 66 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 67 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_ReturnRentalMonsSaveResults
# 68 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 69 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
# 70 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save 0
# 71 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 72 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 73 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 74 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_EndGivePrize:: @ 8208861
# 75 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 76 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 77 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 78 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 79 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 80 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 81 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ResumeChallenge:: @ 8208871
# 82 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 83 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_BeenWaitingForYou
# 84 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 85 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_save CHALLENGE_STATUS_SAVING
# 86 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	playse SE_SAVE
# 87 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitse
# 88 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 89 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 90 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_0x8006, 2
# 91 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_EnterChallenge
# 92 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 93 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Attendant:: @ 82088AA
# 94 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lock
# 95 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	faceplayer
# 96 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_getprize
# 97 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	compare VAR_RESULT, ITEM_NONE
# 98 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_ne SlateportCity_BattleTentLobby_EventScript_GivePrize
# 99 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	special SavePlayerParty
# 100 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
# 101 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge:: @ 82088CA
# 102 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message SlateportCity_BattleTentLobby_Text_TakeChallenge
# 103 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 104 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
# 105 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 106 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 0, SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge
# 107 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 1, SlateportCity_BattleTentLobby_EventScript_ExplainChallenge
# 108 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 2, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 109 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 110 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 111 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge:: @ 8208906
# 112 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
# 113 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
# 114 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
# 115 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
# 116 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 117 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case NO, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 118 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case YES, SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge
# 119 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge
# 120 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 121 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge:: @ 8208950
# 122 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 123 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
# 124 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	slateporttent_init
# 125 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
# 126 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_PAUSED, FALSE
# 127 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 128 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	delay 2
# 129 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 130 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 255
# 131 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	compare VAR_RESULT, 0
# 132 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_eq SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed
# 133 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_0x8006, 0
# 134 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_EnterChallenge:: @ 82089AC
# 135 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_StepThisWay, MSGBOX_DEFAULT
# 136 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closemessage
# 137 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	call SlateportCity_BattleTentLobby_EventScript_WalkToDoor
# 138 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR, 255, 2, 7
# 139 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 140 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitstate
# 141 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 142 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 143 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_WalkToDoor:: @ 82089C9
# 144 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor
# 145 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor
# 146 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmovement 0
# 147 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	opendoor 6, 1
# 148 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitdooranim
# 149 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor
# 150 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor
# 151 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmovement 0
# 152 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	closedoor 6, 1
# 153 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitdooranim
# 154 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	return
# 155 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 156 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_AttendantWalkToDoor: @ 82089F8
# 157 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 158 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 159 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 160 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 161 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 162 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_AttendantEnterDoor: @ 82089FC
# 163 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 164 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 165 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 166 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 167 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_PlayerWalkToDoor: @ 82089FF
# 168 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 169 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 170 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 171 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 172 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 173 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_PlayerEnterDoor: @ 8208A03
# 174 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 175 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 176 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 177 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 178 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 179 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ExplainChallenge:: @ 8208A07
# 180 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSlateportTent, MSGBOX_DEFAULT
# 181 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge
# 182 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 183 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_CancelChallengeSaveFailed:: @ 8208A14
# 184 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 185 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_CancelChallenge
# 186 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 187 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge:: @ 8208A2B
# 188 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	special LoadPlayerParty
# 189 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_CancelChallenge:: @ 8208A2E
# 190 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
# 191 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 192 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 193 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 194 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
@ Unused
# 195 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Movement_UnusedEnterDoor:: @ 8208A38
# 196 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 197 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 198 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	walk_up
# 199 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	set_invisible
# 200 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	step_end
# 201 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 202 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_TormentGiver:: @ 8208A3D
# 203 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lock
# 204 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	faceplayer
# 205 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM41, SlateportCity_BattleTentLobby_EventScript_ReceivedTorment
# 206 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe, MSGBOX_DEFAULT
# 207 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	giveitem ITEM_TM41_TORMENT
# 208 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	compare VAR_RESULT, FALSE
# 209 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 210 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	setflag FLAG_RECEIVED_TM41
# 211 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
# 212 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 213 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 214 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 215 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ReceivedTorment:: @ 8208A74
# 216 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainTorment, MSGBOX_DEFAULT
# 217 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	release
# 218 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 219 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 220 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Man:: @ 8208A7E
# 221 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons, MSGBOX_NPC
# 222 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 223 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 224 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Girl:: @ 8208A87
# 225 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons, MSGBOX_NPC
# 226 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 227 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 228 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_Woman:: @ 8208A90
# 229 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection, MSGBOX_NPC
# 230 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 231 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 232 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesBoard:: @ 8208A99
# 233 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	lockall
# 234 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
# 235 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 236 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 237 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 238 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard:: @ 8208AA8
# 239 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
# 240 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	waitmessage
# 241 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	multichoice 17, 0, MULTI_SLATEPORT_TENT_RULES, FALSE
# 242 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	switch VAR_RESULT
# 243 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 0, SlateportCity_BattleTentLobby_EventScript_RulesBasics
# 244 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 1, SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner
# 245 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 2, SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber
# 246 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 3, SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes
# 247 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 4, SlateportCity_BattleTentLobby_EventScript_RulesMons
# 248 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case 5, SlateportCity_BattleTentLobby_EventScript_ExitRules
# 249 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentLobby_EventScript_ExitRules
# 250 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 251 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 252 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesBasics:: @ 8208B06
# 253 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
# 254 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 255 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 256 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 257 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapPartner:: @ 8208B14
# 258 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
# 259 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 260 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 261 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 262 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapNumber:: @ 8208B22
# 263 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
# 264 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 265 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 266 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 267 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesSwapNotes:: @ 8208B30
# 268 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainSwapNotes, MSGBOX_DEFAULT
# 269 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 270 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 271 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 272 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_RulesMons:: @ 8208B3E
# 273 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	msgbox SlateportCity_BattleTentLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
# 274 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	goto SlateportCity_BattleTentLobby_EventScript_ReadRulesBoard
# 275 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 276 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 277 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_EventScript_ExitRules:: @ 8208B4C
# 278 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	releaseall
# 279 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	end
# 280 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 281 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_CouldntFindMonForMe: @ 8208B4E
# 282 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, like, I couldn't find myself any\n"
# 283 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Pokémon that were, like, for me.\p"
# 284 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, I figured, like, hey, I should file\n"
# 285 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a complaint to the guy there?\p"
# 286 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "And he wouldn't hear me out, like, hey!\n"
# 287 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "So, like, total bummer, man!\p"
# 288 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, like, you! Zip it, you know?\n"
# 289 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Just, you know, take this!$"
# 290 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 291 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_ExplainTorment: @ 8208C5C
# 292 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "That's, like, TM41, you know?\n"
# 293 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, it's Torment, you hearing me?\p"
# 294 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Like, it won't let the other guy\n"
# 295 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "use the same move twice in a row, see?\p"
# 296 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Hey, now, you listen here, like,\n"
# 297 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "I'm not laying a torment on you!$"
# 298 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 299 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_IllTryUsingBugMons: @ 8208D27
# 300 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "I don't really like Bug Pokémon,\n"
# 301 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "but maybe I'll try using some for\l"
# 302 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a change of pace.\p"
# 303 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Who knows, I might even get to like\n"
# 304 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "them!$"
# 305 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 306 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_BattleEvenWithoutToughMons: @ 8208DA6
# 307 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "You can battle all you want here even\n"
# 308 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "if you don't have any tough Pokémon.$"
# 309 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"

# 310 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
SlateportCity_BattleTentLobby_Text_NiceIfMoreSelection: @ 8208DF1
# 311 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "Wouldn't it be nice if they had more of\n"
# 312 "data/maps/SlateportCity_BattleTentLobby/scripts.pory"
	.string "a selection?$"
