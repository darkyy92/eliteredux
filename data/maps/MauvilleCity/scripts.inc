# 1 "data/maps/MauvilleCity/scripts.pory"

# 2 "data/maps/MauvilleCity/scripts.pory"
.set LOCALID_WALLY, 6
# 3 "data/maps/MauvilleCity/scripts.pory"
.set LOCALID_WALLYS_UNCLE, 7
# 4 "data/maps/MauvilleCity/scripts.pory"
.set LOCALID_SCOTT, 10
# 5 "data/maps/MauvilleCity/scripts.pory"

# 6 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_MapScripts:: @ 81DF385
# 7 "data/maps/MauvilleCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
# 8 "data/maps/MauvilleCity/scripts.pory"
	.byte 0
# 9 "data/maps/MauvilleCity/scripts.pory"

# 10 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_OnTransition: @ 81DF38B
# 11 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_VISITED_MAUVILLE_CITY
# 12 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
# 13 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
# 14 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_SYS_TV_START
# 15 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
# 16 "data/maps/MauvilleCity/scripts.pory"
	setvar VAR_MAUVILLE_GYM_STATE, 0
# 17 "data/maps/MauvilleCity/scripts.pory"
	call_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
# 18 "data/maps/MauvilleCity/scripts.pory"
	end
# 19 "data/maps/MauvilleCity/scripts.pory"

# 20 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_MoveWattsonBackToGym:: @ 81DF3A9
# 21 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 22 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
# 23 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
# 24 "data/maps/MauvilleCity/scripts.pory"
	return
# 25 "data/maps/MauvilleCity/scripts.pory"

# 26 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_GyroBallTM::
# 27 "data/maps/MauvilleCity/scripts.pory"
	lock
# 28 "data/maps/MauvilleCity/scripts.pory"
	faceplayer
# 29 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_HaveTM74, MSGBOX_DEFAULT
# 30 "data/maps/MauvilleCity/scripts.pory"
	release
# 31 "data/maps/MauvilleCity/scripts.pory"
	end
# 32 "data/maps/MauvilleCity/scripts.pory"

# 33 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ReceivedTM74::
# 34 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_HaveTM74, MSGBOX_DEFAULT
# 35 "data/maps/MauvilleCity/scripts.pory"
	release
# 36 "data/maps/MauvilleCity/scripts.pory"
	end
# 37 "data/maps/MauvilleCity/scripts.pory"

# 38 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Boy:: @ 81DF3B3
# 39 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
# 40 "data/maps/MauvilleCity/scripts.pory"
	end
# 41 "data/maps/MauvilleCity/scripts.pory"

# 42 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Maniac:: @ 81DF3BC
# 43 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
# 44 "data/maps/MauvilleCity/scripts.pory"
	end
# 45 "data/maps/MauvilleCity/scripts.pory"

# 46 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Woman:: @ 81DF3C5
# 47 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
# 48 "data/maps/MauvilleCity/scripts.pory"
	end
# 49 "data/maps/MauvilleCity/scripts.pory"

# 50 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_RichBoy:: @ 81DF3CE
# 51 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
# 52 "data/maps/MauvilleCity/scripts.pory"
	end
# 53 "data/maps/MauvilleCity/scripts.pory"

# 54 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_CitySign:: @ 81DF3D7
# 55 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
# 56 "data/maps/MauvilleCity/scripts.pory"
	end
# 57 "data/maps/MauvilleCity/scripts.pory"

# 58 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_GymSign:: @ 81DF3E0
# 59 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
# 60 "data/maps/MauvilleCity/scripts.pory"
	end
# 61 "data/maps/MauvilleCity/scripts.pory"

# 62 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_BikeShopSign:: @ 81DF3E9
# 63 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
# 64 "data/maps/MauvilleCity/scripts.pory"
	end
# 65 "data/maps/MauvilleCity/scripts.pory"

# 66 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_GameCornerSign:: @ 81DF3F2
# 67 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
# 68 "data/maps/MauvilleCity/scripts.pory"
	end
# 69 "data/maps/MauvilleCity/scripts.pory"

# 70 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_MoveTutorSign::
# 71 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_MoveTutorSign, MSGBOX_SIGN
# 72 "data/maps/MauvilleCity/scripts.pory"
	end
# 73 "data/maps/MauvilleCity/scripts.pory"

# 74 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_SchoolKidM:: @ 81DF3FB
# 75 "data/maps/MauvilleCity/scripts.pory"
	lock
# 76 "data/maps/MauvilleCity/scripts.pory"
	faceplayer
# 77 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
# 78 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
# 79 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_TV_EXPLAINED
# 80 "data/maps/MauvilleCity/scripts.pory"
	release
# 81 "data/maps/MauvilleCity/scripts.pory"
	end
# 82 "data/maps/MauvilleCity/scripts.pory"

# 83 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_TVExplained:: @ 81DF413
# 84 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
# 85 "data/maps/MauvilleCity/scripts.pory"
	release
# 86 "data/maps/MauvilleCity/scripts.pory"
	end
# 87 "data/maps/MauvilleCity/scripts.pory"

# 88 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_WallysUncle:: @ 81DF41D
# 89 "data/maps/MauvilleCity/scripts.pory"
	lock
# 90 "data/maps/MauvilleCity/scripts.pory"
	faceplayer
