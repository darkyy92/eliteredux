# 1 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
.set LOCALID_RIVAL, 1
# 3 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 4 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_MapScripts:: @ 81F9296
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
# 6 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.byte 0
# 8 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 9 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnTransition: @ 81F92A1
# 10 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_lt LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
# 13 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_ge LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
# 14 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 4
# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 17 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 18 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 19 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos:: @ 81F92CD
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 22 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 2
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_Ret
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 25 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 26 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos:: @ 81F92E6
# 27 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 28 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 29 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_Ret
# 30 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 31 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_Ret
# 32 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 8, 2
# 33 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
# 34 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 35 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 36 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Ret:: @ 81F9309
# 37 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay:: @ 81F930A
# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay:: @ 81F9317
# 46 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 47 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 48 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 49 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_OnWarp: @ 81F931D
# 50 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
# 51 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.2byte 0
# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 53 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor:: @ 81F9327
# 54 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 55 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 56 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq SecretBase_EventScript_InitDecorations
# 57 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 58 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 59 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall:: @ 81F9334
# 60 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 61 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
# 62 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMay
# 63 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 64 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 66 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 67 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMay:: @ 81F934A
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 69 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	addobject LOCALID_RIVAL
# 70 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 72 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PIN
# 73 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 74 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 75 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 76 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 77 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay 10
# 78 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 79 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 80 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
# 81 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 82 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
# 83 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 84 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
# 85 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 86 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
# 87 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 88 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 89 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 90 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 92 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	fadedefaultbgm
# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 95 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 96 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth:: @ 81F93BA
# 97 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
# 98 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 99 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 100 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 101 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 102 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 103 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayCatchYouLater, MSGBOX_DEFAULT
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 105 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
# 106 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
# 107 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 109 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 110 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth:: @ 81F93E9
# 111 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
# 112 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 113 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 114 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 115 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 116 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 117 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayCatchYouLater, MSGBOX_DEFAULT
# 118 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
# 120 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
# 121 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 123 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 124 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest:: @ 81F9418
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
# 126 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 127 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 128 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 129 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 130 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 131 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayCatchYouLater, MSGBOX_DEFAULT
# 132 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 133 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
# 134 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 135 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 136 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 137 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast:: @ 81F9440
# 138 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
# 139 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 140 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 142 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 143 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayCatchYouLater, MSGBOX_DEFAULT
# 145 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 146 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
# 147 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
# 148 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 149 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 150 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 151 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet::
# 152 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_Which_Region, MSGBOX_DEFAULT
# 153 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_REGION_NAMES
# 154 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special ShowScrollableMultichoice
# 155 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 156 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_RESULT
# 157 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 0, LittlerootTown_MaysHouse_2F_EventScript_Kanto
# 158 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 1, LittlerootTown_MaysHouse_2F_EventScript_Johto
# 159 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 2, LittlerootTown_MaysHouse_2F_EventScript_Hoenn
# 160 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 3, LittlerootTown_MaysHouse_2F_EventScript_Sinnoh
# 161 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 4, LittlerootTown_MaysHouse_2F_EventScript_Unova
# 162 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 5, LittlerootTown_MaysHouse_2F_EventScript_Kalos
# 163 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 6, LittlerootTown_MaysHouse_2F_EventScript_Alola
# 164 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case 7, LittlerootTown_MaysHouse_2F_EventScript_Galar
# 165 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 166 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 167 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 168 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Kanto::
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 170 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 171 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 172 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 1
# 173 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringKanto
# 174 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 175 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 176 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Johto::
# 177 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 178 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 179 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 180 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 2
# 181 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringJohto
# 182 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 183 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 184 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Hoenn::
# 185 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 186 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 187 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 188 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 3
# 189 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringHoenn
# 190 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 191 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 192 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Sinnoh::
# 193 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 194 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 195 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 196 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 4
# 197 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringSinnoh
# 198 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 199 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 200 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Unova::
# 201 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 202 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 204 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 5
# 205 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringUnova
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 207 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 208 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Kalos::
# 209 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 210 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 211 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 212 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 6
# 213 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringKalos
# 214 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 215 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 216 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Alola::
# 217 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 218 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 219 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 220 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 7
# 221 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringAlola
# 222 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 223 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 224 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_Galar::
# 225 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 226 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 227 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_ChooseStarterSet
# 228 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 8
# 229 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringGalar
# 230 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 231 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 232 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayEnters: @ 81F946F
# 233 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 234 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 235 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_right
# 236 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 237 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 238 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth: @ 81F9473
# 239 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 240 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 241 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 242 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 243 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 244 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 245 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 246 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth: @ 81F9479
# 247 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 248 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 249 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 250 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_right
# 251 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 252 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 253 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 254 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 255 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 256 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 257 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 258 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth: @ 81F9483
# 259 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 260 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 261 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 262 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 263 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 264 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 265 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_right
# 266 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 267 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 268 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth: @ 81F948B
# 269 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 270 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 271 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 272 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 273 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 274 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth: @ 81F948F
# 275 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 276 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_right
# 277 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 278 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 279 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 280 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 281 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 282 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 283 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 284 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth: @ 81F9497
# 285 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 286 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 287 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 288 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 289 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_right
# 290 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 291 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 292 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest: @ 81F949D
# 293 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 294 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 295 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 296 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 297 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 298 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_down
# 299 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 300 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 301 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest: @ 81F94A4
# 302 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 303 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 304 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 305 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 306 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 307 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 308 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 309 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest: @ 81F94A9
# 310 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 311 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 312 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_right
# 313 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 314 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 315 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast: @ 81F94AD
# 316 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 317 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 318 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_down
# 319 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_right
# 320 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 321 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 322 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast: @ 81F94B2
# 323 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 324 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_up
# 325 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 326 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 327 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 328 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 329 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_right
# 330 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 331 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 332 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 333 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast: @ 81F94BB
# 334 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 335 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 336 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 337 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	delay_16
# 338 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	walk_in_place_fastest_right
# 339 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	step_end
# 340 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 341 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Rival:: @ 81F94C1
# 342 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 343 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
# 344 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 345 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 346 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq RivalsHouse_2F_EventScript_May
# 347 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 348 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq RivalsHouse_2F_EventScript_Brendan
# 349 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 350 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 351 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_May:: @ 81F94E3
# 352 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
# 353 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 354 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 355 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 356 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_Brendan:: @ 81F94ED
# 357 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
# 358 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 359 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 360 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 361 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_RivalPostLilycove:: @ 81F94F7
# 362 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 363 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 364 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 365 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 366 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq RivalsHouse_2F_EventScript_MayPostLilycove
# 367 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 368 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq RivalsHouse_2F_EventScript_BrendanPostLilycove
# 369 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
# 370 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 371 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 372 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 373 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayPostLilycove:: @ 81F951D
# 374 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
# 375 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
# 376 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 377 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 378 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanPostLilycove:: @ 81F952F
# 379 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
# 380 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
# 381 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 382 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 383 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_MayWhereShouldIGoNext:: @ 81F9541
# 384 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
# 385 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 386 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 387 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext:: @ 81F954A
# 388 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
# 389 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	return
# 390 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 391 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_PC:: @ 81F9553
# 392 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 393 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 394 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 395 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
# 396 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 397 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
# 398 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 399 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 400 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC:: @ 81F956C
# 401 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 402 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 403 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 404 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 405 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC:: @ 81F9576
# 406 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, 2
# 407 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 408 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 409 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 410 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 411 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 412 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 413 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 414 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 415 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F958F
# 416 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, 2
# 417 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 418 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 419 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
# 420 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	end
# 421 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 422 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhoAreYou: @ 81F959C
# 423 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh?\n"
# 424 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who… Who are you?\p"
# 425 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\n"
# 426 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "… … … … … … … …\p"
# 427 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}{KUN}.\n"
# 428 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So your move was today.\p"
# 429 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Um… I'm May.\n"
# 430 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Glad to meet you!\p"
# 431 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I…\n"
# 432 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I have this dream of becoming friends\l"
# 433 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "with Pokémon all over the world.\p"
# 434 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
# 435 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "my dad, Prof. Birch.\p"
# 436 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was hoping that you would be nice,\n"
# 437 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
# 438 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, this is silly, isn't it?\n"
# 439 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
# 440 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Eheheh…\p"
# 441 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, no! I forgot!\p"
# 442 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was supposed to go help Dad catch\n"
# 443 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild Pokémon!\p"
# 444 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, hey, that reminds me!\n"
# 445 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "You should go see Dad's newest Pokémon!\p"
# 446 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "He just got three really rare ones\n"
# 447 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "from the, um…$"
# 448 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 449 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayCatchYouLater:
# 450 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh? The {STR_VAR_2} region?\n"
# 451 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Wow, I think that was it!\p"
# 452 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "{PLAYER}{KUN}, I'll catch you later!$"
# 453 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 454 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayGettingReady: @ 81F978A
# 455 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Pokémon fully restored!\n"
# 456 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items ready, and…$"
# 457 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 458 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhoAreYou: @ 81F97B4
# 459 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey!\n"
# 460 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "You…\p"
# 461 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Who are you?\p"
# 462 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you're {PLAYER}, aren't you?\n"
# 463 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Moved in next door, right?\p"
# 464 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I didn't know that you're a girl.\p"
# 465 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Dad, Prof. Birch, said that our new\n"
# 466 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "next-door neighbor is a Gym Leader's\l"
# 467 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "kid, so I assumed you'd be a guy.\p"
# 468 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "My name's Brendan.\n"
# 469 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "So, hi, neighbor!\p"
# 470 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
# 471 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "a Pokémon?\p"
# 472 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Do you want me to go catch you one?\p"
# 473 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Aw, darn, I forgot…\p"
# 474 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I'm supposed to go help my dad catch\n"
# 475 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some wild Pokémon.\p"
# 476 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, you should go check out the three\n"
# 477 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "new Pokémon my dad just got.\p"
# 478 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "They're very rare, and they're all\n"
# 479 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "from the, uh…$"
# 480 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 481 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanSomeOtherTime:
# 482 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "The {STR_VAR_2} region?\n"
# 483 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Huh, I think that was it, actually.\p"
# 484 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Some other time, okay?$"
# 485 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 486 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanGettingReady: @ 81F9962
# 487 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Pokémon fully restored…\n"
# 488 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Items all packed, and…$"
# 489 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 490 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_ItsRivalsPokeBall: @ 81F9991
# 491 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "It's {RIVAL}'s Poké Ball!\p"
# 492 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Better leave it right where it is.$"
# 493 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 494 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayJustCheckingMyPokedex: @ 81F99C9
# 495 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "May: {PLAYER}{KUN}!\p"
# 496 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking my Pokédex.\p"
# 497 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There's still a lot of Pokémon that\n"
# 498 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I've seen but haven't caught.\p"
# 499 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "And there are many others that\n"
# 500 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I think will evolve.\p"
# 501 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I wonder where I should go catch\n"
# 502 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some Pokémon next?$"
# 503 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 504 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_MayWhereShouldIGoNext: @ 81F9A9E
# 505 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "May: I wonder where I should go catch\n"
# 506 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "some Pokémon next?\p"
# 507 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Wouldn't it be funny if we ran into each\n"
# 508 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "other, {PLAYER}{KUN}?$"
# 509 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 510 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex: @ 81F9B0D
# 511 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Brendan: Hey, it's {PLAYER}.\p"
# 512 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I was just checking out my Pokédex.\p"
# 513 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "There are still many Pokémon that\n"
# 514 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "I need to catch, I know, but this\l"
# 515 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "is looking pretty good.\p"
# 516 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Checking this Pokédex out gives me\n"
# 517 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "the urge to hit the road again.$"
# 518 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"

# 519 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
RivalsHouse_2F_Text_BrendanWhereShouldIGoNext: @ 81F9BE7
# 520 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Brendan: I'm having a hard time deciding\n"
# 521 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "where I should catch Pokémon next.\p"
# 522 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Hey, {PLAYER}, if I see you while I'm out\n"
# 523 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "catching Pokémon, I can pitch you a\l"
# 524 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "battle if you'd like.$"
