PetalburgWoods_BreloomRoom_MapScripts::
	.byte 0


PetalburgWoods_BreloomRoom_EventScript_Breloom::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_WOODS_BRELOOM, PetalburgWoods_BreloomRoom_EventScript_Breloom_Join
	goto_if_unset FLAG_BADGE05_GET, PetalburgWoods_BreloomRoom_EventScript_Breloom_PreNorman
	playmoncry SPECIES_BRELOOM, 2
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoods_BreloomRoom_EventScript_Breloom_2
	playmoncry SPECIES_BRELOOM, 2
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_3, MSGBOX_DEFAULT
PetalburgWoods_BreloomRoom_EventScript_Breloom_1:
	release
	end

PetalburgWoods_BreloomRoom_EventScript_Breloom_2:
	playmoncry SPECIES_BRELOOM, 2
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_1, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setflag FLAG_TOTEM_BATTLE
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 1
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 0
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 2
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 2
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_BRELOOM
	setflag FLAG_SHINY_CREATION
	setwildbattlewithcustommoves SPECIES_BRELOOM, 0, ITEM_BRELOOMITE, MOVE_BULLET_SEED, MOVE_BRICK_BREAK, MOVE_SPORE, MOVE_ROCK_TOMB, 0, NATURE_ADAMANT, 252, 252, 252, 252, 252, 252
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, PetalburgWoods_BreloomRoom_EventScript_Breloom_6
	case B_OUTCOME_WON, PetalburgWoods_BreloomRoom_EventScript_Breloom_6
	case B_OUTCOME_RAN, PetalburgWoods_BreloomRoom_EventScript_Breloom_7
	case B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_BreloomRoom_EventScript_Breloom_7
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_1

PetalburgWoods_BreloomRoom_EventScript_Breloom_6:
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_Join
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_1

PetalburgWoods_BreloomRoom_EventScript_Breloom_7:
	setvar VAR_0x8004, SPECIES_BRELOOM
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname 0, VAR_0x8004
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_2, MSGBOX_DEFAULT
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_1


PetalburgWoods_BreloomRoom_EventScript_Breloom_PreNorman::
	message PetalburgWoods_BreloomRoom_EventScript_Breloom_PreNorman_Text_0
	waitmessage
	release
	end


PetalburgWoods_BreloomRoom_EventScript_Breloom_Join::
	msgbox PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_2
PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_1:
	goto_if_unset FLAG_DEFEATED_PETALBURG_WOODS_BRELOOM, PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_5
PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_4:
	release
	end

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_2:
	setflag FLAG_OBTAINED_PETALBURG_WOODS_BRELOOM
	givecustommon SPECIES_BRELOOM, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_ADAMANT, 0, 252, 252, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, MOVE_BULLET_SEED, MOVE_BRICK_BREAK, MOVE_SPORE, MOVE_ROCK_TOMB, TRUE
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_1
	waitfanfare
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_1

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_5:
	setflag FLAG_DEFEATED_PETALBURG_WOODS_BRELOOM
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_BRELOOMITE, 1
	message PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_2
	waitfanfare
	goto PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_4


PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_0:
	.string "The Breloom seems to acknowledge you.\n"
	.string "It wishes to test you in battle, will\l"
	.string "you battle it?$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_1:
	.string "Breloom: Loom!$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_2:
	.string "The {STR_VAR_1} ran away!$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Text_3:
	.string "Breloom: Loom...$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_PreNorman_Text_0:
	.string "The Breloom refuses to acknowledge\n"
	.string "your presence. Perhaps it doesn't yet\l"
	.string "consider you a worthy opponent?{PAUSE_UNTIL_PRESS}$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_0:
	.string "Breloom seems to want to join your\n"
	.string "team, will you let this Breloom join\l"
	.string "you?$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_1:
	.string "{PLAYER} received a Breloom!$"

PetalburgWoods_BreloomRoom_EventScript_Breloom_Join_Text_2:
	.string "{PLAYER} received a Breloomite!$"
