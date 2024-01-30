# 1 "data/maps/PetalburgCity_Gym/scripts.pory"

# 2 "data/maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_NORMAN, 1
# 3 "data/maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_WALLY, 10
# 4 "data/maps/PetalburgCity_Gym/scripts.pory"
.set LOCALID_WALLYS_DAD, 11
# 5 "data/maps/PetalburgCity_Gym/scripts.pory"

# 6 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_MapScripts:: @ 8204889
# 7 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
# 8 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
# 9 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
# 10 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
# 11 "data/maps/PetalburgCity_Gym/scripts.pory"
	.byte 0
# 12 "data/maps/PetalburgCity_Gym/scripts.pory"

# 13 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnLoad: @ 820489E
# 14 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 6
# 15 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_OpenUnlockedDoors
# 16 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 7
# 17 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_ge PetalburgCity_Gym_EventScript_UnlockAllDoors
# 18 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 19 "data/maps/PetalburgCity_Gym/scripts.pory"

# 20 "data/maps/PetalburgCity_Gym/scripts.pory"
@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
# 21 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenUnlockedDoors:: @ 82048B5
# 22 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 23 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 24 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 25 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 26 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 27 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 28 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 29 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 30 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 31 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 32 "data/maps/PetalburgCity_Gym/scripts.pory"

# 33 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockAllDoors:: @ 82048FF
# 34 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 1
# 35 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
# 36 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 37 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 38 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 39 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 40 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 41 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 42 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 43 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 44 "data/maps/PetalburgCity_Gym/scripts.pory"

# 45 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnTransition: @ 820492D
# 46 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 1
# 47 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_MoveWallyToEntrance
# 48 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 6
# 49 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_lt PetalburgCity_Gym_EventScript_MoveNormanToEntrance
# 50 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
# 51 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 52 "data/maps/PetalburgCity_Gym/scripts.pory"

# 53 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveWallyToEntrance:: @ 820494D
# 54 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_WALLY, 5, 108
# 55 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 56 "data/maps/PetalburgCity_Gym/scripts.pory"

# 57 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MoveNormanToEntrance:: @ 8204955
# 58 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_NORMAN, 4, 107
# 59 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 60 "data/maps/PetalburgCity_Gym/scripts.pory"

# 61 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_CheckNormanForRematch:: @ 820495D
# 62 "data/maps/PetalburgCity_Gym/scripts.pory"
	//goto_if_unset FLAG_DAILY_REMATCH_NORMAN, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
# 63 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 8
# 64 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontMoveNormanToFront @ If var = 8 set var = 8? Why
# 65 "data/maps/PetalburgCity_Gym/scripts.pory"
	setobjectxyperm LOCALID_NORMAN, 4, 107
# 66 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 67 "data/maps/PetalburgCity_Gym/scripts.pory"

# 68 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontMoveNormanToFront:: @ 8204985
# 69 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 8
# 70 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 71 "data/maps/PetalburgCity_Gym/scripts.pory"

# 72 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnWarp: @ 820498B
# 73 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
# 74 "data/maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 75 "data/maps/PetalburgCity_Gym/scripts.pory"

# 76 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_TurnPlayerNorth:: @ 8204995
# 77 "data/maps/PetalburgCity_Gym/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 78 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 79 "data/maps/PetalburgCity_Gym/scripts.pory"

# 80 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_OnFrame: @ 820499A
# 81 "data/maps/PetalburgCity_Gym/scripts.pory"
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
# 82 "data/maps/PetalburgCity_Gym/scripts.pory"
	.2byte 0
# 83 "data/maps/PetalburgCity_Gym/scripts.pory"

# 84 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial:: @ 82049A4
# 85 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 86 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
# 87 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
# 88 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 89 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 90 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
# 91 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 92 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_EXIT
# 93 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLY
# 94 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 95 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 96 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 97 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 98 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
# 99 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 2
# 100 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 101 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 102 "data/maps/PetalburgCity_Gym/scripts.pory"

# 103 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitGym: @ 82049EC
# 104 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 105 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 106 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 107 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 108 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 109 "data/maps/PetalburgCity_Gym/scripts.pory"

# 110 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth:: @ 8204A80
# 111 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 0
# 112 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 113 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 114 "data/maps/PetalburgCity_Gym/scripts.pory"

# 115 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth:: @ 8204A8B
# 116 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 117 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 118 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 119 "data/maps/PetalburgCity_Gym/scripts.pory"

# 120 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialWest:: @ 8204A96
# 121 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 122 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 123 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 124 "data/maps/PetalburgCity_Gym/scripts.pory"

# 125 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorialEast:: @ 8204AA1
# 126 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 127 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
# 128 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 129 "data/maps/PetalburgCity_Gym/scripts.pory"

# 130 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BeginWallyTutorial:: @ 8204AAC
# 131 "data/maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_WALLY
# 132 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 133 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 0
# 134 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveSouth
# 135 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 136 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveNorth
# 137 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 138 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 139 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 140 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallyArriveWestEast
# 141 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
# 142 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
# 143 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
# 144 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
# 145 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 0
# 146 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
# 147 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 148 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
# 149 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 150 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
# 151 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 152 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
# 153 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
# 154 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 0
# 155 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallySouth
# 156 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 157 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
# 158 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 159 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyWest
# 160 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 161 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanAddressWallyEast
# 162 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
# 163 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
# 164 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
# 165 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 0
# 166 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
# 167 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 168 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
# 169 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 170 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorWest
# 171 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 172 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_NormanFaceDoorEast
# 173 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 0
# 174 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
# 175 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 176 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallyFaceDown
# 177 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 178 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
# 179 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 180 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallyFacePlayer
# 181 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
# 182 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 183 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 184 "data/maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 185 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 0
# 186 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
# 187 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 188 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
# 189 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 190 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
# 191 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 192 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
# 193 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLY
# 194 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
# 195 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 1
# 196 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 2
# 197 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
# 198 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
# 199 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 200 "data/maps/PetalburgCity_Gym/scripts.pory"
	special InitBirchState
# 201 "data/maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 255, 15, 8
# 202 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 203 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 204 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 205 "data/maps/PetalburgCity_Gym/scripts.pory"

# 206 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveSouth:: @ 8204C31
# 207 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 208 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 209 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 210 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 211 "data/maps/PetalburgCity_Gym/scripts.pory"

# 212 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveNorth:: @ 8204C43
# 213 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
# 214 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 215 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestRight
# 216 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 217 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 218 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 219 "data/maps/PetalburgCity_Gym/scripts.pory"

# 220 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyArriveWestEast:: @ 8204C5F
# 221 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 222 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 223 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyArrive
# 224 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 225 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 226 "data/maps/PetalburgCity_Gym/scripts.pory"

# 227 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallySouth:: @ 8204C78
# 228 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 229 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 230 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
# 231 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 232 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 233 "data/maps/PetalburgCity_Gym/scripts.pory"

# 234 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth:: @ 8204C91
# 235 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
# 236 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
# 237 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 238 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 239 "data/maps/PetalburgCity_Gym/scripts.pory"

# 240 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyWest:: @ 8204CA3
# 241 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
# 242 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
# 243 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 244 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 245 "data/maps/PetalburgCity_Gym/scripts.pory"

# 246 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallyEast:: @ 8204CB5
# 247 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
# 248 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
# 249 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 250 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 251 "data/maps/PetalburgCity_Gym/scripts.pory"

# 252 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth:: @ 8204CC7
# 253 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestUp
# 254 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 255 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 256 "data/maps/PetalburgCity_Gym/scripts.pory"

# 257 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth:: @ 8204CD2
# 258 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 259 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 260 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 261 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 262 "data/maps/PetalburgCity_Gym/scripts.pory"

# 263 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerWest:: @ 8204CE4
# 264 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestRight
# 265 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 266 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 267 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 268 "data/maps/PetalburgCity_Gym/scripts.pory"

# 269 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressPlayerEast:: @ 8204CF6
# 270 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestLeft
# 271 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 272 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 273 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 274 "data/maps/PetalburgCity_Gym/scripts.pory"

# 275 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallySouth:: @ 8204D08
# 276 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 277 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 278 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 279 "data/maps/PetalburgCity_Gym/scripts.pory"

