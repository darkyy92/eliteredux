# 1 "data/maps/MossdeepCity_House2/scripts.pory"

# 2 "data/maps/MossdeepCity_House2/scripts.pory"
.set LOCALID_WINGULL, 3
# 3 "data/maps/MossdeepCity_House2/scripts.pory"

# 4 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_MapScripts:: @ 82220DE
# 5 "data/maps/MossdeepCity_House2/scripts.pory"
	.byte 0
# 6 "data/maps/MossdeepCity_House2/scripts.pory"

# 7 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_Man:: @ 82220DF
# 8 "data/maps/MossdeepCity_House2/scripts.pory"
	msgbox MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree, MSGBOX_NPC
# 9 "data/maps/MossdeepCity_House2/scripts.pory"
	end
# 10 "data/maps/MossdeepCity_House2/scripts.pory"

# 11 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_Twin:: @ 82220E8
# 12 "data/maps/MossdeepCity_House2/scripts.pory"
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
# 13 "data/maps/MossdeepCity_House2/scripts.pory"
	end
# 14 "data/maps/MossdeepCity_House2/scripts.pory"

# 15 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_Wingull:: @ 82220F1
# 16 "data/maps/MossdeepCity_House2/scripts.pory"
	lock
# 17 "data/maps/MossdeepCity_House2/scripts.pory"
	faceplayer
# 18 "data/maps/MossdeepCity_House2/scripts.pory"
	waitse
# 19 "data/maps/MossdeepCity_House2/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 20 "data/maps/MossdeepCity_House2/scripts.pory"
	msgbox MossdeepCity_House2_Text_Wingull, MSGBOX_DEFAULT
# 21 "data/maps/MossdeepCity_House2/scripts.pory"
	waitmoncry
# 22 "data/maps/MossdeepCity_House2/scripts.pory"
	closemessage
# 23 "data/maps/MossdeepCity_House2/scripts.pory"
	setflag FLAG_WINGULL_DELIVERED_MAIL
# 24 "data/maps/MossdeepCity_House2/scripts.pory"
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL
# 25 "data/maps/MossdeepCity_House2/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 26 "data/maps/MossdeepCity_House2/scripts.pory"
	call_if_eq MossdeepCity_House2_EventScript_WingullExitNorth
# 27 "data/maps/MossdeepCity_House2/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 28 "data/maps/MossdeepCity_House2/scripts.pory"
	call_if_eq MossdeepCity_House2_EventScript_WingullExitWest
# 29 "data/maps/MossdeepCity_House2/scripts.pory"
	removeobject LOCALID_WINGULL
# 30 "data/maps/MossdeepCity_House2/scripts.pory"
	release
# 31 "data/maps/MossdeepCity_House2/scripts.pory"
	end
# 32 "data/maps/MossdeepCity_House2/scripts.pory"

# 33 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_WingullExitNorth:: @ 8222124
# 34 "data/maps/MossdeepCity_House2/scripts.pory"
	applymovement LOCALID_WINGULL, MossdeepCity_House2_Movement_WingullExitNorth
# 35 "data/maps/MossdeepCity_House2/scripts.pory"
	waitmovement 0
# 36 "data/maps/MossdeepCity_House2/scripts.pory"
	return
# 37 "data/maps/MossdeepCity_House2/scripts.pory"

# 38 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_EventScript_WingullExitWest:: @ 822212F
# 39 "data/maps/MossdeepCity_House2/scripts.pory"
	applymovement LOCALID_WINGULL, MossdeepCity_House2_Movement_WingullExitEast
# 40 "data/maps/MossdeepCity_House2/scripts.pory"
	waitmovement 0
# 41 "data/maps/MossdeepCity_House2/scripts.pory"
	return
# 42 "data/maps/MossdeepCity_House2/scripts.pory"

# 43 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Movement_WingullExitNorth: @ 822213A
# 44 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_right
# 45 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 46 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 47 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_left
# 48 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 49 "data/maps/MossdeepCity_House2/scripts.pory"
	delay_8
# 50 "data/maps/MossdeepCity_House2/scripts.pory"
	step_end
# 51 "data/maps/MossdeepCity_House2/scripts.pory"

# 52 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Movement_WingullExitEast: @ 8222141
# 53 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 54 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 55 "data/maps/MossdeepCity_House2/scripts.pory"
	walk_fast_down
# 56 "data/maps/MossdeepCity_House2/scripts.pory"
	delay_8
# 57 "data/maps/MossdeepCity_House2/scripts.pory"
	step_end
# 58 "data/maps/MossdeepCity_House2/scripts.pory"

# 59 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree: @ 8222146
# 60 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "My little sister exchanges Mail with\n"
# 61 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "her boyfriend in Fortree.\p"
# 62 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "I don't envy her one bit at all.$"
# 63 "data/maps/MossdeepCity_House2/scripts.pory"

# 64 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth: @ 82221A6
# 65 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "Even though I can't see my friend in\n"
# 66 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "Fortree, my Pokémon carries Mail\l"
# 67 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "back and forth for us.\p"
# 68 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "I'm not lonesome, even though we're\n"
# 69 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "apart.$"
# 70 "data/maps/MossdeepCity_House2/scripts.pory"

# 71 "data/maps/MossdeepCity_House2/scripts.pory"
MossdeepCity_House2_Text_Wingull: @ 822222E
# 72 "data/maps/MossdeepCity_House2/scripts.pory"
	.string "Wingull: Pihyoh!$"
