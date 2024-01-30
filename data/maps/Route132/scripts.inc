# 1 "data/maps/Route132/scripts.pory"

# 2 "data/maps/Route132/scripts.pory"
Route132_MapScripts:: @ 81F74E9
# 3 "data/maps/Route132/scripts.pory"
	.byte 0
# 4 "data/maps/Route132/scripts.pory"

# 5 "data/maps/Route132/scripts.pory"
Route132_EventScript_Gilbert:: @ 81F74EA
# 6 "data/maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_GILBERT, Route132_Text_GilbertIntro, Route132_Text_GilbertDefeat
# 7 "data/maps/Route132/scripts.pory"
	msgbox Route132_Text_GilbertPostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/Route132/scripts.pory"
	end
# 9 "data/maps/Route132/scripts.pory"

# 10 "data/maps/Route132/scripts.pory"
Route132_EventScript_Dana:: @ 81F7501
# 11 "data/maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_DANA, Route132_Text_DanaIntro, Route132_Text_DanaDefeat
# 12 "data/maps/Route132/scripts.pory"
	msgbox Route132_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/Route132/scripts.pory"
	end
# 14 "data/maps/Route132/scripts.pory"

# 15 "data/maps/Route132/scripts.pory"
Route132_EventScript_Ronald:: @ 81F7518
# 16 "data/maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_RONALD, Route132_Text_RonaldIntro, Route132_Text_RonaldDefeat
# 17 "data/maps/Route132/scripts.pory"
	msgbox Route132_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
# 18 "data/maps/Route132/scripts.pory"
	end
# 19 "data/maps/Route132/scripts.pory"

# 20 "data/maps/Route132/scripts.pory"
Route132_EventScript_Kiyo:: @ 81F752F
# 21 "data/maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_KIYO, Route132_Text_KiyoIntro, Route132_Text_KiyoDefeat
# 22 "data/maps/Route132/scripts.pory"
	msgbox Route132_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
# 23 "data/maps/Route132/scripts.pory"
	end
# 24 "data/maps/Route132/scripts.pory"

# 25 "data/maps/Route132/scripts.pory"
Route132_EventScript_Paxton:: @ 81F7546
# 26 "data/maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_PAXTON, Route132_Text_PaxtonIntro, Route132_Text_PaxtonDefeat
# 27 "data/maps/Route132/scripts.pory"
	msgbox Route132_Text_PaxtonPostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/Route132/scripts.pory"
	end
# 29 "data/maps/Route132/scripts.pory"

# 30 "data/maps/Route132/scripts.pory"
Route132_EventScript_Darcy:: @ 81F755D
# 31 "data/maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_DARCY, Route132_Text_DarcyIntro, Route132_Text_DarcyDefeat
# 32 "data/maps/Route132/scripts.pory"
	msgbox Route132_Text_DarcyPostBattle, MSGBOX_AUTOCLOSE
# 33 "data/maps/Route132/scripts.pory"
	end
# 34 "data/maps/Route132/scripts.pory"

# 35 "data/maps/Route132/scripts.pory"
Route132_EventScript_Jonathan:: @ 81F7574
# 36 "data/maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_JONATHAN, Route132_Text_JonathanIntro, Route132_Text_JonathanDefeat
# 37 "data/maps/Route132/scripts.pory"
	msgbox Route132_Text_JonathanPostBattle, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route132/scripts.pory"
	end
# 39 "data/maps/Route132/scripts.pory"

# 40 "data/maps/Route132/scripts.pory"
Route132_EventScript_Makayla:: @ 81F758B
# 41 "data/maps/Route132/scripts.pory"
	trainerbattle_single TRAINER_MAKAYLA, Route132_Text_MakaylaIntro, Route132_Text_MakaylaDefeat
# 42 "data/maps/Route132/scripts.pory"
	msgbox Route132_Text_MakaylaPostBattle, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route132/scripts.pory"
	end

Route132_EventScript_LegendaryNPC::
# 47 "data/maps/Route132/scripts.pory"
	lock
# 48 "data/maps/Route132/scripts.pory"
	faceplayer
# 49 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 51 "data/maps/Route132/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route132_EventScript_LegendaryNPC_2
# 76 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_LegendaryNPC_Text_4
Route132_EventScript_LegendaryNPC_1:
# 78 "data/maps/Route132/scripts.pory"
	release
	end

