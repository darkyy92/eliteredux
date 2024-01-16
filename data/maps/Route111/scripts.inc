.set LOCALID_VICTOR, 1
.set LOCALID_VICTORIA, 2
.set LOCALID_VIVI, 3
.set LOCALID_VICKY, 4
.set LOCALID_PLAYER_FALLING, 42
.set LOCALID_NURSE, 43
.set LOCALID_CHANSEY, 44

Route111_MapScripts:: @ 81F0CA7
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
	.byte 0

Route111_OnLoad: @ 81F0CBC
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
	compare VAR_MIRAGE_TOWER_STATE, 1
	call_if_eq Route111_EventScript_ShowTemporaryMirageTower
	end

Route111_EventScript_CloseDesertRuins:: @ 81F0CD1
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, 1
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, 1
	return

@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
Route111_EventScript_ShowTemporaryMirageTower:: @ 81F0CE4
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, 0
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, 0
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, 0
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, 0
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, 0
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, 0
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, 0
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, 0
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, 0
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, 0
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, 0
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, 0
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, 0
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, 0
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, 0
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, 0
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, 0
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, 0
	return

Route111_OnTransition: @ 81F0D87
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special SetMirageTowerVisibility
	call_if_unset FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_SetLayoutNoMirageTower
	compare VAR_MIRAGE_TOWER_STATE, 1
	call_if_eq Route111_EventScript_SetFallingPlayerGfx
	compare VAR_MIRAGE_TOWER_STATE, 2
	call_if_eq Route111_EventScript_SetMirageTowerGone
	call Route111_EventScript_CheckSetSandstorm
	call GabbyAndTy_EventScript_UpdateLocation
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
	end

Route111_EventScript_SetFallingPlayerGfx:: @ 81F0DC2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route111_EventScript_SetFallingPlayerGfxMale
	compare VAR_RESULT, FEMALE
	goto_if_eq Route111_EventScript_SetFallingPlayerGfxFemale
	return

Route111_EventScript_SetFallingPlayerGfxMale:: @ 81F0DDA
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

Route111_EventScript_SetFallingPlayerGfxFemale:: @ 81F0DE0
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

Route111_EventScript_CheckSetSandstorm:: @ 81F0DE6
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 34
	goto_if_lt Route111_EventScript_EndCheckSetSandstorm
	compare VAR_TEMP_1, 107
	goto_if_gt Route111_EventScript_EndCheckSetSandstorm
	compare VAR_TEMP_1, 72
	goto_if_gt Route111_EventScript_SetSandstorm
	compare VAR_TEMP_0, 2000
	goto_if_gt Route111_EventScript_EndCheckSetSandstorm
	compare VAR_TEMP_0, 8
	goto_if_lt Route111_EventScript_EndCheckSetSandstorm
Route111_EventScript_SetSandstorm:: @ 81F0E22
	setweather WEATHER_SANDSTORM
Route111_EventScript_EndCheckSetSandstorm:: @ 81F0E25
	return

Route111_EventScript_SetWinstratesNotDefeated:: @ 81F0E26
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	cleartrainerflag TRAINER_VICTOR
	cleartrainerflag TRAINER_VICTORIA
	cleartrainerflag TRAINER_VIVI
	end

Route111_EventScript_SetLayoutNoMirageTower:: @ 81F0E3C
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
	return

Route111_EventScript_SetMirageTowerGone:: @ 81F0E40
	setvar VAR_MIRAGE_TOWER_STATE, 3
	return

Route111_OnWarp: @ 81F0E46
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
	.2byte 0

Route111_EventScript_HidePlayerForMirageTower:: @ 81F0E50
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	end

Route111_OnFrame: @ 81F0E56
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
	.2byte 0

Route111_EventScript_MirageTowerDisappear:: @ 81F0E60
	lockall
	special StartMirageTowerShake
	waitstate
	delay 24
	playse SE_FALL
	addobject LOCALID_PLAYER_FALLING
	special StartPlayerDescendMirageTower
	waitstate
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	removeobject LOCALID_PLAYER_FALLING
	delay 16
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 16
	special StartMirageTowerDisintegration
	waitstate
	special StartMirageTowerFossilFallAndSink
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 2
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

Route111_EventScript_RootFossilDisappeared:: @ 81F0EA7
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

