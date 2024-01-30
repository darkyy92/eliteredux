# 1 "data/maps/SlateportCity_Harbor/scripts.pory"

# 2 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_CAPT_STERN, 4
# 3 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_SS_TIDAL, 5
# 4 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_GRUNT, 6
# 5 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_ARCHIE, 7
# 6 "data/maps/SlateportCity_Harbor/scripts.pory"
.set LOCALID_SUBMARINE, 8
# 7 "data/maps/SlateportCity_Harbor/scripts.pory"

# 8 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_MapScripts:: @ 820C97D
# 9 "data/maps/SlateportCity_Harbor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
# 10 "data/maps/SlateportCity_Harbor/scripts.pory"
	.byte 0
# 11 "data/maps/SlateportCity_Harbor/scripts.pory"

# 12 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_OnTransition: @ 820C983
# 13 "data/maps/SlateportCity_Harbor/scripts.pory"
	setescapewarp MAP_SLATEPORT_CITY, 255, 28, 13
# 14 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 0
# 15 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_SLATEPORT_HARBOR_STATE, 1
# 16 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
# 17 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
# 18 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 19 "data/maps/SlateportCity_Harbor/scripts.pory"

# 20 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ShowSSTidal:: @ 820C9A5
# 21 "data/maps/SlateportCity_Harbor/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
# 22 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 23 "data/maps/SlateportCity_Harbor/scripts.pory"

# 24 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene:: @ 820C9A9
# 25 "data/maps/SlateportCity_Harbor/scripts.pory"
	savebgm MUS_ENCOUNTER_AQUA
# 26 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectxyperm LOCALID_CAPT_STERN, 12, 13
# 27 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
# 28 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
# 29 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 30 "data/maps/SlateportCity_Harbor/scripts.pory"

# 31 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger0:: @ 820C9BB
# 32 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 33 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 0
# 34 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 35 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 36 "data/maps/SlateportCity_Harbor/scripts.pory"

# 37 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger1:: @ 820C9C7
# 38 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 39 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 1
# 40 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 41 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 42 "data/maps/SlateportCity_Harbor/scripts.pory"

# 43 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger2:: @ 820C9D3
# 44 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 45 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 2
# 46 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 47 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 48 "data/maps/SlateportCity_Harbor/scripts.pory"

# 49 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger3:: @ 820C9DF
# 50 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 51 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 3
# 52 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
# 53 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 54 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 55 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 56 "data/maps/SlateportCity_Harbor/scripts.pory"

# 57 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeScene:: @ 820C9F5
# 58 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestDown
# 59 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 60 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFastestDown
# 61 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 62 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 63 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
# 64 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 65 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
# 66 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
# 67 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
# 68 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 69 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_GRUNT
# 70 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_ARCHIE
# 71 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SUBMARINE
# 72 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
# 73 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_MET_TEAM_AQUA_HARBOR
# 74 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
# 75 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_0x8008, 0
# 76 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq SlateportCity_Harbor_EventScript_SternApproachPlayer0
# 77 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_0x8008, 1
# 78 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq SlateportCity_Harbor_EventScript_SternApproachPlayer1
# 79 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_0x8008, 2
# 80 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq SlateportCity_Harbor_EventScript_SternApproachPlayer
# 81 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_0x8008, 3
# 82 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq SlateportCity_Harbor_EventScript_SternApproachPlayer
# 83 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 84 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 85 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
# 86 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
# 87 "data/maps/SlateportCity_Harbor/scripts.pory"
	copyobjectxytoperm LOCALID_CAPT_STERN
# 88 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
# 89 "data/maps/SlateportCity_Harbor/scripts.pory"
	releaseall
# 90 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 91 "data/maps/SlateportCity_Harbor/scripts.pory"

# 92 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer0:: @ 820CA89
# 93 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
# 94 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 95 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 96 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 97 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 98 "data/maps/SlateportCity_Harbor/scripts.pory"

