# 1 "data/maps/TrainerHill_Entrance/scripts.pory"

# 2 "data/maps/TrainerHill_Entrance/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/TrainerHill_Entrance/scripts.pory"
.set LOCALID_NURSE, 2
# 4 "data/maps/TrainerHill_Entrance/scripts.pory"
.set LOCALID_GIRL, 4
# 5 "data/maps/TrainerHill_Entrance/scripts.pory"
.set LOCALID_MAN, 5
# 6 "data/maps/TrainerHill_Entrance/scripts.pory"

# 7 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_MapScripts:: @ 82680AC
# 8 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
# 9 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
# 10 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
# 11 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
# 12 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
# 13 "data/maps/TrainerHill_Entrance/scripts.pory"
	.byte 0
# 14 "data/maps/TrainerHill_Entrance/scripts.pory"

# 15 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnTransition: @ 82680C6
# 16 "data/maps/TrainerHill_Entrance/scripts.pory"
	setflag FLAG_LANDMARK_TRAINER_HILL
# 17 "data/maps/TrainerHill_Entrance/scripts.pory"
	getplayerxy VAR_TEMP_D, VAR_RESULT
# 18 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 19 "data/maps/TrainerHill_Entrance/scripts.pory"

# 20 "data/maps/TrainerHill_Entrance/scripts.pory"
@ Unused
# 21 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnWarp: @ 82680CF
# 22 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 23 "data/maps/TrainerHill_Entrance/scripts.pory"

# 24 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnResume: @ 82680D0
# 25 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_resumetimer
# 26 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_0, 0
# 27 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_getusingereader
# 28 "data/maps/TrainerHill_Entrance/scripts.pory"
	compare VAR_RESULT, FALSE  @ VAR_RESULT always FALSE here
# 29 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq TrainerHill_Entrance_EventScript_TryFaceAttendant
# 30 "data/maps/TrainerHill_Entrance/scripts.pory"
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
# 31 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 32 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 33 "data/maps/TrainerHill_Entrance/scripts.pory"

# 34 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_TryFaceAttendant:: @ 82680FF
# 35 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_getwon
# 36 "data/maps/TrainerHill_Entrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 37 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
# 38 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 39 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 40 "data/maps/TrainerHill_Entrance/scripts.pory"

# 41 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant:: @ 826811A
# 42 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 43 "data/maps/TrainerHill_Entrance/scripts.pory"

# 44 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnReturn: @ 826811B
# 45 "data/maps/TrainerHill_Entrance/scripts.pory"
	addobject LOCALID_NURSE
# 46 "data/maps/TrainerHill_Entrance/scripts.pory"
	addobject LOCALID_ATTENDANT
# 47 "data/maps/TrainerHill_Entrance/scripts.pory"
	addobject LOCALID_MAN
# 48 "data/maps/TrainerHill_Entrance/scripts.pory"
	addobject LOCALID_GIRL
# 49 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 50 "data/maps/TrainerHill_Entrance/scripts.pory"

# 51 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnLoad: @ 8268128
# 52 "data/maps/TrainerHill_Entrance/scripts.pory"
	compare VAR_TEMP_D, 17
# 53 "data/maps/TrainerHill_Entrance/scripts.pory"
	call_if_eq TrainerHill_Entrance_EventScript_OpenCounterDoor
# 54 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 55 "data/maps/TrainerHill_Entrance/scripts.pory"

# 56 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_OpenCounterDoor:: @ 8268134
# 57 "data/maps/TrainerHill_Entrance/scripts.pory"
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, 0
# 58 "data/maps/TrainerHill_Entrance/scripts.pory"
	return
# 59 "data/maps/TrainerHill_Entrance/scripts.pory"

# 60 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_OnFrame: @ 826813E
# 61 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
# 62 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
# 63 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
# 64 "data/maps/TrainerHill_Entrance/scripts.pory"
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
# 65 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte 0
# 66 "data/maps/TrainerHill_Entrance/scripts.pory"

# 67 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExitElevator:: @ 8268160
# 68 "data/maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 69 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
# 70 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitmovement 0
# 71 "data/maps/TrainerHill_Entrance/scripts.pory"
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, 1
# 72 "data/maps/TrainerHill_Entrance/scripts.pory"
	special DrawWholeMapView