@ Unused
Route111_Movement_PlayerFall:: @ 81F0EB1
	store_lock_anim
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route111_EventScript_Girl:: @ 81F0EB9
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
	giveitem ITEM_RAZZ_BERRY
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
	special GetPlayerBigGuyGirlString
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_ReceivedBerry:: @ 81F0EF4
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
	release
	end

@ Unused
Route111_EventScript_ViciousSandstormTriggerUp:: @ 81F0EFE
	lockall
	setvar VAR_0x8004, 0
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerDown:: @ 81F0F0A
	lockall
	setvar VAR_0x8004, 1
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerLeft:: @ 81F0F16
	lockall
	setvar VAR_0x8004, 2
	goto Route111_EventScript_ViciousSandstormTrigger
	end

@ Unused
Route111_EventScript_ViciousSandstormTriggerRight:: @ 81F0F22
	lockall
	setvar VAR_0x8004, 3
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTrigger:: @ 81F0F2E
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route111_EventScript_PreventRouteAccess
	setvar VAR_TEMP_3, 1
	releaseall
	end

Route111_EventScript_PreventRouteAccess:: @ 81F0F45
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8004, 0
	call_if_eq Route111_EventScript_PushUpFromRoute
	compare VAR_0x8004, 1
	call_if_eq Route111_EventScript_PushDownFromRoute
	compare VAR_0x8004, 2
	call_if_eq Route111_EventScript_PushLeftFromRoute
	compare VAR_0x8004, 3
	call_if_eq Route111_EventScript_PushRightFromRoute
	releaseall
	end

Route111_EventScript_PushUpFromRoute:: @ 81F0F7C
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushUpFromRoute
	waitmovement 0
	return

Route111_EventScript_PushDownFromRoute:: @ 81F0F87
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushDownFromRoute
	waitmovement 0
	return

Route111_EventScript_PushLeftFromRoute:: @ 81F0F92
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushLeftFromRoute
	waitmovement 0
	return

Route111_EventScript_PushRightFromRoute:: @ 81F0F9D
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushRightFromRoute
	waitmovement 0
	return

Route111_Movement_PushUpFromRoute: @ 81F0FA8
	walk_up
	step_end

Route111_Movement_PushDownFromRoute: @ 81F0FAA
	walk_down
	step_end

Route111_Movement_PushLeftFromRoute: @ 81F0FAC
	walk_left
	step_end

Route111_Movement_PushRightFromRoute: @ 81F0FAE
	walk_right
	step_end

Route111_EventScript_SunTrigger:: @ 81F0FB0
	setweather WEATHER_SUNNY
	fadenewbgm MUS_ROUTE110
	doweather
	setvar VAR_TEMP_3, 0
	end

Route111_EventScript_SandstormTrigger:: @ 81F0FBD
	setweather WEATHER_SANDSTORM
	fadenewbgm MUS_ROUTE111
	doweather
	end

Route111_EventScript_Victor:: @ 81F0FC5
	lock
	faceplayer
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route111_EventScript_BattleWinstrates
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_BattleWinstrates:: @ 81F0FE7
	setflag FLAG_SYS_DISABLE_AUTOHEAL
	special HealPlayerParty
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
	applymovement LOCALID_VICTOR, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICTOR, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICTOR
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VICTORIA
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
	applymovement LOCALID_VICTORIA, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICTORIA
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VIVI
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
	applymovement LOCALID_VIVI, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VIVI
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VICKY
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICKY, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICKY
	clearflag FLAG_SYS_DISABLE_AUTOHEAL
	call Route111_EventScript_CloseWinstrateDoor
	release
	end

Route111_EventScript_OpenWinstrateDoor:: @ 81F113C
	opendoor 13, 113
	waitdooranim
	return

Route111_EventScript_CloseWinstrateDoor:: @ 81F1143
	closedoor 13, 113
	waitdooranim
	return

Route111_Movement_WinstrateEnterHouse: @ 81F114A
	walk_in_place_fastest_up
	walk_up
	step_end

Route111_Movement_WinstrateExitHouse: @ 81F114D
	walk_down
	step_end

Route111_Movement_WaitForNextWinstrate: @ 81F114F
	delay_16
	delay_16
	delay_16
	step_end

Route111_EventScript_RouteSignMauville:: @ 81F1153
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route111_EventScript_WinstrateHouseSign:: @ 81F115C
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign112:: @ 81F1165
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign113:: @ 81F116E
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
	end

Route111_EventScript_OldLadysRestStopSign:: @ 81F1177
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
	end

