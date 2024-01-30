# 1 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 2 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_LASS, 1
# 3 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_MAN, 2
# 4 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_POKEFAN_M, 3
# 5 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_LITTLE_GIRL, 4
# 6 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_NINJA_BOY, 5
# 7 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_BOY, 6
# 8 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_WOMAN, 7
# 9 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
.set LOCALID_EXPERT_F, 8
# 10 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 11 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_MapScripts:: @ 821C785
# 12 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_OnFrame
# 13 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
# 14 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.byte 0
# 15 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 16 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	@ See field_specials.c for a breakdown of the Fan Club and its variables
# 17 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 18 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_OnFrame: @ 821C790
# 19 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
# 20 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.2byte 0
# 21 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 22 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans:: @ 821C79A
# 23 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lockall
# 24 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFastestDown
# 25 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 26 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer, MSGBOX_DEFAULT
# 27 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer
# 28 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_MAN, LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
# 29 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 30 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 31 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 32 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan, MSGBOX_DEFAULT
# 33 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer
# 34 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 35 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 36 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 37 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer
# 38 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmovement 0
# 39 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_LILYCOVE_FAN_CLUB_STATE, 2
# 40 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	releaseall
# 41 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 42 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 43 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer: @ 821C7F5
# 44 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	delay_8
# 45 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_in_place_fastest_down
# 46 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_down
# 47 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_down
# 48 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_down
# 49 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_left
# 50 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_left
# 51 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	step_end
# 52 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 53 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer: @ 821C7FD
# 54 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_left
# 55 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_left
# 56 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_down
# 57 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_down
# 58 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_left
# 59 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_down
# 60 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	step_end
# 61 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 62 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer: @ 821C804
# 63 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_down
# 64 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_in_place_fastest_right
# 65 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	step_end
# 66 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 67 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer: @ 821C807
# 68 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	jump_in_place_right
# 69 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_up
# 70 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_up
# 71 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_fast_right
# 72 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	walk_in_place_fastest_down
# 73 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	step_end
# 74 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 75 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_OnTransition: @ 821C80D
# 76 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
# 77 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 1
# 78 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting
# 79 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 2
# 80 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
# 81 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 82 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 83 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions:: @ 821C829
# 84 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special TryLoseFansFromPlayTime
# 85 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
# 86 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 87 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 88 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 89 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
# 90 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER2
# 91 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 92 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 93 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
# 94 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER3
# 95 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 96 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 97 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
# 98 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER4
# 99 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 100 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 101 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
# 102 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER5
# 103 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 104 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 105 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
# 106 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER6
# 107 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 108 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 109 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
# 110 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER7
# 111 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 112 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 113 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
# 114 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER8
# 115 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 116 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 117 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
# 118 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 119 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 120 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer:: @ 821C8DA
# 121 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, ShouldHideFanClubInterviewer
# 122 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 123 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer
# 124 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
# 125 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
# 126 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 127 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 128 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer:: @ 821C8F1
# 129 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
# 130 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 131 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 132 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ Set up the fan club TV show, if the player has at least 5 fans in the club
# 133 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ Rather than counting up, 1 is subtracted from the total for each member not a fan of the players
# 134 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow:: @ 821C8F5
# 135 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS
# 136 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 137 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 138 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 139 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 140 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER2
# 141 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 142 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 143 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 144 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER3
# 145 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 146 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 147 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 148 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER4
# 149 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 150 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 151 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 152 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER5
# 153 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 154 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 155 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 156 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER6
# 157 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 158 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 159 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 160 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER7
# 161 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 162 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 163 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 164 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER8
# 165 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 166 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 167 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
# 168 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_0x8005, 5
# 169 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_ge LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow
# 170 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 171 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 172 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan:: @ 821C9AE
# 173 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	subvar VAR_0x8005, 1
# 174 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 175 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 176 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow:: @ 821C9B4
# 177 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special TryPutTrainerFanClubOnAir
# 178 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 179 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 180 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable:: @ 821C9B8
# 181 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_LASS, 7, 5
# 182 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 183 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 184 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable:: @ 821C9C0
# 185 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_POKEFAN_M, 3, 4
# 186 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 187 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 188 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable:: @ 821C9C8
# 189 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_LITTLE_GIRL, 7, 2
# 190 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 191 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 192 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable:: @ 821C9D0
# 193 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_NINJA_BOY, 5, 5
# 194 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 195 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 196 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable:: @ 821C9D8
# 197 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_BOY, 5, 2
# 198 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 199 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 200 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable:: @ 821C9E0
# 201 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_MAN, 8, 4
# 202 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 203 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 204 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable:: @ 821C9E8
# 205 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_WOMAN, 3, 3
# 206 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 207 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 208 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable:: @ 821C9F0
# 209 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setobjectxyperm LOCALID_EXPERT_F, 8, 3
# 210 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	return
# 211 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 212 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting:: @ 821C9F8
# 213 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
# 214 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
# 215 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
# 216 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
# 217 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
# 218 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
# 219 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 220 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 221 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Man:: @ 821CA17
# 222 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 223 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 224 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER6
# 225 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 226 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
# 227 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion
# 228 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 229 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 230 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan
# 231 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 232 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
# 233 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan
# 234 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary, MSGBOX_DEFAULT
# 235 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 236 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 237 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 238 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan:: @ 821CA56
# 239 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 240 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 241 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan
# 242 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin, MSGBOX_DEFAULT
# 243 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 244 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 245 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 246 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan:: @ 821CA70
# 247 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest, MSGBOX_DEFAULT
# 248 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 249 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 250 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 251 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan:: @ 821CA7A
# 252 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen, MSGBOX_DEFAULT
# 253 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 254 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 255 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 256 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion:: @ 821CA84
# 257 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer, MSGBOX_DEFAULT
# 258 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 259 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 260 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 261 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Lass:: @ 821CA8E
# 262 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 263 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 264 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 265 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 266 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
# 267 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion
# 268 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 269 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 270 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan
# 271 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 272 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
# 273 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan
# 274 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly, MSGBOX_DEFAULT
# 275 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 276 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 277 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 278 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan:: @ 821CACD
# 279 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 280 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 281 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan
# 282 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou, MSGBOX_DEFAULT
# 283 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 284 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 285 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 286 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan:: @ 821CAE7
# 287 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan, MSGBOX_DEFAULT
# 288 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 289 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 290 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 291 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan:: @ 821CAF1
# 292 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly, MSGBOX_DEFAULT
# 293 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 294 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 295 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 296 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion:: @ 821CAFB
# 297 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly, MSGBOX_DEFAULT
# 298 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 299 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 300 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 301 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanM:: @ 821CB05
# 302 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 303 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 304 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER2
# 305 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 306 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
# 307 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion
# 308 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 309 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 310 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan
# 311 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 312 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
# 313 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan
# 314 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman, MSGBOX_DEFAULT
# 315 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 316 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 317 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 318 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan:: @ 821CB44
# 319 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 320 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 321 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan
# 322 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather, MSGBOX_DEFAULT
# 323 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 324 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 325 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 326 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan:: @ 821CB5E
# 327 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling, MSGBOX_DEFAULT
# 328 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 329 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 330 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 331 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan:: @ 821CB68
# 332 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent, MSGBOX_DEFAULT
# 333 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 334 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 335 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 336 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion:: @ 821CB72
# 337 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers, MSGBOX_DEFAULT
# 338 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 339 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 340 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 341 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirl:: @ 821CB7C
# 342 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 343 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 344 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER3
# 345 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 346 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_LILYCOVE_FAN_CLUB_STATE, 0
# 347 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
# 348 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 349 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 350 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
# 351 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 352 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
# 353 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
# 354 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool, MSGBOX_DEFAULT
# 355 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 356 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 357 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 358 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan:: @ 821CBBB
# 359 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 360 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 361 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
# 362 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer, MSGBOX_DEFAULT
# 363 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 364 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 365 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 366 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan:: @ 821CBD5
# 367 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
# 368 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 369 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 370 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 371 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan:: @ 821CBDF
# 372 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe, MSGBOX_DEFAULT
# 373 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 374 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 375 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 376 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion:: @ 821CBE9
# 377 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat, MSGBOX_DEFAULT
# 378 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 379 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 380 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 381 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoy:: @ 821CBF3
# 382 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 383 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 384 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER4
# 385 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 386 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 387 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 388 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan
# 389 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 390 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
# 391 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan
# 392 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool, MSGBOX_DEFAULT
# 393 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 394 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 395 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 396 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan:: @ 821CC27
# 397 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 398 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 399 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan
# 400 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou, MSGBOX_DEFAULT
# 401 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 402 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 403 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 404 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan:: @ 821CC41
# 405 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou, MSGBOX_DEFAULT
# 406 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 407 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 408 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 409 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan:: @ 821CC4B
# 410 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan, MSGBOX_DEFAULT
# 411 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 412 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 413 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 414 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Boy:: @ 821CC55
# 415 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 416 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 417 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER5
# 418 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 419 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 420 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 421 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan
# 422 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 423 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
# 424 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan
# 425 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne, MSGBOX_DEFAULT
# 426 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 427 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 428 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 429 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan:: @ 821CC89
# 430 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 431 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 432 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan
# 433 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll, MSGBOX_DEFAULT
# 434 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 435 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 436 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 437 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan:: @ 821CCA3
# 438 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner, MSGBOX_DEFAULT
# 439 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 440 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 441 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 442 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan:: @ 821CCAD
# 443 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer, MSGBOX_DEFAULT
# 444 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 445 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 446 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 447 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Woman:: @ 821CCB7
# 448 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 449 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 450 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER7
# 451 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 452 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 453 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 454 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
# 455 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 456 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
# 457 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
# 458 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout, MSGBOX_DEFAULT
# 459 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 460 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 461 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 462 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan:: @ 821CCEB
# 463 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 464 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 465 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
# 466 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind, MSGBOX_DEFAULT
# 467 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 468 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 469 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 470 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan:: @ 821CD05
# 471 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation, MSGBOX_DEFAULT
# 472 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 473 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 474 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 475 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan:: @ 821CD0F
# 476 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger, MSGBOX_DEFAULT
# 477 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 478 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 479 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 480 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertF:: @ 821CD19
# 481 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 482 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 483 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER8
# 484 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 485 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
# 486 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 487 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan
# 488 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 489 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1)
# 490 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan
# 491 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential, MSGBOX_DEFAULT
# 492 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 493 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 494 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 495 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan:: @ 821CD4D
# 496 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
# 497 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 498 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan
# 499 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive, MSGBOX_DEFAULT
# 500 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 501 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 502 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 503 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan:: @ 821CD67
# 504 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth, MSGBOX_DEFAULT
# 505 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 506 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 507 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 508 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan:: @ 821CD71
# 509 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength, MSGBOX_DEFAULT
# 510 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 511 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 512 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 513 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Interviewer:: @ 821CD7B
# 514 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 515 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 516 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
# 517 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_Interview
# 518 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 519 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 520 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ The interviewer doesnt count as an individual fan club member
# 521 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ Instead they always ask about whoever the Lass would be interested in, if not the player
# 522 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_Interview:: @ 821CD90
# 523 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_SPECIAL
# 524 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special InterviewBefore
# 525 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 526 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2
# 527 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x800A, VAR_0x8006
# 528 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 529 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 530 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT
# 531 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
# 532 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 533 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call Common_ShowEasyChatScreen
# 534 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 535 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 536 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 537 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
# 538 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 0
# 539 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
# 540 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 541 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 542 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion:: @ 821CDE0
# 543 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
# 544 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
# 545 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 546 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 547 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion:: @ 821CDEE
# 548 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 549 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 550 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
# 551 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, YES
# 552 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
# 553 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, NO
# 554 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion
# 555 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 556 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 557 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion:: @ 821CE15
# 558 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 559 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 560 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, MSGBOX_DEFAULT
# 561 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
# 562 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 563 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	call Common_ShowEasyChatScreen
# 564 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	lock
# 565 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	faceplayer
# 566 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 1
# 567 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
# 568 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, 0
# 569 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
# 570 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 571 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 572 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer:: @ 821CE4D
# 573 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 574 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 575 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	message LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
# 576 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitmessage
# 577 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
# 578 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special ShowScrollableMultichoice
# 579 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	waitstate
# 580 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 581 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	switch VAR_RESULT
# 582 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	case 11, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
# 583 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	case MULTI_B_PRESSED, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
# 584 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 585 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 586 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x8006, VAR_0x800A
# 587 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 588 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special PutFanClubSpecialOnTheAir
# 589 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview
# 590 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 591 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 592 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer:: @ 821CE9F
# 593 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 594 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 595 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
# 596 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, YES
# 597 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
# 598 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	compare VAR_RESULT, NO
# 599 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	goto_if_eq LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
# 600 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 601 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 602 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer:: @ 821CEC6
# 603 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 604 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 605 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
# 606 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 607 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 608 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 609 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview:: @ 821CED8
# 610 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 611 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 612 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
# 613 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
# 614 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 615 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 616 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 617 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed:: @ 821CEED
# 618 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	setvar VAR_0x8004, FANCLUB_MEMBER1
# 619 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	special BufferFanClubTrainerName
# 620 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	msgbox LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
# 621 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	release
# 622 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 623 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 624 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
@ Shouldnt be reached
# 625 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2:: @ 821CEFF
# 626 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	end
# 627 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 628 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer: @ 821CF00
# 629 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Oh, wow!\n"
# 630 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "It's {PLAYER}!$"
# 631 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 632 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan: @ 821CF12
# 633 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I've heard the news!\n"
# 634 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're really strong, aren't you?\p"
# 635 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "We always argue about who is the\n"
# 636 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "strongest of all Trainers here.\p"
# 637 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "So when I heard about you, I decided\n"
# 638 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "to be your fan!\p"
# 639 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I hope you'll keep on battling other\n"
# 640 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "tough Trainers.\p"
# 641 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That way, we'll be able to see more\n"
# 642 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "of your hot, hot battles.\p"
# 643 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That will make the others here see\n"
# 644 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "exactly how great you are.\p"
# 645 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Remember, I'm cheering for you,\n"
# 646 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{PLAYER}!$"
# 647 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 648 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin: @ 821D094
# 649 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Yo, {PLAYER}!\n"
# 650 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're the one we want to win!$"
# 651 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 652 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest: @ 821D0BB
# 653 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "The others, they don't know that\n"
# 654 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "you're the best of the best!\p"
# 655 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Isn't that right, {PLAYER}?\n"
# 656 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Show them you've got guts!$"
# 657 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 658 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary: @ 821D12A
# 659 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I hate to say this, but the Trainer\n"
# 660 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "everybody's talking about is\l"
# 661 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1}, no question about it!\p"
# 662 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That Trainer's power…\n"
# 663 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "It's out of the ordinary.$"
# 664 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 665 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen: @ 821D1B5
# 666 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Darn it… I've been telling people\n"
# 667 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "that {STR_VAR_1} is the best now…\p"
# 668 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But no one wants to listen…$"
# 669 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 670 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer: @ 821D20C
# 671 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I've been hearing things about\n"
# 672 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "a tough new Trainer.\p"
# 673 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "This Trainer's supposed to be beating\n"
# 674 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Gym Leaders, even.\p"
# 675 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Do you know anything about this\n"
# 676 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "new Trainer?$"
# 677 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 678 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou: @ 821D2A6
# 679 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Oh!\n"
# 680 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{PLAYER}!\p"
# 681 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Go for it!\n"
# 682 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm pulling for you!$"
# 683 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 684 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan: @ 821D2CE
# 685 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Sigh…\n"
# 686 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Brawly…\p"
# 687 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Oh, no! Wait!\n"
# 688 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That's not right! No, no, no!\p"
# 689 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm your fan through and through!\p"
# 690 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "So make me proud!\n"
# 691 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Go for it!$"
# 692 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 693 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly: @ 821D347
# 694 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I can't help it, I can only get to\n"
# 695 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "like Brawly…$"
# 696 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 697 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly: @ 821D377
# 698 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Nobody understands the charm of\n"
# 699 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Brawly…\p"
# 700 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I don't care!\p"
# 701 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even if I'm the only one, I'm going\n"
# 702 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "to keep cheering for Brawly!$"
# 703 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 704 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly: @ 821D3EE
# 705 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Whatever anyone says, my favorite\n"
# 706 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Trainer is Dewford's Gym Leader\l"
# 707 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Brawly!$"
# 708 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 709 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather: @ 821D438
# 710 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You've surpassed your own father in\n"
# 711 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "every regard!\p"
# 712 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm telling you, so there's no question\n"
# 713 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "about it at all!$"
# 714 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 715 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling: @ 821D4A3
# 716 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even when things turned bleak,\n"
# 717 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "your father never gave up.\p"
# 718 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "This I know to be true.\p"
# 719 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You never give up even if you lose!\n"
# 720 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "So keep on battling!$"
# 721 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 722 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman: @ 821D52E
# 723 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Norman battled with more power,\n"
# 724 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "charisma, and showmanship than you.\p"
# 725 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even though people may say that\n"
# 726 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "you're strong…\p"
# 727 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You've still got a long way to go\n"
# 728 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "compared to your father.$"
# 729 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 730 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent: @ 821D5DC
# 731 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're beginning to get the same\n"
# 732 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "air of awe Norman exudes.\p"
# 733 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But there's something conclusively\n"
# 734 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "different between you and Norman.\p"
# 735 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I can't tell you what that is.\n"
# 736 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You'll have to find it yourself.$"
# 737 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 738 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers: @ 821D69C
# 739 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Everyone here, we're all huge fans\n"
# 740 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "of Pokémon battles.\p"
# 741 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "We discuss who we consider to be\n"
# 742 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "the strongest of all Trainers.\p"
# 743 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "If you were to become famous,\n"
# 744 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "we might even become your fans!$"
# 745 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 746 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer: @ 821D751
# 747 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Oh, woweee! It's {PLAYER}!\n"
# 748 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "For real, too!\p"
# 749 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Please, shake my hand, shake my hand!$"
# 750 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 751 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou: @ 821D79B
# 752 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'll always cheer for you, {PLAYER}!\n"
# 753 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Always, always!\p"
# 754 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I don't want to see you lose ever,\n"
# 755 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{PLAYER}.\p"
# 756 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Because I know you're really,\n"
# 757 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "really strong, {PLAYER}!$"
# 758 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 759 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool: @ 821D822
# 760 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} is really cool…\p"
# 761 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Everyone thinks so, right, right?$"
# 762 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 763 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe: @ 821D857
# 764 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} really is cool, don't\n"
# 765 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "you think so?\p"
# 766 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even if it's just me, I'm going to keep\n"
# 767 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "cheering my favorite Trainer.$"
# 768 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 769 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat: @ 821D8C4
# 770 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "My favorite Trainer is…\p"
# 771 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Cool…\p"
# 772 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Strong…\p"
# 773 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "And really nice…\p"
# 774 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I wish there was a Trainer like that…$"
# 775 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 776 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou: @ 821D921
# 777 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Whoa! It's {PLAYER}!\n"
# 778 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Wicked!\p"
# 779 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "When I grow up, I want to be strong\n"
# 780 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "like you, {PLAYER}!$"
# 781 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 782 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou: @ 821D96A
# 783 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even if I'm the only one…\p"
# 784 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You'll always be the only one\n"
# 785 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I cheer for, {PLAYER}!\p"
# 786 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Because I believe in you, {PLAYER}!$"
# 787 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 788 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool: @ 821D9D1
# 789 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} is so wickedly cool…\n"
# 790 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I want to shake hands with my hero.$"
# 791 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 792 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan: @ 821DA0D
# 793 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Even if I'm the only one…\p"
# 794 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm never going to stop being\n"
# 795 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1}'s fan!\p"
# 796 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Because I've heard, {STR_VAR_1}\n"
# 797 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "never loses!$"
# 798 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 799 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll: @ 821DA73
# 800 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{PLAYER}!\n"
# 801 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You are amazing after all!\p"
# 802 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Ever since I set eyes on you,\n"
# 803 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I knew that you were great.\p"
# 804 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "It looks like my eyes didn't deceive me.$"
# 805 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 806 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner: @ 821DAF5
# 807 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Who cares about the others.\n"
# 808 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm in your corner!\p"
# 809 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You don't need to worry. Just get\n"
# 810 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "out there and battle like always.$"
# 811 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 812 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne: @ 821DB69
# 813 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're a pretty decent Trainer,\n"
# 814 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I think.\p"
# 815 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But I also think that {STR_VAR_1}\n"
# 816 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "is number one right now.\p"
# 817 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That's just my opinion.\n"
# 818 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Don't worry about it too much.$"
# 819 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 820 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer: @ 821DBFB
# 821 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Wow, you really are strong.\n"
# 822 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Maybe even stronger than {STR_VAR_1}.\p"
# 823 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But {STR_VAR_1} needs me.\p"
# 824 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "If I don't cheer for {STR_VAR_1},\n"
# 825 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "who will?$"
# 826 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 827 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind: @ 821DC68
# 828 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You've changed my mind!\n"
# 829 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You are strong, aren't you?\p"
# 830 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'd like you to tell me how you managed\n"
# 831 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "to get so strong!$"
# 832 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 833 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation: @ 821DCD6
# 834 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "The tougher the situation, the more\n"
# 835 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "attractively you battle.\p"
# 836 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I can't wait for your next battle!$"
# 837 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 838 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout: @ 821DD36
# 839 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Among the recently hot Trainers,\n"
# 840 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} is the standout.\p"
# 841 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That toughness, it's simply not normal.\p"
# 842 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're doing okay, but you're not in\n"
# 843 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "the same class as {STR_VAR_1}.$"
# 844 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 845 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger: @ 821DDCE
# 846 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You are really popular…\p"
# 847 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You're strong, and you're caring to\n"
# 848 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Pokémon. No one can knock you.\p"
# 849 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But, you know, I believe in {STR_VAR_1}.\p"
# 850 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "{STR_VAR_1} is definitely stronger!\n"
# 851 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I'm positive!$"
# 852 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 853 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive: @ 821DE72
# 854 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You…\p"
# 855 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Impressive!$"
# 856 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 857 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth: @ 821DE83
# 858 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Your true worth, it is fine if only\n"
# 859 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I recognized it.\p"
# 860 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "The others I doubt will understand\n"
# 861 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "the hidden power that beats within.$"
# 862 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 863 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential: @ 821DEFF
# 864 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Yes, I see strength in your eyes.\p"
# 865 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But!\p"
# 866 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "You still haven't realized your\n"
# 867 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "potential.$"
# 868 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"

# 869 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength: @ 821DF51
# 870 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "It is true that you are tremendously\n"
# 871 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "powerful.\p"
# 872 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "But!\n"
# 873 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "I can tell…\p"
# 874 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "That strength cannot be considered\n"
# 875 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "true strength yet!\p"
# 876 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "True strength is…!\n"
# 877 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "… …\p"
# 878 "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.pory"
	.string "Actually, I have no idea, either.$"
