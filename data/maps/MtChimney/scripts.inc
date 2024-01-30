# 1 "data/maps/MtChimney/scripts.pory"

# 2 "data/maps/MtChimney/scripts.pory"
.set LOCALID_ARCHIE, 1
# 3 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAXIE, 2
# 4 "data/maps/MtChimney/scripts.pory"
.set LOCALID_TABITHA, 3
# 5 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAGMA_GRUNT_2, 22
# 6 "data/maps/MtChimney/scripts.pory"
.set LOCALID_MAGMA_GRUNT_1, 29
# 7 "data/maps/MtChimney/scripts.pory"

# 8 "data/maps/MtChimney/scripts.pory"

# 9 "data/maps/MtChimney/scripts.pory"
MtChimney_MapScripts:: @ 822EDC1
# 10 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
# 11 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
# 12 "data/maps/MtChimney/scripts.pory"
	.byte 0
# 13 "data/maps/MtChimney/scripts.pory"

# 14 "data/maps/MtChimney/scripts.pory"
MtChimney_OnTransition: @ 822EDCC
# 15 "data/maps/MtChimney/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
# 16 "data/maps/MtChimney/scripts.pory"
	end
# 17 "data/maps/MtChimney/scripts.pory"

# 18 "data/maps/MtChimney/scripts.pory"
MtChimney_OnResume: @ 822EDD2
# 19 "data/maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_ASH
# 20 "data/maps/MtChimney/scripts.pory"
	end
# 21 "data/maps/MtChimney/scripts.pory"

# 22 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie:: @ 822EDD5
# 23 "data/maps/MtChimney/scripts.pory"
	lock
# 24 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 25 "data/maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 26 "data/maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 27 "data/maps/MtChimney/scripts.pory"
	closemessage
# 28 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
# 29 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 30 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 31 "data/maps/MtChimney/scripts.pory"
	release
# 32 "data/maps/MtChimney/scripts.pory"
	end
# 33 "data/maps/MtChimney/scripts.pory"

# 34 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma:: @ 822EDF9
# 35 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 36 "data/maps/MtChimney/scripts.pory"
	return
# 37 "data/maps/MtChimney/scripts.pory"

# 38 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting:: @ 822EE02
# 39 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 40 "data/maps/MtChimney/scripts.pory"
	return
# 41 "data/maps/MtChimney/scripts.pory"

# 42 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie:: @ 822EE0B
# 43 "data/maps/MtChimney/scripts.pory"
	lockall
# 44 "data/maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 45 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 46 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 47 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 48 "data/maps/MtChimney/scripts.pory"
	playse SE_PIN
# 49 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
# 50 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 51 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
# 52 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 53 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 54 "data/maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 55 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 56 "data/maps/MtChimney/scripts.pory"
	closemessage
# 57 "data/maps/MtChimney/scripts.pory"
	delay 30
# 58 "data/maps/MtChimney/scripts.pory"
	fadescreen FADE_TO_BLACK
# 59 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAXIE
# 60 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_1
# 61 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_TABITHA
# 62 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MAGMA_GRUNT_2
# 63 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 64 "data/maps/MtChimney/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 65 "data/maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_ARCHIE, 10, 12
# 66 "data/maps/MtChimney/scripts.pory"
	addobject LOCALID_ARCHIE
# 67 "data/maps/MtChimney/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 68 "data/maps/MtChimney/scripts.pory"
	call_if_eq MtChimney_EventScript_ArchieApproachPlayerEast
# 69 "data/maps/MtChimney/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 70 "data/maps/MtChimney/scripts.pory"
	call_if_eq MtChimney_EventScript_ArchieApproachPlayerNorth
# 71 "data/maps/MtChimney/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 72 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 73 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 74 "data/maps/MtChimney/scripts.pory"
	closemessage
# 75 "data/maps/MtChimney/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 76 "data/maps/MtChimney/scripts.pory"
	call_if_eq MtChimney_EventScript_ArchieExitEast
# 77 "data/maps/MtChimney/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 78 "data/maps/MtChimney/scripts.pory"
	call_if_eq MtChimney_EventScript_ArchieExitNorth
# 79 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_ARCHIE
# 80 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 81 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 82 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
# 83 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 84 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 85 "data/maps/MtChimney/scripts.pory"
	releaseall
# 86 "data/maps/MtChimney/scripts.pory"
	end
# 87 "data/maps/MtChimney/scripts.pory"

# 88 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast:: @ 822EEC7
# 89 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 90 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 91 "data/maps/MtChimney/scripts.pory"
	return
# 92 "data/maps/MtChimney/scripts.pory"

# 93 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth:: @ 822EED2
# 94 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 95 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 96 "data/maps/MtChimney/scripts.pory"
	return
# 97 "data/maps/MtChimney/scripts.pory"

# 98 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast:: @ 822EEDD
# 99 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
# 100 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 101 "data/maps/MtChimney/scripts.pory"
	return
# 102 "data/maps/MtChimney/scripts.pory"

# 103 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth:: @ 822EEE8
# 104 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 105 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 106 "data/maps/MtChimney/scripts.pory"
	return
# 107 "data/maps/MtChimney/scripts.pory"

# 108 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady:: @ 822EEF3
# 109 "data/maps/MtChimney/scripts.pory"
	lock
# 110 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 111 "data/maps/MtChimney/scripts.pory"
	showmoneybox 0, 0, 0
# 112 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 113 "data/maps/MtChimney/scripts.pory"
	compare VAR_RESULT, NO
# 114 "data/maps/MtChimney/scripts.pory"
	goto_if_eq MtChimney_EventScript_DeclineLavaCookie
# 115 "data/maps/MtChimney/scripts.pory"
	checkmoney 200, 0
