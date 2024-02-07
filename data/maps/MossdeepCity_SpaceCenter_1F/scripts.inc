# 1 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 2 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_SCIENTIST_1, 1
# 3 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_SCIENTIST_2, 2
# 4 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_SAILOR, 3
# 5 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_OLD_MAN, 4
# 6 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_WOMAN, 5
# 7 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
.set LOCALID_STAIR_GRUNT, 9
# 8 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 9 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_MapScripts:: @ 8222F41
# 10 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
# 11 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
# 12 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.byte 0
# 13 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 14 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_OnTransition: @ 8222F4C
# 15 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 16 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
# 17 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 18 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 19 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma:: @ 8222F58
# 20 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SAILOR, 1, 9
# 21 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
# 22 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_WOMAN, 0, 8
# 23 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
# 24 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_OLD_MAN, 1, 6
# 25 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
# 26 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST_1, 3, 4
# 27 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
# 28 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
# 29 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
# 30 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
# 31 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
# 32 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
# 33 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
# 34 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
# 35 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 36 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 37 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft:: @ 8222FAA
# 38 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_STAIR_GRUNT, 12, 2
# 39 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 40 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 41 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown:: @ 8222FB2
# 42 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_STAIR_GRUNT, 13, 3
# 43 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 44 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 45 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 46 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight:: @ 8222FBA
# 47 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setobjectxyperm LOCALID_STAIR_GRUNT, 14, 2
# 48 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 49 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 50 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_OnLoad: @ 8222FC2
# 51 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 52 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_le MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
# 53 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 54 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 55 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote:: @ 8222FCE
# 56 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setmetatile 2, 5, METATILE_Facility_DataPad, 1
# 57 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 58 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 59 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter:: @ 8222FD8
# 60 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 61 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 62 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 63 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
# 64 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	dotimebasedevents
# 65 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	specialvar VAR_RESULT, GetWeekCount
# 66 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	buffernumberstring 0, VAR_RESULT
# 67 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
# 68 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
# 69 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
# 70 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
# 71 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 72 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 73 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 74 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 75 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 76 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 77 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet:: @ 8223012
# 78 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
# 79 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 80 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 81 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber:: @ 822301B
# 82 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
# 83 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 84 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 85 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma:: @ 8223024
# 86 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	dotimebasedevents
# 87 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	specialvar VAR_RESULT, GetWeekCount
# 88 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	buffernumberstring 0, VAR_RESULT
# 89 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_RESULT, 0
# 90 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_eq MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
# 91 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_RESULT, 1
# 92 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	call_if_ge MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
# 93 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 94 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
# 95 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 96 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 97 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 98 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 99 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma:: @ 8223051
# 100 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
# 101 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 102 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 103 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma:: @ 822305A
# 104 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
# 105 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	return
# 106 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 107 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Scientist:: @ 8223063
# 108 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 109 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 110 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 111 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
# 112 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
# 113 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 114 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 115 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 116 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma:: @ 822307A
# 117 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
# 118 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
# 119 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 120 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 121 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 122 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 123 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan:: @ 822308E
# 124 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 125 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 126 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 127 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
# 128 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
# 129 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
# 130 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	giveitem ITEM_SUN_STONE
# 131 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 132 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 133 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
# 134 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
# 135 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 136 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 137 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 138 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone:: @ 82230D0
# 139 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
# 140 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 141 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 142 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 143 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma:: @ 82230DA
# 144 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
# 145 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
# 146 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	giveitem ITEM_SUN_STONE
# 147 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 148 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 149 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
# 150 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
# 151 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
# 152 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 153 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 154 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 155 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 156 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma:: @ 8223119
# 157 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
# 158 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestRight
# 159 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 160 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 161 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 162 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 163 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Woman:: @ 822312D
# 164 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 165 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 166 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
# 167 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 168 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
# 169 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 170 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_lt MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
# 171 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
# 172 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 173 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 174 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal:: @ 8223154
# 175 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
# 176 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 177 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 178 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 179 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma:: @ 822315E
# 180 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
# 181 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 182 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 183 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 184 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldMan:: @ 8223168
# 185 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 186 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 187 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
# 188 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 189 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
# 190 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 191 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_lt MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
# 192 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
# 193 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 194 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 195 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal:: @ 822318F
# 196 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
# 197 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 198 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 199 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 200 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 201 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 202 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 203 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma:: @ 82231A4
# 204 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
# 205 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	closemessage
# 206 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 207 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 208 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 209 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 210 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 211 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Steven:: @ 82231B9
# 212 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 213 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 214 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
# 215 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 216 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 217 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 218 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 219 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 220 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote:: @ 82231CF
# 221 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lockall
# 222 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
# 223 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	releaseall
# 224 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 225 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 226 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt3:: @ 82231DA
# 227 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
# 228 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
# 229 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 230 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 231 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt1:: @ 82231F1
# 232 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
# 233 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 234 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 235 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 236 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt4:: @ 8223208
# 237 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
# 238 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 239 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 240 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 241 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt2:: @ 822321F
# 242 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock
# 243 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	faceplayer
# 244 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
# 245 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
# 246 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
# 247 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
# 248 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	copyobjectxytoperm LOCALID_STAIR_GRUNT
# 249 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	switch VAR_FACING
# 250 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
# 251 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	#ifdef BUGFIX
# 252 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 253 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	#else
# 254 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
# 255 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	#endif
# 256 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
# 257 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 258 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
# 259 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 260 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 261 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 262 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated:: @ 822326E
# 263 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
# 264 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 265 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 266 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 267 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest:: @ 8223278
# 268 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
# 269 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 270 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
# 271 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 272 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 273 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 274 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
# 275 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
# 276 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast:: @ 8223289
# 277 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
# 278 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	waitmovement 0
# 279 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
# 280 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	release
# 281 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	end
# 282 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 283 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest: @ 822329A
# 284 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 285 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_left
# 286 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 287 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 288 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 289 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ Functionally unused. See above
# 290 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast: @ 822329E
# 291 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 292 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_right
# 293 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 294 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 295 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 296 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
# 297 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs: @ 82232A2
# 298 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	face_left
# 299 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	lock_facing_direction
# 300 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	walk_right
# 301 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	unlock_facing_direction
# 302 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	step_end
# 303 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 304 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent: @ 82232A7
# 305 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket's launch is imminent!$"
# 306 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 307 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber: @ 82232C8
# 308 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket launched safely!\n"
# 309 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That's successful launch no. {STR_VAR_1}!$"
# 310 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 311 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent: @ 8223305
# 312 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I know that things are a little\n"
# 313 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "haywire right now, but…\p"
# 314 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket's launch is imminent!$"
# 315 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 316 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber: @ 822335E
# 317 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I know that things are a little\n"
# 318 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "haywire right now, but…\p"
# 319 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket launched safely!\n"
# 320 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That's successful launch no. {STR_VAR_1}!$"
# 321 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 322 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection: @ 82233D3
# 323 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A rocket launch demands perfection.\n"
# 324 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Not even a 1% margin of error is allowed.\p"
# 325 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Even if it's 99% okay, the whole thing\n"
# 326 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "is useless if 1% happens to be no good.\p"
# 327 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Despite that, we never stop trying.\n"
# 328 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Why? It's a dream that never ends.$"
# 329 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 330 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter: @ 82234B7
# 331 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Those Magma thugs have their sights\n"
# 332 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "set on our Space Center.\p"
# 333 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But we can't allow anything that minor\n"
# 334 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "to interfere with our rocket launch!$"
# 335 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 336 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt: @ 8223540
# 337 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I was taking a stroll down the beach\n"
# 338 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "when I found this.\p"
# 339 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "It's not anything I need, so you can\n"
# 340 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "have it.$"
# 341 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 342 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers: @ 82235A6
# 343 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The Hoenn region has been famous for \n"
# 344 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "its meteor showers for a long time.$"
# 345 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 346 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis: @ 82235F0
# 347 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Team Magma can't be allowed to steal\n"
# 348 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel.\p"
# 349 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Oh, by the way, you can have this stone\n"
# 350 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I found on the beach.$"
# 351 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 352 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma: @ 8223664
# 353 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "With Team Magma around, I guess\n"
# 354 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "strolls on the beach aren't safe.$"
# 355 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 356 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace: @ 82236A6
# 357 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Some people claim that Pokémon came\n"
# 358 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "from space. Could it be true?$"
# 359 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 360 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma: @ 82236E8
# 361 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Team Aqua should take care of\n"
# 362 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Team Magma!\p"
# 363 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But if they did that, Team Aqua will\n"
# 364 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "become bold and brazen, won't they?$"
# 365 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 366 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind: @ 822375B
# 367 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A giant chunk of metal bursts through\n"
# 368 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the skies and flies into space…\p"
# 369 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "It boggles my mind!$"
# 370 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 371 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream: @ 82237B5
# 372 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A giant chunk of metal bursts through\n"
# 373 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the skies and flies into space…\p"
# 374 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "But Team Magma wants to spoil\n"
# 375 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "that dream of mine!\p"
# 376 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I'm not having any of that!$"
# 377 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 378 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel: @ 8223849
# 379 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Steven: {PLAYER}{KUN}, have you read that\n"
# 380 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "proclamation already?\p"
# 381 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Team Magma is coming after the rocket\n"
# 382 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "fuel on this island.\p"
# 383 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I don't know what they'd need it for,\n"
# 384 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "but they can't be allowed to take it.\p"
# 385 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I'll keep an eye on things for\n"
# 386 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "a while longer.\p"
# 387 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "In the meantime, why don't you go\n"
# 388 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "check out the town?$"
# 389 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 390 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro: @ 822396C
# 391 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "As promised, we've come for\n"
# 392 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel!$"
# 393 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 394 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat: @ 8223999
# 395 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ran out of fuel…$"
# 396 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 397 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle: @ 82239AA
# 398 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Don't think you're on a roll just\n"
# 399 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "because you've beaten me!$"
# 400 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 401 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro: @ 82239E6
# 402 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We gave you fair warning!\n"
# 403 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "There's nothing sneaky about us!$"
# 404 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 405 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat: @ 8223A21
# 406 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Grrr…\n"
# 407 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We should've used sneaky treachery…$"
# 408 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 409 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle: @ 8223A4B
# 410 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Okay, I get it already! The next time,\n"
# 411 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "we'll come unannounced.$"
# 412 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 413 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro: @ 8223A8A
# 414 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket fuel the Space Center has\n"
# 415 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "in storage--that's what we're after.\p"
# 416 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We mean to take every last bit of it!$"
# 417 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 418 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat: @ 8223AFA
# 419 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Please, can you spare some fuel?\n"
# 420 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Even a chintzy cup will do!$"
# 421 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 422 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle: @ 8223B37
# 423 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "What are we going to do with\n"
# 424 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "the rocket fuel?\p"
# 425 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "How would I know?\n"
# 426 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ask our leader upstairs!$"
# 427 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 428 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro: @ 8223B90
# 429 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Our leader said no one, but no one,\n"
# 430 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "gets past me!$"
# 431 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 432 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat: @ 8223BC2
# 433 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Ack! Ack! Aaack!$"
# 434 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 435 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle: @ 8223BD3
# 436 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Please, tell our leader that\n"
# 437 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I never abandoned my post.\l"
# 438 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "That I stayed to the bitter end…$"
# 439 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"

# 440 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice: @ 8223C2C
# 441 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "This is…\n"
# 442 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "An intent-to-steal notice?\p"
# 443 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“To the staff of the Space Center:\n"
# 444 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "How are you? We are doing fine.\p"
# 445 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“We will soon visit you to take your\n"
# 446 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "rocket fuel.\p"
# 447 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“Please don't try to stop us.\n"
# 448 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "We will take the fuel no matter what.\p"
# 449 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "“Let there be more land!\n"
# 450 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "                                          Team Magma”$"