# 73 "data/maps/TrainerHill_Entrance/scripts.pory"
	playse SE_CLICK
# 74 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitse
# 75 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_D, 0
# 76 "data/maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 77 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 78 "data/maps/TrainerHill_Entrance/scripts.pory"

# 79 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExitChallenge:: @ 8268182
# 80 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_0, 1
# 81 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_getstatus
# 82 "data/maps/TrainerHill_Entrance/scripts.pory"
	switch VAR_RESULT
# 83 "data/maps/TrainerHill_Entrance/scripts.pory"
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
# 84 "data/maps/TrainerHill_Entrance/scripts.pory"
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
# 85 "data/maps/TrainerHill_Entrance/scripts.pory"
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge
# 86 "data/maps/TrainerHill_Entrance/scripts.pory"

# 87 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExitChallengeLost:: @ 82681B5
# 88 "data/maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 89 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 90 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
# 91 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge
# 92 "data/maps/TrainerHill_Entrance/scripts.pory"

# 93 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExitChallengeECard:: @ 82681CA
# 94 "data/maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 95 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 96 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
# 97 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_PlayerExitChallenge:: @ 82681DA
# 98 "data/maps/TrainerHill_Entrance/scripts.pory"
	closemessage
# 99 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
# 100 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitmovement 0
# 101 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
# 102 "data/maps/TrainerHill_Entrance/scripts.pory"
	special HealPlayerParty
# 103 "data/maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 104 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_EndExitChallenge:: @ 82681EE
# 105 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 106 "data/maps/TrainerHill_Entrance/scripts.pory"

# 107 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Nurse:: @ 82681EF
# 108 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 109 "data/maps/TrainerHill_Entrance/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 110 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitmessage
# 111 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitbuttonpress
# 112 "data/maps/TrainerHill_Entrance/scripts.pory"
	release
# 113 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 114 "data/maps/TrainerHill_Entrance/scripts.pory"

# 115 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Attendant:: @ 82681FD
# 116 "data/maps/TrainerHill_Entrance/scripts.pory"
	lock
# 117 "data/maps/TrainerHill_Entrance/scripts.pory"
	faceplayer
# 118 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_inchallenge
# 119 "data/maps/TrainerHill_Entrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 120 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq TrainerHill_Entrance_EventScript_ThanksForPlaying
# 121 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
# 122 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_AttendantEnd
# 123 "data/maps/TrainerHill_Entrance/scripts.pory"

# 124 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ThanksForPlaying:: @ 826821F
# 125 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
# 126 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_AttendantEnd:: @ 8268227
# 127 "data/maps/TrainerHill_Entrance/scripts.pory"
	release
# 128 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 129 "data/maps/TrainerHill_Entrance/scripts.pory"

# 130 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_EntryTrigger:: @ 8268229
# 131 "data/maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 132 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
# 133 "data/maps/TrainerHill_Entrance/scripts.pory"
	@goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
# 134 "data/maps/TrainerHill_Entrance/scripts.pory"
	@ Disable Trainer Hill until it's ready
# 135 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_Closed
# 136 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
# 137 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_getsaved
# 138 "data/maps/TrainerHill_Entrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 139 "data/maps/TrainerHill_Entrance/scripts.pory"
	call_if_eq TrainerHill_Entrance_EventScript_SaveGame
# 140 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_allfloorsused
# 141 "data/maps/TrainerHill_Entrance/scripts.pory"
	compare VAR_RESULT, TRUE
# 142 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq TrainerHill_Entrance_EventScript_AllFloorsUsed
# 143 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
# 144 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
# 145 "data/maps/TrainerHill_Entrance/scripts.pory"

# 146 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_AllFloorsUsed:: @ 8268275
# 147 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
# 148 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_AskChallengeTrainers:: @ 826827D
# 149 "data/maps/TrainerHill_Entrance/scripts.pory"
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
# 150 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitmessage
# 151 "data/maps/TrainerHill_Entrance/scripts.pory"
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
# 152 "data/maps/TrainerHill_Entrance/scripts.pory"
	switch VAR_RESULT