# 116 "data/maps/MtChimney/scripts.pory"
	compare VAR_RESULT, FALSE
# 117 "data/maps/MtChimney/scripts.pory"
	goto_if_eq MtChimney_EventScript_NotEnoughMoney
# 118 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 119 "data/maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE, 1
# 120 "data/maps/MtChimney/scripts.pory"
	compare VAR_RESULT, TRUE
# 121 "data/maps/MtChimney/scripts.pory"
	call_if_eq MtChimney_EventScript_RemoveMoney
# 122 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 123 "data/maps/MtChimney/scripts.pory"
	compare VAR_RESULT, FALSE
# 124 "data/maps/MtChimney/scripts.pory"
	goto_if_eq MtChimney_EventScript_BagIsFull
# 125 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 126 "data/maps/MtChimney/scripts.pory"
	release
# 127 "data/maps/MtChimney/scripts.pory"
	end
# 128 "data/maps/MtChimney/scripts.pory"

# 129 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull:: @ 822EF51
# 130 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 131 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 132 "data/maps/MtChimney/scripts.pory"
	release
# 133 "data/maps/MtChimney/scripts.pory"
	end
# 134 "data/maps/MtChimney/scripts.pory"

# 135 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney:: @ 822EF5E
# 136 "data/maps/MtChimney/scripts.pory"
	removemoney 200, 0
# 137 "data/maps/MtChimney/scripts.pory"
	updatemoneybox 0, 0
# 138 "data/maps/MtChimney/scripts.pory"
	return
# 139 "data/maps/MtChimney/scripts.pory"

# 140 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie:: @ 822EF69
# 141 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 142 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 143 "data/maps/MtChimney/scripts.pory"
	release
# 144 "data/maps/MtChimney/scripts.pory"
	end
# 145 "data/maps/MtChimney/scripts.pory"

# 146 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney:: @ 822EF76
# 147 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 148 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 149 "data/maps/MtChimney/scripts.pory"
	release
# 150 "data/maps/MtChimney/scripts.pory"
	end
# 151 "data/maps/MtChimney/scripts.pory"

# 152 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast: @ 822EF83
# 153 "data/maps/MtChimney/scripts.pory"
	walk_up
# 154 "data/maps/MtChimney/scripts.pory"
	walk_up
# 155 "data/maps/MtChimney/scripts.pory"
	walk_up
# 156 "data/maps/MtChimney/scripts.pory"
	walk_up
# 157 "data/maps/MtChimney/scripts.pory"
	walk_up
# 158 "data/maps/MtChimney/scripts.pory"
	walk_up
# 159 "data/maps/MtChimney/scripts.pory"
	walk_right
# 160 "data/maps/MtChimney/scripts.pory"
	step_end
# 161 "data/maps/MtChimney/scripts.pory"

# 162 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast: @ 822EF8B
# 163 "data/maps/MtChimney/scripts.pory"
	walk_left
# 164 "data/maps/MtChimney/scripts.pory"
	walk_down
# 165 "data/maps/MtChimney/scripts.pory"
	walk_down
# 166 "data/maps/MtChimney/scripts.pory"
	walk_down
# 167 "data/maps/MtChimney/scripts.pory"
	walk_down
# 168 "data/maps/MtChimney/scripts.pory"
	walk_down
# 169 "data/maps/MtChimney/scripts.pory"
	walk_down
# 170 "data/maps/MtChimney/scripts.pory"
	walk_down
# 171 "data/maps/MtChimney/scripts.pory"
	step_end
# 172 "data/maps/MtChimney/scripts.pory"

# 173 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth: @ 822EF94
# 174 "data/maps/MtChimney/scripts.pory"
	walk_up
# 175 "data/maps/MtChimney/scripts.pory"
	walk_up
# 176 "data/maps/MtChimney/scripts.pory"
	walk_up
# 177 "data/maps/MtChimney/scripts.pory"
	walk_up
# 178 "data/maps/MtChimney/scripts.pory"
	walk_up
# 179 "data/maps/MtChimney/scripts.pory"
	walk_right
# 180 "data/maps/MtChimney/scripts.pory"
	walk_right
# 181 "data/maps/MtChimney/scripts.pory"
	step_end
# 182 "data/maps/MtChimney/scripts.pory"

# 183 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth: @ 822EF9C
# 184 "data/maps/MtChimney/scripts.pory"
	walk_left
# 185 "data/maps/MtChimney/scripts.pory"
	walk_left
# 186 "data/maps/MtChimney/scripts.pory"
	walk_down
# 187 "data/maps/MtChimney/scripts.pory"
	walk_down
# 188 "data/maps/MtChimney/scripts.pory"
	walk_down
# 189 "data/maps/MtChimney/scripts.pory"
	walk_down
# 190 "data/maps/MtChimney/scripts.pory"
	walk_down
# 191 "data/maps/MtChimney/scripts.pory"
	walk_down
# 192 "data/maps/MtChimney/scripts.pory"
	walk_down
# 193 "data/maps/MtChimney/scripts.pory"
	step_end
# 194 "data/maps/MtChimney/scripts.pory"

# 195 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1: @ 822EFA6
# 196 "data/maps/MtChimney/scripts.pory"
	walk_down
# 197 "data/maps/MtChimney/scripts.pory"
	walk_down
# 198 "data/maps/MtChimney/scripts.pory"
	walk_down
# 199 "data/maps/MtChimney/scripts.pory"
	walk_down
# 200 "data/maps/MtChimney/scripts.pory"
	walk_down
# 201 "data/maps/MtChimney/scripts.pory"
	walk_left
# 202 "data/maps/MtChimney/scripts.pory"
	walk_left
# 203 "data/maps/MtChimney/scripts.pory"
	walk_down
# 204 "data/maps/MtChimney/scripts.pory"
	walk_down
