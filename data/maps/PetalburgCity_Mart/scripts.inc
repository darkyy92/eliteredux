# 1 "data/maps/PetalburgCity_Mart/scripts.pory"

# 2 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_MapScripts:: @ 8207D68
# 3 "data/maps/PetalburgCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgCity_Mart/scripts.pory"

# 5 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Clerk:: @ 8207D69
# 6 "data/maps/PetalburgCity_Mart/scripts.pory"
	lock
# 7 "data/maps/PetalburgCity_Mart/scripts.pory"
	faceplayer
# 8 "data/maps/PetalburgCity_Mart/scripts.pory"
	message gText_HowMayIServeYou
# 9 "data/maps/PetalburgCity_Mart/scripts.pory"
	waitmessage
# 10 "data/maps/PetalburgCity_Mart/scripts.pory"
	pokemart PetalburgCity_Mart_Pokemart_Basic
# 11 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 12 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 13 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 14 "data/maps/PetalburgCity_Mart/scripts.pory"

# 15 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Pokemart_Basic:
# 16 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ATTACK
# 17 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 18 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 19 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 20 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_SPEED
# 21 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 22 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 23 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 24 "data/maps/PetalburgCity_Mart/scripts.pory"
	.2byte ITEM_NONE
# 25 "data/maps/PetalburgCity_Mart/scripts.pory"
	release
# 26 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 27 "data/maps/PetalburgCity_Mart/scripts.pory"

# 28 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Woman:: @ 8207DD6
# 29 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
# 30 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 31 "data/maps/PetalburgCity_Mart/scripts.pory"

# 32 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Boy:: @ 8207DDF
# 33 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
# 34 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 35 "data/maps/PetalburgCity_Mart/scripts.pory"

# 36 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_EventScript_Man:: @ 8207DE8
# 37 "data/maps/PetalburgCity_Mart/scripts.pory"
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
# 38 "data/maps/PetalburgCity_Mart/scripts.pory"
	end
# 39 "data/maps/PetalburgCity_Mart/scripts.pory"

# 40 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_WeakWillGrowStronger: @ 8207DF1
# 41 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Even if a Pokémon is weak now,\n"
# 42 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "it will grow stronger.\p"
# 43 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "The most important thing is love!\n"
# 44 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Love for your Pokémon!$"
# 45 "data/maps/PetalburgCity_Mart/scripts.pory"

# 46 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_RepelIsUseful: @ 8207E60
# 47 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you use Repel?\n"
# 48 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "It keeps Pokémon away, so it's\l"
# 49 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "useful when you're in a hurry.$"
# 50 "data/maps/PetalburgCity_Mart/scripts.pory"

# 51 "data/maps/PetalburgCity_Mart/scripts.pory"
PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou: @ 8207EB0
# 52 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Do you have any Antidotes with\n"
# 53 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "you?\p"
# 54 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "If you walk around with a poisoned\n"
# 55 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Pokémon, it will lose HP until it faints.\l"
# 56 "data/maps/PetalburgCity_Mart/scripts.pory"
	.string "Take some Antidotes with you.$"
