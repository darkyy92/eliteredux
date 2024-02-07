# 1 "data/maps/SkyPillar_Top/scripts.pory"

# 2 "data/maps/SkyPillar_Top/scripts.pory"
.set LOCALID_RAYQUAZA_SLEEPING, 1
# 3 "data/maps/SkyPillar_Top/scripts.pory"

# 4 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_MapScripts:: @ 82396B8
# 5 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_OnResume
# 6 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_OnTransition
# 7 "data/maps/SkyPillar_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_OnWarp
# 8 "data/maps/SkyPillar_Top/scripts.pory"
	.byte 0
# 9 "data/maps/SkyPillar_Top/scripts.pory"

# 10 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnResume: @ 82396C8
# 11 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SkyPillar_Top_EventScript_TryRemoveRayquaza
# 12 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 13 "data/maps/SkyPillar_Top/scripts.pory"

# 14 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_TryRemoveRayquaza:: @ 82396D2
# 15 "data/maps/SkyPillar_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 16 "data/maps/SkyPillar_Top/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 17 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 18 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 19 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 20 "data/maps/SkyPillar_Top/scripts.pory"

# 21 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnTransition: @ 82396E6
# 22 "data/maps/SkyPillar_Top/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 2
# 23 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_lt SkyPillar_Top_EventScript_SetCleanLayout
# 24 "data/maps/SkyPillar_Top/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 2
# 25 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_ge SkyPillar_Top_EventScript_TryShowRayquaza
# 26 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 27 "data/maps/SkyPillar_Top/scripts.pory"

# 28 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_SetCleanLayout:: @ 82396FD
# 29 "data/maps/SkyPillar_Top/scripts.pory"
	setmaplayoutindex LAYOUT_SKY_PILLAR_TOP_CLEAN
# 30 "data/maps/SkyPillar_Top/scripts.pory"
	setobjectmovementtype LOCALID_RAYQUAZA_SLEEPING, MOVEMENT_TYPE_FACE_DOWN
# 31 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 32 "data/maps/SkyPillar_Top/scripts.pory"

# 33 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_TryShowRayquaza:: @ 8239705
# 34 "data/maps/SkyPillar_Top/scripts.pory"
	call_if_unset FLAG_DEFEATED_RAYQUAZA, SkyPillar_Top_EventScript_ShowRayquaza
# 35 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 36 "data/maps/SkyPillar_Top/scripts.pory"

# 37 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_ShowRayquaza:: @ 823970F
# 38 "data/maps/SkyPillar_Top/scripts.pory"
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
# 39 "data/maps/SkyPillar_Top/scripts.pory"
	return
# 40 "data/maps/SkyPillar_Top/scripts.pory"

# 41 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_OnWarp: @ 8239713
# 42 "data/maps/SkyPillar_Top/scripts.pory"
	map_script_2 VAR_SKY_PILLAR_STATE, 0, SkyPillar_Top_EventScript_RayquazaFaceDown
# 43 "data/maps/SkyPillar_Top/scripts.pory"
	.2byte 0
# 44 "data/maps/SkyPillar_Top/scripts.pory"

# 45 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RayquazaFaceDown:: @ 823971D
# 46 "data/maps/SkyPillar_Top/scripts.pory"
	turnobject LOCALID_RAYQUAZA_SLEEPING, DIR_SOUTH
# 47 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 48 "data/maps/SkyPillar_Top/scripts.pory"

# 49 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_Rayquaza:: @ 8239722
# 50 "data/maps/SkyPillar_Top/scripts.pory"
	lockall
# 51 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 52 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, 2
# 53 "data/maps/SkyPillar_Top/scripts.pory"
	delay 40
# 54 "data/maps/SkyPillar_Top/scripts.pory"
	waitmoncry
# 55 "data/maps/SkyPillar_Top/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 56 "data/maps/SkyPillar_Top/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 57 "data/maps/SkyPillar_Top/scripts.pory"
	setwildbattle SPECIES_RAYQUAZA, VAR_0x800A, ITEM_DRAGON_GEM
# 58 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 59 "data/maps/SkyPillar_Top/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 60 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 61 "data/maps/SkyPillar_Top/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 62 "data/maps/SkyPillar_Top/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 63 "data/maps/SkyPillar_Top/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 64 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq SkyPillar_Top_EventScript_DefeatedRayquaza
# 65 "data/maps/SkyPillar_Top/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 66 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq SkyPillar_Top_EventScript_RanFromRayquaza
# 67 "data/maps/SkyPillar_Top/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 68 "data/maps/SkyPillar_Top/scripts.pory"
	goto_if_eq SkyPillar_Top_EventScript_RanFromRayquaza
# 69 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_DEFEATED_RAYQUAZA
# 70 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 71 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 72 "data/maps/SkyPillar_Top/scripts.pory"

# 73 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_DefeatedRayquaza:: @ 8239768
# 74 "data/maps/SkyPillar_Top/scripts.pory"
	setflag FLAG_DEFEATED_RAYQUAZA
# 75 "data/maps/SkyPillar_Top/scripts.pory"
	goto SkyPillar_Top_EventScript_DefeatedRayquaza2
# 76 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 77 "data/maps/SkyPillar_Top/scripts.pory"

# 78 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RanFromRayquaza:: @ 8239771
# 79 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, SPECIES_RAYQUAZA
# 80 "data/maps/SkyPillar_Top/scripts.pory"
	goto SkyPillar_Top_EventScript_RanFromRayquaza2
# 81 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 82 "data/maps/SkyPillar_Top/scripts.pory"

