# 1 "data/maps/Route116/scripts.pory"

# 2 "data/maps/Route116/scripts.pory"
.set LOCALID_BRINEY, 9
# 3 "data/maps/Route116/scripts.pory"
.set LOCALID_WANDAS_BF_OUTSIDE, 17
# 4 "data/maps/Route116/scripts.pory"

# 5 "data/maps/Route116/scripts.pory"
Route116_MapScripts:: @ 81F2C0C
# 6 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
# 7 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
# 8 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
# 9 "data/maps/Route116/scripts.pory"
	.byte 0
# 10 "data/maps/Route116/scripts.pory"

# 11 "data/maps/Route116/scripts.pory"
Route116_OnTransition: @ 81F2C1C
# 12 "data/maps/Route116/scripts.pory"
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
# 13 "data/maps/Route116/scripts.pory"
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 14 "data/maps/Route116/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
# 15 "data/maps/Route116/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH
# 16 "data/maps/Route116/scripts.pory"
	call_if_eq AbnormalWeather_StartGroudonWeather
# 17 "data/maps/Route116/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH
# 18 "data/maps/Route116/scripts.pory"
	call_if_eq AbnormalWeather_StartGroudonWeather
# 19 "data/maps/Route116/scripts.pory"
	end
# 20 "data/maps/Route116/scripts.pory"

# 21 "data/maps/Route116/scripts.pory"
Route116_EventScript_SetWandasBoyfriendPos:: @ 81F2C47
# 22 "data/maps/Route116/scripts.pory"
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
# 23 "data/maps/Route116/scripts.pory"
	return
# 24 "data/maps/Route116/scripts.pory"

# 25 "data/maps/Route116/scripts.pory"
Route116_OnLoad: @ 81F2C4F
# 26 "data/maps/Route116/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH
# 27 "data/maps/Route116/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute116North
# 28 "data/maps/Route116/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH
# 29 "data/maps/Route116/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute116South
# 30 "data/maps/Route116/scripts.pory"
	end
# 31 "data/maps/Route116/scripts.pory"

# 32 "data/maps/Route116/scripts.pory"
Route116_OnFrame: @ 81F2C66
# 33 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 34 "data/maps/Route116/scripts.pory"
	.2byte 0
# 35 "data/maps/Route116/scripts.pory"

# 36 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend:: @ 81F2C70
# 37 "data/maps/Route116/scripts.pory"
	lock
# 38 "data/maps/Route116/scripts.pory"
	faceplayer
# 39 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 40 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 41 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 42 "data/maps/Route116/scripts.pory"
	release
# 43 "data/maps/Route116/scripts.pory"
	end
# 44 "data/maps/Route116/scripts.pory"

# 45 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel:: @ 81F2C8E
# 46 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 47 "data/maps/Route116/scripts.pory"
	release
# 48 "data/maps/Route116/scripts.pory"
	end
# 49 "data/maps/Route116/scripts.pory"

# 50 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel:: @ 81F2C98
# 51 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 52 "data/maps/Route116/scripts.pory"
	release
# 53 "data/maps/Route116/scripts.pory"
	end
# 54 "data/maps/Route116/scripts.pory"

# 55 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee:: @ 81F2CA2
# 56 "data/maps/Route116/scripts.pory"
	lock
# 57 "data/maps/Route116/scripts.pory"
	faceplayer
# 58 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveAggroniteAgain
# 59 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 60 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveAggronite
# 61 "data/maps/Route116/scripts.pory"
	end
# 62 "data/maps/Route116/scripts.pory"

# 63 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveAggronite:: @ 81F2CBB
# 64 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 65 "data/maps/Route116/scripts.pory"
	givecustommon SPECIES_AGGRON, 30, ITEM_AGGRONITE, ITEM_HEAVY_BALL, NATURE_ADAMANT, 0, 252, 252, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_HEAVY_SLAM, MOVE_ICE_PUNCH, MOVE_SLACK_OFF, MOVE_HIGH_HORSEPOWER, TRUE
# 66 "data/maps/Route116/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 67 "data/maps/Route116/scripts.pory"
	message Route116_EventScript_Text_Got_Aggron
# 68 "data/maps/Route116/scripts.pory"
	waitfanfare
# 69 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_AlsoNeedKeystone, MSGBOX_DEFAULT
# 70 "data/maps/Route116/scripts.pory"
	closemessage
