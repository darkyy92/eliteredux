# 1 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 2 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_MapScripts:: @ 820EBBB
# 3 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.byte 0
# 4 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 5 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Rydel:: @ 820EBBC
# 6 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	lock
# 7 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	faceplayer
# 8 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
# 9 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
# 10 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
# 11 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
# 12 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, YES
# 13 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq MauvilleCity_BikeShop_EventScript_YesFar
# 14 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, NO
# 15 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq MauvilleCity_BikeShop_EventScript_NotFar
# 16 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 17 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 18 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SkipGreeting:: @ 820EBF7
# 19 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
# 20 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, YES
# 21 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq MauvilleCity_BikeShop_EventScript_YesFar
# 22 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, NO
# 23 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq MauvilleCity_BikeShop_EventScript_NotFar
# 24 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 25 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 26 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseBike:: @ 820EC16
# 27 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne, MSGBOX_DEFAULT
# 28 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 29 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 30 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 31 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 32 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 33 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_NotFar:: @ 820EC3D
# 34 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_DECLINED_BIKE
# 35 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
# 36 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 37 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 38 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 39 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_YesFar:: @ 820EC4A
# 40 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	setflag FLAG_RECEIVED_BIKE
# 41 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
# 42 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 43 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 44 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_GetMachBike:: @ 820EC53
# 45 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
# 46 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 47 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 48 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 49 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 50 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_GetAcroBike:: @ 820EC6D
# 51 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
# 52 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 53 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
# 54 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 55 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 56 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes:: @ 820EC87
# 57 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
# 58 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	special SwapRegisteredBike
# 59 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 60 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 61 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 62 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_AskSwitchBikes:: @ 820EC94
# 63 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	checkitem ITEM_ACRO_BIKE, 1
# 64 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
# 65 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	call_if_ne MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
# 66 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	checkitem ITEM_MACH_BIKE, 1
# 67 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
# 68 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	call_if_ne MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
# 69 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_DEFAULT
# 70 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 71 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 72 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 73 "data/maps/MauvilleCity_BikeShop/scripts.pory"
@ If the player does not have a bike on them Rydel assumes its stored in the PC
# 74 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchBikes:: @ 820ECB3
# 75 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
# 76 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	checkitem ITEM_ACRO_BIKE, 1
# 77 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
# 78 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
# 79 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	checkitem ITEM_MACH_BIKE, 1
# 80 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	compare VAR_RESULT, TRUE
# 81 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto_if_eq MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
# 82 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
# 83 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 84 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 85 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 86 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_KeepBike:: @ 820ECE5
# 87 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
# 88 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 89 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 90 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 91 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchAcroForMach:: @ 820ECEF
# 92 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	incrementgamestat GAME_STAT_TRADED_BIKES
# 93 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
# 94 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 95 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	return
# 96 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 97 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SwitchMachForAcro:: @ 820ED10
# 98 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	incrementgamestat GAME_STAT_TRADED_BIKES
# 99 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
# 100 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 101 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	return
# 102 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 103 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Assistant:: @ 820ED31
# 104 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
# 105 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 106 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 107 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_MachBikeHandbook:: @ 820ED3A
# 108 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
# 109 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 110 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 111 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 112 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 113 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage:: @ 820ED46
# 114 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
# 115 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 116 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
# 117 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
# 118 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
# 119 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
# 120 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
# 121 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 122 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 123 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_HowToRide:: @ 820ED88
# 124 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
# 125 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 126 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 127 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 128 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 129 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_HowToTurn:: @ 820ED94
# 130 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
# 131 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 132 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 133 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 134 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 135 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_SandySlopes:: @ 820EDA0
# 136 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_SandySlopes
# 137 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 138 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
# 139 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 140 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 141 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ExitMachHandbook:: @ 820EDAC
# 142 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 143 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 144 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 145 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_AcroBikeHandbook:: @ 820EDAE
# 146 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
# 147 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 148 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 149 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 150 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 151 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage:: @ 820EDBA
# 152 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
# 153 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	switch VAR_RESULT
# 154 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
# 155 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
# 156 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
# 157 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
# 158 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
# 159 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 160 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 161 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Wheelies:: @ 820EDFC
# 162 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_Wheelies
# 163 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 164 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 165 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 166 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 167 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_BunnyHops:: @ 820EE08
# 168 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_BunnyHops
# 169 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 170 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 171 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 172 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 173 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_Jumps:: @ 820EE14
# 174 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	message MauvilleCity_BikeShop_Text_Jumps
# 175 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	waitmessage
# 176 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
# 177 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 178 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 179 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_EventScript_ExitAcroHandbook:: @ 820EE20
# 180 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	release
# 181 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	end
# 182 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 183 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_RydelGreeting: @ 820EE22
# 184 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Well, well, what have we here?\n"
# 185 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A most energetic customer!\p"
# 186 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Me? You may call me Rydel.\n"
# 187 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm the owner of this cycle shop.$"
# 188 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 189 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_DidYouComeFromFarAway: @ 820EE99
# 190 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: Your Running Shoes…\n"
# 191 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "They're awfully filthy.\p"
# 192 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Did you come from far away?$"
# 193 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 194 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_GuessYouDontNeedBike: @ 820EEE8
# 195 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: Is that right?\p"
# 196 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Then, I guess you have no need for\n"
# 197 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "any of my Bikes.$"
# 198 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 199 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne: @ 820EF32
# 200 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: Hm, hm… … … … …\p"
# 201 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You're saying that you came all this\n"
# 202 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "way from Littleroot?\p"
# 203 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "My goodness!\n"
# 204 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "That's ridiculously far!\p"
# 205 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If you had one of my Bikes, you could\n"
# 206 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "go anywhere easily while feeling the\l"
# 207 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "gentle caress of the wind!\p"
# 208 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll tell you what!\n"
# 209 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll give you a Bike!\p"
# 210 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh, wait a second!\p"
# 211 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I forgot to tell you that there are\n"
# 212 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "two kinds of Bikes!\p"
# 213 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "They are the Mach Bike and\n"
# 214 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the Acro Bike!\p"
# 215 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The Mach Bike is for cyclists who want\n"
# 216 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "to feel the wind with their bodies!\p"
# 217 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "And an Acro Bike is for those who\n"
# 218 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "prefer technical rides!\p"
# 219 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm a real sweetheart, so you can\n"
# 220 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "have whichever one you like!\p"
# 221 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which one will you cho...\n"
# 222 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Wait, i recognize you!\p"
# 223 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You're Norman's offspring!\n"
# 224 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Forget about choosing one.\p"
# 225 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll give you both!\n"
# 226 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "In exchange, be sure to\p"
# 227 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "show off our bikes!$"
# 228 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 229 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ChoseMachBike: @ 820F18D
# 230 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} chose the Mach Bike.$"
# 231 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 232 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ChoseAcroBike: @ 820F1A5
# 233 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "{PLAYER} chose the Acro Bike.$"
# 234 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 235 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes: @ 820F1BD
# 236 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: If you get the urge to switch\n"
# 237 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Bikes, just come see me!$"
# 238 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 239 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_WantToSwitchBikes: @ 820F1FB
# 240 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: Be sure to show off our bikes!$"
# 241 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 242 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_IllSwitchBikes: @ 820F22F
# 243 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: Okay, no problem!\n"
# 244 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'll switch Bikes for you!$"
# 245 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 246 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExchangedMachForAcro: @ 820F263
# 247 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: Oh! You're back! Perfect!\n"
# 248 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Last time i think i forgot to give you this.$"
# 249 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 250 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_ExchangedAcroForMach: @ 820F294
# 251 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: Oh! You're back! Perfect!\n"
# 252 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I forgot to give you this last time.$"
# 253 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 254 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HappyYouLikeIt: @ 820F2C4
# 255 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Rydel: Good, good!\n"
# 256 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm happy that you like it!$"
# 257 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 258 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_OhYourBikeIsInPC: @ 820F2F3
# 259 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh? What happened to that Bike\n"
# 260 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I gave you?\p"
# 261 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Oh, I get it, you stored it using your PC.\p"
# 262 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Well, take it out of PC storage,\n"
# 263 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "and I'll be happy to exchange it!\p"
# 264 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "May the wind always be at your back\n"
# 265 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "on your adventure!$"
# 266 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 267 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HandbooksAreInBack: @ 820F3C3
# 268 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I'm learning about Bikes while\n"
# 269 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "I work here.\p"
# 270 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "If you need advice on how to ride your\n"
# 271 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Bike, there're a couple handbooks in\l"
# 272 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the back.$"
# 273 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 274 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_MachHandbookWhichPage: @ 820F445
# 275 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It's a handbook on the Mach Bike.\p"
# 276 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which page do you want to read?$"
# 277 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 278 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HowToRideMachBike: @ 820F487
# 279 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A Bike moves in the direction that\n"
# 280 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "the + Control Pad is pressed.\p"
# 281 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It will speed up once it gets rolling.\p"
# 282 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "To stop, release the + Control Pad.\n"
# 283 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The Bike will slow to a stop.\p"
# 284 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 285 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 286 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_HowToTurnMachBike: @ 820F550
# 287 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "A Mach Bike is speedy, but it can't\n"
# 288 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "stop very quickly.\p"
# 289 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It gets a little tricky to get around\n"
# 290 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "a corner.\p"
# 291 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Release the + Control Pad a little\n"
# 292 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "before the corner and slow down.\p"
# 293 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 294 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 295 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_SandySlopes: @ 820F61A
# 296 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "There are small sandy slopes\n"
# 297 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "throughout the Hoenn region.\p"
# 298 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "The loose, crumbly sand makes it\n"
# 299 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "impossible to climb normally.\p"
# 300 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "But if you have a Mach Bike, you can\n"
# 301 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "zip up a sandy slope.\p"
# 302 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 303 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 304 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_AcroHandbookWhichPage: @ 820F6ED
# 305 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "It's a handbook on the Acro Bike.\p"
# 306 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Which page do you want to read?$"
# 307 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 308 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_Wheelies: @ 820F72F
# 309 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the B Button while riding,\n"
# 310 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "and the front wheel lifts up.\p"
# 311 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You can zip around with the front\n"
# 312 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "wheel up using the + Control Pad.\p"
# 313 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "This technique is called a wheelie.\p"
# 314 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 315 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 316 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_BunnyHops: @ 820F7F5
# 317 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Keeping the B Button pressed,\n"
# 318 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "your Bike can hop on the spot.\p"
# 319 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "This technique is called a bunny hop.\p"
# 320 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "You can ride while hopping, too.\p"
# 321 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
# 322 "data/maps/MauvilleCity_BikeShop/scripts.pory"

# 323 "data/maps/MauvilleCity_BikeShop/scripts.pory"
MauvilleCity_BikeShop_Text_Jumps: @ 820F898
# 324 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the B Button and the + Control\n"
# 325 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Pad at the same time to jump.\p"
# 326 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press the + Control Pad to the side\n"
# 327 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "to jump sideways.\p"
# 328 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Press it backwards to make the Bike\n"
# 329 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "change directions while jumping.\p"
# 330 "data/maps/MauvilleCity_BikeShop/scripts.pory"
	.string "Want to read a different page?$"
