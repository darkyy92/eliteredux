# 1 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 2 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_MOM, 1
# 3 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_RIVAL_MOM, 4
# 4 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 6 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
# 7 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
# 8 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
# 9 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
# 10 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.byte 0
# 11 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 12 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
# 13 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 6
# 14 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_lt LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
# 15 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
# 16 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 17 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 18 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes:: @ 81F777A
# 19 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
# 20 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
# 21 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 22 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 23 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual:: @ 81F778D
# 24 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	checkplayergender
# 25 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, MALE
# 26 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
# 27 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 28 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 29 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F779A
# 30 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
# 31 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 32 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 33 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
# 34 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 3
# 35 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
# 36 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 5
# 37 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
# 38 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 6
# 39 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
# 40 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 41 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 42 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs:: @ 81F77C6
# 43 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 8, 4
# 44 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 45 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 46 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 47 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV:: @ 81F77D2
# 48 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 4, 5
# 49 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 50 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 51 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 52 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor:: @ 81F77DE
# 53 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_MOM, 9, 8
# 54 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
# 55 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 56 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 57 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@ Many of the below scripts have no gender check because they assume youre in the correct house
# 58 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
# 59 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
# 60 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
# 61 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
# 62 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
# 63 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
# 64 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
# 65 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.2byte 0
# 66 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 67 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F7814
# 68 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 69 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 70 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 71 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 72 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 73 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 74 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
# 75 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitstate
# 76 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 77 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 78 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 79 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs: @ 81F783A
# 80 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 81 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 82 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 83 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F783C
# 84 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 85 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_MOM
# 86 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 87 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
# 88 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 89 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 90 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport:: @ 81F784D
# 91 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 92 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, MALE
# 93 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, LOCALID_MOM
# 94 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
# 95 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 96 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 97 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor:: @ 81F785E
# 98 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 99 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 100 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
# 101 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 102 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
# 103 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 104 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 105 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
# 106 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 107 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 108 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 109 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 110 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
# 111 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 112 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 113 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 114 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach: @ 81F789C
# 115 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_down
# 116 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 117 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 118 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 119 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 120 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 121 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 122 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 123 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom:: @ 81F78A3
# 124 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 125 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, LOCALID_MOM
# 126 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 127 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestLeft
# 128 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 129 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
# 130 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 131 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 132 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0:: @ 81F78BE
# 133 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 134 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 135 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 136 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 137 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 138 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1:: @ 81F78CA
# 139 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 140 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 141 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 142 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 143 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 144 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2:: @ 81F78D6
# 145 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 146 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 147 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
# 148 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 149 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 150 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival:: @ 81F78E2
# 151 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 152 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 10
# 153 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	addobject LOCALID_RIVAL
# 154 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 155 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 156 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 157 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 158 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 159 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 160 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 161 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_ne LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
# 162 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 163 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 0
# 164 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
# 165 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 166 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
# 167 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 2
# 168 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
# 169 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 170 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 171 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanSomeOtherTime, MSGBOX_DEFAULT
# 172 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 173 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 0
# 174 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
# 175 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
# 176 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
# 177 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 2
# 178 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
# 179 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 180 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	removeobject LOCALID_RIVAL
# 181 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
# 182 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 183 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 184 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 185 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 186 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 187 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 188 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	fadedefaultbgm
# 189 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
# 190 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 191 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 192 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet::
# 193 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_Which_Region, MSGBOX_DEFAULT
# 194 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_REGION_NAMES
# 195 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special ShowScrollableMultichoice
# 196 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitstate
# 197 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_RESULT
# 198 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 0, LittlerootTown_BrendansHouse_1F_EventScript_Kanto
# 199 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 1, LittlerootTown_BrendansHouse_1F_EventScript_Johto
# 200 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 2, LittlerootTown_BrendansHouse_1F_EventScript_Hoenn
# 201 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 3, LittlerootTown_BrendansHouse_1F_EventScript_Sinnoh
# 202 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 4, LittlerootTown_BrendansHouse_1F_EventScript_Unova
# 203 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 5, LittlerootTown_BrendansHouse_1F_EventScript_Kalos
# 204 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 6, LittlerootTown_BrendansHouse_1F_EventScript_Alola
# 205 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 7, LittlerootTown_BrendansHouse_1F_EventScript_Galar
# 206 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 207 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	end
# 208 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 209 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_Kanto:
# 210 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 211 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 212 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 213 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_STARTER_GEN, 1
# 214 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	bufferstring 1, StarterRegionStringKanto
# 215 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 216 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 217 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_Johto:
# 218 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 219 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 220 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 221 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_STARTER_GEN, 2
# 222 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	bufferstring 1, StarterRegionStringJohto
# 223 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 224 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 225 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_Hoenn:
# 226 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 227 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 228 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 229 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_STARTER_GEN, 3
# 230 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	bufferstring 1, StarterRegionStringHoenn
# 231 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 232 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 233 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_Sinnoh:
# 234 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 235 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 236 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 237 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_STARTER_GEN, 4
# 238 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	bufferstring 1, StarterRegionStringSinnoh
# 239 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 240 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 241 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_Unova:
# 242 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 243 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 244 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 245 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_STARTER_GEN, 5
# 246 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	bufferstring 1, StarterRegionStringUnova
# 247 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 248 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 249 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_Kalos:
# 250 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 251 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 252 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 253 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_STARTER_GEN, 6
# 254 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	bufferstring 1, StarterRegionStringKalos
# 255 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 256 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 257 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_Alola:
# 258 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 259 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 260 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 261 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_STARTER_GEN, 7
# 262 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	bufferstring 1, StarterRegionStringAlola
# 263 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 264 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 265 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_Galar:
# 266 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SureAboutRegion, MSGBOX_YESNO
# 267 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 268 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ChooseStarterSet
# 269 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_STARTER_GEN, 8
# 270 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	bufferstring 1, StarterRegionStringGalar
# 271 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 272 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 273 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan:: @ 81F7981
# 274 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 275 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 276 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 277 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 278 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0:: @ 81F798C
# 279 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
# 280 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 281 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 282 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 283 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1:: @ 81F7997
# 284 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
# 285 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 286 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 287 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 288 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2:: @ 81F79A2
# 289 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
# 290 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 291 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 292 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 293 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0: @ 81F79AD
# 294 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_left
# 295 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 296 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_up
# 297 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 298 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 299 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 300 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 301 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 302 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 303 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1: @ 81F79B5
# 304 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 305 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 306 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 307 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 308 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 309 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2: @ 81F79B9
# 310 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_right
# 311 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 312 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_up
# 313 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 314 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 315 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 316 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 317 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 318 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 319 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0:: @ 81F79C1
# 320 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
# 321 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
# 322 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 323 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 324 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 325 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1:: @ 81F79D3
# 326 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
# 327 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
# 328 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 329 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 330 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 331 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2:: @ 81F79E5
# 332 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
# 333 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
# 334 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 335 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	return
# 336 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 337 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0: @ 81F79F7
# 338 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 339 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 340 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_right
# 341 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 342 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 343 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1: @ 81F79FB
# 344 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 345 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 346 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_right
# 347 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 348 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 349 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_up
# 350 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 351 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 352 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2: @ 81F7A02
# 353 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 354 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 355 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_left
# 356 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 357 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 358 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0: @ 81F7A06
# 359 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_right
# 360 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 361 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_up
# 362 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 363 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 364 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 365 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 366 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1: @ 81F7A0C
# 367 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_right
# 368 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 369 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_up
# 370 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 371 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 372 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_left
# 373 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 374 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_up
# 375 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 376 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 377 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 378 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2: @ 81F7A16
# 379 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_left
# 380 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 381 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_fastest_up
# 382 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 383 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 384 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	step_end
# 385 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 386 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsntItNiceInHere: @ 81F7A1C
# 387 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: See, {PLAYER}?\n"
# 388 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Isn't it nice in here, too?$"
# 389 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 390 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_MoversPokemonGoSetClock: @ 81F7A46
# 391 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The mover's Pokémon do all the work\n"
# 392 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "of moving us in and cleaning up after.\l"
# 393 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "This is so convenient!\p"
# 394 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "{PLAYER}, your room is upstairs.\n"
# 395 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go check it out, dear!\p"
# 396 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad bought you a new clock to mark\n"
# 397 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "our move here.\l"
# 398 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Don't forget to set it!$"
# 399 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 400 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ArentYouInterestedInRoom: @ 81F7B24
# 401 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Well, {PLAYER}?\p"
# 402 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Aren't you interested in seeing your\n"
# 403 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "very own room?$"
# 404 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 405 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GoSetTheClock: @ 81F7B67
# 406 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: {PLAYER}.\p"
# 407 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go set the clock in your room, honey.$"
# 408 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 409 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_OhComeQuickly: @ 81F7B96
# 410 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Oh! {PLAYER}, {PLAYER}!\n"
# 411 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Quick! Come quickly!$"
# 412 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 413 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_MaybeDadWillBeOn: @ 81F7BBC
# 414 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Look! It's Petalburg Gym!\n"
# 415 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Maybe Dad will be on!$"
# 416 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 417 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ItsOverWeMissedHim: @ 81F7BF1
# 418 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Oh… It's over.\p"
# 419 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I think Dad was on, but we missed him.\n"
# 420 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Too bad.$"
# 421 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 422 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor: @ 81F7C35
# 423 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes.\n"
# 424 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "One of Dad's friends lives in town.\p"
# 425 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Prof. Birch is his name.\p"
# 426 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He lives right next door, so you should\n"
# 427 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "go over and introduce yourself.$"
# 428 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 429 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_SeeYouHoney: @ 81F7CC3
# 430 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: See you, honey!$"
# 431 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 432 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DidYouMeetProfBirch: @ 81F7CD8
# 433 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Did you introduce yourself to\n"
# 434 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Prof. Birch?$"
# 435 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 436 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_YouShouldRestABit: @ 81F7D08
# 437 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: How are you doing, {PLAYER}?\n"
# 438 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "You look a little tired.\p"
# 439 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I think you should rest a bit.$"
# 440 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 441 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TakeCareHoney: @ 81F7D5C
# 442 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Take care, honey!$"
# 443 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 444 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom: @ 81F7D73
# 445 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Oh? Did Dad give you that Badge?\p"
# 446 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Then here's something from your Mom!$"
# 447 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 448 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DontPushYourselfTooHard: @ 81F7DBE
# 449 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Don't push yourself too hard, dear.\n"
# 450 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "You can always come home.\p"
# 451 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Go for it, honey!$"
# 452 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 453 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsThatAPokenav: @ 81F7E0E
# 454 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: What is that, honey? A PokéNav?\n"
# 455 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Someone from Devon gave it to you?\p"
# 456 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Well, honey, how about registering\n"
# 457 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "your mom?\p"
# 458 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "… … …$"
# 459 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 460 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_RegisteredMom: @ 81F7E89
# 461 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Registered Mom\n"
# 462 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "in the PokéNav.$"
# 463 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 464 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_Vigoroth1: @ 81F7EA8
# 465 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Fugiiiiih!$"
# 466 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 467 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_Vigoroth2: @ 81F7EB3
# 468 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Huggoh, uggo uggo…$"
# 469 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 470 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_ReportFromPetalburgGym: @ 81F7EC6
# 471 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Interviewer: …We brought you this\n"
# 472 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "report from in front of Petalburg Gym.$"
# 473 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 474 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TheresAMovieOnTV: @ 81F7F0F
# 475 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "There is a movie on TV.\p"
# 476 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Two men are dancing on a big piano\n"
# 477 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "keyboard.\p"
# 478 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Better get going!$"
# 479 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 480 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_RunningShoesManual: @ 81F7F66
# 481 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's the instruction booklet for the\n"
# 482 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Running Shoes.\p"
# 483 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "“Press the B Button to walk while\n"
# 484 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "wearing your Running Shoes.\p"
# 485 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "“Lace up your Running Shoes and hit\n"
# 486 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "the road running!”$"
# 487 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 488 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_TicketFromBrineyCameForYou: @ 81F800E
# 489 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: Hm?\p"
# 490 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 491 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's been a while since I saw you,\n"
# 492 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "but you look…stronger, somehow.\p"
# 493 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "That's the impression I get.\n"
# 494 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "But your old man hasn't given up yet!\p"
# 495 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes, I have something for you.\n"
# 496 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "This came to you from someone named\l"
# 497 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mr. Briney.$"
# 498 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 499 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_PortsInSlateportLilycove: @ 81F80FE
# 500 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Dad: Hm, a Ticket for a ferry?\p"
# 501 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "If I recall, there are ferry ports in\n"
# 502 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Slateport and Lilycove.$"
# 503 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 504 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_BetterGetBackToGym: @ 81F815B
# 505 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I'd better get back to Petalburg Gym.\p"
# 506 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom, thanks for looking after the house\n"
# 507 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "while I'm away.$"
# 508 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 509 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_DadShouldStayLonger: @ 81F81B9
# 510 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: That Dad of yours…\p"
# 511 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He comes home for the first time in a\n"
# 512 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "while, but all he talks about is Pokémon.\p"
# 513 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "He should relax and stay a little longer.$"
# 514 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 515 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_IsThatABreakingStory: @ 81F824B
# 516 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Is that a breaking news story?$"
# 517 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 518 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_LatiEmergencyNewsFlash: @ 81F826F
# 519 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We bring you this emergency\n"
# 520 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "news flash!\p"
# 521 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "In various Hoenn locales, there have\n"
# 522 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "been reports of a BZZT…colored\l"
# 523 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Pokémon in flight.\p"
# 524 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The identity of this Pokémon is\n"
# 525 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "currently unknown.\p"
# 526 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We now return you to the regular\n"
# 527 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "movie program.$"
# 528 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 529 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_WhatColorDidTheySay: @ 81F8351
# 530 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: {PLAYER}, did you catch that?\p"
# 531 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "What color did the announcer say\n"
# 532 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "that Pokémon was?$"
# 533 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"

# 534 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
PlayersHouse_1F_Text_StillUnknownPokemon: @ 81F83A1
# 535 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Mom: Well, isn't that something!\n"
# 536 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "There are still unknown Pokémon.$"

PlayersHouse_1F_Text_Which_Region::
# 539 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Hmm. Which region was it again?$"
