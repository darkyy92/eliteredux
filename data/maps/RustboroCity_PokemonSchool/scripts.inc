# 1 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 2 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_MapScripts:: @ 8213EA8
# 3 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 5 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Blackboard:: @ 8213EA9
# 6 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	lockall
# 7 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
# 8 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 9 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 10 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 11 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic:: @ 8213EB8
# 12 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
# 13 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmessage
# 14 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
# 15 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	switch VAR_RESULT
# 16 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
# 17 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
# 18 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
# 19 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
# 20 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
# 21 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
# 22 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
# 23 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 24 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 25 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Poison:: @ 8213F17
# 26 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
# 27 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 28 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 29 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 30 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Paralysis:: @ 8213F25
# 31 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
# 32 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 33 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 34 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 35 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Sleep:: @ 8213F33
# 36 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
# 37 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 38 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 39 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 40 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Burn:: @ 8213F41
# 41 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
# 42 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 43 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 44 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 45 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Freeze:: @ 8213F4F
# 46 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
# 47 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
# 48 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 49 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 50 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ExitTopicSelect:: @ 8213F5D
# 51 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	releaseall
# 52 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 53 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 54 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_GameboyKid1:: @ 8213F5F
# 55 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
# 56 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 57 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 58 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_GameboyKid2:: @ 8213F68
# 59 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
# 60 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 61 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 62 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_RichBoy:: @ 8213F71
# 63 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
# 64 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 65 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 66 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Lass:: @ 8213F7A
# 67 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
# 68 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 69 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 70 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_SchoolKidM:: @ 8213F83
# 71 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
# 72 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 73 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 74 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_StudentNotebook:: @ 8213F8C
# 75 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
# 76 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 77 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 78 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Teacher:: @ 8213F95
# 79 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	lock
# 80 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	faceplayer
# 81 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
# 82 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	compare VAR_FACING, DIR_EAST
# 83 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	call_if_eq RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
# 84 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	compare VAR_FACING, DIR_WEST
# 85 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	call_if_eq RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
# 86 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
# 87 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	giveitem ITEM_QUICK_CLAW
# 88 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	compare VAR_RESULT, 0
# 89 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 90 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	closemessage
# 91 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 92 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmovement 0
# 93 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	setflag FLAG_RECEIVED_QUICK_CLAW
# 94 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 95 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 96 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 97 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast:: @ 8213FE5
# 98 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
# 99 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmovement 0
# 100 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	return
# 101 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 102 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest:: @ 8213FF0
# 103 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
# 104 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmovement 0
# 105 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	return
# 106 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 107 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_GaveQuickClaw:: @ 8213FFB
# 108 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
# 109 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	closemessage
# 110 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
# 111 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	waitmovement 0
# 112 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 113 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 114 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 115 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest: @ 8214010
# 116 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 117 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 118 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 119 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 120 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_in_place_fastest_down
# 121 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 122 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 123 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 124 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 125 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_in_place_fastest_left
# 126 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 127 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 128 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 129 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 130 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 131 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_8
# 132 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 133 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 134 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 135 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 136 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 137 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 138 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	step_end
# 139 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 140 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast: @ 8214027
# 141 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 142 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 143 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 144 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 145 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 146 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 147 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_in_place_fastest_down
# 148 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 149 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 150 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 151 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_down
# 152 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_in_place_fastest_left
# 153 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 154 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 155 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 156 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 157 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_16
# 158 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	delay_8
# 159 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 160 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_right
# 161 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 162 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_up
# 163 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 164 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	walk_left
# 165 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	step_end
# 166 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 167 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_Scott:: @ 8214040
# 168 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	lock
# 169 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	faceplayer
# 170 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
# 171 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
# 172 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
# 173 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
# 174 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 175 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	setflag FLAG_MET_SCOTT_RUSTBORO
# 176 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 177 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 178 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 179 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready:: @ 821406F
# 180 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
# 181 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
# 182 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 183 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 184 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 185 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge:: @ 8214082
# 186 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
# 187 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
# 188 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 189 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 190 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge:: @ 8214090
# 191 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
# 192 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
# 193 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 194 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 195 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge:: @ 821409E
# 196 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 197 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
# 198 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 199 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 200 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 201 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_EventScript_ScottWatchStudents:: @ 82140A8
# 202 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
# 203 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	release
# 204 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	end
# 205 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 206 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges: @ 82140B2
# 207 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "The blackboard lists status changes\n"
# 208 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "that may affect Pokémon in battle.$"
# 209 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 210 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ReadWhichTopic: @ 82140F9
# 211 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Which topic do you want to read?$"
# 212 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 213 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainPoison: @ 821411A
# 214 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If a Pokémon is poisoned, it will\n"
# 215 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "steadily lose HP.\p"
# 216 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "The effects of poison remain after\n"
# 217 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a battle.\p"
# 218 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A poisoned Pokémon's HP will drop\n"
# 219 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "while it is traveling.\p"
# 220 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Heal a poisoning using an Antidote.$"
# 221 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 222 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainParalysis: @ 82141D8
# 223 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If a Pokémon becomes paralyzed,\n"
# 224 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "its Speed drops.\p"
# 225 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It may also not be able to move while\n"
# 226 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "it is in battle.\p"
# 227 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Paralysis remains after battle.\n"
# 228 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Cure it using a Parlyz Heal.$"
# 229 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 230 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainSleep: @ 821427D
# 231 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If a Pokémon falls asleep, it will be\n"
# 232 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "unable to attack.\p"
# 233 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A Pokémon may wake up on its own,\n"
# 234 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "but if a battle ends while it is\l"
# 235 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "sleeping, it will stay asleep.\p"
# 236 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Wake it up using an Awakening.$"
# 237 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 238 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainBurn: @ 8214336
# 239 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A burn reduces Attack power, and it\n"
# 240 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "steadily reduces the victim's HP.\p"
# 241 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A burn lingers after battle.\n"
# 242 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Cure a burn using a Burn Heal.$"
# 243 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 244 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainFreeze: @ 82143B8
# 245 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If a Pokémon is frozen, it becomes\n"
# 246 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "completely helpless.\p"
# 247 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It will remain frozen after battle.\n"
# 248 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Thaw it out using an Ice Heal.$"
# 249 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 250 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw: @ 8214433
# 251 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Students who don't study get a little\n"
# 252 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "taste of my Quick Claw.\p"
# 253 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Whether or not you are a good student \n"
# 254 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "will be evident from the way you use\l"
# 255 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "this item.$"
# 256 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 257 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ExplainQuickClaw: @ 82144C8
# 258 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A Pokémon holding the Quick Claw will\n"
# 259 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "occasionally speed up and get to move\l"
# 260 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "before its opponent.\p"
# 261 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "There are many other items that are\n"
# 262 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "meant to be held by Pokémon.\p"
# 263 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Just those alone will give you many\n"
# 264 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "topics to study!$"
# 265 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 266 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_TradingRightNow: @ 821459F
# 267 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I'm trading Pokémon with my friend\n"
# 268 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "right now.$"
# 269 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 270 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot: @ 82145CD
# 271 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I always wanted a Seedot, and\n"
# 272 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I'm finally getting one!$"
# 273 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 274 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems: @ 8214604
# 275 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Pokémon can hold items, but they\n"
# 276 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "don't know what to do with man-made\l"
# 277 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "items like Potion and Antidote.$"
# 278 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 279 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself: @ 8214669
# 280 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "You know how some Pokémon moves can\n"
# 281 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "confuse a Pokémon?\p"
# 282 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A confused Pokémon will sometimes\n"
# 283 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "attack itself without meaning to.\p"
# 284 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "But once it leaves battle, it will\n"
# 285 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "return to normal.$"
# 286 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 287 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry: @ 8214719
# 288 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A Pokémon holding a Berry will heal\n"
# 289 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "itself…\p"
# 290 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "There are many kinds of items that\n"
# 291 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Pokémon can hold…\p"
# 292 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Boy, it sure is hard taking notes\n"
# 293 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "down…$"
# 294 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 295 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_StudentsNotes: @ 82147A2
# 296 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's this student's notebook…\p"
# 297 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Pokémon are to be caught using\n"
# 298 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Poké Balls.\p"
# 299 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Up to six Pokémon can accompany\n"
# 300 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a Trainer.\p"
# 301 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A Trainer is someone who catches\n"
# 302 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Pokémon, raises them, and battles\l"
# 303 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "with them.\p"
# 304 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "A Trainer's mission is to defeat\n"
# 305 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "the strong Trainers who await\l"
# 306 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "challengers in Pokémon GymS.$"
# 307 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 308 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut: @ 82148C0
# 309 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Hello? Didn't we meet before?\n"
# 310 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I think back in Petalburg City.\p"
# 311 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Let me introduce myself.\n"
# 312 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "My name's SCOTT.\p"
# 313 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I've been traveling everywhere in\n"
# 314 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "search of outstanding Trainers.\p"
# 315 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "More specifically, I'm looking for\n"
# 316 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Pokémon battle experts.\p"
# 317 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "So, what brings you to this School?\n"
# 318 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Are you a Trainer, too?\p"
# 319 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "The first thing you should do is to\n"
# 320 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "have a Pokémon learn the move Cut.\p"
# 321 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "If I remember correctly, someone in\n"
# 322 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "this town has Cut.$"
# 323 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 324 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown: @ 8214A5F
# 325 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Scott: Hmm…\p"
# 326 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "The talent levels of the students here\n"
# 327 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "are unknown. The potential's there.$"
# 328 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 329 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ScottStoneBadge: @ 8214AB6
# 330 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Scott: Oh, what's that?\p"
# 331 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's a Stone Badge, isn't it?\n"
# 332 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "That's pretty impressive, I'd say.\p"
# 333 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "But, you know, I would've loved to see\n"
# 334 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "you in battle.\p"
# 335 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's hard to tell what you're like as\n"
# 336 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a Trainer from a League Badge.$"
# 337 "data/maps/RustboroCity_PokemonSchool/scripts.pory"

# 338 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge: @ 8214B8A
# 339 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Hello? Didn't we meet before?\n"
# 340 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I think back in Petalburg City.\p"
# 341 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Let me introduce myself.\n"
# 342 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "My name's Scott.\p"
# 343 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "I've been traveling everywhere in\n"
# 344 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "search of outstanding Trainers.\p"
# 345 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "More specifically, I'm looking for\n"
# 346 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Pokémon battle experts.\p"
# 347 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "Oh, what's that?\n"
# 348 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's a Stone Badge, isn't it?\p"
# 349 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "That's pretty impressive, I'd say, for\n"
# 350 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a starting Trainer like yourself.\p"
# 351 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "But, you know, I would've loved to see\n"
# 352 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "you in battle.\p"
# 353 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "It's hard to tell what you're like as\n"
# 354 "data/maps/RustboroCity_PokemonSchool/scripts.pory"
	.string "a Trainer from a League Badge.$"
