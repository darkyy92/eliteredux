# 1 "data/maps/MossdeepCity/scripts.pory"

# 2 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_1, 9
# 3 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_2, 10
# 4 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_3, 11
# 5 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_GRUNT_4, 12
# 6 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_MAXIE, 13
# 7 "data/maps/MossdeepCity/scripts.pory"
.set LOCALID_SCOTT, 15
# 8 "data/maps/MossdeepCity/scripts.pory"

# 9 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_MapScripts:: @ 81E4A96
# 10 "data/maps/MossdeepCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
# 11 "data/maps/MossdeepCity/scripts.pory"
	.byte 0
# 12 "data/maps/MossdeepCity/scripts.pory"

# 13 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnTransition: @ 81E4A9C
# 14 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 15 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 16 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 17 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 18 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 19 "data/maps/MossdeepCity/scripts.pory"
	end
# 20 "data/maps/MossdeepCity/scripts.pory"

# 21 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanF:: @ 81E4AB2
# 22 "data/maps/MossdeepCity/scripts.pory"
	lock
# 23 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 24 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_PokefanFMagmaGone
# 25 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
# 26 "data/maps/MossdeepCity/scripts.pory"
	release
# 27 "data/maps/MossdeepCity/scripts.pory"
	end
# 28 "data/maps/MossdeepCity/scripts.pory"

# 29 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanFMagmaGone:: @ 81E4AC7
# 30 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
# 31 "data/maps/MossdeepCity/scripts.pory"
	release
# 32 "data/maps/MossdeepCity/scripts.pory"
	end
# 33 "data/maps/MossdeepCity/scripts.pory"

# 34 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Sailor:: @ 81E4AD1
# 35 "data/maps/MossdeepCity/scripts.pory"
	lock
# 36 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 37 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM08, MossdeepCity_EventScript_SailorMagmaGone
# 38 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
# 39 "data/maps/MossdeepCity/scripts.pory"
	release
# 40 "data/maps/MossdeepCity/scripts.pory"
	end
# 41 "data/maps/MossdeepCity/scripts.pory"

# 42 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SailorMagmaGone:: @ 81E4AE6
# 43 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
# 44 "data/maps/MossdeepCity/scripts.pory"
	release
# 45 "data/maps/MossdeepCity/scripts.pory"
	end
# 46 "data/maps/MossdeepCity/scripts.pory"

# 47 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_NinjaBoy:: @ 81E4AF0
# 48 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
# 49 "data/maps/MossdeepCity/scripts.pory"
	end
# 50 "data/maps/MossdeepCity/scripts.pory"

# 51 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ExpertM:: @ 81E4AF9
# 52 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
# 53 "data/maps/MossdeepCity/scripts.pory"
	end
# 54 "data/maps/MossdeepCity/scripts.pory"

# 55 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Girl:: @ 81E4B02
# 56 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
# 57 "data/maps/MossdeepCity/scripts.pory"
	end
# 58 "data/maps/MossdeepCity/scripts.pory"

# 59 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Woman:: @ 81E4B0B
# 60 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
# 61 "data/maps/MossdeepCity/scripts.pory"
	end
# 62 "data/maps/MossdeepCity/scripts.pory"

# 63 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_WhiteRock:: @ 81E4B14
# 64 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
# 65 "data/maps/MossdeepCity/scripts.pory"
	end
# 66 "data/maps/MossdeepCity/scripts.pory"

# 67 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_GymSign:: @ 81E4B1D
# 68 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
# 69 "data/maps/MossdeepCity/scripts.pory"
	end
# 70 "data/maps/MossdeepCity/scripts.pory"

# 71 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CitySign:: @ 81E4B26
# 72 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
# 73 "data/maps/MossdeepCity/scripts.pory"
	end
# 74 "data/maps/MossdeepCity/scripts.pory"

# 75 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SpaceCenterSign:: @ 81E4B2F
# 76 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
# 77 "data/maps/MossdeepCity/scripts.pory"
	end
# 78 "data/maps/MossdeepCity/scripts.pory"

# 79 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_VisitedMossdeep:: @ 81E4B38
# 80 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 81 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 82 "data/maps/MossdeepCity/scripts.pory"
	end
# 83 "data/maps/MossdeepCity/scripts.pory"

# 84 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter:: @ 81E4B41
# 85 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 86 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
# 87 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 88 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
# 89 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
# 90 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
# 91 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
# 92 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 93 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
# 94 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
# 95 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
# 96 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
# 97 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
# 98 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 99 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MAXIE
# 100 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 101 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 102 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 103 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_GRUNT_4
# 104 "data/maps/MossdeepCity/scripts.pory"
	delay 30
