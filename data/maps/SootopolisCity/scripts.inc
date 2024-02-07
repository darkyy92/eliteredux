# 1 "data/maps/SootopolisCity/scripts.pory"

# 2 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_EXPERT, 1
# 3 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_WOMAN_2, 2
# 4 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_KIRI, 3
# 5 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_NINJA_BOY, 4
# 6 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_BOY_1, 5
# 7 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_STEVEN, 7
# 8 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_WOMAN_1, 8
# 9 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_GROUDON, 9
# 10 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_KYOGRE, 10
# 11 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_RAYQUAZA, 11
# 12 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_MANIAC, 12
# 13 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_GIRL, 13
# 14 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_BLACK_BELT, 14
# 15 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_BOY_2, 15
# 16 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_MAXIE, 16
# 17 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_ARCHIE, 17
# 18 "data/maps/SootopolisCity/scripts.pory"
.set LOCALID_WALLACE, 18
# 19 "data/maps/SootopolisCity/scripts.pory"

# 20 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_MapScripts:: @ 81E565C
# 21 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
# 22 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
# 23 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
# 24 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
# 25 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
# 26 "data/maps/SootopolisCity/scripts.pory"
	.byte 0
# 27 "data/maps/SootopolisCity/scripts.pory"

# 28 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnLoad: @ 81E5676
# 29 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
# 30 "data/maps/SootopolisCity/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
# 31 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
# 32 "data/maps/SootopolisCity/scripts.pory"
	end
# 33 "data/maps/SootopolisCity/scripts.pory"

# 34 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesNotArrived:: @ 81E5692
# 35 "data/maps/SootopolisCity/scripts.pory"
	end
# 36 "data/maps/SootopolisCity/scripts.pory"

# 37 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockHouseDoors:: @ 81E5693
# 38 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, 1
# 39 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, 1
# 40 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, 1
# 41 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, 1
# 42 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, 1
# 43 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, 1
# 44 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, 1
# 45 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, 1
# 46 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, 1
# 47 "data/maps/SootopolisCity/scripts.pory"
	return
# 48 "data/maps/SootopolisCity/scripts.pory"

# 49 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockGymDoor:: @ 81E56E5
# 50 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, 1
# 51 "data/maps/SootopolisCity/scripts.pory"
	return
# 52 "data/maps/SootopolisCity/scripts.pory"

# 53 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnTransition: @ 81E56EF
# 54 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
# 55 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
# 56 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_HideMapNamePopup
# 57 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 1
# 58 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_HideMapNamePopup
# 59 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetWeather
# 60 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetLayout
# 61 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
# 62 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
# 63 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
# 64 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
# 65 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
# 66 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
# 67 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 68 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
# 69 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 70 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetBattleSpectators
# 71 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
# 72 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 73 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
# 74 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 75 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 76 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
# 77 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 78 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetOutsideGymObjPos
# 79 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 80 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetExpertUnblockCaveEntrance
# 81 "data/maps/SootopolisCity/scripts.pory"
	end
# 82 "data/maps/SootopolisCity/scripts.pory"

# 83 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_HideMapNamePopup:: @ 81E5781
# 84 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 85 "data/maps/SootopolisCity/scripts.pory"
	return
# 86 "data/maps/SootopolisCity/scripts.pory"

# 87 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetBattleSpectators:: @ 81E5785
# 88 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_KIRI, 13, 48
# 89 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_BOY_1, 46, 32
# 90 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_NINJA_BOY, 48, 41
# 91 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WOMAN_1, 45, 43
# 92 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
# 93 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_BOY_1, MOVEMENT_TYPE_FACE_LEFT
# 94 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
# 95 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
# 96 "data/maps/SootopolisCity/scripts.pory"
	return
# 97 "data/maps/SootopolisCity/scripts.pory"

# 98 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLayout:: @ 81E57B2
# 99 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
# 100 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_SetNormalLayout
# 101 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 102 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_SetNormalLayout
# 103 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
# 104 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_SetLegendariesLayout
# 105 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
# 106 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_SetLegendariesLayout
# 107 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
# 108 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_SetLegendariesLayout
# 109 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 110 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_SetLegendariesLayout
# 111 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 1
# 112 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le SootopolisCity_EventScript_SetLegendariesLayout
# 113 "data/maps/SootopolisCity/scripts.pory"
	return
# 114 "data/maps/SootopolisCity/scripts.pory"

# 115 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalLayout:: @ 81E5800
# 116 "data/maps/SootopolisCity/scripts.pory"
	return
# 117 "data/maps/SootopolisCity/scripts.pory"

# 118 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLegendariesLayout:: @ 81E5801
# 119 "data/maps/SootopolisCity/scripts.pory"
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
# 120 "data/maps/SootopolisCity/scripts.pory"
	return
# 121 "data/maps/SootopolisCity/scripts.pory"

# 122 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWeather:: @ 81E5805
# 123 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 0
# 124 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_SetNormalWeather
# 125 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 126 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_SetNormalWeather
# 127 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
# 128 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_SetDownpour
# 129 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 1
# 130 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_SetDownpour
# 131 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 1
# 132 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le Common_EventScript_SetAbnormalWeather
# 133 "data/maps/SootopolisCity/scripts.pory"
	return
# 134 "data/maps/SootopolisCity/scripts.pory"

# 135 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalWeather:: @ 81E583D
# 136 "data/maps/SootopolisCity/scripts.pory"
	return
# 137 "data/maps/SootopolisCity/scripts.pory"

# 138 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetDownpour:: @ 81E583E
# 139 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_DOWNPOUR
# 140 "data/maps/SootopolisCity/scripts.pory"
	return
# 141 "data/maps/SootopolisCity/scripts.pory"

# 142 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos:: @ 81E5842
# 143 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
# 144 "data/maps/SootopolisCity/scripts.pory"
	return
# 145 "data/maps/SootopolisCity/scripts.pory"

# 146 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos:: @ 81E584C
# 147 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_EXPERT, 30, 18
# 148 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 32, 18
# 149 "data/maps/SootopolisCity/scripts.pory"
	return
# 150 "data/maps/SootopolisCity/scripts.pory"

# 151 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExitCaveOfOriginObjPos:: @ 81E585B
# 152 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_EXPERT, 30, 18
# 153 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WALLACE, 31, 18
# 154 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 32, 18
# 155 "data/maps/SootopolisCity/scripts.pory"
	end
# 156 "data/maps/SootopolisCity/scripts.pory"

# 157 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetOutsideGymObjPos:: @ 81E5871
# 158 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_EXPERT, 31, 18
# 159 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_STEVEN, 29, 33
# 160 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_MAXIE, 33, 35
# 161 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 34, 35
# 162 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_WALLACE_STATE, 0
# 163 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetWallaceMiddle
# 164 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_WALLACE_STATE, 1
# 165 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetWallaceRight
# 166 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_WALLACE_STATE, 2
# 167 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_SetWallaceLeft
# 168 "data/maps/SootopolisCity/scripts.pory"
	return
# 169 "data/maps/SootopolisCity/scripts.pory"

# 170 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceMiddle:: @ 81E58AF
# 171 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WALLACE, 31, 33
# 172 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 173 "data/maps/SootopolisCity/scripts.pory"
	return
# 174 "data/maps/SootopolisCity/scripts.pory"

# 175 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceRight:: @ 81E58BB
# 176 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WALLACE, 32, 33
# 177 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 178 "data/maps/SootopolisCity/scripts.pory"
	return
# 179 "data/maps/SootopolisCity/scripts.pory"

# 180 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceLeft:: @ 81E58C7
# 181 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_WALLACE, 30, 33
# 182 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 183 "data/maps/SootopolisCity/scripts.pory"
	return
# 184 "data/maps/SootopolisCity/scripts.pory"

# 185 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExpertUnblockCaveEntrance:: @ 81E58D3
# 186 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_EXPERT, 30, 18
# 187 "data/maps/SootopolisCity/scripts.pory"
	return
# 188 "data/maps/SootopolisCity/scripts.pory"

# 189 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnWarp: @ 81E58DB
# 190 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
# 191 "data/maps/SootopolisCity/scripts.pory"
	.2byte 0
# 192 "data/maps/SootopolisCity/scripts.pory"

# 193 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries:: @ 81E58E5
# 194 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 1
# 195 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_PlayerFaceLegendaries1
# 196 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SKY_PILLAR_STATE, 2
# 197 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_PlayerFaceLegendaries2
# 198 "data/maps/SootopolisCity/scripts.pory"
	end
# 199 "data/maps/SootopolisCity/scripts.pory"

# 200 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries1:: @ 81E58FC
# 201 "data/maps/SootopolisCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 202 "data/maps/SootopolisCity/scripts.pory"
	return
# 203 "data/maps/SootopolisCity/scripts.pory"

# 204 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries2:: @ 81E5901
# 205 "data/maps/SootopolisCity/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 206 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 207 "data/maps/SootopolisCity/scripts.pory"
	return
# 208 "data/maps/SootopolisCity/scripts.pory"