# 280 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyNorth:: @ 8204D13
# 281 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestRight
# 282 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 283 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 284 "data/maps/PetalburgCity_Gym/scripts.pory"

# 285 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyWest:: @ 8204D1E
# 286 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 287 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 288 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 289 "data/maps/PetalburgCity_Gym/scripts.pory"

# 290 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanAddressWallyEast:: @ 8204D29
# 291 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 292 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 293 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 294 "data/maps/PetalburgCity_Gym/scripts.pory"

# 295 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFacePlayer:: @ 8204D34
# 296 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
# 297 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 298 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 299 "data/maps/PetalburgCity_Gym/scripts.pory"

# 300 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallyFaceDown:: @ 8204D3F
# 301 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestDown
# 302 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 303 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 304 "data/maps/PetalburgCity_Gym/scripts.pory"

# 305 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorSouth:: @ 8204D72
# 306 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 307 "data/maps/PetalburgCity_Gym/scripts.pory"

# 308 "data/maps/PetalburgCity_Gym/scripts.pory"
@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
# 309 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth:: @ 8204D73
# 310 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 311 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 312 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 313 "data/maps/PetalburgCity_Gym/scripts.pory"

# 314 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorWest:: @ 8204D7E
# 315 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 316 "data/maps/PetalburgCity_Gym/scripts.pory"

# 317 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanFaceDoorEast:: @ 8204D7F
# 318 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 319 "data/maps/PetalburgCity_Gym/scripts.pory"

# 320 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveFacade2:: @ 8204DAC
# 321 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_Kangaskhan
# 322 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 323 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 324 "data/maps/PetalburgCity_Gym/scripts.pory"

# 325 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetSingles::
# 326 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanAllowLegends, MSGBOX_YESNO
# 327 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 328 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_NormanSinglesRematch
# 329 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_4, PetalburgCity_Gym_Text_NormanRematchDefeat
# 330 "data/maps/PetalburgCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_NORMAN
# 331 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 332 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 333 "data/maps/PetalburgCity_Gym/scripts.pory"

# 334 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetDoubles::
# 335 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanAllowLegends, MSGBOX_YESNO
# 336 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 337 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_NormanDoublesRematch
# 338 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_5, PetalburgCity_Gym_Text_NormanRematchDefeat
# 339 "data/maps/PetalburgCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_NORMAN
# 340 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 341 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 342 "data/maps/PetalburgCity_Gym/scripts.pory"

# 343 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanSinglesRematch::
# 344 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_2, PetalburgCity_Gym_Text_NormanRematchDefeat
# 345 "data/maps/PetalburgCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_NORMAN
# 346 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 347 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 348 "data/maps/PetalburgCity_Gym/scripts.pory"

# 349 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanDoublesRematch::
# 350 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_3, PetalburgCity_Gym_Text_NormanRematchDefeat
# 351 "data/maps/PetalburgCity_Gym/scripts.pory"
	//setflag FLAG_DAILY_REMATCH_NORMAN
# 352 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 353 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 354 "data/maps/PetalburgCity_Gym/scripts.pory"

# 355 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AlreadyRematched::
# 356 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
# 357 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 358 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 359 "data/maps/PetalburgCity_Gym/scripts.pory"

# 360 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Exit::
# 361 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 362 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 363 "data/maps/PetalburgCity_Gym/scripts.pory"

# 364 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry:: @ 8204DCE
# 365 "data/maps/PetalburgCity_Gym/scripts.pory"
	specialvar VAR_RESULT, IsEnigmaBerryValid
# 366 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, FALSE
# 367 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 368 "data/maps/PetalburgCity_Gym/scripts.pory"
	checkitem ITEM_ENIGMA_BERRY, 1
# 369 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, TRUE
# 370 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 371 "data/maps/PetalburgCity_Gym/scripts.pory"
	checkpcitem ITEM_ENIGMA_BERRY, 1
# 372 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, TRUE
# 373 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 374 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_ENIGMA_BERRY_AVAILABLE, 0
# 375 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
# 376 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
# 377 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, TRUE
# 378 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 379 "data/maps/PetalburgCity_Gym/scripts.pory"

# 380 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry:: @ 8204E17
# 381 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_RESULT, FALSE
# 382 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 383 "data/maps/PetalburgCity_Gym/scripts.pory"

# 384 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GiveEnigmaBerry:: @ 8204E1D
# 385 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_ENIGMA_BERRY
# 386 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, FALSE
# 387 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 388 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
# 389 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 390 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 391 "data/maps/PetalburgCity_Gym/scripts.pory"
	
# 392 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_NormanBattle::
# 393 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanBattleIntro, MSGBOX_DEFAULT
# 394 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
# 395 "data/maps/PetalburgCity_Gym/scripts.pory"
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
# 396 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmessage
# 397 "data/maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 398 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
# 399 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 400 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 401 "data/maps/PetalburgCity_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 402 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RegisteredExploud, MSGBOX_DEFAULT
# 403 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitfanfare
# 404 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 405 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 406 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 407 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_GYM_STATE, 7
# 408 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_BADGE05_GET
# 409 "data/maps/PetalburgCity_Gym/scripts.pory"
	special ResetHealLocationFromDewford
# 410 "data/maps/PetalburgCity_Gym/scripts.pory"
	call EventScript_HideMrBriney
# 411 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
# 412 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
# 413 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 5
# 414 "data/maps/PetalburgCity_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 415 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
# 416 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
# 417 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 418 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_Kangaskhan
# 419 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 420 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
# 421 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 422 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 40
# 423 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_DOOR
# 424 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 425 "data/maps/PetalburgCity_Gym/scripts.pory"
	addobject LOCALID_WALLYS_DAD
# 426 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 427 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
# 428 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
# 429 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
# 430 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 431 "data/maps/PetalburgCity_Gym/scripts.pory"

# 432 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesNorth:: @ 8204EF5
# 433 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 434 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 435 "data/maps/PetalburgCity_Gym/scripts.pory"

# 436 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesEast:: @ 8204EFF
# 437 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 438 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 439 "data/maps/PetalburgCity_Gym/scripts.pory"

# 440 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrivesWest:: @ 8204F09
# 441 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 3
# 442 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_WallysDadArrives
# 443 "data/maps/PetalburgCity_Gym/scripts.pory"

# 444 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadArrives:: @ 8204F13
# 445 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
# 446 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 447 "data/maps/PetalburgCity_Gym/scripts.pory"
	playse SE_PIN
# 448 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_ExclamationMark
# 449 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 450 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_Delay48
# 451 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 452 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 10
# 453 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 454 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
# 455 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 456 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
# 457 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 458 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
# 459 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 460 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 461 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 20
# 462 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 463 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
# 464 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 465 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
# 466 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 467 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
# 468 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
# 469 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 470 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 471 "data/maps/PetalburgCity_Gym/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 472 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 1
# 473 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
# 474 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 2
# 475 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
# 476 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8008, 3
# 477 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
# 478 "data/maps/PetalburgCity_Gym/scripts.pory"
	removeobject LOCALID_WALLYS_DAD
# 479 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_PETALBURG_CITY_STATE, 4
# 480 "data/maps/PetalburgCity_Gym/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
# 481 "data/maps/PetalburgCity_Gym/scripts.pory"
	warp MAP_PETALBURG_CITY, 255, 15, 8
# 482 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 483 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 484 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 485 "data/maps/PetalburgCity_Gym/scripts.pory"

# 486 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth:: @ 8204FCC
# 487 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFastestUp
# 488 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 489 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 490 "data/maps/PetalburgCity_Gym/scripts.pory"

# 491 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast:: @ 8204FD7
# 492 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFastestRight
# 493 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 494 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 495 "data/maps/PetalburgCity_Gym/scripts.pory"

# 496 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest:: @ 8204FE2
# 497 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, Common_Movement_WalkInPlaceFastestLeft
# 498 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 499 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 500 "data/maps/PetalburgCity_Gym/scripts.pory"

# 501 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth:: @ 8204FED
# 502 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
# 503 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 504 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 505 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestLeft
# 506 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 507 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 508 "data/maps/PetalburgCity_Gym/scripts.pory"

