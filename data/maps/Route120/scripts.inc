# 1 "data/maps/Route120/scripts.pory"

# 2 "data/maps/Route120/scripts.pory"
.set LOCALID_BRIDGE_KECLEON, 26
# 3 "data/maps/Route120/scripts.pory"
.set LOCALID_STEVEN, 27
# 4 "data/maps/Route120/scripts.pory"
.set LOCALID_BRIDGE_KECLEON_SHADOW, 32  @ They use a second object which is identical to Kecleon but has a reflection palette tag for the bridge shadow
# 5 "data/maps/Route120/scripts.pory"

# 6 "data/maps/Route120/scripts.pory"
Route120_MapScripts:: @ 81F53EC
# 7 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
# 8 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
# 9 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
# 10 "data/maps/Route120/scripts.pory"
	.byte 0
# 11 "data/maps/Route120/scripts.pory"

# 12 "data/maps/Route120/scripts.pory"
Route120_OnResume: @ 81F53FC
# 13 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
# 14 "data/maps/Route120/scripts.pory"
	end
# 15 "data/maps/Route120/scripts.pory"

# 16 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleonObject:: @ 81F5406
# 17 "data/maps/Route120/scripts.pory"
	compare VAR_0x8009, 0
# 18 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_RemoveBridgeKecleon
# 19 "data/maps/Route120/scripts.pory"
	compare VAR_0x8009, 1
# 20 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_RemoveKecleon
# 21 "data/maps/Route120/scripts.pory"
	compare VAR_0x8009, 2
# 22 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_RemoveKecleon
# 23 "data/maps/Route120/scripts.pory"
	compare VAR_0x8009, 3
# 24 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_RemoveKecleon
# 25 "data/maps/Route120/scripts.pory"
	compare VAR_0x8009, 4
# 26 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_RemoveKecleon
# 27 "data/maps/Route120/scripts.pory"
	compare VAR_0x8009, 5
# 28 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_RemoveKecleon
# 29 "data/maps/Route120/scripts.pory"
	return
# 30 "data/maps/Route120/scripts.pory"

# 31 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleon:: @ 81F5449
# 32 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 33 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 34 "data/maps/Route120/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 35 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 36 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 37 "data/maps/Route120/scripts.pory"
	return
# 38 "data/maps/Route120/scripts.pory"

# 39 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleon:: @ 81F5460
# 40 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 41 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 42 "data/maps/Route120/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 43 "data/maps/Route120/scripts.pory"
	removeobject VAR_LAST_TALKED
# 44 "data/maps/Route120/scripts.pory"
	return
# 45 "data/maps/Route120/scripts.pory"

# 46 "data/maps/Route120/scripts.pory"
Route120_OnLoad: @ 81F5474
# 47 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_CloseAncientTomb
# 48 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeClearMetatiles
# 49 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeKecleonMovement
# 50 "data/maps/Route120/scripts.pory"
	end
# 51 "data/maps/Route120/scripts.pory"

# 52 "data/maps/Route120/scripts.pory"
Route120_EventScript_CloseAncientTomb:: @ 81F5490
# 53 "data/maps/Route120/scripts.pory"
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, 1
# 54 "data/maps/Route120/scripts.pory"
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, 1
# 55 "data/maps/Route120/scripts.pory"
	return
# 56 "data/maps/Route120/scripts.pory"

# 57 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeClearMetatiles:: @ 81F54A3
# 58 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, 0
# 59 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, 0
# 60 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, 0
# 61 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, 0
# 62 "data/maps/Route120/scripts.pory"
	return
# 63 "data/maps/Route120/scripts.pory"

# 64 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeKecleonMovement:: @ 81F54C8
# 65 "data/maps/Route120/scripts.pory"
	setobjectmovementtype LOCALID_BRIDGE_KECLEON_SHADOW, MOVEMENT_TYPE_FACE_RIGHT
# 66 "data/maps/Route120/scripts.pory"
	return
# 67 "data/maps/Route120/scripts.pory"

# 68 "data/maps/Route120/scripts.pory"
Route120_OnTransition: @ 81F54CD
# 69 "data/maps/Route120/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 70 "data/maps/Route120/scripts.pory"
	call Route120_EventScript_SetWeather
