# 1 "data/maps/RusturfTunnel/scripts.pory"

# 2 "data/maps/RusturfTunnel/scripts.pory"
.equ LOCALID_WANDAS_BF, 1
# 3 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_BRINEY, 3
# 4 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_GRUNT, 4
# 5 "data/maps/RusturfTunnel/scripts.pory"
.set LOCALID_PEEKO, 5
# 6 "data/maps/RusturfTunnel/scripts.pory"
.equ LOCALID_WANDA, 8
# 7 "data/maps/RusturfTunnel/scripts.pory"

# 8 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_MapScripts:: @ 822CE27
# 9 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
# 10 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
# 11 "data/maps/RusturfTunnel/scripts.pory"
	.byte 0
# 12 "data/maps/RusturfTunnel/scripts.pory"

# 13 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnFrame: @ 822CE32
# 14 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
# 15 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
# 16 "data/maps/RusturfTunnel/scripts.pory"
	.2byte 0
# 17 "data/maps/RusturfTunnel/scripts.pory"

# 18 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnTransition: @ 822CE44
# 19 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_RUSTURF_TUNNEL_STATE, 2
# 20 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
# 21 "data/maps/RusturfTunnel/scripts.pory"
	end
# 22 "data/maps/RusturfTunnel/scripts.pory"

# 23 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos:: @ 822CE50
# 24 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_PEEKO, 13, 4
# 25 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_GRUNT, 13, 5
# 26 "data/maps/RusturfTunnel/scripts.pory"
	return
# 27 "data/maps/RusturfTunnel/scripts.pory"

# 28 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Wanda:: @ 822CE5F
# 29 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 30 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 31 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
# 32 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 33 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 34 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 35 "data/maps/RusturfTunnel/scripts.pory"
	release
# 36 "data/maps/RusturfTunnel/scripts.pory"
	end
# 37 "data/maps/RusturfTunnel/scripts.pory"

# 38 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriend:: @ 822CE76
# 39 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 40 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 41 "data/maps/RusturfTunnel/scripts.pory"
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
# 42 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_TEMP_1
# 43 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
# 44 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 45 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 46 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 47 "data/maps/RusturfTunnel/scripts.pory"
	release
# 48 "data/maps/RusturfTunnel/scripts.pory"
	end
# 49 "data/maps/RusturfTunnel/scripts.pory"

# 50 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AlreadySpokenTo:: @ 822CE99
# 51 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
# 52 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 53 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 54 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 55 "data/maps/RusturfTunnel/scripts.pory"
	release
# 56 "data/maps/RusturfTunnel/scripts.pory"
	end
# 57 "data/maps/RusturfTunnel/scripts.pory"

# 58 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_ClearTunnelScene:: @ 822CEAE
# 59 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 60 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 1
# 61 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend1
# 62 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 2
# 63 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend2
# 64 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 3
# 65 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend3
# 66 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
# 67 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
# 68 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 2
# 69 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 70 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 3
# 71 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 72 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_HM04_STRENGTH
# 73 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECEIVED_HM04
# 74 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
# 75 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 76 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 1
# 77 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda1
# 78 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 2
# 79 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda2
# 80 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 3
# 81 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda3
# 82 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
# 83 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 84 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 1
# 85 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit1
# 86 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 2
# 87 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 88 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_TEMP_1, 3
# 89 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 90 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
# 91 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 92 "data/maps/RusturfTunnel/scripts.pory"
	end
# 93 "data/maps/RusturfTunnel/scripts.pory"

# 94 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda1:: @ 822CF5D
# 95 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
# 96 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
# 97 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 98 "data/maps/RusturfTunnel/scripts.pory"
	return
# 99 "data/maps/RusturfTunnel/scripts.pory"

# 100 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda2:: @ 822CF6F
# 101 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 102 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 103 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 104 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFastestDown
# 105 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 106 "data/maps/RusturfTunnel/scripts.pory"
	return
# 107 "data/maps/RusturfTunnel/scripts.pory"

# 108 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda3:: @ 822CF8B
# 109 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 110 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 111 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 112 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFastestDown
# 113 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 114 "data/maps/RusturfTunnel/scripts.pory"
	return
# 115 "data/maps/RusturfTunnel/scripts.pory"