# 509 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast:: @ 8205009
# 510 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
# 511 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 512 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 513 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 514 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 515 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 516 "data/maps/PetalburgCity_Gym/scripts.pory"

# 517 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest:: @ 8205025
# 518 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
# 519 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 520 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 521 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 522 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 523 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 524 "data/maps/PetalburgCity_Gym/scripts.pory"

# 525 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth:: @ 8205041
# 526 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
# 527 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_NORMAN, Common_Movement_WalkInPlaceFastestDown
# 528 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
# 529 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 530 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 531 "data/maps/PetalburgCity_Gym/scripts.pory"

# 532 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast:: @ 820505A
# 533 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
# 534 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
# 535 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 536 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 537 "data/maps/PetalburgCity_Gym/scripts.pory"

# 538 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest:: @ 820506C
# 539 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
# 540 "data/maps/PetalburgCity_Gym/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
# 541 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmovement 0
# 542 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 543 "data/maps/PetalburgCity_Gym/scripts.pory"

# 544 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitNorth: @ 820507E
# 545 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 546 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 547 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 548 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 549 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 550 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 551 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_up
# 552 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 553 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 554 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 555 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 556 "data/maps/PetalburgCity_Gym/scripts.pory"

# 557 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitEast: @ 8205089
# 558 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 559 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 560 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 561 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 562 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 564 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_up
# 565 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 566 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 567 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 568 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 569 "data/maps/PetalburgCity_Gym/scripts.pory"

# 570 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadExitWest: @ 8205094
# 571 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 572 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 573 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 574 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 575 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 576 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 577 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 578 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 579 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_up
# 580 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 581 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 582 "data/maps/PetalburgCity_Gym/scripts.pory"
	set_invisible
# 583 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 584 "data/maps/PetalburgCity_Gym/scripts.pory"

# 585 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth: @ 82050A1
# 586 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 587 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 588 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 589 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 590 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 591 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 592 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 593 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 594 "data/maps/PetalburgCity_Gym/scripts.pory"

# 595 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast: @ 82050A9
# 596 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 597 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 598 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 599 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 600 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 601 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 602 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 603 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 604 "data/maps/PetalburgCity_Gym/scripts.pory"

# 605 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest: @ 82050B1
# 606 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 607 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 608 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 609 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 610 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 611 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 612 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_left
# 613 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 614 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 615 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 616 "data/maps/PetalburgCity_Gym/scripts.pory"

# 617 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadEnterGym: @ 82050BB
# 618 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 619 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 620 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_right
# 621 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 622 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_left
# 623 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 624 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_up
# 625 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 626 "data/maps/PetalburgCity_Gym/scripts.pory"

# 627 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth: @ 82050C3
# 628 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 629 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 630 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 631 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 632 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 633 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_right
# 634 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 635 "data/maps/PetalburgCity_Gym/scripts.pory"

# 636 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast: @ 82050CA
# 637 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 638 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 639 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 640 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 641 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 642 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 643 "data/maps/PetalburgCity_Gym/scripts.pory"

# 644 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest: @ 82050D0
# 645 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 646 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 647 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 648 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 649 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 650 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 651 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 652 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 653 "data/maps/PetalburgCity_Gym/scripts.pory"

# 654 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_Unused: @ 82050D8
# 655 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_up
# 656 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 657 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 658 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 659 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 660 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 661 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 662 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_down
# 663 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 664 "data/maps/PetalburgCity_Gym/scripts.pory"

# 665 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArriveNorth: @ 82050E1
# 666 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 667 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 668 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 669 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 670 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 671 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 672 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 673 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 674 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_left
# 675 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 676 "data/maps/PetalburgCity_Gym/scripts.pory"

# 677 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyArrive: @ 82050EB
# 678 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 679 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 680 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 681 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 682 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 683 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_up
# 684 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 685 "data/maps/PetalburgCity_Gym/scripts.pory"

# 686 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitNorth: @ 82050F2
# 687 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 688 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 689 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 690 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 691 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_up
# 692 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 693 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 694 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 695 "data/maps/PetalburgCity_Gym/scripts.pory"

# 696 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitEast: @ 82050FA
# 697 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 698 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 699 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 700 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 701 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_up
# 702 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 703 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 704 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 705 "data/maps/PetalburgCity_Gym/scripts.pory"

# 706 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_WallyExitSouthWest: @ 8205102
# 707 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 708 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 709 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 710 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_up
# 711 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 712 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_down
# 713 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 714 "data/maps/PetalburgCity_Gym/scripts.pory"

# 715 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth: @ 8205109
# 716 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 717 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 718 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 719 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 720 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 721 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 722 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 723 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 724 "data/maps/PetalburgCity_Gym/scripts.pory"

# 725 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallySouth: @ 8205111
# 726 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 727 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 728 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 729 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 730 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 731 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 732 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 733 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 734 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 735 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 736 "data/maps/PetalburgCity_Gym/scripts.pory"

# 737 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyWest: @ 820511B
# 738 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 739 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 740 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 741 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 742 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 743 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 744 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 745 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 746 "data/maps/PetalburgCity_Gym/scripts.pory"

# 747 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Movement_PlayerExitWithWallyEast: @ 8205123
# 748 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_in_place_fastest_down
# 749 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 750 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_16
# 751 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 752 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 753 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 754 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_right
# 755 "data/maps/PetalburgCity_Gym/scripts.pory"
	walk_down
# 756 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay_8
# 757 "data/maps/PetalburgCity_Gym/scripts.pory"
	step_end
# 758 "data/maps/PetalburgCity_Gym/scripts.pory"

# 759 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SpeedRoomDoor:: @ 8205137
# 760 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 761 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 6
# 762 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
# 763 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 764 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 85
# 765 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
# 766 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 767 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 768 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 769 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 770 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 771 "data/maps/PetalburgCity_Gym/scripts.pory"

# 772 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_EnterRoom:: @ 820516C
# 773 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 774 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 775 "data/maps/PetalburgCity_Gym/scripts.pory"
	warpdoor MAP_PETALBURG_CITY_GYM, 255, VAR_0x8008, VAR_0x8009
# 776 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 777 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 778 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 779 "data/maps/PetalburgCity_Gym/scripts.pory"

# 780 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DontEnterRoom:: @ 820517B
# 781 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 782 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 783 "data/maps/PetalburgCity_Gym/scripts.pory"

# 784 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_DoorLocked:: @ 820517D
# 785 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
# 786 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 787 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 788 "data/maps/PetalburgCity_Gym/scripts.pory"

# 789 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
# 790 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AccuracyRoomDoor:: @ 8205187
# 791 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 792 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_PETALBURG_GYM_STATE, 6
# 793 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_lt PetalburgCity_Gym_EventScript_DoorLocked
# 794 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 795 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 98
# 796 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
# 797 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 798 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 799 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 800 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 801 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 802 "data/maps/PetalburgCity_Gym/scripts.pory"

# 803 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ConfusionRoomDoor:: @ 82051BC
# 804 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 805 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 806 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 807 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 46
# 808 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
# 809 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 810 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 811 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 812 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 813 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 814 "data/maps/PetalburgCity_Gym/scripts.pory"

# 815 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor:: @ 82051EF
# 816 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 817 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
# 818 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 819 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 820 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 821 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 822 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 823 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 824 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 825 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 826 "data/maps/PetalburgCity_Gym/scripts.pory"

# 827 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightDefenseRoomDoor:: @ 8205222
# 828 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 829 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 830 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 831 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 59
# 832 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
# 833 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 834 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 835 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 836 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 837 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 838 "data/maps/PetalburgCity_Gym/scripts.pory"

# 839 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RecoveryRoomDoor:: @ 8205255
# 840 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 841 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
# 842 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 843 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 72
# 844 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
# 845 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 846 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 847 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 848 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 849 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 850 "data/maps/PetalburgCity_Gym/scripts.pory"

# 851 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor:: @ 8205288
# 852 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 853 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
# 854 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 855 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 856 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 857 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 858 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 859 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 860 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 861 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 862 "data/maps/PetalburgCity_Gym/scripts.pory"

# 863 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightStrengthRoomDoor:: @ 82052BB
# 864 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 865 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 866 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 867 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 20
# 868 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
# 869 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 870 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 871 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 872 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 873 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 874 "data/maps/PetalburgCity_Gym/scripts.pory"