# 71 "data/maps/Route120/scripts.pory"
	end
# 72 "data/maps/Route120/scripts.pory"

# 73 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetWeather:: @ 81F54D8
# 74 "data/maps/Route120/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 75 "data/maps/Route120/scripts.pory"
	compare VAR_TEMP_1, 14
# 76 "data/maps/Route120/scripts.pory"
	goto_if_le Route120_EventScript_SetSunnyWeather
# 77 "data/maps/Route120/scripts.pory"
	compare VAR_TEMP_1, 60
# 78 "data/maps/Route120/scripts.pory"
	goto_if_le Route120_EventScript_TrySetRainyWeather
# 79 "data/maps/Route120/scripts.pory"
	compare VAR_TEMP_1, 61
# 80 "data/maps/Route120/scripts.pory"
	goto_if_ge Route120_EventScript_SetCloudyWeather
# 81 "data/maps/Route120/scripts.pory"
	return
# 82 "data/maps/Route120/scripts.pory"

# 83 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetCloudyWeather:: @ 81F54FF
# 84 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 85 "data/maps/Route120/scripts.pory"
	return
# 86 "data/maps/Route120/scripts.pory"

# 87 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetSunnyWeather:: @ 81F5503
# 88 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY
# 89 "data/maps/Route120/scripts.pory"
	return
# 90 "data/maps/Route120/scripts.pory"

# 91 "data/maps/Route120/scripts.pory"
Route120_EventScript_TrySetRainyWeather:: @ 81F5507
# 92 "data/maps/Route120/scripts.pory"
	compare VAR_TEMP_0, 7
# 93 "data/maps/Route120/scripts.pory"
	goto_if_le Route120_EventScript_SetRainyWeather
# 94 "data/maps/Route120/scripts.pory"
	compare VAR_TEMP_0, 19
# 95 "data/maps/Route120/scripts.pory"
	goto_if_le Route120_EventScript_SetSunnyWeather
# 96 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_SetRainyWeather
# 97 "data/maps/Route120/scripts.pory"
	end
# 98 "data/maps/Route120/scripts.pory"

# 99 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetRainyWeather:: @ 81F5523
# 100 "data/maps/Route120/scripts.pory"
	setweather WEATHER_RAIN
# 101 "data/maps/Route120/scripts.pory"
	return
# 102 "data/maps/Route120/scripts.pory"

# 103 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryBeauty:: @ 81F5527
# 104 "data/maps/Route120/scripts.pory"
	lock
# 105 "data/maps/Route120/scripts.pory"
	faceplayer
# 106 "data/maps/Route120/scripts.pory"
	dotimebasedevents
# 107 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
# 108 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerriesExpressionOfLoveIsntIt, MSGBOX_YESNO
# 109 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, YES
# 110 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_BerryLove
# 111 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, NO
# 112 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_BerryNotLove
# 113 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
# 114 "data/maps/Route120/scripts.pory"
	switch VAR_RESULT
# 115 "data/maps/Route120/scripts.pory"
	case 0, Route120_EventScript_GiveFigyBerry
# 116 "data/maps/Route120/scripts.pory"
	case 5, Route120_EventScript_GiveFigyBerry
# 117 "data/maps/Route120/scripts.pory"
	case 1, Route120_EventScript_GiveWikiBerry
# 118 "data/maps/Route120/scripts.pory"
	case 6, Route120_EventScript_GiveWikiBerry
# 119 "data/maps/Route120/scripts.pory"
	case 2, Route120_EventScript_GiveMagoBerry
# 120 "data/maps/Route120/scripts.pory"
	case 7, Route120_EventScript_GiveMagoBerry
# 121 "data/maps/Route120/scripts.pory"
	case 3, Route120_EventScript_GiveAguavBerry
# 122 "data/maps/Route120/scripts.pory"
	case 8, Route120_EventScript_GiveAguavBerry
# 123 "data/maps/Route120/scripts.pory"
	case 4, Route120_EventScript_GiveIapapaBerry
# 124 "data/maps/Route120/scripts.pory"
	case 9, Route120_EventScript_GiveIapapaBerry
# 125 "data/maps/Route120/scripts.pory"
	end
# 126 "data/maps/Route120/scripts.pory"

