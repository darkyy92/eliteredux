# 1 "data/maps/CaveOfOrigin_1F/scripts.pory"

# 2 "data/maps/CaveOfOrigin_1F/scripts.pory"
CaveOfOrigin_1F_MapScripts:: @ 8235768
# 3 "data/maps/CaveOfOrigin_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_1F_OnTransition
# 4 "data/maps/CaveOfOrigin_1F/scripts.pory"
	.byte 0
# 5 "data/maps/CaveOfOrigin_1F/scripts.pory"

# 6 "data/maps/CaveOfOrigin_1F/scripts.pory"
CaveOfOrigin_1F_OnTransition: @ 823576E
# 7 "data/maps/CaveOfOrigin_1F/scripts.pory"
	call_if_set FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE, CaveOfOrigin_EventScript_DisableTriggers
# 8 "data/maps/CaveOfOrigin_1F/scripts.pory"
	end
# 9 "data/maps/CaveOfOrigin_1F/scripts.pory"

# 10 "data/maps/CaveOfOrigin_1F/scripts.pory"
CaveOfOrigin_1F_EventScript_Carbink::
# 11 "data/maps/CaveOfOrigin_1F/scripts.pory"
	lock
# 12 "data/maps/CaveOfOrigin_1F/scripts.pory"
	playmoncry  SPECIES_CARBINK, 2
# 13 "data/maps/CaveOfOrigin_1F/scripts.pory"
	waitmoncry
# 14 "data/maps/CaveOfOrigin_1F/scripts.pory"
	msgbox CaveOfOrigin_1F_Text_CarbinkStuck, MSGBOX_DEFAULT
# 15 "data/maps/CaveOfOrigin_1F/scripts.pory"
	closemessage
# 16 "data/maps/CaveOfOrigin_1F/scripts.pory"
	release
# 17 "data/maps/CaveOfOrigin_1F/scripts.pory"
	end
# 18 "data/maps/CaveOfOrigin_1F/scripts.pory"

# 19 "data/maps/CaveOfOrigin_1F/scripts.pory"
CaveOfOrigin_1F_Text_CarbinkStuck:
# 20 "data/maps/CaveOfOrigin_1F/scripts.pory"
	.string "This Carbink seems to be stuck,\n"
# 21 "data/maps/CaveOfOrigin_1F/scripts.pory"
	.string "and it's blocking the ladder.\p"
# 22 "data/maps/CaveOfOrigin_1F/scripts.pory"
	.string "Better check back later!$"
