# 1 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_SCOTT, 6
# 4 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 5 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_MapScripts:: @ 8229A34
# 6 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
# 7 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 8 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 9 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 10 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_OnTransition: @ 8229A3F
# 11 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
# 12 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
# 13 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 14 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 15 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott:: @ 8229A4C
# 16 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
# 17 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
# 18 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	return
# 19 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 20 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_Nurse:: @ 8229A59
# 21 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 22 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 23 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 24 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 25 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	release
# 26 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 27 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 28 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_Woman:: @ 8229A67
# 29 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
# 30 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 31 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 32 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM:: @ 8229A70
# 33 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
# 34 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 35 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 36 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_Scott:: @ 8229A79
# 37 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	lock
# 38 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 39 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
# 40 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	closemessage
# 41 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 42 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
# 43 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 44 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
# 45 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 46 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	call_if_eq EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
# 47 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 48 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
# 49 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	playse SE_EXIT
# 50 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitse
# 51 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	removeobject LOCALID_SCOTT
# 52 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	release
# 53 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	end
# 54 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 55 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth:: @ 8229AB6
# 56 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
# 57 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 58 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	return
# 59 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 60 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit:: @ 8229AC1
# 61 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
# 62 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 63 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	return
# 64 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 65 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth: @ 8229ACC
# 66 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_left
# 67 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 68 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 69 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_left
# 70 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 71 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 72 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	step_end
# 73 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 74 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Movement_ScottExit: @ 8229AD3
# 75 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 76 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 77 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_left
# 78 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_left
# 79 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 80 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	walk_down
# 81 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	step_end
# 82 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 83 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad: @ 8229ADA
# 84 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "The Pokémon League is only a short\n"
# 85 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "distance after the Victory Road.\p"
# 86 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "If you've come this far, what choice\n"
# 87 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "do you have but to keep going?$"
# 88 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 89 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon: @ 8229B62
# 90 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "The long and harrowing Victory Road…\p"
# 91 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "It's like reliving the path one has\n"
# 92 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "traveled in life…\p"
# 93 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "Believe in your Pokémon and give it\n"
# 94 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "your very best!$"
# 95 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"

# 96 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou: @ 8229BF1
# 97 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "Scott: {PLAYER}{KUN}, you've clawed your\n"
# 98 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "way up to face the Pokémon League!\p"
# 99 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "I'm happy for you!\n"
# 100 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "You made my cheering worthwhile!\p"
# 101 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER}{KUN}, if you were to become\n"
# 102 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "the Pokémon League Champion…\p"
# 103 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "I'll get in touch with you then.\p"
# 104 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "Okay, {PLAYER}{KUN}.\n"
# 105 "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.pory"
	.string "Go for greatness!$"