# 127 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveFigyBerry:: @ 81F55CA
# 128 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_FIGY_BERRY
# 129 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 130 "data/maps/Route120/scripts.pory"
	end
# 131 "data/maps/Route120/scripts.pory"

# 132 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveWikiBerry:: @ 81F55D5
# 133 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_WIKI_BERRY
# 134 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 135 "data/maps/Route120/scripts.pory"
	end
# 136 "data/maps/Route120/scripts.pory"

# 137 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveMagoBerry:: @ 81F55E0
# 138 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_MAGO_BERRY
# 139 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 140 "data/maps/Route120/scripts.pory"
	end
# 141 "data/maps/Route120/scripts.pory"

# 142 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveAguavBerry:: @ 81F55EB
# 143 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
# 144 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 145 "data/maps/Route120/scripts.pory"
	end
# 146 "data/maps/Route120/scripts.pory"

# 147 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveIapapaBerry:: @ 81F55F6
# 148 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
# 149 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 150 "data/maps/Route120/scripts.pory"
	end
# 151 "data/maps/Route120/scripts.pory"

# 152 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveBerry:: @ 81F5601
# 153 "data/maps/Route120/scripts.pory"
	giveitem VAR_0x8004
# 154 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, FALSE
# 155 "data/maps/Route120/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 156 "data/maps/Route120/scripts.pory"
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
# 157 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerryIsRareRaiseItWithCare, MSGBOX_DEFAULT
# 158 "data/maps/Route120/scripts.pory"
	release
# 159 "data/maps/Route120/scripts.pory"
	end
# 160 "data/maps/Route120/scripts.pory"

# 161 "data/maps/Route120/scripts.pory"
Route120_EventScript_ReceivedBerry:: @ 81F5625
# 162 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_IllGetMoreBerriesFromBerryMaster, MSGBOX_DEFAULT
# 163 "data/maps/Route120/scripts.pory"
	release
# 164 "data/maps/Route120/scripts.pory"
	end
# 165 "data/maps/Route120/scripts.pory"

# 166 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryLove:: @ 81F562F
# 167 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_YesYouUnderstand, MSGBOX_DEFAULT
# 168 "data/maps/Route120/scripts.pory"
	return
# 169 "data/maps/Route120/scripts.pory"

# 170 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryNotLove:: @ 81F5638
# 171 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_MakeYourOwnImpressions, MSGBOX_DEFAULT
# 172 "data/maps/Route120/scripts.pory"
	return
# 173 "data/maps/Route120/scripts.pory"

# 174 "data/maps/Route120/scripts.pory"
Route120_EventScript_Steven:: @ 81F5641
# 175 "data/maps/Route120/scripts.pory"
	lock
# 176 "data/maps/Route120/scripts.pory"
	faceplayer
# 177 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_StevenAskReadyForBattle
# 178 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
# 179 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, NO
# 180 "data/maps/Route120/scripts.pory"
	goto_if_eq Route120_EventScript_StevenNotReady
# 181 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 182 "data/maps/Route120/scripts.pory"
	end
# 183 "data/maps/Route120/scripts.pory"

# 184 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenNotReady:: @ 81F5665
# 185 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenIllWaitHere, MSGBOX_DEFAULT
# 186 "data/maps/Route120/scripts.pory"
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
# 187 "data/maps/Route120/scripts.pory"
	release
# 188 "data/maps/Route120/scripts.pory"
	end
# 189 "data/maps/Route120/scripts.pory"

# 190 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenAskReadyForBattle:: @ 81F5672
# 191 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
# 192 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, NO
# 193 "data/maps/Route120/scripts.pory"
	goto_if_eq Route120_EventScript_StevenNotReady
# 194 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 195 "data/maps/Route120/scripts.pory"
	end
# 196 "data/maps/Route120/scripts.pory"

# 197 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenBattleKecleon:: @ 81F568B
# 198 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
# 199 "data/maps/Route120/scripts.pory"
	closemessage
# 200 "data/maps/Route120/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 201 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_PlayerApproachKecleonNorth
# 202 "data/maps/Route120/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 203 "data/maps/Route120/scripts.pory"
	call_if_eq Route120_EventScript_PlayerApproachKecleonWest