# 116 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend1:: @ 822CFA7
# 117 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_WalkInPlaceFastestUp
# 118 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 119 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 120 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 121 "data/maps/RusturfTunnel/scripts.pory"
	return
# 122 "data/maps/RusturfTunnel/scripts.pory"

# 123 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend2:: @ 822CFBC
# 124 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
# 125 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 126 "data/maps/RusturfTunnel/scripts.pory"
	return
# 127 "data/maps/RusturfTunnel/scripts.pory"

# 128 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend3:: @ 822CFC7
# 129 "data/maps/RusturfTunnel/scripts.pory"
	return
# 130 "data/maps/RusturfTunnel/scripts.pory"

# 131 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer:: @ 822CFC8
# 132 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 133 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
# 134 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 135 "data/maps/RusturfTunnel/scripts.pory"
	return
# 136 "data/maps/RusturfTunnel/scripts.pory"

# 137 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit1:: @ 822CFD4
# 138 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit1
# 139 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
# 140 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 141 "data/maps/RusturfTunnel/scripts.pory"
	return
# 142 "data/maps/RusturfTunnel/scripts.pory"

# 143 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit:: @ 822CFE6
# 144 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
# 145 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit
# 146 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
# 147 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 148 "data/maps/RusturfTunnel/scripts.pory"
	return
# 149 "data/maps/RusturfTunnel/scripts.pory"

# 150 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendNotice:: @ 822CFFF
# 151 "data/maps/RusturfTunnel/scripts.pory"
	playse SE_PIN
# 152 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_ExclamationMark
# 153 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 154 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_WANDAS_BF, Common_Movement_Delay48
# 155 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 156 "data/maps/RusturfTunnel/scripts.pory"
	return
# 157 "data/maps/RusturfTunnel/scripts.pory"

# 158 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit1: @ 822D017
# 159 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 160 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 161 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 162 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 163 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 164 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 165 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 166 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 167 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 168 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 169 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 170 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 171 "data/maps/RusturfTunnel/scripts.pory"

# 172 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit: @ 822D023
# 173 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 174 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 175 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 176 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 177 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 178 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 179 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 180 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 181 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 182 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 183 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 184 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 185 "data/maps/RusturfTunnel/scripts.pory"

# 186 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchWandaExit: @ 822D02F
# 187 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 188 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_up
# 189 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 190 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 191 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_right
# 192 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 193 "data/maps/RusturfTunnel/scripts.pory"

# 194 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused1: @ 822D035
# 195 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 196 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_right
# 197 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 198 "data/maps/RusturfTunnel/scripts.pory"

# 199 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused2: @ 822D038
# 200 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 201 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_up
# 202 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 203 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_right
# 204 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 205 "data/maps/RusturfTunnel/scripts.pory"

# 206 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused3: @ 822D03D
# 207 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 208 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_down
# 209 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 210 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_right
# 211 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 212 "data/maps/RusturfTunnel/scripts.pory"

# 213 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend1: @ 822D042
# 214 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 215 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_right
# 216 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 217 "data/maps/RusturfTunnel/scripts.pory"

# 218 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend: @ 822D045
# 219 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 220 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_left
# 221 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 222 "data/maps/RusturfTunnel/scripts.pory"

# 223 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendFaceRight: @ 822D048
# 224 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 225 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_right
# 226 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 227 "data/maps/RusturfTunnel/scripts.pory"

# 228 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit1: @ 822D04B
# 229 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 230 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 231 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 232 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 233 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 234 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 235 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 236 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 237 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 238 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 239 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 240 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 241 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 242 "data/maps/RusturfTunnel/scripts.pory"

# 243 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit: @ 822D058
# 244 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 245 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 246 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 247 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 248 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 249 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 250 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 251 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 252 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 253 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 254 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 255 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 256 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 257 "data/maps/RusturfTunnel/scripts.pory"

# 258 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendApproachPlayer: @ 822D065
# 259 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 260 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 261 "data/maps/RusturfTunnel/scripts.pory"

# 262 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda1: @ 822D067
# 263 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 264 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 265 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_up
# 266 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 267 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 268 "data/maps/RusturfTunnel/scripts.pory"

