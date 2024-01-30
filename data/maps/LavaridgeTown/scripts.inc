# 1 "data/maps/LavaridgeTown/scripts.pory"

# 2 "data/maps/LavaridgeTown/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 7
# 3 "data/maps/LavaridgeTown/scripts.pory"
.set LOCALID_RIVAL, 8
# 4 "data/maps/LavaridgeTown/scripts.pory"

# 5 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts:: @ 81EA4D3
# 6 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 7 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 8 "data/maps/LavaridgeTown/scripts.pory"
	.byte 0
# 9 "data/maps/LavaridgeTown/scripts.pory"

# 10 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition: @ 81EA4DE
# 11 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 12 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 13 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 14 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 15 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 16 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_LAVARIDGE_TOWN_STATE, 1
# 17 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq LavaridgeTown_EventScript_CheckSetRivalPos
# 18 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_LAVARIDGE_TOWN_STATE, 1
# 19 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq LavaridgeTown_EventScript_HideMapNamePopup
# 20 "data/maps/LavaridgeTown/scripts.pory"
	end
# 21 "data/maps/LavaridgeTown/scripts.pory"

# 22 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut:: @ 81EA514
# 23 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 24 "data/maps/LavaridgeTown/scripts.pory"
	return
# 25 "data/maps/LavaridgeTown/scripts.pory"

# 26 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos:: @ 81EA518
# 27 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 28 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_0x8004, 9
# 29 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq LavaridgeTown_EventScript_SetRivalPos
# 30 "data/maps/LavaridgeTown/scripts.pory"
	return
# 31 "data/maps/LavaridgeTown/scripts.pory"

# 32 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos:: @ 81EA529
# 33 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 11, 9
# 34 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
# 35 "data/maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 36 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 37 "data/maps/LavaridgeTown/scripts.pory"
	return
# 38 "data/maps/LavaridgeTown/scripts.pory"

# 39 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers:: @ 81EA53F
# 40 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 41 "data/maps/LavaridgeTown/scripts.pory"
	return
# 42 "data/maps/LavaridgeTown/scripts.pory"

# 43 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup:: @ 81EA543
# 44 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 45 "data/maps/LavaridgeTown/scripts.pory"
	return
# 46 "data/maps/LavaridgeTown/scripts.pory"

# 47 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame: @ 81EA547
# 48 "data/maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 49 "data/maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 50 "data/maps/LavaridgeTown/scripts.pory"

# 51 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles:: @ 81EA551
# 52 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 53 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 54 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_0x8008, 9
# 55 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq LavaridgeTown_EventScript_RivalNoticePlayer
# 56 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_0x8008, 9
# 57 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne LavaridgeTown_EventScript_RivalExitHerbShop
# 58 "data/maps/LavaridgeTown/scripts.pory"
	delay 20
# 59 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 60 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, MALE
# 61 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq LavaridgeTown_EventScript_PlayMayMusic
# 62 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 63 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq LavaridgeTown_EventScript_PlayBrendanMusic
# 64 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_0x8008, 9
# 65 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq LavaridgeTown_EventScript_RivalApproachPlayer1
# 66 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_0x8008, 9
# 67 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne LavaridgeTown_EventScript_RivalApproachPlayer2
# 68 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 69 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, MALE
# 70 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq LavaridgeTown_EventScript_MayGiveGoGoggles
# 71 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, FEMALE
# 72 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 73 "data/maps/LavaridgeTown/scripts.pory"
	end
# 74 "data/maps/LavaridgeTown/scripts.pory"

# 75 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles:: @ 81EA5B5
# 76 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 77 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 78 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 79 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGoggles, MSGBOX_DEFAULT
# 80 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 81 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayGiveSafetyGogglesChallengeDad, MSGBOX_DEFAULT
# 82 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 83 "data/maps/LavaridgeTown/scripts.pory"
	end
# 84 "data/maps/LavaridgeTown/scripts.pory"