# 204 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestLeft
# 205 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 206 "data/maps/Route120/scripts.pory"
	delay 20
# 207 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
# 208 "data/maps/Route120/scripts.pory"
	closemessage
# 209 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Common_Movement_WalkInPlaceFastestRight
# 210 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 211 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Movement_KecleonAppears
# 212 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 213 "data/maps/Route120/scripts.pory"
	waitse
# 214 "data/maps/Route120/scripts.pory"
	playmoncry SPECIES_KECLEON, 2
# 215 "data/maps/Route120/scripts.pory"
	delay 40
# 216 "data/maps/Route120/scripts.pory"
	waitmoncry
# 217 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 218 "data/maps/Route120/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 219 "data/maps/Route120/scripts.pory"
	setwildbattle SPECIES_KECLEON, VAR_0x800A, ITEM_NONE
# 220 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8009, 0
# 221 "data/maps/Route120/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 222 "data/maps/Route120/scripts.pory"
	dowildbattle
# 223 "data/maps/Route120/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 224 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 225 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 226 "data/maps/Route120/scripts.pory"
	goto_if_eq Route120_EventScript_RemoveBridgeKecleonPostBattle
# 227 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 228 "data/maps/Route120/scripts.pory"
	goto_if_eq Route120_EventScript_RemoveBridgeKecleonPostBattle
# 229 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 230 "data/maps/Route120/scripts.pory"
	goto_if_eq Route120_EventScript_RemoveBridgeKecleonPostBattle
# 231 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 232 "data/maps/Route120/scripts.pory"
	end
# 233 "data/maps/Route120/scripts.pory"

# 234 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleonPostBattle:: @ 81F571C
# 235 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 236 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 237 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 238 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 239 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 240 "data/maps/Route120/scripts.pory"
	end
# 241 "data/maps/Route120/scripts.pory"

# 242 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenGiveDeconScope:: @ 81F572C
# 243 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
# 244 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 245 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 246 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
# 247 "data/maps/Route120/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 248 "data/maps/Route120/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 249 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
# 250 "data/maps/Route120/scripts.pory"
	closemessage
# 251 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
# 252 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 253 "data/maps/Route120/scripts.pory"
	delay 50
# 254 "data/maps/Route120/scripts.pory"
	setfieldeffectargument 0, 1
# 255 "data/maps/Route120/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 256 "data/maps/Route120/scripts.pory"
	delay 15
# 257 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_STEVEN
# 258 "data/maps/Route120/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 259 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, 0
# 260 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, 0
# 261 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, 0
# 262 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, 0
# 263 "data/maps/Route120/scripts.pory"
	special DrawWholeMapView
# 264 "data/maps/Route120/scripts.pory"
	release
# 265 "data/maps/Route120/scripts.pory"
	end
# 266 "data/maps/Route120/scripts.pory"

# 267 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonNorth:: @ 81F57A3
# 268 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 269 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 270 "data/maps/Route120/scripts.pory"
	return
# 271 "data/maps/Route120/scripts.pory"

# 272 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonWest:: @ 81F57AE
# 273 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route120_Movement_ApproachKecleonWest
# 274 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 275 "data/maps/Route120/scripts.pory"
	return
# 276 "data/maps/Route120/scripts.pory"

# 277 "data/maps/Route120/scripts.pory"
Route120_Movement_ApproachKecleonWest: @ 81F57B9
# 278 "data/maps/Route120/scripts.pory"
	walk_down
# 279 "data/maps/Route120/scripts.pory"
	walk_left
# 280 "data/maps/Route120/scripts.pory"
	step_end
# 281 "data/maps/Route120/scripts.pory"

# 282 "data/maps/Route120/scripts.pory"
Route120_EventScript_BridgeKecleon:: @ 81F57BC
# 283 "data/maps/Route120/scripts.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
# 284 "data/maps/Route120/scripts.pory"
	end
# 285 "data/maps/Route120/scripts.pory"

# 286 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSignFortree:: @ 81F57C5
# 287 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
# 288 "data/maps/Route120/scripts.pory"
	end
# 289 "data/maps/Route120/scripts.pory"

# 290 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSign121:: @ 81F57CE
# 291 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
# 292 "data/maps/Route120/scripts.pory"
	end
