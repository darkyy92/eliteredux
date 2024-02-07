# 1 "data/maps/FortreeCity_Mart/scripts.pory"

# 2 "data/maps/FortreeCity_Mart/scripts.pory"
.set LOCALID_SPENSER, 5
# 3 "data/maps/FortreeCity_Mart/scripts.pory"

# 4 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_MapScripts:: @ 8217665
# 5 "data/maps/FortreeCity_Mart/scripts.pory"
	.byte 0
# 6 "data/maps/FortreeCity_Mart/scripts.pory"

# 7 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Clerk:: @ 8217666
# 8 "data/maps/FortreeCity_Mart/scripts.pory"
	lock
# 9 "data/maps/FortreeCity_Mart/scripts.pory"
	faceplayer
# 10 "data/maps/FortreeCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 11 "data/maps/FortreeCity_Mart/scripts.pory"
	waitmessage
# 12 "data/maps/FortreeCity_Mart/scripts.pory"
	pokemart FortreeCity_Mart_Pokemart
# 13 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 14 "data/maps/FortreeCity_Mart/scripts.pory"
	release
# 15 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 16 "data/maps/FortreeCity_Mart/scripts.pory"

# 17 "data/maps/FortreeCity_Mart/scripts.pory"
	.align 2
# 18 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Pokemart:
# 19 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_PROTECTOR
# 20 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_ELECTIRIZER
# 21 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_MAGMARIZER
# 22 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_RAZOR_FANG
# 23 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_RAZOR_CLAW
# 24 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_DUBIOUS_DISC
# 25 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_REAPER_CLOTH
# 26 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_DRAGON_SCALE
# 27 "data/maps/FortreeCity_Mart/scripts.pory"
	.2byte ITEM_NONE
# 28 "data/maps/FortreeCity_Mart/scripts.pory"
	release
# 29 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 30 "data/maps/FortreeCity_Mart/scripts.pory"

# 31 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Woman:: @ 8217698
# 32 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
# 33 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 34 "data/maps/FortreeCity_Mart/scripts.pory"

# 35 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Girl:: @ 82176A1
# 36 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
# 37 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 38 "data/maps/FortreeCity_Mart/scripts.pory"

# 39 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Boy:: @ 82176AA
# 40 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
# 41 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 42 "data/maps/FortreeCity_Mart/scripts.pory"

# 43 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_Spenser::
# 44 "data/maps/FortreeCity_Mart/scripts.pory"
	lock
# 45 "data/maps/FortreeCity_Mart/scripts.pory"
	faceplayer
# 46 "data/maps/FortreeCity_Mart/scripts.pory"
	compare VAR_LAVARIDGE_LUCY_STATE, 2
# 47 "data/maps/FortreeCity_Mart/scripts.pory"
	goto_if_eq FortreeCity_Mart_EventScript_SpenserBeatLucy
# 48 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_SpenserBattle::
# 49 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_SpenserBeforeBattle, MSGBOX_DEFAULT
# 50 "data/maps/FortreeCity_Mart/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENSER_FORTREE, FortreeCity_Mart_Text_SpenserDefeat
# 51 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_SpenserGiveChoiceScarf, MSGBOX_DEFAULT
# 52 "data/maps/FortreeCity_Mart/scripts.pory"
	givecustommon SPECIES_LAPRAS, 55, ITEM_ASSAULT_VEST, ITEM_PARK_BALL, NATURE_MODEST, 2, 252, 0, 0, 4, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_FREEZE_DRY, MOVE_SPARKLING_ARIA, MOVE_THUNDER, MOVE_PSYCHIC, FALSE
# 53 "data/maps/FortreeCity_Mart/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 54 "data/maps/FortreeCity_Mart/scripts.pory"
	message FortreeCity_Mart_Text_Got_Lapras
# 55 "data/maps/FortreeCity_Mart/scripts.pory"
	waitfanfare
# 56 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_SpenserFarewell, MSGBOX_AUTOCLOSE
# 57 "data/maps/FortreeCity_Mart/scripts.pory"
	switch VAR_FACING
# 58 "data/maps/FortreeCity_Mart/scripts.pory"
	case DIR_NORTH, FortreeCity_Mart_EventScript_SpenserExitNorth
# 59 "data/maps/FortreeCity_Mart/scripts.pory"
	case DIR_WEST, FortreeCity_Mart_EventScript_SpenserExitDown
# 60 "data/maps/FortreeCity_Mart/scripts.pory"
	case DIR_EAST, FortreeCity_Mart_EventScript_SpenserExitDown
# 61 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 62 "data/maps/FortreeCity_Mart/scripts.pory"

# 63 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_SpenserExitNorth::
# 64 "data/maps/FortreeCity_Mart/scripts.pory"
	applymovement LOCALID_SPENSER, FortreeCity_Mart_Movement_SpenserExitNorth
# 65 "data/maps/FortreeCity_Mart/scripts.pory"
	waitmovement 0
