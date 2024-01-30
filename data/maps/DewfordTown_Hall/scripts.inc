# 1 "data/maps/DewfordTown_Hall/scripts.pory"

# 2 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_EXPERT_M, 4
# 3 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_TWIN, 5
# 4 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_SCHOOL_KID_M, 7
# 5 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_PSYCHIC_M, 8
# 6 "data/maps/DewfordTown_Hall/scripts.pory"

# 7 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_MapScripts:: @ 81FD4CF
# 8 "data/maps/DewfordTown_Hall/scripts.pory"
	.byte 0
# 9 "data/maps/DewfordTown_Hall/scripts.pory"

# 10 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Girl:: @ 81FD4D0
# 11 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 12 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 13 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 14 "data/maps/DewfordTown_Hall/scripts.pory"
	special IsTrendyPhraseBoring
# 15 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_RESULT, TRUE
# 16 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_GirlBoredOfTrend
# 17 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
# 18 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 19 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 20 "data/maps/DewfordTown_Hall/scripts.pory"

# 21 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_GirlBoredOfTrend:: @ 81FD4EF
# 22 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
# 23 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 24 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 25 "data/maps/DewfordTown_Hall/scripts.pory"

# 26 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Woman:: @ 81FD4F9
# 27 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 28 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 29 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 30 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
# 31 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 32 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 33 "data/maps/DewfordTown_Hall/scripts.pory"

# 34 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Man:: @ 81FD50A
# 35 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 36 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 37 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 38 "data/maps/DewfordTown_Hall/scripts.pory"
	special BufferDeepLinkPhrase
# 39 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
# 40 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_RESULT, YES
# 41 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_ConfirmTrendLink
# 42 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_RESULT, NO
# 43 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_RejectTrendLink
# 44 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 45 "data/maps/DewfordTown_Hall/scripts.pory"

# 46 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ConfirmTrendLink:: @ 81FD533
# 47 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
# 48 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 49 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 50 "data/maps/DewfordTown_Hall/scripts.pory"

# 51 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_RejectTrendLink:: @ 81FD53D
# 52 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
# 53 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 54 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 55 "data/maps/DewfordTown_Hall/scripts.pory"

# 56 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ExpertM:: @ 81FD547
# 57 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 58 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 59 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 60 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
# 61 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 62 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFastestUp
# 63 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 64 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 65 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 66 "data/maps/DewfordTown_Hall/scripts.pory"

# 67 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Twin:: @ 81FD563
# 68 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 69 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 70 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 71 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
# 72 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 73 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFastestUp
# 74 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 75 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 76 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 77 "data/maps/DewfordTown_Hall/scripts.pory"

# 78 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LittleBoy:: @ 81FD57F
# 79 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 80 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 81 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 82 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
# 83 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 84 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 85 "data/maps/DewfordTown_Hall/scripts.pory"

# 86 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Bookshelf:: @ 81FD590
# 87 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 88 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 89 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
# 90 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 91 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 92 "data/maps/DewfordTown_Hall/scripts.pory"

# 93 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Painting:: @ 81FD5A0
# 94 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 95 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 96 "data/maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 97 "data/maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 98 "data/maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
# 99 "data/maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
# 100 "data/maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_SmileTitle
# 101 "data/maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
# 102 "data/maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_LastTitle
# 103 "data/maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_LastTitle
# 104 "data/maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_BirthTitle
# 105 "data/maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_LastTitle
# 106 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 107 "data/maps/DewfordTown_Hall/scripts.pory"

# 108 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ScreamTitle:: @ 81FD607
# 109 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
# 110 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 111 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 112 "data/maps/DewfordTown_Hall/scripts.pory"

# 113 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SmileTitle:: @ 81FD611
# 114 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
# 115 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 116 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 117 "data/maps/DewfordTown_Hall/scripts.pory"

# 118 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LastTitle:: @ 81FD61B
# 119 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
# 120 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 121 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 122 "data/maps/DewfordTown_Hall/scripts.pory"

# 123 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_BirthTitle:: @ 81FD625
# 124 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
# 125 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 126 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 127 "data/maps/DewfordTown_Hall/scripts.pory"

# 128 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SchoolKidM:: @ 81FD62F
# 129 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 130 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 0
# 131 "data/maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 132 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 133 "data/maps/DewfordTown_Hall/scripts.pory"

