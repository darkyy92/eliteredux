# 1 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
.set LOCALID_ATTENDANT, 1
# 3 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 4 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_MapScripts:: @ 824F4A3
# 5 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceCorridor_OnFrame
# 6 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.byte 0
# 7 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 8 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_OnFrame: @ 824F4A9
# 9 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor
# 10 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.2byte 0
# 11 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 12 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor:: @ 824F4B3
# 13 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	delay 16
# 14 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
# 15 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor
# 16 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 17 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	lockall
# 18 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	palace_getcomment
# 19 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	compare VAR_RESULT, 0
# 20 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1
# 21 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	compare VAR_RESULT, 1
# 22 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2
# 23 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	compare VAR_RESULT, 2
# 24 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3
# 25 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	compare VAR_RESULT, 3
# 26 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment
# 27 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	compare VAR_RESULT, 4
# 28 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	call_if_eq BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment
# 29 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closemessage
# 30 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	frontier_get FRONTIER_DATA_LVL_MODE
# 31 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	compare VAR_RESULT, FRONTIER_LVL_OPEN
# 32 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	goto_if_eq BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom
# 33 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom
# 34 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom
# 35 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 36 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	opendoor 6, 3
# 37 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 38 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
# 39 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
# 40 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 41 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closedoor 6, 3
# 42 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 43 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	goto BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom
# 44 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 45 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom:: @ 824F553
# 46 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom
# 47 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom
# 48 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 49 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	opendoor 10, 3
# 50 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 51 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
# 52 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
# 53 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitmovement 0
# 54 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	closedoor 10, 3
# 55 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitdooranim
# 56 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom:: @ 824F581
# 57 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 255, 7, 4
# 58 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	waitstate
# 59 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	end
# 60 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 61 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1:: @ 824F58B
# 62 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame, MSGBOX_DEFAULT
# 63 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 64 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 65 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2:: @ 824F594
# 66 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes, MSGBOX_DEFAULT
# 67 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 68 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 69 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3:: @ 824F59D
# 70 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered, MSGBOX_DEFAULT
# 71 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 72 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 73 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment:: @ 824F5A6
# 74 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature, MSGBOX_DEFAULT
# 75 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 76 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 77 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment:: @ 824F5AF
# 78 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons, MSGBOX_DEFAULT
# 79 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	return
# 80 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 81 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor: @ 824F5B8
# 82 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 83 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 84 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 85 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 86 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 87 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 88 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom: @ 824F5BD
# 89 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 90 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 91 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 92 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 93 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 94 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 95 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 96 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 97 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom: @ 824F5C4
# 98 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 99 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 100 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 101 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 102 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_left
# 103 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 104 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 105 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 106 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom: @ 824F5CB
# 107 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 108 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 109 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 110 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 111 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 112 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 113 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 114 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 115 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom: @ 824F5D2
# 116 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 117 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 118 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 119 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_right
# 120 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 121 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 122 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 123 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 124 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom: @ 824F5D9
# 125 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 126 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom: @ 824F5DA
# 127 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	walk_up
# 128 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	set_invisible
# 129 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	step_end
# 130 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 131 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame: @ 824F5DD
# 132 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "People and Pokémon, they are but\n"
# 133 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "the same…\p"
# 134 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Their individual nature makes them\n"
# 135 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "good at certain things, and not good\l"
# 136 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "at others.$"
# 137 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 138 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes: @ 824F65B
# 139 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Rather than trying to make a Pokémon\n"
# 140 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "do what it dislikes, try to let it do\l"
# 141 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "what it likes and is good at doing.\p"
# 142 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Put yourself in the Pokémon's position\n"
# 143 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "and consider what moves it would like.$"
# 144 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 145 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered: @ 824F718
# 146 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "A Pokémon's nature is a remarkable\n"
# 147 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "thing…\p"
# 148 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Some Pokémon behave in a completely\n"
# 149 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "different way when they are cornered.$"
# 150 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 151 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature: @ 824F78C
# 152 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Are you beginning to understand how\n"
# 153 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "a Pokémon's nature makes it behave?$"
# 154 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"

# 155 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons: @ 824F7D4
# 156 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "Ah… I see a strong, heartfelt bond\n"
# 157 "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.pory"
	.string "between you and your Pokémon…$"