# 293 "data/maps/Route120/scripts.pory"

# 294 "data/maps/Route120/scripts.pory"
Route120_EventScript_Colin:: @ 81F57D7
# 295 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_COLIN, Route120_Text_ColinIntro, Route120_Text_ColinDefeat
# 296 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
# 297 "data/maps/Route120/scripts.pory"
	end
# 298 "data/maps/Route120/scripts.pory"

# 299 "data/maps/Route120/scripts.pory"
Route120_EventScript_Robert:: @ 81F57EE
# 300 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_ROBERT_1, Route120_Text_RobertIntro, Route120_Text_RobertDefeat, Route120_EventScript_RegisterRobert
# 301 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 302 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, TRUE
# 303 "data/maps/Route120/scripts.pory"
	goto_if_eq Route120_EventScript_RematchRobert
# 304 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
# 305 "data/maps/Route120/scripts.pory"
	release
# 306 "data/maps/Route120/scripts.pory"
	end
# 307 "data/maps/Route120/scripts.pory"

# 308 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterRobert:: @ 81F581A
# 309 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 310 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 311 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
# 312 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_ROBERT_1
# 313 "data/maps/Route120/scripts.pory"
	release
# 314 "data/maps/Route120/scripts.pory"
	end
# 315 "data/maps/Route120/scripts.pory"

# 316 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchRobert:: @ 81F5839
# 317 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
# 318 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
# 319 "data/maps/Route120/scripts.pory"
	end
# 320 "data/maps/Route120/scripts.pory"

# 321 "data/maps/Route120/scripts.pory"
Route120_EventScript_Lorenzo:: @ 81F5850
# 322 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LORENZO, Route120_Text_LorenzoIntro, Route120_Text_LorenzoDefeat
# 323 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
# 324 "data/maps/Route120/scripts.pory"
	end
# 325 "data/maps/Route120/scripts.pory"

# 326 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jenna:: @ 81F5867
# 327 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JENNA, Route120_Text_JennaIntro, Route120_Text_JennaDefeat
# 328 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
# 329 "data/maps/Route120/scripts.pory"
	end
# 330 "data/maps/Route120/scripts.pory"

# 331 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jeffrey:: @ 81F587E
# 332 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, Route120_EventScript_RegisterJeffrey
# 333 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 334 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, TRUE
# 335 "data/maps/Route120/scripts.pory"
	goto_if_eq Route120_EventScript_RematchJeffrey
# 336 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
# 337 "data/maps/Route120/scripts.pory"
	release
# 338 "data/maps/Route120/scripts.pory"
	end
# 339 "data/maps/Route120/scripts.pory"

# 340 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterJeffrey:: @ 81F58AA
# 341 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 342 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 343 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
# 344 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_JEFFREY_1
# 345 "data/maps/Route120/scripts.pory"
	release
# 346 "data/maps/Route120/scripts.pory"
	end
# 347 "data/maps/Route120/scripts.pory"

# 348 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchJeffrey:: @ 81F58C9
# 349 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
# 350 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
# 351 "data/maps/Route120/scripts.pory"
	end
# 352 "data/maps/Route120/scripts.pory"

# 353 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jennifer:: @ 81F58E0
# 354 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_JENNIFER, Route120_Text_JenniferIntro, Route120_Text_JenniferDefeat
# 355 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
# 356 "data/maps/Route120/scripts.pory"
	end
# 357 "data/maps/Route120/scripts.pory"

# 358 "data/maps/Route120/scripts.pory"
Route120_EventScript_Chip:: @ 81F58F7
# 359 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CHIP, Route120_Text_ChipIntro, Route120_Text_ChipDefeat
# 360 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
# 361 "data/maps/Route120/scripts.pory"
	end
# 362 "data/maps/Route120/scripts.pory"

# 363 "data/maps/Route120/scripts.pory"
Route120_EventScript_Clarissa:: @ 81F590E
# 364 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CLARISSA, Route120_Text_ClarissaIntro, Route120_Text_ClarissaDefeat
# 365 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
# 366 "data/maps/Route120/scripts.pory"
	end
# 367 "data/maps/Route120/scripts.pory"

