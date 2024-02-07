# 1 "data/maps/SSTidalCorridor/scripts.pory"

# 2 "data/maps/SSTidalCorridor/scripts.pory"
.set LOCALID_SAILOR, 1
# 3 "data/maps/SSTidalCorridor/scripts.pory"
.set LOCALID_SCOTT, 5
# 4 "data/maps/SSTidalCorridor/scripts.pory"

# 5 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_MapScripts:: @ 823BFCF
# 6 "data/maps/SSTidalCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalCorridor_OnFrame
# 7 "data/maps/SSTidalCorridor/scripts.pory"
	.byte 0
# 8 "data/maps/SSTidalCorridor/scripts.pory"

# 9 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_OnFrame: @ 823BFD5
# 10 "data/maps/SSTidalCorridor/scripts.pory"
	map_script_2 VAR_SS_TIDAL_SCOTT_STATE, 0, SSTidalCorridor_EventScript_ScottScene
# 11 "data/maps/SSTidalCorridor/scripts.pory"
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT, SSTidalCorridor_EventScript_DepartSlateportForLilycove
# 12 "data/maps/SSTidalCorridor/scripts.pory"
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE, SSTidalCorridor_EventScript_DepartLilycoveForSlateport
# 13 "data/maps/SSTidalCorridor/scripts.pory"
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_RIGHT, SSTidalCorridor_EventScript_HalfwayToLilycove
# 14 "data/maps/SSTidalCorridor/scripts.pory"
	map_script_2 VAR_SS_TIDAL_STATE, SS_TIDAL_EXIT_CURRENTS_LEFT, SSTidalCorridor_EventScript_ArrivedInSlateport
# 15 "data/maps/SSTidalCorridor/scripts.pory"
	.2byte 0
# 16 "data/maps/SSTidalCorridor/scripts.pory"

# 17 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_DepartSlateportForLilycove:: @ 823BFFF
# 18 "data/maps/SSTidalCorridor/scripts.pory"
	special SetSSTidalFlag
# 19 "data/maps/SSTidalCorridor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
# 20 "data/maps/SSTidalCorridor/scripts.pory"
	lockall
# 21 "data/maps/SSTidalCorridor/scripts.pory"
	playse SE_DING_DONG
# 22 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
# 23 "data/maps/SSTidalCorridor/scripts.pory"
	releaseall
# 24 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 25 "data/maps/SSTidalCorridor/scripts.pory"

# 26 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_DepartLilycoveForSlateport:: @ 823C015
# 27 "data/maps/SSTidalCorridor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_LILYCOVE
# 28 "data/maps/SSTidalCorridor/scripts.pory"
	lockall
# 29 "data/maps/SSTidalCorridor/scripts.pory"
	playse SE_DING_DONG
# 30 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
# 31 "data/maps/SSTidalCorridor/scripts.pory"
	releaseall
# 32 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 33 "data/maps/SSTidalCorridor/scripts.pory"

# 34 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalRooms_EventScript_HalfwayToSlateport:: @ 823C028
# 35 "data/maps/SSTidalCorridor/scripts.pory"
	special SetSSTidalFlag
# 36 "data/maps/SSTidalCorridor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
# 37 "data/maps/SSTidalCorridor/scripts.pory"
	playse SE_DING_DONG
# 38 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage, MSGBOX_DEFAULT
# 39 "data/maps/SSTidalCorridor/scripts.pory"
	return
# 40 "data/maps/SSTidalCorridor/scripts.pory"

# 41 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalRooms_EventScript_ArrivedInLilycove:: @ 823C03C
# 42 "data/maps/SSTidalCorridor/scripts.pory"
	special ResetSSTidalFlag
# 43 "data/maps/SSTidalCorridor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
# 44 "data/maps/SSTidalCorridor/scripts.pory"
	playse SE_DING_DONG
# 45 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidal_Text_MadeLandInLilycove, MSGBOX_DEFAULT
# 46 "data/maps/SSTidalCorridor/scripts.pory"
	return
