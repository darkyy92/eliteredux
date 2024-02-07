# 1 "data/maps/IslandCave/scripts.pory"

# 2 "data/maps/IslandCave/scripts.pory"
IslandCave_MapScripts:: @ 8238E2A
# 3 "data/maps/IslandCave/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, IslandCave_OnResume
# 4 "data/maps/IslandCave/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, IslandCave_OnLoad
# 5 "data/maps/IslandCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IslandCave_OnTransition
# 6 "data/maps/IslandCave/scripts.pory"
	.byte 0
# 7 "data/maps/IslandCave/scripts.pory"

# 8 "data/maps/IslandCave/scripts.pory"
IslandCave_OnResume: @ 8238E3A
# 9 "data/maps/IslandCave/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IslandCave_EventScript_TryRemoveRegice
# 10 "data/maps/IslandCave/scripts.pory"
	end
# 11 "data/maps/IslandCave/scripts.pory"

# 12 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_TryRemoveRegice:: @ 8238E44
# 13 "data/maps/IslandCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/IslandCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 15 "data/maps/IslandCave/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 16 "data/maps/IslandCave/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/IslandCave/scripts.pory"
	return
# 18 "data/maps/IslandCave/scripts.pory"

# 19 "data/maps/IslandCave/scripts.pory"
IslandCave_OnLoad: @ 8238E58
# 20 "data/maps/IslandCave/scripts.pory"
	call_if_unset FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_HideRegiEntrance
# 21 "data/maps/IslandCave/scripts.pory"
	end
# 22 "data/maps/IslandCave/scripts.pory"

# 23 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_HideRegiEntrance:: @ 8238E62
# 24 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
# 25 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
# 26 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
# 27 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 28 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 29 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 30 "data/maps/IslandCave/scripts.pory"
	return
# 31 "data/maps/IslandCave/scripts.pory"

# 32 "data/maps/IslandCave/scripts.pory"
IslandCave_OnTransition: @ 8238E99
# 33 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_LANDMARK_ISLAND_CAVE
# 34 "data/maps/IslandCave/scripts.pory"
	call IslandCave_EventScript_ClearSteps
# 35 "data/maps/IslandCave/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGICE, IslandCave_EventScript_ShowRegice
# 36 "data/maps/IslandCave/scripts.pory"
	end
# 37 "data/maps/IslandCave/scripts.pory"

# 38 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_ShowRegice:: @ 8238EAB
# 39 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_HIDE_REGICE
# 40 "data/maps/IslandCave/scripts.pory"
	return
# 41 "data/maps/IslandCave/scripts.pory"

# 42 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_OpenRegiEntrance:: @ 8238EAF
# 43 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, 1
# 44 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, 1
# 45 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, 1
# 46 "data/maps/IslandCave/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, 1
# 47 "data/maps/IslandCave/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, 0
# 48 "data/maps/IslandCave/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, 1
# 49 "data/maps/IslandCave/scripts.pory"
	special DrawWholeMapView
# 50 "data/maps/IslandCave/scripts.pory"
	playse SE_BANG
# 51 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_SYS_BRAILLE_REGICE_COMPLETED
# 52 "data/maps/IslandCave/scripts.pory"
	end
# 53 "data/maps/IslandCave/scripts.pory"

# 54 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CaveEntranceMiddle:: @ 8238EEF
# 55 "data/maps/IslandCave/scripts.pory"
	lockall
# 56 "data/maps/IslandCave/scripts.pory"
	call_if_set FLAG_TEMP_3, IslandCave_EventScript_ClearSteps
# 57 "data/maps/IslandCave/scripts.pory"
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_BigHoleInWall
# 58 "data/maps/IslandCave/scripts.pory"
	braillemessage IslandCave_Braille_RunLapAroundWall
# 59 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_TEMP_2
# 60 "data/maps/IslandCave/scripts.pory"
	special ShouldDoBrailleRegicePuzzle
# 61 "data/maps/IslandCave/scripts.pory"
	goto IslandCave_EventScript_CloseBrailleMsg
# 62 "data/maps/IslandCave/scripts.pory"
	end
# 63 "data/maps/IslandCave/scripts.pory"

# 64 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_BigHoleInWall:: @ 8238F13
# 65 "data/maps/IslandCave/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 66 "data/maps/IslandCave/scripts.pory"
	releaseall