# 71 "data/maps/Route116/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 72 "data/maps/Route116/scripts.pory"
	call_if_eq Route116_EventScript_DevonEmployeeExit
# 73 "data/maps/Route116/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 74 "data/maps/Route116/scripts.pory"
	call_if_eq Route116_EventScript_DevonEmployeeExit
# 75 "data/maps/Route116/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 76 "data/maps/Route116/scripts.pory"
	call_if_eq Route116_EventScript_DevonEmployeeExit
# 77 "data/maps/Route116/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 78 "data/maps/Route116/scripts.pory"
	call_if_eq Route116_EventScript_DevonEmployeeExitEast
# 79 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 80 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 81 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_AGGRONITE
# 82 "data/maps/Route116/scripts.pory"
	release
# 83 "data/maps/Route116/scripts.pory"
	end
# 84 "data/maps/Route116/scripts.pory"

# 85 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit:: @ 81F2D15
# 86 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 87 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 88 "data/maps/Route116/scripts.pory"
	return
# 89 "data/maps/Route116/scripts.pory"

# 90 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast:: @ 81F2D20
# 91 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 92 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 93 "data/maps/Route116/scripts.pory"
	return
# 94 "data/maps/Route116/scripts.pory"

# 95 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveAggroniteAgain:: @ 81F2D2B
# 96 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 97 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveAggronite
# 98 "data/maps/Route116/scripts.pory"
	end
# 99 "data/maps/Route116/scripts.pory"

# 100 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForAggronite:: @ 81F2D39
# 101 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 102 "data/maps/Route116/scripts.pory"
	release
# 103 "data/maps/Route116/scripts.pory"
	end
# 104 "data/maps/Route116/scripts.pory"

# 105 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit: @ 81F2D43
# 106 "data/maps/Route116/scripts.pory"
	walk_left
# 107 "data/maps/Route116/scripts.pory"
	walk_left
# 108 "data/maps/Route116/scripts.pory"
	walk_left
# 109 "data/maps/Route116/scripts.pory"
	walk_left
# 110 "data/maps/Route116/scripts.pory"
	walk_left
# 111 "data/maps/Route116/scripts.pory"
	walk_left
# 112 "data/maps/Route116/scripts.pory"
	walk_left
# 113 "data/maps/Route116/scripts.pory"
	walk_left
# 114 "data/maps/Route116/scripts.pory"
	step_end
# 115 "data/maps/Route116/scripts.pory"

# 116 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast: @ 81F2D4C
# 117 "data/maps/Route116/scripts.pory"
	walk_down
# 118 "data/maps/Route116/scripts.pory"
	walk_left
# 119 "data/maps/Route116/scripts.pory"
	walk_left
# 120 "data/maps/Route116/scripts.pory"
	walk_left
# 121 "data/maps/Route116/scripts.pory"
	walk_left
# 122 "data/maps/Route116/scripts.pory"
	walk_left
# 123 "data/maps/Route116/scripts.pory"
	walk_left
# 124 "data/maps/Route116/scripts.pory"
	walk_left
# 125 "data/maps/Route116/scripts.pory"
	walk_left
# 126 "data/maps/Route116/scripts.pory"
	walk_left
# 127 "data/maps/Route116/scripts.pory"
	step_end
# 128 "data/maps/Route116/scripts.pory"

# 129 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro:: @ 81F2D57
# 130 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 131 "data/maps/Route116/scripts.pory"
	end
# 132 "data/maps/Route116/scripts.pory"

# 133 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign:: @ 81F2D60
# 134 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 135 "data/maps/Route116/scripts.pory"
	end
# 136 "data/maps/Route116/scripts.pory"

# 137 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign:: @ 81F2D69
# 138 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 139 "data/maps/Route116/scripts.pory"
	end
# 140 "data/maps/Route116/scripts.pory"

# 141 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution:: @ 81F2D72
# 142 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 143 "data/maps/Route116/scripts.pory"
	end
# 144 "data/maps/Route116/scripts.pory"

# 145 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets:: @ 81F2D7B
# 146 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 147 "data/maps/Route116/scripts.pory"
	end
# 148 "data/maps/Route116/scripts.pory"

# 149 "data/maps/Route116/scripts.pory"
Route116_EventScript_Briney:: @ 81F2D84
# 150 "data/maps/Route116/scripts.pory"
	lock
