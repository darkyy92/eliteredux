Seaspray_Cave_B1F_MapScripts::
	.byte 0


Seaspray_Cave_B1F_EventScript_Dewgong::
# 4 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	lock
# 5 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	faceplayer
# 6 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_SEASPRAY_CAVE_DEWGONG, Seaspray_Cave_B1F_EventScript_Dewgong_Join
# 7 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	goto_if_unset FLAG_BADGE07_GET, Seaspray_Cave_B1F_EventScript_Dewgong_PreTateLiza
# 8 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	playmoncry SPECIES_DEWGONG, 2
# 9 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_0, MSGBOX_YESNO
# 10 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Seaspray_Cave_B1F_EventScript_Dewgong_2
# 47 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	playmoncry SPECIES_DEWGONG, 2
# 48 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_3, MSGBOX_DEFAULT
Seaspray_Cave_B1F_EventScript_Dewgong_1:
# 50 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	release
	end

Seaspray_Cave_B1F_EventScript_Dewgong_2:
# 11 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	playmoncry SPECIES_DEWGONG, 2
# 12 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_1, MSGBOX_DEFAULT
# 13 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	delay 40
# 14 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	waitmoncry
# 15 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 16 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 2
# 17 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 2
# 18 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 2
# 19 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 2
# 20 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 2
# 21 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
# 22 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
# 23 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_DEWGONG
# 25 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setwildbattlewithcustommoves SPECIES_DEWGONG, 0, ITEM_DEWGONGITE, MOVE_HORN_DRILL, MOVE_FREEZE_DRY, MOVE_AQUA_JET, MOVE_SLACK_OFF, 2, NATURE_BRAVE, 252, 252, 252, 252, 252, 252
# 26 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 27 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	dowildbattle
# 28 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 29 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 30 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	switch VAR_RESULT
# 31 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	case B_OUTCOME_CAUGHT, Seaspray_Cave_B1F_EventScript_Dewgong_6
# 32 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	case B_OUTCOME_WON, Seaspray_Cave_B1F_EventScript_Dewgong_6
# 35 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	case B_OUTCOME_RAN, Seaspray_Cave_B1F_EventScript_Dewgong_7
# 36 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Seaspray_Cave_B1F_EventScript_Dewgong_7
	goto Seaspray_Cave_B1F_EventScript_Dewgong_1

Seaspray_Cave_B1F_EventScript_Dewgong_6:
# 33 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	goto Seaspray_Cave_B1F_EventScript_Dewgong_Join
	goto Seaspray_Cave_B1F_EventScript_Dewgong_1

Seaspray_Cave_B1F_EventScript_Dewgong_7:
# 37 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setvar VAR_0x8004, SPECIES_DEWGONG
# 38 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 39 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 40 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 41 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 42 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Text_2, MSGBOX_DEFAULT
	goto Seaspray_Cave_B1F_EventScript_Dewgong_1


Seaspray_Cave_B1F_EventScript_Dewgong_PreTateLiza::
# 55 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	message Seaspray_Cave_B1F_EventScript_Dewgong_PreTateLiza_Text_0
# 56 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	waitmessage
# 57 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	release
	end


Seaspray_Cave_B1F_EventScript_Dewgong_Join::
# 62 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_0, MSGBOX_YESNO
# 63 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Seaspray_Cave_B1F_EventScript_Dewgong_Join_2
Seaspray_Cave_B1F_EventScript_Dewgong_Join_1:
# 73 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_SEASPRAY_CAVE_DEWGONG, Seaspray_Cave_B1F_EventScript_Dewgong_Join_5
Seaspray_Cave_B1F_EventScript_Dewgong_Join_4:
# 80 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	release
	end

Seaspray_Cave_B1F_EventScript_Dewgong_Join_2:
# 64 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setflag FLAG_OBTAINED_SEASPRAY_CAVE_DEWGONG
# 65 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	givecustommon SPECIES_DEWGONG, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_BRAVE, 2, 252, 4, 0, 0, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_HORN_DRILL, MOVE_FREEZE_DRY, MOVE_AQUA_JET, MOVE_SLACK_OFF, FALSE
# 66 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 67 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	message Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_1
# 68 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	waitfanfare
# 69 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 70 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 71 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Seaspray_Cave_B1F_EventScript_Dewgong_Join_1

Seaspray_Cave_B1F_EventScript_Dewgong_Join_5:
# 74 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	setflag FLAG_DEFEATED_SEASPRAY_CAVE_DEWGONG
# 75 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 76 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	giveitem ITEM_DEWGONGITE, 1
# 77 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	message Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_2
# 78 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	waitfanfare
	goto Seaspray_Cave_B1F_EventScript_Dewgong_Join_4


Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate::
# 85 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	lock
# 86 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	faceplayer
# 88 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	checktrainerflag TRAINER_KAYLEE
	goto_if 0, Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_2
# 100 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_4, MSGBOX_NPC
Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_1:
# 102 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	release
	end

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_2:
# 89 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_0, MSGBOX_YESNO
# 90 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_5
# 96 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_3, MSGBOX_NPC
	goto Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_1

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_5:
# 91 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	trainerbattle_no_intro TRAINER_KAYLEE, Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_1
# 92 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	msgbox Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_2, MSGBOX_NPC
# 93 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	giveitem ITEM_DEWGONGITE, 1
	goto Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_1


Seaspray_Cave_B1F_EventScript_Dewgong_Text_0:
# 9 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "The Dewgong considers you a worthy\n"
	.string "opponent. It seems it wishes to test\l"
	.string "you in battle.$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_1:
# 12 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "Dewgong: Gong!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_2:
# 42 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "The {STR_VAR_1} ran away!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Text_3:
# 48 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "Dewgong: Gong...$"

Seaspray_Cave_B1F_EventScript_Dewgong_PreTateLiza_Text_0:
# 55 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "The Dewgong finds you pitiful. Perhaps\n"
	.string "return after growing stronger?{PAUSE_UNTIL_PRESS}$"

Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_0:
# 62 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "Dewgong seems to want to join your\n"
	.string "team, will you let this Dewgong join\l"
	.string "you?$"

Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_1:
# 67 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "{PLAYER} received a Dewgong!$"

Seaspray_Cave_B1F_EventScript_Dewgong_Join_Text_2:
# 77 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "{PLAYER} received a Dewgongite!$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_0:
# 89 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "Do you want to battle?, I have a pretty\n"
	.string "good prize for you if you win.$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_1:
# 91 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "I got defeated...$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_2:
# 92 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "That was a great battle, here is your\n"
	.string "prize, you earned it!$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_3:
# 96 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "Oh well...$"

Seaspray_Cave_B1F_EventScript_TrainerMegaStoneTemplate_Text_4:
# 100 "data/maps/Seaspray_Cave_B1F/scripts.pory"
	.string "It was a good battle but I already gave\n"
	.string "you your prize.$"
