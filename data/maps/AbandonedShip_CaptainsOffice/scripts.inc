# 1 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"

# 2 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
AbandonedShip_CaptainsOffice_MapScripts:: @ 82387E1
# 3 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.byte 0
# 4 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"

# 5 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
AbandonedShip_CaptainsOffice_EventScript_CaptSternAide:: @ 82387E2
# 6 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	lock
# 7 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	faceplayer
# 8 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
# 9 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	checkitem ITEM_SCANNER, 1
# 10 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	compare VAR_RESULT, TRUE
# 11 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	goto_if_eq AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
# 12 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
# 13 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
# 14 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	release
# 15 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	end
# 16 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"

# 17 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner:: @ 8238810
# 18 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
# 19 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	release
# 20 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	end
# 21 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"

# 22 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus:: @ 823881A
# 23 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
# 24 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	release
# 25 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	end
# 26 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"

# 27 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner: @ 8238824
# 28 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "I'm investigating this ship on behalf\n"
# 29 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "of Capt. Stern.\p"
# 30 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "He also asked me to find a Scanner,\n"
# 31 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "but I haven't had any success…$"
# 32 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"

# 33 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner: @ 823889D
# 34 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "Oh! That's a Scanner!\p"
# 35 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "Listen, can I get you to deliver that\n"
# 36 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "to Capt. Stern?\p"
# 37 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "I want to investigate this ship a\n"
# 38 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "little more.$"
# 39 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"

# 40 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus: @ 8238918
# 41 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "This ship is called S.S. Cactus.\n"
# 42 "data/maps/AbandonedShip_CaptainsOffice/scripts.pory"
	.string "It seems to be from an earlier era.$"
