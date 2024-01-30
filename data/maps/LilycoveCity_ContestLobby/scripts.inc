# 1 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 2 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
@ Note: data/scripts/berry_blender.inc is for the same map, so shares local IDs
# 3 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
.set LOCALID_RECEPTIONIST, 1
# 4 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
.set LOCALID_LINK_RECEPTIONIST, 2
# 5 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
.set LOCALID_ARTIST, 4
# 6 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
.set LOCALID_ARTIST_LINK, 11
# 7 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 8 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_MapScripts:: @ 821A211
# 9 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_ContestLobby_OnTransition
# 10 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_ContestLobby_OnFrame
# 11 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.byte 0
# 12 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 13 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
@ Some scripts for this room are split into data/scripts/contest_hall and data/scripts/berry_blender
# 14 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 15 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_OnTransition: @ 821A21C
# 16 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_TryShowContestReporter
# 17 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster
# 18 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 19 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 20 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster:: @ 821A227
# 21 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	getpricereduction POKENEWS_BLENDMASTER
# 22 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 23 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_ShowBlendMaster
# 24 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
# 25 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
# 26 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 27 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 28 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowBlendMaster:: @ 821A23C
# 29 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
# 30 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
# 31 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 32 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 33 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_OnFrame: @ 821A243
# 34 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	map_script_2 VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1, LilycoveCity_ContestLobby_EventScript_TryDoContestArtist
# 35 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	map_script_2 VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2, LilycoveCity_ContestLobby_EventScript_TryDoLinkContestArtist
# 36 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.2byte 0
# 37 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 38 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryDoContestArtist:: @ 821A255
# 39 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, LilycoveCity_ContestLobby_EventScript_ContestArtist
# 40 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 41 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 42 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 43 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestArtist:: @ 821A264
# 44 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 45 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	addobject LOCALID_ARTIST
# 46 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer
# 47 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement LOCALID_ARTIST
# 48 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerFaceArtist
# 49 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 50 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
# 51 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 52 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 53 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_ARTIST
# 54 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 55 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
# 56 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, YES
# 57 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum
# 58 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, NO
# 59 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePainting
# 60 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 61 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 62 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 63 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum:: @ 821A2AA
# 64 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
# 65 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 66 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special SaveMuseumContestPainting
# 67 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 68 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_RESULT, GiveMonArtistRibbon
# 69 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 70 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_ReceivedArtistRibbon
# 71 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistExit
# 72 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 73 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	removeobject LOCALID_ARTIST
# 74 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons
# 75 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SetPaintingFlag
# 76 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 77 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 78 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 79 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePainting:: @ 821A2E4
# 80 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
# 81 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, YES
# 82 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum
# 83 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
# 84 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 85 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistExit
# 86 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 87 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 88 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	removeobject LOCALID_ARTIST
# 89 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 90 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 91 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 92 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ReceivedArtistRibbon:: @ 821A314
# 93 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
# 94 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special BufferContestWinnerMonName
# 95 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistBeginToExit
# 96 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 97 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_PIN
# 98 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, Common_Movement_ExclamationMark
# 99 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 100 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer
# 101 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 102 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
# 103 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 104 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
# 105 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitfanfare
# 106 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
# 107 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
# 108 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 109 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 110 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 111 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons:: @ 821A360
# 112 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 113 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_0x8004
# 114 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_ShowPatron1
# 115 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_ShowPatron2
# 116 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 3, LilycoveCity_ContestLobby_EventScript_ShowPatron3
# 117 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 4, LilycoveCity_ContestLobby_EventScript_ShowPatron4
# 118 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 5, LilycoveCity_ContestLobby_EventScript_ShowTourists
# 119 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 120 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 121 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowPatron1:: @ 821A3A2
# 122 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1
# 123 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 124 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 125 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowPatron2:: @ 821A3A6
# 126 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2
# 127 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 128 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 129 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowPatron3:: @ 821A3AA
# 130 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3
# 131 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 132 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 133 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowPatron4:: @ 821A3AE
# 134 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4
# 135 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 136 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 137 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ShowTourists:: @ 821A3B2
# 138 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS
# 139 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 140 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 141 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetPaintingFlag:: @ 821A3B6
# 142 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_CONTEST_CATEGORY
# 143 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_COOL, LilycoveCity_ContestLobby_EventScript_MadeCoolPainting
# 144 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_BEAUTY, LilycoveCity_ContestLobby_EventScript_MadeBeautyPainting
# 145 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_CUTE, LilycoveCity_ContestLobby_EventScript_MadeCutePainting
# 146 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_SMART, LilycoveCity_ContestLobby_EventScript_MadeSmartPainting
# 147 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_TOUGH, LilycoveCity_ContestLobby_EventScript_MadeToughPainting
# 148 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 149 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 150 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeCoolPainting:: @ 821A3F3
# 151 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_COOL_PAINTING_MADE
# 152 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 153 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 154 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeBeautyPainting:: @ 821A3F7
# 155 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_BEAUTY_PAINTING_MADE
# 156 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 157 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 158 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeCutePainting:: @ 821A3FB
# 159 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_CUTE_PAINTING_MADE
# 160 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 161 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 162 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeSmartPainting:: @ 821A3FF
# 163 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_SMART_PAINTING_MADE
# 164 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 165 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 166 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_MadeToughPainting:: @ 821A403
# 167 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_TOUGH_PAINTING_MADE
# 168 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 169 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 170 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer: @ 821A407
# 171 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 172 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 173 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 174 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 175 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 176 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 177 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 178 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 179 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 180 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ArtistExit: @ 821A40F
# 181 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 182 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 183 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 184 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 185 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 186 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 187 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 188 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 189 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 190 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 191 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerFaceArtist: @ 821A418
# 192 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_left
# 193 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 194 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 195 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ArtistBeginToExit: @ 821A41A
# 196 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 197 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 198 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 199 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 200 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 201 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer: @ 821A41E
# 202 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 203 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 204 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 205 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 206 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 207 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 208 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 209 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_right
# 210 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 211 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 212 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryDoLinkContestArtist:: @ 821A427
# 213 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, LilycoveCity_ContestLobby_EventScript_LinkContestArtist
# 214 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 215 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 216 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 217 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkContestArtist:: @ 821A436
# 218 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 219 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	addobject LOCALID_ARTIST_LINK
# 220 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer
# 221 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement LOCALID_ARTIST_LINK
# 222 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist
# 223 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 224 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
# 225 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 226 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 227 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_ARTIST
# 228 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
# 229 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, YES
# 230 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink
# 231 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, NO
# 232 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink
# 233 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 234 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 235 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink:: @ 821A47A
# 236 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
# 237 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 238 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special SaveMuseumContestPainting
# 239 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 240 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_RESULT, GiveMonArtistRibbon
# 241 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 242 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon
# 243 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistExit
# 244 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 245 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	removeobject LOCALID_ARTIST_LINK
# 246 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons
# 247 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SetPaintingFlag
# 248 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 249 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 250 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 251 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink:: @ 821A4B4
# 252 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
# 253 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, YES
# 254 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink
# 255 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
# 256 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 257 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistExit
# 258 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 259 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
# 260 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	removeobject LOCALID_ARTIST_LINK
# 261 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 262 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 263 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 264 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon:: @ 821A4E4
# 265 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
# 266 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_SYS_RIBBON_GET
# 267 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special BufferContestWinnerMonName
# 268 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit
# 269 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 270 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_PIN
# 271 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, Common_Movement_ExclamationMark
# 272 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 273 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_ARTIST_LINK, LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer
# 274 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 275 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
# 276 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 277 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
# 278 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitfanfare
# 279 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
# 280 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
# 281 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 282 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 283 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 284 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer: @ 821A533
# 285 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 286 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 287 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 288 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 289 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 290 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 291 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 292 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 293 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 294 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 295 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkArtistExit: @ 821A53C
# 296 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 297 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 298 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 299 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 300 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 301 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 302 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 303 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 304 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 305 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 306 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist: @ 821A545
# 307 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_right
# 308 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 309 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 310 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit: @ 821A547
# 311 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 312 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 313 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 314 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 315 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 316 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer: @ 821A54B
# 317 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 318 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 319 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 320 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_16
# 321 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 322 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 323 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_fast_up
# 324 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_left
# 325 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 326 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 327 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
@ EventScript_SpeakToContestReceptionist either ends or returns after a contest entry is submitted
# 328 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestReceptionist:: @ 821A554
# 329 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special ClearLinkContestFlags
# 330 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_RESULT, IsContestDebugActive  @ Always FALSE
# 331 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, TRUE
# 332 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SetDebug
# 333 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist
# 334 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_LeadToContestHall
# 335 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special SetContestTrainerGfxIds
# 336 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
# 337 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_SetContestType
# 338 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_WarpToContestHall
# 339 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 340 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 341 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 342 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetContestType:: @ 821A585
# 343 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_CONTEST_RANK
# 344 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_RANK_NORMAL, LilycoveCity_ContestLobby_EventScript_SetNormalContestType
# 345 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_RANK_SUPER, LilycoveCity_ContestLobby_EventScript_SetSuperContestType
# 346 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_RANK_HYPER, LilycoveCity_ContestLobby_EventScript_SetHyperContestType
# 347 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_RANK_MASTER, LilycoveCity_ContestLobby_EventScript_SetMasterContestType
# 348 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 349 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 350 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetNormalContestType:: @ 821A5B7
# 351 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
# 352 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 353 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 354 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetSuperContestType:: @ 821A5BD
# 355 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
# 356 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 357 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 358 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetHyperContestType:: @ 821A5C3
# 359 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER
# 360 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 361 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 362 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetMasterContestType:: @ 821A5C9
# 363 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER
# 364 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 365 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 366 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
@ Functionally unused
# 367 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetDebug:: @ 821A5CF
# 368 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR
# 369 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
# 370 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	additem ITEM_CONTEST_PASS
# 371 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x800B, 8
# 372 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
# 373 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
# 374 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_SYS_RIBBON_GET
# 375 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 376 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 377 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToContestHall:: @ 821A5EF
# 378 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setflag FLAG_ENTERED_CONTEST
# 379 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_CONTEST_CATEGORY
# 380 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_COOL, LilycoveCity_ContestLobby_EventScript_WarpToCoolContestHall
# 381 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_BEAUTY, LilycoveCity_ContestLobby_EventScript_WarpToBeautyContestHall
# 382 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_CUTE, LilycoveCity_ContestLobby_EventScript_WarpToCuteContestHall
# 383 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_SMART, LilycoveCity_ContestLobby_EventScript_WarpToSmartContestHall
# 384 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORY_TOUGH, LilycoveCity_ContestLobby_EventScript_WarpToToughContestHall
# 385 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 386 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 387 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToCoolContestHall:: @ 821A62F
# 388 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_COOL, 255, 7, 5
# 389 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 390 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 391 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 392 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 393 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToBeautyContestHall:: @ 821A63C
# 394 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_BEAUTY, 255, 7, 5
# 395 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 396 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 397 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 398 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 399 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToCuteContestHall:: @ 821A649
# 400 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_CUTE, 255, 7, 5
# 401 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 402 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 403 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 404 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 405 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToSmartContestHall:: @ 821A656
# 406 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_SMART, 255, 7, 5
# 407 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 408 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 409 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 410 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 411 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_WarpToToughContestHall:: @ 821A663
# 412 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setwarp MAP_CONTEST_HALL_TOUGH, 255, 7, 5
# 413 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DoContestHallWarp
# 414 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 415 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 416 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 417 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LeadToContestHall:: @ 821A670
# 418 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 419 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter
# 420 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 421 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_BRIDGE_WALK
# 422 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 12, 2, METATILE_Contest_WallShadow, 1
# 423 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 12, 3, METATILE_Contest_FloorShadow, 1
# 424 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DrawWholeMapView
# 425 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter
# 426 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 427 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_BRIDGE_WALK
# 428 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 12, 2, METATILE_Contest_CounterFlap_Top, 1
# 429 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 12, 3, METATILE_Contest_CounterFlap_Bottom, 1
# 430 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DrawWholeMapView
# 431 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay 20
# 432 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer
# 433 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 434 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist
# 435 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 436 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ComeThroughHere, MSGBOX_DEFAULT
# 437 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 438 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall
# 439 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall
# 440 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 441 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 442 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 443 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 444 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall: @ 821A6E8
# 445 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 446 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 447 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 448 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 449 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 450 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 451 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 452 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_8
# 453 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	set_invisible
# 454 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 455 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 456 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist: @ 821A6F2
# 457 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_left
# 458 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 459 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 460 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 461 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter: @ 821A6F5
# 462 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 463 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 464 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_down
# 465 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 466 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 467 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter: @ 821A6F9
# 468 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 469 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 470 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_up
# 471 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 472 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 473 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall: @ 821A6FD
# 474 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 475 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 476 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_left
# 477 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 478 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 479 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 480 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_8
# 481 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	set_invisible
# 482 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 483 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 484 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer: @ 821A706
# 485 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_right
# 486 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 487 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 488 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlackBelt:: @ 821A708
# 489 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MasterRankHereICome, MSGBOX_NPC
# 490 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 491 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 492 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Girl:: @ 821A711
# 493 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere, MSGBOX_NPC
# 494 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 495 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 496 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Artist:: @ 821A71A
# 497 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ContestFeastForEyes, MSGBOX_NPC
# 498 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 499 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 500 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_FatMan:: @ 821A723
# 501 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ToughContestIsExtreme, MSGBOX_NPC
# 502 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 503 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 504 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Fisherman:: @ 821A72C
# 505 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_LavishedCareOnMon, MSGBOX_NPC
# 506 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 507 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 508 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_NinjaBoy:: @ 821A735
# 509 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily, MSGBOX_NPC
# 510 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 511 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 512 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner1:: @ 821A73E
# 513 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 514 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 515 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_1
# 516 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 517 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 518 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 519 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner2:: @ 821A745
# 520 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 521 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 522 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_2
# 523 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 524 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 525 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 526 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner3:: @ 821A74C
# 527 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 528 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 529 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_3
# 530 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 531 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 532 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 533 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner4:: @ 821A753
# 534 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 535 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 536 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_4
# 537 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 538 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 539 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 540 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner5:: @ 821A75A
# 541 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 542 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 543 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_5
# 544 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 545 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 546 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 547 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ContestWinner6:: @ 821A761
# 548 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 549 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 550 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	showcontestpainting CONTEST_WINNER_HALL_6
# 551 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 552 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 553 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 554 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Blender3Boy:: @ 821A768
# 555 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_LetsGetBlendingAlready, MSGBOX_NPC
# 556 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 557 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 558 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_Blender3Girl:: @ 821A771
# 559 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_WhatKindOfPokeblockWillIGet, MSGBOX_NPC
# 560 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 561 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 562 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BerryBlenderSpeedRecords:: @ 821A77A
# 563 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 564 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special ShowBerryBlenderRecordWindow
# 565 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitbuttonpress
# 566 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special RemoveRecordsWindow
# 567 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 568 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 569 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 570 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkContestResults:: @ 821A784
# 571 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 572 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	frontier_results FACILITY_LINK_CONTEST
# 573 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitbuttonpress
# 574 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special RemoveRecordsWindow
# 575 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
# 576 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 577 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 578 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMaster:: @ 821A798
# 579 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 580 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 581 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_BlendWithTheBlendMaster, MSGBOX_DEFAULT
# 582 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
# 583 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 584 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 585 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker1:: @ 821A7A8
# 586 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 587 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_WhoaAwesome, MSGBOX_DEFAULT
# 588 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 589 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 590 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 591 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker2:: @ 821A7B3
# 592 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 593 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_WickedlyFast, MSGBOX_DEFAULT
# 594 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 595 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 596 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 597 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker3:: @ 821A7BE
# 598 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 599 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_WhatAnExpert, MSGBOX_DEFAULT
# 600 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 601 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 602 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 603 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker4:: @ 821A7C9
# 604 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 605 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 606 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_MadeAmazingPokeblocksWithMaster, MSGBOX_DEFAULT
# 607 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
# 608 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 609 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 610 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker5:: @ 821A7D9
# 611 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 612 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 613 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_QualitiesOfBlendMaster, MSGBOX_DEFAULT
# 614 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
# 615 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 616 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 617 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker6:: @ 821A7E9
# 618 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 619 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 620 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox BerryBlender_Text_MasterWorksOnSkillsInMountains, MSGBOX_DEFAULT
# 621 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
# 622 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 623 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 624 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection:: @ 821A7F9
# 625 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 626 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 627 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 628 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 629 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 630 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 631 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkContestReceptionist:: @ 821A806
# 632 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special ClearLinkContestFlags
# 633 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 634 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 635 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_LinkContestReception, MSGBOX_DEFAULT
# 636 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
# 637 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 638 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 639 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest:: @ 821A819
# 640 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_EnterContest3
# 641 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 642 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 0, 0, MULTI_ENTERINFO, FALSE
# 643 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 644 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_TryEnterLinkContest
# 645 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_LinkContestInfo
# 646 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 647 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 648 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 649 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 650 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryEnterLinkContest:: @ 821A856
# 651 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ProgressWillBeSaved, MSGBOX_YESNO
# 652 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, NO
# 653 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 654 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call Common_EventScript_SaveGame
# 655 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, FALSE
# 656 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 657 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_WhichContestMode
# 658 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 659 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	specialvar VAR_TEMP_D, IsWirelessAdapterConnected
# 660 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 0, 0, MULTI_LINK_CONTEST_MODE, FALSE
# 661 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 662 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_EmeraldMode  @ Shortened to E-Mode
# 663 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_GlobalMode   @ Shortened to G-Mode
# 664 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 665 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 666 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 667 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 668 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_EmeraldMode:: @ 821A8BB
# 669 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_TEMP_C, 0
# 670 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType
# 671 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 672 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 673 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_GlobalMode:: @ 821A8C6
# 674 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_TEMP_C, 1
# 675 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_TEMP_D, 1
# 676 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode
# 677 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType
# 678 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 679 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 680 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType:: @ 821A8DC
# 681 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_EnterWhichContest3
# 682 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 683 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 0, 0, MULTI_CONTEST_TYPE, FALSE
# 684 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 685 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case CONTEST_CATEGORIES_COUNT, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 686 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 687 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
# 688 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
# 689 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 690 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 691 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkContestInfo:: @ 821A90D
# 692 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_WhichTopic2
# 693 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 694 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 0, 0, MULTI_LINK_CONTEST_INFO, FALSE
# 695 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 696 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainLinkContest
# 697 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainEMode
# 698 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainGMode
# 699 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
# 700 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
# 701 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 702 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 703 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ExplainLinkContest:: @ 821A955
# 704 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainLinkContest, MSGBOX_DEFAULT
# 705 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
# 706 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 707 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 708 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ExplainEMode:: @ 821A963
# 709 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainEMode, MSGBOX_DEFAULT
# 710 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
# 711 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 712 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 713 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ExplainGMode:: @ 821A971
# 714 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainGMode, MSGBOX_DEFAULT
# 715 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
# 716 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 717 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 718 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkContest:: @ 821A97F
# 719 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special CloseLink
# 720 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
# 721 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 722 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 723 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 724 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon:: @ 821A98C
# 725 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_EnterWhichPokemon3, MSGBOX_DEFAULT
# 726 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_RANK, 0
# 727 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	choosecontestmon
# 728 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_0x8004, 255
# 729 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 730 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryEnterContestMon
# 731 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, CANT_ENTER_CONTEST
# 732 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkCantEnterLowRank
# 733 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK
# 734 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest
# 735 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK
# 736 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest
# 737 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, CANT_ENTER_CONTEST_EGG
# 738 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkCantEnterEgg
# 739 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, CANT_ENTER_CONTEST_FAINTED
# 740 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkCantEnterFainted
# 741 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 742 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 743 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkCantEnterLowRank:: @ 821A9E0
# 744 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
# 745 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
# 746 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 747 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 748 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkCantEnterEgg:: @ 821A9EE
# 749 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart2, MSGBOX_DEFAULT
# 750 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
# 751 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 752 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 753 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkCantEnterFainted:: @ 821A9FC
# 754 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MonInNoCondition2, MSGBOX_DEFAULT
# 755 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
# 756 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 757 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 758 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest:: @ 821AA0A
# 759 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8004
# 760 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_TrySetUpLinkContest
# 761 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 762 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 763 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TrySetUpLinkContest:: @ 821AA15
# 764 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_TEMP_D, 1
# 765 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupType
# 766 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_TEMP_D, 2
# 767 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_ge LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 768 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel
# 769 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 770 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 771 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_TEMP_C, 0
# 772 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_TryLinkEMode
# 773 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_TEMP_C, 1
# 774 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_TryLinkGMode
# 775 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_TEMP_C, 2
# 776 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_ge LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 777 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
# 778 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices
# 779 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
# 780 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices
# 781 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 782 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 783 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
# 784 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkError
# 785 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED_CONTEST_GMODE
# 786 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelLinkModeDifference
# 787 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageinstant LilycoveCity_ContestLobby_Text_Transmitting
# 788 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	contestlinktransfer
# 789 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_0x8004
# 790 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_StartLinkContest
# 791 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentContest
# 792 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkTransmissionError
# 793 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 794 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 795 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryLinkEMode:: @ 821AABB
# 796 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryContestEModeLinkup
# 797 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 798 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 799 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 800 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryLinkGMode:: @ 821AAC0
# 801 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryContestGModeLinkup
# 802 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 803 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 804 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 805 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentContest:: @ 821AAC5
# 806 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest, MSGBOX_DEFAULT
# 807 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 808 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 809 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 810 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices:: @ 821AAD3
# 811 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice, MSGBOX_DEFAULT
# 812 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 813 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 814 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 815 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkModeDifference:: @ 821AAE1
# 816 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode, MSGBOX_DEFAULT
# 817 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 818 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 819 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 820 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkError:: @ 821AAEF
# 821 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special CloseLink
# 822 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
# 823 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 824 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 825 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 826 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode:: @ 821AAFC
# 827 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special CloseLink
# 828 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode, MSGBOX_DEFAULT
# 829 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 830 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 831 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 832 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_CancelLinkTransmissionError:: @ 821AB09
# 833 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_TransmissionError, MSGBOX_DEFAULT
# 834 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 835 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 836 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 837 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_StartLinkContest:: @ 821AB17
# 838 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special GetContestPlayerId
# 839 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	addvar VAR_0x8004, 1
# 840 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	buffernumberstring 1, VAR_0x8004
# 841 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageautoscroll LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX
# 842 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 843 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	subvar VAR_0x8004, 1
# 844 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_LeadToLinkContestHall
# 845 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 1
# 846 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special SetLinkContestPlayerGfx
# 847 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 848 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
# 849 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_WarpToContestHall
# 850 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 851 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 852 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupType:: @ 821AB4B
# 853 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_COOL
# 854 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupCoolContest
# 855 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_BEAUTY
# 856 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupBeautyContest
# 857 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_CUTE
# 858 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupCuteContest
# 859 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_SMART
# 860 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupSmartContest
# 861 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_TOUGH
# 862 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call_if_eq LilycoveCity_ContestLobby_EventScript_SetLinkGroupToughContest
# 863 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
# 864 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 865 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 866 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupCoolContest:: @ 821AB88
# 867 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_COOL_CONTEST
# 868 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 869 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 870 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupBeautyContest:: @ 821AB8E
# 871 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_BEAUTY_CONTEST
# 872 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 873 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 874 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupCuteContest:: @ 821AB94
# 875 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_CUTE_CONTEST
# 876 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 877 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 878 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupSmartContest:: @ 821AB9A
# 879 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_SMART_CONTEST
# 880 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 881 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 882 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_SetLinkGroupToughContest:: @ 821ABA0
# 883 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setvar VAR_0x8004, LINK_GROUP_TOUGH_CONTEST
# 884 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 885 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 886 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_DecideLinkLeader:: @ 821ABA6
# 887 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	message LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader
# 888 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 889 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
# 890 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 891 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_TryJoinGroup
# 892 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_TryLeadGroup
# 893 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 894 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
# 895 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 896 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 897 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryLeadGroup:: @ 821ABE3
# 898 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_TryBecomeLinkLeader
# 899 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 900 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided
# 901 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 902 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
# 903 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 904 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TryLeadGroup
# 905 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 906 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 907 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 908 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryJoinGroup:: @ 821AC0B
# 909 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_TryJoinLinkGroup
# 910 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 911 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided
# 912 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 913 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
# 914 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 915 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_TryJoinGroup
# 916 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 917 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 918 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 919 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryBecomeLinkLeader:: @ 821AC33
# 920 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryBecomeLinkLeader
# 921 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 922 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 923 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 924 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_TryJoinLinkGroup:: @ 821AC38
# 925 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special TryJoinLinkGroup
# 926 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitstate
# 927 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 928 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 929 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided:: @ 821AC3D
# 930 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageinstant LilycoveCity_ContestLobby_Text_Transmitting
# 931 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	contestlinktransfer
# 932 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto LilycoveCity_ContestLobby_EventScript_StartLinkContest
# 933 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 934 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 935 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LeadToLinkContestHall:: @ 821AC49
# 936 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageautoscroll LilycoveCity_ContestLobby_Text_ContestBeginShortly
# 937 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 938 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay 20
# 939 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 940 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter
# 941 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 942 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_BRIDGE_WALK
# 943 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 17, 2, METATILE_Contest_WallShadow, 1
# 944 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 17, 3, METATILE_Contest_FloorShadow, 1
# 945 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DrawWholeMapView
# 946 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter
# 947 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 948 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playse SE_BRIDGE_WALK
# 949 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 17, 2, METATILE_Contest_CounterFlap_Top, 1
# 950 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	setmetatile 17, 3, METATILE_Contest_CounterFlap_Bottom, 1
# 951 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	special DrawWholeMapView
# 952 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay 20
# 953 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer
# 954 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 955 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist
# 956 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 957 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	messageautoscroll LilycoveCity_ContestLobby_Text_ComeThroughHere
# 958 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmessage
# 959 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay 20
# 960 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	closemessage
# 961 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	call LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer
# 962 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement LOCALID_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall
# 963 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall
# 964 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitmovement 0
# 965 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 966 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	return
# 967 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 968 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall: @ 821ACD0
# 969 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 970 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 971 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 972 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 973 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 974 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 975 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 976 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 977 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_8
# 978 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	set_invisible
# 979 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 980 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 981 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist: @ 821ACDB
# 982 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 983 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 984 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 985 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter: @ 821ACDD
# 986 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 987 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 988 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_down
# 989 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 990 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 991 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter: @ 821ACE1
# 992 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 993 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_down
# 994 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_up
# 995 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 996 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 997 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall: @ 821ACE5
# 998 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 999 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 1000 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 1001 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_right
# 1002 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 1003 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 1004 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_up
# 1005 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	delay_8
# 1006 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	set_invisible
# 1007 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 1008 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1009 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer: @ 821ACEF
# 1010 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	walk_in_place_fastest_left
# 1011 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	step_end
# 1012 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1013 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LittleGirl:: @ 821ACF1
# 1014 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lock
# 1015 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 1016 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase
# 1017 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase, MSGBOX_DEFAULT
# 1018 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 1019 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 1020 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1021 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase:: @ 821AD06
# 1022 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries, MSGBOX_DEFAULT
# 1023 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	release
# 1024 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	end
# 1025 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1026 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase: @ 821AD10
# 1027 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Yippee!\p"
# 1028 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "The lady at the reception counter\n"
# 1029 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "gave me a case for {POKEBLOCK}s!$"
# 1030 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1031 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries: @ 821AD55
# 1032 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Make {POKEBLOCK}S and put them in there.\p"
# 1033 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "When you make a {POKEBLOCK}, everyone\n"
# 1034 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "has to put in a different Berry.$"
# 1035 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1036 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint: @ 821ADB9
# 1037 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Congratulations!\p"
# 1038 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I did a painting of your Pokémon to\n"
# 1039 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "commemorate its victory…\p"
# 1040 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Well, your Pokémon's appeals were\n"
# 1041 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "so fantastic, it spurred me into\l"
# 1042 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "painting better than I usually do.\l"
# 1043 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Look, see?$"
# 1044 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1045 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum: @ 821AE78
# 1046 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "What do you think? I'm confident in\n"
# 1047 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "what I've done, but do you like it?\p"
# 1048 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "A work of this caliber, it wouldn't look\n"
# 1049 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "out of place in an art museum.\p"
# 1050 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Huh? An art museum really is looking\n"
# 1051 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "for paintings?\p"
# 1052 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Do you think I should take this there?$"
# 1053 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1054 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum: @ 821AF63
# 1055 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "What, really? Then, sure, I will take\n"
# 1056 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "this painting there right now.\p"
# 1057 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I'll give it a proper title, too.\p"
# 1058 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I hope they'll like it and consider\n"
# 1059 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "exhibiting this.\p"
# 1060 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Please check if they did accept this.\n"
# 1061 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Thank you!$"
# 1062 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1063 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_TakeMementoOfPainting: @ 821B030
# 1064 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Oh, that's right!\p"
# 1065 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "As a memento of me painting your\n"
# 1066 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Pokémon, please take this.$"
# 1067 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1068 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_ReceivedARibbon: @ 821B07E
# 1069 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{PLAYER} received a Ribbon.$"
# 1070 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1071 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon: @ 821B094
# 1072 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{PLAYER} put the Ribbon on\n"
# 1073 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{STR_VAR_1}.$"
# 1074 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1075 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_OkaySeeYou: @ 821B0AD
# 1076 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Okay, see you!$"
# 1077 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1078 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum: @ 821B0BC
# 1079 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Oh… Then, I guess I'll just take\n"
# 1080 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "this home with me…\p"
# 1081 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "But, you know, I would like to take\n"
# 1082 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "this to the art museum… Okay?$"
# 1083 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1084 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs: @ 821B132
# 1085 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Oh, fine, that's the way it is.\n"
# 1086 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I will hang this in my own house.\p"
# 1087 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I'll just have to try harder next time.\n"
# 1088 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Well, be seeing you.$"
# 1089 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1090 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_MasterRankHereICome: @ 821B1B1
# 1091 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Hoo, boy… Master Rank Contests,\n"
# 1092 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "here I come.\p"
# 1093 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "The world will know that my dearest\n"
# 1094 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Pokémon is the cutest being in all\l"
# 1095 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "existence. The time has come!\l"
# 1096 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Uheheheh.$"
# 1097 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1098 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere: @ 821B24D
# 1099 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "You can see a whole variety of\n"
# 1100 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Pokémon here.\p"
# 1101 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "That's why I make this place a regular\n"
# 1102 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "part of my daily stroll.$"
# 1103 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1104 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_ContestFeastForEyes: @ 821B2BA
# 1105 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Wow, coming out to a Contest is\n"
# 1106 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "a feast for these eyes!\p"
# 1107 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Would you look at all the Pokémon\n"
# 1108 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "that just scream to be painted?$"
# 1109 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1110 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_ToughContestIsExtreme: @ 821B334
# 1111 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "The Toughness Contest is like\n"
# 1112 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "extreme, man!\p"
# 1113 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Those muscular appeals…\n"
# 1114 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Cascading sweat… I swoon!$"
# 1115 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1116 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_LavishedCareOnMon: @ 821B392
# 1117 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Day in and day out, I lavished my care\n"
# 1118 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "on this Pokémon.\p"
# 1119 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Its condition is peaking.\n"
# 1120 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Today, victory is mine!$"
# 1121 "data/maps/LilycoveCity_ContestLobby/scripts.pory"

