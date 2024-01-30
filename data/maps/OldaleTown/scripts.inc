# 1 "data/maps/OldaleTown/scripts.pory"

# 2 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_MART_EMPLOYEE, 2
# 3 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_FOOTPRINTS_MAN, 3
# 4 "data/maps/OldaleTown/scripts.pory"
.set LOCALID_RIVAL, 4
# 5 "data/maps/OldaleTown/scripts.pory"

# 6 "data/maps/OldaleTown/scripts.pory"
OldaleTown_MapScripts:: @ 81E8EA2
# 7 "data/maps/OldaleTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
# 8 "data/maps/OldaleTown/scripts.pory"
	.byte 0
# 9 "data/maps/OldaleTown/scripts.pory"

# 10 "data/maps/OldaleTown/scripts.pory"
OldaleTown_OnTransition: @ 81E8EA8
# 11 "data/maps/OldaleTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 12 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_VISITED_OLDALE_TOWN
# 13 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
# 14 "data/maps/OldaleTown/scripts.pory"
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
# 15 "data/maps/OldaleTown/scripts.pory"
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
# 16 "data/maps/OldaleTown/scripts.pory"
	end
# 17 "data/maps/OldaleTown/scripts.pory"

# 18 "data/maps/OldaleTown/scripts.pory"
@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
# 19 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_SetOldaleState:: @ 81E8ECC
# 20 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 21 "data/maps/OldaleTown/scripts.pory"
	return
# 22 "data/maps/OldaleTown/scripts.pory"

# 23 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockWestEntrance:: @ 81E8ED2
# 24 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
# 25 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
# 26 "data/maps/OldaleTown/scripts.pory"
	return
# 27 "data/maps/OldaleTown/scripts.pory"

# 28 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MoveMartEmployee:: @ 81E8EDE
# 29 "data/maps/OldaleTown/scripts.pory"
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
# 30 "data/maps/OldaleTown/scripts.pory"
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
# 31 "data/maps/OldaleTown/scripts.pory"
	return
# 32 "data/maps/OldaleTown/scripts.pory"

# 33 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_CitySign:: @ 81E8EEA
# 34 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_CitySign, MSGBOX_SIGN
# 35 "data/maps/OldaleTown/scripts.pory"
	end
# 36 "data/maps/OldaleTown/scripts.pory"

# 37 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Girl:: @ 81E8EF3
# 38 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
# 39 "data/maps/OldaleTown/scripts.pory"
	end
# 40 "data/maps/OldaleTown/scripts.pory"

# 41 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_MartEmployee:: @ 81E8EFC
# 42 "data/maps/OldaleTown/scripts.pory"
	lock
# 43 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 44 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
# 45 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
# 46 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_TEMP_1
# 47 "data/maps/OldaleTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, FALSE
# 48 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
# 49 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 50 "data/maps/OldaleTown/scripts.pory"
	switch VAR_FACING
# 51 "data/maps/OldaleTown/scripts.pory"
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
# 52 "data/maps/OldaleTown/scripts.pory"
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
# 53 "data/maps/OldaleTown/scripts.pory"
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
# 54 "data/maps/OldaleTown/scripts.pory"
	end
# 55 "data/maps/OldaleTown/scripts.pory"

# 56 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartSouth:: @ 81E8F47
# 57 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
# 58 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
# 59 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 60 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 61 "data/maps/OldaleTown/scripts.pory"
	end
# 62 "data/maps/OldaleTown/scripts.pory"

# 63 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartNorth:: @ 81E8F5E
# 64 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
# 65 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
# 66 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 67 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 68 "data/maps/OldaleTown/scripts.pory"
	end
# 69 "data/maps/OldaleTown/scripts.pory"

# 70 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_GoToMartEast:: @ 81E8F75
# 71 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
# 72 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
# 73 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 74 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ExplainPokemonMart
# 75 "data/maps/OldaleTown/scripts.pory"
	end
# 76 "data/maps/OldaleTown/scripts.pory"

# 77 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPokemonMart:: @ 81E8F8C
# 78 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
# 79 "data/maps/OldaleTown/scripts.pory"
	giveitem ITEM_FOCUS_SASH
# 80 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, FALSE
# 81 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq OldaleTown_EventScript_BagIsFull
# 82 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 83 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_RECEIVED_POTION_OLDALE
# 84 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 85 "data/maps/OldaleTown/scripts.pory"
	release
# 86 "data/maps/OldaleTown/scripts.pory"
	end
# 87 "data/maps/OldaleTown/scripts.pory"

# 88 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ExplainPotion:: @ 81E8FB9
# 89 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
# 90 "data/maps/OldaleTown/scripts.pory"
	release
