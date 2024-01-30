# 1 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_LANETTE, 6
# 4 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 5 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_MapScripts:: @ 8200BCD
# 6 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
# 7 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 8 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 9 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 10 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_OnTransition: @ 8200BD8
# 11 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
# 12 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 13 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 14 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 15 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_Nurse:: @ 8200BE1
# 16 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 17 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 18 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 19 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 20 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	release
# 21 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 22 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 23 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_Girl:: @ 8200BEF
# 24 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
# 25 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 26 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 27 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_ExpertM:: @ 8200BF8
# 28 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
# 29 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 30 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 31 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_Lanette:: @ 8200C01
# 32 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	lock
# 33 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 34 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	msgbox FallarborTown_PokemonCenter_1F_Text_LanetteGreeting, MSGBOX_DEFAULT
# 35 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	closemessage
# 36 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	switch VAR_FACING
# 37 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth
# 38 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest
# 39 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	case DIR_EAST, FallarborTown_PokemonCenter_1F_EventScript_LanetteExitEast
# 40 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 41 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 42 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_LanetteExitNorth:: @ 8200C28
# 43 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
# 44 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 45 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
# 46 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 47 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 48 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_LanetteExitWest:: @ 8200C38
# 49 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	applymovement LOCALID_LANETTE, FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth
# 50 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 51 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
# 52 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 53 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 54 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_LanetteExitEast::
# 55 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	applymovement 6, FallarborTown_PokemonCenter_1F_Movement_LanetteExitEast
# 56 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	goto FallarborTown_PokemonCenter_1F_EventScript_LanetteExited
# 58 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 59 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 60 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_LanetteExited:: @ 8200C48
# 61 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	playse SE_SLIDING_DOOR
# 62 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	removeobject LOCALID_LANETTE
# 63 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
# 64 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	release
# 65 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 66 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 67 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_EventScript_Clerk2::
# 68 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	lock
# 69 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 70 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	message gText_HowMayIServeYou
# 71 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 72 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	pokemart PokeMart_PokeCenterFallarborTown
# 73 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 74 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	release
# 75 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 76 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 77 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.align 2
# 78 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
PokeMart_PokeCenterFallarborTown::
# 79 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 80 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 81 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 82 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NONE
# 83 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	release
# 84 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	end
# 85 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 86 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Movement_LanetteExitNorth:
# 87 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 88 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 89 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 90 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 91 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 92 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 93 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 94 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	delay_8
# 95 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	step_end
# 96 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 97 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Movement_LanetteExitEast:
# 98 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 99 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 100 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 101 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_left
# 102 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 103 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 104 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	walk_down
# 105 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	delay_8
# 106 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	step_end
# 107 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 108 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Text_LanetteGreeting: @ 8200C6B
# 109 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Oh, hello.\n"
# 110 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "You are?\p"
# 111 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Okay, your name's {PLAYER}{KUN}.\n"
# 112 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "I can see that you're a Trainer.\p"
# 113 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "So that means you use the Pokémon\n"
# 114 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Storage System I developed.\p"
# 115 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "How I arrived at that conclusion is\n"
# 116 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "a simple deductive process.\p"
# 117 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "You spoke to me because you wanted\n"
# 118 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "to access something on this PC.\p"
# 119 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Oh, I'm sorry. I'm Lanette.\p"
# 120 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Honestly, I'm glad to meet you--it's\n"
# 121 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "great you're using the Storage System.\p"
# 122 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "If you could, please visit me at home.\n"
# 123 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "My house is on Route 114.$"
# 124 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 125 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown: @ 8200E22
# 126 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "I wonder what Pokémon looked like\n"
# 127 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "long, long ago?\p"
# 128 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "Maybe the Fossil Maniac at the edge\n"
# 129 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "of town will know.$"
# 130 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"

# 131 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees: @ 8200E8B
# 132 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "In the fields of Fallarbor, we plant\n"
# 133 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "seedlings of hardy trees that thrive\l"
# 134 "data/maps/FallarborTown_PokemonCenter_1F/scripts.pory"
	.string "even in volcanic ash.$"
