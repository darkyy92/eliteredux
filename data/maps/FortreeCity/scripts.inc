# 1 "data/maps/FortreeCity/scripts.pory"

# 2 "data/maps/FortreeCity/scripts.pory"
FortreeCity_MapScripts:: @ 81E25A4
# 3 "data/maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
# 4 "data/maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
# 5 "data/maps/FortreeCity/scripts.pory"
	.byte 0
# 6 "data/maps/FortreeCity/scripts.pory"

# 7 "data/maps/FortreeCity/scripts.pory"
FortreeCity_OnTransition: @ 81E25AF
# 8 "data/maps/FortreeCity/scripts.pory"
	setflag FLAG_VISITED_FORTREE_CITY
# 9 "data/maps/FortreeCity/scripts.pory"
	end
# 10 "data/maps/FortreeCity/scripts.pory"

# 11 "data/maps/FortreeCity/scripts.pory"
FortreeCity_OnResume: @ 81E25B3
# 12 "data/maps/FortreeCity/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 13 "data/maps/FortreeCity/scripts.pory"
	end
# 14 "data/maps/FortreeCity/scripts.pory"

# 15 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Man:: @ 81E25B6
# 16 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
# 17 "data/maps/FortreeCity/scripts.pory"
	end
# 18 "data/maps/FortreeCity/scripts.pory"

# 19 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Woman:: @ 81E25BF
# 20 "data/maps/FortreeCity/scripts.pory"
	lock
# 21 "data/maps/FortreeCity/scripts.pory"
	faceplayer
# 22 "data/maps/FortreeCity/scripts.pory"
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
# 23 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
# 24 "data/maps/FortreeCity/scripts.pory"
	release
# 25 "data/maps/FortreeCity/scripts.pory"
	end
# 26 "data/maps/FortreeCity/scripts.pory"

# 27 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_WomanGymAccessible:: @ 81E25D4
# 28 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
# 29 "data/maps/FortreeCity/scripts.pory"
	release
# 30 "data/maps/FortreeCity/scripts.pory"
	end
# 31 "data/maps/FortreeCity/scripts.pory"

# 32 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Girl:: @ 81E25DE
# 33 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
# 34 "data/maps/FortreeCity/scripts.pory"
	end
# 35 "data/maps/FortreeCity/scripts.pory"

# 36 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_OldMan:: @ 81E25E7
# 37 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
# 38 "data/maps/FortreeCity/scripts.pory"
	end
# 39 "data/maps/FortreeCity/scripts.pory"

# 40 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Boy:: @ 81E25F0
# 41 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
# 42 "data/maps/FortreeCity/scripts.pory"
	end
# 43 "data/maps/FortreeCity/scripts.pory"

# 44 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_GameboyKid:: @ 81E25F9
# 45 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
# 46 "data/maps/FortreeCity/scripts.pory"
	end
# 47 "data/maps/FortreeCity/scripts.pory"

# 48 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_CitySign:: @ 81E2602
# 49 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
# 50 "data/maps/FortreeCity/scripts.pory"
	end
# 51 "data/maps/FortreeCity/scripts.pory"

# 52 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_GymSign:: @ 81E260B
# 53 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
# 54 "data/maps/FortreeCity/scripts.pory"
	end
# 55 "data/maps/FortreeCity/scripts.pory"

# 56 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Kecleon:: @ 81E2614
# 57 "data/maps/FortreeCity/scripts.pory"
	lock
# 58 "data/maps/FortreeCity/scripts.pory"
	faceplayer
# 59 "data/maps/FortreeCity/scripts.pory"
	checkitem ITEM_DEVON_SCOPE, 1
# 60 "data/maps/FortreeCity/scripts.pory"
	compare VAR_RESULT, TRUE
# 61 "data/maps/FortreeCity/scripts.pory"
	goto_if_eq FortreeCity_EventScript_AskUseDevonScope
# 62 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
# 63 "data/maps/FortreeCity/scripts.pory"
	release
