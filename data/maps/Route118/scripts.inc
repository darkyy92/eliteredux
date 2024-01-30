# 1 "data/maps/Route118/scripts.pory"

# 2 "data/maps/Route118/scripts.pory"
.set LOCALID_STEVEN, 19
# 3 "data/maps/Route118/scripts.pory"

# 4 "data/maps/Route118/scripts.pory"
Route118_MapScripts:: @ 81F3DBC
# 5 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
# 6 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
# 7 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
# 8 "data/maps/Route118/scripts.pory"
	.byte 0
# 9 "data/maps/Route118/scripts.pory"

# 10 "data/maps/Route118/scripts.pory"
Route118_OnTransition: @ 81F3DCC
# 11 "data/maps/Route118/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 12 "data/maps/Route118/scripts.pory"
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 13 "data/maps/Route118/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
# 14 "data/maps/Route118/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST
# 15 "data/maps/Route118/scripts.pory"
	call_if_eq AbnormalWeather_StartGroudonWeather
# 16 "data/maps/Route118/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST
# 17 "data/maps/Route118/scripts.pory"
	call_if_eq AbnormalWeather_StartGroudonWeather
# 18 "data/maps/Route118/scripts.pory"
	end
# 19 "data/maps/Route118/scripts.pory"

# 20 "data/maps/Route118/scripts.pory"
Route118_OnLoad: @ 81F3DF3
# 21 "data/maps/Route118/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST
# 22 "data/maps/Route118/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute118East
# 23 "data/maps/Route118/scripts.pory"
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST
# 24 "data/maps/Route118/scripts.pory"
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute118West
# 25 "data/maps/Route118/scripts.pory"
	end
# 26 "data/maps/Route118/scripts.pory"

# 27 "data/maps/Route118/scripts.pory"
Route118_OnFrame: @ 81F3E0A
# 28 "data/maps/Route118/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 29 "data/maps/Route118/scripts.pory"
	.2byte 0
# 30 "data/maps/Route118/scripts.pory"

# 31 "data/maps/Route118/scripts.pory"
Route114_EventScript_GoodRodFisherman:: @ 81F3E14
# 32 "data/maps/Route118/scripts.pory"
	lock
# 33 "data/maps/Route118/scripts.pory"
	faceplayer
# 34 "data/maps/Route118/scripts.pory"
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
# 35 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
# 36 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, YES
# 37 "data/maps/Route118/scripts.pory"
	goto_if_eq Route118_EventScript_ReceiveGoodRod
# 38 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, NO
# 39 "data/maps/Route118/scripts.pory"
	goto_if_eq Route118_EventScript_DeclineGoodRod
# 40 "data/maps/Route118/scripts.pory"
	end
# 41 "data/maps/Route118/scripts.pory"

# 42 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceiveGoodRod:: @ 81F3E3E
# 43 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
# 44 "data/maps/Route118/scripts.pory"
	giveitem ITEM_GOOD_ROD
# 45 "data/maps/Route118/scripts.pory"
	setflag FLAG_RECEIVED_GOOD_ROD
# 46 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
# 47 "data/maps/Route118/scripts.pory"
	release
# 48 "data/maps/Route118/scripts.pory"
	end
# 49 "data/maps/Route118/scripts.pory"

# 50 "data/maps/Route118/scripts.pory"
Route118_EventScript_DeclineGoodRod:: @ 81F3E5F
# 51 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
# 52 "data/maps/Route118/scripts.pory"
	release
# 53 "data/maps/Route118/scripts.pory"
	end
# 54 "data/maps/Route118/scripts.pory"

# 55 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceivedGoodRod:: @ 81F3E69
# 56 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
# 57 "data/maps/Route118/scripts.pory"
	release
# 58 "data/maps/Route118/scripts.pory"
	end
# 59 "data/maps/Route118/scripts.pory"

# 60 "data/maps/Route118/scripts.pory"
Route118_EventScript_Girl:: @ 81F3E73
# 61 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
# 62 "data/maps/Route118/scripts.pory"
	end
# 63 "data/maps/Route118/scripts.pory"

# 64 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSignMauville:: @ 81F3E7C
# 65 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
# 66 "data/maps/Route118/scripts.pory"
	end
# 67 "data/maps/Route118/scripts.pory"

# 68 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSign119:: @ 81F3E85
# 69 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
# 70 "data/maps/Route118/scripts.pory"
	end
# 71 "data/maps/Route118/scripts.pory"

# 72 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit0:: @ 81F3F28
# 73 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 74 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
# 75 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 76 "data/maps/Route118/scripts.pory"
	return
# 77 "data/maps/Route118/scripts.pory"

# 78 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit1:: @ 81F3F3A
# 79 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 80 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
# 81 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 82 "data/maps/Route118/scripts.pory"
	return
