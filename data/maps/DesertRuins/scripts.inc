# 1 "data/maps/DesertRuins/scripts.pory"

# 2 "data/maps/DesertRuins/scripts.pory"
DesertRuins_MapScripts:: @ 822D95B
# 3 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, DesertRuins_OnResume
# 4 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DesertRuins_OnLoad
# 5 "data/maps/DesertRuins/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DesertRuins_OnTransition
# 6 "data/maps/DesertRuins/scripts.pory"
	.byte 0
# 7 "data/maps/DesertRuins/scripts.pory"

# 8 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnResume: @ 822D96B
# 9 "data/maps/DesertRuins/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DesertRuins_EventScript_TryRemoveRegirock
# 10 "data/maps/DesertRuins/scripts.pory"
	end
# 11 "data/maps/DesertRuins/scripts.pory"

# 12 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_TryRemoveRegirock:: @ 822D975
# 13 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 14 "data/maps/DesertRuins/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 15 "data/maps/DesertRuins/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 16 "data/maps/DesertRuins/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/DesertRuins/scripts.pory"
	return
# 18 "data/maps/DesertRuins/scripts.pory"

# 19 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnLoad: @ 822D989
# 20 "data/maps/DesertRuins/scripts.pory"
	call_if_unset FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_HideRegiEntrance
# 21 "data/maps/DesertRuins/scripts.pory"
	end
# 22 "data/maps/DesertRuins/scripts.pory"

# 23 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_HideRegiEntrance:: @ 822D993
# 24 "data/maps/DesertRuins/scripts.pory"
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
# 25 "data/maps/DesertRuins/scripts.pory"
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
# 26 "data/maps/DesertRuins/scripts.pory"
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
# 27 "data/maps/DesertRuins/scripts.pory"
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 28 "data/maps/DesertRuins/scripts.pory"
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 29 "data/maps/DesertRuins/scripts.pory"
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
# 30 "data/maps/DesertRuins/scripts.pory"
	return
# 31 "data/maps/DesertRuins/scripts.pory"

# 32 "data/maps/DesertRuins/scripts.pory"
DesertRuins_OnTransition: @ 822D9CA
# 33 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_LANDMARK_DESERT_RUINS
# 34 "data/maps/DesertRuins/scripts.pory"
	call_if_unset FLAG_DEFEATED_REGIROCK, DesertRuins_EventScript_ShowRegirock
# 35 "data/maps/DesertRuins/scripts.pory"
	end
# 36 "data/maps/DesertRuins/scripts.pory"

# 37 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_ShowRegirock:: @ 822D9D7
# 38 "data/maps/DesertRuins/scripts.pory"
	clearflag FLAG_HIDE_REGIROCK
# 39 "data/maps/DesertRuins/scripts.pory"
	return
# 40 "data/maps/DesertRuins/scripts.pory"

# 41 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_CaveEntranceMiddle:: @ 822D9DB
# 42 "data/maps/DesertRuins/scripts.pory"
	lockall
# 43 "data/maps/DesertRuins/scripts.pory"
	goto_if_set FLAG_SYS_REGIROCK_PUZZLE_COMPLETED, DesertRuins_EventScript_BigHoleInWall
# 44 "data/maps/DesertRuins/scripts.pory"
	braillemessage DesertRuins_Braille_UseRockSmash
# 45 "data/maps/DesertRuins/scripts.pory"
	waitbuttonpress
# 46 "data/maps/DesertRuins/scripts.pory"
	closebraillemessage
# 47 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 48 "data/maps/DesertRuins/scripts.pory"
	end
# 49 "data/maps/DesertRuins/scripts.pory"

# 50 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_BigHoleInWall:: @ 822D9EE
# 51 "data/maps/DesertRuins/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 52 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 53 "data/maps/DesertRuins/scripts.pory"
	end
# 54 "data/maps/DesertRuins/scripts.pory"

# 55 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_CaveEntranceSide:: @ 822D9F8
# 56 "data/maps/DesertRuins/scripts.pory"
	lockall
# 57 "data/maps/DesertRuins/scripts.pory"
	braillemessage DesertRuins_Braille_UseRockSmash
# 58 "data/maps/DesertRuins/scripts.pory"
	waitbuttonpress
# 59 "data/maps/DesertRuins/scripts.pory"
	closebraillemessage
# 60 "data/maps/DesertRuins/scripts.pory"
	releaseall
# 61 "data/maps/DesertRuins/scripts.pory"
	end
# 62 "data/maps/DesertRuins/scripts.pory"

# 63 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_Regirock:: @ 822DA02
# 64 "data/maps/DesertRuins/scripts.pory"
	lock
# 65 "data/maps/DesertRuins/scripts.pory"
	faceplayer
# 66 "data/maps/DesertRuins/scripts.pory"
	waitse
# 67 "data/maps/DesertRuins/scripts.pory"
	playmoncry SPECIES_REGIROCK, 2
# 68 "data/maps/DesertRuins/scripts.pory"
	delay 40
# 69 "data/maps/DesertRuins/scripts.pory"
	waitmoncry
# 70 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 71 "data/maps/DesertRuins/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 72 "data/maps/DesertRuins/scripts.pory"
	setwildbattle SPECIES_REGIROCK, VAR_0x800A, ITEM_HARD_STONE
# 73 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 74 "data/maps/DesertRuins/scripts.pory"
	special StartRegiBattle
# 75 "data/maps/DesertRuins/scripts.pory"
	waitstate
# 76 "data/maps/DesertRuins/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 77 "data/maps/DesertRuins/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 78 "data/maps/DesertRuins/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 79 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq DesertRuins_EventScript_DefeatedRegirock
# 80 "data/maps/DesertRuins/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 81 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq DesertRuins_EventScript_RanFromRegirock
# 82 "data/maps/DesertRuins/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 83 "data/maps/DesertRuins/scripts.pory"
	goto_if_eq DesertRuins_EventScript_RanFromRegirock
# 84 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_REGIROCK
# 85 "data/maps/DesertRuins/scripts.pory"
	release
# 86 "data/maps/DesertRuins/scripts.pory"
	end
# 87 "data/maps/DesertRuins/scripts.pory"

# 88 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_DefeatedRegirock:: @ 822DA49
# 89 "data/maps/DesertRuins/scripts.pory"
	setflag FLAG_DEFEATED_REGIROCK
# 90 "data/maps/DesertRuins/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 91 "data/maps/DesertRuins/scripts.pory"
	end
# 92 "data/maps/DesertRuins/scripts.pory"

# 93 "data/maps/DesertRuins/scripts.pory"
DesertRuins_EventScript_RanFromRegirock:: @ 822DA52
# 94 "data/maps/DesertRuins/scripts.pory"
	setvar VAR_0x8004, SPECIES_REGIROCK
# 95 "data/maps/DesertRuins/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 96 "data/maps/DesertRuins/scripts.pory"
	end
