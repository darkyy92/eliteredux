# 1 "data/maps/Route111/scripts.pory"

# 2 "data/maps/Route111/scripts.pory"
.set LOCALID_VICTOR, 1
# 3 "data/maps/Route111/scripts.pory"
.set LOCALID_VICTORIA, 2
# 4 "data/maps/Route111/scripts.pory"
.set LOCALID_VIVI, 3
# 5 "data/maps/Route111/scripts.pory"
.set LOCALID_VICKY, 4
# 6 "data/maps/Route111/scripts.pory"
.set LOCALID_PLAYER_FALLING, 42
# 7 "data/maps/Route111/scripts.pory"
.set LOCALID_NURSE, 43
# 8 "data/maps/Route111/scripts.pory"
.set LOCALID_CHANSEY, 44
# 9 "data/maps/Route111/scripts.pory"

# 10 "data/maps/Route111/scripts.pory"
Route111_MapScripts:: @ 81F0CA7
# 11 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
# 12 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
# 13 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
# 14 "data/maps/Route111/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
# 15 "data/maps/Route111/scripts.pory"
	.byte 0
# 16 "data/maps/Route111/scripts.pory"

# 17 "data/maps/Route111/scripts.pory"
Route111_OnLoad: @ 81F0CBC
# 18 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
# 19 "data/maps/Route111/scripts.pory"
	compare VAR_MIRAGE_TOWER_STATE, 1
# 20 "data/maps/Route111/scripts.pory"
	call_if_eq Route111_EventScript_ShowTemporaryMirageTower
# 21 "data/maps/Route111/scripts.pory"
	end
# 22 "data/maps/Route111/scripts.pory"

# 23 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseDesertRuins:: @ 81F0CD1
# 24 "data/maps/Route111/scripts.pory"
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, 1
# 25 "data/maps/Route111/scripts.pory"
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, 1
# 26 "data/maps/Route111/scripts.pory"
	return
# 27 "data/maps/Route111/scripts.pory"

# 28 "data/maps/Route111/scripts.pory"
@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
# 29 "data/maps/Route111/scripts.pory"
Route111_EventScript_ShowTemporaryMirageTower:: @ 81F0CE4
# 30 "data/maps/Route111/scripts.pory"
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, 0
# 31 "data/maps/Route111/scripts.pory"
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, 0
# 32 "data/maps/Route111/scripts.pory"
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, 0
# 33 "data/maps/Route111/scripts.pory"
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, 0
# 34 "data/maps/Route111/scripts.pory"
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, 0
# 35 "data/maps/Route111/scripts.pory"
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, 0
# 36 "data/maps/Route111/scripts.pory"
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, 0
# 37 "data/maps/Route111/scripts.pory"
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, 0
# 38 "data/maps/Route111/scripts.pory"
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, 0
# 39 "data/maps/Route111/scripts.pory"
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, 0
# 40 "data/maps/Route111/scripts.pory"
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, 0
# 41 "data/maps/Route111/scripts.pory"
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, 0
# 42 "data/maps/Route111/scripts.pory"
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, 0
# 43 "data/maps/Route111/scripts.pory"
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, 0
# 44 "data/maps/Route111/scripts.pory"
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, 0
# 45 "data/maps/Route111/scripts.pory"
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, 0
# 46 "data/maps/Route111/scripts.pory"
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, 0
# 47 "data/maps/Route111/scripts.pory"
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, 0
# 48 "data/maps/Route111/scripts.pory"
	return
# 49 "data/maps/Route111/scripts.pory"

# 50 "data/maps/Route111/scripts.pory"
Route111_OnTransition: @ 81F0D87
# 51 "data/maps/Route111/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 52 "data/maps/Route111/scripts.pory"
	special SetMirageTowerVisibility
# 53 "data/maps/Route111/scripts.pory"
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
# 54 "data/maps/Route111/scripts.pory"
	compare VAR_MIRAGE_TOWER_STATE, 1
# 55 "data/maps/Route111/scripts.pory"
	call_if_eq Route111_EventScript_SetFallingPlayerGfx
# 56 "data/maps/Route111/scripts.pory"
	compare VAR_MIRAGE_TOWER_STATE, 2
# 57 "data/maps/Route111/scripts.pory"
	call_if_eq Route111_EventScript_SetMirageTowerGone
# 58 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CheckSetSandstorm
# 59 "data/maps/Route111/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 60 "data/maps/Route111/scripts.pory"
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
# 61 "data/maps/Route111/scripts.pory"
	end
# 62 "data/maps/Route111/scripts.pory"

# 63 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfx:: @ 81F0DC2
# 64 "data/maps/Route111/scripts.pory"
	checkplayergender
# 65 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, MALE
# 66 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_SetFallingPlayerGfxMale
# 67 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, FEMALE
# 68 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_SetFallingPlayerGfxFemale
# 69 "data/maps/Route111/scripts.pory"
	return
# 70 "data/maps/Route111/scripts.pory"

# 71 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxMale:: @ 81F0DDA
# 72 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 73 "data/maps/Route111/scripts.pory"
	return
# 74 "data/maps/Route111/scripts.pory"

# 75 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetFallingPlayerGfxFemale:: @ 81F0DE0
# 76 "data/maps/Route111/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 77 "data/maps/Route111/scripts.pory"
	return
# 78 "data/maps/Route111/scripts.pory"

# 79 "data/maps/Route111/scripts.pory"
Route111_EventScript_CheckSetSandstorm:: @ 81F0DE6
# 80 "data/maps/Route111/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 81 "data/maps/Route111/scripts.pory"
	compare VAR_TEMP_1, 34
# 82 "data/maps/Route111/scripts.pory"
	goto_if_lt Route111_EventScript_EndCheckSetSandstorm
# 83 "data/maps/Route111/scripts.pory"
	compare VAR_TEMP_1, 107
# 84 "data/maps/Route111/scripts.pory"
	goto_if_gt Route111_EventScript_EndCheckSetSandstorm
# 85 "data/maps/Route111/scripts.pory"
	compare VAR_TEMP_1, 72
# 86 "data/maps/Route111/scripts.pory"
	goto_if_gt Route111_EventScript_SetSandstorm
# 87 "data/maps/Route111/scripts.pory"
	compare VAR_TEMP_0, 2000
# 88 "data/maps/Route111/scripts.pory"
	goto_if_gt Route111_EventScript_EndCheckSetSandstorm
# 89 "data/maps/Route111/scripts.pory"
	compare VAR_TEMP_0, 8
# 90 "data/maps/Route111/scripts.pory"
	goto_if_lt Route111_EventScript_EndCheckSetSandstorm
# 91 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetSandstorm:: @ 81F0E22
# 92 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 93 "data/maps/Route111/scripts.pory"
Route111_EventScript_EndCheckSetSandstorm:: @ 81F0E25
# 94 "data/maps/Route111/scripts.pory"
	return
# 95 "data/maps/Route111/scripts.pory"

# 96 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetWinstratesNotDefeated:: @ 81F0E26
# 97 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
# 98 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
# 99 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
# 100 "data/maps/Route111/scripts.pory"
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
# 101 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTOR
# 102 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VICTORIA
# 103 "data/maps/Route111/scripts.pory"
	cleartrainerflag TRAINER_VIVI
# 104 "data/maps/Route111/scripts.pory"
	end
# 105 "data/maps/Route111/scripts.pory"

# 106 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetLayoutNoMirageTower:: @ 81F0E3C
# 107 "data/maps/Route111/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
# 108 "data/maps/Route111/scripts.pory"
	return
# 109 "data/maps/Route111/scripts.pory"

# 110 "data/maps/Route111/scripts.pory"
Route111_EventScript_SetMirageTowerGone:: @ 81F0E40
# 111 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 3
# 112 "data/maps/Route111/scripts.pory"
	return
# 113 "data/maps/Route111/scripts.pory"

# 114 "data/maps/Route111/scripts.pory"
Route111_OnWarp: @ 81F0E46
# 115 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
# 116 "data/maps/Route111/scripts.pory"
	.2byte 0
# 117 "data/maps/Route111/scripts.pory"

# 118 "data/maps/Route111/scripts.pory"
Route111_EventScript_HidePlayerForMirageTower:: @ 81F0E50
# 119 "data/maps/Route111/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
# 120 "data/maps/Route111/scripts.pory"
	end
# 121 "data/maps/Route111/scripts.pory"

# 122 "data/maps/Route111/scripts.pory"
Route111_OnFrame: @ 81F0E56
# 123 "data/maps/Route111/scripts.pory"
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
# 124 "data/maps/Route111/scripts.pory"
	.2byte 0
# 125 "data/maps/Route111/scripts.pory"

# 126 "data/maps/Route111/scripts.pory"
Route111_EventScript_MirageTowerDisappear:: @ 81F0E60
# 127 "data/maps/Route111/scripts.pory"
	lockall
# 128 "data/maps/Route111/scripts.pory"
	special StartMirageTowerShake
# 129 "data/maps/Route111/scripts.pory"
	waitstate
# 130 "data/maps/Route111/scripts.pory"
	delay 24
# 131 "data/maps/Route111/scripts.pory"
	playse SE_FALL
# 132 "data/maps/Route111/scripts.pory"
	addobject LOCALID_PLAYER_FALLING
# 133 "data/maps/Route111/scripts.pory"
	special StartPlayerDescendMirageTower
# 134 "data/maps/Route111/scripts.pory"
	waitstate
# 135 "data/maps/Route111/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
# 136 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_PLAYER_FALLING
# 137 "data/maps/Route111/scripts.pory"
	delay 16