# 91 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
# 92 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
# 93 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 94 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
# 95 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 96 "data/maps/MauvilleCity/scripts.pory"
	release
# 97 "data/maps/MauvilleCity/scripts.pory"
	end
# 98 "data/maps/MauvilleCity/scripts.pory"

# 99 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_UncleAskPlayerToBattleWally:: @ 81DF43D
# 100 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
# 101 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 102 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
# 103 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 104 "data/maps/MauvilleCity/scripts.pory"
	release
# 105 "data/maps/MauvilleCity/scripts.pory"
	end
# 106 "data/maps/MauvilleCity/scripts.pory"

# 107 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Wally:: @ 81DF452
# 108 "data/maps/MauvilleCity/scripts.pory"
	lockall
# 109 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
# 110 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
# 111 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 112 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
# 113 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
# 114 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
# 115 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
# 116 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 117 "data/maps/MauvilleCity/scripts.pory"
	playse SE_PIN
# 118 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
# 119 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 120 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_Delay48
# 121 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 122 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
# 123 "data/maps/MauvilleCity/scripts.pory"
	goto MauvilleCity_EventScript_BattleWallyPrompt
# 124 "data/maps/MauvilleCity/scripts.pory"
	end
# 125 "data/maps/MauvilleCity/scripts.pory"

# 126 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_BattleWallyPrompt:: @ 81DF4AD
# 127 "data/maps/MauvilleCity/scripts.pory"
	compare VAR_RESULT, YES
# 128 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq MauvilleCity_EventScript_BattleWally
# 129 "data/maps/MauvilleCity/scripts.pory"
	compare VAR_RESULT, NO
# 130 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq MauvilleCity_EventScript_DeclineWallyBattle
# 131 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 132 "data/maps/MauvilleCity/scripts.pory"
	switch VAR_FACING
# 133 "data/maps/MauvilleCity/scripts.pory"
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
# 134 "data/maps/MauvilleCity/scripts.pory"
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
# 135 "data/maps/MauvilleCity/scripts.pory"
	end
# 136 "data/maps/MauvilleCity/scripts.pory"

# 137 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_WallyAndUncleExitNorth:: @ 81DF4E0
# 138 "data/maps/MauvilleCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
# 139 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
# 140 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
# 141 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 142 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
# 143 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 144 "data/maps/MauvilleCity/scripts.pory"
	delay 30
# 145 "data/maps/MauvilleCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
# 146 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
# 147 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 148 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
# 149 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 150 "data/maps/MauvilleCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
# 151 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
# 152 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
# 153 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 154 "data/maps/MauvilleCity/scripts.pory"
	goto MauvilleCity_EventScript_DefeatedWally
# 155 "data/maps/MauvilleCity/scripts.pory"
	end
# 156 "data/maps/MauvilleCity/scripts.pory"

# 157 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_WallyAndUncleExitEast:: @ 81DF53D
# 158 "data/maps/MauvilleCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
# 159 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
# 160 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
# 161 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 162 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
# 163 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 164 "data/maps/MauvilleCity/scripts.pory"
	delay 30
# 165 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
# 166 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 167 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
# 168 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 169 "data/maps/MauvilleCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
# 170 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
# 171 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
# 172 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 173 "data/maps/MauvilleCity/scripts.pory"
	goto MauvilleCity_EventScript_DefeatedWally
# 174 "data/maps/MauvilleCity/scripts.pory"
	end
# 175 "data/maps/MauvilleCity/scripts.pory"

# 176 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_DefeatedWally:: @ 81DF593
# 177 "data/maps/MauvilleCity/scripts.pory"
	removeobject LOCALID_WALLY
# 178 "data/maps/MauvilleCity/scripts.pory"
	removeobject LOCALID_WALLYS_UNCLE
# 179 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
# 180 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
# 181 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
# 182 "data/maps/MauvilleCity/scripts.pory"
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
# 183 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
# 184 "data/maps/MauvilleCity/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 185 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq MauvilleCity_EventScript_ScottApproachPlayerNorth
# 186 "data/maps/MauvilleCity/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 187 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq MauvilleCity_EventScript_ScottApproachPlayerEast
# 188 "data/maps/MauvilleCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 189 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 190 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
# 191 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 192 "data/maps/MauvilleCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 193 "data/maps/MauvilleCity/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 194 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq MauvilleCity_EventScript_ScottExitNorth
# 195 "data/maps/MauvilleCity/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 196 "data/maps/MauvilleCity/scripts.pory"
	call_if_eq MauvilleCity_EventScript_ScottExitEast
# 197 "data/maps/MauvilleCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 198 "data/maps/MauvilleCity/scripts.pory"
	releaseall
# 199 "data/maps/MauvilleCity/scripts.pory"
	end
# 200 "data/maps/MauvilleCity/scripts.pory"

# 201 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ScottApproachPlayerNorth:: @ 81DF5F3
# 202 "data/maps/MauvilleCity/scripts.pory"
	addobject LOCALID_SCOTT
# 203 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
# 204 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 205 "data/maps/MauvilleCity/scripts.pory"
	return
# 206 "data/maps/MauvilleCity/scripts.pory"

# 207 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ScottApproachPlayerEast:: @ 81DF601
# 208 "data/maps/MauvilleCity/scripts.pory"
	setobjectxyperm LOCALID_SCOTT, 12, 13
