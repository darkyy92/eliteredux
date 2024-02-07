# 1 "data/maps/Route128/scripts.pory"

# 2 "data/maps/Route128/scripts.pory"
.set LOCALID_STEVEN, 3
# 3 "data/maps/Route128/scripts.pory"
.set LOCALID_ARCHIE, 4
# 4 "data/maps/Route128/scripts.pory"
.set LOCALID_MAXIE, 5
# 5 "data/maps/Route128/scripts.pory"

# 6 "data/maps/Route128/scripts.pory"
Route128_MapScripts:: @ 81F6B38
# 7 "data/maps/Route128/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route128_OnTransition
# 8 "data/maps/Route128/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route128_OnFrame
# 9 "data/maps/Route128/scripts.pory"
	.byte 0
# 10 "data/maps/Route128/scripts.pory"

# 11 "data/maps/Route128/scripts.pory"
Route128_OnTransition: @ 81F6B43
# 12 "data/maps/Route128/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 13 "data/maps/Route128/scripts.pory"
	end
# 14 "data/maps/Route128/scripts.pory"

# 15 "data/maps/Route128/scripts.pory"
Route128_OnFrame: @ 81F6B4D
# 16 "data/maps/Route128/scripts.pory"
	map_script_2 VAR_ROUTE128_STATE, 1, Route128_EventScript_KyogreAwakenedScene
# 17 "data/maps/Route128/scripts.pory"
	.2byte 0
# 18 "data/maps/Route128/scripts.pory"

# 19 "data/maps/Route128/scripts.pory"
Route128_EventScript_KyogreAwakenedScene:: @ 81F6B57
# 20 "data/maps/Route128/scripts.pory"
	lockall
# 21 "data/maps/Route128/scripts.pory"
	delay 20
# 22 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieLookAround
# 23 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 24 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_ArchieWhatHappened, MSGBOX_DEFAULT
# 25 "data/maps/Route128/scripts.pory"
	closemessage
# 26 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieBackUp
# 27 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 28 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_ArchieIOnlyWanted, MSGBOX_DEFAULT
# 29 "data/maps/Route128/scripts.pory"
	closemessage
# 30 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieApproachArchie
# 31 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 32 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestUp
# 33 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 34 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_MaxieDoYouUnderstandNow, MSGBOX_DEFAULT
# 35 "data/maps/Route128/scripts.pory"
	closemessage
# 36 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieApproachPlayer
# 37 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 38 "data/maps/Route128/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 39 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 40 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_MaxieResposibilityFallsToArchieAndMe, MSGBOX_DEFAULT
# 41 "data/maps/Route128/scripts.pory"
	closemessage
# 42 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieRunLeft
# 43 "data/maps/Route128/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 44 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieWalkLeft
# 45 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 46 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_MaxieThisDefiesBelief, MSGBOX_DEFAULT
# 47 "data/maps/Route128/scripts.pory"
	closemessage
# 48 "data/maps/Route128/scripts.pory"
	delay 40
# 49 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_MAXIE, Route128_Movement_MaxieExit
# 50 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_ARCHIE, Route128_Movement_ArchieExit
# 51 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 52 "data/maps/Route128/scripts.pory"
	removeobject LOCALID_MAXIE
# 53 "data/maps/Route128/scripts.pory"
	removeobject LOCALID_ARCHIE
# 54 "data/maps/Route128/scripts.pory"
	delay 100
# 55 "data/maps/Route128/scripts.pory"
	setfieldeffectargument 0, 1
# 56 "data/maps/Route128/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 57 "data/maps/Route128/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 58 "data/maps/Route128/scripts.pory"
	addobject LOCALID_STEVEN
# 59 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_STEVEN, Route128_Movement_StevenApproachPlayer
# 60 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 61 "data/maps/Route128/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 62 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 63 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_StevenWhatIsHappening, MSGBOX_DEFAULT
# 64 "data/maps/Route128/scripts.pory"
	closemessage
# 65 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_STEVEN, Route128_Movement_StevenWalkUp
# 66 "data/maps/Route128/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 67 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 68 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_StevenWholeWorldWillDrown, MSGBOX_DEFAULT
# 69 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
# 70 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 71 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_StevenImGoingToSootopolis, MSGBOX_DEFAULT
# 72 "data/maps/Route128/scripts.pory"
	closemessage
