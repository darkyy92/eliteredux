# 1 "data/maps/Route110/scripts.pory"

# 2 "data/maps/Route110/scripts.pory"
.set LOCALID_CHALLENGE_BIKER, 19
# 3 "data/maps/Route110/scripts.pory"
.set LOCALID_RIVAL, 26
# 4 "data/maps/Route110/scripts.pory"
.set LOCALID_RIVAL_ON_BIKE, 27
# 5 "data/maps/Route110/scripts.pory"
.set LOCALID_BIRCH, 33
# 6 "data/maps/Route110/scripts.pory"

# 7 "data/maps/Route110/scripts.pory"
Route110_MapScripts:: @ 81EF269
# 8 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
# 9 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
# 10 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
# 11 "data/maps/Route110/scripts.pory"
	.byte 0
# 12 "data/maps/Route110/scripts.pory"

# 13 "data/maps/Route110/scripts.pory"
Route110_OnResume: @ 81EF279
# 14 "data/maps/Route110/scripts.pory"
	special UpdateCyclingRoadState
# 15 "data/maps/Route110/scripts.pory"
	end
# 16 "data/maps/Route110/scripts.pory"

# 17 "data/maps/Route110/scripts.pory"
Route110_OnTransition: @ 81EF27D
# 18 "data/maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 19 "data/maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 20 "data/maps/Route110/scripts.pory"
	compare VAR_CYCLING_CHALLENGE_STATE, 1
# 21 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_SaveCyclingMusic
# 22 "data/maps/Route110/scripts.pory"
	end
# 23 "data/maps/Route110/scripts.pory"

# 24 "data/maps/Route110/scripts.pory"
Route110_EventScript_SaveCyclingMusic:: @ 81EF293
# 25 "data/maps/Route110/scripts.pory"
	savebgm MUS_CYCLING
# 26 "data/maps/Route110/scripts.pory"
	return
# 27 "data/maps/Route110/scripts.pory"

# 28 "data/maps/Route110/scripts.pory"
Route110_OnFrame: @ 81EF297
# 29 "data/maps/Route110/scripts.pory"
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
# 30 "data/maps/Route110/scripts.pory"
	.2byte 0
# 31 "data/maps/Route110/scripts.pory"

# 32 "data/maps/Route110/scripts.pory"
Route110_EventScript_BeginCylcingRoadChallenge:: @ 81EF2A1
# 33 "data/maps/Route110/scripts.pory"
	special Special_BeginCyclingRoadChallenge
# 34 "data/maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
# 35 "data/maps/Route110/scripts.pory"
	return
# 36 "data/maps/Route110/scripts.pory"

# 37 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt1:: @ 81EF2AA
# 38 "data/maps/Route110/scripts.pory"
	lock
# 39 "data/maps/Route110/scripts.pory"
	faceplayer
# 40 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
# 41 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 42 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 43 "data/maps/Route110/scripts.pory"
	release
# 44 "data/maps/Route110/scripts.pory"
	end
# 45 "data/maps/Route110/scripts.pory"

# 46 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt2:: @ 81EF2C0
# 47 "data/maps/Route110/scripts.pory"
	lock
# 48 "data/maps/Route110/scripts.pory"
	faceplayer
# 49 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
# 50 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 51 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 52 "data/maps/Route110/scripts.pory"
	release
# 53 "data/maps/Route110/scripts.pory"
	end
# 54 "data/maps/Route110/scripts.pory"

# 55 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt3:: @ 81EF2D6
# 56 "data/maps/Route110/scripts.pory"
	lock
# 57 "data/maps/Route110/scripts.pory"
	faceplayer
# 58 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
# 59 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 60 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 61 "data/maps/Route110/scripts.pory"
	release
# 62 "data/maps/Route110/scripts.pory"
	end
# 63 "data/maps/Route110/scripts.pory"

# 64 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt4:: @ 81EF2EC
# 65 "data/maps/Route110/scripts.pory"
	lock
# 66 "data/maps/Route110/scripts.pory"
	faceplayer
# 67 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
# 68 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 69 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 70 "data/maps/Route110/scripts.pory"
	release
# 71 "data/maps/Route110/scripts.pory"
	end
# 72 "data/maps/Route110/scripts.pory"

# 73 "data/maps/Route110/scripts.pory"
Route110_EventScript_Boy1:: @ 81EF302
# 74 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
# 75 "data/maps/Route110/scripts.pory"
	end
# 76 "data/maps/Route110/scripts.pory"

# 77 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGirl1:: @ 81EF30B
# 78 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
# 79 "data/maps/Route110/scripts.pory"
	end
# 80 "data/maps/Route110/scripts.pory"

# 81 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy1:: @ 81EF314
# 82 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
# 83 "data/maps/Route110/scripts.pory"
	end
# 84 "data/maps/Route110/scripts.pory"

# 85 "data/maps/Route110/scripts.pory"
Route110_EventScript_OldMan:: @ 81EF31D
# 86 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
# 87 "data/maps/Route110/scripts.pory"
	end
# 88 "data/maps/Route110/scripts.pory"

# 89 "data/maps/Route110/scripts.pory"
Route110_EventScript_OldWoman:: @ 81EF326
# 90 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
# 91 "data/maps/Route110/scripts.pory"
	end
# 92 "data/maps/Route110/scripts.pory"

# 93 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy2:: @ 81EF32F
# 94 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
# 95 "data/maps/Route110/scripts.pory"
	end
# 96 "data/maps/Route110/scripts.pory"

# 97 "data/maps/Route110/scripts.pory"
Route110_EventScript_Boy2:: @ 81EF338
# 98 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
# 99 "data/maps/Route110/scripts.pory"
	end
# 100 "data/maps/Route110/scripts.pory"

# 101 "data/maps/Route110/scripts.pory"
Route110_EventScript_SlateportCitySign:: @ 81EF341
# 102 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
# 103 "data/maps/Route110/scripts.pory"
	end
# 104 "data/maps/Route110/scripts.pory"

# 105 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadSign:: @ 81EF34A
# 106 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
# 107 "data/maps/Route110/scripts.pory"
	end
# 108 "data/maps/Route110/scripts.pory"

# 109 "data/maps/Route110/scripts.pory"
Route110_EventScript_VandalizedSign:: @ 81EF353
# 110 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
# 111 "data/maps/Route110/scripts.pory"
	end
# 112 "data/maps/Route110/scripts.pory"

# 113 "data/maps/Route110/scripts.pory"
Route110_EventScript_Route103Sign:: @ 81EF35C
# 114 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
# 115 "data/maps/Route110/scripts.pory"
	end
# 116 "data/maps/Route110/scripts.pory"

# 117 "data/maps/Route110/scripts.pory"
Route110_EventScript_SeasideParkingSign:: @ 81EF365
# 118 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
# 119 "data/maps/Route110/scripts.pory"
	end
# 120 "data/maps/Route110/scripts.pory"

# 121 "data/maps/Route110/scripts.pory"
Route110_EventScript_MauvilleCitySign:: @ 81EF36E
# 122 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
# 123 "data/maps/Route110/scripts.pory"
	end
# 124 "data/maps/Route110/scripts.pory"

# 125 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsPrlzSleep:: @ 81EF377
# 126 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
# 127 "data/maps/Route110/scripts.pory"
	end
# 128 "data/maps/Route110/scripts.pory"

# 129 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsRegisterItems:: @ 81EF380
# 130 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
# 131 "data/maps/Route110/scripts.pory"
	end
# 132 "data/maps/Route110/scripts.pory"

# 133 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrickHouseSign:: @ 81EF389
# 134 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
# 135 "data/maps/Route110/scripts.pory"
	end
# 136 "data/maps/Route110/scripts.pory"

# 137 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadResultsSign:: @ 81EF392
# 138 "data/maps/Route110/scripts.pory"
	lockall
# 139 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
# 140 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, FALSE
# 141 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_NoRecordSet
# 142 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
# 143 "data/maps/Route110/scripts.pory"
	releaseall
# 144 "data/maps/Route110/scripts.pory"
	end
# 145 "data/maps/Route110/scripts.pory"

# 146 "data/maps/Route110/scripts.pory"
Route110_EventScript_NoRecordSet:: @ 81EF3AD
# 147 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
# 148 "data/maps/Route110/scripts.pory"
	releaseall
# 149 "data/maps/Route110/scripts.pory"
	end
# 150 "data/maps/Route110/scripts.pory"

# 151 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeGuy:: @ 81EF3B7
# 152 "data/maps/Route110/scripts.pory"
	lock
# 153 "data/maps/Route110/scripts.pory"
	faceplayer