# 209 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnResume: @ 81E590B
# 210 "data/maps/SootopolisCity/scripts.pory"
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 255, 9, 6
# 211 "data/maps/SootopolisCity/scripts.pory"
	end
# 212 "data/maps/SootopolisCity/scripts.pory"

# 213 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnFrame: @ 81E5914
# 214 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
# 215 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
# 216 "data/maps/SootopolisCity/scripts.pory"
	.2byte 0
# 217 "data/maps/SootopolisCity/scripts.pory"

# 218 "data/maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 219 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartLegendariesScene:: @ 81E5926
# 220 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 221 "data/maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 222 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_0x8004, 43
# 223 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne SootopolisCity_EventScript_LegendariesSceneFromDive
# 224 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_0x8005, 32
# 225 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne SootopolisCity_EventScript_LegendariesSceneFromDive
# 226 "data/maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
# 227 "data/maps/SootopolisCity/scripts.pory"
	end
# 228 "data/maps/SootopolisCity/scripts.pory"

# 229 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromPokeCenter:: @ 81E5946
# 230 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 231 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 232 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 233 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 234 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 235 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 236 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 237 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 238 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 239 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 240 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 241 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 242 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, Common_Movement_WalkInPlaceFastestLeft
# 243 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, Common_Movement_WalkInPlaceFastestRight
# 244 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 245 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 246 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 247 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, 2
# 248 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 249 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
# 250 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 251 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 252 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 253 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 254 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 255 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 256 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 257 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 258 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 259 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 260 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 261 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, 2
# 262 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 263 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonAttack
# 264 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 265 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 266 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 267 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 268 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 269 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 270 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 271 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 272 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 273 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 274 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 275 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, 2
# 276 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 277 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
# 278 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 279 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 280 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 281 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 282 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 283 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 284 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 285 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 286 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 287 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 288 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 289 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 290 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonIdle
# 291 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
# 292 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 293 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 294 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 295 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 296 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 297 "data/maps/SootopolisCity/scripts.pory"
	end
# 298 "data/maps/SootopolisCity/scripts.pory"

# 299 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromPokeCenter: @ 81E5A68
# 300 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 301 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 302 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 303 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 304 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 305 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 306 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 307 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 308 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 309 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 310 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 311 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 312 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 313 "data/maps/SootopolisCity/scripts.pory"

# 314 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToPokeCenter: @ 81E5A75
# 315 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 316 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 317 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 318 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 319 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 320 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 321 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 322 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 323 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 324 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 325 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 326 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 327 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 328 "data/maps/SootopolisCity/scripts.pory"

# 329 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromDive:: @ 81E5A82
# 330 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 331 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 332 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 333 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 334 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 335 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 336 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 337 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 338 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 339 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 340 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 341 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 342 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, Common_Movement_WalkInPlaceFastestLeft
# 343 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, Common_Movement_WalkInPlaceFastestRight
# 344 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 345 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 346 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 347 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, 2
# 348 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 349 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
# 350 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 351 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 352 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 353 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 354 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 355 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 356 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 357 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 358 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 359 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 360 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 361 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, 2
# 362 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 363 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonAttack
# 364 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 365 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 366 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 367 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 368 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 369 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 370 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 371 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 372 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 373 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 374 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 375 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, 2
# 376 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 377 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonDefend
# 378 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 379 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 380 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 381 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 382 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 383 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 384 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 385 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 386 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 387 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 388 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 389 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 390 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GROUDON, SootopolisCity_Movement_GroudonIdle
# 391 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanBackToDive
# 392 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 393 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 394 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 395 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 396 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 397 "data/maps/SootopolisCity/scripts.pory"
	end
# 398 "data/maps/SootopolisCity/scripts.pory"

# 399 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromDive: @ 81E5BA4
# 400 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 401 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 402 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 403 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 404 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 405 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 406 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 407 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 408 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 409 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 410 "data/maps/SootopolisCity/scripts.pory"

# 411 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToDive: @ 81E5BAE
# 412 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 413 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 414 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 415 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 416 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 417 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 418 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 419 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 420 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 421 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 422 "data/maps/SootopolisCity/scripts.pory"

# 423 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreAttack: @ 81E5BB8
# 424 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 425 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 426 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 427 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 428 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 429 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 430 "data/maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 431 "data/maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 432 "data/maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 433 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 434 "data/maps/SootopolisCity/scripts.pory"

# 435 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreDefend: @ 81E5BC2
# 436 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 437 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 438 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 439 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 440 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 441 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 442 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 443 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 444 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 445 "data/maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 446 "data/maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 447 "data/maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 448 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 449 "data/maps/SootopolisCity/scripts.pory"

# 450 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreMoveBack: @ 81E5BCF
# 451 "data/maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 452 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 453 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 454 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 455 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 456 "data/maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 457 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 458 "data/maps/SootopolisCity/scripts.pory"

# 459 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreIdle: @ 81E5BD6
# 460 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 461 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 462 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 463 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 464 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 465 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 466 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 467 "data/maps/SootopolisCity/scripts.pory"

# 468 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonAttack: @ 81E5BDD
# 469 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 470 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 471 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 472 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 473 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 474 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 475 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 476 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 477 "data/maps/SootopolisCity/scripts.pory"

# 478 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonDefend: @ 81E5BE5
# 479 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 480 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 481 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 482 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 483 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 484 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 485 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 486 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 487 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 488 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 489 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 490 "data/maps/SootopolisCity/scripts.pory"

# 491 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonMoveBack: @ 81E5BF0
# 492 "data/maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 493 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 494 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 495 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 496 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 497 "data/maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 498 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 499 "data/maps/SootopolisCity/scripts.pory"

# 500 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonIdle: @ 81E5BF7
# 501 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 502 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 503 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 504 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 505 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 506 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 507 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 508 "data/maps/SootopolisCity/scripts.pory"

# 509 "data/maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 510 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartRayquazaScene:: @ 81E5BFE
# 511 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 512 "data/maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 513 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_0x8004, 43
# 514 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne SootopolisCity_EventScript_RayquazaSceneFromDive
# 515 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_0x8005, 32
# 516 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne SootopolisCity_EventScript_RayquazaSceneFromDive
# 517 "data/maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
# 518 "data/maps/SootopolisCity/scripts.pory"
	end
# 519 "data/maps/SootopolisCity/scripts.pory"

# 520 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromPokeCenter:: @ 81E5C1E
# 521 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 522 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 523 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 524 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 525 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 526 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 527 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 528 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 529 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_GROUDON
# 530 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_KYOGRE
# 531 "data/maps/SootopolisCity/scripts.pory"
	addobject LOCALID_RAYQUAZA
# 532 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 533 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 534 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 535 "data/maps/SootopolisCity/scripts.pory"
	playse SE_THUNDER
# 536 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 537 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanUp
# 538 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 539 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 540 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, 2
# 541 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 542 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 543 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 544 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 545 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 546 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 547 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 548 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, 2
# 549 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 550 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 551 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 552 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 553 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 554 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 555 "data/maps/SootopolisCity/scripts.pory"
	waitmoncry
# 556 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 557 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 558 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 559 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 560 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_RAYQUAZA
# 561 "data/maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 562 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 563 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 564 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 565 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 566 "data/maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 567 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 568 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 569 "data/maps/SootopolisCity/scripts.pory"
	warpsootopolislegend MAP_SOOTOPOLIS_CITY, 255, 43, 32
# 570 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 571 "data/maps/SootopolisCity/scripts.pory"
	end
# 572 "data/maps/SootopolisCity/scripts.pory"

# 573 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromDive:: @ 81E5CCE
# 574 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 575 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 576 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 577 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 578 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 579 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 580 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 581 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 582 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_GROUDON
# 583 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_KYOGRE
# 584 "data/maps/SootopolisCity/scripts.pory"
	addobject LOCALID_RAYQUAZA
# 585 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 586 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 587 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 588 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 589 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, SootopolisCity_Movement_PanUp
# 590 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
# 591 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 592 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 593 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, 2
# 594 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 595 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 596 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 597 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 598 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 599 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 600 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 601 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, 2
# 602 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 603 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 604 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 605 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 606 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 607 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 608 "data/maps/SootopolisCity/scripts.pory"
	waitmoncry
# 609 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 610 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 611 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 612 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 613 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_RAYQUAZA
# 614 "data/maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 615 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 616 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 617 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 2
# 618 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 619 "data/maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SURF
# 620 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 621 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 622 "data/maps/SootopolisCity/scripts.pory"
	warpsootopolislegend MAP_SOOTOPOLIS_CITY, 255, 29, 53
# 623 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 624 "data/maps/SootopolisCity/scripts.pory"
	end
# 625 "data/maps/SootopolisCity/scripts.pory"