# 134 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PsychicM:: @ 81FD63B
# 135 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 136 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 1
# 137 "data/maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 138 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 139 "data/maps/DewfordTown_Hall/scripts.pory"

# 140 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DoTrendDebate:: @ 81FD647
# 141 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 142 "data/maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 143 "data/maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 144 "data/maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
# 145 "data/maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
# 146 "data/maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
# 147 "data/maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
# 148 "data/maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
# 149 "data/maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
# 150 "data/maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
# 151 "data/maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
# 152 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 153 "data/maps/DewfordTown_Hall/scripts.pory"

# 154 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate1:: @ 81FD6AD
# 155 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 156 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
# 157 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 158 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
# 159 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 160 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 161 "data/maps/DewfordTown_Hall/scripts.pory"

# 162 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate2:: @ 81FD6C9
# 163 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 164 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
# 165 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 166 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
# 167 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 168 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 169 "data/maps/DewfordTown_Hall/scripts.pory"

# 170 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate3:: @ 81FD6E5
# 171 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 172 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
# 173 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 174 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
# 175 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 176 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 177 "data/maps/DewfordTown_Hall/scripts.pory"

# 178 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate4:: @ 81FD701
# 179 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 180 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
# 181 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 182 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
# 183 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 184 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 185 "data/maps/DewfordTown_Hall/scripts.pory"

# 186 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate5:: @ 81FD71D
# 187 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 188 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
# 189 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 190 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
# 191 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 192 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 193 "data/maps/DewfordTown_Hall/scripts.pory"

# 194 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer1:: @ 81FD739
# 195 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 196 "data/maps/DewfordTown_Hall/scripts.pory"

# 197 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact1:: @ 81FD73A
# 198 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
# 199 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 200 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_0x8008, 0
# 201 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_PlayerReactWest
# 202 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_0x8008, 1
# 203 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_DontMovePlayer2
# 204 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 205 "data/maps/DewfordTown_Hall/scripts.pory"

# 206 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactWest:: @ 81FD75B
# 207 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 208 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_DontMovePlayer1
# 209 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 210 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 211 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 212 "data/maps/DewfordTown_Hall/scripts.pory"

# 213 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer2:: @ 81FD771
# 214 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 215 "data/maps/DewfordTown_Hall/scripts.pory"

# 216 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact2:: @ 81FD772
# 217 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
# 218 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 219 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_0x8008, 0
# 220 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_PlayerReactNorthSouth
# 221 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_0x8008, 1
# 222 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_PlayerReactEast
# 223 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 224 "data/maps/DewfordTown_Hall/scripts.pory"

# 225 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactNorthSouth:: @ 81FD793
# 226 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 227 "data/maps/DewfordTown_Hall/scripts.pory"
	call_if_eq DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
# 228 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
# 229 "data/maps/DewfordTown_Hall/scripts.pory"
	call_if_eq DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
# 230 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 231 "data/maps/DewfordTown_Hall/scripts.pory"

# 232 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp:: @ 81FD7AA
# 233 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 234 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 235 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 236 "data/maps/DewfordTown_Hall/scripts.pory"

# 237 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown:: @ 81FD7B5
# 238 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
# 239 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 240 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 241 "data/maps/DewfordTown_Hall/scripts.pory"

# 242 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactEast:: @ 81FD7C0
# 243 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 244 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_DontMovePlayer1
# 245 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 246 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 247 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 248 "data/maps/DewfordTown_Hall/scripts.pory"

# 249 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft: @ 81FD7D6
# 250 "data/maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_left
# 251 "data/maps/DewfordTown_Hall/scripts.pory"
	step_end
# 252 "data/maps/DewfordTown_Hall/scripts.pory"

# 253 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight: @ 81FD7D8
# 254 "data/maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_right
# 255 "data/maps/DewfordTown_Hall/scripts.pory"
	step_end
# 256 "data/maps/DewfordTown_Hall/scripts.pory"

# 257 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SludgeBombMan:: @ 81FD7DA
# 258 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 259 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 260 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 261 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM36, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
# 262 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
# 263 "data/maps/DewfordTown_Hall/scripts.pory"
	giveitem ITEM_TM36_SLUDGE_BOMB
# 264 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_RESULT, FALSE
# 265 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 266 "data/maps/DewfordTown_Hall/scripts.pory"
	setflag FLAG_RECEIVED_TM36