# 154 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetPlayerAvatarBike
# 155 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, 1
# 156 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_PlayerRidingAcroBike
# 157 "data/maps/Route110/scripts.pory"
	compare VAR_CYCLING_CHALLENGE_STATE, 0
# 158 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_PlayerNotRidingBike
# 159 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
# 160 "data/maps/Route110/scripts.pory"
	release
# 161 "data/maps/Route110/scripts.pory"
	end
# 162 "data/maps/Route110/scripts.pory"

# 163 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayerNotRidingBike:: @ 81EF3DE
# 164 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
# 165 "data/maps/Route110/scripts.pory"
	release
# 166 "data/maps/Route110/scripts.pory"
	end
# 167 "data/maps/Route110/scripts.pory"

# 168 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayerRidingAcroBike:: @ 81EF3E8
# 169 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
# 170 "data/maps/Route110/scripts.pory"
	release
# 171 "data/maps/Route110/scripts.pory"
	end
# 172 "data/maps/Route110/scripts.pory"

# 173 "data/maps/Route110/scripts.pory"
Route110_EventScript_Edward:: @ 81EF3F2
# 174 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
# 175 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
# 176 "data/maps/Route110/scripts.pory"
	end
# 177 "data/maps/Route110/scripts.pory"

# 178 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jaclyn:: @ 81EF409
# 179 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
# 180 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
# 181 "data/maps/Route110/scripts.pory"
	end
# 182 "data/maps/Route110/scripts.pory"

# 183 "data/maps/Route110/scripts.pory"
Route110_EventScript_Edwin:: @ 81EF420
# 184 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
# 185 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 186 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, TRUE
# 187 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_EdwinRematch
# 188 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
# 189 "data/maps/Route110/scripts.pory"
	release
# 190 "data/maps/Route110/scripts.pory"
	end
# 191 "data/maps/Route110/scripts.pory"

# 192 "data/maps/Route110/scripts.pory"
Route110_EventScript_EdwinRegisterMatchCallAfterBattle:: @ 81EF44C
# 193 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 194 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 195 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
# 196 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_EDWIN_1
# 197 "data/maps/Route110/scripts.pory"
	release
# 198 "data/maps/Route110/scripts.pory"
	end
# 199 "data/maps/Route110/scripts.pory"

# 200 "data/maps/Route110/scripts.pory"
Route110_EventScript_EdwinRematch:: @ 81EF46B
# 201 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
# 202 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
# 203 "data/maps/Route110/scripts.pory"
	end
# 204 "data/maps/Route110/scripts.pory"

# 205 "data/maps/Route110/scripts.pory"
Route110_EventScript_Dale:: @ 81EF482
# 206 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
# 207 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
# 208 "data/maps/Route110/scripts.pory"
	end
# 209 "data/maps/Route110/scripts.pory"

# 210 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jacob:: @ 81EF499
# 211 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
# 212 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
# 213 "data/maps/Route110/scripts.pory"
	end
# 214 "data/maps/Route110/scripts.pory"

# 215 "data/maps/Route110/scripts.pory"
Route110_EventScript_Anthony:: @ 81EF4B0
# 216 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
# 217 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 218 "data/maps/Route110/scripts.pory"
	end
# 219 "data/maps/Route110/scripts.pory"

# 220 "data/maps/Route110/scripts.pory"
Route110_EventScript_Benjamin:: @ 81EF4C7
# 221 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
# 222 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 223 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, TRUE
# 224 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_BenjaminRematch
# 225 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
# 226 "data/maps/Route110/scripts.pory"
	release
# 227 "data/maps/Route110/scripts.pory"
	end
# 228 "data/maps/Route110/scripts.pory"

# 229 "data/maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRegisterMatchCallAfterBattle:: @ 81EF4F3
# 230 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 231 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 232 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
# 233 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_BENJAMIN_1
# 234 "data/maps/Route110/scripts.pory"
	release
# 235 "data/maps/Route110/scripts.pory"
	end
# 236 "data/maps/Route110/scripts.pory"

# 237 "data/maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRematch:: @ 81EF512
# 238 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
# 239 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
# 240 "data/maps/Route110/scripts.pory"
	end
# 241 "data/maps/Route110/scripts.pory"

# 242 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jasmine:: @ 81EF529
# 243 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
# 244 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
# 245 "data/maps/Route110/scripts.pory"
	end
# 246 "data/maps/Route110/scripts.pory"

# 247 "data/maps/Route110/scripts.pory"
Route110_EventScript_Abigail:: @ 81EF540
# 248 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
# 249 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 250 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, TRUE
# 251 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_AbigailRematch
# 252 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
# 253 "data/maps/Route110/scripts.pory"
	release
# 254 "data/maps/Route110/scripts.pory"
	end
# 255 "data/maps/Route110/scripts.pory"

# 256 "data/maps/Route110/scripts.pory"
Route110_EventScript_AbigailRegisterMatchCallAfterBattle:: @ 81EF56C
# 257 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 258 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 259 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
# 260 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_ABIGAIL_1
# 261 "data/maps/Route110/scripts.pory"
	release
# 262 "data/maps/Route110/scripts.pory"
	end
# 263 "data/maps/Route110/scripts.pory"

# 264 "data/maps/Route110/scripts.pory"
Route110_EventScript_AbigailRematch:: @ 81EF58B
# 265 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
# 266 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
# 267 "data/maps/Route110/scripts.pory"
	end
# 268 "data/maps/Route110/scripts.pory"

# 269 "data/maps/Route110/scripts.pory"
Route110_EventScript_Isabel:: @ 81EF5A2
# 270 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
# 271 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 272 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, TRUE
# 273 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_IsabelRematch
# 274 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
# 275 "data/maps/Route110/scripts.pory"
	release
# 276 "data/maps/Route110/scripts.pory"
	end
# 277 "data/maps/Route110/scripts.pory"

# 278 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelRegisterMatchCallAfterBattle:: @ 81EF5CE
# 279 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 280 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 281 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
# 282 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_ISABEL_1
# 283 "data/maps/Route110/scripts.pory"
	release
# 284 "data/maps/Route110/scripts.pory"
	end
# 285 "data/maps/Route110/scripts.pory"

# 286 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelRematch:: @ 81EF5ED
# 287 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
# 288 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
# 289 "data/maps/Route110/scripts.pory"
	end
# 290 "data/maps/Route110/scripts.pory"

# 291 "data/maps/Route110/scripts.pory"
Route110_EventScript_Timmy:: @ 81EF604
# 292 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
# 293 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
# 294 "data/maps/Route110/scripts.pory"
	end
# 295 "data/maps/Route110/scripts.pory"

# 296 "data/maps/Route110/scripts.pory"
Route110_EventScript_Unused:: @ 81EF61B
# 297 "data/maps/Route110/scripts.pory"
	end
# 298 "data/maps/Route110/scripts.pory"

# 299 "data/maps/Route110/scripts.pory"
Route110_EventScript_Kaleb:: @ 81EF61C
# 300 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
# 301 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
# 302 "data/maps/Route110/scripts.pory"
	end
# 303 "data/maps/Route110/scripts.pory"

# 304 "data/maps/Route110/scripts.pory"
Route110_EventScript_Joseph:: @ 81EF633
# 305 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
# 306 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
# 307 "data/maps/Route110/scripts.pory"
	end
# 308 "data/maps/Route110/scripts.pory"

# 309 "data/maps/Route110/scripts.pory"
Route110_EventScript_Alyssa:: @ 81EF64A
# 310 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
# 311 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
# 312 "data/maps/Route110/scripts.pory"
	end
# 313 "data/maps/Route110/scripts.pory"

# 314 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeEnd:: @ 81EF661
# 315 "data/maps/Route110/scripts.pory"
	lockall
# 316 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFastestRight
# 317 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 318 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_CyclingChallengeResults
# 319 "data/maps/Route110/scripts.pory"
	releaseall
# 320 "data/maps/Route110/scripts.pory"
	end
# 321 "data/maps/Route110/scripts.pory"

# 322 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeResults:: @ 81EF673
# 323 "data/maps/Route110/scripts.pory"
	special FinishCyclingRoadChallenge
# 324 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
# 325 "data/maps/Route110/scripts.pory"
	switch VAR_RESULT
# 326 "data/maps/Route110/scripts.pory"
	case 10, Route110_EventScript_ChallengeReactionBest
# 327 "data/maps/Route110/scripts.pory"
	case 9, Route110_EventScript_ChallengeReactionGood
# 328 "data/maps/Route110/scripts.pory"
	case 8, Route110_EventScript_ChallengeReactionGood