# 209 "data/maps/MauvilleCity/scripts.pory"
	addobject LOCALID_SCOTT
# 210 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
# 211 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 212 "data/maps/MauvilleCity/scripts.pory"
	return
# 213 "data/maps/MauvilleCity/scripts.pory"

# 214 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ScottExitNorth:: @ 81DF616
# 215 "data/maps/MauvilleCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
# 216 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
# 217 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 218 "data/maps/MauvilleCity/scripts.pory"
	return
# 219 "data/maps/MauvilleCity/scripts.pory"

# 220 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ScottExitEast:: @ 81DF628
# 221 "data/maps/MauvilleCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
# 222 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
# 223 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 224 "data/maps/MauvilleCity/scripts.pory"
	return
# 225 "data/maps/MauvilleCity/scripts.pory"

# 226 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_BattleWally:: @ 81DF63A
# 227 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
# 228 "data/maps/MauvilleCity/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
# 229 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
# 230 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 231 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
# 232 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
# 233 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 234 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
# 235 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestRight
# 236 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 237 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
# 238 "data/maps/MauvilleCity/scripts.pory"
	return
# 239 "data/maps/MauvilleCity/scripts.pory"

# 240 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_DeclineWallyBattle:: @ 81DF683
# 241 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
# 242 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
# 243 "data/maps/MauvilleCity/scripts.pory"
	release
# 244 "data/maps/MauvilleCity/scripts.pory"
	end
# 245 "data/maps/MauvilleCity/scripts.pory"

# 246 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_WallyRequestBattleAgain:: @ 81DF690
# 247 "data/maps/MauvilleCity/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
# 248 "data/maps/MauvilleCity/scripts.pory"
	waitmovement 0
# 249 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
# 250 "data/maps/MauvilleCity/scripts.pory"
	goto MauvilleCity_EventScript_BattleWallyPrompt
# 251 "data/maps/MauvilleCity/scripts.pory"
	end
# 252 "data/maps/MauvilleCity/scripts.pory"

# 253 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallyExitNorth1: @ 81DF6A8
# 254 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 255 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 256 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 257 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 258 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 259 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 260 "data/maps/MauvilleCity/scripts.pory"

# 261 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallyExitEast1: @ 81DF6AE
# 262 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 263 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 264 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 265 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 266 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 267 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 268 "data/maps/MauvilleCity/scripts.pory"

# 269 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallyExitNorth2: @ 81DF6B4
# 270 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 271 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 272 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 273 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 274 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 275 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 276 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 277 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 278 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 279 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 280 "data/maps/MauvilleCity/scripts.pory"
	delay_8
# 281 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 282 "data/maps/MauvilleCity/scripts.pory"

# 283 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallyExitEast2: @ 81DF6C0
# 284 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 285 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 286 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 287 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 288 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 289 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 290 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 291 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 292 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 293 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 294 "data/maps/MauvilleCity/scripts.pory"
	delay_8
# 295 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 296 "data/maps/MauvilleCity/scripts.pory"

# 297 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchWallyExitNorth2: @ 81DF6CC
# 298 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 299 "data/maps/MauvilleCity/scripts.pory"
	delay_8
# 300 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_left
# 301 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 302 "data/maps/MauvilleCity/scripts.pory"

# 303 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchWallyExitEast2: @ 81DF6D0
# 304 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 305 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 306 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 307 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_left
# 308 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 309 "data/maps/MauvilleCity/scripts.pory"

# 310 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchScottExitNorth: @ 81DF6D5
# 311 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 312 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_left
# 313 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 314 "data/maps/MauvilleCity/scripts.pory"

# 315 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchScottExitEast: @ 81DF6D8
# 316 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 317 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 318 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_left
# 319 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 320 "data/maps/MauvilleCity/scripts.pory"

# 321 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchWallyExitEast1: @ 81DF6DC
# 322 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 323 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_down
# 324 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 325 "data/maps/MauvilleCity/scripts.pory"

# 326 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerWatchWallyExitNorth1: @ 81DF6DF
# 327 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 328 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_left
# 329 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 330 "data/maps/MauvilleCity/scripts.pory"

# 331 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleExitNorth1: @ 81DF6E2
# 332 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 333 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 334 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 335 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 336 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 337 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 338 "data/maps/MauvilleCity/scripts.pory"

# 339 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleExitEast1: @ 81DF6E8
# 340 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 341 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 342 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 343 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 344 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 345 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 346 "data/maps/MauvilleCity/scripts.pory"

# 347 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_PlayerFaceUncleNorth: @ 81DF6EE
# 348 "data/maps/MauvilleCity/scripts.pory"
	delay_16
# 349 "data/maps/MauvilleCity/scripts.pory"
	delay_8
# 350 "data/maps/MauvilleCity/scripts.pory"
	delay_4
# 351 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_down
# 352 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 353 "data/maps/MauvilleCity/scripts.pory"

# 354 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleApproachPlayerNorth: @ 81DF6F3
# 355 "data/maps/MauvilleCity/scripts.pory"
	walk_right
# 356 "data/maps/MauvilleCity/scripts.pory"
	walk_right
# 357 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_up
# 358 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 359 "data/maps/MauvilleCity/scripts.pory"