# 64 "data/maps/FortreeCity/scripts.pory"
	end
# 65 "data/maps/FortreeCity/scripts.pory"

# 66 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_AskUseDevonScope:: @ 81E2630
# 67 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
# 68 "data/maps/FortreeCity/scripts.pory"
	compare VAR_RESULT, YES
# 69 "data/maps/FortreeCity/scripts.pory"
	goto_if_eq FortreeCity_EventScript_UseDevonScope
# 70 "data/maps/FortreeCity/scripts.pory"
	release
# 71 "data/maps/FortreeCity/scripts.pory"
	end
# 72 "data/maps/FortreeCity/scripts.pory"

# 73 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_UseDevonScope:: @ 81E2645
# 74 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
# 75 "data/maps/FortreeCity/scripts.pory"
	closemessage
# 76 "data/maps/FortreeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
# 77 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 78 "data/maps/FortreeCity/scripts.pory"
	waitse
# 79 "data/maps/FortreeCity/scripts.pory"
	playmoncry SPECIES_KECLEON, 2
# 80 "data/maps/FortreeCity/scripts.pory"
	delay 40
# 81 "data/maps/FortreeCity/scripts.pory"
	waitmoncry
# 82 "data/maps/FortreeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
# 83 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 84 "data/maps/FortreeCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 85 "data/maps/FortreeCity/scripts.pory"
	setflag FLAG_KECLEON_FLED_FORTREE
# 86 "data/maps/FortreeCity/scripts.pory"
	release
# 87 "data/maps/FortreeCity/scripts.pory"
	end
# 88 "data/maps/FortreeCity/scripts.pory"

# 89 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Movement_KecleonFlee: @ 81E2674
# 90 "data/maps/FortreeCity/scripts.pory"
	walk_right
# 91 "data/maps/FortreeCity/scripts.pory"
	step_end
# 92 "data/maps/FortreeCity/scripts.pory"

# 93 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SawGiganticPokemonInSky: @ 81E2676
# 94 "data/maps/FortreeCity/scripts.pory"
	.string "No one believes me, but I saw this\n"
# 95 "data/maps/FortreeCity/scripts.pory"
	.string "gigantic Pokémon in the sky.\p"
# 96 "data/maps/FortreeCity/scripts.pory"
	.string "It seemed to squirm as it flew toward\n"
# 97 "data/maps/FortreeCity/scripts.pory"
	.string "Route 131.\p"
# 98 "data/maps/FortreeCity/scripts.pory"
	.string "By the way… Sniff…\n"
# 99 "data/maps/FortreeCity/scripts.pory"
	.string "Um… You, uh…smell singed.\p"
# 100 "data/maps/FortreeCity/scripts.pory"
	.string "Were you at a volcano or something?$"
# 101 "data/maps/FortreeCity/scripts.pory"

# 102 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SomethingBlockingGym: @ 81E2738
# 103 "data/maps/FortreeCity/scripts.pory"
	.string "I want to go to the Pokémon Gym,\n"
# 104 "data/maps/FortreeCity/scripts.pory"
	.string "but something's blocking the way.\p"
# 105 "data/maps/FortreeCity/scripts.pory"
	.string "After all the bother I went through\n"
# 106 "data/maps/FortreeCity/scripts.pory"
	.string "training on Route 120…$"
# 107 "data/maps/FortreeCity/scripts.pory"

# 108 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_ThisTimeIllBeatWinona: @ 81E27B6
# 109 "data/maps/FortreeCity/scripts.pory"
	.string "I've got my pride-and-joy Pokémon\n"
# 110 "data/maps/FortreeCity/scripts.pory"
	.string "with me. This time, I'll beat Winona.$"
# 111 "data/maps/FortreeCity/scripts.pory"

# 112 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_TreesGrowByDrinkingRainwater: @ 81E27FE
# 113 "data/maps/FortreeCity/scripts.pory"
	.string "The ground absorbs rainwater, and\n"
# 114 "data/maps/FortreeCity/scripts.pory"
	.string "trees grow by drinking that water…\p"