# 73 "data/maps/Route128/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFastestDown
# 74 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 75 "data/maps/Route128/scripts.pory"
	delay 50
# 76 "data/maps/Route128/scripts.pory"
	setfieldeffectargument 0, 1
# 77 "data/maps/Route128/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 78 "data/maps/Route128/scripts.pory"
	delay 15
# 79 "data/maps/Route128/scripts.pory"
	removeobject LOCALID_STEVEN
# 80 "data/maps/Route128/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 81 "data/maps/Route128/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 82 "data/maps/Route128/scripts.pory"
	setvar VAR_ROUTE128_STATE, 2
# 83 "data/maps/Route128/scripts.pory"
	releaseall
# 84 "data/maps/Route128/scripts.pory"
	end
# 85 "data/maps/Route128/scripts.pory"

# 86 "data/maps/Route128/scripts.pory"
Route128_Movement_Unused1: @ 81F6C76
# 87 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 88 "data/maps/Route128/scripts.pory"
	step_end
# 89 "data/maps/Route128/scripts.pory"

# 90 "data/maps/Route128/scripts.pory"
Route128_Movement_Unused2: @ 81F6C78
# 91 "data/maps/Route128/scripts.pory"
	walk_left
# 92 "data/maps/Route128/scripts.pory"
	walk_left
# 93 "data/maps/Route128/scripts.pory"
	walk_left
# 94 "data/maps/Route128/scripts.pory"
	walk_left
# 95 "data/maps/Route128/scripts.pory"
	walk_left
# 96 "data/maps/Route128/scripts.pory"
	walk_left
# 97 "data/maps/Route128/scripts.pory"
	walk_up
# 98 "data/maps/Route128/scripts.pory"
	walk_up
# 99 "data/maps/Route128/scripts.pory"
	walk_up
# 100 "data/maps/Route128/scripts.pory"
	walk_up
# 101 "data/maps/Route128/scripts.pory"
	walk_up
# 102 "data/maps/Route128/scripts.pory"
	walk_up
# 103 "data/maps/Route128/scripts.pory"
	step_end
# 104 "data/maps/Route128/scripts.pory"

# 105 "data/maps/Route128/scripts.pory"
Route128_Movement_StevenWalkUp: @ 81F6C85
# 106 "data/maps/Route128/scripts.pory"
	walk_up
# 107 "data/maps/Route128/scripts.pory"
	step_end
# 108 "data/maps/Route128/scripts.pory"

# 109 "data/maps/Route128/scripts.pory"
Route128_Movement_StevenApproachPlayer: @ 81F6C87
# 110 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 111 "data/maps/Route128/scripts.pory"
	step_end
# 112 "data/maps/Route128/scripts.pory"

# 113 "data/maps/Route128/scripts.pory"
Route128_Movement_ArchieLookAround: @ 81F6C89
# 114 "data/maps/Route128/scripts.pory"
	walk_fast_down
# 115 "data/maps/Route128/scripts.pory"
	walk_in_place_fastest_left
# 116 "data/maps/Route128/scripts.pory"
	delay_16
# 117 "data/maps/Route128/scripts.pory"
	walk_in_place_fastest_right
# 118 "data/maps/Route128/scripts.pory"
	delay_16
# 119 "data/maps/Route128/scripts.pory"
	delay_16
# 120 "data/maps/Route128/scripts.pory"
	walk_in_place_fastest_down
# 121 "data/maps/Route128/scripts.pory"
	step_end
# 122 "data/maps/Route128/scripts.pory"

# 123 "data/maps/Route128/scripts.pory"
Route128_Movement_ArchieBackUp: @ 81F6C91
# 124 "data/maps/Route128/scripts.pory"
	lock_facing_direction
# 125 "data/maps/Route128/scripts.pory"
	walk_slow_up
# 126 "data/maps/Route128/scripts.pory"
	delay_16
# 127 "data/maps/Route128/scripts.pory"
	unlock_facing_direction
# 128 "data/maps/Route128/scripts.pory"
	step_end