# 360 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleApproachPlayerEast: @ 81DF6F7
# 361 "data/maps/MauvilleCity/scripts.pory"
	walk_right
# 362 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 363 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 364 "data/maps/MauvilleCity/scripts.pory"

# 365 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleExitNorth2: @ 81DF6FA
# 366 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 367 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 368 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 369 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 370 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 371 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 372 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 373 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 374 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 375 "data/maps/MauvilleCity/scripts.pory"

# 376 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_WallysUncleExitEast2: @ 81DF703
# 377 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 378 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 379 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 380 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 381 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 382 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 383 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 384 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 385 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 386 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 387 "data/maps/MauvilleCity/scripts.pory"

# 388 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_ScottApproachPlayerNorth: @ 81DF70D
# 389 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 390 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 391 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 392 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 393 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 394 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 395 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 396 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 397 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 398 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 399 "data/maps/MauvilleCity/scripts.pory"
	walk_in_place_fastest_up
# 400 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 401 "data/maps/MauvilleCity/scripts.pory"

# 402 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_ScottApproachPlayerEast: @ 81DF719
# 403 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 404 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 405 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 406 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 407 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 408 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 409 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 410 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 411 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 412 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 413 "data/maps/MauvilleCity/scripts.pory"
	walk_up
# 414 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 415 "data/maps/MauvilleCity/scripts.pory"

# 416 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_ScottExitNorth: @ 81DF725
# 417 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 418 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 419 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 420 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 421 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 422 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 423 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 424 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 425 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 426 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 427 "data/maps/MauvilleCity/scripts.pory"

# 428 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Movement_ScottExitEast: @ 81DF72F
# 429 "data/maps/MauvilleCity/scripts.pory"
	walk_down
# 430 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 431 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 432 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 433 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 434 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 435 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 436 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 437 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 438 "data/maps/MauvilleCity/scripts.pory"
	walk_left
# 439 "data/maps/MauvilleCity/scripts.pory"
	step_end
# 440 "data/maps/MauvilleCity/scripts.pory"

# 441 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_Wattson:: @ 81DF73A
# 442 "data/maps/MauvilleCity/scripts.pory"
	lock
# 443 "data/maps/MauvilleCity/scripts.pory"
	faceplayer
# 444 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_GOT_TM24_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
# 445 "data/maps/MauvilleCity/scripts.pory"
	compare VAR_NEW_MAUVILLE_STATE, 6
# 446 "data/maps/MauvilleCity/scripts.pory"
	goto_if_eq MauvilleCity_EventScript_CompletedNewMauville
# 447 "data/maps/MauvilleCity/scripts.pory"
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
# 448 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
# 449 "data/maps/MauvilleCity/scripts.pory"
	giveitem ITEM_BASEMENT_KEY
# 450 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
# 451 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
# 452 "data/maps/MauvilleCity/scripts.pory"
	release
# 453 "data/maps/MauvilleCity/scripts.pory"
	end
# 454 "data/maps/MauvilleCity/scripts.pory"

# 455 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_BegunNewMauville:: @ 81DF77A
# 456 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
# 457 "data/maps/MauvilleCity/scripts.pory"
	release
# 458 "data/maps/MauvilleCity/scripts.pory"
	end
# 459 "data/maps/MauvilleCity/scripts.pory"

# 460 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_CompletedNewMauville:: @ 81DF784
# 461 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
# 462 "data/maps/MauvilleCity/scripts.pory"
	givecustommon SPECIES_LANTURN, 55, ITEM_LANTURNITE, ITEM_POKE_BALL, NATURE_MODEST, 1, 252, 0, 0, 4, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_VOLT_SWITCH, MOVE_SPARKLING_ARIA, MOVE_BLIZZARD, MOVE_DAZZLING_GLEAM, FALSE
# 463 "data/maps/MauvilleCity/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 464 "data/maps/MauvilleCity/scripts.pory"
	message MauvilleCity_Text_Got_Lanturn
# 465 "data/maps/MauvilleCity/scripts.pory"
	waitfanfare
# 466 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_GOT_TM24_FROM_WATTSON
# 467 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
# 468 "data/maps/MauvilleCity/scripts.pory"
	release
# 469 "data/maps/MauvilleCity/scripts.pory"
	end
# 470 "data/maps/MauvilleCity/scripts.pory"

# 471 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_ReceivedThunderbolt:: @ 81DF7B0
# 472 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
# 473 "data/maps/MauvilleCity/scripts.pory"
	release
# 474 "data/maps/MauvilleCity/scripts.pory"
	end
# 475 "data/maps/MauvilleCity/scripts.pory"

# 476 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_EventScript_RegisterWallyCall:: @ 81DF7BA
# 477 "data/maps/MauvilleCity/scripts.pory"
	lockall
# 478 "data/maps/MauvilleCity/scripts.pory"
	pokenavcall MauvilleCity_Text_WallyPokenavCall
# 479 "data/maps/MauvilleCity/scripts.pory"
	waitmessage
# 480 "data/maps/MauvilleCity/scripts.pory"
	delay 30
# 481 "data/maps/MauvilleCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 482 "data/maps/MauvilleCity/scripts.pory"
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
# 483 "data/maps/MauvilleCity/scripts.pory"
	waitfanfare
# 484 "data/maps/MauvilleCity/scripts.pory"
	closemessage