# 626 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetRoughWater:: @ 81E5D82
# 627 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, 0
# 628 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, 0
# 629 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, 0
# 630 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, 0
# 631 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, 0
# 632 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, 0
# 633 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, 0
# 634 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, 0
# 635 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, 0
# 636 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, 0
# 637 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, 0
# 638 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, 0
# 639 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, 0
# 640 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, 0
# 641 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, 0
# 642 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, 0
# 643 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, 0
# 644 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, 0
# 645 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, 0
# 646 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, 0
# 647 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, 0
# 648 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, 0
# 649 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, 0
# 650 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, 0
# 651 "data/maps/SootopolisCity/scripts.pory"
	return
# 652 "data/maps/SootopolisCity/scripts.pory"

# 653 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_RayquazaFlyOff: @ 81E5E5B
# 654 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_up
# 655 "data/maps/SootopolisCity/scripts.pory"
	walk_fastest_up
# 656 "data/maps/SootopolisCity/scripts.pory"
	walk_fastest_up
# 657 "data/maps/SootopolisCity/scripts.pory"
	walk_fastest_up
# 658 "data/maps/SootopolisCity/scripts.pory"
	walk_fastest_up
# 659 "data/maps/SootopolisCity/scripts.pory"
	walk_fastest_up
# 660 "data/maps/SootopolisCity/scripts.pory"
	walk_fastest_up
# 661 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 662 "data/maps/SootopolisCity/scripts.pory"

# 663 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanUp: @ 81E5E63
# 664 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 665 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 666 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 667 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 668 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 669 "data/maps/SootopolisCity/scripts.pory"

# 670 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendaries: @ 81E5E68
# 671 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 672 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 673 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 674 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 675 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 676 "data/maps/SootopolisCity/scripts.pory"

# 677 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 678 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendariesDown: @ 81E5E6D
# 679 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 680 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 681 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 682 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 683 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 684 "data/maps/SootopolisCity/scripts.pory"

# 685 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 686 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanUp: @ 81E5E72
# 687 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 688 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 689 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 690 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 691 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 692 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 693 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 694 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 695 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 696 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 697 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 698 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 699 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 700 "data/maps/SootopolisCity/scripts.pory"

# 701 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 702 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanBack: @ 81E5E7F
# 703 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 704 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 705 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 706 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 707 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 708 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 709 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 710 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 711 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 712 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 713 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 714 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 715 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 716 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 717 "data/maps/SootopolisCity/scripts.pory"

# 718 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CaveOfOriginExpert:: @ 81E5E8D
# 719 "data/maps/SootopolisCity/scripts.pory"
	lock
# 720 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 721 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 722 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_ExpertPostLegendaries
# 723 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 724 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_ExpertLegendaries
# 725 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
# 726 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_ExpertLeadToCave
# 727 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
# 728 "data/maps/SootopolisCity/scripts.pory"
	release
# 729 "data/maps/SootopolisCity/scripts.pory"
	end
# 730 "data/maps/SootopolisCity/scripts.pory"

# 731 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLeadToCave:: @ 81E5EBA
# 732 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
# 733 "data/maps/SootopolisCity/scripts.pory"
	release
# 734 "data/maps/SootopolisCity/scripts.pory"
	end
# 735 "data/maps/SootopolisCity/scripts.pory"

# 736 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertPostLegendaries:: @ 81E5EC4
# 737 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
# 738 "data/maps/SootopolisCity/scripts.pory"
	release
# 739 "data/maps/SootopolisCity/scripts.pory"
	end
# 740 "data/maps/SootopolisCity/scripts.pory"

# 741 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLegendaries:: @ 81E5ECE
# 742 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
# 743 "data/maps/SootopolisCity/scripts.pory"
	release
# 744 "data/maps/SootopolisCity/scripts.pory"
	end
# 745 "data/maps/SootopolisCity/scripts.pory"

# 746 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Kiri:: @ 81E5ED8
# 747 "data/maps/SootopolisCity/scripts.pory"
	lock
# 748 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 749 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
# 750 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le SootopolisCity_EventScript_KiriGiveBerry
# 751 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 752 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_KiriGiveBerry
# 753 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 754 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_KiriRayquaza
# 755 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
# 756 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 757 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
# 758 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 759 "data/maps/SootopolisCity/scripts.pory"
	release
# 760 "data/maps/SootopolisCity/scripts.pory"
	end
# 761 "data/maps/SootopolisCity/scripts.pory"

# 762 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriRayquaza:: @ 81E5F10
# 763 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
# 764 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 765 "data/maps/SootopolisCity/scripts.pory"
	release
# 766 "data/maps/SootopolisCity/scripts.pory"
	end
# 767 "data/maps/SootopolisCity/scripts.pory"

# 768 "data/maps/SootopolisCity/scripts.pory"
@ Gives 2 berries daily. First ranges from FIRST_KIRI_BERRY to LAST_KIRI_BERRY, second is always Figy or Iapapa
# 769 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriGiveBerry:: @ 81E5F1B
# 770 "data/maps/SootopolisCity/scripts.pory"
	dotimebasedevents
# 771 "data/maps/SootopolisCity/scripts.pory"
	special GetPlayerBigGuyGirlString
# 772 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
# 773 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
# 774 "data/maps/SootopolisCity/scripts.pory"
	random NUM_KIRI_BERRIES
# 775 "data/maps/SootopolisCity/scripts.pory"
	addvar VAR_RESULT, NUM_KIRI_BERRIES_SKIPPED
# 776 "data/maps/SootopolisCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 777 "data/maps/SootopolisCity/scripts.pory"
	giveitem VAR_RESULT
# 778 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 779 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 780 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
# 781 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
# 782 "data/maps/SootopolisCity/scripts.pory"
	random 2
# 783 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_RESULT, 0
# 784 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_GiveFigyBerry
# 785 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_RESULT, 1
# 786 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_GiveIapapaBerry
# 787 "data/maps/SootopolisCity/scripts.pory"
	end
# 788 "data/maps/SootopolisCity/scripts.pory"

# 789 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveFigyBerry:: @ 81E5F79
# 790 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_FIGY_BERRY
# 791 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 792 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 793 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 794 "data/maps/SootopolisCity/scripts.pory"
	release
# 795 "data/maps/SootopolisCity/scripts.pory"
	end
# 796 "data/maps/SootopolisCity/scripts.pory"

# 797 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveIapapaBerry:: @ 81E5F9A
# 798 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 799 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 800 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 801 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 802 "data/maps/SootopolisCity/scripts.pory"
	release
# 803 "data/maps/SootopolisCity/scripts.pory"
	end
# 804 "data/maps/SootopolisCity/scripts.pory"

# 805 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriReceivedBerry:: @ 81E5FBB
# 806 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
# 807 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_RESULT, YES
# 808 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_KiriLikeSeasonBornIn
# 809 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
# 810 "data/maps/SootopolisCity/scripts.pory"
	release
# 811 "data/maps/SootopolisCity/scripts.pory"
	end
# 812 "data/maps/SootopolisCity/scripts.pory"

# 813 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriLikeSeasonBornIn:: @ 81E5FD8
# 814 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
# 815 "data/maps/SootopolisCity/scripts.pory"
	release
# 816 "data/maps/SootopolisCity/scripts.pory"
	end
# 817 "data/maps/SootopolisCity/scripts.pory"

# 818 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2:: @ 81E5FE2
# 819 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 820 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WOMAN_2, Common_Movement_FacePlayer
# 821 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 822 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 823 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_Woman2Rayquaza
# 824 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
# 825 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 826 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WOMAN_2, Common_Movement_FaceOriginalDirection
# 827 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 828 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 829 "data/maps/SootopolisCity/scripts.pory"
	end
# 830 "data/maps/SootopolisCity/scripts.pory"

# 831 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2Rayquaza:: @ 81E600D
# 832 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
# 833 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 834 "data/maps/SootopolisCity/scripts.pory"
	end
# 835 "data/maps/SootopolisCity/scripts.pory"

# 836 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Man:: @ 81E6017
# 837 "data/maps/SootopolisCity/scripts.pory"
	lock
# 838 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 839 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 840 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_ManPostLegendaries
# 841 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
# 842 "data/maps/SootopolisCity/scripts.pory"
	release
# 843 "data/maps/SootopolisCity/scripts.pory"
	end
# 844 "data/maps/SootopolisCity/scripts.pory"

# 845 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManPostLegendaries:: @ 81E602E
# 846 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
# 847 "data/maps/SootopolisCity/scripts.pory"
	release
# 848 "data/maps/SootopolisCity/scripts.pory"
	end
# 849 "data/maps/SootopolisCity/scripts.pory"

# 850 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1:: @ 81E6038
# 851 "data/maps/SootopolisCity/scripts.pory"
	lock
# 852 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 853 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 854 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_Woman1PostLegendaries
# 855 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 856 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_Woman1Rayquaza
# 857 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
# 858 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_Woman1Legendaries
# 859 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
# 860 "data/maps/SootopolisCity/scripts.pory"
	release
# 861 "data/maps/SootopolisCity/scripts.pory"
	end
# 862 "data/maps/SootopolisCity/scripts.pory"