Route132_EventScript_LegendaryNPC_2:
# 52 "data/maps/Route132/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route132_EventScript_LegendaryNPC_5
# 60 "data/maps/Route132/scripts.pory"
	checktrainerflag TRAINER_MAKAYLA
	goto_if 1, Route132_EventScript_LegendaryNPC_11
Route132_EventScript_LegendaryNPC_9:
# 71 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_LegendaryNPC_Text_3
	goto Route132_EventScript_LegendaryNPC_1

Route132_EventScript_LegendaryNPC_5:
# 53 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_LegendaryNPC_Text_1
	goto Route132_EventScript_LegendaryNPC_1

Route132_EventScript_LegendaryNPC_8:
# 68 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_LegendaryNPC_Text_2
	goto Route132_EventScript_LegendaryNPC_1

Route132_EventScript_LegendaryNPC_10:
# 62 "data/maps/Route132/scripts.pory"
	checktrainerflag TRAINER_DARCY
	goto_if 1, Route132_EventScript_LegendaryNPC_15
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_11:
# 61 "data/maps/Route132/scripts.pory"
	checktrainerflag TRAINER_JONATHAN
	goto_if 1, Route132_EventScript_LegendaryNPC_10
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_14:
# 64 "data/maps/Route132/scripts.pory"
	checktrainerflag TRAINER_KIYO
	goto_if 1, Route132_EventScript_LegendaryNPC_19
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_15:
# 63 "data/maps/Route132/scripts.pory"
	checktrainerflag TRAINER_PAXTON
	goto_if 1, Route132_EventScript_LegendaryNPC_14
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_18:
# 66 "data/maps/Route132/scripts.pory"
	checktrainerflag TRAINER_DANA
	goto_if 1, Route132_EventScript_LegendaryNPC_22
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_19:
# 65 "data/maps/Route132/scripts.pory"
	checktrainerflag TRAINER_RONALD
	goto_if 1, Route132_EventScript_LegendaryNPC_18
	goto Route132_EventScript_LegendaryNPC_9

Route132_EventScript_LegendaryNPC_22:
# 67 "data/maps/Route132/scripts.pory"
	checktrainerflag TRAINER_GILBERT
	goto_if 1, Route132_EventScript_LegendaryNPC_8
	goto Route132_EventScript_LegendaryNPC_9


Route132_EventScript_Gyarados::
# 83 "data/maps/Route132/scripts.pory"
	lock
# 84 "data/maps/Route132/scripts.pory"
	faceplayer
# 85 "data/maps/Route132/scripts.pory"
	goto_if_set FLAG_DEFEATED_ROUTE132_GYARADOS, Route132_EventScript_Gyarados_Join
# 86 "data/maps/Route132/scripts.pory"
	goto_if_unset FLAG_BADGE07_GET, Route132_EventScript_Gyarados_PreTateLiza
# 87 "data/maps/Route132/scripts.pory"
	playmoncry SPECIES_GYARADOS, 2
# 88 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_Gyarados_Text_0, MSGBOX_YESNO
# 89 "data/maps/Route132/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route132_EventScript_Gyarados_2
# 126 "data/maps/Route132/scripts.pory"
	playmoncry SPECIES_GYARADOS, 2
# 127 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_Gyarados_Text_3, MSGBOX_DEFAULT
Route132_EventScript_Gyarados_1:
# 129 "data/maps/Route132/scripts.pory"
	release
	end

Route132_EventScript_Gyarados_2:
# 90 "data/maps/Route132/scripts.pory"
	playmoncry SPECIES_GYARADOS, 2
# 91 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_Gyarados_Text_1, MSGBOX_DEFAULT
# 92 "data/maps/Route132/scripts.pory"
	delay 40
# 93 "data/maps/Route132/scripts.pory"
	waitmoncry
# 94 "data/maps/Route132/scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 95 "data/maps/Route132/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ATK_BOOST, 0
# 96 "data/maps/Route132/scripts.pory"
	setvar VAR_TOTEM_POKEMON_DEF_BOOST, 3
# 97 "data/maps/Route132/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_ATK_BOOST, 1
# 98 "data/maps/Route132/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SP_DEF_BOOST, 3
# 99 "data/maps/Route132/scripts.pory"
	setvar VAR_TOTEM_POKEMON_SPEED_BOOST, 1
# 100 "data/maps/Route132/scripts.pory"
	setvar VAR_TOTEM_POKEMON_ACCURACY_BOOST, 2
# 101 "data/maps/Route132/scripts.pory"
	setvar VAR_TOTEM_POKEMON_EVASION_BOOST, 0