# 269 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda: @ 822D06C
# 270 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 271 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 272 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 273 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_up
# 274 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 275 "data/maps/RusturfTunnel/scripts.pory"

# 276 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos1:: @ 822D071
# 277 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 1
# 278 "data/maps/RusturfTunnel/scripts.pory"
	end
# 279 "data/maps/RusturfTunnel/scripts.pory"

# 280 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos2:: @ 822D077
# 281 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 2
# 282 "data/maps/RusturfTunnel/scripts.pory"
	end
# 283 "data/maps/RusturfTunnel/scripts.pory"

# 284 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos3:: @ 822D07D
# 285 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 3
# 286 "data/maps/RusturfTunnel/scripts.pory"
	end
# 287 "data/maps/RusturfTunnel/scripts.pory"

# 288 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AquaGruntBackUp:: @ 822D083
# 289 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 290 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
# 291 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 292 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 293 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 294 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 295 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT
# 296 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_PEEKO
# 297 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
# 298 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 299 "data/maps/RusturfTunnel/scripts.pory"
	end
# 300 "data/maps/RusturfTunnel/scripts.pory"

# 301 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntAndPeekoBackUp: @ 822D0AB
# 302 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 303 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 304 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 305 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 306 "data/maps/RusturfTunnel/scripts.pory"

# 307 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Peeko:: @ 822D0AF
# 308 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 309 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 310 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 311 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 312 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
# 313 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 314 "data/maps/RusturfTunnel/scripts.pory"
	release
# 315 "data/maps/RusturfTunnel/scripts.pory"
	end
# 316 "data/maps/RusturfTunnel/scripts.pory"

# 317 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Grunt:: @ 822D0C2
# 318 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 319 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 320 "data/maps/RusturfTunnel/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 321 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
# 322 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
# 323 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
# 324 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_DEVON_GOODS
# 325 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 326 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
# 327 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntEscape
# 328 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 329 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_GRUNT
# 330 "data/maps/RusturfTunnel/scripts.pory"
	delay 50
# 331 "data/maps/RusturfTunnel/scripts.pory"
	addobject LOCALID_BRINEY
# 332 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
# 333 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 334 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
# 335 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
# 336 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 337 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
# 338 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_FacePlayer
# 339 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 340 "data/maps/RusturfTunnel/scripts.pory"
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
# 341 "data/maps/RusturfTunnel/scripts.pory"
	waitmessage
# 342 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 343 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 344 "data/maps/RusturfTunnel/scripts.pory"
	waitbuttonpress
# 345 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 346 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 347 "data/maps/RusturfTunnel/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
# 348 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyExit
# 349 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_PeekoExit
# 350 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 351 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_BRINEY
# 352 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_PEEKO
# 353 "data/maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_DEVON_GOODS_STOLEN
# 354 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECOVERED_DEVON_GOODS
# 355 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 356 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_BRINEY_HOUSE_STATE, 1
# 357 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 358 "data/maps/RusturfTunnel/scripts.pory"
	release
# 359 "data/maps/RusturfTunnel/scripts.pory"
	end
# 360 "data/maps/RusturfTunnel/scripts.pory"

# 361 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PushPlayerAsideForGrunt: @ 822D178
# 362 "data/maps/RusturfTunnel/scripts.pory"
	face_down
# 363 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 364 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 365 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 366 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_left
# 367 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 368 "data/maps/RusturfTunnel/scripts.pory"

# 369 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerMoveAsideForBriney: @ 822D17E
# 370 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 371 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_up
# 372 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 373 "data/maps/RusturfTunnel/scripts.pory"

# 374 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntEscape: @ 822D181
# 375 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 376 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 377 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 378 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 379 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 380 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 381 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 382 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 383 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 384 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 385 "data/maps/RusturfTunnel/scripts.pory"

# 386 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko1: @ 822D18B
# 387 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 388 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 389 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 390 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 391 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 392 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 393 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 394 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 395 "data/maps/RusturfTunnel/scripts.pory"

# 396 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyExit: @ 822D193
# 397 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 398 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 399 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 400 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 401 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 402 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 403 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 404 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 405 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 406 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 407 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 408 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 409 "data/maps/RusturfTunnel/scripts.pory"