# 863 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Legendaries:: @ 81E6065
# 864 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
# 865 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 866 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
# 867 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 868 "data/maps/SootopolisCity/scripts.pory"
	release
# 869 "data/maps/SootopolisCity/scripts.pory"
	end
# 870 "data/maps/SootopolisCity/scripts.pory"

# 871 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1PostLegendaries:: @ 81E607A
# 872 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
# 873 "data/maps/SootopolisCity/scripts.pory"
	release
# 874 "data/maps/SootopolisCity/scripts.pory"
	end
# 875 "data/maps/SootopolisCity/scripts.pory"

# 876 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Rayquaza:: @ 81E6084
# 877 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
# 878 "data/maps/SootopolisCity/scripts.pory"
	release
# 879 "data/maps/SootopolisCity/scripts.pory"
	end
# 880 "data/maps/SootopolisCity/scripts.pory"

# 881 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoy:: @ 81E608E
# 882 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 883 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_NINJA_BOY, Common_Movement_FacePlayer
# 884 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 885 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 886 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_NinjaBoyRayquaza
# 887 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 888 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_NinjaBoyNormal
# 889 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
# 890 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le SootopolisCity_EventScript_NinjaBoyNormal
# 891 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
# 892 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 893 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_NINJA_BOY, Common_Movement_FaceOriginalDirection
# 894 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 895 "data/maps/SootopolisCity/scripts.pory"
	release
# 896 "data/maps/SootopolisCity/scripts.pory"
	end
# 897 "data/maps/SootopolisCity/scripts.pory"

# 898 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyNormal:: @ 81E60CF
# 899 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
# 900 "data/maps/SootopolisCity/scripts.pory"
	release
# 901 "data/maps/SootopolisCity/scripts.pory"
	end
# 902 "data/maps/SootopolisCity/scripts.pory"

# 903 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyRayquaza:: @ 81E60D9
# 904 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
# 905 "data/maps/SootopolisCity/scripts.pory"
	release
# 906 "data/maps/SootopolisCity/scripts.pory"
	end
# 907 "data/maps/SootopolisCity/scripts.pory"

# 908 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1:: @ 81E60E3
# 909 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 910 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BOY_1, Common_Movement_FacePlayer
# 911 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 912 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 913 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_Boy1Rayquaza
# 914 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
# 915 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 6
# 916 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge SootopolisCity_EventScript_Boy1Normal
# 917 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 1
# 918 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le SootopolisCity_EventScript_Boy1Normal
# 919 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
# 920 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 921 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BOY_1, Common_Movement_FaceOriginalDirection
# 922 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 923 "data/maps/SootopolisCity/scripts.pory"
	release
# 924 "data/maps/SootopolisCity/scripts.pory"
	end
# 925 "data/maps/SootopolisCity/scripts.pory"

# 926 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Rayquaza:: @ 81E612D
# 927 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
# 928 "data/maps/SootopolisCity/scripts.pory"
	release
# 929 "data/maps/SootopolisCity/scripts.pory"
	end
# 930 "data/maps/SootopolisCity/scripts.pory"

# 931 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1GameClear:: @ 81E6137
# 932 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
# 933 "data/maps/SootopolisCity/scripts.pory"
	release
# 934 "data/maps/SootopolisCity/scripts.pory"
	end
# 935 "data/maps/SootopolisCity/scripts.pory"

# 936 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Normal:: @ 81E6141
# 937 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
# 938 "data/maps/SootopolisCity/scripts.pory"
	release
# 939 "data/maps/SootopolisCity/scripts.pory"
	end
# 940 "data/maps/SootopolisCity/scripts.pory"

# 941 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GymSign:: @ 81E614B
# 942 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
# 943 "data/maps/SootopolisCity/scripts.pory"
	end
# 944 "data/maps/SootopolisCity/scripts.pory"

# 945 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CitySign:: @ 81E6154
# 946 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
# 947 "data/maps/SootopolisCity/scripts.pory"
	end
# 948 "data/maps/SootopolisCity/scripts.pory"

# 949 "data/maps/SootopolisCity/scripts.pory"
EventScript_ClosedSootopolisDoor:: @ 81E615D
# 950 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
# 951 "data/maps/SootopolisCity/scripts.pory"
	end
# 952 "data/maps/SootopolisCity/scripts.pory"

# 953 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Steven:: @ 81E6166
# 954 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 955 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
# 956 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 957 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
# 958 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 2
# 959 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_StevenHelpWallace
# 960 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
# 961 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_StevenHelpedWallace
# 962 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 963 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_StevenHelpedWallace
# 964 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
# 965 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
# 966 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 967 "data/maps/SootopolisCity/scripts.pory"
	end
# 968 "data/maps/SootopolisCity/scripts.pory"

# 969 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpWallace:: @ 81E61AE
# 970 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
# 971 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 972 "data/maps/SootopolisCity/scripts.pory"
	end
# 973 "data/maps/SootopolisCity/scripts.pory"

# 974 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenMaxieArchieLeft:: @ 81E61B8
# 975 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
# 976 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 977 "data/maps/SootopolisCity/scripts.pory"
	end
# 978 "data/maps/SootopolisCity/scripts.pory"

# 979 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpedWallace:: @ 81E61C2
# 980 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
# 981 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 982 "data/maps/SootopolisCity/scripts.pory"
	end
# 983 "data/maps/SootopolisCity/scripts.pory"

# 984 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin:: @ 81E61CC
# 985 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
# 986 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 987 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 988 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
# 989 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 990 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
# 991 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
# 992 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 993 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
# 994 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
# 995 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 996 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 997 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_EXPERT, SootopolisCity_Movement_ExpertMoveAside
# 998 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 999 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
# 1000 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
# 1001 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1002 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
# 1003 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1004 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
# 1005 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
# 1006 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1007 "data/maps/SootopolisCity/scripts.pory"
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 255, 9, 20
# 1008 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 1009 "data/maps/SootopolisCity/scripts.pory"
	end
# 1010 "data/maps/SootopolisCity/scripts.pory"

# 1011 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginWest:: @ 81E6243
# 1012 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 1013 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
# 1014 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1015 "data/maps/SootopolisCity/scripts.pory"
	return
# 1016 "data/maps/SootopolisCity/scripts.pory"

# 1017 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth:: @ 81E6255
# 1018 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 1019 "data/maps/SootopolisCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
# 1020 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1021 "data/maps/SootopolisCity/scripts.pory"
	return
# 1022 "data/maps/SootopolisCity/scripts.pory"

# 1023 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin: @ 81E6267
# 1024 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1025 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1026 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1027 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1028 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1029 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1030 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1031 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1032 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1033 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1034 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1035 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1036 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1037 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1038 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1039 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1040 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1041 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1042 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1043 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1044 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1045 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1046 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1047 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1048 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1049 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1050 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1051 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1052 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1053 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1054 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1055 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1056 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1057 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1058 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1059 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_fastest_down
# 1060 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1061 "data/maps/SootopolisCity/scripts.pory"

# 1062 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest: @ 81E628C
# 1063 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1064 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1065 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1066 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1067 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1068 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1069 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1070 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1071 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1072 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1073 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1074 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1075 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1076 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1077 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1078 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1079 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1080 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1081 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1082 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1083 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1084 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1085 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1086 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1087 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1088 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1089 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1090 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1091 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1092 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1093 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1094 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1095 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1096 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1097 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1098 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1099 "data/maps/SootopolisCity/scripts.pory"

# 1100 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth: @ 81E62B0
# 1101 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1102 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1103 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1104 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1105 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1106 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1107 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1108 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1109 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1110 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1111 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1112 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1113 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1114 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1115 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1116 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1117 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1118 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1119 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1120 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1121 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1122 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1123 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1124 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1125 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1126 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1127 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1128 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1129 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1130 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1131 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1132 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1133 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1134 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1135 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1136 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1137 "data/maps/SootopolisCity/scripts.pory"

# 1138 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenWalkToCaveOfOrigin: @ 81E62D4
# 1139 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1140 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1141 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1142 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1143 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1144 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1145 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1146 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1147 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1148 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1149 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1150 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1151 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1152 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1153 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1154 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1155 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1156 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1157 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1158 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1159 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1160 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1161 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1162 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1163 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1164 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1165 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1166 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1167 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1168 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1169 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1170 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1171 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1172 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1173 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1174 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1175 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1176 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1177 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1178 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1179 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1180 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1181 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1182 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1183 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1184 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1185 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1186 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1187 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1188 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1189 "data/maps/SootopolisCity/scripts.pory"
	delay_4
# 1190 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_fastest_left
# 1191 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1192 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1193 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1194 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1195 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1196 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1197 "data/maps/SootopolisCity/scripts.pory"

# 1198 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerWalkToCaveOfOrigin: @ 81E630E
# 1199 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1200 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1201 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1202 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1203 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1204 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1205 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1206 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1207 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1208 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1209 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1210 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1211 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1212 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1213 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1214 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1215 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1216 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1217 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1218 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1219 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1220 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1221 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1222 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1223 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1224 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1225 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1226 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1227 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1228 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1229 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1230 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1231 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1232 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1233 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1234 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1235 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1236 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1237 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1238 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1239 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1240 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1241 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1242 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1243 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1244 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1245 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1246 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1247 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1248 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1249 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1250 "data/maps/SootopolisCity/scripts.pory"