# 138 "data/maps/Route111/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 139 "data/maps/Route111/scripts.pory"
	delay 16
# 140 "data/maps/Route111/scripts.pory"
	special StartMirageTowerDisintegration
# 141 "data/maps/Route111/scripts.pory"
	waitstate
# 142 "data/maps/Route111/scripts.pory"
	special StartMirageTowerFossilFallAndSink
# 143 "data/maps/Route111/scripts.pory"
	waitstate
# 144 "data/maps/Route111/scripts.pory"
	setvar VAR_MIRAGE_TOWER_STATE, 2
# 145 "data/maps/Route111/scripts.pory"
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
# 146 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
# 147 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
# 148 "data/maps/Route111/scripts.pory"
	releaseall
# 149 "data/maps/Route111/scripts.pory"
	end
# 150 "data/maps/Route111/scripts.pory"

# 151 "data/maps/Route111/scripts.pory"
Route111_EventScript_RootFossilDisappeared:: @ 81F0EA7
# 152 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
# 153 "data/maps/Route111/scripts.pory"
	releaseall
# 154 "data/maps/Route111/scripts.pory"
	end
# 155 "data/maps/Route111/scripts.pory"

# 156 "data/maps/Route111/scripts.pory"
@ Unused
# 157 "data/maps/Route111/scripts.pory"
Route111_Movement_PlayerFall:: @ 81F0EB1
# 158 "data/maps/Route111/scripts.pory"
	store_lock_anim
# 159 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 160 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 161 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 162 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 163 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 164 "data/maps/Route111/scripts.pory"
	walk_fast_down
# 165 "data/maps/Route111/scripts.pory"
	step_end
# 166 "data/maps/Route111/scripts.pory"

# 167 "data/maps/Route111/scripts.pory"
Route111_EventScript_Girl:: @ 81F0EB9
# 168 "data/maps/Route111/scripts.pory"
	lock
# 169 "data/maps/Route111/scripts.pory"
	faceplayer
# 170 "data/maps/Route111/scripts.pory"
	dotimebasedevents
# 171 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
# 172 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
# 173 "data/maps/Route111/scripts.pory"
	giveitem ITEM_RAZZ_BERRY
# 174 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, FALSE
# 175 "data/maps/Route111/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 176 "data/maps/Route111/scripts.pory"
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
# 177 "data/maps/Route111/scripts.pory"
	special GetPlayerBigGuyGirlString
# 178 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
# 179 "data/maps/Route111/scripts.pory"
	release
# 180 "data/maps/Route111/scripts.pory"
	end
# 181 "data/maps/Route111/scripts.pory"

# 182 "data/maps/Route111/scripts.pory"
Route111_EventScript_ReceivedBerry:: @ 81F0EF4
# 183 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
# 184 "data/maps/Route111/scripts.pory"
	release
# 185 "data/maps/Route111/scripts.pory"
	end
# 186 "data/maps/Route111/scripts.pory"

# 187 "data/maps/Route111/scripts.pory"
@ Unused
# 188 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerUp:: @ 81F0EFE
# 189 "data/maps/Route111/scripts.pory"
	lockall
# 190 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 0
# 191 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 192 "data/maps/Route111/scripts.pory"
	end
# 193 "data/maps/Route111/scripts.pory"

# 194 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerDown:: @ 81F0F0A
# 195 "data/maps/Route111/scripts.pory"
	lockall
# 196 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 1
# 197 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 198 "data/maps/Route111/scripts.pory"
	end
# 199 "data/maps/Route111/scripts.pory"

# 200 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerLeft:: @ 81F0F16
# 201 "data/maps/Route111/scripts.pory"
	lockall
# 202 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 2
# 203 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 204 "data/maps/Route111/scripts.pory"
	end
# 205 "data/maps/Route111/scripts.pory"

# 206 "data/maps/Route111/scripts.pory"
@ Unused
# 207 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTriggerRight:: @ 81F0F22
# 208 "data/maps/Route111/scripts.pory"
	lockall
# 209 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, 3
# 210 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_ViciousSandstormTrigger
# 211 "data/maps/Route111/scripts.pory"
	end
# 212 "data/maps/Route111/scripts.pory"

# 213 "data/maps/Route111/scripts.pory"
Route111_EventScript_ViciousSandstormTrigger:: @ 81F0F2E
# 214 "data/maps/Route111/scripts.pory"
	checkitem ITEM_GO_GOGGLES, 1
# 215 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, FALSE
# 216 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_PreventRouteAccess
# 217 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 1
# 218 "data/maps/Route111/scripts.pory"
	releaseall
# 219 "data/maps/Route111/scripts.pory"
	end
# 220 "data/maps/Route111/scripts.pory"

# 221 "data/maps/Route111/scripts.pory"
Route111_EventScript_PreventRouteAccess:: @ 81F0F45
# 222 "data/maps/Route111/scripts.pory"
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
# 223 "data/maps/Route111/scripts.pory"
	closemessage
# 224 "data/maps/Route111/scripts.pory"
	compare VAR_0x8004, 0
# 225 "data/maps/Route111/scripts.pory"
	call_if_eq Route111_EventScript_PushUpFromRoute
# 226 "data/maps/Route111/scripts.pory"
	compare VAR_0x8004, 1
# 227 "data/maps/Route111/scripts.pory"
	call_if_eq Route111_EventScript_PushDownFromRoute
# 228 "data/maps/Route111/scripts.pory"
	compare VAR_0x8004, 2
# 229 "data/maps/Route111/scripts.pory"
	call_if_eq Route111_EventScript_PushLeftFromRoute
# 230 "data/maps/Route111/scripts.pory"
	compare VAR_0x8004, 3
# 231 "data/maps/Route111/scripts.pory"
	call_if_eq Route111_EventScript_PushRightFromRoute
# 232 "data/maps/Route111/scripts.pory"
	releaseall
# 233 "data/maps/Route111/scripts.pory"
	end
# 234 "data/maps/Route111/scripts.pory"

# 235 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushUpFromRoute:: @ 81F0F7C
# 236 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushUpFromRoute
# 237 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 238 "data/maps/Route111/scripts.pory"
	return
# 239 "data/maps/Route111/scripts.pory"

# 240 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushDownFromRoute:: @ 81F0F87
# 241 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushDownFromRoute
# 242 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 243 "data/maps/Route111/scripts.pory"
	return
# 244 "data/maps/Route111/scripts.pory"

# 245 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushLeftFromRoute:: @ 81F0F92
# 246 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushLeftFromRoute
# 247 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 248 "data/maps/Route111/scripts.pory"
	return
# 249 "data/maps/Route111/scripts.pory"

# 250 "data/maps/Route111/scripts.pory"
Route111_EventScript_PushRightFromRoute:: @ 81F0F9D
# 251 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushRightFromRoute
# 252 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 253 "data/maps/Route111/scripts.pory"
	return
# 254 "data/maps/Route111/scripts.pory"

# 255 "data/maps/Route111/scripts.pory"
Route111_Movement_PushUpFromRoute: @ 81F0FA8
# 256 "data/maps/Route111/scripts.pory"
	walk_up
# 257 "data/maps/Route111/scripts.pory"
	step_end
# 258 "data/maps/Route111/scripts.pory"

# 259 "data/maps/Route111/scripts.pory"
Route111_Movement_PushDownFromRoute: @ 81F0FAA
# 260 "data/maps/Route111/scripts.pory"
	walk_down
# 261 "data/maps/Route111/scripts.pory"
	step_end
# 262 "data/maps/Route111/scripts.pory"

# 263 "data/maps/Route111/scripts.pory"
Route111_Movement_PushLeftFromRoute: @ 81F0FAC
# 264 "data/maps/Route111/scripts.pory"
	walk_left
# 265 "data/maps/Route111/scripts.pory"
	step_end
# 266 "data/maps/Route111/scripts.pory"

# 267 "data/maps/Route111/scripts.pory"
Route111_Movement_PushRightFromRoute: @ 81F0FAE
# 268 "data/maps/Route111/scripts.pory"
	walk_right
# 269 "data/maps/Route111/scripts.pory"
	step_end
# 270 "data/maps/Route111/scripts.pory"

# 271 "data/maps/Route111/scripts.pory"
Route111_EventScript_SunTrigger:: @ 81F0FB0
# 272 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SUNNY
# 273 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_ROUTE110
# 274 "data/maps/Route111/scripts.pory"
	doweather
# 275 "data/maps/Route111/scripts.pory"
	setvar VAR_TEMP_3, 0
# 276 "data/maps/Route111/scripts.pory"
	end
# 277 "data/maps/Route111/scripts.pory"

# 278 "data/maps/Route111/scripts.pory"
Route111_EventScript_SandstormTrigger:: @ 81F0FBD
# 279 "data/maps/Route111/scripts.pory"
	setweather WEATHER_SANDSTORM
# 280 "data/maps/Route111/scripts.pory"
	fadenewbgm MUS_ROUTE111
# 281 "data/maps/Route111/scripts.pory"
	doweather
# 282 "data/maps/Route111/scripts.pory"
	end
# 283 "data/maps/Route111/scripts.pory"

# 284 "data/maps/Route111/scripts.pory"
Route111_EventScript_Victor:: @ 81F0FC5
# 285 "data/maps/Route111/scripts.pory"
	lock
# 286 "data/maps/Route111/scripts.pory"
	faceplayer
# 287 "data/maps/Route111/scripts.pory"
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
# 288 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
# 289 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, YES
# 290 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_BattleWinstrates
# 291 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
# 292 "data/maps/Route111/scripts.pory"
	release
# 293 "data/maps/Route111/scripts.pory"
	end
