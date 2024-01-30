# 1 "data/maps/RustboroCity/scripts.pory"

# 2 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_LITTLE_BOY, 7
# 3 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_LITTLE_GIRL, 8
# 4 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 9
# 5 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_GRUNT, 10
# 6 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_RIVAL, 13
# 7 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_SCIENTIST, 14
# 8 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_ROXANNE, 16
# 9 "data/maps/RustboroCity/scripts.pory"

# 10 "data/maps/RustboroCity/scripts.pory"
RustboroCity_MapScripts:: @ 81E06BD
# 11 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
# 12 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
# 13 "data/maps/RustboroCity/scripts.pory"
	.byte 0
# 14 "data/maps/RustboroCity/scripts.pory"

# 15 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnTransition: @ 81E06C8
# 16 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 17 "data/maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 18 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 7
# 19 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_HideMapNamePopup
# 20 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 21 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 7
# 22 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_PositionScientistForExit
# 23 "data/maps/RustboroCity/scripts.pory"
	end
# 24 "data/maps/RustboroCity/scripts.pory"

# 25 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit:: @ 81E06EC
# 26 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 11
# 27 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_PositionScientistLeftExit
# 28 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 12, 15
# 29 "data/maps/RustboroCity/scripts.pory"
	end
# 30 "data/maps/RustboroCity/scripts.pory"

# 31 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit:: @ 81E06FF
# 32 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 11, 15
# 33 "data/maps/RustboroCity/scripts.pory"
	end
# 34 "data/maps/RustboroCity/scripts.pory"

# 35 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup:: @ 81E0707
# 36 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 37 "data/maps/RustboroCity/scripts.pory"
	return
# 38 "data/maps/RustboroCity/scripts.pory"

# 39 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame: @ 81E070B
# 40 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 7, RustboroCity_EventScript_ScientistAddMatchCall
# 41 "data/maps/RustboroCity/scripts.pory"
	.2byte 0
# 42 "data/maps/RustboroCity/scripts.pory"

# 43 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall:: @ 81E0715
# 44 "data/maps/RustboroCity/scripts.pory"
	lockall
# 45 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 46 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 47 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 48 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 49 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 50 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_SCIENTIST
# 51 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 52 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 53 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 54 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
# 55 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 56 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_Delay48
# 57 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 58 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 59 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 60 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 61 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 62 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 63 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 64 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 65 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFastestLeft
# 66 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 67 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 68 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 69 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 70 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 71 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 72 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 73 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 74 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 75 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFastestDown
# 76 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 77 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 78 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 79 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 80 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 81 "data/maps/RustboroCity/scripts.pory"

# 82 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav:: @ 81E07AC
# 83 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 84 "data/maps/RustboroCity/scripts.pory"

# 85 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial:: @ 81E07BD
# 86 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 87 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 88 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 89 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 90 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 92 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_SCIENTIST
# 93 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 94 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 95 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 96 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 97 "data/maps/RustboroCity/scripts.pory"
	end
# 98 "data/maps/RustboroCity/scripts.pory"

# 99 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown: @ 81E084E
# 100 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 101 "data/maps/RustboroCity/scripts.pory"
	step_end
# 102 "data/maps/RustboroCity/scripts.pory"

# 103 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown: @ 81E0850
# 104 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 105 "data/maps/RustboroCity/scripts.pory"
	step_end
# 106 "data/maps/RustboroCity/scripts.pory"

# 107 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer: @ 81E0852
# 108 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 109 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 110 "data/maps/RustboroCity/scripts.pory"
	step_end
# 111 "data/maps/RustboroCity/scripts.pory"

# 112 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 113 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer: @ 81E0855
# 114 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 115 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 116 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 117 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 118 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 119 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fastest_up
# 120 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 121 "data/maps/RustboroCity/scripts.pory"
	step_end
# 122 "data/maps/RustboroCity/scripts.pory"

# 123 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave: @ 81E085D
# 124 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 125 "data/maps/RustboroCity/scripts.pory"
	step_end
# 126 "data/maps/RustboroCity/scripts.pory"

# 127 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan:: @ 81E085F
# 128 "data/maps/RustboroCity/scripts.pory"
	lock
# 129 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 130 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 131 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 132 "data/maps/RustboroCity/scripts.pory"
	release
# 133 "data/maps/RustboroCity/scripts.pory"
	end
# 134 "data/maps/RustboroCity/scripts.pory"

# 135 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt:: @ 81E0874
# 136 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 137 "data/maps/RustboroCity/scripts.pory"
	release
# 138 "data/maps/RustboroCity/scripts.pory"
	end
# 139 "data/maps/RustboroCity/scripts.pory"

# 140 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2:: @ 81E087E
# 141 "data/maps/RustboroCity/scripts.pory"
	lock
# 142 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 143 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 144 "data/maps/RustboroCity/scripts.pory"
	release
# 145 "data/maps/RustboroCity/scripts.pory"
	end
# 146 "data/maps/RustboroCity/scripts.pory"

# 147 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman:: @ 81E088A
# 148 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 149 "data/maps/RustboroCity/scripts.pory"
	end
# 150 "data/maps/RustboroCity/scripts.pory"

# 151 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1:: @ 81E0893
# 152 "data/maps/RustboroCity/scripts.pory"
	lock
# 153 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 154 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 155 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 156 "data/maps/RustboroCity/scripts.pory"
	release
# 157 "data/maps/RustboroCity/scripts.pory"
	end
# 158 "data/maps/RustboroCity/scripts.pory"

# 159 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge:: @ 81E08A8
# 160 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 161 "data/maps/RustboroCity/scripts.pory"
	release
# 162 "data/maps/RustboroCity/scripts.pory"
	end
# 163 "data/maps/RustboroCity/scripts.pory"

# 164 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2:: @ 81E08B2
# 165 "data/maps/RustboroCity/scripts.pory"
	lock
# 166 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 167 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 168 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 169 "data/maps/RustboroCity/scripts.pory"
	release
# 170 "data/maps/RustboroCity/scripts.pory"
	end
# 171 "data/maps/RustboroCity/scripts.pory"

# 172 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel:: @ 81E08C7
# 173 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 174 "data/maps/RustboroCity/scripts.pory"
	release
# 175 "data/maps/RustboroCity/scripts.pory"
	end
# 176 "data/maps/RustboroCity/scripts.pory"

