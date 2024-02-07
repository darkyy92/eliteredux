# 1 "data/maps/ContestHall/scripts.pory"

# 2 "data/maps/ContestHall/scripts.pory"
ContestHall_MapScripts:: @ 823B781
# 3 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ContestHall_OnWarp
# 4 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ContestHall_OnFrame
# 5 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ContestHall_OnTransition
# 6 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, ContestHall_OnResume
# 7 "data/maps/ContestHall/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, ContestHall_OnReturn
# 8 "data/maps/ContestHall/scripts.pory"
	.byte 0
# 9 "data/maps/ContestHall/scripts.pory"

# 10 "data/maps/ContestHall/scripts.pory"
ContestHall_OnReturn: @ 823B79B
# 11 "data/maps/ContestHall/scripts.pory"
	special LoadLinkContestPlayerPalettes
# 12 "data/maps/ContestHall/scripts.pory"
	end
# 13 "data/maps/ContestHall/scripts.pory"

# 14 "data/maps/ContestHall/scripts.pory"
ContestHall_OnTransition: @ 823B79F
# 15 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_ReadyContestMusic
# 16 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_0, 1
# 17 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_AddRandomAudienceMembers
# 18 "data/maps/ContestHall/scripts.pory"
	end
# 19 "data/maps/ContestHall/scripts.pory"

# 20 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_ReadyContestMusic:: @ 823B7AF
# 21 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_TryWaitForLink
# 22 "data/maps/ContestHall/scripts.pory"
	special GetContestMultiplayerId
# 23 "data/maps/ContestHall/scripts.pory"
	compare VAR_RESULT, 0
# 24 "data/maps/ContestHall/scripts.pory"
	call_if_eq ContestHall_EventScript_SaveContestMusicPlayer1
# 25 "data/maps/ContestHall/scripts.pory"
	compare VAR_RESULT, 1
# 26 "data/maps/ContestHall/scripts.pory"
	call_if_eq ContestHall_EventScript_SaveContestMusicPlayer2
# 27 "data/maps/ContestHall/scripts.pory"
	compare VAR_RESULT, 2
# 28 "data/maps/ContestHall/scripts.pory"
	call_if_eq ContestHall_EventScript_SaveContestMusicPlayer3
# 29 "data/maps/ContestHall/scripts.pory"
	compare VAR_RESULT, 3
# 30 "data/maps/ContestHall/scripts.pory"
	call_if_eq ContestHall_EventScript_SaveContestMusicPlayer4
# 31 "data/maps/ContestHall/scripts.pory"
	compare VAR_RESULT, 4
# 32 "data/maps/ContestHall/scripts.pory"
	call_if_eq ContestHall_EventScript_SaveContestMusic
# 33 "data/maps/ContestHall/scripts.pory"
	return
# 34 "data/maps/ContestHall/scripts.pory"

# 35 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusicPlayer1:: @ 823B7EF
# 36 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_LINK_CONTEST_P1
# 37 "data/maps/ContestHall/scripts.pory"
	return
# 38 "data/maps/ContestHall/scripts.pory"

# 39 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusicPlayer2:: @ 823B7F3
# 40 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_LINK_CONTEST_P2
# 41 "data/maps/ContestHall/scripts.pory"
	return
# 42 "data/maps/ContestHall/scripts.pory"

# 43 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusicPlayer3:: @ 823B7F7
# 44 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_LINK_CONTEST_P3
# 45 "data/maps/ContestHall/scripts.pory"
	return
# 46 "data/maps/ContestHall/scripts.pory"

# 47 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusicPlayer4:: @ 823B7FB
# 48 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_LINK_CONTEST_P4
# 49 "data/maps/ContestHall/scripts.pory"
	return
# 50 "data/maps/ContestHall/scripts.pory"

# 51 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SaveContestMusic:: @ 823B7FF
# 52 "data/maps/ContestHall/scripts.pory"
	savebgm MUS_CONTEST
# 53 "data/maps/ContestHall/scripts.pory"
	return
# 54 "data/maps/ContestHall/scripts.pory"