# 151 "data/maps/Route116/scripts.pory"
	faceplayer
# 152 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 153 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 154 "data/maps/Route116/scripts.pory"
	release
# 155 "data/maps/Route116/scripts.pory"
	end
# 156 "data/maps/Route116/scripts.pory"

# 157 "data/maps/Route116/scripts.pory"
Route116_EventScript_BrineyTrigger:: @ 81F2D95
# 158 "data/maps/Route116/scripts.pory"
	lockall
# 159 "data/maps/Route116/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFastestRight
# 160 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 161 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 162 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 163 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 164 "data/maps/Route116/scripts.pory"
	releaseall
# 165 "data/maps/Route116/scripts.pory"
	end
# 166 "data/maps/Route116/scripts.pory"

# 167 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan:: @ 81F2DB6
# 168 "data/maps/Route116/scripts.pory"
	lock
# 169 "data/maps/Route116/scripts.pory"
	faceplayer
# 170 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES, 1
# 171 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, TRUE
# 172 "data/maps/Route116/scripts.pory"
	goto_if_eq Route116_EventScript_PlayerHasGlasses
# 173 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 174 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, TRUE
# 175 "data/maps/Route116/scripts.pory"
	goto_if_eq Route116_EventScript_FoundGlassesNotOnPlayer
# 176 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 177 "data/maps/Route116/scripts.pory"
	release
# 178 "data/maps/Route116/scripts.pory"
	end
# 179 "data/maps/Route116/scripts.pory"

# 180 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer:: @ 81F2DE2
# 181 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 182 "data/maps/Route116/scripts.pory"
	closemessage
# 183 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 184 "data/maps/Route116/scripts.pory"
	end
# 185 "data/maps/Route116/scripts.pory"

# 186 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses:: @ 81F2DF1
# 187 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 188 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 189 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 190 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, TRUE
# 191 "data/maps/Route116/scripts.pory"
	goto_if_eq Route116_EventScript_FoundGlassesOnPlayer
# 192 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 193 "data/maps/Route116/scripts.pory"
	release
# 194 "data/maps/Route116/scripts.pory"
	end
# 195 "data/maps/Route116/scripts.pory"

# 196 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer:: @ 81F2E1B
# 197 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 198 "data/maps/Route116/scripts.pory"
	closemessage
# 199 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 200 "data/maps/Route116/scripts.pory"
	end
# 201 "data/maps/Route116/scripts.pory"

# 202 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit:: @ 81F2E2A
# 203 "data/maps/Route116/scripts.pory"
	delay 20
# 204 "data/maps/Route116/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 205 "data/maps/Route116/scripts.pory"
	call_if_eq Route116_EventScript_GlassesManExitNormal
# 206 "data/maps/Route116/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 207 "data/maps/Route116/scripts.pory"
	call_if_eq Route116_EventScript_GlassesManExitNormal
# 208 "data/maps/Route116/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 209 "data/maps/Route116/scripts.pory"
	call_if_eq Route116_EventScript_GlassesManExitNormal
# 210 "data/maps/Route116/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 211 "data/maps/Route116/scripts.pory"
	call_if_eq Route116_EventScript_GlassesManExitEast
# 212 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 213 "data/maps/Route116/scripts.pory"
	release
# 214 "data/maps/Route116/scripts.pory"
	end
# 215 "data/maps/Route116/scripts.pory"

# 216 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal:: @ 81F2E5E
# 217 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 218 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 219 "data/maps/Route116/scripts.pory"
	return
# 220 "data/maps/Route116/scripts.pory"

# 221 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast:: @ 81F2E69
# 222 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 223 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 224 "data/maps/Route116/scripts.pory"
	return
# 225 "data/maps/Route116/scripts.pory"

# 226 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit: @ 81F2E74
# 227 "data/maps/Route116/scripts.pory"
	walk_left
# 228 "data/maps/Route116/scripts.pory"
	walk_left
# 229 "data/maps/Route116/scripts.pory"
	walk_left
# 230 "data/maps/Route116/scripts.pory"
	walk_left
# 231 "data/maps/Route116/scripts.pory"
	walk_left
# 232 "data/maps/Route116/scripts.pory"
	walk_left
# 233 "data/maps/Route116/scripts.pory"
	walk_left
# 234 "data/maps/Route116/scripts.pory"
	walk_left
# 235 "data/maps/Route116/scripts.pory"
	walk_left