# 329 "data/maps/Route110/scripts.pory"
	case 7, Route110_EventScript_ChallengeReactionGood
# 330 "data/maps/Route110/scripts.pory"
	case 6, Route110_EventScript_ChallengeReactionOk
# 331 "data/maps/Route110/scripts.pory"
	case 5, Route110_EventScript_ChallengeReactionOk
# 332 "data/maps/Route110/scripts.pory"
	case 4, Route110_EventScript_ChallengeReactionOk
# 333 "data/maps/Route110/scripts.pory"
	case 3, Route110_EventScript_ChallengeReactionBad
# 334 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_ChallengeReactionBad
# 335 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_ChallengeReactionBad
# 336 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_ChallengeReactionWorst
# 337 "data/maps/Route110/scripts.pory"
	end
# 338 "data/maps/Route110/scripts.pory"

# 339 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBest:: @ 81EF6FD
# 340 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
# 341 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_GiveTM83, MSGBOX_DEFAULT
# 342 "data/maps/Route110/scripts.pory"
	givecustommon SPECIES_HELIOLISK, 25, ITEM_CHOICE_SPECS, ITEM_PREMIER_BALL, NATURE_TIMID, 2, 0, 0, 0, 252, 252, 4, 0, 0, 0, 0, 0, 0, MOVE_THUNDERBOLT, MOVE_VOLT_SWITCH, MOVE_GRASS_KNOT, MOVE_FOCUS_BLAST, TRUE
# 343 "data/maps/Route110/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 344 "data/maps/Route110/scripts.pory"
	message Route110_Text_ObtainedShinyHeliolisk
# 345 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 346 "data/maps/Route110/scripts.pory"
	end
# 347 "data/maps/Route110/scripts.pory"

# 348 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionGood:: @ 81EF70B
# 349 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
# 350 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_GiveTM83, MSGBOX_DEFAULT
# 351 "data/maps/Route110/scripts.pory"
	givecustommon SPECIES_HELIOLISK, 20, ITEM_LIFE_ORB, ITEM_PREMIER_BALL, NATURE_TIMID, 0, 0, 0, 0, 252, 252, 4, 0, 0, 0, 0, 0, 0, MOVE_SURF, MOVE_THUNDER, MOVE_HYPER_VOICE, MOVE_DRAGON_PULSE, FALSE
# 352 "data/maps/Route110/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 353 "data/maps/Route110/scripts.pory"
	message Route110_Text_ObtainedHeliolisk
# 354 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 355 "data/maps/Route110/scripts.pory"
	end
# 356 "data/maps/Route110/scripts.pory"

# 357 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionOk:: @ 81EF719
# 358 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
# 359 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 360 "data/maps/Route110/scripts.pory"
	end
# 361 "data/maps/Route110/scripts.pory"

# 362 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBad:: @ 81EF727
# 363 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
# 364 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 365 "data/maps/Route110/scripts.pory"
	end
# 366 "data/maps/Route110/scripts.pory"

# 367 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionWorst:: @ 81EF735
# 368 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
# 369 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 370 "data/maps/Route110/scripts.pory"
	end
# 371 "data/maps/Route110/scripts.pory"

# 372 "data/maps/Route110/scripts.pory"
Route110_EventScript_EndChallenge:: @ 81EF743
# 373 "data/maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
# 374 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 375 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 376 "data/maps/Route110/scripts.pory"
	return
# 377 "data/maps/Route110/scripts.pory"

# 378 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger1:: @ 81EF74D
# 379 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 380 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 381 "data/maps/Route110/scripts.pory"
	end
# 382 "data/maps/Route110/scripts.pory"

# 383 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger2:: @ 81EF758
# 384 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 385 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 386 "data/maps/Route110/scripts.pory"
	end
# 387 "data/maps/Route110/scripts.pory"

# 388 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger3:: @ 81EF763
# 389 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 390 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 391 "data/maps/Route110/scripts.pory"
	end
# 392 "data/maps/Route110/scripts.pory"

# 393 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalScene:: @ 81EF76E
# 394 "data/maps/Route110/scripts.pory"
	lockall
# 395 "data/maps/Route110/scripts.pory"
	checkplayergender
# 396 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, MALE
# 397 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_PlayMayMusic
# 398 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, FEMALE
# 399 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_PlayBrendanMusic
# 400 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
# 401 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 402 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 403 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 404 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 405 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 406 "data/maps/Route110/scripts.pory"
	delay 30
# 407 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 1
# 408 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_RivalApproachPlayer1
# 409 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 2
# 410 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_RivalApproachPlayer2
# 411 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 3
# 412 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_RivalApproachPlayer3
# 413 "data/maps/Route110/scripts.pory"
	checkplayergender
# 414 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, MALE
# 415 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_MayBattle
# 416 "data/maps/Route110/scripts.pory"
	compare VAR_RESULT, FEMALE
# 417 "data/maps/Route110/scripts.pory"
	goto_if_eq Route110_EventScript_BrendanBattle
# 418 "data/maps/Route110/scripts.pory"
	releaseall
# 419 "data/maps/Route110/scripts.pory"
	end
# 420 "data/maps/Route110/scripts.pory"

# 421 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayMayMusic:: @ 81EF7E1
# 422 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 423 "data/maps/Route110/scripts.pory"
	return
# 424 "data/maps/Route110/scripts.pory"

# 425 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayBrendanMusic:: @ 81EF7E6
# 426 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 427 "data/maps/Route110/scripts.pory"
	return
# 428 "data/maps/Route110/scripts.pory"

# 429 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattle:: @ 81EF7EB
# 430 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
# 431 "data/maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 432 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_MayBattleTreecko
# 433 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_MayBattleTorchic
# 434 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_MayBattleMudkip
# 435 "data/maps/Route110/scripts.pory"
	end
# 436 "data/maps/Route110/scripts.pory"

# 437 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleTreecko:: @ 81EF81A
# 438 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
# 439 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 440 "data/maps/Route110/scripts.pory"
	end
# 441 "data/maps/Route110/scripts.pory"

# 442 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleTorchic:: @ 81EF82A
# 443 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
# 444 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 445 "data/maps/Route110/scripts.pory"
	end
# 446 "data/maps/Route110/scripts.pory"

# 447 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleMudkip:: @ 81EF83A
# 448 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
# 449 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 450 "data/maps/Route110/scripts.pory"
	end
# 451 "data/maps/Route110/scripts.pory"

# 452 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayDefeated:: @ 81EF84A
# 453 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
# 454 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveItemfinder
# 455 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
# 456 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 457 "data/maps/Route110/scripts.pory"
	end
# 458 "data/maps/Route110/scripts.pory"

# 459 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattle:: @ 81EF865
# 460 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 461 "data/maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 462 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_BrendanBattleTreecko
# 463 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_BrendanBattleTorchic
# 464 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_BrendanBattleMudkip
# 465 "data/maps/Route110/scripts.pory"
	end
# 466 "data/maps/Route110/scripts.pory"

# 467 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleTreecko:: @ 81EF894
# 468 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
# 469 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 470 "data/maps/Route110/scripts.pory"
	end
# 471 "data/maps/Route110/scripts.pory"

# 472 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleTorchic:: @ 81EF8A4
# 473 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
# 474 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 475 "data/maps/Route110/scripts.pory"
	end
# 476 "data/maps/Route110/scripts.pory"

# 477 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleMudkip:: @ 81EF8B4
# 478 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
# 479 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 480 "data/maps/Route110/scripts.pory"
	end
# 481 "data/maps/Route110/scripts.pory"

# 482 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanDefeated:: @ 81EF8C4
# 483 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
# 484 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveItemfinder
# 485 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
# 486 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 487 "data/maps/Route110/scripts.pory"
	end
# 488 "data/maps/Route110/scripts.pory"

# 489 "data/maps/Route110/scripts.pory"
Route110_EventScript_GiveItemfinder:: @ 81EF8DF
# 490 "data/maps/Route110/scripts.pory"
	giveitem ITEM_ITEMFINDER
# 491 "data/maps/Route110/scripts.pory"
	return
# 492 "data/maps/Route110/scripts.pory"

# 493 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit:: @ 81EF8EC
# 494 "data/maps/Route110/scripts.pory"
	closemessage
# 495 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 1
# 496 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_MoveRival1
# 497 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 2
# 498 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_MoveRival2
# 499 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 3
# 500 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_MoveRival3
# 501 "data/maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
# 502 "data/maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
# 503 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL
# 504 "data/maps/Route110/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 505 "data/maps/Route110/scripts.pory"
	delay 45