# 55 "data/maps/ContestHall/scripts.pory"
ContestHall_OnResume: @ 823B803
# 56 "data/maps/ContestHall/scripts.pory"
	compare VAR_TEMP_9, 1
# 57 "data/maps/ContestHall/scripts.pory"
	call_if_eq ContestHall_EventScript_ReShowAudience
# 58 "data/maps/ContestHall/scripts.pory"
	end
# 59 "data/maps/ContestHall/scripts.pory"

# 60 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_ReShowAudience:: @ 823B80F
# 61 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_CreateAudience
# 62 "data/maps/ContestHall/scripts.pory"
	return
# 63 "data/maps/ContestHall/scripts.pory"

# 64 "data/maps/ContestHall/scripts.pory"
ContestHall_OnFrame: @ 823B815
# 65 "data/maps/ContestHall/scripts.pory"
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_Contest
# 66 "data/maps/ContestHall/scripts.pory"
	.2byte 0
# 67 "data/maps/ContestHall/scripts.pory"

# 68 "data/maps/ContestHall/scripts.pory"
ContestHall_OnWarp: @ 823B81F
# 69 "data/maps/ContestHall/scripts.pory"
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_SetContestObjects
# 70 "data/maps/ContestHall/scripts.pory"
	.2byte 0
# 71 "data/maps/ContestHall/scripts.pory"

# 72 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_Contest:: @ 823B829
# 73 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_DoContest
# 74 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_SetExitWarp
# 75 "data/maps/ContestHall/scripts.pory"
	end
# 76 "data/maps/ContestHall/scripts.pory"

# 77 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetContestObjects:: @ 823B834
# 78 "data/maps/ContestHall/scripts.pory"
	special LoadLinkContestPlayerPalettes
# 79 "data/maps/ContestHall/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
# 80 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_CreateAudience
# 81 "data/maps/ContestHall/scripts.pory"
	end
# 82 "data/maps/ContestHall/scripts.pory"

# 83 "data/maps/ContestHall/scripts.pory"
@ There are 8 audience member object events, 7 of which are given random gfx below (the 8th is the Artist)
# 84 "data/maps/ContestHall/scripts.pory"
@ The rest of the audience is created statically by ContestHall_EventScript_CreateAudience
# 85 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_AddRandomAudienceMembers:: @ 823B842
# 86 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_GetRandomAudienceGfxId
# 87 "data/maps/ContestHall/scripts.pory"
	call ContestHall_EventScript_SetRandomAudienceGfx
# 88 "data/maps/ContestHall/scripts.pory"
	compare VAR_TEMP_0, 8
# 89 "data/maps/ContestHall/scripts.pory"
	goto_if_lt ContestHall_EventScript_AddRandomAudienceMembers
# 90 "data/maps/ContestHall/scripts.pory"
	return
# 91 "data/maps/ContestHall/scripts.pory"

# 92 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudienceGfx:: @ 823B858
# 93 "data/maps/ContestHall/scripts.pory"
	switch VAR_TEMP_0
# 94 "data/maps/ContestHall/scripts.pory"
	case 1, ContestHall_EventScript_SetRandomAudience1
# 95 "data/maps/ContestHall/scripts.pory"
	case 2, ContestHall_EventScript_SetRandomAudience2
# 96 "data/maps/ContestHall/scripts.pory"
	case 3, ContestHall_EventScript_SetRandomAudience3
# 97 "data/maps/ContestHall/scripts.pory"
	case 4, ContestHall_EventScript_SetRandomAudience4
# 98 "data/maps/ContestHall/scripts.pory"
	case 5, ContestHall_EventScript_SetRandomAudience5
# 99 "data/maps/ContestHall/scripts.pory"
	case 6, ContestHall_EventScript_SetRandomAudience6
# 100 "data/maps/ContestHall/scripts.pory"
	case 7, ContestHall_EventScript_SetRandomAudience7
# 101 "data/maps/ContestHall/scripts.pory"
	end
# 102 "data/maps/ContestHall/scripts.pory"

# 103 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience1:: @ 823B8AB
# 104 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_4, VAR_TEMP_1
# 105 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 106 "data/maps/ContestHall/scripts.pory"
	return