# 236 "data/maps/Route116/scripts.pory"
	step_end
# 237 "data/maps/Route116/scripts.pory"

# 238 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast: @ 81F2E7E
# 239 "data/maps/Route116/scripts.pory"
	walk_up
# 240 "data/maps/Route116/scripts.pory"
	walk_left
# 241 "data/maps/Route116/scripts.pory"
	walk_left
# 242 "data/maps/Route116/scripts.pory"
	walk_left
# 243 "data/maps/Route116/scripts.pory"
	walk_left
# 244 "data/maps/Route116/scripts.pory"
	walk_left
# 245 "data/maps/Route116/scripts.pory"
	walk_left
# 246 "data/maps/Route116/scripts.pory"
	walk_left
# 247 "data/maps/Route116/scripts.pory"
	walk_left
# 248 "data/maps/Route116/scripts.pory"
	walk_left
# 249 "data/maps/Route116/scripts.pory"
	step_end
# 250 "data/maps/Route116/scripts.pory"

# 251 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey:: @ 81F2E89
# 252 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
# 253 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 254 "data/maps/Route116/scripts.pory"
	end
# 255 "data/maps/Route116/scripts.pory"

# 256 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose:: @ 81F2EA0
# 257 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
# 258 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 259 "data/maps/Route116/scripts.pory"
	end
# 260 "data/maps/Route116/scripts.pory"

# 261 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry:: @ 81F2EB7
# 262 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
# 263 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 264 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, TRUE
# 265 "data/maps/Route116/scripts.pory"
	goto_if_eq Route116_EventScript_RematchJerry
# 266 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_JERRY_1
# 267 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 268 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, FALSE
# 269 "data/maps/Route116/scripts.pory"
	goto_if_eq Route116_EventScript_TryRegisterJerry
# 270 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 271 "data/maps/Route116/scripts.pory"
	release
# 272 "data/maps/Route116/scripts.pory"
	end
# 273 "data/maps/Route116/scripts.pory"

# 274 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle:: @ 81F2EF8
# 275 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 276 "data/maps/Route116/scripts.pory"
	release
# 277 "data/maps/Route116/scripts.pory"
	end
# 278 "data/maps/Route116/scripts.pory"

# 279 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle:: @ 81F2F03
# 280 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 281 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 282 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 283 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 284 "data/maps/Route116/scripts.pory"
	release
# 285 "data/maps/Route116/scripts.pory"
	end
# 286 "data/maps/Route116/scripts.pory"

# 287 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry:: @ 81F2F22
# 288 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 289 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 290 "data/maps/Route116/scripts.pory"
	release
# 291 "data/maps/Route116/scripts.pory"
	end
# 292 "data/maps/Route116/scripts.pory"

# 293 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry:: @ 81F2F35
# 294 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 295 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 296 "data/maps/Route116/scripts.pory"
	release
# 297 "data/maps/Route116/scripts.pory"
	end
# 298 "data/maps/Route116/scripts.pory"

# 299 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry:: @ 81F2F4E
# 300 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 301 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 302 "data/maps/Route116/scripts.pory"
	end
# 303 "data/maps/Route116/scripts.pory"

# 304 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark:: @ 81F2F65
# 305 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
# 306 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 307 "data/maps/Route116/scripts.pory"
	end
# 308 "data/maps/Route116/scripts.pory"

# 309 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice:: @ 81F2F7C
# 310 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
# 311 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 312 "data/maps/Route116/scripts.pory"
	end
# 313 "data/maps/Route116/scripts.pory"

# 314 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen:: @ 81F2F93
# 315 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
# 316 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 317 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, TRUE
# 318 "data/maps/Route116/scripts.pory"
	goto_if_eq Route116_EventScript_RematchKaren
# 319 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_KAREN_1
# 320 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 321 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, FALSE
# 322 "data/maps/Route116/scripts.pory"
	goto_if_eq Route116_EventScript_TryRegisterKaren
# 323 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 324 "data/maps/Route116/scripts.pory"
	release
# 325 "data/maps/Route116/scripts.pory"
	end
# 326 "data/maps/Route116/scripts.pory"

# 327 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle:: @ 81F2FD4
# 328 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 329 "data/maps/Route116/scripts.pory"
	release
# 330 "data/maps/Route116/scripts.pory"
	end
# 331 "data/maps/Route116/scripts.pory"