# 129 "data/maps/Route128/scripts.pory"

# 130 "data/maps/Route128/scripts.pory"
Route128_Movement_ArchieRunLeft: @ 81F6C96
# 131 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 132 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 133 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 134 "data/maps/Route128/scripts.pory"
	walk_in_place_fastest_right
# 135 "data/maps/Route128/scripts.pory"
	step_end
# 136 "data/maps/Route128/scripts.pory"

# 137 "data/maps/Route128/scripts.pory"
Route128_Movement_ArchieExit: @ 81F6C9B
# 138 "data/maps/Route128/scripts.pory"
	delay_16
# 139 "data/maps/Route128/scripts.pory"
	delay_16
# 140 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 141 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 143 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 144 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 145 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 146 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 147 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 148 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 149 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 150 "data/maps/Route128/scripts.pory"
	step_end
# 151 "data/maps/Route128/scripts.pory"

# 152 "data/maps/Route128/scripts.pory"
Route128_Movement_MaxieWalkLeft: @ 81F6CA8
# 153 "data/maps/Route128/scripts.pory"
	walk_left
# 154 "data/maps/Route128/scripts.pory"
	walk_left
# 155 "data/maps/Route128/scripts.pory"
	delay_8
# 156 "data/maps/Route128/scripts.pory"
	delay_4
# 157 "data/maps/Route128/scripts.pory"
	step_end
# 158 "data/maps/Route128/scripts.pory"

# 159 "data/maps/Route128/scripts.pory"
Route128_Movement_MaxieApproachArchie: @ 81F6CAD
# 160 "data/maps/Route128/scripts.pory"
	walk_left
# 161 "data/maps/Route128/scripts.pory"
	walk_in_place_fastest_down
# 162 "data/maps/Route128/scripts.pory"
	step_end
# 163 "data/maps/Route128/scripts.pory"

# 164 "data/maps/Route128/scripts.pory"
Route128_Movement_MaxieExit: @ 81F6CB0
# 165 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 166 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 167 "data/maps/Route128/scripts.pory"
	walk_fast_left
# 168 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 169 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 170 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 171 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 172 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 173 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 174 "data/maps/Route128/scripts.pory"
	walk_fast_up
# 175 "data/maps/Route128/scripts.pory"
	step_end
# 176 "data/maps/Route128/scripts.pory"

# 177 "data/maps/Route128/scripts.pory"
Route128_Movement_MaxieApproachPlayer: @ 81F6CBB
# 178 "data/maps/Route128/scripts.pory"
	walk_right
# 179 "data/maps/Route128/scripts.pory"
	walk_in_place_fastest_down
# 180 "data/maps/Route128/scripts.pory"
	step_end
# 181 "data/maps/Route128/scripts.pory"

# 182 "data/maps/Route128/scripts.pory"
Route128_EventScript_Isaiah:: @ 81F6CBE
# 183 "data/maps/Route128/scripts.pory"
	trainerbattle_single TRAINER_ISAIAH_1, Route128_Text_IsaiahIntro, Route128_Text_IsaiahDefeat, Route128_EventScript_RegisterIsaiah
# 184 "data/maps/Route128/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 185 "data/maps/Route128/scripts.pory"
	compare VAR_RESULT, TRUE
# 186 "data/maps/Route128/scripts.pory"
	goto_if_eq Route128_EventScript_RematchIsaiah
# 187 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_IsaiahPostBattle, MSGBOX_DEFAULT
# 188 "data/maps/Route128/scripts.pory"
	release
# 189 "data/maps/Route128/scripts.pory"
	end
# 190 "data/maps/Route128/scripts.pory"

# 191 "data/maps/Route128/scripts.pory"
Route128_EventScript_RegisterIsaiah:: @ 81F6CEA
# 192 "data/maps/Route128/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 193 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 194 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_IsaiahRegister, MSGBOX_DEFAULT
# 195 "data/maps/Route128/scripts.pory"
	register_matchcall TRAINER_ISAIAH_1
# 196 "data/maps/Route128/scripts.pory"
	release
# 197 "data/maps/Route128/scripts.pory"
	end
# 198 "data/maps/Route128/scripts.pory"

