# 1 "data/maps/SouthernIsland_Interior/scripts.pory"

# 2 "data/maps/SouthernIsland_Interior/scripts.pory"
.set LOCALID_LATI, 2
# 3 "data/maps/SouthernIsland_Interior/scripts.pory"

# 4 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_MapScripts:: @ 8242A45
# 5 "data/maps/SouthernIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
# 6 "data/maps/SouthernIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
# 7 "data/maps/SouthernIsland_Interior/scripts.pory"
	.byte 0
# 8 "data/maps/SouthernIsland_Interior/scripts.pory"

# 9 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_OnResume: @ 8242A50
# 10 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
# 11 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 12 "data/maps/SouthernIsland_Interior/scripts.pory"

# 13 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_TryRemoveLati:: @ 8242A5A
# 14 "data/maps/SouthernIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 16 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 17 "data/maps/SouthernIsland_Interior/scripts.pory"
	removeobject LOCALID_LATI
# 18 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 19 "data/maps/SouthernIsland_Interior/scripts.pory"

# 20 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_OnTransition: @ 8242A6E
# 21 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_ROAMER_POKEMON, 0
# 22 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_eq SouthernIsland_Interior_EventScript_SetUpLatios
# 23 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_ROAMER_POKEMON, 0
# 24 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_ne SouthernIsland_Interior_EventScript_SetUpLatias
# 25 "data/maps/SouthernIsland_Interior/scripts.pory"
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
# 26 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 27 "data/maps/SouthernIsland_Interior/scripts.pory"

# 28 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetUpLatios:: @ 8242A8A
# 29 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
# 30 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_TEMP_4, SPECIES_LATIOS
# 31 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 32 "data/maps/SouthernIsland_Interior/scripts.pory"

# 33 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetUpLatias:: @ 8242A95
# 34 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
# 35 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_TEMP_4, SPECIES_LATIAS
# 36 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 37 "data/maps/SouthernIsland_Interior/scripts.pory"

# 38 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetUpPlayerGfx:: @ 8242AA0
# 39 "data/maps/SouthernIsland_Interior/scripts.pory"
	checkplayergender
# 40 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_RESULT, MALE
# 41 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq SouthernIsland_Interior_EventScript_SetBrendanGfx
# 42 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_RESULT, FEMALE
# 43 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq SouthernIsland_Interior_EventScript_SetMayGfx
# 44 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 45 "data/maps/SouthernIsland_Interior/scripts.pory"

# 46 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetBrendanGfx:: @ 8242AB8
# 47 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 48 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 49 "data/maps/SouthernIsland_Interior/scripts.pory"

# 50 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetMayGfx:: @ 8242ABE
# 51 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 52 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 53 "data/maps/SouthernIsland_Interior/scripts.pory"

# 54 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_TryLatiEncounter:: @ 8242AC4
# 55 "data/maps/SouthernIsland_Interior/scripts.pory"
	lockall
# 56 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_0x8008, 12
# 57 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto SouthernIsland_Interior_EventScript_Lati
# 58 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 59 "data/maps/SouthernIsland_Interior/scripts.pory"

# 60 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_Lati:: @ 8242AD0
# 61 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
# 62 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
# 63 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
# 64 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
# 65 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
# 66 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_TEMP_2
# 67 "data/maps/SouthernIsland_Interior/scripts.pory"
	special SpawnCameraObject
# 68 "data/maps/SouthernIsland_Interior/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
# 69 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitmovement 0
# 70 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 50
# 71 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitse
# 72 "data/maps/SouthernIsland_Interior/scripts.pory"
	playmoncry VAR_TEMP_4, 0
# 73 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 30
# 74 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitmoncry
# 75 "data/maps/SouthernIsland_Interior/scripts.pory"
	addobject LOCALID_LATI
# 76 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 30
# 77 "data/maps/SouthernIsland_Interior/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
# 78 "data/maps/SouthernIsland_Interior/scripts.pory"
	applymovement LOCALID_LATI, SouthernIsland_Interior_Movement_LatiApproach
# 79 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitmovement 0
# 80 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 50
# 81 "data/maps/SouthernIsland_Interior/scripts.pory"
	special RemoveCameraObject
# 82 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_LATI
# 83 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_ROAMER_POKEMON, 0
# 84 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_eq SouthernIsland_Interior_EventScript_SetLatiosBattleVars
# 85 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_ROAMER_POKEMON, 0
# 86 "data/maps/SouthernIsland_Interior/scripts.pory"
	call_if_ne SouthernIsland_Interior_EventScript_SetLatiasBattleVars
# 87 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 88 "data/maps/SouthernIsland_Interior/scripts.pory"
	special BattleSetup_StartLatiBattle
# 89 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitstate
# 90 "data/maps/SouthernIsland_Interior/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 91 "data/maps/SouthernIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 92 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 93 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq SouthernIsland_Interior_EventScript_LatiDefeated
# 94 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 95 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq SouthernIsland_Interior_EventScript_RanFromLati
# 96 "data/maps/SouthernIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 97 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_eq SouthernIsland_Interior_EventScript_RanFromLati
# 98 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
# 99 "data/maps/SouthernIsland_Interior/scripts.pory"
	releaseall