# 99 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer1:: @ 820CA9E
# 100 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
# 101 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 102 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 103 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 104 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 105 "data/maps/SlateportCity_Harbor/scripts.pory"

# 106 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer:: @ 820CAB3
# 107 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
# 108 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 109 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 110 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 111 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 112 "data/maps/SlateportCity_Harbor/scripts.pory"

# 113 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_AquaBoardSub: @ 820CAC8
# 114 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 115 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 116 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 117 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 118 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 119 "data/maps/SlateportCity_Harbor/scripts.pory"

# 120 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused, Archie instead shares above identical movement script with Grunt
# 121 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_ArchieBoardSub: @ 820CACD
# 122 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 123 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 124 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 125 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 126 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 127 "data/maps/SlateportCity_Harbor/scripts.pory"

# 128 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SubmarineExit: @ 820CAD2
# 129 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 130 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 131 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 132 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 133 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 134 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 135 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 136 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 137 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 138 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 139 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 140 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 141 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 142 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 143 "data/maps/SlateportCity_Harbor/scripts.pory"

# 144 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer0: @ 820CAE0
# 145 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 146 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 147 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 148 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 149 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 150 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 151 "data/maps/SlateportCity_Harbor/scripts.pory"

# 152 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer1: @ 820CAE6
# 153 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 154 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 155 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 156 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 157 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 158 "data/maps/SlateportCity_Harbor/scripts.pory"

# 159 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer: @ 820CAEB
# 160 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 161 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 162 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 163 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 164 "data/maps/SlateportCity_Harbor/scripts.pory"

# 165 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_PlayerWalkUp: @ 820CAEF
# 166 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 167 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 168 "data/maps/SlateportCity_Harbor/scripts.pory"

# 169 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryAttendant:: @ 820CAF1
# 170 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 171 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 172 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
# 173 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
# 174 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 175 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 176 "data/maps/SlateportCity_Harbor/scripts.pory"

# 177 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskForTicket:: @ 820CB06
# 178 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 179 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
# 180 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 181 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 182 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 183 "data/maps/SlateportCity_Harbor/scripts.pory"

# 184 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestination:: @ 820CB1A
# 185 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
# 186 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
# 187 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 188 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 189 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 190 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 191 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 192 "data/maps/SlateportCity_Harbor/scripts.pory"

# 193 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier:: @ 820CB50
# 194 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
# 195 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 196 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 197 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, LilycoveCity_Harbor_EventScript_GoToBattleFrontierTemp
# 198 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 199 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 200 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 201 "data/maps/SlateportCity_Harbor/scripts.pory"

# 202 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
# 203 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NoTicket:: @ 820CB88
# 204 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
# 205 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 206 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 207 "data/maps/SlateportCity_Harbor/scripts.pory"

# 208 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Lilycove:: @ 820CB92
# 209 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
# 210 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_RESULT, NO
# 211 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseNewDestination
# 212 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
# 213 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 214 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 255, 1, 10
# 215 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 216 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 217 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 218 "data/maps/SlateportCity_Harbor/scripts.pory"

# 219 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BattleFrontier:: @ 820CBBA
# 220 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 221 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_RESULT, NO
# 222 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq SlateportCity_Harbor_EventScript_ChooseNewDestination
# 223 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 224 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
# 225 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 226 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 227 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 228 "data/maps/SlateportCity_Harbor/scripts.pory"

# 229 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseNewDestination:: @ 820CBDD
# 230 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
# 231 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 232 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 233 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 234 "data/maps/SlateportCity_Harbor/scripts.pory"

# 235 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerry:: @ 820CBE9
# 236 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 237 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 238 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestUp
# 239 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 240 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 241 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
# 242 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 243 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq SlateportCity_Harbor_EventScript_BoardFerryNorth
# 244 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 245 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq SlateportCity_Harbor_EventScript_BoardFerryEast
# 246 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 247 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 248 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 249 "data/maps/SlateportCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 250 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 251 "data/maps/SlateportCity_Harbor/scripts.pory"

