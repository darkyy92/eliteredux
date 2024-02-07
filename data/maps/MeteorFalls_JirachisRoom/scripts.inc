# 1 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"

# 2 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
MeteorFalls_JirachisRoom_MapScripts::
# 3 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Common_EventScript_RemoveOverworldAfterBattle
# 4 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	.byte 0
# 5 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"

# 6 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
MeteorFalls_JirachisRoom_EventScript_Jirachi::
# 7 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	lock
# 8 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	faceplayer
# 9 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	waitse
# 10 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	playmoncry SPECIES_JIRACHI, 2
# 11 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	delay 40
# 12 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	waitmoncry
# 13 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 14 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 15 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	setwildbattle SPECIES_JIRACHI, VAR_0x800A, ITEM_OCCA_BERRY
# 16 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 17 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 18 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	waitstate
# 19 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 20 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 21 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 22 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	goto_if_eq MeteorFalls_JirachisRoom_EventScript_DefeatedJirachi
# 23 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 24 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	goto_if_eq MeteorFalls_JirachisRoom_EventScript_RanFromJirachi
# 25 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 26 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	goto_if_eq MeteorFalls_JirachisRoom_EventScript_RanFromJirachi
# 27 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	setflag FLAG_DEFEATED_JIRACHI
# 28 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	release
# 29 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	end
# 30 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"

# 31 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
MeteorFalls_JirachisRoom_EventScript_DefeatedJirachi::
# 32 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	setflag FLAG_DEFEATED_JIRACHI
# 33 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 34 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	end
# 35 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"

# 36 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
MeteorFalls_JirachisRoom_EventScript_RanFromJirachi::
# 37 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_JIRACHI
# 38 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 39 "data/maps/MeteorFalls_JirachisRoom/scripts.pory"
	end