# 85 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles:: @ 81EA5DA
# 86 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 87 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 88 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 89 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGoggles, MSGBOX_DEFAULT
# 90 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES
# 91 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainSafetyGogglesChallengeDad, MSGBOX_DEFAULT
# 92 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 93 "data/maps/LavaridgeTown/scripts.pory"
	end
# 94 "data/maps/LavaridgeTown/scripts.pory"

# 95 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit:: @ 81EA5FF
# 96 "data/maps/LavaridgeTown/scripts.pory"
	closemessage
# 97 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_RIVAL
# 98 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 99 "data/maps/LavaridgeTown/scripts.pory"
	delay 30
# 100 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_0x8008, 9
# 101 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq LavaridgeTown_EventScript_RivalExit1
# 102 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_0x8008, 9
# 103 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne LavaridgeTown_EventScript_RivalExit2
# 104 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 105 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 106 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 107 "data/maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 108 "data/maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 109 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
# 110 "data/maps/LavaridgeTown/scripts.pory"
	end
# 111 "data/maps/LavaridgeTown/scripts.pory"

# 112 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic:: @ 81EA630
# 113 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 114 "data/maps/LavaridgeTown/scripts.pory"
	return
# 115 "data/maps/LavaridgeTown/scripts.pory"

# 116 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic:: @ 81EA635
# 117 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 118 "data/maps/LavaridgeTown/scripts.pory"
	return
# 119 "data/maps/LavaridgeTown/scripts.pory"

# 120 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer:: @ 81EA63A
# 121 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestUp
# 122 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 123 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 124 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 125 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 126 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 127 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 128 "data/maps/LavaridgeTown/scripts.pory"
	return
# 129 "data/maps/LavaridgeTown/scripts.pory"

# 130 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop:: @ 81EA65C
# 131 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 132 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 133 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_RIVAL
# 134 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 135 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 136 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 137 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 138 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
# 139 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 140 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 141 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 142 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 143 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 144 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 145 "data/maps/LavaridgeTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 146 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 147 "data/maps/LavaridgeTown/scripts.pory"
	return
# 148 "data/maps/LavaridgeTown/scripts.pory"

# 149 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1:: @ 81EA6A1
# 150 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 151 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 152 "data/maps/LavaridgeTown/scripts.pory"
	return
# 153 "data/maps/LavaridgeTown/scripts.pory"

# 154 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2:: @ 81EA6AC
# 155 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 156 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 157 "data/maps/LavaridgeTown/scripts.pory"
	return
# 158 "data/maps/LavaridgeTown/scripts.pory"

# 159 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1:: @ 81EA6B7
# 160 "data/maps/LavaridgeTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 161 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 162 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 163 "data/maps/LavaridgeTown/scripts.pory"
	return
# 164 "data/maps/LavaridgeTown/scripts.pory"

# 165 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2:: @ 81EA6C9
# 166 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 167 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 168 "data/maps/LavaridgeTown/scripts.pory"
	return
# 169 "data/maps/LavaridgeTown/scripts.pory"

# 170 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2: @ 81EA6D4
# 171 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 172 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 173 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 174 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 175 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 176 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 177 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 178 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 179 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 180 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 181 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 182 "data/maps/LavaridgeTown/scripts.pory"

# 183 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit: @ 81EA6DF
# 184 "data/maps/LavaridgeTown/scripts.pory"
	delay_16
# 185 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 186 "data/maps/LavaridgeTown/scripts.pory"
	walk_in_place_fastest_right
# 187 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 188 "data/maps/LavaridgeTown/scripts.pory"

# 189 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1: @ 81EA6E3
# 190 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 191 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 192 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 193 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 194 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 195 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 196 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 197 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 198 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 199 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 200 "data/maps/LavaridgeTown/scripts.pory"

# 201 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2: @ 81EA6ED
# 202 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 203 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 204 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 205 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 206 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 207 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 208 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 209 "data/maps/LavaridgeTown/scripts.pory"

# 210 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1: @ 81EA6F4
# 211 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 212 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 213 "data/maps/LavaridgeTown/scripts.pory"
	walk_up
