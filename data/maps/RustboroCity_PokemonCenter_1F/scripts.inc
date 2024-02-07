# 1 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_MapScripts:: @ 8214D62
# 5 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_OnTransition: @ 8214D6D
# 10 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
# 11 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 12 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 13 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 14 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Nurse:: @ 8214D76
# 15 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 16 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 17 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 18 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 19 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
# 20 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Clerk2::
# 23 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	lock
# 24 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 25 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	message gText_HowMayIServeYou
# 26 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 27 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	pokemart PokeMart_PokeCenterRustboro
# 28 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 29 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
# 30 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 31 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 32 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.align 2
# 33 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
PokeMart_PokeCenterRustboro::
# 34 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 35 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 36 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 37 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NONE
# 38 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	release
# 39 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 40 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 41 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Man:: @ 8214D84
# 42 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
# 43 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 44 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 45 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Boy:: @ 8214D8D
# 46 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
# 47 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 48 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 49 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_EventScript_Girl:: @ 8214D96
# 50 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
# 51 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	end
# 52 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 53 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities: @ 8214D9F
# 54 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "My Pokémon has a Naive nature, and my\n"
# 55 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "friend's has a Jolly nature.\p"
# 56 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "It's fascinating how Pokémon have\n"
# 57 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "personalities!$"
# 58 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 59 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon: @ 8214E13
# 60 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "Just like people, there are male and\n"
# 61 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "female Pokémon.\p"
# 62 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "But no one seems to have any idea how\n"
# 63 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "they're different.$"
# 64 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"

# 65 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor: @ 8214E81
# 66 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "The man next door gave me an HM!\p"
# 67 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "I used it to teach my Pokémon how to\n"
# 68 "data/maps/RustboroCity_PokemonCenter_1F/scripts.pory"
	.string "Cut down skinny trees.$"