# 506 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 1
# 507 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_RivalExit1
# 508 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 2
# 509 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_RivalExit2
# 510 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 3
# 511 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_RivalExit3
# 512 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 513 "data/maps/Route110/scripts.pory"
	setvar VAR_ROUTE110_STATE, 1
# 514 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 515 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 516 "data/maps/Route110/scripts.pory"
	releaseall
# 517 "data/maps/Route110/scripts.pory"
	end
# 518 "data/maps/Route110/scripts.pory"

# 519 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer1:: @ 81EF94E
# 520 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
# 521 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 522 "data/maps/Route110/scripts.pory"
	return
# 523 "data/maps/Route110/scripts.pory"

# 524 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer2:: @ 81EF959
# 525 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
# 526 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 527 "data/maps/Route110/scripts.pory"
	return
# 528 "data/maps/Route110/scripts.pory"

# 529 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer3:: @ 81EF964
# 530 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
# 531 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 532 "data/maps/Route110/scripts.pory"
	return
# 533 "data/maps/Route110/scripts.pory"

# 534 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit1:: @ 81EF96F
# 535 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
# 536 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 537 "data/maps/Route110/scripts.pory"
	return
# 538 "data/maps/Route110/scripts.pory"

# 539 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit2:: @ 81EF97A
# 540 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
# 541 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 542 "data/maps/Route110/scripts.pory"
	return
# 543 "data/maps/Route110/scripts.pory"

# 544 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit3:: @ 81EF985
# 545 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
# 546 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 547 "data/maps/Route110/scripts.pory"
	return
# 548 "data/maps/Route110/scripts.pory"

# 549 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival1:: @ 81EF990
# 550 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
# 551 "data/maps/Route110/scripts.pory"
	return
# 552 "data/maps/Route110/scripts.pory"

# 553 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival2:: @ 81EF998
# 554 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
# 555 "data/maps/Route110/scripts.pory"
	return
# 556 "data/maps/Route110/scripts.pory"

# 557 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival3:: @ 81EF9A0
# 558 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
# 559 "data/maps/Route110/scripts.pory"
	return
# 560 "data/maps/Route110/scripts.pory"

# 561 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer1: @ 81EF9A8
# 562 "data/maps/Route110/scripts.pory"
	walk_down
# 563 "data/maps/Route110/scripts.pory"
	walk_left
# 564 "data/maps/Route110/scripts.pory"
	walk_in_place_fastest_down
# 565 "data/maps/Route110/scripts.pory"
	step_end
# 566 "data/maps/Route110/scripts.pory"

# 567 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer2: @ 81EF9AC
# 568 "data/maps/Route110/scripts.pory"
	walk_down
# 569 "data/maps/Route110/scripts.pory"
	step_end
# 570 "data/maps/Route110/scripts.pory"

# 571 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer3: @ 81EF9AE
# 572 "data/maps/Route110/scripts.pory"
	walk_down
# 573 "data/maps/Route110/scripts.pory"
	walk_right
# 574 "data/maps/Route110/scripts.pory"
	walk_in_place_fastest_down
# 575 "data/maps/Route110/scripts.pory"
	step_end
# 576 "data/maps/Route110/scripts.pory"

# 577 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit1: @ 81EF9B2
# 578 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 579 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 580 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 581 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 582 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 583 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 584 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 585 "data/maps/Route110/scripts.pory"
	step_end
# 586 "data/maps/Route110/scripts.pory"

# 587 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit2: @ 81EF9BA
# 588 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 589 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 590 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 591 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 592 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 593 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 594 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 595 "data/maps/Route110/scripts.pory"
	walk_fast_down
# 596 "data/maps/Route110/scripts.pory"
	step_end
# 597 "data/maps/Route110/scripts.pory"

# 598 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit3: @ 81EF9C3
# 599 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 600 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 601 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 602 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 603 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 604 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 605 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 606 "data/maps/Route110/scripts.pory"
	step_end
# 607 "data/maps/Route110/scripts.pory"

# 608 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene1:: @ 81EF9CB
# 609 "data/maps/Route110/scripts.pory"
	lockall
# 610 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 611 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 612 "data/maps/Route110/scripts.pory"

# 613 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene2:: @ 81EF9D6
# 614 "data/maps/Route110/scripts.pory"
	lockall
# 615 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 616 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 617 "data/maps/Route110/scripts.pory"

# 618 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene3:: @ 81EF9E1
# 619 "data/maps/Route110/scripts.pory"
	lockall
# 620 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 621 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 622 "data/maps/Route110/scripts.pory"

# 623 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene4:: @ 81EF9EC
# 624 "data/maps/Route110/scripts.pory"
	lockall
# 625 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 4
# 626 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 627 "data/maps/Route110/scripts.pory"

# 628 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene:: @ 81EF9F7
# 629 "data/maps/Route110/scripts.pory"
	addobject LOCALID_BIRCH
# 630 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
# 631 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 632 "data/maps/Route110/scripts.pory"
	playse SE_PIN
# 633 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 634 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 635 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
# 636 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 637 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 1
# 638 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_BirchApproachPlayer1
# 639 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 2
# 640 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_BirchApproachPlayer2
# 641 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 3
# 642 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_BirchApproachPlayer3
# 643 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 4
# 644 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_BirchApproachPlayer4
# 645 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
# 646 "data/maps/Route110/scripts.pory"
	closemessage
# 647 "data/maps/Route110/scripts.pory"
	delay 20
# 648 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestLeft
# 649 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 650 "data/maps/Route110/scripts.pory"
	delay 10
# 651 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
# 652 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 653 "data/maps/Route110/scripts.pory"
	delay 20
# 654 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestDown
# 655 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 656 "data/maps/Route110/scripts.pory"
	delay 30
# 657 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
# 658 "data/maps/Route110/scripts.pory"
	closemessage
# 659 "data/maps/Route110/scripts.pory"
	delay 30
# 660 "data/maps/Route110/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 661 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
# 662 "data/maps/Route110/scripts.pory"
	waitfanfare
# 663 "data/maps/Route110/scripts.pory"
	closemessage
# 664 "data/maps/Route110/scripts.pory"
	delay 30
# 665 "data/maps/Route110/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 666 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
# 667 "data/maps/Route110/scripts.pory"
	closemessage
# 668 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 1
# 669 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_BirchExit1
# 670 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 2
# 671 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_BirchExit2
# 672 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 3
# 673 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_BirchExit3
# 674 "data/maps/Route110/scripts.pory"
	compare VAR_0x8008, 4
# 675 "data/maps/Route110/scripts.pory"
	call_if_eq Route110_EventScript_BirchExit4
# 676 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_BIRCH
# 677 "data/maps/Route110/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 678 "data/maps/Route110/scripts.pory"
	releaseall
# 679 "data/maps/Route110/scripts.pory"
	end
# 680 "data/maps/Route110/scripts.pory"

# 681 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer1:: @ 81EFAD8
# 682 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
# 683 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 684 "data/maps/Route110/scripts.pory"
	return
# 685 "data/maps/Route110/scripts.pory"

# 686 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer2:: @ 81EFAE3
# 687 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
# 688 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 689 "data/maps/Route110/scripts.pory"
	return
# 690 "data/maps/Route110/scripts.pory"

# 691 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer3:: @ 81EFAEE
# 692 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
# 693 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 694 "data/maps/Route110/scripts.pory"
	return
# 695 "data/maps/Route110/scripts.pory"

# 696 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer4:: @ 81EFAF9
# 697 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
# 698 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 699 "data/maps/Route110/scripts.pory"
	return
# 700 "data/maps/Route110/scripts.pory"

# 701 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit1:: @ 81EFB04
# 702 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
# 703 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 704 "data/maps/Route110/scripts.pory"
	return
# 705 "data/maps/Route110/scripts.pory"

# 706 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit2:: @ 81EFB0F
# 707 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
# 708 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 709 "data/maps/Route110/scripts.pory"
	return
# 710 "data/maps/Route110/scripts.pory"

# 711 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit3:: @ 81EFB1A
# 712 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
# 713 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 714 "data/maps/Route110/scripts.pory"
	return
# 715 "data/maps/Route110/scripts.pory"

# 716 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit4:: @ 81EFB25
# 717 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
# 718 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 719 "data/maps/Route110/scripts.pory"
	return
# 720 "data/maps/Route110/scripts.pory"

# 721 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchEntrance: @ 81EFB30
# 722 "data/maps/Route110/scripts.pory"
	walk_down
# 723 "data/maps/Route110/scripts.pory"
	walk_down
# 724 "data/maps/Route110/scripts.pory"
	walk_down