# 252 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CancelDestinationSelect:: @ 820CC2D
# 253 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 254 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 255 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 256 "data/maps/SlateportCity_Harbor/scripts.pory"

# 257 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryEast:: @ 820CC37
# 258 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
# 259 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 260 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 261 "data/maps/SlateportCity_Harbor/scripts.pory"

# 262 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryNorth:: @ 820CC42
# 263 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
# 264 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 265 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 266 "data/maps/SlateportCity_Harbor/scripts.pory"

# 267 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryEast: @ 820CC4D
# 268 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 269 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_in_place_fastest_up
# 270 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 271 "data/maps/SlateportCity_Harbor/scripts.pory"

# 272 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryNorth: @ 820CC50
# 273 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 274 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 275 "data/maps/SlateportCity_Harbor/scripts.pory"

# 276 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Sailor:: @ 820CC52
# 277 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 278 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 279 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
# 280 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 0
# 281 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 282 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 283 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_0x8004, 2  @ Defeated both
# 284 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
# 285 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
# 286 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 287 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 288 "data/maps/SlateportCity_Harbor/scripts.pory"

# 289 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather:: @ 820CC89
# 290 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
# 291 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 292 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 293 "data/maps/SlateportCity_Harbor/scripts.pory"

# 294 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CountDefeatedLegendary:: @ 820CC93
# 295 "data/maps/SlateportCity_Harbor/scripts.pory"
	addvar VAR_0x8004, 1
# 296 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 297 "data/maps/SlateportCity_Harbor/scripts.pory"

# 298 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FatMan:: @ 820CC99
# 299 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
# 300 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 301 "data/maps/SlateportCity_Harbor/scripts.pory"

# 302 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptStern:: @ 820CCA2
# 303 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 304 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 305 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
# 306 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
# 307 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
# 308 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_SLATEPORT_HARBOR_STATE, 2
# 309 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq SlateportCity_Harbor_EventScript_WhyStealSubmarine
# 310 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
# 311 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 312 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 313 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 314 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 315 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 316 "data/maps/SlateportCity_Harbor/scripts.pory"

# 317 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_WhyStealSubmarine:: @ 820CCDF
# 318 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 319 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 320 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 321 "data/maps/SlateportCity_Harbor/scripts.pory"

# 322 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive:: @ 820CCE9
# 323 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
# 324 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
# 325 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 326 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 327 "data/maps/SlateportCity_Harbor/scripts.pory"

# 328 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NeedDive:: @ 820CCF6
# 329 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
# 330 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 331 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 332 "data/maps/SlateportCity_Harbor/scripts.pory"

# 333 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment:: @ 820CD00
# 334 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_TEMP_1, 1
# 335 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq SlateportCity_Harbor_EventScript_TradedScanner
# 336 "data/maps/SlateportCity_Harbor/scripts.pory"
	checkitem ITEM_SCANNER, 1
# 337 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_RESULT, TRUE
# 338 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq SlateportCity_Harbor_EventScript_AskToTradeScanner
# 339 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
# 340 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
# 341 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 342 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 343 "data/maps/SlateportCity_Harbor/scripts.pory"

# 344 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryFinished:: @ 820CD2E
# 345 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
# 346 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 347 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 348 "data/maps/SlateportCity_Harbor/scripts.pory"

# 349 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskToTradeScanner:: @ 820CD38
# 350 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_WouldYouTradeScanner, MSGBOX_YESNO
# 351 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_RESULT, NO
# 352 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq SlateportCity_Harbor_EventScript_DeclineTrade
# 353 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_BOTTLE_CAP, 12
# 354 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_RESULT, FALSE
# 355 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 356 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 357 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 358 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 359 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 360 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 361 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 362 "data/maps/SlateportCity_Harbor/scripts.pory"