# 267 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 268 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 269 "data/maps/DewfordTown_Hall/scripts.pory"

# 270 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ReceivedSludgeBomb:: @ 81FD80E
# 271 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
# 272 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 273 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 274 "data/maps/DewfordTown_Hall/scripts.pory"

# 275 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Trader:: @ 82162BB
# 276 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 277 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 278 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, DewfordTown_Hall_EventScript_TradeCompleted
# 279 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, INGAME_TRADE_TROPIUS
# 280 "data/maps/DewfordTown_Hall/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 281 "data/maps/DewfordTown_Hall/scripts.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 282 "data/maps/DewfordTown_Hall/scripts.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 283 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_YouWillTradeWontYou, MSGBOX_YESNO
# 284 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_RESULT, NO
# 285 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_DeclineTrade
# 286 "data/maps/DewfordTown_Hall/scripts.pory"
	special ChoosePartyMon
# 287 "data/maps/DewfordTown_Hall/scripts.pory"
	waitstate
# 288 "data/maps/DewfordTown_Hall/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 289 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_0x8004, 255
# 290 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq DewfordTown_Hall_EventScript_DeclineTrade
# 291 "data/maps/DewfordTown_Hall/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 292 "data/maps/DewfordTown_Hall/scripts.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 293 "data/maps/DewfordTown_Hall/scripts.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 294 "data/maps/DewfordTown_Hall/scripts.pory"
	compare VAR_RESULT, VAR_0x8009
# 295 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_ne DewfordTown_Hall_EventScript_NotRequestedMon
# 296 "data/maps/DewfordTown_Hall/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 297 "data/maps/DewfordTown_Hall/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 298 "data/maps/DewfordTown_Hall/scripts.pory"
	special CreateInGameTradePokemon
# 299 "data/maps/DewfordTown_Hall/scripts.pory"
	special DoInGameTradeScene
# 300 "data/maps/DewfordTown_Hall/scripts.pory"
	waitstate
# 301 "data/maps/DewfordTown_Hall/scripts.pory"
	bufferspeciesname 0, VAR_0x8009
# 302 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_MonYouTakeCare, MSGBOX_DEFAULT
# 303 "data/maps/DewfordTown_Hall/scripts.pory"
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
# 304 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 305 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 306 "data/maps/DewfordTown_Hall/scripts.pory"

# 307 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DeclineTrade:: @ 821633D
# 308 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_YouWontTradeMe, MSGBOX_DEFAULT
# 309 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 310 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 311 "data/maps/DewfordTown_Hall/scripts.pory"

# 312 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_NotRequestedMon:: @ 8216347
# 313 "data/maps/DewfordTown_Hall/scripts.pory"
	bufferspeciesname 0, VAR_0x8009
# 314 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_ThisIsntAMon, MSGBOX_DEFAULT
# 315 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 316 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 317 "data/maps/DewfordTown_Hall/scripts.pory"

# 318 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TradeCompleted:: @ 8216355
# 319 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
# 320 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 321 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 322 "data/maps/DewfordTown_Hall/scripts.pory"
	
# 323 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_YouWillTradeWontYou: @ 821637B
# 324 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wrooooaaar! I need it!\n"
# 325 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I have to get me a {STR_VAR_1}!\l"
# 326 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'll do anything for it!\p"
# 327 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "…Uh… Did you hear that?\n"
# 328 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "My shout from the bottom of my heart?\p"
# 329 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Having heard that, you will trade\n"
# 330 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "your {STR_VAR_1} for my {STR_VAR_2},\l"
# 331 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "won't you?$"
# 332 "data/maps/DewfordTown_Hall/scripts.pory"

# 333 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_MonYouTakeCare: @ 8216440
# 334 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, yeah, right on!\p"
# 335 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}, welcome!\n"
# 336 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_2}, you take care!$"
# 337 "data/maps/DewfordTown_Hall/scripts.pory"

# 338 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_ThisIsntAMon: @ 8216474
# 339 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Uh, no, I don't think so.\n"
# 340 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That isn't a {STR_VAR_1}.$"
# 341 "data/maps/DewfordTown_Hall/scripts.pory"

# 342 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_YouWontTradeMe: @ 821649F
# 343 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "No? You won't trade me?\n"
# 344 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Even after I bared my heart to you?$"
# 345 "data/maps/DewfordTown_Hall/scripts.pory"