Route111_EventScript_TrainerTipsSpAtkSpDef:: @ 81F1180
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
	end

Route111_EventScript_Man1:: @ 81F1189
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
	end

Route111_EventScript_Man2:: @ 81F1192
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
	end

Route111_EventScript_Hiker:: @ 81F119B
	lock
	faceplayer
	compare VAR_MIRAGE_TOWER_STATE, 3
	goto_if_eq Route111_EventScript_HikerMirageTowerGone
	compare VAR_MIRAGE_TOWER_STATE, 2
	goto_if_eq Route111_EventScript_HikerMirageTowerDisintegrated
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerGone:: @ 81F11C6
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerDisintegrated:: @ 81F11D0
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerVisible:: @ 81F11DA
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_Drew:: @ 81F1204
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Heidi:: @ 81F121B
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Beau:: @ 81F1232
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Becky:: @ 81F1249
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Dusty:: @ 81F1260
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_RematchDusty
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterDusty:: @ 81F128C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DUSTY_1
	release
	end

Route111_EventScript_RematchDusty:: @ 81F12AB
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Travis:: @ 81F12C2
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Irene:: @ 81F12D9
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Daisuke:: @ 81F12F0
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Wilton:: @ 81F1307
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_RematchWilton
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterWilton:: @ 81F1333
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_1
	release
	end

Route111_EventScript_RematchWilton:: @ 81F1352
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Brooke:: @ 81F1369
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route111_EventScript_RematchBrooke
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterBrooke:: @ 81F1395
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BROOKE_1
	release
	end

Route111_EventScript_RematchBrooke:: @ 81F13B4
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Hayden:: @ 81F13CB
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bianca:: @ 81F13E2
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Tyron:: @ 81F13F9
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celina:: @ 81F1410
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celia:: @ 81F1427
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bryan:: @ 81F143E
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Branden:: @ 81F1455
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_TrainerHillSign:: @ 81F146C
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
	end

Route111_EventScript_ChanseyBlob::
	lockall
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	call_if_ne Route111_EventScript_PlayerFaceUp
	applymovement LOCALID_NURSE, Common_Movement_WalkInPlaceFastestUp
	applymovement LOCALID_CHANSEY, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox Route111_Text_BlobGetBackHere, MSGBOX_DEFAULT
	applymovement LOCALID_CHANSEY, Route111_Movement_ChanseyJump
	waitmovement 0
	waitse
	playmoncry SPECIES_CHANSEY, 0
	delay 40
	waitmoncry
	applymovement LOCALID_CHANSEY, Route111_Movement_ChanseyEscape
	waitmovement 0
	msgbox Route111_Text_ThatsJustGreat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_NURSE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_NURSE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox Route111_Text_DidYouSeeThat, MSGBOX_DEFAULT
	giveitem ITEM_HEAL_BALL
	msgbox Route111_Text_BlobGetInAnyHealBall, MSGBOX_DEFAULT
	setvar VAR_CHANSEY_NURSE_STATE, 1
	removeobject LOCALID_CHANSEY
	releaseall
	end

Route111_EventScript_VialUpgradeNurse::
	lock
	faceplayer
	compare VAR_CHANSEY_NURSE_STATE, 6
	goto_if_eq Route111_EventScript_UpgradeVialHideNurse
	msgbox Route111_Text_BringBlobBack, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_UpgradeVialHideNurse::
	msgbox Route111_Text_ThanksPlayer, MSGBOX_AUTOCLOSE
	givecustommon SPECIES_CHANSEY, 40, ITEM_EVIOLITE, ITEM_PREMIER_BALL, NATURE_BOLD, 0, 252, 0, 252, 0, 4, 0, 0, 0, 0, 0, 0, 0, MOVE_SOFT_BOILED, MOVE_TOXIC, MOVE_SEISMIC_TOSS, MOVE_STEALTH_ROCK, TRUE
	playfanfare MUS_OBTAIN_ITEM
	message Route111North_Text_ObtainedChansey
	waitfanfare
	waitmessage
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq Route111_EventScript_NurseLeaves2
	applymovement LOCALID_NURSE, Route111_Movement_NurseLeaves1
	waitmovement 0
	removeobject LOCALID_NURSE
	releaseall
	end

Route111_EventScript_NurseLeaves2::
	applymovement LOCALID_NURSE, Route111_Movement_NurseLeaves2
	waitmovement 0
	removeobject LOCALID_NURSE
	releaseall
	end