# 107 "data/maps/ContestHall/scripts.pory"

# 108 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience2:: @ 823B8B6
# 109 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_1
# 110 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 111 "data/maps/ContestHall/scripts.pory"
	return
# 112 "data/maps/ContestHall/scripts.pory"

# 113 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience3:: @ 823B8C1
# 114 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_6, VAR_TEMP_1
# 115 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 116 "data/maps/ContestHall/scripts.pory"
	return
# 117 "data/maps/ContestHall/scripts.pory"

# 118 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience4:: @ 823B8CC
# 119 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_7, VAR_TEMP_1
# 120 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 121 "data/maps/ContestHall/scripts.pory"
	return
# 122 "data/maps/ContestHall/scripts.pory"

# 123 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience5:: @ 823B8D7
# 124 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_8, VAR_TEMP_1
# 125 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 126 "data/maps/ContestHall/scripts.pory"
	return
# 127 "data/maps/ContestHall/scripts.pory"

# 128 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience6:: @ 823B8E2
# 129 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_9, VAR_TEMP_1
# 130 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 131 "data/maps/ContestHall/scripts.pory"
	return
# 132 "data/maps/ContestHall/scripts.pory"

# 133 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetRandomAudience7:: @ 823B8ED
# 134 "data/maps/ContestHall/scripts.pory"
	copyvar VAR_OBJ_GFX_ID_A, VAR_TEMP_1
# 135 "data/maps/ContestHall/scripts.pory"
	addvar VAR_TEMP_0, 1
# 136 "data/maps/ContestHall/scripts.pory"
	return
# 137 "data/maps/ContestHall/scripts.pory"

# 138 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_GetRandomAudienceGfxId:: @ 823B8F8
# 139 "data/maps/ContestHall/scripts.pory"
	setvar VAR_RESULT, 32
# 140 "data/maps/ContestHall/scripts.pory"
	special GenerateContestRand
# 141 "data/maps/ContestHall/scripts.pory"
	addvar VAR_RESULT, 1
# 142 "data/maps/ContestHall/scripts.pory"
	switch VAR_RESULT
# 143 "data/maps/ContestHall/scripts.pory"
	case 1, ContestHall_EventScript_RandomAudienceNinjaBoy
# 144 "data/maps/ContestHall/scripts.pory"
	case 2, ContestHall_EventScript_RandomAudienceTwin
# 145 "data/maps/ContestHall/scripts.pory"
	case 3, ContestHall_EventScript_RandomAudienceBoy1
# 146 "data/maps/ContestHall/scripts.pory"
	case 4, ContestHall_EventScript_RandomAudienceGirl1
# 147 "data/maps/ContestHall/scripts.pory"
	case 5, ContestHall_EventScript_RandomAudienceGirl2
# 148 "data/maps/ContestHall/scripts.pory"
	case 6, ContestHall_EventScript_RandomAudienceLittleBoy
# 149 "data/maps/ContestHall/scripts.pory"
	case 7, ContestHall_EventScript_RandomAudienceGirl
# 150 "data/maps/ContestHall/scripts.pory"
	case 8, ContestHall_EventScript_RandomAudienceBoy3
# 151 "data/maps/ContestHall/scripts.pory"
	case 9, ContestHall_EventScript_RandomAudienceGirl3
# 152 "data/maps/ContestHall/scripts.pory"
	case 10, ContestHall_EventScript_RandomAudienceRichBoy
# 153 "data/maps/ContestHall/scripts.pory"
	case 11, ContestHall_EventScript_RandomAudienceFatMan
# 154 "data/maps/ContestHall/scripts.pory"
	case 12, ContestHall_EventScript_RandomAudiencePokefanF
# 155 "data/maps/ContestHall/scripts.pory"
	case 13, ContestHall_EventScript_RandomAudienceMan1
# 156 "data/maps/ContestHall/scripts.pory"
	case 14, ContestHall_EventScript_RandomAudienceWoman2
# 157 "data/maps/ContestHall/scripts.pory"
	case 15, ContestHall_EventScript_RandomAudienceExpertM