# 294 "data/maps/Route111/scripts.pory"

# 295 "data/maps/Route111/scripts.pory"
Route111_EventScript_BattleWinstrates:: @ 81F0FE7
# 296 "data/maps/Route111/scripts.pory"
	setflag FLAG_SYS_DISABLE_AUTOHEAL
# 297 "data/maps/Route111/scripts.pory"
	special HealPlayerParty
# 298 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
# 299 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
# 300 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTOR, Common_Movement_WalkInPlaceFastestUp
# 301 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 302 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 303 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
# 304 "data/maps/Route111/scripts.pory"
	closemessage
# 305 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTOR, Route111_Movement_WinstrateEnterHouse
# 306 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 307 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICTOR
# 308 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 309 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 310 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 311 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 312 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VICTORIA
# 313 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateExitHouse
# 314 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 315 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 316 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
# 317 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
# 318 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Common_Movement_WalkInPlaceFastestUp
# 319 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 320 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 321 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
# 322 "data/maps/Route111/scripts.pory"
	closemessage
# 323 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateEnterHouse
# 324 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 325 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICTORIA
# 326 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 327 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 328 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 329 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 330 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VIVI
# 331 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateExitHouse
# 332 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 333 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 334 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
# 335 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
# 336 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Common_Movement_WalkInPlaceFastestUp
# 337 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 338 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 339 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
# 340 "data/maps/Route111/scripts.pory"
	closemessage
# 341 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateEnterHouse
# 342 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 343 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VIVI
# 344 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 345 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
# 346 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 347 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 348 "data/maps/Route111/scripts.pory"
	addobject LOCALID_VICKY
# 349 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateExitHouse
# 350 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 351 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 352 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
# 353 "data/maps/Route111/scripts.pory"
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
# 354 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
# 355 "data/maps/Route111/scripts.pory"
	closemessage
# 356 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Common_Movement_WalkInPlaceFastestUp
# 357 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 358 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_OpenWinstrateDoor
# 359 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateEnterHouse
# 360 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 361 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_VICKY
# 362 "data/maps/Route111/scripts.pory"
	clearflag FLAG_SYS_DISABLE_AUTOHEAL
# 363 "data/maps/Route111/scripts.pory"
	call Route111_EventScript_CloseWinstrateDoor
# 364 "data/maps/Route111/scripts.pory"
	release
# 365 "data/maps/Route111/scripts.pory"
	end
# 366 "data/maps/Route111/scripts.pory"

# 367 "data/maps/Route111/scripts.pory"
Route111_EventScript_OpenWinstrateDoor:: @ 81F113C
# 368 "data/maps/Route111/scripts.pory"
	opendoor 13, 113
# 369 "data/maps/Route111/scripts.pory"
	waitdooranim
# 370 "data/maps/Route111/scripts.pory"
	return
# 371 "data/maps/Route111/scripts.pory"

# 372 "data/maps/Route111/scripts.pory"
Route111_EventScript_CloseWinstrateDoor:: @ 81F1143
# 373 "data/maps/Route111/scripts.pory"
	closedoor 13, 113
# 374 "data/maps/Route111/scripts.pory"
	waitdooranim
# 375 "data/maps/Route111/scripts.pory"
	return
# 376 "data/maps/Route111/scripts.pory"

# 377 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateEnterHouse: @ 81F114A
# 378 "data/maps/Route111/scripts.pory"
	walk_in_place_fastest_up
# 379 "data/maps/Route111/scripts.pory"
	walk_up
# 380 "data/maps/Route111/scripts.pory"
	step_end
# 381 "data/maps/Route111/scripts.pory"

# 382 "data/maps/Route111/scripts.pory"
Route111_Movement_WinstrateExitHouse: @ 81F114D
# 383 "data/maps/Route111/scripts.pory"
	walk_down
# 384 "data/maps/Route111/scripts.pory"
	step_end
# 385 "data/maps/Route111/scripts.pory"

# 386 "data/maps/Route111/scripts.pory"
Route111_Movement_WaitForNextWinstrate: @ 81F114F
# 387 "data/maps/Route111/scripts.pory"
	delay_16
# 388 "data/maps/Route111/scripts.pory"
	delay_16
# 389 "data/maps/Route111/scripts.pory"
	delay_16
# 390 "data/maps/Route111/scripts.pory"
	step_end
# 391 "data/maps/Route111/scripts.pory"

# 392 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSignMauville:: @ 81F1153
# 393 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
# 394 "data/maps/Route111/scripts.pory"
	end
# 395 "data/maps/Route111/scripts.pory"

# 396 "data/maps/Route111/scripts.pory"
Route111_EventScript_WinstrateHouseSign:: @ 81F115C
# 397 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
# 398 "data/maps/Route111/scripts.pory"
	end
# 399 "data/maps/Route111/scripts.pory"

# 400 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign112:: @ 81F1165
# 401 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
# 402 "data/maps/Route111/scripts.pory"
	end
# 403 "data/maps/Route111/scripts.pory"

# 404 "data/maps/Route111/scripts.pory"
Route111_EventScript_RouteSign113:: @ 81F116E
# 405 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
# 406 "data/maps/Route111/scripts.pory"
	end
# 407 "data/maps/Route111/scripts.pory"

# 408 "data/maps/Route111/scripts.pory"
Route111_EventScript_OldLadysRestStopSign:: @ 81F1177
# 409 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
# 410 "data/maps/Route111/scripts.pory"
	end
# 411 "data/maps/Route111/scripts.pory"

# 412 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerTipsSpAtkSpDef:: @ 81F1180
# 413 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
# 414 "data/maps/Route111/scripts.pory"
	end
# 415 "data/maps/Route111/scripts.pory"

# 416 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man1:: @ 81F1189
# 417 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
# 418 "data/maps/Route111/scripts.pory"
	end
# 419 "data/maps/Route111/scripts.pory"

# 420 "data/maps/Route111/scripts.pory"
Route111_EventScript_Man2:: @ 81F1192
# 421 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
# 422 "data/maps/Route111/scripts.pory"
	end
# 423 "data/maps/Route111/scripts.pory"

# 424 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hiker:: @ 81F119B
# 425 "data/maps/Route111/scripts.pory"
	lock
# 426 "data/maps/Route111/scripts.pory"
	faceplayer
# 427 "data/maps/Route111/scripts.pory"
	compare VAR_MIRAGE_TOWER_STATE, 3
# 428 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_HikerMirageTowerGone
# 429 "data/maps/Route111/scripts.pory"
	compare VAR_MIRAGE_TOWER_STATE, 2
# 430 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_HikerMirageTowerDisintegrated
# 431 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
# 432 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
# 433 "data/maps/Route111/scripts.pory"
	release
# 434 "data/maps/Route111/scripts.pory"
	end
# 435 "data/maps/Route111/scripts.pory"

# 436 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerGone:: @ 81F11C6
# 437 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
# 438 "data/maps/Route111/scripts.pory"
	release
# 439 "data/maps/Route111/scripts.pory"
	end
# 440 "data/maps/Route111/scripts.pory"

# 441 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerDisintegrated:: @ 81F11D0
# 442 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
# 443 "data/maps/Route111/scripts.pory"
	release
# 444 "data/maps/Route111/scripts.pory"
	end
# 445 "data/maps/Route111/scripts.pory"

# 446 "data/maps/Route111/scripts.pory"
Route111_EventScript_HikerMirageTowerVisible:: @ 81F11DA
# 447 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
# 448 "data/maps/Route111/scripts.pory"
	release
# 449 "data/maps/Route111/scripts.pory"
	end
# 450 "data/maps/Route111/scripts.pory"

# 451 "data/maps/Route111/scripts.pory"
Route111_EventScript_Drew:: @ 81F1204
# 452 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
# 453 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
# 454 "data/maps/Route111/scripts.pory"
	end
# 455 "data/maps/Route111/scripts.pory"

# 456 "data/maps/Route111/scripts.pory"
Route111_EventScript_Heidi:: @ 81F121B
# 457 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
# 458 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
# 459 "data/maps/Route111/scripts.pory"
	end
# 460 "data/maps/Route111/scripts.pory"

# 461 "data/maps/Route111/scripts.pory"
Route111_EventScript_Beau:: @ 81F1232
# 462 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
# 463 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
# 464 "data/maps/Route111/scripts.pory"
	end
# 465 "data/maps/Route111/scripts.pory"

# 466 "data/maps/Route111/scripts.pory"
Route111_EventScript_Becky:: @ 81F1249
# 467 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
# 468 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
# 469 "data/maps/Route111/scripts.pory"
	end
# 470 "data/maps/Route111/scripts.pory"

# 471 "data/maps/Route111/scripts.pory"
Route111_EventScript_Dusty:: @ 81F1260
# 472 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
# 473 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 474 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
# 475 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_RematchDusty
# 476 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
# 477 "data/maps/Route111/scripts.pory"
	release
# 478 "data/maps/Route111/scripts.pory"
	end
# 479 "data/maps/Route111/scripts.pory"

# 480 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterDusty:: @ 81F128C
# 481 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 482 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 483 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
# 484 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_DUSTY_1
# 485 "data/maps/Route111/scripts.pory"
	release
# 486 "data/maps/Route111/scripts.pory"
	end
# 487 "data/maps/Route111/scripts.pory"

# 488 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchDusty:: @ 81F12AB
# 489 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
# 490 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
# 491 "data/maps/Route111/scripts.pory"
	end
# 492 "data/maps/Route111/scripts.pory"

