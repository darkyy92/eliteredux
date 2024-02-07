# 1 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"

# 2 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
CaveOfOrigin_DianciesRoom_MapScripts::
# 3 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Common_EventScript_RemoveOverworldAfterBattle
# 4 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	.byte 0
# 5 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"

# 6 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
CaveOfOrigin_DianciesRoom_EventScript_Diancie::
# 7 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	lock
# 8 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	faceplayer
# 9 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	waitse
# 10 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	playmoncry SPECIES_DIANCIE, 2
# 11 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	delay 40
# 12 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	waitmoncry
# 13 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 14 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 15 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	setwildbattle SPECIES_DIANCIE, VAR_0x800A, ITEM_FAIRY_GEM
# 16 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 17 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 18 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	waitstate
# 19 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 20 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 21 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 22 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	goto_if_eq CaveOfOrigin_DianciesRoom_EventScript_DefeatedDiancie
# 23 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 24 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	goto_if_eq CaveOfOrigin_DianciesRoom_EventScript_RanFromDiancie
# 25 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 26 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	goto_if_eq CaveOfOrigin_DianciesRoom_EventScript_RanFromDiancie
# 27 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	setflag FLAG_DEFEATED_DIANCIE
# 28 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	release
# 29 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	end
# 30 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"

# 31 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
CaveOfOrigin_DianciesRoom_EventScript_DefeatedDiancie::
# 32 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	setflag FLAG_DEFEATED_DIANCIE
# 33 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 34 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	end
# 35 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"

# 36 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
CaveOfOrigin_DianciesRoom_EventScript_RanFromDiancie::
# 37 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_DIANCIE
# 38 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 39 "data/maps/CaveOfOrigin_DianciesRoom/scripts.pory"
	end