# 105 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 2
# 106 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 107 "data/maps/MossdeepCity/scripts.pory"
	releaseall
# 108 "data/maps/MossdeepCity/scripts.pory"
	end
# 109 "data/maps/MossdeepCity/scripts.pory"

# 110 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieGestureToSpaceCenter: @ 81E4BAD
# 111 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 112 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 113 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 114 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 115 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 116 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 117 "data/maps/MossdeepCity/scripts.pory"
	face_left
# 118 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 119 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 120 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 121 "data/maps/MossdeepCity/scripts.pory"

# 122 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_GruntFaceSpaceCenter: @ 81E4BB7
# 123 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 124 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 125 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 126 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 127 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 128 "data/maps/MossdeepCity/scripts.pory"

# 129 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieEnterSpaceCenter: @ 81E4BBC
# 130 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 131 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 132 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 133 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 134 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 135 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 136 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 137 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 138 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 139 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 140 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 141 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 142 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 143 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 144 "data/maps/MossdeepCity/scripts.pory"

# 145 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt1EnterSpaceCenter: @ 81E4BCA
# 146 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 147 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 148 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 149 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 150 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 151 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 152 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 153 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 154 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 155 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 156 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 157 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 158 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 159 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 160 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 161 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 162 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 163 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 164 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 165 "data/maps/MossdeepCity/scripts.pory"

# 166 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt2EnterSpaceCenter: @ 81E4BDD
# 167 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 168 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 169 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 170 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 171 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 172 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 173 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 174 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 175 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 176 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 177 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 178 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 179 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 180 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 181 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 182 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 183 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 184 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 185 "data/maps/MossdeepCity/scripts.pory"

# 186 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt3EnterSpaceCenter: @ 81E4BEF
# 187 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 188 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 189 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 190 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 191 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 192 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 193 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 194 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 195 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 196 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 197 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 198 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 199 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 200 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 201 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 202 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 203 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 204 "data/maps/MossdeepCity/scripts.pory"

# 205 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt4EnterSpaceCenter: @ 81E4C00
# 206 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 207 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 208 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 209 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 210 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 211 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 212 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 213 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 214 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 215 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 216 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 217 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 218 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 219 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 220 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 221 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 222 "data/maps/MossdeepCity/scripts.pory"

# 223 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Man:: @ 81E4C10
# 224 "data/maps/MossdeepCity/scripts.pory"
	lock
# 225 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 226 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
# 227 "data/maps/MossdeepCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 228 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 229 "data/maps/MossdeepCity/scripts.pory"
	release
# 230 "data/maps/MossdeepCity/scripts.pory"
	end
# 231 "data/maps/MossdeepCity/scripts.pory"

# 232 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_KingsRockBoy:: @ 81E4C26
# 233 "data/maps/MossdeepCity/scripts.pory"
	lock
# 234 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 235 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
# 236 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
# 237 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, NO
# 238 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq MossdeepCity_EventScript_DeclineKingsRock
# 239 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
# 240 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_KINGS_ROCK
# 241 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, FALSE
# 242 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 243 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_KINGS_ROCK
# 244 "data/maps/MossdeepCity/scripts.pory"
	release
# 245 "data/maps/MossdeepCity/scripts.pory"
	end
# 246 "data/maps/MossdeepCity/scripts.pory"

# 247 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedKingsRock:: @ 81E4C68
# 248 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
# 249 "data/maps/MossdeepCity/scripts.pory"
	release
# 250 "data/maps/MossdeepCity/scripts.pory"
	end
# 251 "data/maps/MossdeepCity/scripts.pory"

# 252 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_DeclineKingsRock:: @ 81E4C72
# 253 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
# 254 "data/maps/MossdeepCity/scripts.pory"
	release
# 255 "data/maps/MossdeepCity/scripts.pory"
	end
# 256 "data/maps/MossdeepCity/scripts.pory"

# 257 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_BlackBelt:: @ 81E4C7C
# 258 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
# 259 "data/maps/MossdeepCity/scripts.pory"
	end
# 260 "data/maps/MossdeepCity/scripts.pory"

# 261 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Scott:: @ 81E4C85
# 262 "data/maps/MossdeepCity/scripts.pory"
	lock
# 263 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 264 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
# 265 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 266 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 267 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq MossdeepCity_EventScript_ScottExitNorth
# 268 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 269 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq MossdeepCity_EventScript_ScottExitEast
# 270 "data/maps/MossdeepCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 271 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_SCOTT
# 272 "data/maps/MossdeepCity/scripts.pory"
	release