# 91 "data/maps/OldaleTown/scripts.pory"
	end
# 92 "data/maps/OldaleTown/scripts.pory"

# 93 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BagIsFull:: @ 81E8FC3
# 94 "data/maps/OldaleTown/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 95 "data/maps/OldaleTown/scripts.pory"
	fadedefaultbgm
# 96 "data/maps/OldaleTown/scripts.pory"
	release
# 97 "data/maps/OldaleTown/scripts.pory"
	end
# 98 "data/maps/OldaleTown/scripts.pory"

# 99 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeEast: @ 81E8FCE
# 100 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 101 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 102 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 103 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 104 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 105 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 106 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 107 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_fastest_down
# 108 "data/maps/OldaleTown/scripts.pory"
	step_end
# 109 "data/maps/OldaleTown/scripts.pory"

# 110 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeSouth: @ 81E8FD7
# 111 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 112 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 113 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 114 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 115 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 116 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 117 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 118 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 119 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 120 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_fastest_down
# 121 "data/maps/OldaleTown/scripts.pory"
	step_end
# 122 "data/maps/OldaleTown/scripts.pory"

# 123 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_EmployeeNorth: @ 81E8FE2
# 124 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 125 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 126 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 127 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 128 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 129 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 130 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 131 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_fastest_down
# 132 "data/maps/OldaleTown/scripts.pory"
	step_end
# 133 "data/maps/OldaleTown/scripts.pory"

# 134 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown1: @ 81E8FEB
# 135 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 136 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 137 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 138 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 139 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 140 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 141 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 142 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 143 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 144 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 145 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 146 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 147 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_fastest_down
# 148 "data/maps/OldaleTown/scripts.pory"
	step_end
# 149 "data/maps/OldaleTown/scripts.pory"

# 150 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerEast: @ 81E8FF9
# 151 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 152 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 153 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 154 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 155 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 156 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 157 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 158 "data/maps/OldaleTown/scripts.pory"
	step_end
# 159 "data/maps/OldaleTown/scripts.pory"

# 160 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerSouth: @ 81E9001
# 161 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 162 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 163 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 164 "data/maps/OldaleTown/scripts.pory"
	delay_16
# 165 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 166 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 167 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 168 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 169 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 170 "data/maps/OldaleTown/scripts.pory"
	step_end
# 171 "data/maps/OldaleTown/scripts.pory"

# 172 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerNorth: @ 81E900B
# 173 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 174 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 175 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 176 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 177 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 178 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 179 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 180 "data/maps/OldaleTown/scripts.pory"
	step_end
# 181 "data/maps/OldaleTown/scripts.pory"

# 182 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_Unknown2: @ 81E9013
# 183 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 184 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 185 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 186 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 187 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 188 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 189 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 190 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 191 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 192 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 193 "data/maps/OldaleTown/scripts.pory"
	walk_up
# 194 "data/maps/OldaleTown/scripts.pory"
	step_end
# 195 "data/maps/OldaleTown/scripts.pory"

# 196 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_FootprintsMan:: @ 81E901F
# 197 "data/maps/OldaleTown/scripts.pory"
	lock
# 198 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 199 "data/maps/OldaleTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
# 200 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
# 201 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 202 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
# 203 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 204 "data/maps/OldaleTown/scripts.pory"
	release
# 205 "data/maps/OldaleTown/scripts.pory"
	end
# 206 "data/maps/OldaleTown/scripts.pory"

# 207 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_BlockedPath:: @ 81E903F
# 208 "data/maps/OldaleTown/scripts.pory"
	lockall
# 209 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
# 210 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
# 211 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 212 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
# 213 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 214 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
# 215 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 216 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 217 "data/maps/OldaleTown/scripts.pory"
	end
# 218 "data/maps/OldaleTown/scripts.pory"

# 219 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_NotBlockingPath:: @ 81E9066
# 220 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
# 221 "data/maps/OldaleTown/scripts.pory"
	release
# 222 "data/maps/OldaleTown/scripts.pory"
	end
# 223 "data/maps/OldaleTown/scripts.pory"

# 224 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_Rival:: @ 81E9070
# 225 "data/maps/OldaleTown/scripts.pory"
	lockall
# 226 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 227 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 228 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 0
# 229 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 230 "data/maps/OldaleTown/scripts.pory"
	end
# 231 "data/maps/OldaleTown/scripts.pory"

# 232 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger1:: @ 81E9086
# 233 "data/maps/OldaleTown/scripts.pory"
	lockall
# 234 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
# 235 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 236 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 237 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 238 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 239 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 240 "data/maps/OldaleTown/scripts.pory"
	end
