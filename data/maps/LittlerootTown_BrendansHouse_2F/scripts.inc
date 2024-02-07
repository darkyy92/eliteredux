# 1 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
.set LOCALID_RIVAL, 1
# 3 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 4 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_MapScripts:: @ 81F83E3
# 5 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
# 6 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
# 7 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.byte 0
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 9 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnTransition: @ 81F83EE
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
# 11 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_lt LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
# 12 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
# 13 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_ge LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 4
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 17 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 18 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 19 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 20 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos:: @ 81F841A
# 21 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 22 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_BIRCH_LAB_STATE, 2
# 23 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 24 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 25 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 26 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos:: @ 81F8433
# 27 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 28 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 29 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 30 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
# 31 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_Ret  @ Odd that the MaysHouse equivalent was used here instead
# 32 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 0, 2
# 33 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
# 34 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 35 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 36 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Ret:: @ 81F8456
# 37 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 38 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 39 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan:: @ 81F8457
# 40 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 41 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 42 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
# 43 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 44 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 45 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan:: @ 81F8464
# 46 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 47 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 48 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 49 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_OnWarp: @ 81F846A
# 50 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
# 51 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.2byte 0
# 52 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 53 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor:: @ 81F8474
# 54 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 55 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 56 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq SecretBase_EventScript_InitDecorations
# 57 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 58 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 59 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall:: @ 81F8481
# 60 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 61 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
# 62 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
# 63 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
# 64 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 65 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 66 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 67 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan:: @ 81F8497
# 68 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 69 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	addobject LOCALID_RIVAL
# 70 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
# 71 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 72 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PIN
# 73 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 74 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 75 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 76 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 77 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay 10
# 78 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 79 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 80 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
# 81 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 82 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
# 83 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 84 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
# 85 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 86 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
# 87 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 88 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 89 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 90 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 91 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	savebgm MUS_DUMMY
# 92 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	fadedefaultbgm
# 93 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 94 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 95 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 96 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth:: @ 81F8507
# 97 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
# 98 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 99 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 100 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 101 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 102 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 103 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanSomeOtherTime, MSGBOX_DEFAULT
# 104 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 105 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
# 106 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
# 107 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 108 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 109 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 110 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth:: @ 81F8536
# 111 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
# 112 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 113 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 114 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 115 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 116 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 117 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanSomeOtherTime, MSGBOX_DEFAULT
# 118 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 119 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
# 120 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
# 121 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 122 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 123 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 124 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest:: @ 81F8565
# 125 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
# 126 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 127 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 128 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 129 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 130 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 131 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanSomeOtherTime, MSGBOX_DEFAULT
# 132 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 133 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
# 134 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
# 135 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 136 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 137 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 138 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast:: @ 81F8594
# 139 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
# 140 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 141 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 142 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 143 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 144 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 145 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanSomeOtherTime, MSGBOX_DEFAULT
# 146 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	closemessage
# 147 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
# 148 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitmovement 0
# 149 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 150 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 151 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet::
# 152 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_1F_Text_Which_Region, MSGBOX_DEFAULT
# 153 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_REGION_NAMES
# 154 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special ShowScrollableMultichoice
# 155 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitstate
# 156 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	switch VAR_RESULT
# 157 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case 0, LittlerootTown_BrendansHouse_2F_EventScript_Kanto
# 158 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case 1, LittlerootTown_BrendansHouse_2F_EventScript_Johto
# 159 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case 2, LittlerootTown_BrendansHouse_2F_EventScript_Hoenn
# 160 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case 3, LittlerootTown_BrendansHouse_2F_EventScript_Sinnoh
# 161 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case 4, LittlerootTown_BrendansHouse_2F_EventScript_Unova
# 162 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case 5, LittlerootTown_BrendansHouse_2F_EventScript_Kalos
# 163 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case 6, LittlerootTown_BrendansHouse_2F_EventScript_Alola
# 164 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	case 7, LittlerootTown_BrendansHouse_2F_EventScript_Galar
# 165 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 166 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 167 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 168 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Kanto:
# 169 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 170 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 171 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 172 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 1
# 173 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringKanto
# 174 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 175 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 176 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Johto:
# 177 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 178 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 179 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 180 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 2
# 181 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringJohto
# 182 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 183 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 184 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Hoenn:
# 185 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 186 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 187 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 188 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 3
# 189 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringHoenn
# 190 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 191 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 192 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Sinnoh:
# 193 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 194 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 195 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 196 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 4
# 197 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringSinnoh
# 198 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 199 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 200 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Unova:
# 201 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 202 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 203 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 204 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 5
# 205 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringUnova
# 206 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 207 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 208 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Kalos:
# 209 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 210 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 211 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 212 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 6
# 213 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringKalos
# 214 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 215 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 216 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Alola:
# 217 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 218 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 219 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 220 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 7
# 221 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringAlola
# 222 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 223 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 224 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_Galar:
# 225 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 226 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, NO
# 227 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_ChooseStarterSet
# 228 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_STARTER_GEN, 8
# 229 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	bufferstring 1, StarterRegionStringGalar
# 230 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	return
# 231 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 232 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters: @ 81F85BC
# 233 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 234 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 235 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_left
# 236 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 237 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 238 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth: @ 81F85C0
# 239 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 240 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 241 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 242 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 243 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 244 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 245 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 246 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth: @ 81F85C6
# 247 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 248 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 249 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 250 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 251 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 252 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 253 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 254 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 255 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 256 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 257 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth: @ 81F85CF
# 258 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 259 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 260 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 261 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 262 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 263 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 264 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_left
# 265 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 266 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 267 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth: @ 81F85D7
# 268 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 269 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 270 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 271 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 272 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 273 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth: @ 81F85DB
# 274 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 275 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 276 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 277 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 278 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 279 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 280 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 281 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 282 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth: @ 81F85E2
# 283 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 284 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 285 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 286 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 287 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_left
# 288 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 289 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 290 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest: @ 81F85E8
# 291 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 292 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 293 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_down
# 294 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_left
# 295 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 296 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 297 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest: @ 81F85ED
# 298 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 299 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 300 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 301 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 302 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 303 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 304 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 305 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 306 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 307 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 308 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest: @ 81F85F6
# 309 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_8
# 310 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 311 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 312 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 313 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 314 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_left
# 315 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 316 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 317 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast: @ 81F85FD
# 318 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 319 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 320 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 321 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 322 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 323 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_down
# 324 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 325 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 326 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast: @ 81F8604
# 327 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_up
# 328 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 329 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_left
# 330 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_up
# 331 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 332 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 333 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
@ Unused, the player is already facing this direction so its unneeded
# 334 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast: @ 81F8609
# 335 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 336 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	delay_16
# 337 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	walk_in_place_fastest_left
# 338 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	step_end
# 339 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 340 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_PC:: @ 81F860D
# 341 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 342 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkplayergender
# 343 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 344 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
# 345 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 346 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
# 347 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 348 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 349 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC:: @ 81F8626
# 350 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 351 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 352 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_ON
# 353 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 354 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special BedroomPC
# 355 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitstate
# 356 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 357 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 358 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 359 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F863F
# 360 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 361 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 362 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 363 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 364 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 365 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 366 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC:: @ 81F864C
# 367 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 368 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
# 369 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 370 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 371 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_Notebook:: @ 81F8656
# 372 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
# 373 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 374 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 375 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_EventScript_GameCube:: @ 81F865F
# 376 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
# 377 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	end
# 378 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 379 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ClockIsStopped: @ 81F8668
# 380 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
# 381 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Better set it and start it!$"
# 382 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 383 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_HowDoYouLikeYourRoom: @ 81F869A
# 384 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Mom: {PLAYER}, how do you like your\n"
# 385 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "new room?\p"
# 386 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Good! Everything's put away neatly!\p"
# 387 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "They finished moving everything in\n"
# 388 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "downstairs, too.\p"
# 389 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Pokémon movers are so convenient!\p"
# 390 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Oh, you should make sure that\n"
# 391 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "everything's all there on your desk.$"
# 392 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 393 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_Notebook: @ 81F877F
# 394 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
# 395 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Adventure Rule No. 1\n"
# 396 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Open the Menu with Start.\p"
# 397 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Adventure Rule No. 2\n"
# 398 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Record your progress with Save.\p"
# 399 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The remaining pages are blank…$"
# 400 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 401 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
Common_Text_LookCloserAtMap: @ 81F8820
# 402 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
# 403 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "Hoenn region map.$"
# 404 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"

# 405 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
PlayersHouse_2F_Text_ItsAGameCube: @ 81F884F
# 406 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
# 407 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "A Game Boy Advance is connected to\n"
# 408 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "serve as the Controller.$"
