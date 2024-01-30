# 1 "data/maps/SkyPillar_Outside/scripts.pory"

# 2 "data/maps/SkyPillar_Outside/scripts.pory"
.set LOCALID_WALLACE, 1
# 3 "data/maps/SkyPillar_Outside/scripts.pory"
.set LOCALID_GAUNTLET_TRAINER_1, 2 // Expert M middle
# 4 "data/maps/SkyPillar_Outside/scripts.pory"
.set LOCALID_GAUNTLET_TRAINER_2, 3 // Expert F right
# 5 "data/maps/SkyPillar_Outside/scripts.pory"
.set LOCALID_GAUNTLET_TRAINER_3, 4 // Expert F left
# 6 "data/maps/SkyPillar_Outside/scripts.pory"

# 7 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_MapScripts:: @ 82392A8
# 8 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
# 9 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
# 10 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_OnFrame
# 11 "data/maps/SkyPillar_Outside/scripts.pory"
	.byte 0
# 12 "data/maps/SkyPillar_Outside/scripts.pory"

# 13 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_OnTransition: @ 82392B8
# 14 "data/maps/SkyPillar_Outside/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 3
# 15 "data/maps/SkyPillar_Outside/scripts.pory"
	call_if_eq SkyPillar_Outside_EventScript_HideMapNamePopup
# 16 "data/maps/SkyPillar_Outside/scripts.pory"
	compare VAR_SOOTOPOLIS_CITY_STATE, 4
# 17 "data/maps/SkyPillar_Outside/scripts.pory"
	call_if_ge SkyPillar_Outside_EventScript_CheckSetAbnormalWeather
# 18 "data/maps/SkyPillar_Outside/scripts.pory"
	end
# 19 "data/maps/SkyPillar_Outside/scripts.pory"

# 20 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_EventScript_HideMapNamePopup:: @ 82392CF
# 21 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 22 "data/maps/SkyPillar_Outside/scripts.pory"
	return
# 23 "data/maps/SkyPillar_Outside/scripts.pory"

# 24 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_EventScript_CheckSetAbnormalWeather:: @ 82392D3
# 25 "data/maps/SkyPillar_Outside/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 26 "data/maps/SkyPillar_Outside/scripts.pory"
	return
# 27 "data/maps/SkyPillar_Outside/scripts.pory"

# 28 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_OnLoad: @ 82392DD
# 29 "data/maps/SkyPillar_Outside/scripts.pory"
	call SkyPillar_Outside_EventScript_HideGauntletTrainers
# 30 "data/maps/SkyPillar_Outside/scripts.pory"
	call_if_set FLAG_WALLACE_GOES_TO_SKY_PILLAR, SkyPillar_Outside_EventScript_OpenDoor
# 31 "data/maps/SkyPillar_Outside/scripts.pory"
	end
# 32 "data/maps/SkyPillar_Outside/scripts.pory"

# 33 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_EventScript_OpenDoor:: @ 82392E7
# 34 "data/maps/SkyPillar_Outside/scripts.pory"
	setmetatile 14, 4, METATILE_Pacifidlog_SkyPillar_DoorOpen_Top, 0
# 35 "data/maps/SkyPillar_Outside/scripts.pory"
	setmetatile 14, 5, METATILE_Pacifidlog_SkyPillar_DoorOpen_Bottom, 0
# 36 "data/maps/SkyPillar_Outside/scripts.pory"
	return
# 37 "data/maps/SkyPillar_Outside/scripts.pory"

# 38 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_OnFrame: @ 82392FA
# 39 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, SkyPillar_Outside_EventScript_WallaceScene
# 40 "data/maps/SkyPillar_Outside/scripts.pory"
	.2byte 0
# 41 "data/maps/SkyPillar_Outside/scripts.pory"

# 42 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_EventScript_WallaceScene:: @ 8239304
# 43 "data/maps/SkyPillar_Outside/scripts.pory"
	lockall
# 44 "data/maps/SkyPillar_Outside/scripts.pory"
	applymovement LOCALID_WALLACE, SkyPillar_Outside_Movement_WallaceApproachPlayer