# 332 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle:: @ 81F2FDF
# 333 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 334 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 335 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 336 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 337 "data/maps/Route116/scripts.pory"
	release
# 338 "data/maps/Route116/scripts.pory"
	end
# 339 "data/maps/Route116/scripts.pory"

# 340 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren:: @ 81F2FFE
# 341 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 342 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 343 "data/maps/Route116/scripts.pory"
	release
# 344 "data/maps/Route116/scripts.pory"
	end
# 345 "data/maps/Route116/scripts.pory"

# 346 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren:: @ 81F3011
# 347 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 348 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 349 "data/maps/Route116/scripts.pory"
	release
# 350 "data/maps/Route116/scripts.pory"
	end
# 351 "data/maps/Route116/scripts.pory"

# 352 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren:: @ 81F302A
# 353 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 354 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 355 "data/maps/Route116/scripts.pory"
	end
# 356 "data/maps/Route116/scripts.pory"

# 357 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah:: @ 81F3041
# 358 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
# 359 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 360 "data/maps/Route116/scripts.pory"
	end
# 361 "data/maps/Route116/scripts.pory"

# 362 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson:: @ 81F3058
# 363 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
# 364 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 365 "data/maps/Route116/scripts.pory"
	end
# 366 "data/maps/Route116/scripts.pory"

# 367 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan:: @ 81F306F
# 368 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
# 369 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 370 "data/maps/Route116/scripts.pory"
	end
# 371 "data/maps/Route116/scripts.pory"

# 372 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson:: @ 81F3086
# 373 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
# 374 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 375 "data/maps/Route116/scripts.pory"
	end
# 376 "data/maps/Route116/scripts.pory"

# 377 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko: @ 81F309D
# 378 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 379 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, Peeko and I, when\n"
# 380 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 381 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 382 "data/maps/Route116/scripts.pory"
	.string "darling Peeko!\p"
# 383 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! Peeko!$"
# 384 "data/maps/Route116/scripts.pory"

# 385 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel: @ 81F3140
# 386 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 387 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 388 "data/maps/Route116/scripts.pory"

# 389 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut: @ 81F3166
# 390 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 391 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 392 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 393 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 394 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with Pokémon\n"
# 395 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 396 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 397 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 398 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 399 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 400 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 401 "data/maps/Route116/scripts.pory"
	.string "Pokémon into an uproar.$"
# 402 "data/maps/Route116/scripts.pory"

# 403 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel: @ 81F32C1
# 404 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 405 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 406 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 407 "data/maps/Route116/scripts.pory"

# 408 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation: @ 81F3317
# 409 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 410 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 411 "data/maps/Route116/scripts.pory"
	.string "me in Petalburg Woods, but also got\l"
# 412 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 413 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to Slateport!\p"
# 414 "data/maps/Route116/scripts.pory"
	.string "Capt. Stern informed us that the\n"
# 415 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 416 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 417 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 418 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 419 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 420 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful Trainer,\n"
# 421 "data/maps/Route116/scripts.pory"
	.string "I bear a gift!\p"
# 422 "data/maps/Route116/scripts.pory"
	.string "This is an Aggron, holding an\n"
# 423 "data/maps/Route116/scripts.pory"
	.string "Aggronite to Mega Evolve in battle.\p"
# 424 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 425 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful Trainer!$"
# 426 "data/maps/Route116/scripts.pory"

# 427 "data/maps/Route116/scripts.pory"
Route116_Text_AlsoNeedKeystone: @ 81F3521
# 428 "data/maps/Route116/scripts.pory"
	.string "You'll also need a Keystone to use\n"
# 429 "data/maps/Route116/scripts.pory"
	.string "it, but I bet you already knew that!\p"
# 430 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 431 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 432 "data/maps/Route116/scripts.pory"

# 433 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked: @ 81F3593
# 434 "data/maps/Route116/scripts.pory"
	.string "Your Bag is jam-packed.\n"
# 435 "data/maps/Route116/scripts.pory"
	.string "I can't give you this Aggronite.$"
# 436 "data/maps/Route116/scripts.pory"

# 437 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation: @ 81F35CE
# 438 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 439 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 440 "data/maps/Route116/scripts.pory"
	.string "a gift of a Mega Stone for our most\l"
# 441 "data/maps/Route116/scripts.pory"
	.string "wonderful Trainer!$"
# 442 "data/maps/Route116/scripts.pory"