Route111_EventScript_PlayerFaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

Route111_Movement_ChanseyJump:
	jump_in_place_down
	delay_4
	jump_in_place_down
	step_end

Route111_Movement_ChanseyEscape:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

Route111_Movement_NurseLeaves1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route111_Movement_NurseLeaves2:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route111_Text_BlobGetBackHere:
	.string "Blob!\n"
	.string "Stop goofing around and get back here!\p"
	.string "Argh, how did you even get over there?$"

Route111_Text_ThatsJustGreat:
	.string "Blob, wait! Stop!\p"
	.string "Oh, that's just great…$"

Route111_Text_DidYouSeeThat:
	.string "Oh, a Trainer!\p"
	.string "Did you see that? My Chansey's\n"
	.string "escaped!\p"
	.string "Please, you've got to help me get it\n"
	.string "back!\p"
	.string "I'll make it worth your while.\p"
	.string "If you can bring Blob back to me, I'll\n"
	.string "give you a nice reward.\p"
	.string "Sounds good, right? Good!\p"
	.string "Here, take Blob's Poké Ball.$"

Route111_Text_BlobGetInAnyHealBall:
	.string "Blob will get in any old Heal Ball,\n"
	.string "so don't worry if you lose that one.\p"
	.string "Good luck!$"

Route111_Text_BringBlobBack:
	.string "Blob ran off up Route 111.\p"
	.string "Please bring it back to me!$\p"

Route111_Text_ThanksPlayer:
	.string "Thanks for catching Blob for me!\p"
	.string "As promised, here is your reward:\n"
	.string "A shiny {COLOR BLUE}Chansey{COLOR DARK_GRAY}!\p"
	.string "Check your party or PC, {PLAYER}!$"

Route111_Text_BattleOurFamily: @ 81F1475
	.string "Hello! I take it you're a traveler.\p"
	.string "How's this? What do you say to taking\n"
	.string "on our family of four in a series of\l"
	.string "Pokémon battles?$"

Route111_Text_IsThatSo: @ 81F14F5
	.string "Is that so?\n"
	.string "Drop in, if you change your mind!$"

Route111_Text_VictorIntro: @ 81F1523
	.string "That's the spirit! I like you!$"

Route111_Text_VictorDefeat: @ 81F1542
	.string "Aiyah!\n"
	.string "You're a lot tougher than I expected!$"

Route111_Text_VictorPostBattle: @ 81F156F
	.string "Hey, all!\n"
	.string "I've found a pretty strong Trainer!$"

Route111_Text_VictoriaIntro: @ 81F159D
	.string "Oh, my goodness! Aren't you young?\p"
	.string "You must be quite the Trainer to beat\n"
	.string "my husband, though.\p"
	.string "It's my turn to battle now!$"

Route111_Text_VictoriaDefeat: @ 81F1616
	.string "Oh, gosh!\n"
	.string "I can't get over how strong you are!$"

Route111_Text_VictoriaPostBattle: @ 81F1645
	.string "There's a strong Trainer here!\n"
	.string "This one's really strong!$"

Route111_Text_ViviIntro: @ 81F167E
	.string "You're stronger than Mommy? Wow!\p"
	.string "But I'm strong, too!\n"
	.string "Really! Honestly!$"

Route111_Text_ViviDefeat: @ 81F16C6
	.string "Huh? Did I just lose?$"

Route111_Text_ViviPostBattle: @ 81F16DC
	.string "This stinks…\p"
	.string "…Snivel… Grandma!$"

Route111_Text_VickyIntro: @ 81F16FB
	.string "How dare you make my granddaughter\n"
	.string "cry!\p"
	.string "For that, I'm going to smack you!\n"
	.string "Prepare to lose!$"

Route111_Text_VickyDefeat: @ 81F1756
	.string "Kwah! You are strong…\n"
	.string "My granddaughter was right…$"

Route111_Text_VickyPostBattle: @ 81F1788
	.string "If you're not in any hurry,\n"
	.string "visit with us awhile.$"

Route111_Text_ToughToKeepWinningUpTheRanks: @ 81F17BA
	.string "If you don't raise your Pokémon some\n"
	.string "more, it could be tough to keep winning\l"
	.string "up through the ranks.\p"
	.string "I've heard the Pokémon League's\n"
	.string "Elite Four are far stronger than\l"
	.string "any Gym Leader.$"

