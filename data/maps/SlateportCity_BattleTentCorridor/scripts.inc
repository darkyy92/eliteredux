# 1 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 2 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 4 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_MapScripts:: @ 8208E26
# 5 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
# 6 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
# 7 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.byte 0
# 8 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 9 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room
# 10 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 11 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_OnWarp: @ 8208E31
# 12 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
# 13 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.2byte 0
# 14 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 15 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_SetUpObjects:: @ 8208E3B
# 16 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 17 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	compare VAR_0x8006, 1
# 18 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto_if_ne SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
# 19 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	setobjectxy LOCALID_ATTENDANT, 2, 2
# 20 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
# 21 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth:: @ 8208E56
# 22 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 23 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	end
# 24 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 25 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_OnFrame: @ 8208E5B
# 26 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
# 27 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.2byte 0
# 28 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 29 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_EnterCorridor:: @ 8208E65
# 30 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	compare VAR_0x8006, 1
# 31 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
# 32 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	setvar VAR_TEMP_0, 1
# 33 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
# 34 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
# 35 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 36 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	compare VAR_0x8006, 2
# 37 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
# 38 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_generaterentalmons
# 39 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_generateopponentmons
# 40 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
# 41 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	fadescreen FADE_TO_BLACK
# 42 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_rentmons
# 43 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitstate
# 44 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom:: @ 8208EB4
# 45 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
# 46 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	closemessage
# 47 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestUp
# 48 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 49 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	opendoor 2, 1
# 50 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitdooranim
# 51 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
# 52 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
# 53 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmovement 0
# 54 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	closedoor 2, 1
# 55 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitdooranim
# 56 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 255, 4, 4
# 57 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitstate
# 58 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	end
# 59 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 60 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle:: @ 8208EEE
# 61 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	factory_setopponentmons
# 62 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	factory_resethelditems
# 63 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
# 64 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	playfanfare MUS_HEAL
# 65 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitfanfare
# 66 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	special HealPlayerParty
# 67 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent:: @ 8208F0D
# 68 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 69 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	compare VAR_RESULT, 1
# 70 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	call_if_eq SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
# 71 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	compare VAR_RESULT, 2
# 72 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	call_if_eq SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
# 73 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
# 74 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	switch VAR_RESULT
# 75 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
# 76 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
# 77 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge
# 78 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 79 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge:: @ 8208F5B
# 80 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
# 81 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	switch VAR_RESULT
# 82 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 83 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
# 84 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 85 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 86 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge:: @ 8208F89
# 87 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
# 88 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmessage
# 89 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
# 90 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	switch VAR_RESULT
# 91 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 92 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
# 93 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 94 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 95 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_AskSwapMon:: @ 8208FBB
# 96 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_generateopponentmons
# 97 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
# 98 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	switch VAR_RESULT
# 99 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
# 100 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
# 101 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
# 102 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 103 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_SwapMons:: @ 8208FF1
# 104 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	fadescreen FADE_TO_BLACK
# 105 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_swapmons
# 106 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitstate
# 107 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	compare VAR_RESULT, 1
# 108 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto_if_eq SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
# 109 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
# 110 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
# 111 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 112 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent:: @ 8209014
# 113 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
# 114 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmessage
# 115 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	return
# 116 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 117 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent:: @ 820901B
# 118 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
# 119 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmessage
# 120 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	return
# 121 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 122 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_PauseChallenge:: @ 8209022
# 123 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
# 124 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitmessage
# 125 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	slateporttent_save CHALLENGE_STATUS_PAUSED
# 126 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	playse SE_SAVE
# 127 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	waitse
# 128 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	fadescreen FADE_TO_BLACK
# 129 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	frontier_reset
# 130 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	end
# 131 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 132 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge:: @ 8209044
# 133 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	special SavePlayerParty
# 134 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	factory_setparties 0
# 135 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
# 136 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 137 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_Movement_PlayerEnter: @ 8209059
# 138 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 139 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 140 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 141 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 142 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	step_end
# 143 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 144 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_Movement_PlayerExit: @ 820905E
# 145 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 146 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 147 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	set_invisible
# 148 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	step_end
# 149 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 150 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_Movement_AttendantEnter: @ 8209062
# 151 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 152 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 153 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 154 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 155 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_in_place_fastest_down
# 156 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	step_end
# 157 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 158 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_BattleTentCorridor_Movement_AttendantExit: @ 8209068
# 159 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	walk_up
# 160 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	set_invisible
# 161 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	step_end
# 162 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 163 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Leftover text from when this was a Contest Hall in R/S
# 164 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 165 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_AdviceForContests: @ 820906B
# 166 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Want a tasty little bit of advice\n"
# 167 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "for Contests?\p"
# 168 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Using a certain move after another\n"
# 169 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "certain kind of move sometimes gets\l"
# 170 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "you extra attention.\p"
# 171 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "If you know what you're doing,\n"
# 172 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "you can score big in appeal.\p"
# 173 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Of course, your opponents might try\n"
# 174 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "disrupting your Pokémon's showing.$"
# 175 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 176 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 177 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MyPapaIsContestJudge: @ 820917A
# 178 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "My papa, he's a Contest JUDGE.\p"
# 179 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I wonder what I should be when I\n"
# 180 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "grow up, a JUDGE or a Gym Leader?$"
# 181 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 182 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 183 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed: @ 82091DC
# 184 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Hey, man, I'm like majorly cheesed,\n"
# 185 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "you know. Like, you know, I just\l"
# 186 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "wanted to know why my Pokémon\l"
# 187 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "never won, you know, like, hey?\p"
# 188 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "So, like, I gave the JUDGE my two\n"
# 189 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "cents, you know, they're free.\p"
# 190 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "And he wouldn't hear me out, like, hey!\n"
# 191 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "So, like, total bummer, man!\p"
# 192 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Hey, like, you! Zip it, you know?\n"
# 193 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Just, you know, take this!$"
# 194 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 195 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 196 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_ExplainTorment: @ 8209322
# 197 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "That's, like, TM41, you know?\n"
# 198 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Hey, it's TORMENT, you hearing me?\p"
# 199 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Like, it won't let the other guy\n"
# 200 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "use the same move twice in a row, see?\p"
# 201 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Hey, now, you listen here, like,\n"
# 202 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I'm not laying a torment on you!$"
# 203 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 204 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 205 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest: @ 82093ED
# 206 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "MC: Oh, my, my!\n"
# 207 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Now isn't that a dandy of a Pokémon?\p"
# 208 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Please! Do step right up and take\n"
# 209 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "part in our splendid Contests!\p"
# 210 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "You'll do well! I'm sure of it!\n"
# 211 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "My eyes have never failed me!$"
# 212 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 213 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 214 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest: @ 82094A1
# 215 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Judge: Well, hello there!\n"
# 216 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I see that you're a Trainer!\p"
# 217 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Then, it just wouldn't do for you\n"
# 218 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "to miss a Pokémon Contest!\p"
# 219 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Get a Contest PASS in Verdanturf\n"
# 220 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "CITY and enter anytime!$"
# 221 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 222 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 223 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_ItsAppealTime: @ 820954E
# 224 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "It's appeal time!\n"
# 225 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "What should I lead with?$"
# 226 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 227 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 228 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal: @ 8209579
# 229 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "They didn't pay much attention to\n"
# 230 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "my Pokémon's appeal…\p"
# 231 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Humph, that JUDGE, he doesn't know\n"
# 232 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "a good thing when he sees it.$"
# 233 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 234 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 235 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_RewardWithSageAdvice: @ 82095F1
# 236 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Oh, hi! You must be a serious fan to get\n"
# 237 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "this close to the action.\p"
# 238 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I'll reward your enthusiasm with\n"
# 239 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "this sage advice.\p"
# 240 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "If a move goes over really well,\n"
# 241 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "the audience will get excited.\p"
# 242 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "The Pokémon that makes its appeal\n"
# 243 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "right when everyone's excited…\p"
# 244 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Well, you'd think something good has\n"
# 245 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "to happen!$"
# 246 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 247 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 248 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon: @ 8209718
# 249 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I can't do this! I'm more freaked out\n"
# 250 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "than my Pokémon.\p"
# 251 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "I'm shivering and my heart is racing!$"
# 252 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 253 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 254 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_BattleAndContestAlike: @ 8209775
# 255 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "A battle and a Contest aren't the\n"
# 256 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "same, but they are alike, too.\p"
# 257 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "You need to work hard and believe\n"
# 258 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "in the Pokémon you've raised.$"
# 259 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 260 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 261 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame: @ 82097F6
# 262 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "That Pokémon looks like it's on top\n"
# 263 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "of its game, huh?\p"
# 264 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "A Pokémon that does good in the\n"
# 265 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "secondary judging seems to be more\l"
# 266 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "relaxed when it's doing appeals.$"
# 267 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 268 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 269 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot: @ 8209890
# 270 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Will you look at that sorry sight?\p"
# 271 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Heh, my Pokémon's absolutely better\n"
# 272 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "than that lot!$"
# 273 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 274 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 275 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon: @ 82098E6
# 276 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Don't you get the urge to move with\n"
# 277 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Pokémon if they're putting on an\l"
# 278 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "energetic appeal?$"
# 279 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"

# 280 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
@ Unused
# 281 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
SlateportCity_ContestHall_Text_HyperRankStage: @ 820993D
# 282 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "Pokémon Contests\n"
# 283 "data/maps/SlateportCity_BattleTentCorridor/scripts.pory"
	.string "HYPER RANK STAGE!$"
