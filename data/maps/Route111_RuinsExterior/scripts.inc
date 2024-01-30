# 1 "data/maps/Route111_RuinsExterior/scripts.pory"

# 2 "data/maps/Route111_RuinsExterior/scripts.pory"
Route111_RuinsExterior_MapScripts::
# 3 "data/maps/Route111_RuinsExterior/scripts.pory"
	.byte 0

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle::
# 7 "data/maps/Route111_RuinsExterior/scripts.pory"
	lock
# 8 "data/maps/Route111_RuinsExterior/scripts.pory"
	faceplayer
# 9 "data/maps/Route111_RuinsExterior/scripts.pory"
	goto_if_set FLAG_BADGE05_GET, Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_2
# 30 "data/maps/Route111_RuinsExterior/scripts.pory"
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_6, MSGBOX_NPC
Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_1:
# 32 "data/maps/Route111_RuinsExterior/scripts.pory"
	release
	end

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_2:
# 11 "data/maps/Route111_RuinsExterior/scripts.pory"
	checktrainerflag TRAINER_KROOKODILENITE_ROUTE111_RUINS_EXTERIOR
	goto_if 0, Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_5
# 26 "data/maps/Route111_RuinsExterior/scripts.pory"
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_5, MSGBOX_NPC
	goto Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_1

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_5:
# 12 "data/maps/Route111_RuinsExterior/scripts.pory"
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_0, MSGBOX_YESNO
# 13 "data/maps/Route111_RuinsExterior/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_8
# 22 "data/maps/Route111_RuinsExterior/scripts.pory"
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_4, MSGBOX_NPC
	goto Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_1

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_8:
# 14 "data/maps/Route111_RuinsExterior/scripts.pory"
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_1, MSGBOX_NPC
# 15 "data/maps/Route111_RuinsExterior/scripts.pory"
	trainerbattle_no_intro TRAINER_KROOKODILENITE_ROUTE111_RUINS_EXTERIOR, Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_2
# 16 "data/maps/Route111_RuinsExterior/scripts.pory"
	msgbox Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_3, MSGBOX_NPC
# 17 "data/maps/Route111_RuinsExterior/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 18 "data/maps/Route111_RuinsExterior/scripts.pory"
	giveitem ITEM_KROOKODILENITE, 1
# 19 "data/maps/Route111_RuinsExterior/scripts.pory"
	waitmessage
	goto Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_1


Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_0:
# 12 "data/maps/Route111_RuinsExterior/scripts.pory"
	.string "Hmm, searching for something\n"
	.string "interesting, are we? I've already\l"
	.string "claimed this site, but I see spirit in\l"
	.string "you. Prove me right, and I'll reward you\l"
	.string "with something nice I've dug up.$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_1:
# 14 "data/maps/Route111_RuinsExterior/scripts.pory"
	.string "Let's get to it then!$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_2:
# 15 "data/maps/Route111_RuinsExterior/scripts.pory"
	.string "Ha, these old eyes never lie to me.$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_3:
# 16 "data/maps/Route111_RuinsExterior/scripts.pory"
	.string "I knew I saw something great in you!\n"
	.string "Take this, and get out of here before\l"
	.string "you get footprints on my dig!$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_4:
# 22 "data/maps/Route111_RuinsExterior/scripts.pory"
	.string "Such a shame, come back when you're\n"
	.string "ready to get your hands dirty!$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_5:
# 26 "data/maps/Route111_RuinsExterior/scripts.pory"
	.string "Your persistence is admirable, young\n"
	.string "one, yet fruitless. My treasures have\l"
	.string "been exhausted. Find your fortune\l"
	.string "elsewhere, and leave this hollow\l"
	.string "sanctum to rest undisturbed.$"

Route111_Ruins_Exterior_EventScript_Krookodilenite_Battle_Text_6:
# 30 "data/maps/Route111_RuinsExterior/scripts.pory"
	.string "What's this? A young explorer scurrying\n"
	.string "onto my site? Run along chap, maybe I'll\l"
	.string "entertain you when you're stronger.$"