# 158 "data/maps/ContestHall/scripts.pory"
	case 16, ContestHall_EventScript_RandomAudienceExpertF
# 159 "data/maps/ContestHall/scripts.pory"
	case 17, ContestHall_EventScript_RandomAudiencePokefanM
# 160 "data/maps/ContestHall/scripts.pory"
	case 18, ContestHall_EventScript_RandomAudienceWoman4
# 161 "data/maps/ContestHall/scripts.pory"
	case 19, ContestHall_EventScript_RandomAudienceCook
# 162 "data/maps/ContestHall/scripts.pory"
	case 20, ContestHall_EventScript_RandomAudienceLass
# 163 "data/maps/ContestHall/scripts.pory"
	case 21, ContestHall_EventScript_RandomAudienceOldWoman
# 164 "data/maps/ContestHall/scripts.pory"
	case 22, ContestHall_EventScript_RandomAudienceCamper
# 165 "data/maps/ContestHall/scripts.pory"
	case 23, ContestHall_EventScript_RandomAudiencePicnicker
# 166 "data/maps/ContestHall/scripts.pory"
	case 24, ContestHall_EventScript_RandomAudienceMan3
# 167 "data/maps/ContestHall/scripts.pory"
	case 25, ContestHall_EventScript_RandomAudienceWoman5
# 168 "data/maps/ContestHall/scripts.pory"
	case 26, ContestHall_EventScript_RandomAudienceYoungster
# 169 "data/maps/ContestHall/scripts.pory"
	case 27, ContestHall_EventScript_RandomAudienceBugCatcher
# 170 "data/maps/ContestHall/scripts.pory"
	case 28, ContestHall_EventScript_RandomAudiencePsychicM
# 171 "data/maps/ContestHall/scripts.pory"
	case 29, ContestHall_EventScript_RandomAudienceSchoolKidM
# 172 "data/maps/ContestHall/scripts.pory"
	case 30, ContestHall_EventScript_RandomAudienceBlackBelt
# 173 "data/maps/ContestHall/scripts.pory"
	case 31, ContestHall_EventScript_RandomAudienceBeauty
# 174 "data/maps/ContestHall/scripts.pory"
	case 32, ContestHall_EventScript_RandomAudienceScientist1
# 175 "data/maps/ContestHall/scripts.pory"
	end
# 176 "data/maps/ContestHall/scripts.pory"

# 177 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceNinjaBoy:: @ 823BA6B
# 178 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_NINJA_BOY
# 179 "data/maps/ContestHall/scripts.pory"
	return
# 180 "data/maps/ContestHall/scripts.pory"

# 181 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceTwin:: @ 823BA71
# 182 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_TWIN
# 183 "data/maps/ContestHall/scripts.pory"
	return
# 184 "data/maps/ContestHall/scripts.pory"

# 185 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBoy1:: @ 823BA77
# 186 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_1
# 187 "data/maps/ContestHall/scripts.pory"
	return
# 188 "data/maps/ContestHall/scripts.pory"

# 189 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceGirl1:: @ 823BA7D
# 190 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_1
# 191 "data/maps/ContestHall/scripts.pory"
	return
# 192 "data/maps/ContestHall/scripts.pory"

# 193 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceGirl2:: @ 823BA83
# 194 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_2
# 195 "data/maps/ContestHall/scripts.pory"
	return
# 196 "data/maps/ContestHall/scripts.pory"

# 197 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceLittleBoy:: @ 823BA89
# 198 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_BOY
# 199 "data/maps/ContestHall/scripts.pory"
	return
# 200 "data/maps/ContestHall/scripts.pory"

# 201 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceGirl:: @ 823BA8F
# 202 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_GIRL
# 203 "data/maps/ContestHall/scripts.pory"
	return
# 204 "data/maps/ContestHall/scripts.pory"

# 205 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBoy3:: @ 823BA95
# 206 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_3
# 207 "data/maps/ContestHall/scripts.pory"
	return
# 208 "data/maps/ContestHall/scripts.pory"