# 83 "data/maps/Route118/scripts.pory"

# 84 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit2:: @ 81F3F4C
# 85 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 86 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
# 87 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 88 "data/maps/Route118/scripts.pory"
	return
# 89 "data/maps/Route118/scripts.pory"

# 90 "data/maps/Route118/scripts.pory"
Route118_Movement_PlayerWatchStevenExit: @ 81F3F5E
# 91 "data/maps/Route118/scripts.pory"
	delay_16
# 92 "data/maps/Route118/scripts.pory"
	walk_in_place_fastest_right
# 93 "data/maps/Route118/scripts.pory"
	step_end
# 94 "data/maps/Route118/scripts.pory"

# 95 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge0: @ 81F3F61
# 96 "data/maps/Route118/scripts.pory"
	walk_left
# 97 "data/maps/Route118/scripts.pory"
	step_end
# 98 "data/maps/Route118/scripts.pory"

# 99 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge2: @ 81F3F63
# 100 "data/maps/Route118/scripts.pory"
	walk_right
# 101 "data/maps/Route118/scripts.pory"
	step_end
# 102 "data/maps/Route118/scripts.pory"

# 103 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenJumpLedge: @ 81F3F65
# 104 "data/maps/Route118/scripts.pory"
	jump_2_down
# 105 "data/maps/Route118/scripts.pory"
	delay_16
# 106 "data/maps/Route118/scripts.pory"
	walk_down
# 107 "data/maps/Route118/scripts.pory"
	step_end
# 108 "data/maps/Route118/scripts.pory"

# 109 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit0: @ 81F3F69
# 110 "data/maps/Route118/scripts.pory"
	walk_right
# 111 "data/maps/Route118/scripts.pory"
	walk_right
# 112 "data/maps/Route118/scripts.pory"
	walk_right
# 113 "data/maps/Route118/scripts.pory"
	walk_right
# 114 "data/maps/Route118/scripts.pory"
	walk_right
# 115 "data/maps/Route118/scripts.pory"
	walk_right
# 116 "data/maps/Route118/scripts.pory"
	walk_right
# 117 "data/maps/Route118/scripts.pory"
	walk_right
# 118 "data/maps/Route118/scripts.pory"
	walk_right
# 119 "data/maps/Route118/scripts.pory"
	walk_right
# 120 "data/maps/Route118/scripts.pory"
	step_end
# 121 "data/maps/Route118/scripts.pory"

# 122 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit1: @ 81F3F74
# 123 "data/maps/Route118/scripts.pory"
	walk_right
# 124 "data/maps/Route118/scripts.pory"
	walk_right
# 125 "data/maps/Route118/scripts.pory"
	walk_right
# 126 "data/maps/Route118/scripts.pory"
	walk_right
# 127 "data/maps/Route118/scripts.pory"
	walk_right
# 128 "data/maps/Route118/scripts.pory"
	walk_right
# 129 "data/maps/Route118/scripts.pory"
	walk_right
# 130 "data/maps/Route118/scripts.pory"
	walk_right
# 131 "data/maps/Route118/scripts.pory"
	walk_right
# 132 "data/maps/Route118/scripts.pory"
	step_end
# 133 "data/maps/Route118/scripts.pory"

# 134 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit2: @ 81F3F7E
# 135 "data/maps/Route118/scripts.pory"
	walk_right
# 136 "data/maps/Route118/scripts.pory"
	walk_right
# 137 "data/maps/Route118/scripts.pory"
	walk_right
# 138 "data/maps/Route118/scripts.pory"
	walk_right
# 139 "data/maps/Route118/scripts.pory"
	walk_right
# 140 "data/maps/Route118/scripts.pory"
	walk_right
# 141 "data/maps/Route118/scripts.pory"
	walk_right
# 142 "data/maps/Route118/scripts.pory"
	walk_right
# 143 "data/maps/Route118/scripts.pory"
	step_end
# 144 "data/maps/Route118/scripts.pory"

# 145 "data/maps/Route118/scripts.pory"
Route118_EventScript_Rose:: @ 81F3F87
# 146 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
# 147 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 148 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, TRUE
# 149 "data/maps/Route118/scripts.pory"
	goto_if_eq Route118_EventScript_RematchRose
# 150 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
# 151 "data/maps/Route118/scripts.pory"
	release
# 152 "data/maps/Route118/scripts.pory"
	end
# 153 "data/maps/Route118/scripts.pory"

# 154 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterRose:: @ 81F3FB3
# 155 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 156 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 157 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
# 158 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_ROSE_1
# 159 "data/maps/Route118/scripts.pory"
	release
# 160 "data/maps/Route118/scripts.pory"
	end
# 161 "data/maps/Route118/scripts.pory"

