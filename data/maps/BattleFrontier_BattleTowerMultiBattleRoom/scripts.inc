# 1 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_OPPONENT_1, 1
# 3 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT_1, 2
# 4 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_ATTENDANT_2, 3
# 5 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_OPPONENT_2, 4
# 6 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_PLAYER, 5
# 7 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
.set LOCALID_PARTNER, 6
# 8 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 9 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_MapScripts:: @ 8248EE8
# 10 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiBattleRoom_OnTransition
# 11 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnWarp
# 12 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiBattleRoom_OnFrame
# 13 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.byte 0
# 14 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 15 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ On this map the player (OBJ_EVENT_ID_PLAYER) is hidden
# 16 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ The player is represented instead by LOCALID_PLAYER, which has the gfx id VAR_OBJ_GFX_ID_F
# 17 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	@ The multi partner is represented by LOCALID_PARTNER, which has the gfx id VAR_OBJ_GFX_ID_E
# 18 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 19 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnTransition: @ 8248EF8
# 20 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
# 21 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx
# 22 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 23 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx
# 24 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 25 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 26 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetObjGfx:: @ 8248F0F
# 27 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setpartnergfx
# 28 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	checkplayergender
# 29 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_RESULT, FEMALE
# 30 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale
# 31 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 32 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 33 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 34 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetPlayerGfxFemale:: @ 8248F29
# 35 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_MAY_NORMAL
# 36 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 37 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 38 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_SetLinkPlayerGfx:: @ 8248F2F
# 39 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special SetBattleTowerLinkPlayerGfx
# 40 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 41 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 42 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnWarp: @ 8248F33
# 43 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj
# 44 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.2byte 0
# 45 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 46 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_HidePlayerObj:: @ 8248F3D
# 47 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM
# 48 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 49 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 50 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_OnFrame: @ 8248F43
# 51 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom
# 52 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.2byte 0
# 53 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 54 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_EnterRoom:: @ 8248F4D
# 55 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 56 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom
# 57 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom
# 58 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 59 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 60 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 61 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
# 62 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 63 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 64 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 65 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 66 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 67 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 68 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 69 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 70 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 71 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter:: @ 8248FB4
# 72 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setopponent
# 73 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT_1
# 74 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	addobject LOCALID_OPPONENT_2
# 75 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter
# 76 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter
# 77 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 78 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 79 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink
# 80 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 81 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 15
# 82 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 83 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 84 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 85 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 86 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 1
# 87 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 88 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 89 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 90 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 91 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle
# 92 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 93 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoOpponentIntrosLink:: @ 8249026
# 94 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 0
# 95 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 15
# 96 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 97 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 98 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll gStringVar4
# 99 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 100 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 101 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_getopponentintro 1
# 102 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft
# 103 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 104 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll gStringVar4
# 105 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 106 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 107 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DoTowerBattle:: @ 8249069
# 108 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerBattleRoom_EventScript_DoTowerBattle
# 109 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 110 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case B_OUTCOME_WON, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents
# 111 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost:: @ 824907E
# 112 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 113 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 114 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 115 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 116 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 117 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 118 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_DefeatedOpponents:: @ 82490AA
# 119 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 120 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_setbattlewon
# 121 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 122 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 7, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon
# 123 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit
# 124 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_OPPONENT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit
# 125 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 126 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT_1
# 127 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	removeobject LOCALID_OPPONENT_2
# 128 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 129 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer
# 130 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 131 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 132 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant
# 133 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 134 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 135 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink
# 136 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth, MSGBOX_DEFAULT
# 137 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty
# 138 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 139 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetorePartyMsgLink:: @ 8249118
# 140 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	messageautoscroll BattleFrontier_BattleTowerBattleRoom_Text_RestoreMonsToFullHealth
# 141 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 142 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 143 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RestoreParty:: @ 8249121
# 144 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LoadPlayerParty
# 145 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_setpartyorder FRONTIER_MULTI_PARTY_SIZE
# 146 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 147 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink
# 148 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	playfanfare MUS_HEAL
# 149 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitfanfare
# 150 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special HealPlayerParty
# 151 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents:: @ 8249143
# 152 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 153 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet
# 154 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 155 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 156 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_GetCantRecordBattle
# 157 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 158 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord
# 159 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 19, 4, MULTI_GO_ON_RECORD_REST_RETIRE, TRUE
# 160 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 162 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle
# 163 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
# 164 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
# 165 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 166 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 167 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsNoRecord:: @ 82491B1
# 168 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 169 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 170 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge
# 171 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge
# 172 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge
# 173 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 174 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 175 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattle:: @ 82491E7
# 176 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 177 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 178 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 179 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 180 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 181 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle
# 182 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 183 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 184 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RecordBattle:: @ 8249219
# 185 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 186 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 187 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 188 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskPauseChallenge:: @ 8249223
# 189 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 190 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 191 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case NO, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 192 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case YES, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge
# 193 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 194 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 195 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallenge:: @ 8249251
# 196 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 197 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 198 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 199 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 200 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 201 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 202 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 203 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 204 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallenge:: @ 8249283
# 205 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	closemessage
# 206 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 207 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
# 208 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_PARTNER, BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle
# 209 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 210 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_1, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
# 211 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT_2, BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos
# 212 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmovement 0
# 213 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_OpponentsEnter
# 214 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 215 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 216 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyWon:: @ 82492AF
# 217 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
# 218 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_set TOWER_DATA_LVL_MODE
# 219 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, FANCOUNTER_USED_BATTLE_TOWER
# 220 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special Script_TryGainNewFanFromCounter
# 221 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerBattleRoom_EventScript_WarpToLobby
# 222 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 223 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_PauseChallenge:: @ 82492DB
# 224 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_SavingPleaseWait
# 225 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 226 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	tower_save CHALLENGE_STATUS_PAUSED
# 227 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	playse SE_SAVE
# 228 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitse
# 229 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	fadescreen 1
# 230 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	frontier_reset
# 231 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 232 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 233 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSet:: @ 82492FD
# 234 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
# 235 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink
# 236 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 237 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 238 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet
# 239 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet
# 240 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet
# 241 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet
# 242 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet
# 243 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet
# 244 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 245 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSet:: @ 8249354
# 246 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
# 247 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 248 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 249 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 250 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSet:: @ 824935B
# 251 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
# 252 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 253 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 254 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 255 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSet:: @ 8249362
# 256 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
# 257 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 258 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 259 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 260 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSet:: @ 8249369
# 261 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
# 262 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 263 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 264 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 265 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSet:: @ 8249370
# 266 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
# 267 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 268 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 269 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 270 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSet:: @ 8249377
# 271 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
# 272 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 273 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 274 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 275 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyForNextOpponentSetLink:: @ 824937E
# 276 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	copyvar VAR_TEMP_F, VAR_RESULT
# 277 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_TEMP_F
# 278 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink
# 279 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink
# 280 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 3, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink
# 281 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 4, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink
# 282 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 5, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink
# 283 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 6, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink
# 284 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 285 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor2ndOpponentSetLink:: @ 82493CA
# 286 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet
# 287 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 288 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 289 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 290 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 291 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor3rdOpponentSetLink:: @ 82493D6
# 292 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet
# 293 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 294 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 295 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 296 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 297 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor4thOpponentSetLink:: @ 82493E2
# 298 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet
# 299 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 300 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 301 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 302 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 303 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor5thOpponentSetLink:: @ 82493EE
# 304 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet
# 305 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 306 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 307 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 308 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 309 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor6thOpponentSetLink:: @ 82493FA
# 310 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet
# 311 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 312 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 313 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 314 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 315 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReadyFor7thOpponentSetLink:: @ 8249406
# 316 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet
# 317 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 318 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink
# 319 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 320 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 321 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg:: @ 8249412
# 322 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 323 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	delay 48
# 324 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 325 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 326 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLink:: @ 8249417
# 327 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_set FLAG_TEMP_2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord
# 328 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 19, 6, MULTI_GO_ON_RECORD_RETIRE, TRUE
# 329 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 330 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
# 331 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink
# 332 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 2, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 333 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 334 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 335 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 336 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponentsLinkNoRecord:: @ 8249457
# 337 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoice 20, 8, MULTI_GO_ON_RETIRE, TRUE
# 338 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 339 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 0, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink
# 340 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 341 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink
# 342 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 343 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 344 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ContinueChallengeLink:: @ 8249483
# 345 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, BATTLE_TOWER_LINK_CONTINUE
# 346 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 347 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message gText_LinkStandby3
# 348 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 349 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LinkRetireStatusWithBattleTowerPartner
# 350 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitstate
# 351 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_RESULT, BATTLE_TOWER_LINKSTAT_CONTINUE
# 352 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_ne BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 353 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_LinkDelayForMsg
# 354 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 355 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 356 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRecordBattleLink:: @ 82494A8
# 357 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_RecordYourBattle
# 358 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 359 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 360 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	switch VAR_RESULT
# 361 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 362 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 363 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	call BattleFrontier_EventScript_SaveBattle
# 364 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 365 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 366 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 367 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 368 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskRetireChallengeLink:: @ 82494DD
# 369 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message BattleFrontier_BattleTowerBattleRoom_Text_CancelYourChallenge
# 370 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 371 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 372 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	compare VAR_RESULT, 0
# 373 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink
# 374 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_AskReadyForOpponents
# 375 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 376 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 377 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_RetireChallengeLink:: @ 82494FA
# 378 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8004, BATTLE_TOWER_LINK_RETIRE
# 379 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 380 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	message gText_LinkStandby3
# 381 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitmessage
# 382 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special LinkRetireStatusWithBattleTowerPartner
# 383 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	waitstate
# 384 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiBattleRoom_EventScript_WarpToLobbyLost
# 385 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	end
# 386 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 387 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_EventScript_ReconnectLink:: @ 8249514
# 388 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	special BattleTowerReconnectLink
# 389 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	return
# 390 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 391 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_PlayerEnterRoom: @ 8249518
# 392 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 393 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 394 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 395 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 396 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_right
# 397 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 398 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 399 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_PartnerEnterRoom: @ 824951E
# 400 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 401 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 402 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 403 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 404 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_right
# 405 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 406 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 407 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceAttendant: @ 8249524
# 408 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 409 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 410 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 411 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_FaceBattle: @ 8249526
# 412 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 413 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 414 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 415 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Enter: @ 8249528
# 416 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 417 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 418 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 419 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 420 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 421 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 422 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 423 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Enter: @ 824952E
# 424 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 425 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 426 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 427 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_down
# 428 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	face_left
# 429 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 430 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 431 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent2Exit: @ 8249534
# 432 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 433 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 434 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 435 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	set_invisible
# 436 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 437 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 438 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_Opponent1Exit: @ 8249539
# 439 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 440 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 441 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 442 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_up
# 443 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 444 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 445 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantApproachPlayer: @ 824953E
# 446 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 447 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_right
# 448 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 449 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 450 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_AttendantReturnToPos: @ 8249541
# 451 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 452 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_left
# 453 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_fastest_right
# 454 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 455 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 456 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Movement_WalkInPlaceLeft: @ 8249545
# 457 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	walk_in_place_left
# 458 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	step_end
# 459 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 460 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor2ndOpponentSet: @ 8249547
# 461 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 2nd set of opponents is next.\n"
# 462 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 463 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 464 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor3rdOpponentSet: @ 8249578
# 465 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 3rd set of opponents is next.\n"
# 466 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 467 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 468 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor4thOpponentSet: @ 82495A9
# 469 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 4th set of opponents is next.\n"
# 470 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 471 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 472 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor5thOpponentSet: @ 82495DA
# 473 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 5th set of opponents is next.\n"
# 474 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 475 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 476 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor6thOpponentSet: @ 824960B
# 477 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 6th set of opponents is next.\n"
# 478 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 479 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 480 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_ReadyFor7thOpponentSet: @ 824963C
# 481 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 7th set of opponents is next.\n"
# 482 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Are you ready?$"
# 483 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 484 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 485 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_2ndOpponentSetNext: @ 824966D
# 486 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 2nd set of opponents is next.\n"
# 487 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 488 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 489 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 490 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_3rdOpponentSetNext: @ 824969D
# 491 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 3rd set of opponents is next.\n"
# 492 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 493 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 494 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 495 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_4thOpponentSetNext: @ 82496CD
# 496 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 4th set of opponents is next.\n"
# 497 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 498 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 499 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 500 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_5thOpponentSetNext: @ 82496FD
# 501 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 5th set of opponents is next.\n"
# 502 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 503 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 504 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 505 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_6thOpponentSetNext: @ 824972D
# 506 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 6th set of opponents is next.\n"
# 507 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 508 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 509 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
@ Unused
# 510 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
BattleFrontier_BattleTowerMultiBattleRoom_Text_7thOpponentSetNext: @ 824975D
# 511 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "The 7th set of opponents is next.\n"
# 512 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Do your best!$"
# 513 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 514 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
gText_LinkStandby3:: @ 824978D
# 515 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Link standby…$"
# 516 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"

# 517 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
gText_YourPartnerHasRetired:: @ 824979B
# 518 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Your partner has retired.\p"
# 519 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "Your BATTLE ROOM challenge\n"
# 520 "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.pory"
	.string "will be canceled.$"