# 346 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GoingToMakeVolbeatStrong: @ 82164DB
# 347 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm going to make Croagunk super\n"
# 348 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "strong from this moment on!\p"
# 349 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I hope you do the same with Tropius!$"
# 350 "data/maps/DewfordTown_Hall/scripts.pory"

# 351 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CantImagineLifeWithoutTrend: @ 81FD818
# 352 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 353 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 354 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I can't imagine what life would be like\n"
# 355 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "without “{STR_VAR_1}”!$"
# 356 "data/maps/DewfordTown_Hall/scripts.pory"

# 357 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GettingBoredOfTrend: @ 81FD877
# 358 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 359 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 360 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "But I'm getting kind of bored with it.\p"
# 361 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I should look for the next big thing.$"
# 362 "data/maps/DewfordTown_Hall/scripts.pory"

# 363 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TeachingMonAboutTrend: @ 81FD8ED
# 364 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm teaching my Pokémon about\n"
# 365 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1},”\l"
# 366 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "but it's not going well.\p"
# 367 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's a bit too much, I think.$"
# 368 "data/maps/DewfordTown_Hall/scripts.pory"

# 369 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_DeepLinkBetweenXAndY: @ 81FD948
# 370 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm studying up on the hip and trendy\n"
# 371 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” now.\p"
# 372 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is it true that there's a deep link\n"
# 373 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "between “{STR_VAR_1}”\l"
# 374 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "and “{STR_VAR_2}”?$"
# 375 "data/maps/DewfordTown_Hall/scripts.pory"

# 376 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_MyHunchWasRight: @ 81FD9B3
# 377 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 378 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "So, my hunch was right!\p"
# 379 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm one step closer to being hip and\n"
# 380 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "happening, yowza!$"
# 381 "data/maps/DewfordTown_Hall/scripts.pory"

# 382 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_NotEasyToKeepUp: @ 81FDA06
# 383 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What?!\n"
# 384 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is that so?!\p"
# 385 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's not easy for an older fellow like\n"
# 386 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "me to keep up with trends!$"
# 387 "data/maps/DewfordTown_Hall/scripts.pory"

# 388 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TVShowAboutTrend: @ 81FDA5C
# 389 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "This whole business about\n"
# 390 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\l"
# 391 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't there a TV show on it?$"
# 392 "data/maps/DewfordTown_Hall/scripts.pory"

# 393 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea: @ 81FDA99
# 394 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Across the sea…\p"
# 395 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is “{STR_VAR_1}”\n"
# 396 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "even more popular?$"
# 397 "data/maps/DewfordTown_Hall/scripts.pory"

# 398 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CollectTrendMerchandise: @ 81FDAC4
# 399 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I collect official\n"
# 400 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 401 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "licensed merchandise.\p"
# 402 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I have official\n"
# 403 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” Dolls…\p"
# 404 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Official “{STR_VAR_1}”\n"
# 405 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "brand clothing…\p"
# 406 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "And officially licensed\n"
# 407 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 408 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "picture books.\p"
# 409 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Heheh, I own!\n"
# 410 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm not sharing anything with you!$"
# 411 "data/maps/DewfordTown_Hall/scripts.pory"

# 412 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BooksAboutTrend: @ 81FDB89
# 413 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Identifying Good\n"
# 414 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” &\l"
# 415 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Bad “{STR_VAR_1}”…\p"
# 416 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "The Link Between\n"
# 417 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” AND\l"
# 418 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Pokémon…\p"
# 419 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Useful\n"
# 420 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\p"
# 421 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's neatly jammed with books about\n"
# 422 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 423 "data/maps/DewfordTown_Hall/scripts.pory"

# 424 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsScream: @ 81FDC05
# 425 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 426 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Scream” is the title.$"
# 427 "data/maps/DewfordTown_Hall/scripts.pory"

# 428 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsSmile: @ 81FDC21
# 429 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 430 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Smile” is the title.$"
# 431 "data/maps/DewfordTown_Hall/scripts.pory"

# 432 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LastTrend: @ 81FDC3C
# 433 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “The LAST\n"
# 434 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 435 "data/maps/DewfordTown_Hall/scripts.pory"

# 436 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BirthOfTrend: @ 81FDC57
# 437 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “The BIRTH OF\n"
# 438 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 439 "data/maps/DewfordTown_Hall/scripts.pory"

