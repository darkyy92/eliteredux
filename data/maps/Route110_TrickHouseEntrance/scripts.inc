# 1 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 2 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
.set LOCALID_TRICK_MASTER, 1
# 3 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 4 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_MapScripts:: @ 8269A50
# 5 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEntrance_OnTransition
# 6 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEntrance_OnFrame
# 7 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEntrance_OnWarp
# 8 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.byte 0
# 9 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 10 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	@ State descriptions for VAR_TRICK_HOUSE_ENTRANCE_STATE
# 11 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 0: Trick Master is hiding
# 12 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 1: Trick Master has left at start of challenge
# 13 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 2: Trick Master ready to give normal reward from previous challenge (if bag was full)
# 14 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 3: Trick Master still making next puzzle
# 15 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 4: Finished final puzzle
# 16 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 5: Completed previous challenge
# 17 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	@ 6: 'Trick Master' mechadoll ready to give Tent reward from final challenge (if bag was full)
# 18 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 19 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_OnTransition: @ 8269A60
# 20 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setflag FLAG_LANDMARK_TRICK_HOUSE
# 21 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 1
# 22 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_EnterFromCorridor
# 23 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
# 24 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward
# 25 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1
# 26 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor
# 27 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
# 28 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
# 29 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
# 30 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
# 31 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_ENTRANCE_STATE, 0
# 32 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle
# 33 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
# 34 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger
# 35 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1
# 36 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2
# 37 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3
# 38 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 39 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 40 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetReadyToGiveReward:: @ 8269AD7
# 41 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 42 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 8
# 43 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward
# 44 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 2
# 45 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 46 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 47 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ReadyToGiveTentReward:: @ 8269AED
# 48 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 6
# 49 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 50 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 51 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterFromCorridor:: @ 8269AF3
# 52 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR, 0
# 53 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
# 54 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 55 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 56 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 57 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForNextPuzzle:: @ 8269B03
# 58 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 0
# 59 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 1
# 60 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2
# 61 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 2
# 62 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3
# 63 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 3
# 64 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4
# 65 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 4
# 66 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5
# 67 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 5
# 68 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6
# 69 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 6
# 70 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7
# 71 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 7
# 72 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8
# 73 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 8
# 74 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FinishedPuzzles
# 75 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 76 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 77 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle2:: @ 8269B61
# 78 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_unset FLAG_BADGE03_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 79 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 80 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 81 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle3:: @ 8269B6B
# 82 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_unset FLAG_BADGE04_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 83 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 84 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 85 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle4:: @ 8269B75
# 86 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_unset FLAG_BADGE05_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 87 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 88 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 89 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle5:: @ 8269B7F
# 90 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_unset FLAG_BADGE06_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 91 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 92 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 93 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle6:: @ 8269B89
# 94 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_unset FLAG_BADGE07_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 95 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 96 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 97 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle7:: @ 8269B93
# 98 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_unset FLAG_BADGE08_GET, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 99 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 100 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 101 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckReadyForPuzzle8:: @ 8269B9D
# 102 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle
# 103 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 104 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 105 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FinishedPuzzles:: @ 8269BA7
# 106 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 4
# 107 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 108 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 109 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_NotReadyForPuzzle:: @ 8269BAD
# 110 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
# 111 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 112 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 113 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_MoveTrickMasterToDoor:: @ 8269BB3
# 114 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxyperm LOCALID_TRICK_MASTER, 5, 2
# 115 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 116 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 117 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ReadyBeingWatchedTrigger:: @ 8269BBB
# 118 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 0
# 119 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 120 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 121 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched1:: @ 8269BC1
# 122 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 123 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 124 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 125 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched2:: @ 8269BC7
# 126 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 127 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 128 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 129 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetNotBeingWatched3:: @ 8269BCD
# 130 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 131 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 132 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 133 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_OnWarp: @ 8269BD3
# 134 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_TrickMasterFound
# 135 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 0, Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot
# 136 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 1, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
# 137 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 2, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
# 138 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 3, Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor
# 139 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 4, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
# 140 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 5, Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster
# 141 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_ENTRANCE_STATE, 6, Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor
# 142 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.2byte 0
# 143 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 144 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_TrickMasterFound:: @ 8269C15
# 145 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 146 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
# 147 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
# 148 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 149 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 150 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 151 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetTrickMasterHidingSpot:: @ 8269C26
# 152 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 153 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	hideobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
# 154 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 155 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1
# 156 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2
# 157 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 2, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3
# 158 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4
# 159 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5
# 160 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 5, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6
# 161 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 6, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7
# 162 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 7, Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8
# 163 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 164 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 165 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle1:: @ 8269C8C
# 166 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 6, 3
# 167 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 168 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 169 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle2:: @ 8269C94
# 170 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 11, 5
# 171 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 172 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 173 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle3:: @ 8269C9C
# 174 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 9, 1
# 175 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 176 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 177 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle4:: @ 8269CA4
# 178 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 3, 1
# 179 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 180 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 181 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle5:: @ 8269CAC
# 182 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 0, 5
# 183 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 184 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 185 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle6:: @ 8269CB4
# 186 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 11, 1
# 187 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 188 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 189 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle7:: @ 8269CBC
# 190 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 8, 1
# 191 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 192 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 193 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetHidingSpotPuzzle8:: @ 8269CC4
# 194 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 4, 4
# 195 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 196 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 197 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_RemoveTrickMaster:: @ 8269CCC
# 198 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	removeobject LOCALID_TRICK_MASTER
# 199 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 200 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 201 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetTrickMasterFacingDoor:: @ 8269CD0
# 202 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 203 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
# 204 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_NORTH
# 205 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 206 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 207 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_SetTrickMasterInFrontOfDoor:: @ 8269CDF
# 208 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	addobject LOCALID_TRICK_MASTER
# 209 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setobjectxy LOCALID_TRICK_MASTER, 5, 2
# 210 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	turnobject LOCALID_TRICK_MASTER, DIR_SOUTH
# 211 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 212 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 213 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_OnFrame: @ 8269CEE
# 214 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	map_script_2 VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1, Route110_TrickHouseEntrance_EventScript_BeginChallenge
# 215 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.2byte 0
# 216 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 217 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_BeginChallenge:: @ 8269CF8
# 218 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 219 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	delay 20
# 220 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 0
# 221 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_MeetTrickMaster
# 222 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse, MSGBOX_DEFAULT
# 223 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 224 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	delay 20
# 225 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
# 226 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 227 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_M_EXPLOSION
# 228 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
# 229 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 230 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	removeobject LOCALID_TRICK_MASTER
# 231 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 1
# 232 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 0
# 233 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 234 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 235 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 236 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_UnusedRelease:: @ 8269D39
# 237 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 238 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 239 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 240 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_TrickMaster:: @ 8269D3B
# 241 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 242 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
# 243 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_FoundTrickMaster
# 244 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 2, Route110_TrickHouseEntrance_EventScript_GiveReward
# 245 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle
# 246 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 6, Route110_TrickHouseEntrance_EventScript_MechadollReward
# 247 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 248 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 249 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundTrickMaster:: @ 8269D6E
# 250 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 251 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 252 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 253 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 254 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 255 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 0
# 256 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk
# 257 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 1
# 258 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FoundBehindTree
# 259 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 2
# 260 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FoundInDresser
# 261 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 3
# 262 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow
# 263 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 4
# 264 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FoundInPlanter
# 265 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 5
# 266 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FoundInCupboard
# 267 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 6
# 268 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FoundBehindWindow
# 269 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 7
# 270 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion
# 271 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 272 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_FOUND_TRICK_MASTER, 1
# 273 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warpsilent MAP_ROUTE110_TRICK_HOUSE_ENTRANCE, 255, 6, 2
# 274 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 275 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 276 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 277 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 278 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBeneathDesk:: @ 8269DEE
# 279 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk, MSGBOX_DEFAULT
# 280 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 281 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 282 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBehindTree:: @ 8269DF7
# 283 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindTree, MSGBOX_DEFAULT
# 284 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 285 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 286 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundInDresser:: @ 8269E00
# 287 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInDresser, MSGBOX_DEFAULT
# 288 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 289 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 290 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBeyondWindow:: @ 8269E09
# 291 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConealedBeyondWindow, MSGBOX_DEFAULT
# 292 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 293 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 294 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundInPlanter:: @ 8269E12
# 295 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInPlanter, MSGBOX_DEFAULT
# 296 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 297 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 298 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundInCupboard:: @ 8269E1B
# 299 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedInCupboard, MSGBOX_DEFAULT
# 300 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 301 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 302 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBehindWindow:: @ 8269E24
# 303 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBehindWindow, MSGBOX_DEFAULT
# 304 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 305 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 306 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_FoundBeneathCushion:: @ 8269E2D
# 307 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion, MSGBOX_DEFAULT
# 308 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 309 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 310 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouse_Movement_TrickMasterSpin: @ 8269E36
# 311 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	face_up
# 312 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	delay_4
# 313 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	face_left
# 314 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	delay_4
# 315 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	face_down
# 316 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	delay_4
# 317 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	face_right
# 318 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	delay_4
# 319 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	step_end
# 320 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 321 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouse_Movement_TrickMasterJumpAway: @ 8269E3F
# 322 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	face_up
# 323 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	disable_anim
# 324 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 325 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 326 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 327 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 328 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 329 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	slide_up
# 330 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	step_end
# 331 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 332 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_MeetTrickMaster:: @ 8269E48
# 333 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster, MSGBOX_DEFAULT
# 334 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 335 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 336 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_StillMakingPuzzle:: @ 8269E51
# 337 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick, MSGBOX_DEFAULT
# 338 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 339 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
# 340 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 341 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 342 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
# 343 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 344 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_Delay48
# 345 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 346 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges, MSGBOX_DEFAULT
# 347 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestUp
# 348 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 349 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 350 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 351 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 352 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GiveReward:: @ 8269E8F
# 353 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
# 354 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 355 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward, MSGBOX_DEFAULT
# 356 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 1
# 357 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward
# 358 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 2
# 359 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward
# 360 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 3
# 361 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward
# 362 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 4
# 363 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward
# 364 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 5
# 365 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward
# 366 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 6
# 367 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward
# 368 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 7
# 369 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward
# 370 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 371 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 372 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle1Reward:: @ 8269EEF
# 373 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_TM12_TAUNT
# 374 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 375 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GotReward
# 376 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 377 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Common_EventScript_BagIsFull
# 378 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 379 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 380 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 381 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 382 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle2Reward:: @ 8269F1B
# 383 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_SMOKE_BALL
# 384 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 385 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GotReward
# 386 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 387 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Common_EventScript_BagIsFull
# 388 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 389 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 390 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 391 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 392 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle3Reward:: @ 8269F47
# 393 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_TM92_TRICK_ROOM
# 394 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 395 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GotReward
# 396 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 397 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Common_EventScript_BagIsFull
# 398 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 399 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 400 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 401 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 402 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle4Reward:: @ 8269F73
# 403 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_ROCKY_HELMET
# 404 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 405 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GotReward
# 406 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 407 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Common_EventScript_BagIsFull
# 408 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 409 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 410 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 411 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 412 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle5Reward:: @ 8269F9F
# 413 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_RARE_CANDY
# 414 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 415 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GotReward
# 416 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 417 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Common_EventScript_BagIsFull
# 418 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 419 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 420 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 421 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 422 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle6Reward:: @ 8269FCB
# 423 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_MAGNET
# 424 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 425 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GotReward
# 426 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 427 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Common_EventScript_BagIsFull
# 428 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 429 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 430 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 431 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 432 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GivePuzzle7Reward:: @ 8269FF7
# 433 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	giveitem ITEM_PP_MAX
# 434 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 435 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_GotReward
# 436 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 437 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Common_EventScript_BagIsFull
# 438 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward, MSGBOX_DEFAULT
# 439 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 440 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 441 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 442 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GotReward:: @ 826A023
# 443 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 444 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 3
# 445 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFastestUp
# 446 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 447 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 448 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 449 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 450 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_MechadollReward:: @ 826A039
# 451 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
# 452 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 453 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_MechadollWhichTent, MSGBOX_DEFAULT
# 454 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call Route110_TrickHouseEntrance_EventScript_ChooseTent
# 455 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 456 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_ReceivedTent
# 457 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 458 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Common_EventScript_NoRoomForDecor
# 459 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_PCFullAgain, MSGBOX_DEFAULT
# 460 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 461 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 462 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 463 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ChooseTent:: @ 826A070
# 464 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	multichoice 0, 0, MULTI_TENT, TRUE
# 465 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_RESULT
# 466 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_GiveRedTent
# 467 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto Route110_TrickHouseEntrance_EventScript_GiveBlueTent
# 468 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 469 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GiveRedTent:: @ 826A08A
# 470 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	givedecoration DECOR_RED_TENT
# 471 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 472 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 473 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GiveBlueTent:: @ 826A092
# 474 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	givedecoration DECOR_BLUE_TENT
# 475 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 476 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 477 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ReceivedTent:: @ 826A09A
# 478 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ThenFarewell, MSGBOX_DEFAULT
# 479 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 480 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHousePuzzle5_Movement_MechadollShake
# 481 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 482 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
# 483 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 484 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_M_EXPLOSION
# 485 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
# 486 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 487 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	removeobject LOCALID_TRICK_MASTER
# 488 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
# 489 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_ENTRANCE_STATE, 5
# 490 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 491 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 492 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 493 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_Door:: @ 826A0D3
# 494 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 495 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_ENTRANCE_STATE
# 496 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_ItsAScroll
# 497 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHouseEntrance_EventScript_GoInHolePrompt
# 498 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote
# 499 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 5, Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage
# 500 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 501 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 502 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_ItsAScroll:: @ 826A106
# 503 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
# 504 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 505 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 506 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 507 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_GoInHolePrompt:: @ 826A110
# 508 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll, MSGBOX_YESNO
# 509 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	closemessage
# 510 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_RESULT, YES
# 511 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom
# 512 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 513 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 514 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 515 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom:: @ 826A126
# 516 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 5, 1, METATILE_GenericBuilding_TrickHouse_Stairs_Down, 0
# 517 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 518 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	delay 20
# 519 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 520 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 521 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEntrance_Movement_EnterRoom
# 522 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitmovement 0
# 523 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 524 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1
# 525 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2
# 526 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 2, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3
# 527 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4
# 528 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5
# 529 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 5, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6
# 530 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 6, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7
# 531 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 7, Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8
# 532 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 533 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 534 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Movement_EnterRoom: @ 826A1A7
# 535 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	set_invisible
# 536 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	step_end
# 537 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 538 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom1:: @ 826A1A9
# 539 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE1, 255, 0, 21
# 540 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 541 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 542 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 543 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 544 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom2:: @ 826A1B4
# 545 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE2, 255, 0, 21
# 546 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 547 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 548 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 549 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 550 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom3:: @ 826A1BF
# 551 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE3, 255, 0, 21
# 552 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 553 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 554 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 555 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 556 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom4:: @ 826A1CA
# 557 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE4, 255, 0, 21
# 558 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 559 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 560 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 561 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 562 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom5:: @ 826A1D5
# 563 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE5, 255, 0, 21
# 564 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 565 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 566 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 567 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 568 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom6:: @ 826A1E0
# 569 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE6, 255, 0, 21
# 570 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 571 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 572 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 573 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 574 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom7:: @ 826A1EB
# 575 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE7, 255, 0, 21
# 576 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 577 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 578 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 579 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 580 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_EnterPuzzleRoom8:: @ 826A1F6
# 581 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	warp MAP_ROUTE110_TRICK_HOUSE_PUZZLE8, 255, 0, 21
# 582 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitstate
# 583 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 584 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 585 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 586 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote:: @ 826A201
# 587 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
# 588 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 589 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 590 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 591 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_CheckLevelForMessage:: @ 826A20B
# 592 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 8
# 593 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2
# 594 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_ItsAScroll, MSGBOX_DEFAULT
# 595 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 596 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 597 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 598 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_LeftOnJourneyNote2:: @ 826A220
# 599 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote, MSGBOX_DEFAULT
# 600 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 601 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 602 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 603 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_EventScript_Door:: @ 826A22A
# 604 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 605 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	switch VAR_TRICK_HOUSE_LEVEL
# 606 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 0, Route110_TrickHousePuzzle1_EventScript_Door
# 607 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 1, Route110_TrickHousePuzzle2_EventScript_Door
# 608 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 2, Route110_TrickHousePuzzle3_EventScript_Door
# 609 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 3, Route110_TrickHousePuzzle4_EventScript_Door
# 610 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 4, Route110_TrickHousePuzzle5_EventScript_Door
# 611 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 5, Route110_TrickHousePuzzle6_EventScript_Door
# 612 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 6, Route110_TrickHousePuzzle7_EventScript_Door
# 613 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	case 7, Route110_TrickHousePuzzle8_EventScript_Door
# 614 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 615 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 616 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle1_EventScript_Door:: @ 826A289
# 617 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0
# 618 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle_EventScript_DoorLocked
# 619 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 620 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 621 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2
# 622 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 623 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 624 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 625 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 626 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 627 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle2_EventScript_Door:: @ 826A2B2
# 628 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_2_STATE, 0
# 629 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle_EventScript_DoorLocked
# 630 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle2_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 631 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 632 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_2_STATE, 2
# 633 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 634 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 635 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 636 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 637 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 638 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle3_EventScript_Door:: @ 826A2DB
# 639 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_3_STATE, 0
# 640 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle_EventScript_DoorLocked
# 641 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle3_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 642 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 643 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_3_STATE, 2
# 644 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 645 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 646 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 647 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 648 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 649 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle4_EventScript_Door:: @ 826A304
# 650 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0
# 651 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle_EventScript_DoorLocked
# 652 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 653 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 654 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 2
# 655 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 656 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 657 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 658 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 659 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 660 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle5_EventScript_Door:: @ 826A32D
# 661 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_5_STATE, 0
# 662 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle_EventScript_DoorLocked
# 663 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle5_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 664 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 665 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_5_STATE, 2
# 666 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 667 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 668 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 669 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 670 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 671 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle6_EventScript_Door:: @ 826A356
# 672 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0
# 673 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle_EventScript_DoorLocked
# 674 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 675 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 676 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 2
# 677 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 678 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 679 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 680 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 681 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 682 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle7_EventScript_Door:: @ 826A37F
# 683 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_7_STATE, 0
# 684 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle_EventScript_DoorLocked
# 685 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle7_EventScript_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 686 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 687 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_7_STATE, 2
# 688 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 689 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 690 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 691 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 692 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 693 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle8_EventScript_Door:: @ 826A3A8
# 694 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0
# 695 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	goto_if_eq Route110_TrickHousePuzzle_EventScript_DoorLocked
# 696 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle8_EventScript_WroteSecretCodeLockOpened, MSGBOX_DEFAULT
# 697 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playse SE_PIN
# 698 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 2
# 699 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, 0
# 700 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	special DrawWholeMapView
# 701 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 702 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 703 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 704 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_EventScript_DoorLocked:: @ 826A3D1
# 705 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere, MSGBOX_DEFAULT
# 706 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 707 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 708 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 709 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_EventScript_ReadScrollAgain:: @ 826A3DB
# 710 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt, MSGBOX_DEFAULT
# 711 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 712 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 713 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 714 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_EventScript_FoundScroll:: @ 826A3E5
# 715 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 716 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	message Route110_TrickHousePuzzle_Text_FoundAScroll
# 717 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitfanfare
# 718 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHousePuzzle_Text_MemorizedSecretCode, MSGBOX_DEFAULT
# 719 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 720 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 721 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 722 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_TrickMasterHiding:: @ 826A3F8
# 723 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	lockall
# 724 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	msgbox Route110_TrickHouseEntrance_Text_YoureBeingWatched, MSGBOX_DEFAULT
# 725 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	releaseall
# 726 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 0
# 727 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1
# 728 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 1
# 729 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2
# 730 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	compare VAR_TRICK_HOUSE_LEVEL, 2
# 731 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call_if_eq Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3
# 732 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_TRICK_HOUSE_BEING_WATCHED_STATE, 1
# 733 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	end
# 734 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 735 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle1:: @ 826A429
# 736 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8004, 6  @ x
# 737 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8005, 3  @ y
# 738 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
# 739 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 740 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 741 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle2:: @ 826A439
# 742 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8004, 11  @ x
# 743 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8005, 5   @ y
# 744 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
# 745 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 746 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 747 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle3:: @ 826A449
# 748 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8004, 9  @ x
# 749 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8005, 2  @ y
# 750 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
# 751 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 752 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 753 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle:: @ 826A459
# 754 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	setvar VAR_0x8006, 0
# 755 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	dofieldeffectsparkle VAR_0x8004, VAR_0x8005, VAR_0x8006
# 756 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 757 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	delay 10
# 758 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	return
# 759 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 760 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_YoureBeingWatched: @ 826A474
# 761 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "You're being watched…$"
# 762 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 763 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedBeneathDesk: @ 826A48A
# 764 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 765 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 766 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "beneath this desk? You're sharp!$"
# 767 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 768 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedBehindTree: @ 826A4DA
# 769 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 770 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 771 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "behind this tree? You're sharp!$"
# 772 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 773 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedInDresser: @ 826A529
# 774 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 775 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 776 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "in this dresser? You're sharp!$"
# 777 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 778 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConealedBeyondWindow: @ 826A577
# 779 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 780 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 781 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "beyond this window? You're sharp!$"
# 782 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 783 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedInPlanter: @ 826A5C8
# 784 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 785 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 786 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "in this planter? You're sharp!$"
# 787 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 788 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedInCupboard: @ 826A616
# 789 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 790 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 791 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "in this cupboard? You're sharp!$"
# 792 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 793 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedBehindWindow: @ 826A665
# 794 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 795 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 796 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "behind this window? You're sharp!$"
# 797 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 798 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ConcealedBeneathCushion: @ 826A6B6
# 799 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? Grrr…\p"
# 800 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "How did you know I concealed myself\n"
# 801 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "beneath this cushion? You're sharp!$"
# 802 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 803 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_TheyCallMeTrickMaster: @ 826A709
# 804 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Behold!\p"
# 805 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "For I am the greatest living mystery\n"
# 806 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "of a man in all of Hoenn!\l"
# 807 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "They call me…\p"
# 808 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "The Trick Master!\n"
# 809 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Wahahaha! Glad to meet you!$"
# 810 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 811 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ComeToChallengeTrickHouse: @ 826A78C
# 812 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "You, you've come to challenge\n"
# 813 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "my Trick House, haven't you?\p"
# 814 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "That's why you're here, isn't it?\n"
# 815 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Yes, it is!\p"
# 816 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Consider your challenge accepted!\p"
# 817 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Enter through the scroll there,\n"
# 818 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "and let your challenge commence!\p"
# 819 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "I shall be waiting in the back!$"
# 820 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 821 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ItsAScroll: @ 826A878
# 822 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "It's a scroll.$"
# 823 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 824 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_GoInHoleBehindScroll: @ 826A887
# 825 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "There is a big hole behind the scroll!\p"
# 826 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Want to go in?$"
# 827 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 828 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_LeavingOnJourneyNote: @ 826A8BD
# 829 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "There is a note affixed to the scroll…\p"
# 830 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "“I am leaving on a journey.\n"
# 831 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Don't look for me. Trick Master”$"
# 832 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 833 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_NextTimeUseThisTrick: @ 826A921
# 834 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "For the next time, I'll use this trick,\n"
# 835 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "and that scheme, and those ruses…\p"
# 836 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Mufufufu… If I may say so, it's\n"
# 837 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "brilliantly difficult, even for me!$"
# 838 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 839 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_InMidstOfDevisingNewChallenges: @ 826A9AF
# 840 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah? What?!\n"
# 841 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Oh, it's you!\p"
# 842 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "I'm in the midst of devising new tricky\n"
# 843 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "challenges!\p"
# 844 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "It's not too much to ask for a bit more\n"
# 845 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "time for me to think, is it now?\l"
# 846 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "You wouldn't begrudge me that?\l"
# 847 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Come back in a little while!$"
# 848 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 849 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_YoureHereToAcceptReward: @ 826AA82
# 850 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Ah, it's you! You're here to accept the\n"
# 851 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "reward from before, isn't that right?\l"
# 852 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Yes, right I am!\p"
# 853 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Here!\n"
# 854 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "I'll give it to you now!$"
# 855 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 856 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_DidYouNotComeToClaimReward: @ 826AB00
# 857 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Hah?\n"
# 858 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "Did you not come to claim your reward?$"
# 859 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 860 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_MechadollWhichTent: @ 826AB2C
# 861 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "MECHADOLL 5 I AM!\n"
# 862 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "IF REWARD IS NOT TAKEN BY YOU,\l"
# 863 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "THEN TRICK MASTER YOU CANNOT FOLLOW.\p"
# 864 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "RED TENT OR BLUE TENT,\n"
# 865 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "WHICH DO YOU PREFER?$"
# 866 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 867 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_ThenFarewell: @ 826ABAE
# 868 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "THEN FAREWELL.$"
# 869 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 870 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_PCFullAgain: @ 826ABBD
# 871 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "YOUR PC STATUS: FULL AGAIN.\n"
# 872 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "MEAN, YOU ARE.$"
# 873 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 874 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_Text_FoundAScroll: @ 826ABE8
# 875 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "{PLAYER} found a scroll.$"
# 876 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 877 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_Text_MemorizedSecretCode: @ 826ABFB
# 878 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "{PLAYER} memorized the secret code\n"
# 879 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "written on the scroll.$"
# 880 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 881 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHousePuzzle_Text_SecretCodeWrittenOnIt: @ 826AC2F
# 882 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "A secret code is written on it.$"
# 883 "data/maps/Route110_TrickHouseEntrance/scripts.pory"

# 884 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
Route110_TrickHouseEntrance_Text_DoorLockedWriteSecretCodeHere: @ 826AC4F
# 885 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "The door is locked.\p"
# 886 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "…On closer inspection, this is written\n"
# 887 "data/maps/Route110_TrickHouseEntrance/scripts.pory"
	.string "on it: “Write the secret code here.”$"