# 199 "data/maps/Route128/scripts.pory"
Route128_EventScript_RematchIsaiah:: @ 81F6D09
# 200 "data/maps/Route128/scripts.pory"
	trainerbattle_rematch TRAINER_ISAIAH_1, Route128_Text_IsaiahRematchIntro, Route128_Text_IsaiahRematchDefeat
# 201 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_IsaiahPostRematch, MSGBOX_AUTOCLOSE
# 202 "data/maps/Route128/scripts.pory"
	end
# 203 "data/maps/Route128/scripts.pory"

# 204 "data/maps/Route128/scripts.pory"
Route128_EventScript_Katelyn:: @ 81F6D20
# 205 "data/maps/Route128/scripts.pory"
	trainerbattle_single TRAINER_KATELYN_1, Route128_Text_KatelynIntro, Route128_Text_KatelynDefeat, Route128_EventScript_RegisterKatelyn
# 206 "data/maps/Route128/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 207 "data/maps/Route128/scripts.pory"
	compare VAR_RESULT, TRUE
# 208 "data/maps/Route128/scripts.pory"
	goto_if_eq Route128_EventScript_RematchKatelyn
# 209 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_KatelynPostBattle, MSGBOX_DEFAULT
# 210 "data/maps/Route128/scripts.pory"
	release
# 211 "data/maps/Route128/scripts.pory"
	end
# 212 "data/maps/Route128/scripts.pory"

# 213 "data/maps/Route128/scripts.pory"
Route128_EventScript_RegisterKatelyn:: @ 81F6D4C
# 214 "data/maps/Route128/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 215 "data/maps/Route128/scripts.pory"
	waitmovement 0
# 216 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_KatelynRegister, MSGBOX_DEFAULT
# 217 "data/maps/Route128/scripts.pory"
	register_matchcall TRAINER_KATELYN_1
# 218 "data/maps/Route128/scripts.pory"
	release
# 219 "data/maps/Route128/scripts.pory"
	end
# 220 "data/maps/Route128/scripts.pory"

# 221 "data/maps/Route128/scripts.pory"
Route128_EventScript_RematchKatelyn:: @ 81F6D6B
# 222 "data/maps/Route128/scripts.pory"
	trainerbattle_rematch TRAINER_KATELYN_1, Route128_Text_KatelynRematchIntro, Route128_Text_KatelynRematchDefeat
# 223 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_KatelynPostRematch, MSGBOX_AUTOCLOSE
# 224 "data/maps/Route128/scripts.pory"
	end
# 225 "data/maps/Route128/scripts.pory"

# 226 "data/maps/Route128/scripts.pory"
Route128_EventScript_Alexa:: @ 81F6D82
# 227 "data/maps/Route128/scripts.pory"
	trainerbattle_single TRAINER_ALEXA, Route128_Text_AlexaIntro, Route128_Text_AlexaDefeat
# 228 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
# 229 "data/maps/Route128/scripts.pory"
	end
# 230 "data/maps/Route128/scripts.pory"

# 231 "data/maps/Route128/scripts.pory"
Route128_EventScript_Ruben:: @ 81F6D99
# 232 "data/maps/Route128/scripts.pory"
	trainerbattle_single TRAINER_RUBEN, Route128_Text_RubenIntro, Route128_Text_RubenDefeat
# 233 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
# 234 "data/maps/Route128/scripts.pory"
	end
# 235 "data/maps/Route128/scripts.pory"

# 236 "data/maps/Route128/scripts.pory"
Route128_EventScript_Wayne:: @ 81F6DB0
# 237 "data/maps/Route128/scripts.pory"
	trainerbattle_single TRAINER_WAYNE, Route128_Text_WayneIntro, Route128_Text_WayneDefeat
# 238 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
# 239 "data/maps/Route128/scripts.pory"
	end
# 240 "data/maps/Route128/scripts.pory"

# 241 "data/maps/Route128/scripts.pory"
Route128_EventScript_Harrison:: @ 81F6DC7
# 242 "data/maps/Route128/scripts.pory"
	trainerbattle_single TRAINER_HARRISON, Route128_Text_HarrisonIntro, Route128_Text_HarrisonDefeat
