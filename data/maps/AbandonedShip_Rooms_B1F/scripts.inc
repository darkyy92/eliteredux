# 1 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"

# 2 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
AbandonedShip_Rooms_B1F_MapScripts:: @ 8237FB7
# 3 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_OnResume
# 4 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	.byte 0
# 5 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"

# 6 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
AbandonedShip_Rooms_B1F_OnResume: @ 8237FBD
# 7 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 255, 17, 4
# 8 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	end
# 9 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"

# 10 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
AbandonedShip_Rooms_B1F_EventScript_FatMan:: @ 8237FC6
# 11 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	msgbox AbandonedShip_Rooms_B1F_Text_GettingQueasy, MSGBOX_NPC
# 12 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	end
# 13 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"

# 14 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
AbandonedShip_Rooms_B1F_Text_GettingQueasy: @ 8237FCF
# 15 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	.string "Urrrrppp…\p"
# 16 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	.string "I'm getting queasy just being aboard\n"
# 17 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	.string "this ship…\p"
# 18 "data/maps/AbandonedShip_Rooms_B1F/scripts.pory"
	.string "It's not even moving, but…$"