# 875 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftOHKORoomDoor:: @ 82052EE
# 876 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 877 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
# 878 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 879 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 880 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 881 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 882 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 883 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 884 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 885 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 886 "data/maps/PetalburgCity_Gym/scripts.pory"

# 887 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightOHKORoomDoor:: @ 8205321
# 888 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 889 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
# 890 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 891 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 33
# 892 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
# 893 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 894 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 895 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 896 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 897 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 898 "data/maps/PetalburgCity_Gym/scripts.pory"

# 899 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor:: @ 8205354
# 900 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 901 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
# 902 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 1
# 903 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 904 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 905 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 906 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 907 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 908 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 909 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 910 "data/maps/PetalburgCity_Gym/scripts.pory"

# 911 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor:: @ 8205387
# 912 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 913 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
# 914 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8008, 7
# 915 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8009, 7
# 916 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
# 917 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, YES
# 918 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_EnterRoom
# 919 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_RESULT, NO
# 920 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_eq PetalburgCity_Gym_EventScript_DontEnterRoom
# 921 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 922 "data/maps/PetalburgCity_Gym/scripts.pory"

# 923 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Randall:: @ 82053BA
# 924 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
# 925 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
# 926 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
# 927 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 928 "data/maps/PetalburgCity_Gym/scripts.pory"

# 929 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors:: @ 82053DE
# 930 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 931 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
# 932 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 933 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 934 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 935 "data/maps/PetalburgCity_Gym/scripts.pory"

# 936 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RandallPostBadge:: @ 82053ED
# 937 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
# 938 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 939 "data/maps/PetalburgCity_Gym/scripts.pory"

# 940 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Parker:: @ 82053F6
# 941 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
# 942 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
# 943 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
# 944 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 945 "data/maps/PetalburgCity_Gym/scripts.pory"

# 946 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors:: @ 820541A
# 947 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 948 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
# 949 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 950 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 951 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 952 "data/maps/PetalburgCity_Gym/scripts.pory"

# 953 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_ParkerPostBadge:: @ 8205429
# 954 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
# 955 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 956 "data/maps/PetalburgCity_Gym/scripts.pory"

# 957 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_George:: @ 8205432
# 958 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
# 959 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
# 960 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
# 961 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 962 "data/maps/PetalburgCity_Gym/scripts.pory"

# 963 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors:: @ 8205456
# 964 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 965 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
# 966 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 967 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 968 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 969 "data/maps/PetalburgCity_Gym/scripts.pory"

# 970 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GeorgePostBadge:: @ 8205465
# 971 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
# 972 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 973 "data/maps/PetalburgCity_Gym/scripts.pory"

# 974 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Berke:: @ 820546E
# 975 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
# 976 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
# 977 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
# 978 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 979 "data/maps/PetalburgCity_Gym/scripts.pory"

# 980 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors:: @ 8205492
# 981 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 982 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
# 983 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 984 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 985 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 986 "data/maps/PetalburgCity_Gym/scripts.pory"

# 987 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_BerkePostBadge:: @ 82054A1
# 988 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
# 989 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 990 "data/maps/PetalburgCity_Gym/scripts.pory"

# 991 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Mary:: @ 82054AA
# 992 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
# 993 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
# 994 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
# 995 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 996 "data/maps/PetalburgCity_Gym/scripts.pory"

# 997 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors:: @ 82054CE
# 998 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 999 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
# 1000 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 1001 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1002 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1003 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1004 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_MaryPostBadge:: @ 82054DD
# 1005 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
# 1006 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1007 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1008 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Alexia:: @ 82054E6
# 1009 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
# 1010 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
# 1011 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
# 1012 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1013 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1014 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors:: @ 820550A
# 1015 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 1016 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
# 1017 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 1018 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1019 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1020 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1021 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_AlexiaPostBadge:: @ 8205519
# 1022 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
# 1023 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1024 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1025 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_Jody:: @ 8205522
# 1026 "data/maps/PetalburgCity_Gym/scripts.pory"
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
# 1027 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
# 1028 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
# 1029 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1030 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1031 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors:: @ 8205546
# 1032 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8005, 0
# 1033 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
# 1034 "data/maps/PetalburgCity_Gym/scripts.pory"
	special DrawWholeMapView
# 1035 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1036 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1037 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1038 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_JodyPostBadge:: @ 8205555
# 1039 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
# 1040 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1041 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1042 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8004 below is the room number
# 1043 "data/maps/PetalburgCity_Gym/scripts.pory"
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
# 1044 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors:: @ 820555E
# 1045 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 1
# 1046 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 0
# 1047 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1048 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 1
# 1049 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1050 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
# 1051 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1052 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1053 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors:: @ 820557F
# 1054 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 2
# 1055 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 0
# 1056 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1057 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 1
# 1058 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1059 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
# 1060 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1061 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1062 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors:: @ 82055A0
# 1063 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 3
# 1064 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 0
# 1065 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1066 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 1
# 1067 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1068 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
# 1069 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1070 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1071 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors:: @ 82055C1
# 1072 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 4
# 1073 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 0
# 1074 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1075 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 1
# 1076 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1077 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
# 1078 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1079 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1080 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors:: @ 82055E2
# 1081 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 5
# 1082 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 0
# 1083 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1084 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 1
# 1085 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1086 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
# 1087 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1088 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1089 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors:: @ 8205603
# 1090 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 6
# 1091 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 0
# 1092 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1093 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 1
# 1094 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1095 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
# 1096 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1097 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1098 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors:: @ 8205624
# 1099 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 7
# 1100 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 0
# 1101 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1102 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 1
# 1103 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1104 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
# 1105 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1106 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1107 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_OpenOHKORoomDoors:: @ 8205645
# 1108 "data/maps/PetalburgCity_Gym/scripts.pory"
	setvar VAR_0x8004, 8
# 1109 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 0
# 1110 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
# 1111 "data/maps/PetalburgCity_Gym/scripts.pory"
	compare VAR_0x8005, 1
# 1112 "data/maps/PetalburgCity_Gym/scripts.pory"
	call_if_eq PetalburgCity_Gym_EventScript_UnlockRoomDoors
# 1113 "data/maps/PetalburgCity_Gym/scripts.pory"
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
# 1114 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1115 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1116 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles:: @ 8205666
# 1117 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1118 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1119 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1120 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1121 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1122 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1123 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles:: @ 820568B
# 1124 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1125 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1126 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1127 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1128 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1129 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1130 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles:: @ 82056B0
# 1131 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1132 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1133 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1134 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1135 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1136 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1137 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles:: @ 82056D5
# 1138 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1139 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1140 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1141 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1142 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles:: @ 82056E8
# 1143 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1144 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1145 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1146 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1147 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1148 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1149 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles:: @ 820570D
# 1150 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1151 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1152 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1153 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1154 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles:: @ 8205720
# 1155 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1156 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1157 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1158 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1159 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles:: @ 8205733
# 1160 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, 0
# 1161 "data/maps/PetalburgCity_Gym/scripts.pory"
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, 0
# 1162 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1163 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1164 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_SlideOpenRoomDoors:: @ 8205746
# 1165 "data/maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymSlideOpenRoomDoors
# 1166 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitstate
# 1167 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1168 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1169 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_UnlockRoomDoors:: @ 820574B
# 1170 "data/maps/PetalburgCity_Gym/scripts.pory"
	special PetalburgGymUnlockRoomDoors
# 1171 "data/maps/PetalburgCity_Gym/scripts.pory"
	return
# 1172 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1173 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuide:: @ 820574F
# 1174 "data/maps/PetalburgCity_Gym/scripts.pory"
	lock
# 1175 "data/maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 1176 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
# 1177 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice1, MSGBOX_DEFAULT
# 1178 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice2, MSGBOX_DEFAULT
# 1179 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1180 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1181 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1182 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuide2::
# 1183 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice2, MSGBOX_DEFAULT
# 1184 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1185 "data/maps/PetalburgCity_Gym/scripts.pory"
	end	
