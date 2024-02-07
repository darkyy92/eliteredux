# 1 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 2 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_RICH_BOY, 1
# 3 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_GENTLEMAN, 2
# 4 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_SCIENTIST, 3
# 5 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_STEVEN, 4
# 6 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
@ Grunt names numbered like their Trainer values (which are for the full Space Center)
# 7 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_GRUNT_6, 5
# 8 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_GRUNT_5, 6
# 9 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_GRUNT_7, 7
# 10 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_COURTNEY, 8
# 11 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_MAXIE, 9
# 12 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
.set LOCALID_TABITHA, 10
# 13 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 14 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_MapScripts:: @ 8223D58
# 15 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
# 16 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_OnFrame
# 17 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.byte 0
# 18 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 19 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_OnTransition: @ 8223D63
# 20 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 21 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians
# 22 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
# 23 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts
# 24 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 25 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 26 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_MoveCivilians:: @ 8223D7A
# 27 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
# 28 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 5, 3
# 29 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
# 30 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_RICH_BOY, 3, 2
# 31 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_RIGHT
# 32 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_GENTLEMAN, 1, 3
# 33 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectmovementtype LOCALID_GENTLEMAN, MOVEMENT_TYPE_FACE_RIGHT
# 34 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 35 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 36 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_MoveDefeatedGrunts:: @ 8223D9F
# 37 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_GRUNT_6, 11, 2
# 38 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_GRUNT_7, 15, 2
# 39 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_GRUNT_5, 13, 4
# 40 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 41 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 42 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_OnFrame: @ 8223DB5
# 43 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE, 1, MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts
# 44 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.2byte 0
# 45 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 46 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ThreeMagmaGrunts:: @ 8223DBF
# 47 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	playse SE_PIN
# 48 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 49 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 50 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 51 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 52 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn, MSGBOX_YESNO
# 53 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_RESULT, YES
# 54 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
# 55 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_GoodAnswer, MSGBOX_DEFAULT
# 56 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 57 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_PlayerExit
# 58 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 59 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 255, 13, 1
# 60 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitstate
# 61 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 62 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 63 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 64 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_PlayerExit: @ 8223E07
# 65 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_up
# 66 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 67 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 68 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts:: @ 8223E09
# 69 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_SYS_DISABLE_AUTOHEAL
# 70 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	special HealPlayerParty
# 71 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro, MSGBOX_DEFAULT
# 72 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_5, MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat
# 73 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_GRUNT_5, MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated
# 74 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 75 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 76 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 77 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro, MSGBOX_DEFAULT
# 78 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_6, MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat
# 79 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_GRUNT_6, MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated
# 80 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 81 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 82 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 83 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro, MSGBOX_DEFAULT
# 84 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_7, MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat
# 85 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_GRUNT_7, MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated
# 86 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 87 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	clearflag FLAG_SYS_DISABLE_AUTOHEAL
# 88 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2
# 89 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT_6
# 90 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT_7
# 91 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	copyobjectxytoperm LOCALID_GRUNT_5
# 92 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 93 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 94 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 95 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated: @ 8223E81
# 96 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 97 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_left
# 98 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 99 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 100 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 101 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated: @ 8223E85
# 102 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 103 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_down
# 104 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 105 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 106 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 107 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated: @ 8223E89
# 108 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 109 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_right
# 110 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 111 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 112 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 113 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Scientist:: @ 8223E8D
# 114 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock
# 115 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	faceplayer
# 116 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
# 117 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 118 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
# 119 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 120 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal
# 121 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma
# 122 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 123 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 124 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ScientistNormal:: @ 8223EB4
# 125 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets, MSGBOX_DEFAULT
# 126 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 127 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 128 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 129 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ScientistMagma:: @ 8223EBE
# 130 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel, MSGBOX_DEFAULT
# 131 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 132 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 133 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 134 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Gentleman:: @ 8223EC8
# 135 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock
# 136 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	faceplayer
# 137 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
# 138 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 139 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
# 140 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 141 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal
# 142 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma
# 143 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 144 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 145 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_GentlemanNormal:: @ 8223EEF
# 146 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut, MSGBOX_DEFAULT
# 147 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 148 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 149 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 150 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_GentlemanMagma:: @ 8223EF9
# 151 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis, MSGBOX_DEFAULT
# 152 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 153 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 154 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 155 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_RichBoy:: @ 8223F03
# 156 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock
# 157 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	faceplayer
# 158 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
# 159 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 160 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
# 161 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_MOSSDEEP_CITY_STATE, 2
# 162 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal
# 163 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma
# 164 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 165 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 166 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_RichBoyNormal:: @ 8223F2A
# 167 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace, MSGBOX_DEFAULT
# 168 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 169 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 170 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 171 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_RichBoyMagma:: @ 8223F34
# 172 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace, MSGBOX_DEFAULT
# 173 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 174 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 175 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 176 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
@ Battle for the below 3 grunts is handled in MossdeepCity_SpaceCenter_2F_EventScript_BattleThreeMagmaGrunts
# 177 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Grunt6:: @ 8223F3E
# 178 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle, MSGBOX_NPC
# 179 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 180 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 181 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Grunt7:: @ 8223F47
# 182 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle, MSGBOX_NPC
# 183 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 184 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 185 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Grunt5:: @ 8223F50
# 186 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle, MSGBOX_NPC
# 187 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 188 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 189 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Courtney:: @ 8223F59
# 190 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock
# 191 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	faceplayer
# 192 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou, MSGBOX_DEFAULT
# 193 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 194 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 195 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	release
# 196 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 197 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 198 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Maxie:: @ 8223F6F
# 199 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lockall
# 200 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere, MSGBOX_DEFAULT
# 201 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 202 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 203 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 204 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Steven:: @ 8223F7A
# 205 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lockall
# 206 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
# 207 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
# 208 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel, MSGBOX_DEFAULT
# 209 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano, MSGBOX_DEFAULT
# 210 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 211 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay 30
# 212 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 213 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	switch VAR_FACING
# 214 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth
# 215 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFight
# 216 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 217 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 218 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 219 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 220 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_StevenFightMovementSouth:: @ 8223FBA
# 221 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_STEVEN, MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth
# 222 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 223 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 224 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 225 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 226 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_StevenFight: @ 8223FC6
# 227 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 228 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_fast_up
# 229 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_fast_up
# 230 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 231 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay_16
# 232 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay_16
# 233 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_slow_down
# 234 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_slow_down
# 235 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 236 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 237 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth: @ 8223FCF
# 238 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	face_left
# 239 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lock_facing_direction
# 240 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_fast_right
# 241 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_fast_right
# 242 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	unlock_facing_direction
# 243 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay_16
# 244 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay_16
# 245 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_slow_left
# 246 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	walk_slow_left
# 247 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	face_down
# 248 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	step_end
# 249 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 250 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt:: @ 8223FDA
# 251 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 252 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 253 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle, MSGBOX_YESNO
# 254 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_RESULT, YES
# 255 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
# 256 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly, MSGBOX_DEFAULT
# 257 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 258 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 259 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 260 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 261 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 262 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 263 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle:: @ 822400C
# 264 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	special HealPlayerParty
# 265 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 266 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 267 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
    msgbox MossdeepCity_SpaceCenter_Text_ChooseMons, MSGBOX_DEFAULT