# 725 "data/maps/Route110/scripts.pory"
	step_end
# 726 "data/maps/Route110/scripts.pory"

# 727 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer1: @ 81EFB34
# 728 "data/maps/Route110/scripts.pory"
	walk_down
# 729 "data/maps/Route110/scripts.pory"
	walk_left
# 730 "data/maps/Route110/scripts.pory"
	walk_left
# 731 "data/maps/Route110/scripts.pory"
	walk_down
# 732 "data/maps/Route110/scripts.pory"
	step_end
# 733 "data/maps/Route110/scripts.pory"

# 734 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer2: @ 81EFB39
# 735 "data/maps/Route110/scripts.pory"
	walk_down
# 736 "data/maps/Route110/scripts.pory"
	walk_left
# 737 "data/maps/Route110/scripts.pory"
	walk_down
# 738 "data/maps/Route110/scripts.pory"
	step_end
# 739 "data/maps/Route110/scripts.pory"

# 740 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer3: @ 81EFB3D
# 741 "data/maps/Route110/scripts.pory"
	walk_down
# 742 "data/maps/Route110/scripts.pory"
	walk_down
# 743 "data/maps/Route110/scripts.pory"
	step_end
# 744 "data/maps/Route110/scripts.pory"

# 745 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer4: @ 81EFB40
# 746 "data/maps/Route110/scripts.pory"
	walk_down
# 747 "data/maps/Route110/scripts.pory"
	walk_right
# 748 "data/maps/Route110/scripts.pory"
	walk_down
# 749 "data/maps/Route110/scripts.pory"
	step_end
# 750 "data/maps/Route110/scripts.pory"

# 751 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit1: @ 81EFB44
# 752 "data/maps/Route110/scripts.pory"
	walk_up
# 753 "data/maps/Route110/scripts.pory"
	walk_up
# 754 "data/maps/Route110/scripts.pory"
	walk_right
# 755 "data/maps/Route110/scripts.pory"
	walk_up
# 756 "data/maps/Route110/scripts.pory"
	walk_up
# 757 "data/maps/Route110/scripts.pory"
	walk_up
# 758 "data/maps/Route110/scripts.pory"
	step_end
# 759 "data/maps/Route110/scripts.pory"

# 760 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit2: @ 81EFB4B
# 761 "data/maps/Route110/scripts.pory"
	walk_up
# 762 "data/maps/Route110/scripts.pory"
	walk_up
# 763 "data/maps/Route110/scripts.pory"
	walk_up
# 764 "data/maps/Route110/scripts.pory"
	walk_up
# 765 "data/maps/Route110/scripts.pory"
	walk_up
# 766 "data/maps/Route110/scripts.pory"
	step_end
# 767 "data/maps/Route110/scripts.pory"

# 768 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit3: @ 81EFB51
# 769 "data/maps/Route110/scripts.pory"
	walk_up
# 770 "data/maps/Route110/scripts.pory"
	walk_up
# 771 "data/maps/Route110/scripts.pory"
	walk_up
# 772 "data/maps/Route110/scripts.pory"
	walk_up
# 773 "data/maps/Route110/scripts.pory"
	walk_up
# 774 "data/maps/Route110/scripts.pory"
	step_end
# 775 "data/maps/Route110/scripts.pory"

# 776 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit4: @ 81EFB57
# 777 "data/maps/Route110/scripts.pory"
	walk_up
# 778 "data/maps/Route110/scripts.pory"
	walk_up
# 779 "data/maps/Route110/scripts.pory"
	walk_up
# 780 "data/maps/Route110/scripts.pory"
	walk_up
# 781 "data/maps/Route110/scripts.pory"
	walk_up
# 782 "data/maps/Route110/scripts.pory"
	step_end
# 783 "data/maps/Route110/scripts.pory"

# 784 "data/maps/Route110/scripts.pory"
Route110_Text_WeCantTalkAboutAquaActivities: @ 81EFB5D
# 785 "data/maps/Route110/scripts.pory"
	.string "Team Aqua's activities…\n"
# 786 "data/maps/Route110/scripts.pory"
	.string "We can't talk about them yet.$"
# 787 "data/maps/Route110/scripts.pory"

# 788 "data/maps/Route110/scripts.pory"
Route110_Text_KickUpARuckus: @ 81EFB93
# 789 "data/maps/Route110/scripts.pory"
	.string "I want to get going to Slateport and\n"
# 790 "data/maps/Route110/scripts.pory"
	.string "kick up a ruckus!$"
# 791 "data/maps/Route110/scripts.pory"

# 792 "data/maps/Route110/scripts.pory"
Route110_Text_MyFirstJobInAqua: @ 81EFBCA
# 793 "data/maps/Route110/scripts.pory"
	.string "This is my first job after joining\n"
# 794 "data/maps/Route110/scripts.pory"
	.string "Team Aqua. It's a little scary.$"
# 795 "data/maps/Route110/scripts.pory"

# 796 "data/maps/Route110/scripts.pory"
Route110_Text_AquaActionsBringSmiles: @ 81EFC0D
# 797 "data/maps/Route110/scripts.pory"
	.string "Team Aqua's actions should bring\n"
# 798 "data/maps/Route110/scripts.pory"
	.string "smiles to people's faces!$"
# 799 "data/maps/Route110/scripts.pory"

# 800 "data/maps/Route110/scripts.pory"
Route110_Text_MayLetsBattle: @ 81EFC48
# 801 "data/maps/Route110/scripts.pory"
	.string "May: Hi, {PLAYER}{KUN}, long time no see!\p"
# 802 "data/maps/Route110/scripts.pory"
	.string "While I was searching for other\n"
# 803 "data/maps/Route110/scripts.pory"
	.string "Pokémon, my Pokémon grew stronger.\p"
# 804 "data/maps/Route110/scripts.pory"
	.string "So…\n"
# 805 "data/maps/Route110/scripts.pory"
	.string "How about a little battle?$"
# 806 "data/maps/Route110/scripts.pory"

# 807 "data/maps/Route110/scripts.pory"
Route110_Text_MayDefeated: @ 81EFCCB
# 808 "data/maps/Route110/scripts.pory"
	.string "Yikes!\n"
# 809 "data/maps/Route110/scripts.pory"
	.string "You're better than I expected!$"
# 810 "data/maps/Route110/scripts.pory"

# 811 "data/maps/Route110/scripts.pory"
Route110_Text_MayTakeThis: @ 81EFCF1
# 812 "data/maps/Route110/scripts.pory"
	.string "May: {PLAYER}{KUN}, you've been busy\n"
# 813 "data/maps/Route110/scripts.pory"
	.string "training, too, haven't you?\p"
# 814 "data/maps/Route110/scripts.pory"
	.string "I think you deserve a reward!\n"
# 815 "data/maps/Route110/scripts.pory"
	.string "This is from me!$"
# 816 "data/maps/Route110/scripts.pory"

# 817 "data/maps/Route110/scripts.pory"
Route110_Text_MayExplainItemfinder: @ 81EFD58
# 818 "data/maps/Route110/scripts.pory"
	.string "May: That's an Itemfinder.\p"
# 819 "data/maps/Route110/scripts.pory"
	.string "Try it out. If there is an item that's\n"
# 820 "data/maps/Route110/scripts.pory"
	.string "not visible, it emits a sound.\p"
# 821 "data/maps/Route110/scripts.pory"
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
# 822 "data/maps/Route110/scripts.pory"
	.string "I know it's a little silly coming from\n"
# 823 "data/maps/Route110/scripts.pory"
	.string "me, but I think you should train a lot\l"
# 824 "data/maps/Route110/scripts.pory"
	.string "harder for the next time.$"
# 825 "data/maps/Route110/scripts.pory"

# 826 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanLetsBattle: @ 81EFE3F
# 827 "data/maps/Route110/scripts.pory"
	.string "Brendan: Hey, {PLAYER}.\n"
# 828 "data/maps/Route110/scripts.pory"
	.string "So this is where you were.\l"
# 829 "data/maps/Route110/scripts.pory"
	.string "How's it going?\p"
# 830 "data/maps/Route110/scripts.pory"
	.string "Have you been raising your Pokémon?\n"
# 831 "data/maps/Route110/scripts.pory"
	.string "I'll check for you.$"
# 832 "data/maps/Route110/scripts.pory"

# 833 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanDefeated: @ 81EFEB4
# 834 "data/maps/Route110/scripts.pory"
	.string "Hmm…\n"
# 835 "data/maps/Route110/scripts.pory"
	.string "You're pretty good.$"
# 836 "data/maps/Route110/scripts.pory"