# 440 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_SawTrendCoolestThing: @ 81FDC76
# 441 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I saw “{STR_VAR_1}”!\n"
# 442 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Cool, huh?\p"
# 443 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's, like, the coolest thing going!\p"
# 444 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It was awesome!\n"
# 445 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It was the real thing, oh yeah!$"
# 446 "data/maps/DewfordTown_Hall/scripts.pory"

# 447 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_AllegedTrendNotAuthentic: @ 81FDCE2
# 448 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, no, no, no.\p"
# 449 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That alleged\n"
# 450 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 451 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "you claim to have seen--it's not.\p"
# 452 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "The authentic article is much…\n"
# 453 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "How should I say it?\l"
# 454 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Sharper, yet more mellow!\p"
# 455 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Ah, no matter. It's astonishing!$"
# 456 "data/maps/DewfordTown_Hall/scripts.pory"

# 457 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_ComposedTrendThemeSong: @ 81FDD95
# 458 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hey, listen, I composed a theme song\n"
# 459 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "for “{STR_VAR_1}.”\p"
# 460 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\n"
# 461 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "is really popular right now.\p"
# 462 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Okay, listen!\n"
# 463 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 464 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 465 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!\p"
# 466 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wonderful\n"
# 467 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!$"
# 468 "data/maps/DewfordTown_Hall/scripts.pory"

# 469 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WorkOnYourSinging: @ 81FDE0E
# 470 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 471 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I dare say, chap, it would pay for you\n"
# 472 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "to work on your singing before you\l"
# 473 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "trifle yourself with\l"
# 474 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 475 "data/maps/DewfordTown_Hall/scripts.pory"

# 476 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_OrganizeTrendParty: @ 81FDE77
# 477 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Anyway, as I was saying earlier, we\n"
# 478 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "should get together and organize a\l"
# 479 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” party\l"
# 480 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "on the island.$"
# 481 "data/maps/DewfordTown_Hall/scripts.pory"

# 482 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BrilliantIndeed: @ 81FDED8
# 483 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, a smashing good idea!\p"
# 484 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It will settle once and for all\n"
# 485 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "who is the best at\l"
# 486 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”\l"
# 487 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Brilliant, indeed!\p"
# 488 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Starting today, our lives will revolve\n"
# 489 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "around “{STR_VAR_1}”!$"
# 490 "data/maps/DewfordTown_Hall/scripts.pory"

# 491 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendHasBecomePartOfLife: @ 81FDF72
# 492 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I was thinking, though…\p"
# 493 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wouldn't you agree that\n"
# 494 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” has\l"
# 495 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "grown from being something trendy to\l"
# 496 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "being a part of our daily lives?$"
# 497 "data/maps/DewfordTown_Hall/scripts.pory"

# 498 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind: @ 81FDFF1
# 499 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Beg pardon?\n"
# 500 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That much, what?\p"
# 501 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "However, it's true that\n"
# 502 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 503 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "weighs heavily on your mind, whether\l"
# 504 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "you're awake or asleep.\p"
# 505 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Absolutely, you're the\n"
# 506 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 507 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Professor, old sport!$"
# 508 "data/maps/DewfordTown_Hall/scripts.pory"

# 509 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible: @ 81FE09A
# 510 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "If you and me team up as a combo,\n"
# 511 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "we'll be invincible when it comes to all\l"
# 512 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "things “{STR_VAR_1}”!$"
# 513 "data/maps/DewfordTown_Hall/scripts.pory"

# 514 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WellBeTrendDuo: @ 81FE0F2
# 515 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Spot on, my friend!\p"
# 516 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "We shall be the\n"
# 517 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” Duo!\p"
# 518 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't that a ripe image?\n"
# 519 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hahahah!$"
# 520 "data/maps/DewfordTown_Hall/scripts.pory"

# 521 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GiveYouSludgeBomb: @ 81FE142
# 522 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "For me, Sludge Bomb is at the peak\n"
# 523 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "of popularity. It's the one.\p"
# 524 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hunh? You're telling me that you don't\n"
# 525 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "know about Sludge Bomb?\p"
# 526 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That's outright pitiful.\n"
# 527 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'll give you one.$"
# 528 "data/maps/DewfordTown_Hall/scripts.pory"

# 529 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo: @ 81FE1ED
# 530 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I love Sludge Bomb.\p"
# 531 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "But Pokémon with the move\n"
# 532 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 533 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "are in, too.$"