# 1186 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1187 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymGuidePostVictory:: @ 8205764
# 1188 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 1189 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1190 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1191 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1192 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_LeftGymStatue:: @ 820576E
# 1193 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1194 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1195 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1196 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1197 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1198 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_RightGymStatue:: @ 820577E
# 1199 "data/maps/PetalburgCity_Gym/scripts.pory"
	lockall
# 1200 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
# 1201 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_GymStatue
# 1202 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1203 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1204 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatueCertified:: @ 820578E
# 1205 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 1206 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1207 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1208 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1209 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_EventScript_GymStatue:: @ 8205798
# 1210 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 1211 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
# 1212 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
# 1213 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1214 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon: @ 82057A2
# 1215 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Hm?\p"
# 1216 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, if it isn't {PLAYER}!\n"
# 1217 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "So you're all finished moving in?\p"
# 1218 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm surprised that you managed to\n"
# 1219 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "get here by yourself.\p"
# 1220 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Oh, I see.\n"
# 1221 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're with your Pokémon.\p"
# 1222 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hm… Then I guess you're going to\n"
# 1223 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "become a Trainer like me, {PLAYER}.\p"
# 1224 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That's great news!\n"
# 1225 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll be looking forward to it!$"
# 1226 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1227 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIdLikeAPokemon: @ 82058B1
# 1228 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Um… I…\n"
# 1229 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'd like to get a Pokémon, please…$"
# 1230 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1231 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadOhYoureWallyRight: @ 82058DB
# 1232 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Hm? You're… Uh… Oh, right.\n"
# 1233 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're Wally, right?$"
# 1234 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1235 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon: @ 8205910
# 1236 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Wally: I'm going to go stay with my\n"
# 1237 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "relatives in Verdanturf Town.\p"
# 1238 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I thought I would be lonely by myself,\n"
# 1239 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "so I wanted to take a Pokémon along.\p"
# 1240 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But I've never caught a Pokémon before.\n"
# 1241 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I don't know how…$"
# 1242 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1243 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHmISee: @ 82059D8
# 1244 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Hm. I see.$"
# 1245 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1246 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadPlayerGoWithWally: @ 82059E8
# 1247 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: {PLAYER}, you heard that,\n"
# 1248 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right?\p"
# 1249 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go with Wally and make sure that he\n"
# 1250 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "safely catches a Pokémon.$"
# 1251 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1252 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon: @ 8205A46
# 1253 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Wally, here, I'll loan you my Pokémon.\p"
# 1254 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Wally received a Zigzagoon!$"
# 1255 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1256 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall: @ 8205A89
# 1257 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Wally: Oh, wow!\n"
# 1258 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "A Pokémon!\p"
# 1259 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Hm. I'll give you a Poké Ball, too.\n"
# 1260 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go for it!\p"
# 1261 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Wally received a Poké Ball!$"
# 1262 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1263 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyOhWowThankYou: @ 8205AF4
# 1264 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Wally: Oh, wow!\n"
# 1265 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Thank you!$"
# 1266 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1267 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WouldYouReallyComeWithMe: @ 8205B0F
# 1268 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}… Would you really come\n"
# 1269 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with me?$"
# 1270 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1271 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadSoDidItWorkOut: @ 8205B32
# 1272 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: So, did it work out?$"
# 1273 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1274 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_WallyThankYouBye: @ 8205B4C
# 1275 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Wally: Thank you, yes, it did.\n"
# 1276 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Here's your Pokémon back.\p"
# 1277 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, thank you for coming along\n"
# 1278 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with me.\p"
# 1279 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You two are why I was able to catch\n"
# 1280 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "my Pokémon.\p"
# 1281 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I promise I'll take really good\n"
# 1282 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "care of it.\p"
# 1283 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Oh! My mom's waiting for me,\n"
# 1284 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "so I have to go!\p"
# 1285 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Bye, {PLAYER}!$"
# 1286 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1287 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoCollectBadges: @ 8205C40
# 1288 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Now…\p"
# 1289 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, if you want to become a\n"
# 1290 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "strong Trainer, here's my advice.\p"
# 1291 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Head for Rustboro City beyond this\n"
# 1292 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "town.\p"
# 1293 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There, you should challenge\n"
# 1294 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the Gym Leader, Roxanne.\p"
# 1295 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "After her, go on to other Pokémon\n"
# 1296 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Gyms and defeat their Leaders.\p"
# 1297 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Collect Badges from them,\n"
# 1298 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "understood?\p"
# 1299 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Of course, I'm a Gym Leader, too.\n"
# 1300 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "We'll battle one day, {PLAYER}.\p"
# 1301 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But that's only after you become\n"
# 1302 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.$"
# 1303 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1304 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToRustboro: @ 8205DB4
# 1305 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Hm? Aren't you going to the\n"
# 1306 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Pokémon Gym in Rustboro City?\p"
# 1307 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There's no challenge for me to\n"
# 1308 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "battle a greenhorn Trainer.\p"
# 1309 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, I want you to challenge me\n"
# 1310 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "when you become a lot stronger.\p"
# 1311 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll battle you, {PLAYER}, when you\n"
# 1312 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "can show me four Gym Badges, okay?$"
# 1313 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1314 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanGoToDewford: @ 8205EAE
# 1315 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: I see… So, you've beaten\n"
# 1316 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the Gym Leader in Rustboro City.\p"
# 1317 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But there are many more Trainers\n"
# 1318 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "who are stronger than you, {PLAYER}.\p"
# 1319 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Across the sea in Dewford Town is a\n"
# 1320 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Gym Leader named Brawly.\p"
# 1321 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You should go challenge him.$"
# 1322 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1323 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_YouHaveGottenStronger: @ 8205F87
# 1324 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Hm… {PLAYER}, you have gotten\n"
# 1325 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1326 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I can tell by the number of Badges\n"
# 1327 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "that you've earned.$"
# 1328 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1329 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanIntro: @ 8205FE5
# 1330 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Hm…\n"
# 1331 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "So, you did get four Gym Badges.\p"
# 1332 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Fine, as I promised, we will have\n"
# 1333 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a Pokémon battle.\p"
# 1334 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But first, let me give you this.$"
# 1335 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1336 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanMegaBracelet:
# 1337 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That Mega Bracelet will allow certain\n"
# 1338 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Pokémon to Mega Evolve in battle.\p"
# 1339 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It's no good on its own, though.\p"
# 1340 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "To Mega Evolve a Pokémon, you must\n"
# 1341 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "also let it hold its Mega Stone.\p"
# 1342 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Then, press START before choosing a\n"
# 1343 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "move.\p"
# 1344 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Mega Evolution is a very powerful\n"
# 1345 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "technique, but I think you and your\l"
# 1346 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Pokémon are ready for it.\p"
# 1347 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "If you can, give it a try in our\n"
# 1348 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "battle!\p"
# 1349 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Here, take these Mega Stones too.$"
# 1350 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1351 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanBattleIntro:
# 1352 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}…\p"
# 1353 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm so happy that I can have\n"
# 1354 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a real battle with my own child.\p"
# 1355 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But, a battle is a battle!\p"
# 1356 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I will do everything in my power as\n"
# 1357 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a Gym Leader to win.\p"
# 1358 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}, you'd better give it your\n"
# 1359 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "best shot, too!$"
# 1360 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1361 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanDefeat: @ 8206107
# 1362 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "…\p"
# 1363 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I… I can't…\p"
# 1364 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I can't believe it. {PLAYER}…\p"
# 1365 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost to {PLAYER}?\p"
# 1366 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But, rules are rules!\n"
# 1367 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Here, take this.$"
# 1368 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1369 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ReceivedBalanceBadge: @ 8206162
# 1370 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER} received the Balance Badge\n"
# 1371 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "from Dad!$"
# 1372 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1373 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis: @ 820618A
# 1374 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: With that Badge, Pokémon that\n"
# 1375 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "know the HM move Surf will be able\l"
# 1376 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "to travel over water.\p"
# 1377 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "If you like, you can borrow my Exploud\n"
# 1378 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "to Surf if you don't want to teach the\l"
# 1379 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "move to any of your own Pokémon.\p"
# 1380 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "… … … … … …$"
# 1381 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1382 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RegisteredExploud: @ 81FF517
# 1383 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Registered Dad's Exploud\n"
# 1384 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "in the PokéNav.$"
# 1385 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1386 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_TakeThis:
# 1387 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is my gift to you. {PLAYER}, I'm\n"
# 1388 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "sure you can use it correctly.$"
# 1389 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1390 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ExplainFacade: @ 8206254
# 1391 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: TM42 contains Facade.\p"
# 1392 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It doubles in power if the Pokémon\n"
# 1393 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "is poisoned, paralyzed, or burned.\p"
# 1394 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It might be able to turn a bad\n"
# 1395 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "situation into an advantage.$"
# 1396 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1397 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadHappyAndSad: @ 82062FB
# 1398 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: As the Gym Leader, I can't\n"
# 1399 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "express how upset I am…\p"
# 1400 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But as a father, it makes me both\n"
# 1401 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "happy and a little sad. It's odd…$"
# 1402 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1403 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_PleaseComeWithMe: @ 8206377
# 1404 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
# 1405 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Please come with me.\n"
# 1406 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I have something I want you to have.$"
# 1407 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1408 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_LetMeBorrowPlayer: @ 82063CA
# 1409 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Norman, you don't mind, do you?\p"
# 1410 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
# 1411 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a minute or two.$"
# 1412 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1413 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadGoingToKeepTraining: @ 8206417
# 1414 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: {PLAYER}, you should go visit\n"
# 1415 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "your mother every so often.\p"
# 1416 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to stay here and redouble\n"
# 1417 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "my training.\p"
# 1418 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It would bother me as a Trainer to\n"
# 1419 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "not avenge my loss to you, {PLAYER}!$"
# 1420 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1421 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough: @ 82064C3
# 1422 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: {PLAYER}, how are things going?\p"
# 1423 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The world of Pokémon is deep.\p"
# 1424 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I honestly think that no amount of\n"
# 1425 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training would ever be enough.$"
# 1426 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1427 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuideAdvice1: @ 8206542
# 1428 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hey, how's it going, Champion-\n"
# 1429 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "bound {PLAYER}?$"
# 1430 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1431 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuideAdvice2:
# 1432 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The doors in this Gym open when you\n"
# 1433 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "beat the awaiting Trainers.\p"
# 1434 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Whoops! The doors in this room are\n"
# 1435 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "already open, so don't attack me!\p"
# 1436 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the left leads to\n"
# 1437 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the Speed Room.\p"
# 1438 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The door at the right leads to\n"
# 1439 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the Accuracy Room.\p"
# 1440 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The room's name will be on\n"
# 1441 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the door, so choose carefully.\p"
# 1442 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Once you've chosen the door…\n"
# 1443 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Well, hey, go for it!\p"
# 1444 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Oh, and your Dad's got something\n"
# 1445 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "special for you once you reach him!$"
# 1446 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1447 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymGuidePostVictory: @ 82066F3
# 1448 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}! Whoa! You've overcome even\n"
# 1449 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "your own father!\p"
# 1450 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Like, whoa!\n"
# 1451 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What a stunning turn of events!$"
# 1452 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1453 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallIntro: @ 820674F
# 1454 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The ability to attack before the\n"
# 1455 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "opponent…\p"
# 1456 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Just that alone puts me at a great\n"
# 1457 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "advantage, don't you agree?$"
# 1458 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1459 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallDefeat: @ 82067B9
# 1460 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That was a magnificent battle!$"
# 1461 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1462 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBattle: @ 82067D8
# 1463 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on to the next room where a new\n"
# 1464 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "challenge awaits you.\p"
# 1465 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "At the left is the Confusion Room.\p"
# 1466 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door leads to the Defense\n"
# 1467 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Room.$"
# 1468 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1469 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_RandallPostBadge: @ 820685E
# 1470 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Whomever you beat, and whomever you\n"
# 1471 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "may lose to, you never shirk from\l"
# 1472 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training yourself and your Pokémon.\p"
# 1473 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "That's what I think being a\n"
# 1474 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Gym Leader is all about.$"
# 1475 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1476 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerIntro: @ 82068FD
# 1477 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the Confusion Room.\p"
# 1478 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Let me see how well bonded you are\n"
# 1479 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with your Pokémon!$"
# 1480 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1481 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerDefeat: @ 820694F
# 1482 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't confuse your team enough…\n"
# 1483 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You share a strong bond together.$"
# 1484 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1485 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBattle: @ 8206996
# 1486 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The next room is the Strength Room.\n"
# 1487 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you withstand brute force?$"
# 1488 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1489 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_ParkerPostBadge: @ 82069D9
# 1490 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "After you beat our Leader, the\n"
# 1491 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "training has become a lot tougher.$"
# 1492 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1493 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeIntro: @ 8206A1B
# 1494 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Just when you think you're going to\n"
# 1495 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "win, your opponent restores HP…\p"
# 1496 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Can you just imagine how awful that\n"
# 1497 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "must feel?\p"
# 1498 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you exactly how awful it\n"
# 1499 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "feels!$"
# 1500 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1501 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgeDefeat: @ 8206AB8
# 1502 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I couldn't restore HP enough…\n"
# 1503 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What Attack power…$"
# 1504 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1505 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBattle: @ 8206AE9
# 1506 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I should have expected no less from\n"
# 1507 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "our Leader's kid.\p"
# 1508 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "No, wait! A Trainer's abilities are\n"
# 1509 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "earned only through effort.\p"
# 1510 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I lost because my own efforts\n"
# 1511 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "weren't enough.\p"
# 1512 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on! The One-Hit KO Room is next.$"
# 1513 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1514 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GeorgePostBadge: @ 8206BB1
# 1515 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm going to keep training at Gyms.\n"
# 1516 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "One day, I'll become a Leader.$"
# 1517 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1518 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeIntro: @ 8206BF4
# 1519 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'm not going to take it easy just\n"
# 1520 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "because you're our Leader's kid.\p"
# 1521 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll show you how horrid it is for\n"
# 1522 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a Pokémon to take a critical hit!$"
# 1523 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1524 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkeDefeat: @ 8206C7D
# 1525 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your power…\n"
# 1526 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You're the real deal.$"
# 1527 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1528 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBattle: @ 8206C9F
# 1529 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your father really is strong.\n"
# 1530 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "He's a Trainer worth my respect.\p"
# 1531 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "And, I sense the same glow coming\n"
# 1532 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "from you as your father.\p"
# 1533 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I hope that you'll stage a terrific\n"
# 1534 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "battle with your father!$"
# 1535 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1536 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_BerkePostBadge: @ 8206D56
# 1537 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Since your dad became the Leader,\n"
# 1538 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the Trainers of Petalburg City have\l"
# 1539 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "become a lot tougher.$"
# 1540 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1541 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryIntro: @ 8206DB2
# 1542 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Giggle…\n"
# 1543 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is the Accuracy Room.\p"
# 1544 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It's pretty nasty when every attack\n"
# 1545 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "lands without fail.$"
# 1546 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1547 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryDefeat: @ 8206E0D
# 1548 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You were a cut above me…$"
# 1549 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1550 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBattle: @ 8206E26
# 1551 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "There are some even stronger\n"
# 1552 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Trainers waiting for you.\p"
# 1553 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The left is the Defense Room, and\n"
# 1554 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the right is the Recovery Room.\p"
# 1555 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Your Pokémon's Attack power will be\n"
# 1556 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "on trial either way.$"
# 1557 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1558 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_MaryPostBadge: @ 8206ED8
# 1559 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you know what we're trying to\n"
# 1560 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "achieve as Trainers?\p"
# 1561 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "We're striving to become soul mates\n"
# 1562 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with our Pokémon.$"
# 1563 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1564 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaIntro: @ 8206F44
# 1565 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The higher the Defense, the more\n"
# 1566 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "reckless I can be in attack.$"
# 1567 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1568 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaDefeat: @ 8206F82
# 1569 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Our defenses weren't enough…$"
# 1570 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1571 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBattle: @ 8206F9F
# 1572 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I think you've taught me a valuable\n"
# 1573 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "lesson here.\p"
# 1574 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Now, go on! The left door goes to\n"
# 1575 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the Strength Room.\p"
# 1576 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The right door opens to\n"
# 1577 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "the One-Hit KO Room.\p"
# 1578 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Both of them have Trainers who are\n"
# 1579 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "skilled at offense.$"
# 1580 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1581 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_AlexiaPostBadge: @ 8207069
# 1582 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hi! Have you tried using Surf?$"
# 1583 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1584 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyIntro: @ 8207088
# 1585 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Our Gym Leader told us to go all out\n"
# 1586 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "and beat you.\p"
# 1587 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Even if you happen to be the\n"
# 1588 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Leader's kid!$"
# 1589 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1590 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyDefeat: @ 82070E6
# 1591 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But… I went all out!$"
# 1592 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1593 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBattle: @ 82070FB
# 1594 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "The way you use your Pokémon…\n"
# 1595 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It's like your father's style.\p"
# 1596 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Go on through! The Gym Leader, your\n"
# 1597 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "father, is waiting!$"
# 1598 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1599 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_JodyPostBadge: @ 8207170
# 1600 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Sure, it's fine to make your Pokémon\n"
# 1601 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "stronger.\p"
# 1602 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "But what decides the winner?\p"
# 1603 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Why, it's the feelings Trainers have\n"
# 1604 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "for their Pokémon.$"
# 1605 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1606 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked: @ 82071F4
# 1607 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1608 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1609 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1610 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterSpeedRoom: @ 820721E
# 1611 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“Speed Room,” the sign says.\p"
# 1612 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1613 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1614 "data/maps/PetalburgCity_Gym/scripts.pory"
@ Unused
# 1615 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_DoorAppearsLocked2: @ 8207256
# 1616 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This door appears to be locked\n"
# 1617 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "right now…$"
# 1618 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1619 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterAccuracyRoom: @ 8207280
# 1620 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“Accuracy Room,” the sign says.\p"
# 1621 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1622 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1623 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterConfusionRoom: @ 82072BB
# 1624 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“Confusion Room,” the sign says.\p"
# 1625 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1626 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1627 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterDefenseRoom: @ 82072F7
# 1628 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“Defense Room,” the sign says.\p"
# 1629 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1630 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1631 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterRecoveryRoom: @ 8207331
# 1632 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“Recovery Room,” the sign says.\p"
# 1633 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1634 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1635 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterStrengthRoom: @ 820736C
# 1636 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“Strength Room,” the sign says.\p"
# 1637 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1638 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1639 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterOHKORoom: @ 82073A7
# 1640 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“One-Hit Ko Room,” the sign says.\p"
# 1641 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1642 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1643 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_EnterGymLeadersRoom: @ 82073E4
# 1644 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“Gym Leader's Room.”\p"
# 1645 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "“Prepare to get spanked by your\n"
# 1646 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "dad!” the sign says.\p"
# 1647 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you want to go through?$"
# 1648 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1649 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatue: @ 820744C
# 1650 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Petalburg City Pokémon Gym$"
# 1651 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1652 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_GymStatueCertified: @ 8207467
# 1653 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Petalburg City Pokémon Gym\p"
# 1654 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Norman's Certified Trainers:\n"
# 1655 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER}$"
# 1656 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1657 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPreRematch: @ 82074A2
# 1658 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Because we are parent and child,\n"
# 1659 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we owe it to each other to do the best\l"
# 1660 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we can. Isn't that right, {PLAYER}?$"
# 1661 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1662 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchDefeat: @ 82075CE
# 1663 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Uh… Haha…\n"
# 1664 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Maybe that was going too hard…$"
# 1665 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1666 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanPostRematch: @ 82075F7
# 1667 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: {PLAYER}…\n"
# 1668 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "What is your dream?\p"
# 1669 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "My dream…\n"
# 1670 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Hahaha…\l"
# 1671 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "It has already come true, actually.$"
# 1672 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1673 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanRematchNeedTwoMons: @ 820764A
# 1674 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Hm? Wait a second, {PLAYER}.\p"
# 1675 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Do you only have one Pokémon that is\n"
# 1676 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "capable of battle?\p"
# 1677 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Sorry, but you'll have to come back\n"
# 1678 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "with at least two Pokémon.$"
# 1679 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1680 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanChooseFormat:
# 1681 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: {PLAYER}…\n"
# 1682 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I had a feeling that you would come.\p"
# 1683 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I would never refuse to accept\n"
# 1684 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "a challenge from you.\p"
# 1685 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "You do understand, don't you?\p"
# 1686 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Inside a Gym, it doesn't matter that\n"
# 1687 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "we are a parent and child.\p"
# 1688 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "I'll let you set the rules for our\n"
# 1689 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "rematch.\p"
# 1690 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "So what'll it be: a single battle,\n"
# 1691 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "or a double battle?$"
# 1692 "data/maps/PetalburgCity_Gym/scripts.pory"