# 177 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin:: @ 81E08D1
# 178 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 179 "data/maps/RustboroCity/scripts.pory"
	end
# 180 "data/maps/RustboroCity/scripts.pory"

# 181 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy:: @ 81E08DA
# 182 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 183 "data/maps/RustboroCity/scripts.pory"
	end
# 184 "data/maps/RustboroCity/scripts.pory"

# 185 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign:: @ 81E08E3
# 186 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 187 "data/maps/RustboroCity/scripts.pory"
	end
# 188 "data/maps/RustboroCity/scripts.pory"

# 189 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign:: @ 81E08EC
# 190 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 191 "data/maps/RustboroCity/scripts.pory"
	end
# 192 "data/maps/RustboroCity/scripts.pory"

# 193 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign:: @ 81E08F5
# 194 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 195 "data/maps/RustboroCity/scripts.pory"
	end
# 196 "data/maps/RustboroCity/scripts.pory"

# 197 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 198 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign:: @ 81E08FE
# 199 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 200 "data/maps/RustboroCity/scripts.pory"
	end
# 201 "data/maps/RustboroCity/scripts.pory"

# 202 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign:: @ 81E0907
# 203 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 204 "data/maps/RustboroCity/scripts.pory"
	end
# 205 "data/maps/RustboroCity/scripts.pory"

# 206 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign:: @ 81E0910
# 207 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 208 "data/maps/RustboroCity/scripts.pory"
	end
# 209 "data/maps/RustboroCity/scripts.pory"

# 210 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign:: @ 81E0919
# 211 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 212 "data/maps/RustboroCity/scripts.pory"
	end
# 213 "data/maps/RustboroCity/scripts.pory"

# 214 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy:: @ 81E0922
# 215 "data/maps/RustboroCity/scripts.pory"
	lock
# 216 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 217 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 218 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 219 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 220 "data/maps/RustboroCity/scripts.pory"
	release
# 221 "data/maps/RustboroCity/scripts.pory"
	end
# 222 "data/maps/RustboroCity/scripts.pory"

# 223 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl:: @ 81E0938
# 224 "data/maps/RustboroCity/scripts.pory"
	lock
# 225 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 226 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 227 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 228 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 229 "data/maps/RustboroCity/scripts.pory"
	release
# 230 "data/maps/RustboroCity/scripts.pory"
	end
# 231 "data/maps/RustboroCity/scripts.pory"

# 232 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2:: @ 81E094E
# 233 "data/maps/RustboroCity/scripts.pory"
	lock
# 234 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 235 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 236 "data/maps/RustboroCity/scripts.pory"
	release
# 237 "data/maps/RustboroCity/scripts.pory"
	end
# 238 "data/maps/RustboroCity/scripts.pory"

# 239 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0:: @ 81E095A
# 240 "data/maps/RustboroCity/scripts.pory"
	lockall
# 241 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 242 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 243 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 244 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 245 "data/maps/RustboroCity/scripts.pory"
	end
# 246 "data/maps/RustboroCity/scripts.pory"

# 247 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1:: @ 81E0971
# 248 "data/maps/RustboroCity/scripts.pory"
	lockall
# 249 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 250 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 251 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 252 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 253 "data/maps/RustboroCity/scripts.pory"
	end
# 254 "data/maps/RustboroCity/scripts.pory"

# 255 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2:: @ 81E0988
# 256 "data/maps/RustboroCity/scripts.pory"
	lockall
# 257 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 258 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 259 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 260 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 261 "data/maps/RustboroCity/scripts.pory"
	end
# 262 "data/maps/RustboroCity/scripts.pory"

# 263 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3:: @ 81E099F
# 264 "data/maps/RustboroCity/scripts.pory"
	lockall
# 265 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 266 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 267 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 268 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 269 "data/maps/RustboroCity/scripts.pory"
	end
# 270 "data/maps/RustboroCity/scripts.pory"

# 271 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4:: @ 81E09B6
# 272 "data/maps/RustboroCity/scripts.pory"
	lockall
# 273 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 274 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 275 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 276 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 277 "data/maps/RustboroCity/scripts.pory"
	end
# 278 "data/maps/RustboroCity/scripts.pory"

# 279 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene:: @ 81E09CD
# 280 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 281 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 282 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 283 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_GRUNT
# 284 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_DEVON_EMPLOYEE
# 285 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
# 286 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 287 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_GRUNT
# 288 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 289 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 290 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 291 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 292 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 293 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 294 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 295 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 296 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
# 297 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 298 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 299 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3 @ Should be 3? Was 2
# 300 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 301 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 302 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 303 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 304 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 305 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 306 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 307 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 308 "data/maps/RustboroCity/scripts.pory"
	end
# 309 "data/maps/RustboroCity/scripts.pory"

# 310 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 311 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff:: @ 81E0A3B
# 312 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 313 "data/maps/RustboroCity/scripts.pory"
	return
# 314 "data/maps/RustboroCity/scripts.pory"

# 315 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 316 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou:: @ 81E0A44
# 317 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 318 "data/maps/RustboroCity/scripts.pory"
	return
# 319 "data/maps/RustboroCity/scripts.pory"

# 320 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 321 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp:: @ 81E0A4D
# 322 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 323 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 324 "data/maps/RustboroCity/scripts.pory"
	return
# 325 "data/maps/RustboroCity/scripts.pory"

# 326 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 327 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft:: @ 81E0A58
# 328 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 329 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 330 "data/maps/RustboroCity/scripts.pory"
	return
# 331 "data/maps/RustboroCity/scripts.pory"

# 332 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 333 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight:: @ 81E0A63
# 334 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 335 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 336 "data/maps/RustboroCity/scripts.pory"
	return
# 337 "data/maps/RustboroCity/scripts.pory"

# 338 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 339 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown:: @ 81E0A6E
# 340 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 341 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 342 "data/maps/RustboroCity/scripts.pory"
	return
# 343 "data/maps/RustboroCity/scripts.pory"

# 344 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 345 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar:: @ 81E0A79
# 346 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 347 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 348 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 349 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 350 "data/maps/RustboroCity/scripts.pory"
	return
# 351 "data/maps/RustboroCity/scripts.pory"

# 352 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 353 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended: @ 81E0A8E
# 354 "data/maps/RustboroCity/scripts.pory"
	walk_fastest_right
