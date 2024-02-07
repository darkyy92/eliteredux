# 1 "data/maps/PacifidlogTown_House5/scripts.pory"

# 2 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_MapScripts:: @ 8204110
# 3 "data/maps/PacifidlogTown_House5/scripts.pory"
	.byte 0
# 4 "data/maps/PacifidlogTown_House5/scripts.pory"

# 5 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_EventScript_MirageIslandWatcher:: @ 8204111
# 6 "data/maps/PacifidlogTown_House5/scripts.pory"
	lock
# 7 "data/maps/PacifidlogTown_House5/scripts.pory"
	faceplayer
# 8 "data/maps/PacifidlogTown_House5/scripts.pory"
	specialvar VAR_RESULT, IsMirageIslandPresent
# 9 "data/maps/PacifidlogTown_House5/scripts.pory"
	compare VAR_RESULT, TRUE
# 10 "data/maps/PacifidlogTown_House5/scripts.pory"
	goto_if_eq PacifidlogTown_House5_EventScript_MirageIslandPresent
# 11 "data/maps/PacifidlogTown_House5/scripts.pory"
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
# 12 "data/maps/PacifidlogTown_House5/scripts.pory"
	release
# 13 "data/maps/PacifidlogTown_House5/scripts.pory"
	end
# 14 "data/maps/PacifidlogTown_House5/scripts.pory"

# 15 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_EventScript_MirageIslandPresent:: @ 820412D
# 16 "data/maps/PacifidlogTown_House5/scripts.pory"
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
# 17 "data/maps/PacifidlogTown_House5/scripts.pory"
	release
# 18 "data/maps/PacifidlogTown_House5/scripts.pory"
	end
# 19 "data/maps/PacifidlogTown_House5/scripts.pory"

# 20 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_EventScript_Gentleman:: @ 8204137
# 21 "data/maps/PacifidlogTown_House5/scripts.pory"
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
# 22 "data/maps/PacifidlogTown_House5/scripts.pory"
	end
# 23 "data/maps/PacifidlogTown_House5/scripts.pory"

# 24 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_Text_CantSeeMirageIslandToday: @ 8204140
# 25 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "I can't see Mirage Island today…$"
# 26 "data/maps/PacifidlogTown_House5/scripts.pory"

# 27 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_Text_CanSeeMirageIslandToday: @ 8204161
# 28 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "Oh! Oh my!\n"
# 29 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "I can see Mirage Island today!$"
# 30 "data/maps/PacifidlogTown_House5/scripts.pory"

# 31 "data/maps/PacifidlogTown_House5/scripts.pory"
PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather: @ 820418B
# 32 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "Mirage Island…\p"
# 33 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "It must become visible and invisible\n"
# 34 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "depending on the weather conditions\l"
# 35 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "that make mirages appear.\p"
# 36 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "Or is it really appearing and\n"
# 37 "data/maps/PacifidlogTown_House5/scripts.pory"
	.string "disappearing?$"
