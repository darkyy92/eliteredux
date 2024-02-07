# 1 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 2 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 4 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_MapScripts:: @ 8202726
# 5 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
# 6 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 7 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.byte 0
# 8 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 9 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_OnTransition: @ 8202731
# 10 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
# 11 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_UpdateBrineyLocation
# 12 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 13 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 14 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_Nurse:: @ 820273A
# 15 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 16 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 17 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 18 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	waitbuttonpress
# 19 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	release
# 20 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 21 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 22 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_XscissorTM::
# 23 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	lock
# 24 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 25 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_1F_Text_DoYouLikeBugs, MSGBOX_YESNO
# 26 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, NO
# 27 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	goto_if_eq VerdanturfTown_PokemonCenter_1F_EventScript_DontLikeBugs
# 28 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_1F_Text_GiveTM81, MSGBOX_DEFAULT
# 29 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	release
# 30 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 31 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 32 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_ReceivedTM81::
# 33 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_1F_Text_HaveTM81, MSGBOX_DEFAULT
# 34 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	release
# 35 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 36 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 37 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_DontLikeBugs::
# 38 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_1F_Text_DontLikeBugs, MSGBOX_DEFAULT
# 39 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	release
# 40 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 41 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 42 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_Clerk2::
# 43 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	lock
# 44 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 45 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	message gText_HowMayIServeYou
# 46 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 47 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	pokemart PokeMart_PokeCenterVerdanturfTown
# 48 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 49 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	release
# 50 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 51 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 52 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.align 2
# 53 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
PokeMart_PokeCenterVerdanturfTown::
# 54 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 55 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 56 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 57 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.2byte ITEM_NONE
# 58 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	release
# 59 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 60 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 61 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman:: @ 8202748
# 62 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
# 63 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 64 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 65 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM:: @ 8202751
# 66 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
# 67 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	end
# 68 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 69 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_Text_DoYouLikeBugs:
# 70 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "Yo! Bug-type Pokémon are wickedly cool!\n"
# 71 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "You agree, right?$"
# 72 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 73 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_Text_GiveTM81:
# 74 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "Yeah! I like you. We can be friends.$"
# 75 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 76 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_Text_HaveTM81:
# 77 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "TM81 is X-scissor.\n"
# 78 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "It's a wickedly cool Bug-type attack!$"
# 79 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 80 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_Text_DontLikeBugs:
# 81 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "No? We're not on the same wavelength.$"
# 82 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 83 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon: @ 820275A
# 84 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "You can't consider yourself a real\n"
# 85 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "Trainer if you don't have faith\l"
# 86 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "in your Pokémon.\p"
# 87 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "Only those people who can believe\n"
# 88 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "in their battling Pokémon can win\l"
# 89 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "through to the very end.$"
# 90 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"

# 91 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent: @ 820280B
# 92 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "The reason why anyone would visit\n"
# 93 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "Verdanturf…\p"
# 94 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "It's the Battle Tent. It goes without\n"
# 95 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "saying.\p"
# 96 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "Or is there somebody here that you\n"
# 97 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "came to see?$"

Common_EventScript_PkmnCenterNurse::
# 101 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	lock
# 102 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	faceplayer
# 104 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	checkitem ITEM_POKE_VIAL, 1
# 105 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_EventScript_PkmnCenterNurse_2
# 111 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_0, MSGBOX_DEFAULT
# 118 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 119 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	message Common_EventScript_PkmnCenterNurse_Text_1
# 120 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 121 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	setflag FLAG_SYS_DEXNAV_GET
# 122 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 124 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_2, MSGBOX_DEFAULT
# 126 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 127 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	message Common_EventScript_PkmnCenterNurse_Text_3
# 128 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	waitmessage
# 129 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse_GiveItems_First_Time
# 130 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	waitfanfare
# 132 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
# 133 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	additem ITEM_POKE_VIAL
# 134 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_POKE_VIAL_MAX_CHARGES, 1
# 135 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	setvar VAR_POKE_VIAL_CHARGES, 1
# 136 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_4, MSGBOX_DEFAULT
Common_EventScript_PkmnCenterNurse_1:
# 138 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	release
	end

Common_EventScript_PkmnCenterNurse_2:
# 107 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	goto EventScript_PkmnCenterNurseHasVial
	goto Common_EventScript_PkmnCenterNurse_1


Common_EventScript_PkmnCenterNurse_GiveItems_First_Time::
# 143 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	giveBattleItems
	return


Common_EventScript_PkmnCenterNurse_Text_0:
# 111 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "Hello, and welcome to the Pokémon\n"
	.string "Center.\p"
	.string "We can restore your tired Pokémon to\n"
	.string "full health, but that's not really\l"
	.string "needed as your Pokémon will auto-heal\l"
	.string "before every battle.\p"
	.string "This is your first time here, isn't it?\p"
	.string "It's your lucky day!\p"
	.string "We're currently giving out tons of\n"
	.string "useful items to all rookie Trainers.\p"
	.string "Here, take this DexNav first!$"

Common_EventScript_PkmnCenterNurse_Text_1:
# 119 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received the DexNav!$"

Common_EventScript_PkmnCenterNurse_Text_2:
# 124 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "I'll give you a Candy Box, TM Case, all\n"
	.string "Battle items, all Pokéballs, all TMs &\l"
	.string "HMs, all Berries, all Type Gems and some\l"
	.string "more stuff.\p"
	.string "Every time you speak to me, I'll fill all\n"
	.string "your items up again.$"

Common_EventScript_PkmnCenterNurse_Text_3:
# 127 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "{PLAYER} received a LOT of items!$"

Common_EventScript_PkmnCenterNurse_Text_4:
# 136 "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.pory"
	.string "We hope to see you again!$"