# 47 "data/maps/SSTidalCorridor/scripts.pory"

# 48 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_ReachedStepCount:: @ 823C050
# 49 "data/maps/SSTidalCorridor/scripts.pory"
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
# 50 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_eq SSTidalCorridor_EventScript_HalfwayToLilycove
# 51 "data/maps/SSTidalCorridor/scripts.pory"
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
# 52 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_eq SSTidalCorridor_EventScript_ArrivedInSlateport
# 53 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 54 "data/maps/SSTidalCorridor/scripts.pory"

# 55 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_HalfwayToLilycove:: @ 823C067
# 56 "data/maps/SSTidalCorridor/scripts.pory"
	special ResetSSTidalFlag
# 57 "data/maps/SSTidalCorridor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_LILYCOVE
# 58 "data/maps/SSTidalCorridor/scripts.pory"
	lockall
# 59 "data/maps/SSTidalCorridor/scripts.pory"
	playse SE_DING_DONG
# 60 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidal_Text_HopeYouEnjoyVoyage, MSGBOX_DEFAULT
# 61 "data/maps/SSTidalCorridor/scripts.pory"
	releaseall
# 62 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 63 "data/maps/SSTidalCorridor/scripts.pory"

# 64 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_ArrivedInSlateport:: @ 823C07D
# 65 "data/maps/SSTidalCorridor/scripts.pory"
	special ResetSSTidalFlag
# 66 "data/maps/SSTidalCorridor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
# 67 "data/maps/SSTidalCorridor/scripts.pory"
	lockall
# 68 "data/maps/SSTidalCorridor/scripts.pory"
	playse SE_DING_DONG
# 69 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
# 70 "data/maps/SSTidalCorridor/scripts.pory"
	releaseall
# 71 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 72 "data/maps/SSTidalCorridor/scripts.pory"

# 73 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalRooms_EventScript_ArrivedInSlateport:: @ 823C093
# 74 "data/maps/SSTidalCorridor/scripts.pory"
	special ResetSSTidalFlag
# 75 "data/maps/SSTidalCorridor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
# 76 "data/maps/SSTidalCorridor/scripts.pory"
	playse SE_DING_DONG
# 77 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidal_Text_MadeLandInSlateport, MSGBOX_DEFAULT
# 78 "data/maps/SSTidalCorridor/scripts.pory"
	return
# 79 "data/maps/SSTidalCorridor/scripts.pory"

# 80 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalRooms_EventScript_ProgessCruiseAfterBed:: @ 823C0A7
# 81 "data/maps/SSTidalCorridor/scripts.pory"
	switch VAR_SS_TIDAL_STATE
# 82 "data/maps/SSTidalCorridor/scripts.pory"
	case SS_TIDAL_DEPART_SLATEPORT, SSTidalRooms_EventScript_ArrivedInLilycove
# 83 "data/maps/SSTidalCorridor/scripts.pory"
	case SS_TIDAL_HALFWAY_LILYCOVE, SSTidalRooms_EventScript_ArrivedInLilycove
# 84 "data/maps/SSTidalCorridor/scripts.pory"
	case SS_TIDAL_DEPART_LILYCOVE, SSTidalRooms_EventScript_HalfwayToSlateport
# 85 "data/maps/SSTidalCorridor/scripts.pory"
	case SS_TIDAL_HALFWAY_SLATEPORT, SSTidalRooms_EventScript_ArrivedInSlateport
# 86 "data/maps/SSTidalCorridor/scripts.pory"
	return
# 87 "data/maps/SSTidalCorridor/scripts.pory"

# 88 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_Briney:: @ 823C0D9
# 89 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_BrineyWelcomeAboard, MSGBOX_NPC
# 90 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 91 "data/maps/SSTidalCorridor/scripts.pory"

# 92 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_Peeko:: @ 823C0E2
# 93 "data/maps/SSTidalCorridor/scripts.pory"
	lock
# 94 "data/maps/SSTidalCorridor/scripts.pory"
	faceplayer
