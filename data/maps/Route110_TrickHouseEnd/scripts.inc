# 1 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 2 "data/maps/Route110_TrickHouseEnd/scripts.pory"
.set LOCALID_TRICK_MASTER, 1
# 3 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 4 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_MapScripts:: @ 826ACAF
# 5 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
# 6 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
# 7 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
# 8 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
# 9 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.byte 0
# 10 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 11 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnResume: @ 826ACC4
# 12 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	compare VAR_TEMP_1, 1
# 13 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
# 14 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 15 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 16 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnTransition: @ 826ACD0
# 17 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_1, 0
# 18 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_2, 0
# 19 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special SetTrickHouseNuggetFlag
# 20 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 21 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 22 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnWarp: @ 826ACDE
# 23 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
# 24 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.2byte 0
# 25 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 26 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_SetTrickMasterPos:: @ 826ACE8
# 27 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 28 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
# 29 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
# 30 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 31 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 32 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_OnFrame: @ 826ACF5
# 33 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
# 34 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.2byte 0
# 35 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 36 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CloseDoor:: @ 826ACFF
# 37 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_1, 1
# 38 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
# 39 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special DrawWholeMapView
# 40 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 41 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 42 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile:: @ 826AD0D
# 43 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, 1
# 44 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 45 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 46 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMaster:: @ 826AD17
# 47 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	lock
# 48 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	faceplayer
# 49 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
# 50 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TEMP_2, 1
# 51 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 52 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
# 53 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
# 54 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
# 55 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
# 56 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
# 57 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
# 58 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
# 59 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
# 60 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 61 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 62 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle1:: @ 826AD84
# 63 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
# 64 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 65 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 66 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givecustommon SPECIES_PIKACHU_ORIGINAL_CAP, 25, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 67 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 68 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	message Route110_TrickHouseEnd_Text_ObtainedPikachu
# 69 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitfanfare
# 70 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmessage
# 71 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 72 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 73 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 74 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 75 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 76 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 77 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle2:: @ 826ADC0
# 78 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
# 79 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 80 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 81 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givecustommon SPECIES_PIKACHU_HOENN_CAP, 25, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 82 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 83 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	message Route110_TrickHouseEnd_Text_ObtainedPikachu
# 84 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitfanfare
# 85 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmessage
# 86 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 87 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 88 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 89 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 90 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 91 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 92 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle3:: @ 826ADFC
# 93 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
# 94 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 95 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 96 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givecustommon SPECIES_PIKACHU_SINNOH_CAP, 25, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 97 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 98 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	message Route110_TrickHouseEnd_Text_ObtainedPikachu
# 99 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitfanfare
# 100 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmessage
# 101 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 102 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 103 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 104 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 105 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 106 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 107 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle4:: @ 826AE38
# 108 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
# 109 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 110 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 111 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givecustommon SPECIES_PIKACHU_UNOVA_CAP, 25, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 112 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 113 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	message Route110_TrickHouseEnd_Text_ObtainedPikachu
# 114 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitfanfare
# 115 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmessage
# 116 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 117 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 118 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 119 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 120 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 121 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 122 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle5:: @ 826AE74
# 123 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
# 124 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 125 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 126 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givecustommon SPECIES_PIKACHU_KALOS_CAP, 25, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 127 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 128 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	message Route110_TrickHouseEnd_Text_ObtainedPikachu
# 129 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitfanfare
# 130 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmessage
# 131 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 132 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 133 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 134 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 135 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 136 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 137 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle6:: @ 826AEB0
# 138 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
# 139 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 140 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 141 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givecustommon SPECIES_PIKACHU_ALOLA_CAP, 25, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 142 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 143 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	message Route110_TrickHouseEnd_Text_ObtainedPikachu
# 144 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitfanfare
# 145 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmessage
# 146 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 147 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 148 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 149 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 150 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 151 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 152 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle7:: @ 826AEEC
# 153 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
# 154 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 155 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 156 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givecustommon SPECIES_PIKACHU_PARTNER_CAP, 25, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 157 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 158 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	message Route110_TrickHouseEnd_Text_ObtainedPikachu
# 159 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitfanfare
# 160 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmessage
# 161 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
# 162 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 163 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 164 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 165 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 166 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 167 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_CompletedPuzzle8:: @ 826AF28
# 168 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
# 169 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 170 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 171 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
# 172 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 173 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
# 174 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 175 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
# 176 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 177 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call_if_eq Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
# 178 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 30
# 179 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
# 180 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 181 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
# 182 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 183 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 30
# 184 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
# 185 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 186 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givecustommon SPECIES_PIKACHU_WORLD_CAP, 25, ITEM_LIGHT_BALL, ITEM_PREMIER_BALL, NATURE_NAIVE, 2, 0, 180, 0, 252, 76, 0, 0, 0, 0, 0, 0, 0, MOVE_FAKE_OUT, MOVE_ZIPPY_ZAP, MOVE_SPLISHY_SPLASH, MOVE_EXTREME_SPEED, FALSE
# 187 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 188 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	message Route110_TrickHouseEnd_Text_ObtainedPikachu
# 189 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitfanfare
# 190 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmessage
# 191 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
# 192 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
# 193 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	special ResetTrickHouseNuggetFlag
# 194 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	release
# 195 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 196 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 197 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_ChooseTent:: @ 826AFA5
# 198 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	multichoice 0, 0, MULTI_TENT, TRUE
# 199 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	switch VAR_RESULT
# 200 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
# 201 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent
# 202 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 203 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_GiveRedTent:: @ 826AFBF
# 204 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givedecoration DECOR_RED_TENT
# 205 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 206 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 207 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_GiveBlueTent:: @ 826AFC7
# 208 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	givedecoration DECOR_BLUE_TENT
# 209 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 210 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 211 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterExit:: @ 826AFCF
# 212 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
# 213 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 214 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_M_EXPLOSION
# 215 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
# 216 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 217 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	removeobject LOCALID_TRICK_MASTER
# 218 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	addvar VAR_TRICK_HOUSE_LEVEL, 1
# 219 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 220 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 221 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_BagFull:: @ 826AFEF
# 222 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Common_EventScript_BagIsFull
# 223 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
# 224 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 225 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 226 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 227 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_NoRoomForTent:: @ 826B002
# 228 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	call Common_EventScript_NoRoomForDecor
# 229 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
# 230 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 231 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 232 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 233 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth:: @ 826B015
# 234 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestDown
# 235 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 236 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 237 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 238 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth:: @ 826B020
# 239 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestUp
# 240 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 241 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 242 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 243 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest:: @ 826B02B
# 244 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestLeft
# 245 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 246 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 247 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 248 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast:: @ 826B036
# 249 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestRight
# 250 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 251 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	return
# 252 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 253 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger:: @ 826B041
# 254 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	lockall
# 255 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
# 256 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_PIN
# 257 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
# 258 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 259 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 20
# 260 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
# 261 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 262 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	playse SE_M_EXPLOSION
# 263 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 264 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 265 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
# 266 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	closemessage
# 267 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
# 268 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	waitmovement 0
# 269 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	delay 4
# 270 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
# 271 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	releaseall
# 272 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	end
# 273 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 274 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Movement_KeepPlayerInRoom: @ 826B089
# 275 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	walk_down
# 276 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	step_end
# 277 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 278 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Movement_TrickMasterSurprise: @ 826B08B
# 279 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	jump_in_place_left
# 280 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	step_end
# 281 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 282 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YouveMadeItToMe: @ 826B08D
# 283 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Aak!\n"
# 284 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You've made it to me?\l"
# 285 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Hmmm… You're sharp!$"
# 286 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 287 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToPlantTrees: @ 826B0BC
# 288 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to plant all those\n"
# 289 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "trees…\p"
# 290 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 291 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four, five, six places!$"
# 292 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 293 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToMakeMaze: @ 826B13B
# 294 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to make the maze…\p"
# 295 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 296 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four, five places!$"
# 297 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 298 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToPreparePanels: @ 826B1AD
# 299 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to prepare\n"
# 300 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "the wall panels…\p"
# 301 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 302 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three, four places!$"
# 303 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 304 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToShoveBoulders: @ 826B223
# 305 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to shove in those\n"
# 306 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "boulders…\p"
# 307 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 308 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two, three places!$"
# 309 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 310 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls: @ 826B293
# 311 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to make Mechadolls\n"
# 312 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "and another to think up the quiz…\p"
# 313 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness by\n"
# 314 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "one, two places!$"
# 315 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 316 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightToInstallDoors: @ 826B315
# 317 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night to install\n"
# 318 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "the doors…\p"
# 319 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're almost my equal in greatness!$"
# 320 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 321 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightSettingUpArrows: @ 826B365
# 322 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night setting up arrows…\p"
# 323 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're my equal in greatness!$"
# 324 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 325 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_AllNightPolishingFloors: @ 826B3AB
# 326 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It took me all night polishing floors…\p"
# 327 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You're above me in greatness!\n"
# 328 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Possibly…$"
# 329 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 330 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry: @ 826B3FA
# 331 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Wh-what should I do?\n"
# 332 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "My fountain of ideas for tricks has\l"
# 333 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "run dry…\p"
# 334 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Perhaps it is time I toured the country\n"
# 335 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "on a quest to devise new tricks…$"
# 336 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 337 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent: @ 826B485
# 338 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I hate to admit defeat, but you have\n"
# 339 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "bested me!\p"
# 340 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Still, you must have been reeled in by\n"
# 341 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "my charisma for you to visit me again\l"
# 342 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "and again. Yes, you must have!\p"
# 343 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "But that has nothing to do with my\n"
# 344 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "losing!\p"
# 345 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "In recognition of the friendship\n"
# 346 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "between you, the driven, and the genius\l"
# 347 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "that is myself, I demand that you take\l"
# 348 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "this keepsake!\p"
# 349 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Actually there are two--\n"
# 350 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "a Red Tent and a Blue Tent.\l"
# 351 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Which do you prefer?$"
# 352 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 353 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_NoRoomInPC: @ 826B615
# 354 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What? No room in your PC?\n"
# 355 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What am I to make of that?\p"
# 356 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I wish I could say that, but I am much\n"
# 357 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "too kind and caring, so come back later!$"
# 358 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 359 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_LeavingOnJourney: @ 826B69A
# 360 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "… … … … … …\p"
# 361 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I am leaving on a journey of discovery.\n"
# 362 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "A quest in search of new tricks.\p"
# 363 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I wish that you will one day visit and\n"
# 364 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "entertain me again.\p"
# 365 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "And now, farewell!$"
# 366 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 367 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward: @ 826B73D
# 368 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Fine!\n"
# 369 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You have earned this reward!$"
# 370 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 371 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_NoRoomForThis: @ 826B760
# 372 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What? Have you no room for this?\n"
# 373 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "What manner of items do you carry?\p"
# 374 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "But fine, since you've reached me,\n"
# 375 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "your reward will be with me till later.$"
# 376 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 377 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou: @ 826B7EF
# 378 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Scrub that smug smirk from your face!\n"
# 379 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "It's much too early to think you've won!\p"
# 380 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "I'll make new tricks to stump you, I will.\n"
# 381 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "You may mock me only when you're done.\p"
# 382 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Come back for the next exciting\n"
# 383 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "installment!$"
# 384 "data/maps/Route110_TrickHouseEnd/scripts.pory"

# 385 "data/maps/Route110_TrickHouseEnd/scripts.pory"
Route110_TrickHouseEnd_Text_YoureIgnoringMe: @ 826B8BD
# 386 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Now, now! You're ignoring me now?\n"
# 387 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "Now that, I consider heartbreaking!$"

Route110_TrickHouseEnd_Text_ObtainedPikachu::
# 390 "data/maps/Route110_TrickHouseEnd/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Pikachu{COLOR DARK_GRAY}$"
