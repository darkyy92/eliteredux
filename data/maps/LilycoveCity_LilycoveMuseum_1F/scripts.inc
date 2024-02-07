# 1 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
.set LOCALID_CURATOR, 2
# 3 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
.set LOCALID_ARTIST_2, 8
# 4 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 5 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_MapScripts:: @ 8218CB8
# 6 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.byte 0
# 7 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 8 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter:: @ 8218CB9
# 9 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
# 10 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 11 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 12 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Curator:: @ 8218CC2
# 13 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 14 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
# 15 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
# 16 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmessage
# 17 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
# 18 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	compare VAR_RESULT, 0
# 19 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
# 20 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	compare VAR_RESULT, 1
# 21 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
# 22 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 23 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 24 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet:: @ 8218CEC
# 25 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
# 26 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 27 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 28 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings:: @ 8218CF5
# 29 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
# 30 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	compare VAR_RESULT, NO
# 31 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
# 32 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	compare VAR_RESULT, YES
# 33 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
# 34 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 35 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 36 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested:: @ 8218D14
# 37 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
# 38 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	releaseall
# 39 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 40 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 41 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings:: @ 8218D1E
# 42 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
# 43 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
# 44 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 45 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	removeobject LOCALID_CURATOR
# 46 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	switch VAR_FACING
# 47 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
# 48 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
# 49 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
# 50 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 51 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 52 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth:: @ 8218D5A
# 53 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 54 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
# 55 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 56 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
# 57 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 58 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 59 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 60 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest:: @ 8218D6F
# 61 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 62 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
# 63 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 64 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
# 65 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 66 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 67 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 68 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast:: @ 8218D84
# 69 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lockall
# 70 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
# 71 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 72 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
# 73 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitstate
# 74 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 75 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 76 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs: @ 8218D99
# 77 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 78 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 79 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 80 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest: @ 8218D9B
# 81 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_left
# 82 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 83 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 84 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 85 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast: @ 8218D9E
# 86 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_right
# 87 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 88 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 89 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 90 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth: @ 8218DA1
# 91 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 92 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	walk_up
# 93 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	step_end
# 94 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 95 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting:: @ 8218DA4
# 96 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
# 97 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 98 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 99 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting:: @ 8218DAD
# 100 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
# 101 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 102 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 103 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting:: @ 8218DB6
# 104 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
# 105 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 106 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 107 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting:: @ 8218DBF
# 108 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
# 109 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 110 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 111 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting:: @ 8218DC8
# 112 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
# 113 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 114 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 115 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting:: @ 8218DD1
# 116 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
# 117 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 118 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 119 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture:: @ 8218DDA
# 120 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
# 121 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 122 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 123 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture:: @ 8218DE3
# 124 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
# 125 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 126 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 127 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet:: @ 8218DEC
# 128 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
# 129 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 130 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 131 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM:: @ 8218DF5
# 132 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
# 133 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 134 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 135 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1:: @ 8218DFE
# 136 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
# 137 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 138 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 139 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy:: @ 8218E07
# 140 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
# 141 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 142 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 143 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1:: @ 8218E10
# 144 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
# 145 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 146 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 147 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2:: @ 8218E19
# 148 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
# 149 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 150 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 151 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM:: @ 8218E22
# 152 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
# 153 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 154 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 155 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2:: @ 8218E2B
# 156 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	lock
# 157 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	faceplayer
# 158 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
# 159 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	closemessage
# 160 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	applymovement LOCALID_ARTIST_2, Common_Movement_FaceOriginalDirection
# 161 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	waitmovement 0
# 162 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	release
# 163 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 164 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 165 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan:: @ 8218E42
# 166 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
# 167 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	end
# 168 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 169 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum: @ 8218E4B
# 170 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Welcome to Lilycove Museum.\p"
# 171 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Please take the time to enjoy our\n"
# 172 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "collection of fantastic artwork\l"
# 173 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "featuring Pokémon.$"
# 174 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 175 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings: @ 8218EBC
# 176 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'm the Curator of this Museum of\n"
# 177 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "fine arts.\p"
# 178 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's heartening to see someone so\n"
# 179 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "young as you in our Museum.\p"
# 180 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Have you viewed our collection of\n"
# 181 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "paintings already?$"
# 182 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 183 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime: @ 8218F5C
# 184 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Ah, then let me not disturb you.\n"
# 185 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Please, do take your time.$"
# 186 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 187 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings: @ 8218F98
# 188 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Oh? I do believe that you seem to\n"
# 189 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "be a Pokémon Trainer.\p"
# 190 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Have you an interest in paintings,\n"
# 191 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "too?$"
# 192 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 193 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat: @ 8218FF8
# 194 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I see…\p"
# 195 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'm honored that you would visit\n"
# 196 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "us in spite of that.$"
# 197 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 198 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe: @ 8219035
# 199 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Ah, excellent!\n"
# 200 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "You do like paintings!\p"
# 201 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Then, may I ask you to come with me?$"
# 202 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 203 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting: @ 8219080
# 204 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a very old painting.\n"
# 205 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The paint is peeling here and there.$"
# 206 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 207 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery: @ 82190BF
# 208 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's an odd landscape with bizarre\n"
# 209 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "and fantastic scenery.$"
# 210 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 211 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman: @ 82190F9
# 212 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of a beautiful, smiling\n"
# 213 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "woman with a Pokémon on her lap.$"
# 214 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 215 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon: @ 8219142
# 216 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of a legendary Pokémon\n"
# 217 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "from long ago.\p"
# 218 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The artist painted this from\n"
# 219 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "imagination.$"
# 220 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 221 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon: @ 82191A2
# 222 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a painting of Grass Pokémon\n"
# 223 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "swaying in a breeze.\p"
# 224 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "They appear to be enjoying the wind's\n"
# 225 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "gentle caress.$"
# 226 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 227 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries: @ 821920D
# 228 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a delicious-looking painting\n"
# 229 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "of Berries.\p"
# 230 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This painting could make you hungry!$"
# 231 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 232 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica: @ 8219260
# 233 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a replica of a famous sculpture.\p"
# 234 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It depicts an ancient Bird Pokémon.$"
# 235 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 236 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone: @ 82192AA
# 237 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a big Poké Ball carved from\n"
# 238 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "a black stone.\p"
# 239 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It was apparently used in festivals\n"
# 240 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "in the olden days.$"
# 241 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 242 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText: @ 8219311
# 243 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's a huge stone tablet inscribed\n"
# 244 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "with Pokémon and dense text in the\l"
# 245 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "small characters of an ancient,\l"
# 246 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "unreadable language.$"
# 247 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 248 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence: @ 821938C
# 249 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Hmmm…\n"
# 250 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "What works of great magnificence…$"
# 251 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 252 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts: @ 82193B4
# 253 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Battling with Pokémon is fun,\n"
# 254 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'll grant you that.\p"
# 255 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "But one mustn't forget our love for\n"
# 256 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "the fine arts.$"
# 257 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 258 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration: @ 821941A
# 259 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This artists Museum… Well, you could\n"
# 260 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "see many fantastic paintings.\p"
# 261 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "And the Curator is a wonderful person.\p"
# 262 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Among artists like myself, this Museum\n"
# 263 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "is an inspiration.$"
# 264 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 265 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty: @ 82194BA
# 266 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This lady is pretty!\n"
# 267 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "She's like Mommy!$"
# 268 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 269 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable: @ 82194E1
# 270 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This Pokémon is adorable!\n"
# 271 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Just like our little boy!$"
# 272 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 273 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings: @ 8219515
# 274 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I'd heard that this Art Museum got\n"
# 275 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "in some new paintings.\p"
# 276 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "So, naturally I hurried over.\p"
# 277 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Are the new paintings up on\n"
# 278 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "the second floor?$"
# 279 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 280 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful: @ 821959B
# 281 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Lately, the Curator has been\n"
# 282 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "unusually cheerful.\p"
# 283 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I bet something good happened for him.\n"
# 284 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "Definitely.$"
# 285 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 286 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings: @ 82195FF
# 287 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I aim to see many great paintings\n"
# 288 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "here and learn from them.\p"
# 289 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "I have this dream of one day having\n"
# 290 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "my artwork exhibited here.$"
# 291 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"

# 292 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination: @ 821967A
# 293 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "The Art Museum has become a favorite\n"
# 294 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "tourist destination.\p"
# 295 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "It's great for Lilycove…\n"
# 296 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "No, great for the Hoenn region!\p"
# 297 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "This is what I've heard--a lone Trainer\n"
# 298 "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.pory"
	.string "procured all the paintings upstairs.$"
