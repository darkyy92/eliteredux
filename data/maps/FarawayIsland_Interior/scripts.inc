# 1 "data/maps/FarawayIsland_Interior/scripts.pory"

# 2 "data/maps/FarawayIsland_Interior/scripts.pory"
.set LOCALID_MEW, 1
# 3 "data/maps/FarawayIsland_Interior/scripts.pory"

# 4 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_MapScripts:: @ 8267CFA
# 5 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FarawayIsland_Interior_OnResume
# 6 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Interior_OnTransition
# 7 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Interior_OnFrame
# 8 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, FarawayIsland_Interior_OnReturnToField
# 9 "data/maps/FarawayIsland_Interior/scripts.pory"
	.byte 0
# 10 "data/maps/FarawayIsland_Interior/scripts.pory"

# 11 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_OnReturnToField: @ 8267D0F
# 12 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TrySetMewAboveGrass
# 13 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 14 "data/maps/FarawayIsland_Interior/scripts.pory"

# 15 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_TrySetMewAboveGrass:: @ 8267D19
# 16 "data/maps/FarawayIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 17 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 18 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq FarawayIsland_Interior_EventScript_SetMewAboveGrass
# 19 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 20 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq FarawayIsland_Interior_EventScript_SetMewAboveGrass
# 21 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 22 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq FarawayIsland_Interior_EventScript_SetMewAboveGrass
# 23 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_MON_TELEPORTED
# 24 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq FarawayIsland_Interior_EventScript_SetMewAboveGrass
# 25 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 26 "data/maps/FarawayIsland_Interior/scripts.pory"

# 27 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_SetMewAboveGrass:: @ 8267D4B
# 28 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, 1
# 29 "data/maps/FarawayIsland_Interior/scripts.pory"
	special SetMewAboveGrass
# 30 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 31 "data/maps/FarawayIsland_Interior/scripts.pory"

# 32 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_OnResume: @ 8267D54
# 33 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TryRemoveMew
# 34 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 35 "data/maps/FarawayIsland_Interior/scripts.pory"

# 36 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_TryRemoveMew:: @ 8267D5E
# 37 "data/maps/FarawayIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 38 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
# 39 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_ne Common_EventScript_NopReturn
# 40 "data/maps/FarawayIsland_Interior/scripts.pory"
	removeobject VAR_LAST_TALKED
# 41 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 42 "data/maps/FarawayIsland_Interior/scripts.pory"

# 43 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_OnTransition: @ 8267D72
# 44 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_FARAWAY_ISLAND_STEP_COUNTER, 0
# 45 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_TEMP_1, 1
# 46 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_unset FLAG_CAUGHT_MEW, FarawayIsland_Interior_EventScript_TryShowMew
# 47 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 48 "data/maps/FarawayIsland_Interior/scripts.pory"

# 49 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_TryShowMew:: @ 8267D86
# 50 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_set FLAG_DEFEATED_MEW, Common_EventScript_NopReturn
# 51 "data/maps/FarawayIsland_Interior/scripts.pory"
	clearflag FLAG_HIDE_MEW
# 52 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_TEMP_1, 0
# 53 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 54 "data/maps/FarawayIsland_Interior/scripts.pory"

# 55 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_OnFrame: @ 8267D98
# 56 "data/maps/FarawayIsland_Interior/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, FarawayIsland_Interior_EventScript_FindMew
# 57 "data/maps/FarawayIsland_Interior/scripts.pory"
	.2byte 0
# 58 "data/maps/FarawayIsland_Interior/scripts.pory"

# 59 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FindMew:: @ 8267DA2
# 60 "data/maps/FarawayIsland_Interior/scripts.pory"
	lockall
# 61 "data/maps/FarawayIsland_Interior/scripts.pory"
	playse SE_PIN
# 62 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_MEW, Common_Movement_ExclamationMark
# 63 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 64 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_MEW, Common_Movement_Delay48
# 65 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 66 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewMoveAndHide
# 67 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 68 "data/maps/FarawayIsland_Interior/scripts.pory"
	copyobjectxytoperm LOCALID_MEW