Route111_Text_WinstrateFamilyDestroyedMe: @ 81F186E
	.string "I challenged the Winstrate family,\n"
	.string "but four matches in a row is tough\l"
	.string "going… They destroyed me.$"

Route111_Text_RouteSignMauville: @ 81F18CE
	.string "Route 111\n"
	.string "{DOWN_ARROW} Mauville City$"

Route111_Text_WinstrateHouseSign: @ 81F18E8
	.string "“Our family's hearts beat as one!”\n"
	.string "The Winstrate's House$"

Route111_Text_RouteSign112: @ 81F1921
	.string "Route 111\n"
	.string "{LEFT_ARROW} Route 112$"

Route111_Text_RouteSign113: @ 81F1937
	.string "Route 111\n"
	.string "{LEFT_ARROW} Route 113$"

Route111_Text_OldLadysRestStopSign: @ 81F194D
	.string "Old Lady's Rest Stop\n"
	.string "“Come in and rest your tired bones.”$"

Route111_Text_TrainerTipsSpAtkSpDef: @ 81F1987
	.string "Trainer Tips\p"
	.string "One of the indicators of a Pokémon's\n"
	.string "powerfulness is Sp. Atk. It stands for\l"
	.string "“Special Attack.”\p"
	.string "Likewise, Sp. Def stands for “Special\n"
	.string "Defense.”$"

Route111_Text_ShouldBeMirageTowerAroundHere: @ 81F1A22
	.string "There should be a tower made of sand\n"
	.string "around here somewhere.\p"
	.string "But for some reason, it can be seen\n"
	.string "sometimes, and sometimes not.\p"
	.string "That's why I call it the Mirage Tower.$"

Route111_Text_MirageTowerClearlyVisible: @ 81F1AC7
	.string "I see it!\n"
	.string "The tower of sand!\p"
	.string "The sand tower they called a mirage\n"
	.string "is clearly visible!\p"
	.string "But it looks so fragile…\n"
	.string "It could crumble away anytime…\p"
	.string "I want to go inside it, but I can't\n"
	.string "get my courage up for it…$"

Route111_Text_ThatWasShockingSandRainedDown: @ 81F1B92
	.string "Whoa…\n"
	.string "That was shocking.\p"
	.string "Sand rained down in chunks all of\n"
	.string "a sudden.\p"
	.string "What was it like inside?\n"
	.string "Were there sandy ghosts and such?$"

Route111_Text_MirageTowerHasntBeenSeenSince: @ 81F1C12
	.string "Since I spoke to you, the tower of sand\n"
	.string "hasn't been seen.\p"
	.string "Perhaps it really was\n"
	.string "the Mirage Tower…$"

Route111_Text_ClawFossilDisappeared: @ 81F1C74
	.string "The Claw Fossil disappeared into\n"
	.string "the sand…$"

Route111_Text_RootFossilDisappeared: @ 81F1C9F
	.string "The Root Fossil disappeared into\n"
	.string "the sand…$"

Route111_Text_TrainerHillSign: @ 81F1D61
	.string "{RIGHT_ARROW} Trainer Hill Entrance\p"
	.string "“Scale the heights, you hot-blooded\n"
	.string "Trainers!”$"

Route111South_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_TYRON
	goto_if 1, Route111South_EventScript_Gen8_NPC_5
Route111South_EventScript_Gen8_NPC_3:
	msgbox Route111South_EventScript_Gen8_NPC_Text_2
Route111South_EventScript_Gen8_NPC_1:
	release
	end

Route111South_EventScript_Gen8_NPC_2:
	msgbox Route111South_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_SINISTEA, 10, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message Route111South_EventScript_Gen8_NPC_Text_1
	waitfanfare
	goto Route111South_EventScript_Gen8_NPC_1

Route111South_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_BIANCA
	goto_if 1, Route111South_EventScript_Gen8_NPC_9
	goto Route111South_EventScript_Gen8_NPC_3

Route111South_EventScript_Gen8_NPC_5:
	checktrainerflag TRAINER_CELINA
	goto_if 1, Route111South_EventScript_Gen8_NPC_4
	goto Route111South_EventScript_Gen8_NPC_3

Route111South_EventScript_Gen8_NPC_8:
	checktrainerflag TRAINER_IRENE
	goto_if 1, Route111South_EventScript_Gen8_NPC_12
	goto Route111South_EventScript_Gen8_NPC_3