# 493 "data/maps/Route111/scripts.pory"
Route111_EventScript_Travis:: @ 81F12C2
# 494 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
# 495 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
# 496 "data/maps/Route111/scripts.pory"
	end
# 497 "data/maps/Route111/scripts.pory"

# 498 "data/maps/Route111/scripts.pory"
Route111_EventScript_Irene:: @ 81F12D9
# 499 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
# 500 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
# 501 "data/maps/Route111/scripts.pory"
	end
# 502 "data/maps/Route111/scripts.pory"

# 503 "data/maps/Route111/scripts.pory"
Route111_EventScript_Daisuke:: @ 81F12F0
# 504 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
# 505 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
# 506 "data/maps/Route111/scripts.pory"
	end
# 507 "data/maps/Route111/scripts.pory"

# 508 "data/maps/Route111/scripts.pory"
Route111_EventScript_Wilton:: @ 81F1307
# 509 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
# 510 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 511 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
# 512 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_RematchWilton
# 513 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
# 514 "data/maps/Route111/scripts.pory"
	release
# 515 "data/maps/Route111/scripts.pory"
	end
# 516 "data/maps/Route111/scripts.pory"

# 517 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterWilton:: @ 81F1333
# 518 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 519 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 520 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
# 521 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_WILTON_1
# 522 "data/maps/Route111/scripts.pory"
	release
# 523 "data/maps/Route111/scripts.pory"
	end
# 524 "data/maps/Route111/scripts.pory"

# 525 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchWilton:: @ 81F1352
# 526 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
# 527 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
# 528 "data/maps/Route111/scripts.pory"
	end
# 529 "data/maps/Route111/scripts.pory"

# 530 "data/maps/Route111/scripts.pory"
Route111_EventScript_Brooke:: @ 81F1369
# 531 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
# 532 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 533 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, TRUE
# 534 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_RematchBrooke
# 535 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
# 536 "data/maps/Route111/scripts.pory"
	release
# 537 "data/maps/Route111/scripts.pory"
	end
# 538 "data/maps/Route111/scripts.pory"

# 539 "data/maps/Route111/scripts.pory"
Route111_EventScript_RegisterBrooke:: @ 81F1395
# 540 "data/maps/Route111/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 541 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 542 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
# 543 "data/maps/Route111/scripts.pory"
	register_matchcall TRAINER_BROOKE_1
# 544 "data/maps/Route111/scripts.pory"
	release
# 545 "data/maps/Route111/scripts.pory"
	end
# 546 "data/maps/Route111/scripts.pory"

# 547 "data/maps/Route111/scripts.pory"
Route111_EventScript_RematchBrooke:: @ 81F13B4
# 548 "data/maps/Route111/scripts.pory"
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
# 549 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
# 550 "data/maps/Route111/scripts.pory"
	end
# 551 "data/maps/Route111/scripts.pory"

# 552 "data/maps/Route111/scripts.pory"
Route111_EventScript_Hayden:: @ 81F13CB
# 553 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
# 554 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
# 555 "data/maps/Route111/scripts.pory"
	end
# 556 "data/maps/Route111/scripts.pory"

# 557 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bianca:: @ 81F13E2
# 558 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
# 559 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
# 560 "data/maps/Route111/scripts.pory"
	end
# 561 "data/maps/Route111/scripts.pory"

# 562 "data/maps/Route111/scripts.pory"
Route111_EventScript_Tyron:: @ 81F13F9
# 563 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
# 564 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
# 565 "data/maps/Route111/scripts.pory"
	end
# 566 "data/maps/Route111/scripts.pory"

# 567 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celina:: @ 81F1410
# 568 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
# 569 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
# 570 "data/maps/Route111/scripts.pory"
	end
# 571 "data/maps/Route111/scripts.pory"

# 572 "data/maps/Route111/scripts.pory"
Route111_EventScript_Celia:: @ 81F1427
# 573 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
# 574 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
# 575 "data/maps/Route111/scripts.pory"
	end
# 576 "data/maps/Route111/scripts.pory"

# 577 "data/maps/Route111/scripts.pory"
Route111_EventScript_Bryan:: @ 81F143E
# 578 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
# 579 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
# 580 "data/maps/Route111/scripts.pory"
	end
# 581 "data/maps/Route111/scripts.pory"

# 582 "data/maps/Route111/scripts.pory"
Route111_EventScript_Branden:: @ 81F1455
# 583 "data/maps/Route111/scripts.pory"
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
# 584 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
# 585 "data/maps/Route111/scripts.pory"
	end
# 586 "data/maps/Route111/scripts.pory"

# 587 "data/maps/Route111/scripts.pory"
Route111_EventScript_TrainerHillSign:: @ 81F146C
# 588 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
# 589 "data/maps/Route111/scripts.pory"
	end
# 590 "data/maps/Route111/scripts.pory"

# 591 "data/maps/Route111/scripts.pory"
Route111_EventScript_ChanseyBlob::
# 592 "data/maps/Route111/scripts.pory"
	lockall
# 593 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 594 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
# 595 "data/maps/Route111/scripts.pory"
	call_if_ne Route111_EventScript_PlayerFaceUp
# 596 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_NURSE, Common_Movement_WalkInPlaceFastestUp
# 597 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_CHANSEY, Common_Movement_WalkInPlaceFastestDown
# 598 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 599 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BlobGetBackHere, MSGBOX_DEFAULT
# 600 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_CHANSEY, Route111_Movement_ChanseyJump
# 601 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 602 "data/maps/Route111/scripts.pory"
	waitse
# 603 "data/maps/Route111/scripts.pory"
	playmoncry SPECIES_CHANSEY, 0
# 604 "data/maps/Route111/scripts.pory"
	delay 40
# 605 "data/maps/Route111/scripts.pory"
	waitmoncry
# 606 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_CHANSEY, Route111_Movement_ChanseyEscape
# 607 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 608 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThatsJustGreat, MSGBOX_DEFAULT
# 609 "data/maps/Route111/scripts.pory"
	playse SE_PIN
# 610 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_NURSE, Common_Movement_ExclamationMark
# 611 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 612 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_NURSE, Common_Movement_WalkInPlaceFastestRight
# 613 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 614 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 615 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 616 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_DidYouSeeThat, MSGBOX_DEFAULT
# 617 "data/maps/Route111/scripts.pory"
	giveitem ITEM_HEAL_BALL
# 618 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BlobGetInAnyHealBall, MSGBOX_DEFAULT
# 619 "data/maps/Route111/scripts.pory"
	setvar VAR_CHANSEY_NURSE_STATE, 1
# 620 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_CHANSEY
# 621 "data/maps/Route111/scripts.pory"
	releaseall
# 622 "data/maps/Route111/scripts.pory"
	end
# 623 "data/maps/Route111/scripts.pory"

# 624 "data/maps/Route111/scripts.pory"
Route111_EventScript_VialUpgradeNurse::
# 625 "data/maps/Route111/scripts.pory"
	lock
# 626 "data/maps/Route111/scripts.pory"
	faceplayer
# 627 "data/maps/Route111/scripts.pory"
	compare VAR_CHANSEY_NURSE_STATE, 6
# 628 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_UpgradeVialHideNurse
# 629 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_BringBlobBack, MSGBOX_DEFAULT
# 630 "data/maps/Route111/scripts.pory"
	release
# 631 "data/maps/Route111/scripts.pory"
	end
# 632 "data/maps/Route111/scripts.pory"

# 633 "data/maps/Route111/scripts.pory"
Route111_EventScript_UpgradeVialHideNurse::
# 634 "data/maps/Route111/scripts.pory"
	msgbox Route111_Text_ThanksPlayer, MSGBOX_AUTOCLOSE
# 635 "data/maps/Route111/scripts.pory"
	givecustommon SPECIES_CHANSEY, 40, ITEM_EVIOLITE, ITEM_PREMIER_BALL, NATURE_BOLD, 0, 252, 0, 252, 0, 4, 0, 0, 0, 0, 0, 0, 0, MOVE_SOFT_BOILED, MOVE_TOXIC, MOVE_SEISMIC_TOSS, MOVE_STEALTH_ROCK, TRUE
# 636 "data/maps/Route111/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 637 "data/maps/Route111/scripts.pory"
	message Route111North_Text_ObtainedChansey
# 638 "data/maps/Route111/scripts.pory"
	waitfanfare
# 639 "data/maps/Route111/scripts.pory"
	waitmessage
# 640 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 641 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
# 642 "data/maps/Route111/scripts.pory"
	goto_if_eq Route111_EventScript_NurseLeaves2
# 643 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_NURSE, Route111_Movement_NurseLeaves1
# 644 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 645 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_NURSE
# 646 "data/maps/Route111/scripts.pory"
	releaseall
# 647 "data/maps/Route111/scripts.pory"
	end
# 648 "data/maps/Route111/scripts.pory"

# 649 "data/maps/Route111/scripts.pory"
Route111_EventScript_NurseLeaves2::
# 650 "data/maps/Route111/scripts.pory"
	applymovement LOCALID_NURSE, Route111_Movement_NurseLeaves2
# 651 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 652 "data/maps/Route111/scripts.pory"
	removeobject LOCALID_NURSE
# 653 "data/maps/Route111/scripts.pory"
	releaseall
# 654 "data/maps/Route111/scripts.pory"
	end
# 655 "data/maps/Route111/scripts.pory"

# 656 "data/maps/Route111/scripts.pory"
Route111_EventScript_PlayerFaceUp::
# 657 "data/maps/Route111/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 658 "data/maps/Route111/scripts.pory"
	waitmovement 0
# 659 "data/maps/Route111/scripts.pory"
	return
