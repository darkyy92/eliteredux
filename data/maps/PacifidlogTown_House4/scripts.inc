# 1 "data/maps/PacifidlogTown_House4/scripts.pory"

# 2 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_MapScripts:: @ 8203F4B
# 3 "data/maps/PacifidlogTown_House4/scripts.pory"
	.byte 0
# 4 "data/maps/PacifidlogTown_House4/scripts.pory"

# 5 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_LittleGirl:: @ 8203F4C
# 6 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
# 7 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 8 "data/maps/PacifidlogTown_House4/scripts.pory"

# 9 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_Woman:: @ 8203F55
# 10 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
# 11 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 12 "data/maps/PacifidlogTown_House4/scripts.pory"

# 13 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_Boy:: @ 8203F5E
# 14 "data/maps/PacifidlogTown_House4/scripts.pory"
	lock
# 15 "data/maps/PacifidlogTown_House4/scripts.pory"
	faceplayer
# 16 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
# 17 "data/maps/PacifidlogTown_House4/scripts.pory"
	compare VAR_RESULT, YES
# 18 "data/maps/PacifidlogTown_House4/scripts.pory"
	goto_if_eq PacifidlogTown_House4_EventScript_Yes
# 19 "data/maps/PacifidlogTown_House4/scripts.pory"
	compare VAR_RESULT, NO
# 20 "data/maps/PacifidlogTown_House4/scripts.pory"
	goto_if_eq PacifidlogTown_House4_EventScript_No
# 21 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 22 "data/maps/PacifidlogTown_House4/scripts.pory"

# 23 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_Yes:: @ 8203F7F
# 24 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
# 25 "data/maps/PacifidlogTown_House4/scripts.pory"
	release
# 26 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 27 "data/maps/PacifidlogTown_House4/scripts.pory"

# 28 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_EventScript_No:: @ 8203F89
# 29 "data/maps/PacifidlogTown_House4/scripts.pory"
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
# 30 "data/maps/PacifidlogTown_House4/scripts.pory"
	release
# 31 "data/maps/PacifidlogTown_House4/scripts.pory"
	end
# 32 "data/maps/PacifidlogTown_House4/scripts.pory"

# 33 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon: @ 8203F93
# 34 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "People were saying they saw a Pokémon\n"
# 35 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "flying high above Hoenn.\p"
# 36 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Is it flying around all the time?\n"
# 37 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Doesn't it need to rest somewhere?$"
# 38 "data/maps/PacifidlogTown_House4/scripts.pory"

# 39 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_SkyPokemon: @ 8204017
# 40 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "A sky Pokémon!\n"
# 41 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "A sky Pokémon!$"
# 42 "data/maps/PacifidlogTown_House4/scripts.pory"

# 43 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_WhereDidYouComeFrom: @ 8204035
# 44 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Where did you come from?$"
# 45 "data/maps/PacifidlogTown_House4/scripts.pory"

# 46 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_YesTown: @ 820404E
# 47 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Yes?\n"
# 48 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Yes Town?\p"
# 49 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "I've never heard of a place like that.$"
# 50 "data/maps/PacifidlogTown_House4/scripts.pory"

# 51 "data/maps/PacifidlogTown_House4/scripts.pory"
PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere: @ 8204084
# 52 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "No? That doesn't make any sense.\n"
# 53 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "You have to come from somewhere.\p"
# 54 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "Oh! Wait! You're not going to say you\n"
# 55 "data/maps/PacifidlogTown_House4/scripts.pory"
	.string "were born at the bottom of the sea?$"
