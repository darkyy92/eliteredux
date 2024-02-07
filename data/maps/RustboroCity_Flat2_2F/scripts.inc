# 1 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 2 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
.set LOCALID_ACE, 3
# 3 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
.set LOCALID_HIKER, 4
# 4 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 5 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_MapScripts::
# 6 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat2_2F_OnTransition
# 7 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.byte 0
# 8 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 9 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_OnTransition: @ 82379A0
# 10 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	goto_if_set FLAG_ITEM_RUSTBORO_FLOAT_STONE, RustboroCity_Flat2_2F_HideAceShowHiker
# 11 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 12 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 13 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_HideAceShowHiker:
# 14 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_HIKER 
# 15 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	removeobject LOCALID_ACE
# 16 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 17 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 18 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_OldMan:: @ 8215FD8
# 19 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
# 20 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 21 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 22 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_NinjaBoy:: @ 8215FE1
# 23 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	lock
# 24 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	faceplayer
# 25 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
# 26 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
# 27 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	giveitem ITEM_PREMIER_BALL
# 28 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	compare VAR_RESULT, FALSE
# 29 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 30 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
# 31 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	release
# 32 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 33 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 34 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_GavePremierBall:: @ 8216010
# 35 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
# 36 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	release
# 37 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 38 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 39 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_GiveFloatStone::
# 40 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	lock
# 41 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	faceplayer
# 42 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	goto_if_set FLAG_ITEM_RUSTBORO_FLOAT_STONE, RustboroCity_Flat2_2F_EventScript_GaveFloatStone
# 43 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_MyDadsAceAtDevon, MSGBOX_DEFAULT
# 44 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	giveitem ITEM_FLOAT_STONE
# 45 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_PokemonHoldFloatStone, MSGBOX_DEFAULT
# 46 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	setflag FLAG_ITEM_RUSTBORO_FLOAT_STONE
# 47 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	release
# 48 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 49 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 50 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_GaveFloatStone::
# 51 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	lock
# 52 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	faceplayer
# 53 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_PokemonHoldFloatStone, MSGBOX_DEFAULT
# 54 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	release
# 55 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 56 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 57 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_EventScript_FatMan::
# 58 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	lock
# 59 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	faceplayer
# 60 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	msgbox RustboroCity_Flat2_2F_Text_PutOnWeight, MSGBOX_DEFAULT
# 61 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	release
# 62 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	end
# 63 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 64 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays: @ 821601A
# 65 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "Way back in the old days, Devon was just\n"
# 66 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "a teeny, tiny company.$"
# 67 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 68 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt: @ 821605A
# 69 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "My daddy's working at the Corporation.\p"
# 70 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "My daddy made this!\n"
# 71 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "But I can't use it, so you can have it.$"
# 72 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 73 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo: @ 82160BD
# 74 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "My daddy's working at the Corporation.\p"
# 75 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "When I grow up, I'm going to work for\n"
# 76 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "Devon, too.$"
# 77 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 78 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_MyDadsAceAtDevon:
# 79 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "My dad's a real ace in the Devon\n"
# 80 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "Corporation, I'll have you know!\p"
# 81 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "It's no wonder I'm an ace myself!\p"
# 82 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "Here. I'll give you something that\n"
# 83 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "an Ace Trainer like me uses!$"
# 84 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 85 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_PokemonHoldFloatStone:
# 86 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "If you have a Pokémon hold a Float Stone,\n"
# 87 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "its weight will be halved.\p"
# 88 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "Although it looks like it'll be a while\n"
# 89 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "before you can use something like this\l"
# 90 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "as well as I can.$"
# 91 "data/maps/RustboroCity_Flat2_2F/scripts.pory"

# 92 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
RustboroCity_Flat2_2F_Text_PutOnWeight:
# 93 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "… … … … … …\p"
# 94 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "For some reason, I've put on\n"
# 95 "data/maps/RustboroCity_Flat2_2F/scripts.pory"
	.string "a lot of weight recently.$"
