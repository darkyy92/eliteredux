# 1 "data/maps/EmberPath/scripts.pory"

# 2 "data/maps/EmberPath/scripts.pory"
EmberPath_MapScripts::
# 3 "data/maps/EmberPath/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Common_EventScript_RemoveOverworldAfterBattle
# 4 "data/maps/EmberPath/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EmberPath_OnTransition
# 5 "data/maps/EmberPath/scripts.pory"
	.byte 0
# 6 "data/maps/EmberPath/scripts.pory"

# 7 "data/maps/EmberPath/scripts.pory"
EmberPath_OnTransition:
# 8 "data/maps/EmberPath/scripts.pory"
	setflag FLAG_LANDMARK_EMBER_PATH
# 9 "data/maps/EmberPath/scripts.pory"
	end
# 10 "data/maps/EmberPath/scripts.pory"

# 11 "data/maps/EmberPath/scripts.pory"
EmberPath_EventScript_Moltres::
# 12 "data/maps/EmberPath/scripts.pory"
	lock
# 13 "data/maps/EmberPath/scripts.pory"
	faceplayer
# 14 "data/maps/EmberPath/scripts.pory"
	waitse
# 15 "data/maps/EmberPath/scripts.pory"
	playmoncry SPECIES_MOLTRES, 2
# 16 "data/maps/EmberPath/scripts.pory"
	delay 40
# 17 "data/maps/EmberPath/scripts.pory"
	waitmoncry
# 18 "data/maps/EmberPath/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 19 "data/maps/EmberPath/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 20 "data/maps/EmberPath/scripts.pory"
	setwildbattle SPECIES_MOLTRES, VAR_0x800A, ITEM_OCCA_BERRY
# 21 "data/maps/EmberPath/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 22 "data/maps/EmberPath/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 23 "data/maps/EmberPath/scripts.pory"
	waitstate
# 24 "data/maps/EmberPath/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 25 "data/maps/EmberPath/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 26 "data/maps/EmberPath/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 27 "data/maps/EmberPath/scripts.pory"
	goto_if_eq EmberPath_EventScript_DefeatedMoltres
# 28 "data/maps/EmberPath/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 29 "data/maps/EmberPath/scripts.pory"
	goto_if_eq EmberPath_EventScript_RanFromMoltres
# 30 "data/maps/EmberPath/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 31 "data/maps/EmberPath/scripts.pory"
	goto_if_eq EmberPath_EventScript_RanFromMoltres
# 32 "data/maps/EmberPath/scripts.pory"
	setflag FLAG_DEFEATED_MOLTRES
# 33 "data/maps/EmberPath/scripts.pory"
	release
# 34 "data/maps/EmberPath/scripts.pory"
	end
# 35 "data/maps/EmberPath/scripts.pory"

# 36 "data/maps/EmberPath/scripts.pory"
EmberPath_EventScript_DefeatedMoltres:: @ 8238F9F
# 37 "data/maps/EmberPath/scripts.pory"
	setflag FLAG_DEFEATED_MOLTRES
# 38 "data/maps/EmberPath/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 39 "data/maps/EmberPath/scripts.pory"
	end
# 40 "data/maps/EmberPath/scripts.pory"

# 41 "data/maps/EmberPath/scripts.pory"
EmberPath_EventScript_RanFromMoltres:: @ 8238FA8
# 42 "data/maps/EmberPath/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLTRES
# 43 "data/maps/EmberPath/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 44 "data/maps/EmberPath/scripts.pory"
	end