# 1251 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_ExpertMoveAside: @ 81E6341
# 1252 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_left
# 1253 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_fastest_right
# 1254 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1255 "data/maps/SootopolisCity/scripts.pory"

# 1256 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenArriveCaveEntrance: @ 81E6344
# 1257 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1258 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1259 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1260 "data/maps/SootopolisCity/scripts.pory"
	delay_8
# 1261 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1262 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1263 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1264 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1265 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1266 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_fastest_left
# 1267 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1268 "data/maps/SootopolisCity/scripts.pory"

# 1269 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerArriveCaveEntrance: @ 81E634F
# 1270 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1271 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1272 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1273 "data/maps/SootopolisCity/scripts.pory"
	delay_8
# 1274 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1275 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1276 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1277 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1278 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1279 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_fastest_right
# 1280 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1281 "data/maps/SootopolisCity/scripts.pory"

# 1282 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerEnterCaveOfOrigin: @ 81E635A
# 1283 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1284 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1285 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1286 "data/maps/SootopolisCity/scripts.pory"

# 1287 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2:: @ 81E635D
# 1288 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1289 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BOY_2, Common_Movement_FacePlayer
# 1290 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1291 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 1292 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_Boy2Rayquaza
# 1293 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
# 1294 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1295 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BOY_2, Common_Movement_FaceOriginalDirection
# 1296 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1297 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1298 "data/maps/SootopolisCity/scripts.pory"
	end
# 1299 "data/maps/SootopolisCity/scripts.pory"

# 1300 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2Rayquaza:: @ 81E6388
# 1301 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
# 1302 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1303 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1304 "data/maps/SootopolisCity/scripts.pory"
	end
# 1305 "data/maps/SootopolisCity/scripts.pory"

# 1306 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBelt:: @ 81E6393
# 1307 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1308 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 1309 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_BlackBeltRayquaza
# 1310 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
# 1311 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1312 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BLACK_BELT, Common_Movement_FacePlayer
# 1313 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1314 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
# 1315 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1316 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BLACK_BELT, Common_Movement_FaceOriginalDirection
# 1317 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1318 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1319 "data/maps/SootopolisCity/scripts.pory"
	end
# 1320 "data/maps/SootopolisCity/scripts.pory"

# 1321 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBeltRayquaza:: @ 81E63C7
# 1322 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_BLACK_BELT, Common_Movement_FacePlayer
# 1323 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1324 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
# 1325 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1326 "data/maps/SootopolisCity/scripts.pory"
	end
# 1327 "data/maps/SootopolisCity/scripts.pory"

# 1328 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Girl:: @ 81E63DB
# 1329 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1330 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GIRL, Common_Movement_FacePlayer
# 1331 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1332 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 1333 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_GirlRayquaza
# 1334 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
# 1335 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1336 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_GIRL, Common_Movement_FaceOriginalDirection
# 1337 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1338 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1339 "data/maps/SootopolisCity/scripts.pory"
	end
# 1340 "data/maps/SootopolisCity/scripts.pory"

# 1341 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GirlRayquaza:: @ 81E6406
# 1342 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
# 1343 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1344 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1345 "data/maps/SootopolisCity/scripts.pory"
	end
# 1346 "data/maps/SootopolisCity/scripts.pory"

# 1347 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maniac:: @ 81E6411
# 1348 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1349 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_MANIAC, Common_Movement_FacePlayer
# 1350 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1351 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 1352 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_ManiacRayquaza
# 1353 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
# 1354 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1355 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_MANIAC, Common_Movement_FaceOriginalDirection
# 1356 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1357 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1358 "data/maps/SootopolisCity/scripts.pory"
	end
# 1359 "data/maps/SootopolisCity/scripts.pory"

# 1360 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManiacRayquaza:: @ 81E643C
# 1361 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
# 1362 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1363 "data/maps/SootopolisCity/scripts.pory"
	end
# 1364 "data/maps/SootopolisCity/scripts.pory"

# 1365 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Wallace:: @ 81E6446
# 1366 "data/maps/SootopolisCity/scripts.pory"
	lock
# 1367 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 1368 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 1369 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_GoToSkyPillar
# 1370 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM07, SootopolisCity_EventScript_GoToGym
# 1371 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
# 1372 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
# 1373 "data/maps/SootopolisCity/scripts.pory"
	release
# 1374 "data/maps/SootopolisCity/scripts.pory"
	end
# 1375 "data/maps/SootopolisCity/scripts.pory"

# 1376 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveWaterfall:: @ 81E646F
# 1377 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
# 1378 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_HM07_WATERFALL
# 1379 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_HM07
# 1380 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
# 1381 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1382 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 1383 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_WallaceMoveFromGym
# 1384 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 1385 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_WallaceMoveFromGym
# 1386 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 1387 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq SootopolisCity_EventScript_WallaceMoveFromGymWest
# 1388 "data/maps/SootopolisCity/scripts.pory"
	release
# 1389 "data/maps/SootopolisCity/scripts.pory"
	end
# 1390 "data/maps/SootopolisCity/scripts.pory"

# 1391 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGym:: @ 81E64B2
# 1392 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
# 1393 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1394 "data/maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_WALLACE
# 1395 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
# 1396 "data/maps/SootopolisCity/scripts.pory"
	return
# 1397 "data/maps/SootopolisCity/scripts.pory"

# 1398 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGymWest:: @ 81E64C5
# 1399 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
# 1400 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1401 "data/maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_WALLACE
# 1402 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
# 1403 "data/maps/SootopolisCity/scripts.pory"
	return
# 1404 "data/maps/SootopolisCity/scripts.pory"

# 1405 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToSkyPillar:: @ 81E64D8
# 1406 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
# 1407 "data/maps/SootopolisCity/scripts.pory"
	release
# 1408 "data/maps/SootopolisCity/scripts.pory"
	end
# 1409 "data/maps/SootopolisCity/scripts.pory"

# 1410 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToGym:: @ 81E64E2
# 1411 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
# 1412 "data/maps/SootopolisCity/scripts.pory"
	release
# 1413 "data/maps/SootopolisCity/scripts.pory"
	end
# 1414 "data/maps/SootopolisCity/scripts.pory"

# 1415 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGym: @ 81E64EC
# 1416 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1417 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_fastest_down
# 1418 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1419 "data/maps/SootopolisCity/scripts.pory"

# 1420 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGymWest: @ 81E64EF
# 1421 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1422 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_fastest_down
# 1423 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1424 "data/maps/SootopolisCity/scripts.pory"

# 1425 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maxie:: @ 81E64F2
# 1426 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1427 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 1428 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_MaxieRayquaza
# 1429 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
# 1430 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1431 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1432 "data/maps/SootopolisCity/scripts.pory"
	end
# 1433 "data/maps/SootopolisCity/scripts.pory"

# 1434 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieRayquaza:: @ 81E6509
# 1435 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
# 1436 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
# 1437 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1438 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1439 "data/maps/SootopolisCity/scripts.pory"
	end
# 1440 "data/maps/SootopolisCity/scripts.pory"

# 1441 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Archie:: @ 81E651F
# 1442 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1443 "data/maps/SootopolisCity/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 5
# 1444 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq SootopolisCity_EventScript_ArchieRayquaza
# 1445 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
# 1446 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1447 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1448 "data/maps/SootopolisCity/scripts.pory"
	end
# 1449 "data/maps/SootopolisCity/scripts.pory"

# 1450 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ArchieRayquaza:: @ 81E6536
# 1451 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
# 1452 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
# 1453 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1454 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1455 "data/maps/SootopolisCity/scripts.pory"
	end
# 1456 "data/maps/SootopolisCity/scripts.pory"

# 1457 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieArchieLeave:: @ 81E654C
# 1458 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 1459 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 1460 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
# 1461 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
# 1462 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 1463 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 2
# 1464 "data/maps/SootopolisCity/scripts.pory"
	warpsilent MAP_SOOTOPOLIS_CITY, 255, 31, 34
# 1465 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 1466 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1467 "data/maps/SootopolisCity/scripts.pory"
	end
# 1468 "data/maps/SootopolisCity/scripts.pory"

# 1469 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 1470 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_Levitate:: @ 81E656B
# 1471 "data/maps/SootopolisCity/scripts.pory"
	levitate
# 1472 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1473 "data/maps/SootopolisCity/scripts.pory"

# 1474 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 1475 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_DestroyTask:: @ 81E656D
# 1476 "data/maps/SootopolisCity/scripts.pory"
	destroy_extra_task
# 1477 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1478 "data/maps/SootopolisCity/scripts.pory"

# 1479 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GymSign: @ 81E656F
# 1480 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis City Pokémon Gym\n"
# 1481 "data/maps/SootopolisCity/scripts.pory"
	.string "Leader: Juan\p"