# 660 "data/maps/Route111/scripts.pory"

# 661 "data/maps/Route111/scripts.pory"
Route111_Movement_ChanseyJump:
# 662 "data/maps/Route111/scripts.pory"
	jump_in_place_down
# 663 "data/maps/Route111/scripts.pory"
	delay_4
# 664 "data/maps/Route111/scripts.pory"
	jump_in_place_down
# 665 "data/maps/Route111/scripts.pory"
	step_end
# 666 "data/maps/Route111/scripts.pory"

# 667 "data/maps/Route111/scripts.pory"
Route111_Movement_ChanseyEscape:
# 668 "data/maps/Route111/scripts.pory"
	walk_up
# 669 "data/maps/Route111/scripts.pory"
	walk_left
# 670 "data/maps/Route111/scripts.pory"
	walk_up
# 671 "data/maps/Route111/scripts.pory"
	walk_up
# 672 "data/maps/Route111/scripts.pory"
	walk_up
# 673 "data/maps/Route111/scripts.pory"
	step_end
# 674 "data/maps/Route111/scripts.pory"

# 675 "data/maps/Route111/scripts.pory"
Route111_Movement_NurseLeaves1:
# 676 "data/maps/Route111/scripts.pory"
	walk_down
# 677 "data/maps/Route111/scripts.pory"
	walk_down
# 678 "data/maps/Route111/scripts.pory"
	walk_down
# 679 "data/maps/Route111/scripts.pory"
	walk_down
# 680 "data/maps/Route111/scripts.pory"
	walk_down
# 681 "data/maps/Route111/scripts.pory"
	walk_down
# 682 "data/maps/Route111/scripts.pory"
	step_end
# 683 "data/maps/Route111/scripts.pory"

# 684 "data/maps/Route111/scripts.pory"
Route111_Movement_NurseLeaves2:
# 685 "data/maps/Route111/scripts.pory"
	walk_right
# 686 "data/maps/Route111/scripts.pory"
	walk_down
# 687 "data/maps/Route111/scripts.pory"
	walk_down
# 688 "data/maps/Route111/scripts.pory"
	walk_down
# 689 "data/maps/Route111/scripts.pory"
	walk_down
# 690 "data/maps/Route111/scripts.pory"
	walk_down
# 691 "data/maps/Route111/scripts.pory"
	walk_down
# 692 "data/maps/Route111/scripts.pory"
	step_end
# 693 "data/maps/Route111/scripts.pory"

# 694 "data/maps/Route111/scripts.pory"
Route111_Text_BlobGetBackHere:
# 695 "data/maps/Route111/scripts.pory"
	.string "Blob!\n"
# 696 "data/maps/Route111/scripts.pory"
	.string "Stop goofing around and get back here!\p"
# 697 "data/maps/Route111/scripts.pory"
	.string "Argh, how did you even get over there?$"
# 698 "data/maps/Route111/scripts.pory"

# 699 "data/maps/Route111/scripts.pory"
Route111_Text_ThatsJustGreat:
# 700 "data/maps/Route111/scripts.pory"
	.string "Blob, wait! Stop!\p"
# 701 "data/maps/Route111/scripts.pory"
	.string "Oh, that's just great…$"
# 702 "data/maps/Route111/scripts.pory"

# 703 "data/maps/Route111/scripts.pory"
Route111_Text_DidYouSeeThat:
# 704 "data/maps/Route111/scripts.pory"
	.string "Oh, a Trainer!\p"
# 705 "data/maps/Route111/scripts.pory"
	.string "Did you see that? My Chansey's\n"
# 706 "data/maps/Route111/scripts.pory"
	.string "escaped!\p"
# 707 "data/maps/Route111/scripts.pory"
	.string "Please, you've got to help me get it\n"
# 708 "data/maps/Route111/scripts.pory"
	.string "back!\p"
# 709 "data/maps/Route111/scripts.pory"
	.string "I'll make it worth your while.\p"
# 710 "data/maps/Route111/scripts.pory"
	.string "If you can bring Blob back to me, I'll\n"
# 711 "data/maps/Route111/scripts.pory"
	.string "give you a nice reward.\p"
# 712 "data/maps/Route111/scripts.pory"
	.string "Sounds good, right? Good!\p"
# 713 "data/maps/Route111/scripts.pory"
	.string "Here, take Blob's Poké Ball.$"
# 714 "data/maps/Route111/scripts.pory"

# 715 "data/maps/Route111/scripts.pory"
Route111_Text_BlobGetInAnyHealBall:
# 716 "data/maps/Route111/scripts.pory"
	.string "Blob will get in any old Heal Ball,\n"
# 717 "data/maps/Route111/scripts.pory"
	.string "so don't worry if you lose that one.\p"
# 718 "data/maps/Route111/scripts.pory"
	.string "Good luck!$"
# 719 "data/maps/Route111/scripts.pory"

# 720 "data/maps/Route111/scripts.pory"
Route111_Text_BringBlobBack:
# 721 "data/maps/Route111/scripts.pory"
	.string "Blob ran off up Route 111.\p"
# 722 "data/maps/Route111/scripts.pory"
	.string "Please bring it back to me!$\p"
# 723 "data/maps/Route111/scripts.pory"

# 724 "data/maps/Route111/scripts.pory"
Route111_Text_ThanksPlayer:
# 725 "data/maps/Route111/scripts.pory"
	.string "Thanks for catching Blob for me!\p"
# 726 "data/maps/Route111/scripts.pory"
	.string "As promised, here is your reward:\n"
# 727 "data/maps/Route111/scripts.pory"
	.string "A shiny {COLOR BLUE}Chansey{COLOR DARK_GRAY}!\p"
# 728 "data/maps/Route111/scripts.pory"
	.string "Check your party or PC, {PLAYER}!$"
# 729 "data/maps/Route111/scripts.pory"

# 730 "data/maps/Route111/scripts.pory"
Route111_Text_BattleOurFamily: @ 81F1475
# 731 "data/maps/Route111/scripts.pory"
	.string "Hello! I take it you're a traveler.\p"
# 732 "data/maps/Route111/scripts.pory"
	.string "How's this? What do you say to taking\n"
# 733 "data/maps/Route111/scripts.pory"
	.string "on our family of four in a series of\l"
# 734 "data/maps/Route111/scripts.pory"
	.string "Pokémon battles?$"
# 735 "data/maps/Route111/scripts.pory"

# 736 "data/maps/Route111/scripts.pory"
Route111_Text_IsThatSo: @ 81F14F5
# 737 "data/maps/Route111/scripts.pory"
	.string "Is that so?\n"
# 738 "data/maps/Route111/scripts.pory"
	.string "Drop in, if you change your mind!$"
# 739 "data/maps/Route111/scripts.pory"

# 740 "data/maps/Route111/scripts.pory"
Route111_Text_VictorIntro: @ 81F1523
# 741 "data/maps/Route111/scripts.pory"
	.string "That's the spirit! I like you!$"
# 742 "data/maps/Route111/scripts.pory"

# 743 "data/maps/Route111/scripts.pory"
Route111_Text_VictorDefeat: @ 81F1542
# 744 "data/maps/Route111/scripts.pory"
	.string "Aiyah!\n"
# 745 "data/maps/Route111/scripts.pory"
	.string "You're a lot tougher than I expected!$"
# 746 "data/maps/Route111/scripts.pory"

# 747 "data/maps/Route111/scripts.pory"
Route111_Text_VictorPostBattle: @ 81F156F
# 748 "data/maps/Route111/scripts.pory"
	.string "Hey, all!\n"
# 749 "data/maps/Route111/scripts.pory"
	.string "I've found a pretty strong Trainer!$"
# 750 "data/maps/Route111/scripts.pory"

# 751 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaIntro: @ 81F159D
# 752 "data/maps/Route111/scripts.pory"
	.string "Oh, my goodness! Aren't you young?\p"
# 753 "data/maps/Route111/scripts.pory"
	.string "You must be quite the Trainer to beat\n"
# 754 "data/maps/Route111/scripts.pory"
	.string "my husband, though.\p"
# 755 "data/maps/Route111/scripts.pory"
	.string "It's my turn to battle now!$"
# 756 "data/maps/Route111/scripts.pory"

# 757 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaDefeat: @ 81F1616
# 758 "data/maps/Route111/scripts.pory"
	.string "Oh, gosh!\n"
# 759 "data/maps/Route111/scripts.pory"
	.string "I can't get over how strong you are!$"
# 760 "data/maps/Route111/scripts.pory"

# 761 "data/maps/Route111/scripts.pory"
Route111_Text_VictoriaPostBattle: @ 81F1645
# 762 "data/maps/Route111/scripts.pory"
	.string "There's a strong Trainer here!\n"
# 763 "data/maps/Route111/scripts.pory"
	.string "This one's really strong!$"
# 764 "data/maps/Route111/scripts.pory"

# 765 "data/maps/Route111/scripts.pory"
Route111_Text_ViviIntro: @ 81F167E
# 766 "data/maps/Route111/scripts.pory"
	.string "You're stronger than Mommy? Wow!\p"
# 767 "data/maps/Route111/scripts.pory"
	.string "But I'm strong, too!\n"
# 768 "data/maps/Route111/scripts.pory"
	.string "Really! Honestly!$"
# 769 "data/maps/Route111/scripts.pory"

# 770 "data/maps/Route111/scripts.pory"
Route111_Text_ViviDefeat: @ 81F16C6
# 771 "data/maps/Route111/scripts.pory"
	.string "Huh? Did I just lose?$"
# 772 "data/maps/Route111/scripts.pory"

