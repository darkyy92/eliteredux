# 1 "data/maps/SafariZone_South/scripts.pory"

# 2 "data/maps/SafariZone_South/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/SafariZone_South/scripts.pory"

# 4 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_MapScripts:: @ 823D279
# 5 "data/maps/SafariZone_South/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_South_OnTransition
# 6 "data/maps/SafariZone_South/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SafariZone_South_OnFrame
# 7 "data/maps/SafariZone_South/scripts.pory"
	.byte 0
# 8 "data/maps/SafariZone_South/scripts.pory"

# 9 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_OnFrame: @ 823D284
# 10 "data/maps/SafariZone_South/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SafariZone_South_EventScript_EnterSafariZone
# 11 "data/maps/SafariZone_South/scripts.pory"
	.2byte 0
# 12 "data/maps/SafariZone_South/scripts.pory"

# 13 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_EnterSafariZone:: @ 823D28E
# 14 "data/maps/SafariZone_South/scripts.pory"
	lockall
# 15 "data/maps/SafariZone_South/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerEnter
# 16 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 17 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_ExitAttendantBlockDoor
# 18 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 19 "data/maps/SafariZone_South/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 32, 34
# 20 "data/maps/SafariZone_South/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 0
# 21 "data/maps/SafariZone_South/scripts.pory"
	releaseall
# 22 "data/maps/SafariZone_South/scripts.pory"
	end
# 23 "data/maps/SafariZone_South/scripts.pory"

# 24 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_OnTransition: @ 823D2B1
# 25 "data/maps/SafariZone_South/scripts.pory"
	compare VAR_SAFARI_ZONE_STATE, 2
# 26 "data/maps/SafariZone_South/scripts.pory"
	call_if_eq SafariZone_South_EventScript_SetExitAttendantAside
# 27 "data/maps/SafariZone_South/scripts.pory"
	end
# 28 "data/maps/SafariZone_South/scripts.pory"

# 29 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_SetExitAttendantAside:: @ 823D2BD
# 30 "data/maps/SafariZone_South/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 31, 34
# 31 "data/maps/SafariZone_South/scripts.pory"
	return
# 32 "data/maps/SafariZone_South/scripts.pory"

# 33 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerEnter: @ 823D2C5
# 34 "data/maps/SafariZone_South/scripts.pory"
	walk_down
# 35 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 36 "data/maps/SafariZone_South/scripts.pory"

# 37 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_ExitAttendantBlockDoor: @ 823D2C7
# 38 "data/maps/SafariZone_South/scripts.pory"
	walk_right
# 39 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_fastest_down
# 40 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 41 "data/maps/SafariZone_South/scripts.pory"

# 42 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Boy:: @ 823D2CA
# 43 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Boy, MSGBOX_NPC
# 44 "data/maps/SafariZone_South/scripts.pory"
	end
# 45 "data/maps/SafariZone_South/scripts.pory"

# 46 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Man:: @ 823D2D3
# 47 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Man, MSGBOX_NPC
# 48 "data/maps/SafariZone_South/scripts.pory"
	end
# 49 "data/maps/SafariZone_South/scripts.pory"

# 50 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Youngster:: @ 823D2DC
# 51 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_Youngster, MSGBOX_NPC
# 52 "data/maps/SafariZone_South/scripts.pory"
	end
# 53 "data/maps/SafariZone_South/scripts.pory"

# 54 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitAttendant:: @ 823D2E5
# 55 "data/maps/SafariZone_South/scripts.pory"
	lock
# 56 "data/maps/SafariZone_South/scripts.pory"
	faceplayer
# 57 "data/maps/SafariZone_South/scripts.pory"
	goto_if_unset FLAG_GOOD_LUCK_SAFARI_ZONE, SafariZone_South_EventScript_GoodLuck
# 58 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_StillHaveTimeExit, MSGBOX_YESNO
# 59 "data/maps/SafariZone_South/scripts.pory"
	compare VAR_RESULT, YES
# 60 "data/maps/SafariZone_South/scripts.pory"
	goto_if_eq SafariZone_South_EventScript_ExitEarly
# 61 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_EnjoyTheRestOfYourAdventure, MSGBOX_DEFAULT
# 62 "data/maps/SafariZone_South/scripts.pory"
	release
# 63 "data/maps/SafariZone_South/scripts.pory"
	end
# 64 "data/maps/SafariZone_South/scripts.pory"

# 65 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_GoodLuck:: @ 823D30D
# 66 "data/maps/SafariZone_South/scripts.pory"
	setflag FLAG_GOOD_LUCK_SAFARI_ZONE
# 67 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_GoodLuck, MSGBOX_DEFAULT
# 68 "data/maps/SafariZone_South/scripts.pory"
	release
# 69 "data/maps/SafariZone_South/scripts.pory"
	end
# 70 "data/maps/SafariZone_South/scripts.pory"

# 71 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarly:: @ 823D31A
# 72 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_ExitEarlyThankYouForPlaying, MSGBOX_DEFAULT
# 73 "data/maps/SafariZone_South/scripts.pory"
	closemessage
# 74 "data/maps/SafariZone_South/scripts.pory"
	switch VAR_FACING
# 75 "data/maps/SafariZone_South/scripts.pory"
	case DIR_NORTH, SafariZone_South_EventScript_ExitEarlyNorth
# 76 "data/maps/SafariZone_South/scripts.pory"
	case DIR_EAST, SafariZone_South_EventScript_ExitEarlyEast