# 268 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
    choose_mons
# 269 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
    compare VAR_RESULT, 0
# 270 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
    goto_if_ne MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle
# 271 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
    goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt
# 272 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 273 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle::
# 274 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
    multi_2_vs_2 TRAINER_MAXIE_MOSSDEEP, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, TRAINER_COURTNEY_MOSSDEEP, MossdeepCity_SpaceCenter_Text_CourtneyDefeat, TRAINER_STEVEN_MOSSDEEP, TRAINER_BACK_PIC_STEVEN
# 275 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 276 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 277 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_Lost
# 278 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided, MSGBOX_DEFAULT
# 279 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 280 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay 20
# 281 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestLeft
# 282 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_COURTNEY, Common_Movement_WalkInPlaceFastestDown
# 283 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 284 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay 60
# 285 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestUp
# 286 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	applymovement LOCALID_COURTNEY, Common_Movement_WalkInPlaceFastestRight
# 287 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmovement 0
# 288 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	delay 20
# 289 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp, MSGBOX_DEFAULT
# 290 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 291 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 3
# 292 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadedefaultbgm
# 293 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 294 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 3
# 295 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
# 296 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
# 297 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 298 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_GRUNT_6
# 299 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_GRUNT_7
# 300 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_GRUNT_5
# 301 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_COURTNEY
# 302 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_MAXIE
# 303 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_TABITHA
# 304 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxy LOCALID_SCIENTIST, 5, 6
# 305 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_SCIENTIST, DIR_SOUTH
# 306 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxy LOCALID_GENTLEMAN, 11, 8
# 307 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_GENTLEMAN, DIR_NORTH
# 308 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxy LOCALID_RICH_BOY, 6, 2
# 309 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_RICH_BOY, DIR_NORTH
# 310 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer
# 311 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 312 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome, MSGBOX_DEFAULT
# 313 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 314 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 315 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 316 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 317 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_STEVEN
# 318 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
# 319 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 320 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 1
# 321 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
# 322 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	removeobject LOCALID_SCIENTIST
# 323 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 5, 6
# 324 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_WANDER_AROUND
# 325 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	addobject LOCALID_SCIENTIST
# 326 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 327 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 328 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 329 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_Lost::
# 330 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 331 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	special SetCB2WhiteOut
# 332 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitstate
# 333 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 334 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayer:: @ 8224131
# 335 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	switch VAR_FACING
# 336 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	case DIR_SOUTH, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth
# 337 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	case DIR_WEST, MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest
# 338 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 339 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 340 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerSouth:: @ 822414D
# 341 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_STEVEN, DIR_NORTH
# 342 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 343 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 344 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_StevenFacePlayerWest:: @ 8224152
# 345 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	turnobject LOCALID_STEVEN, DIR_EAST
# 346 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 347 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 348 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_MaxieTrainer:: @ 8224157
# 349 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_MAXIE_MOSSDEEP, 0, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand, MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand
# 350 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 351 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 352 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_CourtneyTrainer::
# 353 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_COURTNEY_MOSSDEEP, 0, MossdeepCity_SpaceCenter_Text_CourtneyDefeat, MossdeepCity_SpaceCenter_Text_CourtneyDefeat
# 354 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 355 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 356 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_1F_EventScript_Tabitha::
# 357 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MOSSDEEP, MossdeepCity_SpaceCenter_Text_TabithaIntro, MossdeepCity_SpaceCenter_Text_TabithaDefeat
# 358 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 359 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 360 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 361 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall:: @ 8224175
# 362 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	lockall
# 363 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	checkplayergender
# 364 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_RESULT, MALE
# 365 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall
# 366 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	compare VAR_RESULT, FEMALE
# 367 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall
# 368 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	closemessage
# 369 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
# 370 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	releaseall
# 371 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	end
# 372 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 373 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_MayRayquazaCall:: @ 8224193
# 374 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	pokenavcall MatchCall_Text_MayRayquazaCall
# 375 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmessage
# 376 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 377 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 378 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_EventScript_BrendanRayquazaCall:: @ 822419A
# 379 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	pokenavcall MatchCall_Text_BrendanRayquazaCall
# 380 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	waitmessage
# 381 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	return
# 382 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 383 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MossdeepIdealForRockets: @ 82241A1
# 384 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Mossdeep has mainly sunny weather,\n"
# 385 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "and its winds are stable.\p"
# 386 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "It's an ideal location for launching\n"
# 387 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "rockets.$"
# 388 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 389 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_WhyWouldMagmaStealRocketFuel: @ 822420C
# 390 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Why would Team Magma want to steal\n"
# 391 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "our rocket fuel in the first place?$"
# 392 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 393 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_WouldveLikedToBeAstronaut: @ 8224253
# 394 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If only I was a little younger, I would\n"
# 395 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "have liked being an astronaut…\p"
# 396 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "No… It's not too late!\n"
# 397 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I can and will try!$"
# 398 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 399 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MagmaCantGetAwayWithThis: @ 82242C5
# 400 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If Team Magma takes the rocket fuel,\n"
# 401 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I won't be able to go to space!\p"
# 402 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "They can't be allowed to get away\n"
# 403 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "with such an outrage!$"
# 404 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 405 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_WishOrdinaryPeopleCouldGoIntoSpace: @ 8224342
# 406 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I wish ordinary people could go into\n"
# 407 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "space one day…$"
# 408 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 409 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_DoesMagmaWantToGoToSpace: @ 8224376
# 410 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Team Magma…\n"
# 411 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Do they want to go to space, too?$"
# 412 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 413 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_YoureOutnumberedTakeUsOn: @ 82243A4
# 414 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "What's wrong with you?\p"
# 415 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "You're outnumbered three to one,\n"
# 416 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "but you still want to take us on?$"
# 417 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 418 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_GoodAnswer: @ 82243FE
# 419 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Good answer!\n"
# 420 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "That's what a smart person'll do!$"
# 421 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 422 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt5Intro: @ 822442D
# 423 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "A reckless go-getter, are you?\n"
# 424 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Okay, I'll go first!$"
# 425 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 426 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt5Defeat: @ 8224461
# 427 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I lost!\n"
# 428 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "But!$"
# 429 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 430 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt6Intro: @ 822446E
# 431 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "It's too soon to be relieved!\n"
# 432 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I'm up next!$"
# 433 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 434 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt6Defeat: @ 8224499
# 435 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I lost, too!\n"
# 436 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "But!$"
# 437 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 438 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt7Intro: @ 82244AB
# 439 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I bet you want to take a break.\n"
# 440 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "But I'm not about to let you do that!$"
# 441 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 442 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt7Defeat: @ 82244F1
# 443 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We should've taken a break…\n"
# 444 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "That's what we should've done…$"
# 445 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 446 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt6PostBattle: @ 822452C
# 447 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Three of us here, and look at the sorry\n"
# 448 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "mess we got ourselves into.$"
# 449 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 450 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt7PostBattle: @ 8224570
# 451 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We three losing like this…\n"
# 452 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We look worse than usual by triple!$"
# 453 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 454 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_Grunt5PostBattle: @ 82245AF
# 455 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Are we being useful to our leader\n"
# 456 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "at all?$"
# 457 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 458 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_WellTakeCareOfYou: @ 82245D9
# 459 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Ahahaha!\p"
# 460 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We come all the way here to get some\n"
# 461 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "fuel, and we're interfered with again!\p"
# 462 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If you're going to mess with us too,\n"
# 463 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "we'll take care of you at the same time!$"
# 464 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 465 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MaxieDontInterfere: @ 822467B
# 466 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Maxie: Clear out of the way!\n"
# 467 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Don't you dare interfere!$"
# 468 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 469 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_StevenWhyStealRocketFuel: @ 82246B2
# 470 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Steven: Team Magma…\p"
# 471 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "What's the point of stealing rocket\n"
# 472 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "fuel?$"
# 473 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 474 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MaxieUseFuelToEruptVolcano: @ 82246F0
# 475 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Maxie: Fufufu… Since you're so\n"
# 476 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "curious, you deserve an explanation.\p"
# 477 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We're going to jettison the entire\n"
# 478 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "load into Mt. Chimney!\p"
# 479 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "With Groudon gone, we have no need\n"
# 480 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "for that slag heap of a mountain!\p"
# 481 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "So we'll use the fuel's power to make\n"
# 482 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "the volcano erupt!\p"
# 483 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "It will be savage!$"
# 484 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 485 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_StevenAreYouReadyToBattle: @ 82247FF
# 486 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Steven: {PLAYER}{KUN}!\n"
# 487 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "You're going to help me?\p"
# 488 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Let's go into battle together!\n"
# 489 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Are you ready?$"
# 490 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 491 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_StevenHurryGetReadyQuickly: @ 8224854
# 492 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Steven: Then, hurry!\n"
# 493 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Get ready quickly!$"
# 494 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 495 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand: @ 822487C
# 496 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "All I want…\n"
# 497 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I just want to expand the land mass…$"
# 498 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 499 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_Text_CourtneyDefeat: @ 82248AD
# 500 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I'm with our leader…$"
# 501 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 502 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MaxieWeFailedIsAquaAlsoMisguided: @ 82248C2
# 503 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Maxie: We failed to make the volcano\n"
# 504 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "erupt…\p"
# 505 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We failed to control Groudon after\n"
# 506 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "we had awoken it…\p"
# 507 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Is our goal to expand the land\n"
# 508 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "misguided?\p"
# 509 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "… … … … … …\n"
# 510 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "… … … … … …\p"
# 511 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If…\n"
# 512 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "If we, Team Magma, are wrong…\l"
# 513 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "… … … … … …\p"
# 514 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Then might Team Aqua's goal to expand\n"
# 515 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "the sea also be equally misguided?$"
# 516 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 517 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_MaxieWeWillGiveUp: @ 82249DC
# 518 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Maxie: All right…\n"
# 519 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We will give up on the fuel…\p"
# 520 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "There appear to be more important\n"
# 521 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "matters that I must examine…$"
# 522 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 523 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_2F_Text_StevenThankYouComeSeeMeAtHome: @ 8224A4A
# 524 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Steven: Whew, that was too tense.\n"
# 525 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "{PLAYER}{KUN}, thank you.\p"
# 526 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I have something to give you as\n"
# 527 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "thanks for your support.\p"
# 528 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Please come see me at home\n"
# 529 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "after this.\p"
# 530 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Oh, yes, I don't live in Rustboro City.\n"
# 531 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "I live right here on this island.$"
# 532 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 533 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_Text_TabithaIntro:
# 534 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Hehehe!\p"
# 535 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "We're taking the fuel, and no amount\n"
# 536 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "of meddling is going to stop us!$"
# 537 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 538 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_Text_TabithaDefeat:
# 539 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Hehe…\n"
# 540 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Well, maybe that's enough to stop me…$"
# 541 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 542 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_Text_TabithaPostBattle:
# 543 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Hehe…\p"
# 544 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "It's all up to our Leader and Courtney\n"
# 545 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "now.$"
# 546 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"

# 547 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
MossdeepCity_SpaceCenter_Text_ChooseMons:
# 548 "data/maps/MossdeepCity_SpaceCenter_2F/scripts.pory"
	.string "Choose which Pokémon will battle.$"
