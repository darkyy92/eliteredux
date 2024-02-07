# 1 "data/maps/Route131/scripts.pory"

# 2 "data/maps/Route131/scripts.pory"
Route131_MapScripts:: @ 81F7404
# 3 "data/maps/Route131/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route131_OnTransition
# 4 "data/maps/Route131/scripts.pory"
	.byte 0
# 5 "data/maps/Route131/scripts.pory"

# 6 "data/maps/Route131/scripts.pory"
Route131_OnTransition: @ 81F740A
# 7 "data/maps/Route131/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 8 "data/maps/Route131/scripts.pory"
	call_if_ge Route131_EventScript_CheckSetAbnormalWeather
# 9 "data/maps/Route131/scripts.pory"
	call Route131_EventScript_SetLayout
# 10 "data/maps/Route131/scripts.pory"
	end
# 11 "data/maps/Route131/scripts.pory"

# 12 "data/maps/Route131/scripts.pory"
Route131_EventScript_SetLayout:: @ 81F741B
# 13 "data/maps/Route131/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE131_SKY_PILLAR
# 14 "data/maps/Route131/scripts.pory"
	return
# 15 "data/maps/Route131/scripts.pory"

# 16 "data/maps/Route131/scripts.pory"
Route131_EventScript_CheckSetAbnormalWeather:: @ 81F741F
# 17 "data/maps/Route131/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 18 "data/maps/Route131/scripts.pory"
	return
# 19 "data/maps/Route131/scripts.pory"

# 20 "data/maps/Route131/scripts.pory"
Route131_EventScript_Richard:: @ 81F7429
# 21 "data/maps/Route131/scripts.pory"
	trainerbattle_single TRAINER_RICHARD, Route131_Text_RichardIntro, Route131_Text_RichardDefeat
# 22 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_RichardPostBattle, MSGBOX_AUTOCLOSE
# 23 "data/maps/Route131/scripts.pory"
	end
# 24 "data/maps/Route131/scripts.pory"

# 25 "data/maps/Route131/scripts.pory"
Route131_EventScript_Herman:: @ 81F7440
# 26 "data/maps/Route131/scripts.pory"
	trainerbattle_single TRAINER_HERMAN, Route131_Text_HermanIntro, Route131_Text_HermanDefeat
# 27 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_HermanPostBattle, MSGBOX_AUTOCLOSE
# 28 "data/maps/Route131/scripts.pory"
	end
# 29 "data/maps/Route131/scripts.pory"

# 30 "data/maps/Route131/scripts.pory"
Route131_EventScript_Susie:: @ 81F7457
# 31 "data/maps/Route131/scripts.pory"
	trainerbattle_single TRAINER_SUSIE, Route131_Text_SusieIntro, Route131_Text_SusieDefeat
# 32 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
# 33 "data/maps/Route131/scripts.pory"
	end
# 34 "data/maps/Route131/scripts.pory"

# 35 "data/maps/Route131/scripts.pory"
Route131_EventScript_Kara:: @ 81F746E
# 36 "data/maps/Route131/scripts.pory"
	trainerbattle_single TRAINER_KARA, Route131_Text_KaraIntro, Route131_Text_KaraDefeat
# 37 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_KaraPostBattle, MSGBOX_AUTOCLOSE
# 38 "data/maps/Route131/scripts.pory"
	end
# 39 "data/maps/Route131/scripts.pory"

# 40 "data/maps/Route131/scripts.pory"
Route131_EventScript_Reli:: @ 81F7485
# 41 "data/maps/Route131/scripts.pory"
	trainerbattle_double TRAINER_RELI_AND_IAN, Route131_Text_ReliIntro, Route131_Text_ReliDefeat, Route131_Text_ReliNotEnoughMons
# 42 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
# 43 "data/maps/Route131/scripts.pory"
	end
# 44 "data/maps/Route131/scripts.pory"

# 45 "data/maps/Route131/scripts.pory"
Route131_EventScript_Ian:: @ 81F74A0
# 46 "data/maps/Route131/scripts.pory"
	trainerbattle_double TRAINER_RELI_AND_IAN, Route131_Text_IanIntro, Route131_Text_IanDefeat, Route131_Text_IanNotEnoughMons
# 47 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_IanPostBattle, MSGBOX_AUTOCLOSE
# 48 "data/maps/Route131/scripts.pory"
	end
# 49 "data/maps/Route131/scripts.pory"

# 50 "data/maps/Route131/scripts.pory"
Route131_EventScript_Talia:: @ 81F74BB
# 51 "data/maps/Route131/scripts.pory"
	trainerbattle_single TRAINER_TALIA, Route131_Text_TaliaIntro, Route131_Text_TaliaDefeat
# 52 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_TaliaPostBattle, MSGBOX_AUTOCLOSE
# 53 "data/maps/Route131/scripts.pory"
	end
# 54 "data/maps/Route131/scripts.pory"

# 55 "data/maps/Route131/scripts.pory"
Route131_EventScript_Kevin:: @ 81F74D2
# 56 "data/maps/Route131/scripts.pory"
	trainerbattle_single TRAINER_KEVIN, Route131_Text_KevinIntro, Route131_Text_KevinDefeat
# 57 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_KevinPostBattle, MSGBOX_AUTOCLOSE
# 58 "data/maps/Route131/scripts.pory"
	end

Route131_EventScript_LegendaryNPC::
# 62 "data/maps/Route131/scripts.pory"
	lock