# 1693 "data/maps/PetalburgCity_Gym/scripts.pory"
PetalburgCity_Gym_Text_NormanAllowLegends:
# 1694 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Do you want to try battling my\n"
# 1695 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Legendary Pokémon?$"

PetalburgCity_Gym_EventScript_Kangaskhan::
# 1699 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Kangaskhan_Text_0
# 1700 "data/maps/PetalburgCity_Gym/scripts.pory"
	givecustommon SPECIES_KANGASKHAN, 45, ITEM_FLAME_ORB, ITEM_CHERISH_BALL, NATURE_JOLLY, 2, 0, 252, 4, 252, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_DRAIN_PUNCH, MOVE_FACADE, MOVE_COMET_PUNCH, FALSE
# 1701 "data/maps/PetalburgCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1702 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Kangaskhan_Text_1
# 1703 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitfanfare
# 1704 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM42
	return


PetalburgCity_Gym_EventScript_CheckTrainers::
# 1711 "data/maps/PetalburgCity_Gym/scripts.pory"
	checktrainerflag TRAINER_RANDALL
	goto_if 0, PetalburgCity_Gym_EventScript_CheckTrainers_3
# 1712 "data/maps/PetalburgCity_Gym/scripts.pory"
	checktrainerflag TRAINER_PARKER
	goto_if 0, PetalburgCity_Gym_EventScript_CheckTrainers_3