# 443 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses: @ 81F3657
# 444 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 445 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 446 "data/maps/Route116/scripts.pory"

# 447 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses: @ 81F3688
# 448 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 449 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 450 "data/maps/Route116/scripts.pory"

# 451 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere: @ 81F36B4
# 452 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 453 "data/maps/Route116/scripts.pory"
	.string "These are BlackGlasses.\l"
# 454 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 455 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 456 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 457 "data/maps/Route116/scripts.pory"

# 458 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere: @ 81F3718
# 459 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 460 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 461 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 462 "data/maps/Route116/scripts.pory"

# 463 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor: @ 81F375E
# 464 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 465 "data/maps/Route116/scripts.pory"
	.string "These are BlackGlasses.\l"
# 466 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 467 "data/maps/Route116/scripts.pory"

# 468 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro: @ 81F379D
# 469 "data/maps/Route116/scripts.pory"
	.string "Route 116\n"
# 470 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} Rustboro City$"
# 471 "data/maps/Route116/scripts.pory"

# 472 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign: @ 81F37B7
# 473 "data/maps/Route116/scripts.pory"
	.string "Rusturf Tunnel\n"
# 474 "data/maps/Route116/scripts.pory"
	.string "“Linking Rustboro and Verdanturf\p"
# 475 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 476 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 477 "data/maps/Route116/scripts.pory"

# 478 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse: @ 81F380F
# 479 "data/maps/Route116/scripts.pory"
	.string "Tunneler's Rest House$"
# 480 "data/maps/Route116/scripts.pory"

# 481 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution: @ 81F3825
# 482 "data/maps/Route116/scripts.pory"
	.string "Trainer Tips\p"
# 483 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a Pokémon from\n"
# 484 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 485 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 486 "data/maps/Route116/scripts.pory"
	.string "The startled Pokémon will stop.\p"
# 487 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 488 "data/maps/Route116/scripts.pory"

# 489 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets: @ 81F38D4
# 490 "data/maps/Route116/scripts.pory"
	.string "Trainer Tips\p"
# 491 "data/maps/Route116/scripts.pory"
	.string "Your Bag has several Pockets.\p"
# 492 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 493 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate Pockets.\p"
# 494 "data/maps/Route116/scripts.pory"
	.string "No Trainer can afford to be without\n"
# 495 "data/maps/Route116/scripts.pory"
	.string "a Bag of their own.$"

Route116_EventScript_LegendaryNPC::
# 498 "data/maps/Route116/scripts.pory"
	lock
# 499 "data/maps/Route116/scripts.pory"
	faceplayer
# 500 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 501 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_LegendaryNPC_2
# 524 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_LegendaryNPC_Text_4
Route116_EventScript_LegendaryNPC_1:
# 526 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_LegendaryNPC_2:
# 502 "data/maps/Route116/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route116_EventScript_LegendaryNPC_5
# 506 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JOEY
	goto_if 1, Route116_EventScript_LegendaryNPC_11
Route116_EventScript_LegendaryNPC_9:
# 519 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_LegendaryNPC_Text_3
	goto Route116_EventScript_LegendaryNPC_1

Route116_EventScript_LegendaryNPC_5:
# 503 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_LegendaryNPC_Text_1
	goto Route116_EventScript_LegendaryNPC_1

Route116_EventScript_LegendaryNPC_8:
# 516 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_LegendaryNPC_Text_2
	goto Route116_EventScript_LegendaryNPC_1

Route116_EventScript_LegendaryNPC_10:
# 508 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JERRY_1
	goto_if 1, Route116_EventScript_LegendaryNPC_15
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_11:
# 507 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JOSE
	goto_if 1, Route116_EventScript_LegendaryNPC_10
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_14:
# 510 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JANICE
	goto_if 1, Route116_EventScript_LegendaryNPC_19
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_15:
# 509 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_CLARK
	goto_if 1, Route116_EventScript_LegendaryNPC_14
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_18:
# 512 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_SARAH
	goto_if 1, Route116_EventScript_LegendaryNPC_23
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_19:
# 511 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_KAREN_1
	goto_if 1, Route116_EventScript_LegendaryNPC_18
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_22:
# 514 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_DEVAN
	goto_if 1, Route116_EventScript_LegendaryNPC_26
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_23:
# 513 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_DAWSON
	goto_if 1, Route116_EventScript_LegendaryNPC_22
	goto Route116_EventScript_LegendaryNPC_9