# 95 "data/maps/SSTidalCorridor/scripts.pory"
	waitse
# 96 "data/maps/SSTidalCorridor/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 97 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_Peeko, MSGBOX_DEFAULT
# 98 "data/maps/SSTidalCorridor/scripts.pory"
	waitmoncry
# 99 "data/maps/SSTidalCorridor/scripts.pory"
	release
# 100 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 101 "data/maps/SSTidalCorridor/scripts.pory"

# 102 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_Cabin1Sign:: @ 823C0F5
# 103 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_Cabin1, MSGBOX_SIGN
# 104 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 105 "data/maps/SSTidalCorridor/scripts.pory"

# 106 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_Cabin2Sign:: @ 823C0FE
# 107 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_Cabin2, MSGBOX_SIGN
# 108 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 109 "data/maps/SSTidalCorridor/scripts.pory"

# 110 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_Cabin3Sign:: @ 823C107
# 111 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_Cabin3, MSGBOX_SIGN
# 112 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 113 "data/maps/SSTidalCorridor/scripts.pory"

# 114 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_Cabin4Sign:: @ 823C110
# 115 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_Cabin4, MSGBOX_SIGN
# 116 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 117 "data/maps/SSTidalCorridor/scripts.pory"

# 118 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_ExitSailor:: @ 823C119
# 119 "data/maps/SSTidalCorridor/scripts.pory"
	lock
# 120 "data/maps/SSTidalCorridor/scripts.pory"
	faceplayer
# 121 "data/maps/SSTidalCorridor/scripts.pory"
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
# 122 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_eq SSTidalCorridor_EventScript_ExitLilycove
# 123 "data/maps/SSTidalCorridor/scripts.pory"
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_SLATEPORT
# 124 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_eq SSTidalCorridor_EventScript_ExitSlateport
# 125 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_CanRestInCabin2, MSGBOX_DEFAULT
# 126 "data/maps/SSTidalCorridor/scripts.pory"
	release
# 127 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 128 "data/maps/SSTidalCorridor/scripts.pory"

# 129 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_ExitLilycove:: @ 823C13B
# 130 "data/maps/SSTidalCorridor/scripts.pory"
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
# 131 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
# 132 "data/maps/SSTidalCorridor/scripts.pory"
	call_if_set FLAG_RECEIVED_TM49, SSTidalCorridor_EventScript_HideSnatchGiver
# 133 "data/maps/SSTidalCorridor/scripts.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
# 134 "data/maps/SSTidalCorridor/scripts.pory"
	waitstate
# 135 "data/maps/SSTidalCorridor/scripts.pory"
	release
# 136 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 137 "data/maps/SSTidalCorridor/scripts.pory"

# 138 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_ExitSlateport:: @ 823C15A
# 139 "data/maps/SSTidalCorridor/scripts.pory"
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
# 140 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_WeveArrived, MSGBOX_DEFAULT
# 141 "data/maps/SSTidalCorridor/scripts.pory"
	call_if_set FLAG_RECEIVED_TM49, SSTidalCorridor_EventScript_HideSnatchGiver
# 142 "data/maps/SSTidalCorridor/scripts.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
# 143 "data/maps/SSTidalCorridor/scripts.pory"
	waitstate
# 144 "data/maps/SSTidalCorridor/scripts.pory"
	release
# 145 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 146 "data/maps/SSTidalCorridor/scripts.pory"

# 147 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_HideSnatchGiver:: @ 823C179
# 148 "data/maps/SSTidalCorridor/scripts.pory"
	setflag FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER
# 149 "data/maps/SSTidalCorridor/scripts.pory"
	return
# 150 "data/maps/SSTidalCorridor/scripts.pory"

# 151 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_Porthole:: @ 823C17D
# 152 "data/maps/SSTidalCorridor/scripts.pory"
	lockall
