# 1 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 2 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_MapScripts:: @ 82380A5
# 3 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	.byte 0
# 4 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 5 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_EventScript_Spiritomb::
# 6 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	lock
# 7 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	checkPartyHasSpecies SPECIES_LICKITUNG
# 8 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 9 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_eq AbandonedShip_Room_B1F_EventScript_CheckOddKeystone
# 10 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	checkPartyHasSpecies SPECIES_SLUGMA
# 11 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	compare VAR_RESULT, TRUE
# 12 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_eq AbandonedShip_Room_B1F_EventScript_CheckOddKeystone
# 13 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_EventScript_ItsEmpty::
# 14 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	msgbox Text_EmptyTrashCan, MSGBOX_DEFAULT
# 15 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	closemessage
# 16 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	release
# 17 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	end
# 18 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 19 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_EventScript_CheckOddKeystone::
# 20 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	checkitem ITEM_ODD_KEYSTONE, 1
# 21 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 22 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_eq AbandonedShip_Room_B1F_EventScript_ItsEmpty
# 23 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	msgbox AbandonedShip_Room_B1F_Text_PutKeystoneInTrash, MSGBOX_YESNO
# 24 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	compare VAR_RESULT, NO
# 25 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_eq AbandonedShip_Room_B1F_EventScript_End
# 26 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	closemessage
# 27 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	removeitem ITEM_ODD_KEYSTONE, 1
# 28 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 29 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 30 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setwildbattle SPECIES_SPIRITOMB, VAR_0x800A, ITEM_SMOKE_BALL
# 31 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	waitse
# 32 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	playmoncry SPECIES_SPIRITOMB, 2
# 33 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	delay 40
# 34 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	waitmoncry
# 35 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	dowildbattle
# 36 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	release
# 37 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	end
# 38 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 39 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_EventScript_End::
# 40 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	closemessage
# 41 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	release
# 42 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	end
# 43 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 44 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_Text_PutKeystoneInTrash:
# 45 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	.string "Something is compelling you to toss\n"
# 46 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	.string "the Odd Keystone into this trash can.\p"
# 47 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	.string "Trash the Odd Keystone?$"