# 162 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchRose:: @ 81F3FD2
# 163 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
# 164 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
# 165 "data/maps/Route118/scripts.pory"
	end
# 166 "data/maps/Route118/scripts.pory"

# 167 "data/maps/Route118/scripts.pory"
Route118_EventScript_Barny:: @ 81F3FE9
# 168 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
# 169 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
# 170 "data/maps/Route118/scripts.pory"
	end
# 171 "data/maps/Route118/scripts.pory"

# 172 "data/maps/Route118/scripts.pory"
Route118_EventScript_Wade:: @ 81F4000
# 173 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
# 174 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
# 175 "data/maps/Route118/scripts.pory"
	end
# 176 "data/maps/Route118/scripts.pory"

# 177 "data/maps/Route118/scripts.pory"
Route118_EventScript_Dalton:: @ 81F4017
# 178 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
# 179 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 180 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, TRUE
# 181 "data/maps/Route118/scripts.pory"
	goto_if_eq Route118_EventScript_RematchDalton
# 182 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
# 183 "data/maps/Route118/scripts.pory"
	release
# 184 "data/maps/Route118/scripts.pory"
	end
# 185 "data/maps/Route118/scripts.pory"

# 186 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterDalton:: @ 81F4043
# 187 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 188 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 189 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
# 190 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_DALTON_1
# 191 "data/maps/Route118/scripts.pory"
	release
# 192 "data/maps/Route118/scripts.pory"
	end
# 193 "data/maps/Route118/scripts.pory"

# 194 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchDalton:: @ 81F4062
# 195 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
# 196 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
# 197 "data/maps/Route118/scripts.pory"
	end
# 198 "data/maps/Route118/scripts.pory"

# 199 "data/maps/Route118/scripts.pory"
Route118_EventScript_Perry:: @ 81F4079
# 200 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
# 201 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
# 202 "data/maps/Route118/scripts.pory"
	end
# 203 "data/maps/Route118/scripts.pory"

# 204 "data/maps/Route118/scripts.pory"
Route118_EventScript_Chester:: @ 81F4090
# 205 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
# 206 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
# 207 "data/maps/Route118/scripts.pory"
	end
# 208 "data/maps/Route118/scripts.pory"

# 209 "data/maps/Route118/scripts.pory"
Route118_EventScript_Deandre:: @ 81F40A7
# 210 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
# 211 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
# 212 "data/maps/Route118/scripts.pory"
	end
# 213 "data/maps/Route118/scripts.pory"

# 214 "data/maps/Route118/scripts.pory"
Route114_EventScript_MagikarpGuy::
# 215 "data/maps/Route118/scripts.pory"
	lock
# 216 "data/maps/Route118/scripts.pory"
	faceplayer
# 217 "data/maps/Route118/scripts.pory"
	goto_if_set FLAG_ROUTE118_GYARADOSITE, Route118_EventScript_ReceivedGyaradosite
# 218 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DoYouLiekKarp, MSGBOX_YESNO
# 219 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, YES
# 220 "data/maps/Route118/scripts.pory"
	goto_if_eq Route118_EventScript_ILuurveKarp
# 221 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, NO
# 222 "data/maps/Route118/scripts.pory"
	goto_if_eq Route118_EventScript_DontLikeKarp
# 223 "data/maps/Route118/scripts.pory"
	release
# 224 "data/maps/Route118/scripts.pory"
	end
# 225 "data/maps/Route118/scripts.pory"

# 226 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceivedGyaradosite::
# 227 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_KarpBetterThanGyara, MSGBOX_DEFAULT
# 228 "data/maps/Route118/scripts.pory"
	release
# 229 "data/maps/Route118/scripts.pory"
	end
# 230 "data/maps/Route118/scripts.pory"

# 231 "data/maps/Route118/scripts.pory"
Route118_EventScript_ILuurveKarp::
# 232 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_ILuurveKarp, MSGBOX_DEFAULT
# 233 "data/maps/Route118/scripts.pory"
	closemessage
# 234 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_ReadyForKarpFite, MSGBOX_YESNO
# 235 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, YES
# 236 "data/maps/Route118/scripts.pory"
	goto_if_eq Route118_EventScript_CheckParty
# 237 "data/maps/Route118/scripts.pory"
	release
# 238 "data/maps/Route118/scripts.pory"
	end
# 239 "data/maps/Route118/scripts.pory"

# 240 "data/maps/Route118/scripts.pory"
Route118_EventScript_DontLikeKarp::
# 241 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DontLikeKarp, MSGBOX_DEFAULT
# 242 "data/maps/Route118/scripts.pory"
	release
# 243 "data/maps/Route118/scripts.pory"
	end
# 244 "data/maps/Route118/scripts.pory"