# 363 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeclineTrade:: @ 820CDFB
# 364 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
# 365 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 366 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 367 "data/maps/SlateportCity_Harbor/scripts.pory"

# 368 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TradedScanner:: @ 820CE11
# 369 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 370 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
# 371 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 372 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 373 "data/maps/SlateportCity_Harbor/scripts.pory"

# 374 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FerryServiceUnavailable: @ 820CE20
# 375 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I beg your pardon?\n"
# 376 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're looking for a ship?\p"
# 377 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
# 378 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "available at present…$"
# 379 "data/maps/SlateportCity_Harbor/scripts.pory"

# 380 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_MayISeeYourTicket: @ 820CE87
# 381 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 382 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "May I see your Ticket?$"
# 383 "data/maps/SlateportCity_Harbor/scripts.pory"

# 384 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_YouMustHaveTicket: @ 820CEC1
# 385 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} doesn't have the Ticket…\p"
# 386 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm terribly sorry.\p"
# 387 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You must have a Ticket to board\n"
# 388 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ferry.$"
# 389 "data/maps/SlateportCity_Harbor/scripts.pory"

# 390 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FlashedTicketWhereTo: @ 820CF1C
# 391 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} flashed the Ticket.\p"
# 392 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 393 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "And where would you like to go?$"
# 394 "data/maps/SlateportCity_Harbor/scripts.pory"

# 395 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SailAnotherTime: @ 820CF71
# 396 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please sail with us another time!$"
# 397 "data/maps/SlateportCity_Harbor/scripts.pory"

# 398 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LilycoveItIs: @ 820CF93
# 399 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Lilycove City it is, then!$"
# 400 "data/maps/SlateportCity_Harbor/scripts.pory"

# 401 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_BattleFrontierItIs: @ 820CFAE
# 402 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Battle Frontier it is, then!$"
# 403 "data/maps/SlateportCity_Harbor/scripts.pory"

# 404 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_PleaseBoardFerry: @ 820CFCB
# 405 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 406 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "departure.$"
# 407 "data/maps/SlateportCity_Harbor/scripts.pory"

# 408 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhereWouldYouLikeToGo: @ 820CFFA
# 409 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Then, where would you like to go?$"
# 410 "data/maps/SlateportCity_Harbor/scripts.pory"

# 411 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday: @ 820D01C
# 412 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A journey to the bottom of the sea…\n"
# 413 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wonder what it'd be like?\p"
# 414 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'd love to go deep underwater like\n"
# 415 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that someday.$"
# 416 "data/maps/SlateportCity_Harbor/scripts.pory"

# 417 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_AbnormalWeather: @ 820D08E
# 418 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "For a ship to sail safely, we need to\n"
# 419 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "know about the weather!\p"
# 420 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Speaking of weather, I heard something\n"
# 421 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "from a guy at the Weather Institute.\p"
# 422 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "He was saying abnormal weather has\n"
# 423 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "been reported all over the place!\p"
# 424 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You should visit the Weather Institute\n"
# 425 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "and ask around!$"
# 426 "data/maps/SlateportCity_Harbor/scripts.pory"

# 427 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SubTooSmallForMe: @ 820D194
# 428 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wanted to go with Capt. Stern on\n"
# 429 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ocean floor exploration.\p"
# 430 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But the sub's too small for me.\p"
# 431 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "If I squeezed in, there wouldn't be\n"
# 432 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "any room for the Captain…$"
# 433 "data/maps/SlateportCity_Harbor/scripts.pory"

# 434 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum: @ 820D232
# 435 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Those thugs…\p"
# 436 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They're the same lot who tried to rob\n"
# 437 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the Devon Parts at the Museum.$"
# 438 "data/maps/SlateportCity_Harbor/scripts.pory"

