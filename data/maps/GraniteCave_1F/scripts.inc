# 1 "data/maps/GraniteCave_1F/scripts.pory"

# 2 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_MapScripts:: @ 822DA5D
# 3 "data/maps/GraniteCave_1F/scripts.pory"
	.byte 0
# 4 "data/maps/GraniteCave_1F/scripts.pory"

# 5 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_EventScript_Hiker:: @ 822DA5E
# 6 "data/maps/GraniteCave_1F/scripts.pory"
	lock
# 7 "data/maps/GraniteCave_1F/scripts.pory"
	faceplayer
# 8 "data/maps/GraniteCave_1F/scripts.pory"
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
# 9 "data/maps/GraniteCave_1F/scripts.pory"
	setflag FLAG_RECEIVED_HM05
# 10 "data/maps/GraniteCave_1F/scripts.pory"
	release
# 11 "data/maps/GraniteCave_1F/scripts.pory"
	end
# 12 "data/maps/GraniteCave_1F/scripts.pory"

# 13 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_EventScript_ReceivedFlash:: @ 822DA8A
# 14 "data/maps/GraniteCave_1F/scripts.pory"
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
# 15 "data/maps/GraniteCave_1F/scripts.pory"
	release
# 16 "data/maps/GraniteCave_1F/scripts.pory"
	end
# 17 "data/maps/GraniteCave_1F/scripts.pory"

# 18 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_Text_GetsDarkAheadHereYouGo: @ 822DA94
# 19 "data/maps/GraniteCave_1F/scripts.pory"
	.string "Hey, you.\n"
# 20 "data/maps/GraniteCave_1F/scripts.pory"
	.string "It used to be dark in here.\l"
# 21 "data/maps/GraniteCave_1F/scripts.pory"
	.string "But it's not anymore.\p"
# 22 "data/maps/GraniteCave_1F/scripts.pory"
	.string "Have fun exploring!$"
# 23 "data/maps/GraniteCave_1F/scripts.pory"

# 24 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_Text_ExplainFlash: @ 822DBB7
# 25 "data/maps/GraniteCave_1F/scripts.pory"
	.string "Teach that hidden move Flash to\n"
# 26 "data/maps/GraniteCave_1F/scripts.pory"
	.string "a Pokémon and use it.\p"
# 27 "data/maps/GraniteCave_1F/scripts.pory"
	.string "It lights up even the inky darkness\n"
# 28 "data/maps/GraniteCave_1F/scripts.pory"
	.string "of caves.\p"
# 29 "data/maps/GraniteCave_1F/scripts.pory"
	.string "But, to use it, you need the Gym Badge\n"
# 30 "data/maps/GraniteCave_1F/scripts.pory"
	.string "from Dewford's Pokémon Gym.$"