# 153 "data/maps/TrainerHill_Entrance/scripts.pory"
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
# 154 "data/maps/TrainerHill_Entrance/scripts.pory"
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
# 155 "data/maps/TrainerHill_Entrance/scripts.pory"
	case 2, TrainerHill_Entrance_EventScript_Info
# 156 "data/maps/TrainerHill_Entrance/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
# 157 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 158 "data/maps/TrainerHill_Entrance/scripts.pory"

# 159 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Info:: @ 82682BA
# 160 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
# 161 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
# 162 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 163 "data/maps/TrainerHill_Entrance/scripts.pory"

# 164 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ChooseChallenge:: @ 82682C8
# 165 "data/maps/TrainerHill_Entrance/scripts.pory"
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
# 166 "data/maps/TrainerHill_Entrance/scripts.pory"
	switch VAR_RESULT
# 167 "data/maps/TrainerHill_Entrance/scripts.pory"
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
# 168 "data/maps/TrainerHill_Entrance/scripts.pory"
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
# 169 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_settag VAR_RESULT
# 170 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
# 171 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_5, 0
# 172 "data/maps/TrainerHill_Entrance/scripts.pory"
	special HealPlayerParty
# 173 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
# 174 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_start
# 175 "data/maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 176 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 177 "data/maps/TrainerHill_Entrance/scripts.pory"

# 178 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_CancelEntry:: @ 8268314
# 179 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_5, 0
# 180 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
# 181 "data/maps/TrainerHill_Entrance/scripts.pory"
	closemessage
# 182 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
# 183 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitmovement 0
# 184 "data/maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 185 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 186 "data/maps/TrainerHill_Entrance/scripts.pory"

# 187 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_SaveGame:: @ 826832E
# 188 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
# 189 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_setsaved
# 190 "data/maps/TrainerHill_Entrance/scripts.pory"
	setvar VAR_TEMP_5, 1
# 191 "data/maps/TrainerHill_Entrance/scripts.pory"
	call Common_EventScript_SaveGame
# 192 "data/maps/TrainerHill_Entrance/scripts.pory"
	compare VAR_RESULT, FALSE
# 193 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto_if_eq TrainerHill_Entrance_EventScript_SaveFailed
# 194 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_setsaved
# 195 "data/maps/TrainerHill_Entrance/scripts.pory"
	return
# 196 "data/maps/TrainerHill_Entrance/scripts.pory"

# 197 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_SaveFailed:: @ 826835C
# 198 "data/maps/TrainerHill_Entrance/scripts.pory"
	trainerhill_clearsaved
# 199 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto TrainerHill_Entrance_EventScript_CancelEntry
# 200 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 201 "data/maps/TrainerHill_Entrance/scripts.pory"

# 202 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Closed:: @ 826836A
# 203 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
# 204 "data/maps/TrainerHill_Entrance/scripts.pory"
	closemessage
# 205 "data/maps/TrainerHill_Entrance/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
# 206 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitmovement 0
# 207 "data/maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 208 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 209 "data/maps/TrainerHill_Entrance/scripts.pory"

# 210 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Movement_PlayerFaceAttendant: @ 826837F
# 211 "data/maps/TrainerHill_Entrance/scripts.pory"
	face_right
# 212 "data/maps/TrainerHill_Entrance/scripts.pory"
	step_end
# 213 "data/maps/TrainerHill_Entrance/scripts.pory"

# 214 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Movement_PushPlayerBackFromCounter: @ 8268381
# 215 "data/maps/TrainerHill_Entrance/scripts.pory"
	walk_down
# 216 "data/maps/TrainerHill_Entrance/scripts.pory"
	step_end
# 217 "data/maps/TrainerHill_Entrance/scripts.pory"

# 218 "data/maps/TrainerHill_Entrance/scripts.pory"
@ Unused
# 219 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Movement_FaceUp: @ 8268383
# 220 "data/maps/TrainerHill_Entrance/scripts.pory"
	face_up
# 221 "data/maps/TrainerHill_Entrance/scripts.pory"
	step_end
# 222 "data/maps/TrainerHill_Entrance/scripts.pory"

# 223 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Movement_PlayerExitElevator: @ 8268385
# 224 "data/maps/TrainerHill_Entrance/scripts.pory"
	walk_down
# 225 "data/maps/TrainerHill_Entrance/scripts.pory"
	walk_down