# 485 "data/maps/MauvilleCity/scripts.pory"
	delay 30
# 486 "data/maps/MauvilleCity/scripts.pory"
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
# 487 "data/maps/MauvilleCity/scripts.pory"
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
# 488 "data/maps/MauvilleCity/scripts.pory"
	releaseall
# 489 "data/maps/MauvilleCity/scripts.pory"
	end
# 490 "data/maps/MauvilleCity/scripts.pory"

# 491 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleHesTooPeppy: @ 81DF7DC
# 492 "data/maps/MauvilleCity/scripts.pory"
	.string "Uncle: It's because of Pokémon that\n"
# 493 "data/maps/MauvilleCity/scripts.pory"
	.string "this boy's got more pep, I suppose…\l"
# 494 "data/maps/MauvilleCity/scripts.pory"
	.string "But he's become a bit too peppy…$"
# 495 "data/maps/MauvilleCity/scripts.pory"

# 496 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyWantToChallengeGym: @ 81DF845
# 497 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: Aww, Uncle, please?\p"
# 498 "data/maps/MauvilleCity/scripts.pory"
	.string "I want to challenge this Gym and see\n"
# 499 "data/maps/MauvilleCity/scripts.pory"
	.string "how much better I've become.\p"
# 500 "data/maps/MauvilleCity/scripts.pory"
	.string "Please? May I, please?$"
# 501 "data/maps/MauvilleCity/scripts.pory"

# 502 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleYourePushingIt: @ 81DF8B9
# 503 "data/maps/MauvilleCity/scripts.pory"
	.string "Uncle: Now hold on, Wally.\p"
# 504 "data/maps/MauvilleCity/scripts.pory"
	.string "Since you started living with Pokémon,\n"
# 505 "data/maps/MauvilleCity/scripts.pory"
	.string "you have grown quite a lot stronger.\p"
# 506 "data/maps/MauvilleCity/scripts.pory"
	.string "But don't you think you're pushing it\n"
# 507 "data/maps/MauvilleCity/scripts.pory"
	.string "to suddenly challenge a Gym?$"
# 508 "data/maps/MauvilleCity/scripts.pory"

# 509 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyWeCanBeatAnyone: @ 81DF963
# 510 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: I'm not pushing it.\p"
# 511 "data/maps/MauvilleCity/scripts.pory"
	.string "If I combine forces with Gardevoir,\n"
# 512 "data/maps/MauvilleCity/scripts.pory"
	.string "we can beat anyone!$"
# 513 "data/maps/MauvilleCity/scripts.pory"

# 514 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyWillYouBattleMe: @ 81DF9B2
# 515 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: Oh! Hi, {PLAYER}!\p"
# 516 "data/maps/MauvilleCity/scripts.pory"
	.string "I've gotten a lot stronger since\n"
# 517 "data/maps/MauvilleCity/scripts.pory"
	.string "we met.\p"
# 518 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}, I want you and my Uncle to\n"
# 519 "data/maps/MauvilleCity/scripts.pory"
	.string "understand that.\p"
# 520 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}, please, will you have\n"
# 521 "data/maps/MauvilleCity/scripts.pory"
	.string "a battle with me?$"
# 522 "data/maps/MauvilleCity/scripts.pory"

# 523 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyMyUncleWontKnowImStrong: @ 81DFA4A
# 524 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: Oh… If you won't battle me,\n"
# 525 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}, my Uncle won't know that I've\l"
# 526 "data/maps/MauvilleCity/scripts.pory"
	.string "become really strong.$"
# 527 "data/maps/MauvilleCity/scripts.pory"

# 528 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleCanYouBattleWally: @ 81DFAA5
# 529 "data/maps/MauvilleCity/scripts.pory"
	.string "Uncle: {PLAYER}{KUN}, was it?\n"
# 530 "data/maps/MauvilleCity/scripts.pory"
	.string "On Wally's behalf, can I ask you to\l"
# 531 "data/maps/MauvilleCity/scripts.pory"
	.string "battle with him just this once?\p"
# 532 "data/maps/MauvilleCity/scripts.pory"
	.string "I don't think he's going to listen to\n"
# 533 "data/maps/MauvilleCity/scripts.pory"
	.string "any reason the way he is now.$"
# 534 "data/maps/MauvilleCity/scripts.pory"

# 535 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyPleaseBattleMe: @ 81DFB42
# 536 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: {PLAYER}, please!\n"
# 537 "data/maps/MauvilleCity/scripts.pory"
	.string "Battle with me, please.$"
# 538 "data/maps/MauvilleCity/scripts.pory"

# 539 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyHereICome: @ 81DFB6D
# 540 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: {PLAYER}, thank you.\p"
# 541 "data/maps/MauvilleCity/scripts.pory"
	.string "Okay… Here I come!$"
# 542 "data/maps/MauvilleCity/scripts.pory"

# 543 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyDefeat: @ 81DFB96
# 544 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: … … … … … … …\p"
# 545 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … … … …\p"
# 546 "data/maps/MauvilleCity/scripts.pory"
	.string "I lost…$"
# 547 "data/maps/MauvilleCity/scripts.pory"

# 548 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyIllGoBackToVerdanturf: @ 81DFBC3
# 549 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: Uncle…\n"
# 550 "data/maps/MauvilleCity/scripts.pory"
	.string "I'll go back to Verdanturf…$"
