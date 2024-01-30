# 1 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 2 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_GRUNT_1, 1
# 3 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_GRUNT_2, 2
# 4 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_SHELLY, 3
# 5 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_SCIENTIST, 5
# 6 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_GRUNT_3, 7
# 7 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
.set LOCALID_GRUNT_4, 8
# 8 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 9 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_MapScripts:: @ 826FF1E
# 10 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
# 11 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.byte 0
# 12 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 13 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_OnTransition: @ 826FF24
# 14 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	compare VAR_WEATHER_INSTITUTE_STATE, 0
# 15 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_eq Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
# 16 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	compare VAR_WEATHER_INSTITUTE_STATE, 1
# 17 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_eq Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
# 18 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
# 19 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 20 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 21 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere:: @ 826FF44
# 22 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
# 23 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
# 24 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 25 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 26 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone:: @ 826FF50
# 27 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
# 28 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
# 29 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 30 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 31 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear:: @ 826FF5C
# 32 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
# 33 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
# 34 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 35 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 36 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt5:: @ 826FF68
# 37 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
# 38 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
# 39 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 40 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 41 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt2:: @ 826FF7F
# 42 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
# 43 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 44 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 45 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 46 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Grunt3:: @ 826FF96
# 47 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
# 48 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 49 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 50 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 51 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_Shelly:: @ 826FFAD
# 52 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
# 53 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
# 54 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 55 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 56 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ShellyDefeated:: @ 826FFC8
# 57 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
# 58 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 59 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	addobject LOCALID_GRUNT_3
# 60 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
# 61 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
# 62 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 63 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
# 64 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 65 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	playse SE_PIN
# 66 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
# 67 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 68 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
# 69 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 70 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
# 71 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	closemessage
# 72 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
# 73 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
# 74 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadedefaultbgm
# 75 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 76 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
# 77 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
# 78 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 79 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 80 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_SHELLY
# 81 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 82 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 83 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
# 84 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 85 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 86 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
# 87 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmovement 0
# 88 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	copyobjectxytoperm LOCALID_SCIENTIST
# 89 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
# 90 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 91 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 92 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastform:: @ 827004D
# 93 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
# 94 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_CASTFORM
# 95 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 96 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 97 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	givemon SPECIES_CASTFORM, VAR_0x800A, ITEM_MYSTIC_WATER
# 98 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	compare VAR_RESULT, 0
# 99 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
# 100 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	compare VAR_RESULT, 1
# 101 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
# 102 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 103 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 104 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 105 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty:: @ 8270085
# 106 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
# 107 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 108 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	compare VAR_RESULT, NO
# 109 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 110 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 111 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 112 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 113 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 114 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 115 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC:: @ 82700AD
# 116 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
# 117 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 118 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	compare VAR_RESULT, NO
# 119 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
# 120 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 121 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
# 122 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 123 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 124 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_SendCastformToPC:: @ 82700D0
# 125 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 126 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
# 127 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 128 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 129 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare:: @ 82700DB
# 130 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 131 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
# 132 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitmessage
# 133 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	waitfanfare
# 134 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	bufferspeciesname 0, SPECIES_CASTFORM
# 135 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 136 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 137 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ExplainCastform:: @ 82700EA
# 138 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
# 139 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_RECEIVED_CASTFORM
# 140 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 141 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 142 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 143 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather:: @ 82700F7
# 144 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
# 145 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
# 146 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 147 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 148 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 149 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather:: @ 827010A
# 150 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setvar VAR_0x8004, 0
# 151 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
# 152 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
# 153 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	compare VAR_0x8004, 2  @ Both defeated
# 154 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather
# 155 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
# 156 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
# 157 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	compare VAR_RESULT, 1
# 158 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_KyogreWeather
# 159 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
# 160 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 161 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 162 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 163 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_KyogreWeather:: @ 827014F
# 164 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
# 165 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 166 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 167 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 168 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather:: @ 8270159
# 169 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	special CreateAbnormalWeatherEvent
# 170 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	setflag FLAG_TEMP_2
# 171 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 172 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 173 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated:: @ 8270160
# 174 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	addvar VAR_0x8004, 1
# 175 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	return
# 176 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 177 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather:: @ 8270166
# 178 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
# 179 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	release
# 180 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 181 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 182 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_GruntApproachShelly: @ 8270170
# 183 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 184 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 185 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 186 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 187 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 188 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 189 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 190 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 191 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 192 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 193 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_fast_left
# 194 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 195 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 196 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay: @ 827017C
# 197 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 198 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 199 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 200 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 201 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	delay_16
# 202 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	ride_water_current_up
# 203 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_in_place_fastest_down
# 204 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 205 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 206 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition: @ 8270184
# 207 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	slide_down
# 208 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_in_place_fastest_left
# 209 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 210 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 211 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer: @ 8270187
# 212 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 213 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 214 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	walk_right
# 215 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	step_end
# 216 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 217 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_EventScript_WeatherScientist:: @ 827018B
# 218 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	lock
# 219 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	faceplayer
# 220 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
# 221 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
# 222 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	end
# 223 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 224 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2Intro: @ 827019C
# 225 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "The Institute created a type of\n"
# 226 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Pokémon that has something to do with\l"
# 227 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the weather. We're here to take them!$"
# 228 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 229 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2Defeat: @ 8270208
# 230 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Our plan's being spoiled by a kid?$"
# 231 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 232 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt2PostBattle: @ 827022B
# 233 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "If the Pokémon they made here can\n"
# 234 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "control the weather freely, then we of\l"
# 235 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Team Aqua definitely need it!$"
# 236 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 237 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3Intro: @ 8270292
# 238 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We're Team Aqua!\n"
# 239 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We appear wherever anything rare is\l"
# 240 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "found!$"
# 241 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 242 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3Defeat: @ 82702CE
# 243 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You got me!$"
# 244 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 245 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt3PostBattle: @ 82702DA
# 246 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You don't have any idea what we of\n"
# 247 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Team Aqua are working towards!\l"
# 248 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You stay out of our way!$"
# 249 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 250 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5Intro: @ 8270335
# 251 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Don't tell me you're looking for that\n"
# 252 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "weather Pokémon, too?\p"
# 253 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "That's a no-no!\n"
# 254 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We were here to get it first!$"
# 255 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 256 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5Defeat: @ 827039F
# 257 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Oh, will you look at my Pokémon?$"
# 258 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 259 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_Grunt5PostBattle: @ 82703C0
# 260 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Humph, so what?\n"
# 261 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What we want…\p"
# 262 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What we really want isn't here…\n"
# 263 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ihihihihi…$"
# 264 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 265 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyIntro: @ 8270409
# 266 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\p"
# 267 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're going to meddle in Team Aqua's\n"
# 268 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "affairs?\p"
# 269 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're either absolutely fearless,\n"
# 270 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "simply ignorant, or both!\p"
# 271 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're so cute, you're disgusting!\n"
# 272 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I'll put you down, kiddy!$"
# 273 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 274 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyDefeat: @ 82704BD
# 275 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\n"
# 276 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "You're disgustingly strong!$"
# 277 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 278 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ShellyPostBattle: @ 82704E4
# 279 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "It's bad enough to have Team Magma\n"
# 280 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "blunder about, but now there's you!\p"
# 281 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What makes you want to sniff around\n"
# 282 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "in our business, anyway?$"
# 283 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 284 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy: @ 8270568
# 285 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We have a situation here!\p"
# 286 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "A Team Magma mob just passed\n"
# 287 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the Weather Institute.\p"
# 288 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "They appear to be headed for\n"
# 289 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Mt. Pyre!$"
# 290 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 291 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre: @ 82705DD
# 292 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "What?!\p"
# 293 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We can't waste any more time here!\n"
# 294 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "We have to hurry to Mt. Pyre, too!\p"
# 295 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Ahahahaha!\n"
# 296 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Team Magma, just you wait!$"
# 297 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 298 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon: @ 8270650
# 299 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Thanks!\n"
# 300 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Thanks to you, we're safe!\p"
# 301 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "It might be an odd way of thanking you,\n"
# 302 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "but take this Pokémon.$"
# 303 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 304 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
@ Unused
# 305 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon: @ 82706B2
# 306 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Hm? You don't seem to have any room\n"
# 307 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "for this Pokémon.$"
# 308 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 309 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform: @ 82706E8
# 310 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{PLAYER} received Castform!$"
# 311 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 312 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather: @ 82706FE
# 313 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "That Pokémon changes shape according\n"
# 314 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "to the weather conditions.\p"
# 315 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "There're plenty of them in the\n"
# 316 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Institute--go ahead and take it.$"
# 317 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 318 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous: @ 827077E
# 319 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I've been researching rain for many\n"
# 320 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "years, but it's ridiculous to think that\l"
# 321 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "humans can freely change the weather.$"
# 322 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 323 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_GroudonWeather: @ 82707F1
# 324 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I track weather patterns over\n"
# 325 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the Hoenn region.\p"
# 326 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Presently, a drought has been recorded\n"
# 327 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "in {STR_VAR_1}.\p"
# 328 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Could that mean, somewhere near\n"
# 329 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{STR_VAR_1}…$"
# 330 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 331 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_KyogreWeather: @ 8270873
# 332 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I track weather patterns over\n"
# 333 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "the Hoenn region.\p"
# 334 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Presently, heavy rainfall has been\n"
# 335 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "recorded over {STR_VAR_1}.\p"
# 336 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Could that mean, somewhere near\n"
# 337 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "{STR_VAR_1}…$"
# 338 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"

# 339 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
Route119_WeatherInstitute_2F_Text_NoAbnormalWeather: @ 82708FC
# 340 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Abnormal weather conditions are\n"
# 341 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "no longer being reported.\p"
# 342 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "The occasional rainfall is a blessing,\n"
# 343 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "really.$"