# 410 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBrineyExit: @ 822D19F
# 411 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 412 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 413 "data/maps/RusturfTunnel/scripts.pory"
	delay_4
# 414 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fastest_left
# 415 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 416 "data/maps/RusturfTunnel/scripts.pory"

# 417 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko2: @ 822D1A4
# 418 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 419 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 420 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 421 "data/maps/RusturfTunnel/scripts.pory"

# 422 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PeekoExit: @ 822D1A7
# 423 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 424 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 425 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 426 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 427 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 428 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 429 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 430 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 431 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 432 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 433 "data/maps/RusturfTunnel/scripts.pory"

# 434 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Mike:: @ 822D1B1
# 435 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
# 436 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 437 "data/maps/RusturfTunnel/scripts.pory"
	end
# 438 "data/maps/RusturfTunnel/scripts.pory"

# 439 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ComeAndGetSome: @ 822D1C8
# 440 "data/maps/RusturfTunnel/scripts.pory"
	.string "What, are you coming?\n"
# 441 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come and get some, then!$"
# 442 "data/maps/RusturfTunnel/scripts.pory"

# 443 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_Peeko: @ 822D1F7
# 444 "data/maps/RusturfTunnel/scripts.pory"
	.string "Peeko: Pii pihyoh!$"
# 445 "data/maps/RusturfTunnel/scripts.pory"

# 446 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntIntro: @ 822D20A
# 447 "data/maps/RusturfTunnel/scripts.pory"
	.string "Grah, keelhaul it all!\p"
# 448 "data/maps/RusturfTunnel/scripts.pory"
	.string "That hostage Pokémon turned out to\n"
# 449 "data/maps/RusturfTunnel/scripts.pory"
	.string "be worthless!\p"
# 450 "data/maps/RusturfTunnel/scripts.pory"
	.string "And to think I made a getaway…\n"
# 451 "data/maps/RusturfTunnel/scripts.pory"
	.string "In this tunnel to nowhere!\p"
# 452 "data/maps/RusturfTunnel/scripts.pory"
	.string "Hey! You!\n"
# 453 "data/maps/RusturfTunnel/scripts.pory"
	.string "So you want to battle me?$"
# 454 "data/maps/RusturfTunnel/scripts.pory"

# 455 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntDefeat: @ 822D2B0
# 456 "data/maps/RusturfTunnel/scripts.pory"
	.string "Urrrggh! My career in crime comes to\n"
# 457 "data/maps/RusturfTunnel/scripts.pory"
	.string "a dead end!$"
# 458 "data/maps/RusturfTunnel/scripts.pory"

# 459 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntTakePackage: @ 822D2E1
# 460 "data/maps/RusturfTunnel/scripts.pory"
	.string "This is plain not right…\p"
# 461 "data/maps/RusturfTunnel/scripts.pory"
	.string "The Boss told me this would be a\n"
# 462 "data/maps/RusturfTunnel/scripts.pory"
	.string "slick-and-easy job to pull.\p"
# 463 "data/maps/RusturfTunnel/scripts.pory"
	.string "All I had to do was steal some package\n"
# 464 "data/maps/RusturfTunnel/scripts.pory"
	.string "from Devon.\p"
# 465 "data/maps/RusturfTunnel/scripts.pory"
	.string "Tch!\n"
# 466 "data/maps/RusturfTunnel/scripts.pory"
	.string "You want it back that badly, take it!$"
# 467 "data/maps/RusturfTunnel/scripts.pory"

# 468 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_PeekoGladToSeeYouSafe: @ 822D395
# 469 "data/maps/RusturfTunnel/scripts.pory"
	.string "Peeko!\n"
# 470 "data/maps/RusturfTunnel/scripts.pory"
	.string "Am I glad to see you're safe!$"
# 471 "data/maps/RusturfTunnel/scripts.pory"

# 472 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ThankYouLetsGoHomePeeko: @ 822D3BA
# 473 "data/maps/RusturfTunnel/scripts.pory"
	.string "Peeko owes her life to you!\p"
# 474 "data/maps/RusturfTunnel/scripts.pory"
	.string "They call me Mr. Briney.\n"
# 475 "data/maps/RusturfTunnel/scripts.pory"
	.string "And, you are?\p"
