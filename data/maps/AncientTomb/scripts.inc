# 1 "data/maps/AncientTomb/scripts.pory"

# 2 "data/maps/AncientTomb/scripts.pory"
AncientTomb_MapScripts:: @ 8238FB3
# 3 "data/maps/AncientTomb/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AncientTomb_OnResume
# 4 "data/maps/AncientTomb/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AncientTomb_OnLoad
# 5 "data/maps/AncientTomb/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AncientTomb_OnTransition
# 6 "data/maps/AncientTomb/scripts.pory"
	.byte 0
# 7 "data/maps/AncientTomb/scripts.pory"

# 8 "data/maps/AncientTomb/scripts.pory"
AncientTomb_OnResume: @ 8238FC3
# 9 "data/maps/AncientTomb/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AncientTomb_EventScript_TryRemoveRegisteel
# 10 "data/maps/AncientTomb/scripts.pory"
	end
# 11 "data/maps/AncientTomb/scripts.pory"

# 12 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_TryRemoveRegisteel:: @ 8238FCD
# 13 "data/maps/AncientTomb/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/AncientTomb/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 15 "data/maps/AncientTomb/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 16 "data/maps/AncientTomb/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/AncientTomb/scripts.pory"
	return
# 18 "data/maps/AncientTomb/scripts.pory"

# 19 "data/maps/AncientTomb/scripts.pory"
AncientTomb_OnTransition: @ 8238FE1
# 20 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_LANDMARK_ANCIENT_TOMB
# 21 "data/maps/AncientTomb/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGISTEEL, AncientTomb_EventScript_ShowRegisteel
# 22 "data/maps/AncientTomb/scripts.pory"
	end
# 23 "data/maps/AncientTomb/scripts.pory"

# 24 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_ShowRegisteel:: @ 8238FEE
# 25 "data/maps/AncientTomb/scripts.pory"
	clearflag FLAG_HIDE_REGISTEEL
# 26 "data/maps/AncientTomb/scripts.pory"
	return
# 27 "data/maps/AncientTomb/scripts.pory"

# 28 "data/maps/AncientTomb/scripts.pory"
AncientTomb_OnLoad: @ 8238FF2
# 29 "data/maps/AncientTomb/scripts.pory"
	call_if_unset FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED, AncientTomb_EventScript_HideRegiEntrance
# 30 "data/maps/AncientTomb/scripts.pory"
	end
# 31 "data/maps/AncientTomb/scripts.pory"

# 32 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_HideRegiEntrance:: @ 8238FFC
# 33 "data/maps/AncientTomb/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
# 34 "data/maps/AncientTomb/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
# 35 "data/maps/AncientTomb/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
# 36 "data/maps/AncientTomb/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 37 "data/maps/AncientTomb/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 38 "data/maps/AncientTomb/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 39 "data/maps/AncientTomb/scripts.pory"
	return
# 40 "data/maps/AncientTomb/scripts.pory"

# 41 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_CaveEntranceMiddle:: @ 8239033
# 42 "data/maps/AncientTomb/scripts.pory"
	lockall
# 43 "data/maps/AncientTomb/scripts.pory"
	goto_if_set FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED, AncientTomb_EventScript_BigHoleInWall
# 44 "data/maps/AncientTomb/scripts.pory"
	braillemessage AncientTomb_Braille_ShineInTheMiddle
# 45 "data/maps/AncientTomb/scripts.pory"
	waitbuttonpress
# 46 "data/maps/AncientTomb/scripts.pory"
	closebraillemessage
# 47 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 48 "data/maps/AncientTomb/scripts.pory"
	end
# 49 "data/maps/AncientTomb/scripts.pory"

# 50 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_BigHoleInWall:: @ 8239046
# 51 "data/maps/AncientTomb/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 52 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 53 "data/maps/AncientTomb/scripts.pory"
	end
# 54 "data/maps/AncientTomb/scripts.pory"

# 55 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_CaveEntranceSide:: @ 8239050
# 56 "data/maps/AncientTomb/scripts.pory"
	lockall
# 57 "data/maps/AncientTomb/scripts.pory"
	braillemessage AncientTomb_Braille_ShineInTheMiddle
# 58 "data/maps/AncientTomb/scripts.pory"
	waitbuttonpress
# 59 "data/maps/AncientTomb/scripts.pory"
	closebraillemessage
# 60 "data/maps/AncientTomb/scripts.pory"
	releaseall
# 61 "data/maps/AncientTomb/scripts.pory"
	end
# 62 "data/maps/AncientTomb/scripts.pory"

# 63 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_Registeel:: @ 823905A
# 64 "data/maps/AncientTomb/scripts.pory"
	lock
# 65 "data/maps/AncientTomb/scripts.pory"
	faceplayer
# 66 "data/maps/AncientTomb/scripts.pory"
	waitse
# 67 "data/maps/AncientTomb/scripts.pory"
	playmoncry SPECIES_REGISTEEL, 2
# 68 "data/maps/AncientTomb/scripts.pory"
	delay 40
# 69 "data/maps/AncientTomb/scripts.pory"
	waitmoncry
# 70 "data/maps/AncientTomb/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 71 "data/maps/AncientTomb/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 72 "data/maps/AncientTomb/scripts.pory"
	setwildbattle SPECIES_REGISTEEL, VAR_0x800A, ITEM_METAL_COAT
# 73 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 74 "data/maps/AncientTomb/scripts.pory"
	special StartRegiBattle
# 75 "data/maps/AncientTomb/scripts.pory"
	waitstate
# 76 "data/maps/AncientTomb/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data/maps/AncientTomb/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 78 "data/maps/AncientTomb/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 79 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq AncientTomb_EventScript_DefeatedRegisteel
# 80 "data/maps/AncientTomb/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 81 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq AncientTomb_EventScript_RanFromRegisteel
# 82 "data/maps/AncientTomb/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 83 "data/maps/AncientTomb/scripts.pory"
	goto_if_eq AncientTomb_EventScript_RanFromRegisteel
# 84 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_DEFEATED_REGISTEEL
# 85 "data/maps/AncientTomb/scripts.pory"
	release
# 86 "data/maps/AncientTomb/scripts.pory"
	end
# 87 "data/maps/AncientTomb/scripts.pory"

# 88 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_DefeatedRegisteel:: @ 82390A1
# 89 "data/maps/AncientTomb/scripts.pory"
	setflag FLAG_DEFEATED_REGISTEEL
# 90 "data/maps/AncientTomb/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 91 "data/maps/AncientTomb/scripts.pory"
	end
# 92 "data/maps/AncientTomb/scripts.pory"

# 93 "data/maps/AncientTomb/scripts.pory"
AncientTomb_EventScript_RanFromRegisteel:: @ 82390AA
# 94 "data/maps/AncientTomb/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGISTEEL
# 95 "data/maps/AncientTomb/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 96 "data/maps/AncientTomb/scripts.pory"
	end
