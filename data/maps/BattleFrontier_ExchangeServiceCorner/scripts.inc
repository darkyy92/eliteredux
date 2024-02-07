# 1 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 2 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_MapScripts:: @ 825F070
# 3 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 5 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome:: @ 825F071
# 6 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
# 7 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowBattlePointsWindow
# 8 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	return
# 9 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 10 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye:: @ 825F07D
# 11 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
# 12 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseBattlePointsWindow
# 13 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 14 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 16 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize:: @ 825F08A
# 17 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
# 18 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_TEMP_1, VAR_0x8008
# 19 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_ge BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
# 20 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
# 21 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
# 22 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 23 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
# 24 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 25 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
# 26 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 27 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 28 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 29 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 30 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize:: @ 825F0C9
# 31 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
# 32 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
# 33 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
# 34 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
# 35 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
# 36 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 37 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 38 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor:: @ 825F0E5
# 39 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	checkdecorspace VAR_0x8009
# 40 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 41 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
# 42 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 43 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special TakeFrontierBattlePoints
# 44 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	adddecoration VAR_0x8009
# 45 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special UpdateBattlePointsWindow
# 46 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	playse SE_SHOP
# 47 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
# 48 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
# 49 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 50 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 51 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 52 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 53 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor:: @ 825F11D
# 54 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
# 55 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseBattlePointsWindow
# 56 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 57 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 58 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 59 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem:: @ 825F12A
# 60 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	checkitemspace VAR_0x8009, 1
# 61 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, FALSE
# 62 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
# 63 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 64 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special TakeFrontierBattlePoints
# 65 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	additem VAR_0x8009
# 66 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special UpdateBattlePointsWindow
# 67 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	playse SE_SHOP
# 68 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
# 69 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
# 70 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 71 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 72 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 73 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 74 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_BagFull:: @ 825F166
# 75 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
# 76 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseBattlePointsWindow
# 77 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 78 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 79 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 80 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1:: @ 825F173
# 81 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 82 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 83 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
# 84 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 85 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 86 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 87 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 88 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1:: @ 825F185
# 89 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
# 90 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 91 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowScrollableMultichoice
# 92 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 93 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 94 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	switch VAR_RESULT
# 95 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
# 96 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
# 97 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
# 98 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
# 99 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
# 100 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
# 101 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
# 102 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
# 103 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
# 104 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
# 105 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 106 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 107 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 108 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 109 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster:: @ 825F21E
# 110 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
# 111 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 112 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 113 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 16
# 114 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_KISS_POSTER
# 115 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 116 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 117 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 118 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion:: @ 825F241
# 119 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
# 120 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 121 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 122 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 32
# 123 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_KISS_CUSHION
# 124 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 125 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 126 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 127 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll:: @ 825F264
# 128 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
# 129 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 130 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 131 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 32
# 132 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
# 133 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 134 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 135 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 136 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll:: @ 825F287
# 137 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
# 138 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 139 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 140 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 48
# 141 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
# 142 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 143 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 144 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 145 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll:: @ 825F2AA
# 146 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
# 147 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 148 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 149 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 48
# 150 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
# 151 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 152 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 153 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 154 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll:: @ 825F2CD
# 155 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
# 156 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 157 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 158 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 48
# 159 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
# 160 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 161 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 162 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 163 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll:: @ 825F2F0
# 164 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
# 165 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 166 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 167 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 48
# 168 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_DITTO_DOLL
# 169 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 170 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 171 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 172 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll:: @ 825F313
# 173 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
# 174 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 175 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 176 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 80
# 177 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
# 178 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 179 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 180 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 181 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll:: @ 825F336
# 182 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
# 183 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 184 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 185 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 80
# 186 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
# 187 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 188 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 189 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 190 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll:: @ 825F359
# 191 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
# 192 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 193 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
# 194 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 80
# 195 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
# 196 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 197 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 198 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 199 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2:: @ 825F37C
# 200 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 201 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 202 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
# 203 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 204 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 205 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 206 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 207 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2:: @ 825F38E
# 208 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
# 209 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 210 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowScrollableMultichoice
# 211 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 212 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 213 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	switch VAR_RESULT
# 214 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
# 215 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
# 216 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
# 217 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
# 218 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
# 219 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 220 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 221 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 222 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 223 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll:: @ 825F3F0
# 224 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
# 225 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 226 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 227 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 128
# 228 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
# 229 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 230 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 231 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 232 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll:: @ 825F413
# 233 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
# 234 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 235 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 236 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 128
# 237 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
# 238 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 239 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 240 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 241 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll:: @ 825F436
# 242 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
# 243 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 244 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 245 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 256
# 246 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
# 247 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 248 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 249 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 250 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll:: @ 825F459
# 251 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
# 252 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 253 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 254 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 256
# 255 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
# 256 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 257 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 258 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 259 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll:: @ 825F47C
# 260 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
# 261 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 262 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
# 263 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 256
# 264 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
# 265 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 266 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 267 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 268 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk:: @ 825F49F
# 269 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 270 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 271 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
# 272 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 273 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 274 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 275 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 276 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin:: @ 825F4B1
# 277 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
# 278 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 279 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowScrollableMultichoice
# 280 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 281 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 282 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	switch VAR_RESULT
# 283 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
# 284 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
# 285 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
# 286 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
# 287 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
# 288 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
# 289 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 290 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 291 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 292 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 293 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Protein:: @ 825F51E
# 294 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
# 295 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 296 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 297 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 1
# 298 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_PROTEIN
# 299 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 300 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 301 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 302 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Calcium:: @ 825F541
# 303 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
# 304 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 305 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 306 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 1
# 307 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_CALCIUM
# 308 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 309 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 310 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 311 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Iron:: @ 825F564
# 312 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
# 313 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 314 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 315 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 1
# 316 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_IRON
# 317 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 318 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 319 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 320 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Zinc:: @ 825F587
# 321 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
# 322 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 323 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 324 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 1
# 325 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_ZINC
# 326 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 327 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 328 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 329 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Carbos:: @ 825F5AA
# 330 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
# 331 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 332 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 333 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 1
# 334 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_CARBOS
# 335 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 336 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 337 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 338 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_HPUp:: @ 825F5CD
# 339 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp, MSGBOX_YESNO
# 340 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 341 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
# 342 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 1
# 343 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_HP_UP
# 344 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 345 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 346 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 347 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk:: @ 825F5F0
# 348 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 349 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	faceplayer
# 350 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
# 351 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
# 352 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 353 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 354 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 355 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem:: @ 825F602
# 356 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
# 357 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowFrontierExchangeCornerItemIconWindow
# 358 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special ShowScrollableMultichoice
# 359 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	waitstate
# 360 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	special CloseFrontierExchangeCornerItemIconWindow
# 361 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	switch VAR_RESULT
# 362 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
# 363 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
# 364 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
# 365 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
# 366 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
# 367 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
# 368 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
# 369 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
# 370 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
# 371 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 372 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
# 373 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 374 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 375 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers:: @ 825F690
# 376 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
# 377 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 378 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 379 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 48
# 380 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_LEFTOVERS
# 381 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 382 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 383 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 384 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb:: @ 825F6B3
# 385 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
# 386 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 387 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 388 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 48
# 389 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_WHITE_HERB
# 390 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 391 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 392 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 393 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw:: @ 825F6D6
# 394 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
# 395 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 396 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 397 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 48
# 398 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_QUICK_CLAW
# 399 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 400 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 401 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 402 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb:: @ 825F6F9
# 403 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
# 404 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 405 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 406 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 48
# 407 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_MENTAL_HERB
# 408 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 409 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 410 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 411 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder:: @ 825F71C
# 412 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
# 413 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 414 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 415 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 64
# 416 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
# 417 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 418 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 419 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 420 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand:: @ 825F73F
# 421 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
# 422 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 423 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 424 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 64
# 425 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_CHOICE_BAND
# 426 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 427 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 428 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 429 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock:: @ 825F762
# 430 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
# 431 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 432 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 433 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 64
# 434 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_KINGS_ROCK
# 435 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 436 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 437 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 438 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand:: @ 825F785
# 439 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
# 440 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 441 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 442 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 64
# 443 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_FOCUS_BAND
# 444 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 445 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 446 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 447 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens:: @ 825F7A8
# 448 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
# 449 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	compare VAR_RESULT, NO
# 450 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto_if_eq BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
# 451 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8008, 64
# 452 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	setvar VAR_0x8009, ITEM_SCOPE_LENS
# 453 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
# 454 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 455 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 456 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Man:: @ 825F7CB
# 457 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
# 458 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 459 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 460 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Sailor:: @ 825F7D4
# 461 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
# 462 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 463 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 464 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF:: @ 825F7DD
# 465 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	lock
# 466 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
# 467 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	release
# 468 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 469 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 470 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy:: @ 825F7E8
# 471 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
# 472 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 473 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 474 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_EventScript_Girl:: @ 825F7F1
# 475 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
# 476 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	end
# 477 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 478 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize: @ 825F7FA
# 479 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hello, this is the EXCHANGE SERVICE\n"
# 480 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "CORNER.\p"
# 481 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "We exchange the Battle Points you\n"
# 482 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "have collected for lovely prizes.\p"
# 483 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Please choose a prize from this list.$"
# 484 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 485 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
@ Unused
# 486 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize: @ 825F890
# 487 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Please choose a prize from this list.$"
# 488 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 489 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster: @ 825F8B6
# 490 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the KISS POSTER.\n"
# 491 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 492 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 493 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion: @ 825F8E6
# 494 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the KISS CUSHION.\n"
# 495 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 496 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 497 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll: @ 825F917
# 498 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SMOOCHUM DOLL.\n"
# 499 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 500 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 501 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll: @ 825F949
# 502 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the TOGEPI DOLL.\n"
# 503 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 504 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 505 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll: @ 825F979
# 506 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the MEOWTH DOLL.\n"
# 507 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 508 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 509 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll: @ 825F9A9
# 510 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CLEFAIRY DOLL.\n"
# 511 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 512 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 513 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll: @ 825F9DB
# 514 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the DITTO DOLL.\n"
# 515 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 516 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 517 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll: @ 825FA0A
# 518 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CYNDAQUIL DOLL.\n"
# 519 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 520 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 521 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll: @ 825FA3D
# 522 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CHIKORITA DOLL.\n"
# 523 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 524 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 525 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll: @ 825FA70
# 526 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the TOTODILE DOLL.\n"
# 527 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 528 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 529 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll: @ 825FAA2
# 530 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the LAPRAS DOLL.\n"
# 531 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 532 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 533 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll: @ 825FAD2
# 534 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SNORLAX DOLL.\n"
# 535 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 536 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 537 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll: @ 825FB03
# 538 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the VENUSAUR DOLL.\n"
# 539 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 540 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 541 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll: @ 825FB35
# 542 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CHARIZARD DOLL.\n"
# 543 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 544 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 545 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll: @ 825FB68
# 546 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the BLASTOISE DOLL.\n"
# 547 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 548 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 549 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein: @ 825FB9B
# 550 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the PROTEIN.\n"
# 551 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 552 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 553 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium: @ 825FBC7
# 554 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CALCIUM.\n"
# 555 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 556 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 557 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron: @ 825FBF3
# 558 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the IRON.\n"
# 559 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 560 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 561 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc: @ 825FC1C
# 562 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the ZINC.\n"
# 563 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 564 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 565 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos: @ 825FC45
# 566 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CARBOS.\n"
# 567 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 568 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 569 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp: @ 825FC70
# 570 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the HP UP.\n"
# 571 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 572 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 573 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder: @ 825FC9A
# 574 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the BRIGHTPOWDER.\n"
# 575 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 576 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 577 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb: @ 825FCCB
# 578 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the WHITE HERB.\n"
# 579 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 580 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 581 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw: @ 825FCFA
# 582 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the QUICK CLAW.\n"
# 583 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 584 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 585 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb: @ 825FD29
# 586 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the MENTAL HERB.\n"
# 587 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 588 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 589 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand: @ 825FD59
# 590 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the CHOICE BAND.\n"
# 591 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 592 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 593 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock: @ 825FD89
# 594 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the KING'S ROCK.\n"
# 595 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 596 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 597 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand: @ 825FDB9
# 598 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the FOCUS BAND.\n"
# 599 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 600 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 601 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens: @ 825FDE8
# 602 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the SCOPE LENS.\n"
# 603 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 604 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 605 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers: @ 825FE17
# 606 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You've chosen the LEFTOVERS.\n"
# 607 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Is that correct?$"
# 608 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 609 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC: @ 825FE45
# 610 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Thank you!\n"
# 611 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "We'll send it to your PC at home.$"
# 612 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 613 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize: @ 825FE72
# 614 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Here is your prize!$"
# 615 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 616 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints: @ 825FE86
# 617 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 618 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have enough Battle Points…$"
# 619 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 620 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_PCIsFull: @ 825FEB9
# 621 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 622 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Your PC appears to be full…$"
# 623 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 624 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt: @ 825FEE3
# 625 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I'm so sorry…\n"
# 626 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You don't have space to hold it…$"
# 627 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 628 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints: @ 825FF12
# 629 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Thank you very much.\p"
# 630 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Please visit us when you have\n"
# 631 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "saved up Battle Points.$"
# 632 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 633 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls: @ 825FF5D
# 634 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Oh, they're so nice!\n"
# 635 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I wish I had them!\l"
# 636 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Cute cushions!\l"
# 637 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Big plush Dolls!\l"
# 638 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Little plush Dolls!\l"
# 639 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I wish I had them all!$"
# 640 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 641 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant: @ 825FFD0
# 642 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Leave it to your mommy!\p"
# 643 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If it's anything you want, I'll go\n"
# 644 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "through anything to get it, honey!$"
# 645 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 646 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher: @ 826002E
# 647 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If I can get hold of the items here,\n"
# 648 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "my Pokémon will get tougher.\p"
# 649 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "You bet they will!\n"
# 650 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "No question about it!$"
# 651 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 652 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll: @ 8260099
# 653 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Hah?\n"
# 654 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "What are you gawking at?\p"
# 655 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "I don't like you staring at my plush\n"
# 656 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "doll like that.\p"
# 657 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If you want it, go get one yourself!\n"
# 658 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Isn't that right, SMOOCHUM?$"
# 659 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 660 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord: @ 826012D
# 661 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Did you know?\p"
# 662 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "If you stretch your record at any of\n"
# 663 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the BATTLE facilities, they start\l"
# 664 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "giving you more and more Battle Points.$"
# 665 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 666 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc:: @ 82601AA
# 667 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A large poster with a SMOOCHUM print.$"
# 668 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 669 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc:: @ 82601D0
# 670 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A SMOOCHUM cushion.\n"
# 671 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 672 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 673 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc:: @ 8260201
# 674 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A SMOOCHUM DOLL.\n"
# 675 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 676 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 677 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc:: @ 826022F
# 678 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A TOGEPI DOLL.\n"
# 679 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 680 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 681 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc:: @ 826025B
# 682 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A MEOWTH DOLL.\n"
# 683 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 684 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 685 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc:: @ 8260287
# 686 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CLEFAIRY DOLL.\n"
# 687 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 688 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 689 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc:: @ 82602B5
# 690 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A DITTO DOLL.\n"
# 691 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 692 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 693 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc:: @ 82602E0
# 694 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CYNDAQUIL DOLL.\n"
# 695 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 696 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 697 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc:: @ 826030F
# 698 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A CHIKORITA DOLL.\n"
# 699 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 700 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 701 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc:: @ 826033E
# 702 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A TOTODILE DOLL.\n"
# 703 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 704 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 705 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc:: @ 826036C
# 706 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A large DOLL.\n"
# 707 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Place it on a mat or a desk.$"
# 708 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 709 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc:: @ 8260397
# 710 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat ATTACK of one\n"
# 711 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Pokémon.$"
# 712 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 713 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc:: @ 82603BE
# 714 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat Sp. Atk of one\n"
# 715 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Pokémon.$"
# 716 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 717 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_IronDesc:: @ 82603E6
# 718 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat DEFENSE of one\n"
# 719 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Pokémon.$"
# 720 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 721 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ZincDesc:: @ 826040E
# 722 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat Sp. Def of one\n"
# 723 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Pokémon.$"
# 724 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 725 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc:: @ 8260436
# 726 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the stat SPEED of one\n"
# 727 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Pokémon.$"
# 728 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 729 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc:: @ 826045C
# 730 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises the HP of one Pokémon.$"
# 731 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 732 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc:: @ 826047A
# 733 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that gradually restores\n"
# 734 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "HP in battle.$"
# 735 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 736 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc:: @ 82604AC
# 737 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that restores any\n"
# 738 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "lowered stat.$"
# 739 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 740 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc:: @ 82604D8
# 741 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that occasionally allows\n"
# 742 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "the first strike.$"
# 743 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 744 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc:: @ 826050F
# 745 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that snaps Pokémon out\n"
# 746 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "of infatuation.$"
# 747 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 748 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc:: @ 8260542
# 749 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that casts a glare to\n"
# 750 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "reduce accuracy.$"
# 751 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 752 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc:: @ 8260575
# 753 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "Raises a move's power, but permits\n"
# 754 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "only that move.$"
# 755 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 756 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc:: @ 82605A8
# 757 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that may cause flinching\n"
# 758 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "when the foe is hit.$"
# 759 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 760 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc:: @ 82605E2
# 761 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that occasionally\n"
# 762 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "prevents fainting.$"
# 763 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"

# 764 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc:: @ 8260613
# 765 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "A hold item that raises the\n"
# 766 "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.pory"
	.string "critical-hit rate.$"