# 245 "data/maps/Route118/scripts.pory"
Route118_EventScript_CheckParty::
# 246 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, CheckMagikarpBattle
# 247 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, FALSE
# 248 "data/maps/Route118/scripts.pory"
	goto_if_eq Route118_EventScript_NeedMoreKarp
# 249 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_KarpFiteStart, MSGBOX_DEFAULT
# 250 "data/maps/Route118/scripts.pory"
	trainerbattle_no_intro TRAINER_MAGIKARP_GUY, Route118_Text_MagikarpDefeat
# 251 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TakeGyaradosite, MSGBOX_DEFAULT
# 252 "data/maps/Route118/scripts.pory"
	givecustommon SPECIES_MAGIKARP, 55, ITEM_GYARADOSITE, ITEM_CHERISH_BALL, NATURE_NAIVE, 0, 0, 252, 4, 252, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_V_CREATE, MOVE_DRAGON_ASCENT, MOVE_WICKED_BLOW, MOVE_CORE_ENFORCER, TRUE
# 253 "data/maps/Route118/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 254 "data/maps/Route118/scripts.pory"
	message Route118_EventScript_Text_Got_Magikarp
# 255 "data/maps/Route118/scripts.pory"
	waitfanfare
# 256 "data/maps/Route118/scripts.pory"
	setflag FLAG_ROUTE118_GYARADOSITE
# 257 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_KarpBetterThanGyara, MSGBOX_DEFAULT
# 258 "data/maps/Route118/scripts.pory"
	release
# 259 "data/maps/Route118/scripts.pory"
	end
# 260 "data/maps/Route118/scripts.pory"

# 261 "data/maps/Route118/scripts.pory"
Route118_EventScript_NeedMoreKarp::
# 262 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_NeedMoreKarp, MSGBOX_DEFAULT
# 263 "data/maps/Route118/scripts.pory"
	release
# 264 "data/maps/Route118/scripts.pory"
	end
# 265 "data/maps/Route118/scripts.pory"

# 266 "data/maps/Route118/scripts.pory"
Route118_Text_DoYouLiekKarp:
# 267 "data/maps/Route118/scripts.pory"
	.string "Do you like the Pokémon Magikarp?$"
# 268 "data/maps/Route118/scripts.pory"

# 269 "data/maps/Route118/scripts.pory"
Route118_Text_DontLikeKarp:
# 270 "data/maps/Route118/scripts.pory"
	.string "Oh… That's disappointing.\n"
# 271 "data/maps/Route118/scripts.pory"
	.string "I was hoping you were a fellow\l"
# 272 "data/maps/Route118/scripts.pory"
	.string "Magikarp aficionado…$"
# 273 "data/maps/Route118/scripts.pory"

# 274 "data/maps/Route118/scripts.pory"
Route118_Text_ILuurveKarp:
# 275 "data/maps/Route118/scripts.pory"
	.string "You do?!\n"
# 276 "data/maps/Route118/scripts.pory"
	.string "That's great!\p"
# 277 "data/maps/Route118/scripts.pory"
	.string "Not many people appreciate the true\n"
# 278 "data/maps/Route118/scripts.pory"
	.string "majesty of Magikarp…\p"
# 279 "data/maps/Route118/scripts.pory"
	.string "Oh, I know! If you can show me you\n"
# 280 "data/maps/Route118/scripts.pory"
	.string "truly love Magikarp, I'll give you this\l"
# 281 "data/maps/Route118/scripts.pory"
	.string "special Pokémon I found!\p"
# 282 "data/maps/Route118/scripts.pory"
	.string "Here's what I want you to do…\p"
# 283 "data/maps/Route118/scripts.pory"
	.string "You must defeat my team of Magikarp\n"
# 284 "data/maps/Route118/scripts.pory"
	.string "all stars…\p"
# 285 "data/maps/Route118/scripts.pory"
	.string "With your own team of Magikarp!$"
# 286 "data/maps/Route118/scripts.pory"

# 287 "data/maps/Route118/scripts.pory"
Route118_Text_ReadyForKarpFite:
# 288 "data/maps/Route118/scripts.pory"
	.string "So, are you ready for our magical\n"
# 289 "data/maps/Route118/scripts.pory"
	.string "showdown?$"
# 290 "data/maps/Route118/scripts.pory"

# 291 "data/maps/Route118/scripts.pory"
Route118_Text_NeedMoreKarp:
# 292 "data/maps/Route118/scripts.pory"
	.string "Hmm… You don't have enough Magikarp\n"
# 293 "data/maps/Route118/scripts.pory"
	.string "to challenge me.\p"
# 294 "data/maps/Route118/scripts.pory"
	.string "Please come back once you've fished up\n"
# 295 "data/maps/Route118/scripts.pory"
	.string "a full team of them!$"