# 45 "data/maps/SkyPillar_Outside/scripts.pory"
	waitmovement 0
# 46 "data/maps/SkyPillar_Outside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 47 "data/maps/SkyPillar_Outside/scripts.pory"
	waitmovement 0
# 48 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_OpenedDoorToSkyPillar, MSGBOX_DEFAULT
# 49 "data/maps/SkyPillar_Outside/scripts.pory"
	closemessage
# 50 "data/maps/SkyPillar_Outside/scripts.pory"
	delay 30
# 51 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 52 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 53 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 54 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 55 "data/maps/SkyPillar_Outside/scripts.pory"
	special ShakeCamera
# 56 "data/maps/SkyPillar_Outside/scripts.pory"
	waitstate
# 57 "data/maps/SkyPillar_Outside/scripts.pory"
	delay 40
# 58 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_EarthquakeNotMomentToWaste, MSGBOX_DEFAULT
# 59 "data/maps/SkyPillar_Outside/scripts.pory"
	closemessage
# 60 "data/maps/SkyPillar_Outside/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SkyPillar_Outside_Movement_PlayerClimbSkyPillar
# 61 "data/maps/SkyPillar_Outside/scripts.pory"
	applymovement LOCALID_WALLACE, SkyPillar_Outside_Movement_WallaceClimbSkyPillar
# 62 "data/maps/SkyPillar_Outside/scripts.pory"
	waitmovement 0
# 63 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 64 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_0x8005, 3   @ horizontal pan
# 65 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_0x8006, 20  @ num shakes
# 66 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_0x8007, 5   @ shake delay
# 67 "data/maps/SkyPillar_Outside/scripts.pory"
	special ShakeCamera
# 68 "data/maps/SkyPillar_Outside/scripts.pory"
	waitstate
# 69 "data/maps/SkyPillar_Outside/scripts.pory"
	delay 20
# 70 "data/maps/SkyPillar_Outside/scripts.pory"
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestLeft
# 71 "data/maps/SkyPillar_Outside/scripts.pory"
	waitmovement 0
# 72 "data/maps/SkyPillar_Outside/scripts.pory"
	delay 10
# 73 "data/maps/SkyPillar_Outside/scripts.pory"
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestRight
# 74 "data/maps/SkyPillar_Outside/scripts.pory"
	waitmovement 0
# 75 "data/maps/SkyPillar_Outside/scripts.pory"
	delay 20
# 76 "data/maps/SkyPillar_Outside/scripts.pory"
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFastestDown
# 77 "data/maps/SkyPillar_Outside/scripts.pory"
	waitmovement 0
# 78 "data/maps/SkyPillar_Outside/scripts.pory"
	delay 30
# 79 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_SituationGettingWorse, MSGBOX_DEFAULT
# 80 "data/maps/SkyPillar_Outside/scripts.pory"
	closemessage
# 81 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_SYS_WEATHER_CTRL
# 82 "data/maps/SkyPillar_Outside/scripts.pory"
	setweather WEATHER_ABNORMAL
# 83 "data/maps/SkyPillar_Outside/scripts.pory"
	doweather
# 84 "data/maps/SkyPillar_Outside/scripts.pory"
	special WaitWeather
# 85 "data/maps/SkyPillar_Outside/scripts.pory"
	waitstate
# 86 "data/maps/SkyPillar_Outside/scripts.pory"
	delay 30
# 87 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_GotToGoBackForSootopolis, MSGBOX_DEFAULT
# 88 "data/maps/SkyPillar_Outside/scripts.pory"
	closemessage
# 89 "data/maps/SkyPillar_Outside/scripts.pory"
	playse SE_EXIT
# 90 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 91 "data/maps/SkyPillar_Outside/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 92 "data/maps/SkyPillar_Outside/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 4
# 93 "data/maps/SkyPillar_Outside/scripts.pory"
	removeobject LOCALID_WALLACE
# 94 "data/maps/SkyPillar_Outside/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
# 95 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 96 "data/maps/SkyPillar_Outside/scripts.pory"
	releaseall