# 837 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanTakeThis: @ 81EFECD
# 838 "data/maps/Route110/scripts.pory"
	.string "Brendan: {PLAYER}, you've trained\n"
# 839 "data/maps/Route110/scripts.pory"
	.string "without me noticing…\p"
# 840 "data/maps/Route110/scripts.pory"
	.string "Good enough!\n"
# 841 "data/maps/Route110/scripts.pory"
	.string "Here, take this.$"
# 842 "data/maps/Route110/scripts.pory"

# 843 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanExplainItemfinder: @ 81EFF1C
# 844 "data/maps/Route110/scripts.pory"
	.string "Brendan: That's an Itemfinder.\p"
# 845 "data/maps/Route110/scripts.pory"
	.string "Use it to root around for items that\n"
# 846 "data/maps/Route110/scripts.pory"
	.string "aren't visible.\p"
# 847 "data/maps/Route110/scripts.pory"
	.string "If it senses something, it emits\n"
# 848 "data/maps/Route110/scripts.pory"
	.string "a sound.\p"
# 849 "data/maps/Route110/scripts.pory"
	.string "Anyway, I'm off to look for new\n"
# 850 "data/maps/Route110/scripts.pory"
	.string "Pokémon.$"
# 851 "data/maps/Route110/scripts.pory"

# 852 "data/maps/Route110/scripts.pory"
Route110_Text_RideBikeAtFullSpeed: @ 81EFFC3
# 853 "data/maps/Route110/scripts.pory"
	.string "Wouldn't it be great to ride a Bike\n"
# 854 "data/maps/Route110/scripts.pory"
	.string "at full speed on Cycling Road?$"
# 855 "data/maps/Route110/scripts.pory"

# 856 "data/maps/Route110/scripts.pory"
Route110_Text_HairStreamsBehindMe: @ 81F0006
# 857 "data/maps/Route110/scripts.pory"
	.string "How do you like the way my raven-\n"
# 858 "data/maps/Route110/scripts.pory"
	.string "colored hair streams behind me?\p"
# 859 "data/maps/Route110/scripts.pory"
	.string "I grew my hair out just for that.$"
# 860 "data/maps/Route110/scripts.pory"

# 861 "data/maps/Route110/scripts.pory"
Route110_Text_YouGotBikeFromRydel: @ 81F006A
# 862 "data/maps/Route110/scripts.pory"
	.string "Oh, hey, you got that Bike from Rydel!\p"
# 863 "data/maps/Route110/scripts.pory"
	.string "Oh, it's glaringly obvious.\n"
# 864 "data/maps/Route110/scripts.pory"
	.string "It says right on your bike…\p"
# 865 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\n"
# 866 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\p"
# 867 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\n"
# 868 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\p"
# 869 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\n"
# 870 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\p"
# 871 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\n"
# 872 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\p"
# 873 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\n"
# 874 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\p"
# 875 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\n"
# 876 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel,\p"
# 877 "data/maps/Route110/scripts.pory"
	.string "Rydel, Rydel, Rydel, Rydel, Rydel…\n"
# 878 "data/maps/Route110/scripts.pory"
	.string "That name's everywhere.\p"
# 879 "data/maps/Route110/scripts.pory"
	.string "You should ride it around all over\n"
# 880 "data/maps/Route110/scripts.pory"
	.string "the place--it's good advertising!$"
# 881 "data/maps/Route110/scripts.pory"

# 882 "data/maps/Route110/scripts.pory"
Route110_Text_TwoRoads: @ 81F0261
# 883 "data/maps/Route110/scripts.pory"
	.string "The two roads, one above, one below…\p"
# 884 "data/maps/Route110/scripts.pory"
	.string "A road each for people and Pokémon.\n"
# 885 "data/maps/Route110/scripts.pory"
	.string "Perhaps that is right and fair.$"
# 886 "data/maps/Route110/scripts.pory"

# 887 "data/maps/Route110/scripts.pory"
Route110_Text_WalkOnTheLowRoad: @ 81F02CA
# 888 "data/maps/Route110/scripts.pory"
	.string "I don't have a Bike, so I'll take\n"
# 889 "data/maps/Route110/scripts.pory"
	.string "a leisurely walk on the low road.$"
# 890 "data/maps/Route110/scripts.pory"

# 891 "data/maps/Route110/scripts.pory"
Route110_Text_BikeTechniques: @ 81F030E
# 892 "data/maps/Route110/scripts.pory"
	.string "Learning techniques will make Bike\n"
# 893 "data/maps/Route110/scripts.pory"
	.string "riding even more fun.\p"
# 894 "data/maps/Route110/scripts.pory"
	.string "There are some places that you can\n"
# 895 "data/maps/Route110/scripts.pory"
	.string "reach only by using a Bike technique.$"
# 896 "data/maps/Route110/scripts.pory"

# 897 "data/maps/Route110/scripts.pory"
Route110_Text_WhichShouldIChoose: @ 81F0390
# 898 "data/maps/Route110/scripts.pory"
	.string "Which should I choose?\p"
# 899 "data/maps/Route110/scripts.pory"
	.string "Make a beeline for Mauville on\n"
# 900 "data/maps/Route110/scripts.pory"
	.string "Cycling Road, or take the low road\l"
# 901 "data/maps/Route110/scripts.pory"
	.string "and look for Pokémon?$"
# 902 "data/maps/Route110/scripts.pory"

# 903 "data/maps/Route110/scripts.pory"
Route110_Text_CyclingChallengeResultSummary: @ 81F03FF
# 904 "data/maps/Route110/scripts.pory"
	.string "Number of collisions:\n"
# 905 "data/maps/Route110/scripts.pory"
	.string "… … {STR_VAR_1}!\p"
# 906 "data/maps/Route110/scripts.pory"
	.string "Total time:\n"
# 907 "data/maps/Route110/scripts.pory"
	.string "… … {STR_VAR_2}!$"
# 908 "data/maps/Route110/scripts.pory"

# 909 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBest: @ 81F0431
# 910 "data/maps/Route110/scripts.pory"
	.string "Bravo! Splendid showing!\p"
# 911 "data/maps/Route110/scripts.pory"
	.string "Your love of cycling comes from deep\n"
# 912 "data/maps/Route110/scripts.pory"
	.string "within your heart.\l"
# 913 "data/maps/Route110/scripts.pory"
	.string "You've shaken me to my very soul!$"
# 914 "data/maps/Route110/scripts.pory"

# 915 "data/maps/Route110/scripts.pory"
Route110_Text_GiveTM93:
# 916 "data/maps/Route110/scripts.pory"
	.string "Please, take this TM as a reward\n"
# 917 "data/maps/Route110/scripts.pory"
	.string "for your cycling mastery!$"
# 918 "data/maps/Route110/scripts.pory"

# 919 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionGood: @ 81F04A4
# 920 "data/maps/Route110/scripts.pory"
	.string "Your technique is remarkable.\p"
# 921 "data/maps/Route110/scripts.pory"
	.string "I suggest you speed up a bit while\n"
# 922 "data/maps/Route110/scripts.pory"
	.string "still avoiding collisions.$"
# 923 "data/maps/Route110/scripts.pory"

# 924 "data/maps/Route110/scripts.pory"
Route110_Text_GiveTM83:
# 925 "data/maps/Route110/scripts.pory"
	.string "Here, take this Pokémon to\n"
# 926 "data/maps/Route110/scripts.pory"
	.string "commemorate your success.$"
# 927 "data/maps/Route110/scripts.pory"

# 928 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionOk: @ 81F0500
# 929 "data/maps/Route110/scripts.pory"
	.string "I would consider you a work in\n"
# 930 "data/maps/Route110/scripts.pory"
	.string "progress.\p"
# 931 "data/maps/Route110/scripts.pory"
	.string "Still, I hope you don't forget the\n"
# 932 "data/maps/Route110/scripts.pory"
	.string "sheer pleasure of cycling.$"
# 933 "data/maps/Route110/scripts.pory"

# 934 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBad: @ 81F0567
# 935 "data/maps/Route110/scripts.pory"
	.string "My word… Your cycling skills border\n"
# 936 "data/maps/Route110/scripts.pory"
	.string "on terrifying.\p"
# 937 "data/maps/Route110/scripts.pory"
	.string "Most certainly, you need much more\n"
# 938 "data/maps/Route110/scripts.pory"
	.string "practice riding.$"
# 939 "data/maps/Route110/scripts.pory"

# 940 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionWorst: @ 81F05CE
# 941 "data/maps/Route110/scripts.pory"
	.string "…I am aghast…\p"
# 942 "data/maps/Route110/scripts.pory"
	.string "You're perhaps not cut out for this\n"