# 296 "data/maps/Route118/scripts.pory"

# 297 "data/maps/Route118/scripts.pory"
Route118_Text_KarpFiteStart:
# 298 "data/maps/Route118/scripts.pory"
	.string "Oho! Then let us begin!$"
# 299 "data/maps/Route118/scripts.pory"

# 300 "data/maps/Route118/scripts.pory"
Route118_Text_MagikarpDefeat:
# 301 "data/maps/Route118/scripts.pory"
	.string "Ah! Your love for Magikarp is clear!$"
# 302 "data/maps/Route118/scripts.pory"

# 303 "data/maps/Route118/scripts.pory"
Route118_Text_TakeGyaradosite:
# 304 "data/maps/Route118/scripts.pory"
	.string "Here, take this special Magikarp.\n"
# 305 "data/maps/Route118/scripts.pory"
	.string "You earned it!$"
# 306 "data/maps/Route118/scripts.pory"

# 307 "data/maps/Route118/scripts.pory"
Route118_Text_KarpBetterThanGyara:
# 308 "data/maps/Route118/scripts.pory"
	.string "Gyarados might not be Magikarp, but\n"
# 309 "data/maps/Route118/scripts.pory"
	.string "it's almost as good!$"
# 310 "data/maps/Route118/scripts.pory"

# 311 "data/maps/Route118/scripts.pory"
Route118_Text_StevenQuestions: @ 81F40BE
# 312 "data/maps/Route118/scripts.pory"
	.string "Steven: Hi, {PLAYER}{KUN}!\p"
# 313 "data/maps/Route118/scripts.pory"
	.string "It's me, Steven!\n"
# 314 "data/maps/Route118/scripts.pory"
	.string "We met in the cave near Dewford.\p"
# 315 "data/maps/Route118/scripts.pory"
	.string "Have you met many kinds of Pokémon\n"
# 316 "data/maps/Route118/scripts.pory"
	.string "since I last saw you?\p"
# 317 "data/maps/Route118/scripts.pory"
	.string "There are many, many kinds of Pokémon\n"
# 318 "data/maps/Route118/scripts.pory"
	.string "in this wide world of ours.\p"
# 319 "data/maps/Route118/scripts.pory"
	.string "If you wanted to raise only your\n"
# 320 "data/maps/Route118/scripts.pory"
	.string "favorites, that's fine.\p"
# 321 "data/maps/Route118/scripts.pory"
	.string "Perhaps you find it more fun to raise\n"
# 322 "data/maps/Route118/scripts.pory"
	.string "all sorts of Pokémon.\p"
# 323 "data/maps/Route118/scripts.pory"
	.string "As a Trainer of Pokémon,\n"
# 324 "data/maps/Route118/scripts.pory"
	.string "what do you think?\p"
# 325 "data/maps/Route118/scripts.pory"
	.string "Of course, it's not any of my business.\p"
# 326 "data/maps/Route118/scripts.pory"
	.string "It would be nice if we were to meet\n"
# 327 "data/maps/Route118/scripts.pory"
	.string "again somewhere.$"
# 328 "data/maps/Route118/scripts.pory"

# 329 "data/maps/Route118/scripts.pory"
Route118_Text_YouAgreeGoodRodIsGood: @ 81F427B
# 330 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 331 "data/maps/Route118/scripts.pory"
	.string "A Good Rod is really good!\p"
# 332 "data/maps/Route118/scripts.pory"
	.string "Wouldn't you agree?$"
# 333 "data/maps/Route118/scripts.pory"

# 334 "data/maps/Route118/scripts.pory"
Route118_Text_IdenticalMindsTakeThis: @ 81F42AF
# 335 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 336 "data/maps/Route118/scripts.pory"
	.string "We're of identical minds!\p"
# 337 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 338 "data/maps/Route118/scripts.pory"
	.string "Take this Good Rod!$"
# 339 "data/maps/Route118/scripts.pory"

# 340 "data/maps/Route118/scripts.pory"
Route118_Text_TryYourLuckFishing: @ 81F42E7
# 341 "data/maps/Route118/scripts.pory"
	.string "Wherever there's water, try your luck\n"
# 342 "data/maps/Route118/scripts.pory"
	.string "at fishing.$"
# 343 "data/maps/Route118/scripts.pory"

# 344 "data/maps/Route118/scripts.pory"
Route118_Text_DontYouLikeToFish: @ 81F4319
# 345 "data/maps/Route118/scripts.pory"
	.string "Don't you like to fish?$"
# 346 "data/maps/Route118/scripts.pory"

# 347 "data/maps/Route118/scripts.pory"
Route118_Text_TryCatchingMonWithGoodRod: @ 81F4331
# 348 "data/maps/Route118/scripts.pory"
	.string "Try catching all sorts of Pokémon\n"