# 273 "data/maps/MossdeepCity/scripts.pory"
	end
# 274 "data/maps/MossdeepCity/scripts.pory"

# 275 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitNorth:: @ 81E4CB0
# 276 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 277 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
# 278 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 279 "data/maps/MossdeepCity/scripts.pory"
	return
# 280 "data/maps/MossdeepCity/scripts.pory"

# 281 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitEast:: @ 81E4CC2
# 282 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 283 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
# 284 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 285 "data/maps/MossdeepCity/scripts.pory"
	return
# 286 "data/maps/MossdeepCity/scripts.pory"

# 287 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_AvalancheTM::
# 288 "data/maps/MossdeepCity/scripts.pory"
	lock
# 289 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 290 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_HaveTM96, MSGBOX_DEFAULT
# 291 "data/maps/MossdeepCity/scripts.pory"
	release
# 292 "data/maps/MossdeepCity/scripts.pory"
	end
# 293 "data/maps/MossdeepCity/scripts.pory"

# 294 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedTM96::
# 295 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_HaveTM96, MSGBOX_DEFAULT
# 296 "data/maps/MossdeepCity/scripts.pory"
	release
# 297 "data/maps/MossdeepCity/scripts.pory"
	end
# 298 "data/maps/MossdeepCity/scripts.pory"

# 299 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerWatchScottExit: @ 81E4CD4
# 300 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 301 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 302 "data/maps/MossdeepCity/scripts.pory"
	walk_in_place_fastest_left
# 303 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 304 "data/maps/MossdeepCity/scripts.pory"

# 305 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitNorth: @ 81E4CD8
# 306 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 307 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 308 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 309 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 310 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 311 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 312 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 313 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 314 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 315 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 316 "data/maps/MossdeepCity/scripts.pory"

# 317 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitEast: @ 81E4CE2
# 318 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 319 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 320 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 321 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 322 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 323 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 324 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 325 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 326 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 327 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 328 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 329 "data/maps/MossdeepCity/scripts.pory"

# 330 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WantKingsRockStevenGaveMe: @ 81E4CED
# 331 "data/maps/MossdeepCity/scripts.pory"
	.string "I got this from Steven, but I don't\n"
# 332 "data/maps/MossdeepCity/scripts.pory"
	.string "know what it's good for.\p"
# 333 "data/maps/MossdeepCity/scripts.pory"
	.string "I think it's called King's Rock.\n"
# 334 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want it?$"
# 335 "data/maps/MossdeepCity/scripts.pory"

# 336 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_YouCanKeepIt: @ 81E4D5B
# 337 "data/maps/MossdeepCity/scripts.pory"
	.string "Why would you want it?\n"
# 338 "data/maps/MossdeepCity/scripts.pory"
	.string "You're weird.\p"
# 339 "data/maps/MossdeepCity/scripts.pory"
	.string "You can keep it, but keep it a secret\n"
# 340 "data/maps/MossdeepCity/scripts.pory"
	.string "from Steven.$"
# 341 "data/maps/MossdeepCity/scripts.pory"

# 342 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_StevensHouseOverThere: @ 81E4DB3
# 343 "data/maps/MossdeepCity/scripts.pory"
	.string "Steven's house is right over there!$"
# 344 "data/maps/MossdeepCity/scripts.pory"

# 345 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WhatToDoWithWeirdRock: @ 81E4DD7
# 346 "data/maps/MossdeepCity/scripts.pory"
	.string "Yeah, you think so, too! What are you\n"
# 347 "data/maps/MossdeepCity/scripts.pory"
	.string "supposed to do with some weird rock?$"
# 348 "data/maps/MossdeepCity/scripts.pory"

# 349 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WailmerWatching: @ 81E4E22
# 350 "data/maps/MossdeepCity/scripts.pory"
	.string "Around Mossdeep, you can see wild\n"
# 351 "data/maps/MossdeepCity/scripts.pory"
	.string "Wailmer.\p"
# 352 "data/maps/MossdeepCity/scripts.pory"
	.string "It's called, uh…\n"
# 353 "data/maps/MossdeepCity/scripts.pory"
	.string "What was it now…\p"
# 354 "data/maps/MossdeepCity/scripts.pory"
	.string "Wai, Wai, Wai…\p"
# 355 "data/maps/MossdeepCity/scripts.pory"
	.string "Wailmer watching!$"
# 356 "data/maps/MossdeepCity/scripts.pory"

# 357 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterReceivedLetter: @ 81E4E90
# 358 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's Space Center has been\n"
# 359 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.\p"
# 360 "data/maps/MossdeepCity/scripts.pory"
	.string "There's been some kind of an uproar\n"
