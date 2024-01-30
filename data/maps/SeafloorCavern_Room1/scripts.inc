# 1 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 2 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_MapScripts:: @ 82347EB
# 3 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.byte 0
# 4 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 5 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_EventScript_Grunt1:: @ 82347EC
# 6 "data/maps/SeafloorCavern_Room1/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
# 7 "data/maps/SeafloorCavern_Room1/scripts.pory"
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 8 "data/maps/SeafloorCavern_Room1/scripts.pory"
	end
# 9 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 10 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_EventScript_Grunt2:: @ 8234803
# 11 "data/maps/SeafloorCavern_Room1/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
# 12 "data/maps/SeafloorCavern_Room1/scripts.pory"
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 13 "data/maps/SeafloorCavern_Room1/scripts.pory"
	end
# 14 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 15 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_Text_Grunt1Intro: @ 823481A
# 16 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "We don't need a kid around!\n"
# 17 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "Go on home already!$"
# 18 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 19 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_Text_Grunt1Defeat: @ 823484A
# 20 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "I want to go home…$"
# 21 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 22 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_Text_Grunt1PostBattle: @ 823485D
# 23 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "I want to get a promotion so I can\n"
# 24 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "boss around the Grunts…$"
# 25 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 26 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_Text_Grunt2Intro: @ 8234898
# 27 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "That submarine… It's tiny inside.\n"
# 28 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "I'm sore all over!$"
# 29 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 30 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_Text_Grunt2Defeat: @ 82348CD
# 31 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "Losing makes me sore!$"
# 32 "data/maps/SeafloorCavern_Room1/scripts.pory"

# 33 "data/maps/SeafloorCavern_Room1/scripts.pory"
SeafloorCavern_Room1_Text_Grunt2PostBattle: @ 82348E3
# 34 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "That submarine we jacked, man,\n"
# 35 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "it's brutal as a ride.\l"
# 36 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "It's way too tight in there!$"