# 205 "data/maps/MtChimney/scripts.pory"
	walk_down
# 206 "data/maps/MtChimney/scripts.pory"
	walk_down
# 207 "data/maps/MtChimney/scripts.pory"
	walk_left
# 208 "data/maps/MtChimney/scripts.pory"
	walk_left
# 209 "data/maps/MtChimney/scripts.pory"
	walk_left
# 210 "data/maps/MtChimney/scripts.pory"
	walk_left
# 211 "data/maps/MtChimney/scripts.pory"
	walk_left
# 212 "data/maps/MtChimney/scripts.pory"
	walk_down
# 213 "data/maps/MtChimney/scripts.pory"
	step_end
# 214 "data/maps/MtChimney/scripts.pory"

# 215 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2: @ 822EFB8
# 216 "data/maps/MtChimney/scripts.pory"
	walk_down
# 217 "data/maps/MtChimney/scripts.pory"
	walk_down
# 218 "data/maps/MtChimney/scripts.pory"
	walk_down
# 219 "data/maps/MtChimney/scripts.pory"
	walk_down
# 220 "data/maps/MtChimney/scripts.pory"
	walk_left
# 221 "data/maps/MtChimney/scripts.pory"
	walk_left
# 222 "data/maps/MtChimney/scripts.pory"
	walk_left
# 223 "data/maps/MtChimney/scripts.pory"
	walk_down
# 224 "data/maps/MtChimney/scripts.pory"
	step_end
# 225 "data/maps/MtChimney/scripts.pory"

# 226 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3: @ 822EFC1
# 227 "data/maps/MtChimney/scripts.pory"
	walk_right
# 228 "data/maps/MtChimney/scripts.pory"
	walk_down
# 229 "data/maps/MtChimney/scripts.pory"
	walk_down
# 230 "data/maps/MtChimney/scripts.pory"
	walk_down
# 231 "data/maps/MtChimney/scripts.pory"
	walk_down
# 232 "data/maps/MtChimney/scripts.pory"
	walk_left
# 233 "data/maps/MtChimney/scripts.pory"
	walk_left
# 234 "data/maps/MtChimney/scripts.pory"
	walk_left
# 235 "data/maps/MtChimney/scripts.pory"
	walk_left
# 236 "data/maps/MtChimney/scripts.pory"
	walk_left
# 237 "data/maps/MtChimney/scripts.pory"
	walk_down
# 238 "data/maps/MtChimney/scripts.pory"
	walk_down
# 239 "data/maps/MtChimney/scripts.pory"
	walk_down
# 240 "data/maps/MtChimney/scripts.pory"
	walk_down
# 241 "data/maps/MtChimney/scripts.pory"
	step_end
# 242 "data/maps/MtChimney/scripts.pory"

# 243 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4: @ 822EFD0
# 244 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 245 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 246 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 247 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 248 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 249 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 250 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 251 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 252 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 253 "data/maps/MtChimney/scripts.pory"
	walk_left
# 254 "data/maps/MtChimney/scripts.pory"
	walk_left
# 255 "data/maps/MtChimney/scripts.pory"
	walk_down
# 256 "data/maps/MtChimney/scripts.pory"
	walk_down
# 257 "data/maps/MtChimney/scripts.pory"
	walk_down
# 258 "data/maps/MtChimney/scripts.pory"
	walk_left
# 259 "data/maps/MtChimney/scripts.pory"
	walk_left
# 260 "data/maps/MtChimney/scripts.pory"
	walk_down
# 261 "data/maps/MtChimney/scripts.pory"
	walk_down
# 262 "data/maps/MtChimney/scripts.pory"
	walk_left
# 263 "data/maps/MtChimney/scripts.pory"
	walk_left
# 264 "data/maps/MtChimney/scripts.pory"
	walk_left
# 265 "data/maps/MtChimney/scripts.pory"
	walk_left
# 266 "data/maps/MtChimney/scripts.pory"
	walk_left
# 267 "data/maps/MtChimney/scripts.pory"
	walk_down
# 268 "data/maps/MtChimney/scripts.pory"
	step_end
# 269 "data/maps/MtChimney/scripts.pory"

# 270 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5: @ 822EFE9
# 271 "data/maps/MtChimney/scripts.pory"
	delay_16
# 272 "data/maps/MtChimney/scripts.pory"
	delay_16
# 273 "data/maps/MtChimney/scripts.pory"
	delay_16
# 274 "data/maps/MtChimney/scripts.pory"
	walk_down
# 275 "data/maps/MtChimney/scripts.pory"
	walk_down
# 276 "data/maps/MtChimney/scripts.pory"
	walk_down
# 277 "data/maps/MtChimney/scripts.pory"
	walk_left
# 278 "data/maps/MtChimney/scripts.pory"
	walk_left
# 279 "data/maps/MtChimney/scripts.pory"
	walk_left
# 280 "data/maps/MtChimney/scripts.pory"
	walk_down
# 281 "data/maps/MtChimney/scripts.pory"
	step_end
# 282 "data/maps/MtChimney/scripts.pory"

# 283 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6: @ 822EFF4
# 284 "data/maps/MtChimney/scripts.pory"
	delay_16
# 285 "data/maps/MtChimney/scripts.pory"
	walk_left
# 286 "data/maps/MtChimney/scripts.pory"
	walk_down
# 287 "data/maps/MtChimney/scripts.pory"
	walk_down
# 288 "data/maps/MtChimney/scripts.pory"
	walk_down
# 289 "data/maps/MtChimney/scripts.pory"
	walk_down
# 290 "data/maps/MtChimney/scripts.pory"
	walk_left
# 291 "data/maps/MtChimney/scripts.pory"
	walk_left
# 292 "data/maps/MtChimney/scripts.pory"
	walk_left
