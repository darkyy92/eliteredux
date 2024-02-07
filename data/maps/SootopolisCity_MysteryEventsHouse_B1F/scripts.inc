# 1 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 2 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_MapScripts:: @ 8227E4F
# 3 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_B1F_OnTransition
# 4 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_B1F_OnFrame
# 5 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	.byte 0
# 6 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 7 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_OnTransition: @ 8227E5A
# 8 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	special SetEReaderTrainerGfxId
# 9 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	end
# 10 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 11 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_OnFrame: @ 8227E5E
# 12 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleVisitingTrainer
# 13 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	.2byte 0
# 14 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 15 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleVisitingTrainer:: @ 8227E68
# 16 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	lockall
# 17 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnterBasement
# 18 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	waitmovement 0
# 19 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	special CopyEReaderTrainerGreeting
# 20 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 21 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	closemessage
# 22 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_EREADER
# 23 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	setvar VAR_0x8005, 0
# 24 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	special DoSpecialTrainerBattle
# 25 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	waitstate
# 26 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_DREW
# 27 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleTie
# 28 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 29 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleWon
# 30 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 31 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	call_if_eq SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLost
# 32 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	closemessage
# 33 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	special HealPlayerParty
# 34 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExitBasement
# 35 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	waitmovement 0
# 36 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	special LoadPlayerParty
# 37 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 38 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, 255, 3, 1
# 39 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	waitstate
# 40 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	releaseall
# 41 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	end
# 42 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 43 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleTie:: @ 8227ECF
# 44 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3
# 45 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw, MSGBOX_DEFAULT
# 46 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	return
# 47 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 48 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleWon:: @ 8227EDD
# 49 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1
# 50 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	special ShowFieldMessageStringVar4
# 51 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	waitmessage
# 52 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	waitbuttonpress
# 53 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	return
# 54 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 55 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLost:: @ 8227EE8
# 56 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2
# 57 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	special ShowFieldMessageStringVar4
# 58 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	waitmessage
# 59 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	waitbuttonpress
# 60 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	return
# 61 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 62 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnterBasement: @ 8227EF3
# 63 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_down
# 64 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_down
# 65 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_down
# 66 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_right
# 67 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_right
# 68 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	step_end
# 69 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"

# 70 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExitBasement: @ 8227EF9
# 71 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_left
# 72 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_left
# 73 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_up
# 74 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_up
# 75 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_up
# 76 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	walk_up
# 77 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	delay_8
# 78 "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.pory"
	step_end