# 67 "data/maps/IslandCave/scripts.pory"
	end
# 68 "data/maps/IslandCave/scripts.pory"

# 69 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CaveEntranceSide:: @ 8238F1D
# 70 "data/maps/IslandCave/scripts.pory"
	lockall
# 71 "data/maps/IslandCave/scripts.pory"
	call_if_set FLAG_TEMP_3, IslandCave_EventScript_ClearSteps
# 72 "data/maps/IslandCave/scripts.pory"
	braillemessage IslandCave_Braille_RunLapAroundWall
# 73 "data/maps/IslandCave/scripts.pory"
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_CloseBrailleMsg
# 74 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_TEMP_2
# 75 "data/maps/IslandCave/scripts.pory"
	special ShouldDoBrailleRegicePuzzle
# 76 "data/maps/IslandCave/scripts.pory"
	goto IslandCave_EventScript_CloseBrailleMsg
# 77 "data/maps/IslandCave/scripts.pory"
	end
# 78 "data/maps/IslandCave/scripts.pory"

# 79 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_CloseBrailleMsg:: @ 8238F41
# 80 "data/maps/IslandCave/scripts.pory"
	waitbuttonpress
# 81 "data/maps/IslandCave/scripts.pory"
	closebraillemessage
# 82 "data/maps/IslandCave/scripts.pory"
	releaseall
# 83 "data/maps/IslandCave/scripts.pory"
	end
# 84 "data/maps/IslandCave/scripts.pory"

# 85 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_ClearSteps:: @ 8238F45
# 86 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_1, 0
# 87 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_2, 0
# 88 "data/maps/IslandCave/scripts.pory"
	setvar VAR_REGICE_STEPS_3, 0
# 89 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_TEMP_3
# 90 "data/maps/IslandCave/scripts.pory"
	return
# 91 "data/maps/IslandCave/scripts.pory"

# 92 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_Regice:: @ 8238F58
# 93 "data/maps/IslandCave/scripts.pory"
	lock
# 94 "data/maps/IslandCave/scripts.pory"
	faceplayer
# 95 "data/maps/IslandCave/scripts.pory"
	waitse
# 96 "data/maps/IslandCave/scripts.pory"
	playmoncry SPECIES_REGICE, 2
# 97 "data/maps/IslandCave/scripts.pory"
	delay 40
# 98 "data/maps/IslandCave/scripts.pory"
	waitmoncry
# 99 "data/maps/IslandCave/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 100 "data/maps/IslandCave/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 101 "data/maps/IslandCave/scripts.pory"
	setwildbattle SPECIES_REGICE, VAR_0x800A, ITEM_NEVER_MELT_ICE
# 102 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 103 "data/maps/IslandCave/scripts.pory"
	special StartRegiBattle
# 104 "data/maps/IslandCave/scripts.pory"
	waitstate
# 105 "data/maps/IslandCave/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 106 "data/maps/IslandCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 107 "data/maps/IslandCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 108 "data/maps/IslandCave/scripts.pory"
	goto_if_eq IslandCave_EventScript_DefeatedRegice
# 109 "data/maps/IslandCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 110 "data/maps/IslandCave/scripts.pory"
	goto_if_eq IslandCave_EventScript_RanFromRegice
# 111 "data/maps/IslandCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 112 "data/maps/IslandCave/scripts.pory"
	goto_if_eq IslandCave_EventScript_RanFromRegice
# 113 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_DEFEATED_REGICE
# 114 "data/maps/IslandCave/scripts.pory"
	release
# 115 "data/maps/IslandCave/scripts.pory"
	end
# 116 "data/maps/IslandCave/scripts.pory"

# 117 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_DefeatedRegice:: @ 8238F9F
# 118 "data/maps/IslandCave/scripts.pory"
	setflag FLAG_DEFEATED_REGICE
# 119 "data/maps/IslandCave/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 120 "data/maps/IslandCave/scripts.pory"
	end
# 121 "data/maps/IslandCave/scripts.pory"

# 122 "data/maps/IslandCave/scripts.pory"
IslandCave_EventScript_RanFromRegice:: @ 8238FA8
# 123 "data/maps/IslandCave/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGICE
# 124 "data/maps/IslandCave/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 125 "data/maps/IslandCave/scripts.pory"
	end