# 349 "data/maps/Route118/scripts.pory"
	.string "with your Good Rod.$"
# 350 "data/maps/Route118/scripts.pory"

# 351 "data/maps/Route118/scripts.pory"
Route118_Text_CanCrossRiversWithSurf: @ 81F4367
# 352 "data/maps/Route118/scripts.pory"
	.string "Even if there isn't a boat, you can\n"
# 353 "data/maps/Route118/scripts.pory"
	.string "cross rivers and the sea if you have\l"
# 354 "data/maps/Route118/scripts.pory"
	.string "a Pokémon that knows Surf.\p"
# 355 "data/maps/Route118/scripts.pory"
	.string "Pokémon can be counted on to do so\n"
# 356 "data/maps/Route118/scripts.pory"
	.string "much!$"
# 357 "data/maps/Route118/scripts.pory"

# 358 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSignMauville: @ 81F43F4
# 359 "data/maps/Route118/scripts.pory"
	.string "Route 118\n"
# 360 "data/maps/Route118/scripts.pory"
	.string "{LEFT_ARROW} Mauville City$"
# 361 "data/maps/Route118/scripts.pory"

# 362 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSign119: @ 81F440E
# 363 "data/maps/Route118/scripts.pory"
	.string "Route 118\n"
# 364 "data/maps/Route118/scripts.pory"
	.string "{UP_ARROW} Route 119$"

Route118_EventScript_LegendaryNPC::
# 368 "data/maps/Route118/scripts.pory"
	lock
# 369 "data/maps/Route118/scripts.pory"
	faceplayer
# 370 "data/maps/Route118/scripts.pory"
	msgbox Route118_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 371 "data/maps/Route118/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route118_EventScript_LegendaryNPC_2
# 393 "data/maps/Route118/scripts.pory"
	msgbox Route118_EventScript_LegendaryNPC_Text_4
Route118_EventScript_LegendaryNPC_1:
# 395 "data/maps/Route118/scripts.pory"
	release
	end

Route118_EventScript_LegendaryNPC_2:
# 372 "data/maps/Route118/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route118_EventScript_LegendaryNPC_5
# 378 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_ROSE_1
	goto_if 1, Route118_EventScript_LegendaryNPC_11
Route118_EventScript_LegendaryNPC_9:
# 388 "data/maps/Route118/scripts.pory"
	msgbox Route118_EventScript_LegendaryNPC_Text_3
	goto Route118_EventScript_LegendaryNPC_1

Route118_EventScript_LegendaryNPC_5:
# 373 "data/maps/Route118/scripts.pory"
	msgbox Route118_EventScript_LegendaryNPC_Text_1
	goto Route118_EventScript_LegendaryNPC_1

Route118_EventScript_LegendaryNPC_8:
# 385 "data/maps/Route118/scripts.pory"
	msgbox Route118_EventScript_LegendaryNPC_Text_2
	goto Route118_EventScript_LegendaryNPC_1

Route118_EventScript_LegendaryNPC_10:
# 380 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_WADE
	goto_if 1, Route118_EventScript_LegendaryNPC_15
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_11:
# 379 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_BARNY
	goto_if 1, Route118_EventScript_LegendaryNPC_10
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_14:
# 382 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_PERRY
	goto_if 1, Route118_EventScript_LegendaryNPC_19
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_15:
# 381 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_DALTON_1
	goto_if 1, Route118_EventScript_LegendaryNPC_14
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_18:
# 384 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_DEANDRE
	goto_if 1, Route118_EventScript_LegendaryNPC_8
	goto Route118_EventScript_LegendaryNPC_9

Route118_EventScript_LegendaryNPC_19:
# 383 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_CHESTER
	goto_if 1, Route118_EventScript_LegendaryNPC_18
	goto Route118_EventScript_LegendaryNPC_9


Route118West_EventScript_Gen8_NPC::
# 400 "data/maps/Route118/scripts.pory"
	lock
# 401 "data/maps/Route118/scripts.pory"
	faceplayer
# 402 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_ROSE_1
	goto_if 1, Route118West_EventScript_Gen8_NPC_5
Route118West_EventScript_Gen8_NPC_3:
# 415 "data/maps/Route118/scripts.pory"
	msgbox Route118West_EventScript_Gen8_NPC_Text_2
Route118West_EventScript_Gen8_NPC_1:
# 417 "data/maps/Route118/scripts.pory"
	release
	end

Route118West_EventScript_Gen8_NPC_2:
# 407 "data/maps/Route118/scripts.pory"
	msgbox Route118West_EventScript_Gen8_NPC_Text_0
# 408 "data/maps/Route118/scripts.pory"
	givemon SPECIES_HATENNA, 10, ITEM_NONE