# 209 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceGirl3:: @ 823BA9B
# 210 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_3
# 211 "data/maps/ContestHall/scripts.pory"
	return
# 212 "data/maps/ContestHall/scripts.pory"

# 213 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceRichBoy:: @ 823BAA1
# 214 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_RICH_BOY
# 215 "data/maps/ContestHall/scripts.pory"
	return
# 216 "data/maps/ContestHall/scripts.pory"

# 217 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceFatMan:: @ 823BAA7
# 218 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_FAT_MAN
# 219 "data/maps/ContestHall/scripts.pory"
	return
# 220 "data/maps/ContestHall/scripts.pory"

# 221 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudiencePokefanF:: @ 823BAAD
# 222 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_F
# 223 "data/maps/ContestHall/scripts.pory"
	return
# 224 "data/maps/ContestHall/scripts.pory"

# 225 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceMan1:: @ 823BAB3
# 226 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_1
# 227 "data/maps/ContestHall/scripts.pory"
	return
# 228 "data/maps/ContestHall/scripts.pory"

# 229 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceWoman2:: @ 823BAB9
# 230 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_2
# 231 "data/maps/ContestHall/scripts.pory"
	return
# 232 "data/maps/ContestHall/scripts.pory"

# 233 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceExpertM:: @ 823BABF
# 234 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_M
# 235 "data/maps/ContestHall/scripts.pory"
	return
# 236 "data/maps/ContestHall/scripts.pory"

# 237 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceExpertF:: @ 823BAC5
# 238 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_F
# 239 "data/maps/ContestHall/scripts.pory"
	return
# 240 "data/maps/ContestHall/scripts.pory"

# 241 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudiencePokefanM:: @ 823BACB
# 242 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_M
# 243 "data/maps/ContestHall/scripts.pory"
	return
# 244 "data/maps/ContestHall/scripts.pory"

# 245 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceWoman4:: @ 823BAD1
# 246 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_4
# 247 "data/maps/ContestHall/scripts.pory"
	return
# 248 "data/maps/ContestHall/scripts.pory"

# 249 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceCook:: @ 823BAD7
# 250 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_COOK
# 251 "data/maps/ContestHall/scripts.pory"
	return
# 252 "data/maps/ContestHall/scripts.pory"

# 253 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceLass:: @ 823BADD
# 254 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LASS
# 255 "data/maps/ContestHall/scripts.pory"
	return
# 256 "data/maps/ContestHall/scripts.pory"

# 257 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceOldWoman:: @ 823BAE3
# 258 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_OLD_WOMAN
# 259 "data/maps/ContestHall/scripts.pory"
	return
# 260 "data/maps/ContestHall/scripts.pory"

# 261 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceCamper:: @ 823BAE9
# 262 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_CAMPER
# 263 "data/maps/ContestHall/scripts.pory"
	return
# 264 "data/maps/ContestHall/scripts.pory"

# 265 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudiencePicnicker:: @ 823BAEF
# 266 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PICNICKER
# 267 "data/maps/ContestHall/scripts.pory"
	return
# 268 "data/maps/ContestHall/scripts.pory"

# 269 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceMan3:: @ 823BAF5
# 270 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_3
# 271 "data/maps/ContestHall/scripts.pory"
	return
# 272 "data/maps/ContestHall/scripts.pory"

# 273 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceWoman5:: @ 823BAFB
# 274 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_5
# 275 "data/maps/ContestHall/scripts.pory"
	return
# 276 "data/maps/ContestHall/scripts.pory"

# 277 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceYoungster:: @ 823BB01
# 278 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_YOUNGSTER
# 279 "data/maps/ContestHall/scripts.pory"
	return
# 280 "data/maps/ContestHall/scripts.pory"

# 281 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBugCatcher:: @ 823BB07
# 282 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BUG_CATCHER
# 283 "data/maps/ContestHall/scripts.pory"
	return
# 284 "data/maps/ContestHall/scripts.pory"

# 285 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudiencePsychicM:: @ 823BB0D
# 286 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PSYCHIC_M
# 287 "data/maps/ContestHall/scripts.pory"
	return
