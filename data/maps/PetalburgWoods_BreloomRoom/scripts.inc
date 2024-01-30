PetalburgWoods_BreloomRoom_MapScripts::
	.byte 0


PetalburgWoods_BreloomRoom_EventScript_Breloom::
# 4 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	lock
# 5 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	faceplayer
# 6 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_PETALBURG_WOODS_BRELOOM, PetalburgWoods_BreloomRoom_EventScript_Breloom_Join
# 7 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, PetalburgWoods_BreloomRoom_EventScript_Breloom_PreNorman
# 8 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	playmoncry SPECIES_BRELOOM, 2
# 9 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_0, MSGBOX_YESNO
# 10 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoods_BreloomRoom_EventScript_Breloom_2
# 47 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	playmoncry SPECIES_BRELOOM, 2
# 48 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_3, MSGBOX_DEFAULT
PetalburgWoods_BreloomRoom_EventScript_Breloom_1:
# 50 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	release
	end

PetalburgWoods_BreloomRoom_EventScript_Breloom_2:
# 11 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	playmoncry SPECIES_BRELOOM, 2
# 12 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_1, MSGBOX_DEFAULT
# 13 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	delay 40
# 14 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	waitmoncry
# 15 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 16 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 1
# 17 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 2
# 18 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 0
# 19 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 2
# 20 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 2
# 21 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
# 22 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
# 23 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_BRELOOM
# 24 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setflag FLAG_SHINY_CREATION
# 25 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setwildbattlewithcustommoves SPECIES_BRELOOM, 0, ITEM_BRELOOMITE, MOVE_BULLET_SEED, MOVE_BRICK_BREAK, MOVE_SPORE, MOVE_ROCK_TOMB, 0, NATURE_ADAMANT, 252, 252, 252, 252, 252, 252
# 26 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 27 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	dowildbattle
# 28 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 29 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 30 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	switch VAR_RESULT
# 31 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	case B_OUTCOME_CAUGHT, PetalburgWoods_BreloomRoom_EventScript_Breloom_6
# 32 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	case B_OUTCOME_WON, PetalburgWoods_BreloomRoom_EventScript_Breloom_6
# 35 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	case B_OUTCOME_RAN, PetalburgWoods_BreloomRoom_EventScript_Breloom_7
# 36 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_BreloomRoom_EventScript_Breloom_7
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_1

PetalburgWoods_BreloomRoom_EventScript_Breloom_6:
# 33 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_Join
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_1

PetalburgWoods_BreloomRoom_EventScript_Breloom_7:
# 37 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_BRELOOM
# 38 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 39 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	removeobject VAR_LAST_TALKED
# 40 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 41 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 42 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_2, MSGBOX_DEFAULT
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_1


PetalburgWoods_BreloomRoom_EventScript_Breloom_PreNorman::
# 55 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	message PetalburgWoods_BreloomRoom_EventScript_Breloom_PreNorman_Text_0
# 56 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	waitmessage
# 57 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	release
	end


PetalburgWoods_BreloomRoom_EventScript_Breloom_Join::
# 62 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_0, MSGBOX_YESNO
# 63 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_2
PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_1:
# 73 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_PETALBURG_WOODS_BRELOOM, PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_5
PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_4:
# 80 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	release
	end

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_2:
# 64 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setflag FLAG_OBTAINED_PETALBURG_WOODS_BRELOOM
# 65 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	givecustommon SPECIES_BRELOOM, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_ADAMANT, 0, 252, 252, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_BULLET_SEED, MOVE_BRICK_BREAK, MOVE_SPORE, MOVE_ROCK_TOMB, TRUE
# 66 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 67 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	message PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_1
# 68 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	waitfanfare
# 69 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 70 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	removeobject VAR_LAST_TALKED
# 71 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_1

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_5:
# 74 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_WOODS_BRELOOM
# 75 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 76 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	giveitem ITEM_BRELOOMITE, 1
# 77 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	message PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_2
# 78 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	waitfanfare
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_4


PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_0:
# 9 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	.string "The Breloom seems to acknowledge you.\n"
	.string "It wishes to test you in battle, will you\l"
	.string "battle it?$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_1:
# 12 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	.string "Breloom: Loom!$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_2:
# 42 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	.string "The {STR_VAR_1} ran away!$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_3:
# 48 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	.string "Breloom: Loom...$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_PreNorman_Text_0:
# 55 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	.string "The Breloom refuses to acknowledge\n"
	.string "your presence. Perhaps it doesn't yet\l"
	.string "consider you a worthy opponent?{PAUSE_UNTIL_PRESS}$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_0:
# 62 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	.string "Breloom seems to want to join your\n"
	.string "team, will you let this Breloom join you?$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_1:
# 67 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	.string "{PLAYER} received a Breloom!$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_2:
# 77 "data/maps/PetalburgWoods_BreloomRoom/scripts.pory"
	.string "{PLAYER} received a Breloomite!$"