# 214 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 215 "data/maps/LavaridgeTown/scripts.pory"

# 216 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop: @ 81EA6F8
# 217 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 218 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 219 "data/maps/LavaridgeTown/scripts.pory"

# 220 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger:: @ 81EA6FA
# 221 "data/maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 222 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
# 223 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq LavaridgeTown_EventScript_EnteredHotSprings
# 224 "data/maps/LavaridgeTown/scripts.pory"
	end
# 225 "data/maps/LavaridgeTown/scripts.pory"

# 226 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings:: @ 81EA70B
# 227 "data/maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 228 "data/maps/LavaridgeTown/scripts.pory"
	end
# 229 "data/maps/LavaridgeTown/scripts.pory"

# 230 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM:: @ 81EA70E
# 231 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 232 "data/maps/LavaridgeTown/scripts.pory"
	end
# 233 "data/maps/LavaridgeTown/scripts.pory"

# 234 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan:: @ 81EA717
# 235 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 236 "data/maps/LavaridgeTown/scripts.pory"
	end
# 237 "data/maps/LavaridgeTown/scripts.pory"

# 238 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin:: @ 81EA720
# 239 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 240 "data/maps/LavaridgeTown/scripts.pory"
	end
# 241 "data/maps/LavaridgeTown/scripts.pory"

# 242 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1:: @ 81EA729
# 243 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 244 "data/maps/LavaridgeTown/scripts.pory"
	end
# 245 "data/maps/LavaridgeTown/scripts.pory"

# 246 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2:: @ 81EA732
# 247 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 248 "data/maps/LavaridgeTown/scripts.pory"
	end
# 249 "data/maps/LavaridgeTown/scripts.pory"

# 250 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF:: @ 81EA73B
# 251 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 252 "data/maps/LavaridgeTown/scripts.pory"
	end
# 253 "data/maps/LavaridgeTown/scripts.pory"

# 254 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman:: @ 81EA744
# 255 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 256 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 257 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 258 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 259 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, NO
# 260 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
# 261 "data/maps/LavaridgeTown/scripts.pory"
	getpartysize
# 262 "data/maps/LavaridgeTown/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
# 263 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
# 264 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 265 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 266 "data/maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 267 "data/maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 268 "data/maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 269 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
# 270 "data/maps/LavaridgeTown/scripts.pory"
	release
# 271 "data/maps/LavaridgeTown/scripts.pory"
	end
# 272 "data/maps/LavaridgeTown/scripts.pory"

# 273 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg:: @ 81EA787
# 274 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 275 "data/maps/LavaridgeTown/scripts.pory"
	release
# 276 "data/maps/LavaridgeTown/scripts.pory"
	end
# 277 "data/maps/LavaridgeTown/scripts.pory"

# 278 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg:: @ 81EA791
# 279 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 280 "data/maps/LavaridgeTown/scripts.pory"
	release
# 281 "data/maps/LavaridgeTown/scripts.pory"
	end
# 282 "data/maps/LavaridgeTown/scripts.pory"

# 283 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg:: @ 81EA79B
# 284 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 285 "data/maps/LavaridgeTown/scripts.pory"
	release
# 286 "data/maps/LavaridgeTown/scripts.pory"
	end
# 287 "data/maps/LavaridgeTown/scripts.pory"

# 288 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign:: @ 81EA7A5
# 289 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 290 "data/maps/LavaridgeTown/scripts.pory"
	end
# 291 "data/maps/LavaridgeTown/scripts.pory"

# 292 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign:: @ 81EA7AE
# 293 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 294 "data/maps/LavaridgeTown/scripts.pory"
	end
# 295 "data/maps/LavaridgeTown/scripts.pory"

# 296 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign:: @ 81EA7B7
# 297 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 298 "data/maps/LavaridgeTown/scripts.pory"
	end
# 299 "data/maps/LavaridgeTown/scripts.pory"

