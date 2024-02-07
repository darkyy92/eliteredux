# 1 "data/maps/Route119_House/scripts.pory"

# 2 "data/maps/Route119_House/scripts.pory"
Route119_House_MapScripts:: @ 8270965
# 3 "data/maps/Route119_House/scripts.pory"
	.byte 0
# 4 "data/maps/Route119_House/scripts.pory"

# 5 "data/maps/Route119_House/scripts.pory"
Route119_House_EventScript_Woman:: @ 8270966
# 6 "data/maps/Route119_House/scripts.pory"
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
# 7 "data/maps/Route119_House/scripts.pory"
	end
# 8 "data/maps/Route119_House/scripts.pory"

# 9 "data/maps/Route119_House/scripts.pory"
Route119_House_EventScript_Wingull:: @ 827096F
# 10 "data/maps/Route119_House/scripts.pory"
	lock
# 11 "data/maps/Route119_House/scripts.pory"
	faceplayer
# 12 "data/maps/Route119_House/scripts.pory"
	waitse
# 13 "data/maps/Route119_House/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 14 "data/maps/Route119_House/scripts.pory"
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
# 15 "data/maps/Route119_House/scripts.pory"
	waitmoncry
# 16 "data/maps/Route119_House/scripts.pory"
	release
# 17 "data/maps/Route119_House/scripts.pory"
	end
# 18 "data/maps/Route119_House/scripts.pory"

# 19 "data/maps/Route119_House/scripts.pory"
Route119_House_Text_RumorAboutCaveOfOrigin: @ 8270982
# 20 "data/maps/Route119_House/scripts.pory"
	.string "I heard about a cave called the Cave\n"
# 21 "data/maps/Route119_House/scripts.pory"
	.string "of Origin.\p"
# 22 "data/maps/Route119_House/scripts.pory"
	.string "People rumor that the spirits of\n"
# 23 "data/maps/Route119_House/scripts.pory"
	.string "Pokémon are revived there. Could\l"
# 24 "data/maps/Route119_House/scripts.pory"
	.string "something like that really happen?$"
# 25 "data/maps/Route119_House/scripts.pory"

# 26 "data/maps/Route119_House/scripts.pory"
Route119_House_Text_Wingull: @ 8270A17
# 27 "data/maps/Route119_House/scripts.pory"
	.string "Wingull: Pihyoh!$"