# 476 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\n"
# 477 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\p"
# 478 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
# 479 "data/maps/RusturfTunnel/scripts.pory"
	.string "I sincerely thank you!\p"
# 480 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now, if there's anything that troubles\n"
# 481 "data/maps/RusturfTunnel/scripts.pory"
	.string "you, don't hesitate to tell me!\p"
# 482 "data/maps/RusturfTunnel/scripts.pory"
	.string "You can usually find me in my cottage\n"
# 483 "data/maps/RusturfTunnel/scripts.pory"
	.string "by the sea near Petalburg Woods.\p"
# 484 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come, Peeko, we should make our way\n"
# 485 "data/maps/RusturfTunnel/scripts.pory"
	.string "home.\p"
# 486 "data/maps/RusturfTunnel/scripts.pory"
	.string "Peeko: Pihyoh!$"
# 487 "data/maps/RusturfTunnel/scripts.pory"

# 488 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WhyCantTheyKeepDigging: @ 822D510
# 489 "data/maps/RusturfTunnel/scripts.pory"
	.string "… …\p"
# 490 "data/maps/RusturfTunnel/scripts.pory"
	.string "Why can't they keep digging?\n"
# 491 "data/maps/RusturfTunnel/scripts.pory"
	.string "Is the bedrock too hard?\p"
# 492 "data/maps/RusturfTunnel/scripts.pory"
	.string "My beloved awaits me in Verdanturf\n"
# 493 "data/maps/RusturfTunnel/scripts.pory"
	.string "TOWN just beyond here…\p"
# 494 "data/maps/RusturfTunnel/scripts.pory"
	.string "If Rustboro and Verdanturf were\n"
# 495 "data/maps/RusturfTunnel/scripts.pory"
	.string "joined by this tunnel, I could visit\l"
# 496 "data/maps/RusturfTunnel/scripts.pory"
	.string "her every day…\p"
# 497 "data/maps/RusturfTunnel/scripts.pory"
	.string "But this…\n"
# 498 "data/maps/RusturfTunnel/scripts.pory"
	.string "What am I to do?$"
# 499 "data/maps/RusturfTunnel/scripts.pory"

# 500 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ToGetToVerdanturf: @ 822D5F3
# 501 "data/maps/RusturfTunnel/scripts.pory"
	.string "To get from Rustboro to Verdanturf,\n"
# 502 "data/maps/RusturfTunnel/scripts.pory"
	.string "you need to go to Dewford, then pass\l"
# 503 "data/maps/RusturfTunnel/scripts.pory"
	.string "through Slateport and Mauville…$"
# 504 "data/maps/RusturfTunnel/scripts.pory"

# 505 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_YouShatteredBoulderTakeHM: @ 822D65C
# 506 "data/maps/RusturfTunnel/scripts.pory"
	.string "Wow! You shattered that boulder\n"
# 507 "data/maps/RusturfTunnel/scripts.pory"
	.string "blocking the way.\p"
# 508 "data/maps/RusturfTunnel/scripts.pory"
	.string "To show you how much I appreciate it,\n"
# 509 "data/maps/RusturfTunnel/scripts.pory"
	.string "I'd like you to have this HM.$"
# 510 "data/maps/RusturfTunnel/scripts.pory"

# 511 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ExplainStrength: @ 822D6D2
# 512 "data/maps/RusturfTunnel/scripts.pory"
	.string "That HM contains Strength.\p"
# 513 "data/maps/RusturfTunnel/scripts.pory"
	.string "If a muscular Pokémon were to learn\n"
# 514 "data/maps/RusturfTunnel/scripts.pory"
	.string "that, it would be able to move even\l"
# 515 "data/maps/RusturfTunnel/scripts.pory"
	.string "large boulders.$"
# 516 "data/maps/RusturfTunnel/scripts.pory"

# 517 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WandaReunion: @ 822D745
# 518 "data/maps/RusturfTunnel/scripts.pory"
	.string "Wanda!\n"
# 519 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now I can see you anytime!\p"
# 520 "data/maps/RusturfTunnel/scripts.pory"
	.string "Wanda: That's…wonderful.\p"
# 521 "data/maps/RusturfTunnel/scripts.pory"
	.string "Please, take some rest at my home.$"