# 943 "data/maps/Route110/scripts.pory"
	.string "unfortunate cycling business.\p"
# 944 "data/maps/Route110/scripts.pory"
	.string "You ought to give serious thought to\n"
# 945 "data/maps/Route110/scripts.pory"
	.string "returning that Bike to Rydel.$"
# 946 "data/maps/Route110/scripts.pory"

# 947 "data/maps/Route110/scripts.pory"
Route110_Text_RatedForNumberOfCollisions: @ 81F0661
# 948 "data/maps/Route110/scripts.pory"
	.string "This is Cycling Road.\p"
# 949 "data/maps/Route110/scripts.pory"
	.string "If you were to ride from Mauville to\n"
# 950 "data/maps/Route110/scripts.pory"
	.string "Slateport on a Mach Bike, you would\l"
# 951 "data/maps/Route110/scripts.pory"
	.string "be rated for the number of collisions\l"
# 952 "data/maps/Route110/scripts.pory"
	.string "and your total time.$"
# 953 "data/maps/Route110/scripts.pory"

# 954 "data/maps/Route110/scripts.pory"
Route110_Text_AlwaysAimHigher: @ 81F06FB
# 955 "data/maps/Route110/scripts.pory"
	.string "Regardless of the results, I count on\n"
# 956 "data/maps/Route110/scripts.pory"
	.string "seeing more challenges from you.\l"
# 957 "data/maps/Route110/scripts.pory"
	.string "Always aim higher!$"
# 958 "data/maps/Route110/scripts.pory"

# 959 "data/maps/Route110/scripts.pory"
Route110_Text_AcroBikesDoNotQualify: @ 81F0755
# 960 "data/maps/Route110/scripts.pory"
	.string "On this Cycling Road, those riding\n"
# 961 "data/maps/Route110/scripts.pory"
	.string "Mach Bikes are rated for their number\l"
# 962 "data/maps/Route110/scripts.pory"
	.string "of collisions and their total times.\p"
# 963 "data/maps/Route110/scripts.pory"
	.string "Acro Bikes do not qualify for rating.\n"
# 964 "data/maps/Route110/scripts.pory"
	.string "They are easy to turn, so it's not fair.$"
# 965 "data/maps/Route110/scripts.pory"

# 966 "data/maps/Route110/scripts.pory"
Route110_Text_SlateportCitySign: @ 81F0812
# 967 "data/maps/Route110/scripts.pory"
	.string "Route 110\n"
# 968 "data/maps/Route110/scripts.pory"
	.string "{DOWN_ARROW} Slateport City$"
# 969 "data/maps/Route110/scripts.pory"

# 970 "data/maps/Route110/scripts.pory"
Route110_Text_CyclingRoadSign: @ 81F082D
# 971 "data/maps/Route110/scripts.pory"
	.string "Seaside Cycling Road$"
# 972 "data/maps/Route110/scripts.pory"

# 973 "data/maps/Route110/scripts.pory"
Route110_Text_AquaWasHere: @ 81F0842
# 974 "data/maps/Route110/scripts.pory"
	.string "“Team Aqua was here!”\p"
# 975 "data/maps/Route110/scripts.pory"
	.string "Someone painted that onto this sign,\n"
# 976 "data/maps/Route110/scripts.pory"
	.string "but then someone else painted over it.\p"
# 977 "data/maps/Route110/scripts.pory"
	.string "“Team Magma rules!” is what it\n"
# 978 "data/maps/Route110/scripts.pory"
	.string "says now.$"
# 979 "data/maps/Route110/scripts.pory"

# 980 "data/maps/Route110/scripts.pory"
Route110_Text_Route103Sign: @ 81F08CD
# 981 "data/maps/Route110/scripts.pory"
	.string "Route 110\n"
# 982 "data/maps/Route110/scripts.pory"
	.string "{LEFT_ARROW} Route 103$"
# 983 "data/maps/Route110/scripts.pory"

# 984 "data/maps/Route110/scripts.pory"
Route110_Text_SeasideParkingSign: @ 81F08E3
# 985 "data/maps/Route110/scripts.pory"
	.string "Seaside Parking$"
# 986 "data/maps/Route110/scripts.pory"

# 987 "data/maps/Route110/scripts.pory"
Route110_Text_MauvilleCitySign: @ 81F08F3
# 988 "data/maps/Route110/scripts.pory"
	.string "Route 110\n"
# 989 "data/maps/Route110/scripts.pory"
	.string "{UP_ARROW} Mauville City$"
# 990 "data/maps/Route110/scripts.pory"

# 991 "data/maps/Route110/scripts.pory"
Route110_Text_TrainerTipsPrlzSleep: @ 81F090D
# 992 "data/maps/Route110/scripts.pory"
	.string "Trainer Tips\p"
# 993 "data/maps/Route110/scripts.pory"
	.string "The foe can be made helpless by\n"
# 994 "data/maps/Route110/scripts.pory"
	.string "paralyzing it or causing it to sleep.\p"
# 995 "data/maps/Route110/scripts.pory"
	.string "It is an important technique for\n"
# 996 "data/maps/Route110/scripts.pory"
	.string "Pokémon battles.$"
# 997 "data/maps/Route110/scripts.pory"

# 998 "data/maps/Route110/scripts.pory"
Route110_Text_TrainerTipsRegisterItems: @ 81F0992
# 999 "data/maps/Route110/scripts.pory"
	.string "Trainer Tips\p"
# 1000 "data/maps/Route110/scripts.pory"
	.string "The items in the Bag can be reorganized\n"
# 1001 "data/maps/Route110/scripts.pory"
	.string "by pressing Select.$"
# 1002 "data/maps/Route110/scripts.pory"

# 1003 "data/maps/Route110/scripts.pory"
Route110_Text_TrickHouseSign: @ 81F09DB
# 1004 "data/maps/Route110/scripts.pory"
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
# 1005 "data/maps/Route110/scripts.pory"
	.string "to reach the wondrous Trick House.”$"
# 1006 "data/maps/Route110/scripts.pory"

# 1007 "data/maps/Route110/scripts.pory"
Route110_Text_BestRecord: @ 81F0A1E
# 1008 "data/maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 1009 "data/maps/Route110/scripts.pory"
	.string "No. of collisions: {STR_VAR_1}\p"
# 1010 "data/maps/Route110/scripts.pory"
	.string "Elapsed time: {STR_VAR_2}$"
# 1011 "data/maps/Route110/scripts.pory"

# 1012 "data/maps/Route110/scripts.pory"
Route110_Text_ThereIsNoRecord: @ 81F0A5E
# 1013 "data/maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 1014 "data/maps/Route110/scripts.pory"
	.string "No one seems to have taken the\n"
# 1015 "data/maps/Route110/scripts.pory"
	.string "challenge. There is no record…$"
# 1016 "data/maps/Route110/scripts.pory"

# 1017 "data/maps/Route110/scripts.pory"
Route110_Text_ImagineSeeingYouHere: @ 81F0AB5
# 1018 "data/maps/Route110/scripts.pory"
	.string "Prof. Birch: Oh, {PLAYER}{KUN}!\n"
# 1019 "data/maps/Route110/scripts.pory"
	.string "Imagine seeing you here!\p"
# 1020 "data/maps/Route110/scripts.pory"
	.string "And where might my {RIVAL} be?$"
# 1021 "data/maps/Route110/scripts.pory"

# 1022 "data/maps/Route110/scripts.pory"
Route110_Text_HeardYouInstallMatchCall: @ 81F0AFF
# 1023 "data/maps/Route110/scripts.pory"
	.string "Oh, I see!\n"
# 1024 "data/maps/Route110/scripts.pory"
	.string "You two are running separately.\l"
# 1025 "data/maps/Route110/scripts.pory"
	.string "Well, that's fine.\p"
# 1026 "data/maps/Route110/scripts.pory"
	.string "Oh, yes, I heard that your PokéNav\n"
# 1027 "data/maps/Route110/scripts.pory"
	.string "had the Match Call system installed.\p"
# 1028 "data/maps/Route110/scripts.pory"
	.string "Well, then, I should register you in\n"
# 1029 "data/maps/Route110/scripts.pory"
	.string "my PokéNav as well.\p"
# 1030 "data/maps/Route110/scripts.pory"
	.string "That way, even when we're apart,\n"
# 1031 "data/maps/Route110/scripts.pory"
	.string "I can rate your Pokédex anytime.\p"
# 1032 "data/maps/Route110/scripts.pory"
	.string "… … … … … …$"
# 1033 "data/maps/Route110/scripts.pory"