# 66 "data/maps/FortreeCity_Mart/scripts.pory"
	goto FortreeCity_Mart_EventScript_SpenserLeave
# 67 "data/maps/FortreeCity_Mart/scripts.pory"

# 68 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_SpenserExitDown::
# 69 "data/maps/FortreeCity_Mart/scripts.pory"
	applymovement LOCALID_SPENSER, FortreeCity_Mart_Movement_SpenserExitDown
# 70 "data/maps/FortreeCity_Mart/scripts.pory"
	waitmovement 0
# 71 "data/maps/FortreeCity_Mart/scripts.pory"
	goto FortreeCity_Mart_EventScript_SpenserLeave
# 72 "data/maps/FortreeCity_Mart/scripts.pory"

# 73 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_SpenserLeave::
# 74 "data/maps/FortreeCity_Mart/scripts.pory"
	playse SE_SLIDING_DOOR
# 75 "data/maps/FortreeCity_Mart/scripts.pory"
	removeobject LOCALID_SPENSER
# 76 "data/maps/FortreeCity_Mart/scripts.pory"
	release
# 77 "data/maps/FortreeCity_Mart/scripts.pory"
	end
# 78 "data/maps/FortreeCity_Mart/scripts.pory"

# 79 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_EventScript_SpenserBeatLucy::
# 80 "data/maps/FortreeCity_Mart/scripts.pory"
	msgbox FortreeCity_Mart_Text_SpenserBeatLucy, MSGBOX_DEFAULT
# 81 "data/maps/FortreeCity_Mart/scripts.pory"
	goto FortreeCity_Mart_EventScript_SpenserBattle
# 82 "data/maps/FortreeCity_Mart/scripts.pory"

# 83 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_SpenserBeatLucy:
# 84 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Hm? You're the youngster who beat Lucy!\n"
# 85 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Gwahahah! She wasn't happy about that!$"
# 86 "data/maps/FortreeCity_Mart/scripts.pory"

# 87 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_SpenserIntro:
# 88 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Hm? You're the youngster Scott's\n"
# 89 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "always talking about!$"
# 90 "data/maps/FortreeCity_Mart/scripts.pory"

# 91 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_SpenserBeforeBattle:
# 92 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "I'd like to see your skills for myself.\p"
# 93 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Can your bonds of trust with your\n"
# 94 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Pokémon match mine?\p"
# 95 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "If not, you will never beat my\n"
# 96 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "brethren!$"
# 97 "data/maps/FortreeCity_Mart/scripts.pory"

# 98 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_SpenserDefeat:
# 99 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Gwahahah!$"
# 100 "data/maps/FortreeCity_Mart/scripts.pory"

# 101 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_SpenserGiveChoiceScarf:
# 102 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Hahahaha! Saw right through my\n"
# 103 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "bluster, did you?\p"
# 104 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Here, take one of my Pokémon!$"
# 105 "data/maps/FortreeCity_Mart/scripts.pory"

# 106 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_SpenserFarewell:
# 107 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "I look forward to our next battle.\n"
# 108 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Farewell for now!$"
# 109 "data/maps/FortreeCity_Mart/scripts.pory"

# 110 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_SuperRepelBetter: @ 82176B3
# 111 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Super Repel lasts a long time,\n"
# 112 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "and it gets the job done.\p"
# 113 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "It's much better than an ordinary\n"
# 114 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Repel.$"
# 115 "data/maps/FortreeCity_Mart/scripts.pory"

# 116 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_StockUpOnItems: @ 8217715
# 117 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "I always stock up on more items than\n"
# 118 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "I'm sure I'll need.\p"
# 119 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "You never know what might happen.\n"
# 120 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "Better to be safe than sorry!$"
# 121 "data/maps/FortreeCity_Mart/scripts.pory"

# 122 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Text_RareCandyMakesMonGrow: @ 821778E
# 123 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "A Rare Candy makes a Pokémon grow\n"
# 124 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "immediately by one level.$"
# 125 "data/maps/FortreeCity_Mart/scripts.pory"

# 126 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Movement_SpenserExitNorth:
# 127 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_left
# 128 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 129 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 130 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 131 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 132 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 133 "data/maps/FortreeCity_Mart/scripts.pory"
	delay_8
# 134 "data/maps/FortreeCity_Mart/scripts.pory"
	step_end
# 135 "data/maps/FortreeCity_Mart/scripts.pory"

# 136 "data/maps/FortreeCity_Mart/scripts.pory"
FortreeCity_Mart_Movement_SpenserExitDown:
# 137 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 138 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 139 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 140 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 141 "data/maps/FortreeCity_Mart/scripts.pory"
	walk_down
# 142 "data/maps/FortreeCity_Mart/scripts.pory"
	delay_8
# 143 "data/maps/FortreeCity_Mart/scripts.pory"
	step_end

FortreeCity_Mart_Text_Got_Lapras::
# 145 "data/maps/FortreeCity_Mart/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Lapras{COLOR DARK_GRAY} as a gift!$"