# 115 "data/maps/FortreeCity/scripts.pory"
	.string "Our Fortree City exists because\n"
# 116 "data/maps/FortreeCity/scripts.pory"
	.string "there's both water and soil.$"
# 117 "data/maps/FortreeCity/scripts.pory"

# 118 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_EveryoneHealthyAndLively: @ 81E2880
# 119 "data/maps/FortreeCity/scripts.pory"
	.string "The City consists of homes built on\n"
# 120 "data/maps/FortreeCity/scripts.pory"
	.string "trees.\p"
# 121 "data/maps/FortreeCity/scripts.pory"
	.string "Perhaps because of that lifestyle,\n"
# 122 "data/maps/FortreeCity/scripts.pory"
	.string "everyone is healthy and lively.\p"
# 123 "data/maps/FortreeCity/scripts.pory"
	.string "Why, even myself--I feel as if I've\n"
# 124 "data/maps/FortreeCity/scripts.pory"
	.string "grown thirty years younger.$"
# 125 "data/maps/FortreeCity/scripts.pory"

# 126 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_BugPokemonComeThroughWindow: @ 81E292E
# 127 "data/maps/FortreeCity/scripts.pory"
	.string "Living on top of trees is okay.\p"
# 128 "data/maps/FortreeCity/scripts.pory"
	.string "But sometimes BUG Pokémon come in\n"
# 129 "data/maps/FortreeCity/scripts.pory"
	.string "through windows.\l"
# 130 "data/maps/FortreeCity/scripts.pory"
	.string "It can be really startling.$"
# 131 "data/maps/FortreeCity/scripts.pory"

# 132 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_PokemonThatEvolveWhenTraded: @ 81E299D
# 133 "data/maps/FortreeCity/scripts.pory"
	.string "There are Pokémon that evolve when\n"
# 134 "data/maps/FortreeCity/scripts.pory"
	.string "you trade them! That's what I heard.$"
# 135 "data/maps/FortreeCity/scripts.pory"

# 136 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SomethingUnseeable: @ 81E29E5
# 137 "data/maps/FortreeCity/scripts.pory"
	.string "Something unseeable is in the way.$"
# 138 "data/maps/FortreeCity/scripts.pory"

# 139 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_UnseeableUseDevonScope: @ 81E2A08
# 140 "data/maps/FortreeCity/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 141 "data/maps/FortreeCity/scripts.pory"
	.string "Want to use the Devon Scope?$"
# 142 "data/maps/FortreeCity/scripts.pory"

# 143 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_UsedDevonScopePokemonFled: @ 81E2A48
# 144 "data/maps/FortreeCity/scripts.pory"
	.string "{PLAYER} used the Devon Scope.\p"
# 145 "data/maps/FortreeCity/scripts.pory"
	.string "An invisible Pokémon became completely\n"
# 146 "data/maps/FortreeCity/scripts.pory"
	.string "visible!\p"
# 147 "data/maps/FortreeCity/scripts.pory"
	.string "The startled Pokémon fled!$"
# 148 "data/maps/FortreeCity/scripts.pory"

# 149 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_CitySign: @ 81E2AAC
# 150 "data/maps/FortreeCity/scripts.pory"
	.string "Fortree City\n"
# 151 "data/maps/FortreeCity/scripts.pory"
	.string "“The treetop city that frolics with\l"
# 152 "data/maps/FortreeCity/scripts.pory"
	.string "nature.”$"
# 153 "data/maps/FortreeCity/scripts.pory"

# 154 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_GymSign: @ 81E2AE6
# 155 "data/maps/FortreeCity/scripts.pory"
	.string "Fortree City Pokémon Gym\n"
# 156 "data/maps/FortreeCity/scripts.pory"
	.string "Leader: Winona\p"
# 157 "data/maps/FortreeCity/scripts.pory"
	.string "“The bird user taking flight into\n"
# 158 "data/maps/FortreeCity/scripts.pory"
	.string "the world.”$"
