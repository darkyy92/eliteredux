# 1 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 2 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_MapScripts:: @ 823896C
# 3 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_HiddenFloorCorridors_OnResume
# 4 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorCorridors_OnLoad
# 5 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.byte 0
# 6 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 7 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_OnResume: @ 8238977
# 8 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 255, 5, 4
# 9 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 10 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 11 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_OnLoad: @ 8238980
# 12 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_unset FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1
# 13 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_unset FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2
# 14 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_unset FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4
# 15 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_unset FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6
# 16 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
# 17 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
# 18 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
# 19 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
# 20 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 21 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 22 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1:: @ 82389C9
# 23 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, 1
# 24 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 25 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 26 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2:: @ 82389D3
# 27 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, 1
# 28 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 29 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 30 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4:: @ 82389DD
# 31 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Unlocked, 0
# 32 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 33 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 34 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6:: @ 82389E7
# 35 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Unlocked, 0
# 36 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 37 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 38 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1:: @ 82389F1
# 39 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, 1
# 40 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 41 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 42 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2:: @ 82389FB
# 43 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, 1
# 44 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 45 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 46 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4:: @ 8238A05
# 47 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Locked, 0
# 48 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 49 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 50 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6:: @ 8238A0F
# 51 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Locked, 0
# 52 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	return
# 53 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 54 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Room1Door:: @ 8238A19
# 55 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	lockall
# 56 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
# 57 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	checkitem ITEM_ROOM_1_KEY, 1
# 58 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	compare VAR_RESULT, FALSE
# 59 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked
# 60 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
# 61 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	playse SE_PIN
# 62 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	removeitem ITEM_ROOM_1_KEY
# 63 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setflag FLAG_USED_ROOM_1_KEY
# 64 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
# 65 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	special DrawWholeMapView
# 66 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 67 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 68 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 69 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Room2Door:: @ 8238A50
# 70 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	lockall
# 71 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
# 72 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	checkitem ITEM_ROOM_2_KEY, 1
# 73 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	compare VAR_RESULT, FALSE
# 74 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked
# 75 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
# 76 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	playse SE_PIN
# 77 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	removeitem ITEM_ROOM_2_KEY
# 78 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setflag FLAG_USED_ROOM_2_KEY
# 79 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
# 80 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	special DrawWholeMapView
# 81 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 82 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 83 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 84 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Room4Door:: @ 8238A87
# 85 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	lockall
# 86 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
# 87 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	checkitem ITEM_ROOM_4_KEY, 1
# 88 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	compare VAR_RESULT, FALSE
# 89 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked
# 90 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
# 91 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	playse SE_PIN
# 92 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	removeitem ITEM_ROOM_4_KEY
# 93 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setflag FLAG_USED_ROOM_4_KEY
# 94 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
# 95 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	special DrawWholeMapView
# 96 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 97 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 98 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 99 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Room6Door:: @ 8238ABE
# 100 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	lockall
# 101 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
# 102 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	checkitem ITEM_ROOM_6_KEY, 1
# 103 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	compare VAR_RESULT, FALSE
# 104 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked
# 105 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
# 106 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	playse SE_PIN
# 107 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	removeitem ITEM_ROOM_6_KEY
# 108 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	setflag FLAG_USED_ROOM_6_KEY
# 109 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
# 110 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	special DrawWholeMapView
# 111 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 112 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 113 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 114 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked:: @ 8238AF5
# 115 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked, MSGBOX_DEFAULT
# 116 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 117 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 118 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 119 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked:: @ 8238AFF
# 120 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked, MSGBOX_DEFAULT
# 121 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 122 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 123 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 124 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked:: @ 8238B09
# 125 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked, MSGBOX_DEFAULT
# 126 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 127 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 128 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 129 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked:: @ 8238B13
# 130 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked, MSGBOX_DEFAULT
# 131 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 132 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 133 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 134 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen:: @ 8238B1D
# 135 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
# 136 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	releaseall
# 137 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	end
# 138 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 139 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked: @ 8238B27
# 140 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The door is locked.\p"
# 141 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "“RM. 1” is painted on the door.$"
# 142 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 143 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked: @ 8238B5B
# 144 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The door is locked.\p"
# 145 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "“RM. 2” is painted on the door.$"
# 146 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 147 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked: @ 8238B8F
# 148 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The door is locked.\p"
# 149 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "“RM. 4” is painted on the door.$"
# 150 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 151 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked: @ 8238BC3
# 152 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The door is locked.\p"
# 153 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "“RM. 6” is painted on the door.$"
# 154 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"

# 155 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
AbandonedShip_HiddenFloorCorridors_Text_InsertedKey: @ 8238BF7
# 156 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "{PLAYER} inserted and turned the\n"
# 157 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "KEY.\p"
# 158 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "The inserted Key stuck fast,\n"
# 159 "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.pory"
	.string "but the door opened.$"