# 368 "data/maps/Route120/scripts.pory"
Route120_EventScript_Angelica:: @ 81F5925
# 369 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_ANGELICA, Route120_Text_AngelicaIntro, Route120_Text_AngelicaDefeat
# 370 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
# 371 "data/maps/Route120/scripts.pory"
	end
# 372 "data/maps/Route120/scripts.pory"

# 373 "data/maps/Route120/scripts.pory"
Route120_EventScript_Keigo:: @ 81F593C
# 374 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_KEIGO, Route120_Text_KeigoIntro, Route120_Text_KeigoDefeat
# 375 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
# 376 "data/maps/Route120/scripts.pory"
	end
# 377 "data/maps/Route120/scripts.pory"

# 378 "data/maps/Route120/scripts.pory"
Route120_EventScript_Riley:: @ 81F5953
# 379 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_RILEY, Route120_Text_RileyIntro, Route120_Text_RileyDefeat
# 380 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
# 381 "data/maps/Route120/scripts.pory"
	end
# 382 "data/maps/Route120/scripts.pory"

# 383 "data/maps/Route120/scripts.pory"
Route120_EventScript_Leonel:: @ 81F596A
# 384 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
# 385 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
# 386 "data/maps/Route120/scripts.pory"
	end
# 387 "data/maps/Route120/scripts.pory"

# 388 "data/maps/Route120/scripts.pory"
Route120_EventScript_Callie:: @ 81F5981
# 389 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_CALLIE, Route120_Text_CallieIntro, Route120_Text_CallieDefeat
# 390 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
# 391 "data/maps/Route120/scripts.pory"
	end
# 392 "data/maps/Route120/scripts.pory"

# 393 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGreeting: @ 81F5998
# 394 "data/maps/Route120/scripts.pory"
	.string "Steven: Hm? {PLAYER}{KUN}, hi.\n"
# 395 "data/maps/Route120/scripts.pory"
	.string "It's been a while.\p"
# 396 "data/maps/Route120/scripts.pory"
	.string "There's something here that you can't\n"
# 397 "data/maps/Route120/scripts.pory"
	.string "see, right?\p"
# 398 "data/maps/Route120/scripts.pory"
	.string "Now, if I were to use this device on\n"
# 399 "data/maps/Route120/scripts.pory"
	.string "the invisible obstacle…\p"
# 400 "data/maps/Route120/scripts.pory"
	.string "No, no. Rather than describing it,\n"
# 401 "data/maps/Route120/scripts.pory"
	.string "I should just show you.\l"
# 402 "data/maps/Route120/scripts.pory"
	.string "That would be more fun.\p"
# 403 "data/maps/Route120/scripts.pory"
	.string "{PLAYER}{KUN}, are your Pokémon ready for\n"
# 404 "data/maps/Route120/scripts.pory"
	.string "battle?$"
# 405 "data/maps/Route120/scripts.pory"

# 406 "data/maps/Route120/scripts.pory"
Route120_Text_StevenIllWaitHere: @ 81F5AAC
# 407 "data/maps/Route120/scripts.pory"
	.string "Steven: No?\p"
# 408 "data/maps/Route120/scripts.pory"
	.string "I'll wait here, so you can get ready.$"
# 409 "data/maps/Route120/scripts.pory"

# 410 "data/maps/Route120/scripts.pory"
Route120_Text_StevenReadyForBattle: @ 81F5ADE
# 411 "data/maps/Route120/scripts.pory"
	.string "Steven: {PLAYER}{KUN}, are your Pokémon\n"
# 412 "data/maps/Route120/scripts.pory"
	.string "ready for battle?$"
# 413 "data/maps/Route120/scripts.pory"

# 414 "data/maps/Route120/scripts.pory"
Route120_Text_StevenShowMeYourPower: @ 81F5B0F
# 415 "data/maps/Route120/scripts.pory"
	.string "Steven: {PLAYER}{KUN}, show me your true\n"
# 416 "data/maps/Route120/scripts.pory"
	.string "power as a Trainer!$"
# 417 "data/maps/Route120/scripts.pory"

# 418 "data/maps/Route120/scripts.pory"
Route120_Text_StevenUsedDevonScope: @ 81F5B43
# 419 "data/maps/Route120/scripts.pory"
	.string "Steven used the Devon Scope.\p"
