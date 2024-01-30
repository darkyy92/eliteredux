# 1 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"

# 2 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
.set LOCALID_HEATRAN, 1
# 3 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"

# 4 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
ScorchedSlab_HeatransRoom_MapScripts::
# 5 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Common_EventScript_RemoveOverworldAfterBattle
# 6 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	.byte 0
# 7 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"

# 8 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
ScorchedSlab_HeatransRoom_EventScript_Heatran::
# 9 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	lock
# 10 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	faceplayer
# 11 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	waitse
# 12 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	playmoncry SPECIES_HEATRAN, 2
# 13 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	delay 40
# 14 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	waitmoncry
# 15 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 16 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 17 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	setwildbattle SPECIES_HEATRAN, VAR_0x800A, ITEM_OCCA_BERRY
# 18 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 19 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 20 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	waitstate
# 21 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 22 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 23 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 24 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	goto_if_eq ScorchedSlab_HeatransRoom_EventScript_DefeatedHeatran
# 25 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 26 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	goto_if_eq ScorchedSlab_HeatransRoom_EventScript_RanFromHeatran
# 27 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 28 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	goto_if_eq ScorchedSlab_HeatransRoom_EventScript_RanFromHeatran
# 29 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	setflag FLAG_DEFEATED_HEATRAN
# 30 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	release
# 31 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	end
# 32 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"

# 33 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
ScorchedSlab_HeatransRoom_EventScript_DefeatedHeatran::
# 34 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	setflag FLAG_DEFEATED_HEATRAN
# 35 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 36 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	end
# 37 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"

# 38 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
ScorchedSlab_HeatransRoom_EventScript_RanFromHeatran::
# 39 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_HEATRAN
# 40 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 41 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	end
# 42 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"

# 43 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
ScorchedSlab_HeatransRoom_EventScript_MagmaStone::
# 44 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	lock
# 45 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	checkitem ITEM_MAGMA_STONE, 1
# 46 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 47 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	goto_if_eq ScorchedSlab_HeatransRoom_EventScript_PlaceMagmaStone
# 48 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	release
# 49 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	end
# 50 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"

# 51 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
ScorchedSlab_HeatransRoom_EventScript_PlaceMagmaStone::
# 52 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	msgbox ScorchedSlab_HeatransRoom_Text_PlaceMagmaStone, MSGBOX_YESNO
# 53 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	compare VAR_RESULT, NO
# 54 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	goto_if_eq ScorchedSlab_HeatransRoom_EventScript_MagmaStoneEnd
# 55 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 56 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	closemessage
# 57 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	waitse
# 58 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	playmoncry SPECIES_HEATRAN, 2
# 59 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	delay 40
# 60 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	waitmoncry
# 61 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	addobject LOCALID_HEATRAN
# 62 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	clearflag FLAG_DEFEATED_HEATRAN
# 63 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 64 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	removeitem ITEM_MAGMA_STONE
# 65 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
ScorchedSlab_HeatransRoom_EventScript_MagmaStoneEnd::
# 66 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	releaseall
# 67 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	end
# 68 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"

# 69 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
ScorchedSlab_HeatransRoom_Text_PlaceMagmaStone:
# 70 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	.string "The Magma Stone is reacting\n"
# 71 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	.string "to something…\p"
# 72 "data/maps/ScorchedSlab_HeatransRoom/scripts.pory"
	.string "Will you set it down here?$"