# 773 "data/maps/Route111/scripts.pory"
Route111_Text_ViviPostBattle: @ 81F16DC
# 774 "data/maps/Route111/scripts.pory"
	.string "This stinks…\p"
# 775 "data/maps/Route111/scripts.pory"
	.string "…Snivel… Grandma!$"
# 776 "data/maps/Route111/scripts.pory"

# 777 "data/maps/Route111/scripts.pory"
Route111_Text_VickyIntro: @ 81F16FB
# 778 "data/maps/Route111/scripts.pory"
	.string "How dare you make my granddaughter\n"
# 779 "data/maps/Route111/scripts.pory"
	.string "cry!\p"
# 780 "data/maps/Route111/scripts.pory"
	.string "For that, I'm going to smack you!\n"
# 781 "data/maps/Route111/scripts.pory"
	.string "Prepare to lose!$"
# 782 "data/maps/Route111/scripts.pory"

# 783 "data/maps/Route111/scripts.pory"
Route111_Text_VickyDefeat: @ 81F1756
# 784 "data/maps/Route111/scripts.pory"
	.string "Kwah! You are strong…\n"
# 785 "data/maps/Route111/scripts.pory"
	.string "My granddaughter was right…$"
# 786 "data/maps/Route111/scripts.pory"

# 787 "data/maps/Route111/scripts.pory"
Route111_Text_VickyPostBattle: @ 81F1788
# 788 "data/maps/Route111/scripts.pory"
	.string "If you're not in any hurry,\n"
# 789 "data/maps/Route111/scripts.pory"
	.string "visit with us awhile.$"
# 790 "data/maps/Route111/scripts.pory"

# 791 "data/maps/Route111/scripts.pory"
Route111_Text_ToughToKeepWinningUpTheRanks: @ 81F17BA
# 792 "data/maps/Route111/scripts.pory"
	.string "If you don't raise your Pokémon some\n"
# 793 "data/maps/Route111/scripts.pory"
	.string "more, it could be tough to keep winning\l"
# 794 "data/maps/Route111/scripts.pory"
	.string "up through the ranks.\p"
# 795 "data/maps/Route111/scripts.pory"
	.string "I've heard the Pokémon League's\n"
# 796 "data/maps/Route111/scripts.pory"
	.string "Elite Four are far stronger than\l"
# 797 "data/maps/Route111/scripts.pory"
	.string "any Gym Leader.$"
# 798 "data/maps/Route111/scripts.pory"

# 799 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateFamilyDestroyedMe: @ 81F186E
# 800 "data/maps/Route111/scripts.pory"
	.string "I challenged the Winstrate family,\n"
# 801 "data/maps/Route111/scripts.pory"
	.string "but four matches in a row is tough\l"
# 802 "data/maps/Route111/scripts.pory"
	.string "going… They destroyed me.$"
# 803 "data/maps/Route111/scripts.pory"

# 804 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSignMauville: @ 81F18CE
# 805 "data/maps/Route111/scripts.pory"
	.string "Route 111\n"
# 806 "data/maps/Route111/scripts.pory"
	.string "{DOWN_ARROW} Mauville City$"
# 807 "data/maps/Route111/scripts.pory"

# 808 "data/maps/Route111/scripts.pory"
Route111_Text_WinstrateHouseSign: @ 81F18E8
# 809 "data/maps/Route111/scripts.pory"
	.string "“Our family's hearts beat as one!”\n"
# 810 "data/maps/Route111/scripts.pory"
	.string "The Winstrate's House$"
# 811 "data/maps/Route111/scripts.pory"

# 812 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign112: @ 81F1921
# 813 "data/maps/Route111/scripts.pory"
	.string "Route 111\n"
# 814 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} Route 112$"
# 815 "data/maps/Route111/scripts.pory"

# 816 "data/maps/Route111/scripts.pory"
Route111_Text_RouteSign113: @ 81F1937
# 817 "data/maps/Route111/scripts.pory"
	.string "Route 111\n"
# 818 "data/maps/Route111/scripts.pory"
	.string "{LEFT_ARROW} Route 113$"
# 819 "data/maps/Route111/scripts.pory"

# 820 "data/maps/Route111/scripts.pory"
Route111_Text_OldLadysRestStopSign: @ 81F194D
# 821 "data/maps/Route111/scripts.pory"
	.string "Old Lady's Rest Stop\n"
# 822 "data/maps/Route111/scripts.pory"
	.string "“Come in and rest your tired bones.”$"
# 823 "data/maps/Route111/scripts.pory"

# 824 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerTipsSpAtkSpDef: @ 81F1987
# 825 "data/maps/Route111/scripts.pory"
	.string "Trainer Tips\p"
# 826 "data/maps/Route111/scripts.pory"
	.string "One of the indicators of a Pokémon's\n"
# 827 "data/maps/Route111/scripts.pory"
	.string "powerfulness is Sp. Atk. It stands for\l"
# 828 "data/maps/Route111/scripts.pory"
	.string "“Special Attack.”\p"
# 829 "data/maps/Route111/scripts.pory"
	.string "Likewise, Sp. Def stands for “Special\n"
# 830 "data/maps/Route111/scripts.pory"
	.string "Defense.”$"
# 831 "data/maps/Route111/scripts.pory"

# 832 "data/maps/Route111/scripts.pory"
Route111_Text_ShouldBeMirageTowerAroundHere: @ 81F1A22
# 833 "data/maps/Route111/scripts.pory"
	.string "There should be a tower made of sand\n"
# 834 "data/maps/Route111/scripts.pory"
	.string "around here somewhere.\p"
# 835 "data/maps/Route111/scripts.pory"
	.string "But for some reason, it can be seen\n"
# 836 "data/maps/Route111/scripts.pory"
	.string "sometimes, and sometimes not.\p"
# 837 "data/maps/Route111/scripts.pory"
	.string "That's why I call it the Mirage Tower.$"
# 838 "data/maps/Route111/scripts.pory"

# 839 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerClearlyVisible: @ 81F1AC7
# 840 "data/maps/Route111/scripts.pory"
	.string "I see it!\n"
# 841 "data/maps/Route111/scripts.pory"
	.string "The tower of sand!\p"
# 842 "data/maps/Route111/scripts.pory"
	.string "The sand tower they called a mirage\n"
# 843 "data/maps/Route111/scripts.pory"
	.string "is clearly visible!\p"
# 844 "data/maps/Route111/scripts.pory"
	.string "But it looks so fragile…\n"
# 845 "data/maps/Route111/scripts.pory"
	.string "It could crumble away anytime…\p"
# 846 "data/maps/Route111/scripts.pory"
	.string "I want to go inside it, but I can't\n"
# 847 "data/maps/Route111/scripts.pory"
	.string "get my courage up for it…$"
# 848 "data/maps/Route111/scripts.pory"

# 849 "data/maps/Route111/scripts.pory"
Route111_Text_ThatWasShockingSandRainedDown: @ 81F1B92
# 850 "data/maps/Route111/scripts.pory"
	.string "Whoa…\n"
# 851 "data/maps/Route111/scripts.pory"
	.string "That was shocking.\p"
# 852 "data/maps/Route111/scripts.pory"
	.string "Sand rained down in chunks all of\n"
# 853 "data/maps/Route111/scripts.pory"
	.string "a sudden.\p"
# 854 "data/maps/Route111/scripts.pory"
	.string "What was it like inside?\n"
# 855 "data/maps/Route111/scripts.pory"
	.string "Were there sandy ghosts and such?$"
# 856 "data/maps/Route111/scripts.pory"

# 857 "data/maps/Route111/scripts.pory"
Route111_Text_MirageTowerHasntBeenSeenSince: @ 81F1C12
# 858 "data/maps/Route111/scripts.pory"
	.string "Since I spoke to you, the tower of sand\n"
# 859 "data/maps/Route111/scripts.pory"
	.string "hasn't been seen.\p"
# 860 "data/maps/Route111/scripts.pory"
	.string "Perhaps it really was\n"
# 861 "data/maps/Route111/scripts.pory"
	.string "the Mirage Tower…$"
# 862 "data/maps/Route111/scripts.pory"

# 863 "data/maps/Route111/scripts.pory"
Route111_Text_ClawFossilDisappeared: @ 81F1C74
# 864 "data/maps/Route111/scripts.pory"
	.string "The Claw Fossil disappeared into\n"
# 865 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 866 "data/maps/Route111/scripts.pory"

# 867 "data/maps/Route111/scripts.pory"
Route111_Text_RootFossilDisappeared: @ 81F1C9F
# 868 "data/maps/Route111/scripts.pory"
	.string "The Root Fossil disappeared into\n"
# 869 "data/maps/Route111/scripts.pory"
	.string "the sand…$"
# 870 "data/maps/Route111/scripts.pory"

# 871 "data/maps/Route111/scripts.pory"
Route111_Text_TrainerHillSign: @ 81F1D61
# 872 "data/maps/Route111/scripts.pory"
	.string "{RIGHT_ARROW} Trainer Hill Entrance\p"
# 873 "data/maps/Route111/scripts.pory"
	.string "“Scale the heights, you hot-blooded\n"
# 874 "data/maps/Route111/scripts.pory"
	.string "Trainers!”$"

Route111South_EventScript_Gen8_NPC::
# 879 "data/maps/Route111/scripts.pory"
	lock
# 880 "data/maps/Route111/scripts.pory"
	faceplayer
# 881 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_TYRON
	goto_if 1, Route111South_EventScript_Gen8_NPC_5
Route111South_EventScript_Gen8_NPC_3:
# 896 "data/maps/Route111/scripts.pory"
	msgbox Route111South_EventScript_Gen8_NPC_Text_2