# 1482 "data/maps/SootopolisCity/scripts.pory"
	.string "“The Gym Leader with the beauty\n"
# 1483 "data/maps/SootopolisCity/scripts.pory"
	.string "of pure water!”$"
# 1484 "data/maps/SootopolisCity/scripts.pory"

# 1485 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CitySign: @ 81E65C8
# 1486 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis City\p"
# 1487 "data/maps/SootopolisCity/scripts.pory"
	.string "“The mystical city where history\n"
# 1488 "data/maps/SootopolisCity/scripts.pory"
	.string "slumbers.”$"
# 1489 "data/maps/SootopolisCity/scripts.pory"

# 1490 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoorIsClosed: @ 81E6604
# 1491 "data/maps/SootopolisCity/scripts.pory"
	.string "The door is closed.$"
# 1492 "data/maps/SootopolisCity/scripts.pory"

# 1493 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PhysicallyFitLivingHere: @ 81E6618
# 1494 "data/maps/SootopolisCity/scripts.pory"
	.string "Diving in the sea. Climbing up and\n"
# 1495 "data/maps/SootopolisCity/scripts.pory"
	.string "down stairs all the time…\p"
# 1496 "data/maps/SootopolisCity/scripts.pory"
	.string "If you live in this town, you end up\n"
# 1497 "data/maps/SootopolisCity/scripts.pory"
	.string "getting physically fit.$"
# 1498 "data/maps/SootopolisCity/scripts.pory"

# 1499 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiantPokemonSuddenlyAppeared: @ 81E6692
# 1500 "data/maps/SootopolisCity/scripts.pory"
	.string "These giant Pokémon suddenly appeared\n"
# 1501 "data/maps/SootopolisCity/scripts.pory"
	.string "in the middle of the city!\p"
# 1502 "data/maps/SootopolisCity/scripts.pory"
	.string "And, I've never seen them before!\p"
# 1503 "data/maps/SootopolisCity/scripts.pory"
	.string "Why are they smashing into each\n"
# 1504 "data/maps/SootopolisCity/scripts.pory"
	.string "other like that?\p"
# 1505 "data/maps/SootopolisCity/scripts.pory"
	.string "Why can't they be friends, those\n"
# 1506 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon?$"
# 1507 "data/maps/SootopolisCity/scripts.pory"

# 1508 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhatIsThatGreenPokemon: @ 81E6750
# 1509 "data/maps/SootopolisCity/scripts.pory"
	.string "What? What? What?\n"
# 1510 "data/maps/SootopolisCity/scripts.pory"
	.string "What is that green Pokémon?!$"
# 1511 "data/maps/SootopolisCity/scripts.pory"

# 1512 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhereDidLegendariesGo: @ 81E677F
# 1513 "data/maps/SootopolisCity/scripts.pory"
	.string "Groudon and Kyogre…\n"
# 1514 "data/maps/SootopolisCity/scripts.pory"
	.string "Where did they go?\p"
# 1515 "data/maps/SootopolisCity/scripts.pory"
	.string "Will they cause droughts or downpours\n"
# 1516 "data/maps/SootopolisCity/scripts.pory"
	.string "somewhere else?$"
# 1517 "data/maps/SootopolisCity/scripts.pory"

# 1518 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TwoPokemonArentAngry: @ 81E67DC
# 1519 "data/maps/SootopolisCity/scripts.pory"
	.string "I just get this sense somehow that\n"
# 1520 "data/maps/SootopolisCity/scripts.pory"
	.string "the two Pokémon aren't angry.\p"
# 1521 "data/maps/SootopolisCity/scripts.pory"
	.string "I think… They probably can't control\n"
# 1522 "data/maps/SootopolisCity/scripts.pory"
	.string "their own power…$"
# 1523 "data/maps/SootopolisCity/scripts.pory"

# 1524 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FlyingMonStoppedRampage: @ 81E6853
# 1525 "data/maps/SootopolisCity/scripts.pory"
	.string "That flying Pokémon came down from\n"
# 1526 "data/maps/SootopolisCity/scripts.pory"
	.string "the sky and stopped the rampaging\l"
# 1527 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon…$"
# 1528 "data/maps/SootopolisCity/scripts.pory"

# 1529 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WonderWhatWorldIsLike: @ 81E68A1
# 1530 "data/maps/SootopolisCity/scripts.pory"
	.string "I… I've never been out of this city.\p"
# 1531 "data/maps/SootopolisCity/scripts.pory"
	.string "I wonder what the world is like on\n"
# 1532 "data/maps/SootopolisCity/scripts.pory"
	.string "the other side of this round sky?$"
# 1533 "data/maps/SootopolisCity/scripts.pory"

# 1534 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThisIsWicked: @ 81E690B
# 1535 "data/maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1536 "data/maps/SootopolisCity/scripts.pory"
	.string "This is wicked!$"
# 1537 "data/maps/SootopolisCity/scripts.pory"

# 1538 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThatWasWicked: @ 81E6920
# 1539 "data/maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1540 "data/maps/SootopolisCity/scripts.pory"
	.string "That was wicked!$"
# 1541 "data/maps/SootopolisCity/scripts.pory"

# 1542 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GoRedAndBlueMon: @ 81E6936
# 1543 "data/maps/SootopolisCity/scripts.pory"
	.string "Go for it, red Pokémon!\n"
# 1544 "data/maps/SootopolisCity/scripts.pory"
	.string "Don't back off, blue Pokémon!$"
# 1545 "data/maps/SootopolisCity/scripts.pory"

# 1546 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoYouKnowMonNames: @ 81E696C
# 1547 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1548 "data/maps/SootopolisCity/scripts.pory"
	.string "Hi, do you know the names of those\n"
# 1549 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon fighting over there?$"
# 1550 "data/maps/SootopolisCity/scripts.pory"

# 1551 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GreenOneSettlesThings: @ 81E69B8
# 1552 "data/maps/SootopolisCity/scripts.pory"
	.string "I was wondering which one would win,\n"
# 1553 "data/maps/SootopolisCity/scripts.pory"
	.string "the red one or the blue one, but, oh no,\l"
# 1554 "data/maps/SootopolisCity/scripts.pory"
	.string "it's the green one that settles things!\p"
# 1555 "data/maps/SootopolisCity/scripts.pory"
	.string "Talk about a huge turn of events!$"
# 1556 "data/maps/SootopolisCity/scripts.pory"

# 1557 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SeeingLegendWithOwnEyes: @ 81E6A50
# 1558 "data/maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1559 "data/maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1560 "data/maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between Pokémon.\p"
# 1561 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, I'm seeing that happen with\n"
# 1562 "data/maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1563 "data/maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1564 "data/maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1565 "data/maps/SootopolisCity/scripts.pory"

# 1566 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SawLegendWithOwnEyes: @ 81E6B2A
# 1567 "data/maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1568 "data/maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1569 "data/maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between Pokémon.\p"
# 1570 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, I saw that happen with\n"
# 1571 "data/maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1572 "data/maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1573 "data/maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1574 "data/maps/SootopolisCity/scripts.pory"

# 1575 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_BigPokemonFighting: @ 81E6BFF
# 1576 "data/maps/SootopolisCity/scripts.pory"
	.string "A big Pokémon is fighting with\n"
# 1577 "data/maps/SootopolisCity/scripts.pory"
	.string "another big Pokémon!\p"
# 1578 "data/maps/SootopolisCity/scripts.pory"
	.string "Please, someone make them stop!$"
# 1579 "data/maps/SootopolisCity/scripts.pory"

# 1580 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PrettyMonCameFromSky: @ 81E6C53
# 1581 "data/maps/SootopolisCity/scripts.pory"
	.string "A pretty Pokémon came down from\n"
# 1582 "data/maps/SootopolisCity/scripts.pory"
	.string "the sky…$"
# 1583 "data/maps/SootopolisCity/scripts.pory"

# 1584 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisWillBeWrecked: @ 81E6C7C
# 1585 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh, no!\n"
# 1586 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis City will get wrecked!$"
# 1587 "data/maps/SootopolisCity/scripts.pory"

# 1588 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisDidntGetWrecked: @ 81E6CA6
# 1589 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis City didn't get wrecked!$"
# 1590 "data/maps/SootopolisCity/scripts.pory"

# 1591 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NoOrdinaryTourist: @ 81E6CCA
# 1592 "data/maps/SootopolisCity/scripts.pory"
	.string "Hm!\n"
# 1593 "data/maps/SootopolisCity/scripts.pory"
	.string "You've come all the way to Sootopolis?\l"
# 1594 "data/maps/SootopolisCity/scripts.pory"
	.string "You're no ordinary tourist.\p"
# 1595 "data/maps/SootopolisCity/scripts.pory"
	.string "But I suppose that doesn't make you\n"
# 1596 "data/maps/SootopolisCity/scripts.pory"
	.string "an extraordinary tourist, either.$"