Route116_EventScript_LegendaryNPC_26:
# 515 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JOHNSON
	goto_if 1, Route116_EventScript_LegendaryNPC_8
	goto Route116_EventScript_LegendaryNPC_9


Route116_EventScript_Gen8_NPC::
# 531 "data/maps/Route116/scripts.pory"
	lock
# 532 "data/maps/Route116/scripts.pory"
	faceplayer
# 533 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JOEY
	goto_if 1, Route116_EventScript_Gen8_NPC_5
Route116_EventScript_Gen8_NPC_3:
# 552 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_Gen8_NPC_Text_2
Route116_EventScript_Gen8_NPC_1:
# 554 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Gen8_NPC_2:
# 544 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_Gen8_NPC_Text_0
# 545 "data/maps/Route116/scripts.pory"
	givemon SPECIES_FARFETCHD_GALARIAN, 10, ITEM_NONE
# 546 "data/maps/Route116/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 547 "data/maps/Route116/scripts.pory"
	message Route116_EventScript_Gen8_NPC_Text_1
# 548 "data/maps/Route116/scripts.pory"
	waitfanfare
	goto Route116_EventScript_Gen8_NPC_1

Route116_EventScript_Gen8_NPC_4:
# 535 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JERRY_1
	goto_if 1, Route116_EventScript_Gen8_NPC_9
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_5:
# 534 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JOSE
	goto_if 1, Route116_EventScript_Gen8_NPC_4
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_8:
# 537 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JANICE
	goto_if 1, Route116_EventScript_Gen8_NPC_13
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_9:
# 536 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_CLARK
	goto_if 1, Route116_EventScript_Gen8_NPC_8
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_12:
# 539 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_SARAH
	goto_if 1, Route116_EventScript_Gen8_NPC_17
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_13:
# 538 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_KAREN_1
	goto_if 1, Route116_EventScript_Gen8_NPC_12
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_16:
# 541 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_DEVAN
	goto_if 1, Route116_EventScript_Gen8_NPC_20
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_17:
# 540 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_DAWSON
	goto_if 1, Route116_EventScript_Gen8_NPC_16
	goto Route116_EventScript_Gen8_NPC_3

Route116_EventScript_Gen8_NPC_20:
# 542 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_JOHNSON
	goto_if 1, Route116_EventScript_Gen8_NPC_2
	goto Route116_EventScript_Gen8_NPC_3


Route116_EventScript_MegaNidos_Battle::
# 563 "data/maps/Route116/scripts.pory"
	lock
# 564 "data/maps/Route116/scripts.pory"
	faceplayer
# 565 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_BADGE06_GET, Route116_EventScript_MegaNidos_Battle_2
# 588 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_MegaNidos_Battle_Text_6, MSGBOX_NPC
Route116_EventScript_MegaNidos_Battle_1:
# 590 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_MegaNidos_Battle_2:
# 567 "data/maps/Route116/scripts.pory"
	checktrainerflag TRAINER_NIDO_MEGAS_ROUTE116_RUSTURF
	goto_if 0, Route116_EventScript_MegaNidos_Battle_5
# 584 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_MegaNidos_Battle_Text_5, MSGBOX_NPC
	goto Route116_EventScript_MegaNidos_Battle_1

Route116_EventScript_MegaNidos_Battle_5:
# 568 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_MegaNidos_Battle_Text_0, MSGBOX_YESNO
# 569 "data/maps/Route116/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_MegaNidos_Battle_8
# 580 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_MegaNidos_Battle_Text_4, MSGBOX_NPC
	goto Route116_EventScript_MegaNidos_Battle_1

Route116_EventScript_MegaNidos_Battle_8:
# 570 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_MegaNidos_Battle_Text_1, MSGBOX_NPC
# 572 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_NIDO_MEGAS_ROUTE116_RUSTURF, Route116_EventScript_MegaNidos_Battle_Text_2
# 573 "data/maps/Route116/scripts.pory"
	msgbox Route116_EventScript_MegaNidos_Battle_Text_3, MSGBOX_NPC
# 574 "data/maps/Route116/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 575 "data/maps/Route116/scripts.pory"
	giveitem ITEM_NIDOKINGITE, 1
# 576 "data/maps/Route116/scripts.pory"
	giveitem ITEM_NIDOQUEENITE, 1