# 226 "data/maps/TrainerHill_Entrance/scripts.pory"
	step_end
# 227 "data/maps/TrainerHill_Entrance/scripts.pory"

# 228 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Records:: @ 8268388
# 229 "data/maps/TrainerHill_Entrance/scripts.pory"
	lockall
# 230 "data/maps/TrainerHill_Entrance/scripts.pory"
	fadescreen FADE_TO_BLACK
# 231 "data/maps/TrainerHill_Entrance/scripts.pory"
	special ShowTrainerHillRecords
# 232 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitstate
# 233 "data/maps/TrainerHill_Entrance/scripts.pory"
	releaseall
# 234 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 235 "data/maps/TrainerHill_Entrance/scripts.pory"

# 236 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Man:: @ 8268391
# 237 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
# 238 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
# 239 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 240 "data/maps/TrainerHill_Entrance/scripts.pory"

# 241 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ManTrainerHillClosed:: @ 82683A3
# 242 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
# 243 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 244 "data/maps/TrainerHill_Entrance/scripts.pory"

# 245 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Girl:: @ 82683AC
# 246 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
# 247 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
# 248 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 249 "data/maps/TrainerHill_Entrance/scripts.pory"

# 250 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_GirlTrainerHillClosed:: @ 82683BE
# 251 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
# 252 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 253 "data/maps/TrainerHill_Entrance/scripts.pory"

# 254 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_Clerk:: @ 82683C7
# 255 "data/maps/TrainerHill_Entrance/scripts.pory"
	lock
# 256 "data/maps/TrainerHill_Entrance/scripts.pory"
	faceplayer
# 257 "data/maps/TrainerHill_Entrance/scripts.pory"
	message gText_HowMayIServeYou
# 258 "data/maps/TrainerHill_Entrance/scripts.pory"
	waitmessage
# 259 "data/maps/TrainerHill_Entrance/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
# 260 "data/maps/TrainerHill_Entrance/scripts.pory"
	pokemart TrainerHill_Entrance_Pokemart_Basic
# 261 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 262 "data/maps/TrainerHill_Entrance/scripts.pory"
	release
# 263 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 264 "data/maps/TrainerHill_Entrance/scripts.pory"

# 265 "data/maps/TrainerHill_Entrance/scripts.pory"
	.align 2
# 266 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Pokemart_Basic: @ 82683E8
# 267 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 268 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 269 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 270 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_AWAKENING
# 271 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_SPEED
# 272 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 273 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_ATTACK
# 274 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 275 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 276 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 277 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 278 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_NONE
# 279 "data/maps/TrainerHill_Entrance/scripts.pory"
	release
# 280 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 281 "data/maps/TrainerHill_Entrance/scripts.pory"

# 282 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_EventScript_ExpandedPokemart:: @ 8268402
# 283 "data/maps/TrainerHill_Entrance/scripts.pory"
	pokemart TrainerHill_Entrance_Pokemart_Expanded
# 284 "data/maps/TrainerHill_Entrance/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 285 "data/maps/TrainerHill_Entrance/scripts.pory"
	release
# 286 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 287 "data/maps/TrainerHill_Entrance/scripts.pory"

# 288 "data/maps/TrainerHill_Entrance/scripts.pory"
	.align 2
# 289 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Pokemart_Expanded: @ 8268414
# 290 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 291 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_MAX_POTION
# 292 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 293 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 294 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_REVIVE
# 295 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_SPEED
# 296 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 297 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_ATTACK
# 298 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 299 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 300 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 301 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 302 "data/maps/TrainerHill_Entrance/scripts.pory"
	.2byte ITEM_NONE
# 303 "data/maps/TrainerHill_Entrance/scripts.pory"
	release
# 304 "data/maps/TrainerHill_Entrance/scripts.pory"
	end
# 305 "data/maps/TrainerHill_Entrance/scripts.pory"

# 306 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_StillGettingReady: @ 8268430
# 307 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "This is the Trainer Hill where\n"
# 308 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "you may enjoy tag battles with many\l"
# 309 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Trainers.\p"
# 310 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Unfortunately, we're still getting\n"
# 311 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "things ready. Please come back later!$"
# 312 "data/maps/TrainerHill_Entrance/scripts.pory"