# 241 "data/maps/OldaleTown/scripts.pory"

# 242 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger2:: @ 81E90A6
# 243 "data/maps/OldaleTown/scripts.pory"
	lockall
# 244 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
# 245 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 246 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 247 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 248 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 249 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 250 "data/maps/OldaleTown/scripts.pory"
	end
# 251 "data/maps/OldaleTown/scripts.pory"

# 252 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalTrigger3:: @ 81E90C6
# 253 "data/maps/OldaleTown/scripts.pory"
	lockall
# 254 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
# 255 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 256 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 257 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 258 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_0x8009, 1
# 259 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_ShowRivalMessage
# 260 "data/maps/OldaleTown/scripts.pory"
	end
# 261 "data/maps/OldaleTown/scripts.pory"

# 262 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowRivalMessage:: @ 81E90E6
# 263 "data/maps/OldaleTown/scripts.pory"
	checkplayergender
# 264 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, MALE
# 265 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq OldaleTown_EventScript_ShowMayMessage
# 266 "data/maps/OldaleTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 267 "data/maps/OldaleTown/scripts.pory"
	goto_if_eq OldaleTown_EventScript_ShowBrendanMessage
# 268 "data/maps/OldaleTown/scripts.pory"
	end
# 269 "data/maps/OldaleTown/scripts.pory"

# 270 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowMayMessage:: @ 81E90FE
# 271 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
# 272 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 273 "data/maps/OldaleTown/scripts.pory"
	end
# 274 "data/maps/OldaleTown/scripts.pory"

# 275 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_ShowBrendanMessage:: @ 81E910C
# 276 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
# 277 "data/maps/OldaleTown/scripts.pory"
	goto OldaleTown_EventScript_RivalFinish
# 278 "data/maps/OldaleTown/scripts.pory"
	end
# 279 "data/maps/OldaleTown/scripts.pory"

# 280 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_RivalFinish:: @ 81E911A
# 281 "data/maps/OldaleTown/scripts.pory"
	closemessage
# 282 "data/maps/OldaleTown/scripts.pory"
	compare VAR_0x8009, 0
# 283 "data/maps/OldaleTown/scripts.pory"
	call_if_eq OldaleTown_EventScript_DoExitMovement1
# 284 "data/maps/OldaleTown/scripts.pory"
	compare VAR_0x8009, 1
# 285 "data/maps/OldaleTown/scripts.pory"
	call_if_eq OldaleTown_EventScript_DoExitMovement2
# 286 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 287 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 288 "data/maps/OldaleTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 289 "data/maps/OldaleTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 290 "data/maps/OldaleTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 291 "data/maps/OldaleTown/scripts.pory"
	releaseall
# 292 "data/maps/OldaleTown/scripts.pory"
	end
# 293 "data/maps/OldaleTown/scripts.pory"

# 294 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement1:: @ 81E9148
# 295 "data/maps/OldaleTown/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 296 "data/maps/OldaleTown/scripts.pory"
	goto_if_ne OldaleTown_EventScript_DoExitMovement2
# 297 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 298 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 299 "data/maps/OldaleTown/scripts.pory"
	return
# 300 "data/maps/OldaleTown/scripts.pory"

# 301 "data/maps/OldaleTown/scripts.pory"
OldaleTown_EventScript_DoExitMovement2:: @ 81E915E
# 302 "data/maps/OldaleTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
# 303 "data/maps/OldaleTown/scripts.pory"
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
# 304 "data/maps/OldaleTown/scripts.pory"
	waitmovement 0
# 305 "data/maps/OldaleTown/scripts.pory"
	return
# 306 "data/maps/OldaleTown/scripts.pory"

# 307 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer1: @ 81E9170
# 308 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 309 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 310 "data/maps/OldaleTown/scripts.pory"
	step_end
# 311 "data/maps/OldaleTown/scripts.pory"

# 312 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer2: @ 81E9173
# 313 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 314 "data/maps/OldaleTown/scripts.pory"
	step_end
# 315 "data/maps/OldaleTown/scripts.pory"

# 316 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalApproachPlayer3: @ 81E9175
# 317 "data/maps/OldaleTown/scripts.pory"
	face_left
# 318 "data/maps/OldaleTown/scripts.pory"
	step_end
# 319 "data/maps/OldaleTown/scripts.pory"

# 320 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_RivalExit: @ 81E9177
# 321 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 322 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 323 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 324 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 325 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 326 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 327 "data/maps/OldaleTown/scripts.pory"
	step_end
# 328 "data/maps/OldaleTown/scripts.pory"