Route111South_EventScript_Gen8_NPC_9:
	checktrainerflag TRAINER_HAYDEN
	goto_if 1, Route111South_EventScript_Gen8_NPC_8
	goto Route111South_EventScript_Gen8_NPC_3

Route111South_EventScript_Gen8_NPC_12:
	checktrainerflag TRAINER_TRAVIS
	goto_if 1, Route111South_EventScript_Gen8_NPC_2
	goto Route111South_EventScript_Gen8_NPC_3


Route111North_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_BROOKE_1
	goto_if 1, Route111North_EventScript_Gen8_NPC_4
Route111North_EventScript_Gen8_NPC_3:
	msgbox Route111North_EventScript_Gen8_NPC_Text_2
Route111North_EventScript_Gen8_NPC_1:
	release
	end

Route111North_EventScript_Gen8_NPC_2:
	msgbox Route111North_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_DARUMAKA_GALARIAN, 10, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message Route111North_EventScript_Gen8_NPC_Text_1
	waitfanfare
	goto Route111North_EventScript_Gen8_NPC_1

Route111North_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_WILTON_1
	goto_if 1, Route111North_EventScript_Gen8_NPC_2
	goto Route111North_EventScript_Gen8_NPC_3


Route111Desert_EventScript_Gen8_NPC::
	lock
	faceplayer
	checktrainerflag TRAINER_DREW
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_5
Route111Desert_EventScript_Gen8_NPC_3:
	msgbox Route111Desert_EventScript_Gen8_NPC_Text_2
Route111Desert_EventScript_Gen8_NPC_1:
	release
	end

Route111Desert_EventScript_Gen8_NPC_2:
	msgbox Route111Desert_EventScript_Gen8_NPC_Text_0
	givemon SPECIES_ARCTOZOLT, 50, ITEM_NONE
	playfanfare MUS_OBTAIN_ITEM
	message Route111Desert_EventScript_Gen8_NPC_Text_1
	waitfanfare
	goto Route111Desert_EventScript_Gen8_NPC_1

Route111Desert_EventScript_Gen8_NPC_4:
	checktrainerflag TRAINER_HEIDI
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_9
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_5:
	checktrainerflag TRAINER_BEAU
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_4
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_8:
	checktrainerflag TRAINER_DUSTY_1
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_13
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_9:
	checktrainerflag TRAINER_BECKY
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_8
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_12:
	checktrainerflag TRAINER_BRANDEN
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_16
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_13:
	checktrainerflag TRAINER_CELIA
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_12
	goto Route111Desert_EventScript_Gen8_NPC_3

Route111Desert_EventScript_Gen8_NPC_16:
	checktrainerflag TRAINER_BRYAN
	goto_if 1, Route111Desert_EventScript_Gen8_NPC_2
	goto Route111Desert_EventScript_Gen8_NPC_3


Route111Desert_EventScript_LegendaryNPC::
	lock
	faceplayer
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111Desert_EventScript_LegendaryNPC_2
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_4, MSGBOX_NPC
Route111Desert_EventScript_LegendaryNPC_1:
	release
	end

Route111Desert_EventScript_LegendaryNPC_2:
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route111Desert_EventScript_LegendaryNPC_5
	checktrainerflag TRAINER_DREW
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_11
Route111Desert_EventScript_LegendaryNPC_9:
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_3
	goto Route111Desert_EventScript_LegendaryNPC_1

Route111Desert_EventScript_LegendaryNPC_5:
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_1
	goto Route111Desert_EventScript_LegendaryNPC_1

Route111Desert_EventScript_LegendaryNPC_8:
	msgbox Route111Desert_EventScript_LegendaryNPC_Text_2
	goto Route111Desert_EventScript_LegendaryNPC_1

Route111Desert_EventScript_LegendaryNPC_10:
	checktrainerflag TRAINER_HEIDI
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_15
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_11:
	checktrainerflag TRAINER_BEAU
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_10
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_14:
	checktrainerflag TRAINER_DUSTY_1
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_19
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_15:
	checktrainerflag TRAINER_BECKY
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_14
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_18:
	checktrainerflag TRAINER_BRANDEN
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_22
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_19:
	checktrainerflag TRAINER_CELIA
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_18
	goto Route111Desert_EventScript_LegendaryNPC_9

Route111Desert_EventScript_LegendaryNPC_22:
	checktrainerflag TRAINER_BRYAN
	goto_if 1, Route111Desert_EventScript_LegendaryNPC_8
	goto Route111Desert_EventScript_LegendaryNPC_9