# 439 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove: @ 820D291
# 440 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Archie: Oh?\n"
# 441 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Not you again…\p"
# 442 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You are tenacious to track us here,\n"
# 443 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that much I will give you.\p"
# 444 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But now…\n"
# 445 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "No one can stop us! No one!\p"
# 446 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Or, will you follow us back to our\n"
# 447 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Hideout in Lilycove City?\p"
# 448 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Fwahahahaha…$"
# 449 "data/maps/SlateportCity_Harbor/scripts.pory"

# 450 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine: @ 820D35A
# 451 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Why…\p"
# 452 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Why would Team Aqua steal my\n"
# 453 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Submarine Explorer 1?\p"
# 454 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They can't be after the slumbering\n"
# 455 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Pokémon at the bottom of the sea…\p"
# 456 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But even if I were to chase them,\n"
# 457 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I don't stand a chance against them…$"
# 458 "data/maps/SlateportCity_Harbor/scripts.pory"

# 459 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TeamAquaLeftNeedDive: @ 820D42B
# 460 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Oh, {PLAYER}{KUN}…\p"
# 461 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Okay… So Team Aqua left before you\n"
# 462 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "could stop them…\p"
# 463 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Oh, no, don't blame yourself.\n"
# 464 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're not responsible for this.\p"
# 465 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Trying to catch a submarine…\n"
# 466 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's impossible for most people.\p"
# 467 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a Pokémon that knows\n"
# 468 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to Dive…\p"
# 469 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 470 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Mossdeep City…\p"
# 471 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 472 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might teach you…$"
# 473 "data/maps/SlateportCity_Harbor/scripts.pory"

# 474 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_NeedDiveToCatchSub: @ 820D58A
# 475 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Trying to catch a\n"
# 476 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "submarine… It's impossible.\p"
# 477 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a Pokémon that knows\n"
# 478 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to Dive…\p"
# 479 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 480 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Mossdeep City…\p"
# 481 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 482 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might teach you…$"
# 483 "data/maps/SlateportCity_Harbor/scripts.pory"

# 484 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry: @ 820D65C
# 485 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Oh, yes.\n"
# 486 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Mr. Briney came to our Shipyard.\p"
# 487 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It won't be long now before we finish\n"
# 488 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "making the ferry!$"
# 489 "data/maps/SlateportCity_Harbor/scripts.pory"

# 490 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FinishedMakingFerry: @ 820D6CB
# 491 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: {PLAYER}{KUN}!\p"
# 492 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We finally finished making the ferry\n"
# 493 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "S.S. Tidal!\p"
# 494 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We couldn't have done it without\n"
# 495 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your friend Mr. Briney.\p"
# 496 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please go for a short cruise on it!$"
# 497 "data/maps/SlateportCity_Harbor/scripts.pory"

# 498 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WouldYouTradeScanner: @ 820D76C
# 499 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Oh?\n"
# 500 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, that item you have…\p"
# 501 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "That's a Scanner! That would sure\n"
# 502 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "help us on our explorations.\p"
# 503 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, would you trade your\n"
# 504 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Scanner for something?\p"
# 505 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Like, say, these twelve Bottle Caps\n"
# 506 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that I have?$"
# 507 "data/maps/SlateportCity_Harbor/scripts.pory"

# 508 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow: @ 820D841
# 509 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Are you certain?\n"
# 510 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's useless to you, {PLAYER}{KUN}…\p"
# 511 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Well, okay, then. If you want to trade\n"
# 512 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your Scanner, let me know.$"
# 513 "data/maps/SlateportCity_Harbor/scripts.pory"

# 514 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_HandedScannerToStern: @ 820D94A
# 515 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} handed the Scanner to\n"
# 516 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern.$"
# 517 "data/maps/SlateportCity_Harbor/scripts.pory"

# 518 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ThisWillHelpResearch: @ 820D970
# 519 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Thanks, {PLAYER}{KUN}!\n"
# 520 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "This will help our research a lot!$"
