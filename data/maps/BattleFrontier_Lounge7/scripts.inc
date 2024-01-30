# 1 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 2 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_MapScripts:: @ 8265254
# 3 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 5 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_LeftMoveTutor:: @ 8265255
# 6 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	lock
# 7 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	faceplayer
# 8 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 9 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
# 10 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
# 11 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
# 12 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
# 13 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 14 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 15 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor:: @ 8265276
# 16 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
# 17 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
# 18 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 20 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove:: @ 8265284
# 21 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 22 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 23 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowBattlePointsWindow
# 24 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_E, 0
# 25 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 26 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 0
# 27 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 28 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 29 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 30 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 31 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
# 32 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
# 33 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
# 34 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
# 35 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
# 36 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
# 37 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
# 38 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_Counter
# 39 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
# 40 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
# 41 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 42 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 43 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 44 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 45 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove:: @ 826532F
# 46 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 47 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 48 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_E, 0
# 49 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
# 50 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 1
# 51 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 52 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 53 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 54 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 55 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
# 56 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
# 57 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
# 58 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
# 59 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
# 60 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
# 61 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
# 62 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_Counter
# 63 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
# 64 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
# 65 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 66 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 67 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 68 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 69 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Softboiled:: @ 82653D7
# 70 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 16
# 71 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 72 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 73 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 74 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_SeismicToss:: @ 82653E2
# 75 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 76 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 77 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 78 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 79 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_DreamEater:: @ 82653ED
# 80 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 81 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 82 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 83 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 84 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MegaPunch:: @ 82653F8
# 85 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 86 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 87 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 88 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 89 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MegaKick:: @ 8265403
# 90 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 91 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 92 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 93 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 94 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_BodySlam:: @ 826540E
# 95 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 96 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 97 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 98 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 99 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_RockSlide:: @ 8265419
# 100 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 101 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 102 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 103 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 104 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Counter:: @ 8265424
# 105 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 106 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 107 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 108 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 109 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ThunderWave:: @ 826542F
# 110 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 111 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 112 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 113 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 114 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_SwordsDance:: @ 826543A
# 115 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 116 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 117 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 118 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 119 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_RightMoveTutor:: @ 8265445
# 120 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	lock
# 121 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	faceplayer
# 122 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ScriptMenu_CreatePKMNCenterMoveTutorMultichoice
# 123 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 124 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special GetPKMNCenterMoveListMultichoice
# 125 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	switch VAR_RESULT
# 126 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 0, testBlock
# 127 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 1, testBlock
# 128 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 2, testBlock
# 129 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 3, testBlock
# 130 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 4, testBlock
# 131 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 5, testBlock
# 132 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 6, testBlock
# 133 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case 7, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 134 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 135 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 136 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 137 "data/maps/BattleFrontier_Lounge7/scripts.pory"
testBlock::
# 138 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_7
# 139 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
# 140 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 141 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 142 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor:: @ 8265466
# 143 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
# 144 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
# 145 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 146 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 147 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove:: @ 8265474
# 148 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 149 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 150 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_E, 6
# 151 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_7
# 152 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 0
# 153 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 154 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 155 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 156 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	compare VAR_RESULT 17
# 157 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 158 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	compare VAR_RESULT MULTI_B_PRESSED
# 159 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 160 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 161 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 162 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 163 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove:: @ 826551F
# 164 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	message BattleFrontier_Lounge7_Text_TeachWhichMove
# 165 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitmessage
# 166 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_TEMP_E, 6
# 167 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_7
# 168 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8006, 1
# 169 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ShowScrollableMultichoice
# 170 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 171 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_TEMP_D, VAR_RESULT
# 172 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	compare VAR_RESULT 17
# 173 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 174 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	compare VAR_RESULT MULTI_B_PRESSED
# 175 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
# 176 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 177 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 178 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 179 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_DefenseCurl:: @ 82655C7
# 180 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 16
# 181 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 182 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 183 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 184 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Snore:: @ 82655D2
# 185 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 186 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 187 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 188 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 189 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_MudSlap:: @ 82655DD
# 190 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 191 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 192 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 193 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 194 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Swift:: @ 82655E8
# 195 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 196 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 197 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 198 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 199 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_IcyWind:: @ 82655F3
# 200 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 24
# 201 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 202 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 203 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 204 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Endure:: @ 82655FE
# 205 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 206 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 207 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 208 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 209 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_PsychUp:: @ 8265609
# 210 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 211 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 212 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 213 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 214 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_IcePunch:: @ 8265614
# 215 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 216 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 217 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 218 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 219 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ThunderPunch:: @ 826561F
# 220 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 221 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 222 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 223 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 224 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_FirePunch:: @ 826562A
# 225 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	setvar VAR_0x8008, 48
# 226 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
# 227 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 228 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 229 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect:: @ 8265635
# 230 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattleFrontierTutorWindow
# 231 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattlePointsWindow
# 232 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
# 233 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 234 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 235 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 236 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_CancelChooseMon:: @ 8265645
# 237 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
# 238 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 239 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 240 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 241 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_0x8008 is the price
# 242 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_C is the scroll multichoice ID
# 243 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_D is the move selection
# 244 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ VAR_TEMP_E is which move tutor was spoken to
# 245 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection:: @ 826564F
# 246 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_D
# 247 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_0x8005, VAR_TEMP_E
# 248 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special BufferBattleFrontierTutorMoveName
# 249 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	buffernumberstring 1, VAR_0x8008
# 250 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_C
# 251 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
# 252 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	compare VAR_RESULT, NO
# 253 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq BattleFrontier_Lounge7_EventScript_ChooseNewMove
# 254 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_TeachTutorMove
# 255 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 256 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 257 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_TeachTutorMove:: @ 8265696
# 258 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
# 259 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special GetBattleFrontierTutorMoveIndex
# 260 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	fadescreen FADE_TO_BLACK
# 261 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattlePointsWindow
# 262 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special CloseBattleFrontierTutorWindow
# 263 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	special ChooseMonForMoveTutor
# 264 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	waitstate
# 265 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	compare VAR_RESULT, FALSE
# 266 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq BattleFrontier_Lounge7_EventScript_CancelChooseMon
# 267 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
# 268 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	release
# 269 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 270 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 271 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_ChooseNewMove:: @ 82656CA
# 272 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	compare VAR_TEMP_E, 0
# 273 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto_if_eq BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
# 274 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
# 275 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 276 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 277 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Sailor:: @ 82656DB
# 278 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
# 279 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 280 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 281 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_EventScript_Gentleman:: @ 82656E4
# 282 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
# 283 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	end
# 284 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 285 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LeftTutorIntro: @ 82656ED
# 286 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Buhahaha!\p"
# 287 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You couldn't tell it from looking now,\n"
# 288 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "but I used to be one tough Trainer.\p"
# 289 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I had a reputation as the toughest\n"
# 290 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "BEAUTY around, I tell you!\p"
# 291 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "… … … … … …\p"
# 292 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What is it now?\n"
# 293 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't believe me.\p"
# 294 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'm not like that blowhard woman over\n"
# 295 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "there. I'm actually talented!\p"
# 296 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Let me prove it to you.\n"
# 297 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can teach your Pokémon special and\l"
# 298 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet cute moves.\p"
# 299 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But my lessons don't come free.\n"
# 300 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "How about paying for the moves I teach\l"
# 301 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with a wee bit of Battle Points?$"
# 302 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 303 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack: @ 82658AB
# 304 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Buhahaha!\p"
# 305 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Are you back to learn special and\n"
# 306 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet cute Pokémon moves?$"
# 307 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 308 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_TeachWhichMove: @ 82658EF
# 309 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fine, fine, look here!\n"
# 310 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Which move should I teach?$"
# 311 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 312 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints: @ 8265921
# 313 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "The move {STR_VAR_1}, is it?\n"
# 314 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"
# 315 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 316 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_TeachMoveToWhichMon: @ 826595A
# 317 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fine, fine, now pick the Pokémon\n"
# 318 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I should teach the move to.$"
# 319 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 320 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_HaventGotEnoughPoints: @ 8265997
# 321 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What the…\n"
# 322 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You haven't got enough Battle Points!$"
# 323 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 324 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IllTakeBattlePoints: @ 82659C7
# 325 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Do you see how skilled I am now?\n"
# 326 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'll take your Battle Points, thanks!$"
# 327 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 328 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_YouDontWantTo: @ 8265A0E
# 329 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What's that?\n"
# 330 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't want to…\p"
# 331 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "If you want to see how skilled I am,\n"
# 332 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "you come see me anytime!$"
# 333 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 334 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RightTutorIntro: @ 8265A6C
# 335 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ihihihi!\p"
# 336 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I know it's hard to see now, but I used\n"
# 337 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "to be one fantastic Trainer.\p"
# 338 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I had a reputation as the most\n"
# 339 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "invincible SWIMMER around, I tell you!\p"
# 340 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "… … … … … …\p"
# 341 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "What's wrong?\n"
# 342 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "You don't believe me.\p"
# 343 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I'm not like that buffoonish woman over\n"
# 344 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "there. I'm actually experienced!\p"
# 345 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can prove it to you.\n"
# 346 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "I can teach your Pokémon hard and\l"
# 347 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet pretty moves.\p"
# 348 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But my lessons don't come free.\n"
# 349 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "How about paying for the moves I teach\l"
# 350 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with a wee bit of Battle Points?$"
# 351 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 352 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RightTutorWelcomeBack: @ 8265C2C
# 353 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ihihihi!\p"
# 354 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Have you come to learn hard and\n"
# 355 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "yet pretty Pokémon moves?$"
# 356 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 357 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong: @ 8265C6F
# 358 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Those ladies, the way they bad-mouth\n"
# 359 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "each other, you probably think that\l"
# 360 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "they don't get along.\p"
# 361 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But if that were true, they wouldn't\n"
# 362 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "stay out here together, would they?$"
# 363 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 364 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful: @ 8265D17
# 365 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "When I was just a wee YOUNGSTER,\n"
# 366 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "those ladies were strong and beautiful.\p"
# 367 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "They were idols among us Trainers.\p"
# 368 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Even now, age hasn't dulled their\n"
# 369 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "abilities.\p"
# 370 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "In fact, their Pokémon moves have\n"
# 371 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "grown even more polished.\p"
# 372 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "But… For some reason, I can't help\n"
# 373 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "but feel this…\p"
# 374 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Time is so cruel…$"
# 375 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 376 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SoftboiledDesc:: @ 8265E30
# 377 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Recovers up to\n"
# 378 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "half the user's\n"
# 379 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "maximum HP.$"
# 380 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 381 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SeismicTossDesc:: @ 8265E5B
# 382 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Inflicts damage\n"
# 383 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "identical to the\n"
# 384 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "user's level.$"
# 385 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 386 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_DreamEaterDesc:: @ 8265E8A
# 387 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Recovers half the\n"
# 388 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "damage inflicted\n"
# 389 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "on a sleeping foe.$"
# 390 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 391 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MegaPunchDesc:: @ 8265EC0
# 392 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A strong punch\n"
# 393 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "thrown with\n"
# 394 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "incredible power.$"
# 395 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 396 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MegaKickDesc:: @ 8265EED
# 397 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An extremely\n"
# 398 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "powerful kick with\n"
# 399 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "intense force.$"
# 400 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 401 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_BodySlamDesc:: @ 8265F1C
# 402 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A full-body slam\n"
# 403 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may cause\n"
# 404 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralysis.$"
# 405 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 406 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_RockSlideDesc:: @ 8265F47
# 407 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Large boulders\n"
# 408 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "are hurled. May\n"
# 409 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "cause flinching.$"
# 410 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 411 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_CounterDesc:: @ 8265F77
# 412 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Retaliates any\n"
# 413 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "physical hit with\n"
# 414 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "double the power.$"
# 415 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 416 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThunderWaveDesc:: @ 8265FAA
# 417 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A weak jolt of\n"
# 418 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "electricity that\n"
# 419 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralyzes the foe.$"
# 420 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 421 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SwordsDanceDesc:: @ 8265FDD
# 422 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A fighting dance\n"
# 423 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that sharply\n"
# 424 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "raises ATTACK.$"
# 425 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 426 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_DefenseCurlDesc:: @ 826600A
# 427 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Curls up to con-\n"
# 428 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ceal weak spots\n"
# 429 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "and raise DEFENSE.$"
# 430 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 431 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SnoreDesc:: @ 826603E
# 432 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A loud attack\n"
# 433 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that can be used\n"
# 434 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "only while asleep.$"
# 435 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 436 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_MudSlapDesc:: @ 8266070
# 437 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hurls mud in the\n"
# 438 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's face to re-\n"
# 439 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "duce its accuracy.$"
# 440 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 441 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_SwiftDesc:: @ 82660A6
# 442 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sprays star-\n"
# 443 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "shaped rays\n"
# 444 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that never miss.$"
# 445 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 446 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IcyWindDesc:: @ 82660D0
# 447 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A chilling attack\n"
# 448 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that lowers the\n"
# 449 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's SPEED.$"
# 450 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 451 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_EndureDesc:: @ 82660FF
# 452 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Endures any at-\n"
# 453 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "tack for 1 turn,\n"
# 454 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "leaving 1HP.$"
# 455 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 456 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_PsychUpDesc:: @ 826612D
# 457 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Copies the foe's\n"
# 458 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "effect(s) and\n"
# 459 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "gives to the user.$"
# 460 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 461 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_IcePunchDesc:: @ 826615F
# 462 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An icy punch\n"
# 463 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may\n"
# 464 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "freeze the foe.$"
# 465 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 466 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_ThunderPunchDesc:: @ 8266185
# 467 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An electrified\n"
# 468 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "punch that may\n"
# 469 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralyze the foe.$"
# 470 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 471 "data/maps/BattleFrontier_Lounge7/scripts.pory"
BattleFrontier_Lounge7_Text_FirePunchDesc:: @ 82661B5
# 472 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A fiery punch\n"
# 473 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may burn\n"
# 474 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the foe.$"
# 475 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 476 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@@@@@
# 477 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 478 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ Set 1
# 479 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_FuryCutterDesc::
# 480 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An attack that\n"
# 481 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "intensifies on\n"
# 482 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "successive hits.$"
# 483 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 484 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_RolloutDesc::
# 485 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An attack that\n"
# 486 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "intensifies each\n"
# 487 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "turn.$"
# 488 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 489 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SeismicTossDesc::
# 490 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Inflicts damage\n"
# 491 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "identical to the\n"
# 492 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "user's level.$"
# 493 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 494 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_CovetDesc::
# 495 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Cutely begs to\n"
# 496 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "steal the foe's\n"
# 497 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "held item.$"
# 498 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 499 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_VacuumWaveDesc::
# 500 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A wave of pure\n"
# 501 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "vacuum that al-\n"
# 502 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ways goes first.$"
# 503 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 504 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ShockWaveDesc::
# 505 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A rapid jolt of\n"
# 506 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "electricity that\n"
# 507 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "can't be avoided.$"
# 508 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 509 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_BugBiteDesc::
# 510 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Steals and eats\n"
# 511 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the target's held\n"
# 512 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Berry.$"
# 513 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 514 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_AirCutterDesc::
# 515 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hits both foes.\n"
# 516 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "High critical hit\n"
# 517 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ratio.$"
# 518 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 519 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SwiftDesc::
# 520 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sprays star-\n"
# 521 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "shaped rays\n"
# 522 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that never miss.$"
# 523 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 524 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SnatchDesc::
# 525 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Steals effects\n"
# 526 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "of the target's\n"
# 527 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "next move.$"
# 528 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 529 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MimicDesc::
# 530 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Copies a move\n"
# 531 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "used by the foe\n"
# 532 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "for one battle.$"
# 533 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 534 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MudSlapDesc::
# 535 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hurls mud in the\n"
# 536 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's face to re-\n"
# 537 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "duce its accuracy.$"
# 538 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 539 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MetronomeDesc::
# 540 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Waggles a finger\n"
# 541 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "to use any move\n"
# 542 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "at random.$"
# 543 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 544 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_OminousWindDesc::
# 545 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A repulsive gust\n"
# 546 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "of wind that may\n"
# 547 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "raise all stats.$"
# 548 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 549 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SuperFangDesc::
# 550 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Bites with sharp\n"
# 551 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "fangs and halves\n"
# 552 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the foe's HP.$"
# 553 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 554 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HoneClawsDesc::
# 555 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sharpens claws\n"
# 556 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "to boost Attack\n"
# 557 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "and accuracy.$"
# 558 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 559 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PsychUpDesc::
# 560 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Copies the foe's\n"
# 561 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "effect(s) and\n"
# 562 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "gives to the user.$"
# 563 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 564 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_FocusEnergyDesc::
# 565 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Focuses power to\n"
# 566 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "raise critical-hit\n"
# 567 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ratio.$"
# 568 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 569 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SpikesDesc::
# 570 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sets spikes that\n"
# 571 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "hurt a foe\n"
# 572 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "switching in.$"
# 573 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 574 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_InfestationDesc::
# 575 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Infests and\n"
# 576 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "attacks the foe\n"
# 577 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "for 2 to 5 turns.$"
# 578 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 579 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ Set 2
# 580 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_CounterDesc::
# 581 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Retaliates any\n"
# 582 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "physical hit with\n"
# 583 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "double the power.$"
# 584 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 585 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_EndeavorDesc::
# 586 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Cuts the target's\n"
# 587 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "HP to equal the\n"
# 588 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "user's HP.$"
# 589 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 590 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_WorrySeedDesc::
# 591 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Makes target's\n"
# 592 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ability Insomnia,\n"
# 593 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "preventing sleep.$"
# 594 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 595 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_DefenseCurlDesc::
# 596 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Curls up to con-\n"
# 597 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ceal weak spots\n"
# 598 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "and raise Defense.$"
# 599 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 600 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_DefogDesc::
# 601 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Blows away spikes,\n"
# 602 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "screens, etc. Also\n"
# 603 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "lowers evasion.$"
# 604 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 605 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MagicCoatDesc::
# 606 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Reflects Leech\n"
# 607 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Seed and status\n"
# 608 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "effects.$"
# 609 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 610 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_UproarDesc::
# 611 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Causes an uproar\n"
# 612 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "for three turns,\n"
# 613 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "preventing sleep.$"
# 614 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 615 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HexDesc::
# 616 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Doubles damage if\n"
# 617 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the target has a\n"
# 618 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "status condition.$"
# 619 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 620 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_GastroAcidDesc::
# 621 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hurls stomach\n"
# 622 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "acid to nullify\n"
# 623 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "target's Ability.$"
# 624 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 625 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SynthesisDesc::
# 626 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Restores HP. The\n"
# 627 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "amount varies\n"
# 628 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with the weather.$"
# 629 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 630 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PainSplitDesc::
# 631 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Adds the user and\n"
# 632 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "target's HP, then\n"
# 633 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "shares it equally.$"
# 634 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 635 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_LowKickDesc::
# 636 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A kick that does\n"
# 637 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "more damage to\n"
# 638 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "heavier targets.$"
# 639 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 640 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_IronDefenseDesc::
# 641 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Body surface is\n"
# 642 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "hardened, sharply\n"
# 643 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "raising Defense.$"
# 644 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 645 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MagnetRiseDesc::
# 646 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Levitates using\n"
# 647 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "electromagnetism\n"
# 648 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "for five turns.$"
# 649 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 650 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SwaggerDesc::
# 651 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Confuses target,\n"
# 652 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "but sharply raises\n"
# 653 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "its Attack stat.$"
# 654 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 655 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PinMissileDesc::
# 656 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fires sharp pins\n"
# 657 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that strike 2 to 5\n"
# 658 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "times.$"
# 659 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 660 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MudShotDesc::
# 661 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hurls mud at the\n"
# 662 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "target, reducing\n"
# 663 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "its Speed stat.$"
# 664 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 665 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_AgilityDesc::
# 666 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Relaxes the body\n"
# 667 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "to sharply boost\n"
# 668 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Speed.$"
# 669 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 670 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ Set 3
# 671 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SignalBeamDesc::
# 672 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A sinister beam\n"
# 673 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may also\n"
# 674 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "cause confusion.$"
# 675 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 676 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_GravityDesc::
# 677 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "For 5 turns flight\n"
# 678 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "is impossible and\n"
# 679 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "accuracy rises.$"
# 680 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 681 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SeedBombDesc::
# 682 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A barrage of hard-\n"
# 683 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "shelled seeds is\n"
# 684 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "rained on the foe.$"
# 685 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 686 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PsychoCutDesc::
# 687 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Has an increased\n"
# 688 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "critical-hit\n"
# 689 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ratio.$"
# 690 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 691 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_IcyWindDesc::
# 692 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A chilling attack\n"
# 693 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that lowers the\n"
# 694 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's Speed.$"
# 695 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 696 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ElectroWebDesc::
# 697 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An electric net\n"
# 698 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "captures foes.\n"
# 699 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Lowers Speed.$"
# 700 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 701 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ThunderFangDesc::
# 702 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An electrified\n"
# 703 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "bite that may\n"
# 704 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralyze the foe.$"
# 705 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 706 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_FireFangDesc::
# 707 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A fiery bite\n"
# 708 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may burn\n"
# 709 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the foe.$"
# 710 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 711 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_IceFangDesc::
# 712 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An icy bite\n"
# 713 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may\n"
# 714 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "freeze the foe.$"
# 715 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 716 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_BrineDesc::
# 717 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Power is doubled\n"
# 718 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "if foe's HP is\n"
# 719 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "half or less.$"
# 720 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 721 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_RazorShellDesc::
# 722 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "High critical-hit\n"
# 723 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ratio. May also\n"
# 724 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "lower Defense.$"
# 725 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 726 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_RevengeDesc::
# 727 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Doubles damage\n"
# 728 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "if user was hurt\n"
# 729 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "by foe this turn.$"
# 730 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 731 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_DrainingKissDesc::
# 732 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A kiss that steals\n"
# 733 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "half the damage\n"
# 734 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "inflicted.$"
# 735 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 736 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_LeafBladeDesc::
# 737 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Has an increased\n"
# 738 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "critical-hit\n"
# 739 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ratio.$"
# 740 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 741 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_RockBlastDesc::
# 742 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hurls boulders at\n"
# 743 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the foe 2 to 5\n"
# 744 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "times in a row.$"
# 745 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 746 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SoftBoiledDesc::
# 747 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Recovers up to\n"
# 748 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "half the user's\n"
# 749 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "maximum HP.$"
# 750 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 751 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_AuroraBeamDesc::
# 752 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fires a rainbow-\n"
# 753 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "colored beam that\n"
# 754 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "may lower Attack.$"
# 755 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 756 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_TeleportDesc::
# 757 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A psychic move\n"
# 758 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "for fleeing from\n"
# 759 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "battle instantly.$"
# 760 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 761 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ Set 4
# 762 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ThunderPunchDesc::
# 763 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An electrified\n"
# 764 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "punch that may\n"
# 765 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralyze the foe.$"
# 766 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 767 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_FirePunchDesc::
# 768 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A fiery punch\n"
# 769 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may burn\n"
# 770 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the foe.$"
# 771 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 772 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_IcePunchDesc::
# 773 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "An icy punch\n"
# 774 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may\n"
# 775 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "freeze the foe.$"
# 776 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 777 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_TailwindDesc::
# 778 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A turbulent wind\n"
# 779 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ups allies' Speed\n"
# 780 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "for 4 turns.$"
# 781 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 782 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ZenHeadbuttDesc::
# 783 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Focuses willpower,\n"
# 784 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "rams the foe. May\n"
# 785 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "cause flinching.$"
# 786 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 787 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_BodySlamDesc::
# 788 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A full-body slam\n"
# 789 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that may cause\n"
# 790 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "paralysis.$"
# 791 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 792 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_IcicleSpearDesc::
# 793 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sharp icicles are\n"
# 794 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "fired at the foe.\n"
# 795 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hits 2 to 5 times.$"
# 796 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 797 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_DualChopDesc::
# 798 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Attacks with\n"
# 799 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "brutal strikes.\n"
# 800 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Hits 2 times.$"
# 801 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 802 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ReversalDesc::
# 803 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Inflicts more\n"
# 804 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "damage if the\n"
# 805 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "user's HP is down.$"
# 806 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 807 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_BugBuzzDesc::
# 808 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Creates a harmful\n"
# 809 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "sound wave. May\n"
# 810 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "lower Sp. Def.$"
# 811 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 812 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_LastResortDesc::
# 813 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "User must use its\n"
# 814 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "other known moves\n"
# 815 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "before this one.$"
# 816 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 817 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_RolePlayDesc::
# 818 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Mimics the target\n"
# 819 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "and copies its\n"
# 820 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ability.$"
# 821 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 822 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_DrillRunDesc::
# 823 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Spins, slams the\n"
# 824 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe. High critical\n"
# 825 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "-hit ratio.$"
# 826 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 827 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_BlazeKickDesc::
# 828 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "High critical-hit\n"
# 829 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ratio. May also\n"
# 830 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "burn the target.$"
# 831 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 832 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_CrossPoisonDesc::
# 833 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "High critical-hit\n"
# 834 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ratio. May also\n"
# 835 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "poison the target.$"
# 836 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 837 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_WeatherBallDesc::
# 838 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "The move's type\n"
# 839 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "and power change\n"
# 840 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with the weather.$"
# 841 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 842 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_AirSlashDesc::
# 843 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Cuts with a blade\n"
# 844 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "of air. May also\n"
# 845 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "cause flinching.$"
# 846 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 847 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_StompingTantrumDesc::
# 848 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Stomps around\n"
# 849 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "angrily. Stronger\n"
# 850 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "after a failure.$"
# 851 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 852 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ Set 5
# 853 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_IronHeadDesc::
# 854 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Slams the foe with\n"
# 855 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "a steel-hard head.\n"
# 856 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Foe may flinch.$"
# 857 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 858 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_AquaTailDesc::
# 859 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "User swings its\n"
# 860 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "tail as if it were\n"
# 861 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "a wave in a storm.$"
# 862 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 863 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PowerGemDesc::
# 864 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Attacks with a ray\n"
# 865 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "of light that\n"
# 866 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "sparkles like gems.$"
# 867 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 868 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_BounceDesc::
# 869 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Bounces up, then\n"
# 870 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "down next turn.\n"
# 871 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "May paralyze.$"
# 872 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 873 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HealBellDesc::
# 874 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Chimes soothingly\n"
# 875 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "to eliminate all\n"
# 876 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "status problems.$"
# 877 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 878 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SuperpowerDesc::
# 879 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Attacks with full\n"
# 880 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "power, but lowers\n"
# 881 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Attack & Defense.$"
# 882 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 883 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_CrunchDesc::
# 884 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Crunches with\n"
# 885 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "sharp fangs. May\n"
# 886 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "lower Defense.$"
# 887 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 888 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MysticalFireDesc::
# 889 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Breathes special,\n"
# 890 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "hot fire. May\n"
# 891 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "lower Sp. Atk.$"
# 892 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 893 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_GunkShotDesc::
# 894 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Shoots filthy\n"
# 895 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "garbage at the\n"
# 896 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe. May poison.$"
# 897 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 898 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HyperVoiceDesc::
# 899 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A loud attack\n"
# 900 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that uses sound\n"
# 901 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "waves to injure.$"
# 902 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 903 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SkyAttackDesc::
# 904 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Searches out weak\n"
# 905 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "spots, then\n"
# 906 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "strikes next turn.$"
# 907 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 908 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HeatCrashDesc::
# 909 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Does more damage\n"
# 910 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "if the user weighs\n"
# 911 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "more than the foe.$"
# 912 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 913 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_StoredPowerDesc::
# 914 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ups damage the\n"
# 915 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "more the user's\n"
# 916 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "stats are raised.$"
# 917 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 918 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_TrickDesc::
# 919 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Tricks the foe\n"
# 920 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "into trading\n"
# 921 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "held items.$"
# 922 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 923 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_DynamicPunchDesc::
# 924 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Powerful, sure to\n"
# 925 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "cause confusion,\n"
# 926 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "but inaccurate.$"
# 927 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 928 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HelpingHandDesc::
# 929 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Boosts the power\n"
# 930 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "of an ally's\n"
# 931 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "attack in battle.$"
# 932 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 933 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ToxicSpikesDesc::
# 934 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sets spikes that\n"
# 935 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "poison a foe\n"
# 936 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "switching in.$"
# 937 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 938 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HighHorsepowerDesc::
# 939 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Slams hard into\n"
# 940 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the foe with its\n"
# 941 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "entire body.$"
# 942 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 943 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ Set 6
# 944 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MegahornDesc::
# 945 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A brutal ramming\n"
# 946 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "attack using\n"
# 947 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "out-thrust horns.$"
# 948 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 949 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_AuraSphereDesc::
# 950 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A blast of aura\n"
# 951 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "power that cannot\n"
# 952 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "be avoided.$"
# 953 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 954 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ThroatChopDesc::
# 955 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Strikes the foe's\n"
# 956 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "throat to silence\n"
# 957 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "it for 2 turns.$"
# 958 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 959 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_EarthPowerDesc::
# 960 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ground under the\n"
# 961 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe erupts. May\n"
# 962 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "lower Sp. Def.$"
# 963 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 964 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HeatWaveDesc::
# 965 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Exhales a hot\n"
# 966 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "breath on the foe.\n"
# 967 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "May inflict a burn.$"
# 968 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 969 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_LiquidationDesc::
# 970 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Slams the target\n"
# 971 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "with a water blast.\n"
# 972 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "May lower Defense.$"
# 973 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 974 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_BatonPassDesc::
# 975 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Switches out the\n"
# 976 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "user while keeping\n"
# 977 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "effects in play.$"
# 978 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 979 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_FoulPlayDesc::
# 980 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Does damage based\n"
# 981 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "on the foe's\n"
# 982 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Attack stat.$"
# 983 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 984 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SolarBladeDesc::
# 985 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Absorbs light in\n"
# 986 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "one turn, attacks\n"
# 987 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the next turn.$"
# 988 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 989 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PhantomForceDesc::
# 990 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Vanishes, then\n"
# 991 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "strikes next turn.\n"
# 992 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Ignores Protect.$"
# 993 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 994 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MeteorMashDesc::
# 995 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fires a Meteor\n"
# 996 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "-like punch.\n"
# 997 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "May raise Attack.$"
# 998 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 999 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PsychicFangsDesc::
# 1000 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Bites with Psychic\n"
# 1001 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "power. Also\n"
# 1002 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "destroys Screens.$"
# 1003 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1004 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_EncoreDesc::
# 1005 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Makes the foe\n"
# 1006 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "repeat its last\n"
# 1007 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "move for 3 turns.$"
# 1008 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1009 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_GrassyTerrainDesc::
# 1010 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Covers the field\n"
# 1011 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "in grass, healing\n"
# 1012 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "grounded Pokémon.$"
# 1013 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1014 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_ElectricTerrainDesc::
# 1015 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Electrifies the\n"
# 1016 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ground,\n"
# 1017 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "preventing sleep.$"
# 1018 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1019 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_MistyTerrainDesc::
# 1020 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Covers the field\n"
# 1021 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "in mist. Prevents\n"
# 1022 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "status conditions.$"
# 1023 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1024 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PsychicTerrainDesc::
# 1025 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Protects Pokémon\n"
# 1026 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "on the ground from\n"
# 1027 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "priority moves.$"
# 1028 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1029 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PowerUpPunchDesc::
# 1030 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A hard punch that\n"
# 1031 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "raises the user's\n"
# 1032 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Attack.$"
# 1033 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1034 "data/maps/BattleFrontier_Lounge7/scripts.pory"
@ Set 7
# 1035 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_DoubleEdgeDesc::
# 1036 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A life-risking\n"
# 1037 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "tackle that also\n"
# 1038 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "hurts the user.$"
# 1039 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1040 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PlayRoughDesc::
# 1041 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "The user plays ro-\n"
# 1042 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "ugh with the foe.\n"
# 1043 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "May lower Attack.$"
# 1044 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1045 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_NastyPlotDesc::
# 1046 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Thinking bad\n"
# 1047 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "thoughts sharply\n"
# 1048 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "raises Sp. Atk.$"
# 1049 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1050 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_SelfDestructDesc::
# 1051 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Inflicts severe\n"
# 1052 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "damage but makes\n"
# 1053 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "the user faint.$"
# 1054 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1055 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_CloseCombatDesc::
# 1056 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Fights the foe up\n"
# 1057 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "close. Lowers\n"
# 1058 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Defense & Sp. Def.$"
# 1059 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1060 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_FlareBlitzDesc::
# 1061 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A flame-cloaked\n"
# 1062 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "charge that also\n"
# 1063 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "hurts the user.$"
# 1064 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1065 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_BraveBirdDesc::
# 1066 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A low altitude\n"
# 1067 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "charge that also\n"
# 1068 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "hurts the user.$"
# 1069 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1070 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_LeafStormDesc::
# 1071 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A storm of sharp\n"
# 1072 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "leaves. Harshly\n"
# 1073 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "lowers Sp. Atk.$"
# 1074 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1075 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_PowerWhipDesc::
# 1076 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Violently whirls\n"
# 1077 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "vines, etc. to\n"
# 1078 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "lash the foe.$"
# 1079 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1080 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HurricaneDesc::
# 1081 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Attacks with a\n"
# 1082 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "fierce wind that\n"
# 1083 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "may also confuse.$"
# 1084 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1085 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_HydroPumpDesc::
# 1086 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Blasts water at\n"
# 1087 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "high power to\n"
# 1088 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "strike the foe.$"
# 1089 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1090 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_DragonDanceDesc::
# 1091 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A mystical dance\n"
# 1092 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that ups Attack\n"
# 1093 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "and Speed.$"
# 1094 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1095 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_OutrageDesc::
# 1096 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A rampage of 2 to\n"
# 1097 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "3 turns. The user\n"
# 1098 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "is confused after.$"
# 1099 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1100 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_KnockOffDesc::
# 1101 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Knocks down the\n"
# 1102 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "foe's held item to\n"
# 1103 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "prevent its use.$"
# 1104 "data/maps/BattleFrontier_Lounge7/scripts.pory"

# 1105 "data/maps/BattleFrontier_Lounge7/scripts.pory"
PokemonCenterMoveTutor_Text_QuiverDanceDesc::
# 1106 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "A mystic dance\n"
# 1107 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "that ups Sp. Atk,\n"
# 1108 "data/maps/BattleFrontier_Lounge7/scripts.pory"
	.string "Sp. Def & Speed.$"