# 361 "data/maps/MossdeepCity/scripts.pory"
	.string "over a letter they received recently.$"
# 362 "data/maps/MossdeepCity/scripts.pory"

# 363 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterLaunchingRockets: @ 81E4F15
# 364 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's Space Center has been\n"
# 365 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.$"
# 366 "data/maps/MossdeepCity/scripts.pory"

# 367 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_MossdeepTargetedByMagma: @ 81E4F50
# 368 "data/maps/MossdeepCity/scripts.pory"
	.string "I heard from a Sailor buddy that\n"
# 369 "data/maps/MossdeepCity/scripts.pory"
	.string "Team Aqua set up shop in Lilycove.\p"
# 370 "data/maps/MossdeepCity/scripts.pory"
	.string "I also heard that someone came along\n"
# 371 "data/maps/MossdeepCity/scripts.pory"
	.string "and wiped the floor with them!\p"
# 372 "data/maps/MossdeepCity/scripts.pory"
	.string "But Mossdeep here's been targeted\n"
# 373 "data/maps/MossdeepCity/scripts.pory"
	.string "by that Team Magma.\p"
# 374 "data/maps/MossdeepCity/scripts.pory"
	.string "If you want to know what they're up to,\n"
# 375 "data/maps/MossdeepCity/scripts.pory"
	.string "go visit the Space Center.$"
# 376 "data/maps/MossdeepCity/scripts.pory"

# 377 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_FeelReliefOnLand: @ 81E5051
# 378 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm a Sailor, so the sea's obviously\n"
# 379 "data/maps/MossdeepCity/scripts.pory"
	.string "more important to me.\p"
# 380 "data/maps/MossdeepCity/scripts.pory"
	.string "But you know? When I get back on land\n"
# 381 "data/maps/MossdeepCity/scripts.pory"
	.string "after a long voyage, I do feel relief!$"
# 382 "data/maps/MossdeepCity/scripts.pory"

# 383 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_NiceIfWorldCoveredByFlowers: @ 81E50D9
# 384 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't it be nice?\p"
# 385 "data/maps/MossdeepCity/scripts.pory"
	.string "If the whole world was covered in\n"
# 386 "data/maps/MossdeepCity/scripts.pory"
	.string "plants and flowers like this island?$"
# 387 "data/maps/MossdeepCity/scripts.pory"

# 388 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_LifeNeedsSeaToLive: @ 81E5135
# 389 "data/maps/MossdeepCity/scripts.pory"
	.string "All life needs the sea to live, even\n"
# 390 "data/maps/MossdeepCity/scripts.pory"
	.string "though it makes its home on the land.\p"
# 391 "data/maps/MossdeepCity/scripts.pory"
	.string "Life, having run its course, becomes\n"
# 392 "data/maps/MossdeepCity/scripts.pory"
	.string "soil and returns to the land.\p"
# 393 "data/maps/MossdeepCity/scripts.pory"
	.string "And the sea is always connected to\n"
# 394 "data/maps/MossdeepCity/scripts.pory"
	.string "the land.\p"
# 395 "data/maps/MossdeepCity/scripts.pory"
	.string "Yes, like the very shoreline here.$"
# 396 "data/maps/MossdeepCity/scripts.pory"

# 397 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SurfExhilarating: @ 81E5213
# 398 "data/maps/MossdeepCity/scripts.pory"
	.string "A voyage on a ship is fine.\p"
# 399 "data/maps/MossdeepCity/scripts.pory"
	.string "But crossing the sea with Pokémon\n"
# 400 "data/maps/MossdeepCity/scripts.pory"
	.string "using Surf…\p"
# 401 "data/maps/MossdeepCity/scripts.pory"
	.string "Now that's an exhilarating trip!\n"
# 402 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't you agree, youngster?$"
# 403 "data/maps/MossdeepCity/scripts.pory"

# 404 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpecialSpaceCenterRock: @ 81E529D
# 405 "data/maps/MossdeepCity/scripts.pory"
	.string "This rock has a special meaning to\n"
# 406 "data/maps/MossdeepCity/scripts.pory"
	.string "the people at the Space Center.\p"
# 407 "data/maps/MossdeepCity/scripts.pory"
	.string "They put it here as their wish for\n"
# 408 "data/maps/MossdeepCity/scripts.pory"
	.string "their rockets to fly safely.\p"
# 409 "data/maps/MossdeepCity/scripts.pory"
	.string "When you make a wish, what do you use?\n"