Route111South_EventScript_Gen8_NPC_1:
# 898 "data/maps/Route111/scripts.pory"
	release
	end

Route111South_EventScript_Gen8_NPC_2:
# 888 "data/maps/Route111/scripts.pory"
	msgbox Route111South_EventScript_Gen8_NPC_Text_0
# 889 "data/maps/Route111/scripts.pory"
	givemon SPECIES_SINISTEA, 10, ITEM_NONE
# 890 "data/maps/Route111/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 891 "data/maps/Route111/scripts.pory"
	message Route111South_EventScript_Gen8_NPC_Text_1
# 892 "data/maps/Route111/scripts.pory"
	waitfanfare
	goto Route111South_EventScript_Gen8_NPC_1

Route111South_EventScript_Gen8_NPC_4:
# 883 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BIANCA
	goto_if 1, Route111South_EventScript_Gen8_NPC_9
	goto Route111South_EventScript_Gen8_NPC_3

Route111South_EventScript_Gen8_NPC_5:
# 882 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_CELINA
	goto_if 1, Route111South_EventScript_Gen8_NPC_4
	goto Route111South_EventScript_Gen8_NPC_3

Route111South_EventScript_Gen8_NPC_8:
# 885 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_IRENE
	goto_if 1, Route111South_EventScript_Gen8_NPC_12
	goto Route111South_EventScript_Gen8_NPC_3

Route111South_EventScript_Gen8_NPC_9:
# 884 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_HAYDEN
	goto_if 1, Route111South_EventScript_Gen8_NPC_8
	goto Route111South_EventScript_Gen8_NPC_3

Route111South_EventScript_Gen8_NPC_12:
# 886 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_TRAVIS
	goto_if 1, Route111South_EventScript_Gen8_NPC_2
	goto Route111South_EventScript_Gen8_NPC_3


Route111North_EventScript_Gen8_NPC::
# 907 "data/maps/Route111/scripts.pory"
	lock
# 908 "data/maps/Route111/scripts.pory"
	faceplayer
# 909 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BROOKE_1
	goto_if 1, Route111North_EventScript_Gen8_NPC_4
Route111North_EventScript_Gen8_NPC_3:
# 920 "data/maps/Route111/scripts.pory"
	msgbox Route111North_EventScript_Gen8_NPC_Text_2
Route111North_EventScript_Gen8_NPC_1:
# 922 "data/maps/Route111/scripts.pory"
	release
	end

Route111North_EventScript_Gen8_NPC_2:
# 912 "data/maps/Route111/scripts.pory"
	msgbox Route111North_EventScript_Gen8_NPC_Text_0
# 913 "data/maps/Route111/scripts.pory"
	givemon SPECIES_DARUMAKA_GALARIAN, 10, ITEM_NONE
# 914 "data/maps/Route111/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 915 "data/maps/Route111/scripts.pory"
	message Route111North_EventScript_Gen8_NPC_Text_1
# 916 "data/maps/Route111/scripts.pory"
	waitfanfare
	goto Route111North_EventScript_Gen8_NPC_1

Route111North_EventScript_Gen8_NPC_4:
# 910 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_WILTON_1
	goto_if 1, Route111North_EventScript_Gen8_NPC_2
	goto Route111North_EventScript_Gen8_NPC_3


Route111Desert_EventScript_Gen8_NPC::
# 927 "data/maps/Route111/scripts.pory"
	lock
# 928 "data/maps/Route111/scripts.pory"
	faceplayer
# 929 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_DREW
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_5
Route111Desert_EventScript_Gen8_NPC_3:
# 946 "data/maps/Route111/scripts.pory"
	msgbox Route111Desert_EventScript_Gen8_NPC_Text_2
Route111Desert_EventScript_Gen8_NPC_1:
# 948 "data/maps/Route111/scripts.pory"
	release
	end

Route111Desert_EventScript_Gen8_NPC_2:
# 938 "data/maps/Route111/scripts.pory"
	msgbox Route111Desert_EventScript_Gen8_NPC_Text_0
# 939 "data/maps/Route111/scripts.pory"
	givemon SPECIES_ARCTOZOLT, 50, ITEM_NONE
# 940 "data/maps/Route111/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 941 "data/maps/Route111/scripts.pory"
	message Route111Desert_EventScript_Gen8_NPC_Text_1
# 942 "data/maps/Route111/scripts.pory"
	waitfanfare
	goto Route111Desert_EventScript_Gen8_NPC_1

Route111Desert_EventScript_Gen8_NPC_4:
# 931 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_HEIDI
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_9
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_5:
# 930 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BEAU
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_4
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_8:
# 933 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_DUSTY_1
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_13
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_9:
# 932 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BECKY
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_8
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_12:
# 935 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BRANDEN
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_16
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_13:
# 934 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_CELIA
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_12
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_16:
# 936 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BRYAN
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_2
	goto Route111Desert_EventScript_Gen8_NPC_3


Route111Desert_EventScript_LegendaryNPC::
# 953 "data/maps/Route111/scripts.pory"
	lock
# 954 "data/maps/Route111/scripts.pory"
	faceplayer
# 955 "data/maps/Route111/scripts.pory"
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 957 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route111Desert_EventScript_LegendaryNPC_2
# 981 "data/maps/Route111/scripts.pory"
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_4, MSGBOX_NPC
Route111Desert_EventScript_LegendaryNPC_1:
# 983 "data/maps/Route111/scripts.pory"
	release
	end

Route111Desert_EventScript_LegendaryNPC_2:
# 958 "data/maps/Route111/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route111Desert_EventScript_LegendaryNPC_5
# 965 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_DREW
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_11
Route111Desert_EventScript_LegendaryNPC_9:
# 976 "data/maps/Route111/scripts.pory"
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_3
	goto Route111Desert_EventScript_LegendaryNPC_1

Route111Desert_EventScript_LegendaryNPC_5:
# 959 "data/maps/Route111/scripts.pory"
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_1
	goto Route111Desert_EventScript_LegendaryNPC_1

Route111Desert_EventScript_LegendaryNPC_8:
# 973 "data/maps/Route111/scripts.pory"
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_2
	goto Route111Desert_EventScript_LegendaryNPC_1

Route111Desert_EventScript_LegendaryNPC_10:
# 967 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_HEIDI
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_15
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_11:
# 966 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BEAU
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_10
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_14:
# 969 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_DUSTY_1
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_19
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_15:
# 968 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BECKY
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_14
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_18:
# 971 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BRANDEN
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_22
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_19:
# 970 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_CELIA
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_18
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_22:
# 972 "data/maps/Route111/scripts.pory"
	checktrainerflag TRAINER_BRYAN
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_8
	goto Route111Desert_EventScript_LegendaryNPC_9


Route111_EventScript_Sandslash::
# 988 "data/maps/Route111/scripts.pory"
	lock
# 989 "data/maps/Route111/scripts.pory"
	faceplayer
# 990 "data/maps/Route111/scripts.pory"
	goto_if_set FLAG_DEFEATED_ROUTE111_SANDSLASH, Route111_EventScript_Sandslash_Join
# 991 "data/maps/Route111/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, Route111_EventScript_Sandslash_PreNorman
# 992 "data/maps/Route111/scripts.pory"
	playmoncry SPECIES_SANDSLASH, 2
# 993 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Sandslash_Text_0, MSGBOX_YESNO
# 994 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_Sandslash_2
# 1031 "data/maps/Route111/scripts.pory"
	playmoncry SPECIES_SANDSLASH, 2
# 1032 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Sandslash_Text_3, MSGBOX_DEFAULT
Route111_EventScript_Sandslash_1:
# 1034 "data/maps/Route111/scripts.pory"
	release
	end

Route111_EventScript_Sandslash_2:
# 995 "data/maps/Route111/scripts.pory"
	playmoncry SPECIES_SANDSLASH, 2
# 996 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Sandslash_Text_1, MSGBOX_DEFAULT
# 997 "data/maps/Route111/scripts.pory"
	delay 40
# 998 "data/maps/Route111/scripts.pory"
	waitmoncry
# 999 "data/maps/Route111/scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 1000 "data/maps/Route111/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 1
# 1001 "data/maps/Route111/scripts.pory"
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 3
# 1002 "data/maps/Route111/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 0
# 1003 "data/maps/Route111/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 3
# 1004 "data/maps/Route111/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 1
# 1005 "data/maps/Route111/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
# 1006 "data/maps/Route111/scripts.pory"
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
# 1007 "data/maps/Route111/scripts.pory"
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_SANDSLASH
# 1008 "data/maps/Route111/scripts.pory"
	setflag FLAG_SHINY_CREATION
# 1009 "data/maps/Route111/scripts.pory"
	setwildbattlewithcustommoves SPECIES_SANDSLASH, 0, ITEM_SANDSLASHITE, MOVE_FISSURE, MOVE_STONE_EDGE, MOVE_POISON_JAB, MOVE_KNOCK_OFF, 2, NATURE_JOLLY, 252, 252, 252, 252, 252, 252
# 1010 "data/maps/Route111/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1011 "data/maps/Route111/scripts.pory"
	dowildbattle
# 1012 "data/maps/Route111/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1013 "data/maps/Route111/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1014 "data/maps/Route111/scripts.pory"
	switch VAR_RESULT
# 1015 "data/maps/Route111/scripts.pory"
	case B_OUTCOME_CAUGHT, Route111_EventScript_Sandslash_6
# 1016 "data/maps/Route111/scripts.pory"
	case B_OUTCOME_WON, Route111_EventScript_Sandslash_6