# 243 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_HarrisonPostBattle, MSGBOX_AUTOCLOSE
# 244 "data/maps/Route128/scripts.pory"
	end
# 245 "data/maps/Route128/scripts.pory"

# 246 "data/maps/Route128/scripts.pory"
Route128_EventScript_Carlee:: @ 81F6DDE
# 247 "data/maps/Route128/scripts.pory"
	trainerbattle_single TRAINER_CARLEE, Route128_Text_CarleeIntro, Route128_Text_CarleeDefeat
# 248 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_CarleePostBattle, MSGBOX_AUTOCLOSE
# 249 "data/maps/Route128/scripts.pory"
	end
# 250 "data/maps/Route128/scripts.pory"

# 251 "data/maps/Route128/scripts.pory"
Route128_Text_ArchieWhatHappened: @ 81F6DF5
# 252 "data/maps/Route128/scripts.pory"
	.string "Archie: What happened…\n"
# 253 "data/maps/Route128/scripts.pory"
	.string "What is this wretched scene…\p"
# 254 "data/maps/Route128/scripts.pory"
	.string "Did I…make a horrible mistake?$"
# 255 "data/maps/Route128/scripts.pory"

# 256 "data/maps/Route128/scripts.pory"
Route128_Text_ArchieIOnlyWanted: @ 81F6E48
# 257 "data/maps/Route128/scripts.pory"
	.string "I…\n"
# 258 "data/maps/Route128/scripts.pory"
	.string "I only wanted…$"
# 259 "data/maps/Route128/scripts.pory"

# 260 "data/maps/Route128/scripts.pory"
Route128_Text_MaxieDoYouUnderstandNow: @ 81F6E5A
# 261 "data/maps/Route128/scripts.pory"
	.string "Maxie: Do you understand now,\n"
# 262 "data/maps/Route128/scripts.pory"
	.string "Archie?\p"
# 263 "data/maps/Route128/scripts.pory"
	.string "Do you finally see how disastrous\n"
# 264 "data/maps/Route128/scripts.pory"
	.string "your dream turned out to be?\p"
# 265 "data/maps/Route128/scripts.pory"
	.string "We have to hurry! We have to do\n"
# 266 "data/maps/Route128/scripts.pory"
	.string "something before the situation goes\l"
# 267 "data/maps/Route128/scripts.pory"
	.string "completely out of control!$"
# 268 "data/maps/Route128/scripts.pory"

# 269 "data/maps/Route128/scripts.pory"
Route128_Text_MaxieResposibilityFallsToArchieAndMe: @ 81F6F1E
# 270 "data/maps/Route128/scripts.pory"
	.string "Maxie: {PLAYER}, don't say anything.\p"
# 271 "data/maps/Route128/scripts.pory"
	.string "I know that I have no right to be\n"
# 272 "data/maps/Route128/scripts.pory"
	.string "critical of Archie…\p"
# 273 "data/maps/Route128/scripts.pory"
	.string "But the way things are now, I doubt\n"
# 274 "data/maps/Route128/scripts.pory"
	.string "that we humans will be capable of\l"
# 275 "data/maps/Route128/scripts.pory"
	.string "doing anything about it.\p"
# 276 "data/maps/Route128/scripts.pory"
	.string "But neither can we stand by and\n"
# 277 "data/maps/Route128/scripts.pory"
	.string "just watch helplessly.\p"
# 278 "data/maps/Route128/scripts.pory"
	.string "The responsibility for putting an end\n"
# 279 "data/maps/Route128/scripts.pory"
	.string "to this falls to Archie and I…$"
# 280 "data/maps/Route128/scripts.pory"

# 281 "data/maps/Route128/scripts.pory"
Route128_Text_MaxieThisDefiesBelief: @ 81F704F
# 282 "data/maps/Route128/scripts.pory"
	.string "Maxie: This defies belief…\p"
# 283 "data/maps/Route128/scripts.pory"
	.string "Those super-ancient Pokémon…\p"
# 284 "data/maps/Route128/scripts.pory"
	.string "Their power is unbelievable.\n"
# 285 "data/maps/Route128/scripts.pory"
	.string "They've upset the balance of nature…$"
