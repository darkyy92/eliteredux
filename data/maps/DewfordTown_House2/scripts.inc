# 1 "data/maps/DewfordTown_House2/scripts.pory"

# 2 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_MapScripts:: @ 81FE22D
# 3 "data/maps/DewfordTown_House2/scripts.pory"
	.byte 0
# 4 "data/maps/DewfordTown_House2/scripts.pory"

# 5 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_Man:: @ 81FE22E
# 6 "data/maps/DewfordTown_House2/scripts.pory"
	lock
# 7 "data/maps/DewfordTown_House2/scripts.pory"
	faceplayer
# 8 "data/maps/DewfordTown_House2/scripts.pory"
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
# 9 "data/maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
# 10 "data/maps/DewfordTown_House2/scripts.pory"
	giveitem ITEM_SILK_SCARF
# 11 "data/maps/DewfordTown_House2/scripts.pory"
	compare VAR_RESULT, FALSE
# 12 "data/maps/DewfordTown_House2/scripts.pory"
	goto_if_eq DewfordTown_House2_EventScript_NoRoomForScarf
# 13 "data/maps/DewfordTown_House2/scripts.pory"
	setflag FLAG_RECEIVED_SILK_SCARF
# 14 "data/maps/DewfordTown_House2/scripts.pory"
	release
# 15 "data/maps/DewfordTown_House2/scripts.pory"
	end
# 16 "data/maps/DewfordTown_House2/scripts.pory"

# 17 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_NoRoomForScarf:: @ 81FE25D
# 18 "data/maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
# 19 "data/maps/DewfordTown_House2/scripts.pory"
	release
# 20 "data/maps/DewfordTown_House2/scripts.pory"
	end
# 21 "data/maps/DewfordTown_House2/scripts.pory"

# 22 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_ExplainSilkScarf:: @ 81FE267
# 23 "data/maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
# 24 "data/maps/DewfordTown_House2/scripts.pory"
	release
# 25 "data/maps/DewfordTown_House2/scripts.pory"
	end
# 26 "data/maps/DewfordTown_House2/scripts.pory"

# 27 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_EventScript_Boy:: @ 81FE271
# 28 "data/maps/DewfordTown_House2/scripts.pory"
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
# 29 "data/maps/DewfordTown_House2/scripts.pory"
	end
# 30 "data/maps/DewfordTown_House2/scripts.pory"

# 31 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_WantYouToHaveSilkScarf: @ 81FE27A
# 32 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Gorge your eyes on this!\p"
# 33 "data/maps/DewfordTown_House2/scripts.pory"
	.string "It's a Silk Scarf. It's right at the\n"
# 34 "data/maps/DewfordTown_House2/scripts.pory"
	.string "cutting edge of fashion, yeah!\p"
# 35 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Oh, I can see your eyes twinkling!\n"
# 36 "data/maps/DewfordTown_House2/scripts.pory"
	.string "You appreciate my dazzling style!\p"
# 37 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Oh, you're a delight!\n"
# 38 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Here you go. I want you to have it!$"
# 39 "data/maps/DewfordTown_House2/scripts.pory"

# 40 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_NoRoom: @ 81FE356
# 41 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Oh, you don't have room?\p"
# 42 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Now, listen tight, this SCARF is a must-\n"
# 43 "data/maps/DewfordTown_House2/scripts.pory"
	.string "have! Why, I would sell all my items\l"
# 44 "data/maps/DewfordTown_House2/scripts.pory"
	.string "in order to get it!$"
# 45 "data/maps/DewfordTown_House2/scripts.pory"

# 46 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_ExplainSilkScarf: @ 81FE3D1
# 47 "data/maps/DewfordTown_House2/scripts.pory"
	.string "The Silk Scarf raises the power of\n"
# 48 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Normal-type moves.\p"
# 49 "data/maps/DewfordTown_House2/scripts.pory"
	.string "It's a marvelous Scarf that will go\n"
# 50 "data/maps/DewfordTown_House2/scripts.pory"
	.string "with almost all Pokémon!$"
# 51 "data/maps/DewfordTown_House2/scripts.pory"

# 52 "data/maps/DewfordTown_House2/scripts.pory"
DewfordTown_House2_Text_BrawlySoCool: @ 81FE444
# 53 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Wow, you bothered to cross the sea\n"
# 54 "data/maps/DewfordTown_House2/scripts.pory"
	.string "to visit Dewford?\p"
# 55 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Did you maybe come here because you\n"
# 56 "data/maps/DewfordTown_House2/scripts.pory"
	.string "heard about Brawly?\p"
# 57 "data/maps/DewfordTown_House2/scripts.pory"
	.string "He's so cool…\n"
# 58 "data/maps/DewfordTown_House2/scripts.pory"
	.string "Everyone idolizes him.$"