# 293 "data/maps/MtChimney/scripts.pory"
	walk_left
# 294 "data/maps/MtChimney/scripts.pory"
	walk_left
# 295 "data/maps/MtChimney/scripts.pory"
	walk_down
# 296 "data/maps/MtChimney/scripts.pory"
	walk_down
# 297 "data/maps/MtChimney/scripts.pory"
	walk_down
# 298 "data/maps/MtChimney/scripts.pory"
	walk_down
# 299 "data/maps/MtChimney/scripts.pory"
	step_end
# 300 "data/maps/MtChimney/scripts.pory"

# 301 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7: @ 822F004
# 302 "data/maps/MtChimney/scripts.pory"
	delay_16
# 303 "data/maps/MtChimney/scripts.pory"
	walk_left
# 304 "data/maps/MtChimney/scripts.pory"
	walk_left
# 305 "data/maps/MtChimney/scripts.pory"
	walk_down
# 306 "data/maps/MtChimney/scripts.pory"
	walk_down
# 307 "data/maps/MtChimney/scripts.pory"
	walk_down
# 308 "data/maps/MtChimney/scripts.pory"
	walk_left
# 309 "data/maps/MtChimney/scripts.pory"
	walk_left
# 310 "data/maps/MtChimney/scripts.pory"
	walk_down
# 311 "data/maps/MtChimney/scripts.pory"
	walk_down
# 312 "data/maps/MtChimney/scripts.pory"
	walk_left
# 313 "data/maps/MtChimney/scripts.pory"
	walk_left
# 314 "data/maps/MtChimney/scripts.pory"
	walk_left
# 315 "data/maps/MtChimney/scripts.pory"
	walk_left
# 316 "data/maps/MtChimney/scripts.pory"
	walk_left
# 317 "data/maps/MtChimney/scripts.pory"
	walk_down
# 318 "data/maps/MtChimney/scripts.pory"
	step_end
# 319 "data/maps/MtChimney/scripts.pory"

# 320 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8: @ 822F015
# 321 "data/maps/MtChimney/scripts.pory"
	delay_16
# 322 "data/maps/MtChimney/scripts.pory"
	walk_down
# 323 "data/maps/MtChimney/scripts.pory"
	walk_left
# 324 "data/maps/MtChimney/scripts.pory"
	walk_left
# 325 "data/maps/MtChimney/scripts.pory"
	walk_left
# 326 "data/maps/MtChimney/scripts.pory"
	walk_left
# 327 "data/maps/MtChimney/scripts.pory"
	walk_in_place_fastest_down
# 328 "data/maps/MtChimney/scripts.pory"
	step_end
# 329 "data/maps/MtChimney/scripts.pory"

# 330 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9: @ 822F01D
# 331 "data/maps/MtChimney/scripts.pory"
	walk_down
# 332 "data/maps/MtChimney/scripts.pory"
	walk_down
# 333 "data/maps/MtChimney/scripts.pory"
	walk_down
# 334 "data/maps/MtChimney/scripts.pory"
	walk_down
# 335 "data/maps/MtChimney/scripts.pory"
	walk_left
# 336 "data/maps/MtChimney/scripts.pory"
	walk_left
# 337 "data/maps/MtChimney/scripts.pory"
	walk_left
# 338 "data/maps/MtChimney/scripts.pory"
	walk_left
# 339 "data/maps/MtChimney/scripts.pory"
	walk_left
# 340 "data/maps/MtChimney/scripts.pory"
	walk_down
# 341 "data/maps/MtChimney/scripts.pory"
	walk_down
# 342 "data/maps/MtChimney/scripts.pory"
	walk_down
# 343 "data/maps/MtChimney/scripts.pory"
	walk_down
# 344 "data/maps/MtChimney/scripts.pory"
	step_end
# 345 "data/maps/MtChimney/scripts.pory"

# 346 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10: @ 822F02B
# 347 "data/maps/MtChimney/scripts.pory"
	walk_down
# 348 "data/maps/MtChimney/scripts.pory"
	step_end
# 349 "data/maps/MtChimney/scripts.pory"

# 350 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11: @ 822F02D
# 351 "data/maps/MtChimney/scripts.pory"
	walk_down
# 352 "data/maps/MtChimney/scripts.pory"
	walk_down
# 353 "data/maps/MtChimney/scripts.pory"
	walk_down
# 354 "data/maps/MtChimney/scripts.pory"
	walk_down
# 355 "data/maps/MtChimney/scripts.pory"
	walk_down
# 356 "data/maps/MtChimney/scripts.pory"
	walk_down
# 357 "data/maps/MtChimney/scripts.pory"
	walk_down
# 358 "data/maps/MtChimney/scripts.pory"
	step_end
# 359 "data/maps/MtChimney/scripts.pory"

# 360 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12: @ 822F035
# 361 "data/maps/MtChimney/scripts.pory"
	delay_16
# 362 "data/maps/MtChimney/scripts.pory"
	delay_16
# 363 "data/maps/MtChimney/scripts.pory"
	walk_in_place_fastest_left
# 364 "data/maps/MtChimney/scripts.pory"
	delay_16
# 365 "data/maps/MtChimney/scripts.pory"
	walk_down
# 366 "data/maps/MtChimney/scripts.pory"
	walk_down
# 367 "data/maps/MtChimney/scripts.pory"
	walk_down
# 368 "data/maps/MtChimney/scripts.pory"
	walk_down
# 369 "data/maps/MtChimney/scripts.pory"
	walk_down
# 370 "data/maps/MtChimney/scripts.pory"
	step_end
# 371 "data/maps/MtChimney/scripts.pory"

# 372 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13: @ 822F03F
# 373 "data/maps/MtChimney/scripts.pory"
	delay_16
# 374 "data/maps/MtChimney/scripts.pory"
	delay_16
