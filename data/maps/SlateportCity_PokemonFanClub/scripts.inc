# 1 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 2 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_MapScripts:: @ 8209E95
# 3 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.byte 0
# 4 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 5 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_Chairman:: @ 8209E96
# 6 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	lock
# 7 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	faceplayer
# 8 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
# 9 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
# 10 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	switch VAR_SLATEPORT_FAN_CLUB_STATE
# 11 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
# 12 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
# 13 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
# 14 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 15 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 16 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 17 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment:: @ 8209ED2
# 18 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
# 19 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
# 20 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
# 21 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 22 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 23 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon:: @ 8209EE5
# 24 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_TEMP_2, 0
# 25 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
# 26 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
# 27 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
# 28 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
# 29 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
# 30 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_TEMP_2, CONTEST_CATEGORIES_COUNT
# 31 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_eq SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
# 32 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_SLATEPORT_FAN_CLUB_STATE, 2
# 33 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
# 34 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
# 35 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
# 36 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 37 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 38 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_NoMoreScarves:: @ 8209F3B
# 39 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
# 40 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 41 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 42 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 43 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon:: @ 8209F45
# 44 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
# 45 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_TEMP_1, 0
# 46 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
# 47 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
# 48 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
# 49 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
# 50 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
# 51 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	bufferleadmonspeciesname 0
# 52 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	switch VAR_TEMP_1
# 53 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
# 54 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
# 55 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
# 56 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
# 57 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
# 58 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
# 59 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 60 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 61 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 62 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves:: @ 8209FCA
# 63 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
# 64 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 65 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 66 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf:: @ 8209FD0
# 67 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	addvar VAR_TEMP_2, 1
# 68 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 69 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 70 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_NoHighConditions:: @ 8209FD6
# 71 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
# 72 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 73 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 74 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 75 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_GiveRedScarf:: @ 8209FE0
# 76 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	checkitemspace ITEM_RED_SCARF, 1
# 77 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 78 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
# 79 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
# 80 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setflag FLAG_RECEIVED_RED_SCARF
# 81 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	giveitem ITEM_RED_SCARF
# 82 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
# 83 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 84 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 85 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 86 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf:: @ 820A011
# 87 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	checkitemspace ITEM_BLUE_SCARF, 1
# 88 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 89 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
# 90 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
# 91 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setflag FLAG_RECEIVED_BLUE_SCARF
# 92 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	giveitem ITEM_BLUE_SCARF
# 93 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
# 94 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 95 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 96 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 97 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_GivePinkScarf:: @ 820A042
# 98 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	checkitemspace ITEM_PINK_SCARF, 1
# 99 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 100 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
# 101 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
# 102 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setflag FLAG_RECEIVED_PINK_SCARF
# 103 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	giveitem ITEM_PINK_SCARF
# 104 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
# 105 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 106 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 107 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 108 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf:: @ 820A073
# 109 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	checkitemspace ITEM_GREEN_SCARF, 1
# 110 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 111 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
# 112 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
# 113 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setflag FLAG_RECEIVED_GREEN_SCARF
# 114 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	giveitem ITEM_GREEN_SCARF
# 115 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
# 116 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 117 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 118 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 119 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf:: @ 820A0A4
# 120 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	checkitemspace ITEM_YELLOW_SCARF, 1
# 121 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 122 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
# 123 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
# 124 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setflag FLAG_RECEIVED_YELLOW_SCARF
# 125 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	giveitem ITEM_YELLOW_SCARF
# 126 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
# 127 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 128 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 129 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 130 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf:: @ 820A0D5
# 131 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
# 132 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 133 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 134 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 135 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_CheckMonCool:: @ 820A0DF
# 136 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	specialvar VAR_RESULT, CheckLeadMonCool
# 137 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 138 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonCool
# 139 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 140 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 141 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_SetMonCool:: @ 820A0F0
# 142 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_TEMP_1, 1
# 143 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 144 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 145 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty:: @ 820A0F6
# 146 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	specialvar VAR_RESULT, CheckLeadMonBeauty
# 147 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 148 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
# 149 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 150 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 151 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_SetMonBeauty:: @ 820A107
# 152 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_TEMP_1, 2
# 153 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 154 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 155 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_CheckMonCute:: @ 820A10D
# 156 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	specialvar VAR_RESULT, CheckLeadMonCute
# 157 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 158 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonCute
# 159 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 160 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 161 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_SetMonCute:: @ 820A11E
# 162 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_TEMP_1, 3
# 163 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 164 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 165 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_CheckMonSmart:: @ 820A124
# 166 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	specialvar VAR_RESULT, CheckLeadMonSmart
# 167 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 168 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonSmart
# 169 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 170 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 171 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_SetMonSmart:: @ 820A135
# 172 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_TEMP_1, 4
# 173 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 174 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 175 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_CheckMonTough:: @ 820A13B
# 176 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	specialvar VAR_RESULT, CheckLeadMonTough
# 177 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, TRUE
# 178 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonTough
# 179 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 180 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 181 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_SetMonTough:: @ 820A14C
# 182 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setvar VAR_TEMP_1, 5
# 183 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 184 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 185 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest:: @ 820A152
# 186 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
# 187 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
# 188 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
# 189 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 190 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 191 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 192 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest:: @ 820A168
# 193 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
# 194 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 195 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 196 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 197 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_MeetChairman:: @ 820A172
# 198 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
# 199 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
# 200 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	return
# 201 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 202 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_SootheBellWoman:: @ 820A17E
# 203 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	lock
# 204 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	faceplayer
# 205 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
# 206 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
# 207 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
# 208 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, 4
# 209 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_ge SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
# 210 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 211 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 212 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 213 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_GiveSootheBell:: @ 820A1A3
# 214 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	playse SE_PIN
# 215 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 216 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	waitmovement 0
# 217 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
# 218 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	waitmovement 0
# 219 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
# 220 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	giveitem ITEM_LOVE_BALL
# 221 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	compare VAR_RESULT, FALSE
# 222 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 223 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	setflag FLAG_RECEIVED_SOOTHE_BELL
# 224 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 225 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 226 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 227 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell:: @ 820A1DE
# 228 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
# 229 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 230 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 231 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 232 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_Man:: @ 820A1E8
# 233 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
# 234 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 235 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 236 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_Twin:: @ 820A1F1
# 237 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
# 238 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 239 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 240 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_Skitty:: @ 820A1FA
# 241 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	lock
# 242 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	faceplayer
# 243 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	waitse
# 244 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	playmoncry SPECIES_SKITTY, 0
# 245 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
# 246 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	waitmoncry
# 247 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 248 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 249 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 250 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_Zigzagoon:: @ 820A20D
# 251 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	lock
# 252 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	faceplayer
# 253 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	waitse
# 254 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	playmoncry SPECIES_ZIGZAGOON, 0
# 255 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
# 256 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	waitmoncry
# 257 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 258 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 259 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 260 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_Azumarill:: @ 820A220
# 261 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	lock
# 262 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	faceplayer
# 263 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	waitse
# 264 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	playmoncry SPECIES_AZUMARILL, 0
# 265 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
# 266 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	waitmoncry
# 267 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 268 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 269 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 270 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_EndureTM::
# 271 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	lock
# 272 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	faceplayer
# 273 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_HaveTM58, MSGBOX_DEFAULT
# 274 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 275 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 276 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 277 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_EventScript_ReceivedTM58::
# 278 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	lock
# 279 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	faceplayer
# 280 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	msgbox SlateportCity_PokemonFanClub_Text_HaveTM58, MSGBOX_DEFAULT
# 281 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	release
# 282 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	end
# 283 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 284 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_GiveTM58:
# 285 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Check out my Azumarill! It's pretty\n"
# 286 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "sturdy, right? Almost as sturdy as\l"
# 287 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "a Roggenrola with Sturdy!\p"
# 288 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Your Pokémon can be sturdy too,\n"
# 289 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "if you use this TM!$"
# 290 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 291 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_HaveTM58:
# 292 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Endure allows a Pokémon to withstand\n"
# 293 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "any attack with one HP left.\p"
# 294 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "It might not work if you use it too\n"
# 295 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "many times in a row, though.$"
# 296 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 297 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_MeetChairman: @ 820A233
# 298 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Er-hem! I am the Chairman of the\n"
# 299 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Pokémon Fan Club!\p"
# 300 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Being the Chairman, I am naturally\n"
# 301 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "the most important!\p"
# 302 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "No one can best me when it comes\n"
# 303 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "to raising Pokémon. No one!\p"
# 304 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Well, let me tell you about\n"
# 305 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Pokémon Contests.\p"
# 306 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "They're events where one can show off\n"
# 307 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Pokémon for the world to see!\p"
# 308 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "However, they're held in far-off towns,\n"
# 309 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "so I cannot participate often enough.\p"
# 310 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "That is why we gather here to show\n"
# 311 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "off our Pokémon, and have others\l"
# 312 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "show us theirs.$"
# 313 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 314 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon: @ 820A3EE
# 315 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "The Pokémon of a Trainer who has\n"
# 316 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "entered a Pokémon Contest…\l"
# 317 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "That, I would like to see.$"
# 318 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 319 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon: @ 820A445
# 320 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Er-hem! I see you've participated in\n"
# 321 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "a Pokémon Contest!\p"
# 322 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Please! Allow me to examine how you\n"
# 323 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "have raised your Pokémon.\p"
# 324 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "It delights me no end to see Pokémon\n"
# 325 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "raised by other Trainers.\p"
# 326 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "The happy expressions of Pokémon\n"
# 327 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "raised with proper care…\p"
# 328 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "The kindly eyes of the Trainer that\n"
# 329 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "nurtured and raised the Pokémon…\p"
# 330 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "The very thought fills my heart to\n"
# 331 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "overwhelming with joy.\p"
# 332 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Oh! I do beg your pardon!\n"
# 333 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Forgive me for prattling on so!\p"
# 334 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Please! Allow me to examine how much\n"
# 335 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "your Pokémon has grown!$"
# 336 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 337 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing: @ 820A62A
# 338 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "How is your Pokémon growing?\n"
# 339 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Allow me to examine it.$"
# 340 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 341 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_HmHmISee: @ 820A65F
# 342 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Hm, hm…\n"
# 343 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "I see…$"
# 344 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 345 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks: @ 820A66E
# 346 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Hmmm… It's not bad, but it's not\n"
# 347 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "good, either…\p"
# 348 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "You, the Trainer, must put more\n"
# 349 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "effort into raising this Pokémon!\p"
# 350 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "For instance, may I suggest that\n"
# 351 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "you give it more {POKEBLOCK}S?$"
# 352 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 353 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_NoSpaceForReward: @ 820A719
# 354 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Oh, my…\p"
# 355 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Your Pokémon is growing quite well,\n"
# 356 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "so you deserve a reward.\p"
# 357 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Unfortunately, you have no space for\n"
# 358 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "this in your Bag.$"
# 359 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 360 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis: @ 820A795
# 361 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Your {STR_VAR_1}, it is growing in\n"
# 362 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "a most impressive manner!\l"
# 363 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "It is one fine specimen!\p"
# 364 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "But! If you were to give it this,\n"
# 365 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "it would grow even better! Indeed!$"
# 366 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 367 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_ExplainRedScarf: @ 820A827
# 368 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Let a Pokémon hold that Red Scarf.\p"
# 369 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Everyone will recognize the coolness\n"
# 370 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "of that Pokémon!$"
# 371 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 372 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_ExplainBlueScarf: @ 820A880
# 373 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Let a Pokémon hold that Blue Scarf.\p"
# 374 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Its beauty will be accentuated much\n"
# 375 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "more than now!$"
# 376 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 377 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_ExplainPinkScarf: @ 820A8D7
# 378 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Let a Pokémon hold that Pink Scarf.\p"
# 379 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "It will draw out the cuteness of\n"
# 380 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "the Pokémon some more!$"
# 381 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 382 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_ExplainGreenScarf: @ 820A933
# 383 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Let a Pokémon hold that Green Scarf.\p"
# 384 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "That will enhance the\n"
# 385 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "smartness of Pokémon!$"
# 386 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 387 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_ExplainYellowScarf: @ 820A984
# 388 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Let a Pokémon hold that Yellow Scarf.\p"
# 389 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "It will bolster your Pokémon's\n"
# 390 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "toughness so much more!$"
# 391 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 392 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou: @ 820A9E1
# 393 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "I'm sorry, but I've nothing else to\n"
# 394 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "give you! None at all!\p"
# 395 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "After all, you're blessed with the gift\n"
# 396 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "of raising Pokémon without resorting\l"
# 397 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "to any items!$"
# 398 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 399 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou: @ 820AA77
# 400 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "I love seeing Pokémon that love\n"
# 401 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "their Trainers.\p"
# 402 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Pokémon are very sensitive to\n"
# 403 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "the feelings of their Trainers.\p"
# 404 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "If you treat your Pokémon with love\n"
# 405 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "and care, they'll love you back.\p"
# 406 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "When your Pokémon grow to love you,\n"
# 407 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "please come show me.$"
# 408 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 409 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_PokemonAdoresYou: @ 820AB63
# 410 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Your Pokémon really adores you.\p"
# 411 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "For you, a most compassionate\n"
# 412 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Trainer, a gift from the Fan Club!$"
# 413 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 414 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove: @ 820ABC4
# 415 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Pokémon are very sensitive to\n"
# 416 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "the feelings of their Trainers.\p"
# 417 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "If you treat your Pokémon with love\n"
# 418 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "and care, they'll love you back.$"
# 419 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 420 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting: @ 820AC47
# 421 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "If you keep letting a Pokémon faint\n"
# 422 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "in battle, it'll come to resent it.\p"
# 423 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Soon, it will become less trusting\n"
# 424 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "of the Trainer.\p"
# 425 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "In other words, it certainly won't\n"
# 426 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "like you very much.$"
# 427 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 428 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein: @ 820ACF9
# 429 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Do Pokémon enjoy having items used\n"
# 430 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "on them?\p"
# 431 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Mine acted really happy when I gave\n"
# 432 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "it some Protein.$"
# 433 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 434 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_Skitty: @ 820AD5A
# 435 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Skitty: Fffnyaaaah…$"
# 436 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 437 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_Zigzagoon: @ 820AD6E
# 438 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Zigzagoon: Kyuuu…$"
# 439 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"

# 440 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
SlateportCity_PokemonFanClub_Text_Azumarill: @ 820AD80
# 441 "data/maps/SlateportCity_PokemonFanClub/scripts.pory"
	.string "Azumarill: Marimari?$"