# 355 "data/maps/RustboroCity/scripts.pory"
	walk_fastest_right
# 356 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 357 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 358 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 359 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 360 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 361 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 362 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 363 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 364 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 365 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 366 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 367 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 368 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 369 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 370 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 371 "data/maps/RustboroCity/scripts.pory"
	step_end
# 372 "data/maps/RustboroCity/scripts.pory"

# 373 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape: @ 81E0AA0
# 374 "data/maps/RustboroCity/scripts.pory"
	walk_fastest_right
# 375 "data/maps/RustboroCity/scripts.pory"
	walk_fastest_right
# 376 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 377 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 378 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 379 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 380 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 381 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 382 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 383 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 384 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 385 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 386 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 387 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 388 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 389 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 390 "data/maps/RustboroCity/scripts.pory"
	step_end
# 391 "data/maps/RustboroCity/scripts.pory"

# 392 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1: @ 81E0AB1
# 393 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 394 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 395 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 396 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 397 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 398 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 399 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fastest_up
# 400 "data/maps/RustboroCity/scripts.pory"
	step_end
# 401 "data/maps/RustboroCity/scripts.pory"

# 402 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2: @ 81E0AB9
# 403 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 404 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 405 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 406 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 407 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 408 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 409 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 410 "data/maps/RustboroCity/scripts.pory"
	step_end
# 411 "data/maps/RustboroCity/scripts.pory"

# 412 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 413 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp: @ 81E0AC1
# 414 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 415 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 416 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 417 "data/maps/RustboroCity/scripts.pory"
	step_end
# 418 "data/maps/RustboroCity/scripts.pory"

# 419 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 420 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft: @ 81E0AC5
# 421 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 422 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 423 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 424 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 425 "data/maps/RustboroCity/scripts.pory"
	step_end
# 426 "data/maps/RustboroCity/scripts.pory"

# 427 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 428 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight: @ 81E0ACA
# 429 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 430 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 431 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 432 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 433 "data/maps/RustboroCity/scripts.pory"
	step_end
# 434 "data/maps/RustboroCity/scripts.pory"

# 435 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 436 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown: @ 81E0ACF
# 437 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 438 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 439 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 440 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 441 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 442 "data/maps/RustboroCity/scripts.pory"
	step_end
# 443 "data/maps/RustboroCity/scripts.pory"

# 444 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 445 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar: @ 81E0AD5
# 446 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 447 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 448 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 449 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 450 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 451 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 452 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fastest_down
# 453 "data/maps/RustboroCity/scripts.pory"
	step_end
# 454 "data/maps/RustboroCity/scripts.pory"

# 455 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee1:: @ 81E0ADD
# 456 "data/maps/RustboroCity/scripts.pory"
	lock
# 457 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 458 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 459 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 460 "data/maps/RustboroCity/scripts.pory"
	release
# 461 "data/maps/RustboroCity/scripts.pory"
	end
# 462 "data/maps/RustboroCity/scripts.pory"

# 463 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsSpokeToEmployee:: @ 81E0AF2
# 464 "data/maps/RustboroCity/scripts.pory"
	waitse
# 465 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 466 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 467 "data/maps/RustboroCity/scripts.pory"
	end
# 468 "data/maps/RustboroCity/scripts.pory"

# 469 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger0:: @ 81E0AFE
# 470 "data/maps/RustboroCity/scripts.pory"
	lockall
# 471 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 472 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 473 "data/maps/RustboroCity/scripts.pory"
	end
# 474 "data/maps/RustboroCity/scripts.pory"

# 475 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger1:: @ 81E0B0A
# 476 "data/maps/RustboroCity/scripts.pory"
	lockall
# 477 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 478 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 479 "data/maps/RustboroCity/scripts.pory"
	end
# 480 "data/maps/RustboroCity/scripts.pory"

# 481 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger2:: @ 81E0B16
# 482 "data/maps/RustboroCity/scripts.pory"
	lockall
# 483 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 484 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 485 "data/maps/RustboroCity/scripts.pory"
	end
# 486 "data/maps/RustboroCity/scripts.pory"

# 487 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HelpGetGoodsTrigger3:: @ 81E0B22
# 488 "data/maps/RustboroCity/scripts.pory"
	lockall
# 489 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 490 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
# 491 "data/maps/RustboroCity/scripts.pory"
	end
# 492 "data/maps/RustboroCity/scripts.pory"

# 493 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeAskToGetGoods:: @ 81E0B2E
# 494 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 0
# 495 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerUp1
# 496 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
# 497 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 498 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 2
# 499 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerDown1
# 500 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 3
# 501 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 502 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 503 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 4
# 504 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_DEVON_EMPLOYEE
# 505 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 506 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 507 "data/maps/RustboroCity/scripts.pory"
	end
# 508 "data/maps/RustboroCity/scripts.pory"

# 509 "data/maps/RustboroCity/scripts.pory"
@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
# 510 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp1:: @ 81E0B6F
# 511 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
# 512 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 513 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 514 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 515 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 516 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 517 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 518 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 519 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 520 "data/maps/RustboroCity/scripts.pory"
	return
# 521 "data/maps/RustboroCity/scripts.pory"

# 522 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft1:: @ 81E0B9B
# 523 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestLeft
# 524 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 525 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 526 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 527 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 528 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 529 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 530 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 531 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 532 "data/maps/RustboroCity/scripts.pory"
	return
# 533 "data/maps/RustboroCity/scripts.pory"

# 534 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown1:: @ 81E0BC7
# 535 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestDown
# 536 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 537 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 538 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 539 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 540 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 541 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 542 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 543 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 544 "data/maps/RustboroCity/scripts.pory"
	return
# 545 "data/maps/RustboroCity/scripts.pory"

# 546 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown1:: @ 81E0BF3
# 547 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestDown
# 548 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 549 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 550 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 551 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 552 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 553 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 554 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 555 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 556 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 557 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 558 "data/maps/RustboroCity/scripts.pory"
	return
# 559 "data/maps/RustboroCity/scripts.pory"

# 560 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown: @ 81E0C29
# 561 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 562 "data/maps/RustboroCity/scripts.pory"
	step_end
# 563 "data/maps/RustboroCity/scripts.pory"

# 564 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0:: @ 81E0C2B
# 565 "data/maps/RustboroCity/scripts.pory"
	lockall
# 566 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 567 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 568 "data/maps/RustboroCity/scripts.pory"
	end