# 1597 "data/maps/SootopolisCity/scripts.pory"

# 1598 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CityRegainedCalm: @ 81E6D57
# 1599 "data/maps/SootopolisCity/scripts.pory"
	.string "The city has regained its calm…$"
# 1600 "data/maps/SootopolisCity/scripts.pory"

# 1601 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginPleaseLeave: @ 81E6D77
# 1602 "data/maps/SootopolisCity/scripts.pory"
	.string "Who might you be?\p"
# 1603 "data/maps/SootopolisCity/scripts.pory"
	.string "This is the Cave of Origin.\p"
# 1604 "data/maps/SootopolisCity/scripts.pory"
	.string "The spirits of Pokémon, becalmed at\n"
# 1605 "data/maps/SootopolisCity/scripts.pory"
	.string "Mt. Pyre, are said to be revived here.\p"
# 1606 "data/maps/SootopolisCity/scripts.pory"
	.string "Please leave.$"
# 1607 "data/maps/SootopolisCity/scripts.pory"

# 1608 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_LeadSuperiorTrainerToCave: @ 81E6DFE
# 1609 "data/maps/SootopolisCity/scripts.pory"
	.string "A person with a strong will and\n"
# 1610 "data/maps/SootopolisCity/scripts.pory"
	.string "superior talent…\p"
# 1611 "data/maps/SootopolisCity/scripts.pory"
	.string "A Trainer who has knowledge and\n"
# 1612 "data/maps/SootopolisCity/scripts.pory"
	.string "experience of many kinds of Pokémon…\p"
# 1613 "data/maps/SootopolisCity/scripts.pory"
	.string "If such a person were to appear, I was\n"
# 1614 "data/maps/SootopolisCity/scripts.pory"
	.string "instructed by Wallace to lead that\l"
# 1615 "data/maps/SootopolisCity/scripts.pory"
	.string "Trainer to this cave.$"
# 1616 "data/maps/SootopolisCity/scripts.pory"

# 1617 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AwakenedPokemonClash: @ 81E6ED4
# 1618 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh, my…\p"
# 1619 "data/maps/SootopolisCity/scripts.pory"
	.string "The clash between the two awakened\n"
# 1620 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon was quelled by the awakening\l"
# 1621 "data/maps/SootopolisCity/scripts.pory"
	.string "of a third Pokémon…$"
# 1622 "data/maps/SootopolisCity/scripts.pory"

# 1623 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginSleepsToo: @ 81E6F38
# 1624 "data/maps/SootopolisCity/scripts.pory"
	.string "This is the Cave of Origin…\p"
# 1625 "data/maps/SootopolisCity/scripts.pory"
	.string "With the passing of the crisis,\n"
# 1626 "data/maps/SootopolisCity/scripts.pory"
	.string "the cave, too, shall sleep…$"
# 1627 "data/maps/SootopolisCity/scripts.pory"

# 1628 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisSkyBeautiful: @ 81E6F90
# 1629 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis sprang up as a town in\n"
# 1630 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano.\p"
# 1631 "data/maps/SootopolisCity/scripts.pory"
	.string "If you look up at the sky, the lip of\n"
# 1632 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater is also visible.\l"
# 1633 "data/maps/SootopolisCity/scripts.pory"
	.string "So, all you see is the sky in a circle.\p"
# 1634 "data/maps/SootopolisCity/scripts.pory"
	.string "But that's what makes the sky above\n"
# 1635 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis the most beautiful.$"
# 1636 "data/maps/SootopolisCity/scripts.pory"

# 1637 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiganticPokemonFight: @ 81E7078
# 1638 "data/maps/SootopolisCity/scripts.pory"
	.string "When two Pokémon that gigantic\n"
# 1639 "data/maps/SootopolisCity/scripts.pory"
	.string "are fighting that savagely, there's\l"
# 1640 "data/maps/SootopolisCity/scripts.pory"
	.string "not much that we can do.$"
# 1641 "data/maps/SootopolisCity/scripts.pory"

# 1642 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FearedWorstWhenPokemonFlewDown: @ 81E70D4
# 1643 "data/maps/SootopolisCity/scripts.pory"
	.string "When that third Pokémon flew down,\n"
# 1644 "data/maps/SootopolisCity/scripts.pory"
	.string "I feared the worst.$"
# 1645 "data/maps/SootopolisCity/scripts.pory"

# 1646 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NightSkyFavoriteScenery: @ 81E710B
# 1647 "data/maps/SootopolisCity/scripts.pory"
	.string "A circle of a night sky framed by\n"
# 1648 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano…\p"
# 1649 "data/maps/SootopolisCity/scripts.pory"
	.string "And in that ring, stars flicker and\n"
# 1650 "data/maps/SootopolisCity/scripts.pory"
	.string "blink as if they were alive…\l"
# 1651 "data/maps/SootopolisCity/scripts.pory"
	.string "It's my favorite scenery.$"
# 1652 "data/maps/SootopolisCity/scripts.pory"

# 1653 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WeatherWentWild: @ 81E71A1
# 1654 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather was clear this morning,\n"
# 1655 "data/maps/SootopolisCity/scripts.pory"
	.string "but…\p"
# 1656 "data/maps/SootopolisCity/scripts.pory"
	.string "All of a sudden, dark clouds brewed up,\n"
# 1657 "data/maps/SootopolisCity/scripts.pory"
	.string "rain started falling in sheets, and\l"
# 1658 "data/maps/SootopolisCity/scripts.pory"
	.string "there was thunder and lightning, too.\p"
# 1659 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather just went completely\n"
# 1660 "data/maps/SootopolisCity/scripts.pory"
	.string "wild!\p"
# 1661 "data/maps/SootopolisCity/scripts.pory"
	.string "Is all of this because of those\n"
# 1662 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon?$"
# 1663 "data/maps/SootopolisCity/scripts.pory"

# 1664 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_YouBroughtFlyingMon: @ 81E728C
# 1665 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh?\p"
# 1666 "data/maps/SootopolisCity/scripts.pory"
	.string "It was you who brought that flying\n"
# 1667 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon here?\p"
# 1668 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, aren't you amazing!$"
# 1669 "data/maps/SootopolisCity/scripts.pory"

# 1670 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GroudonPleaseStop: @ 81E72DB
# 1671 "data/maps/SootopolisCity/scripts.pory"
	.string "Maxie: G… Groudon…\n"
# 1672 "data/maps/SootopolisCity/scripts.pory"
	.string "Please! Stop what you're doing!\p"
# 1673 "data/maps/SootopolisCity/scripts.pory"
	.string "I know the extent of your power now!\p"
# 1674 "data/maps/SootopolisCity/scripts.pory"
	.string "If you keep going, all Hoenn, not just\n"
# 1675 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis, will be utterly ruined!$"
# 1676 "data/maps/SootopolisCity/scripts.pory"

# 1677 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AfterAllOurScheming: @ 81E737E
# 1678 "data/maps/SootopolisCity/scripts.pory"
	.string "Maxie: So the super-ancient Pokémon\n"
# 1679 "data/maps/SootopolisCity/scripts.pory"
	.string "weren't only Groudon and Kyogre…\p"
# 1680 "data/maps/SootopolisCity/scripts.pory"
	.string "After all our fruitless scheming and\n"
# 1681 "data/maps/SootopolisCity/scripts.pory"
	.string "frantic efforts, that one Pokémon's\l"
# 1682 "data/maps/SootopolisCity/scripts.pory"
	.string "simple action puts everything right\l"
# 1683 "data/maps/SootopolisCity/scripts.pory"
	.string "again as if nothing had happened…\p"
# 1684 "data/maps/SootopolisCity/scripts.pory"
	.string "Fu…\n"
# 1685 "data/maps/SootopolisCity/scripts.pory"
	.string "Fuhahaha…$"
# 1686 "data/maps/SootopolisCity/scripts.pory"

# 1687 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KyogreCalmDown: @ 81E7460
# 1688 "data/maps/SootopolisCity/scripts.pory"
	.string "Archie: Kyogre! What's wrong?!\n"
# 1689 "data/maps/SootopolisCity/scripts.pory"
	.string "Look over here! It's the Blue Orb!\l"
# 1690 "data/maps/SootopolisCity/scripts.pory"
	.string "Calm down! Kyogre!\p"
# 1691 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\n"
# 1692 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1693 "data/maps/SootopolisCity/scripts.pory"
	.string "It's no good!\n"
# 1694 "data/maps/SootopolisCity/scripts.pory"
	.string "It's not responding at all!$"
# 1695 "data/maps/SootopolisCity/scripts.pory"

# 1696 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TryingMeaninglessToPokemon: @ 81E74F6
# 1697 "data/maps/SootopolisCity/scripts.pory"
	.string "Archie: Kyogre and Groudon both\n"
# 1698 "data/maps/SootopolisCity/scripts.pory"
	.string "flew off to who knows where.\p"
# 1699 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather in Hoenn has returned\n"
# 1700 "data/maps/SootopolisCity/scripts.pory"
	.string "to its normal state…\p"