# 420 "data/maps/Route120/scripts.pory"
	.string "An invisible Pokémon became completely\n"
# 421 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 422 "data/maps/Route120/scripts.pory"
	.string "The startled Pokémon attacked!$"
# 423 "data/maps/Route120/scripts.pory"

# 424 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGiveDevonScope: @ 81F5BAF
# 425 "data/maps/Route120/scripts.pory"
	.string "Steven: I see…\n"
# 426 "data/maps/Route120/scripts.pory"
	.string "Your battle style is intriguing.\p"
# 427 "data/maps/Route120/scripts.pory"
	.string "Your Pokémon have obviously grown\n"
# 428 "data/maps/Route120/scripts.pory"
	.string "since I first met you in Dewford.\p"
# 429 "data/maps/Route120/scripts.pory"
	.string "I'd like you to have this\n"
# 430 "data/maps/Route120/scripts.pory"
	.string "Devon Scope.\p"
# 431 "data/maps/Route120/scripts.pory"
	.string "Who knows, there may be other\n"
# 432 "data/maps/Route120/scripts.pory"
	.string "concealed Pokémon.$"
# 433 "data/maps/Route120/scripts.pory"

# 434 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGoodbye: @ 81F5C7B
# 435 "data/maps/Route120/scripts.pory"
	.string "Steven: {PLAYER}{KUN}.\p"
# 436 "data/maps/Route120/scripts.pory"
	.string "I enjoy seeing Pokémon and Trainers\n"
# 437 "data/maps/Route120/scripts.pory"
	.string "who strive together.\p"
# 438 "data/maps/Route120/scripts.pory"
	.string "I think you're doing great.\p"
# 439 "data/maps/Route120/scripts.pory"
	.string "Well, let's meet again somewhere.$"
# 440 "data/maps/Route120/scripts.pory"

# 441 "data/maps/Route120/scripts.pory"
Kecleon_Text_SomethingUnseeable: @ 81F5D00
# 442 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.$"
# 443 "data/maps/Route120/scripts.pory"

# 444 "data/maps/Route120/scripts.pory"
Kecleon_Text_WantToUseDevonScope: @ 81F5D23
# 445 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 446 "data/maps/Route120/scripts.pory"
	.string "Want to use the Devon Scope?$"
# 447 "data/maps/Route120/scripts.pory"

# 448 "data/maps/Route120/scripts.pory"
Kecleon_Text_UseDevonScopeMonAttacked: @ 81F5D63
# 449 "data/maps/Route120/scripts.pory"
	.string "{PLAYER} used the Devon Scope.\p"
# 450 "data/maps/Route120/scripts.pory"
	.string "An invisible Pokémon became completely\n"
# 451 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 452 "data/maps/Route120/scripts.pory"
	.string "The startled Pokémon attacked!$"
# 453 "data/maps/Route120/scripts.pory"

# 454 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSignFortree: @ 81F5DCB
# 455 "data/maps/Route120/scripts.pory"
	.string "Route 120\n"
# 456 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} Fortree City$"
# 457 "data/maps/Route120/scripts.pory"

# 458 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSign121: @ 81F5DE4
# 459 "data/maps/Route120/scripts.pory"
	.string "{RIGHT_ARROW} Route 121\n"
# 460 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} Route 120$"

Route120_EventScript_LegendaryNPC::
# 463 "data/maps/Route120/scripts.pory"
	lock
# 464 "data/maps/Route120/scripts.pory"
	faceplayer
# 465 "data/maps/Route120/scripts.pory"
	msgbox Route120_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 466 "data/maps/Route120/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route120_EventScript_LegendaryNPC_2
# 497 "data/maps/Route120/scripts.pory"
	msgbox Route120_EventScript_LegendaryNPC_Text_4
Route120_EventScript_LegendaryNPC_1:
# 498 "data/maps/Route120/scripts.pory"
	release
	end

Route120_EventScript_LegendaryNPC_2:
# 467 "data/maps/Route120/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route120_EventScript_LegendaryNPC_5
# 476 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_COLIN
	goto_if 1, Route120_EventScript_LegendaryNPC_11
Route120_EventScript_LegendaryNPC_9:
# 492 "data/maps/Route120/scripts.pory"
	msgbox Route120_EventScript_LegendaryNPC_Text_3
	goto Route120_EventScript_LegendaryNPC_1