# 100 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 101 "data/maps/SouthernIsland_Interior/scripts.pory"

# 102 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_LatiDefeated:: @ 8242B81
# 103 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
# 104 "data/maps/SouthernIsland_Interior/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_4
# 105 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 106 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 107 "data/maps/SouthernIsland_Interior/scripts.pory"

# 108 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_RanFromLati:: @ 8242B8F
# 109 "data/maps/SouthernIsland_Interior/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_4
# 110 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 111 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 112 "data/maps/SouthernIsland_Interior/scripts.pory"

# 113 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_Sign:: @ 8242B9A
# 114 "data/maps/SouthernIsland_Interior/scripts.pory"
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
# 115 "data/maps/SouthernIsland_Interior/scripts.pory"
	goto_if_unset FLAG_RECEIVED_LATI_STONES SouthernIsland_Interior_EventScript_GiveLatiStones
# 116 "data/maps/SouthernIsland_Interior/scripts.pory"
	releaseall
# 117 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 118 "data/maps/SouthernIsland_Interior/scripts.pory"

# 119 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_GiveLatiStones::
# 120 "data/maps/SouthernIsland_Interior/scripts.pory"
	closemessage
# 121 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay 20
# 122 "data/maps/SouthernIsland_Interior/scripts.pory"
	playse SE_M_DETECT
# 123 "data/maps/SouthernIsland_Interior/scripts.pory"
	dofieldeffectsparkle 13, 11, 0
# 124 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 125 "data/maps/SouthernIsland_Interior/scripts.pory"
	playse SE_PIN
# 126 "data/maps/SouthernIsland_Interior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 127 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitmovement 0
# 128 "data/maps/SouthernIsland_Interior/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 129 "data/maps/SouthernIsland_Interior/scripts.pory"
	waitmovement 0
# 130 "data/maps/SouthernIsland_Interior/scripts.pory"
	giveitem ITEM_LATIOSITE
# 131 "data/maps/SouthernIsland_Interior/scripts.pory"
	giveitem ITEM_LATIASITE
# 132 "data/maps/SouthernIsland_Interior/scripts.pory"
	setflag FLAG_RECEIVED_LATI_STONES
# 133 "data/maps/SouthernIsland_Interior/scripts.pory"
	releaseall
# 134 "data/maps/SouthernIsland_Interior/scripts.pory"
	end
# 135 "data/maps/SouthernIsland_Interior/scripts.pory"

# 136 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetLatiosBattleVars:: @ 8242BA4
# 137 "data/maps/SouthernIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 138 "data/maps/SouthernIsland_Interior/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT @ level
# 139 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_0x8004, SPECIES_LATIOS
# 140 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_0x8006, ITEM_SOUL_DEW
# 141 "data/maps/SouthernIsland_Interior/scripts.pory"
	special CreateEventLegalEnemyMon
# 142 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 143 "data/maps/SouthernIsland_Interior/scripts.pory"

# 144 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_EventScript_SetLatiasBattleVars:: @ 8242BB7
# 145 "data/maps/SouthernIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 146 "data/maps/SouthernIsland_Interior/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT @ level
# 147 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_0x8004, SPECIES_LATIAS
# 148 "data/maps/SouthernIsland_Interior/scripts.pory"
	setvar VAR_0x8006, ITEM_SOUL_DEW
# 149 "data/maps/SouthernIsland_Interior/scripts.pory"
	special CreateEventLegalEnemyMon
# 150 "data/maps/SouthernIsland_Interior/scripts.pory"
	return
# 151 "data/maps/SouthernIsland_Interior/scripts.pory"

# 152 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_Movement_CameraPanUp: @ 8242BCA
# 153 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_up
# 154 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_up
# 155 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_up
# 156 "data/maps/SouthernIsland_Interior/scripts.pory"
	step_end
# 157 "data/maps/SouthernIsland_Interior/scripts.pory"

# 158 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_Movement_CameraPanDown: @ 8242BCE
# 159 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 160 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 161 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 162 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 163 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 164 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 165 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 166 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 167 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 168 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 169 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_in_place_fastest_up
# 170 "data/maps/SouthernIsland_Interior/scripts.pory"
	step_end
# 171 "data/maps/SouthernIsland_Interior/scripts.pory"

# 172 "data/maps/SouthernIsland_Interior/scripts.pory"
SouthernIsland_Interior_Movement_LatiApproach: @ 8242BDA
# 173 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 174 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 175 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 176 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 177 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 178 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 179 "data/maps/SouthernIsland_Interior/scripts.pory"
	delay_16
# 180 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 181 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 182 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 183 "data/maps/SouthernIsland_Interior/scripts.pory"
	walk_down
# 184 "data/maps/SouthernIsland_Interior/scripts.pory"
	step_end
