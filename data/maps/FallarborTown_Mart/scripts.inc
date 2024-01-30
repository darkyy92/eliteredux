# 1 "data/maps/FallarborTown_Mart/scripts.pory"

# 2 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_MapScripts:: @ 81FFCBE
# 3 "data/maps/FallarborTown_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/FallarborTown_Mart/scripts.pory"

# 5 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Clerk:: @ 81FFCBF
# 6 "data/maps/FallarborTown_Mart/scripts.pory"
	lock
# 7 "data/maps/FallarborTown_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/FallarborTown_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/FallarborTown_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/FallarborTown_Mart/scripts.pory"
	pokemart FallarborTown_Mart_Pokemart
# 11 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 13 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 14 "data/maps/FallarborTown_Mart/scripts.pory"

# 15 "data/maps/FallarborTown_Mart/scripts.pory"
	.align 2
# 16 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Pokemart: @ 81FFCD8
# 17 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 18 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 19 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 20 "data/maps/FallarborTown_Mart/scripts.pory"
	.2byte ITEM_NONE
# 21 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 22 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 23 "data/maps/FallarborTown_Mart/scripts.pory"

# 24 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Woman:: @ 81FFCF4
# 25 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
# 26 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 27 "data/maps/FallarborTown_Mart/scripts.pory"

# 28 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_PokefanM:: @ 81FFCFD
# 29 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
# 30 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 31 "data/maps/FallarborTown_Mart/scripts.pory"

# 32 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_Skitty:: @ 81FFD06
# 33 "data/maps/FallarborTown_Mart/scripts.pory"
	lock
# 34 "data/maps/FallarborTown_Mart/scripts.pory"
	faceplayer
# 35 "data/maps/FallarborTown_Mart/scripts.pory"
	waitse
# 36 "data/maps/FallarborTown_Mart/scripts.pory"
	playmoncry SPECIES_SKITTY, 0
# 37 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
# 38 "data/maps/FallarborTown_Mart/scripts.pory"
	waitmoncry
# 39 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 40 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 41 "data/maps/FallarborTown_Mart/scripts.pory"

# 42 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_DrainPunchTM::
# 43 "data/maps/FallarborTown_Mart/scripts.pory"
	lock
# 44 "data/maps/FallarborTown_Mart/scripts.pory"
	faceplayer
# 45 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_HaveTM60, MSGBOX_DEFAULT
# 46 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 47 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 48 "data/maps/FallarborTown_Mart/scripts.pory"

# 49 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_EventScript_ReceivedTM60::
# 50 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_HaveTM60, MSGBOX_DEFAULT
# 51 "data/maps/FallarborTown_Mart/scripts.pory"
	release
# 52 "data/maps/FallarborTown_Mart/scripts.pory"
	end
# 53 "data/maps/FallarborTown_Mart/scripts.pory"

# 54 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_FreeSample:
# 55 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "Hi there! How are you today?\p"
# 56 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "Can I interest you in a free sample\n"
# 57 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "of Devon Corporation's new cleaning\l"
# 58 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "product, DRAIN PUNCH?\p"
# 59 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "It's super effective against grime,\n"
# 60 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "gunk and gunge!\p"
# 61 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "… … … … … … … …\p"
# 62 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "… … … … … … … …\p"
# 63 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "… … … … … … … …\p"
# 64 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "Hmm? You're on an adventure?\n"
# 65 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "You don't need drain cleaner?\p"
# 66 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "Well, how about you take this TM\n"
# 67 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "instead?$"
# 68 "data/maps/FallarborTown_Mart/scripts.pory"

# 69 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_HaveTM60:
# 70 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "TM60 is also Drain Punch, but it's\n"
# 71 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "a punch that drains HP instead.\p"
# 72 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "Please don't use it on any drains!$"
# 73 "data/maps/FallarborTown_Mart/scripts.pory"

# 74 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_DecidingSkittyEvolve: @ 81FFD19
# 75 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I'm having a hard time deciding if I\n"
# 76 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "should make my Skitty evolve or not.\p"
# 77 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I only have to use this Moon Stone,\n"
# 78 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "but it's so hard to decide…\p"
# 79 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "If I make it evolve, it will become\n"
# 80 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "much stronger.\p"
# 81 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "But it will look so different, too.$"
# 82 "data/maps/FallarborTown_Mart/scripts.pory"

# 83 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_Skitty: @ 81FFDFA
# 84 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "Skitty: Miyao?$"
# 85 "data/maps/FallarborTown_Mart/scripts.pory"

# 86 "data/maps/FallarborTown_Mart/scripts.pory"
FallarborTown_Mart_Text_SellNuggetIFound: @ 81FFE09
# 87 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "This Nugget I found here…\n"
# 88 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I suppose I'll have to sell it, seeing\l"
# 89 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "as how it has no other use.$"