# 1019 "data/maps/Route111/scripts.pory"
	case B_OUTCOME_RAN, Route111_EventScript_Sandslash_7
# 1020 "data/maps/Route111/scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Route111_EventScript_Sandslash_7
	goto Route111_EventScript_Sandslash_1

Route111_EventScript_Sandslash_6:
# 1017 "data/maps/Route111/scripts.pory"
	goto Route111_EventScript_Sandslash_Join
	goto Route111_EventScript_Sandslash_1

Route111_EventScript_Sandslash_7:
# 1021 "data/maps/Route111/scripts.pory"
	setvar VAR_0x8004, SPECIES_SANDSLASH
# 1022 "data/maps/Route111/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1023 "data/maps/Route111/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1024 "data/maps/Route111/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1025 "data/maps/Route111/scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 1026 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Sandslash_Text_2, MSGBOX_DEFAULT
	goto Route111_EventScript_Sandslash_1


Route111_EventScript_Sandslash_PreNorman::
# 1039 "data/maps/Route111/scripts.pory"
	message Route111_EventScript_Sandslash_PreNorman_Text_0
# 1040 "data/maps/Route111/scripts.pory"
	waitmessage
# 1041 "data/maps/Route111/scripts.pory"
	release
	end


Route111_EventScript_Sandslash_Join::
# 1046 "data/maps/Route111/scripts.pory"
	msgbox Route111_EventScript_Sandslash_Join_Text_0, MSGBOX_YESNO
# 1047 "data/maps/Route111/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_Sandslash_Join_2
Route111_EventScript_Sandslash_Join_1:
# 1057 "data/maps/Route111/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ROUTE111_SANDSLASH, Route111_EventScript_Sandslash_Join_5
Route111_EventScript_Sandslash_Join_4:
# 1064 "data/maps/Route111/scripts.pory"
	release
	end

Route111_EventScript_Sandslash_Join_2:
# 1048 "data/maps/Route111/scripts.pory"
	setflag FLAG_OBTAINED_ROUTE111_SANDSLASH
# 1049 "data/maps/Route111/scripts.pory"
	givecustommon SPECIES_SANDSLASH, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_JOLLY, 2, 252, 252, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_FISSURE, MOVE_STONE_EDGE, MOVE_POISON_JAB, MOVE_KNOCK_OFF, TRUE
# 1050 "data/maps/Route111/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1051 "data/maps/Route111/scripts.pory"
	message Route111_EventScript_Sandslash_Join_Text_1
# 1052 "data/maps/Route111/scripts.pory"
	waitfanfare
# 1053 "data/maps/Route111/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1054 "data/maps/Route111/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1055 "data/maps/Route111/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Route111_EventScript_Sandslash_Join_1

Route111_EventScript_Sandslash_Join_5:
# 1058 "data/maps/Route111/scripts.pory"
	setflag FLAG_DEFEATED_ROUTE111_SANDSLASH
# 1059 "data/maps/Route111/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1060 "data/maps/Route111/scripts.pory"
	giveitem ITEM_SANDSLASHITE, 1
# 1061 "data/maps/Route111/scripts.pory"
	message Route111_EventScript_Sandslash_Join_Text_2
# 1062 "data/maps/Route111/scripts.pory"
	waitfanfare
	goto Route111_EventScript_Sandslash_Join_4


Route111South_EventScript_Gen8_NPC_Text_0:
# 888 "data/maps/Route111/scripts.pory"
	.string "Well done indeed! Let us commence the\n"
	.string "celebrations for your victory!$"

Route111South_EventScript_Gen8_NPC_Text_1:
# 891 "data/maps/Route111/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Sinistea{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer here!$"

Route111South_EventScript_Gen8_NPC_Text_2:
# 896 "data/maps/Route111/scripts.pory"
	.string "Greetings, esteemed trainer! Allow me\n"
	.string "to present an exceptional opportunity.\l"
	.string "By besting all trainers on your path,\l"
	.string "you shall be granted a mesmerizing\l"
	.string "companion. I await your triumph.$"

Route111North_EventScript_Gen8_NPC_Text_0:
# 912 "data/maps/Route111/scripts.pory"
	.string "Your rad fighting gave me chills! You're\n"
	.string "a natural born ice-breaker!$"

Route111North_EventScript_Gen8_NPC_Text_1:
# 915 "data/maps/Route111/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Galarian Darumaka{COLOR DARK_GRAY} as a\n"
	.string "gift for defeating the two Ace trainers\l"
	.string "here!$"

Route111North_EventScript_Gen8_NPC_Text_2:
# 920 "data/maps/Route111/scripts.pory"
	.string "If you ice those two guys, I'll show you\n"
	.string "the coolest catch in Galar. Ready to\l"
	.string "'snow' them who's boss and slide to\l"
	.string "victory?$"

Route111Desert_EventScript_Gen8_NPC_Text_0:
# 938 "data/maps/Route111/scripts.pory"
	.string "Congrats... I guess... whatever, take\n"
	.string "this and leave me alone, I got better\l"
	.string "stuff to do than stay in this dried up\l"
	.string "wasteland.$"

Route111Desert_EventScript_Gen8_NPC_Text_1:
# 941 "data/maps/Route111/scripts.pory"
	.string "{PLAYER} got an {COLOR BLUE}Arctozolt{COLOR DARK_GRAY} as a gift\n"
	.string "for defeating every trainer here!$"

Route111Desert_EventScript_Gen8_NPC_Text_2:
# 946 "data/maps/Route111/scripts.pory"
	.string "Listen up, I think they scammed me, this\n"
	.string "doesn't even look like a Pokémon, but\l"
	.string "I'm supposed to give it out to people\l"
	.string "like you... whatever. You know the drill\l"
	.string "by now, defeat everyone, return, yada\l"
	.string "yada yada, good luck.$"

Route111Desert_EventScript_LegendaryNPC_Text_0:
# 955 "data/maps/Route111/scripts.pory"
	.string "Sage: I tell the story of Life, Death\n"
	.string "and Harmony.\p"
	.string "Do you have the patience to hear it?$"

Route111Desert_EventScript_LegendaryNPC_Text_1:
# 959 "data/maps/Route111/scripts.pory"
	.string "At last, our paths converge in this\n"
	.string "parched land, young trainer. The\l"
	.string "Guardians of Harmony rest in this place,\l"
	.string "awaiting for your arrival:\p"
	.string "Xerneas, The Burn that Cures, harbinger\n"
	.string "of life and renewal. Yveltal, The Wicked\l"
	.string "Heart, embodiment of darkness and\l"
	.string "rebirth.\p"
	.string "And finally, Zygarde, the Guardian of\n"
	.string "Balance and Harmony, watchful sentry\l"
	.string "over the fragile equilibrium of nature.\p"
	.string "There's no doubt in my mind, you'll be\n"
	.string "their trainer once you'll reach your full\l"
	.string "potential. Defeat the Pokémon League,\l"
	.string "become champion, and come back to me.\p"
	.string "$"

Route111Desert_EventScript_LegendaryNPC_Text_2:
# 973 "data/maps/Route111/scripts.pory"
	.string "You are now worthy of catching Xerneas,\n"
	.string "Yveltal and Zygarde. I added their\l"
	.string "resting locations to your DexNav. It's\l"
	.string "been a thousand years... but a wait\l"
	.string "worth the while. Good luck, champion.$"

Route111Desert_EventScript_LegendaryNPC_Text_3:
# 976 "data/maps/Route111/scripts.pory"
	.string "Congratulations on becoming the\n"
	.string "champion, but I'm afraid there's still a\l"
	.string "little work before meeting the\l"
	.string "Guardians of Harmony. Defeat all\l"
	.string "trainers in this route, then come back\l"
	.string "to me.$"

Route111Desert_EventScript_LegendaryNPC_Text_4:
# 981 "data/maps/Route111/scripts.pory"
	.string "Shame...$"

Route111_EventScript_Sandslash_Text_0:
# 993 "data/maps/Route111/scripts.pory"
	.string "Sandslash regards you as an equal and\n"
	.string "appears eager to challenge you in\l"
	.string "battle. Are you ready?$"

Route111_EventScript_Sandslash_Text_1:
# 996 "data/maps/Route111/scripts.pory"
	.string "Sandslash: Slash!$"

Route111_EventScript_Sandslash_Text_2:
# 1026 "data/maps/Route111/scripts.pory"
	.string "The {STR_VAR_1} ran away!$"

Route111_EventScript_Sandslash_Text_3:
# 1032 "data/maps/Route111/scripts.pory"
	.string "Sandslash: Slash...$"

Route111_EventScript_Sandslash_PreNorman_Text_0:
# 1039 "data/maps/Route111/scripts.pory"
	.string "Sandslash appears to regard you with a\n"
	.string "sense of superiority. It might be\l"
	.string "advisable to return once you've\l"
	.string "bolstered your strength.{PAUSE_UNTIL_PRESS}$"

Route111_EventScript_Sandslash_Join_Text_0:
# 1046 "data/maps/Route111/scripts.pory"
	.string "Sandslash seems to want to join your\n"
	.string "team, will you let this Sandslash join\l"
	.string "you?$"

Route111_EventScript_Sandslash_Join_Text_1:
# 1051 "data/maps/Route111/scripts.pory"
	.string "{PLAYER} received a Sandslash!$"

Route111_EventScript_Sandslash_Join_Text_2:
# 1061 "data/maps/Route111/scripts.pory"
	.string "{PLAYER} received a Sandslashite!$"

Route111North_Text_ObtainedChansey::
# 902 "data/maps/Route111/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Chansey{COLOR DARK_GRAY}$"