# 153 "data/maps/SSTidalCorridor/scripts.pory"
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
# 154 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_eq SSTidalCorridor_EventScript_LookThroughPorthole
# 155 "data/maps/SSTidalCorridor/scripts.pory"
	compare VAR_SS_TIDAL_STATE, SS_TIDAL_HALFWAY_SLATEPORT
# 156 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_eq SSTidalCorridor_EventScript_LookThroughPorthole
# 157 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole, MSGBOX_DEFAULT
# 158 "data/maps/SSTidalCorridor/scripts.pory"
	releaseall
# 159 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 160 "data/maps/SSTidalCorridor/scripts.pory"

# 161 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_LookThroughPorthole:: @ 823C19E
# 162 "data/maps/SSTidalCorridor/scripts.pory"
	special LookThroughPorthole
# 163 "data/maps/SSTidalCorridor/scripts.pory"
	waitstate
# 164 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 165 "data/maps/SSTidalCorridor/scripts.pory"

# 166 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_Sailor:: @ 823C1A3
# 167 "data/maps/SSTidalCorridor/scripts.pory"
	lock
# 168 "data/maps/SSTidalCorridor/scripts.pory"
	faceplayer
# 169 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_set FLAG_DEFEATED_SS_TIDAL_TRAINERS, SSTidalCorridor_EventScript_EnjoyYourCruise
# 170 "data/maps/SSTidalCorridor/scripts.pory"
	call SSTidalCorridor_EventScript_CheckIfTrainersDefeated
# 171 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_VisitOtherCabins, MSGBOX_DEFAULT
# 172 "data/maps/SSTidalCorridor/scripts.pory"
	release
# 173 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 174 "data/maps/SSTidalCorridor/scripts.pory"

# 175 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_EnjoyYourCruise:: @ 823C1BD
# 176 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_EnjoyYourCruise, MSGBOX_DEFAULT
# 177 "data/maps/SSTidalCorridor/scripts.pory"
	release
# 178 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 179 "data/maps/SSTidalCorridor/scripts.pory"

# 180 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_CheckIfTrainersDefeated:: @ 823C1C7
# 181 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_not_defeated TRAINER_PHILLIP, SSTidalCorridor_EventScript_TrainerNotDefeated
# 182 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_not_defeated TRAINER_LEONARD, SSTidalCorridor_EventScript_TrainerNotDefeated
# 183 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_not_defeated TRAINER_COLTON, SSTidalCorridor_EventScript_TrainerNotDefeated
# 184 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_not_defeated TRAINER_MICAH, SSTidalCorridor_EventScript_TrainerNotDefeated
# 185 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_not_defeated TRAINER_THOMAS, SSTidalCorridor_EventScript_TrainerNotDefeated
# 186 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_not_defeated TRAINER_LEA_AND_JED, SSTidalCorridor_EventScript_TrainerNotDefeated
# 187 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_not_defeated TRAINER_GARRET, SSTidalCorridor_EventScript_TrainerNotDefeated
# 188 "data/maps/SSTidalCorridor/scripts.pory"
	goto_if_not_defeated TRAINER_NAOMI, SSTidalCorridor_EventScript_TrainerNotDefeated
# 189 "data/maps/SSTidalCorridor/scripts.pory"
	setflag FLAG_DEFEATED_SS_TIDAL_TRAINERS
# 190 "data/maps/SSTidalCorridor/scripts.pory"
	goto SSTidalCorridor_EventScript_EnjoyYourCruise
# 191 "data/maps/SSTidalCorridor/scripts.pory"
	return
# 192 "data/maps/SSTidalCorridor/scripts.pory"

# 193 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_TrainerNotDefeated:: @ 823C218
# 194 "data/maps/SSTidalCorridor/scripts.pory"
	return
# 195 "data/maps/SSTidalCorridor/scripts.pory"

# 196 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_EventScript_ScottScene:: @ 823C219
# 197 "data/maps/SSTidalCorridor/scripts.pory"
	lockall
# 198 "data/maps/SSTidalCorridor/scripts.pory"
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottApproachPlayer
# 199 "data/maps/SSTidalCorridor/scripts.pory"
	waitmovement 0