# 375 "data/maps/MtChimney/scripts.pory"
	delay_16
# 376 "data/maps/MtChimney/scripts.pory"
	delay_16
# 377 "data/maps/MtChimney/scripts.pory"
	delay_16
# 378 "data/maps/MtChimney/scripts.pory"
	delay_16
# 379 "data/maps/MtChimney/scripts.pory"
	walk_in_place_fastest_left
# 380 "data/maps/MtChimney/scripts.pory"
	delay_16
# 381 "data/maps/MtChimney/scripts.pory"
	walk_down
# 382 "data/maps/MtChimney/scripts.pory"
	walk_down
# 383 "data/maps/MtChimney/scripts.pory"
	step_end
# 384 "data/maps/MtChimney/scripts.pory"

# 385 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14: @ 822F04A
# 386 "data/maps/MtChimney/scripts.pory"
	lock_facing_direction
# 387 "data/maps/MtChimney/scripts.pory"
	walk_fast_left
# 388 "data/maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 389 "data/maps/MtChimney/scripts.pory"
	face_right
# 390 "data/maps/MtChimney/scripts.pory"
	step_end
# 391 "data/maps/MtChimney/scripts.pory"

# 392 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15: @ 822F04F
# 393 "data/maps/MtChimney/scripts.pory"
	walk_left
# 394 "data/maps/MtChimney/scripts.pory"
	walk_in_place_fastest_right
# 395 "data/maps/MtChimney/scripts.pory"
	delay_16
# 396 "data/maps/MtChimney/scripts.pory"
	step_end
# 397 "data/maps/MtChimney/scripts.pory"

# 398 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1:: @ 822F053
# 399 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 400 "data/maps/MtChimney/scripts.pory"
	end
# 401 "data/maps/MtChimney/scripts.pory"

# 402 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2:: @ 822F05C
# 403 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 404 "data/maps/MtChimney/scripts.pory"
	end
# 405 "data/maps/MtChimney/scripts.pory"

# 406 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3:: @ 822F065
# 407 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 408 "data/maps/MtChimney/scripts.pory"
	end
# 409 "data/maps/MtChimney/scripts.pory"

# 410 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha:: @ 822F06E
# 411 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 412 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 413 "data/maps/MtChimney/scripts.pory"
	end
# 414 "data/maps/MtChimney/scripts.pory"

# 415 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2:: @ 822F085
# 416 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 417 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 418 "data/maps/MtChimney/scripts.pory"
	end
# 419 "data/maps/MtChimney/scripts.pory"

# 420 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1:: @ 822F09C
# 421 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 422 "data/maps/MtChimney/scripts.pory"
	end
# 423 "data/maps/MtChimney/scripts.pory"

# 424 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2:: @ 822F0A5
# 425 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 426 "data/maps/MtChimney/scripts.pory"
	end
# 427 "data/maps/MtChimney/scripts.pory"

# 428 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3:: @ 822F0AE
# 429 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 430 "data/maps/MtChimney/scripts.pory"
	end
# 431 "data/maps/MtChimney/scripts.pory"

# 432 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4:: @ 822F0B7
# 433 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 434 "data/maps/MtChimney/scripts.pory"
	end
# 435 "data/maps/MtChimney/scripts.pory"

# 436 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5:: @ 822F0C0
# 437 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 438 "data/maps/MtChimney/scripts.pory"
	end
# 439 "data/maps/MtChimney/scripts.pory"

# 440 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6:: @ 822F0C9
# 441 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 442 "data/maps/MtChimney/scripts.pory"
	end
# 443 "data/maps/MtChimney/scripts.pory"

# 444 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena:: @ 822F0D2
# 445 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 446 "data/maps/MtChimney/scripts.pory"
	end
# 447 "data/maps/MtChimney/scripts.pory"

# 448 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena:: @ 822F0DB
# 449 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 450 "data/maps/MtChimney/scripts.pory"
	end
# 451 "data/maps/MtChimney/scripts.pory"

# 452 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine:: @ 822F0E4
# 453 "data/maps/MtChimney/scripts.pory"
	lockall
# 454 "data/maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 455 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 456 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 457 "data/maps/MtChimney/scripts.pory"
	compare VAR_RESULT, NO
# 458 "data/maps/MtChimney/scripts.pory"
	goto_if_eq MtChimney_EventScript_LeaveMeteoriteAlone
# 459 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 460 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 461 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 462 "data/maps/MtChimney/scripts.pory"
	releaseall
# 463 "data/maps/MtChimney/scripts.pory"
	end
# 464 "data/maps/MtChimney/scripts.pory"

# 465 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone:: @ 822F123
# 466 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 467 "data/maps/MtChimney/scripts.pory"
	releaseall
# 468 "data/maps/MtChimney/scripts.pory"
	end
# 469 "data/maps/MtChimney/scripts.pory"

# 470 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff:: @ 822F12D
# 471 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 472 "data/maps/MtChimney/scripts.pory"
	releaseall
# 473 "data/maps/MtChimney/scripts.pory"
	end
# 474 "data/maps/MtChimney/scripts.pory"

# 475 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn:: @ 822F137
# 476 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
# 477 "data/maps/MtChimney/scripts.pory"
	releaseall
# 478 "data/maps/MtChimney/scripts.pory"
	end
# 479 "data/maps/MtChimney/scripts.pory"

# 480 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign:: @ 822F141
# 481 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 482 "data/maps/MtChimney/scripts.pory"
	end
# 483 "data/maps/MtChimney/scripts.pory"

# 484 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby:: @ 822F14A
# 485 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 486 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 487 "data/maps/MtChimney/scripts.pory"
	compare VAR_RESULT, TRUE
# 488 "data/maps/MtChimney/scripts.pory"
	goto_if_eq MtChimney_EventScript_RematchShelby