# 569 "data/maps/RustboroCity/scripts.pory"

# 570 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1:: @ 81E0C37
# 571 "data/maps/RustboroCity/scripts.pory"
	lockall
# 572 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 573 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 574 "data/maps/RustboroCity/scripts.pory"
	end
# 575 "data/maps/RustboroCity/scripts.pory"

# 576 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2:: @ 81E0C43
# 577 "data/maps/RustboroCity/scripts.pory"
	lockall
# 578 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 579 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 580 "data/maps/RustboroCity/scripts.pory"
	end
# 581 "data/maps/RustboroCity/scripts.pory"

# 582 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3:: @ 81E0C4F
# 583 "data/maps/RustboroCity/scripts.pory"
	lockall
# 584 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 585 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 586 "data/maps/RustboroCity/scripts.pory"
	end
# 587 "data/maps/RustboroCity/scripts.pory"

# 588 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods:: @ 81E0C5B
# 589 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 0
# 590 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerUp2
# 591 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
# 592 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 593 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 2
# 594 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerDown2
# 595 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 3
# 596 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 597 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 4
# 598 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerRight
# 599 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 600 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_DREAM_BALL, 2
# 601 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 602 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_BagFull
# 603 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 604 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 605 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 606 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 607 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 6
# 608 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 609 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 255, 2, 2
# 610 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 611 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 612 "data/maps/RustboroCity/scripts.pory"
	end
# 613 "data/maps/RustboroCity/scripts.pory"

# 614 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull:: @ 81E0CD3
# 615 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 616 "data/maps/RustboroCity/scripts.pory"
	return
# 617 "data/maps/RustboroCity/scripts.pory"

# 618 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2:: @ 81E0CDC
# 619 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
# 620 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 621 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 622 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 623 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 624 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 625 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 626 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 627 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 628 "data/maps/RustboroCity/scripts.pory"
	return
# 629 "data/maps/RustboroCity/scripts.pory"

# 630 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2:: @ 81E0D08
# 631 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestRight
# 632 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 633 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 634 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 635 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 636 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 637 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 638 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 639 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 640 "data/maps/RustboroCity/scripts.pory"
	return
# 641 "data/maps/RustboroCity/scripts.pory"

# 642 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2:: @ 81E0D34
# 643 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestDown
# 644 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 645 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 646 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 647 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 648 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 649 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 650 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 651 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 652 "data/maps/RustboroCity/scripts.pory"
	return
# 653 "data/maps/RustboroCity/scripts.pory"

# 654 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2:: @ 81E0D60
# 655 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestDown
# 656 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 657 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 658 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 659 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 660 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 661 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 662 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 663 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 664 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 665 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 666 "data/maps/RustboroCity/scripts.pory"
	return
# 667 "data/maps/RustboroCity/scripts.pory"

# 668 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight:: @ 81E0D96
# 669 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestLeft
# 670 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 671 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 672 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 673 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 674 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 675 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 676 "data/maps/RustboroCity/scripts.pory"
	return
# 677 "data/maps/RustboroCity/scripts.pory"

# 678 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival:: @ 81E0DB8
# 679 "data/maps/RustboroCity/scripts.pory"
	lockall
# 680 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 681 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 682 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 683 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 684 "data/maps/RustboroCity/scripts.pory"

# 685 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic:: @ 81E0DD1
# 686 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 687 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, MALE
# 688 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_PlayMayMusic
# 689 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, FEMALE
# 690 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_PlayBrendanMusic
# 691 "data/maps/RustboroCity/scripts.pory"
	return
# 692 "data/maps/RustboroCity/scripts.pory"

# 693 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic:: @ 81E0DE9
# 694 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 695 "data/maps/RustboroCity/scripts.pory"
	return
# 696 "data/maps/RustboroCity/scripts.pory"

# 697 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic:: @ 81E0DEE
# 698 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 699 "data/maps/RustboroCity/scripts.pory"
	return
# 700 "data/maps/RustboroCity/scripts.pory"

# 701 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0:: @ 81E0DF3
# 702 "data/maps/RustboroCity/scripts.pory"
	lockall
# 703 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 704 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 705 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 706 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 707 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 708 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 709 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 710 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 711 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 712 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 713 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 714 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 715 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 716 "data/maps/RustboroCity/scripts.pory"

# 717 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1:: @ 81E0E33
# 718 "data/maps/RustboroCity/scripts.pory"
	lockall
# 719 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 720 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 721 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 722 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 723 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 724 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 725 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 726 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 727 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 728 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 729 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 730 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 731 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 732 "data/maps/RustboroCity/scripts.pory"

# 733 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2:: @ 81E0E73
# 734 "data/maps/RustboroCity/scripts.pory"
	lockall
# 735 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 736 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 737 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 738 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 739 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 740 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 741 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 742 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 743 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 744 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 745 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 746 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 747 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 748 "data/maps/RustboroCity/scripts.pory"

# 749 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3:: @ 81E0EB3
# 750 "data/maps/RustboroCity/scripts.pory"
	lockall
# 751 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 752 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 753 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 754 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 755 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 756 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 757 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 758 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 759 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 760 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 761 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 762 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 763 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 764 "data/maps/RustboroCity/scripts.pory"

# 765 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4:: @ 81E0EF3
# 766 "data/maps/RustboroCity/scripts.pory"
	lockall
# 767 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 768 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 769 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 770 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 771 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 772 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 773 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 774 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 775 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 776 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 777 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 778 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 779 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 780 "data/maps/RustboroCity/scripts.pory"

# 781 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5:: @ 81E0F33
# 782 "data/maps/RustboroCity/scripts.pory"
	lockall
# 783 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 784 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 785 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 786 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 787 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 788 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 789 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 790 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 791 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 792 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 793 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 794 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 795 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 796 "data/maps/RustboroCity/scripts.pory"

# 797 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6:: @ 81E0F73
# 798 "data/maps/RustboroCity/scripts.pory"
	lockall
# 799 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 800 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 801 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 802 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 803 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 804 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 805 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 806 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 807 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 808 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 809 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 810 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 811 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 812 "data/maps/RustboroCity/scripts.pory"

# 813 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7:: @ 81E0FB3
# 814 "data/maps/RustboroCity/scripts.pory"
	lockall