# 329 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_WatchRivalExit: @ 81E917E
# 330 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 331 "data/maps/OldaleTown/scripts.pory"
	delay_4
# 332 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_fastest_down
# 333 "data/maps/OldaleTown/scripts.pory"
	step_end
# 334 "data/maps/OldaleTown/scripts.pory"

# 335 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_PlayerStepBack: @ 81E9182
# 336 "data/maps/OldaleTown/scripts.pory"
	delay_8
# 337 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 338 "data/maps/OldaleTown/scripts.pory"
	step_end
# 339 "data/maps/OldaleTown/scripts.pory"

# 340 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_BackUp: @ 81E9185
# 341 "data/maps/OldaleTown/scripts.pory"
	walk_fast_up
# 342 "data/maps/OldaleTown/scripts.pory"
	walk_in_place_fastest_left
# 343 "data/maps/OldaleTown/scripts.pory"
	lock_facing_direction
# 344 "data/maps/OldaleTown/scripts.pory"
	walk_right
# 345 "data/maps/OldaleTown/scripts.pory"
	unlock_facing_direction
# 346 "data/maps/OldaleTown/scripts.pory"
	step_end
# 347 "data/maps/OldaleTown/scripts.pory"

# 348 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Movement_ReturnToOriginalPosition: @ 81E918B
# 349 "data/maps/OldaleTown/scripts.pory"
	walk_down
# 350 "data/maps/OldaleTown/scripts.pory"
	walk_left
# 351 "data/maps/OldaleTown/scripts.pory"
	step_end
# 352 "data/maps/OldaleTown/scripts.pory"

# 353 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_SavingMyProgress: @ 81E918E
# 354 "data/maps/OldaleTown/scripts.pory"
	.string "I want to take a rest, so I'm saving my\n"
# 355 "data/maps/OldaleTown/scripts.pory"
	.string "progress.$"
# 356 "data/maps/OldaleTown/scripts.pory"

# 357 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_IWorkAtPokemonMart: @ 81E91C0
# 358 "data/maps/OldaleTown/scripts.pory"
	.string "Hi!\n"
# 359 "data/maps/OldaleTown/scripts.pory"
	.string "I work at a Pokémon Mart.\p"
# 360 "data/maps/OldaleTown/scripts.pory"
	.string "Can I get you to come with me?$"
# 361 "data/maps/OldaleTown/scripts.pory"

# 362 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_ThisIsAPokemonMart:
# 363 "data/maps/OldaleTown/scripts.pory"
	.string "This is a Pokémon Mart.\n"
# 364 "data/maps/OldaleTown/scripts.pory"
	.string "Just look for our blue roof.\p"
# 365 "data/maps/OldaleTown/scripts.pory"
	.string "We sell a variety of consumable items\n"
# 366 "data/maps/OldaleTown/scripts.pory"
	.string "that Pokémon can hold in battle, as\l"
# 367 "data/maps/OldaleTown/scripts.pory"
	.string "well as items like evolution stones.\p"
# 368 "data/maps/OldaleTown/scripts.pory"
	.string "Here, I'd like you to have this as\n"
# 369 "data/maps/OldaleTown/scripts.pory"
	.string "a promotional item.$"
# 370 "data/maps/OldaleTown/scripts.pory"

# 371 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_PotionExplanation: @ 81E92AF
# 372 "data/maps/OldaleTown/scripts.pory"
	.string "If you're after healing items like\n"
# 373 "data/maps/OldaleTown/scripts.pory"
	.string "Potions or Poké Balls, please see our\l"
# 374 "data/maps/OldaleTown/scripts.pory"
	.string "friendly clerks in any Pokémon Center.$"
# 375 "data/maps/OldaleTown/scripts.pory"

# 376 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_WaitDontComeInHere: @ 81E9313
# 377 "data/maps/OldaleTown/scripts.pory"
	.string "Aaaaah! Wait!\n"
# 378 "data/maps/OldaleTown/scripts.pory"
	.string "Please don't come in here.\p"
# 379 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 380 "data/maps/OldaleTown/scripts.pory"
	.string "a rare Pokémon!\p"
# 381 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 382 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 383 "data/maps/OldaleTown/scripts.pory"

# 384 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_DiscoveredFootprints: @ 81E939A
# 385 "data/maps/OldaleTown/scripts.pory"
	.string "I just discovered the footprints of\n"
# 386 "data/maps/OldaleTown/scripts.pory"
	.string "a rare Pokémon!\p"
# 387 "data/maps/OldaleTown/scripts.pory"
	.string "Wait until I finish sketching\n"
# 388 "data/maps/OldaleTown/scripts.pory"
	.string "them, okay?$"