# 286 "data/maps/Route128/scripts.pory"

# 287 "data/maps/Route128/scripts.pory"
Route128_Text_StevenWhatIsHappening: @ 81F70C9
# 288 "data/maps/Route128/scripts.pory"
	.string "Steven: {PLAYER}{KUN}!\n"
# 289 "data/maps/Route128/scripts.pory"
	.string "What is happening?$"
# 290 "data/maps/Route128/scripts.pory"

# 291 "data/maps/Route128/scripts.pory"
Route128_Text_StevenWholeWorldWillDrown: @ 81F70EA
# 292 "data/maps/Route128/scripts.pory"
	.string "This is terrible…\p"
# 293 "data/maps/Route128/scripts.pory"
	.string "After the scorching heat wave ended,\n"
# 294 "data/maps/Route128/scripts.pory"
	.string "this deluge began.\p"
# 295 "data/maps/Route128/scripts.pory"
	.string "If this doesn't stop, all of Hoenn…\n"
# 296 "data/maps/Route128/scripts.pory"
	.string "No, the whole world will drown.\p"
# 297 "data/maps/Route128/scripts.pory"
	.string "This huge rain cloud is spreading\n"
# 298 "data/maps/Route128/scripts.pory"
	.string "from above Sootopolis…\p"
# 299 "data/maps/Route128/scripts.pory"
	.string "What in the world is taking place there?\p"
# 300 "data/maps/Route128/scripts.pory"
	.string "There's no point arguing here…\n"
# 301 "data/maps/Route128/scripts.pory"
	.string "Sootopolis might provide answers…$"
# 302 "data/maps/Route128/scripts.pory"

# 303 "data/maps/Route128/scripts.pory"
Route128_Text_StevenImGoingToSootopolis: @ 81F721B
# 304 "data/maps/Route128/scripts.pory"
	.string "{PLAYER}{KUN}…\n"
# 305 "data/maps/Route128/scripts.pory"
	.string "I don't know what you intend to do,\l"
# 306 "data/maps/Route128/scripts.pory"
	.string "but don't do anything reckless.\p"
# 307 "data/maps/Route128/scripts.pory"
	.string "Okay.\n"
# 308 "data/maps/Route128/scripts.pory"
	.string "I'm going to Sootopolis.$"

Route128_EventScript_LegendaryNPC::
# 312 "data/maps/Route128/scripts.pory"
	lock
# 313 "data/maps/Route128/scripts.pory"
	faceplayer
# 314 "data/maps/Route128/scripts.pory"
	msgbox Route128_EventScript_LegendaryNPC_Text_0, MSGBOX_YESNO
# 315 "data/maps/Route128/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Route128_EventScript_LegendaryNPC_2
# 342 "data/maps/Route128/scripts.pory"
	msgbox Route128_EventScript_LegendaryNPC_Text_4
Route128_EventScript_LegendaryNPC_1:
# 344 "data/maps/Route128/scripts.pory"
	release
	end

Route128_EventScript_LegendaryNPC_2:
# 316 "data/maps/Route128/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route128_EventScript_LegendaryNPC_5
# 327 "data/maps/Route128/scripts.pory"
	checktrainerflag TRAINER_CARLEE
	goto_if 1, Route128_EventScript_LegendaryNPC_11
Route128_EventScript_LegendaryNPC_9:
# 337 "data/maps/Route128/scripts.pory"
	msgbox Route128_EventScript_LegendaryNPC_Text_3
	goto Route128_EventScript_LegendaryNPC_1

Route128_EventScript_LegendaryNPC_5:
# 317 "data/maps/Route128/scripts.pory"
	msgbox Route128_EventScript_LegendaryNPC_Text_1
	goto Route128_EventScript_LegendaryNPC_1

Route128_EventScript_LegendaryNPC_8:
# 334 "data/maps/Route128/scripts.pory"
	msgbox Route128_EventScript_LegendaryNPC_Text_2
	goto Route128_EventScript_LegendaryNPC_1