# 200 "data/maps/SSTidalCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 201 "data/maps/SSTidalCorridor/scripts.pory"
	waitmovement 0
# 202 "data/maps/SSTidalCorridor/scripts.pory"
	msgbox SSTidalCorridor_Text_ScottBattleFrontierInvite, MSGBOX_DEFAULT
# 203 "data/maps/SSTidalCorridor/scripts.pory"
	closemessage
# 204 "data/maps/SSTidalCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSTidalCorridor_Movement_PlayerWatchScottExit
# 205 "data/maps/SSTidalCorridor/scripts.pory"
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorMoveForScott
# 206 "data/maps/SSTidalCorridor/scripts.pory"
	applymovement LOCALID_SCOTT, SSTidalCorridor_Movement_ScottExit
# 207 "data/maps/SSTidalCorridor/scripts.pory"
	waitmovement 0
# 208 "data/maps/SSTidalCorridor/scripts.pory"
	playse SE_EXIT
# 209 "data/maps/SSTidalCorridor/scripts.pory"
	waitse
# 210 "data/maps/SSTidalCorridor/scripts.pory"
	removeobject LOCALID_SCOTT
# 211 "data/maps/SSTidalCorridor/scripts.pory"
	applymovement LOCALID_SAILOR, SSTidalCorridor_Movement_SailorReturn
# 212 "data/maps/SSTidalCorridor/scripts.pory"
	waitmovement 0
# 213 "data/maps/SSTidalCorridor/scripts.pory"
	delay 30
# 214 "data/maps/SSTidalCorridor/scripts.pory"
	setflag FLAG_MET_SCOTT_ON_SS_TIDAL
# 215 "data/maps/SSTidalCorridor/scripts.pory"
	setvar VAR_SS_TIDAL_SCOTT_STATE, 1
# 216 "data/maps/SSTidalCorridor/scripts.pory"
	releaseall
# 217 "data/maps/SSTidalCorridor/scripts.pory"
	end
# 218 "data/maps/SSTidalCorridor/scripts.pory"

# 219 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Movement_ScottApproachPlayer: @ 823C26D
# 220 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 221 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 222 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 223 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 224 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 225 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 226 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 227 "data/maps/SSTidalCorridor/scripts.pory"
	step_end
# 228 "data/maps/SSTidalCorridor/scripts.pory"

# 229 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Movement_ScottExit: @ 823C275
# 230 "data/maps/SSTidalCorridor/scripts.pory"
	walk_in_place_fastest_down
# 231 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 232 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 233 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 234 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 235 "data/maps/SSTidalCorridor/scripts.pory"
	walk_down
# 236 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 237 "data/maps/SSTidalCorridor/scripts.pory"
	step_end
# 238 "data/maps/SSTidalCorridor/scripts.pory"

# 239 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Movement_PlayerWatchScottExit: @ 823C27D
# 240 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 241 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 242 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 243 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 244 "data/maps/SSTidalCorridor/scripts.pory"
	delay_8
# 245 "data/maps/SSTidalCorridor/scripts.pory"
	walk_in_place_fastest_down
# 246 "data/maps/SSTidalCorridor/scripts.pory"
	step_end
# 247 "data/maps/SSTidalCorridor/scripts.pory"

# 248 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Movement_SailorMoveForScott: @ 823C284
# 249 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 250 "data/maps/SSTidalCorridor/scripts.pory"
	walk_right
# 251 "data/maps/SSTidalCorridor/scripts.pory"
	walk_right
# 252 "data/maps/SSTidalCorridor/scripts.pory"
	walk_in_place_fastest_up
# 253 "data/maps/SSTidalCorridor/scripts.pory"
	delay_16
# 254 "data/maps/SSTidalCorridor/scripts.pory"
	walk_in_place_fastest_left
# 255 "data/maps/SSTidalCorridor/scripts.pory"
	step_end
# 256 "data/maps/SSTidalCorridor/scripts.pory"