# 489 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 490 "data/maps/MtChimney/scripts.pory"
	release
# 491 "data/maps/MtChimney/scripts.pory"
	end
# 492 "data/maps/MtChimney/scripts.pory"

# 493 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby:: @ 822F176
# 494 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 495 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 496 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 497 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 498 "data/maps/MtChimney/scripts.pory"
	release
# 499 "data/maps/MtChimney/scripts.pory"
	end
# 500 "data/maps/MtChimney/scripts.pory"

# 501 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby:: @ 822F195
# 502 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 503 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 504 "data/maps/MtChimney/scripts.pory"
	end
# 505 "data/maps/MtChimney/scripts.pory"

# 506 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa:: @ 822F1AC
# 507 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 508 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 509 "data/maps/MtChimney/scripts.pory"
	end
# 510 "data/maps/MtChimney/scripts.pory"

# 511 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila:: @ 822F1C3
# 512 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 513 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 514 "data/maps/MtChimney/scripts.pory"
	end
# 515 "data/maps/MtChimney/scripts.pory"

# 516 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley:: @ 822F1DA
# 517 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 518 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 519 "data/maps/MtChimney/scripts.pory"
	end
# 520 "data/maps/MtChimney/scripts.pory"

# 521 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1:: @ 822F1F1
# 522 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 523 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 524 "data/maps/MtChimney/scripts.pory"
	end
# 525 "data/maps/MtChimney/scripts.pory"

# 526 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer:: @ 822F208
# 527 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 528 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 529 "data/maps/MtChimney/scripts.pory"
	compare VAR_RESULT, TRUE
# 530 "data/maps/MtChimney/scripts.pory"
	goto_if_eq MtChimney_EventScript_SawyerRematch
# 531 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 532 "data/maps/MtChimney/scripts.pory"
	release
# 533 "data/maps/MtChimney/scripts.pory"
	end
# 534 "data/maps/MtChimney/scripts.pory"

# 535 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated:: @ 822F234
# 536 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 537 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 538 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 539 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 540 "data/maps/MtChimney/scripts.pory"
	release
# 541 "data/maps/MtChimney/scripts.pory"
	end
# 542 "data/maps/MtChimney/scripts.pory"

# 543 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch:: @ 822F253
# 544 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 545 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 546 "data/maps/MtChimney/scripts.pory"
	end
# 547 "data/maps/MtChimney/scripts.pory"

# 548 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano: @ 822F26A
# 549 "data/maps/MtChimney/scripts.pory"
	.string "The power contained in the Meteorite…\p"
# 550 "data/maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 551 "data/maps/MtChimney/scripts.pory"
	.string "machine, Mt. Chimney's volcanic\l"
# 552 "data/maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 553 "data/maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 554 "data/maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 555 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 556 "data/maps/MtChimney/scripts.pory"

# 557 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro: @ 822F32E
# 558 "data/maps/MtChimney/scripts.pory"
	.string "Maxie: Hm?\n"
# 559 "data/maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 560 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 561 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 562 "data/maps/MtChimney/scripts.pory"
	.string "I'd heard Archie bemoaning a child\n"
# 563 "data/maps/MtChimney/scripts.pory"
	.string "who's been meddling in Team Aqua's\l"
# 564 "data/maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 565 "data/maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 566 "data/maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 567 "data/maps/MtChimney/scripts.pory"
	.string "interfering with us, Team Magma?\p"
# 568 "data/maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 569 "data/maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 570 "data/maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 571 "data/maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 572 "data/maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 573 "data/maps/MtChimney/scripts.pory"
	.string "That is why Team Magma is dedicated\n"
# 574 "data/maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 575 "data/maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 576 "data/maps/MtChimney/scripts.pory"
	.string "humankind and Pokémon!\p"
# 577 "data/maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 578 "data/maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 579 "data/maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 580 "data/maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 581 "data/maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 582 "data/maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 583 "data/maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 584 "data/maps/MtChimney/scripts.pory"

# 585 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat: @ 822F5CF
# 586 "data/maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 587 "data/maps/MtChimney/scripts.pory"
	.string "I, Maxie, was caught off guard?!$"
# 588 "data/maps/MtChimney/scripts.pory"

# 589 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma: @ 822F5F7
# 590 "data/maps/MtChimney/scripts.pory"
	.string "Maxie: But, enough.\n"
# 591 "data/maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 592 "data/maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 593 "data/maps/MtChimney/scripts.pory"
	.string "you've seen of Team Magma.\p"
# 594 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 595 "data/maps/MtChimney/scripts.pory"
	.string "Even without the Meteorite, if we\n"
# 596 "data/maps/MtChimney/scripts.pory"
	.string "obtain that Orb… Fufufu…$"
# 597 "data/maps/MtChimney/scripts.pory"

# 598 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro: @ 822F6AA
# 599 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 600 "data/maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 601 "data/maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 602 "data/maps/MtChimney/scripts.pory"
	.string "Courtney's already delivered the\l"
# 603 "data/maps/MtChimney/scripts.pory"
	.string "Meteorite from Meteor Falls to\l"
# 604 "data/maps/MtChimney/scripts.pory"
	.string "the Boss!$"
# 605 "data/maps/MtChimney/scripts.pory"

# 606 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat: @ 822F72C
# 607 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 608 "data/maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 609 "data/maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 610 "data/maps/MtChimney/scripts.pory"

# 611 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle: @ 822F76D
# 612 "data/maps/MtChimney/scripts.pory"
	.string "Boss, hurry!\n"
# 613 "data/maps/MtChimney/scripts.pory"
	.string "Give it the Meteorite's energy!\p"
# 614 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 615 "data/maps/MtChimney/scripts.pory"