# 815 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 816 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 817 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 818 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 819 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 820 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 821 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 822 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 823 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 824 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 825 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 826 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 827 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 828 "data/maps/RustboroCity/scripts.pory"

# 829 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter:: @ 81E0FF3
# 830 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 831 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, MALE
# 832 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_MayEncounter
# 833 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, FEMALE
# 834 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_BrendanEncounter
# 835 "data/maps/RustboroCity/scripts.pory"
	end
# 836 "data/maps/RustboroCity/scripts.pory"

# 837 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter:: @ 81E100B
# 838 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 839 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 840 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 841 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 842 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 843 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 844 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 845 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 846 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 847 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 848 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 849 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 850 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 10
# 851 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 852 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 853 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 854 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, YES
# 855 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_BattleMay
# 856 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 857 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 858 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 859 "data/maps/RustboroCity/scripts.pory"
	end
# 860 "data/maps/RustboroCity/scripts.pory"

# 861 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle:: @ 81E1070
# 862 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 863 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 864 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, YES
# 865 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_BattleMay
# 866 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 867 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 868 "data/maps/RustboroCity/scripts.pory"
	end
# 869 "data/maps/RustboroCity/scripts.pory"

# 870 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay:: @ 81E1092
# 871 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 872 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 873 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 874 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 875 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 876 "data/maps/RustboroCity/scripts.pory"
	end
# 877 "data/maps/RustboroCity/scripts.pory"

# 878 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint:: @ 81E10C1
# 879 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 880 "data/maps/RustboroCity/scripts.pory"
	compare VAR_0x8008, 0
# 881 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_RestoreBgm
# 882 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 883 "data/maps/RustboroCity/scripts.pory"
	end
# 884 "data/maps/RustboroCity/scripts.pory"

# 885 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm:: @ 81E10D6
# 886 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 887 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 888 "data/maps/RustboroCity/scripts.pory"
	return
# 889 "data/maps/RustboroCity/scripts.pory"

# 890 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko:: @ 81E10DB
# 891 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 892 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 893 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 894 "data/maps/RustboroCity/scripts.pory"
	end
# 895 "data/maps/RustboroCity/scripts.pory"

# 896 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic:: @ 81E10EE
# 897 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 898 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 899 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 900 "data/maps/RustboroCity/scripts.pory"
	end
# 901 "data/maps/RustboroCity/scripts.pory"

# 902 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip:: @ 81E1101
# 903 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 904 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 905 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 906 "data/maps/RustboroCity/scripts.pory"
	end
# 907 "data/maps/RustboroCity/scripts.pory"

# 908 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter:: @ 81E1114
# 909 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 910 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 911 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 912 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 913 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 914 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 915 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 916 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 917 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 918 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 919 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 920 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 921 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 10
# 922 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 923 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 924 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, YES
# 925 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_BattleBrendan
# 926 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 927 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 928 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 929 "data/maps/RustboroCity/scripts.pory"
	end
# 930 "data/maps/RustboroCity/scripts.pory"

# 931 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle:: @ 81E1174
# 932 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 933 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RESULT, YES
# 934 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq RustboroCity_EventScript_BattleBrendan
# 935 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 936 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 937 "data/maps/RustboroCity/scripts.pory"
	end
# 938 "data/maps/RustboroCity/scripts.pory"

# 939 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan:: @ 81E1191
# 940 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 941 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 942 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 943 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 944 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 945 "data/maps/RustboroCity/scripts.pory"
	end
# 946 "data/maps/RustboroCity/scripts.pory"

# 947 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint:: @ 81E11C0
# 948 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 949 "data/maps/RustboroCity/scripts.pory"
	compare VAR_0x8008, 0
# 950 "data/maps/RustboroCity/scripts.pory"
	call_if_eq RustboroCity_EventScript_RestoreBgm
# 951 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 952 "data/maps/RustboroCity/scripts.pory"
	end
# 953 "data/maps/RustboroCity/scripts.pory"

# 954 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko:: @ 81E11D5
# 955 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 956 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 957 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 958 "data/maps/RustboroCity/scripts.pory"
	end
# 959 "data/maps/RustboroCity/scripts.pory"

# 960 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic:: @ 81E11E8
# 961 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 962 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 963 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 964 "data/maps/RustboroCity/scripts.pory"
	end
# 965 "data/maps/RustboroCity/scripts.pory"

# 966 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 967 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 968 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 969 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 970 "data/maps/RustboroCity/scripts.pory"
	end
# 971 "data/maps/RustboroCity/scripts.pory"

# 972 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Pokecall_Trigger1::
# 973 "data/maps/RustboroCity/scripts.pory"
	lockall
# 974 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_ROXANNE, Common_Movement_WalkInPlaceFastestDown
# 975 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 976 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 977 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PokecallMoveRoxanne
# 978 "data/maps/RustboroCity/scripts.pory"

# 979 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Roxanne::
# 980 "data/maps/RustboroCity/scripts.pory"
	lockall
# 981 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 982 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PokecallMoveRoxanne
# 983 "data/maps/RustboroCity/scripts.pory"

# 984 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PokecallMoveRoxanne::
# 985 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RoxanneOhHello, MSGBOX_DEFAULT
# 986 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 987 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 988 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 989 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredAnorith, MSGBOX_DEFAULT
# 990 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 991 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 992 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 993 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Movement_RoxanneOneMoreThing, MSGBOX_DEFAULT
# 994 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 995 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 996 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 997 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 998 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 999 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1000 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1001 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RoxanneBye, MSGBOX_AUTOCLOSE
# 1002 "data/maps/RustboroCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 1003 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_ROXANNE
# 1004 "data/maps/RustboroCity/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 1005 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 9
# 1006 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1007 "data/maps/RustboroCity/scripts.pory"
	end
# 1008 "data/maps/RustboroCity/scripts.pory"

# 1009 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1010 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1011 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1012 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1013 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1014 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1015 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1016 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1017 "data/maps/RustboroCity/scripts.pory"

# 1018 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1019 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1020 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1021 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1022 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1023 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1024 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1025 "data/maps/RustboroCity/scripts.pory"

# 1026 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1027 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1028 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1029 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1030 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1031 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1032 "data/maps/RustboroCity/scripts.pory"

# 1033 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1034 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1035 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1036 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1037 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1038 "data/maps/RustboroCity/scripts.pory"

# 1039 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4: @ 81E1224
# 1040 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1041 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1042 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1043 "data/maps/RustboroCity/scripts.pory"

