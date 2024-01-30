# 1 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_MapScripts:: @ 82034A7
# 5 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
# 6 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_OnTransition: @ 82034B2
# 10 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
# 11 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 12 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 13 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_Nurse:: @ 82034B6
# 14 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 15 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 16 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 17 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 18 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	release
# 19 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 20 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 21 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_Girl:: @ 82034C4
# 22 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
# 23 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 24 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 25 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_Woman:: @ 82034CD
# 26 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
# 27 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 28 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 29 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_OldMan:: @ 82034D6
# 30 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
# 31 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 32 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 33 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTM::
# 34 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	lock
# 35 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 36 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_1F_Text_HaveExplosion, MSGBOX_DEFAULT
# 37 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	release
# 38 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 39 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 40 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_HaveExplosion::
# 41 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	msgbox PacifidlogTown_PokemonCenter_1F_Text_HaveExplosion, MSGBOX_DEFAULT
# 42 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	release
# 43 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	end
# 44 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 45 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard: @ 82034DF
# 46 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "What color is your Trainer Card?\n"
# 47 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "Mine's copper!$"
# 48 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 49 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola: @ 820350F
# 50 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "Pacifidlog Town floats on top of\n"
# 51 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "a colony of Corsola.\p"
# 52 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "If I told you that, would you believe\n"
# 53 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "me?$"
# 54 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 55 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats: @ 820356F
# 56 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "The ancestors of the people in\n"
# 57 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "Pacifidlog were said to have been\l"
# 58 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "born on boats and then lived and died\l"
# 59 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "aboard them.\p"
# 60 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "I understand that they lived that way\n"
# 61 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "because they were searching for\l"
# 62 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "something.$"
# 63 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 64 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_Text_GiveExplosion: @ 82C7CFA
# 65 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "I don't intend to be going nowhere\n"
# 66 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "fast in the sticks like this forever.\p"
# 67 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "You watch me, I'll get out to the city\n"
# 68 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "and become a huge hit.\p"
# 69 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "Seriously, I'm going to cause\n"
# 70 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "a huge Explosion of popularity!\p"
# 71 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "Since you overheard that, I'll happily\n"
# 72 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "give you this TM for Explosion!$"
# 73 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"

# 74 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
PacifidlogTown_PokemonCenter_1F_Text_HaveExplosion: @ 82C7E7A
# 75 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "For a long time, I've taught Pokémon\n"
# 76 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "how to use Explosion, but I've yet\l"
# 77 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "to ignite my own Explosion…\p"
# 78 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "Maybe it's because deep down,\n"
# 79 "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.pory"
	.string "I would rather stay here…$"
