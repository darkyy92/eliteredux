# 1 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 2 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
.set LOCALID_OLD_MAN, 1
# 3 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 4 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_MapScripts:: @ 8227953
# 5 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_OnTransition
# 6 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_OnFrame
# 7 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.byte 0
# 8 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 9 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_OnTransition: @ 822795E
# 10 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	frontier_checkvisittrainer
# 11 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_RESULT, 0
# 12 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout
# 13 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
# 14 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_ne SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor
# 15 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 16 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 17 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout:: @ 822797D
# 18 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 19 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_OLD_MAN, 3, 2
# 20 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_DOWN
# 21 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
# 22 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 23 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 24 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor:: @ 8227991
# 25 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setobjectxyperm LOCALID_OLD_MAN, 2, 2
# 26 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
# 27 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 28 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 29 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_OnFrame: @ 822799D
# 30 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
# 31 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
# 32 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle
# 33 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.2byte 0
# 34 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 35 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_OldManCommentOnBattle:: @ 82279B7
# 36 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	lockall
# 37 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs
# 38 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 39 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement LOCALID_OLD_MAN, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer
# 40 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 41 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	copyobjectxytoperm LOCALID_OLD_MAN
# 42 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 43 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 44 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1
# 45 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment
# 46 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2
# 47 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment
# 48 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3
# 49 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment
# 50 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special LoadPlayerParty
# 51 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0
# 52 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	releaseall
# 53 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 54 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 55 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleWonComment:: @ 8227A04
# 56 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative, MSGBOX_DEFAULT
# 57 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 58 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 59 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleLostComment:: @ 8227A0D
# 60 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou, MSGBOX_DEFAULT
# 61 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 62 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 63 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_BattleTiedComment:: @ 8227A16
# 64 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff, MSGBOX_DEFAULT
# 65 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 66 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 67 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs: @ 8227A1F
# 68 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_down
# 69 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 70 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 71 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer: @ 8227A21
# 72 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_right
# 73 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_in_place_fastest_down
# 74 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 75 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 76 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan:: @ 8227A24
# 77 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	lock
# 78 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	faceplayer
# 79 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	frontier_checkvisittrainer
# 80 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_RESULT, 1
# 81 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer
# 82 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_TEMP_1, 1
# 83 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting
# 84 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
# 85 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	release
# 86 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 87 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 88 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer:: @ 8227A4E
# 89 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
# 90 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	release
# 91 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 92 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 93 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting:: @ 8227A58
# 94 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special SavePlayerParty
# 95 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special BufferEReaderTrainerName
# 96 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
# 97 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 98 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
# 99 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty
# 100 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_RESULT, 0
# 101 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
# 102 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
# 103 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_RESULT, NO
# 104 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
# 105 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special LoadPlayerParty
# 106 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call Common_EventScript_SaveGame
# 107 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 108 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
# 109 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special SavePlayerParty
# 110 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 111 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch, MSGBOX_DEFAULT
# 112 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	closemessage
# 113 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
# 114 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth
# 115 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 116 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast
# 117 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 118 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest
# 119 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F, 255, 3, 1
# 120 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitstate
# 121 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	release
# 122 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 123 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 124 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle:: @ 8227AE2
# 125 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special LoadPlayerParty
# 126 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle, MSGBOX_DEFAULT
# 127 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	release
# 128 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	end
# 129 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 130 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty:: @ 8227AEF
# 131 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3, MSGBOX_DEFAULT
# 132 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 133 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	special ChooseHalfPartyForBattle
# 134 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitstate
# 135 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 136 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 137 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth:: @ 8227AFE
# 138 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
# 139 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth
# 140 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 141 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 142 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 143 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast:: @ 8227B10
# 144 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight
# 145 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast
# 146 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 147 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 148 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 149 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest:: @ 8227B22
# 150 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
# 151 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest
# 152 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	waitmovement 0
# 153 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	return
# 154 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 155 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth: @ 8227B34
# 156 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	delay_16
# 157 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_up
# 158 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_up
# 159 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 160 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 161 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast: @ 8227B38
# 162 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	delay_16
# 163 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_right
# 164 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_up
# 165 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 166 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 167 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest: @ 8227B3C
# 168 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	delay_16
# 169 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_left
# 170 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_up
# 171 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 172 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 173 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft: @ 8227B40
# 174 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_left
# 175 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_in_place_fastest_right
# 176 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 177 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 178 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight: @ 8227B43
# 179 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_right
# 180 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	walk_in_place_fastest_left
# 181 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	step_end
# 182 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 183 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles: @ 8227B46
# 184 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "When I was young, I traveled the world\n"
# 185 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "as a Pokémon Trainer.\p"
# 186 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Now that I've become an old buzzard,\n"
# 187 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "my only amusement is watching young\l"
# 188 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Trainers battle.$"
# 189 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 190 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_DoorAppearsToBeLocked: @ 8227BDD
# 191 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "The door appears to be locked.$"
# 192 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 193 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer: @ 8227BFC
# 194 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "A Trainer named {STR_VAR_1}\n"
# 195 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "is visiting my home.\p"
# 196 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Would you like to challenge\n"
# 197 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "{STR_VAR_1}?$"
# 198 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 199 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle: @ 8227C44
# 200 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "You won't battle? I'm disappointed\n"
# 201 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "that I can't see you battle…$"
# 202 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 203 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3: @ 8227C84
# 204 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Oh, good, good!\p"
# 205 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "But my house isn't all that sturdy.\p"
# 206 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Could I ask you to keep it down to\n"
# 207 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "a 3-on-3 match?$"
# 208 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 209 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle: @ 8227CEB
# 210 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Before you two battle, you should\n"
# 211 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "save your progress.$"
# 212 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 213 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch: @ 8227D21
# 214 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "I hope to see a good match!$"
# 215 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 216 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
@ Unused
# 217 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Tie: @ 8227D3D
# 218 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "{STR_VAR_1}$"
# 219 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 220 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw: @ 8227D40
# 221 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "The match ended up a draw.$"
# 222 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 223 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff: @ 8227D5B
# 224 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "So, it became a standoff.\p"
# 225 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "It was a brilliant match in which\n"
# 226 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "neither side conceded a step!$"
# 227 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 228 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
@ Unused
# 229 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Won: @ 8227DB5
# 230 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "{STR_VAR_1}$"
# 231 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 232 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative: @ 8227DB8
# 233 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "That was superlative!\p"
# 234 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Why, it was like seeing myself in\n"
# 235 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "my youth again!$"
# 236 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 237 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
@ Unused
# 238 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Lost: @ 8227E00
# 239 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "{STR_VAR_1}$"
# 240 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"

# 241 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou: @ 8227E03
# 242 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "Ah, too bad for you!\p"
# 243 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "But it was a good match.\n"
# 244 "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.pory"
	.string "I hope you can win next time.$"