# 409 "data/maps/Route118/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 410 "data/maps/Route118/scripts.pory"
	message Route118West_EventScript_Gen8_NPC_Text_1
# 411 "data/maps/Route118/scripts.pory"
	waitfanfare
	goto Route118West_EventScript_Gen8_NPC_1

Route118West_EventScript_Gen8_NPC_4:
# 404 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_DALTON_1
	goto_if 1, Route118West_EventScript_Gen8_NPC_8
	goto Route118West_EventScript_Gen8_NPC_3

Route118West_EventScript_Gen8_NPC_5:
# 403 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_WADE
	goto_if 1, Route118West_EventScript_Gen8_NPC_4
	goto Route118West_EventScript_Gen8_NPC_3

Route118West_EventScript_Gen8_NPC_8:
# 405 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_DEANDRE
	goto_if 1, Route118West_EventScript_Gen8_NPC_2
	goto Route118West_EventScript_Gen8_NPC_3


Route118East_EventScript_Gen8_NPC::
# 422 "data/maps/Route118/scripts.pory"
	lock
# 423 "data/maps/Route118/scripts.pory"
	faceplayer
# 424 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_BARNY
	goto_if 1, Route118East_EventScript_Gen8_NPC_5
Route118East_EventScript_Gen8_NPC_3:
# 436 "data/maps/Route118/scripts.pory"
	msgbox Route118East_EventScript_Gen8_NPC_Text_2
Route118East_EventScript_Gen8_NPC_1:
# 438 "data/maps/Route118/scripts.pory"
	release
	end

Route118East_EventScript_Gen8_NPC_2:
# 428 "data/maps/Route118/scripts.pory"
	msgbox Route118East_EventScript_Gen8_NPC_Text_0
# 429 "data/maps/Route118/scripts.pory"
	givemon SPECIES_DRACOZOLT, 50, ITEM_NONE
# 430 "data/maps/Route118/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 431 "data/maps/Route118/scripts.pory"
	message Route118East_EventScript_Gen8_NPC_Text_1
# 432 "data/maps/Route118/scripts.pory"
	waitfanfare
	goto Route118East_EventScript_Gen8_NPC_1

Route118East_EventScript_Gen8_NPC_4:
# 426 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_CHESTER
	goto_if 1, Route118East_EventScript_Gen8_NPC_2
	goto Route118East_EventScript_Gen8_NPC_3

Route118East_EventScript_Gen8_NPC_5:
# 425 "data/maps/Route118/scripts.pory"
	checktrainerflag TRAINER_PERRY
	goto_if 1, Route118East_EventScript_Gen8_NPC_4
	goto Route118East_EventScript_Gen8_NPC_3


Route118_EventScript_StevenTrigger0::
# 448 "data/maps/Route118/scripts.pory"
	lockall
# 449 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 0
# 450 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 451 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 452 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge0
# 453 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 454 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
	end


Route118_EventScript_StevenTrigger1::
# 459 "data/maps/Route118/scripts.pory"
	lockall
# 460 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 1
# 461 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 462 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 463 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
	end


Route118_EventScript_StevenTrigger2::
# 468 "data/maps/Route118/scripts.pory"
	lockall
# 469 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 2
# 470 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 471 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 472 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge2
# 473 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 474 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
	end


Route118_EventScript_StevenTrigger::
# 479 "data/maps/Route118/scripts.pory"
	playse SE_LEDGE
# 480 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
# 481 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 482 "data/maps/Route118/scripts.pory"
	delay 30
# 483 "data/maps/Route118/scripts.pory"
	msgbox Route118_EventScript_StevenTrigger_Text_0, MSGBOX_DEFAULT
# 484 "data/maps/Route118/scripts.pory"
	trainerbattle_no_intro TRAINER_STEVEN_ROUTE118, Route118_EventScript_StevenTrigger_Text_1
# 485 "data/maps/Route118/scripts.pory"
	msgbox Route118_EventScript_StevenTrigger_Text_2, MSGBOX_DEFAULT
# 486 "data/maps/Route118/scripts.pory"
	closemessage
# 487 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 488 "data/maps/Route118/scripts.pory"
	switch VAR_0x8008
# 489 "data/maps/Route118/scripts.pory"
	case 0, Route118_EventScript_StevenTrigger_3
# 492 "data/maps/Route118/scripts.pory"
	case 1, Route118_EventScript_StevenTrigger_4
# 495 "data/maps/Route118/scripts.pory"
	case 2, Route118_EventScript_StevenTrigger_5
Route118_EventScript_StevenTrigger_1:
# 499 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 500 "data/maps/Route118/scripts.pory"
	setvar VAR_ROUTE118_STATE, 1
