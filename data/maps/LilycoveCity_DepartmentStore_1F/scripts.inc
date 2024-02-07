# 1 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
.set LOCALID_LOTTERY_CLERK, 2
# 3 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 4 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_MapScripts:: @ 821F692
# 5 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.byte 0
# 6 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 7 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_Greeter:: @ 821F693
# 8 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
# 9 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 10 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 11 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk:: @ 821F69C
# 12 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	lock
# 13 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	faceplayer
# 14 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	dotimebasedevents
# 15 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
# 16 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_ne LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
# 17 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
# 18 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
# 19 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_RESULT, NO
# 20 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
# 21 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
# 22 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
# 23 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmessage
# 24 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special RetrieveLotteryNumber
# 25 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 26 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special BufferLottoTicketNumber
# 27 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
# 28 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_WalkInPlaceFastestRight
# 29 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmovement 0
# 30 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	playse SE_PC_ON
# 31 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special DoLotteryCornerComputerEffect
# 32 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special PickLotteryCornerTicket
# 33 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	delay 220
# 34 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special EndLotteryCornerComputerEffect
# 35 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	delay 10
# 36 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	applymovement LOCALID_LOTTERY_CLERK, Common_Movement_FacePlayer
# 37 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmovement 0
# 38 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_0x8004, 0
# 39 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
# 40 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
# 41 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_0x8006, 0
# 42 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
# 43 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_0x8006, 1
# 44 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
# 45 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	bufferitemname 0, VAR_0x8005
# 46 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_0x8004, 1
# 47 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
# 48 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_0x8004, 2
# 49 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
# 50 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_0x8004, 3
# 51 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
# 52 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_0x8004, 4
# 53 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	call_if_eq LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
# 54 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	giveitem VAR_0x8005
# 55 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 56 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
# 57 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special TryPutLotteryWinnerReportOnAir
# 58 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
# 59 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 60 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 61 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon:: @ 821F77B
# 62 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
# 63 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 64 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 65 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon:: @ 821F784
# 66 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
# 67 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 68 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 69 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow:: @ 821F78D
# 70 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
# 71 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 72 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 73 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 74 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain:: @ 821F797
# 75 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
# 76 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 77 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 78 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 79 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_NoMatch:: @ 821F7A1
# 80 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
# 81 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
# 82 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 83 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 84 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2:: @ 821F7AF
# 85 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
# 86 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 87 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 88 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 89 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch:: @ 821F7B9
# 90 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
# 91 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 92 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 93 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch:: @ 821F7C2
# 94 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
# 95 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 96 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 97 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch:: @ 821F7CB
# 98 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
# 99 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 100 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 101 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FullMatch:: @ 821F7D4
# 102 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
# 103 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	return
# 104 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 105 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom:: @ 821F7DD
# 106 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
# 107 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
# 108 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
# 109 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 110 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 111 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize:: @ 821F7ED
# 112 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
# 113 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 114 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 115 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 116 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier:: @ 821F7F7
# 117 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
# 118 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	giveitem VAR_POKELOT_PRIZE_ITEM
# 119 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	compare VAR_RESULT, FALSE
# 120 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	goto_if_eq LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
# 121 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
# 122 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
# 123 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	special TryPutLotteryWinnerReportOnAir
# 124 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
# 125 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	setvar VAR_POKELOT_PRIZE_PLACE, 0
# 126 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 127 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 128 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 129 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PokefanF:: @ 821F82F
# 130 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
# 131 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 132 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 133 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl:: @ 821F838
# 134 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
# 135 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 136 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 137 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_PokefanM:: @ 821F841
# 138 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
# 139 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 140 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 141 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_Azumarill:: @ 821F84A
# 142 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	lock
# 143 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	faceplayer
# 144 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitse
# 145 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	playmoncry SPECIES_AZUMARILL, 0
# 146 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
# 147 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	waitmoncry
# 148 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	release
# 149 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 150 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 151 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign:: @ 821F85D
# 152 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
# 153 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	end
# 154 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 155 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore: @ 821F866
# 156 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Welcome to Lilycove Department Store.$"
# 157 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 158 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings: @ 821F88C
# 159 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Whenever I come to the Department\n"
# 160 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Store, I always end up buying all sorts\l"
# 161 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "of things because it's so fun.$"
# 162 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 163 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture: @ 821F8F5
# 164 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Today, my mom is going to buy me some\n"
# 165 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "nice furniture.$"
# 166 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 167 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill: @ 821F92B
# 168 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I'm buying something for my Azumarill\n"
# 169 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "as a reward for winning a Contest.$"
# 170 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 171 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_Azumarill: @ 821F974
# 172 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Azumarill: Maririroo!$"
# 173 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 174 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign: @ 821F98A
# 175 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "1F: Service Counter\n"
# 176 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "    Lottery Corner\p"
# 177 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "2F: Trainer's Zone\p"
# 178 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "3F: Battle Collection\p"
# 179 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "4F: TM Corner\p"
# 180 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "5F: Poké Doll Floor\p"
# 181 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Rooftop: Rooftop Plaza$"
# 182 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 183 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
@ Unused
# 184 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun: @ 821FA13
# 185 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "Wireless Communication is a\n"
# 186 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "lot of fun, isn't it?\p"
# 187 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I think it lets you do things that\n"
# 188 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "weren't possible before.\p"
# 189 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "For instance, you can now trade\n"
# 190 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "with people you couldn't before.\p"
# 191 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I think it's going to be exciting!$"
# 192 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"

# 193 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
@ Unused
# 194 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm: @ 821FAE5
# 195 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "I want to spread the word about how\n"
# 196 "data/maps/LilycoveCity_DepartmentStore_1F/scripts.pory"
	.string "fun Wireless Communication can be.$"