# 410 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you wish upon a star?\p"
# 411 "data/maps/MossdeepCity/scripts.pory"
	.string "I use a wish tag to make it happen.\n"
# 412 "data/maps/MossdeepCity/scripts.pory"
	.string "That's what I do.$"
# 413 "data/maps/MossdeepCity/scripts.pory"

# 414 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ItsAWhiteRock: @ 81E5396
# 415 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"
# 416 "data/maps/MossdeepCity/scripts.pory"

# 417 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_GymSign: @ 81E53A9
# 418 "data/maps/MossdeepCity/scripts.pory"
	.string "Mossdeep City Pokémon Gym\n"
# 419 "data/maps/MossdeepCity/scripts.pory"
	.string "Leaders: Tate & Liza\p"
# 420 "data/maps/MossdeepCity/scripts.pory"
	.string "“The mystic combination!”$"
# 421 "data/maps/MossdeepCity/scripts.pory"

# 422 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_CitySign: @ 81E53F2
# 423 "data/maps/MossdeepCity/scripts.pory"
	.string "Mossdeep City\n"
# 424 "data/maps/MossdeepCity/scripts.pory"
	.string "“Our slogan: Cherish Pokémon!”$"
# 425 "data/maps/MossdeepCity/scripts.pory"

# 426 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterSign: @ 81E541F
# 427 "data/maps/MossdeepCity/scripts.pory"
	.string "Mossdeep Space Center\n"
# 428 "data/maps/MossdeepCity/scripts.pory"
	.string "“The closest place to space.”$"
# 429 "data/maps/MossdeepCity/scripts.pory"

# 430 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ScottSomethingWrongWithTown: @ 81E5453
# 431 "data/maps/MossdeepCity/scripts.pory"
	.string "Scott: {PLAYER}{KUN}, feeling good?\n"
# 432 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm doing great!\p"
# 433 "data/maps/MossdeepCity/scripts.pory"
	.string "I'd heard Mossdeep's Gym Leader is\n"
# 434 "data/maps/MossdeepCity/scripts.pory"
	.string "pretty strong, so I decided to come\l"
# 435 "data/maps/MossdeepCity/scripts.pory"
	.string "take a look-see for myself.\p"
# 436 "data/maps/MossdeepCity/scripts.pory"
	.string "But there's something wrong about\n"
# 437 "data/maps/MossdeepCity/scripts.pory"
	.string "this town.\p"
# 438 "data/maps/MossdeepCity/scripts.pory"
	.string "People are going on about a warning\n"
# 439 "data/maps/MossdeepCity/scripts.pory"
	.string "letter and the Space Center…\p"
# 440 "data/maps/MossdeepCity/scripts.pory"
	.string "I don't think it concerns me in any\n"
# 441 "data/maps/MossdeepCity/scripts.pory"
	.string "way, though.$"
# 442 "data/maps/MossdeepCity/scripts.pory"

# 443 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SootopolisNewGymLeader: @ 81E5581
# 444 "data/maps/MossdeepCity/scripts.pory"
	.string "Ahh… It feels great letting the waves\n"
# 445 "data/maps/MossdeepCity/scripts.pory"
	.string "wash over my feet…\p"
# 446 "data/maps/MossdeepCity/scripts.pory"
	.string "Speaking of the waves, you know that\n"
# 447 "data/maps/MossdeepCity/scripts.pory"
	.string "island city Sootopolis?\p"
# 448 "data/maps/MossdeepCity/scripts.pory"
	.string "I think the Gym there had a new\n"
# 449 "data/maps/MossdeepCity/scripts.pory"
	.string "Leader come in.\p"
# 450 "data/maps/MossdeepCity/scripts.pory"
	.string "People tell me the new Leader once\n"
# 451 "data/maps/MossdeepCity/scripts.pory"
	.string "mentored Wallace.$"
# 452 "data/maps/MossdeepCity/scripts.pory"

# 453 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_AvalancheNonsense:
# 454 "data/maps/MossdeepCity/scripts.pory"
	.string "You Trainer?\p"
# 455 "data/maps/MossdeepCity/scripts.pory"
	.string "Take TM!$"
# 456 "data/maps/MossdeepCity/scripts.pory"

# 457 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_HaveTM96:
# 458 "data/maps/MossdeepCity/scripts.pory"
	.string "… … … … … … … … … … … … … … … …\p"
# 459 "data/maps/MossdeepCity/scripts.pory"
	.string "… … … … … … … … … … … … … … … …\p"
# 460 "data/maps/MossdeepCity/scripts.pory"
	.string "(Seems he has nothing to say…)$"