# 97 "data/maps/SkyPillar_Outside/scripts.pory"
	end
# 98 "data/maps/SkyPillar_Outside/scripts.pory"

# 99 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_Movement_WallaceApproachPlayer: @ 82393D3
# 100 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_down
# 101 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_down
# 102 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_down
# 103 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_down
# 104 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_down
# 105 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_down
# 106 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_down
# 107 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_right
# 108 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_right
# 109 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_right
# 110 "data/maps/SkyPillar_Outside/scripts.pory"
	step_end
# 111 "data/maps/SkyPillar_Outside/scripts.pory"

# 112 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_Movement_WallaceClimbSkyPillar: @ 82393DE
# 113 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_left
# 114 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_left
# 115 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_left
# 116 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 117 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 118 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 119 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 120 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_right
# 121 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 122 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 123 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 124 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 125 "data/maps/SkyPillar_Outside/scripts.pory"
	step_end
# 126 "data/maps/SkyPillar_Outside/scripts.pory"

# 127 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_Movement_PlayerClimbSkyPillar: @ 82393EB
# 128 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_left
# 129 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_left
# 130 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_left
# 131 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_left
# 132 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 133 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 134 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 135 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 136 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_right
# 137 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 138 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 139 "data/maps/SkyPillar_Outside/scripts.pory"
	walk_up
# 140 "data/maps/SkyPillar_Outside/scripts.pory"
	step_end
# 141 "data/maps/SkyPillar_Outside/scripts.pory"

# 142 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_EventScript_Wallace:: @ 82393F8
# 143 "data/maps/SkyPillar_Outside/scripts.pory"
	end
# 144 "data/maps/SkyPillar_Outside/scripts.pory"

# 145 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_EventScript_ClosedDoor:: @ 82393F9
# 146 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_DoorIsClosed, MSGBOX_SIGN
# 147 "data/maps/SkyPillar_Outside/scripts.pory"
	end
# 148 "data/maps/SkyPillar_Outside/scripts.pory"

# 149 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_Text_DoorIsClosed: @ 8239402
# 150 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "The door is closed.$"
# 151 "data/maps/SkyPillar_Outside/scripts.pory"

# 152 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_Text_OpenedDoorToSkyPillar: @ 8239416
# 153 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Wallace: Oh, my, I'm terribly sorry!\p"
# 154 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "In my haste, I didn't notice that\n"
# 155 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "I'd left you behind!\p"
# 156 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "I've opened the locked door of\n"
# 157 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "the Sky Pillar.\p"
# 158 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "{PLAYER}{KUN}, let's be on our way!$"
# 159 "data/maps/SkyPillar_Outside/scripts.pory"

# 160 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_Text_EarthquakeNotMomentToWaste: @ 82394BC
# 161 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Wallace: It's an earthquake!\p"
# 162 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "There's not a moment to waste!\n"
# 163 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "We've got to hurry!$"
# 164 "data/maps/SkyPillar_Outside/scripts.pory"

# 165 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_Text_SituationGettingWorse: @ 823950C
# 166 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Wallace: Hmm…\n"
# 167 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "The situation is getting worse…$"
# 168 "data/maps/SkyPillar_Outside/scripts.pory"

# 169 "data/maps/SkyPillar_Outside/scripts.pory"
SkyPillar_Outside_Text_GotToGoBackForSootopolis: @ 823953A
# 170 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Wallace: This isn't good…\p"
# 171 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "The weather distortion is spreading\n"
# 172 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "even here…\p"
# 173 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "{PLAYER}{KUN}.\p"
# 174 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Rayquaza should be farther up\n"
# 175 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "from here.\p"
# 176 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "I'm worried about Sootopolis.\n"
# 177 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "I've got to go back.\p"
# 178 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Everything is in your hands now.\n"
# 179 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Don't fail us!$"

SkyPillar_Outside_Text_Gauntlet::
# 183 "data/maps/SkyPillar_Outside/scripts.pory"
	lock
# 184 "data/maps/SkyPillar_Outside/scripts.pory"
	faceplayer
