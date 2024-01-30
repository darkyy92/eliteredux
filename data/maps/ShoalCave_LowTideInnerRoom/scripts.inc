# 1 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 2 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_MapScripts:: @ 8236EF5
# 3 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideInnerRoom_OnLoad
# 4 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideInnerRoom_OnTransition
# 5 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	.byte 0
# 6 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 7 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_OnTransition: @ 8236F00
# 8 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetHighTide
# 9 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetLowTide
# 10 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 11 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetHighTide:: @ 8236F0E
# 12 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM
# 13 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 14 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 15 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetLowTide:: @ 8236F12
# 16 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
# 17 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 18 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 19 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_OnLoad: @ 8236F16
# 20 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	call ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles
# 21 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 22 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 23 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles:: @ 8236F1C
# 24 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_1, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
# 25 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
# 26 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 31, 8, METATILE_Cave_ShoalCave_DirtPile_Large, 1
# 27 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
# 28 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 29 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 30 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2:: @ 8236F3D
# 31 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_2, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
# 32 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
# 33 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 14, 26, METATILE_Cave_ShoalCave_DirtPile_Large, 1
# 34 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
# 35 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 36 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 37 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3:: @ 8236F5E
# 38 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_1, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4
# 39 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 41, 20, METATILE_Cave_ShoalCave_BlueStone_Large, 1
# 40 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4
# 41 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 42 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 43 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4:: @ 8236F76
# 44 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_2, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5
# 45 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 41, 10, METATILE_Cave_ShoalCave_BlueStone_Large, 1
# 46 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5
# 47 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 48 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 49 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5:: @ 8236F8E
# 50 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_3, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6
# 51 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 6, 9, METATILE_Cave_ShoalCave_BlueStone_Large, 1
# 52 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6
# 53 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 54 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 55 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6:: @ 8236FA6
# 56 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_4, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatilesEnd
# 57 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 16, 13, METATILE_Cave_ShoalCave_BlueStone_Large, 1
# 58 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	return
# 59 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 60 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatilesEnd:: @ 8236FB9
# 61 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	return
# 62 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 63 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell1:: @ 8236FBA
# 64 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 65 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_1, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
# 66 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 67 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 68 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 69 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 41, 20, METATILE_Cave_ShoalCave_BlueStone_Small, 0
# 70 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 71 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SHELL_1
# 72 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 73 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 74 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 75 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell:: @ 8236FEC
# 76 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	msgbox ShoalCave_Text_WasShoallShellNowNothing, MSGBOX_DEFAULT
# 77 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 78 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 79 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 80 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell2:: @ 8236FF6
# 81 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 82 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_2, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
# 83 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 84 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 85 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 86 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 41, 10, METATILE_Cave_ShoalCave_BlueStone_Small, 0
# 87 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 88 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SHELL_2
# 89 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 90 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 91 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 92 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell3:: @ 8237028
# 93 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 94 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_3, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
# 95 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 96 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 97 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 98 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 6, 9, METATILE_Cave_ShoalCave_BlueStone_Small, 0
# 99 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 100 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SHELL_3
# 101 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 102 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 103 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 104 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalShell4:: @ 823705A
# 105 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 106 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SHELL_4, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
# 107 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 108 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 109 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 110 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 16, 13, METATILE_Cave_ShoalCave_BlueStone_Small, 0
# 111 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 112 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SHELL_4
# 113 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 114 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 115 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 116 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalSalt1:: @ 823708C
# 117 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 118 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_1, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt
# 119 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SALT
# 120 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 121 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 122 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 31, 8, METATILE_Cave_ShoalCave_DirtPile_Small, 0
# 123 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 124 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SALT_1
# 125 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 126 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 127 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 128 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt:: @ 82370BE
# 129 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
# 130 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 131 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
# 132 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"

# 133 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
ShoalCave_LowTideInnerRoom_EventScript_ShoalSalt2:: @ 82370C8
# 134 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	lockall
# 135 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_2, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt
# 136 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	giveitem ITEM_SHOAL_SALT
# 137 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 138 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 139 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setmetatile 14, 26, METATILE_Cave_ShoalCave_DirtPile_Small, 0
# 140 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	special DrawWholeMapView
# 141 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	setflag FLAG_RECEIVED_SHOAL_SALT_2
# 142 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	releaseall
# 143 "data/maps/ShoalCave_LowTideInnerRoom/scripts.pory"
	end