# 1122 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily: @ 821B3FC
# 1123 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I made {POKEBLOCK}S with Mom, Dad, and\n"
# 1124 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Big Sister. They turned out great!\p"
# 1125 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I bet you can make smoother, better\n"
# 1126 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{POKEBLOCK}s if you have more people.$"

LilycoveCity_ContestLobby_EventScript_BrokenMachine::
# 1130 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 1131 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_BrokenMachine_Text_0, MSGBOX_DEFAULT
# 1132 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
	end


LilycoveCity_ContestLobby_EventScript_PokeblockManiac::
# 1137 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 1138 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 1139 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_0, MSGBOX_YESNO
# 1140 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	switch VAR_RESULT
# 1141 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case NO, LilycoveCity_ContestLobby_EventScript_PokeblockManiac_3
# 1144 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	case YES, LilycoveCity_ContestLobby_EventScript_PokeblockManiac_4
LilycoveCity_ContestLobby_EventScript_PokeblockManiac_1:
# 1152 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_PokeblockManiac_3:
# 1142 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_1, MSGBOX_NPC
	goto LilycoveCity_ContestLobby_EventScript_PokeblockManiac_1

LilycoveCity_ContestLobby_EventScript_PokeblockManiac_4:
# 1145 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_2, MSGBOX_NPC
# 1146 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1147 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_3, MSGBOX_NPC
# 1148 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	waitfanfare
# 1149 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_4, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_PokeblockManiac_1