# 1044 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5: @ 81E1227
# 1045 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1046 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1047 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1048 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1049 "data/maps/RustboroCity/scripts.pory"

# 1050 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6: @ 81E122B
# 1051 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1052 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1053 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1054 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1055 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1056 "data/maps/RustboroCity/scripts.pory"

# 1057 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7: @ 81E1230
# 1058 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1059 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1060 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1061 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1062 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1063 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1064 "data/maps/RustboroCity/scripts.pory"

# 1065 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1:: @ 81E1236
# 1066 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1067 "data/maps/RustboroCity/scripts.pory"
	end
# 1068 "data/maps/RustboroCity/scripts.pory"

# 1069 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RoxanneOhHello:
# 1070 "data/maps/RustboroCity/scripts.pory"
	.string "Roxanne: Oh, hello, {PLAYER}.\p"
# 1071 "data/maps/RustboroCity/scripts.pory"
	.string "I see you've got a PokéNav! Did you\n"
# 1072 "data/maps/RustboroCity/scripts.pory"
	.string "know about its PokéCall function?\p"
# 1073 "data/maps/RustboroCity/scripts.pory"
	.string "Let me explain: you can register\n"
# 1074 "data/maps/RustboroCity/scripts.pory"
	.string "Pokémon as well as people.\p"
# 1075 "data/maps/RustboroCity/scripts.pory"
	.string "When you're out in the field, you'll\n"
# 1076 "data/maps/RustboroCity/scripts.pory"
	.string "be able to call registered Pokémon\l"
# 1077 "data/maps/RustboroCity/scripts.pory"
	.string "to help you get through obstacles, like\l"
# 1078 "data/maps/RustboroCity/scripts.pory"
	.string "the small trees in Petalburg Woods.\p"
# 1079 "data/maps/RustboroCity/scripts.pory"
	.string "Here, I'll register my Anorith for\n"
# 1080 "data/maps/RustboroCity/scripts.pory"
	.string "you.\p"
# 1081 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …\n"
# 1082 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … Click!$"
# 1083 "data/maps/RustboroCity/scripts.pory"

# 1084 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RoxanneOneMoreThing:
# 1085 "data/maps/RustboroCity/scripts.pory"
	.string "Use it in the same way you'd use Cut.\p"
# 1086 "data/maps/RustboroCity/scripts.pory"
	.string "One more thing: I'd rather not think\n"
# 1087 "data/maps/RustboroCity/scripts.pory"
	.string "that I can't beat you.\p"
# 1088 "data/maps/RustboroCity/scripts.pory"
	.string "I promise, I will shape up my Gym\n"
# 1089 "data/maps/RustboroCity/scripts.pory"
	.string "so that you may challenge us again.\p"
# 1090 "data/maps/RustboroCity/scripts.pory"
	.string "I hope you'll be looking forward to\n"
# 1091 "data/maps/RustboroCity/scripts.pory"
	.string "that occasion as much as me!\p"
# 1092 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …\n"
# 1093 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … Click!$"
# 1094 "data/maps/RustboroCity/scripts.pory"

# 1095 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredAnorith:
# 1096 "data/maps/RustboroCity/scripts.pory"
	.string "Registered Roxanne's Anorith\n"
# 1097 "data/maps/RustboroCity/scripts.pory"
	.string "in the PokéNav.$"
# 1098 "data/maps/RustboroCity/scripts.pory"

# 1099 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredRoxanne:
# 1100 "data/maps/RustboroCity/scripts.pory"
	.string "Registered Gym Leader Roxanne\n"
# 1101 "data/maps/RustboroCity/scripts.pory"
	.string "in the PokéNav.$"
# 1102 "data/maps/RustboroCity/scripts.pory"

# 1103 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RoxanneBye:
# 1104 "data/maps/RustboroCity/scripts.pory"
	.string "Good luck in your next Gym Battle,\n"
# 1105 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}!\p"
# 1106 "data/maps/RustboroCity/scripts.pory"
	.string "Goodbye for now!$"
# 1107 "data/maps/RustboroCity/scripts.pory"

# 1108 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon: @ 81E123F
# 1109 "data/maps/RustboroCity/scripts.pory"
	.string "The Devon Corporation…\n"
# 1110 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to Devon.\p"
# 1111 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1112 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1113 "data/maps/RustboroCity/scripts.pory"

# 1114 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner: @ 81E12AC
# 1115 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1116 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1117 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1118 "data/maps/RustboroCity/scripts.pory"

# 1119 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym: @ 81E130D
# 1120 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the Pokémon Gym\n"
# 1121 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1122 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny Gym Badge\n"
# 1123 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess Trainers begin to\l"
# 1124 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1125 "data/maps/RustboroCity/scripts.pory"

# 1126 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge: @ 81E139E
# 1127 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's Rustboro's Gym Badge!\p"
# 1128 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the Pokémon Gym Badges,\n"
# 1129 "data/maps/RustboroCity/scripts.pory"
	.string "Rustboro's is the coolest, I'd say.$"
# 1130 "data/maps/RustboroCity/scripts.pory"

# 1131 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere: @ 81E1407
# 1132 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1133 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1134 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1135 "data/maps/RustboroCity/scripts.pory"
	.string "Pokémon Trainer's School?$"
# 1136 "data/maps/RustboroCity/scripts.pory"

# 1137 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire: @ 81E1480
# 1138 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the Gym Leader, but…\p"
# 1139 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1140 "data/maps/RustboroCity/scripts.pory"
	.string "my Fire-type Pokémon…\p"
# 1141 "data/maps/RustboroCity/scripts.pory"
	.string "Fire-type Pokémon don't match up\n"
# 1142 "data/maps/RustboroCity/scripts.pory"
	.string "well against Rock-type Pokémon…$"
# 1143 "data/maps/RustboroCity/scripts.pory"

# 1144 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel: @ 81E1520
# 1145 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor Mr. Briney lives in\n"
# 1146 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1147 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1148 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1149 "data/maps/RustboroCity/scripts.pory"

# 1150 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko: @ 81E1589
# 1151 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor Mr. Briney lives in\n"
# 1152 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1153 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1154 "data/maps/RustboroCity/scripts.pory"
	.string "Slateport for his pet, Peeko.\p"
# 1155 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1156 "data/maps/RustboroCity/scripts.pory"
	.string "that Peeko.$"