# 185 "data/maps/SkyPillar_Outside/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SkyPillar_Outside_Text_Gauntlet_2
# 262 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_12, MSGBOX_NPC
SkyPillar_Outside_Text_Gauntlet_1:
# 264 "data/maps/SkyPillar_Outside/scripts.pory"
	release
	end

SkyPillar_Outside_Text_Gauntlet_2:
# 187 "data/maps/SkyPillar_Outside/scripts.pory"
	goto_if_unset FLAG_OBTAINED_DRAGONITENITE, SkyPillar_Outside_Text_Gauntlet_5
# 258 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_11, MSGBOX_NPC
	goto SkyPillar_Outside_Text_Gauntlet_1

SkyPillar_Outside_Text_Gauntlet_5:
# 188 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_0, MSGBOX_YESNO
# 189 "data/maps/SkyPillar_Outside/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SkyPillar_Outside_Text_Gauntlet_8
# 254 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_10, MSGBOX_NPC
	goto SkyPillar_Outside_Text_Gauntlet_1

SkyPillar_Outside_Text_Gauntlet_8:
# 190 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_1, MSGBOX_NPC
# 191 "data/maps/SkyPillar_Outside/scripts.pory"
	special HealPlayerParty
# 192 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_SYS_DISABLE_AUTOHEAL
# 194 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 196 "data/maps/SkyPillar_Outside/scripts.pory"
	setobjectxy LOCALID_GAUNTLET_TRAINER_1, 14, 17
# 198 "data/maps/SkyPillar_Outside/scripts.pory"
	clearflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_2
# 199 "data/maps/SkyPillar_Outside/scripts.pory"
	addobject LOCALID_GAUNTLET_TRAINER_2
# 200 "data/maps/SkyPillar_Outside/scripts.pory"
	setobjectxy LOCALID_GAUNTLET_TRAINER_2, 15, 17
# 202 "data/maps/SkyPillar_Outside/scripts.pory"
	clearflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_3
# 203 "data/maps/SkyPillar_Outside/scripts.pory"
	addobject LOCALID_GAUNTLET_TRAINER_3
# 204 "data/maps/SkyPillar_Outside/scripts.pory"
	setobjectxy LOCALID_GAUNTLET_TRAINER_3, 16, 17
# 205 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 208 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_2, MSGBOX_NPC
# 209 "data/maps/SkyPillar_Outside/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAGONITENITE_SAGE_2, SkyPillar_Outside_Text_Gauntlet_Text_3
# 212 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 214 "data/maps/SkyPillar_Outside/scripts.pory"
	setobjectxy LOCALID_GAUNTLET_TRAINER_2, 16, 17
# 215 "data/maps/SkyPillar_Outside/scripts.pory"
	setobjectxy LOCALID_GAUNTLET_TRAINER_3, 15, 17
# 216 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 219 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_4, MSGBOX_NPC
# 220 "data/maps/SkyPillar_Outside/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAGONITENITE_SAGE_3, SkyPillar_Outside_Text_Gauntlet_Text_5
# 223 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 224 "data/maps/SkyPillar_Outside/scripts.pory"
	setobjectxy LOCALID_GAUNTLET_TRAINER_1, 15, 17
# 226 "data/maps/SkyPillar_Outside/scripts.pory"
	setobjectxy LOCALID_GAUNTLET_TRAINER_3, 14, 17
# 227 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 230 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_6, MSGBOX_NPC
# 231 "data/maps/SkyPillar_Outside/scripts.pory"
	trainerbattle_no_intro TRAINER_DRAGONITENITE_SAGE_1, SkyPillar_Outside_Text_Gauntlet_Text_7
# 234 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_8, MSGBOX_NPC
# 235 "data/maps/SkyPillar_Outside/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 236 "data/maps/SkyPillar_Outside/scripts.pory"
	giveitem ITEM_DRAGONITENITE, 1
# 237 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_OBTAINED_DRAGONITENITE
# 238 "data/maps/SkyPillar_Outside/scripts.pory"
	clearflag FLAG_SYS_DISABLE_AUTOHEAL
