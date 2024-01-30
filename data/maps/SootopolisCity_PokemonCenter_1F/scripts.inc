# 1 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_MapScripts:: @ 82264F1
# 5 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
# 6 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_OnTransition: @ 82264FC
# 10 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
# 11 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 12 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 13 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_Nurse:: @ 8226500
# 14 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 15 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 16 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 17 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 18 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 19 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 20 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 21 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_Gentleman:: @ 822650E
# 22 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	lock
# 23 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 24 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 2
# 25 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	goto_if_ge SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
# 26 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
# 27 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
# 28 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 29 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 30 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 31 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries:: @ 822652E
# 32 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
# 33 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 34 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 35 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 36 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_Woman:: @ 8226538
# 37 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	lock
# 38 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 39 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 2
# 40 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	goto_if_ge SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
# 41 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
# 42 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
# 43 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 44 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 45 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 46 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries:: @ 8226558
# 47 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
# 48 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 49 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 50 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 51 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_EventScript_Clerk2::
# 52 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	lock
# 53 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	faceplayer
# 54 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	message gText_HowMayIServeYou
# 55 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	waitmessage
# 56 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	pokemart PokeMart_PokeCenterSootopolisCity
# 57 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 58 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 59 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 60 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 61 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.align 2
# 62 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
PokeMart_PokeCenterSootopolisCity::
# 63 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 64 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NET_BALL
# 65 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 66 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NONE
# 67 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	release
# 68 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	end
# 69 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 70 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn: @ 8226562
# 71 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Wallace is rumored to be the toughest\n"
# 72 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Trainer in the whole Hoenn region.\p"
# 73 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "This town's Gym is led by the Trainer\n"
# 74 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "who taught Wallace.\p"
# 75 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "But the Elite Four… They're said to be\n"
# 76 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "even stronger than Wallace's mentor.\p"
# 77 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "How strong could they be?$"
# 78 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 79 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge: @ 822664B
# 80 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Everyone in town has taken refuge\n"
# 81 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "and won't come out of their homes.\p"
# 82 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Even I would rather not venture\n"
# 83 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "outside.$"
# 84 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 85 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon: @ 82266B9
# 86 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Whenever, wherever, and whatever\n"
# 87 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "happens, I will always be friends with\l"
# 88 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Pokémon.\p"
# 89 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Because it's fun to be with Pokémon!$"
# 90 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"

# 91 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends: @ 822672F
# 92 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Aren't Pokémon our friends?\p"
# 93 "data/maps/SootopolisCity_PokemonCenter_1F/scripts.pory"
	.string "Why are they going wild this way?$"