LilycoveCity_ContestLobby_EventScript_PokeblockManiac2::
# 1157 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 1158 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 1159 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_PokeblockManiac2_Text_0, MSGBOX_NPC
# 1160 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
	end


LilycoveCity_ContestLobby_EventScript_Pokeblock_Machine_Broken_Girl::
# 1165 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 1166 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 1167 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_Pokeblock_Machine_Broken_Girl_Text_0, MSGBOX_NPC
# 1168 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
	end


LilycoveCity_ContestLobby_EventScript_Pokeblock_Machine_Broken_Scientist::
# 1173 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	faceplayer
# 1174 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	lockall
# 1175 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	msgbox LilycoveCity_ContestLobby_EventScript_Pokeblock_Machine_Broken_Scientist_Text_0, MSGBOX_NPC
# 1176 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	releaseall
	end


LilycoveCity_ContestLobby_EventScript_BrokenMachine_Text_0:
# 1131 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "It looks like the machine is broken, it's\n"
	.string "probably better to leave it as is.$"

LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_0:
# 1139 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I played a lot with this {POKEBLOCK} machine\n"
	.string "and I broke it so nobody can play, but\l"
	.string "now I have a lot of {POKEBLOCK}s, do you want\l"
	.string "some?.$"

LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_1:
# 1142 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "More for me I guess.$"

LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_2:
# 1145 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "Take them all!$"

LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_3:
# 1147 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "{PLAYER} obtained a lot of {POKEBLOCK}s.$"

LilycoveCity_ContestLobby_EventScript_PokeblockManiac_Text_4:
# 1149 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "If you need more of them please tell me.$"

LilycoveCity_ContestLobby_EventScript_PokeblockManiac2_Text_0:
# 1159 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "I played a lot with this {POKEBLOCK} machine\n"
	.string "and I broke it so nobody can play now...$"

LilycoveCity_ContestLobby_EventScript_Pokeblock_Machine_Broken_Girl_Text_0:
# 1167 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "My dumb brother broke every machine\n"
	.string "here and now I can't play.$"

LilycoveCity_ContestLobby_EventScript_Pokeblock_Machine_Broken_Scientist_Text_0:
# 1175 "data/maps/LilycoveCity_ContestLobby/scripts.pory"
	.string "We are trying to fix these broken\n"
	.string "machines.$"