# 102 "data/maps/Route132/scripts.pory"
	setvar VAR_TOTEM_MESSAGE, TOTEM_FIGHT_GYARADOS
# 103 "data/maps/Route132/scripts.pory"
	setflag FLAG_SHINY_CREATION
# 104 "data/maps/Route132/scripts.pory"
	setwildbattlewithcustommoves SPECIES_GYARADOS, 0, ITEM_GYARADOSITE_Y, MOVE_BOOMBURST, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HURRICANE, 0, NATURE_TIMID, 252, 252, 252, 252, 252, 252
# 105 "data/maps/Route132/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 106 "data/maps/Route132/scripts.pory"
	dowildbattle
# 107 "data/maps/Route132/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 108 "data/maps/Route132/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 109 "data/maps/Route132/scripts.pory"
	switch VAR_RESULT
# 110 "data/maps/Route132/scripts.pory"
	case B_OUTCOME_CAUGHT, Route132_EventScript_Gyarados_6
# 111 "data/maps/Route132/scripts.pory"
	case B_OUTCOME_WON, Route132_EventScript_Gyarados_6
# 114 "data/maps/Route132/scripts.pory"
	case B_OUTCOME_RAN, Route132_EventScript_Gyarados_7
# 115 "data/maps/Route132/scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Route132_EventScript_Gyarados_7
	goto Route132_EventScript_Gyarados_1

Route132_EventScript_Gyarados_6:
# 112 "data/maps/Route132/scripts.pory"
	goto Route132_EventScript_Gyarados_Join
	goto Route132_EventScript_Gyarados_1

Route132_EventScript_Gyarados_7:
# 116 "data/maps/Route132/scripts.pory"
	setvar VAR_0x8004, SPECIES_GYARADOS
# 117 "data/maps/Route132/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 118 "data/maps/Route132/scripts.pory"
	removeobject VAR_LAST_TALKED
# 119 "data/maps/Route132/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 120 "data/maps/Route132/scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 121 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_Gyarados_Text_2, MSGBOX_DEFAULT
	goto Route132_EventScript_Gyarados_1


Route132_EventScript_Gyarados_PreTateLiza::
# 134 "data/maps/Route132/scripts.pory"
	message Route132_EventScript_Gyarados_PreTateLiza_Text_0
# 135 "data/maps/Route132/scripts.pory"
	release
	end


Route132_EventScript_Gyarados_Join::
# 140 "data/maps/Route132/scripts.pory"
	msgbox Route132_EventScript_Gyarados_Join_Text_0, MSGBOX_YESNO
# 141 "data/maps/Route132/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route132_EventScript_Gyarados_Join_2
Route132_EventScript_Gyarados_Join_1:
# 151 "data/maps/Route132/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ROUTE132_GYARADOS, Route132_EventScript_Gyarados_Join_5
Route132_EventScript_Gyarados_Join_4:
# 158 "data/maps/Route132/scripts.pory"
	release
	end

Route132_EventScript_Gyarados_Join_2:
# 142 "data/maps/Route132/scripts.pory"
	setflag FLAG_OBTAINED_ROUTE132_GYARADOS
# 143 "data/maps/Route132/scripts.pory"
	givecustommon SPECIES_GYARADOS, 50, ITEM_NONE, ITEM_CHERISH_BALL, NATURE_TIMID, 0, 252, 0, 0, 4, 252, 0, 0, 0, 0, 0, 0, 0, MOVE_BOOMBURST, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_HURRICANE, TRUE
# 144 "data/maps/Route132/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 145 "data/maps/Route132/scripts.pory"
	message Route132_EventScript_Gyarados_Join_Text_1
# 146 "data/maps/Route132/scripts.pory"
	waitfanfare
# 147 "data/maps/Route132/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 148 "data/maps/Route132/scripts.pory"
	removeobject VAR_LAST_TALKED
# 149 "data/maps/Route132/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Route132_EventScript_Gyarados_Join_1

Route132_EventScript_Gyarados_Join_5:
# 152 "data/maps/Route132/scripts.pory"
	setflag FLAG_DEFEATED_ROUTE132_GYARADOS
# 153 "data/maps/Route132/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 154 "data/maps/Route132/scripts.pory"
	giveitem ITEM_GYARADOSITE_Y, 1
# 155 "data/maps/Route132/scripts.pory"
	message Route132_EventScript_Gyarados_Join_Text_2
