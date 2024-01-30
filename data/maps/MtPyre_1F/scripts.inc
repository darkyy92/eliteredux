# 1 "data/maps/MtPyre_1F/scripts.pory"

# 2 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_MapScripts:: @ 8230F3E
# 3 "data/maps/MtPyre_1F/scripts.pory"
	.byte 0
# 4 "data/maps/MtPyre_1F/scripts.pory"

# 5 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_EventScript_CleanseTagWoman:: @ 8230F3F
# 6 "data/maps/MtPyre_1F/scripts.pory"
	lock
# 7 "data/maps/MtPyre_1F/scripts.pory"
	faceplayer
# 8 "data/maps/MtPyre_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
# 9 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
# 10 "data/maps/MtPyre_1F/scripts.pory"
	giveitem ITEM_CLEANSE_TAG
# 11 "data/maps/MtPyre_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 12 "data/maps/MtPyre_1F/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 13 "data/maps/MtPyre_1F/scripts.pory"
	setflag FLAG_RECEIVED_CLEANSE_TAG
# 14 "data/maps/MtPyre_1F/scripts.pory"
	release
# 15 "data/maps/MtPyre_1F/scripts.pory"
	end
# 16 "data/maps/MtPyre_1F/scripts.pory"

# 17 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_EventScript_ReceivedCleanseTag:: @ 8230F6E
# 18 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
# 19 "data/maps/MtPyre_1F/scripts.pory"
	release
# 20 "data/maps/MtPyre_1F/scripts.pory"
	end
# 21 "data/maps/MtPyre_1F/scripts.pory"

# 22 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_EventScript_PokefanF:: @ 8230F78
# 23 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
# 24 "data/maps/MtPyre_1F/scripts.pory"
	end
# 25 "data/maps/MtPyre_1F/scripts.pory"

# 26 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_EventScript_Man:: @ 8230F81
# 27 "data/maps/MtPyre_1F/scripts.pory"
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
# 28 "data/maps/MtPyre_1F/scripts.pory"
	end
# 29 "data/maps/MtPyre_1F/scripts.pory"

# 30 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Text_TakeThisForYourOwnGood: @ 8230F8A
# 31 "data/maps/MtPyre_1F/scripts.pory"
	.string "All sorts of beings wander the slopes\n"
# 32 "data/maps/MtPyre_1F/scripts.pory"
	.string "of Mt. Pyre…\p"
# 33 "data/maps/MtPyre_1F/scripts.pory"
	.string "There is no telling what may happen.\n"
# 34 "data/maps/MtPyre_1F/scripts.pory"
	.string "Take this. It's for your own good.$"
# 35 "data/maps/MtPyre_1F/scripts.pory"

# 36 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Text_ExplainCleanseTag: @ 8231005
# 37 "data/maps/MtPyre_1F/scripts.pory"
	.string "Have a Pokémon hold that\n"
# 38 "data/maps/MtPyre_1F/scripts.pory"
	.string "Cleanse Tag.\p"
# 39 "data/maps/MtPyre_1F/scripts.pory"
	.string "It will help ward off wild Pokémon.$"
# 40 "data/maps/MtPyre_1F/scripts.pory"

# 41 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Text_ComeToPayRespects: @ 823104F
# 42 "data/maps/MtPyre_1F/scripts.pory"
	.string "Did you come to pay your respect\n"
# 43 "data/maps/MtPyre_1F/scripts.pory"
	.string "to the spirits of departed Pokémon?\p"
# 44 "data/maps/MtPyre_1F/scripts.pory"
	.string "You must care for your Pokémon a lot.$"
# 45 "data/maps/MtPyre_1F/scripts.pory"

# 46 "data/maps/MtPyre_1F/scripts.pory"
MtPyre_1F_Text_RestingPlaceOfZigzagoon: @ 82310BA
# 47 "data/maps/MtPyre_1F/scripts.pory"
	.string "This is the final resting place of my\n"
# 48 "data/maps/MtPyre_1F/scripts.pory"
	.string "Zigzagoon. I cherished it…$"