# 1157 "data/maps/RustboroCity/scripts.pory"

# 1158 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon: @ 81E1633
# 1159 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have Pokémon with you, too.\p"
# 1160 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1161 "data/maps/RustboroCity/scripts.pory"
	.string "places with Pokémon, too.$"
# 1162 "data/maps/RustboroCity/scripts.pory"

# 1163 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool: @ 81E1695
# 1164 "data/maps/RustboroCity/scripts.pory"
	.string "Pokémon Trainer's School!\p"
# 1165 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1166 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare Pokémon easily?$"
# 1167 "data/maps/RustboroCity/scripts.pory"

# 1168 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp: @ 81E16F4
# 1169 "data/maps/RustboroCity/scripts.pory"
	.string "If a Pokémon gains experience in\n"
# 1170 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1171 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1172 "data/maps/RustboroCity/scripts.pory"

# 1173 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape: @ 81E174B
# 1174 "data/maps/RustboroCity/scripts.pory"
	.string "A Pokémon changes shape?\n"
# 1175 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1176 "data/maps/RustboroCity/scripts.pory"

# 1177 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast: @ 81E1789
# 1178 "data/maps/RustboroCity/scripts.pory"
	.string "A Pokémon you get in a trade from\n"
# 1179 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1180 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain Gym\n"
# 1181 "data/maps/RustboroCity/scripts.pory"
	.string "Badges, it may not obey you…$"
# 1182 "data/maps/RustboroCity/scripts.pory"

# 1183 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay: @ 81E17FE
# 1184 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1185 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1186 "data/maps/RustboroCity/scripts.pory"

# 1187 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods: @ 81E1817
# 1188 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1189 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my Goods!$"
# 1190 "data/maps/RustboroCity/scripts.pory"

# 1191 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed: @ 81E183E
# 1192 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1193 "data/maps/RustboroCity/scripts.pory"
	.string "You're that fantastic Trainer who\n"
# 1194 "data/maps/RustboroCity/scripts.pory"
	.string "helped me in Petalburg Woods!\p"
# 1195 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by Team Aqua!\n"
# 1196 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the Devon Parts back!\p"
# 1197 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1198 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1199 "data/maps/RustboroCity/scripts.pory"

# 1200 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel: @ 81E1904
# 1201 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1202 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1203 "data/maps/RustboroCity/scripts.pory"

# 1204 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou: @ 81E194D
# 1205 "data/maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1206 "data/maps/RustboroCity/scripts.pory"
	.string "The Devon Parts?\p"
# 1207 "data/maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1208 "data/maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1209 "data/maps/RustboroCity/scripts.pory"
	.string "You really are a great Trainer!\p"
# 1210 "data/maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1211 "data/maps/RustboroCity/scripts.pory"
	.string "these Dream Balls!$"
# 1212 "data/maps/RustboroCity/scripts.pory"

# 1213 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems: @ 81E19E5
# 1214 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1215 "data/maps/RustboroCity/scripts.pory"
	.string "I can't give you these Dream Balls.$"
# 1216 "data/maps/RustboroCity/scripts.pory"

# 1217 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe: @ 81E1A21
# 1218 "data/maps/RustboroCity/scripts.pory"
	.string "Devon Corp. worked with a scientist\n"
# 1219 "data/maps/RustboroCity/scripts.pory"
	.string "from the Unova Region to develop\l"
# 1220 "data/maps/RustboroCity/scripts.pory"
	.string "those modified Dream Balls.\p"
# 1221 "data/maps/RustboroCity/scripts.pory"
	.string "Any Pokémon captured in one will\n"
# 1222 "data/maps/RustboroCity/scripts.pory"
	.string "receive its Hidden Ability!\p"
# 1223 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1224 "data/maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1225 "data/maps/RustboroCity/scripts.pory"

# 1226 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister: @ 81E1A49
# 1227 "data/maps/RustboroCity/scripts.pory"
	.string "May: Oh, hi, {PLAYER}{KUN}!\p"
# 1228 "data/maps/RustboroCity/scripts.pory"
	.string "You had a Match Call feature put\n"
# 1229 "data/maps/RustboroCity/scripts.pory"
	.string "on your PokéNav!\p"
# 1230 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1231 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1232 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1233 "data/maps/RustboroCity/scripts.pory"

# 1234 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay: @ 81E1ADB
# 1235 "data/maps/RustboroCity/scripts.pory"
	.string "Registered May\n"
# 1236 "data/maps/RustboroCity/scripts.pory"
	.string "in the PokéNav.$"
# 1237 "data/maps/RustboroCity/scripts.pory"

# 1238 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle: @ 81E1AFA
# 1239 "data/maps/RustboroCity/scripts.pory"
	.string "May: Oh, by the way, I passed\n"
# 1240 "data/maps/RustboroCity/scripts.pory"
	.string "Mr. Briney in Petalburg Woods.\p"
# 1241 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1242 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1243 "data/maps/RustboroCity/scripts.pory"
	.string "How's your Pokédex coming along,\n"
# 1244 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1245 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1246 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1247 "data/maps/RustboroCity/scripts.pory"

# 1248 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough: @ 81E1BD3
# 1249 "data/maps/RustboroCity/scripts.pory"
	.string "May: Oh, what's the matter?\p"
# 1250 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1251 "data/maps/RustboroCity/scripts.pory"
	.string "Pokémon very much?\p"
# 1252 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a Trainer!$"
# 1253 "data/maps/RustboroCity/scripts.pory"

# 1254 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle: @ 81E1C48
# 1255 "data/maps/RustboroCity/scripts.pory"
	.string "May: So, what do you think?\n"
# 1256 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1257 "data/maps/RustboroCity/scripts.pory"

# 1258 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose: @ 81E1C84
# 1259 "data/maps/RustboroCity/scripts.pory"
	.string "May: You just became a Trainer,\n"
# 1260 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1261 "data/maps/RustboroCity/scripts.pory"

# 1262 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat: @ 81E1CC1
# 1263 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1264 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1265 "data/maps/RustboroCity/scripts.pory"

# 1266 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint: @ 81E1CE7
# 1267 "data/maps/RustboroCity/scripts.pory"
	.string "May: Oh, by the way, Mr. Briney, who\n"