Route128_EventScript_LegendaryNPC_10:
# 329 "data/maps/Route128/scripts.pory"
	checktrainerflag TRAINER_WAYNE
	goto_if 1, Route128_EventScript_LegendaryNPC_15
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_11:
# 328 "data/maps/Route128/scripts.pory"
	checktrainerflag TRAINER_HARRISON
	goto_if 1, Route128_EventScript_LegendaryNPC_10
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_14:
# 331 "data/maps/Route128/scripts.pory"
	checktrainerflag TRAINER_ALEXA
	goto_if 1, Route128_EventScript_LegendaryNPC_19
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_15:
# 330 "data/maps/Route128/scripts.pory"
	checktrainerflag TRAINER_RUBEN
	goto_if 1, Route128_EventScript_LegendaryNPC_14
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_18:
# 333 "data/maps/Route128/scripts.pory"
	checktrainerflag TRAINER_ISAIAH_1
	goto_if 1, Route128_EventScript_LegendaryNPC_8
	goto Route128_EventScript_LegendaryNPC_9

Route128_EventScript_LegendaryNPC_19:
# 332 "data/maps/Route128/scripts.pory"
	checktrainerflag TRAINER_KATELYN_1
	goto_if 1, Route128_EventScript_LegendaryNPC_18
	goto Route128_EventScript_LegendaryNPC_9


Route128_EventScript_LegendaryNPC_Text_0:
# 314 "data/maps/Route128/scripts.pory"
	.string "Sage: Not only am I a sage, but once\n"
	.string "upon a time I was a bard, too. A good one\l"
	.string "at that... but a long time has passed. I\l"
	.string "used to sing the legend of King Calyrex,\l"
	.string "the righteous king turned mad by power.\l"
	.string "Do you want to hear me sing one last\l"
	.string "time?$"

Route128_EventScript_LegendaryNPC_Text_1:
# 317 "data/maps/Route128/scripts.pory"
	.string "Once upon a time, in the frozen lands of\n"
	.string "Galar, lived a benevolent king named\l"
	.string "Calyrex\p"
	.string "Calyrex was beloved by the people and\n"
	.string "feared by his enemies: every day he\l"
	.string "would ride his magnificent steed,\l"
	.string "Glastrier, across the realm,\p"
	.string "helping those in need, lifting\n"
	.string "everyone's spirits and being there when\l"
	.string "his presence was needed the most.\p"
	.string "One day, two messengers from Alola came\n"
	.string "to Calyrex's castle: they were the\l"
	.string "island guardians Tapu Koko and Tapu\l"
	.string "Bulu.\p"
	.string "They told Calyrex that Alola was under\n"
	.string "attack from outer space: Necrozma, the\l"
	.string "cosmic devourer, had finally reached\l"
	.string "the region,\p"
	.string "and was about to wreck havoc alongside\n"
	.string "his army of Ultra Beasts. The king,\l"
	.string "fearing for his people, rushed\l"
	.string "immediately to Alola to aid in the fight.\p"
	.string "The battle was long and bloody.\n"
	.string "Miracolously, they managed to push\l"
	.string "back Necrozma, but it was already too\l"
	.string "late: the Ultra Beasts had reached the\l"
	.string "surface, and it seemed like nothing\l"
	.string "could stop them...\p"
	.string "This is the part of the legend that was\n"
	.string "taught to me, I'm sure someone knows\l"
	.string "the rest. If you wanna catch this\l"
	.string "battling trio, come back once you\l"
	.string "become champion!$"

Route128_EventScript_LegendaryNPC_Text_2:
# 334 "data/maps/Route128/scripts.pory"
	.string "Tapu Koko, Tapu Bulu and Glastrier have\n"
	.string "deemed you worthy of meeting them. I\l"
	.string "marked their location on your DexNav:\l"
	.string "use it on this route to meet them!$"

Route128_EventScript_LegendaryNPC_Text_3:
# 337 "data/maps/Route128/scripts.pory"
	.string "The Tapus and the King's steed admire\n"
	.string "your dedication to becoming champion,\l"
	.string "but would like to see some more action\l"
	.string "from you! Defeat every trainer in this\l"
	.string "route and come back to me!$"

Route128_EventScript_LegendaryNPC_Text_4:
# 342 "data/maps/Route128/scripts.pory"
	.string "You know there's nothing left of me...\n"
	.string "Let me sing... please...$"