# 577 "data/maps/Route116/scripts.pory"
	waitmessage
	goto Route116_EventScript_MegaNidos_Battle_1


Route116_EventScript_LegendaryNPC_Text_0:
# 500 "data/maps/Route116/scripts.pory"
	.string "Sage: Despite your young age, you\n"
	.string "appear to be someone who seeks a\l"
	.string "profound significance in everyday\l"
	.string "matters... Am I right?$"

Route116_EventScript_LegendaryNPC_Text_1:
# 503 "data/maps/Route116/scripts.pory"
	.string "Of course... young trainer, I sense your\n"
	.string "curiosity for the extraordinary. But\l"
	.string "beware, for you tread on sacred\l"
	.string "grounds. The presence of the legendary\l"
	.string "Creation Trio looms over this place.\l"
	.string "They seek a guardian who can commune\l"
	.string "with their power, but you don't seem\l"
	.string "ready yet. Come back once you've\l"
	.string "accomplished an exceptional feat in\l"
	.string "the Pokémon League.$"

Route116_EventScript_LegendaryNPC_Text_2:
# 516 "data/maps/Route116/scripts.pory"
	.string "Ah, young trainer, your potential shines\n"
	.string "through the shadows like a glimmering\l"
	.string "light. I can sense it: the Creation Trio\l"
	.string "has deemed you worthy of their time.\l"
	.string "Use your DexNav to meet them.$"

Route116_EventScript_LegendaryNPC_Text_3:
# 519 "data/maps/Route116/scripts.pory"
	.string "You are almost worthy. Defeat all\n"
	.string "remaining trainers to prove your might\l"
	.string "once and for all!$"

Route116_EventScript_LegendaryNPC_Text_4:
# 524 "data/maps/Route116/scripts.pory"
	.string "You had so much potential... how\n"
	.string "disappointing.$"

Route116_EventScript_Gen8_NPC_Text_0:
# 544 "data/maps/Route116/scripts.pory"
	.string "Take this Pokémon from Galar. You can\n"
	.string "have as many of them as you like!$"

Route116_EventScript_Gen8_NPC_Text_1:
# 547 "data/maps/Route116/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Galarian Farfetch'd{COLOR DARK_GRAY} as\n"
	.string "a gift for defeating every trainer\l"
	.string "here!$"

Route116_EventScript_Gen8_NPC_Text_2:
# 552 "data/maps/Route116/scripts.pory"
	.string "If you can beat all trainers here, I will\n"
	.string "give you an exotic Pokémon from the\l"
	.string "Galar region: a valiant wielder of\l"
	.string "longswords!$"

Route116_EventScript_MegaNidos_Battle_Text_0:
# 568 "data/maps/Route116/scripts.pory"
	.string "Hah! Look at you. Hey, pleb. I'm bored, so\n"
	.string "have a battle with me. I'll even give you\l"
	.string "a reward if you do!$"

Route116_EventScript_MegaNidos_Battle_Text_1:
# 570 "data/maps/Route116/scripts.pory"
	.string "Then let us begin.$"

Route116_EventScript_MegaNidos_Battle_Text_2:
# 572 "data/maps/Route116/scripts.pory"
	.string "What? How?$"

Route116_EventScript_MegaNidos_Battle_Text_3:
# 573 "data/maps/Route116/scripts.pory"
	.string "Unbelievable. Me, losing to the likes of\n"
	.string "you? Well, a promise is a promise. Take\l"
	.string "these stones and get out of my sight.$"

Route116_EventScript_MegaNidos_Battle_Text_4:
# 580 "data/maps/Route116/scripts.pory"
	.string "No? Tsk. I should've expected as much\n"
	.string "from someone like you.$"

Route116_EventScript_MegaNidos_Battle_Text_5:
# 584 "data/maps/Route116/scripts.pory"
	.string "Didn't I tell you to get out of my sight?$"

Route116_EventScript_MegaNidos_Battle_Text_6:
# 588 "data/maps/Route116/scripts.pory"
	.string "You aren't worthy enough to talk to me.\n"
	.string "A peasant like you who hasn't even beat\l"
	.string "Winona has no business here.$"

Route116_EventScript_Text_Got_Aggron::
# 558 "data/maps/Route116/scripts.pory"
	.string "{PLAYER} got an {COLOR BLUE}Aggron{COLOR DARK_GRAY} as a gift!$"