# 313 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_WelcomeToTrainerHill: @ 82684C6
# 314 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Welcome!\p"
# 315 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "This is the Trainer Hill where\n"
# 316 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "you may enjoy tag battles with many\l"
# 317 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Trainers!$"
# 318 "data/maps/TrainerHill_Entrance/scripts.pory"

# 319 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_SaveGameBeforeEnter: @ 826851C
# 320 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Is this your first visit here?\p"
# 321 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Before you enter, please save\n"
# 322 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "your game.$"
# 323 "data/maps/TrainerHill_Entrance/scripts.pory"

# 324 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_TrainersUpToFloorX: @ 8268564
# 325 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Let's see…\n"
# 326 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "The Trainers here now are…\p"
# 327 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Up to floor no. {STR_VAR_1}.$"
# 328 "data/maps/TrainerHill_Entrance/scripts.pory"

# 329 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_TrainersInEveryRoom: @ 826859E
# 330 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Let's see…\n"
# 331 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "The Trainers here now are…\p"
# 332 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "There appear to be Trainers gathered\n"
# 333 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "in every room.$"
# 334 "data/maps/TrainerHill_Entrance/scripts.pory"

# 335 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_LikeToChallengeTrainers: @ 82685F8
# 336 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Would you like to challenge the\n"
# 337 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "waiting Trainers?$"
# 338 "data/maps/TrainerHill_Entrance/scripts.pory"

# 339 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_TimeProgessGetSetGo: @ 826862A
# 340 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I will time your progress.\n"
# 341 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Best of luck!\p"
# 342 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "On your marks…\p"
# 343 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Get set…\p"
# 344 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Go!$"
# 345 "data/maps/TrainerHill_Entrance/scripts.pory"

# 346 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_PleaseVisitUsAgain: @ 826866F
# 347 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Please do visit us again!$"
# 348 "data/maps/TrainerHill_Entrance/scripts.pory"

# 349 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_TooBadTremendousEffort: @ 8268689
# 350 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "That was too bad.\p"
# 351 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I think you put in a tremendous\n"
# 352 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "effort in your battling.\p"
# 353 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Please come back and try again!$"
# 354 "data/maps/TrainerHill_Entrance/scripts.pory"

# 355 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_HopeYouGiveItYourBest: @ 82686F4
# 356 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I hope you give it your best.$"
# 357 "data/maps/TrainerHill_Entrance/scripts.pory"

# 358 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_MovedReceptionHereForSwitch: @ 8268712
# 359 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "When the Trainers switch places,\n"
# 360 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "the movement can be hectic.\p"
# 361 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "To avoid the stampede, we moved\n"
# 362 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "the reception counter here.\p"
# 363 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I'm sorry for the inconvenience.$"
# 364 "data/maps/TrainerHill_Entrance/scripts.pory"

# 365 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_ThankYouForPlaying: @ 82687AC
# 366 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Thank you for playing!$"
# 367 "data/maps/TrainerHill_Entrance/scripts.pory"

# 368 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_ExplainTrainerHill: @ 82687C3
# 369 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Here at the Trainer Hill, we conduct\n"
# 370 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "an event called the Time Attack.\p"
# 371 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "It is a race that measures how long\n"
# 372 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "you take to reach our owner on\l"
# 373 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "the rooftop from this counter.\p"
# 374 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "The fastest times are posted on\n"
# 375 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "the Time Board--try competing with\l"
# 376 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "your friends.\p"
# 377 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "In Trainer battles along the way,\n"
# 378 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "neither Exp. Points nor money will\l"
# 379 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "be awarded.$"
# 380 "data/maps/TrainerHill_Entrance/scripts.pory"

# 381 "data/maps/TrainerHill_Entrance/scripts.pory"
@ Unused
# 382 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon: @ 826890D
# 383 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Oh, I'm sorry, but you appear to have\n"
# 384 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "only one Pokémon with you.\p"
# 385 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "You will need at least two Pokémon\n"
# 386 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "to enter this event.$"
# 387 "data/maps/TrainerHill_Entrance/scripts.pory"

