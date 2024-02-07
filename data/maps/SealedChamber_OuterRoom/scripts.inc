# 1 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 2 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_MapScripts:: @ 8239106
# 3 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_OnResume
# 4 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_OnTransition
# 5 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_OnLoad
# 6 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	.byte 0
# 7 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 8 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_OnResume: @ 8239116
# 9 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setdivewarp MAP_UNDERWATER_SEALED_CHAMBER, 255, 12, 44
# 10 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setescapewarp MAP_UNDERWATER_SEALED_CHAMBER, 255, 12, 44
# 11 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 12 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 13 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_OnTransition: @ 8239127
# 14 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setflag FLAG_LANDMARK_SEALED_CHAMBER
# 15 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 16 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 17 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_OnLoad: @ 823912B
# 18 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	call_if_unset FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance
# 19 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 20 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 21 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance:: @ 8239135
# 22 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 9, 1, METATILE_Cave_EntranceCover, 1
# 23 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 10, 1, METATILE_Cave_EntranceCover, 1
# 24 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 11, 1, METATILE_Cave_EntranceCover, 1
# 25 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 9, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
# 26 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 10, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
# 27 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	setmetatile 11, 2, METATILE_Cave_SealedChamberBraille_Mid, 1
# 28 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	return
# 29 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 30 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleABC:: @ 823916C
# 31 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 32 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_ABC
# 33 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 34 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 35 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 36 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 37 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 38 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleGHI:: @ 8239176
# 39 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 40 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_GHI
# 41 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 42 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 43 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 44 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 45 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 46 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleMNO:: @ 8239180
# 47 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 48 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_MNO
# 49 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 50 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 51 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 52 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 53 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 54 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleTUV:: @ 823918A
# 55 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 56 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_TUV
# 57 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 58 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 59 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 60 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 61 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 62 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleDEF:: @ 8239194
# 63 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 64 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_DEF
# 65 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 66 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 67 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 68 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 69 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 70 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleJKL:: @ 823919E
# 71 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 72 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_JKL
# 73 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 74 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 75 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 76 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 77 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 78 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BraillePQRS:: @ 82391A8
# 79 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 80 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_PQRS
# 81 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 82 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 83 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 84 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 85 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 86 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BraillePeriod:: @ 82391B2
# 87 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 88 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_Period
# 89 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 90 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 91 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 92 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 93 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 94 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleWXYZ:: @ 82391BC
# 95 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 96 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_WXYZ
# 97 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 98 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 99 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 100 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 101 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 102 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleComma:: @ 82391C6
# 103 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 104 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_Comma
# 105 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 106 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 107 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 108 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 109 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 110 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_InnerRoomEntranceWall:: @ 82391D0
# 111 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 112 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	goto_if_set FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_HoleInWall
# 113 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_DigHere
# 114 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 115 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 116 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 117 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 118 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 119 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_HoleInWall:: @ 82391E3
# 120 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
# 121 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 122 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
# 123 "data/maps/SealedChamber_OuterRoom/scripts.pory"

# 124 "data/maps/SealedChamber_OuterRoom/scripts.pory"
SealedChamber_OuterRoom_EventScript_BrailleDigHere:: @ 82391ED
# 125 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	lockall
# 126 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	braillemessage SealedChamber_OuterRoom_Braille_DigHere
# 127 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	waitbuttonpress
# 128 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	closebraillemessage
# 129 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	releaseall
# 130 "data/maps/SealedChamber_OuterRoom/scripts.pory"
	end
