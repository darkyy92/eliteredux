# 1 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 2 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
.set LOCALID_NURSE, 1
# 3 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
.set LOCALID_GUARD_1, 3
# 4 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
.set LOCALID_GUARD_2, 4
# 5 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 6 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_MapScripts:: @ 82295D2
# 7 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
# 8 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 9 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.byte 0
# 10 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 11 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_OnTransition:
# 12 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
# 13 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
# 14 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
# 15 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 16 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 17 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
# 18 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_GUARD_1, 9, 2
# 19 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_GUARD_2, 10, 2
# 20 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 21 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 22 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Nurse:: @ 82295FC
# 23 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_NURSE
# 24 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 25 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 26 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitbuttonpress
# 27 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 28 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 29 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 30 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Clerk:: @ 822960A
# 31 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lock
# 32 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	faceplayer
# 33 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message gText_HowMayIServeYou
# 34 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 35 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemart PokeMart_Poke_Center_Feather_Badge
# 36 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 37 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 38 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 39 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 40 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
# 41 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ Its assumed the player has the remaining badges
# 42 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard:: @ 8229636
# 43 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lockall
# 44 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_2, 1
# 45 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_eq EverGrandeCity_PokemonLeague_1F_EventScriptSwitchTrainerMsg
# 46 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 47 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_0, 11
# 48 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_ge EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
# 49 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_0, 8
# 50 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_le EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
# 51 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_PokemonLeague_1F_EventScript_Rematches
# 52 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
# 53 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
# 54 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 55 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 120
# 56 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
# 57 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 58 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_TEMP_2, 1
# 59 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
# 60 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
# 61 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 62 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 10
# 63 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 64 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
# 65 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 66 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitfanfare
# 67 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 68 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_GUARD_1
# 69 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_GUARD_2
# 70 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_ENTERED_ELITE_FOUR
# 71 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 72 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 73 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 74 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScriptSwitchTrainerMsg:
# 75 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_PokemonLeague_1F_EventScriptGoForthChampion
# 76 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto EverGrandeCity_PokemonLeague_1F_EventScript_GoForthFacePlayer
# 77 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 78 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Rematches::
# 79 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_ChooseFormat
# 80 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 81 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
# 82 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	switch VAR_RESULT
# 83 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	case 0, EverGrandeCity_PokemonLeague_1F_EventScript_SetSingles
# 84 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	case 1, EverGrandeCity_PokemonLeague_1F_EventScript_SetDoubles
# 85 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	case 2, EverGrandeCity_PokemonLeague_1F_EventScript_Exit
# 86 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	case 127, EverGrandeCity_PokemonLeague_1F_EventScript_Exit
# 87 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 88 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_SetSingles::
# 89 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_Legendaries, MSGBOX_YESNO
# 90 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_RESULT, 1
# 91 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_eq EverGrandeCity_PokemonLeague_1F_EventScript_SetSinglesLegendaries
# 92 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_ELITE_4_MODE, 0
# 93 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto EverGrandeCity_PokemonLeague_1F_EventScriptMoveGuards
# 94 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 95 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_SetSinglesLegendaries::
# 96 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_ELITE_4_MODE, 1
# 97 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto EverGrandeCity_PokemonLeague_1F_EventScriptMoveGuards
# 98 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 99 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_SetDoubles::
# 100 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_Legendaries, MSGBOX_YESNO
# 101 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_RESULT, 1
# 102 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_eq EverGrandeCity_PokemonLeague_1F_EventScript_SetDoublesLegendaries
# 103 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_ELITE_4_MODE, 2
# 104 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto EverGrandeCity_PokemonLeague_1F_EventScriptMoveGuards
# 105 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 106 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_SetDoublesLegendaries::
# 107 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_ELITE_4_MODE, 3
# 108 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto EverGrandeCity_PokemonLeague_1F_EventScriptMoveGuards
# 109 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 110 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScriptMoveGuards::
# 111 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_TEMP_2, 1
# 112 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 113 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
# 114 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
# 115 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 116 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 10
# 117 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 118 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScriptGoForthChampion2::
# 119 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_GoForthChampion
# 120 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 121 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitfanfare
# 122 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 123 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 124 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 125 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_GUARD_1
# 126 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_GUARD_2
# 127 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 128 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 129 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 130 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScriptGoForthChampion::
# 131 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 132 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 133 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto EverGrandeCity_PokemonLeague_1F_EventScriptGoForthChampion2
# 134 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 135 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight:: @ 8229698
# 136 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
# 137 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 138 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 139 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 140 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft:: @ 82296A3
# 141 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
# 142 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 143 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 144 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 145 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges:: @ 82296AE
# 146 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playse SE_FAILURE
# 147 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
# 148 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 149 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 150 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 151 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GoForth:: @ 82296BB
# 152 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_2, 1
# 153 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_eq EverGrandeCity_PokemonLeague_1F_EventScript_GoForthFacePlayer
# 154 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 155 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 156 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
# 157 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
# 158 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 159 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 10
# 160 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 161 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_TEMP_2, 1
# 162 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GoForth2::
# 163 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
# 164 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 165 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 166 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 167 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 168 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 169 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 170 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GoForthFacePlayer::
# 171 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 172 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 173 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto EverGrandeCity_PokemonLeague_1F_EventScript_GoForth2
# 174 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 175 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Exit::
# 176 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 177 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 178 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 179 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight: @ 82296DA
# 180 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 181 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 182 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_fastest_up
# 183 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 184 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 185 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft: @ 82296DE
# 186 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 187 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 188 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_fastest_up
# 189 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 190 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 191 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay: @ 82296E2
# 192 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 193 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_fastest_down
# 194 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 195 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 196 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay: @ 82296E5
# 197 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 198 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_fastest_down
# 199 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 200 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 201 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges: @ 82296E8
# 202 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Beyond this point, only those Trainers\n"
# 203 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "who have collected all the Gym Badges\l"
# 204 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "are permitted to enter.\p"
# 205 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Trainer, let us confirm that you have\n"
# 206 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "all the Gym Badges.$"
# 207 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 208 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges: @ 8229787
# 209 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "You haven't obtained all the Badges.\p"
# 210 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "If you're bound for the Pokémon\n"
# 211 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "League, you must return with them.$"
# 212 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 213 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_GoForth: @ 82297EF
# 214 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Trainer! Believe in yourself and your\n"
# 215 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Pokémon, and go forth!$"
# 216 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 217 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_ChooseFormat:
# 218 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Welcome, Champion!\p"
# 219 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "If you wish to take on the Pokémon\n"
# 220 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "League again, you must first set the\l"
# 221 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "rules for your challenge.\p"
# 222 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Which battle format would you like?$"
# 223 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 224 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_Legendaries:
# 225 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Would you like to test yourself\n"
# 226 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "against the power of Legendary\l"
# 227 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Pokémon?$"
# 228 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 229 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_GoForthChampion:
# 230 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Champion! Believe in yourself and your\n"
# 231 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Pokémon, and go forth!$"

EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode::
# 234 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lockall
# 236 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_1, Common_Movement_FaceRight
# 237 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_GUARD_2, Common_Movement_FaceLeft
# 238 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_Text_0, MSGBOX_YESNO
# 239 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_2
# 244 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_Text_2, MSGBOX_NPC
# 245 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	clearflag FLAG_SYS_LOCKED_MODE
EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_1:
# 247 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
# 248 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 249 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	warp MAP_EVER_GRANDE_CITY_HALL5, 255, 5, 12
# 250 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 40
# 251 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_2:
# 240 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_Text_1, MSGBOX_NPC
# 241 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_SYS_LOCKED_MODE
	goto EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_1


EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_Text_0:
# 238 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Guard: Do you want to enable Locked\n"
	.string "Mode during the League? This prevents\l"
	.string "you from changing your Pokémon, except\l"
	.string "held items.$"

EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_Text_1:
# 240 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Guard: Locked Mode is now enabled.$"

EverGrandeCity_PokemonLeague_1F_EventScript_LockedMode_Text_2:
# 244 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Guard: Locked Mode is now disabled.$"