# 616 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro: @ 822F7A2
# 617 "data/maps/MtChimney/scripts.pory"
	.string "We of Team Magma are working hard for\n"
# 618 "data/maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 619 "data/maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 620 "data/maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 621 "data/maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 622 "data/maps/MtChimney/scripts.pory"

# 623 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat: @ 822F83A
# 624 "data/maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 625 "data/maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 626 "data/maps/MtChimney/scripts.pory"

# 627 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle: @ 822F859
# 628 "data/maps/MtChimney/scripts.pory"
	.string "Our Boss says, “It will make everyone\n"
# 629 "data/maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 630 "data/maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 631 "data/maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 632 "data/maps/MtChimney/scripts.pory"

# 633 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro: @ 822F8B6
# 634 "data/maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 635 "data/maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 636 "data/maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 637 "data/maps/MtChimney/scripts.pory"

# 638 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat: @ 822F921
# 639 "data/maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 640 "data/maps/MtChimney/scripts.pory"

# 641 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle: @ 822F93A
# 642 "data/maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 643 "data/maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 644 "data/maps/MtChimney/scripts.pory"

# 645 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans: @ 822F978
# 646 "data/maps/MtChimney/scripts.pory"
	.string "That annoying Team Aqua…\n"
# 647 "data/maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 648 "data/maps/MtChimney/scripts.pory"

# 649 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower: @ 822F9B2
# 650 "data/maps/MtChimney/scripts.pory"
	.string "Meteorites pack amazing power!$"
# 651 "data/maps/MtChimney/scripts.pory"

# 652 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs: @ 822F9D1
# 653 "data/maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 654 "data/maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 655 "data/maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 656 "data/maps/MtChimney/scripts.pory"

# 657 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar: @ 822FA2F
# 658 "data/maps/MtChimney/scripts.pory"
	.string "We're Team Magma!\p"
# 659 "data/maps/MtChimney/scripts.pory"
	.string "They're Team Aqua!\p"
# 660 "data/maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 661 "data/maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 662 "data/maps/MtChimney/scripts.pory"

# 663 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire: @ 822FA8B
# 664 "data/maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 665 "data/maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 666 "data/maps/MtChimney/scripts.pory"

# 667 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand: @ 822FAA5
# 668 "data/maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 669 "data/maps/MtChimney/scripts.pory"

# 670 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh: @ 822FACB
# 671 "data/maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 672 "data/maps/MtChimney/scripts.pory"

# 673 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma: @ 822FAD2
# 674 "data/maps/MtChimney/scripts.pory"
	.string "Archie: Grr, {PLAYER}!\n"
# 675 "data/maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 676 "data/maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 677 "data/maps/MtChimney/scripts.pory"
	.string "of Team Magma are up to!\p"
# 678 "data/maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 679 "data/maps/MtChimney/scripts.pory"
	.string "Meteorite's power into the volcano!\p"
# 680 "data/maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 681 "data/maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 682 "data/maps/MtChimney/scripts.pory"

# 683 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull: @ 822FBC7
# 684 "data/maps/MtChimney/scripts.pory"
	.string "Archie: Grrr…\p"
# 685 "data/maps/MtChimney/scripts.pory"
	.string "I want to stop that Maxie,\n"
# 686 "data/maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 687 "data/maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 688 "data/maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 689 "data/maps/MtChimney/scripts.pory"

# 690 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou: @ 822FC3D
# 691 "data/maps/MtChimney/scripts.pory"
	.string "Archie: {PLAYER}!\n"
# 692 "data/maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 693 "data/maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted Team\n"
# 694 "data/maps/MtChimney/scripts.pory"
	.string "Magma's destructive plan!\p"
# 695 "data/maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 696 "data/maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 697 "data/maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 698 "data/maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 699 "data/maps/MtChimney/scripts.pory"
	.string "our pursuit of Team Magma.\p"
# 700 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 701 "data/maps/MtChimney/scripts.pory"

# 702 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs: @ 822FD1F
# 703 "data/maps/MtChimney/scripts.pory"
	.string "Darn… Team Magma outnumbers us!\n"
# 704 "data/maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 705 "data/maps/MtChimney/scripts.pory"

# 706 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon: @ 822FD5B
# 707 "data/maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 708 "data/maps/MtChimney/scripts.pory"
	.string "less habitats for Water Pokémon!$"
# 709 "data/maps/MtChimney/scripts.pory"

# 710 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar: @ 822FDA1
# 711 "data/maps/MtChimney/scripts.pory"
	.string "We're Team Aqua!\p"
# 712 "data/maps/MtChimney/scripts.pory"
	.string "They're Team Magma!\p"
# 713 "data/maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 714 "data/maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 715 "data/maps/MtChimney/scripts.pory"

# 716 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa: @ 822FDFC
# 717 "data/maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 718 "data/maps/MtChimney/scripts.pory"

# 719 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200: @ 822FE04
# 720 "data/maps/MtChimney/scripts.pory"
	.string "Lava Cookies are Mt. Chimney's local\n"
# 721 "data/maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 722 "data/maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 723 "data/maps/MtChimney/scripts.pory"

# 724 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear: @ 822FE4D
# 725 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 726 "data/maps/MtChimney/scripts.pory"

# 727 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney: @ 822FE5E
# 728 "data/maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 729 "data/maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 730 "data/maps/MtChimney/scripts.pory"

# 731 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen: @ 822FE9B
# 732 "data/maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 733 "data/maps/MtChimney/scripts.pory"

# 734 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MetoriteFittedOnMachine: @ 822FEAA
# 735 "data/maps/MtChimney/scripts.pory"
	.string "A Meteorite is fitted on a mysterious\n"