# 156 "data/maps/Route132/scripts.pory"
	waitfanfare
	goto Route132_EventScript_Gyarados_Join_4


Route132_EventScript_LegendaryNPC_Text_0:
# 49 "data/maps/Route132/scripts.pory"
	.string "Sage: I stand as the gatekeeper to the\n"
	.string "resting place of the Ultra Beasts. Make\l"
	.string "no mistake: despite still wearing the\l"
	.string "battle scars inflicted upon them by\l"
	.string "King Calyrex and the Tapus, they\l"
	.string "possess an immense power, so tread with\l"
	.string "caution in their presence.\p"
	.string "Do you want to know how they got here?$"

Route132_EventScript_LegendaryNPC_Text_1:
# 53 "data/maps/Route132/scripts.pory"
	.string "The Ultra Beasts are creatures coming\n"
	.string "from worlds outside our galaxy. They\l"
	.string "came to Earth not by choice,\p"
	.string "but necessity: Necrozma's hunger\n"
	.string "didn't spare their planets, so they\l"
	.string "roamed until they found a hospitable\l"
	.string "place to live.\p"
	.string "Those who didn't immediately flee were\n"
	.string "either consumed or turned into soldiers\l"
	.string "for Necrozma's galactic army. Many of\l"
	.string "these\p"
	.string "Ultra Beasts perished in the war waged\n"
	.string "on them by the Tapus and King Calyrex,\l"
	.string "but it looks like some have survived by\l"
	.string "hiding in these small islands.\p"
	.string "These creatures suffered a lot in their\n"
	.string "life, I think they deserve a guardian to\l"
	.string "take care of them. Your heart seems in\l"
	.string "the right place. Once you'll be worthy\l"
	.string "of them, return to me.\p"
	.string "$"

Route132_EventScript_LegendaryNPC_Text_2:
# 68 "data/maps/Route132/scripts.pory"
	.string "Your heart is in the right place, and\n"
	.string "your strength is the one of a great\l"
	.string "trainer. I added the location of some of\l"
	.string "the Ultra Beasts in your DexNav. There\l"
	.string "might be more in other routes, too: try\l"
	.string "to catch them all!$"

Route132_EventScript_LegendaryNPC_Text_3:
# 71 "data/maps/Route132/scripts.pory"
	.string "You have demonstrated great strenght\n"
	.string "so far. But I want to see it with my\l"
	.string "eyes! Defeat these last few trainers,\l"
	.string "and I'll show you the place where the\l"
	.string "Ultra Beasts reside.$"

Route132_EventScript_LegendaryNPC_Text_4:
# 76 "data/maps/Route132/scripts.pory"
	.string "Stay safe out there.$"

Route132_EventScript_Gyarados_Text_0:
# 88 "data/maps/Route132/scripts.pory"
	.string "Gyarados locks eyes with you, its\n"
	.string "challenging stare conveying a clear\l"
	.string "invitation to a fierce battle. Do you\l"
	.string "possess the courage to accept the\l"
	.string "challenge?$"

Route132_EventScript_Gyarados_Text_1:
# 91 "data/maps/Route132/scripts.pory"
	.string "Gyarados: Gyara!$"

Route132_EventScript_Gyarados_Text_2:
# 121 "data/maps/Route132/scripts.pory"
	.string "The {STR_VAR_1} ran away!$"

Route132_EventScript_Gyarados_Text_3:
# 127 "data/maps/Route132/scripts.pory"
	.string "Gyarados: Gyara...$"

Route132_EventScript_Gyarados_PreTateLiza_Text_0:
# 134 "data/maps/Route132/scripts.pory"
	.string "Gyarados gazes past you, as though\n"
	.string "you're invisible, suggesting that you\l"
	.string "may want to come back when you possess\l"
	.string "the strength to rival its presence.{PAUSE_UNTIL_PRESS}$"

Route132_EventScript_Gyarados_Join_Text_0:
# 140 "data/maps/Route132/scripts.pory"
	.string "Gyarados seems to want to join your\n"
	.string "team, will you let this Gyarados join\l"
	.string "you?$"

Route132_EventScript_Gyarados_Join_Text_1:
# 145 "data/maps/Route132/scripts.pory"
	.string "{PLAYER} received a Gyarados!$"

Route132_EventScript_Gyarados_Join_Text_2:
# 155 "data/maps/Route132/scripts.pory"
	.string "{PLAYER} received a Gyaradosite Y!$"
