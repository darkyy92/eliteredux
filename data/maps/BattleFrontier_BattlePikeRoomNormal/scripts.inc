# 1 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Objects in this room are set dynamically with OBJ_EVENT_GFX_VAR_0 and OBJ_EVENT_GFX_VAR_1
# 3 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Note: LOCALIDs shared with data/scripts/battle_pike.inc
# 4 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
.equ LOCALID_OBJ_0, 1
# 5 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
.equ LOCALID_OBJ_1, 2
# 6 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 7 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_MapScripts:: @ 825D152
# 8 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoom_OnResume
# 9 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
# 10 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomNormal_OnFrame
# 11 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
# 12 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.byte 0
# 13 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 14 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_OnFrame: @ 825D167
# 15 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom
# 16 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.2byte 0
# 17 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 18 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterRoom:: @ 825D171
# 19 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_TEMP_0, 1
# 20 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getroomtype
# 21 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 22 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom
# 23 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom
# 24 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom
# 25 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom
# 26 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom
# 27 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom
# 28 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 29 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 30 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterSingleBattleRoom:: @ 825D1C6
# 31 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 32 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 33 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 34 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 35 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 36 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 37 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 38 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 39 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 40 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 41 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 42 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 43 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 44 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 45 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle
# 46 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost:: @ 825D20A
# 47 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 48 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
# 49 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 50 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 51 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 52 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonSingleBattle:: @ 825D226
# 53 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 54 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 55 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 56 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 57 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterHardBattleRoom:: @ 825D231
# 58 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 59 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 60 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer, MSGBOX_DEFAULT
# 61 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 62 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 63 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 64 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 65 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 66 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 67 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 68 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 69 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 70 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 71 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 72 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 73 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 74 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 75 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle
# 76 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 77 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 78 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 79 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonHardBattle:: @ 825D285
# 80 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 81 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 82 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer
# 83 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 84 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 85 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 86 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth, MSGBOX_DEFAULT
# 87 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 88 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 89 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special HealPlayerParty
# 90 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2, MSGBOX_DEFAULT
# 91 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 92 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 93 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 94 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 95 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 96 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 97 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterBrainRoom:: @ 825D2BF
# 98 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 22
# 99 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 100 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer
# 101 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 102 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_prequeenheal
# 103 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 104 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 0, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal
# 105 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon
# 106 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 2, BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons
# 107 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 108 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter:: @ 825D2FB
# 109 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster, MSGBOX_DEFAULT
# 110 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 111 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special SpawnCameraObject
# 112 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp
# 113 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy
# 114 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 115 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playse SE_PIKE_CURTAIN_CLOSE
# 116 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
# 117 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 118 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
# 119 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 120 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed
# 121 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 122 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 123 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 60
# 124 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playse SE_PIKE_CURTAIN_OPEN
# 125 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 65
# 126 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed
# 127 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	showobjectat LOCALID_OBJ_0, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
# 128 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 129 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed
# 130 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 4
# 131 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen
# 132 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 133 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter
# 134 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 135 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getbrainstatus
# 136 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 137 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold
# 138 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
# 139 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
# 140 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 141 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, FALSE
# 142 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver
# 143 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen, MSGBOX_DEFAULT
# 144 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 145 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucySilver:: @ 825D3BD
# 146 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck, MSGBOX_DEFAULT
# 147 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
# 148 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, 1
# 149 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver
# 150 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 151 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 152 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucySilver:: @ 825D3DA
# 153 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_getsymbols
# 154 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, 0
# 155 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 156 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass, MSGBOX_DEFAULT
# 157 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 158 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 159 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol
# 160 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 161 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 162 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_givesymbol
# 163 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear, MSGBOX_DEFAULT
# 164 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 165 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 166 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 167 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_IntroLucyGold:: @ 825D416
# 168 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 169 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, FALSE
# 170 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_ne BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold
# 171 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain, MSGBOX_DEFAULT
# 172 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
# 173 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_BattleLucyGold:: @ 825D443
# 174 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn, MSGBOX_DEFAULT
# 175 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle
# 176 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, 1
# 177 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold
# 178 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 179 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 180 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucyGold:: @ 825D460
# 181 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_getsymbols
# 182 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, 2
# 183 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 184 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass, MSGBOX_DEFAULT
# 185 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 186 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 187 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine
# 188 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 189 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 190 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	frontier_givesymbol
# 191 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_IWontForget, MSGBOX_DEFAULT
# 192 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 193 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy
# 194 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 195 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 196 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DefeatedLucy:: @ 825D49D
# 197 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside
# 198 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 199 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
# 200 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 201 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_get PIKE_DATA_WIN_STREAK
# 202 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	addvar VAR_RESULT, 1
# 203 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_set PIKE_DATA_WIN_STREAK VAR_RESULT
# 204 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
# 205 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 206 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 207 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 208 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenNoHeal:: @ 825D4DC
# 209 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal, MSGBOX_DEFAULT
# 210 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 211 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 212 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 213 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealOneMon:: @ 825D4EA
# 214 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne, MSGBOX_DEFAULT
# 215 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 216 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 217 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 218 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 219 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 220 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_PreQueenHealTwoMons:: @ 825D4FC
# 221 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo, MSGBOX_DEFAULT
# 222 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 223 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 224 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_LucyEnter
# 225 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 226 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 227 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterFullHealRoom:: @ 825D50E
# 228 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 229 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 230 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer
# 231 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 232 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth
# 233 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 234 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 235 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 236 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special HealPlayerParty
# 237 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge, MSGBOX_DEFAULT
# 238 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 239 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit
# 240 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 241 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 242 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 243 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 244 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterDoubleBattleRoom:: @ 825D53E
# 245 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 246 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 247 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight
# 248 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft
# 249 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 250 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
# 251 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown
# 252 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 253 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer
# 254 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer
# 255 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 256 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1
# 257 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 258 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 0
# 259 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 260 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 261 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay 16
# 262 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
# 263 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 264 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_gettrainerintro 1
# 265 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 266 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 267 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_DOUBLE
# 268 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 269 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 270 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 271 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 272 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case 1, BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle
# 273 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	goto BattleFrontier_BattlePikeRoomNormal_EventScript_WarpToLobbyLost
# 274 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 275 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 276 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WonDoubleBattle:: @ 825D5DC
# 277 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2
# 278 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 279 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit
# 280 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 281 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit
# 282 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 283 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp
# 284 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 285 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 286 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 287 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_EnterStatusRoom:: @ 825D605
# 288 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lockall
# 289 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_WatchOut
# 290 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer
# 291 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 292 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatusmon
# 293 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 294 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_0x8004, PIKE_STATUSMON_KIRLIA
# 295 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack
# 296 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_0x8004, PIKE_STATUSMON_DUSCLOPS
# 297 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack
# 298 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled, MSGBOX_DEFAULT
# 299 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 300 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	releaseall
# 301 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 302 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 303 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaAttack:: @ 825D643
# 304 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop, MSGBOX_DEFAULT
# 305 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 306 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 307 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, 0
# 308 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 309 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatus
# 310 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, PIKE_STATUS_TOXIC
# 311 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic
# 312 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, PIKE_STATUS_BURN
# 313 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp
# 314 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, PIKE_STATUS_PARALYSIS
# 315 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave
# 316 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, PIKE_STATUS_SLEEP
# 317 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis
# 318 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_flashscreen
# 319 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 320 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
# 321 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 322 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
# 323 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 324 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 325 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, 0
# 326 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 327 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
# 328 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 329 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_KIRLIA, 0
# 330 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 331 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 332 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
# 333 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
# 334 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 335 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia, MSGBOX_DEFAULT
# 336 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 337 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 338 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsAttack:: @ 825D6D5
# 339 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop, MSGBOX_DEFAULT
# 340 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 341 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 342 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, 0
# 343 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 344 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getstatus
# 345 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, PIKE_STATUS_FREEZE
# 346 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam
# 347 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, PIKE_STATUS_BURN
# 348 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp
# 349 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_flashscreen
# 350 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 351 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon
# 352 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 353 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC
# 354 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 355 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 356 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, 0
# 357 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 358 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough, MSGBOX_DEFAULT
# 359 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitse
# 360 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playmoncry SPECIES_DUSCLOPS, 0
# 361 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmoncry
# 362 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 363 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside
# 364 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer
# 365 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 366 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops, MSGBOX_DEFAULT
# 367 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 368 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 369 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedToxic:: @ 825D751
# 370 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic
# 371 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 372 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 373 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 374 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedWillOWisp:: @ 825D758
# 375 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp
# 376 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 377 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 378 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 379 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedThunderWave:: @ 825D75F
# 380 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave
# 381 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 382 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 383 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 384 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_KirliaUsedHypnosis:: @ 825D766
# 385 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis
# 386 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 387 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 388 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 389 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedIceBeam:: @ 825D76D
# 390 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam
# 391 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 392 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 393 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 394 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DusclopsUsedWillOWisp:: @ 825D774
# 395 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	message BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp
# 396 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 397 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 398 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 399 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_DoPikeQueenBattle:: @ 825D77B
# 400 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 401 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2
# 402 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 403 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_PIKE_SINGLE
# 404 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setvar VAR_0x8005, 0
# 405 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DoSpecialTrainerBattle
# 406 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitstate
# 407 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 408 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 409 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_ApproachPlayer: @ 825D795
# 410 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 411 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 412 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 413 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 414 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_NPCExit: @ 825D798
# 415 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 416 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 417 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 418 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 419 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 420 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 421 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 422 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit: @ 825D79E
# 423 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 424 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 425 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 426 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 427 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 428 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_NPCApproachMon: @ 825D7A2
# 429 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 430 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 431 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 432 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_StatusNPCApproachPlayer: @ 825D7A4
# 433 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 434 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 435 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay_16
# 436 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	delay_16
# 437 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 438 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 439 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 440 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonApproachPlayer: @ 825D7AA
# 441 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_down
# 442 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_right
# 443 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_right
# 444 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_down
# 445 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_fast_left
# 446 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 447 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 448 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 449 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceNPC: @ 825D7B1
# 450 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_up
# 451 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 452 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 453 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside: @ 825D7B3
# 454 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 455 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight: @ 825D7B4
# 456 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 457 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 458 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 459 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCApproachPlayer: @ 825D7B6
# 460 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 461 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 462 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 463 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_down
# 464 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 465 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 466 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer1: @ 825D7BB
# 467 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 468 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 469 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 470 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceTrainer2: @ 825D7BD
# 471 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 472 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 473 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 474 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerFaceUp: @ 825D7BF
# 475 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_up
# 476 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 477 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 478 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1WalkRight: @ 825D7C1
# 479 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 480 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 481 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 482 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2WalkLeft: @ 825D7C3
# 483 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 484 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 485 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 486 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_DoubleTrainersWalkDown: @ 825D7C5
# 487 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 488 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 489 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 490 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 491 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1FacePlayer: @ 825D7C8
# 492 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 493 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 494 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 495 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2FacePlayer: @ 825D7CA
# 496 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_left
# 497 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 498 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 499 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer1Exit: @ 825D7CC
# 500 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 501 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 502 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 503 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_right
# 504 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 505 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 506 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 507 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 508 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 509 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_Trainer2Exit: @ 825D7D4
# 510 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 511 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 512 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 513 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 514 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 515 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 516 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 517 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 518 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 519 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ For approaching Lucy and exiting room after defeating Lucy
# 520 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PlayerWalkUp2: @ 825D7DC
# 521 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 522 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 523 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 524 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 525 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_PreQueenHealNPCApproachPlayer: @ 825D7DF
# 526 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 527 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 528 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 529 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 530 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExitForLucy: @ 825D7E2
# 531 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 532 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 533 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 534 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_invisible
# 535 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 536 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 537 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_LucyEnter: @ 825D7E7
# 538 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	set_visible
# 539 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 540 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 541 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 542 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_LucyMoveAside: @ 825D7EA
# 543 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_left
# 544 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	face_right
# 545 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 546 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 547 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_NPC:: @ 825D7ED
# 548 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getroomtype
# 549 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	switch VAR_RESULT
# 550 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC
# 551 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC
# 552 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC
# 553 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_NormalNPC:: @ 825D81B
# 554 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 555 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 556 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_getnpcmsg
# 557 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 558 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmessage
# 559 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 560 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 561 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 562 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 563 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusNPC:: @ 825D831
# 564 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 565 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 566 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine, MSGBOX_DEFAULT
# 567 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 568 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 569 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 570 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 571 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_HealNPC:: @ 825D83E
# 572 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	pike_healonetwomons
# 573 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, 2
# 574 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons
# 575 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	compare VAR_RESULT, 1
# 576 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	call_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon
# 577 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	playfanfare MUS_HEAL
# 578 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitfanfare
# 579 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell, MSGBOX_DEFAULT
# 580 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 581 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 582 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_0, BattleFrontier_BattlePikeRoomNormal_Movement_HealNPCExit
# 583 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 584 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 585 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 586 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreOneMon:: @ 825D875
# 587 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 588 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 589 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon, MSGBOX_DEFAULT
# 590 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 591 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 592 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 593 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_WillRestoreTwoMons:: @ 825D881
# 594 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 595 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 596 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons, MSGBOX_DEFAULT
# 597 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 598 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 599 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 600 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Dusclops or Kirlia
# 601 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_StatusMon:: @ 825D88D
# 602 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	lock
# 603 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	faceplayer
# 604 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	msgbox BattleFrontier_BattlePikeRoomNormal_Text_Silence, MSGBOX_DEFAULT
# 605 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	closemessage
# 606 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	release
# 607 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	applymovement LOCALID_OBJ_1, BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight
# 608 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	waitmovement 0
# 609 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	end
# 610 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 611 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesMostlyClosed:: @ 825D8A4
# 612 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage1_Tile0, 1
# 613 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage1_Tile1, 1
# 614 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage1_Tile2, 1
# 615 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage1_Tile3, 1
# 616 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage1_Tile4, 1
# 617 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage1_Tile5, 0
# 618 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage1_Tile6, 1
# 619 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 620 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 621 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 622 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesLittleClosed:: @ 825D8E7
# 623 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage2_Tile0, 1
# 624 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage2_Tile1, 1
# 625 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage2_Tile2, 1
# 626 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage2_Tile3, 1
# 627 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage2_Tile4, 1
# 628 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage2_Tile5, 0
# 629 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage2_Tile6, 1
# 630 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 631 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 632 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 633 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesOpen:: @ 825D92A
# 634 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage3_Tile0, 1
# 635 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage3_Tile1, 1
# 636 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage3_Tile2, 1
# 637 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage3_Tile3, 1
# 638 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage3_Tile4, 1
# 639 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage3_Tile5, 0
# 640 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage3_Tile6, 1
# 641 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 642 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 643 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 644 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetCurtainTilesClosed:: @ 825D96D
# 645 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 1, METATILE_BattlePike_Curtain_Stage0_Tile0, 1
# 646 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 2, METATILE_BattlePike_Curtain_Stage0_Tile1, 1
# 647 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 2, METATILE_BattlePike_Curtain_Stage0_Tile2, 1
# 648 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 2, METATILE_BattlePike_Curtain_Stage0_Tile3, 1
# 649 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 3, 3, METATILE_BattlePike_Curtain_Stage0_Tile4, 1
# 650 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 4, 3, METATILE_BattlePike_Curtain_Stage0_Tile5, 0
# 651 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	setmetatile 5, 3, METATILE_BattlePike_Curtain_Stage0_Tile6, 1
# 652 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	special DrawWholeMapView
# 653 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	return
# 654 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 655 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanUp: @ 825D9B0
# 656 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 657 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_up
# 658 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 659 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 660 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 661 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Movement_CameraPanDown: @ 825D9B3
# 662 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 663 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	walk_down
# 664 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	step_end
# 665 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 666 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreToFullHealth: @ 825D9B6
# 667 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Welcome…\n"
# 668 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You must be commended for your luck…\p"
# 669 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Your Pokémon shall be restored\n"
# 670 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health…$"
# 671 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 672 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge: @ 825DA13
# 673 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I urge you to enjoy the rest of your\n"
# 674 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Battle Choice challenge…$"
# 675 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 676 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreOneMon: @ 825DA51
# 677 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Ah, you're a lucky one.\n"
# 678 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'm in somewhat-good spirits now.\p"
# 679 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I will restore one of your Pokémon\n"
# 680 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health.$"
# 681 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 682 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell: @ 825DABE
# 683 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The best of luck to you.\n"
# 684 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Farewell.$"
# 685 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 686 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Seems there was a planned room type where the player could choose to battle and would be healed if they won
# 687 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Possibly replaced/superseded by the hard battle room, which is the same but the battle isnt optional
# 688 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 689 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_CareForBattleWillRestoreMons: @ 825DAE1
# 690 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Excuse me…\p"
# 691 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Would you care for a battle?\n"
# 692 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'll restore your Pokémon if you win.$"
# 693 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 694 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 695 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_NowShallWe: @ 825DB2F
# 696 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Very well…\n"
# 697 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, shall we?$"
# 698 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 699 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 700 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_HowUnsportingOfYou: @ 825DB49
# 701 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I see…\n"
# 702 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "How unsporting of you…$"
# 703 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 704 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 705 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreMonsAsPromised: @ 825DB67
# 706 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Magnificent…\p"
# 707 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "As promised, I shall restore your\n"
# 708 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Pokémon to full health.$"
# 709 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 710 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 711 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BestOfLuckFarewell2: @ 825DBAE
# 712 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The best of luck to you.\n"
# 713 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Farewell.$"
# 714 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 715 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WatchOut: @ 825DBD1
# 716 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Oh, my!\p"
# 717 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Watch out!$"
# 718 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 719 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaStop: @ 825DBE4
# 720 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, now!\n"
# 721 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA, stop that!$"
# 722 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 723 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsStop: @ 825DC01
# 724 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now, now!\n"
# 725 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS, stop that!$"
# 726 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 727 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedToxic: @ 825DC20
# 728 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used TOXIC!$"
# 729 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 730 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedHypnosis: @ 825DC33
# 731 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used HYPNOSIS!$"
# 732 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 733 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedThunderWave: @ 825DC49
# 734 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used THUNDER WAVE!$"
# 735 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 736 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_KirliaUsedWillOWisp: @ 825DC63
# 737 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "KIRLIA used WILL-O-WISP!$"
# 738 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 739 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedWillOWisp: @ 825DC7C
# 740 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS used WILL-O-WISP!$"
# 741 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 742 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_DusclopsUsedIceBeam: @ 825DC97
# 743 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "DUSCLOPS used ICE BEAM!$"
# 744 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 745 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ThatsEnough: @ 825DCAF
# 746 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Look here!\n"
# 747 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "That's quite enough!$"
# 748 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 749 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForKirlia: @ 825DCCF
# 750 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I must apologize to you…\p"
# 751 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "My KIRLIA has a TIMID nature…$"
# 752 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 753 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeForDusclops: @ 825DD06
# 754 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I must apologize to you…\p"
# 755 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "My DUSCLOPS has a TIMID nature…$"
# 756 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 757 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_AttacksWhenStartled: @ 825DD3F
# 758 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "It attacks without warning if it is\n"
# 759 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "startled by another person…\p"
# 760 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Are you and your Pokémon all right?$"
# 761 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 762 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ApologizeHopeMonsAreFine: @ 825DDA3
# 763 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I do apologize for what happened…\n"
# 764 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I do hope your Pokémon are fine.$"
# 765 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 766 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_Silence: @ 825DDE6
# 767 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\n"
# 768 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …$"
# 769 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 770 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_BattleSomewhatToughTrainer: @ 825DDFE
# 771 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Welcome…\p"
# 772 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Here, we will have you battle\n"
# 773 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "a somewhat-tough Trainer…$"
# 774 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 775 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_RestoreToFullHealth: @ 825DE3F
# 776 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "How wonderful…\p"
# 777 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "To honor your victory, your Pokémon\n"
# 778 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "shall be restored to full health…$"
# 779 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 780 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_EnjoyRestOfChallenge2: @ 825DE94
# 781 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I urge you to enjoy the rest of your\n"
# 782 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Battle Choice challenge…$"
# 783 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 784 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ImThePikeQueen: @ 825DED2
# 785 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I am LUCY…\n"
# 786 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I am the law here…\l"
# 787 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "For I am the PIKE QUEEN…\p"
# 788 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You already know it, but to advance,\n"
# 789 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "you must defeat me…\p"
# 790 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…I'm not one for idle chatter.\n"
# 791 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Hurry. Come on…$"
# 792 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 793 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_HopeYouDidntUseUpLuck: @ 825DF71
# 794 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Your luck…\n"
# 795 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I hope you didn't use it all up here…$"
# 796 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 797 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyShowMeFrontierPass: @ 825DFA2
# 798 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: … … … … … …\n"
# 799 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Show me your FRONTIER PASS…$"
# 800 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 801 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ReceivedLuckSymbol: @ 825DFD0
# 802 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The Luck Symbol was embossed on\n"
# 803 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "the FRONTIER PASS!$"
# 804 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 805 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_AllThereIsDisappear: @ 825E003
# 806 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…That's all there is…\n"
# 807 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Disappear already…$"
# 808 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 809 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyYouAgain: @ 825E02C
# 810 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: …You again…\p"
# 811 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\p"
# 812 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…I've trampled flowers and braved\n"
# 813 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "storms to get to where I am…\p"
# 814 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I don't feel any compulsion to keep\n"
# 815 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "losing to the same opponent…\p"
# 816 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "… … … … … …\n"
# 817 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Fine… I'll do it…$"
# 818 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 819 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_NowComeOn: @ 825E0E8
# 820 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Now!\n"
# 821 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Come on!$"
# 822 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 823 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LucyFrontierPass: @ 825E0F6
# 824 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "LUCY: … … … … … …\p"
# 825 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…FRONTIER PASS…$"
# 826 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 827 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_LuckSymbolTookGoldenShine: @ 825E118
# 828 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "The Luck Symbol took on\n"
# 829 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "a golden shine!$"
# 830 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 831 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_IWontForget: @ 825E140
# 832 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…You, I won't forget…\n"
# 833 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "…Ever…$"
# 834 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 835 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomNoHeal: @ 825E15D
# 836 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 837 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Giggle…\n"
# 838 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You seem to be bereft of luck…\p"
# 839 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "If only you hadn't chosen this room,\n"
# 840 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "your Pokémon could have been healed…$"
# 841 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 842 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealOne: @ 825E1DD
# 843 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 844 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room, I will\n"
# 845 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "restore one Pokémon to full health…$"
# 846 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 847 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ChoseRoomHealTwo: @ 825E238
# 848 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 849 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room, I will\n"
# 850 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "restore two Pokémon to full health…$"
# 851 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 852 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
@ Unused
# 853 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreAllMons: @ 825E293
# 854 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I welcome you…\p"
# 855 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Giggle…\n"
# 856 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "You should thank your lucky stars…\p"
# 857 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Since you have chosen this room,\n"
# 858 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "all your Pokémon will be restored…$"
# 859 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 860 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_ShallFetchOurMaster: @ 825E311
# 861 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I shall go fetch our master…$"
# 862 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"

# 863 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
BattleFrontier_BattlePikeRoomNormal_Text_WillRestoreTwoMons: @ 825E32E
# 864 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "Ah, you're a lucky one!\n"
# 865 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I'm in good spirits now.\p"
# 866 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "I will restore two of your Pokémon\n"
# 867 "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.pory"
	.string "to full health!$"
