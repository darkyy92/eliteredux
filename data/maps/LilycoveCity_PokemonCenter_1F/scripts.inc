# 1 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_MapScripts:: @ 821C5B2
# 5 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_OnTransition: @ 821C5BD
# 10 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
# 11 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	goto LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx
# 12 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 13 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 14 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
@ SetLilycoveLadyGfx returns TRUE if its the Contest Lady
# 15 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx:: @ 821C5C6
# 16 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	special SetLilycoveLadyGfx
# 17 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 18 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
# 19 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 20 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
# 21 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 22 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 23 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon:: @ 821C5E0
# 24 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
# 25 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 26 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 27 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon:: @ 821C5E4
# 28 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
# 29 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 30 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 31 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Nurse:: @ 821C5E8
# 32 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 33 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 34 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 35 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 36 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	release
# 37 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 38 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 39 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Boy:: @ 821C5F6
# 40 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon, MSGBOX_NPC
# 41 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 42 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 43 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Maniac:: @ 821C5FF
# 44 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	lock
# 45 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 46 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
# 47 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
# 48 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	release
# 49 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 50 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 51 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone:: @ 821C614
# 52 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
# 53 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	release
# 54 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	end
# 55 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 56 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon: @ 821C61E
# 57 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "I wonder how many kinds of Pokémon\n"
# 58 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "there are in the world.\p"
# 59 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "It'd be great to cross seas and\n"
# 60 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "trade Pokémon with people far away.$"
# 61 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 62 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels: @ 821C69D
# 63 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "I've been hearing about some rotten\n"
# 64 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "scoundrels who steal Pokémon and rip\l"
# 65 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "off Meteorites.$"
# 66 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"

# 67 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels: @ 821C6F6
# 68 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "Those rotten scoundrels who steal\n"
# 69 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "Pokémon and rip off Meteorites…\p"
# 70 "data/maps/LilycoveCity_PokemonCenter_1F/scripts.pory"
	.string "I haven't seen them around recently.$"