# 257 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Movement_SailorReturn: @ 823C28B
# 258 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 259 "data/maps/SSTidalCorridor/scripts.pory"
	walk_left
# 260 "data/maps/SSTidalCorridor/scripts.pory"
	walk_in_place_fastest_up
# 261 "data/maps/SSTidalCorridor/scripts.pory"
	step_end
# 262 "data/maps/SSTidalCorridor/scripts.pory"

# 263 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_ScottBattleFrontierInvite: @ 823C28F
# 264 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Scott: Well, hi, hi!\n"
# 265 "data/maps/SSTidalCorridor/scripts.pory"
	.string "{PLAYER}{KUN}, {PLAYER}{KUN}!\p"
# 266 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Something's come up, so I have to\n"
# 267 "data/maps/SSTidalCorridor/scripts.pory"
	.string "disembark, but am I glad to see you!\p"
# 268 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Congratulations, League Champion!\p"
# 269 "data/maps/SSTidalCorridor/scripts.pory"
	.string "There's a place I'd like to invite\n"
# 270 "data/maps/SSTidalCorridor/scripts.pory"
	.string "someone like you.\p"
# 271 "data/maps/SSTidalCorridor/scripts.pory"
	.string "It's the…\n"
# 272 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Battle Frontier!\p"
# 273 "data/maps/SSTidalCorridor/scripts.pory"
	.string "What's the place like?\n"
# 274 "data/maps/SSTidalCorridor/scripts.pory"
	.string "You'll understand when you see it!\p"
# 275 "data/maps/SSTidalCorridor/scripts.pory"
	.string "I've spoken with the ship's CAPTAIN\n"
# 276 "data/maps/SSTidalCorridor/scripts.pory"
	.string "about this.\p"
# 277 "data/maps/SSTidalCorridor/scripts.pory"
	.string "The next time you take a ferry,\n"
# 278 "data/maps/SSTidalCorridor/scripts.pory"
	.string "you should be able to sail to\l"
# 279 "data/maps/SSTidalCorridor/scripts.pory"
	.string "the Battle Frontier.\p"
# 280 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Okay, {PLAYER}{KUN}, I'll be waiting for you\n"
# 281 "data/maps/SSTidalCorridor/scripts.pory"
	.string "at the Battle Frontier!$"
# 282 "data/maps/SSTidalCorridor/scripts.pory"

# 283 "data/maps/SSTidalCorridor/scripts.pory"
SSTidal_Text_FastCurrentsHopeYouEnjoyVoyage: @ 823C462
# 284 "data/maps/SSTidalCorridor/scripts.pory"
	.string "This ferry is built to plow through\n"
# 285 "data/maps/SSTidalCorridor/scripts.pory"
	.string "fast-running currents.\p"
# 286 "data/maps/SSTidalCorridor/scripts.pory"
	.string "We hope you enjoy your voyage with us.\n"
# 287 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Feel free to explore the ship.$"
# 288 "data/maps/SSTidalCorridor/scripts.pory"

# 289 "data/maps/SSTidalCorridor/scripts.pory"
SSTidal_Text_HopeYouEnjoyVoyage: @ 823C4E3
# 290 "data/maps/SSTidalCorridor/scripts.pory"
	.string "We hope you enjoy your voyage on\n"
# 291 "data/maps/SSTidalCorridor/scripts.pory"
	.string "our ferry.$"
# 292 "data/maps/SSTidalCorridor/scripts.pory"

# 293 "data/maps/SSTidalCorridor/scripts.pory"
SSTidal_Text_MadeLandInSlateport: @ 823C50F
# 294 "data/maps/SSTidalCorridor/scripts.pory"
	.string "We have made land in Slateport City.\n"
# 295 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Thank you for sailing with us.$"
# 296 "data/maps/SSTidalCorridor/scripts.pory"

# 297 "data/maps/SSTidalCorridor/scripts.pory"
SSTidal_Text_MadeLandInLilycove: @ 823C553
# 298 "data/maps/SSTidalCorridor/scripts.pory"
	.string "We have made land in Lilycove City.\n"