# 239 "data/maps/SkyPillar_Outside/scripts.pory"
	waitfanfare
# 240 "data/maps/SkyPillar_Outside/scripts.pory"
	msgbox SkyPillar_Outside_Text_Gauntlet_Text_9, MSGBOX_NPC
# 241 "data/maps/SkyPillar_Outside/scripts.pory"
	waitmessage
# 244 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 245 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_1
# 246 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_2
# 247 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_3
# 248 "data/maps/SkyPillar_Outside/scripts.pory"
	removeobject LOCALID_GAUNTLET_TRAINER_1
# 249 "data/maps/SkyPillar_Outside/scripts.pory"
	removeobject LOCALID_GAUNTLET_TRAINER_2
# 250 "data/maps/SkyPillar_Outside/scripts.pory"
	removeobject LOCALID_GAUNTLET_TRAINER_3
# 251 "data/maps/SkyPillar_Outside/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto SkyPillar_Outside_Text_Gauntlet_1


SkyPillar_Outside_EventScript_HideGauntletTrainers::
# 269 "data/maps/SkyPillar_Outside/scripts.pory"
	goto_if_unset FLAG_OBTAINED_DRAGONITENITE, SkyPillar_Outside_EventScript_HideGauntletTrainers_2
SkyPillar_Outside_EventScript_HideGauntletTrainers_1:
	return

SkyPillar_Outside_EventScript_HideGauntletTrainers_2:
# 270 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_2
# 271 "data/maps/SkyPillar_Outside/scripts.pory"
	setflag FLAG_SKY_PILLAR_GAUNTLET_HIDE_TRAINER_3
	goto SkyPillar_Outside_EventScript_HideGauntletTrainers_1


SkyPillar_Outside_Text_Gauntlet_Text_0:
# 188 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Does thou seek might, young seeker?\n"
	.string "Display thine prowess unto us, and thee\l"
	.string "shall be endowed with strength\l"
	.string "unparalleled.$"

SkyPillar_Outside_Text_Gauntlet_Text_1:
# 190 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Overcome our united strength, and the\n"
	.string "ancient dragon's power shall awaken for\l"
	.string "you. Prove your worth and harness the\l"
	.string "legacy.$"

SkyPillar_Outside_Text_Gauntlet_Text_2:
# 208 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Thus, we commence.$"

SkyPillar_Outside_Text_Gauntlet_Text_3:
# 209 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Superb. Onward we shall proceed.$"

SkyPillar_Outside_Text_Gauntlet_Text_4:
# 219 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Exquisite! Now, contend with me and\n"
	.string "demonstrate your deserving spirit!$"

SkyPillar_Outside_Text_Gauntlet_Text_5:
# 220 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Thou art steadfast; luck grace thy\n"
	.string "final duel.$"

SkyPillar_Outside_Text_Gauntlet_Text_6:
# 230 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Thou standest before the eldest sage.\n"
	.string "Thy final trial commences now, seeker.\l"
	.string "Reveal thy true mettle!$"

SkyPillar_Outside_Text_Gauntlet_Text_7:
# 231 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Verily, thou hast demonstrated thy\n"
	.string "worth.$"

SkyPillar_Outside_Text_Gauntlet_Text_8:
# 234 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Receive this, and brandish the\n"
	.string "veritable power of Dragonite in its\l"
	.string "purest essence.$"

SkyPillar_Outside_Text_Gauntlet_Text_9:
# 240 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Fare thee well, noble seeker.$"

SkyPillar_Outside_Text_Gauntlet_Text_10:
# 254 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Regrettable. Return unto this place\n"
	.string "when thee art prepared to confront our\l"
	.string "triad.$"

SkyPillar_Outside_Text_Gauntlet_Text_11:
# 258 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "I have naught more to utter.$"

SkyPillar_Outside_Text_Gauntlet_Text_12:
# 262 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "Thy worth is not proven. Vanquish the\n"
	.string "Twins of Mossdeep, and then, seeker,\l"
	.string "return to this sacred place.$"