# 389 "data/maps/OldaleTown/scripts.pory"

# 390 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_FinishedSketchingFootprints: @ 81E93F8
# 391 "data/maps/OldaleTown/scripts.pory"
	.string "I finished sketching the footprints of\n"
# 392 "data/maps/OldaleTown/scripts.pory"
	.string "a rare Pokémon.\p"
# 393 "data/maps/OldaleTown/scripts.pory"
	.string "But it turns out they were only my\n"
# 394 "data/maps/OldaleTown/scripts.pory"
	.string "own footprints…$"
# 395 "data/maps/OldaleTown/scripts.pory"

# 396 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_MayLetsGoBack: @ 81E9462
# 397 "data/maps/OldaleTown/scripts.pory"
	.string "May: {PLAYER}{KUN}!\n"
# 398 "data/maps/OldaleTown/scripts.pory"
	.string "Over here!\l"
# 399 "data/maps/OldaleTown/scripts.pory"
	.string "Let's hurry home!$"
# 400 "data/maps/OldaleTown/scripts.pory"

# 401 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_BrendanLetsGoBack: @ 81E948A
# 402 "data/maps/OldaleTown/scripts.pory"
	.string "Brendan: I'm heading back to my dad's\n"
# 403 "data/maps/OldaleTown/scripts.pory"
	.string "Lab now.\l"
# 404 "data/maps/OldaleTown/scripts.pory"
	.string "{PLAYER}, you should hustle back, too.$"
# 405 "data/maps/OldaleTown/scripts.pory"

# 406 "data/maps/OldaleTown/scripts.pory"
OldaleTown_Text_CitySign: @ 81E94DA
# 407 "data/maps/OldaleTown/scripts.pory"
	.string "Oldale Town\n"
# 408 "data/maps/OldaleTown/scripts.pory"
	.string "“Where things start off scarce.”$"

OldaleTown_EventScript_Sageleader::
# 412 "data/maps/OldaleTown/scripts.pory"
	lock
# 413 "data/maps/OldaleTown/scripts.pory"
	faceplayer
# 414 "data/maps/OldaleTown/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, OldaleTown_EventScript_Sageleader_2
# 421 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_Sageleader_Text_1
OldaleTown_EventScript_Sageleader_1:
# 427 "data/maps/OldaleTown/scripts.pory"
	release
	end

OldaleTown_EventScript_Sageleader_2:
# 415 "data/maps/OldaleTown/scripts.pory"
	msgbox OldaleTown_EventScript_Sageleader_Text_0
	goto OldaleTown_EventScript_Sageleader_1


OldaleTown_EventScript_Sageleader_Text_0:
# 415 "data/maps/OldaleTown/scripts.pory"
	.string "Ah, there you are, young trainer. It\n"
	.string "seems the winds of destiny have\l"
	.string "brought us together.\p"
	.string "Me and my associates are known as the\n"
	.string "Legendary Sages, and have been\l"
	.string "entrusted with a crucial task: the\l"
	.string "guardianship of the legendary Pokémon\l"
	.string "that have started dwelling within the\l"
	.string "region.\p"
	.string "We have been waiting for you, but it\n"
	.string "seems like the time has finally come.\l"
	.string "Your destiny is to become champion and\l"
	.string "guardian of the Legendaries. Still\l"
	.string "confused? Talk to my subordinates,\l"
	.string "they're scattered all across Hoenn:\l"
	.string "they'll tell you everything you'll need\l"
	.string "to know.\p"
	.string "Embrace victory, and don't disappoint\n"
	.string "us.$"

OldaleTown_EventScript_Sageleader_Text_1:
# 421 "data/maps/OldaleTown/scripts.pory"
	.string "Just as predicted, you emerged\n"
	.string "victorious from the trials of the\l"
	.string "Pokémon League. I assume you want to\l"
	.string "start catching the Legendaries as I\l"
	.string "promised you a while back: I'm afraid\l"
	.string "you'll have to wait... a little longer.\p"
	.string "You see, they're not creatures easily\n"
	.string "pleased. They only deal with the best of\l"
	.string "the best, like me... and soon, you. Maybe.\p"
	.string "If you want to catch them, you'll have\n"
	.string "to give every trainer on a given route a\l"
	.string "sound beating, through your Pokémon of\l"
	.string "course.\p"
	.string "Once you do, make sure to talk to one of\n"
	.string "my associates on the route: they'll\l"
	.string "update your DexNav with their location.\p"
	.string "You have come so far since we first met,\n"
	.string "don't waste your potential just now! We\l"
	.string "have faith you'll emerge victorious\l"
	.string "from this endeavour!$"