# 77 "data/maps/SafariZone_South/scripts.pory"
	end
# 78 "data/maps/SafariZone_South/scripts.pory"

# 79 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarlyNorth:: @ 823D33F
# 80 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_MoveExitAttendantNorth
# 81 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 82 "data/maps/SafariZone_South/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerExitNorth
# 83 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 84 "data/maps/SafariZone_South/scripts.pory"
	goto SafariZone_South_EventScript_Exit
# 85 "data/maps/SafariZone_South/scripts.pory"
	end
# 86 "data/maps/SafariZone_South/scripts.pory"

# 87 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ExitEarlyEast:: @ 823D359
# 88 "data/maps/SafariZone_South/scripts.pory"
	applymovement LOCALID_ATTENDANT, SafariZone_South_Movement_MoveExitAttendantEast
# 89 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 90 "data/maps/SafariZone_South/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SafariZone_South_Movement_PlayerExitEast
# 91 "data/maps/SafariZone_South/scripts.pory"
	waitmovement 0
# 92 "data/maps/SafariZone_South/scripts.pory"
	goto SafariZone_South_EventScript_Exit
# 93 "data/maps/SafariZone_South/scripts.pory"
	end
# 94 "data/maps/SafariZone_South/scripts.pory"

# 95 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_Exit:: @ 823D373
# 96 "data/maps/SafariZone_South/scripts.pory"
	setvar VAR_SAFARI_ZONE_STATE, 1
# 97 "data/maps/SafariZone_South/scripts.pory"
	special ExitSafariMode
# 98 "data/maps/SafariZone_South/scripts.pory"
	warpdoor MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
# 99 "data/maps/SafariZone_South/scripts.pory"
	waitstate
# 100 "data/maps/SafariZone_South/scripts.pory"
	end
# 101 "data/maps/SafariZone_South/scripts.pory"

# 102 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerExitNorth: @ 823D385
# 103 "data/maps/SafariZone_South/scripts.pory"
	walk_up
# 104 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 105 "data/maps/SafariZone_South/scripts.pory"

# 106 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_PlayerExitEast: @ 823D387
# 107 "data/maps/SafariZone_South/scripts.pory"
	walk_right
# 108 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_fastest_up
# 109 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 110 "data/maps/SafariZone_South/scripts.pory"

# 111 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_MoveExitAttendantNorth: @ 823D38A
# 112 "data/maps/SafariZone_South/scripts.pory"
	walk_left
# 113 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_fastest_right
# 114 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 115 "data/maps/SafariZone_South/scripts.pory"

# 116 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_Movement_MoveExitAttendantEast: @ 823D38D
# 117 "data/maps/SafariZone_South/scripts.pory"
	walk_down
# 118 "data/maps/SafariZone_South/scripts.pory"
	walk_in_place_fastest_up
# 119 "data/maps/SafariZone_South/scripts.pory"
	step_end
# 120 "data/maps/SafariZone_South/scripts.pory"

# 121 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ConstructionWorker1:: @ 823D390
# 122 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_AreaOffLimits1, MSGBOX_NPC
# 123 "data/maps/SafariZone_South/scripts.pory"
	end
# 124 "data/maps/SafariZone_South/scripts.pory"

# 125 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_ExpansionZoneAttendant:: @ 823D399
# 126 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_ExpansionIsFinished, MSGBOX_NPC
# 127 "data/maps/SafariZone_South/scripts.pory"
	end
# 128 "data/maps/SafariZone_South/scripts.pory"

# 129 "data/maps/SafariZone_South/scripts.pory"
SafariZone_South_EventScript_ConstructionWorker2:: @ 823D3A2
# 130 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_South_Text_AreaOffLimits2, MSGBOX_NPC
# 131 "data/maps/SafariZone_South/scripts.pory"
	end
# 132 "data/maps/SafariZone_South/scripts.pory"

# 133 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_LittleGirl:: @ 823D3AB
# 134 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_LittleGirl, MSGBOX_NPC
# 135 "data/maps/SafariZone_South/scripts.pory"
	end
# 136 "data/maps/SafariZone_South/scripts.pory"

# 137 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_FatMan:: @ 823D3B4
# 138 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_FatMan, MSGBOX_NPC
# 139 "data/maps/SafariZone_South/scripts.pory"
	end
# 140 "data/maps/SafariZone_South/scripts.pory"

# 141 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Southeast_EventScript_RichBoy:: @ 823D3BD
# 142 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Southeast_Text_RichBoy, MSGBOX_NPC
# 143 "data/maps/SafariZone_South/scripts.pory"
	end
# 144 "data/maps/SafariZone_South/scripts.pory"

# 145 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Boy:: @ 823D3C6
# 146 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Boy, MSGBOX_NPC
# 147 "data/maps/SafariZone_South/scripts.pory"
	end
# 148 "data/maps/SafariZone_South/scripts.pory"

# 149 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Woman:: @ 823D3CF
# 150 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Woman, MSGBOX_NPC
# 151 "data/maps/SafariZone_South/scripts.pory"
	end
# 152 "data/maps/SafariZone_South/scripts.pory"

# 153 "data/maps/SafariZone_South/scripts.pory"
SafariZone_Northeast_EventScript_Girl:: @ 823D3D8
# 154 "data/maps/SafariZone_South/scripts.pory"
	msgbox SafariZone_Northeast_Text_Girl, MSGBOX_NPC
# 155 "data/maps/SafariZone_South/scripts.pory"
	end