# 288 "data/maps/ContestHall/scripts.pory"

# 289 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceSchoolKidM:: @ 823BB13
# 290 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCHOOL_KID_M
# 291 "data/maps/ContestHall/scripts.pory"
	return
# 292 "data/maps/ContestHall/scripts.pory"

# 293 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBlackBelt:: @ 823BB19
# 294 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BLACK_BELT
# 295 "data/maps/ContestHall/scripts.pory"
	return
# 296 "data/maps/ContestHall/scripts.pory"

# 297 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceBeauty:: @ 823BB1F
# 298 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BEAUTY
# 299 "data/maps/ContestHall/scripts.pory"
	return
# 300 "data/maps/ContestHall/scripts.pory"

# 301 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_RandomAudienceScientist1:: @ 823BB25
# 302 "data/maps/ContestHall/scripts.pory"
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCIENTIST_1
# 303 "data/maps/ContestHall/scripts.pory"
	return
# 304 "data/maps/ContestHall/scripts.pory"

# 305 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateAudience:: @ 823BB2B
# 306 "data/maps/ContestHall/scripts.pory"
	specialvar VAR_RESULT, IsWirelessContest
# 307 "data/maps/ContestHall/scripts.pory"
	compare VAR_RESULT, TRUE
# 308 "data/maps/ContestHall/scripts.pory"
	goto_if_eq ContestHall_EventScript_CreateWirelessContestAudience
# 309 "data/maps/ContestHall/scripts.pory"
	switch VAR_CONTEST_TYPE
# 310 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_CreateNormalContestAudience
# 311 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_CreateSuperContestAudience
# 312 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_CreateHyperContestAudience
# 313 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_CreateMasterContestAudience
# 314 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_LINK, ContestHall_EventScript_CreateMasterContestAudience
# 315 "data/maps/ContestHall/scripts.pory"
	return
# 316 "data/maps/ContestHall/scripts.pory"

# 317 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateNormalContestAudience:: @ 823BB78
# 318 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 20, 3, 2, 3, DIR_SOUTH
# 319 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
# 320 "data/maps/ContestHall/scripts.pory"
	return
# 321 "data/maps/ContestHall/scripts.pory"

# 322 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateSuperContestAudience:: @ 823BB8B
# 323 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
# 324 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
# 325 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
# 326 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 3, 2, 8, 3, DIR_EAST
# 327 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
# 328 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
# 329 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
# 330 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 13, 12, 8, 3, DIR_WEST
# 331 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LASS, 20, 3, 2, 3, DIR_SOUTH
# 332 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
# 333 "data/maps/ContestHall/scripts.pory"
	return
# 334 "data/maps/ContestHall/scripts.pory"

# 335 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateHyperContestAudience:: @ 823BBE6
# 336 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
# 337 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
# 338 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
# 339 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 3, 2, 8, 3, DIR_EAST
# 340 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
# 341 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
# 342 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
# 343 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
# 344 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 3, 2, 3, DIR_SOUTH
# 345 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_2, 20, 6, 2, 3, DIR_SOUTH
# 346 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 20, 7, 2, 3, DIR_SOUTH
# 347 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 8, 2, 3, DIR_SOUTH
# 348 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 11, 2, 3, DIR_SOUTH
# 349 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 3, 9, 3, DIR_NORTH
# 350 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
# 351 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 5, 9, 3, DIR_NORTH
# 352 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
# 353 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
# 354 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
# 355 "data/maps/ContestHall/scripts.pory"
	return
# 356 "data/maps/ContestHall/scripts.pory"

# 357 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateMasterContestAudience:: @ 823BC92
# 358 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
# 359 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
# 360 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
# 361 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
# 362 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
# 363 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
# 364 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
# 365 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
# 366 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
# 367 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
# 368 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
# 369 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
# 370 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
# 371 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
# 372 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
# 373 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
# 374 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
# 375 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
# 376 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
# 377 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
# 378 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
# 379 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SAILOR, 25, 3, 9, 3, DIR_NORTH
# 380 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
# 381 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 27, 5, 9, 3, DIR_NORTH
# 382 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
# 383 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
# 384 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
# 385 "data/maps/ContestHall/scripts.pory"
	return