# 300 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis: @ 81EA7C0
# 301 "data/maps/LavaridgeTown/scripts.pory"
	.string "May: {PLAYER}{KUN}! Long time no see!\p"
# 302 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 303 "data/maps/LavaridgeTown/scripts.pory"
	.string "you got the Lavaridge Gym Badge.\p"
# 304 "data/maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 305 "data/maps/LavaridgeTown/scripts.pory"
	.string "good Pokémon…\l"
# 306 "data/maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 307 "data/maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 308 "data/maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 309 "data/maps/LavaridgeTown/scripts.pory"

# 310 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGoggles: @ 81EA897
# 311 "data/maps/LavaridgeTown/scripts.pory"
	.string "May: With those Go-Goggles, you'll\n"
# 312 "data/maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 313 "data/maps/LavaridgeTown/scripts.pory"
	.string "desert near Route 111.\p"
# 314 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, and you might want a pair of these\n"
# 315 "data/maps/LavaridgeTown/scripts.pory"
	.string "for your Pokémon.$"
# 316 "data/maps/LavaridgeTown/scripts.pory"

# 317 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayGiveSafetyGogglesChallengeDad:
# 318 "data/maps/LavaridgeTown/scripts.pory"
	.string "May: Safety Goggles are like Go-Goggles\n"
# 319 "data/maps/LavaridgeTown/scripts.pory"
	.string "for Pokémon - they'll protect them from\l"
# 320 "data/maps/LavaridgeTown/scripts.pory"
	.string "weather and Powder moves.\p"
# 321 "data/maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 322 "data/maps/LavaridgeTown/scripts.pory"
	.string "Challenging Gyms…\p"
# 323 "data/maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 324 "data/maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 325 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 326 "data/maps/LavaridgeTown/scripts.pory"
	.string "your dad in Petalburg Gym.\p"
# 327 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 328 "data/maps/LavaridgeTown/scripts.pory"

# 329 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis: @ 81EA9A2
# 330 "data/maps/LavaridgeTown/scripts.pory"
	.string "Brendan: {PLAYER}, hey, it's been a while.\n"
# 331 "data/maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 332 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 333 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of Badges.\p"
# 334 "data/maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 335 "data/maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 336 "data/maps/LavaridgeTown/scripts.pory"

# 337 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGoggles:
# 338 "data/maps/LavaridgeTown/scripts.pory"
	.string "Brendan: Keep those with you if you're\n"
# 339 "data/maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 340 "data/maps/LavaridgeTown/scripts.pory"
	.string "Route 111.\p"
# 341 "data/maps/LavaridgeTown/scripts.pory"
	.string "You should take a pair of these for\n"
# 342 "data/maps/LavaridgeTown/scripts.pory"
	.string "your Pokémon, too.$"
# 343 "data/maps/LavaridgeTown/scripts.pory"

# 344 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainSafetyGogglesChallengeDad:
# 345 "data/maps/LavaridgeTown/scripts.pory"
	.string "Brendan: If you let a Pokémon hold\n"
# 346 "data/maps/LavaridgeTown/scripts.pory"
	.string "those Safety Goggles, they won't be\l"
# 347 "data/maps/LavaridgeTown/scripts.pory"
	.string "hurt by the desert's sandstorm.\p"
# 348 "data/maps/LavaridgeTown/scripts.pory"
	.string "There should be some Pokémon that\n"
# 349 "data/maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 350 "data/maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 351 "data/maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 352 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging Norman,\l"
# 353 "data/maps/LavaridgeTown/scripts.pory"
	.string "the Gym Leader of Petalburg.\p"
# 354 "data/maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 355 "data/maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 356 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 357 "data/maps/LavaridgeTown/scripts.pory"

# 358 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt: @ 81EAB80
# 359 "data/maps/LavaridgeTown/scripts.pory"
	.string "I have here an Egg.\p"
# 360 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 361 "data/maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 362 "data/maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 363 "data/maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 364 "data/maps/LavaridgeTown/scripts.pory"
	.string "kept together with Pokémon and\l"
