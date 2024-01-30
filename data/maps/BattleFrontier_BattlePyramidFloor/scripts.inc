# 1 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 2 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_MapScripts:: @ 8252A33
# 3 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
# 4 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
# 5 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
# 6 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.byte 0
# 7 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 8 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_OnFrame: @ 8252A43
# 9 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
# 10 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
# 11 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
# 12 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.2byte 0
# 13 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 14 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight:: @ 8252A5D
# 15 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	lockall
# 16 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	@ pyramid_updatelight, cant use macro because it straddles the loop
# 17 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
# 18 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_0x8005, 4
# 19 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
# 20 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_0x8007, SE_SAVE
# 21 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_RESULT, 0
# 22 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop:: @ 8252A77
# 23 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	special CallBattlePyramidFunction
# 24 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	delay 2
# 25 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_RESULT, 2
# 26 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_ne BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
# 27 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_D, 0
# 28 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	releaseall
# 29 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 30 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 31 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName:: @ 8252A8F
# 32 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	special ShowMapNamePopup
# 33 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_F, 0
# 34 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 35 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 36 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic:: @ 8252A98
# 37 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	playbgm MUS_B_PYRAMID, FALSE
# 38 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_E, 1
# 39 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 40 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 41 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_OnResume: @ 8252AA2
# 42 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_setfloorpal
# 43 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_getstatus
# 44 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	switch VAR_TEMP_0
# 45 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
# 46 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
# 47 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
# 48 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 49 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
# 50 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
# 51 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
# 52 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
# 53 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_RESULT, 0
# 54 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
# 55 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 56 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 57 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_DREW
# 58 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 59 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_FORFEITED
# 60 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 61 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
# 62 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_D, 1
# 63 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty:: @ 8252B39
# 64 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_resetparty
# 65 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 66 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 67 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost:: @ 8252B42
# 68 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
# 69 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
# 70 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramid_EventScript_WarpToLobby:: @ 8252B66
# 71 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
# 72 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_clearhelditems
# 73 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	special HealPlayerParty
# 74 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 255, 7, 13
# 75 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitstate
# 76 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 77 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 78 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge:: @ 8252B8D
# 79 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_save CHALLENGE_STATUS_SAVING
# 80 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	special SavePlayerParty
# 81 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 82 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_settrainers
# 83 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_setpartyorder FRONTIER_PARTY_SIZE
# 84 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_F, 1
# 85 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 86 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 87 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_OnTransition: @ 8252BCA
# 88 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
# 89 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_TEMP_F, 1
# 90 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 91 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 92 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius:: @ 8252BD5
# 93 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
# 94 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	return
# 95 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 96 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_WarpToNextFloor:: @ 8252BE8
# 97 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	call BattleFrontier_EventScript_IncrementWinStreak
# 98 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
# 99 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	addvar VAR_RESULT, 1
# 100 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 101 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_RESULT, 7
# 102 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq BattlePyramid_WarpToTop
# 103 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_seedfloor
# 104 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
# 105 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	setvar VAR_RESULT, 0
# 106 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 255, 1, 1
# 107 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitstate
# 108 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 109 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 110 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_WarpToTop:: @ 8252C45
# 111 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 255, 17, 17
# 112 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitstate
# 113 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 114 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 115 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
@ TRAINER_PHILLIP is used as a placeholder
# 116 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_TrainerBattle:: @ 8252C4F
# 117 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
# 118 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_showhint
# 119 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitmessage
# 120 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	waitbuttonpress
# 121 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	closemessage
# 122 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	releaseall
# 123 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 124 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 125 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_FindItemBall:: @ 8252C6A
# 126 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_setitem
# 127 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	callstd STD_FIND_ITEM
# 128 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	compare VAR_0x8007, 0
# 129 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto_if_eq BattlePyramid_FindItemBallEnd
# 130 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	pyramid_hideitem
# 131 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_FindItemBallEnd:: @ 8252C87
# 132 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	end
# 133 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 134 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Retire:: @ 8252C88
# 135 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 136 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 137 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
@ Also used by Trainer Hill
# 138 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattleFacility_TrainerBattle_PlaceholderText: @ 8252C8D
# 139 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is a sample message.$"
# 140 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 141 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
gText_BattlePyramidConfirmRest:: @ 8252CA7
# 142 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Your BATTLE PYRAMID quest will be\n"
# 143 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "saved so that you may quit for now.\l"
# 144 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Is that okay?$"
# 145 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 146 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
gText_BattlePyramidConfirmRetire:: @ 8252CFB
# 147 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you sure you want to quit your\n"
# 148 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "PYRAMID quest?$"
# 149 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 150 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp1:: @ 8252D2D
# 151 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This floor's exit is in\n"
# 152 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that direction: {UP_ARROW}$"
# 153 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 154 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft1:: @ 8252D57
# 155 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This floor's exit is in\n"
# 156 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that direction: {LEFT_ARROW}$"
# 157 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 158 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight1:: @ 8252D81
# 159 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This floor's exit is in\n"
# 160 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that direction: {RIGHT_ARROW}$"
# 161 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 162 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown1:: @ 8252DAB
# 163 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This floor's exit is in\n"
# 164 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that direction: {DOWN_ARROW}$"
# 165 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 166 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp2:: @ 8252DD5
# 167 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit on this floor is in\n"
# 168 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {UP_ARROW} direction.$"
# 169 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 170 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft2:: @ 8252E03
# 171 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit on this floor is in\n"
# 172 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {LEFT_ARROW} direction.$"
# 173 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 174 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight2:: @ 8252E31
# 175 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit on this floor is in\n"
# 176 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {RIGHT_ARROW} direction.$"
# 177 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 178 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown2:: @ 8252E5F
# 179 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit on this floor is in\n"
# 180 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {DOWN_ARROW} direction.$"
# 181 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 182 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp3:: @ 8252E8D
# 183 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit is over\n"
# 184 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that {UP_ARROW} way.$"
# 185 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 186 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft3:: @ 8252EAA
# 187 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit is over\n"
# 188 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that {LEFT_ARROW} way.$"
# 189 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 190 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight3:: @ 8252EC7
# 191 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit is over\n"
# 192 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that {RIGHT_ARROW} way.$"
# 193 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 194 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown3:: @ 8252EE4
# 195 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit is over\n"
# 196 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "that {DOWN_ARROW} way.$"
# 197 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 198 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp4:: @ 8252F01
# 199 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor, the exit is somewhere\n"
# 200 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "in the {UP_ARROW} direction.$"
# 201 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 202 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft4:: @ 8252F3A
# 203 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor, the exit is somewhere\n"
# 204 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "in the {LEFT_ARROW} direction.$"
# 205 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 206 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight4:: @ 8252F73
# 207 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor, the exit is somewhere\n"
# 208 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "in the {RIGHT_ARROW} direction.$"
# 209 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 210 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown4:: @ 8252FAC
# 211 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor, the exit is somewhere\n"
# 212 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "in the {DOWN_ARROW} direction.$"
# 213 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 214 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp5:: @ 8252FE5
# 215 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit?\n"
# 216 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "It's that {UP_ARROW} way.$"
# 217 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 218 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft5:: @ 8253000
# 219 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit?\n"
# 220 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "It's that {LEFT_ARROW} way.$"
# 221 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 222 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight5:: @ 825301B
# 223 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit?\n"
# 224 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "It's that {RIGHT_ARROW} way.$"
# 225 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 226 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown5:: @ 8253036
# 227 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit?\n"
# 228 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "It's that {DOWN_ARROW} way.$"
# 229 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 230 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintUp6:: @ 8253051
# 231 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit happens to be in\n"
# 232 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {UP_ARROW} direction.$"
# 233 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 234 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintLeft6:: @ 825307C
# 235 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit happens to be in\n"
# 236 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {LEFT_ARROW} direction.$"
# 237 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 238 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintRight6:: @ 82530A7
# 239 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit happens to be in\n"
# 240 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {RIGHT_ARROW} direction.$"
# 241 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 242 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ExitHintDown6:: @ 82530D2
# 243 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "The exit happens to be in\n"
# 244 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the {DOWN_ARROW} direction.$"
# 245 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 246 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining1:: @ 82530FD
# 247 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 248 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are eight items left to\n"
# 249 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 250 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 251 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining1:: @ 8253140
# 252 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 253 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are seven items left to\n"
# 254 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 255 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 256 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining1:: @ 8253183
# 257 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 258 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are six items left to\n"
# 259 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 260 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 261 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining1:: @ 82531C4
# 262 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 263 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are five items left to\n"
# 264 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 265 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 266 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining1:: @ 8253206
# 267 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 268 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are four items left to\n"
# 269 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 270 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 271 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining1:: @ 8253248
# 272 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 273 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are three items left to\n"
# 274 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 275 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 276 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining1:: @ 825328B
# 277 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 278 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are two items left to\n"
# 279 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 280 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 281 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining1:: @ 82532CC
# 282 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 283 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There is one item left to\n"
# 284 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found.$"
# 285 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 286 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining1:: @ 825330B
# 287 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Are you looking for items?\p"
# 288 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There isn't anything left to\n"
# 289 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "be found!$"
# 290 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 291 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining2:: @ 825334D
# 292 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 293 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 294 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are eight items\n"
# 295 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 296 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 297 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining2:: @ 82533A6
# 298 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 299 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 300 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are seven items left\n"
# 301 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 302 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 303 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining2:: @ 8253404
# 304 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 305 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 306 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are six items left\n"
# 307 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 308 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 309 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining2:: @ 8253460
# 310 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 311 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 312 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are five items left\n"
# 313 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 314 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 315 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining2:: @ 82534BD
# 316 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 317 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 318 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are four items left\n"
# 319 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 320 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 321 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining2:: @ 825351A
# 322 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 323 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 324 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are three items left\n"
# 325 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 326 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 327 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining2:: @ 8253578
# 328 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 329 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 330 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are two items left\n"
# 331 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 332 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 333 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining2:: @ 82535D4
# 334 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 335 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 336 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There is just one item\n"
# 337 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 338 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 339 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining2:: @ 825362E
# 340 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Because you won, I'll tell you\n"
# 341 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a little secret!\p"
# 342 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There isn't anything left\n"
# 343 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "lying around here.$"
# 344 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 345 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining3:: @ 825368B
# 346 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 347 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are eight items left\n"
# 348 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 349 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 350 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining3:: @ 82536F8
# 351 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 352 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are seven items left\n"
# 353 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 354 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 355 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining3:: @ 8253765
# 356 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 357 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are six items left\n"
# 358 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 359 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 360 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining3:: @ 82537D0
# 361 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 362 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are five items left\n"
# 363 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 364 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 365 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining3:: @ 825383C
# 366 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 367 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are four items left\n"
# 368 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 369 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 370 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining3:: @ 82538A8
# 371 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 372 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are three items left\n"
# 373 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 374 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 375 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining3:: @ 8253915
# 376 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 377 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are two items left\n"
# 378 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 379 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 380 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining3:: @ 8253980
# 381 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 382 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there's but one item left\n"
# 383 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.$"
# 384 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 385 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining3:: @ 82539EC
# 386 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "How's your stock of items holding up?\p"
# 387 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I reckon there are no more items\n"
# 388 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "waiting to be found on this floor.\l"
# 389 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You take care now!$"
# 390 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 391 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining4:: @ 8253A69
# 392 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 393 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 394 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be eight more\n"
# 395 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 396 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 397 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining4:: @ 8253AC4
# 398 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 399 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 400 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be seven more\n"
# 401 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 402 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 403 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining4:: @ 8253B1F
# 404 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 405 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 406 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be six more\n"
# 407 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 408 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 409 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining4:: @ 8253B78
# 410 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 411 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 412 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be five more\n"
# 413 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 414 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 415 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining4:: @ 8253BD2
# 416 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 417 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 418 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be four more\n"
# 419 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 420 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 421 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining4:: @ 8253C2C
# 422 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 423 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 424 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be three more\n"
# 425 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 426 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 427 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining4:: @ 8253C87
# 428 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 429 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 430 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be two more\n"
# 431 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 432 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 433 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining4:: @ 8253CE0
# 434 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 435 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 436 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appears to be only one more\n"
# 437 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "item on the ground.$"
# 438 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 439 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining4:: @ 8253D3E
# 440 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You're strong, so you've earned\n"
# 441 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "a hint!\p"
# 442 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There appear to be no more\n"
# 443 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on the ground.$"
# 444 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 445 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining5:: @ 8253D96
# 446 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 447 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are eight items…$"
# 448 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 449 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining5:: @ 8253DD2
# 450 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 451 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are seven items…$"
# 452 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 453 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining5:: @ 8253E0E
# 454 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 455 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are six items…$"
# 456 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 457 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining5:: @ 8253E48
# 458 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 459 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are five items…$"
# 460 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 461 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining5:: @ 8253E83
# 462 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 463 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are four items…$"
# 464 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 465 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining5:: @ 8253EBE
# 466 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 467 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are three items…$"
# 468 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 469 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining5:: @ 8253EFA
# 470 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 471 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are two items…$"
# 472 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 473 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining5:: @ 8253F34
# 474 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 475 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there is one item…$"
# 476 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 477 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining5:: @ 8253F6C
# 478 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "On this floor of the PYRAMID,\n"
# 479 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I hear there are no items…$"
# 480 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 481 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_EightItemsRemaining6:: @ 8253FA5
# 482 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 483 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are eight more\n"
# 484 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 485 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 486 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenItemsRemaining6:: @ 8253FF7
# 487 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 488 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are seven more\n"
# 489 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 490 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 491 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixItemsRemaining6:: @ 8254049
# 492 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 493 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are six more\n"
# 494 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 495 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 496 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveItemsRemaining6:: @ 8254099
# 497 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 498 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are five more\n"
# 499 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 500 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 501 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourItemsRemaining6:: @ 82540EA
# 502 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 503 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are four more\n"
# 504 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 505 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 506 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeItemsRemaining6:: @ 825413B
# 507 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 508 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are three more\n"
# 509 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 510 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 511 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoItemsRemaining6:: @ 825418D
# 512 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 513 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are two more\n"
# 514 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 515 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 516 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneItemRemaining6:: @ 82541DD
# 517 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 518 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there is one more\n"
# 519 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "item on this floor.$"
# 520 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 521 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroItemsRemaining6:: @ 825422B
# 522 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Have you collected any items?\p"
# 523 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I believe there are no more\n"
# 524 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "items on this floor.$"
# 525 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 526 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining1:: @ 825427A
# 527 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 528 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still seven tough\n"
# 529 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Trainers other than me!$"
# 530 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 531 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining1:: @ 82542CB
# 532 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 533 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still six tough\n"
# 534 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Trainers other than me!$"
# 535 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 536 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining1:: @ 825431A
# 537 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 538 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still five tough\n"
# 539 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Trainers other than me!$"
# 540 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 541 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining1:: @ 825436A
# 542 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 543 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still four tough\n"
# 544 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Trainers other than me!$"
# 545 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 546 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining1:: @ 82543BA
# 547 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 548 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still three tough\n"
# 549 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Trainers other than me!$"
# 550 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 551 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining1:: @ 825440B
# 552 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 553 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are still two tough\n"
# 554 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Trainers other than me!$"
# 555 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 556 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining1:: @ 825445A
# 557 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 558 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there's still one tough\n"
# 559 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Trainer other than me!$"
# 560 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 561 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining1:: @ 82544A6
# 562 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You were really awesome!\p"
# 563 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There's no one left that\n"
# 564 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "can beat you!$"
# 565 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 566 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining2:: @ 82544E6
# 567 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 568 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are seven Trainers left!\n"
# 569 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 570 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 571 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining2:: @ 8254538
# 572 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 573 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are six Trainers left!\n"
# 574 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 575 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 576 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining2:: @ 8254588
# 577 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 578 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are five Trainers left!\n"
# 579 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 580 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 581 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining2:: @ 82545D9
# 582 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 583 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are four Trainers left!\n"
# 584 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 585 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 586 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining2:: @ 825462A
# 587 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 588 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are three Trainers left!\n"
# 589 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 590 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 591 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining2:: @ 825467C
# 592 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 593 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are two Trainers left!\n"
# 594 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Someone will humble you!$"
# 595 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 596 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining2:: @ 82546CC
# 597 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 598 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there's one Trainer left!\n"
# 599 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "I'm sure you will be humbled!$"
# 600 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 601 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining2:: @ 825471E
# 602 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "This is so upsetting!\p"
# 603 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are no more Trainers\n"
# 604 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "who can engage you!$"
# 605 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 606 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining3:: @ 8254767
# 607 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 608 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are seven more Trainers\n"
# 609 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 610 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 611 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining3:: @ 82547C9
# 612 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 613 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are six more Trainers\n"
# 614 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 615 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 616 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining3:: @ 8254829
# 617 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 618 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are five more Trainers\n"
# 619 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 620 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 621 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining3:: @ 825488A
# 622 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 623 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are four more Trainers\n"
# 624 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 625 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 626 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining3:: @ 82548EB
# 627 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 628 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are three more Trainers\n"
# 629 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them all?$"
# 630 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 631 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining3:: @ 825494D
# 632 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 633 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there are two more Trainers\n"
# 634 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you beat them both?$"
# 635 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 636 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining3:: @ 82549AE
# 637 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 638 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "But there's still one more Trainer\n"
# 639 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor. Can you prevail?$"
# 640 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 641 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining3:: @ 8254A0B
# 642 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "That's pretty impressive!\p"
# 643 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You've gone through all the Trainers\n"
# 644 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "on this floor.$"
# 645 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 646 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining4:: @ 8254A59
# 647 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 648 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the seven Trainers left on this floor.$"
# 649 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 650 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining4:: @ 8254A9E
# 651 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 652 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the six Trainers left on this floor.$"
# 653 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 654 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining4:: @ 8254AE1
# 655 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 656 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the five Trainers left on this floor.$"
# 657 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 658 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining4:: @ 8254B25
# 659 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 660 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the four Trainers left on this floor.$"
# 661 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 662 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining4:: @ 8254B69
# 663 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 664 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the three Trainers left on this floor.$"
# 665 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 666 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining4:: @ 8254BAE
# 667 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could sweep through\n"
# 668 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the two Trainers left on this floor.$"
# 669 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 670 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining4:: @ 8254BF1
# 671 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Maybe you could complete your sweep\n"
# 672 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "with the one Trainer left on this floor.$"
# 673 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 674 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining4:: @ 8254C3E
# 675 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There isn't a single person left who\n"
# 676 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "can defeat you now…$"
# 677 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 678 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining5:: @ 8254C77
# 679 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 680 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the seven expert Trainers who remain.$"
# 681 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 682 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining5:: @ 8254CC0
# 683 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 684 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the six expert Trainers who remain.$"
# 685 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 686 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining5:: @ 8254D07
# 687 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 688 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the five expert Trainers who remain.$"
# 689 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 690 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining5:: @ 8254D4F
# 691 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 692 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the four expert Trainers who remain.$"
# 693 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 694 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining5:: @ 8254D97
# 695 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 696 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the three expert Trainers who remain.$"
# 697 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 698 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining5:: @ 8254DE0
# 699 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 700 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the two expert Trainers who remain.$"
# 701 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 702 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining5:: @ 8254E27
# 703 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "You may have what it takes to beat\n"
# 704 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the one expert Trainer who remains.$"
# 705 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 706 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining5:: @ 8254E6E
# 707 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Your skills are beyond reproach.\p"
# 708 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There are no more Trainers here\n"
# 709 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "who have any chance of beating you.$"
# 710 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 711 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SevenTrainersRemaining6:: @ 8254ED3
# 712 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 713 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the seven remaining TRAINERS?$"
# 714 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 715 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_SixTrainersRemaining6:: @ 8254F0E
# 716 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 717 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the six remaining TRAINERS?$"
# 718 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 719 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FiveTrainersRemaining6:: @ 8254F47
# 720 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 721 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the five remaining TRAINERS?$"
# 722 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 723 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_FourTrainersRemaining6:: @ 8254F81
# 724 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 725 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the four remaining TRAINERS?$"
# 726 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 727 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ThreeTrainersRemaining6:: @ 8254FBB
# 728 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 729 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the three remaining TRAINERS?$"
# 730 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 731 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_TwoTrainersRemaining6:: @ 8254FF6
# 732 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 733 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the two remaining TRAINERS?$"
# 734 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 735 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_OneTrainersRemaining6:: @ 825502F
# 736 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "Can you keep winning against\n"
# 737 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "the last remaining Trainer?$"
# 738 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"

# 739 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
BattlePyramid_Text_ZeroTrainersRemaining6:: @ 8255068
# 740 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "There aren't any Trainers left that\n"
# 741 "data/maps/BattleFrontier_BattlePyramidFloor/scripts.pory"
	.string "can take you on now…$"
