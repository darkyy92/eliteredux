# 1 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 2 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 4 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts:: @ 8243D92
# 5 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
# 6 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
# 7 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
# 8 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
# 9 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.byte 0
# 10 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 11 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnResume: @ 8243DA7
# 12 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	pyramid_resetparty
# 13 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 14 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 15 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition: @ 8243DB0
# 16 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
# 17 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
# 18 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
# 19 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
# 20 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
# 21 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
# 22 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
# 23 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
# 24 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
# 25 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_loadpartners
# 26 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 27 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 28 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner:: @ 8243DDA
# 29 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
# 30 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
# 31 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
# 32 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
# 33 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
# 34 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
# 35 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
# 36 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
# 37 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 38 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_3, 1
# 39 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
# 40 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 41 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 42 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp: @ 8243E14
# 43 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
# 44 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.2byte 0
# 45 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 46 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth:: @ 8243E1E
# 47 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 48 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 49 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 50 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame: @ 8243E23
# 51 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
# 52 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
# 53 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.2byte 0
# 54 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 55 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom:: @ 8243E35
# 56 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lockall
# 57 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_3, 0
# 58 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
# 59 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 60 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 61 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom:: @ 8243E41
# 62 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lockall
# 63 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
# 64 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 65 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
# 66 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 67 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	copyobjectxytoperm LOCALID_ATTENDANT
# 68 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 69 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 70 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
# 71 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	special HealPlayerParty
# 72 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 73 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	releaseall
# 74 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 75 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 76 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom: @ 8243E75
# 77 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_down
# 78 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 79 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 80 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit: @ 8243E77
# 81 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_left
# 82 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_in_place_fastest_down
# 83 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 84 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 85 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant:: @ 8243E7A
# 86 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 87 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 88 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
# 89 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 90 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 91 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	compare VAR_RESULT, 0
# 92 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_eq BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
# 93 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
# 94 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 95 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 96 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 97 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge:: @ 8243E9D
# 98 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
# 99 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
# 100 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 101 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 102 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator:: @ 8243EB5
# 103 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
# 104 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closemessage
# 105 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestUp
# 106 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 107 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	opendoor 10, 1
# 108 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitdooranim
# 109 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
# 110 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closedoor 10, 1
# 111 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitdooranim
# 112 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 255, 1, 6
# 113 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitstate
# 114 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	releaseall
# 115 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 116 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 117 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator:: @ 8243EE4
# 118 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 119 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
# 120 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 121 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 122 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 123 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Unused
# 124 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast: @ 8243EF6
# 125 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 126 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
# 127 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 128 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 129 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 130 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Unused
# 131 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest: @ 8243F08
# 132 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
# 133 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
# 134 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 135 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 136 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 137 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator: @ 8243F1A
# 138 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 139 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 140 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 141 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 142 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 143 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Functionally unused
# 144 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast: @ 8243F1E
# 145 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_right
# 146 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 147 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 148 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 149 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 150 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
@ Functionally unused
# 151 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest: @ 8243F22
# 152 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_left
# 153 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 154 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 155 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 156 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 157 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator: @ 8243F26
# 158 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_up
# 159 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	set_invisible
# 160 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 161 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 162 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1:: @ 8243F29
# 163 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 164 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 165 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 0
# 166 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 167 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 168 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 169 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner:: @ 8243F36
# 170 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 171 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_INTRO
# 172 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 173 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 174 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_MON1
# 175 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 176 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 177 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
# 178 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 179 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 180 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	switch VAR_RESULT
# 181 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 182 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
# 183 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
# 184 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 185 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 186 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	closemessage
# 187 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 188 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call_if_ne BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
# 189 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 190 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	call_if_eq BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
# 191 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	removeobject VAR_LAST_TALKED
# 192 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
# 193 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 255, 10, 3
# 194 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitstate
# 195 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 196 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 197 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 198 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner:: @ 8243FC3
# 199 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	tower_dopartnermsg PARTNER_MSGID_REJECT
# 200 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmessage
# 201 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitbuttonpress
# 202 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	release
# 203 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 204 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 205 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit:: @ 8243FD4
# 206 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
# 207 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 208 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 209 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 210 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth:: @ 8243FDF
# 211 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
# 212 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	waitmovement 0
# 213 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	return
# 214 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 215 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit: @ 8243FEA
# 216 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 217 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 218 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 219 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 220 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 221 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 222 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 223 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 224 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 225 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth: @ 8243FF2
# 226 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_left
# 227 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 228 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 229 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 230 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 231 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 232 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 233 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	walk_fast_up
# 234 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	step_end
# 235 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 236 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2:: @ 8243FFB
# 237 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 238 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 239 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 240 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 241 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 242 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 243 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3:: @ 8244008
# 244 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 245 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 246 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 2
# 247 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 248 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 249 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 250 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4:: @ 8244015
# 251 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 252 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 253 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 3
# 254 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 255 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 256 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 257 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5:: @ 8244022
# 258 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 259 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 260 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 4
# 261 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 262 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 263 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 264 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6:: @ 824402F
# 265 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 266 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 267 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 5
# 268 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 269 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 270 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 271 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7:: @ 824403C
# 272 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 273 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 274 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 6
# 275 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 276 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 277 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 278 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8:: @ 8244049
# 279 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	lock
# 280 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	faceplayer
# 281 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	setvar VAR_TEMP_2, 7
# 282 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
# 283 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	end
# 284 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 285 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner: @ 8244056
# 286 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please find a partner from out of\n"
# 287 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the Trainers gathered here.$"
# 288 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 289 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner: @ 8244094
# 290 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, you have not found a partner\n"
# 291 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "for your tag team.\p"
# 292 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you like to quit looking and\n"
# 293 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "return to the reception counter?$"
# 294 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 295 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2: @ 824410C
# 296 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Then, please find a partner from\n"
# 297 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the Trainers gathered here.$"
# 298 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 299 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner:: @ 8244149
# 300 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you for choosing a partner.\p"
# 301 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will now show you to your\n"
# 302 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "MULTI BATTLE ROOM.$"
# 303 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 304 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro:: @ 824419A
# 305 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 306 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You can call me {STR_VAR_3}!$"
# 307 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 308 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1:: @ 82441CA
# 309 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "On {STR_VAR_1}'s advice, I brought\n"
# 310 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
# 311 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 312 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask:: @ 82441F7
# 313 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 314 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, let me join you as a tag team.$"
# 315 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 316 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept:: @ 824422E
# 317 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 318 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right now.$"
# 319 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 320 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject:: @ 8244255
# 321 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I really wanted to form a tag team\n"
# 322 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with you, {PLAYER}…$"
# 323 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 324 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro:: @ 8244286
# 325 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 326 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name is {STR_VAR_3}.$"
# 327 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 328 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1:: @ 82442B2
# 329 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I got advice from {STR_VAR_1} and chose\n"
# 330 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_3} with {STR_VAR_2} and$"
# 331 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 332 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask:: @ 82442E4
# 333 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 334 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, let's form a tag team!$"
# 335 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 336 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept:: @ 8244313
# 337 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you very much!\n"
# 338 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be done with registration quickly!$"
# 339 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 340 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject:: @ 8244350
# 341 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I was hoping that I could\n"
# 342 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partner up with you…$"
# 343 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 344 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro:: @ 8244383
# 345 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um, my name's {STR_VAR_3}, and I'm\n"
# 346 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}'s no. {STR_VAR_2} apprentice.\p"
# 347 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Snivel…\p"
# 348 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sorry!\n"
# 349 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This tension is making me cry…$"
# 350 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 351 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1:: @ 82443E7
# 352 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} advised me, so I have\n"
# 353 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 354 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 355 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask:: @ 8244413
# 356 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 357 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Snivel…\n"
# 358 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, please team up with me!$"
# 359 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 360 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept:: @ 824444B
# 361 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, really? You will?\n"
# 362 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Awesome! Wicked! Awoooh!\p"
# 363 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh… I'm sorry…\n"
# 364 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm so happy, I'm crying…\p"
# 365 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right away.\n"
# 366 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please don't go away!$"
# 367 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 368 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject:: @ 82444D6
# 369 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, b-but…\n"
# 370 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sob… Waaaaah!$"
# 371 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 372 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro:: @ 82444EF
# 373 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there! I'm {STR_VAR_3}!\n"
# 374 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 375 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 376 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1:: @ 824451E
# 377 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} recommended my crew.\n"
# 378 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 379 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 380 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask:: @ 8244549
# 381 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
# 382 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's what I have! Cool, huh?\p"
# 383 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So come on!\n"
# 384 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's form a tag team!$"
# 385 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 386 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept:: @ 824459B
# 387 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay! Great!\n"
# 388 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, I'll go register, okay?$"
# 389 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 390 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject:: @ 82445C5
# 391 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, why?\n"
# 392 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I wanted to team up, {PLAYER}!$"
# 393 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 394 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro:: @ 82445E8
# 395 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}, the no. {STR_VAR_2} apprentice\n"
# 396 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "of the famous {STR_VAR_1}!$"
# 397 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 398 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1:: @ 8244618
# 399 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I looked to {STR_VAR_3} for advice.\n"
# 400 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 401 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 402 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask:: @ 8244643
# 403 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1},\n"
# 404 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's my pair.\p"
# 405 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, will you join me in\n"
# 406 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 407 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 408 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept:: @ 824468F
# 409 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 410 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register right away!$"
# 411 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 412 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject:: @ 82446B4
# 413 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I had been hoping to join\n"
# 414 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "you in a tag team…$"
# 415 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 416 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro:: @ 82446E5
# 417 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um… I'm sincerely happy that you\n"
# 418 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "would take the time to talk to me.\p"
# 419 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}.\n"
# 420 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…$"
# 421 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 422 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1:: @ 824474D
# 423 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} gave me advice.\n"
# 424 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm very grateful for it.\p"
# 425 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have a team of one {STR_VAR_2}\n"
# 426 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with {STR_VAR_1} and$"
# 427 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 428 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask:: @ 824479E
# 429 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 430 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I know I'm asking a lot…\p"
# 431 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I don't think you'll be willing to,\n"
# 432 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "but may I join you as a partner?$"
# 433 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 434 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept:: @ 824480C
# 435 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Really? I can't believe it!\n"
# 436 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I can't believe you'll let me join you!\l"
# 437 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I… I won't let you down!\p"
# 438 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Um… If it's really okay, I'll go register\n"
# 439 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right this instant!$"
# 440 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 441 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject:: @ 82448A7
# 442 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh…\n"
# 443 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I didn't think I was good enough…$"
# 444 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 445 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro:: @ 82448CD
# 446 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm {STR_VAR_3}.\n"
# 447 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 448 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 449 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1:: @ 82448F5
# 450 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} told me that it would be\n"
# 451 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "good to make this team:\l"
# 452 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"
# 453 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 454 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask:: @ 8244939
# 455 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} that knows how\n"
# 456 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to use {STR_VAR_1}.\p"
# 457 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not bad, huh?\n"
# 458 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want me to team up with you?$"
# 459 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 460 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept:: @ 8244989
# 461 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, glad to join you!\n"
# 462 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you won't mess things up for me!\l"
# 463 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll do my registration now.$"
# 464 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 465 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject:: @ 82449E6
# 466 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Huh? Why did you turn me down?\n"
# 467 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're no judge of character!$"
# 468 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 469 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro:: @ 8244A23
# 470 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3} and I'm a TRIATHLETE.\n"
# 471 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm busy every day what with jogging,\l"
# 472 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "training, and rapping.\p"
# 473 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I also happen to be {STR_VAR_1}'s\n"
# 474 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice.$"
# 475 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 476 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1:: @ 8244AA9
# 477 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This is what {STR_VAR_3} recommended.\n"
# 478 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 479 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 480 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask:: @ 8244AD6
# 481 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 482 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 483 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I put a lot of effort into raising\n"
# 484 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "them, even though I'm busy.\p"
# 485 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's form a tag team\n"
# 486 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and give it a go!$"
# 487 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 488 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept:: @ 8244B52
# 489 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks, that's the spirit!\n"
# 490 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hang tight while I go register, okay?$"
# 491 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 492 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject:: @ 8244B93
# 493 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I took time from my busy schedule\n"
# 494 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to be here! Give me a break!$"
# 495 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 496 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro:: @ 8244BD2
# 497 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi!\n"
# 498 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How's it going?\p"
# 499 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}, {STR_VAR_1}'s\n"
# 500 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice. Glad to meet you!$"
# 501 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 502 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1:: @ 8244C18
# 503 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Listen, listen! You have to hear about\n"
# 504 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the Pokémon {STR_VAR_3} recommended.\l"
# 505 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 506 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 507 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask:: @ 8244C6E
# 508 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 509 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I raised them superbly!\p"
# 510 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, want to team up?\n"
# 511 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sure it'll be a great combo!$"
# 512 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 513 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept:: @ 8244CD6
# 514 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay, I think this will be fun!\n"
# 515 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register!$"
# 516 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 517 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject:: @ 8244D07
# 518 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, you're mean!\n"
# 519 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I come recommended, you know.$"
# 520 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 521 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro:: @ 8244D36
# 522 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please let me introduce myself.\n"
# 523 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_3}.\p"
# 524 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I serve as {STR_VAR_1}'s\n"
# 525 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice.$"
# 526 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 527 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1:: @ 8244D82
# 528 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I sought the sage advice of\n"
# 529 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} and raised my team\l"
# 530 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "of one {STR_VAR_2} with {STR_VAR_1}$"
# 531 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 532 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask:: @ 8244DC6
# 533 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\p"
# 534 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please agree to a tag team with me!$"
# 535 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 536 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept:: @ 8244DFE
# 537 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh… I'm delighted!\n"
# 538 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I promise to give you my best!\p"
# 539 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I will register us!\n"
# 540 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please wait!$"
# 541 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 542 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject:: @ 8244E5B
# 543 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I had been hoping to join you,\n"
# 544 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}…$"
# 545 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 546 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro:: @ 8244E7E
# 547 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Eek! You spoke to me!\n"
# 548 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I… I'm overjoyed!\p"
# 549 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}! I'm {STR_VAR_1}'s\n"
# 550 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice!$"
# 551 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 552 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1:: @ 8244ECA
# 553 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "On {STR_VAR_3}'s advice, I trained\n"
# 554 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}$"
# 555 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 556 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask:: @ 8244EF4
# 557 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 558 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 559 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, can you grant me my wish?\n"
# 560 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I want to be your tag-team partner!$"
# 561 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 562 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept:: @ 8244F4F
# 563 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Eek! I… I feel giddy!\n"
# 564 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you so much!\l"
# 565 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us right away!$"
# 566 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 567 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject:: @ 8244F98
# 568 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Waaah! Don't you feel any pity?\n"
# 569 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "But that makes you cooler…$"
# 570 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 571 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro:: @ 8244FD3
# 572 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeehaw! I'm {STR_VAR_1}'s\n"
# 573 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice!\p"
# 574 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3}'s my name, hello, hello!$"
# 575 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 576 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1:: @ 8245013
# 577 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My mentor {STR_VAR_3} recommended\n"
# 578 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-master {STR_VAR_2}$"
# 579 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 580 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask:: @ 824503D
# 581 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-master\n"
# 582 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}.\p"
# 583 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good stuff, huh?\n"
# 584 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll partner with me, won't you?$"
# 585 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 586 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept:: @ 8245087
# 587 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, excellent!\n"
# 588 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done quickly!$"
# 589 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 590 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject:: @ 82450C0
# 591 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gwaaah!\n"
# 592 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're a calculating one, {PLAYER}!$"
# 593 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 594 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro:: @ 82450E6
# 595 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey! There's big trouble! This is\n"
# 596 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the Battle Tower's last day!\p"
# 597 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "… … … … … …\n"
# 598 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm only joking!\p"
# 599 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "People call me {STR_VAR_3} and I do, too!\n"
# 600 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s 1,000th apprentice!\l"
# 601 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Actually, I'm no. {STR_VAR_2}!$"
# 602 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 603 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1:: @ 8245196
# 604 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} gave me some advice.\n"
# 605 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 606 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 607 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask:: @ 82451BD
# 608 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1}.\n"
# 609 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've got ten of each kind!\l"
# 610 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Actually, just one of each!\p"
# 611 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 612 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to try tag battles with me?$"
# 613 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 614 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept:: @ 824522F
# 615 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yippee!\n"
# 616 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll give you a Pokémon as my thanks!\p"
# 617 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Just joking! But I will really go do\n"
# 618 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the registration, okay?$"
# 619 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 620 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject:: @ 824529A
# 621 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, that's so cold! I'll have to wreck\n"
# 622 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the Battle Tower for that!\p"
# 623 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course I won't!$"
# 624 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 625 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro:: @ 82452EF
# 626 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, there, I'm rockin' and a-rollin'!\n"
# 627 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Pokémon, I be controllin'!\p"
# 628 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3} the rappin' SAILOR.\n"
# 629 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't be mistakin' me for no wailer!\p"
# 630 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\n"
# 631 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Me, you shouldn't be quick to dismiss!$"
# 632 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 633 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1:: @ 82453B4
# 634 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With the advice of {STR_VAR_3} I did\n"
# 635 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "abide, put together my team of pride!\l"
# 636 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 637 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 638 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask:: @ 8245406
# 639 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 640 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}!\p"
# 641 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Our meeting we should commemorate,\n"
# 642 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with a tag-team victory to celebrate!$"
# 643 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 644 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept:: @ 8245464
# 645 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, hey, I like your style!\n"
# 646 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Our registration, I will go file!$"
# 647 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 648 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject:: @ 82454A3
# 649 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, hey, {PLAYER}, now that's cold!\n"
# 650 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If I may be so bold!$"
# 651 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 652 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro:: @ 82454D6
# 653 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yippee-yahoo!\n"
# 654 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, don't run! I was just having fun!\p"
# 655 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Howdy! I'm {STR_VAR_3}!\n"
# 656 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"
# 657 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 658 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1:: @ 8245535
# 659 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} told me what to do.\n"
# 660 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So one {STR_VAR_1}-using {STR_VAR_2}$"
# 661 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 662 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask:: @ 824555F
# 663 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 664 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2}, I did choose.\p"
# 665 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, what do you say?\n"
# 666 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Come on, make my day!\p"
# 667 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, I'm begging you!\n"
# 668 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me join you, don't leave me blue!$"
# 669 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 670 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept:: @ 82455EC
# 671 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeahah! Luck is with me!\n"
# 672 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It sure makes me happy!\p"
# 673 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Before we go join the fray,\n"
# 674 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register right away!$"
# 675 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 676 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject:: @ 8245656
# 677 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're turning me down?\n"
# 678 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, you're making me frown!$"
# 679 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 680 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro:: @ 824568A
# 681 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cough!\p"
# 682 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, sorry, I have a cold.\n"
# 683 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My Pokémon are fine, though.\p"
# 684 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name's {STR_VAR_3}, {STR_VAR_1}'s\n"
# 685 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "no. {STR_VAR_2} apprentice. Cough!$"
# 686 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 687 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1:: @ 82456F5
# 688 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I took {STR_VAR_3}'s advice to heart\n"
# 689 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and put together my team of\l"
# 690 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 691 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 692 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask:: @ 8245740
# 693 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 694 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I trained them every day,\n"
# 695 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "even in wind and rain.\p"
# 696 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's why I have this cold,\n"
# 697 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I think.\p"
# 698 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's what I'm about.\n"
# 699 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be my tag partner?$"
# 700 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 701 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept:: @ 82457D9
# 702 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks, I appreciate this!\n"
# 703 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cough, cough!\l"
# 704 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hang on while I go register.$"
# 705 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 706 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject:: @ 824581F
# 707 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, you won't?\n"
# 708 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{PLAYER}, I think we'd make a good pair.$"
# 709 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 710 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro:: @ 8245851
# 711 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, hello!\n"
# 712 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "This is nerve-racking.\p"
# 713 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_3}.\n"
# 714 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"
# 715 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 716 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1:: @ 824589C
# 717 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} said this team'll be good--\n"
# 718 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 719 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 720 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask:: @ 82458CE
# 721 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 722 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm feeling self-conscious about this,\n"
# 723 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "but will you let me join you?$"
# 724 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 725 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept:: @ 8245923
# 726 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, gee, thank you!\n"
# 727 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I feel bashful, but I'll do my best!\p"
# 728 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go get the registration done.$"
# 729 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 730 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject:: @ 824597F
# 731 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, please don't say no!\n"
# 732 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I feel self-conscious enough already…$"
# 733 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 734 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro:: @ 82459BE
# 735 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_3}, and that's no lie.\n"
# 736 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"
# 737 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 738 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1:: @ 82459F7
# 739 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_3} recommended my team.\p"
# 740 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Since the advice sounded sincere,\n"
# 741 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I decided to bring with me\l"
# 742 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2} and$"
# 743 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 744 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask:: @ 8245A5F
# 745 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\p"
# 746 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If possible, I would like you to accept\n"
# 747 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "me as your tag-team partner.$"
# 748 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 749 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept:: @ 8245AB4
# 750 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You really will accept me?\n"
# 751 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be too terrible otherwise.\p"
# 752 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "But since you've agreed, this is fine.\n"
# 753 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall go register the both of us.$"
# 754 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 755 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject:: @ 8245B3E
# 756 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm? Now why would you refuse?\n"
# 757 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Is this your idea of a joke?$"
# 758 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 759 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro:: @ 8245B79
# 760 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a LASS!$"
# 761 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 762 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1:: @ 8245B91
# 763 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I have are one {STR_VAR_2}\n"
# 764 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and one$"
# 765 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 766 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask:: @ 8245BBD
# 767 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\n"
# 768 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Those are what I have with me.\p"
# 769 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you be my partner?$"
# 770 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 771 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept:: @ 8245C05
# 772 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 773 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration!$"
# 774 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 775 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject:: @ 8245C2D
# 776 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You don't want to be my partner?\n"
# 777 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret it later!$"
# 778 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 779 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro:: @ 8245C66
# 780 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\p"
# 781 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm YOUNGSTER {STR_VAR_1}!$"
# 782 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 783 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1:: @ 8245C7F
# 784 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know what I have?\n"
# 785 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 786 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 787 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask:: @ 8245CAC
# 788 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 789 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll be my tag-team partner,\n"
# 790 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "won't you?$"
# 791 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 792 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept:: @ 8245CE6
# 793 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay!\n"
# 794 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go and register, okay?$"
# 795 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 796 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject:: @ 8245D07
# 797 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww! If you'd form a tag team with\n"
# 798 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my Pokémon, we'd be unstoppable!$"
# 799 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 800 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro:: @ 8245D4B
# 801 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yahoo!\n"
# 802 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm HIKER {STR_VAR_1}!$"
# 803 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 804 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1:: @ 8245D60
# 805 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Know what I have with me?\n"
# 806 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My {STR_VAR_1}-using {STR_VAR_2} and$"
# 807 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 808 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask:: @ 8245D8D
# 809 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\p"
# 810 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sounds good, eh?\n"
# 811 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to form a tag team?$"
# 812 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 813 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept:: @ 8245DC7
# 814 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yahoo!\n"
# 815 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registering, then.$"
# 816 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 817 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject:: @ 8245DF0
# 818 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I would've liked to battle with you\n"
# 819 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "at my side.$"
# 820 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 821 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro:: @ 8245E20
# 822 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 823 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a BEAUTY!$"
# 824 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 825 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1:: @ 8245E41
# 826 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you know what I've been raising?\n"
# 827 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 828 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 829 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask:: @ 8245E78
# 830 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 831 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do you think?\n"
# 832 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to make a tag team together?$"
# 833 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 834 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept:: @ 8245EBD
# 835 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wonderful!\n"
# 836 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done now!$"
# 837 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 838 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject:: @ 8245EEC
# 839 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How disappointing!\p"
# 840 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We two together--we would've been\n"
# 841 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the best!$"
# 842 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 843 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro:: @ 8245F2B
# 844 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo!\p"
# 845 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You know who I am?\n"
# 846 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1} the FISHERMAN!$"
# 847 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 848 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1:: @ 8245F58
# 849 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've got with me a team of one\n"
# 850 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 851 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 852 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask:: @ 8245F87
# 853 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 854 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, how about it?\n"
# 855 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you battle at my side?$"
# 856 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 857 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept:: @ 8245FC6
# 858 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good, good!\n"
# 859 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Leave it up to me!\p"
# 860 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go and register us now.$"
# 861 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 862 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject:: @ 8246002
# 863 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We matched up perfectly, too…$"
# 864 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 865 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro:: @ 8246020
# 866 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Glad to make your acquaintance.\n"
# 867 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, a LADY.$"
# 868 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 869 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1:: @ 8246051
# 870 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am accompanied by a team of\n"
# 871 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 872 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 873 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask:: @ 8246082
# 874 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 875 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope I meet your approval.\n"
# 876 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "For I wish to have you as my partner.$"
# 877 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 878 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept:: @ 82460D5
# 879 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thank you sincerely.\n"
# 880 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall handle the registration.$"
# 881 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 882 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject:: @ 824610D
# 883 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm sure that you will regret not\n"
# 884 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "having me as your partner.$"
# 885 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 886 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro:: @ 824614A
# 887 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 888 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 889 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1:: @ 824615D
# 890 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I have…\n"
# 891 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 892 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 893 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask:: @ 824617D
# 894 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
# 895 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's my pair!\p"
# 896 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please?\n"
# 897 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Will you form a tag team with me?$"
# 898 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 899 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept:: @ 82461C7
# 900 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gee, thanks!\n"
# 901 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register at the counter.$"
# 902 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 903 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject:: @ 82461F5
# 904 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We two together, we would've been\n"
# 905 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tough for certain!$"
# 906 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 907 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro:: @ 824622A
# 908 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiya!\n"
# 909 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BUG CATCHER {STR_VAR_1}!$"
# 910 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 911 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1:: @ 8246244
# 912 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out what I have!\n"
# 913 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 914 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 915 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask:: @ 824626E
# 916 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 917 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "So, listen!\n"
# 918 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you want to form a tag team?$"
# 919 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 920 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept:: @ 82462AA
# 921 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Gotcha!\p"
# 922 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration stuff\n"
# 923 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "at the counter.$"
# 924 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 925 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject:: @ 82462E4
# 926 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, my Pokémon are awesome.\n"
# 927 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you won't regret this!$"
# 928 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 929 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro:: @ 824631F
# 930 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good day!\n"
# 931 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm School Kid {STR_VAR_1}!$"
# 932 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 933 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1:: @ 824633C
# 934 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What I've been raising are one\n"
# 935 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} that uses {STR_VAR_1}$"
# 936 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 937 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask:: @ 824636B
# 938 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} that uses\n"
# 939 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 940 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not too bad, don't you think?\n"
# 941 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you care to form a tag team?$"
# 942 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 943 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept:: @ 82463C5
# 944 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you very much!\n"
# 945 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get done with the registration.$"
# 946 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 947 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject:: @ 82463FF
# 948 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's too bad…\p"
# 949 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was hoping that I could learn\n"
# 950 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "from you as your partner…$"
# 951 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 952 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro:: @ 8246449
# 953 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo! Let me tell you who I am!\n"
# 954 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm RICH BOY {STR_VAR_1}!$"
# 955 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 956 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1:: @ 8246478
# 957 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Guess what I got!\n"
# 958 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 959 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 960 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask:: @ 824649D
# 961 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 962 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm willing to offer you the chance\n"
# 963 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to be in a tag team with me.$"
# 964 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 965 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept:: @ 82464EE
# 966 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Smart move!\p"
# 967 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll finish up the registration\n"
# 968 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "process quick!$"
# 969 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 970 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject:: @ 8246529
# 971 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'd turn me of all people down?\n"
# 972 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret that decision for sure!$"
# 973 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 974 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro:: @ 8246571
# 975 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiyah!\n"
# 976 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am BLACK BELT {STR_VAR_1}.$"
# 977 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 978 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1:: @ 824658C
# 979 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "As my companions, I have\n"
# 980 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} using {STR_VAR_1}$"
# 981 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 982 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask:: @ 82465B5
# 983 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} using\n"
# 984 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 985 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please, grant me my wish!\n"
# 986 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Allow me to be your tag partner!$"
# 987 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 988 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept:: @ 8246605
# 989 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiyah!\n"
# 990 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will go register forthwith!$"
# 991 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 992 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject:: @ 824662A
# 993 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I see… I hope for an opportunity\n"
# 994 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the next time we meet…$"
# 995 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 996 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro:: @ 8246662
# 997 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there!\n"
# 998 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a TUBER!$"
# 999 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1000 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1:: @ 8246686
# 1001 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll tell you what I have.\n"
# 1002 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1003 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1004 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask:: @ 82466B4
# 1005 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\n"
# 1006 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I please be on your tag team?$"
# 1007 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1008 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept:: @ 82466E6
# 1009 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 1010 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us now!$"
# 1011 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1012 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject:: @ 824670A
# 1013 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we'd become partners, we could\n"
# 1014 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "have been so strong!$"
# 1015 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1016 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro:: @ 8246741
# 1017 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Greetings…\n"
# 1018 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am HEX MANIAC {STR_VAR_1}…$"
# 1019 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1020 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1:: @ 8246760
# 1021 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I bear with me one {STR_VAR_1}-using\n"
# 1022 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} together with one$"
# 1023 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1024 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask:: @ 8246791
# 1025 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2}…\p"
# 1026 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I beseech you…\n"
# 1027 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Join me in a tag team…$"
# 1028 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1029 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept:: @ 82467C4
# 1030 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thank you…\n"
# 1031 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall register us…$"
# 1032 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1033 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject:: @ 82467E6
# 1034 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I so longed to join you…$"
# 1035 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1036 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro:: @ 82467FF
# 1037 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How do you do? I'm {STR_VAR_1},\n"
# 1038 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and I'm a Pokémon BREEDER!$"
# 1039 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1040 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1:: @ 8246831
# 1041 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm raising a couple good ones!\n"
# 1042 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1043 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1044 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask:: @ 8246864
# 1045 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1046 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 1047 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Feel like making a tag team with me?$"
# 1048 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1049 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept:: @ 82468A7
# 1050 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you kindly!\p"
# 1051 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go take care of the registration\n"
# 1052 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "stuff, so you wait right here!$"
# 1053 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1054 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject:: @ 82468FE
# 1055 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was looking forward to being\n"
# 1056 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "your partner…$"
# 1057 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1058 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro:: @ 824692B
# 1059 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, hello!\n"
# 1060 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 1061 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1062 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1:: @ 824694B
# 1063 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know what I run with?\n"
# 1064 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1065 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1066 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask:: @ 824697C
# 1067 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1068 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well?\n"
# 1069 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be in a tag team with me?$"
# 1070 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1071 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept:: @ 82469B4
# 1072 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good going!\p"
# 1073 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be quick and get the registration\n"
# 1074 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "all done!$"
# 1075 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1076 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject:: @ 82469F1
# 1077 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You and me, we would've been tops.\n"
# 1078 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad…$"
# 1079 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1080 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro:: @ 8246A22
# 1081 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey, there! My name's {STR_VAR_1}!\n"
# 1082 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a TRIATHLETE!$"
# 1083 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1084 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1:: @ 8246A4E
# 1085 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I go on runs with my durable team--\n"
# 1086 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1087 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1088 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask:: @ 8246A85
# 1089 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1090 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Not too shabby, huh?\n"
# 1091 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We should be in a tag team together!$"
# 1092 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1093 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept:: @ 8246ACF
# 1094 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All right!\n"
# 1095 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register in a flash!$"
# 1096 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1097 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject:: @ 8246AF7
# 1098 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I really wanted to battle as your\n"
# 1099 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag-team partner…$"
# 1100 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1101 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro:: @ 8246B2B
# 1102 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BATTLE GIRL {STR_VAR_1}!$"
# 1103 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1104 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1:: @ 8246B3F
# 1105 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been toughening up one\n"
# 1106 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1107 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1108 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask:: @ 8246B6B
# 1109 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\p"
# 1110 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you like that combo?\n"
# 1111 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about you and me join up?$"
# 1112 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1113 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept:: @ 8246BB2
# 1114 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why, thanks!\p"
# 1115 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done\n"
# 1116 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right now!$"
# 1117 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1118 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject:: @ 8246BE9
# 1119 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With you, I thought we could form\n"
# 1120 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the ultimate tag team…$"
# 1121 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1122 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro:: @ 8246C22
# 1123 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TRIATHLETE {STR_VAR_1}!$"
# 1124 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1125 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1:: @ 8246C35
# 1126 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been running with one {STR_VAR_2}\n"
# 1127 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that knows how to use {STR_VAR_1}$"
# 1128 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1129 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask:: @ 8246C6C
# 1130 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1131 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We could be in a tag team.\n"
# 1132 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wouldn't that be great?$"
# 1133 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1134 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept:: @ 8246CB3
# 1135 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\p"
# 1136 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register us, and that's\n"
# 1137 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "right now!$"
# 1138 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1139 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject:: @ 8246CE9
# 1140 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aww, that's too bad. We would've been\n"
# 1141 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the toughest tag team around!$"
# 1142 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1143 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro:: @ 8246D2D
# 1144 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Me?\n"
# 1145 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm TUBER {STR_VAR_1}!$"
# 1146 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1147 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1:: @ 8246D3F
# 1148 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do I have with me?\n"
# 1149 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1150 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1151 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask:: @ 8246D6A
# 1152 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1153 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hey?\n"
# 1154 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll team up with me, right?$"
# 1155 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1156 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept:: @ 8246D9E
# 1157 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay!\p"
# 1158 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register!\n"
# 1159 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's be excellent together!$"
# 1160 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1161 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject:: @ 8246DD3
# 1162 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My Pokémon are tough for sure…\n"
# 1163 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad you don't want to team up.$"
# 1164 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1165 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro:: @ 8246E1A
# 1166 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey!\n"
# 1167 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Call me GUITARIST {STR_VAR_1}!$"
# 1168 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1169 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1:: @ 8246E39
# 1170 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out my entourage!\n"
# 1171 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1172 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1173 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask:: @ 8246E64
# 1174 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1175 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey! Pretty wild, huh?\n"
# 1176 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll have to do a duet in a tag team!$"
# 1177 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1178 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept:: @ 8246EB6
# 1179 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay-hey! Right on!\n"
# 1180 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll do that registration stuff now!$"
# 1181 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1182 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject:: @ 8246EEE
# 1183 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My Pokémon rock hard!\n"
# 1184 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll be sorry, I tell you!$"
# 1185 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1186 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro:: @ 8246F21
# 1187 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Pleased to meet you.\n"
# 1188 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, a GENTLEMAN.$"
# 1189 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1190 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1:: @ 8246F4C
# 1191 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am accompanied by my trusted\n"
# 1192 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1193 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1194 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask:: @ 8246F7B
# 1195 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 1196 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I ask you to join me in a tag-team\n"
# 1197 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partnership arrangement?$"
# 1198 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1199 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept:: @ 8246FCC
# 1200 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ah, I thank you for your trust.\n"
# 1201 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall be done with the registration.$"
# 1202 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1203 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject:: @ 8247013
# 1204 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That is most unfortunate…\p"
# 1205 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall look forward to the next\n"
# 1206 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "opportunity…$"
# 1207 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1208 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro:: @ 824705B
# 1209 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello, I'm {STR_VAR_1},\n"
# 1210 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and I'm a POKéFAN.$"
# 1211 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1212 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1:: @ 824707D
# 1213 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have with me now one {STR_VAR_2}\n"
# 1214 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that knows the move {STR_VAR_1} and$"
# 1215 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1216 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask:: @ 82470B2
# 1217 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1218 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you like what you see?\n"
# 1219 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why don't you be my tag partner?$"
# 1220 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1221 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept:: @ 82470FD
# 1222 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you!\n"
# 1223 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll look after the registration!$"
# 1224 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1225 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject:: @ 824712A
# 1226 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My Pokémon are top grade…\n"
# 1227 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's too bad you can't appreciate that.$"
# 1228 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1229 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro:: @ 824716C
# 1230 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm!\n"
# 1231 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I am {STR_VAR_1}, and an EXPERT am I!$"
# 1232 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1233 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1:: @ 824718D
# 1234 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The Pokémon that I've toughened up are\n"
# 1235 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1236 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1237 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask:: @ 82471C7
# 1238 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1239 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What say you to a tag team with me?$"
# 1240 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1241 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept:: @ 82471FB
# 1242 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hm!\n"
# 1243 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I shall register us right away!\l"
# 1244 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let us both do our best!$"
# 1245 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1246 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject:: @ 8247238
# 1247 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will hope that your choice is\n"
# 1248 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "indeed correct…$"
# 1249 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1250 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro:: @ 8247268
# 1251 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello, hello.\n"
# 1252 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm an EXPERT.$"
# 1253 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1254 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1:: @ 8247291
# 1255 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've raised my Pokémon thoroughly.\n"
# 1256 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1257 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1258 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask:: @ 82472C7
# 1259 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1260 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they're what I have.\p"
# 1261 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Wouldn't you like to team up with me?$"
# 1262 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1263 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept:: @ 8247313
# 1264 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good, good.\n"
# 1265 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll see to the registration right away.$"
# 1266 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1267 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject:: @ 8247348
# 1268 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Perhaps we can form a team the next\n"
# 1269 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "time we meet.$"
# 1270 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1271 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro:: @ 824737A
# 1272 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm DRAGON TAMER {STR_VAR_1}!$"
# 1273 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1274 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1:: @ 824738F
# 1275 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The team I've been toughening up is\n"
# 1276 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1277 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1278 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask:: @ 82473C6
# 1279 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1280 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about it?\n"
# 1281 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to be my partner?$"
# 1282 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1283 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept:: @ 82473FB
# 1284 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay, I'll give it my best!\n"
# 1285 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register now, all right?$"
# 1286 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1287 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject:: @ 8247438
# 1288 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You're not going to find many tougher\n"
# 1289 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partners than me!$"
# 1290 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1291 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro:: @ 8247470
# 1292 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm BIRD KEEPER {STR_VAR_1}!$"
# 1293 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1294 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1:: @ 8247484
# 1295 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What Pokémon do I have?\n"
# 1296 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1297 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1298 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask:: @ 82474AF
# 1299 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1300 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think we'd make a decent\n"
# 1301 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag team?$"
# 1302 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1303 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept:: @ 82474EC
# 1304 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Great, thanks!\n"
# 1305 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll look after the registration!$"
# 1306 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1307 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject:: @ 824751D
# 1308 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My Pokémon and I are strong.\n"
# 1309 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What a letdown.$"
# 1310 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1311 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro:: @ 824754A
# 1312 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm NINJA BOY {STR_VAR_1}!$"
# 1313 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1314 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1:: @ 824755C
# 1315 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My Pokémon team consists of one\n"
# 1316 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1317 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1318 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask:: @ 824758B
# 1319 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1320 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's be in a tag team together!$"
# 1321 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1322 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept:: @ 82475BC
# 1323 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yay!\n"
# 1324 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me go register!$"
# 1325 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1326 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject:: @ 82475D5
# 1327 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll regret not having my tough\n"
# 1328 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Pokémon on your side!$"
# 1329 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1330 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro:: @ 824760D
# 1331 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 1332 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm PARASOL LADY {STR_VAR_1}!$"
# 1333 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1334 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1:: @ 8247629
# 1335 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Escorting me now are my {STR_VAR_2}\n"
# 1336 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and$"
# 1337 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1338 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask:: @ 8247655
# 1339 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} that uses\n"
# 1340 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 1341 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aren't they nice?\n"
# 1342 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Care to join us in a tag team?$"
# 1343 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1344 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept:: @ 824769B
# 1345 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thanks a bunch!\p"
# 1346 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register at the counter.\n"
# 1347 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's not disappoint each other!$"
# 1348 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1349 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject:: @ 82476ED
# 1350 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My Pokémon are tremendously strong.\n"
# 1351 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How disappointing…$"
# 1352 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1353 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro:: @ 8247724
# 1354 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello.\n"
# 1355 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a BUG MANIAC!$"
# 1356 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1357 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1:: @ 8247749
# 1358 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I have found my Pokémon, yes.\n"
# 1359 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1360 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1361 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask:: @ 824777A
# 1362 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1363 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they are what I found.\p"
# 1364 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Could I interest you in forming\n"
# 1365 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 1366 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1367 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept:: @ 82477CE
# 1368 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Okay!\n"
# 1369 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Understood!\p"
# 1370 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I won't be long with the registration!$"
# 1371 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1372 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject:: @ 8247807
# 1373 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "With the Pokémon I found, we wouldn't\n"
# 1374 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "have lost…$"
# 1375 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1376 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro:: @ 8247838
# 1377 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ahoy, there!\n"
# 1378 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm SAILOR {STR_VAR_1}!$"
# 1379 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1380 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1:: @ 8247854
# 1381 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me show you my pride and joy!\n"
# 1382 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1383 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1384 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask:: @ 8247889
# 1385 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1386 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Of course you're not going to turn\n"
# 1387 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "me down. We will team up, right?$"
# 1388 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1389 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept:: @ 82478DD
# 1390 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I didn't expect any less!\n"
# 1391 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register now.$"
# 1392 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1393 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject:: @ 824790D
# 1394 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We would've stormed through\n"
# 1395 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the opposition! Too bad!$"
# 1396 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1397 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro:: @ 8247942
# 1398 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm {STR_VAR_1}.\n"
# 1399 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a COLLECTOR.$"
# 1400 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1401 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1:: @ 824795F
# 1402 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The jewels in my collection are\n"
# 1403 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "my {STR_VAR_2} with {STR_VAR_1} and$"
# 1404 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1405 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask:: @ 8247991
# 1406 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1407 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Swell, huh?\n"
# 1408 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We should be in a team together.$"
# 1409 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1410 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept:: @ 82479CE
# 1411 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Oh, yeah!\p"
# 1412 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, let's not waste any time.\n"
# 1413 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go register the two of us.$"
# 1414 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1415 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject:: @ 8247A18
# 1416 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, that's upsetting.\n"
# 1417 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You don't appreciate my Pokémon.$"
# 1418 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1419 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro:: @ 8247A51
# 1420 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Howdy, I'm {STR_VAR_1}.\n"
# 1421 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a Pokémon RANGER.$"
# 1422 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1423 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1:: @ 8247A76
# 1424 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Keeping me company are one\n"
# 1425 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1426 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1427 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask:: @ 8247AA1
# 1428 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1429 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think we'd make an impressive\n"
# 1430 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "tag team?$"
# 1431 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1432 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept:: @ 8247AE3
# 1433 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's super!\n"
# 1434 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll deal with the registration now.$"
# 1435 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1436 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject:: @ 8247B16
# 1437 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Next time, choose my Pokémon,\n"
# 1438 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "will you?$"
# 1439 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1440 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro:: @ 8247B3E
# 1441 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My name's {STR_VAR_1}.\n"
# 1442 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a Pokémon RANGER!$"
# 1443 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1444 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1:: @ 8247B62
# 1445 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let me tell you about my team. I have\n"
# 1446 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1447 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1448 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask:: @ 8247B9B
# 1449 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1450 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How would you like to form a tag team\n"
# 1451 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with my little posse?$"
# 1452 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1453 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept:: @ 8247BE7
# 1454 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll be at our best!\n"
# 1455 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get the registration done quick!$"
# 1456 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1457 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject:: @ 8247C23
# 1458 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope you'll choose my Pokémon\n"
# 1459 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "next time.$"
# 1460 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1461 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro:: @ 8247C4E
# 1462 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Pleased to meet you. I'm {STR_VAR_1}.\n"
# 1463 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I consider myself an AROMA LADY.$"
# 1464 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1465 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1:: @ 8247C8C
# 1466 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I travel with one {STR_VAR_2}\n"
# 1467 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that uses {STR_VAR_1} and$"
# 1468 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1469 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask:: @ 8247CB2
# 1470 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} that uses\n"
# 1471 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}.\p"
# 1472 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope they strike your fancy.\n"
# 1473 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you care to be my partner?$"
# 1474 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1475 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept:: @ 8247D07
# 1476 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm honored by your acceptance.\n"
# 1477 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will go register right this instant.$"
# 1478 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1479 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject:: @ 8247D4E
# 1480 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be wonderful if we could form\n"
# 1481 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team the next time we meet.$"
# 1482 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1483 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro:: @ 8247D97
# 1484 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to know who I am?\n"
# 1485 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, the RUIN MANIAC!$"
# 1486 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1487 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1:: @ 8247DC7
# 1488 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The Pokémon that I have with me are\n"
# 1489 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1490 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1491 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask:: @ 8247DFE
# 1492 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1493 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Intriguing, eh?\n"
# 1494 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about you and I partner up?$"
# 1495 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1496 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept:: @ 8247E3E
# 1497 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's a sound decision!\n"
# 1498 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration paperwork.$"
# 1499 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1500 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject:: @ 8247E7E
# 1501 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hmm…\n"
# 1502 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I think my Pokémon are tough…$"
# 1503 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1504 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro:: @ 8247EA1
# 1505 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm COOLTRAINER {STR_VAR_1}!$"
# 1506 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1507 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1:: @ 8247EB5
# 1508 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The Pokémon I have right now are one\n"
# 1509 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1510 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1511 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask:: @ 8247EE9
# 1512 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\n"
# 1513 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cool, huh?\p"
# 1514 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Don't you think it'd be pretty cool\n"
# 1515 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "if we made a tag team?$"
# 1516 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1517 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept:: @ 8247F3F
# 1518 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Cool!\n"
# 1519 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go do the registration in a flash!$"
# 1520 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1521 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject:: @ 8247F6D
# 1522 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I thought that we'd make just\n"
# 1523 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the greatest team ever.$"
# 1524 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1525 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro:: @ 8247FA3
# 1526 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm COOLTRAINER {STR_VAR_1}!$"
# 1527 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1528 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1:: @ 8247FB7
# 1529 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The team I've been raising has one\n"
# 1530 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} with {STR_VAR_1} and$"
# 1531 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1532 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask:: @ 8247FE9
# 1533 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1534 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Does that sound okay?\n"
# 1535 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about we become tag partners?$"
# 1536 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1537 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept:: @ 8248031
# 1538 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sounds A-OK!\n"
# 1539 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'd better do the registration.$"
# 1540 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1541 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject:: @ 824805E
# 1542 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I was thinking how we would be\n"
# 1543 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one tough team…$"
# 1544 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1545 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro:: @ 824808D
# 1546 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Heyo!\n"
# 1547 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, the POKéMANIAC!$"
# 1548 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1549 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1:: @ 82480AB
# 1550 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What does a guy like me have?\n"
# 1551 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1552 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1553 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask:: @ 82480DC
# 1554 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1},\n"
# 1555 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that's what!\p"
# 1556 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Let's do it!\n"
# 1557 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'll stomp around as a tag team!$"
# 1558 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1559 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept:: @ 8248128
# 1560 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Good call!\n"
# 1561 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register the both of us!$"
# 1562 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1563 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject:: @ 8248151
# 1564 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My Pokémon are brutal!\n"
# 1565 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It's not my fault if you regret this!$"
# 1566 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1567 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro:: @ 824818E
# 1568 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yo, there!\n"
# 1569 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm KINDLER {STR_VAR_1}!$"
# 1570 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1571 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1:: @ 82481A9
# 1572 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You know what my training cooked up?\n"
# 1573 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1574 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1575 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask:: @ 82481E1
# 1576 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1577 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Well, what do you say?\n"
# 1578 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Want to form a tag team?$"
# 1579 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1580 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept:: @ 8248221
# 1581 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All right!\n"
# 1582 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get on with the registration.$"
# 1583 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1584 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject:: @ 824824F
# 1585 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Promise you'll partner up with me\n"
# 1586 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "the next time we run into each other.$"
# 1587 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1588 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro:: @ 8248297
# 1589 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a CAMPER!$"
# 1590 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1591 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1:: @ 82482B1
# 1592 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I've been raising one {STR_VAR_1}-\n"
# 1593 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "using {STR_VAR_2} and one$"
# 1594 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1595 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask:: @ 82482DC
# 1596 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2}.\p"
# 1597 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Do you think it'd be fun to team up?\n"
# 1598 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I bet it would be!$"
# 1599 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1600 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept:: @ 8248321
# 1601 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Yeah!\n"
# 1602 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Off I go to register!$"
# 1603 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1604 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject:: @ 824833D
# 1605 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Next time, okay?\n"
# 1606 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I want to be on your team.$"
# 1607 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1608 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro:: @ 8248369
# 1609 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hello!\n"
# 1610 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a PICNICKER!$"
# 1611 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1612 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1:: @ 824838D
# 1613 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The Pokémon I've been taking are\n"
# 1614 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1615 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1616 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask:: @ 82483C1
# 1617 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1618 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Are you interested in joining me\n"
# 1619 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "on a tag team?$"
# 1620 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1621 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept:: @ 8248401
# 1622 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Why, thank you!\n"
# 1623 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I will do the registration now.$"
# 1624 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1625 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject:: @ 8248431
# 1626 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It would be nice if I could join you\n"
# 1627 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "some other time.$"
# 1628 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1629 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro:: @ 8248467
# 1630 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm PSYCHIC {STR_VAR_1}!$"
# 1631 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1632 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1:: @ 8248477
# 1633 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The twosome I've been raising are\n"
# 1634 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1635 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1636 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask:: @ 82484AC
# 1637 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1638 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Would you like to form a tag team\n"
# 1639 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with me?$"
# 1640 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1641 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept:: @ 82484E7
# 1642 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sure thing!\n"
# 1643 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll take care of the registration!$"
# 1644 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1645 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject:: @ 8248517
# 1646 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, that's when I'd like\n"
# 1647 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to team up with you.$"
# 1648 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1649 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro:: @ 8248553
# 1650 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}.\n"
# 1651 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a PSYCHIC.$"
# 1652 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1653 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1:: @ 824856A
# 1654 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1655 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1656 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask:: @ 824857D
# 1657 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}--\n"
# 1658 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "they're my disciples.\p"
# 1659 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Doesn't the idea of forming a tag-team\n"
# 1660 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "partnership intrigue you?$"
# 1661 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1662 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept:: @ 82485E5
# 1663 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you.\n"
# 1664 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll go deal with the registration.$"
# 1665 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1666 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject:: @ 8248614
# 1667 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I hope there will be another chance\n"
# 1668 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to forge an alliance.$"
# 1669 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1670 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro:: @ 824864E
# 1671 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm School Kid {STR_VAR_1}!$"
# 1672 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1673 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1:: @ 8248661
# 1674 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 1675 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1676 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask:: @ 8248671
# 1677 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 1678 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} are my Pokémon pair.\p"
# 1679 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I please be your partner on\n"
# 1680 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team?$"
# 1681 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1682 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept:: @ 82486C6
# 1683 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Ooh, thank you!\n"
# 1684 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register at the counter right away!$"
# 1685 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1686 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject:: @ 82486FF
# 1687 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Please?\n"
# 1688 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "May I join you the next time?$"
# 1689 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1690 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro:: @ 8248725
# 1691 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hiya! The name's {STR_VAR_1}!\n"
# 1692 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm a Pokémon BREEDER!$"
# 1693 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1694 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1:: @ 8248751
# 1695 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The Pokémon I've raised are one\n"
# 1696 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_1}-using {STR_VAR_2} and$"
# 1697 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1698 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask:: @ 8248781
# 1699 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\p"
# 1700 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sound interesting?\n"
# 1701 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "How about we form a tag team, then?$"
# 1702 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1703 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept:: @ 82487C9
# 1704 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "All righty!\n"
# 1705 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You leave the registration to me!$"
# 1706 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1707 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject:: @ 82487F7
# 1708 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You have to team up with me next time,\n"
# 1709 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "all right?$"
# 1710 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1711 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro:: @ 8248829
# 1712 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm proud to say\n"
# 1713 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "that I am a POKéFAN.$"
# 1714 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1715 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1:: @ 824885B
# 1716 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "The darling Pokémon I've raised are\n"
# 1717 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1} and$"
# 1718 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1719 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask:: @ 8248892
# 1720 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}.\p"
# 1721 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Aren't they just the cutest?\n"
# 1722 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We ought to make a team!$"
# 1723 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1724 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept:: @ 82488D8
# 1725 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Thank you, dear!\n"
# 1726 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll be on my way to register!$"
# 1727 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1728 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject:: @ 8248908
# 1729 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "My darling Pokémon are the best,\n"
# 1730 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll have you know. How annoying!$"
# 1731 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1732 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro:: @ 824894B
# 1733 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, I'm SWIMMER {STR_VAR_1}.$"
# 1734 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1735 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1:: @ 824895F
# 1736 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"
# 1737 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1738 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask:: @ 824896F
# 1739 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "and one {STR_VAR_1}-using\n"
# 1740 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "{STR_VAR_2} are what I've trained.\p"
# 1741 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You and me, let's make a tag team.$"
# 1742 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1743 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept:: @ 82489BD
# 1744 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "That's cool!\n"
# 1745 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll register the two of us.$"
# 1746 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1747 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject:: @ 82489E7
# 1748 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, you owe me\n"
# 1749 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a tag team!$"
# 1750 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1751 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro:: @ 8248A10
# 1752 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What's happening?\n"
# 1753 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a TRIATHLETE.$"
# 1754 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1755 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1:: @ 8248A40
# 1756 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I got a couple decent Pokémon.\n"
# 1757 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1758 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1759 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask:: @ 8248A72
# 1760 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1761 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It'd be neat if we made a tag team\n"
# 1762 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "together, so how about it?$"
# 1763 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1764 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept:: @ 8248AC0
# 1765 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Right on!\n"
# 1766 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You wait while I register, okay?$"
# 1767 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1768 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject:: @ 8248AEB
# 1769 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I expect you'll let me join you\n"
# 1770 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "next time, how's that?$"
# 1771 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1772 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro:: @ 8248B22
# 1773 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm the TRIATHLETE {STR_VAR_1}!$"
# 1774 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1775 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1:: @ 8248B39
# 1776 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1777 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1778 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask:: @ 8248B4C
# 1779 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "another {STR_VAR_2} that knows how\n"
# 1780 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "to use {STR_VAR_1}. That's my pair.\p"
# 1781 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "What do you think?\n"
# 1782 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "We'd make a good team, I'd say.$"
# 1783 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1784 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept:: @ 8248BB4
# 1785 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I like that answer!\n"
# 1786 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get done with registration fast!$"
# 1787 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1788 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject:: @ 8248BEE
# 1789 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "You'll give me another chance to form\n"
# 1790 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "a partnership, won't you?$"
# 1791 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1792 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro:: @ 8248C2E
# 1793 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Hi, there! Hello!\n"
# 1794 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'm {STR_VAR_1}, and I'm a SWIMMER!$"
# 1795 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1796 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1:: @ 8248C5B
# 1797 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Check out what I've been raising!\n"
# 1798 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"
# 1799 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1800 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask:: @ 8248C90
# 1801 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "one {STR_VAR_2} with {STR_VAR_1}!\p"
# 1802 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Sweet, huh?\n"
# 1803 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "It'd be sweet to form a team, too!$"
# 1804 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1805 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept:: @ 8248CCF
# 1806 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "Much obliged!\n"
# 1807 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "I'll get this registration thing done!$"
# 1808 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"

# 1809 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject:: @ 8248D04
# 1810 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "If we meet again, you have to team up\n"
# 1811 "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.pory"
	.string "with me. You'll do that, right?$"