Route111_EventScript_Sandslash::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ROUTE111_SANDSLASH, Route111_EventScript_Sandslash_Join
	goto_if_unset FLAG_BADGE05_GET, Route111_EventScript_Sandslash_PreNorman
	playmoncry SPECIES_SANDSLASH, 2
	msgbox Route111_EventScript_Sandslash_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_Sandslash_2
	playmoncry SPECIES_SANDSLASH, 2
	msgbox Route111_EventScript_Sandslash_Text_3, MSGBOX_DEFAULT
Route111_EventScript_Sandslash_1:
	release
	end

Route111_EventScript_Sandslash_2:
	playmoncry SPECIES_SANDSLASH, 2
	msgbox Route111_EventScript_Sandslash_Text_1, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setflag FLAG_TOTEM_BATTLE
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 1
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 3
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 0
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 3
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 1
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_SANDSLASH
	setflag FLAG_SHINY_CREATION
	setwildbattlewithcustommoves SPECIES_SANDSLASH, 0, ITEM_SANDSLASHITE, MOVE_FISSURE, MOVE_STONE_EDGE, MOVE_POISON_JAB, MOVE_KNOCK_OFF, 2, NATURE_JOLLY, 252, 252, 252, 252, 252, 252
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Route111_EventScript_Sandslash_6
	case B_OUTCOME_WON, Route111_EventScript_Sandslash_6
	case B_OUTCOME_RAN, Route111_EventScript_Sandslash_7
	case B_OUTCOME_PLAYER_TELEPORTED, Route111_EventScript_Sandslash_7
	goto Route111_EventScript_Sandslash_1

Route111_EventScript_Sandslash_6:
	goto Route111_EventScript_Sandslash_Join
	goto Route111_EventScript_Sandslash_1

Route111_EventScript_Sandslash_7:
	setvar VAR_0x8004, SPECIES_SANDSLASH
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox Route111_EventScript_Sandslash_Text_2, MSGBOX_DEFAULT
	goto Route111_EventScript_Sandslash_1


Route111_EventScript_Sandslash_PreNorman::
	message Route111_EventScript_Sandslash_PreNorman_Text_0
	waitmessage
	release
	end


Route111_EventScript_Sandslash_Join::
	msgbox Route111_EventScript_Sandslash_Join_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_EventScript_Sandslash_Join_2
Route111_EventScript_Sandslash_Join_1:
	goto_if_unset FLAG_DEFEATED_ROUTE111_SANDSLASH, Route111_EventScript_Sandslash_Join_5
Route111_EventScript_Sandslash_Join_4:
	release
	end

Route111_EventScript_Sandslash_Join_2:
	setflag FLAG_OBTAINED_ROUTE111_SANDSLASH
	givecustommon SPECIES_SANDSLASH, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_JOLLY, 2, 252, 252, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_FISSURE, MOVE_STONE_EDGE, MOVE_POISON_JAB, MOVE_KNOCK_OFF, TRUE
	playfanfare MUS_OBTAIN_ITEM
	message Route111_EventScript_Sandslash_Join_Text_1
	waitfanfare
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Route111_EventScript_Sandslash_Join_1

Route111_EventScript_Sandslash_Join_5:
	setflag FLAG_DEFEATED_ROUTE111_SANDSLASH
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_SANDSLASHITE, 1
	message Route111_EventScript_Sandslash_Join_Text_2
	waitfanfare
	goto Route111_EventScript_Sandslash_Join_4


Route111South_EventScript_Gen8_NPC_Text_0:
	.string "Well done indeed! Let us commence the\n"
	.string "celebrations for your victory!$"