# 1713 "data/maps/PetalburgCity_Gym/scripts.pory"
	checktrainerflag TRAINER_GEORGE
	goto_if 0, PetalburgCity_Gym_EventScript_CheckTrainers_3
# 1714 "data/maps/PetalburgCity_Gym/scripts.pory"
	checktrainerflag TRAINER_BERKE
	goto_if 0, PetalburgCity_Gym_EventScript_CheckTrainers_3
# 1715 "data/maps/PetalburgCity_Gym/scripts.pory"
	checktrainerflag TRAINER_MARY
	goto_if 0, PetalburgCity_Gym_EventScript_CheckTrainers_3
# 1716 "data/maps/PetalburgCity_Gym/scripts.pory"
	checktrainerflag TRAINER_ALEXIA
	goto_if 0, PetalburgCity_Gym_EventScript_CheckTrainers_3
# 1717 "data/maps/PetalburgCity_Gym/scripts.pory"
	checktrainerflag TRAINER_JODY
	goto_if 0, PetalburgCity_Gym_EventScript_CheckTrainers_3
PetalburgCity_Gym_EventScript_CheckTrainers_2:
	return

PetalburgCity_Gym_EventScript_CheckTrainers_1:
# 1719 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_CheckTrainers_Text_0, MSGBOX_NPC
# 1720 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
	end

PetalburgCity_Gym_EventScript_CheckTrainers_3:
# 1718 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_CheckTrainers_1
	goto PetalburgCity_Gym_EventScript_CheckTrainers_2


PetalburgCity_Gym_EventScript_Norman::
# 1730 "data/maps/PetalburgCity_Gym/scripts.pory"
	lock
# 1731 "data/maps/PetalburgCity_Gym/scripts.pory"
	faceplayer
# 1732 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_PETALBURG_GYM_STATE
# 1733 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 0, PetalburgCity_Gym_EventScript_Norman_2
# 1737 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 1, PetalburgCity_Gym_EventScript_Norman_3
# 1743 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_Norman_4
# 1748 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_Norman_5
# 1753 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_Norman_6
# 1758 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 5, PetalburgCity_Gym_EventScript_Norman_7
# 1763 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 6, PetalburgCity_Gym_EventScript_Norman_8
# 1783 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 7, PetalburgCity_Gym_EventScript_Norman_9
# 1784 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 8, PetalburgCity_Gym_EventScript_Norman_9
	return