# 63 "data/maps/Route131/scripts.pory"
	faceplayer
# 64 "data/maps/Route131/scripts.pory"
	msgbox Route131_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 65 "data/maps/Route131/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route131_EventScript_LegendaryNPC_2
# 92 "data/maps/Route131/scripts.pory"
	msgbox Route131_EventScript_LegendaryNPC_Text_4
Route131_EventScript_LegendaryNPC_1:
# 94 "data/maps/Route131/scripts.pory"
	release
	end

Route131_EventScript_LegendaryNPC_2:
# 66 "data/maps/Route131/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route131_EventScript_LegendaryNPC_5
# 76 "data/maps/Route131/scripts.pory"
	checktrainerflag TRAINER_RICHARD
	goto_if 1, Route131_EventScript_LegendaryNPC_11
Route131_EventScript_LegendaryNPC_9:
# 87 "data/maps/Route131/scripts.pory"
	msgbox Route131_EventScript_LegendaryNPC_Text_3
	goto Route131_EventScript_LegendaryNPC_1

Route131_EventScript_LegendaryNPC_5:
# 67 "data/maps/Route131/scripts.pory"
	msgbox Route131_EventScript_LegendaryNPC_Text_1
	goto Route131_EventScript_LegendaryNPC_1

Route131_EventScript_LegendaryNPC_8:
# 83 "data/maps/Route131/scripts.pory"
	msgbox Route131_EventScript_LegendaryNPC_Text_2
	goto Route131_EventScript_LegendaryNPC_1

Route131_EventScript_LegendaryNPC_10:
# 78 "data/maps/Route131/scripts.pory"
	checktrainerflag TRAINER_SUSIE
	goto_if 1, Route131_EventScript_LegendaryNPC_15
	goto Route131_EventScript_LegendaryNPC_9

Route131_EventScript_LegendaryNPC_11:
# 77 "data/maps/Route131/scripts.pory"
	checktrainerflag TRAINER_HERMAN
	goto_if 1, Route131_EventScript_LegendaryNPC_10
	goto Route131_EventScript_LegendaryNPC_9

Route131_EventScript_LegendaryNPC_14:
# 80 "data/maps/Route131/scripts.pory"
	checktrainerflag TRAINER_RELI_AND_IAN
	goto_if 1, Route131_EventScript_LegendaryNPC_19
	goto Route131_EventScript_LegendaryNPC_9

Route131_EventScript_LegendaryNPC_15:
# 79 "data/maps/Route131/scripts.pory"
	checktrainerflag TRAINER_KARA
	goto_if 1, Route131_EventScript_LegendaryNPC_14
	goto Route131_EventScript_LegendaryNPC_9

Route131_EventScript_LegendaryNPC_18:
# 82 "data/maps/Route131/scripts.pory"
	checktrainerflag TRAINER_KEVIN
	goto_if 1, Route131_EventScript_LegendaryNPC_8
	goto Route131_EventScript_LegendaryNPC_9

Route131_EventScript_LegendaryNPC_19:
# 81 "data/maps/Route131/scripts.pory"
	checktrainerflag TRAINER_TALIA
	goto_if 1, Route131_EventScript_LegendaryNPC_18
	goto Route131_EventScript_LegendaryNPC_9


Route131_EventScript_LegendaryNPC_Text_0:
# 64 "data/maps/Route131/scripts.pory"
	.string "Sage: There's no time to explain, will\n"
	.string "you help us?$"

Route131_EventScript_LegendaryNPC_Text_1:
# 67 "data/maps/Route131/scripts.pory"
	.string "The influence of the Sky Pillar has\n"
	.string "attracted a nefarious invader from\l"
	.string "outer space:\p"
	.string "Necrozma, an alien creature whose\n"
	.string "hunger for light consumes everything\l"
	.string "that crosses their path.\p"
	.string "Hopping from planet to planet like a\n"
	.string "flock of hungry locusts, they only\l"
	.string "leave a trail of darkness and\l"
	.string "desolation behind.\p"
	.string "Their goal? Consuming the entire\n"
	.string "galaxy, turning those who inhabit\l"
	.string "subjugated planets into soldiers for\l"
	.string "his galactic army.\p"
	.string "Many worlds have already been consumed\n"
	.string "by their hunger, but we must put a stop\l"
	.string "to this!\p"
	.string "Me and my colleagues managed to\n"
	.string "temporarily stall him, but you must help\l"
	.string "us.\p"
	.string "You're already destined to become\n"
	.string "champion. Once you do, come back here\l"
	.string "and help us stop this disgrace from\l"
	.string "happening!$"

Route131_EventScript_LegendaryNPC_Text_2:
# 83 "data/maps/Route131/scripts.pory"
	.string "Great job with those trainers! Finally,\n"
	.string "we're ready to proceed: I marked\l"
	.string "Necrozma's location on your DexNav.\p"
	.string "The stakes couldn't be higher, but I'm\n"
	.string "sure you'll succeed in bringing this\l"
	.string "monster down!$"

Route131_EventScript_LegendaryNPC_Text_3:
# 87 "data/maps/Route131/scripts.pory"
	.string "Finally you came back! Before\n"
	.string "proceeding, make sure no one's getting\l"
	.string "caught in the crossfire: defeat all\l"
	.string "trainers in this route first!$"

Route131_EventScript_LegendaryNPC_Text_4:
# 92 "data/maps/Route131/scripts.pory"
	.string "No time to explain!$"
