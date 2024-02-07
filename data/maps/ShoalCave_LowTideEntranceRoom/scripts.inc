# 1 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 2 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_MapScripts:: @ 8236DBA
# 3 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideEntranceRoom_OnTransition
# 4 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	.byte 0
# 5 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 6 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_OnTransition: @ 8236DC0
# 7 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	special UpdateShoalTideFlag
# 8 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_set FLAG_SYS_SHOAL_TIDE, ShoalCave_LowTideEntranceRoom_EventScript_SetHighTide
# 9 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto ShoalCave_LowTideEntranceRoom_EventScript_SetLowTide
# 10 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 11 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_SetHighTide:: @ 8236DD1
# 12 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	setmaplayoutindex LAYOUT_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM
# 13 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 14 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 15 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_SetLowTide:: @ 8236DD5
# 16 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	setmaplayoutindex LAYOUT_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM
# 17 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 18 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 19 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_ShellBellExpert:: @ 8236DD9
# 20 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	lock
# 21 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	faceplayer
# 22 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	dotimebasedevents
# 23 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	call_if_set FLAG_SYS_SHOAL_ITEM, ShoalCave_LowTideEntranceRoom_EventScript_ResetShoalItems
# 24 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SALT, 4
# 25 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 26 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_NotEnoughShoalSaltOrShells
# 27 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SHELL, 4
# 28 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 29 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_NotEnoughShoalSaltOrShells
# 30 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_WouldYouLikeShellBell, MSGBOX_YESNO
# 31 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, NO
# 32 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_DeclineShellBell
# 33 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitemspace ITEM_SHELL_BELL, 1
# 34 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 35 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	call_if_eq ShoalCave_LowTideEntranceRoom_EventScript_CheckSpaceWillBeFreed
# 36 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, 2
# 37 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_NoRoomForShellBell
# 38 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_MakeShellBellRightAway, MSGBOX_DEFAULT
# 39 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	removeitem ITEM_SHOAL_SALT, 4
# 40 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	removeitem ITEM_SHOAL_SHELL, 4
# 41 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	giveitem ITEM_SHELL_BELL
# 42 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, FALSE
# 43 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 44 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_ExplainShellBell, MSGBOX_DEFAULT
# 45 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 46 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_unset FLAG_SHOALCAVE_SLOWBRONITE, ShoalCave_LowTideEntranceRoom_EventScript_Slowbronite
# 47 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 48 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 49 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 50 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_Slowbronite::
# 51 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_Slowbronite, MSGBOX_DEFAULT
# 52 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	givecustommon SPECIES_SLOWBRO, 70, ITEM_SLOWBRONITE, ITEM_POKE_BALL, NATURE_BOLD, 1, 252, 0, 252, 0, 0, 4, 0, 0, 0, 0, 0, 0, MOVE_HYDRO_PUMP, MOVE_PSYCHIC, MOVE_PROTECT, MOVE_CALM_MIND, FALSE
# 53 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 54 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	message ShoalCave_LowTideEntranceRoom_Text_Got_Slowbro
# 55 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	waitfanfare
# 56 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 57 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 58 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 59 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
@ If the bag is full, check if a slot will be freed when 4 Shoal Salt or Shells are given
# 60 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_CheckSpaceWillBeFreed:: @ 8236E69
# 61 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SALT, 5
# 62 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 63 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_CheckSpaceWillBeFreedShells
# 64 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	return
# 65 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 66 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_CheckSpaceWillBeFreedShells:: @ 8236E7A
# 67 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SHELL, 5
# 68 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 69 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_NoSpaceWillBeFreed
# 70 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	return
# 71 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 72 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_NoSpaceWillBeFreed:: @ 8236E8B
# 73 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	setvar VAR_RESULT, 2
# 74 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	return
# 75 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 76 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_NoRoomForShellBell:: @ 8236E91
# 77 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_NoSpaceInYourBag, MSGBOX_DEFAULT
# 78 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 79 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 80 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 81 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_NotEnoughShoalSaltOrShells:: @ 8236E9B
# 82 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SALT, 1
# 83 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 84 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_HasSomeShoalSaltOrShell
# 85 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	checkitem ITEM_SHOAL_SHELL, 1
# 86 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	compare VAR_RESULT, TRUE
# 87 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	goto_if_eq ShoalCave_LowTideEntranceRoom_EventScript_HasSomeShoalSaltOrShell
# 88 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_AreYouPlanningOnGoingInThere, MSGBOX_DEFAULT
# 89 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 90 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 91 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 92 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_HasSomeShoalSaltOrShell:: @ 8236EC5
# 93 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_BringMe4ShoalSaltAndShells, MSGBOX_DEFAULT
# 94 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 95 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 96 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 97 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_DeclineShellBell:: @ 8236ECF
# 98 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	msgbox ShoalCave_LowTideEntranceRoom_Text_WantedToMakeShellBell, MSGBOX_DEFAULT
# 99 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	release
# 100 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	end
# 101 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"

# 102 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
ShoalCave_LowTideEntranceRoom_EventScript_ResetShoalItems:: @ 8236ED9
# 103 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SALT_1
# 104 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SALT_2
# 105 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SALT_3
# 106 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SALT_4
# 107 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SHELL_1
# 108 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SHELL_2
# 109 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SHELL_3
# 110 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_RECEIVED_SHOAL_SHELL_4
# 111 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	clearflag FLAG_SYS_SHOAL_ITEM
# 112 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	return

ShoalCave_LowTideEntranceRoom_Text_Got_Slowbro::
# 115 "data/maps/ShoalCave_LowTideEntranceRoom/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Slowbro{COLOR DARK_GRAY} as a gift!$"