Route120_EventScript_LegendaryNPC_5:
# 468 "data/maps/Route120/scripts.pory"
	msgbox Route120_EventScript_LegendaryNPC_Text_1
	goto Route120_EventScript_LegendaryNPC_1

Route120_EventScript_LegendaryNPC_8:
# 489 "data/maps/Route120/scripts.pory"
	msgbox Route120_EventScript_LegendaryNPC_Text_2
	goto Route120_EventScript_LegendaryNPC_1

Route120_EventScript_LegendaryNPC_10:
# 478 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_LORENZO
	goto_if 1, Route120_EventScript_LegendaryNPC_15
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_11:
# 477 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_ROBERT_1
	goto_if 1, Route120_EventScript_LegendaryNPC_10
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_14:
# 480 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_JEFFREY_1
	goto_if 1, Route120_EventScript_LegendaryNPC_19
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_15:
# 479 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_JENNA
	goto_if 1, Route120_EventScript_LegendaryNPC_14
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_18:
# 482 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_CHIP
	goto_if 1, Route120_EventScript_LegendaryNPC_23
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_19:
# 481 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_JENNIFER
	goto_if 1, Route120_EventScript_LegendaryNPC_18
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_22:
# 484 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_ANGELICA
	goto_if 1, Route120_EventScript_LegendaryNPC_27
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_23:
# 483 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_CLARISSA
	goto_if 1, Route120_EventScript_LegendaryNPC_22
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_26:
# 486 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_RILEY
	goto_if 1, Route120_EventScript_LegendaryNPC_31
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_27:
# 485 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_KEIGO
	goto_if 1, Route120_EventScript_LegendaryNPC_26
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_30:
# 488 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_CALLIE
	goto_if 1, Route120_EventScript_LegendaryNPC_8
	goto Route120_EventScript_LegendaryNPC_9

Route120_EventScript_LegendaryNPC_31:
# 487 "data/maps/Route120/scripts.pory"
	checktrainerflag TRAINER_LEONEL
	goto_if 1, Route120_EventScript_LegendaryNPC_30
	goto Route120_EventScript_LegendaryNPC_9


Route120_EventScript_LegendaryNPC_Text_0:
# 465 "data/maps/Route120/scripts.pory"
	.string "Sage: I know a lot about this place,\n"
	.string "more than you could imagine. Wanna hear\l"
	.string "me talk about it?$"

Route120_EventScript_LegendaryNPC_Text_1:
# 468 "data/maps/Route120/scripts.pory"
	.string "It might not seem like it at first, but\n"
	.string "you have entered the domain of the\l"
	.string "Forces of Nature.\p"
	.string "They strayed all the way from Unova to\n"
	.string "here, looking for wild lands to unleash\l"
	.string "their powers onto.\p"
	.string "But, despite what we initially feared, it\n"
	.string "seems like Hoenn has rather soothed\l"
	.string "their spirits.\p"
	.string "No ferocious gales nor fierce\n"
	.string "thunderstorms have grazed this place,\l"
	.string "yet.\p"
	.string "Perhaps their master, Landorus, has\n"
	.string "regained control of them? Nobody knows\l"
	.string "for sure.\p"
	.string "If you want to catch them, however, you\n"
	.string "must first prove your worth by becoming\l"
	.string "champion!$"

Route120_EventScript_LegendaryNPC_Text_2:
# 489 "data/maps/Route120/scripts.pory"
	.string "Seek after the eye of the storm: the\n"
	.string "Forces of Nature have deemed you\l"
	.string "worthy of meeting them. Use your\l"
	.string "DexNav to discover their location, and\l"
	.string "get ready to face nature's wrath!$"

Route120_EventScript_LegendaryNPC_Text_3:
# 492 "data/maps/Route120/scripts.pory"
	.string "I can sense it: the Forces of Nature\n"
	.string "are awake and vigilant. They're almost\l"
	.string "ready to come out and meet you. Defeat\l"
	.string "the remaining trainers on this route to\l"
	.string "meet them!$"

Route120_EventScript_LegendaryNPC_Text_4:
# 497 "data/maps/Route120/scripts.pory"
	.string "Oh...$"