PetalburgCity_Gym_EventScript_Norman_2:
# 1735 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_Norman_WallyTutorial
	return

PetalburgCity_Gym_EventScript_Norman_3:
# 1739 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Text_0, MSGBOX_DEFAULT
# 1740 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1741 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
	return

PetalburgCity_Gym_EventScript_Norman_4:
# 1744 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
# 1745 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1746 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
	return

PetalburgCity_Gym_EventScript_Norman_5:
# 1749 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
# 1750 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1751 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
	return

PetalburgCity_Gym_EventScript_Norman_6:
# 1754 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 1755 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1756 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
	return

PetalburgCity_Gym_EventScript_Norman_7:
# 1759 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
# 1760 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
# 1761 "data/maps/PetalburgCity_Gym/scripts.pory"
	end
	return

PetalburgCity_Gym_EventScript_Norman_8:
# 1764 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_RECEIVED_KEYSTONE, PetalburgCity_Gym_EventScript_Norman_11
# 1768 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
# 1769 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_MEGA_BRACELET
# 1770 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_SYS_RECEIVED_KEYSTONE
# 1771 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanMegaBracelet, MSGBOX_DEFAULT
# 1772 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveBattleItems
# 1773 "data/maps/PetalburgCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1774 "data/maps/PetalburgCity_Gym/scripts.pory"
	message PetalburgCity_Gym_EventScript_Norman_Text_1
# 1775 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitfanfare
# 1776 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 1777 "data/maps/PetalburgCity_Gym/scripts.pory"
	delay 30
# 1778 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Text_2, MSGBOX_DEFAULT
# 1779 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
	end

PetalburgCity_Gym_EventScript_Norman_9:
# 1786 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, PetalburgCity_Gym_EventScript_Norman_21
PetalburgCity_Gym_EventScript_Norman_20:
# 1795 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM42, PetalburgCity_Gym_EventScript_Norman_16
# 1798 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_Norman_17
# 1802 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
# 1803 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
	end

PetalburgCity_Gym_EventScript_Norman_10:
	return

PetalburgCity_Gym_EventScript_Norman_11:
# 1765 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_NormanBattle
	goto PetalburgCity_Gym_EventScript_Norman_10

PetalburgCity_Gym_EventScript_Norman_14:
	return

PetalburgCity_Gym_EventScript_Norman_15:
# 1787 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Text_3
# 1788 "data/maps/PetalburgCity_Gym/scripts.pory"
	giveitem ITEM_SLAKINGITE
# 1789 "data/maps/PetalburgCity_Gym/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1790 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitfanfare
# 1791 "data/maps/PetalburgCity_Gym/scripts.pory"
	setflag FLAG_OBTAINED_SLAKINGITE
# 1792 "data/maps/PetalburgCity_Gym/scripts.pory"
	release
	end

PetalburgCity_Gym_EventScript_Norman_16:
# 1796 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_Kangaskhan
	goto PetalburgCity_Gym_EventScript_Norman_14

PetalburgCity_Gym_EventScript_Norman_17:
# 1799 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_Norman_Rematch
	goto PetalburgCity_Gym_EventScript_Norman_14

PetalburgCity_Gym_EventScript_Norman_21:
# 1786 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto_if_unset FLAG_OBTAINED_SLAKINGITE, PetalburgCity_Gym_EventScript_Norman_15
	goto PetalburgCity_Gym_EventScript_Norman_20


PetalburgCity_Gym_EventScript_Norman_WallyTutorial::
# 1811 "data/maps/PetalburgCity_Gym/scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
# 1812 "data/maps/PetalburgCity_Gym/scripts.pory"
	closemessage
# 1813 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_FACING
# 1814 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_Norman_WallyTutorial_3
# 1817 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_NORTH, PetalburgCity_Gym_EventScript_Norman_WallyTutorial_4
# 1820 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_WEST, PetalburgCity_Gym_EventScript_Norman_WallyTutorial_5
# 1823 "data/maps/PetalburgCity_Gym/scripts.pory"
	case DIR_EAST, PetalburgCity_Gym_EventScript_Norman_WallyTutorial_6
PetalburgCity_Gym_EventScript_Norman_WallyTutorial_1:
	end

PetalburgCity_Gym_EventScript_Norman_WallyTutorial_3:
# 1815 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth
	goto PetalburgCity_Gym_EventScript_Norman_WallyTutorial_1

PetalburgCity_Gym_EventScript_Norman_WallyTutorial_4:
# 1818 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth
	goto PetalburgCity_Gym_EventScript_Norman_WallyTutorial_1

PetalburgCity_Gym_EventScript_Norman_WallyTutorial_5:
# 1821 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorialWest
	goto PetalburgCity_Gym_EventScript_Norman_WallyTutorial_1

PetalburgCity_Gym_EventScript_Norman_WallyTutorial_6:
# 1824 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorialEast
	goto PetalburgCity_Gym_EventScript_Norman_WallyTutorial_1


PetalburgCity_Gym_EventScript_Norman_Rematch::
# 1831 "data/maps/PetalburgCity_Gym/scripts.pory"
	message PetalburgCity_Gym_Text_NormanChooseFormat
# 1832 "data/maps/PetalburgCity_Gym/scripts.pory"
	waitmessage
# 1833 "data/maps/PetalburgCity_Gym/scripts.pory"
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
# 1834 "data/maps/PetalburgCity_Gym/scripts.pory"
	switch VAR_RESULT
# 1835 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 0, PetalburgCity_Gym_EventScript_Norman_Rematch_3
# 1838 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 1, PetalburgCity_Gym_EventScript_Norman_Rematch_4
# 1840 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_Norman_Rematch_5
# 1841 "data/maps/PetalburgCity_Gym/scripts.pory"
	case 127, PetalburgCity_Gym_EventScript_Norman_Rematch_5
PetalburgCity_Gym_EventScript_Norman_Rematch_1:
# 1845 "data/maps/PetalburgCity_Gym/scripts.pory"
	releaseall
	end

PetalburgCity_Gym_EventScript_Norman_Rematch_3:
# 1836 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SetSingles
	goto PetalburgCity_Gym_EventScript_Norman_Rematch_1

PetalburgCity_Gym_EventScript_Norman_Rematch_4:
# 1839 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_SetDoubles
	goto PetalburgCity_Gym_EventScript_Norman_Rematch_1

PetalburgCity_Gym_EventScript_Norman_Rematch_5:
# 1842 "data/maps/PetalburgCity_Gym/scripts.pory"
	goto PetalburgCity_Gym_EventScript_Exit
	goto PetalburgCity_Gym_EventScript_Norman_Rematch_1


PetalburgCity_Gym_EventScript_Kangaskhan_Text_0:
# 1699 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Take this special Pokémon as a gift\n"
	.string "from me!$"

PetalburgCity_Gym_EventScript_Kangaskhan_Text_1:
# 1702 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER} got Norman's {COLOR BLUE}Kangaskhan{COLOR DARK_GRAY} as\n"
	.string "a gift!$"

PetalburgCity_Gym_EventScript_CheckTrainers_Text_0:
# 1719 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Dad: Sorry {PLAYER}, but you need to\n"
	.string "defeat every trainer on this Gym before\l"
	.string "battling your dad.$"

PetalburgCity_Gym_EventScript_Norman_Text_0:
# 1739 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "This is a failsafe, if you find this file\n"
	.string "a bug report please$"

PetalburgCity_Gym_EventScript_Norman_Text_1:
# 1774 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "{PLAYER} got all the {COLOR LIGHT_GREEN}Mega Stones{COLOR DARK_GRAY}!$"

PetalburgCity_Gym_EventScript_Norman_Text_2:
# 1778 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Now then, {PLAYER}! I'm ready when\n"
	.string "you are!$"

PetalburgCity_Gym_EventScript_Norman_Text_3:
# 1787 "data/maps/PetalburgCity_Gym/scripts.pory"
	.string "Take this special Item as a gift from\n"
	.string "me!$"
