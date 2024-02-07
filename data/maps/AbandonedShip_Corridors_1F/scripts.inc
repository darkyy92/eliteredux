# 1 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"

# 2 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
AbandonedShip_Corridors_1F_MapScripts:: @ 82379A4
# 3 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.byte 0
# 4 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"

# 5 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
AbandonedShip_Corridors_1F_EventScript_Youngster:: @ 82379A5
# 6 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
# 7 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	end
# 8 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"

# 9 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
AbandonedShip_Corridors_1F_EventScript_Charlie:: @ 82379AE
# 10 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
# 11 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
# 12 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	end
# 13 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"

# 14 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
AbandonedShip_Corridors_1F_Text_CharlieIntro: @ 82379C5
# 15 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "What's so funny about having my inner\n"
# 16 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "tube aboard the ship?$"
# 17 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"

# 18 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
AbandonedShip_Corridors_1F_Text_CharlieDefeat: @ 8237A01
# 19 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "Whoa, you overwhelmed me!$"
# 20 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"

# 21 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
AbandonedShip_Corridors_1F_Text_CharliePostBattle: @ 8237A1B
# 22 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "It's not easy throwing Poké Balls\n"
# 23 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "while hanging on to an inner tube!$"
# 24 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"

# 25 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
AbandonedShip_Corridors_1F_Text_IsntItFunHere: @ 8237A60
# 26 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "Isn't it fun here?\n"
# 27 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "I get excited just being here!$"
