# 1 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 2 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
.set LOCALID_OLD_SEA_MAP, 2
# 3 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
.set LOCALID_BUG_CATCHER, 3
# 4 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
.set LOCALID_SHEDINJAITE, 4
# 5 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 6 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_MapScripts:: @ 8238C49
# 7 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorRooms_OnResume
# 8 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AbandonedShip_HiddenFloorRooms_OnFrame
# 9 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.byte 0
# 10 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 11 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_OnFrame: @ 8238C4F
# 12 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle
# 13 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.2byte 0
# 14 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 15 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
@ After the below calculation, VAR_TEMP_4 is the room number of the door the player entered
# 16 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
@ Bottom row, left column   (Rm 1)
# 17 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
@ Bottom row, middle column (Rm 2)
# 18 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
@ Bottom row, right column	(Rm 3)
# 19 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
@ Upper row,  left column   (Rm 4)
# 20 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
@ Upper row,  middle column (Rm 5)
# 21 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
@ Upper row,  right column  (Rm 6)
# 22 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle:: @ 8238C59
# 23 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setvar VAR_TEMP_1, 1
# 24 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
# 25 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setvar VAR_TEMP_4, 1
# 26 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_TEMP_2, 21
# 27 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn
# 28 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_TEMP_2, 36
# 29 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn
# 30 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_TEMP_3, 2
# 31 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow
# 32 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	switch VAR_TEMP_4
# 33 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	case 1, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1
# 34 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	case 2, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2
# 35 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	case 3, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3
# 36 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	case 4, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4
# 37 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	case 5, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5
# 38 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	case 6, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6
# 39 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 40 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 41 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn:: @ 8238CD1
# 42 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	addvar VAR_TEMP_4, 1
# 43 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	return
# 44 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 45 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn:: @ 8238CD7
# 46 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	addvar VAR_TEMP_4, 2
# 47 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	return
# 48 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 49 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow:: @ 8238CDD
# 50 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	addvar VAR_TEMP_4, 3
# 51 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	return
# 52 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 53 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1:: @ 8238CE3
# 54 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	delay 20
# 55 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 10, 10, 0
# 56 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	specialvar VAR_RESULT, FoundAbandonedShipRoom4Key
# 57 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_RESULT, FALSE
# 58 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle
# 59 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 60 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	delay 10
# 61 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 62 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 63 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2:: @ 8238D0C
# 64 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 65 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 66 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3:: @ 8238D0D
# 67 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	specialvar VAR_RESULT, FoundAbandonedShipRoom1Key
# 68 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_RESULT, TRUE
# 69 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	goto_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle
# 70 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	delay 20
# 71 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_RESULT, FALSE
# 72 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle
# 73 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 74 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	delay 10
# 75 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 76 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 77 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle:: @ 8238D32
# 78 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 79 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 80 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4:: @ 8238D33
# 81 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	delay 20
# 82 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 8, 5, 0
# 83 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 11, 3, 0
# 84 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	specialvar VAR_RESULT, FoundAbandonedShipRoom6Key
# 85 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_RESULT, FALSE
# 86 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle
# 87 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 88 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	delay 10
# 89 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 90 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 91 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5:: @ 8238D6B
# 92 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	delay 20
# 93 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 16, 3, 0
# 94 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 25, 2, 0
# 95 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 24, 6, 0
# 96 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	specialvar VAR_RESULT, FoundAbandonedShipRoom2Key
# 97 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_RESULT, FALSE
# 98 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	call_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle
# 99 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 100 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	delay 10
# 101 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 102 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 103 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6:: @ 8238DB2
# 104 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 105 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 106 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle:: @ 8238DB3
# 107 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 42, 10, 0
# 108 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	return
# 109 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 110 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle:: @ 8238DC3
# 111 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 20, 5, 0
# 112 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	return
# 113 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 114 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle:: @ 8238DD3
# 115 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 1, 12, 0
# 116 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	return
# 117 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 118 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle:: @ 8238DE3
# 119 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	dofieldeffectsparkle 1, 2, 0
# 120 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	return
# 121 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 122 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_Trash:: @ 8238DF3
# 123 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	lockall
# 124 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	msgbox AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash, MSGBOX_DEFAULT
# 125 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	releaseall
# 126 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 127 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 128 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_EventScript_OldSeaMap::
# 129 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	lockall
# 130 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	giveitem ITEM_OLD_SEA_MAP
# 131 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	removeobject LOCALID_OLD_SEA_MAP
# 132 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
# 133 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	releaseall
# 134 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	end
# 135 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"

# 136 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash: @ 8238DFE
# 137 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.string "It's bright and shiny!\n"
# 138 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.string "But it's just trash…$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle::
# 143 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	lock
# 144 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	faceplayer
# 145 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_4
AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_3:
# 174 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_3, MSGBOX_NPC
AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_1:
# 176 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	release
	end

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_2:
# 147 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	checktrainerflag TRAINER_SHEDINJITE_ABANDONED_SHIP
	goto_if 0, AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_7
# 170 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_4, MSGBOX_NPC
	goto AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_1

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_4:
# 145 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ABANDONDED_SHIP_BUGCATCHER, AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_2
	goto AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_3

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_7:
# 148 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_0, MSGBOX_YESNO
# 149 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_10
# 166 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_3, MSGBOX_NPC
	goto AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_1

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_10:
# 150 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	msgbox AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_1, MSGBOX_NPC
# 151 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	trainerbattle_no_intro TRAINER_SHEDINJITE_ABANDONED_SHIP, AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_2
# 153 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setflag FLAG_DEFEATED_ABANDONDED_SHIP_BUGCATCHER
# 154 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	clearflag FLAG_HIDE_ABANDONED_SHIP_SHEDINJITE
# 155 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 156 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	removeobject VAR_LAST_TALKED
# 157 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	addobject LOCALID_SHEDINJAITE
# 158 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setobjectxy LOCALID_SHEDINJAITE, 23, 10
# 159 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setobjectmovementtype LOCALID_SHEDINJAITE, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 160 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_1


AbandonedShip_HiddenFloorRooms_OnResume::
# 181 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	checktrainerflag TRAINER_SHEDINJITE_ABANDONED_SHIP
	goto_if 1, AbandonedShip_HiddenFloorRooms_OnResume_4
AbandonedShip_HiddenFloorRooms_OnResume_3:
# 185 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setflag FLAG_HIDE_ABANDONED_SHIP_SHEDINJITE
# 186 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setobjectxy LOCALID_SHEDINJAITE, 0, 0
AbandonedShip_HiddenFloorRooms_OnResume_1:
	return

AbandonedShip_HiddenFloorRooms_OnResume_2:
# 182 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	setobjectxy LOCALID_SHEDINJAITE, 23, 10
	goto AbandonedShip_HiddenFloorRooms_OnResume_1

AbandonedShip_HiddenFloorRooms_OnResume_4:
# 181 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	goto_if_unset FLAG_HIDE_ABANDONED_SHIP_SHEDINJITE, AbandonedShip_HiddenFloorRooms_OnResume_2
	goto AbandonedShip_HiddenFloorRooms_OnResume_3


AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_0:
# 148 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.string "... Nincada?$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_1:
# 150 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.string "It's so scary now...$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_2:
# 151 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.string "Thank... you...$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_3:
# 166 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.string "...$"

AbandonedShip_HiddenFloorRooms_EventScript_Shedinjite_Battle_Text_4:
# 170 "data/maps/AbandonedShip_HiddenFloorRooms/scripts.pory"
	.string "remove this code$"