# 69 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_TEMP_1, 1
# 70 "data/maps/FarawayIsland_Interior/scripts.pory"
	releaseall
# 71 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 72 "data/maps/FarawayIsland_Interior/scripts.pory"

# 73 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewMoveAndHide: @ 8267DCE
# 74 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_up
# 75 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_up
# 76 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_up
# 77 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_fastest_down
# 78 "data/maps/FarawayIsland_Interior/scripts.pory"
	set_invisible
# 79 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 80 "data/maps/FarawayIsland_Interior/scripts.pory"

# 81 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewAppear: @ 8267DD4
# 82 "data/maps/FarawayIsland_Interior/scripts.pory"
	set_visible
# 83 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 84 "data/maps/FarawayIsland_Interior/scripts.pory"

# 85 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewFloatUpNorth: @ 8267DD6
# 86 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock_facing_direction
# 87 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 88 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 89 "data/maps/FarawayIsland_Interior/scripts.pory"
	unlock_facing_direction
# 90 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_down
# 91 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_down
# 92 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 93 "data/maps/FarawayIsland_Interior/scripts.pory"

# 94 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewFloatUpSouth: @ 8267DDD
# 95 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock_facing_direction
# 96 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 97 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 98 "data/maps/FarawayIsland_Interior/scripts.pory"
	unlock_facing_direction
# 99 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_up
# 100 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_up
# 101 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 102 "data/maps/FarawayIsland_Interior/scripts.pory"

# 103 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewFloatUpWest: @ 8267DE4
# 104 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock_facing_direction
# 105 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 106 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 107 "data/maps/FarawayIsland_Interior/scripts.pory"
	unlock_facing_direction
# 108 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_right
# 109 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_right
# 110 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 111 "data/maps/FarawayIsland_Interior/scripts.pory"

# 112 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Movement_MewFloatUpEast: @ 8267DEB
# 113 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock_facing_direction
# 114 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 115 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_fast_up
# 116 "data/maps/FarawayIsland_Interior/scripts.pory"
	unlock_facing_direction
# 117 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_left
# 118 "data/maps/FarawayIsland_Interior/scripts.pory"
	walk_in_place_left
# 119 "data/maps/FarawayIsland_Interior/scripts.pory"
	step_end
# 120 "data/maps/FarawayIsland_Interior/scripts.pory"

# 121 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_Mew:: @ 8267DF2
# 122 "data/maps/FarawayIsland_Interior/scripts.pory"
	lock
# 123 "data/maps/FarawayIsland_Interior/scripts.pory"
	faceplayer
# 124 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewAppear
# 125 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 126 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, 0
# 127 "data/maps/FarawayIsland_Interior/scripts.pory"
	special SetMewAboveGrass
# 128 "data/maps/FarawayIsland_Interior/scripts.pory"
	message FarawayIsland_Interior_Text_Mew
# 129 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitse
# 130 "data/maps/FarawayIsland_Interior/scripts.pory"
	playmoncry SPECIES_MEW, 2
# 131 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 132 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_eq FarawayIsland_Interior_EventScript_FoundMewNorth
# 133 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 134 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_eq FarawayIsland_Interior_EventScript_FoundMewSouth
# 135 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 136 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_eq FarawayIsland_Interior_EventScript_FoundMewWest
# 137 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 138 "data/maps/FarawayIsland_Interior/scripts.pory"
	call_if_eq FarawayIsland_Interior_EventScript_FoundMewEast
# 139 "data/maps/FarawayIsland_Interior/scripts.pory"
	special DestroyMewEmergingGrassSprite
# 140 "data/maps/FarawayIsland_Interior/scripts.pory"
	delay 40