# 501 "data/maps/Route118/scripts.pory"
	removeobject LOCALID_STEVEN
# 502 "data/maps/Route118/scripts.pory"
	releaseall
	end

Route118_EventScript_StevenTrigger_3:
# 490 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
	goto Route118_EventScript_StevenTrigger_1

Route118_EventScript_StevenTrigger_4:
# 493 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
	goto Route118_EventScript_StevenTrigger_1

Route118_EventScript_StevenTrigger_5:
# 496 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
	goto Route118_EventScript_StevenTrigger_1


Route118_EventScript_LegendaryNPC_Text_0:
# 370 "data/maps/Route118/scripts.pory"
	.string "Sage: The world we live truly is a thing\n"
	.string "of beauty. Do you agree?$"

Route118_EventScript_LegendaryNPC_Text_1:
# 373 "data/maps/Route118/scripts.pory"
	.string "How could you not? But I'll tell you\n"
	.string "more. This land we stand on is blessed\l"
	.string "by the presence of the Stewards of\l"
	.string "nature: Manaphy, the sea guardian,\l"
	.string "Phione, their offspring, and Celebi, the\l"
	.string "time travelling wild spirit.\p"
	.string "Remember, as you explore, to remain in\n"
	.string "harmony with nature, treating every\l"
	.string "blade of grass, every little crevace,\l"
	.string "every grain of sand as if it was your\l"
	.string "dearest treasure.\p"
	.string "If you want to meet these angelic\n"
	.string "guardians, become Champion and come\l"
	.string "back to this sacred place.$"

Route118_EventScript_LegendaryNPC_Text_2:
# 385 "data/maps/Route118/scripts.pory"
	.string "Your skills in battle have been tested,\n"
	.string "and you have succeded against all odds.\l"
	.string "Congratulations. Use your DexNav to\l"
	.string "finally meet these extraordinary\l"
	.string "protectors.$"

Route118_EventScript_LegendaryNPC_Text_3:
# 388 "data/maps/Route118/scripts.pory"
	.string "You have defeated the Pokémon\n"
	.string "League... and the champion too? I'm\l"
	.string "impressed, and the guardians of this\l"
	.string "place are, too. Once you'll have\l"
	.string "defeated these last few trainers,\l"
	.string "nothing will stand between you and\l"
	.string "them!$"

Route118_EventScript_LegendaryNPC_Text_4:
# 393 "data/maps/Route118/scripts.pory"
	.string "Your opinion disgusts me. Go away,\n"
	.string "you've made a fool out of yourself.$"

Route118West_EventScript_Gen8_NPC_Text_0:
# 407 "data/maps/Route118/scripts.pory"
	.string "Cute might not be the word that best\n"
	.string "describes your battling... but I liked\l"
	.string "it! Here, take this!$"

Route118West_EventScript_Gen8_NPC_Text_1:
# 410 "data/maps/Route118/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Hatenna{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer at the beach!$"

Route118West_EventScript_Gen8_NPC_Text_2:
# 415 "data/maps/Route118/scripts.pory"
	.string "Have you ever heard the expression\n"
	.string "'cute and deadly'? I have a Pokémon\l"
	.string "here that fits that description to a\l"
	.string "tee! Show your cuteness in battle to\l"
	.string "receive it!$"

Route118East_EventScript_Gen8_NPC_Text_0:
# 428 "data/maps/Route118/scripts.pory"
	.string "Here, take it and don't tell anyone!$"

Route118East_EventScript_Gen8_NPC_Text_1:
# 431 "data/maps/Route118/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Dracozolt{COLOR DARK_GRAY} as a gift\n"
	.string "for defeating the three regular\l"
	.string "trainers here!$"

Route118East_EventScript_Gen8_NPC_Text_2:
# 436 "data/maps/Route118/scripts.pory"
	.string "If you can beat all three regular\n"
	.string "trainers at the east side of this route,\l"
	.string "I will give you this fossil I stole from\l"
	.string "school!$"

Route118_EventScript_StevenTrigger_Text_0:
# 483 "data/maps/Route118/scripts.pory"
	.string "Steven: Hi, {PLAYER}{KUN} I hope you're\n"
	.string "ready. I upgraded my team after you\l"
	.string "defeated me last time...$"

Route118_EventScript_StevenTrigger_Text_1:
# 484 "data/maps/Route118/scripts.pory"
	.string "You still have great potential.$"

Route118_EventScript_StevenTrigger_Text_2:
# 485 "data/maps/Route118/scripts.pory"
	.string "Steven: I knew I wasn't the only one\n"
	.string "who upgraded his team. I hope we meet\l"
	.string "again.$"

Route118_EventScript_Text_Got_Magikarp::
# 442 "data/maps/Route118/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Magikarp{COLOR DARK_GRAY} as a gift!$"