# 365 "data/maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 366 "data/maps/LavaridgeTown/scripts.pory"
	.string "You are a Trainer, yes?\n"
# 367 "data/maps/LavaridgeTown/scripts.pory"
	.string "And your Pokémon radiate vitality.\p"
# 368 "data/maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 369 "data/maps/LavaridgeTown/scripts.pory"
	.string "Will you take this Egg to hatch?$"
# 370 "data/maps/LavaridgeTown/scripts.pory"

# 371 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg: @ 81EACC0
# 372 "data/maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 373 "data/maps/LavaridgeTown/scripts.pory"
	.string "this here Egg!$"
# 374 "data/maps/LavaridgeTown/scripts.pory"

# 375 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg: @ 81EACF4
# 376 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the Egg.$"
# 377 "data/maps/LavaridgeTown/scripts.pory"

# 378 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg: @ 81EAD09
# 379 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many Pokémon.\n"
# 380 "data/maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this Egg…$"
# 381 "data/maps/LavaridgeTown/scripts.pory"

# 382 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen: @ 81EAD44
# 383 "data/maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 384 "data/maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 385 "data/maps/LavaridgeTown/scripts.pory"
	.string "hatching this Egg, I will be here.$"
# 386 "data/maps/LavaridgeTown/scripts.pory"

# 387 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare: @ 81EAD9E
# 388 "data/maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an Egg will be found at\n"
# 389 "data/maps/LavaridgeTown/scripts.pory"
	.string "the Pokémon Day Care.\p"
# 390 "data/maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 391 "data/maps/LavaridgeTown/scripts.pory"

# 392 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry: @ 81EAE03
# 393 "data/maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 394 "data/maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 395 "data/maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 396 "data/maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 397 "data/maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 398 "data/maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 399 "data/maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 400 "data/maps/LavaridgeTown/scripts.pory"

# 401 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside: @ 81EAEE1
# 402 "data/maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 403 "data/maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 404 "data/maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 405 "data/maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 406 "data/maps/LavaridgeTown/scripts.pory"
	.string "A Pokémon nipped my backside!$"
# 407 "data/maps/LavaridgeTown/scripts.pory"

# 408 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings: @ 81EAF4E
# 409 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 410 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 411 "data/maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 412 "data/maps/LavaridgeTown/scripts.pory"

# 413 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay: @ 81EAF9B
# 414 "data/maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 415 "data/maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 416 "data/maps/LavaridgeTown/scripts.pory"
	.string "Gym Leader like Flannery.$"
# 417 "data/maps/LavaridgeTown/scripts.pory"

# 418 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings: @ 81EB003
# 419 "data/maps/LavaridgeTown/scripts.pory"
	.string "If people put Pokémon in hot springs,\n"
# 420 "data/maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 421 "data/maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 422 "data/maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 423 "data/maps/LavaridgeTown/scripts.pory"

# 424 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims: @ 81EB092
# 425 "data/maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 426 "data/maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 427 "data/maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 428 "data/maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 429 "data/maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 430 "data/maps/LavaridgeTown/scripts.pory"

# 431 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign: @ 81EB12B
# 432 "data/maps/LavaridgeTown/scripts.pory"
	.string "Lavaridge Town\p"
# 433 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Pokémon Center Hot Springs\n"
# 434 "data/maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 435 "data/maps/LavaridgeTown/scripts.pory"

# 436 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign: @ 81EB178
# 437 "data/maps/LavaridgeTown/scripts.pory"
	.string "Lavaridge Town Pokémon Gym\n"
# 438 "data/maps/LavaridgeTown/scripts.pory"
	.string "Leader: Flannery\l"
# 439 "data/maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 440 "data/maps/LavaridgeTown/scripts.pory"

# 441 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign: @ 81EB1CB
# 442 "data/maps/LavaridgeTown/scripts.pory"
	.string "Pokémon Herb Shop\n"
# 443 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"