# 522 "data/maps/RusturfTunnel/scripts.pory"

# 523 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_BoyfriendOnOtherSideOfRock: @ 822D7A3
# 524 "data/maps/RusturfTunnel/scripts.pory"
	.string "On the other side of this rock…\n"
# 525 "data/maps/RusturfTunnel/scripts.pory"
	.string "My boyfriend is there.\p"
# 526 "data/maps/RusturfTunnel/scripts.pory"
	.string "He… He's not just digging the tunnel\n"
# 527 "data/maps/RusturfTunnel/scripts.pory"
	.string "to come see me.\p"
# 528 "data/maps/RusturfTunnel/scripts.pory"
	.string "He works his hands raw and rough\n"
# 529 "data/maps/RusturfTunnel/scripts.pory"
	.string "for the benefit of everyone.$"
# 530 "data/maps/RusturfTunnel/scripts.pory"

# 531 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeIntro: @ 822D84D
# 532 "data/maps/RusturfTunnel/scripts.pory"
	.string "What do you call a wild man up in the\n"
# 533 "data/maps/RusturfTunnel/scripts.pory"
	.string "mountains? A mountain man, right?\p"
# 534 "data/maps/RusturfTunnel/scripts.pory"
	.string "So why don't they call a Pokémon in\n"
# 535 "data/maps/RusturfTunnel/scripts.pory"
	.string "the mountains a mountain Pokémon?$"
# 536 "data/maps/RusturfTunnel/scripts.pory"

# 537 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeDefeat: @ 822D8DB
# 538 "data/maps/RusturfTunnel/scripts.pory"
	.string "My Pokémon…\n"
# 539 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ran out of power…$"
# 540 "data/maps/RusturfTunnel/scripts.pory"

# 541 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikePostBattle: @ 822D8F9
# 542 "data/maps/RusturfTunnel/scripts.pory"
	.string "They halted development here to\n"
# 543 "data/maps/RusturfTunnel/scripts.pory"
	.string "protect Pokémon, right?\l"
# 544 "data/maps/RusturfTunnel/scripts.pory"
	.string "There's a feel-good story!$"

RusturfTunnel_EventScript_Gen8_NPC::
# 549 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 550 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 551 "data/maps/RusturfTunnel/scripts.pory"
	checktrainerflag TRAINER_MIKE_2
	goto_if 1, RusturfTunnel_EventScript_Gen8_NPC_2
# 561 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_EventScript_Gen8_NPC_Text_2
RusturfTunnel_EventScript_Gen8_NPC_1:
# 563 "data/maps/RusturfTunnel/scripts.pory"
	release
	end

RusturfTunnel_EventScript_Gen8_NPC_2:
# 553 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_EventScript_Gen8_NPC_Text_0
# 554 "data/maps/RusturfTunnel/scripts.pory"
	givemon SPECIES_IMPIDIMP, 10, ITEM_NONE
# 555 "data/maps/RusturfTunnel/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 556 "data/maps/RusturfTunnel/scripts.pory"
	message RusturfTunnel_EventScript_Gen8_NPC_Text_1
# 557 "data/maps/RusturfTunnel/scripts.pory"
	waitfanfare
	goto RusturfTunnel_EventScript_Gen8_NPC_1


RusturfTunnel_EventScript_Gen8_NPC_Text_0:
# 553 "data/maps/RusturfTunnel/scripts.pory"
	.string "Take this Pokémon from Galar. You can\n"
	.string "have as many of them as you like! No,\l"
	.string "really, take as many as you can!\l"
	.string "(please...)$"

RusturfTunnel_EventScript_Gen8_NPC_Text_1:
# 556 "data/maps/RusturfTunnel/scripts.pory"
	.string "{PLAYER} got an {COLOR BLUE}Impidimp{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating the hiker!$"

RusturfTunnel_EventScript_Gen8_NPC_Text_2:
# 561 "data/maps/RusturfTunnel/scripts.pory"
	.string "If you can beat this hiker over there, I\n"
	.string "will give you a special Pokémon from the\l"
	.string "Galar region. They're kind of a pest\l"
	.string "really... (shouldn't have said that!) but\l"
	.string "I think you'll... like them. I guess.$"
