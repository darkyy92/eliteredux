# 1 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 2 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_MapScripts:: @ 822BBB1
# 3 "data/maps/Route117_PokemonDayCare/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
# 4 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.byte 0
# 5 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 6 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_OnTransition: @ 822BBB7
# 7 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
# 8 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end
# 9 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 10 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_EventScript_RandomEgg::
# 11 "data/maps/Route117_PokemonDayCare/scripts.pory"
	lock
# 12 "data/maps/Route117_PokemonDayCare/scripts.pory"
	faceplayer
# 13 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, Route117_PokemonDayCare_EventScript_ReceivedTogepi
# 14 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setvar VAR_0x8004, SPECIES_TOGEPI
# 15 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setvar VAR_0x8005, MOVE_EXTRASENSORY
# 16 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_EventScript_TryGiveEgg::
# 17 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 18 "data/maps/Route117_PokemonDayCare/scripts.pory"
	compare VAR_RESULT, NO
# 19 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_DeclineEgg
# 20 "data/maps/Route117_PokemonDayCare/scripts.pory"
	specialvar VAR_0x8006, CalculatePlayerPartyCount
# 21 "data/maps/Route117_PokemonDayCare/scripts.pory"
	compare VAR_0x8006, PARTY_SIZE
# 22 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_NoRoomForEgg
# 23 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_Text_ThankYou, MSGBOX_DEFAULT
# 24 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setflag FLAG_DAILY_RECEIVED_DAYCARE_EGG
# 25 "data/maps/Route117_PokemonDayCare/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 26 "data/maps/Route117_PokemonDayCare/scripts.pory"
	message Route117_PokemonDayCare_Text_ReceivedTheEgg
# 27 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route117_PokemonDayCare_EventScript_TryGiveTogepiEgg
# 28 "data/maps/Route117_PokemonDayCare/scripts.pory"
	special SetSpeciesAndEggMove
# 29 "data/maps/Route117_PokemonDayCare/scripts.pory"
	waitfanfare
# 30 "data/maps/Route117_PokemonDayCare/scripts.pory"
	giveEgg VAR_0x8004
# 31 "data/maps/Route117_PokemonDayCare/scripts.pory"
	special SetGiftEggMove
# 32 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
# 33 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end
# 34 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 35 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_EventScript_TryGiveTogepiEgg::
# 36 "data/maps/Route117_PokemonDayCare/scripts.pory"
	waitfanfare
# 37 "data/maps/Route117_PokemonDayCare/scripts.pory"
	giveEgg VAR_0x8004
# 38 "data/maps/Route117_PokemonDayCare/scripts.pory"
	special SetGiftEggMove
# 39 "data/maps/Route117_PokemonDayCare/scripts.pory"
	setflag FLAG_RECEIVED_TOGEPI_EGG
# 40 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
# 41 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end
# 42 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 43 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_EventScript_ReceivedTogepi::
# 44 "data/maps/Route117_PokemonDayCare/scripts.pory"
	goto Route117_PokemonDayCare_EventScript_TryGiveEgg
# 45 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 46 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_EventScript_ReceivedEgg::
# 47 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_Text_SometimesEggFoundAtDayCare, MSGBOX_DEFAULT
# 48 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
# 49 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end
# 50 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 51 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_EventScript_NoRoomForEgg::
# 52 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 53 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
# 54 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end
# 55 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 56 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_EventScript_DeclineEgg::
# 57 "data/maps/Route117_PokemonDayCare/scripts.pory"
	msgbox Route117_PokemonDayCare_Text_AsYouWishThen, MSGBOX_DEFAULT
# 58 "data/maps/Route117_PokemonDayCare/scripts.pory"
	release
# 59 "data/maps/Route117_PokemonDayCare/scripts.pory"
	end
# 60 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 61 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_Text_HaveEggWillYouTakeIt:
# 62 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Ooh, you're a Pokémon Trainer,\n"
# 63 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "aren't you?\p "
# 64 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "See, I found an Egg at the Day Care,\n"
# 65 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "and I've been trying to find a good\l"
# 66 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "home for it.\p"
# 67 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Would you be interested in taking it?$"
# 68 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 69 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_Text_ThankYou:
# 70 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Oh, thank you! Please take good care\n"
# 71 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "of this Egg!$"
# 72 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 73 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_Text_ReceivedTheEgg:
# 74 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "{PLAYER} received the Egg.$"
# 75 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 76 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_Text_NoRoomForThisEgg:
# 77 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Oh? You've got a full party.\n"
# 78 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "There's no room for this Egg…$"
# 79 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 80 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_Text_AsYouWishThen:
# 81 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Oh…\p"
# 82 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "That's a shame. Let me know if you\n"
# 83 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "change your mind.$"
# 84 "data/maps/Route117_PokemonDayCare/scripts.pory"

# 85 "data/maps/Route117_PokemonDayCare/scripts.pory"
Route117_PokemonDayCare_Text_SometimesEggFoundAtDayCare:
# 86 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Sometimes Eggs are found here at the\n"
# 87 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "Day Care, but no one knows where they\l"
# 88 "data/maps/Route117_PokemonDayCare/scripts.pory"
	.string "come from.$"