# 551 "data/maps/MauvilleCity/scripts.pory"

# 552 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_ThankYouNotEnoughToBattle: @ 81DFBED
# 553 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}, thank you.\n"
# 554 "data/maps/MauvilleCity/scripts.pory"
	.string "Being a Trainer is tough, isn't it?\p"
# 555 "data/maps/MauvilleCity/scripts.pory"
	.string "It's not enough just to have Pokémon\n"
# 556 "data/maps/MauvilleCity/scripts.pory"
	.string "and make them battle. That isn't what\l"
# 557 "data/maps/MauvilleCity/scripts.pory"
	.string "being a real Trainer is about.$"
# 558 "data/maps/MauvilleCity/scripts.pory"

# 559 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleNoNeedToBeDown: @ 81DFC8A
# 560 "data/maps/MauvilleCity/scripts.pory"
	.string "Uncle: Wally, there's no need to be so\n"
# 561 "data/maps/MauvilleCity/scripts.pory"
	.string "down on yourself.\p"
# 562 "data/maps/MauvilleCity/scripts.pory"
	.string "Why, what's keeping you from becoming\n"
# 563 "data/maps/MauvilleCity/scripts.pory"
	.string "stronger and stronger?\p"
# 564 "data/maps/MauvilleCity/scripts.pory"
	.string "Come on, let's go home.\n"
# 565 "data/maps/MauvilleCity/scripts.pory"
	.string "Everyone's waiting for you.$"
# 566 "data/maps/MauvilleCity/scripts.pory"

# 567 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_UncleVisitUsSometime: @ 81DFD34
# 568 "data/maps/MauvilleCity/scripts.pory"
	.string "Uncle: {PLAYER}{KUN}, it just dawned on me\n"
# 569 "data/maps/MauvilleCity/scripts.pory"
	.string "that you must be the Trainer who kept\l"
# 570 "data/maps/MauvilleCity/scripts.pory"
	.string "an eye out for Wally when he caught\l"
# 571 "data/maps/MauvilleCity/scripts.pory"
	.string "his Pokémon.\p"
# 572 "data/maps/MauvilleCity/scripts.pory"
	.string "Why don't you visit us in Verdanturf\n"
# 573 "data/maps/MauvilleCity/scripts.pory"
	.string "sometime?\l"
# 574 "data/maps/MauvilleCity/scripts.pory"
	.string "I'm sure Wally would enjoy it.$"
# 575 "data/maps/MauvilleCity/scripts.pory"

# 576 "data/maps/MauvilleCity/scripts.pory"

# 577 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WallyPokenavCall: @ 81DFDFB
# 578 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … …\n"
# 579 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … Beep!\p"
# 580 "data/maps/MauvilleCity/scripts.pory"
	.string "Wally: Oh, hello, {PLAYER}!\p"
# 581 "data/maps/MauvilleCity/scripts.pory"
	.string "I just wanted to tell you that\n"
# 582 "data/maps/MauvilleCity/scripts.pory"
	.string "my uncle bought me a PokéNav!\p"
# 583 "data/maps/MauvilleCity/scripts.pory"
	.string "Now I can get in touch with you\n"
# 584 "data/maps/MauvilleCity/scripts.pory"
	.string "anytime, {PLAYER}!\p"
# 585 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … …\n"
# 586 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … Click!$"
# 587 "data/maps/MauvilleCity/scripts.pory"

# 588 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_RegisteredWally: @ 81DFEB4
# 589 "data/maps/MauvilleCity/scripts.pory"
	.string "Registered Wally\n"
# 590 "data/maps/MauvilleCity/scripts.pory"
	.string "in the PokéNav.$"
# 591 "data/maps/MauvilleCity/scripts.pory"

# 592 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_ScottYouDidntHoldBack: @ 81DFED5
# 593 "data/maps/MauvilleCity/scripts.pory"
	.string "Scott: Hehe…\n"
# 594 "data/maps/MauvilleCity/scripts.pory"
	.string "I was watching that match!\p"
# 595 "data/maps/MauvilleCity/scripts.pory"
	.string "You're friends with that boy Wally,\n"
# 596 "data/maps/MauvilleCity/scripts.pory"
	.string "aren't you?\p"
# 597 "data/maps/MauvilleCity/scripts.pory"
	.string "But you didn't hold anything back\n"
# 598 "data/maps/MauvilleCity/scripts.pory"
	.string "and beat him impressively.\p"
# 599 "data/maps/MauvilleCity/scripts.pory"
	.string "Yeah! That's what a real Pokémon\n"
# 600 "data/maps/MauvilleCity/scripts.pory"
	.string "battle is all about!\p"
# 601 "data/maps/MauvilleCity/scripts.pory"
	.string "I idolize Trainers like that!\p"
# 602 "data/maps/MauvilleCity/scripts.pory"
	.string "… … … … … …\n"
# 603 "data/maps/MauvilleCity/scripts.pory"
	.string "I'll be cheering for you!$"
# 604 "data/maps/MauvilleCity/scripts.pory"

# 605 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WattsonNeedFavorTakeKey: @ 81DFFE4
# 606 "data/maps/MauvilleCity/scripts.pory"
	.string "Wattson: Oh, {PLAYER}{KUN}!\n"
