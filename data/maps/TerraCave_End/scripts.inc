# 1 "data/maps/TerraCave_End/scripts.pory"

# 2 "data/maps/TerraCave_End/scripts.pory"
.set LOCALID_GROUDON, 1
# 3 "data/maps/TerraCave_End/scripts.pory"

# 4 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_MapScripts:: @ 823B0B0
# 5 "data/maps/TerraCave_End/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_OnResume
# 6 "data/maps/TerraCave_End/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_OnTransition
# 7 "data/maps/TerraCave_End/scripts.pory"
	.byte 0
# 8 "data/maps/TerraCave_End/scripts.pory"

# 9 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_OnResume: @ 823B0BB
# 10 "data/maps/TerraCave_End/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TerraCave_End_EventScript_TryRemoveGroudon
# 11 "data/maps/TerraCave_End/scripts.pory"
	end
# 12 "data/maps/TerraCave_End/scripts.pory"

# 13 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_EventScript_TryRemoveGroudon:: @ 823B0C5
# 14 "data/maps/TerraCave_End/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/TerraCave_End/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 16 "data/maps/TerraCave_End/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 17 "data/maps/TerraCave_End/scripts.pory"
	removeobject LOCALID_GROUDON
# 18 "data/maps/TerraCave_End/scripts.pory"
	return
# 19 "data/maps/TerraCave_End/scripts.pory"

# 20 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_OnTransition: @ 823B0D9
# 21 "data/maps/TerraCave_End/scripts.pory"
	call_if_unset FLAG_DEFEATED_GROUDON, TerraCave_End_EventScript_ShowGroudon
# 22 "data/maps/TerraCave_End/scripts.pory"
	end
# 23 "data/maps/TerraCave_End/scripts.pory"

# 24 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_EventScript_ShowGroudon:: @ 823B0E3
# 25 "data/maps/TerraCave_End/scripts.pory"
	clearflag FLAG_HIDE_TERRA_CAVE_GROUDON
# 26 "data/maps/TerraCave_End/scripts.pory"
	setvar VAR_TEMP_1, 1
# 27 "data/maps/TerraCave_End/scripts.pory"
	return
# 28 "data/maps/TerraCave_End/scripts.pory"

# 29 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_EventScript_Groudon:: @ 823B0EC
# 30 "data/maps/TerraCave_End/scripts.pory"
	lockall
# 31 "data/maps/TerraCave_End/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 32 "data/maps/TerraCave_End/scripts.pory"
	waitmovement 0
# 33 "data/maps/TerraCave_End/scripts.pory"
	applymovement LOCALID_GROUDON, TerraCave_End_Movement_GroudonApproach
# 34 "data/maps/TerraCave_End/scripts.pory"
	waitmovement 0
# 35 "data/maps/TerraCave_End/scripts.pory"
	waitse
# 36 "data/maps/TerraCave_End/scripts.pory"
	playmoncry SPECIES_GROUDON, 2
# 37 "data/maps/TerraCave_End/scripts.pory"
	delay 40
# 38 "data/maps/TerraCave_End/scripts.pory"
	waitmoncry
# 39 "data/maps/TerraCave_End/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_GROUDON
# 40 "data/maps/TerraCave_End/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 41 "data/maps/TerraCave_End/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 42 "data/maps/TerraCave_End/scripts.pory"
	setwildbattle SPECIES_GROUDON, VAR_0x800A, ITEM_GROUND_GEM
# 43 "data/maps/TerraCave_End/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 44 "data/maps/TerraCave_End/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 45 "data/maps/TerraCave_End/scripts.pory"
	waitstate
# 46 "data/maps/TerraCave_End/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 47 "data/maps/TerraCave_End/scripts.pory"
	setvar VAR_TEMP_1, 0
# 48 "data/maps/TerraCave_End/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 49 "data/maps/TerraCave_End/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 50 "data/maps/TerraCave_End/scripts.pory"
	goto_if_eq TerraCave_End_EventScript_DefeatedGroudon
# 51 "data/maps/TerraCave_End/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 52 "data/maps/TerraCave_End/scripts.pory"
	goto_if_eq TerraCave_End_EventScript_RanFromGroudon
# 53 "data/maps/TerraCave_End/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 54 "data/maps/TerraCave_End/scripts.pory"
	goto_if_eq TerraCave_End_EventScript_RanFromGroudon
# 55 "data/maps/TerraCave_End/scripts.pory"
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 56 "data/maps/TerraCave_End/scripts.pory"
	setflag FLAG_DEFEATED_GROUDON
# 57 "data/maps/TerraCave_End/scripts.pory"
	releaseall
# 58 "data/maps/TerraCave_End/scripts.pory"
	end
# 59 "data/maps/TerraCave_End/scripts.pory"

# 60 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_EventScript_DefeatedGroudon:: @ 823B155
# 61 "data/maps/TerraCave_End/scripts.pory"
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 62 "data/maps/TerraCave_End/scripts.pory"
	setflag FLAG_DEFEATED_GROUDON
# 63 "data/maps/TerraCave_End/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 64 "data/maps/TerraCave_End/scripts.pory"
	end
# 65 "data/maps/TerraCave_End/scripts.pory"

# 66 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_EventScript_RanFromGroudon:: @ 823B163
# 67 "data/maps/TerraCave_End/scripts.pory"
	setvar VAR_0x8004, SPECIES_GROUDON
# 68 "data/maps/TerraCave_End/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 69 "data/maps/TerraCave_End/scripts.pory"
	end
# 70 "data/maps/TerraCave_End/scripts.pory"

# 71 "data/maps/TerraCave_End/scripts.pory"
TerraCave_End_Movement_GroudonApproach: @ 823B16E
# 72 "data/maps/TerraCave_End/scripts.pory"
	init_affine_anim
# 73 "data/maps/TerraCave_End/scripts.pory"
	walk_down_start_affine
# 74 "data/maps/TerraCave_End/scripts.pory"
	delay_16
# 75 "data/maps/TerraCave_End/scripts.pory"
	delay_16
# 76 "data/maps/TerraCave_End/scripts.pory"
	walk_down_affine
# 77 "data/maps/TerraCave_End/scripts.pory"
	delay_16
# 78 "data/maps/TerraCave_End/scripts.pory"
	delay_16
# 79 "data/maps/TerraCave_End/scripts.pory"
	walk_down_affine
# 80 "data/maps/TerraCave_End/scripts.pory"
	step_end