# 1034 "data/maps/Route110/scripts.pory"
Route110_Text_RegisteredBirchInPokenav: @ 81F0C0C
# 1035 "data/maps/Route110/scripts.pory"
	.string "Registered Prof. Birch\n"
# 1036 "data/maps/Route110/scripts.pory"
	.string "in the PokéNav.$"
# 1037 "data/maps/Route110/scripts.pory"

# 1038 "data/maps/Route110/scripts.pory"
Route110_Text_KeepAnEyeOutForRival: @ 81F0C33
# 1039 "data/maps/Route110/scripts.pory"
	.string "Prof. Birch: {PLAYER}{KUN}…\p"
# 1040 "data/maps/Route110/scripts.pory"
	.string "Please keep an eye out for my {RIVAL}.\n"
# 1041 "data/maps/Route110/scripts.pory"
	.string "… … … … … …\p"
# 1042 "data/maps/Route110/scripts.pory"
	.string "Well, I had better get going.\n"
# 1043 "data/maps/Route110/scripts.pory"
	.string "See you again, {PLAYER}{KUN}!$"

Route110_Walking_EventScript_Gen8_NPC::
# 1047 "data/maps/Route110/scripts.pory"
	lock
# 1048 "data/maps/Route110/scripts.pory"
	faceplayer
# 1049 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_ISABEL_1
	goto_if 1, Route110_Walking_EventScript_Gen8_NPC_5
Route110_Walking_EventScript_Gen8_NPC_3:
# 1066 "data/maps/Route110/scripts.pory"
	msgbox Route110_Walking_EventScript_Gen8_NPC_Text_2
Route110_Walking_EventScript_Gen8_NPC_1:
# 1068 "data/maps/Route110/scripts.pory"
	release
	end

Route110_Walking_EventScript_Gen8_NPC_2:
# 1058 "data/maps/Route110/scripts.pory"
	msgbox Route110_Walking_EventScript_Gen8_NPC_Text_0
# 1059 "data/maps/Route110/scripts.pory"
	givemon SPECIES_TOXEL, 10, ITEM_NONE
# 1060 "data/maps/Route110/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1061 "data/maps/Route110/scripts.pory"
	message Route110_Walking_EventScript_Gen8_NPC_Text_1
# 1062 "data/maps/Route110/scripts.pory"
	waitfanfare
	goto Route110_Walking_EventScript_Gen8_NPC_1

Route110_Walking_EventScript_Gen8_NPC_4:
# 1051 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_TIMMY
	goto_if 1, Route110_Walking_EventScript_Gen8_NPC_9
	goto Route110_Walking_EventScript_Gen8_NPC_3

Route110_Walking_EventScript_Gen8_NPC_5:
# 1050 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_KALEB
	goto_if 1, Route110_Walking_EventScript_Gen8_NPC_4
	goto Route110_Walking_EventScript_Gen8_NPC_3

Route110_Walking_EventScript_Gen8_NPC_8:
# 1053 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_JOSEPH
	goto_if 1, Route110_Walking_EventScript_Gen8_NPC_13
	goto Route110_Walking_EventScript_Gen8_NPC_3

Route110_Walking_EventScript_Gen8_NPC_9:
# 1052 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_EDWIN_1
	goto_if 1, Route110_Walking_EventScript_Gen8_NPC_8
	goto Route110_Walking_EventScript_Gen8_NPC_3

Route110_Walking_EventScript_Gen8_NPC_12:
# 1055 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_EDWARD
	goto_if 1, Route110_Walking_EventScript_Gen8_NPC_16
	goto Route110_Walking_EventScript_Gen8_NPC_3

Route110_Walking_EventScript_Gen8_NPC_13:
# 1054 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_ALYSSA
	goto_if 1, Route110_Walking_EventScript_Gen8_NPC_12
	goto Route110_Walking_EventScript_Gen8_NPC_3

Route110_Walking_EventScript_Gen8_NPC_16:
# 1056 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_DALE
	goto_if 1, Route110_Walking_EventScript_Gen8_NPC_2
	goto Route110_Walking_EventScript_Gen8_NPC_3


Route110_CyclingRoad_EventScript_Gen8_NPC::
# 1073 "data/maps/Route110/scripts.pory"
	lock
# 1074 "data/maps/Route110/scripts.pory"
	faceplayer
# 1075 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_ABIGAIL_1
	goto_if 1, Route110_CyclingRoad_EventScript_Gen8_NPC_5
Route110_CyclingRoad_EventScript_Gen8_NPC_3:
# 1089 "data/maps/Route110/scripts.pory"
	msgbox Route110_CyclingRoad_EventScript_Gen8_NPC_Text_2
Route110_CyclingRoad_EventScript_Gen8_NPC_1:
# 1091 "data/maps/Route110/scripts.pory"
	release
	end

Route110_CyclingRoad_EventScript_Gen8_NPC_2:
# 1081 "data/maps/Route110/scripts.pory"
	msgbox Route110_CyclingRoad_EventScript_Gen8_NPC_Text_0
# 1082 "data/maps/Route110/scripts.pory"
	givemon SPECIES_ROLYCOLY, 10, ITEM_NONE
# 1083 "data/maps/Route110/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1084 "data/maps/Route110/scripts.pory"
	message Route110_CyclingRoad_EventScript_Gen8_NPC_Text_1
# 1085 "data/maps/Route110/scripts.pory"
	waitfanfare
	goto Route110_CyclingRoad_EventScript_Gen8_NPC_1

Route110_CyclingRoad_EventScript_Gen8_NPC_4:
# 1077 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_BENJAMIN_1
	goto_if 1, Route110_CyclingRoad_EventScript_Gen8_NPC_9
	goto Route110_CyclingRoad_EventScript_Gen8_NPC_3

Route110_CyclingRoad_EventScript_Gen8_NPC_5:
# 1076 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_ANTHONY
	goto_if 1, Route110_CyclingRoad_EventScript_Gen8_NPC_4
	goto Route110_CyclingRoad_EventScript_Gen8_NPC_3

Route110_CyclingRoad_EventScript_Gen8_NPC_8:
# 1079 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_JACOB
	goto_if 1, Route110_CyclingRoad_EventScript_Gen8_NPC_2
	goto Route110_CyclingRoad_EventScript_Gen8_NPC_3

Route110_CyclingRoad_EventScript_Gen8_NPC_9:
# 1078 "data/maps/Route110/scripts.pory"
	checktrainerflag TRAINER_JASMINE
	goto_if 1, Route110_CyclingRoad_EventScript_Gen8_NPC_8
	goto Route110_CyclingRoad_EventScript_Gen8_NPC_3


Route110_Walking_EventScript_Gen8_NPC_Text_0:
# 1058 "data/maps/Route110/scripts.pory"
	.string "Hey now, you're a rockstar!$"

Route110_Walking_EventScript_Gen8_NPC_Text_1:
# 1061 "data/maps/Route110/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Toxel{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer!$"

Route110_Walking_EventScript_Gen8_NPC_Text_2:
# 1066 "data/maps/Route110/scripts.pory"
	.string "Somebody once told me 'A trainer is\n"
	.string "gonna roll them!'. Get your game on, go,\l"
	.string "play!$"

Route110_CyclingRoad_EventScript_Gen8_NPC_Text_0:
# 1081 "data/maps/Route110/scripts.pory"
	.string "Steam wins once again! Here, take this\n"
	.string "wonder of nature and technology as a\l"
	.string "sign of gratitude and recognition!$"

Route110_CyclingRoad_EventScript_Gen8_NPC_Text_1:
# 1084 "data/maps/Route110/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Rolycoly{COLOR DARK_GRAY} as a gift for\n"
	.string "defeating every trainer on the Cycling\l"
	.string "Road!$"

Route110_CyclingRoad_EventScript_Gen8_NPC_Text_2:
# 1089 "data/maps/Route110/scripts.pory"
	.string "Did you know? Galarians used to build\n"
	.string "machines powered by Pokémon! You can\l"
	.string "have a steam-powered-pokémon too, but\l"
	.string "only after showing these\l"
	.string "muscle-powered-bike-wielding\l"
	.string "Hoennians a lesson!$"

Route110_Text_ObtainedHeliolisk::
# 1096 "data/maps/Route110/scripts.pory"
	.string "{PLAYER} got a {COLOR BLUE}Heliolisk{COLOR DARK_GRAY}$"

Route110_Text_ObtainedShinyHeliolisk::
# 1100 "data/maps/Route110/scripts.pory"
	.string "{PLAYER} got a Shiny{COLOR BLUE}Heliolisk{COLOR DARK_GRAY}$"
