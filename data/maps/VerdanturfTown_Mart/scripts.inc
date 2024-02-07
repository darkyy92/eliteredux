# 1 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 2 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_MapScripts:: @ 8202586
# 3 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 5 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_Clerk:: @ 8202587
# 6 "data/maps/VerdanturfTown_Mart/scripts.pory"
	lock
# 7 "data/maps/VerdanturfTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/VerdanturfTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/VerdanturfTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/VerdanturfTown_Mart/scripts.pory"
	pokemart VerdanturfTown_Mart_Pokemart
# 11 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/VerdanturfTown_Mart/scripts.pory"
	release
# 13 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 14 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 15 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Pokemart:
# 16 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 17 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 18 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 19 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 20 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 21 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 22 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 23 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 24 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.2byte ITEM_NONE
# 25 "data/maps/VerdanturfTown_Mart/scripts.pory"
	release
# 26 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 27 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 28 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_Boy:: @ 82025BA
# 29 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
# 30 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 31 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 32 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_ExpertF:: @ 82025C3
# 33 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
# 34 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 35 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 36 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_Lass:: @ 82025CC
# 37 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
# 38 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 39 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 40 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_PaybackTM::
# 41 "data/maps/VerdanturfTown_Mart/scripts.pory"
	lock
# 42 "data/maps/VerdanturfTown_Mart/scripts.pory"
	faceplayer
# 43 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox VerdanturfTown_Mart_Text_HaveTM66, MSGBOX_DEFAULT
# 44 "data/maps/VerdanturfTown_Mart/scripts.pory"
	release
# 45 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 46 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 47 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_EventScript_ReceivedTM66::
# 48 "data/maps/VerdanturfTown_Mart/scripts.pory"
	msgbox VerdanturfTown_Mart_Text_HaveTM66, MSGBOX_DEFAULT
# 49 "data/maps/VerdanturfTown_Mart/scripts.pory"
	release
# 50 "data/maps/VerdanturfTown_Mart/scripts.pory"
	end
# 51 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 52 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Text_SlowPokemon:
# 53 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "Do you think slow Pokémon ever get\n"
# 54 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "tired of taking the first hit in every\l"
# 55 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "battle?\p"
# 56 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "I think they'd be itching for a little\n"
# 57 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "payback!\p"
# 58 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "If you've got any slow Pokémon, give\n"
# 59 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "this TM a try.$"
# 60 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 61 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Text_HaveTM66:
# 62 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "My favorite move is Payback!\p"
# 63 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "It's an attack that doubles in power\n"
# 64 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "if the user moves after its target.$"
# 65 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 66 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Text_XSpecialIsCrucial: @ 82025D5
# 67 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "For any Pokémon match, X Special\n"
# 68 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "is crucial.\p"
# 69 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "It jacks up the power of some moves\n"
# 70 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "even though it's only for one battle.$"
# 71 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 72 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent: @ 820264C
# 73 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "They don't seem to sell any winning\n"
# 74 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "strategy guides for the Battle Tent…\p"
# 75 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "It seems one must rely on one's\n"
# 76 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "own wits after all…$"
# 77 "data/maps/VerdanturfTown_Mart/scripts.pory"

# 78 "data/maps/VerdanturfTown_Mart/scripts.pory"
VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
# 79 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "The Nest Ball works better on\n"
# 80 "data/maps/VerdanturfTown_Mart/scripts.pory"
	.string "weaker Pokémon.$"