# 1268 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1269 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1270 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but Mr. Briney\l"
# 1271 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1272 "data/maps/RustboroCity/scripts.pory"

# 1273 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister: @ 81E1D7D
# 1274 "data/maps/RustboroCity/scripts.pory"
	.string "Brendan: Oh, hey, {PLAYER}!\p"
# 1275 "data/maps/RustboroCity/scripts.pory"
	.string "You had a Match Call feature put\n"
# 1276 "data/maps/RustboroCity/scripts.pory"
	.string "on your PokéNav! Cool!\p"
# 1277 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1278 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1279 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1280 "data/maps/RustboroCity/scripts.pory"

# 1281 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan: @ 81E1E11
# 1282 "data/maps/RustboroCity/scripts.pory"
	.string "Registered Brendan\n"
# 1283 "data/maps/RustboroCity/scripts.pory"
	.string "in the PokéNav.$"
# 1284 "data/maps/RustboroCity/scripts.pory"

# 1285 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle: @ 81E1E34
# 1286 "data/maps/RustboroCity/scripts.pory"
	.string "Brendan: By the way, {PLAYER}, I walked\n"
# 1287 "data/maps/RustboroCity/scripts.pory"
	.string "by Mr. Briney in Petalburg Woods.\p"
# 1288 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1289 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1290 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your Pokédex?\n"
# 1291 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1292 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1293 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1294 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1295 "data/maps/RustboroCity/scripts.pory"

# 1296 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon: @ 81E1F2F
# 1297 "data/maps/RustboroCity/scripts.pory"
	.string "Brendan: What's the matter? Don't have\n"
# 1298 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your Pokémon?$"
# 1299 "data/maps/RustboroCity/scripts.pory"

# 1300 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle: @ 81E1F76
# 1301 "data/maps/RustboroCity/scripts.pory"
	.string "Brendan: What's up?\n"
# 1302 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1303 "data/maps/RustboroCity/scripts.pory"

# 1304 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy: @ 81E1FA9
# 1305 "data/maps/RustboroCity/scripts.pory"
	.string "Brendan: I know you just became\n"
# 1306 "data/maps/RustboroCity/scripts.pory"
	.string "a Trainer, but I won't go easy!$"
# 1307 "data/maps/RustboroCity/scripts.pory"

# 1308 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat: @ 81E1FE9
# 1309 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1310 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1311 "data/maps/RustboroCity/scripts.pory"

# 1312 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint: @ 81E2002
# 1313 "data/maps/RustboroCity/scripts.pory"
	.string "Brendan: By the way, you know\n"
# 1314 "data/maps/RustboroCity/scripts.pory"
	.string "Mr. Briney? The guy I just passed?\p"
# 1315 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1316 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1317 "data/maps/RustboroCity/scripts.pory"
	.string "Mr. Briney was once a great sailor.$"
# 1318 "data/maps/RustboroCity/scripts.pory"

# 1319 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion: @ 81E20A6
# 1320 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1321 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1322 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1323 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1324 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1325 "data/maps/RustboroCity/scripts.pory"

# 1326 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign: @ 81E2128
# 1327 "data/maps/RustboroCity/scripts.pory"
	.string "Devon Corporation\p"
# 1328 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1329 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1330 "data/maps/RustboroCity/scripts.pory"

# 1331 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign: @ 81E2167
# 1332 "data/maps/RustboroCity/scripts.pory"
	.string "Rustboro City Pokémon Gym\n"
# 1333 "data/maps/RustboroCity/scripts.pory"
	.string "Leader: Roxanne\p"
# 1334 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1335 "data/maps/RustboroCity/scripts.pory"

# 1336 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign: @ 81E21B3
# 1337 "data/maps/RustboroCity/scripts.pory"
	.string "Devon Corp. Branch Office\p"
# 1338 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to Devon employees\n"
# 1339 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1340 "data/maps/RustboroCity/scripts.pory"

# 1341 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign: @ 81E220B
# 1342 "data/maps/RustboroCity/scripts.pory"
	.string "Rustboro City\p"
# 1343 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1344 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1345 "data/maps/RustboroCity/scripts.pory"

# 1346 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign: @ 81E2253
# 1347 "data/maps/RustboroCity/scripts.pory"
	.string "Pokémon Trainer's School\p"
# 1348 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1349 "data/maps/RustboroCity/scripts.pory"
	.string "Pokémon!”$"
# 1350 "data/maps/RustboroCity/scripts.pory"

# 1351 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse: @ 81E2296
# 1352 "data/maps/RustboroCity/scripts.pory"
	.string "Cutter's House$"
# 1353 "data/maps/RustboroCity/scripts.pory"

# 1354 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature: @ 81E22A5
# 1355 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1356 "data/maps/RustboroCity/scripts.pory"
	.string "for the PokéNav…\p"
# 1357 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1358 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that PokéNav?\n"
# 1359 "data/maps/RustboroCity/scripts.pory"
	.string "The one our President gave you?$"
# 1360 "data/maps/RustboroCity/scripts.pory"

# 1361 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone: @ 81E2331
# 1362 "data/maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1363 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1364 "data/maps/RustboroCity/scripts.pory"
	.string "Match Call to your PokéNav.\p"
# 1365 "data/maps/RustboroCity/scripts.pory"
	.string "Using the Match Call feature,\n"
# 1366 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1367 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your PokéNav.\p"
# 1368 "data/maps/RustboroCity/scripts.pory"

# 1369 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav: @ 81E2449
# 1370 "data/maps/RustboroCity/scripts.pory"
	.string "You should tell Roxanne\n"
# 1371 "data/maps/RustboroCity/scripts.pory"
	.string "about your new gadget!$"
# 1372 "data/maps/RustboroCity/scripts.pory"

# 1373 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork: @ 81E2464
# 1374 "data/maps/RustboroCity/scripts.pory"
	.string "I added Mr. Stone's number,\n"
# 1375 "data/maps/RustboroCity/scripts.pory"
	.string "Feel free to call him!\p"
# 1376 "data/maps/RustboroCity/scripts.pory"
	.string "Have fun using the PokéNav!$"
# 1377 "data/maps/RustboroCity/scripts.pory"

# 1378 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle: @ 81E249D
# 1379 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1380 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1381 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another Trainer.\p"
# 1382 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two Trainers\n"
# 1383 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more Pokémon,\l"
# 1384 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1385 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1386 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two Trainers by yourself?$"