# 736 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 737 "data/maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 738 "data/maps/MtChimney/scripts.pory"
	.string "energy in the Meteorite.$"
# 739 "data/maps/MtChimney/scripts.pory"

# 740 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite: @ 822FF12
# 741 "data/maps/MtChimney/scripts.pory"
	.string "A Meteorite is fitted on a mysterious\n"
# 742 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 743 "data/maps/MtChimney/scripts.pory"
	.string "Do you want to remove the Meteorite?$"
# 744 "data/maps/MtChimney/scripts.pory"

# 745 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite: @ 822FF66
# 746 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the Meteorite from\n"
# 747 "data/maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 748 "data/maps/MtChimney/scripts.pory"

# 749 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite: @ 822FF9C
# 750 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the Meteorite where\n"
# 751 "data/maps/MtChimney/scripts.pory"
	.string "it was.$"
# 752 "data/maps/MtChimney/scripts.pory"

# 753 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse: @ 822FFC0
# 754 "data/maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 755 "data/maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 756 "data/maps/MtChimney/scripts.pory"

# 757 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign: @ 822FFFA
# 758 "data/maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} Jagged Pass\n"
# 759 "data/maps/MtChimney/scripts.pory"
	.string "Lavaridge Town Ahead$"
# 760 "data/maps/MtChimney/scripts.pory"

# 761 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro: @ 823001D
# 762 "data/maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 763 "data/maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 764 "data/maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 765 "data/maps/MtChimney/scripts.pory"

# 766 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat: @ 8230076
# 767 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 768 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 769 "data/maps/MtChimney/scripts.pory"

# 770 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle: @ 82300A2
# 771 "data/maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 772 "data/maps/MtChimney/scripts.pory"
	.string "myself an Expert now, can I?$"
# 773 "data/maps/MtChimney/scripts.pory"

# 774 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister: @ 82300E3
# 775 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 776 "data/maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 777 "data/maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 778 "data/maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 779 "data/maps/MtChimney/scripts.pory"

# 780 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro: @ 8230153
# 781 "data/maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 782 "data/maps/MtChimney/scripts.pory"
	.string "of your Pokémon, why, you should be\l"
# 783 "data/maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 784 "data/maps/MtChimney/scripts.pory"

# 785 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat: @ 82301BB
# 786 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 787 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 788 "data/maps/MtChimney/scripts.pory"

# 789 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch: @ 82301E7
# 790 "data/maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 791 "data/maps/MtChimney/scripts.pory"
	.string "with the hearts of your Pokémon.$"
# 792 "data/maps/MtChimney/scripts.pory"

# 793 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro: @ 823022A
# 794 "data/maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 795 "data/maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 796 "data/maps/MtChimney/scripts.pory"

# 797 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat: @ 823026D
# 798 "data/maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 799 "data/maps/MtChimney/scripts.pory"

# 800 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle: @ 8230292
# 801 "data/maps/MtChimney/scripts.pory"
	.string "The heat of Mt. Chimney warms\n"
# 802 "data/maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 803 "data/maps/MtChimney/scripts.pory"

# 804 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro: @ 82302BD
# 805 "data/maps/MtChimney/scripts.pory"
	.string "I've finally made it to Mt. Chimney.\n"
# 806 "data/maps/MtChimney/scripts.pory"
	.string "I want to make my Pokémon battle!$"
# 807 "data/maps/MtChimney/scripts.pory"

# 808 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat: @ 8230304
# 809 "data/maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 810 "data/maps/MtChimney/scripts.pory"
	.string "It's like a Mt. Chimney eruption!$"
# 811 "data/maps/MtChimney/scripts.pory"

# 812 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle: @ 823033A
# 813 "data/maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 814 "data/maps/MtChimney/scripts.pory"
	.string "Mt. Chimney. It would be a shame if\l"
# 815 "data/maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 816 "data/maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 817 "data/maps/MtChimney/scripts.pory"
	.string "Cookies as souvenirs.$"
# 818 "data/maps/MtChimney/scripts.pory"

# 819 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro: @ 82303DF
# 820 "data/maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 821 "data/maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 822 "data/maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 823 "data/maps/MtChimney/scripts.pory"

# 824 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat: @ 8230436
# 825 "data/maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 826 "data/maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 827 "data/maps/MtChimney/scripts.pory"

# 828 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle: @ 8230463
# 829 "data/maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 830 "data/maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 831 "data/maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 832 "data/maps/MtChimney/scripts.pory"

# 833 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro: @ 82304B3
# 834 "data/maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 835 "data/maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 836 "data/maps/MtChimney/scripts.pory"

# 837 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat: @ 82304F7
# 838 "data/maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 839 "data/maps/MtChimney/scripts.pory"

# 840 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle: @ 8230519
# 841 "data/maps/MtChimney/scripts.pory"
	.string "I think I need a dip in Lavaridge\n"
# 842 "data/maps/MtChimney/scripts.pory"
	.string "Hot Spring with the locals!$"
# 843 "data/maps/MtChimney/scripts.pory"

# 844 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister: @ 8230557
# 845 "data/maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 846 "data/maps/MtChimney/scripts.pory"
	.string "Let me register you in my PokéNav.$"
# 847 "data/maps/MtChimney/scripts.pory"

# 848 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro: @ 823059C
# 849 "data/maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 850 "data/maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 851 "data/maps/MtChimney/scripts.pory"

# 852 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat: @ 82305E3
# 853 "data/maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 854 "data/maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 855 "data/maps/MtChimney/scripts.pory"

# 856 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch: @ 8230614
# 857 "data/maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 858 "data/maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"