# 1701 "data/maps/SootopolisCity/scripts.pory"
	.string "Haha…\n"
# 1702 "data/maps/SootopolisCity/scripts.pory"
	.string "Hahaha…\p"
# 1703 "data/maps/SootopolisCity/scripts.pory"
	.string "Maybe what we were trying to do was\n"
# 1704 "data/maps/SootopolisCity/scripts.pory"
	.string "something small, even meaningless,\l"
# 1705 "data/maps/SootopolisCity/scripts.pory"
	.string "to Pokémon…$"
# 1706 "data/maps/SootopolisCity/scripts.pory"

# 1707 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_InvolvedWithCrisisComeWithMe: @ 81E75CB
# 1708 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: Those Pokémon fighting…\n"
# 1709 "data/maps/SootopolisCity/scripts.pory"
	.string "Groudon… And Kyogre…\p"
# 1710 "data/maps/SootopolisCity/scripts.pory"
	.string "The two super-ancient Pokémon\n"
# 1711 "data/maps/SootopolisCity/scripts.pory"
	.string "were awakened from a long sleep…\p"
# 1712 "data/maps/SootopolisCity/scripts.pory"
	.string "And now they are smashing each other\n"
# 1713 "data/maps/SootopolisCity/scripts.pory"
	.string "with their uncontrollable energy…\p"
# 1714 "data/maps/SootopolisCity/scripts.pory"
	.string "…{PLAYER}{KUN}.\p"
# 1715 "data/maps/SootopolisCity/scripts.pory"
	.string "You being here now I'll take to mean\n"
# 1716 "data/maps/SootopolisCity/scripts.pory"
	.string "that you're prepared to become\l"
# 1717 "data/maps/SootopolisCity/scripts.pory"
	.string "involved in this crisis.\p"
# 1718 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, then, there's someone that\n"
# 1719 "data/maps/SootopolisCity/scripts.pory"
	.string "I'd like you to meet.\p"
# 1720 "data/maps/SootopolisCity/scripts.pory"
	.string "Come with me, please.$"
# 1721 "data/maps/SootopolisCity/scripts.pory"

# 1722 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoesThisMakeYourFearPokemon: @ 81E7737
# 1723 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: Listen, {PLAYER}{KUN}.\p"
# 1724 "data/maps/SootopolisCity/scripts.pory"
	.string "Does seeing Groudon and Kyogre make\n"
# 1725 "data/maps/SootopolisCity/scripts.pory"
	.string "you think Pokémon are to be feared?\p"
# 1726 "data/maps/SootopolisCity/scripts.pory"
	.string "But that's not true.\n"
# 1727 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon are really more…\p"
# 1728 "data/maps/SootopolisCity/scripts.pory"
	.string "…Why am I asking you this?\n"
# 1729 "data/maps/SootopolisCity/scripts.pory"
	.string "You already know.$"
# 1730 "data/maps/SootopolisCity/scripts.pory"

# 1731 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HereWereAreHelpWallace: @ 81E77F0
# 1732 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: Okay, here we are!\p"
# 1733 "data/maps/SootopolisCity/scripts.pory"
	.string "Inside here you'll find someone named\n"
# 1734 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace.\p"
# 1735 "data/maps/SootopolisCity/scripts.pory"
	.string "I think you have what's needed to\n"
# 1736 "data/maps/SootopolisCity/scripts.pory"
	.string "help him…$"
# 1737 "data/maps/SootopolisCity/scripts.pory"

# 1738 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KnowWhatsNeededToHelpHim: @ 81E7866
# 1739 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: I think you have what's\n"
# 1740 "data/maps/SootopolisCity/scripts.pory"
	.string "needed to help him…$"
# 1741 "data/maps/SootopolisCity/scripts.pory"

# 1742 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NeverBeenToSkyPillar: @ 81E789A
# 1743 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: The Sky Pillar…\p"
# 1744 "data/maps/SootopolisCity/scripts.pory"
	.string "I've never been there.\n"
# 1745 "data/maps/SootopolisCity/scripts.pory"
	.string "I wonder where it could be?$"
# 1746 "data/maps/SootopolisCity/scripts.pory"

# 1747 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SoThatsRayquaza: @ 81E78E5
# 1748 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: So that's Rayquaza…\p"
# 1749 "data/maps/SootopolisCity/scripts.pory"
	.string "It's incredible how the two rampaging\n"
# 1750 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon would flee from it in fear…$"
# 1751 "data/maps/SootopolisCity/scripts.pory"

# 1752 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_MaxieArchieLeft: @ 81E794B
# 1753 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: It looks like both Maxie and\n"
# 1754 "data/maps/SootopolisCity/scripts.pory"
	.string "Archie have gone away somewhere.\p"
# 1755 "data/maps/SootopolisCity/scripts.pory"
	.string "Perhaps they've gone to Mt. Pyre to\n"
# 1756 "data/maps/SootopolisCity/scripts.pory"
	.string "return those Orbs…$"
# 1757 "data/maps/SootopolisCity/scripts.pory"

# 1758 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HaventYouScaledSkyPillar: @ 81E79C8
# 1759 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace: Oh?\n"
# 1760 "data/maps/SootopolisCity/scripts.pory"
	.string "{PLAYER}{KUN}?\p"
# 1761 "data/maps/SootopolisCity/scripts.pory"
	.string "Haven't you scaled the Sky Pillar\n"
# 1762 "data/maps/SootopolisCity/scripts.pory"
	.string "yet?\p"
# 1763 "data/maps/SootopolisCity/scripts.pory"
	.string "I'm sure that you can make it to\n"
# 1764 "data/maps/SootopolisCity/scripts.pory"
	.string "the top of the Sky Pillar…$"
# 1765 "data/maps/SootopolisCity/scripts.pory"

# 1766 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AquaMagmaDidntMeanHarm: @ 81E7A3E
# 1767 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace: {PLAYER}{KUN}…\p"
# 1768 "data/maps/SootopolisCity/scripts.pory"
	.string "The leaders of Team Magma and Aqua,\n"
# 1769 "data/maps/SootopolisCity/scripts.pory"
	.string "I don't think they meant harm.\p"
# 1770 "data/maps/SootopolisCity/scripts.pory"
	.string "It wouldn't hurt to hear what they\n"
# 1771 "data/maps/SootopolisCity/scripts.pory"
	.string "have to say for themselves.$"
# 1772 "data/maps/SootopolisCity/scripts.pory"

# 1773 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThankYouForHelpAcceptThis: @ 81E7ACF
# 1774 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace: {PLAYER}{KUN}…\n"
# 1775 "data/maps/SootopolisCity/scripts.pory"
	.string "My eyes didn't deceive me.\p"
# 1776 "data/maps/SootopolisCity/scripts.pory"
	.string "Thanks to your help, Sootopolis…\n"
# 1777 "data/maps/SootopolisCity/scripts.pory"
	.string "No, all of Hoenn was saved.\p"
# 1778 "data/maps/SootopolisCity/scripts.pory"
	.string "On behalf of the people, I thank you.\p"
# 1779 "data/maps/SootopolisCity/scripts.pory"
	.string "This is a gift from me.\n"
# 1780 "data/maps/SootopolisCity/scripts.pory"
	.string "Please accept it.$"
# 1781 "data/maps/SootopolisCity/scripts.pory"

# 1782 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ExplainWaterfallGoToGym: @ 81E7B86
# 1783 "data/maps/SootopolisCity/scripts.pory"
	.string "That Hidden Machine contains\n"
# 1784 "data/maps/SootopolisCity/scripts.pory"
	.string "Waterfall.\p"
# 1785 "data/maps/SootopolisCity/scripts.pory"
	.string "If you have the Rain Badge, a Pokémon\n"
# 1786 "data/maps/SootopolisCity/scripts.pory"
	.string "that has learned that HM move can\l"
# 1787 "data/maps/SootopolisCity/scripts.pory"
	.string "force its way up waterfalls.\p"
# 1788 "data/maps/SootopolisCity/scripts.pory"
	.string "And where does one get the Rain Badge?\n"
# 1789 "data/maps/SootopolisCity/scripts.pory"
	.string "You know, don't you?\p"
# 1790 "data/maps/SootopolisCity/scripts.pory"
	.string "That's right! You have to beat\n"
# 1791 "data/maps/SootopolisCity/scripts.pory"
	.string "the Sootopolis Gym Leader.\p"
# 1792 "data/maps/SootopolisCity/scripts.pory"
	.string "When you're all set to go, step through\n"
# 1793 "data/maps/SootopolisCity/scripts.pory"
	.string "that door.$"
# 1794 "data/maps/SootopolisCity/scripts.pory"

# 1795 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DazzledByMentor: @ 81E7CBC
# 1796 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace: I'm sure that you will be\n"
# 1797 "data/maps/SootopolisCity/scripts.pory"
	.string "dazzled by my mentor's breathtakingly\l"
# 1798 "data/maps/SootopolisCity/scripts.pory"
	.string "elegant battle style.$"