# 388 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_YouFinallyCameBravo: @ 8268986
# 389 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Hm! Hm!\p"
# 390 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "You finally came!\n"
# 391 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Yes, you have arrived!\p"
# 392 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Wait! Don't say it!\n"
# 393 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I know why you came all the way\l"
# 394 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "here by yourself!\p"
# 395 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "You wanted to see me, the owner\n"
# 396 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "of the Trainer Hill, because…\p"
# 397 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "You want to form a tag team with me!\n"
# 398 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Wa-hoo!\p"
# 399 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "…Uh?\n"
# 400 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "That's not it?\p"
# 401 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Anyway, I watched you on your way up.\n"
# 402 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Marvelous battling! Bravo, indeed!$"
# 403 "data/maps/TrainerHill_Entrance/scripts.pory"

# 404 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_HaveTheMostMarvelousGift: @ 8268AC5
# 405 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "For a marvelous someone like you,\n"
# 406 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I have the most marvelous gift!$"
# 407 "data/maps/TrainerHill_Entrance/scripts.pory"

# 408 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_FullUpBeBackLaterForThis: @ 8268B07
# 409 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Oh, no, full up with things!\n"
# 410 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "You'll be back later for this!$"
# 411 "data/maps/TrainerHill_Entrance/scripts.pory"

# 412 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_GotHereMarvelouslyQuickly: @ 8268B43
# 413 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Oh, hold on here! Did you possibly get\n"
# 414 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "here marvelously quickly?\p"
# 415 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "How splendid! You needn't have\n"
# 416 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "hurried so to see me!\p"
# 417 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "That is so delightful. I'll have the Time\n"
# 418 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Board at the reception updated!$"
# 419 "data/maps/TrainerHill_Entrance/scripts.pory"

# 420 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_YouWerentVeryQuick: @ 8268C03
# 421 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "But, oh…\n"
# 422 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "You weren't very quick getting here.$"
# 423 "data/maps/TrainerHill_Entrance/scripts.pory"

# 424 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_ArriveZippierNextTime: @ 8268C31
# 425 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Perhaps it would please me more if you\n"
# 426 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "arrived zippier next time.\p"
# 427 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Then, I should be pleased to form\n"
# 428 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "a tag team with you!\p"
# 429 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Until we meet again, amigo!$"
# 430 "data/maps/TrainerHill_Entrance/scripts.pory"

# 431 "data/maps/TrainerHill_Entrance/scripts.pory"
@ Unused
# 432 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner: @ 8268CC6
# 433 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I had the Trainer Hill built for but\n"
# 434 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "one reason and one only!\p"
# 435 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "To find the most suitable partner\n"
# 436 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "with whom I may form a tag team!$"
# 437 "data/maps/TrainerHill_Entrance/scripts.pory"

# 438 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_ChallengeTime: @ 8268D47
# 439 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"
# 440 "data/maps/TrainerHill_Entrance/scripts.pory"

# 441 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead: @ 8268D5A
# 442 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Who knows what sort of Trainers\n"
# 443 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "and Pokémon combos are ahead?\p"
# 444 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "All I know is that I'll knock aside\n"
# 445 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "anyone that stands in my way!$"
# 446 "data/maps/TrainerHill_Entrance/scripts.pory"

# 447 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_CantWaitToTestTheWaters: @ 8268DDA
# 448 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I heard tough Trainers come to this\n"
# 449 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Trainer Hill from all over.\p"
# 450 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I can't wait to test the waters!\p"
# 451 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I'll knock aside anyone that stands\n"
# 452 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "in my way!$"
# 453 "data/maps/TrainerHill_Entrance/scripts.pory"

# 454 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop: @ 8268E6A
# 455 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Do you see the Time Board over there?\p"
# 456 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "My friends and I are trying to see who\n"
# 457 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "can reach the top in the least time.$"
# 458 "data/maps/TrainerHill_Entrance/scripts.pory"

# 459 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen: @ 8268EDC
# 460 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Do you know when they're opening\n"
# 461 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "this place up?\p"
# 462 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "I'm waiting here to be the first\n"
# 463 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "challenger ever!$"
# 464 "data/maps/TrainerHill_Entrance/scripts.pory"

# 465 "data/maps/TrainerHill_Entrance/scripts.pory"
TrainerHill_Elevator_Text_ReturnToReception: @ 8268F3E
# 466 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "Would you like to return to\n"
# 467 "data/maps/TrainerHill_Entrance/scripts.pory"
	.string "the reception counter?$"
