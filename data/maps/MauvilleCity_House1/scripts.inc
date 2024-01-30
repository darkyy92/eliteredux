# 1 "data/maps/MauvilleCity_House1/scripts.pory"

# 2 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_MapScripts:: @ 820F975
# 3 "data/maps/MauvilleCity_House1/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_House1/scripts.pory"

# 5 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_RockSmashDude:: @ 820F976
# 6 "data/maps/MauvilleCity_House1/scripts.pory"
	lock
# 7 "data/maps/MauvilleCity_House1/scripts.pory"
	faceplayer
# 8 "data/maps/MauvilleCity_House1/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM06, MauvilleCity_House1_EventScript_ReceivedRockSmash
# 9 "data/maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
# 10 "data/maps/MauvilleCity_House1/scripts.pory"
	giveitem ITEM_HM06_ROCK_SMASH
# 11 "data/maps/MauvilleCity_House1/scripts.pory"
	setflag FLAG_RECEIVED_HM06
# 12 "data/maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
# 13 "data/maps/MauvilleCity_House1/scripts.pory"
	release
# 14 "data/maps/MauvilleCity_House1/scripts.pory"
	end
# 15 "data/maps/MauvilleCity_House1/scripts.pory"

# 16 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_EventScript_ReceivedRockSmash:: @ 820F9A5
# 17 "data/maps/MauvilleCity_House1/scripts.pory"
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
# 18 "data/maps/MauvilleCity_House1/scripts.pory"
	release
# 19 "data/maps/MauvilleCity_House1/scripts.pory"
	end
# 20 "data/maps/MauvilleCity_House1/scripts.pory"

# 21 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_ImRockSmashDudeTakeThis: @ 820F9AF
# 22 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!\p"
# 23 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "I hear people call me the Rock Smash\n"
# 24 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Guy, but I find that sort of degrading.\p"
# 25 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "I think I deserve a bit more respect,\n"
# 26 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "like maybe the Rock Smash Dude.\p"
# 27 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!\p"
# 28 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Anyways, your Pokémon look pretty\n"
# 29 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "strong.\p"
# 30 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "I like that!\n"
# 31 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Here, take this Hidden Machine!$"
# 32 "data/maps/MauvilleCity_House1/scripts.pory"

# 33 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_ExplainRockSmash: @ 820FAA9
# 34 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "That HM contains Rock Smash.\p"
# 35 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "If you come across large boulders\n"
# 36 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "that block your path…\p"
# 37 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Well, use that HM move and smash\n"
# 38 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "them right out of your way!\p"
# 39 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Yes, sir! Smash rocks aside, I say!\n"
# 40 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!$"
# 41 "data/maps/MauvilleCity_House1/scripts.pory"

# 42 "data/maps/MauvilleCity_House1/scripts.pory"
MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock: @ 820FB67
# 43 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Oh, yes, if you smash a rock, a Pokémon\n"
# 44 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "could come flying out of hiding.\p"
# 45 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Sometimes you'll find an item, or even\n"
# 46 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "a Fossil.\p"
# 47 "data/maps/MauvilleCity_House1/scripts.pory"
	.string "Woohoo!$"