# 607 "data/maps/MauvilleCity/scripts.pory"
	.string "You look like you have a lot of zip!\l"
# 608 "data/maps/MauvilleCity/scripts.pory"
	.string "That's a good thing, wahahahaha!\p"
# 609 "data/maps/MauvilleCity/scripts.pory"
	.string "Fine! I've decided!\n"
# 610 "data/maps/MauvilleCity/scripts.pory"
	.string "I need a favor, {PLAYER}{KUN}!\p"
# 611 "data/maps/MauvilleCity/scripts.pory"
	.string "Mauville City has an underground\n"
# 612 "data/maps/MauvilleCity/scripts.pory"
	.string "sector called New Mauville.\p"
# 613 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
# 614 "data/maps/MauvilleCity/scripts.pory"
	.string "switch off the Generator.\p"
# 615 "data/maps/MauvilleCity/scripts.pory"
	.string "The Generator has been running a bit\n"
# 616 "data/maps/MauvilleCity/scripts.pory"
	.string "haywire. It's getting unsafe.\p"
# 617 "data/maps/MauvilleCity/scripts.pory"
	.string "Here, this is the Key to get into\n"
# 618 "data/maps/MauvilleCity/scripts.pory"
	.string "New Mauville.$"
# 619 "data/maps/MauvilleCity/scripts.pory"

# 620 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WattsonWontBeChallenge: @ 81E0154
# 621 "data/maps/MauvilleCity/scripts.pory"
	.string "Wattson: Don't you worry about it.\n"
# 622 "data/maps/MauvilleCity/scripts.pory"
	.string "It won't be a challenge to you.\p"
# 623 "data/maps/MauvilleCity/scripts.pory"
	.string "The entrance to New Mauville is just\n"
# 624 "data/maps/MauvilleCity/scripts.pory"
	.string "a short Surf away from Route 110.\p"
# 625 "data/maps/MauvilleCity/scripts.pory"
	.string "That's it, then, you have my trust!\n"
# 626 "data/maps/MauvilleCity/scripts.pory"
	.string "Wahahahaha!$"
# 627 "data/maps/MauvilleCity/scripts.pory"

# 628 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WattsonThanksTakeTM: @ 81E020E
# 629 "data/maps/MauvilleCity/scripts.pory"
	.string "Wattson: Wahahahaha!\p"
# 630 "data/maps/MauvilleCity/scripts.pory"
	.string "I knew it, {PLAYER}{KUN}! I knew I'd made\n"
# 631 "data/maps/MauvilleCity/scripts.pory"
	.string "the right choice asking you!\p"
# 632 "data/maps/MauvilleCity/scripts.pory"
	.string "This is my thanks - you can\n"
# 633 "data/maps/MauvilleCity/scripts.pory"
	.string "have this.\p"
# 634 "data/maps/MauvilleCity/scripts.pory"
	.string "Go on, you've earned it!$"
# 635 "data/maps/MauvilleCity/scripts.pory"

# 636 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_WattsonYoungTakeCharge: @ 81E02AA
# 637 "data/maps/MauvilleCity/scripts.pory"
	.string "Wattson: Wahahahaha!\p"
# 638 "data/maps/MauvilleCity/scripts.pory"
	.string "It pleases me to no end to see\n"
# 639 "data/maps/MauvilleCity/scripts.pory"
	.string "the young step up and take charge!$"
# 640 "data/maps/MauvilleCity/scripts.pory"

# 641 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_NurseHurtMonBackToHealth: @ 81E0301
# 642 "data/maps/MauvilleCity/scripts.pory"
	.string "You know, it's cool to have Pokémon\n"
# 643 "data/maps/MauvilleCity/scripts.pory"
	.string "battles and stuff…\p"
# 644 "data/maps/MauvilleCity/scripts.pory"
	.string "But if your Pokémon gets hurt,\n"
# 645 "data/maps/MauvilleCity/scripts.pory"
	.string "you have to nurse it back to health.$"
# 646 "data/maps/MauvilleCity/scripts.pory"

# 647 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_AllSortsOfPeopleComeThrough: @ 81E037C
# 648 "data/maps/MauvilleCity/scripts.pory"
	.string "The roads of this town stretch north\n"
# 649 "data/maps/MauvilleCity/scripts.pory"
	.string "and south, and east and west.\p"
# 650 "data/maps/MauvilleCity/scripts.pory"
	.string "Because of that, we get all sorts of\n"
# 651 "data/maps/MauvilleCity/scripts.pory"
	.string "people coming through.$"
# 652 "data/maps/MauvilleCity/scripts.pory"

# 653 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_RydelVeryGenerous: @ 81E03FB
# 654 "data/maps/MauvilleCity/scripts.pory"
	.string "Have you been to Rydel's Cycles yet?\p"
# 655 "data/maps/MauvilleCity/scripts.pory"
	.string "Rydel, the owner, is a very generous\n"
# 656 "data/maps/MauvilleCity/scripts.pory"
	.string "man.$"
# 657 "data/maps/MauvilleCity/scripts.pory"

# 658 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_PokemonCanJumpYouOnBike: @ 81E044A
# 659 "data/maps/MauvilleCity/scripts.pory"
	.string "Even if you're riding a Bike,\n"