# 386 "data/maps/ContestHall/scripts.pory"

# 387 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_CreateWirelessContestAudience:: @ 823BD86
# 388 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
# 389 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
# 390 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
# 391 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
# 392 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
# 393 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
# 394 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
# 395 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
# 396 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
# 397 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
# 398 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
# 399 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
# 400 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
# 401 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
# 402 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
# 403 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
# 404 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
# 405 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
# 406 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
# 407 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
# 408 "data/maps/ContestHall/scripts.pory"
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
# 409 "data/maps/ContestHall/scripts.pory"
	return
# 410 "data/maps/ContestHall/scripts.pory"

# 411 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarp:: @ 823BE44
# 412 "data/maps/ContestHall/scripts.pory"
	special ClearLinkContestFlags
# 413 "data/maps/ContestHall/scripts.pory"
	switch VAR_CONTEST_TYPE
# 414 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_SetExitWarpNormalContest
# 415 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_SetExitWarpSuperContest
# 416 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_SetExitWarpHyperContest
# 417 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_SetExitWarpMasterContest
# 418 "data/maps/ContestHall/scripts.pory"
	case CONTEST_TYPE_LINK, ContestHall_EventScript_SetExitWarpLinkContest
# 419 "data/maps/ContestHall/scripts.pory"
	return
# 420 "data/maps/ContestHall/scripts.pory"

# 421 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpNormalContest:: @ 823BE84
# 422 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 14, 4
# 423 "data/maps/ContestHall/scripts.pory"
	waitstate
# 424 "data/maps/ContestHall/scripts.pory"
	end
# 425 "data/maps/ContestHall/scripts.pory"

# 426 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpSuperContest:: @ 823BE8E
# 427 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 14, 4
# 428 "data/maps/ContestHall/scripts.pory"
	waitstate
# 429 "data/maps/ContestHall/scripts.pory"
	end
# 430 "data/maps/ContestHall/scripts.pory"

# 431 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpHyperContest:: @ 823BE98
# 432 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 14, 4
# 433 "data/maps/ContestHall/scripts.pory"
	waitstate
# 434 "data/maps/ContestHall/scripts.pory"
	end
# 435 "data/maps/ContestHall/scripts.pory"

# 436 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpMasterContest:: @ 823BEA2
# 437 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 14, 4
# 438 "data/maps/ContestHall/scripts.pory"
	waitstate
# 439 "data/maps/ContestHall/scripts.pory"
	end
# 440 "data/maps/ContestHall/scripts.pory"

# 441 "data/maps/ContestHall/scripts.pory"
ContestHall_EventScript_SetExitWarpLinkContest:: @ 823BEAC
# 442 "data/maps/ContestHall/scripts.pory"
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 15, 4
# 443 "data/maps/ContestHall/scripts.pory"
	waitstate
# 444 "data/maps/ContestHall/scripts.pory"
	end
# 445 "data/maps/ContestHall/scripts.pory"

# 446 "data/maps/ContestHall/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetPlayerGfx:: @ 823BEB6
# 447 "data/maps/ContestHall/scripts.pory"
	checkplayergender
# 448 "data/maps/ContestHall/scripts.pory"
	compare VAR_RESULT, MALE
# 449 "data/maps/ContestHall/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SetPlayerGfxBrendan
# 450 "data/maps/ContestHall/scripts.pory"
	compare VAR_RESULT, FEMALE
# 451 "data/maps/ContestHall/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay
# 452 "data/maps/ContestHall/scripts.pory"
	return
# 453 "data/maps/ContestHall/scripts.pory"

# 454 "data/maps/ContestHall/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetPlayerGfxBrendan:: @ 823BECE
# 455 "data/maps/ContestHall/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 456 "data/maps/ContestHall/scripts.pory"
	return
# 457 "data/maps/ContestHall/scripts.pory"

# 458 "data/maps/ContestHall/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay:: @ 823BED4
# 459 "data/maps/ContestHall/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 460 "data/maps/ContestHall/scripts.pory"
	return
