# 1 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"

# 2 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
ShoalCave_LowTideIceRoom_MapScripts::
# 3 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Common_EventScript_RemoveOverworldAfterBattle
# 4 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	.byte 0
# 5 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"

# 6 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
ShoalCave_LowTideIceRoom_EventScript_Articuno::
# 7 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	lock
# 8 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	faceplayer
# 9 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	waitse
# 10 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	playmoncry SPECIES_ARTICUNO, 2
# 11 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	delay 40
# 12 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	waitmoncry
# 13 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 14 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 15 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setwildbattle SPECIES_ARTICUNO, VAR_0x800A, ITEM_YACHE_BERRY
# 16 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 17 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 18 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	waitstate
# 19 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 20 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 21 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 22 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideIceRoom_EventScript_DefeatedArticuno
# 23 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 24 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideIceRoom_EventScript_RanFromArticuno
# 25 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 26 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideIceRoom_EventScript_RanFromArticuno
# 27 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setflag FLAG_DEFEATED_ARTICUNO
# 28 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	release
# 29 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	end
# 30 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"

# 31 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
ShoalCave_LowTideIceRoom_EventScript_DefeatedArticuno:: @ 8238F9F
# 32 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setflag FLAG_DEFEATED_ARTICUNO
# 33 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 34 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	end
# 35 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"

# 36 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
ShoalCave_LowTideIceRoom_EventScript_RanFromArticuno:: @ 8238FA8
# 37 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_ARTICUNO
# 38 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 39 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	end