# 660 "data/maps/MauvilleCity/scripts.pory"
	.string "wild Pokémon could jump you.$"
# 661 "data/maps/MauvilleCity/scripts.pory"

# 662 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_CitySign: @ 81E0485
# 663 "data/maps/MauvilleCity/scripts.pory"
	.string "Mauville City\n"
# 664 "data/maps/MauvilleCity/scripts.pory"
	.string "“The bright and shiny city of fun!”$"
# 665 "data/maps/MauvilleCity/scripts.pory"

# 666 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_GymSign: @ 81E04B7
# 667 "data/maps/MauvilleCity/scripts.pory"
	.string "Mauville City Pokémon Gym\n"
# 668 "data/maps/MauvilleCity/scripts.pory"
	.string "Leader: Wattson\l"
# 669 "data/maps/MauvilleCity/scripts.pory"
	.string "“The cheerfully electrifying man!”$"
# 670 "data/maps/MauvilleCity/scripts.pory"

# 671 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_BikeShopSign: @ 81E0504
# 672 "data/maps/MauvilleCity/scripts.pory"
	.string "“Ride in gravel and shake up your\n"
# 673 "data/maps/MauvilleCity/scripts.pory"
	.string "soul!”\l"
# 674 "data/maps/MauvilleCity/scripts.pory"
	.string "Rydel's Cycles$"
# 675 "data/maps/MauvilleCity/scripts.pory"

# 676 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_GameCornerSign: @ 81E053C
# 677 "data/maps/MauvilleCity/scripts.pory"
	.string "“The play spot for all!”\n"
# 678 "data/maps/MauvilleCity/scripts.pory"
	.string "Mauville Game Corner$"
# 679 "data/maps/MauvilleCity/scripts.pory"

# 680 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_MoveTutorSign:
# 681 "data/maps/MauvilleCity/scripts.pory"
	.string "Mauville Move Tutor\n"
# 682 "data/maps/MauvilleCity/scripts.pory"
	.string "“Special moves for Starter Pokémon!”$"
# 683 "data/maps/MauvilleCity/scripts.pory"

# 684 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_ExplainTV: @ 81E056A
# 685 "data/maps/MauvilleCity/scripts.pory"
	.string "Hi, do you check out TV at all?\p"
# 686 "data/maps/MauvilleCity/scripts.pory"
	.string "They've added a bunch of cool new\n"
# 687 "data/maps/MauvilleCity/scripts.pory"
	.string "shows recently.\p"
# 688 "data/maps/MauvilleCity/scripts.pory"
	.string "TV is so cool. I've seen my friends on\n"
# 689 "data/maps/MauvilleCity/scripts.pory"
	.string "TV just out of the blue.\p"
# 690 "data/maps/MauvilleCity/scripts.pory"
	.string "And, sometimes, they even put you on TV\n"
# 691 "data/maps/MauvilleCity/scripts.pory"
	.string "without telling you.\p"
# 692 "data/maps/MauvilleCity/scripts.pory"
	.string "I wish I would be on TV sometime.\p"
# 693 "data/maps/MauvilleCity/scripts.pory"
	.string "That's why I think you should check\n"
# 694 "data/maps/MauvilleCity/scripts.pory"
	.string "out TVs whenever you can.$"
# 695 "data/maps/MauvilleCity/scripts.pory"

# 696 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_BeenCheckingOutTV: @ 81E0699
# 697 "data/maps/MauvilleCity/scripts.pory"
	.string "Hi, have you been checking out TVs?$"
# 698 "data/maps/MauvilleCity/scripts.pory"

# 699 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_GiveTM74:
# 700 "data/maps/MauvilleCity/scripts.pory"
	.string "Did you know that you can go from\n"
# 701 "data/maps/MauvilleCity/scripts.pory"
	.string "here a long way in that direction\l"
# 702 "data/maps/MauvilleCity/scripts.pory"
	.string "without changing direction?\p"
# 703 "data/maps/MauvilleCity/scripts.pory"
	.string "I might even be able to roll\n"
# 704 "data/maps/MauvilleCity/scripts.pory"
	.string "that way.\p"
# 705 "data/maps/MauvilleCity/scripts.pory"
	.string "Do you think your Pokémon will\n"
# 706 "data/maps/MauvilleCity/scripts.pory"
	.string "want to roll, too?\p"
# 707 "data/maps/MauvilleCity/scripts.pory"
	.string "Here, let them try out this TM\n"
# 708 "data/maps/MauvilleCity/scripts.pory"
	.string "if you'd like.$"
# 709 "data/maps/MauvilleCity/scripts.pory"

# 710 "data/maps/MauvilleCity/scripts.pory"
MauvilleCity_Text_HaveTM74:
# 711 "data/maps/MauvilleCity/scripts.pory"
	.string "My slow mons love Gyro Ball, an attack\n"
# 712 "data/maps/MauvilleCity/scripts.pory"
	.string "that does more damage the slower the\l"
# 713 "data/maps/MauvilleCity/scripts.pory"
	.string "user is compared to the foe.$"

MauvilleCity_Text_Got_Lanturn::
# 715 "data/maps/MauvilleCity/scripts.pory"
	.string "{PLAYER} got Wattson's {COLOR BLUE}Lanturn{COLOR DARK_GRAY} as a\n"
	.string "gift!$"