# 299 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Thank you for sailing with us.$"
# 300 "data/maps/SSTidalCorridor/scripts.pory"

# 301 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_CanRestInCabin2: @ 823C596
# 302 "data/maps/SSTidalCorridor/scripts.pory"
	.string "It'll be some time before we make land,\n"
# 303 "data/maps/SSTidalCorridor/scripts.pory"
	.string "I reckon.\p"
# 304 "data/maps/SSTidalCorridor/scripts.pory"
	.string "You can rest up in your cabin if you'd\n"
# 305 "data/maps/SSTidalCorridor/scripts.pory"
	.string "like. Your cabin's No. 2.\p"
# 306 "data/maps/SSTidalCorridor/scripts.pory"
	.string "The bed in there is soft and plushy.\n"
# 307 "data/maps/SSTidalCorridor/scripts.pory"
	.string "I can attest to how comfy it is!$"
# 308 "data/maps/SSTidalCorridor/scripts.pory"

# 309 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_WeveArrived: @ 823C64F
# 310 "data/maps/SSTidalCorridor/scripts.pory"
	.string "We've arrived!$"
# 311 "data/maps/SSTidalCorridor/scripts.pory"

# 312 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_VisitOtherCabins: @ 823C65E
# 313 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Go visit other cabins.\n"
# 314 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Trainers bored of the boat trip will\l"
# 315 "data/maps/SSTidalCorridor/scripts.pory"
	.string "be itching to battle.$"
# 316 "data/maps/SSTidalCorridor/scripts.pory"

# 317 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_EnjoyYourCruise: @ 823C6B0
# 318 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Enjoy your cruise!$"
# 319 "data/maps/SSTidalCorridor/scripts.pory"

# 320 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_HorizonSpreadsBeyondPorthole: @ 823C6C3
# 321 "data/maps/SSTidalCorridor/scripts.pory"
	.string "The horizon spreads beyond\n"
# 322 "data/maps/SSTidalCorridor/scripts.pory"
	.string "the porthole.$"
# 323 "data/maps/SSTidalCorridor/scripts.pory"

# 324 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_BrineyWelcomeAboard: @ 823C6EC
# 325 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Mr. Briney: Welcome aboard, {PLAYER}{KUN}!\p"
# 326 "data/maps/SSTidalCorridor/scripts.pory"
	.string "They made me honorary captain of\n"
# 327 "data/maps/SSTidalCorridor/scripts.pory"
	.string "the S.S. Tidal!\p"
# 328 "data/maps/SSTidalCorridor/scripts.pory"
	.string "You can call me Captain Briney now!\p"
# 329 "data/maps/SSTidalCorridor/scripts.pory"
	.string "You know, I retired once before,\n"
# 330 "data/maps/SSTidalCorridor/scripts.pory"
	.string "but when I saw this majestic ship…\p"
# 331 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Let me just say, it stirred my sleeping\n"
# 332 "data/maps/SSTidalCorridor/scripts.pory"
	.string "soul as a sailor!$"
# 333 "data/maps/SSTidalCorridor/scripts.pory"

# 334 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_Peeko: @ 823C7E1
# 335 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Peeko: Pihyo pihyohyo…$"
# 336 "data/maps/SSTidalCorridor/scripts.pory"

# 337 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_Cabin1: @ 823C7F8
# 338 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Cabin 1$"
# 339 "data/maps/SSTidalCorridor/scripts.pory"

# 340 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_Cabin2: @ 823C800
# 341 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Cabin 2$"
# 342 "data/maps/SSTidalCorridor/scripts.pory"

# 343 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_Cabin3: @ 823C808
# 344 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Cabin 3$"
# 345 "data/maps/SSTidalCorridor/scripts.pory"

# 346 "data/maps/SSTidalCorridor/scripts.pory"
SSTidalCorridor_Text_Cabin4: @ 823C810
# 347 "data/maps/SSTidalCorridor/scripts.pory"
	.string "Cabin 4$"