Route111South_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got a {COLOR BLUE}Sinistea{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer here!$"

Route111South_EventScript_Gen8_NPC_Text_2:
	.string "Greetings, esteemed trainer! Allow me\n"
	.string "to present an exceptional opportunity.\l"
	.string "By besting all trainers on your path,\l"
	.string "you shall be granted a mesmerizing\l"
	.string "companion. I await your triumph.$"

Route111North_EventScript_Gen8_NPC_Text_0:
	.string "Your rad fighting gave me chills! You're\n"
	.string "a natural born ice-breaker!$"

Route111North_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got a {COLOR BLUE}Galarian Darumaka{COLOR DARK_GRAY} as a\n"
	.string "gift for defeating the two Ace\l"
	.string "trainers here!$"

Route111North_EventScript_Gen8_NPC_Text_2:
	.string "If you ice those two guys, I'll show you\n"
	.string "the coolest catch in Galar. Ready to\l"
	.string "'snow' them who's boss and slide to\l"
	.string "victory?$"

Route111Desert_EventScript_Gen8_NPC_Text_0:
	.string "Congrats... I guess... whatever, take\n"
	.string "this and leave me alone, I got better\l"
	.string "stuff to do than stay in this dried up\l"
	.string "wasteland.$"

Route111Desert_EventScript_Gen8_NPC_Text_1:
	.string "{PLAYER} got an {COLOR BLUE}Arctozolt{COLOR DARK_GRAY} as a gift\n"
	.string "for defeating every trainer here!$"

Route111Desert_EventScript_Gen8_NPC_Text_2:
	.string "Listen up, I think they scammed me, this\n"
	.string "doesn't even look like a Pokémon, but\l"
	.string "I'm supposed to give it out to people\l"
	.string "like you... whatever. You know the drill\l"
	.string "by now, defeat everyone, return, yada\l"
	.string "yada yada, good luck.$"

Route111Desert_EventScript_LegendaryNPC_Text_0:
	.string "Sage: I tell the story of Life, Death\n"
	.string "and Harmony.\p"
	.string "Do you have the patience to hear it?$"

Route111Desert_EventScript_LegendaryNPC_Text_1:
	.string "At last, our paths converge in this\n"
	.string "parched land, young trainer. The\l"
	.string "Guardians of Harmony rest in this\l"
	.string "place, awaiting for your arrival:\p"
	.string "Xerneas, The Burn that Cures, harbinger\n"
	.string "of life and renewal. Yveltal, The Wicked\l"
	.string "Heart, embodiment of darkness and\l"
	.string "rebirth.\p"
	.string "And finally, Zygarde, the Guardian of\n"
	.string "Balance and Harmony, watchful sentry\l"
	.string "over the fragile equilibrium of nature.\p"
	.string "There's no doubt in my mind, you'll be\n"
	.string "their trainer once you'll reach your\l"
	.string "full potential. Defeat the Pokémon\l"
	.string "League, become champion, and come back\l"
	.string "to me.\p"
	.string "$"

Route111Desert_EventScript_LegendaryNPC_Text_2:
	.string "You are now worthy of catching Xerneas,\n"
	.string "Yveltal and Zygarde. I added their\l"
	.string "resting locations to your DexNav. It's\l"
	.string "been a thousand years... but a wait\l"
	.string "worth the while. Good luck, champion.$"

Route111Desert_EventScript_LegendaryNPC_Text_3:
	.string "Congratulations on becoming the\n"
	.string "champion, but I'm afraid there's still a\l"
	.string "little work before meeting the\l"
	.string "Guardians of Harmony. Defeat all\l"
	.string "trainers in this route, then come back\l"
	.string "to me.$"

Route111Desert_EventScript_LegendaryNPC_Text_4:
	.string "Shame...$"

Route111_EventScript_Sandslash_Text_0:
	.string "Sandslash regards you as an equal and\n"
	.string "appears eager to challenge you in\l"
	.string "battle. Are you ready?$"

Route111_EventScript_Sandslash_Text_1:
	.string "Sandslash: Slash!$"

Route111_EventScript_Sandslash_Text_2:
	.string "The {STR_VAR_1} ran away!$"

Route111_EventScript_Sandslash_Text_3:
	.string "Sandslash: Slash...$"

Route111_EventScript_Sandslash_PreNorman_Text_0:
	.string "Sandslash appears to regard you with a\n"
	.string "sense of superiority. It might be\l"
	.string "advisable to return once you've\l"
	.string "bolstered your strength.{PAUSE_UNTIL_PRESS}$"

Route111_EventScript_Sandslash_Join_Text_0:
	.string "Sandslash seems to want to join your\n"
	.string "team, will you let this Sandslash join\l"
	.string "you?$"

Route111_EventScript_Sandslash_Join_Text_1:
	.string "{PLAYER} received a Sandslash!$"

Route111_EventScript_Sandslash_Join_Text_2:
	.string "{PLAYER} received a Sandslashite!$"

Route111North_Text_ObtainedChansey::
	.string "{PLAYER} got a {COLOR BLUE}Chansey{COLOR DARK_GRAY}$"