# 141 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmoncry
# 142 "data/maps/FarawayIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetHighestLevelInPlayerParty
# 143 "data/maps/FarawayIsland_Interior/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT @ level
# 144 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, SPECIES_MEW
# 145 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8006, ITEM_NONE
# 146 "data/maps/FarawayIsland_Interior/scripts.pory"
	special CreateEventLegalEnemyMon
# 147 "data/maps/FarawayIsland_Interior/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 148 "data/maps/FarawayIsland_Interior/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 149 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitstate
# 150 "data/maps/FarawayIsland_Interior/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 151 "data/maps/FarawayIsland_Interior/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 152 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 153 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq FarawayIsland_Interior_EventScript_MewDefeated
# 154 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 155 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
# 156 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 157 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
# 158 "data/maps/FarawayIsland_Interior/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_MON_TELEPORTED
# 159 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
# 160 "data/maps/FarawayIsland_Interior/scripts.pory"
	setflag FLAG_CAUGHT_MEW
# 161 "data/maps/FarawayIsland_Interior/scripts.pory"
	release
# 162 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 163 "data/maps/FarawayIsland_Interior/scripts.pory"

# 164 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_MewDefeated:: @ 8267E96
# 165 "data/maps/FarawayIsland_Interior/scripts.pory"
	setflag FLAG_DEFEATED_MEW
# 166 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, SPECIES_MEW
# 167 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 168 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 169 "data/maps/FarawayIsland_Interior/scripts.pory"

# 170 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_PlayerOrMewRan:: @ 8267EA4
# 171 "data/maps/FarawayIsland_Interior/scripts.pory"
	setvar VAR_0x8004, SPECIES_MEW
# 172 "data/maps/FarawayIsland_Interior/scripts.pory"
	goto Common_EventScript_LegendaryFlewAway
# 173 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 174 "data/maps/FarawayIsland_Interior/scripts.pory"

# 175 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FoundMewNorth:: @ 8267EAF
# 176 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewFloatUpNorth
# 177 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 178 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 179 "data/maps/FarawayIsland_Interior/scripts.pory"

# 180 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FoundMewSouth:: @ 8267EBA
# 181 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewFloatUpSouth
# 182 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 183 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 184 "data/maps/FarawayIsland_Interior/scripts.pory"

# 185 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FoundMewWest:: @ 8267EC5
# 186 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewFloatUpWest
# 187 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 188 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 189 "data/maps/FarawayIsland_Interior/scripts.pory"

# 190 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_FoundMewEast:: @ 8267ED0
# 191 "data/maps/FarawayIsland_Interior/scripts.pory"
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewFloatUpEast
# 192 "data/maps/FarawayIsland_Interior/scripts.pory"
	waitmovement 0
# 193 "data/maps/FarawayIsland_Interior/scripts.pory"
	return
# 194 "data/maps/FarawayIsland_Interior/scripts.pory"

# 195 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_EventScript_HideMewWhenGrassCut:: @ 8267EDB
# 196 "data/maps/FarawayIsland_Interior/scripts.pory"
	lockall
# 197 "data/maps/FarawayIsland_Interior/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 198 "data/maps/FarawayIsland_Interior/scripts.pory"
	setflag FLAG_HIDE_MEW
# 199 "data/maps/FarawayIsland_Interior/scripts.pory"
	removeobject LOCALID_MEW
# 200 "data/maps/FarawayIsland_Interior/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 201 "data/maps/FarawayIsland_Interior/scripts.pory"
	msgbox FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded, MSGBOX_DEFAULT
# 202 "data/maps/FarawayIsland_Interior/scripts.pory"
	closemessage
# 203 "data/maps/FarawayIsland_Interior/scripts.pory"
	releaseall
# 204 "data/maps/FarawayIsland_Interior/scripts.pory"
	end
# 205 "data/maps/FarawayIsland_Interior/scripts.pory"

# 206 "data/maps/FarawayIsland_Interior/scripts.pory"
FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded: @ 8267EF1
# 207 "data/maps/FarawayIsland_Interior/scripts.pory"
	.string "The feeling of being watched faded…$"