# 83 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_DefeatedRayquaza2:: @ 823977C
# 84 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 85 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 86 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 87 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 88 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 89 "data/maps/SkyPillar_Top/scripts.pory"

# 90 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_RanFromRayquaza2:: @ 8239785
# 91 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 92 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject VAR_LAST_TALKED
# 93 "data/maps/SkyPillar_Top/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 94 "data/maps/SkyPillar_Top/scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 95 "data/maps/SkyPillar_Top/scripts.pory"
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
# 96 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 97 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 98 "data/maps/SkyPillar_Top/scripts.pory"

# 99 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_EventScript_AwakenRayquaza:: @ 823979A
# 100 "data/maps/SkyPillar_Top/scripts.pory"
	lockall
# 101 "data/maps/SkyPillar_Top/scripts.pory"
	fadeoutbgm 1
# 102 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 103 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 104 "data/maps/SkyPillar_Top/scripts.pory"
	special SpawnCameraObject
# 105 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
# 106 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 107 "data/maps/SkyPillar_Top/scripts.pory"
	special RemoveCameraObject
# 108 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaStir
# 109 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 110 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 111 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, 2
# 112 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 113 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 114 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 115 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 116 "data/maps/SkyPillar_Top/scripts.pory"
	special ShakeCamera
# 117 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 118 "data/maps/SkyPillar_Top/scripts.pory"
	waitse
# 119 "data/maps/SkyPillar_Top/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, 2
# 120 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 121 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 122 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 123 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 124 "data/maps/SkyPillar_Top/scripts.pory"
	special ShakeCamera
# 125 "data/maps/SkyPillar_Top/scripts.pory"
	waitstate
# 126 "data/maps/SkyPillar_Top/scripts.pory"
	waitmoncry
# 127 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement LOCALID_RAYQUAZA_SLEEPING, SkyPillar_Top_Movement_RayquazaFlyOff
# 128 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 129 "data/maps/SkyPillar_Top/scripts.pory"
	removeobject LOCALID_RAYQUAZA_SLEEPING
# 130 "data/maps/SkyPillar_Top/scripts.pory"
	msgbox SkyPillar_Top_Text_RayquazaFlewOff, MSGBOX_DEFAULT
# 131 "data/maps/SkyPillar_Top/scripts.pory"
	closemessage
# 132 "data/maps/SkyPillar_Top/scripts.pory"
	delay 20
# 133 "data/maps/SkyPillar_Top/scripts.pory"
	fadeinbgm 1
# 134 "data/maps/SkyPillar_Top/scripts.pory"
	special SpawnCameraObject
# 135 "data/maps/SkyPillar_Top/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SkyPillar_Top_Movement_CameraPanDown
# 136 "data/maps/SkyPillar_Top/scripts.pory"
	waitmovement 0
# 137 "data/maps/SkyPillar_Top/scripts.pory"
	special RemoveCameraObject
# 138 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 5
# 139 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 1
# 140 "data/maps/SkyPillar_Top/scripts.pory"
	setvar VAR_SKY_PILLAR_RAQUAZA_CRY_DONE, 1
# 141 "data/maps/SkyPillar_Top/scripts.pory"
	releaseall
# 142 "data/maps/SkyPillar_Top/scripts.pory"
	end
# 143 "data/maps/SkyPillar_Top/scripts.pory"

# 144 "data/maps/SkyPillar_Top/scripts.pory"
@ Rayquaza has unusual movement frames
# 145 "data/maps/SkyPillar_Top/scripts.pory"
@ See comments, or sAnimTable_Rayquaza
# 146 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_RayquazaStir: @ 823983A
# 147 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 148 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_fast_left  @ Coiled, awake
# 149 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 150 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 151 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 152 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 153 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 154 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_left  @ Coiled, mouth open
# 155 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 156 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_right  @ Normal, awake
# 157 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 158 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 159 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 160 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 161 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 162 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 163 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 164 "data/maps/SkyPillar_Top/scripts.pory"

# 165 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_RayquazaFlyOff: @ 823984B
# 166 "data/maps/SkyPillar_Top/scripts.pory"
	delay_16
# 167 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_down  @ Coiled, asleep
# 168 "data/maps/SkyPillar_Top/scripts.pory"
	delay_8
# 169 "data/maps/SkyPillar_Top/scripts.pory"
	walk_in_place_right  @ Normal, awake
# 170 "data/maps/SkyPillar_Top/scripts.pory"
	delay_8
# 171 "data/maps/SkyPillar_Top/scripts.pory"
	walk_fastest_up  @ Fly up
# 172 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 173 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 174 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 175 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 176 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 177 "data/maps/SkyPillar_Top/scripts.pory"
	slide_up
# 178 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 179 "data/maps/SkyPillar_Top/scripts.pory"

# 180 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_CameraPanUp: @ 8239858
# 181 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 182 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 183 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_up
# 184 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 185 "data/maps/SkyPillar_Top/scripts.pory"

# 186 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Movement_CameraPanDown: @ 823985C
# 187 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 188 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 189 "data/maps/SkyPillar_Top/scripts.pory"
	walk_slow_down
# 190 "data/maps/SkyPillar_Top/scripts.pory"
	step_end
# 191 "data/maps/SkyPillar_Top/scripts.pory"

# 192 "data/maps/SkyPillar_Top/scripts.pory"
SkyPillar_Top_Text_RayquazaFlewOff: @ 8239860
# 193 "data/maps/SkyPillar_Top/scripts.pory"
	.string "The awakened Rayquaza flew off…$"
