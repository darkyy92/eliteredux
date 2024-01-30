# 1 "data/maps/NavelRock_Bottom/scripts.pory"

# 2 "data/maps/NavelRock_Bottom/scripts.pory"
.set LOCALID_LUGIA, 1
# 3 "data/maps/NavelRock_Bottom/scripts.pory"

# 4 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_MapScripts:: @ 8269255
# 5 "data/maps/NavelRock_Bottom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_OnTransition
# 6 "data/maps/NavelRock_Bottom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_OnResume
# 7 "data/maps/NavelRock_Bottom/scripts.pory"
	.byte 0
# 8 "data/maps/NavelRock_Bottom/scripts.pory"

# 9 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_OnTransition: @ 8269260
# 10 "data/maps/NavelRock_Bottom/scripts.pory"
	call_if_set FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_HideLugia
# 11 "data/maps/NavelRock_Bottom/scripts.pory"
	call_if_unset FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_TryShowLugia
# 12 "data/maps/NavelRock_Bottom/scripts.pory"
	end
# 13 "data/maps/NavelRock_Bottom/scripts.pory"

# 14 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_HideLugia:: @ 8269273
# 15 "data/maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_HIDE_LUGIA
# 16 "data/maps/NavelRock_Bottom/scripts.pory"
	return
# 17 "data/maps/NavelRock_Bottom/scripts.pory"

# 18 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_TryShowLugia:: @ 8269277
# 19 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
# 20 "data/maps/NavelRock_Bottom/scripts.pory"
	clearflag FLAG_HIDE_LUGIA
# 21 "data/maps/NavelRock_Bottom/scripts.pory"
	return
# 22 "data/maps/NavelRock_Bottom/scripts.pory"

# 23 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_OnResume: @ 8269284
# 24 "data/maps/NavelRock_Bottom/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Bottom_EventScript_TryRemoveLugia
# 25 "data/maps/NavelRock_Bottom/scripts.pory"
	end
# 26 "data/maps/NavelRock_Bottom/scripts.pory"

# 27 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_TryRemoveLugia:: @ 826928E
# 28 "data/maps/NavelRock_Bottom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/maps/NavelRock_Bottom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 30 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 31 "data/maps/NavelRock_Bottom/scripts.pory"
	removeobject LOCALID_LUGIA
# 32 "data/maps/NavelRock_Bottom/scripts.pory"
	return
# 33 "data/maps/NavelRock_Bottom/scripts.pory"

# 34 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_Lugia:: @ 82692A2
# 35 "data/maps/NavelRock_Bottom/scripts.pory"
	lock
# 36 "data/maps/NavelRock_Bottom/scripts.pory"
	faceplayer
# 37 "data/maps/NavelRock_Bottom/scripts.pory"
	waitse
# 38 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 20
# 39 "data/maps/NavelRock_Bottom/scripts.pory"
	playse SE_THUNDERSTORM_STOP
# 40 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, 0  @ vertical pan
# 41 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8005, 3  @ horizontal pan
# 42 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8006, 4  @ num shakes
# 43 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8007, 2  @ shake delay
# 44 "data/maps/NavelRock_Bottom/scripts.pory"
	special ShakeCamera
# 45 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 30
# 46 "data/maps/NavelRock_Bottom/scripts.pory"
	playse SE_THUNDERSTORM_STOP
# 47 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, 0  @ vertical pan
# 48 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8005, 3  @ horizontal pan
# 49 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8006, 4  @ num shakes
# 50 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8007, 2  @ shake delay
# 51 "data/maps/NavelRock_Bottom/scripts.pory"
	special ShakeCamera
# 52 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 30
# 53 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 50
# 54 "data/maps/NavelRock_Bottom/scripts.pory"
	waitse
# 55 "data/maps/NavelRock_Bottom/scripts.pory"
	playmoncry SPECIES_LUGIA, 2
# 56 "data/maps/NavelRock_Bottom/scripts.pory"
	waitmoncry
# 57 "data/maps/NavelRock_Bottom/scripts.pory"
	delay 20
# 58 "data/maps/NavelRock_Bottom/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 59 "data/maps/NavelRock_Bottom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT @ level
# 60 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 61 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8006, ITEM_NONE
# 62 "data/maps/NavelRock_Bottom/scripts.pory"
	special CreateEventLegalEnemyMon
# 63 "data/maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 64 "data/maps/NavelRock_Bottom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 65 "data/maps/NavelRock_Bottom/scripts.pory"
	waitstate
# 66 "data/maps/NavelRock_Bottom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 67 "data/maps/NavelRock_Bottom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 68 "data/maps/NavelRock_Bottom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 69 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq NavelRock_Bottom_EventScript_DefeatedLugia
# 70 "data/maps/NavelRock_Bottom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 71 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq NavelRock_Bottom_EventScript_RanFromLugia
# 72 "data/maps/NavelRock_Bottom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 73 "data/maps/NavelRock_Bottom/scripts.pory"
	goto_if_eq NavelRock_Bottom_EventScript_RanFromLugia
# 74 "data/maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_CAUGHT_LUGIA
# 75 "data/maps/NavelRock_Bottom/scripts.pory"
	release
# 76 "data/maps/NavelRock_Bottom/scripts.pory"
	end
# 77 "data/maps/NavelRock_Bottom/scripts.pory"

# 78 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_DefeatedLugia:: @ 8269336
# 79 "data/maps/NavelRock_Bottom/scripts.pory"
	setflag FLAG_DEFEATED_LUGIA
# 80 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 81 "data/maps/NavelRock_Bottom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 82 "data/maps/NavelRock_Bottom/scripts.pory"
	end
# 83 "data/maps/NavelRock_Bottom/scripts.pory"

# 84 "data/maps/NavelRock_Bottom/scripts.pory"
NavelRock_Bottom_EventScript_RanFromLugia:: @ 8269344
# 85 "data/maps/NavelRock_Bottom/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA
# 86 "data/maps/NavelRock_Bottom/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 87 "data/maps/NavelRock_Bottom/scripts.pory"
	end
